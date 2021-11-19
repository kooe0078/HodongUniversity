#include "IntroSceneE.h"
#include "IntroSceneF.h"
#include "IntroScene.h"
#include "SimpleAudioEngine.h"
//#include "MainScene.h"
//사운드 할라면 꼭 필요
using namespace CocosDenshion;
USING_NS_CC;

Scene* IntroSceneE::createScene()
{
    auto scene = Scene::create();
    auto layer = IntroSceneE::create();
    scene->addChild(layer);

    return scene;
}

bool IntroSceneE::init()
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
	
	////터치 리스너 등록
	//auto listener = EventListenerTouchOneByOne::create();
	//listener->onTouchBegan = CC_CALLBACK_2(IntroScene::onTouchBegan, this);
	//Director::getInstance()->getEventDispatcher()->addEventListenerWithFixedPriority(listener, 1);

	//배경음악
	//SimpleAudioEngine::getInstance()->playBackgroundMusic("MiniGameResources/IntroBackSound.mp3", true);

	this->scheduleOnce(schedule_selector(IntroSceneE::start2), 5.0f);

    return true;
}
void IntroSceneE::update(float ft)
{
	//씬 자체적으로 반복 되야하는 내용
}
void IntroSceneE::InitBackGround()
{
	auto sprite = Sprite::create("MiniGameResources/TITLE_7.png");
	sprite->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	this->addChild(sprite, 0);
}
void IntroSceneE::InitLabel()
{
	char MyString[150];
	WideCharToMultiByte(CP_UTF8, 0, L"좌절하던 중 누군가가 대학생활을 통해 금수저가 될 수있다는 사실을 알려준다.", -1, MyString, 150, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "fonts/Bold.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(20);
	this->addChild(name, 3);
}
// 인트로 선택창
void IntroSceneE::InitMenu()
{
	//스토리A창
	auto storyA_item = MenuItemImage::create(
		"MiniGameResources/UI_Textlblack.png",
		"MiniGameResources/UI_Textlblack.png",

		CC_CALLBACK_1(IntroSceneE::storyAspr, this));
	storyA_item->setAnchorPoint(Point(0.5, 0.5));
	storyA_item->setPosition(Point(510, 100));

	auto storyA = Menu::create(storyA_item, NULL);
	storyA->setAnchorPoint(Point(0.5, 0.5));
	storyA->setPosition(Point(0, 0));
	storyA->setTag(4);
	this->addChild(storyA, 1);

	//스킵창
	auto skip_item = MenuItemImage::create(
		"MiniGameResources/skip.png",
		"MiniGameResources/skippress.png",

		CC_CALLBACK_1(IntroSceneE::skipDspr, this));
	skip_item->setAnchorPoint(Point(0.5, 0.5));
	skip_item->setPosition(Point(970, 50));

	auto skip = Menu::create(skip_item, NULL);
	skip->setAnchorPoint(Point(0.5, 0.5));
	skip->setPosition(Point(0, 0));
	skip->setTag(4);
	this->addChild(skip, 2);
	////이어하기창
	//auto replay_item = MenuItemImage::create(
	//	"MiniGameResources/replay.png",
	//	"MiniGameResources/replay.png",

	//	CC_CALLBACK_1(IntroSceneE::replayspr, this));
	//replay_item->setAnchorPoint(Point(0.5, 0.5));
	//replay_item->setPosition(Point(500, 400));

	//auto replay = Menu::create(replay_item, NULL);
	//replay->setAnchorPoint(Point(0.5, 0.5));
	//replay->setPosition(Point(0, 0));
	//replay->setTag(4);
	//this->addChild(replay,1);
}

void IntroSceneE::start2(float f)
{
	
	log("start1 after delay");
	auto scene = TransitionCrossFade::create(1.5, IntroSceneF::createScene());
	Director::getInstance()->replaceScene(scene);
	/*Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
	Director::getInstance()->replaceScene(IntroSceneF::createScene());*/
	
}
void IntroSceneE::storyAspr(Ref *pSender)
{

}
void IntroSceneE::skipDspr(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("MiniGameResources/button_click_16_sound_effects_.mp3", false);
	Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
	Director::getInstance()->replaceScene(IntroScene::createScene());
}
//bool IntroScene::onTouchBegan(Touch* touch, Event* unused_event)
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
