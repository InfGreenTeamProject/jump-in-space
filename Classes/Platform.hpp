
#ifndef Platform_hpp
#define Platform_hpp

#include "cocos2d.h"
#include "Constants.h"

using namespace cocos2d;

enum class type: char
{
    cake='c',
    grass='g',
    stone='m',
    sand='S',
    snow='s',
    wood='w',
};

enum class size: char
    {
        smalll='b',
        normal='s',
    };
enum class state: char
    {
        normal='n',
        broken='b',
    };

class Platform : public cocos2d::Sprite
{
public:
    bool containsTraps = false;
    
   
    void setType(type t) {
        _type = t;
    }
    
    void setSize(size s) {
        _size = s;
    }
    
    void setState(state st) {
        _state = st;
    }
    
    Platform();
    ~Platform();
    
    static Platform* create(type t,size s,state st);
    
    void initOptions();

    //Add decorations to ths platform if suitable
    
    //Iv platform is broen on steping will break and fall down
    void PlatformBroke();
    
    //This will add Spikes to the platform
    
    //This will add an enemy to the platform (this enemy will walk on top of the platform)
    void AddWalkingEnemy();
    
    //This will add a sprint to the platform
    void AddSpring();

    //This will destroy the platform and delete it from the scene
    void DestroyPlatform();
    
    //Returns the state of the platform
    state getState();
    
    //Asks the latform if its a broken platform or not if it is after this jump will get destroyed
    bool isBroken();
    
    
private:
    //Variables
    type _type;
    size _size;
    state _state;
    
    //Methods
    
};


#endif /* Platform_hpp */
