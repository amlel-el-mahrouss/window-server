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

    BOOL createDisplay()
    {
        mDisplayPtr = XOpenDisplay(nullptr);

        if (!mDisplayPtr)
            return NO;

        return YES;
    }

    BOOL disposeDisplay()
    {
        if (mDisplayPtr)
        {
            XCloseDisplay(mDisplayPtr);
            return YES;
        }

        return NO;
    }

    BOOL runDisplay()
    {
        Window root;
        root = DefaultRootWindow(mDisplayPtr);

        XSelectInput(mDisplayPtr, root, SubstructureRedirectMask | SubstructureNotifyMask);

        // > b. Synchronize the changes.
        XSync(mDisplayPtr, False);

        Cursor cursor = XCreateFontCursor(mDisplayPtr, XC_left_ptr);
        // > b. Define the cursor for the root window.
        XDefineCursor(mDisplayPtr, root, cursor);
        // > c. Synchronize the changes.
        XSync(mDisplayPtr, False);

        XEvent e;

        while (YES) 
        {
            XNextEvent(mDisplayPtr, &e);

            switch (e.type) 
            {
            case ButtonPress:
            {
                // Unfreeze X to allow more mouse events for the root and all children.
                XAllowEvents(mDisplayPtr, ReplayPointer, CurrentTime);
                XSync(mDisplayPtr, False);
                
                MLLog("Button pressed!");
                break;
            }
            default:
            {
                MLLog("Unhandled type of event.");
                break;
            }
            }
            // Ensures that X will proccess the event.
            XSync(mDisplayPtr, False);
        }
    }

private:
    Display* mDisplayPtr{nullptr};

};