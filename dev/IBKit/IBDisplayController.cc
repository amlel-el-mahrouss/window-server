/*
 * =====================================================================
 *
 *            Copyright (C) 2024, EL Mahrouss Logic, all rights reserved.
 *
 * =====================================================================
 */

#include <IBKit/IBDisplayController.h>

BOOL IBDisplayController::paintDisplays() noexcept
{
    while (YES) 
    {
        for (MLInteger64 indexDisplay = 0UL; indexDisplay < this->mDisplays.count(); ++indexDisplay) 
        {
            this->mDisplays[indexDisplay].onPaint();
        }
    }
}

MLArray<IBDisplayDelegate, kMaxDisplaysPerController>& IBDisplayController::leakDisplays() noexcept
{
    return this->mDisplays;
}