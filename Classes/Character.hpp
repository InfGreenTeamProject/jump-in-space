//
//  Character.hpp
//  BunnyJump
//
//  Created by Anthony on 2/17/17.
//
//

#ifndef Character_hpp
#define Character_hpp

#include "cocos2d.h"

using namespace cocos2d;

// Gender of the character may be gender::male or gender::female
enum class gender: char
{
    male='m',
    female='f', // C++11 allows the extra comma
};

class Character : public cocos2d::Sprite
{
public:
    //Variables
    
    //Methods
    Character();
    ~Character();
    
    static Character* create(gender gr);
   
    void initOptions();
    
    bool isDead();
	Animation *jumpAnim;
	Size _size; //We need to save this for a weird thing. SpriteFrameCache seems to change physics body. So i want to use always same size
	gender _gender;
	int genderNum;
private:
    
    //Variables
    //In the animation the gender has different numbers 1 male , 2 female.
    
    //Animation of character

    
    //If its dead do not get input
    bool dead;
    //
    ////Methods
    //bool onContactBegin(PhysicsContact& contact);
    //
    ////Method to make the character jump including the animation
    //void jump();
    //
    //void die();
};

#endif /* Character_hpp */
