/*
 * =====================================================================
 *
 *            Copyright (C) 2024, Amlal EL Mahrouss, all rights reserved.
 *
 * =====================================================================
 */

#include <WSKit/WSDisplayDelegate.h>

WSDisplayDelegate::operator bool()
{
	return this->fOnPaint && this->fShouldPaint && this->fShouldPaint();
}