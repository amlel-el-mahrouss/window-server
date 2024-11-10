/*
 * =====================================================================
 *
 *            Copyright (C) 2024, EL Mahrouss Logic, all rights reserved.
 *
 * =====================================================================
 */

#include <WSKit/WSDisplayDelegate.h>

WSDisplayDelegate::operator bool()
{
	return this->fOnPaint && this->fShouldPaint && this->fShouldPaint();
}