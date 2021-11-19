#include "hhhhhhh.h"
#include "EndScene.h"
#include "SimpleAudioEngine.h"
#include "singleton.h"

//사운드 할라면 꼭 필요
using namespace CocosDenshion;
USING_NS_CC;

Scene* hhhhhhh::createScene()
{
    auto scene = Scene::create();
    auto layer = hhhhhhh::create();
    scene->addChild(layer);

    return scene;
}

bool hhhhhhh::init()
{

    if ( !Layer::init() )
    {
        return false;
    }

	Gauge();
	click();

	//배경음악
	//SimpleAudioEngine::getInstance()->playBackgroundMusic("MiniGameResources/MainBackSound.mp3", true);

	//키보드 리스너
	auto keylistener = EventListenerKeyboard::create();
	keylistener->onKeyPressed = CC_CALLBACK_2(hhhhhhh::onKeyPressed, this);
	keylistener->onKeyReleased = CC_CALLBACK_2(hhhhhhh::onKeyReleased, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(keylistener, this);

	this->schedule(schedule_selector(hhhhhhh::update));
	this->schedule(schedule_selector(hhhhhhh::GaugeUp));

    return true;
}
void hhhhhhh::update(float ft)
{
	
}
void hhhhhhh::Gauge() // 게이지 칸
{
	auto spr1 = CCSprite::create("Percent/0percent.png");
	spr1->setPosition(Point(512, 384));
	spr1->setTag(600);
	this->addChild(spr1);
}
void hhhhhhh::GaugeUp(float delta) // 게이지 상승
{
	if (10 <= Singletons::getInstance()->Danger && Singletons::getInstance()->Danger < 20)
	{
		auto spr2 = CCSprite::create("Percent/10percent.png");
		spr2->setPosition(Point(512, 384));
		spr2->setTag(601);
		this->addChild(spr2);
	}
	else if (20 <= Singletons::getInstance()->Danger && Singletons::getInstance()->Danger < 30)
	{
		auto spr2 = CCSprite::create("Percent/20percent.png");
		spr2->setPosition(Point(512, 384));
		spr2->setTag(602);
		this->addChild(spr2);
	}
	else if (30 <= Singletons::getInstance()->Danger && Singletons::getInstance()->Danger < 40)
	{
		auto spr2 = CCSprite::create("Percent/30percent.png");
		spr2->setPosition(Point(512, 384));
		spr2->setTag(603);
		this->addChild(spr2);
	}
	else if (40 <= Singletons::getInstance()->Danger && Singletons::getInstance()->Danger < 50)
	{
		auto spr2 = CCSprite::create("Percent/40percent.png");
		spr2->setPosition(Point(512, 384));
		spr2->setTag(604);
		this->addChild(spr2);
	}
	else if (50 <= Singletons::getInstance()->Danger && Singletons::getInstance()->Danger < 60)
	{
		auto spr2 = CCSprite::create("Percent/50percent.png");
		spr2->setPosition(Point(512, 384));
		spr2->setTag(605);
		this->addChild(spr2);
	}
	else if (60 <= Singletons::getInstance()->Danger && Singletons::getInstance()->Danger < 70)
	{
		auto spr2 = CCSprite::create("Percent/60percent.png");
		spr2->setPosition(Point(512, 384));
		spr2->setTag(606);
		this->addChild(spr2);
	}
	else if (70 <= Singletons::getInstance()->Danger && Singletons::getInstance()->Danger < 80)
	{
		auto spr2 = CCSprite::create("Percent/70percent.png");
		spr2->setPosition(Point(512, 384));
		spr2->setTag(607);
		this->addChild(spr2);
	}
	else if (80 <= Singletons::getInstance()->Danger && Singletons::getInstance()->Danger < 90)
	{
		auto spr2 = CCSprite::create("Percent/80percent.png");
		spr2->setPosition(Point(512, 384));
		spr2->setTag(608);
		this->addChild(spr2);
	}
	else if (90 <= Singletons::getInstance()->Danger && Singletons::getInstance()->Danger < 100)
	{
		auto spr2 = CCSprite::create("Percent/90percent.png");
		spr2->setPosition(Point(512, 384));
		spr2->setTag(609);
		this->addChild(spr2);
	}
	else if (Singletons::getInstance()->Danger >= 100)
	{
		auto spr2 = CCSprite::create("Percent/100percent.png");
		spr2->setPosition(Point(512, 384));
		spr2->setTag(610);
		this->addChild(spr2);
	}
}
void hhhhhhh::onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event) // 키보드
{
	//이런 식으로 키 값에 따라 처리를 하면 된다
	auto spr = (Sprite*)this->getChildByTag(TAG_UP);
	switch (keyCode)
	{
		case EventKeyboard::KeyCode::KEY_LEFT_ARROW:
		{
			Singletons::getInstance()->Danger = Singletons::getInstance()->Danger - 10;
		}
		case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
		{
			Singletons::getInstance()->Danger += 10;
		}
	}
}
void hhhhhhh::onKeyReleased(EventKeyboard::KeyCode keyCode, Event* event)
{
	auto spr = (Sprite*)this->getChildByTag(TAG_UP);
	switch (keyCode)
	{
	case EventKeyboard::KeyCode::KEY_LEFT_ARROW:
		
		break;

	case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
		
		break;
	}
}

void hhhhhhh::click() // 버튼
{
	auto Back1 = MenuItemImage::create(
		"Shop/purchase_buy.png",
		"Shop/purchase_buypr.png",
		CC_CALLBACK_1(hhhhhhh::Pur1, this));
	Back1->setPosition(Point(870, 682));

	auto menu1 = Menu::create(Back1, NULL);
	menu1->setPosition(Vec2::ZERO);
	this->addChild(menu1, 2);
}
void hhhhhhh::Pur1(Ref * pSender) // 버튼 클릭
{
	Singletons::getInstance()->Danger = Singletons::getInstance()->Danger +  10;

	Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
	Director::getInstance()->replaceScene(hhhhhhh::createScene());
}