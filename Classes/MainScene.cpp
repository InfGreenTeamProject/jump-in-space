#include "MainScene.h"
#include "SimpleAudioEngine.h"
#include "ui/CocosGUI.h"
#include "GameScene.h"
USING_NS_CC;
Scene* MainScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    auto layer = MainScene::create();
    scene->addChild(layer);
    return scene;
}
bool MainScene::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    auto label = Sprite::create("LogoMakr_9mVl3m.png");
    label->setScale(1.7);
    label->setAnchorPoint(Vec2( 0.5, 0.5 ));

    label->setPosition(Vec2(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height*0.9));
    this->addChild(label, 1);

    auto logo = Sprite::create("statistic1.png");
    logo->setScale(0.1);
    logo->setAnchorPoint(Vec2( 0.5, 0.5 ));
        logo->setPosition(Vec2(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height*0.75));
    this->addChild(logo, 1);
    auto bkg1 = Sprite::create("bg_layer1.png");
    auto bkg2 = Sprite::create("bg_layer2.png");
    auto bkg3 = Sprite::create("bg_layer3.png");
    auto bkg4 = Sprite::create("bg_layer4.png");

    bkg1->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    bkg2->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    bkg3->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    bkg4->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

    this->addChild(bkg1, 0);
    this->addChild(bkg2, 0);
    this->addChild(bkg3, 0);
    this->addChild(bkg4, 0);

    //Play Button now
    auto Playbutton = cocos2d::ui::Button::create("p1.png", "p2.png");
    Playbutton->setScale(0.35);
        Playbutton->setPosition(Vec2(origin.x + visibleSize.width/2 , origin.y + visibleSize.height/2));
    Playbutton->addTouchEventListener([&](Ref* sender, cocos2d::ui::Widget::TouchEventType type){
        switch (type)
        {
            case ui::Widget::TouchEventType::BEGAN:
                break;
            case ui::Widget::TouchEventType::ENDED:
                Director::getInstance()->replaceScene(TransitionFade::create(0.5, GameScene::createScene(), Color3B(67,67,67)));
                break;
            default:
                break;
        }
    });
    this->addChild(Playbutton,1);

    return true;
}


void MainScene::PlayItemCallback(Ref* pSender)
{


}