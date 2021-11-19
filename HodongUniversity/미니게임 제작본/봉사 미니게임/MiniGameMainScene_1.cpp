#include "MiniGameMainScene_1.h"
#include "SimpleAudioEngine.h"
#include "MiniGameEndScene.h"
// 사운드에 필요
using namespace CocosDenshion;
USING_NS_CC;

Scene* MiniGameMainScene_1::createScene()
{
    auto scene = Scene::create();
    auto layer = MiniGameMainScene_1::create();
    scene->addChild(layer);

    return scene;
}

bool MiniGameMainScene_1::init()
{

    if ( !Layer::init() )
    {
        return false;
    }

	for (int i = 0; i < 30; i++)
	{
		Garbage_1[i] = Sprite::create("ServiceMiniGame/trash.png");
		Garbage_1[i]->setAnchorPoint(Point(0.5, 0.5));
		Garbage_1[i]->setPosition(Point(10000, 10000));
		Garbage_1[i]->setScale(0.5);
		this->addChild(Garbage_1[i], 1);
	}
	for (int i = 30; i < 60; i++)
	{
		Garbage_2[i] = Sprite::create("ServiceMiniGame/cantrash.png");
		Garbage_2[i]->setAnchorPoint(Point(0.5, 0.5));
		Garbage_2[i]->setPosition(Point(20000, 20000));
		Garbage_2[i]->setScale(0.5);
		this->addChild(Garbage_2[i], 1);
	}

	visibleSize = Director::getInstance()->getVisibleSize();
	origin      = Director::getInstance()->getVisibleOrigin();

	InitBackGround();
	InitSprite();
	InitLabel();
	
	// 배경음악
	//SimpleAudioEngine::getInstance()->playBackgroundMusic("MiniGameResources/MainBackSound.mp3", true);
	// 스케쥴
	this->schedule(schedule_selector(MiniGameMainScene_1::update));
	this->schedule(schedule_selector(MiniGameMainScene_1::Score));
	this->schedule(schedule_selector(MiniGameMainScene_1::SetLabel), 1.0f);
	this->schedule(schedule_selector(MiniGameMainScene_1::SetGarbage), 0.8f);
	// 키보드 리스너
	auto keylistener = EventListenerKeyboard::create();
	keylistener->onKeyPressed = CC_CALLBACK_2(MiniGameMainScene_1::onKeyPressed, this);
	keylistener->onKeyReleased = CC_CALLBACK_2(MiniGameMainScene_1::onKeyReleased, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(keylistener, this);

    return true;
}
void MiniGameMainScene_1::update(float ft) // 씬 자체적으로 반복
{
	Sprite* chickSpr = (Sprite *)this->getChildByTag(1);

	Rect sprChick = chickSpr->getBoundingBox();

	for (int i = 0; i < 30; i++)
	{
		Rect sprGar_1 = Garbage_1[i]->getBoundingBox();

		if (sprChick.intersectsRect(sprGar_1))
		{
			GameScore += 1;
			Garbage_1[i]->setPosition(10000, 10000);

			/*SimpleAudioEngine::getInstance()->playEffect("MiniGameResources/Hit.wav");*/
		}
	}
	for (int i = 30; i < 60; i++)
	{
		Rect sprGar_2 = Garbage_2[i]->getBoundingBox();

		if (sprChick.intersectsRect(sprGar_2))
		{
			GameScore += 3;
			Garbage_2[i]->setPosition(20000, 20000);

			/*SimpleAudioEngine::getInstance()->playEffect("MiniGameResources/Hit.wav");*/
		}
	}
}

void MiniGameMainScene_1::InitBackGround() // 뒷배경
{
	auto sprite = Sprite::create("ServiceMiniGame/volunteer.png");
	sprite->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	this->addChild(sprite, 0);
}
void MiniGameMainScene_1::InitSprite() // 사람
{
	Sprite* chickSpr = Sprite::create("ServiceMiniGame/move2.png");
	chickSpr->setAnchorPoint(Point(0.5, 0));
	chickSpr->setPosition(Point(120, 100));
	chickSpr->setTag(1);
	this->addChild(chickSpr);

	//제한시간
	Sprite* time = Sprite::create("ServiceMiniGame/vol_time.png");
	time->setAnchorPoint(Point(0.5, 0));
	time->setPosition(Point(80, 550));
	//plan->setTag(44);
	this->addChild(time, 2);
	//봉사점수
	Sprite* score = Sprite::create("ServiceMiniGame/vol_score.png");
	score->setAnchorPoint(Point(0.5, 0));
	score->setPosition(Point(80, 510));
	//plan->setTag(44);
	this->addChild(score, 2);
}
void MiniGameMainScene_1::SetGarbage(float delta) // 쓰레기
{
	for (int i = 0; i < 30; i++) // 1점짜리
	{
		auto action = Place::create(Point(rand() % 40 * 25, rand() % 40 * 20));
		if (Garbage_1[i]->getPosition() == (Vec2(10000, 10000)))
		{
			Garbage_1[i]->runAction(action);
			break;
		}
	}
	for (int i = 30; i < 60; i++) // 3점짜리
	{
		auto action2 = Place::create(Point(rand() % 40 * 25, rand() % 40 * 20));
		if (Garbage_2[i]->getPosition() == (Vec2(20000, 20000)))
		{
			Garbage_2[i]->runAction(action2);
			break;
		}
	}
}
void MiniGameMainScene_1::InitLabel() // 시간, 점수 설정
{
	Label* label = Label::createWithTTF(StringUtils::format(""), "MiniGameResources/CuteFont.ttf", 30);
	label->setAnchorPoint(Point(0, 1));
	label->setPosition(Point(135, 584));
	label->setColor(Color3B::RED);
	label->setTag(10);
	this->addChild(label, 2);

	Label* Score = Label::createWithTTF(StringUtils::format("", GameScore), "MiniGameResources/CuteFont.ttf", 30);
	Score->setAnchorPoint(Point(0, 1));
	Score->setPosition(Point(135, 544));
	Score->setColor(Color3B::RED);
	Score->setTag(20);
	this->addChild(Score, 2);
}
void MiniGameMainScene_1::SetLabel(float delta) // 시간 변화
{
	static int currClock = 30;
	currClock -= 1;

	Label* label = (Label*)this->getChildByTag(10);
	label->setString(StringUtils::format("%d", currClock));

	if (currClock == 0) // 시간이 다 될 경우
	{
		currClock = 30;
		Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
		Director::getInstance()->replaceScene(MiniGameEndScene::createScene());
	}
}
void MiniGameMainScene_1::Score(float ft) // 점수 변화
{
	Label* label = (Label*)this->getChildByTag(20);
	label->setString(StringUtils::format("%d", GameScore));
}
void MiniGameMainScene_1::onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event) // 방향키 처리
{
	auto spr = (Sprite*)this->getChildByTag(1);
	switch (keyCode)
	{
		case EventKeyboard::KeyCode::KEY_LEFT_ARROW:
		{
			spr->setRotationY(180);
			auto action_0 = MoveBy::create(1, Point(-150, 0));
			auto action_1 = RepeatForever::create(action_0);
			action_1->setTag(3);
			spr->runAction(action_1);

			Animation* ani = Animation::create();
			ani->setDelayPerUnit(0.2f);

			for (int i = 0; i < 3; i++) {
				ani->addSpriteFrameWithFile(StringUtils::format("ServiceMiniGame/move1.png", i + 1));
			}
			ani->addSpriteFrameWithFile("ServiceMiniGame/move3.png");

			Animate*		anim = Animate::create(ani);
			RepeatForever*	action = RepeatForever::create(anim);
			action->setTag(20);
			spr->runAction(action);

			break;
		}
		case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
		{
			spr->setRotationY(0);
			auto action_2 = MoveBy::create(1, Point(150, 0));
			auto action_3 = RepeatForever::create(action_2);
			action_3->setTag(4);
			spr->runAction(action_3);

			Animation* ani = Animation::create();
			ani->setDelayPerUnit(0.2f);

			for (int i = 0; i < 3; i++) {
				ani->addSpriteFrameWithFile(StringUtils::format("ServiceMiniGame/move1.png", i + 1));
			}
			ani->addSpriteFrameWithFile("ServiceMiniGame/move3.png");

			Animate*		anim = Animate::create(ani);
			RepeatForever*	action = RepeatForever::create(anim);
			action->setTag(21);
			spr->runAction(action);

			break;
		}
		case EventKeyboard::KeyCode::KEY_UP_ARROW:
		{
			auto action_4 = MoveBy::create(1, Point(0, 150));
			auto action_5 = RepeatForever::create(action_4);
			action_5->setTag(5);
			spr->runAction(action_5);

			Animation* ani = Animation::create();
			ani->setDelayPerUnit(0.2f);

			for (int i = 0; i < 3; i++) {
				ani->addSpriteFrameWithFile(StringUtils::format("ServiceMiniGame/move1.png", i + 1));
			}
			ani->addSpriteFrameWithFile("ServiceMiniGame/move3.png");

			Animate*		anim = Animate::create(ani);
			RepeatForever*	action = RepeatForever::create(anim);
			action->setTag(22);
			spr->runAction(action);

			break;
		}
		case EventKeyboard::KeyCode::KEY_DOWN_ARROW:
		{
			auto action_6 = MoveBy::create(1, Point(0, -150));
			auto action_7 = RepeatForever::create(action_6);
			action_7->setTag(6);
			spr->runAction(action_7);

			Animation* ani = Animation::create();
			ani->setDelayPerUnit(0.2f);

			for (int i = 0; i < 3; i++) {
				ani->addSpriteFrameWithFile(StringUtils::format("ServiceMiniGame/move1.png", i + 1));
			}
			ani->addSpriteFrameWithFile("ServiceMiniGame/move3.png");

			Animate*		anim = Animate::create(ani);
			RepeatForever*	action = RepeatForever::create(anim);
			action->setTag(23);
			spr->runAction(action);

			break;
		}
	}
}
void MiniGameMainScene_1::onKeyReleased(EventKeyboard::KeyCode keyCode, Event* event)
{
	auto spr = (Sprite*)this->getChildByTag(1);
	switch (keyCode)
	{
	case EventKeyboard::KeyCode::KEY_LEFT_ARROW:
		spr->stopActionByTag(3);
		spr->stopActionByTag(20);
		break;
	case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
		spr->stopActionByTag(4);
		spr->stopActionByTag(21);
		break;
	case EventKeyboard::KeyCode::KEY_UP_ARROW:
		spr->stopActionByTag(5);
		spr->stopActionByTag(22);
		break;
	case EventKeyboard::KeyCode::KEY_DOWN_ARROW:
		spr->stopActionByTag(6);
		spr->stopActionByTag(23);
		break;
	}
}