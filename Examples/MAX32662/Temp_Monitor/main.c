/******************************************************************************
 *
 * Copyright (C) 2022-2023 Maxim Integrated Products, Inc. (now owned by 
 * Analog Devices, Inc.),
 * Copyright (C) 2023-2024 Analog Devices, Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 ******************************************************************************/

/**
 * @file    main.c
 * @brief   Low-Power Temp Monitor example.
 * @details In this example the MCU is used monitor the air temperature. Temperature 
 *          readings are timestamped and placed in flash. If a reading exceeds the 
 *          user defined temperature limits a warning message will be printed to the 
 *          terminal and the red warning light will begin to flash.  
 */

/***** Included Files *****/
#include <stdio.h>
#include "board.h"
#include "lp.h"
#include "temp_monitor.h"
#include "mxc_delay.h"
#include "mxc_device.h"
#include "pb.h"
#include "rtc.h"
#include "uart.h"

/***** Functions *****/
void RTC_IRQHandler(void)
{
    int flags = MXC_RTC_GetFlags();
    MXC_RTC_ClearFlags(flags);

    // RTC TOD alarm --> check temperature
    if (flags & MXC_RTC_INT_FL_LONG) {
        temp_monitor_check_temp();
    }

    // RTC SSEC alarm --> toggle warning light
    if (flags & MXC_RTC_INT_FL_SHORT) {
        temp_monitor_flash_warning_light();
    }
}

void PB_Handler(void *pb)
{
    temp_monitor_print_temps();
}

int main(void)
{
    int err;

    MXC_Delay(MXC_DELAY_SEC(2)); //Delay to give debugger a connection window

    printf("\n********************** Temperature Monitor Demo **********************\n");

    printf("This simple example demonstrates the use of the MAX32662 as a temperature\n");
    printf("monitor.\n\n");

    printf("The device periodically measures the air temperature using an external\n");
    printf("MAX31889 temperature sensor.\n\n");

    printf("If a temperature reading exceeds the upper or lower limits, a warning message\n");
    printf("will be printed in the terminal and the LED will begin to flash at a rate of\n");
    printf("4Hz. Otherwise if the temperature is within the defined limits, the LED will\n");
    printf("stay illuminated until the next temperature warning occurs.\n\n");

    printf("Press SW2 to print the last 12 temperature readings taken.\n\n");

    // Initialize Temperature Monitor
    if ((err = temp_monitor_init()) != E_NO_ERROR) {
        return err;
    }

    // Configure pushbutton as a wakeup source and set interrupt callback
    MXC_LP_EnableGPIOWakeup((mxc_gpio_cfg_t *)&pb_pin[0]);
    PB_RegisterCallback(0, PB_Handler);
    PB_IntEnable(0);

    while (1) {
        while (MXC_UART_GetActive(MXC_UART_GET_UART(CONSOLE_UART))) {}
        //Make sure print statements have finished before sleeping
        MXC_LP_EnterSleepMode(); //Wait for next RTC interrupt
    }

    return E_NO_ERROR;
}
