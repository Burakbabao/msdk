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
 * @file    st7735s_cfaf128128b1.h
 * @brief   CrystalFontz CFAF128128B1 controller configuration data
 *          
 */

/* Configuration for the CrystalFontz CFAF128128B1 panel
 * 
 * fosc = 333kHz, per CrystalFontz
 *
 * Note that this configuration is executed in a linear manner from first 
 *  register write to last register write. Delays will occur after the cmd/data
 *  is transmitted.
 */

#ifndef LIBRARIES_MISCDRIVERS_DISPLAY_ST7735S_CFAF128128B1_H_
#define LIBRARIES_MISCDRIVERS_DISPLAY_ST7735S_CFAF128128B1_H_

#include "st7735s.h"

#ifdef __cplusplus
extern "C" {
#endif

st7735s_regcfg_t cfaf128128b1_regcfg[] = {
    /* Send a software reset to clear regs (120ms delay mandatory) */
    { .cmd = ST7735S_SWRESET, .delay = 120, .len = 0, .data = NULL },
    /* Wake up panel (120ms delay mandatory) */
    { .cmd = ST7735S_SLPOUT, .delay = 120, .len = 0, .data = NULL },
    /* Frame rate control, panel-specific */
    { .cmd = ST7735S_FRMCTR1, .delay = 0, .len = 3, .data = (uint8_t *)"\x02\x35\x36" },
    { .cmd = ST7735S_FRMCTR2, .delay = 0, .len = 3, .data = (uint8_t *)"\x02\x35\x36" },
    { .cmd = ST7735S_FRMCTR3, .delay = 0, .len = 6, .data = (uint8_t *)"\x02\x35\x36\x02\x35\x36" },
    /* Display inversion control */
    { .cmd = ST7735S_INVCTR, .delay = 0, .len = 1, .data = (uint8_t *)"\x07" },
    /* Power control 1; GVDD = 4.70V, AVDD = 2.5uA */
    { .cmd = ST7735S_PWCTR1, .delay = 0, .len = 2, .data = (uint8_t *)"\x02\x02" },
    /* Power control 2; VGH = 14.70V, VGL = -7.35V */
    { .cmd = ST7735S_PWCTR2, .delay = 0, .len = 1, .data = (uint8_t *)"\xc5" },
    /* Power control 3 (full-color); Opamp Bias = "Large", DC Booster Frequency = BCLK / 1 */
    { .cmd = ST7735S_PWCTR3, .delay = 0, .len = 2, .data = (uint8_t *)"\x0d\x00" },
    /* Power control 4 (8-color); Opamp Bias = "Large", DC Booster Frequency = BCLK / 4 */
    { .cmd = ST7735S_PWCTR4, .delay = 0, .len = 2, .data = (uint8_t *)"\x8d\x1a" },
    /* Power control 5 (partial-color); Opamp Bias = "Large", DC Booster Frequency = BCLK / 8 */
    { .cmd = ST7735S_PWCTR5, .delay = 0, .len = 2, .data = (uint8_t *)"\x8d\xee" },
    /* VCOM Control 1; VCOMH = +4.525V, VCOML = -0.575V */
    { .cmd = ST7735S_VMCTR1, .delay = 0, .len = 2, .data = (uint8_t *)"\x51\x4d" },
    /* Gamma correction (negative) */
    { .cmd = ST7735S_GAMCTRP1,
      .delay = 0,
      .len = 16,
      .data = (uint8_t *)"\x0a\x1c\x0c\x14\x33\x2b\x24\x28\x27\x25\x2c\x39\x00\x05\x03\x0d" },
    /* Gamma correction (positive) */
    { .cmd = ST7735S_GAMCTRN1,
      .delay = 0,
      .len = 16,
      .data = (uint8_t *)"\x0a\x1c\x0c\x14\x33\x2b\x24\x28\x27\x25\x2d\x3a\x00\x05\x03\x0d" },
    /* Color format; 18-bit/pixel */
    { .cmd = ST7735S_COLMOD, .delay = 0, .len = 1, .data = (uint8_t *)"\x06" },
    /* Display ON */
    { .cmd = ST7735S_DISPON, .delay = 0, .len = 0, .data = NULL },
    /* Memory Data Access Control; Reverse row and column address order for panel orientation */
    { .cmd = ST7735S_MADCTL, .delay = 0, .len = 1, .data = (uint8_t *)"\xc0" },
};

#ifdef __cplusplus
}
#endif

#endif // LIBRARIES_MISCDRIVERS_DISPLAY_ST7735S_CFAF128128B1_H_
