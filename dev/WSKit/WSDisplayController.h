/*
 * =====================================================================
 *
 *            Copyright (C) 2024, EL Mahrouss Logic, all rights reserved.
 *
 * =====================================================================
 */

#pragma once

#include <WSKit/Foundation.h>
#include <WSKit/WSDisplayDelegate.h>

inline constexpr MLInteger64 kMaxDisplaysPerController = 16;

/// @brief Main display controller class.
/// @note Calls IBWindowDisplayDelegate when it gets an event.
class WSDisplayController final ML_OBJECT
{
public:
	ML_COPY_DEFAULT(WSDisplayController);

	WSDisplayController()  = default;
	~WSDisplayController() = default;

public:
	BOOL paintDisplays() noexcept;
	MLArray<WSDisplayDelegate, kMaxDisplaysPerController>& leakDisplays() noexcept;

private:
	MLArray<WSDisplayDelegate, kMaxDisplaysPerController> mDisplays;
};