/**
 * Tae Won Ha — @hataewon
 *
 * http://taewon.de
 * http://qvacua.com
 *
 * See LICENSE
 */

#import <Cocoa/Cocoa.h>
#import <MacVimFramework/MacVimFramework.h>


@class VRDocument;
@class VRMainWindowController;

extern NSString *const qMainWindowNibName;
extern NSString *const qVimArgFileNamesToOpen;

@interface VRDocumentController : NSDocumentController <MMVimManagerDelegateProtocol>

#pragma mark Properties
@property (weak) MMVimManager *vimManager;

#pragma mark IBActions
- (IBAction)newTab:(id)sender;

#pragma mark NSDocumentController
- (id)openUntitledDocumentAndDisplay:(BOOL)displayDocument error:(NSError **)outError;
- (id)init;
- (void)dealloc;

#pragma mark MMVimManagerDelegate
- (void)manager:(MMVimManager *)manager vimControllerCreated:(MMVimController *)controller;
- (void)manager:(MMVimManager *)manager vimControllerRemovedWithControllerId:(unsigned int)vimControllerId pid:(int)pid;
- (NSMenuItem *)menuItemTemplateForManager:(MMVimManager *)manager;

@end
