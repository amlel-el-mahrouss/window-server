#import "DOMRenderer.h"

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        // Create a default window
        NSWindow *window = [[NSWindow alloc] init];
        
        [window setBackgroundColor:[NSColor whiteColor]];
        
        [window makeKeyAndOrderFront:nil];
        [window setTitle:@"Photon"];
        [window setSubtitle:@"photon:blank"];
        [window setContentSize:NSSizeFromString(@"{1280,720}}")];
        
        NSToolbar* toolbar = [[NSToolbar alloc] initWithIdentifier:@"NSToolbarIdentifierTab"];
        toolbar.allowsUserCustomization = YES;
        toolbar.displayMode = NSToolbarDisplayModeIconAndLabel;
        
        [[window contentView] setBoundsOrigin:NSMakePoint(0, -[window contentView].frame.size.height)];
        
        [window setToolbar:toolbar];
        
        kRootDOM->set_content_text(@"Welcome!");
        kRootDOM->set_heading(IZkDOM::kHeading1);
        
        ZkImageDOM* layout_3 = new ZkImageDOM();
        
        layout_3->set_image_url([[NSURL alloc] initWithString:@"https://upload.wikimedia.org/wikipedia/commons/6/6b/Rotating_globe.gif"]);
        layout_3->set_content_text(@"Could not load image");
        layout_3->set_heading(IZkDOM::kHeading5);
        
        ZkImageDOM* layout_4 = new ZkImageDOM();
        
        layout_4->set_image_url([[NSURL alloc] initWithString:@"https://images.squarespace-cdn.com/content/v1/601baa165d76be323d850cd5/1617212521474-E7PTKK8H7TGIH8ING0AE/netscape.gif"]);
        layout_4->set_content_text(@"Could not load image");
        layout_4->set_heading(IZkDOM::kHeading5);
        
        layout_4->set_position(50, 10);
        
        layout_3->insert_child_element(layout_4);
        kRootDOM->insert_child_element(layout_3);
        
        kRootDOM->insert_element(window);
        
        NSEvent* event = nullptr;
        
        while (YES) {
            do {
                event = [window nextEventMatchingMask:NSEventMaskAny]; // window shows now.
                if ([event type] == NSEventTypeLeftMouseDown) {
                    NSLog(@"Mouse left down");
                } else if ([event type] == NSEventTypeRightMouseDown) {
                    NSLog(@"Mouse Right Down.");
                } else {
                    
                }
            } while (event != nullptr);
        }
    }
    
    return 0;
}
