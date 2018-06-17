

#ifndef Constants_h
#define Constants_h
#define kMinPlatformStep	75
#define kMaxPlatformStep	200 //this needs to be same as max jump force
#define kNumPlatforms		13 //more platforms to avoid poping in the case they get together
#define kPlatformStepIncrease 5
#define kNormalJumpForce 220
#define kSpringJumpForce 400
#define kInitialPlatformTag 50 //This is to identify the platforms
#define kCharacterXVelocity 100; //The velocity at which the character moves on touch on left or right side of the screen
#define scrollSpeed 7

//Trap Tags
#define kTopSpikeTag 333
#define kBottomSpikeTag 334

#endif /* Constants_h */
