#include "IntroSceneA.h"
#include "IntroSceneB.h"
#include "IntroScene.h"
#include "SimpleAudioEngine.h"
//#include "MainScene.h"
//���� �Ҷ�� �� �ʿ�
using namespace CocosDenshion;
USING_NS_CC;

Scene* IntroSceneA::createScene()
{
    auto scene = Scene::create();
    auto layer = IntroSceneA::create();
    scene->addChild(layer);

    return scene;
}

bool IntroSceneA::init()
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
	
	////��ġ ������ ���
	//auto listener = EventListenerTouchOneByOne::create();
	//listener->onTouchBegan = CC_CALLBACK_2(IntroScene::onTouchBegan, this);
	//Director::getInstance()->getEventDispatcher()->addEventListenerWithFixedPriority(listener, 1);

	//�������
	SimpleAudioEngine::getInstance()->playBackgroundMusic("sound/intro_sound.mp3", true);

	this->scheduleOnce(schedule_selector(IntroSceneA::start1), 5.0f);

    return true;
}
void IntroSceneA::update(float ft)
{
	//�� ��ü������ �ݺ� �Ǿ��ϴ� ����
}
void IntroSceneA::InitBackGround()
{
	auto sprite = Sprite::create("MiniGameResources/TITLE1.png");
	sprite->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	this->addChild(sprite, 0);
}
void IntroSceneA::InitLabel()
{
	char MyString[100];
	WideCharToMultiByte(CP_UTF8, 0, L"�ð񿡼� �¾ ����� ��Ȱ�� ���� ���ΰ�", -1, MyString, 100, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "fonts/Bold.ttf",30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(20);
	this->addChild(name, 3);
}
// ��Ʈ�� ����â
void IntroSceneA::InitMenu()
{
	//���丮Aâ
	auto storyA_item = MenuItemImage::create(
		"MiniGameResources/UI_Textlblack.png",
		"MiniGameResources/UI_Textlblack.png",

		CC_CALLBACK_1(IntroSceneA::storyAspr, this));
	storyA_item->setAnchorPoint(Point(0.5, 0.5));
	storyA_item->setPosition(Point(510, 100));

	auto storyA = Menu::create(storyA_item, NULL);
	storyA->setAnchorPoint(Point(0.5, 0.5));
	storyA->setPosition(Point(0, 0));
	storyA->setTag(4);
	this->addChild(storyA,1);
	//���丮 ��ŵâ

	auto skip_item = MenuItemImage::create(
		"MiniGameResources/skip.png",
		"MiniGameResources/skippress.png",

		CC_CALLBACK_1(IntroSceneA::skipspr, this));
	skip_item->setAnchorPoint(Point(0.5, 0.5));
	skip_item->setPosition(Point(970, 50));

	auto skip = Menu::create(skip_item, NULL);
	skip->setAnchorPoint(Point(0.5, 0.5));
	skip->setPosition(Point(0, 0));
	skip->setTag(4);
	this->addChild(skip,2);
}


void IntroSceneA::start1(float f)
{
	
	log("start1 after delay");
	/*Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
	Director::getInstance()->replaceScene(IntroSceneB::createScene());*/
	auto scene = TransitionCrossFade::create(1.5, IntroSceneB::createScene());
	Director::getInstance()->replaceScene(scene);
	
}
void IntroSceneA::skipspr(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);
	Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
	Director::getInstance()->replaceScene(IntroScene::createScene());
}
void IntroSceneA::storyAspr(Ref *pSender)
{
	////���丮A�ؽ�Ʈ
	//auto name = Label::createWithSystemFont("�ƾƾƤ��ƾƾƾƾƾƾƾӤ��� ", "fonts/hangul.ttf", 20);
	//name->setAnchorPoint(Point(0, 1));
	//name->setPosition(Point(380, 520));
	//name->setColor(Color3B::BLACK);
	//name->setTag(20);
	//this->addChild(name, 2);
}
//void IntroSceneA::replayspr(Ref *pSender)
//{
//	
//}
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
