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

#ifndef LIBRARIES_MAXUSB_INCLUDE_DEVCLASS_MSC_H_
#define LIBRARIES_MAXUSB_INCLUDE_DEVCLASS_MSC_H_

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @file  MSC.h
 * @brief Mass Storage Class over USB.
 */

#define MAX_PACKET_SIZE                     512     /* The maximum size block (in bytes) handled by this driver. */
                                                    /* LBAs are typically 512 bytes so that is a reasonable choice for this value. */

#define VENDOR_ID_MAX_LEN                   8
#define PRODUCT_ID_MAX_LEN                  16
#define PRODUCT_REV_MAX_LEN                 4

/// Configuration structure
typedef struct {
    unsigned int out_ep;           /* endpoint to be used for OUT packets   */
    unsigned int out_maxpacket;    /* max packet size for OUT endpoint      */
    unsigned int in_ep;            /* endpoint to be used for IN packets    */
    unsigned int in_maxpacket;     /* max packet size for IN endpoint       */
} msc_cfg_t;

typedef struct {
    uint8_t vendor[VENDOR_ID_MAX_LEN];      /* Vendor string.  Maximum of 8 bytes */
    uint8_t product[PRODUCT_ID_MAX_LEN];    /* Product string.  Maximum of 16 bytes */
    uint8_t revision[PRODUCT_REV_MAX_LEN];  /* Version string.  Maximum of 4 bytes */
} msc_idstrings_t;

typedef struct {
    int (*init)(void);                  /* Function to initialize the memory exposed by the MSC.    */
                                        /*   Returns 0 for success, non-zero for failure.           */
    int (*start)(void);                 /* Function to "wake" the memory.  This is called when the  */
                                        /*   device has been enumerated on the bus and the host is  */
                                        /*   to begin sending transactions to it.  Returns 0 for    */
                                        /*   success, non-zero for failure.                         */
    int (*stop)(void);                  /* Function to stop the memory.  This function is called    */
                                        /*   when the "disk" has been ejected.  This function       */
                                        /*   should flush any pending writes to the memory.         */
                                        /*   Returns 0 for success, non-zero for failure.           */
    int (*ready)(void);                 /* Function to test the readiness of the memory.  Returns 0 */
                                        /*   for ready, non-zero for not ready.                     */
    uint32_t (*size)(void);             /* Function to get the memory's size.  Returns the number   */
                                        /*   of 512 byte blocks supported by the memory.            */
    int (*read)(uint32_t, uint8_t*);    /* Function to read the memory.  The first paramter is the  */
                                        /*   block number to read, the second is a buffer where the */
                                        /*   read data should be stored. Returns 0 for success,     */
                                        /*   non-zero for failure.                                  */
    int (*write)(uint32_t, uint8_t*);   /* Function to write the memory.  Set to NULL if the memory */
                                        /*   is not writable.  The first paramter is the block      */
                                        /*   number to write, the second is a buffer containing the */
                                        /*   data to write. Returns 0 for success, non-zero for     */
                                        /*   failure.                                               */
} msc_mem_t;

/**
 *  \brief    Initialize the class driver
 *  \details  Initialize the class driver.
 *  \param    if_desc Pointer to the interface descriptor
 *  \param    ids List of application specific string
 *  \param    funcs Set of functions used by the driver to control the underlying memory
 *  \return   Zero (0) for success, non-zero for failure
 */
int msc_init(const MXC_USB_interface_descriptor_t *if_desc, const msc_idstrings_t* ids, const msc_mem_t* funcs);

/**
 *  \brief    Set the specified configuration
 *  \details  Configures the class and endpoints and starts operation. This function should be
 *            called upon configuration from the host.
 *  \param    cfg   configuration to be set
 *  \return   Zero (0) for success, non-zero for failure
 */
int msc_configure(const msc_cfg_t *cfg);

/**
 *  \brief    Clear the current configuration and resets endpoints
 *  \details  Clear the current configuration and resets endpoints.
 *  \return   Zero (0) for success, non-zero for failure
 */
int msc_deconfigure(void);

#ifdef __cplusplus
}
#endif

#endif //LIBRARIES_MAXUSB_INCLUDE_DEVCLASS_MSC_H_
