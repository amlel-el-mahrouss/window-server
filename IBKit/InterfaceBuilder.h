/*
 * =====================================================================
 *
 *            Copyright El Mahrouss Logic, all rights reserved.
 *
 * =====================================================================
 */

#pragma once

#import <Cocoa/Cocoa.h>
#import <AVKit/AVKit.h>

#include <vector>
#include <string>

#define IB_KIT_VERSION_STR "1.0.0"
#define IB_KIT_VERSION_BCD 0x0100

#define IB_KIT_DEPRECATED __attribute__((deprecated))

#define IB_KIT_EXTENSION ".ib"

namespace ZKA {
class IZkDOM;
class IZkTextDOM;
class IZkVideoDOM;
class IZkImageDOM;
class ZkButtonDOM;
} // namespace ZKA
