/**
 * @file sm_types.h
 * @author NXP Semiconductors
 * @version 1.0
 * @par License
 * Copyright 2016 NXP
 *
 * This software is owned or controlled by NXP and may only be used
 * strictly in accordance with the applicable license terms.  By expressly
 * accepting such terms or by downloading, installing, activating and/or
 * otherwise using the software, you are agreeing that you have read, and
 * that you agree to comply with and are bound by, such license terms.  If
 * you do not agree to be bound by the applicable license terms, then you
 * may not retain, install, activate or otherwise use the software.
 *
 * @par Description
 * This file defines A7-series specific types
 * @par History
 * 1.0   20-feb-2012 : Initial version
 *
 */

#ifndef _SM_TYPES_H_
#define _SM_TYPES_H_

#ifdef __cplusplus
extern "C" {
#endif


#if defined(__GNUC__) || defined (__arm__) || defined(__ICCARM__)
#   include <stdint.h>
#   include <stdbool.h>
#endif /* __GNUC__ || __arm__ || iccarm */

#if defined(__ICCARM__)
#    include "stddef.h"
#endif /* __ICCARM__ */

#if defined(_MSC_VER) && _MSC_VER >= 1600
#   include <stdint.h>
#endif /* _MSC_VER */

typedef unsigned char   U8;
typedef unsigned short U16;
typedef unsigned long  U32;

typedef signed char   S8;
typedef signed short S16;
typedef signed long  S32;

#if !defined(__cplusplus) && !defined(__GNUC__) && !defined(__arm__) && !defined(__ICCARM__)
    typedef unsigned char bool; // C++ and GCC has bool.
#   define false    (0)
#   define true     (1)
#endif /* bool */


#if defined(CPU_MIMXRT1052DVL6B) && !defined(IMX_RT)
#   define IMX_RT
#endif

/** @define AX_EMBEDDED Plaform is embedded like Kinetis / LPC / i.MX RT / Freedom Series */
#if defined(FREEDOM) \
    || defined (IMX_RT) \
    || defined (CPU_LPC54018JET180)
#   define AX_EMBEDDED  1
#else
#   define AX_EMBEDDED  0
#endif

/**
 * Identification of ECC curve. Not all turnkey solutions cover all these ECC curves.
 */
typedef enum
{
  ECCCurve_NIST_P192   = 0x01,
  ECCCurve_NIST_P224   = 0x02,
  ECCCurve_NIST_P256   = 0x03, /**< NIST Curve with 256 bits */
  ECCCurve_BrainPoolP192r1 = 0x04,
  ECCCurve_BrainPoolP224r1 = 0x05,
  ECCCurve_BrainPoolP256r1 = 0x06
} ECCCurve_t;

/**
 * Identification of hash algorithm
 */
typedef enum
{
    HASHAlgo_SHA1 = 0x01,
    HASHAlgo_SHA256 = 0x02
} HASHAlgo_t;

typedef U16 SM_Error_t;

#define AX_UNUSED_ARG(x) (void)(x)

// The following defines are visible at the smCom layer
// Because they are also used in the platform specific implementation
// layer, they have ended up in this include file.
// They do not belong here from a structural point of view.
#define SMCOM_CLOSE_MODE_STD       0x00
#define SMCOM_CLOSE_MODE_TERMINATE 0x01

// The following is a set of predefined return values.

/* Don't use
// Protocol error codes
#define     BAD_SEQ_NUMBER          0x8000
#define     UNAUTH_CLIENT           0x8001
#define     SEND_ERROR              0x8002
#define     UNKNOW_ORDER            0x8003
*/

/* ------------------------------ */
// Error/status word
#define SW_OK                               (0x9000) //!< Operation successfull

#define ERR_CONNECT_LINK_FAILED             (0x7001)
#define ERR_CONNECT_SELECT_FAILED           (0x7002)
#define ERR_COMM_ERROR                      (0x7003) //!< Generic communication error
#define ERR_NO_VALID_IP_PORT_PATTERN  (0x8000)

/* Range 0x701x is reserved for Error codes defined in smCom.h */
// #define SMCOM_SND_FAILED 0x7010
// #define SMCOM_RCV_FAILED 0x7011

#define ERR_MEMORY                          (0x7020) //!< Memory allocation error
#define ERR_GENERAL_ERROR                   (0x7021) //!< Non-specific error code
#define ERR_WRONG_RESPONSE                  (0x7022) //!< Semantic error discovered while parsing APDU response
#define ERR_API_ERROR                       (0x7023) //!< Illegal parameter value passed to API
#define ERR_TLV_MISSING                     (0x7024) //!< Specific TAG is missing from APDU response
#define ERR_HASH_COMPARE_FAILS              (0x7025)
#define ERR_BUF_TOO_SMALL                   (0x7026) //!< Buffer provided is too small
#define ERR_CRYPTO_ENGINE_FAILED            (0x7027) //!< The crypto engine (implemented underneath a crypto abstraction layer) failed to provide a crypto service.
#define ERR_PATTERN_COMPARE_FAILED          (0x7028)
#define ERR_NOT_IMPLEMENTED                 (0x7029)
#define ERR_FILE_SYSTEM                     (0x7030)
#define ERR_NO_PRIVATE_KEY                  (0x7031)
#define ERR_IDENT_IDX_RANGE                 (0x7032) //!< Identifier or Index of Reference Key is out of bounds

#define SCP_OK                              (SW_OK)
#define SCP_UNDEFINED_CHANNEL_ID            (0x7041) //!< Undefined SCP channel identifier
#define SCP_FAIL                            (0x7042)
#define SCP_CARD_CRYPTOGRAM_FAILS_TO_VERIFY (0x7043)
#define SCP_PARAMETER_ERROR                 (0x7044)

#define SCP_RSP_MAC_FAIL                    (0x7050) //!< MAC on APDU response is not correct
#define SCP_DECODE_FAIL                     (0x7051) //!< Encrypted Response did not decode to correctly padded plaintext

#ifdef __cplusplus
}
#endif
#endif // _SM_TYPES_H_
