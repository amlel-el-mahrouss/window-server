#include <IBKit/IBWindowDisplayController.h>

BOOL IBWindowDisplayController::createDisplay() noexcept
{
    mDisplayPtr = XOpenDisplay(nullptr);

    if (!mDisplayPtr)
        return NO;

    return YES;
}

BOOL IBWindowDisplayController::disposeDisplay() noexcept
{
    if (mDisplayPtr)
    {
        XCloseDisplay(mDisplayPtr);
        return YES;
    }

    return NO;
}

BOOL IBWindowDisplayController::runDisplay() noexcept
{
    Window root;
    root = DefaultRootWindow(mDisplayPtr);

    XSelectInput(mDisplayPtr, root, SubstructureRedirectMask | SubstructureNotifyMask);

    // > b. Synchronize the changes.
    XSync(mDisplayPtr, False);

    XEvent env;

    while (YES) 
    {
        XNextEvent(mDisplayPtr, &env);

        switch (env.type) 
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