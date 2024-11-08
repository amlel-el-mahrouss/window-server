/*
 * =====================================================================
 *
 *            Copyright (C) 2024, EL Mahrouss Logic, all rights reserved.
 *
 * =====================================================================
 */

#pragma once

#define IB_KIT_VERSION_STR "1.0.0"
#define IB_KIT_VERSION_BCD 0x0100

#define IB_KIT_DEPRECATED __attribute__((deprecated))

extern "C" {
#   include <X11/Xlib.h>
#   include <X11/cursorfont.h>
}

#include <FoundationKit/FoundationKit.h>
#include <FoundationKit/MLRect.h>
#include <FoundationKit/MLPoint.h>
#include <FoundationKit/MLString.h>

class IBWindowDisplayController;
class IBWindowDisplayDelegate;
class IBWindow;