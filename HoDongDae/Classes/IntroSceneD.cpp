#include "IntroSceneD.h"
#include "IntroSceneE.h"
#include "IntroScene.h"
#include "SimpleAudioEngine.h"
//#include "MainScene.h"
//사운드 할라면 꼭 필요
using namespace CocosDenshion;
USING_NS_CC;

Scene* IntroSceneD::createScene()
{
    auto scene = Scene::create();
    auto layer = IntroSceneD::create();
    scene->addChild(layer);

    return scene;
}

bool IntroSceneD::init()
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

	this->scheduleOnce(schedule_selector(IntroSceneD::start2), 5.0f);

    return true;
}
void IntroSceneD::update(float ft)
{
	//씬 자체적으로 반복 되야하는 내용
}
void IntroSceneD::InitBackGround()
{
	auto sprite = Sprite::create("MiniGameResources/TITLE6.png");
	sprite->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	this->addChild(sprite, 0);
}
void IntroSceneD::InitLabel()
{
	char MyString[100];
	WideCharToMultiByte(CP_UTF8, 0, L"현실의 부조리함을 깨닫고 좌절한다.", -1, MyString, 100, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "fonts/Bold.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(20);
	this->addChild(name, 3);
}
// 인트로 선택창
void IntroSceneD::InitMenu()
{
	//스토리A창
	auto storyA_item = MenuItemImage::create(
		"MiniGameResources/UI_Textlblack.png",
		"MiniGameResources/UI_Textlblack.png",

		CC_CALLBACK_1(IntroSceneD::storyAspr, this));
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

		CC_CALLBACK_1(IntroSceneD::skipCspr, this));
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

	//	CC_CALLBACK_1(IntroSceneD::replayspr, this));
	//replay_item->setAnchorPoint(Point(0.5, 0.5));
	//replay_item->setPosition(Point(500, 400));

	//auto replay = Menu::create(replay_item, NULL);
	//replay->setAnchorPoint(Point(0.5, 0.5));
	//replay->setPosition(Point(0, 0));
	//replay->setTag(4);
	//this->addChild(replay,1);
}

void IntroSceneD::start2(float f)
{
	
	log("start1 after delay");
	auto scene = TransitionCrossFade::create(1.5, IntroSceneE::createScene());
	Director::getInstance()->replaceScene(scene);
	/*Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
	Director::getInstance()->replaceScene(IntroSceneE::createScene());*/
	
}
void IntroSceneD::storyAspr(Ref *pSender)
{

}
void IntroSceneD::skipCspr(Ref *pSender)
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
