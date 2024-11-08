/*
 * =====================================================================
 *
 *            Copyright (C) 2024, EL Mahrouss Logic, all rights reserved.
 *
 * =====================================================================
 */

#pragma once

#include <IBKit/Foundation.h>

inline constexpr MLInteger64 kMaxDisplaysPerController = 16;

/// @brief Main display controller class.
/// @note Calls IBWindowDisplayDelegate when it gets an event.
class IBDisplayController final ML_OBJECT
{
public:
	ML_COPY_DEFAULT(IBDisplayController);

	IBDisplayController()  = default;
	~IBDisplayController() = default;

public:
	BOOL paintDisplays() noexcept;
	MLArray<IBDisplayDelegate, kMaxDisplaysPerController>& leakDisplays() noexcept;

private:
	MLArray<IBDisplayDelegate, kMaxDisplaysPerController> mDisplays;
};