#include "AlbaScene.h"
#include "AlbaEndScene.h"
#include "SimpleAudioEngine.h"
#include <stdlib.h>
#include "singleton.h"

//���� �Ҷ�� �� �ʿ�
using namespace CocosDenshion;
USING_NS_CC;

Scene* AlbaScene::createScene()
{
    auto scene = Scene::create();
    auto layer = AlbaScene::create();
    scene->addChild(layer);

    return scene;
}

bool AlbaScene::init()
{
	srand((unsigned)time(NULL));

    if ( !Layer::init() )
    {
        return false;
    }

	initBG();
	Released();
	initMove(); 
	TimeLimit();
	initLabel();

	// �巡�� �׼�
	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = CC_CALLBACK_2(AlbaScene::onTouchBegan, this);
	listener->onTouchMoved = CC_CALLBACK_2(AlbaScene::onTouchMoved, this);
	listener->onTouchEnded = CC_CALLBACK_2(AlbaScene::onTouchEnded, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

	sprReady(); // READY ȿ�� ó��
	this->scheduleOnce(schedule_selector(AlbaScene::sprStart), 1.1f); // GO ȿ�� ������ ó��
	this->schedule(schedule_selector(AlbaScene::SetLabel), 1.0f); // �ð� ������ ó��
	this->schedule(schedule_selector(AlbaScene::SetLabel2)); // ���� ������ ó��

    return true;
}
void AlbaScene::initBG() // ���
{
	auto spr = CCSprite::create("AlbaGame/ministop.png");
	spr->setPosition(Point(512, 384));
	this->addChild(spr);
}
void AlbaScene::sprReady() // �غ� �ΰ�
{
	auto sprite = Sprite::create("AlbaGame/ready.png");
	sprite->setPosition(Point(512, 384));
	sprite->setOpacity(0);
	this->addChild(sprite);

	auto action_fadein = FadeIn::create(1.0f);
	auto action_fadeout = FadeOut::create(0.1f);
	auto action_seq = Sequence::create(action_fadein, action_fadeout, NULL);
	sprite->runAction(action_seq);
}
void AlbaScene::sprStart(float delta) // ���� �ΰ�
{
	auto sprite = Sprite::create("AlbaGame/go.png");
	sprite->setPosition(Point(512, 384));
	sprite->setOpacity(0);
	this->addChild(sprite);

	auto action_fadein = FadeIn::create(1.0f);
	auto action_fadeout = FadeOut::create(0.1f);
	auto action_seq = Sequence::create(action_fadein, action_fadeout, NULL);
	sprite->runAction(action_seq);
}
void AlbaScene::TimeLimit() // �ð� ����, �ű� ����
{
	char Q1[200];
	WideCharToMultiByte(CP_UTF8, 0, L"���� �ð� : ", -1, Q1, 200, NULL, NULL);
	auto Time = Label::createWithTTF(Q1, "AlbaGame/ABC.ttf", 30);
	Time->setAnchorPoint(Point(0, 1));
	Time->setPosition(Point(90, 200));
	Time->setColor(Color3B::RED);
	this->addChild(Time, 2);

	WideCharToMultiByte(CP_UTF8, 0, L"�ű� ���� : ", -1, Q1, 200, NULL, NULL);
	auto Score = Label::createWithTTF(Q1, "AlbaGame/ABC.ttf", 30);
	Score->setAnchorPoint(Point(0, 1));
	Score->setPosition(Point(90, 150));
	Score->setColor(Color3B::RED);
	this->addChild(Score, 2);

	WideCharToMultiByte(CP_UTF8, 0, L"�ִ��� ���� ������ �˸��� ��ġ�� �ű⼼��!! ", -1, Q1, 200, NULL, NULL);
	auto EX = Label::createWithTTF(Q1, "AlbaGame/ABC.ttf", 30);
	EX->setAnchorPoint(Point(0, 1));
	EX->setPosition(Point(412, 50));
	EX->setColor(Color3B::RED);
	this->addChild(EX, 2);
}
void AlbaScene::initLabel() // ���� �ð�, ���� Ȯ��
{
	Label* label = Label::createWithTTF(StringUtils::format(""), "AlbaGame/ABC.ttf", 30);
	label->setAnchorPoint(Point(0, 1));
	label->setPosition(Point(250, 200));
	label->setColor(Color3B::RED);
	label->setTag(618);
	this->addChild(label, 2);

	Label* label2 = Label::createWithTTF(StringUtils::format(""), "AlbaGame/ABC.ttf", 30);
	label2->setAnchorPoint(Point(0, 1));
	label2->setPosition(Point(250, 150));
	label2->setColor(Color3B::RED);
	label2->setTag(619);
	this->addChild(label2, 2);
}
void AlbaScene::SetLabel(float delta) // �ð� ��ȭ
{
	Singletons::getInstance()->aurrClock = UserDefault::getInstance()->getIntegerForKey("aurrClock") - 1;
	UserDefault::getInstance()->setIntegerForKey("aurrClock", Singletons::getInstance()->aurrClock);
	UserDefault::getInstance()->flush();

	Label* label = (Label*)this->getChildByTag(618);
	label->setString(StringUtils::format("%d", Singletons::getInstance()->aurrClock));

	if (Singletons::getInstance()->aurrClock == 0) // �ð��� �� �� ���
	{
		Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
		auto scene = TransitionCrossFade::create(1.5, AlbaEndScene::createScene());
		Director::getInstance()->replaceScene(scene);
	}
}
void AlbaScene::SetLabel2(float delta) // ���� ����
{
	Label* label = (Label*)this->getChildByTag(619);
	label->setString(StringUtils::format("%d", Singletons::getInstance()->Many));
}
void AlbaScene::Released() // ���� ����
{
	auto spr = Sprite::create("AlbaGame/albaicon1on.png");
	spr->setPosition(Point(100, 650));
	spr->setTag(615);
	this->addChild(spr);

	auto spr2 = Sprite::create("AlbaGame/albaicon2on.png");
	spr2->setPosition(Point(512, 650));
	spr2->setTag(616);
	this->addChild(spr2);

	auto spr3 = Sprite::create("AlbaGame/albaicon3on.png");
	spr3->setPosition(Point(924, 650));
	spr3->setTag(617);
	this->addChild(spr3);
}
void AlbaScene::initMove() // ������ �͵�
{
	i = rand() % 3 + 1;

	if (i == 1)
	{
		auto move1 = Sprite::create("AlbaGame/albaicon1.png");
		move1->setAnchorPoint(Point(0.5, 0.5));
		move1->setTag(611);
		move1->setPosition(Point(512, 100));
		move1->getBoundingBox();
		this->addChild(move1, 1);
	}
	else if (i == 2)
	{
		auto move2 = Sprite::create("AlbaGame/albaicon2.png");
		move2->setAnchorPoint(Point(0.5, 0.5));
		move2->setTag(612);
		move2->setPosition(Point(512, 100));
		move2->getBoundingBox();
		this->addChild(move2, 1);
	}
	else if (i == 3)
	{
		auto move3 = Sprite::create("AlbaGame/albaicon3.png");
		move3->setAnchorPoint(Point(0.5, 0.5));
		move3->setTag(613);
		move3->setPosition(Point(512, 100));
		move3->getBoundingBox();
		this->addChild(move3, 1);
	}
}
bool AlbaScene::onTouchBegan(Touch *touch, Event *event) // ���콺 Ŭ��
{
	if (click == false)
	{
		if (i == 1)
		{
			Point location = touch->getLocation();

			auto move1 = (Sprite*)this->getChildByTag(611);
			if (move1->getPositionX() <= location.x + 100 && move1->getPositionX() >= location.x - 100 &
				move1->getPositionY() <= location.y + 100 && move1->getPositionY() >= location.y - 100)
			{
				click = true;
			}
		}
		else if (i == 2)
		{
			Point location = touch->getLocation();

			auto move2 = (Sprite*)this->getChildByTag(612);
			if (move2->getPositionX() <= location.x + 150 && move2->getPositionX() >= location.x - 150 &
				move2->getPositionY() <= location.y + 150 && move2->getPositionY() >= location.y - 150)
			{
				click = true;
			}
		}
		else if (i == 3)
		{
			Point location = touch->getLocation();

			auto move3 = (Sprite*)this->getChildByTag(613);
			if (move3->getPositionX() <= location.x + 150 && move3->getPositionX() >= location.x - 150 &
				move3->getPositionY() <= location.y + 150 && move3->getPositionY() >= location.y - 150)
			{
				click = true;
			}
		}
		return true;
	}
}
void AlbaScene::onTouchMoved(Touch *touch, Event *event) // ���콺 �巡��
{
	if (click == true)
	{
		if (i == 1)
		{
			Point location = touch->getLocation();
			auto Obj = (Sprite*)this->getChildByTag(611);
			Obj->setPosition(location); // �巡��

			Sprite* R1 = (Sprite*)this->getChildByTag(615);
			Rect   rect_1 = R1->getBoundingBox(); // 1�� �浹����
			Sprite* R2 = (Sprite*)this->getChildByTag(616);
			Rect   rect_2 = R2->getBoundingBox(); // 2�� �浹����
			Sprite* R3 = (Sprite*)this->getChildByTag(617);
			Rect   rect_3 = R3->getBoundingBox(); // 3�� �浹����

			if (rect_1.containsPoint(location)) // 1�� �浹��
			{
				click = false;
				removeChildByTag(611);

				auto spr = CCSprite::create("AlbaGame/o.png");
				spr->setPosition(Point(512, 384));
				spr->setOpacity(0);
				this->addChild(spr);

				auto action_fadein = FadeIn::create(0.5f);
				auto action_fadeout = FadeOut::create(0.1f);
				auto action_seq = Sequence::create(action_fadein, action_fadeout, NULL);
				spr->runAction(action_seq);

				Singletons::getInstance()->Many = UserDefault::getInstance()->getIntegerForKey("Many") + 1;
				UserDefault::getInstance()->setIntegerForKey("Many", Singletons::getInstance()->Many);
				UserDefault::getInstance()->flush();

				initMove();
			}
			if (rect_2.containsPoint(location)) // 2�� �浹��
			{
				click = false;
				removeChildByTag(611);

				auto spr = CCSprite::create("AlbaGame/x.png");
				spr->setPosition(Point(512, 384));
				spr->setOpacity(0);
				this->addChild(spr);

				auto action_fadein = FadeIn::create(0.5f);
				auto action_fadeout = FadeOut::create(0.1f);
				auto action_seq = Sequence::create(action_fadein, action_fadeout, NULL);
				spr->runAction(action_seq);

				initMove();
			}
			if (rect_3.containsPoint(location)) // 3�� �浹��
			{
				click = false;
				removeChildByTag(611);

				auto spr = CCSprite::create("AlbaGame/x.png");
				spr->setPosition(Point(512, 384));
				spr->setOpacity(0);
				this->addChild(spr);

				auto action_fadein = FadeIn::create(0.5f);
				auto action_fadeout = FadeOut::create(0.1f);
				auto action_seq = Sequence::create(action_fadein, action_fadeout, NULL);
				spr->runAction(action_seq);

				initMove();
			}
		}
		else if (i == 2)
		{
			Point location = touch->getLocation();
			auto Obj = (Sprite*)this->getChildByTag(612);
			Obj->setPosition(location);; // �巡��

			Sprite* R1 = (Sprite*)this->getChildByTag(615);
			Rect   rect_1 = R1->getBoundingBox(); // 1�� �浹����
			Sprite* R2 = (Sprite*)this->getChildByTag(616);
			Rect   rect_2 = R2->getBoundingBox(); // 2�� �浹����
			Sprite* R3 = (Sprite*)this->getChildByTag(617);
			Rect   rect_3 = R3->getBoundingBox(); // 3�� �浹����

			if (rect_1.containsPoint(location)) // 1�� �浹��
			{
				click = false;
				removeChildByTag(612);

				auto spr = CCSprite::create("AlbaGame/x.png");
				spr->setPosition(Point(512, 384));
				spr->setOpacity(0);
				this->addChild(spr);

				auto action_fadein = FadeIn::create(0.5f);
				auto action_fadeout = FadeOut::create(0.1f);
				auto action_seq = Sequence::create(action_fadein, action_fadeout, NULL);
				spr->runAction(action_seq);

				initMove();
			}
			if (rect_2.containsPoint(location)) // 2�� �浹��
			{
				click = false;
				removeChildByTag(612);

				auto spr = CCSprite::create("AlbaGame/o.png");
				spr->setPosition(Point(512, 384));
				spr->setOpacity(0);
				this->addChild(spr);

				auto action_fadein = FadeIn::create(0.5f);
				auto action_fadeout = FadeOut::create(0.1f);
				auto action_seq = Sequence::create(action_fadein, action_fadeout, NULL);
				spr->runAction(action_seq);

				Singletons::getInstance()->Many = UserDefault::getInstance()->getIntegerForKey("Many") + 1;
				UserDefault::getInstance()->setIntegerForKey("Many", Singletons::getInstance()->Many);
				UserDefault::getInstance()->flush();

				initMove();
			}
			if (rect_3.containsPoint(location)) // 3�� �浹��
			{
				click = false;
				removeChildByTag(612);

				auto spr = CCSprite::create("AlbaGame/x.png");
				spr->setPosition(Point(512, 384));
				spr->setOpacity(0);
				this->addChild(spr);

				auto action_fadein = FadeIn::create(0.5f);
				auto action_fadeout = FadeOut::create(0.1f);
				auto action_seq = Sequence::create(action_fadein, action_fadeout, NULL);
				spr->runAction(action_seq);

				initMove();
			}
		}
		else if (i == 3)
		{
			Point location = touch->getLocation();
			auto Obj = (Sprite*)this->getChildByTag(613);
			Obj->setPosition(location); // �巡��

			Sprite* R1 = (Sprite*)this->getChildByTag(615);
			Rect   rect_1 = R1->getBoundingBox(); // 1�� �浹����
			Sprite* R2 = (Sprite*)this->getChildByTag(616);
			Rect   rect_2 = R2->getBoundingBox(); // 2�� �浹����
			Sprite* R3 = (Sprite*)this->getChildByTag(617);
			Rect   rect_3 = R3->getBoundingBox(); // 3�� �浹����

			if (rect_1.containsPoint(location)) // 1�� �浹��
			{
				click = false;
				removeChildByTag(613);

				auto spr = CCSprite::create("AlbaGame/x.png");
				spr->setPosition(Point(512, 384));
				spr->setOpacity(0);
				this->addChild(spr);

				auto action_fadein = FadeIn::create(0.5f);
				auto action_fadeout = FadeOut::create(0.1f);
				auto action_seq = Sequence::create(action_fadein, action_fadeout, NULL);
				spr->runAction(action_seq);

				initMove();
			}
			if (rect_2.containsPoint(location)) // 2�� �浹��
			{
				click = false;
				removeChildByTag(613);

				auto spr = CCSprite::create("AlbaGame/x.png");
				spr->setPosition(Point(512, 384));
				spr->setOpacity(0);
				this->addChild(spr);

				auto action_fadein = FadeIn::create(0.5f);
				auto action_fadeout = FadeOut::create(0.1f);
				auto action_seq = Sequence::create(action_fadein, action_fadeout, NULL);
				spr->runAction(action_seq);

				initMove();
			}
			if (rect_3.containsPoint(location)) // 3�� �浹��
			{
				click = false;
				removeChildByTag(613);

				auto spr = CCSprite::create("AlbaGame/o.png");
				spr->setPosition(Point(512, 384));
				spr->setOpacity(0);
				this->addChild(spr);

				auto action_fadein = FadeIn::create(0.5f);
				auto action_fadeout = FadeOut::create(0.1f);
				auto action_seq = Sequence::create(action_fadein, action_fadeout, NULL);
				spr->runAction(action_seq);

				Singletons::getInstance()->Many = UserDefault::getInstance()->getIntegerForKey("Many") + 1;
				UserDefault::getInstance()->setIntegerForKey("Many", Singletons::getInstance()->Many);
				UserDefault::getInstance()->flush();

				initMove();
			}
		}
	}
}
void AlbaScene::onTouchEnded(Touch *touch, Event *event) // ���콺 Ŭ�� ����
{
	if (i == 1)
	{
		auto Obj = (Sprite*)this->getChildByTag(611);
		Obj->setPosition(Point(512, 100));
		
		click = false;
	}
	else if (i == 2)
	{
		auto Obj = (Sprite*)this->getChildByTag(612);
		Obj->setPosition(Point(512, 100));
		
		click = false;
	}
	else if (i == 3)
	{
		auto Obj = (Sprite*)this->getChildByTag(613);
		Obj->setPosition(Point(512, 100));

		click = false;
	}
}