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

/*
  adxl343.h

  Analog Devices ADXL343 driver.
*/

#ifndef EXAMPLES_MAX78000_I2C_ADXL343_ADXL343_H_
#define EXAMPLES_MAX78000_I2C_ADXL343_ADXL343_H_

#include <stdint.h>
#include "mxc.h"

#ifdef __cplusplus
extern "C" {
#endif

/*
  Power control
*/
#define ADXL343_PWRCTL_STANDBY 0x00
#define ADXL343_PWRCTL_MEASURE 0x08

/*
  Power mode
*/
#define ADXL343_PWRMOD_NORMAL 0x00
#define ADXL343_PWRMOD_LP 0x10

/*
  Interrupt enable, map and source fields
*/
#define ADXL343_INT_DATA_READY 0x80
#define ADXL343_INT_SINGLE_TAP 0x40
#define ADXL343_INT_DOUBLE_TAP 0x20
#define ADXL343_INT_ACTIVITY 0x10
#define ADXL343_INT_INACTIVITY 0x08
#define ADXL343_INT_FREE_FALL 0x04
#define ADXL343_INT_WATERMARK 0x02
#define ADXL343_INT_OVERRUN 0x01

/*
  Data ranges
*/
#define ADXL343_RANGE_2G 0x00
#define ADXL343_RANGE_4G 0x01
#define ADXL343_RANGE_8G 0x02
#define ADXL343_RANGE_16G 0x03

/*
  Data rates
*/
#define ADXL343_DR_3200HZ 0x0F
#define ADXL343_DR_1600HZ 0x0E
#define ADXL343_DR_800HZ 0x0D
#define ADXL343_DR_400HZ 0x0C
#define ADXL343_DR_200HZ 0x0B
#define ADXL343_DR_100HZ 0x0A
#define ADXL343_DR_50HZ 0x09
#define ADXL343_DR_25HZ 0x08
#define ADXL343_DR_12HZ5 0x07
#define ADXL343_DR_6HZ25 0x06
#define ADXL343_DR_3HZ13 0x05
#define ADXL343_DR_1HZ56 0x04
#define ADXL343_DR_HZ78 0x03
#define ADXL343_DR_HZ39 0x02
#define ADXL343_DR_HZ20 0x01
#define ADXL343_DR_HZ10 0x00

/*
  FIFO modes
*/
#define ADXL343_FIFO_BYPASS 0x00
#define ADXL343_FIFO_FIFO 0x40
#define ADXL343_FIFO_STREAM 0x80
#define ADXL343_FIFO_TRIGGER 0xC0

/*
  Scale factor -- micro g / LSB
*/
#define ADXL343_SF_FULLRES 0.0039f
#define ADXL343_SF_2G 0.0039f
#define ADXL343_SF_4G 0.0078f
#define ADXL343_SF_8G 0.0156f
#define ADXL343_SF_16G 0.0312f

/*
  Read X, Y and Z axis data.

  PTR parameter must be large enough to accept three int16_t values.
  Axis data order is X, Y, Z.

  Returns 0 on success, negative if error.
*/
int adxl343_get_axis_data(int16_t *ptr);

/*
  Set data output rate.

  RATE parameter is one of the ADXL343_DR_x constants.

  Returns 0 on success, negative if error.
*/
int adxl343_set_data_rate(uint8_t rate);

/*
  Set g range.

  RANGE parameter is one of the ADXL343_RANGE_x constants.

  Returns 0 on success, negative if error.
*/
int adxl343_set_range(uint8_t range);

/*
  Set power control.

  PWR parameter is one of the ADXL343_PWRCTL_x constants.

  Returns 0 on success, negative if error.
*/
int adxl343_set_power_control(uint8_t pwr);

/*
  Set power mode.

  MODE parameter is one of the ADXL343_PWRMOD_x constants.

  Returns 0 on success, negative if error.
 */
int adxl343_set_power_mode(uint8_t mode);

/*
  Set FIFO mode.

  MODE parameter is one of the ADXL343_FIFO_x constants.

  Returns 0 on success, negative if error.
*/
int adxl343_set_fifo_mode(uint8_t mode);

/*
  Enable interrupt sources.

  SRCS parameter is the bitwise OR of one or more of the ADXL343_INT_x constants.
  Specified interrupt sources are enabled; unspecified interrupt sources are disabled.

  Returns 0 on success, negative if error.
*/
int adxl343_set_int_enable(uint8_t srcs);

/*
  Set interrupt pin mapping.

  MAP parameter is the bitwise OR of one or more of the ADXL343_INT_x constants.
  Specified interrupt sources are mapped to INT2 pin; unspecified interrupt sources are mapped to INT1 pin.

  Returns 0 on success, negative if error.
*/
int adxl343_set_int_map(uint8_t map);

/*
  Read interrupt source register.

  SRCS parameter specifies location to receive interrupt source register value.
  Active interrupts read a 1; ADXL343_INT_x constants should be used to identify active sources.

  Returns 0 on success, negative if error.
*/
int adxl343_get_int_source(uint8_t *srcs);

/*
  Set X, Y and Z axis offsets.

  OFFS parameter specifies location to retrieve three int8_t offsets.
  Axis offset order is X, Y, Z.

  Returns 0 on success, negative if error.
*/
int adxl343_set_offsets(const int8_t *offs);

/*
  Initialize device.

  I2C_INST parameter is pointer to I2C peripheral instance to be used for communication with device.

  Returns 0 on success, negative if error.
*/
int adxl343_init(mxc_i2c_regs_t *i2c_inst);

#ifdef __cplusplus
}
#endif

#endif // EXAMPLES_MAX78000_I2C_ADXL343_ADXL343_H_
