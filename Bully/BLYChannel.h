//
//  BLYChannel
//  Bully
//
//  Created by Sam Soffes on 6/1/12.
//  Copyright (c) 2012 Sam Soffes. All rights reserved.
//

#import <Foundation/Foundation.h>

@class BLYClient;
@class BLYChannel;

typedef void (^BLYChannelEventBlock)(id message);
typedef void (^BLYChannelAuthenticationBlock)(BLYChannel *channel);

@interface BLYChannel : NSObject

@property (nonatomic, strong, readonly) NSString *name;
@property (nonatomic, weak, readonly) BLYClient *client;
@property (nonatomic, copy) BLYChannelAuthenticationBlock authenticationBlock;

- (BOOL)isPrivate;

- (void)subscribeWithAuthentication:(NSDictionary *)authentication;

- (void)bindToEvent:(NSString *)eventName block:(BLYChannelEventBlock)block;
- (void)unbindEvent:(NSString *)eventName;

- (void)unsubscribe;

@end
