

#ifndef GameOverScene_hpp
#define GameOverScene_hpp

#include "cocos2d.h"

class GameOverScene : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();
    
    virtual bool init();
    
    // Play Button callback
    void PlayItemCallback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(GameOverScene);

};
#endif /* GameOverScene_hpp */
