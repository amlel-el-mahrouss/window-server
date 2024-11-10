/*
 * =====================================================================
 *
 *            Copyright (C) 2024, EL Mahrouss Logic, all rights reserved.
 *
 * =====================================================================
 */

#include <WSKit/WSDisplayController.h>
#include <stdexcept>

BOOL WSDisplayController::paintDisplays() noexcept
{
	if (this->mDisplays.isEmpty())
		return NO;

	for (MLInteger64 indexDisplay = 0UL; indexDisplay < this->mDisplays.capacity(); ++indexDisplay)
	{
		if (!this->mDisplays[indexDisplay])
			continue;

		if (!this->mDisplays[indexDisplay].fShouldPaint())
			continue;

		try
		{
			if (!this->mDisplays[indexDisplay].fOnPaint(&this->mDisplays[indexDisplay]))
			{
				throw std::runtime_error("Displayr returned false (WSError)");
			}
		}
		catch (std::runtime_error& err)
		{
			MLLog("%s", err.what());
		}
	}

	return YES;
}

MLArray<WSDisplayDelegate, kMaxDisplaysPerController>& WSDisplayController::leakDisplays() noexcept
{
	return this->mDisplays;
}