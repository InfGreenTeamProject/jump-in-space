#include "SplashScreen.h"
#include "MainScene.h"


USING_NS_CC;

Scene* SplashScreen::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = SplashScreen::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool SplashScreen::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Layer::init())
	{
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	this->scheduleOnce(schedule_selector(SplashScreen::GoToMainMenuScene), 2);

	auto backgroundSprite = Sprite::create("Splash Screen.png");
	backgroundSprite->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

	this->addChild(backgroundSprite);

	return true;
}

void SplashScreen::GoToMainMenuScene(float dt)
{
	auto scene = MainScene::createScene();

	Director::getInstance()->replaceScene(TransitionFade::create(0.5, scene));
}



