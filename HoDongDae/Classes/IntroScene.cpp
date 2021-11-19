#include "IntroScene.h"
#include "SimpleAudioEngine.h"
#include "MainScene.h"
#include "chrcreateScene.h"
//사운드 할라면 꼭 필요
using namespace CocosDenshion;
USING_NS_CC;

Scene* IntroScene::createScene()
{
    auto scene = Scene::create();
    auto layer = IntroScene::create();
    scene->addChild(layer);

    return scene;
}

bool IntroScene::init()
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
	SimpleAudioEngine::getInstance()->playBackgroundMusic("sound/intro_sound.mp3", true);
	//SimpleAudioEngine::getInstance()->playBackgroundMusic("MiniGameResources/IntroBackSound.mp3", true);

    return true;
}
void IntroScene::update(float ft)
{
	//씬 자체적으로 반복 되야하는 내용
}
void IntroScene::InitBackGround()
{
	auto sprite = Sprite::create("MiniGameResources/Title_Scene.png");
	sprite->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	this->addChild(sprite, 0);
}
void IntroScene::InitLabel()
{
	char MyString[20];
	WideCharToMultiByte(CP_UTF8, 0, L"호  동  대", -1, MyString, 20, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "fonts/ABC.ttf", 100);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(320, 670));
	name->setColor(Color3B::WHITE);
	//name->setTag(20);
	this->addChild(name, 2);

	char String[20];
	WideCharToMultiByte(CP_UTF8, 0, L"검 은 손", -1, String, 20, NULL, NULL);
	auto name2 = Label::createWithTTF(String, "fonts/ABC.ttf", 40);
	name2->setAnchorPoint(Point(0, 1));
	name2->setPosition(Point(570, 570));
	name2->setColor(Color3B::BLACK);
	//name->setTag(20);
	this->addChild(name2, 2);

	/*auto label = Label::create("", "MiniGameResources/CuteFont.ttf", 60);
	label->setTextColor(Color4B(0, 0, 0, 255));
	label->setPosition(Vec2(origin.x + visibleSize.width / 2,
		origin.y + visibleSize.height - label->getContentSize().height * 2));
	this->addChild(label, 1);*/




	/*auto action_0 = ScaleBy::create(2.0f, 1.3);
	name->runAction(action_0);
	auto action_1 = ScaleTo::create(2.0f, 1.0);
	name->runAction(action_1);*/
	//auto action_2 = RepeatForever::create(action_0);
	//name->runAction(action_0);
}
// 인트로 선택창
void IntroScene::InitMenu()
{
	//설명보기창
	auto newplay_item = MenuItemImage::create(
		"MiniGameResources/UI_EXample.png",
		"MiniGameResources/UI_EXamplepr.png",

		CC_CALLBACK_1(IntroScene::newplay, this));
	newplay_item->setAnchorPoint(Point(0.5, 0.5));
	newplay_item->setPosition(Point(510, 350));

	auto newplay = Menu::create(newplay_item, NULL);
	newplay->setAnchorPoint(Point(0.5, 0.5));
	newplay->setPosition(Point(0, 0));
	newplay->setTag(4);
	this->addChild(newplay,1);
	//게임시작창
	auto replay_item = MenuItemImage::create(
		"MiniGameResources/UI_start.png",
		"MiniGameResources/UI_startpr.png",

		CC_CALLBACK_1(IntroScene::replayspr, this));
	replay_item->setAnchorPoint(Point(0.5, 0.5));
	replay_item->setPosition(Point(510, 250));

	auto replay = Menu::create(replay_item, NULL);
	replay->setAnchorPoint(Point(0.5, 0.5));
	replay->setPosition(Point(0, 0));
	replay->setTag(4);
	this->addChild(replay,1);
	//시스템설정
//auto system_item = MenuItemImage::create(
//	"MiniGameResources/UI_TITLE4.png",
//	"MiniGameResources/UI_TT_PUSH3.png",
//
//	CC_CALLBACK_1(IntroScene::system, this));
//system_item->setAnchorPoint(Point(0.5, 0.5));
//system_item->setPosition(Point(510, 200));
//
//auto system = Menu::create(system_item, NULL);
//system->setAnchorPoint(Point(0.5, 0.5));
//system->setPosition(Point(0, 0));
//system->setTag(4);
//this->addChild(system, 1);
	//종료
	auto fin_item = MenuItemImage::create(
		"MiniGameResources/UI_TITLE3.png",
		"MiniGameResources/UI_TT_PUSH4.png",

		CC_CALLBACK_1(IntroScene::fin, this));
	fin_item->setAnchorPoint(Point(0.5, 0.5));
	fin_item->setPosition(Point(510, 150));

	auto fin = Menu::create(fin_item, NULL);
	fin->setAnchorPoint(Point(0.5, 0.5));
	fin->setPosition(Point(0, 0));
	fin->setTag(4);
	this->addChild(fin, 1);
	//보조 판업
	Sprite* sub = Sprite::create("MiniGameResources/TITLE_zemog.png");
	sub->setAnchorPoint(Point(0.5, 0));
	sub->setPosition(Point(525, 450));
	sub->setTag(44);
	this->addChild(sub, 1);
}
void IntroScene::fin(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("MiniGameResources/button_click_16_sound_effects_.mp3", false);
	Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif
}

void IntroScene::replayspr(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("MiniGameResources/button_click_16_sound_effects_.mp3", false);
	Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
	Director::getInstance()->replaceScene(MainScene::createScene());
}
void IntroScene::newplay(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("MiniGameResources/button_click_16_sound_effects_.mp3", false);
	Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
	Director::getInstance()->replaceScene(chrcreateScene::createScene());
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
