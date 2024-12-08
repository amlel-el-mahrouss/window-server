/*
 * =====================================================================
 *
 *            Copyright (C) 2024, Amlal EL Mahrouss, all rights reserved.
 *
 * =====================================================================
 */

#pragma once

#include <WSKit/Foundation.h>

typedef MLInteger WSLinearFB;

/// @brief Window object of Window Server.
struct WSWindow final ML_OBJECT
{
    MLChar fWindowName[255];
    MLRect fWindowRect;
    MLPoint fWindowOrigin;
    WSDisplayDelegate* fWindowDisplay;
    WSLinearFB* fWindowFramebuffer;

    BOOL (*fOnWindowPaint)(WSWindow* self) = nullptr;

    WSWindow() = default;
	~WSWindow() = default;

	ML_COPY_DEFAULT(WSWindow);
};