#import "MacHtmlRenderer.h"

int main (int argc, const char * argv[]) {
    @autoreleasepool {
        // Create a default window
        NSWindow *window = [[NSWindow alloc] init];
        
        [window setBackgroundColor:[NSColor whiteColor]];
        
        [window makeKeyAndOrderFront:nil];
        [window setTitle:@"MacHtmlRenderer"];
        [window setSubtitle:@"DotCom.com"];
        [window setContentSize:NSSizeFromString(@"{1280,720}}")];
        
        NSToolbar* toolbar = [[NSToolbar alloc] initWithIdentifier:@"NSToolbarIdentifierTab"];
        toolbar.allowsUserCustomization = YES;
        toolbar.displayMode = NSToolbarDisplayModeIconAndLabel;
        
        [window setToolbar:toolbar];
            
        ZkTextDOM* layout = new ZkTextDOM();
        layout->set_content_text(@"DotCom.com");
        layout->set_heading(IZkDOM::kHeading1);
        
        ZkTextDOM* layout_2 = new ZkTextDOM();
        
        layout_2->set_content_text(@"AI, .COM, APP Company.");
        layout_2->set_heading(IZkDOM::kHeading5);
        
        ZkImageDOM* layout_3 = new ZkImageDOM();
        
        layout_3->set_image_url([[NSURL alloc] initWithString:@"https://upload.wikimedia.org/wikipedia/commons/6/6b/Rotating_globe.gif"]);
        layout_3->set_content_text(@"Could not load image");
        layout_3->set_heading(IZkDOM::kHeading5);
        layout_3->set_position(0, 0);
        
        layout->insert_child_element(layout_2);
        layout->insert_child_element(layout_3);
        
        layout->insert_element(window);
        
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
