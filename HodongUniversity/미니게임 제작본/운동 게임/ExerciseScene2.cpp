#include "ExerciseScene2.h"
#include "EndScene.h"
#include "SimpleAudioEngine.h"
#include "singleton.h"

//사운드 할라면 꼭 필요
using namespace CocosDenshion;
USING_NS_CC;

Scene* ExerciseScene2::createScene()
{
    auto scene = Scene::create();
    auto layer = ExerciseScene2::create();
    scene->addChild(layer);

    return scene;
}

bool ExerciseScene2::init()
{

    if ( !Layer::init() )
    {
        return false;
    }

	initBG();
	initLabel();
	initChar();
	Gauge();

	//배경음악
	//SimpleAudioEngine::getInstance()->playBackgroundMusic("MiniGameResources/MainBackSound.mp3", true);

	//키보드 리스너
	auto keylistener = EventListenerKeyboard::create();
	keylistener->onKeyPressed = CC_CALLBACK_2(ExerciseScene2::onKeyPressed, this);
	keylistener->onKeyReleased = CC_CALLBACK_2(ExerciseScene2::onKeyReleased, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(keylistener, this);

	this->schedule(schedule_selector(ExerciseScene2::update));
	this->schedule(schedule_selector(ExerciseScene2::GaugeDown), 1.0f);
	this->schedule(schedule_selector(ExerciseScene2::GaugeUp));

    return true;
}
void ExerciseScene2::update(float ft)
{
	Sprite* spr = (Sprite*)this->getChildByTag(590);

	if (Tra >= 100) // 게이지 100
	{
		line = false;

		auto spr3 = CCSprite::create("ExerciseGame/practice3.png");
		spr3->setPosition(Point(472, 424));
		spr3->setTag(591);
		spr3->setOpacity(0);
		this->addChild(spr3);

		Sprite* action4 = (Sprite*)this->getChildByTag(590);
		action4->setOpacity(0);
		Sprite* action5 = (Sprite*)this->getChildByTag(591);
		action5->setOpacity(255);

		auto spr = CCSprite::create("ExerciseGame/clear.png");
		spr->setPosition(Point(512, 384));
		spr->setOpacity(0);
		this->addChild(spr);

		auto action_fadein = FadeIn::create(1.5f);
		spr->runAction(action_fadein);

		this->scheduleOnce(schedule_selector(ExerciseScene2::endGame), 1.0f);
	}
}
void ExerciseScene2::endGame(float delta)
{
	Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
	Director::getInstance()->replaceScene(ExerciseScene2::createScene());
}
void ExerciseScene2::initBG() // 배경
{
	auto spr = CCSprite::create("ExerciseGame/practice_back.png");
	spr->setPosition(Point(512, 384));
	this->addChild(spr);
}
void ExerciseScene2::initChar() // 캐릭터 애니메이션
{
	auto spr1 = CCSprite::create("ExerciseGame/practice2.png");
	spr1->setPosition(Point(472, 424));
	spr1->setTag(590);
	this->addChild(spr1);

	Animation* ani = Animation::create();
	ani->setDelayPerUnit(0.3);

	for (int i = 0; i < 3; i++) {
		ani->addSpriteFrameWithFile(StringUtils::format("ExerciseGame/practice1.png", i + 1));
	}
	ani->addSpriteFrameWithFile("ExerciseGame/practice2.png");

	Animate*		anim = Animate::create(ani);
	RepeatForever*	action = RepeatForever::create(anim);
	spr1->runAction(action);
}
void ExerciseScene2::Gauge() // 게이지 칸
{
	auto spr1 = CCSprite::create("ExerciseGame/gauge0.png");
	spr1->setPosition(Point(762, 334));
	spr1->setTag(600);
	this->addChild(spr1);
}
void ExerciseScene2::GaugeUp(float delta) // 게이지 상승
{
	if (10 <= Tra && Tra < 20)
	{
		Sprite* spr1 = (Sprite*)this->getChildByTag(600);
		spr1->setOpacity(0);

		auto spr2 = CCSprite::create("ExerciseGame/gauge1.png");
		spr2->setPosition(Point(762, 334));
		spr2->setTag(601);
		this->addChild(spr2);
	}
	else if (20 <= Tra && Tra < 30)
	{
		Sprite* spr1 = (Sprite*)this->getChildByTag(601);
		spr1->setOpacity(0);

		auto spr2 = CCSprite::create("ExerciseGame/gauge2.png");
		spr2->setPosition(Point(762, 334));
		spr2->setTag(602);
		this->addChild(spr2);
	}
	else if (30 <= Tra && Tra < 40)
	{
		Sprite* spr1 = (Sprite*)this->getChildByTag(602);
		spr1->setOpacity(0);

		auto spr2 = CCSprite::create("ExerciseGame/gauge3.png");
		spr2->setPosition(Point(762, 334));
		spr2->setTag(603);
		this->addChild(spr2);
	}
	else if (40 <= Tra && Tra < 50)
	{
		Sprite* spr1 = (Sprite*)this->getChildByTag(603);
		spr1->setOpacity(0);

		auto spr2 = CCSprite::create("ExerciseGame/gauge4.png");
		spr2->setPosition(Point(762, 334));
		spr2->setTag(604);
		this->addChild(spr2);
	}
	else if (50 <= Tra && Tra < 60)
	{
		Sprite* spr1 = (Sprite*)this->getChildByTag(604);
		spr1->setOpacity(0);

		auto spr2 = CCSprite::create("ExerciseGame/gauge5.png");
		spr2->setPosition(Point(762, 334));
		spr2->setTag(605);
		this->addChild(spr2);
	}
	else if (60 <= Tra && Tra < 70)
	{
		Sprite* spr1 = (Sprite*)this->getChildByTag(605);
		spr1->setOpacity(0);

		auto spr2 = CCSprite::create("ExerciseGame/gauge6.png");
		spr2->setPosition(Point(762, 334));
		spr2->setTag(606);
		this->addChild(spr2);
	}
	else if (70 <= Tra && Tra < 80)
	{
		Sprite* spr1 = (Sprite*)this->getChildByTag(606);
		spr1->setOpacity(0);

		auto spr2 = CCSprite::create("ExerciseGame/gauge7.png");
		spr2->setPosition(Point(762, 334));
		spr2->setTag(607);
		this->addChild(spr2);
	}
	else if (80 <= Tra && Tra < 90)
	{
		Sprite* spr1 = (Sprite*)this->getChildByTag(607);
		spr1->setOpacity(0);

		auto spr2 = CCSprite::create("ExerciseGame/gauge8.png");
		spr2->setPosition(Point(762, 334));
		spr2->setTag(608);
		this->addChild(spr2);
	}
	else if (90 <= Tra && Tra < 100)
	{
		Sprite* spr1 = (Sprite*)this->getChildByTag(608);
		spr1->setOpacity(0);

		auto spr2 = CCSprite::create("ExerciseGame/gauge9.png");
		spr2->setPosition(Point(762, 334));
		spr2->setTag(609);
		this->addChild(spr2);
	}
	else if (Tra >= 100)
	{
		Sprite* spr1 = (Sprite*)this->getChildByTag(609);
		spr1->setOpacity(0);

		auto spr2 = CCSprite::create("ExerciseGame/gauge10.png");
		spr2->setPosition(Point(762, 334));
		spr2->setTag(610);
		this->addChild(spr2);
	}
}
void ExerciseScene2::GaugeDown(float delta) // 게이지 하락
{
	if (Tra == 0)
	{
		Tra -= 0;
	}
	else if (line == true)
	{
		Tra -= 3;
	}
	else if (line == false)
	{
		Tra -= 0;
	}
}
void ExerciseScene2::initLabel() // 설명
{
	char Q1[200];
	WideCharToMultiByte(CP_UTF8, 0, L"키보드 양쪽 키를 연타해 호동이를 운동시키세요!!", -1, Q1, 200, NULL, NULL);
	auto EX = Label::createWithTTF(Q1, "ExerciseGame/ABC.ttf", 40);
	EX->setAnchorPoint(Point(0.5, 0.5));
	EX->setPosition(Point(512, 650));
	EX->setColor(Color3B::RED);
	this->addChild(EX, 2);
}
void ExerciseScene2::onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event) // 키보드
{
	//이런 식으로 키 값에 따라 처리를 하면 된다
	auto spr = (Sprite*)this->getChildByTag(TAG_UP);
	switch (keyCode)
	{
		case EventKeyboard::KeyCode::KEY_LEFT_ARROW:
		{
			if (line == true)
			{
				Tra += 2;
				break;
			}
			else if (line == false)
			{
				Tra += 0;
			}
		}
		case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
		{
			if (line == true)
			{
				Tra += 2;
				break;
			}
			else if (line == false)
			{
				Tra += 0;
			}
		}
	}
}
void ExerciseScene2::onKeyReleased(EventKeyboard::KeyCode keyCode, Event* event)
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