#include "MainScene.h"
#include "EndScene.h"
#include "SimpleAudioEngine.h"
#include <stdlib.h>
#include "singleton.h"

//사운드 할라면 꼭 필요
using namespace CocosDenshion;
USING_NS_CC;

Scene* MainScene::createScene()
{
    auto scene = Scene::create();
    auto layer = MainScene::create();
    scene->addChild(layer);

    return scene;
}
bool MainScene::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
	//터치 리스너 등록
	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = CC_CALLBACK_2(MainScene::onTouchBegan, this);
	Director::getInstance()->getEventDispatcher()->addEventListenerWithFixedPriority(listener, 1);

	isTouch = false;

	initBG();
	life;
	card[8];
	countCard;

	initLabel();
	initGameData();
	initTopMenuLabel();
	initCard();
	initO();
	initX();

	sprReady();
	this->scheduleOnce(schedule_selector(MainScene::sprStart), 1.1f); // GO 효과 스케줄 처리
	this->scheduleOnce(schedule_selector(MainScene::actionCard), 2.2f); // 카드 오픈 처리
	this->scheduleOnce(schedule_selector(MainScene::endCard), 6.2f); // 순서 확인 후 시작 처리

    return true;
}
bool MainScene::onTouchBegan(Touch * touch, Event * unused_event) // 터치 리스너
{
	if (!isTouch) return true;

	Point location = touch->getLocation();

	for (int i = 0; i < 14; i++)
	{
		auto spr = (Sprite*)this->getChildByTag(TAG_SPRITE_CARD + i);
		Rect sprRect = spr->getBoundingBox();

		if (sprRect.containsPoint(location))
		{
			isTouch = false;
			auto action = Sequence::create(Show::create(),
				DelayTime::create(0.5), Hide::create(), NULL);
			spr->runAction(action);

			if (i == card[countCard])
			{
				Singletons::getInstance()->CardOK ++;
				countCard++;
				if (Singletons::getInstance()->CardOK == 8)
				{
					actionGameEnd(true);
				}
				setLabelCard();
				actionOX(true);
			}
			else
			{
				life--;
				if (life == 0)
				{
					actionGameEnd(false);
				}
				setLabelLife();
				actionOX(false);
			}
		}
	}
	return false;
}
void MainScene::initBG() // 배경
{
	auto spr = CCSprite::create("CardGame_2/black_board_2.png");
	spr->setPosition(Point(512, 384));
	this->addChild(spr);
}
void MainScene::initLabel() // 설명
{
	char EX_1[300];
	WideCharToMultiByte(CP_UTF8, 0, L"1초간 뒤집어지는 8장의 카드의 순서를 보고, 뒤집힌 순서대로 누르세요!\n(* 카드가 같은 곳에 머무르면 그곳을 두번 클릭하세요)", -1, EX_1, 300, NULL, NULL);
	auto EX = Label::createWithTTF(EX_1, "CardGame_2/ABC.ttf", 27);
	EX->setAnchorPoint(Point(0, 1));
	EX->setPosition(Point(90, 650));
	EX->setColor(Color3B::BLACK);
	this->addChild(EX, 2);
}
void MainScene::initGameData()
{
	winSize = Director::getInstance()->getWinSize();

	Singletons::getInstance()->CardOK;
	life = 3;
	srand(time(NULL));

	for (int i = 0; i < 8; i++)
	{
		card[i] = rand() % 14;
	}
	countCard = 0;
}
void MainScene::initTopMenuLabel() // 카드 수, 생명 상단 배치
{
	auto label_0 = Label::createWithSystemFont("", "", 20);
	label_0->setAnchorPoint(Point(0, 1));
	label_0->setPosition(Point(10,	winSize.height - 10));
	label_0->setTag(TAG_LABEL_CARD);
	label_0->setColor(Color3B::RED);
	this->addChild(label_0, 1);

	auto label_1 = Label::createWithSystemFont("", "", 20);
	label_1->setAnchorPoint(Point(1, 1));
	label_1->setPosition(Point(winSize.width - 10, winSize.height - 10));
	label_1->setTag(TAG_LABEL_LlFE);
	label_1->setColor(Color3B::RED);
	this ->addChild(label_1);

	setLabelCard();
	setLabelLife();
}
void MainScene::setLabelCard() // 카드 수
{
	auto label = (Label*)this->getChildByTag(TAG_LABEL_CARD);
	label->setString(StringUtils::format("CARD : %d/8", Singletons::getInstance()->CardOK));
}
void MainScene::setLabelLife() // 생명 수
{
	auto label = (Label*)this->getChildByTag(TAG_LABEL_LlFE);
	label->setString(StringUtils::format("LIFE : %d", life));
}
void MainScene::initCard() // 카드 배치
{
	for (int i = 0; i < 14; i++) // 2줄로 총 14장
	{
		auto spr = Sprite::create("CardGame_2/Card.png"); // 뒷면
		spr->setPosition(Point(210 - 60 + 60 * 2 * (i / 2),
			winSize.height / 2.5 + 120 - 120 * (i % 2)));
		this->addChild(spr);

		auto sprFront = Sprite::create(StringUtils::format("CardGame_2/DeathWing.png", (i + 1))); // 앞면
		sprFront->setPosition(Point(210 - 60 + 60 * 2 * (i / 2),
			winSize.height / 2.5 + 120 - 120 * (i % 2)));
		sprFront->setVisible(false);
		sprFront->setTag(TAG_SPRITE_CARD + i);
		this->addChild(sprFront);
	}
}
void MainScene::sprReady() // 준비 로고
{
	auto sprite = Sprite::create("CardGame_2/ready.png");
	sprite->setPosition(Point(winSize.width / 2, winSize.height / 2));
	sprite->setOpacity(0);
	this->addChild(sprite);

	auto action_fadein = FadeIn::create(1.0f);
	auto action_fadeout = FadeOut::create(0.1f);
	auto action_seq = Sequence::create(action_fadein, action_fadeout, NULL);
	sprite->runAction(action_seq);
}
void MainScene::sprStart(float delta) // 시작 로고
{
	auto sprite = Sprite::create("CardGame_2/go.png");
	sprite->setPosition(Point(winSize.width / 2, winSize.height / 2));
	sprite->setOpacity(1);
	this->addChild(sprite);

	auto action_fadein = FadeIn::create(1.0f);
	auto action_fadeout = FadeOut::create(0.1f);
	auto action_seq = Sequence::create(action_fadein, action_fadeout, NULL);
	sprite->runAction(action_seq);
}
void MainScene::actionCard(float delta) // 카드 오픈
{
	for (int i = 0; i < 8; i++)
	{
		auto action = Sequence::create(DelayTime::create(1.0*i),
			Show::create(),
			DelayTime::create(1.0),
			Hide::create(), NULL);
		auto spr = (Sprite*)this->getChildByTag(TAG_SPRITE_CARD + card[i]);
		spr->runAction(action);
	}
}
void MainScene::endCard(float delta)
{
	isTouch = true;
}
void MainScene::initO() // 맞으면 O창이 나옴
{
	auto spr = Sprite::create("CardGame_2/o.png");
	spr->setPosition(Point(winSize.width / 2, winSize.height / 2));
	spr->setTag(TAG_SPRITE_O);
	spr->setVisible(false);
	this->addChild(spr);
}
void MainScene::initX() // 틀리면 X창이 나옴
{
	auto spr = Sprite::create("CardGame_2/x.png");
	spr->setPosition(Point(winSize.width / 2, winSize.height / 2));
	spr->setTag(TAG_SPRlTE_X);
	spr->setVisible(false);
	this->addChild(spr);
}
void MainScene::actionOX(bool isO) // OX창 관리
{
	auto action = Sequence::create(Show::create(), DelayTime::create(0.3), Hide::create(),
		CallFunc::create(CC_CALLBACK_0(MainScene::endOX, this)), NULL);
	Sprite *spr;
	if (isO)
	{
		spr = (Sprite*)this->getChildByTag(TAG_SPRITE_O);
	}
	else
	{
		spr = (Sprite*)this->getChildByTag(TAG_SPRlTE_X);
	}
	spr->runAction(action);
}
void MainScene::endOX() // 종료 조건이 아닐경우
{
	if (!(Singletons::getInstance()->CardOK == 8 || life == 0))
	{
		isTouch = true;
	}
}
void MainScene::actionGameEnd(bool isGameClear) // 종료 조건 충족시
{
	isTouch = false;

	auto action = Sequence::create(DelayTime::create(0.5f),
		Show::create(),
		EaseBounceOut::create(MoveTo::create(1.0, Point(winSize.width / 2, winSize.height / 2))),
		DelayTime::create(0.5f),
		Hide::create(),
		Place::create(Point(winSize.width / 2, winSize.height + 50)),
		CallFunc::create(CC_CALLBACK_0(MainScene::endGameEnd, this)), NULL);
	
	if (isGameClear) // 게임 클리어
	{
		auto spr1 = Sprite::create("CardGame_2/clear.png");
		spr1->setPosition(Point(winSize.width / 2, winSize.height / 2));
		spr1->setTag(TAG_SPRITE_GAMECLEAR);
		spr1->setVisible(false);
		this->addChild(spr1);
		spr1->runAction(action);
	}
	else // 게임 오버
	{
		auto spr2 = Sprite::create("CardGame_2/fail.png");
		spr2->setPosition(Point(winSize.width / 2, winSize.height / 2));
		spr2->setTag(TAG_SPRITE_GAMEOVER);
		spr2->setVisible(false);
		this->addChild(spr2);
		spr2->runAction(action);
	}
}
void MainScene::endGameEnd()
{
	Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
	Director::getInstance()->replaceScene(EndScene::createScene());
}