

#include "Character.hpp"
#include "Platform.hpp"
#include "Constants.h"

using namespace cocos2d;

Character::Character() {}

Character::~Character() {}

//Just pass the gender we construct the sprite accoding to that gender passed.
Character* Character::create(gender gr)
{
    std::string _sprite;
            _sprite = "hero.png";

    
    //Get the spriteFrameFirst
    SpriteFrame *frame = SpriteFrameCache::getInstance()->getSpriteFrameByName(_sprite);
    
#if COCOS2D_DEBUG > 0
    char msg[256] = {0};
    sprintf(msg, "Invalid spriteFrameName: %s", _sprite.c_str());
    CCASSERT(frame != nullptr, msg);
#endif

    Character *pSprite = new Character();
    //Assign the gender here used later on initWithOptions
    pSprite->_gender = gr;
    
    if (pSprite && pSprite->initWithSpriteFrame(frame))
    {
        pSprite->autorelease();
        
        pSprite->setSpriteFrame(frame);
        
        pSprite->initOptions();
        
        //pSprite->scheduleUpdate(); // runs update()
        
        return pSprite;
    }
    
    CC_SAFE_DELETE(pSprite);
    return NULL;
}

void Character::initOptions()
{
    // do things here like setTag(), setPosition(), any custom logic.
    
    genderNum = 1;
    //Character gets tag 1
    setTag(1);
    
    //Set the Name
    setName("Character");
    
    //Set anchor point to be in the middle
    setAnchorPoint(Vec2(0.5f, 0.5f));
    
    //Set the physics body
    auto physicsBody = PhysicsBody::createBox(Size(this->getContentSize().width,this->getContentSize().height),PhysicsMaterial(0.1f, 1.0f, 0.0f));
    
    //Set dynamic so it falls and w can apply forces to it.
    physicsBody->setDynamic(true);
    
    //Set collisions
    physicsBody->setCategoryBitmask(0x02);    // 0010
    //physicsBody->setCollisionBitmask(0x01);   // 0001
    physicsBody->setContactTestBitmask(0xFFFFFFFF);
    
    physicsBody->setRotationEnable(false);
    
    //Add the physics body
    this->addComponent(physicsBody);
    
    //Create an animation for the character for jumping
    //We will do a 4 frames animation as follows : stand => ready => stand => jump and keep jump until touching something
    //Generate the frames using the spritnf to change between female and male
    
    //Stand
    auto frameStand = SpriteFrameCache::getInstance()->getSpriteFrameByName("hero.png");
    
    //Ready
    auto frameReady = SpriteFrameCache::getInstance()->getSpriteFrameByName("hero.png");
    
    //Jump
    auto frameJump = SpriteFrameCache::getInstance()->getSpriteFrameByName("hero4.png");
    
    /*
     * Fix for the weird physics animation behaviour with SpriteFrameCache.
     **/
    //SpriteFrameCache does something really weird with the physic body when animating. We move the anchor point to 0,0 to avoid
    //the physics body from moving if the rect of the animated sprites have not the same size.
    frameStand->setAnchorPoint(Vec2(0, 0));
    frameReady->setAnchorPoint(Vec2(0, 0));
    frameJump->setAnchorPoint(Vec2(0, 0));
    
    //Now we just need to add them to animJump Frames
    Vector<SpriteFrame*> animJumpFrames;
    animJumpFrames.reserve(4);
    //Add the frames
    animJumpFrames.pushBack(frameStand);
    animJumpFrames.pushBack(frameReady);
    animJumpFrames.pushBack(frameStand);
    animJumpFrames.pushBack(frameJump);
    
    //Create the animation that we will play
    jumpAnim = Animation::createWithSpriteFrames(animJumpFrames, 0.05f);
    //The Animate object has autorelease so we need to retain it if we want to execute it later on
    jumpAnim->retain();

    //adds contact event listener


    //auto contactListener = EventListenerPhysicsContact::create();
    //contactListener->onContactBegin = CC_CALLBACK_1(Character::onContactBegin, this);
    //_eventDispatcher->addEventListenerWithSceneGraphPriority(contactListener, this);
    
}

//isDead
//Tells other clases if the character is dead
bool Character::isDead() {
//    //Tell others if character is dead. Useful for movement for example
    return dead;
}

