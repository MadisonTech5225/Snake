//
//  Snake.h
//  Snake
//
//  Copyright Matt Rajca 2009. All rights reserved.
//

#import "Types.h"

@class SnakePart;

@interface Snake : NSObject {
  @private
	Direction _direction;
	NSMutableArray *_parts;
	NSMutableArray *_turningPoints;
	uint8_t _growsLeft;
}

@property (nonatomic, readonly) NSArray *parts;
@property (nonatomic, readonly) SnakePart *headPart;
@property (nonatomic, assign) Direction direction;

- (void)changeDirection:(Direction)direction;
- (void)getProposedLocationWithPart:(SnakePart *)part direction:(Direction)direction x:(int8_t *)ox y:(int8_t *)oy;
- (void)beginGrowth;
- (void)update;

- (void)draw;

@end
