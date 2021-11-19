#include "StoryChangeScene.h"
#include "SchoolStoryScene.h"
#include "SimpleAudioEngine.h"
#include "sinngleton.h"
#include "ParkTalk.h"
#include "BudongStoryScene.h"
#include "Street.h"
//���� �Ҷ�� �� �ʿ�
using namespace CocosDenshion;
USING_NS_CC;

Scene* StoryChangeScene::createScene()
{
    auto scene = Scene::create();
    auto layer = StoryChangeScene::create();
    scene->addChild(layer);
	
    return scene;
}

bool StoryChangeScene::init()
{

    if ( !Layer::init() )
    {
        return false;
    }
	
	visibleSize = Director::getInstance()->getVisibleSize();
	origin      = Director::getInstance()->getVisibleOrigin();

	InitBackGround();
	InitLabel();
	InitMenu();
	//�������
	//SimpleAudioEngine::getInstance()->playBackgroundMusic("MiniGameResources/IntroBackSound.mp3", true);
	this->scheduleOnce(schedule_selector(StoryChangeScene::start1), 1.0f);
    return true;
}
void StoryChangeScene::update(float ft)
{
	//�� ��ü������ �ݺ� �Ǿ��ϴ� ����
}
void StoryChangeScene::InitBackGround()
{
	auto sprite = Sprite::create("MiniGameResources/allblack.png");
	sprite->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	this->addChild(sprite, 0);
}
void StoryChangeScene::InitLabel()
{

}
void StoryChangeScene::start1(float f)
{
	//UserDefault::getInstance()->setIntegerForKey("SaveUsing", Singletons::getInstance()->day+1);
	//Singletons::getInstance()->day = UserDefault::getInstance()->getIntegerForKey("SaveUsing");
	//UserDefault::getInstance()->flush();
	//�����ϱ�
	//UserDefault::getInstance()->setIntegerForKey("SaveUsing", 1);
	//Singletons::getInstance()->day = UserDefault::getInstance()->getIntegerForKey("SaveUsing");
	//UserDefault::getInstance()->flush();
	if (Singletons::getInstance()->num_5 == 1)
	{
			Singletons::getInstance()->day = Singletons::getInstance()->day;
		
		log("start1 after delay");
		auto scene = TransitionCrossFade::create(1.5, SchoolStoryScene::createScene());
		Director::getInstance()->replaceScene(scene);

		Singletons::getInstance()->num_5 = 0;
	}

	if (Singletons::getInstance()->num_5 == 2)
	{
		Singletons::getInstance()->day = Singletons::getInstance()->day;

		log("start1 after delay");
		auto scene = TransitionCrossFade::create(1.5, BudongStoryScene::createScene());
		Director::getInstance()->replaceScene(scene);

		Singletons::getInstance()->num_5 = 0;
	}
	if (Singletons::getInstance()->num_5 == 3)
	{
		Singletons::getInstance()->day = Singletons::getInstance()->day;

		log("start1 after delay");
		auto scene = TransitionCrossFade::create(1.5, ParkTalk::createScene());
		Director::getInstance()->replaceScene(scene);

		Singletons::getInstance()->num_5 = 0;
	}
	if (Singletons::getInstance()->num_5 == 4)
	{
		Singletons::getInstance()->day = Singletons::getInstance()->day;

		log("start1 after delay");
		auto scene = TransitionCrossFade::create(1.5, Street::createScene());
		Director::getInstance()->replaceScene(scene);

		Singletons::getInstance()->num_5 = 0;
	}
}
// ��Ʈ�� ����â
void StoryChangeScene::InitMenu()
{

}
void StoryChangeScene::fin(Ref *pSender)
{
	
}
void StoryChangeScene::system(Ref *pSender)
{

}
void StoryChangeScene::replayspr(Ref *pSender)
{
	
}
void StoryChangeScene::newplayspr(Ref *pSender)
{

}
//bool StoryChangeScene::onTouchBegan(Touch* touch, Event* unused_event)
//{
//	Point location = touch->getLocation();
//	Sprite* spr = (Sprite*)this->getChildByTag(1);
//	Rect	rect = spr->getBoundingBox();
//
//	if (rect.containsPoint(location)) {
//		Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
//		Director::getInstance()->replaceScene(MainScene::createScene());
//	}
//
//	return false;
//}
