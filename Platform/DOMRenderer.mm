#import "DOMRenderer.h"

using namespace ZKA;

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        // Create a default window
        NSWindow *window = [[NSWindow alloc] init];
        
        [window setBackgroundColor:[NSColor whiteColor]];
        
        [window makeKeyAndOrderFront:nil];
        
        [window setTitle:@"Photon Browser"];
        [window setSubtitle:@"photon:welcome"];
        [window setContentSize:NSSizeFromString(@"{1280,720}}")];
        
        NSToolbar* toolbar = [[NSToolbar alloc] initWithIdentifier:@"NSToolbarIdentifierTab"];
        toolbar.allowsUserCustomization = YES;
        toolbar.displayMode = NSToolbarDisplayModeIconAndLabel;
        
        [[window contentView] setBoundsOrigin:NSMakePoint(0, -[window contentView].frame.size.height)];
        
        [window setToolbar:toolbar];
        
        ZkImageDOM* layout_doodle = new ZkImageDOM();
        
        layout_doodle->set_image_url([[NSURL alloc] initWithString:@"https://upload.wikimedia.org/wikipedia/commons/4/42/Animated-Flag-USA.gif"]);
        
        layout_doodle->set_content_text(@"Couldn't load Doodle...");
        layout_doodle->set_heading(IZkDOM::kHeading5);
        
        layout_doodle->set_position(50, 10);
        
        ZkButtonDOM* layout_search_button = new ZkButtonDOM();
        
        layout_search_button->set_content_text(@"Search...");
        layout_search_button->set_heading(IZkDOM::kHeadingParagraph);
        
        layout_search_button->set_position(50, 10);
        
        kRootDOM->insert_child_element(layout_search_button);
        kRootDOM->insert_child_element(layout_doodle);
        kRootDOM->insert_element(window);
        
        NSEvent* event = nullptr;
        
        while (YES) {
            do {
                event = [window nextEventMatchingMask:NSEventMaskAny]; // window shows now.
                if ([event type] == NSEventTypeLeftMouseDown) {
                    NSLog(@"Mouse Left down");
                } else if ([event type] == NSEventTypeRightMouseDown) {
                    NSLog(@"Mouse Right Down.");
                } else {
                    
                }
            } while (event != nullptr);
        }
    }
    
    return 0;
}
