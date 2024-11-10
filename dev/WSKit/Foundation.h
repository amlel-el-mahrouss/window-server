/*
 * =====================================================================
 *
 *            Copyright (C) 2024, EL Mahrouss Logic, all rights reserved.
 *
 * =====================================================================
 */

#pragma once

#include "FoundationKit/Macros.h"
#define IB_KIT_VERSION_STR "1.0.0"
#define IB_KIT_VERSION_BCD 0x0100

#define IB_KIT_DEPRECATED __attribute__((deprecated))

#include <FoundationKit/FoundationKit.h>
#include <GraphicsKit/Foundation.h>
#include <AnimationKit/Foundation.h>

class WSDisplayController;
class WSDisplayDelegate;
class WSConnectionHashList;
struct WSWindow;

inline const MLChar* kSocketAddress = "/tmp/WSKit.sock";