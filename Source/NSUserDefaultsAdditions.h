//
//  NSUserDefaultsAdditions.h
//  SmugMugExport
//
//  Created by Aaron Evans on 6/10/07.
//  Copyright 2007 Aaron Evans. All rights reserved.
//

#import <Cocoa/Cocoa.h>
@class SmugMugUserDefaults;

@interface NSUserDefaults (NSUserDefaultsAdditions)

+(SmugMugUserDefaults *)smugMugUserDefaults;

@end