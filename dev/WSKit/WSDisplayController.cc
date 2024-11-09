/*
 * =====================================================================
 *
 *            Copyright (C) 2024, EL Mahrouss Logic, all rights reserved.
 *
 * =====================================================================
 */

#include <WSKit/WSDisplayController.h>

BOOL WSDisplayController::paintDisplays() noexcept
{
    while (YES) 
    {
        for (MLInteger64 indexDisplay = 0UL; indexDisplay < this->mDisplays.count(); ++indexDisplay) 
        {
            this->mDisplays[indexDisplay].onPaint();
        }
    }
}

MLArray<WSDisplayDelegate, kMaxDisplaysPerController>& WSDisplayController::leakDisplays() noexcept
{
    return this->mDisplays;
}