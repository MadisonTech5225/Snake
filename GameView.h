//
//  GameView.h
//  Snake
//
//  Copyright Matt Rajca 2009. All rights reserved.
//

#import "Types.h"

@class Food, Snake;
@protocol GameViewDelegate;

typedef enum {
	GameViewStatePaused = 0,
	GameViewStateInProgress
} GameViewState;

@interface GameView : NSView {
  @private
	Snake *_snake;
	Food *_food;
	Direction _nextDirection;
	NSTimer *_gameTimer;
	NSDate *_lastFoodDate;
	BOOL _isPaused;
	BOOL _isReady;
	int _points;
	
	id < GameViewDelegate > _delegate;
}

@property (nonatomic, assign) BOOL ready;

@property (nonatomic, assign) IBOutlet id < GameViewDelegate > delegate;

- (IBAction)pause:(id)sender;
- (IBAction)resume:(id)sender;

- (void)newGame;

@end


@protocol GameViewDelegate < NSObject >

- (void)gameView:(GameView *)view didUpdatePoints:(int)points;
- (void)gameView:(GameView *)view didEndWithPoints:(int)points;
- (void)gameView:(GameView *)view didChangeState:(GameViewState)state;

@end
