/**
 * @file    icc_regs.h
 * @brief   Registers, Bit Masks and Bit Positions for the ICC Peripheral Module.
 * @note    This file is @generated.
 * @ingroup icc_registers
 */

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

#ifndef LIBRARIES_CMSIS_DEVICE_MAXIM_MAX32660_INCLUDE_ICC_REGS_H_
#define LIBRARIES_CMSIS_DEVICE_MAXIM_MAX32660_INCLUDE_ICC_REGS_H_

/* **** Includes **** */
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

#if defined (__ICCARM__)
  #pragma system_include
#endif

#if defined (__CC_ARM)
  #pragma anon_unions
#endif
/// @cond
/*
    If types are not defined elsewhere (CMSIS) define them here
*/
#ifndef __IO
#define __IO volatile
#endif
#ifndef __I
#ifdef __cplusplus
#define __I volatile
#else
#define __I volatile const
#endif
#endif
#ifndef __O
#define __O  volatile
#endif
#ifndef __R
#define __R  volatile const
#endif
/// @endcond

/* **** Definitions **** */

/**
 * @ingroup     icc
 * @defgroup    icc_registers ICC_Registers
 * @brief       Registers, Bit Masks and Bit Positions for the ICC Peripheral Module.
 * @details     Instruction Cache Controller Registers
 */

/**
 * @ingroup icc_registers
 * Structure type to access the ICC Registers.
 */
typedef struct {
    __I  uint32_t cache_id;             /**< <tt>\b 0x0000:</tt> ICC CACHE_ID Register */
    __I  uint32_t mem_size;             /**< <tt>\b 0x0004:</tt> ICC MEM_SIZE Register */
    __R  uint32_t rsv_0x8_0xff[62];
    __IO uint32_t cache_ctrl;           /**< <tt>\b 0x0100:</tt> ICC CACHE_CTRL Register */
    __R  uint32_t rsv_0x104_0x6ff[383];
    __IO uint32_t invalidate;           /**< <tt>\b 0x0700:</tt> ICC INVALIDATE Register */
} mxc_icc_regs_t;

/* Register offsets for module ICC */
/**
 * @ingroup    icc_registers
 * @defgroup   ICC_Register_Offsets Register Offsets
 * @brief      ICC Peripheral Register Offsets from the ICC Base Peripheral Address.
 * @{
 */
#define MXC_R_ICC_CACHE_ID                 ((uint32_t)0x00000000UL) /**< Offset from ICC Base Address: <tt> 0x0000</tt> */
#define MXC_R_ICC_MEM_SIZE                 ((uint32_t)0x00000004UL) /**< Offset from ICC Base Address: <tt> 0x0004</tt> */
#define MXC_R_ICC_CACHE_CTRL               ((uint32_t)0x00000100UL) /**< Offset from ICC Base Address: <tt> 0x0100</tt> */
#define MXC_R_ICC_INVALIDATE               ((uint32_t)0x00000700UL) /**< Offset from ICC Base Address: <tt> 0x0700</tt> */
/**@} end of group icc_registers */

/**
 * @ingroup  icc_registers
 * @defgroup ICC_CACHE_ID ICC_CACHE_ID
 * @brief    Cache ID Register.
 * @{
 */
#define MXC_F_ICC_CACHE_ID_RELNUM_POS                  0 /**< CACHE_ID_RELNUM Position */
#define MXC_F_ICC_CACHE_ID_RELNUM                      ((uint32_t)(0x3FUL << MXC_F_ICC_CACHE_ID_RELNUM_POS)) /**< CACHE_ID_RELNUM Mask */

#define MXC_F_ICC_CACHE_ID_PARTNUM_POS                 6 /**< CACHE_ID_PARTNUM Position */
#define MXC_F_ICC_CACHE_ID_PARTNUM                     ((uint32_t)(0xFUL << MXC_F_ICC_CACHE_ID_PARTNUM_POS)) /**< CACHE_ID_PARTNUM Mask */

#define MXC_F_ICC_CACHE_ID_CCHID_POS                   10 /**< CACHE_ID_CCHID Position */
#define MXC_F_ICC_CACHE_ID_CCHID                       ((uint32_t)(0x3FUL << MXC_F_ICC_CACHE_ID_CCHID_POS)) /**< CACHE_ID_CCHID Mask */

/**@} end of group ICC_CACHE_ID_Register */

/**
 * @ingroup  icc_registers
 * @defgroup ICC_MEM_SIZE ICC_MEM_SIZE
 * @brief    Memory Configuration Register.
 * @{
 */
#define MXC_F_ICC_MEM_SIZE_CCHSZ_POS                   0 /**< MEM_SIZE_CCHSZ Position */
#define MXC_F_ICC_MEM_SIZE_CCHSZ                       ((uint32_t)(0xFFFFUL << MXC_F_ICC_MEM_SIZE_CCHSZ_POS)) /**< MEM_SIZE_CCHSZ Mask */

#define MXC_F_ICC_MEM_SIZE_MEMSZ_POS                   16 /**< MEM_SIZE_MEMSZ Position */
#define MXC_F_ICC_MEM_SIZE_MEMSZ                       ((uint32_t)(0xFFFFUL << MXC_F_ICC_MEM_SIZE_MEMSZ_POS)) /**< MEM_SIZE_MEMSZ Mask */

/**@} end of group ICC_MEM_SIZE_Register */

/**
 * @ingroup  icc_registers
 * @defgroup ICC_CACHE_CTRL ICC_CACHE_CTRL
 * @brief    Cache Control and Status Register.
 * @{
 */
#define MXC_F_ICC_CACHE_CTRL_ENABLE_POS                0 /**< CACHE_CTRL_ENABLE Position */
#define MXC_F_ICC_CACHE_CTRL_ENABLE                    ((uint32_t)(0x1UL << MXC_F_ICC_CACHE_CTRL_ENABLE_POS)) /**< CACHE_CTRL_ENABLE Mask */

#define MXC_F_ICC_CACHE_CTRL_READY_POS                 16 /**< CACHE_CTRL_READY Position */
#define MXC_F_ICC_CACHE_CTRL_READY                     ((uint32_t)(0x1UL << MXC_F_ICC_CACHE_CTRL_READY_POS)) /**< CACHE_CTRL_READY Mask */

/**@} end of group ICC_CACHE_CTRL_Register */

#ifdef __cplusplus
}
#endif

#endif // LIBRARIES_CMSIS_DEVICE_MAXIM_MAX32660_INCLUDE_ICC_REGS_H_
