/*
 * =====================================================================
 *
 *            Copyright (C) 2024, EL Mahrouss Logic, all rights reserved.
 *
 * =====================================================================
 */

#include <IBKit/IBWindowDisplayController.h>

int main(int argc, char** argv)
{
    IBWindowDisplayController main_display_ctrl;
    main_display_ctrl.createDisplay();

    return !(main_display_ctrl.runDisplay() == YES);
}