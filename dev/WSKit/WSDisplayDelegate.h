/*
 * =====================================================================
 *
 *            Copyright (C) 2024, Amlal EL Mahrouss, all rights reserved.
 *
 * =====================================================================
 */

#pragma once

#include <WSKit/Foundation.h>

class WSDisplayDelegate ML_OBJECT
{
public:
	void (*onPaint)() = nullptr;
	BOOL(*shouldPaint)
	() = nullptr;

	operator bool()
	{
		return onPaint && shouldPaint && shouldPaint();
	}
};