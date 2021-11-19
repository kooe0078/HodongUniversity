#include "CardScene.h"
#include "CardEndScene.h"
#include "SimpleAudioEngine.h"
#include <stdlib.h>
#include "sinngleton.h"

//���� �Ҷ�� �� �ʿ�
using namespace CocosDenshion;
USING_NS_CC;

Scene* CardScene::createScene()
{
    auto scene = Scene::create();
    auto layer = CardScene::create();
    scene->addChild(layer);

    return scene;
}
bool CardScene::init()
{
    if ( !Layer::init() )
    {
        return false;
    }

	//�������
	SimpleAudioEngine::getInstance()->playBackgroundMusic("sound/game_sound.mp3", true);

	//��ġ ������ ���
	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = CC_CALLBACK_2(CardScene::onTouchBegan, this);
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
	this->scheduleOnce(schedule_selector(CardScene::sprStart), 1.1f); // GO ȿ�� ������ ó��
	this->scheduleOnce(schedule_selector(CardScene::actionCard), 2.2f); // ī�� ���� ó��
	this->scheduleOnce(schedule_selector(CardScene::endCard), 10.2f); // ���� Ȯ�� �� ���� ó��

    return true;
}
bool CardScene::onTouchBegan(Touch * touch, Event * unused_event) // ��ġ ������
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
void CardScene::initBG() // ���
{
	auto spr = CCSprite::create("MiniGameResources/pc_back.png");
	spr->setPosition(Point(512, 384));
	this->addChild(spr);
}
void CardScene::initLabel() // ����
{
	char EX_1[300];
	WideCharToMultiByte(CP_UTF8, 0, L"1�ʰ� ���������� 8���� ī���� ������ ����, ������ ������� ��������!\n(* ī�尡 ���� ���� �ӹ����� �װ��� �ι� Ŭ���ϼ���)", -1, EX_1, 300, NULL, NULL);
	auto EX = Label::createWithTTF(EX_1, "CardGame_2/ABC.ttf", 27);
	EX->setAnchorPoint(Point(0, 1));
	EX->setPosition(Point(90, 650));
	EX->setColor(Color3B::BLACK);
	this->addChild(EX, 2);
}
void CardScene::initGameData()
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
void CardScene::initTopMenuLabel() // ī�� ��, ���� ��� ��ġ
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
void CardScene::setLabelCard() // ī�� ��
{
	auto label = (Label*)this->getChildByTag(TAG_LABEL_CARD);
	label->setString(StringUtils::format("CARD : %d/8", Singletons::getInstance()->CardOK));
}
void CardScene::setLabelLife() // ���� ��
{
	auto label = (Label*)this->getChildByTag(TAG_LABEL_LlFE);
	label->setString(StringUtils::format("LIFE : %d", life));
}
void CardScene::initCard() // ī�� ��ġ
{
	for (int i = 0; i < 14; i++) // 2�ٷ� �� 14��
	{
		auto spr = Sprite::create("CardGame_2/Card.png"); // �޸�
		spr->setPosition(Point(210 - 60 + 60 * 2 * (i / 2),
			winSize.height / 2.5 + 120 - 120 * (i % 2)));
		this->addChild(spr);

		auto sprFront = Sprite::create(StringUtils::format("CardGame_2/DeathWing.png", (i + 1))); // �ո�
		sprFront->setPosition(Point(210 - 60 + 60 * 2 * (i / 2),
			winSize.height / 2.5 + 120 - 120 * (i % 2)));
		sprFront->setVisible(false);
		sprFront->setTag(TAG_SPRITE_CARD + i);
		this->addChild(sprFront);
	}
}
void CardScene::sprReady() // �غ� �ΰ�
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
void CardScene::sprStart(float delta) // ���� �ΰ�
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
void CardScene::actionCard(float delta) // ī�� ����
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
void CardScene::endCard(float delta)
{
	isTouch = true;
}
void CardScene::initO() // ������ Oâ�� ����
{
	auto spr = Sprite::create("CardGame_2/o.png");
	spr->setPosition(Point(winSize.width / 2, winSize.height / 2));
	spr->setTag(TAG_SPRITE_O);
	spr->setVisible(false);
	this->addChild(spr);

	SimpleAudioEngine::getInstance()->playEffect("sound/win sound.mp3", false);
}
void CardScene::initX() // Ʋ���� Xâ�� ����
{
	auto spr = Sprite::create("CardGame_2/x.png");
	spr->setPosition(Point(winSize.width / 2, winSize.height / 2));
	spr->setTag(TAG_SPRlTE_X);
	spr->setVisible(false);
	this->addChild(spr);

	SimpleAudioEngine::getInstance()->playEffect("sound/win sound.mp3", false);
}
void CardScene::actionOX(bool isO) // OXâ ����
{
	auto action = Sequence::create(Show::create(), DelayTime::create(0.3), Hide::create(),
		CallFunc::create(CC_CALLBACK_0(CardScene::endOX, this)), NULL);
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
void CardScene::endOX() // ���� ������ �ƴҰ��
{
	if (!(Singletons::getInstance()->CardOK == 8 || life == 0))
	{
		isTouch = true;
	}
}
void CardScene::actionGameEnd(bool isGameClear) // ���� ���� ������
{
	isTouch = false;

	auto action = Sequence::create(DelayTime::create(0.5f),
		Show::create(),
		EaseBounceOut::create(MoveTo::create(1.0, Point(winSize.width / 2, winSize.height / 2))),
		DelayTime::create(0.5f),
		Hide::create(),
		Place::create(Point(winSize.width / 2, winSize.height + 50)),
		CallFunc::create(CC_CALLBACK_0(CardScene::endGameEnd, this)), NULL);
	
	if (isGameClear) // ���� Ŭ����
	{
		auto spr1 = Sprite::create("CardGame_2/clear.png");
		spr1->setPosition(Point(winSize.width / 2, winSize.height / 2));
		spr1->setTag(TAG_SPRITE_GAMECLEAR);
		spr1->setVisible(false);
		this->addChild(spr1);
		spr1->runAction(action);
	}
	else // ���� ����
	{
		auto spr2 = Sprite::create("CardGame_2/fail.png");
		spr2->setPosition(Point(winSize.width / 2, winSize.height / 2));
		spr2->setTag(TAG_SPRITE_GAMEOVER);
		spr2->setVisible(false);
		this->addChild(spr2);
		spr2->runAction(action);
	}
}
void CardScene::endGameEnd()
{
	Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
	Director::getInstance()->replaceScene(CardEndScene::createScene());
}