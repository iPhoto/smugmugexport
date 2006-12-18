//
//  SmugMugManager.h
//  SmugMugExport
//
//  Created by Aaron Evans on 10/7/06.
//  Copyright 2006 Aaron Evans. All rights reserved.
//

#import <Cocoa/Cocoa.h>
@class CURLHandle;

@protocol SmugMugManagerDelegate
-(void)loginDidComplete:(BOOL)wasSuccessful;
-(void)logoutDidComplete:(BOOL)wasSuccessful;
-(void)uploadDidCompleteForFile:(NSString *)aFullPathToImage withError:(NSString *)error;
-(void)uploadMadeProgressForFile:(NSString *)pathToFile bytesWritten:(long)bytesWritten totalBytes:(long)totalBytes;
@end

@interface SmugMugManager : NSObject {
	id delegate;
	CURLHandle *curlHandle;

	NSArray *albums;
	NSString *username;
	NSString *password;
	NSString *sessionID;
	NSString *userID;
	NSString *passwordHash;
	CFReadStreamRef readStream;
	NSMutableData *responseData;
	
	NSString *currentPathForUpload;
	NSTimer *uploadProgressTimer;
	long uploadSize;
	BOOL isUploading;
	BOOL isLoggingIn;
	BOOL isLoggedIn;
	long nextProgressThreshold;
	NSLock *uploadLock;
}

+(SmugMugManager *)smugmugManager;
-(id)initWithUsername:(NSString *)accountId password:(NSString *)password;

-(void)setDelegate:(id)delegate;
-(id)delegate;

-(void)login;
-(void)logout;

-(BOOL)isLoggingIn;
-(BOOL)isLoggedIn;

-(NSString *)username;
-(void)setUsername:(NSString *)n;
-(NSString *)password;
-(void)setPassword:(NSString *)p;

-(void)uploadImageAtPath:(NSString *)path albumWithID:(NSNumber *)albumId caption:(NSString *)caption;

-(NSArray *)albums;

@end