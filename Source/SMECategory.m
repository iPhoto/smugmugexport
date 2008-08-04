//
//  SMECategory.m
//  SmugMugExport
//
//  Created by Aaron Evans on 7/3/08.
//  Copyright 2008 Aaron Evans. All rights reserved.
//

#import "SMECategory.h"


@implementation SMECategory

+(SMECategory *)nullCategory {
	return [[[[self class] alloc] initWithSourceData:[NSDictionary dictionaryWithObjectsAndKeys:
			 [NSNumber numberWithInt:0], @"id",
													  NSLocalizedString(@"No Value", @"Null category title"), @"Title",nil]] autorelease];
}

-(void)dealloc {
	[childSubCategories release];
	[super dealloc];
}

-(NSString *)description {
	return [NSString stringWithFormat:@"category %d", [self identifier]];
}

-(unsigned int)identifier  {
	return [[[self sourceData] objectForKey:@"id"] intValue];
}

-(NSString *)title {
	return [[self sourceData] objectForKey:@"Title"];
}

-(NSDictionary *)toDict {
	return [self sourceData];
}

-(unsigned int)hash {
	return 31 * [[[self sourceData] objectForKey:@"id"] hash];
}

-(BOOL)isEqual:(id)anotherObject {
	if(![anotherObject isKindOfClass:[self class]])
		return NO;
	
	return [self identifier] == [(SMECategory *)anotherObject identifier];
}

-(NSArray *)childSubCategories {
	return childSubCategories;
}

-(void)setChildSubCategories:(NSArray *)categories {
	if(childSubCategories != categories) {
		[childSubCategories release];
		childSubCategories = [categories retain];
	}
}

@end
