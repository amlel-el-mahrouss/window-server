/*
 * =====================================================================
 *
 *            Copyright (C) 2024, EL Mahrouss Logic, all rights reserved.
 *
 * =====================================================================
 */

#pragma once

#include <IBKit/Foundation.h>


/// @brief Main display controller class.
/// @note Calls IBWindowDisplayDelegate when it gets an event.
class IBWindowDisplayController final ML_OBJECT
{
public:
    ML_COPY_DEFAULT(IBWindowDisplayController);

    IBWindowDisplayController() = default;
    ~IBWindowDisplayController() = default;

public:
    BOOL createDisplay() noexcept;
    BOOL disposeDisplay() noexcept;

    BOOL runDisplay() noexcept;

private:
    Display* mDisplayPtr{nullptr};

};