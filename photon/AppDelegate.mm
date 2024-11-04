//
//  AppDelegate.m
//  photon
//
//  Created by Amlal on 11/4/24.
//

#import "AppDelegate.h"
#include "../IBKit/InterfaceBuilder.h"

#include <dlfcn.h>

@interface AppDelegate ()

@end

@implementation AppDelegate

- (void)applicationDidFinishLaunching:(NSNotification *)aNotification {
    NSWindow *window = [[NSWindow alloc] init];
    
    [window setBackgroundColor:[NSColor whiteColor]];
    
    [window setIsVisible:YES];
    
    [window makeKeyAndOrderFront:nil];
    
    [window setShowsToolbarButton:YES];
    
    [window setFrameOrigin:NSMakePoint(100, 100)];
    
    [window setTitle:@"Interface Builder"];
    [window setSubtitle:@"zib:untitled"];
    [window setContentSize:NSSizeFromString(@"{1280,720}}")];
    
    NSToolbar* toolbar = [[NSToolbar alloc] initWithIdentifier:@"NSToolbarIdentifierTab"];
    toolbar.allowsUserCustomization = YES;
    toolbar.displayMode = NSToolbarDisplayModeIconAndLabel;
    
    [window setToolbar:toolbar];
    
    void* main_plugin = ::dlopen("libIBCorePlugin.dylib", RTLD_LAZY);
    
    if (main_plugin) {
        ZKA::ZkPluginEntrypoint element = reinterpret_cast<ZKA::ZkPluginEntrypoint>(::dlsym(main_plugin, "IBPluginMain"));
        element(ZKA::kRootDOM);
    }
    
    ZKA::kRootDOM->insert_element(window);
}


- (void)applicationWillTerminate:(NSNotification *)aNotification {
    // Insert code here to tear down your application
}


- (BOOL)applicationSupportsSecureRestorableState:(NSApplication *)app {
    return YES;
}


@end
