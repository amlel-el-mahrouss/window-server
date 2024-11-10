/*
 * =====================================================================
 *
 *            Copyright (C) 2024, EL Mahrouss Logic, all rights reserved.
 *
 * =====================================================================
 */

#pragma once

#include <WSKit/Foundation.h>

class WSDisplayDelegate ML_OBJECT
{
public:
	BOOL(*fOnPaint)(WSDisplayDelegate* self) = nullptr;
	BOOL(*fShouldPaint)
	() = nullptr;
	struct WSWindow* fWindow{nullptr};

	operator bool();

	WSDisplayDelegate() = default;
	~WSDisplayDelegate() = default;

	ML_COPY_DEFAULT(WSDisplayDelegate);
};