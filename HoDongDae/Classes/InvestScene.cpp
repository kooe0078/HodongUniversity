#include "InvestScene.h"
#include "SimpleAudioEngine.h"
#include "MainScene.h"
#include "chrcreateScene.h"
#include "sinngleton.h"
#include "BudongScene.h"
#include "NextDayScene.h"
//사운드 할라면 꼭 필요
using namespace CocosDenshion;
USING_NS_CC;

Scene* InvestScene::createScene()
{
    auto scene = Scene::create();
    auto layer = InvestScene::create();
    scene->addChild(layer);

    return scene;
}

bool InvestScene::init()
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
	//listener->onTouchBegan = CC_CALLBACK_2(InvestScene::onTouchBegan, this);
	//Director::getInstance()->getEventDispatcher()->addEventListenerWithFixedPriority(listener, 1);
	this->schedule(schedule_selector(InvestScene::update),0.001f);
	//배경음악
	SimpleAudioEngine::getInstance()->playBackgroundMusic("sound/invest sound.mp3", true);

    return true;
}
void InvestScene::update(float ft)
{
	//씬 자체적으로 반복 되야하는 내용

	Label* JuS = (Label*)this->getChildByTag(101);
	JuS->setString(StringUtils::format("%d", Singletons::getInstance()->ju_S));
	
	Label* JuA = (Label*)this->getChildByTag(102);
	JuA->setString(StringUtils::format("%d", Singletons::getInstance()->ju_A));

	Label* JuH = (Label*)this->getChildByTag(103);
	JuH->setString(StringUtils::format("%d", Singletons::getInstance()->ju_H));

	Label* JuK = (Label*)this->getChildByTag(104);
	JuK->setString(StringUtils::format("%d", Singletons::getInstance()->ju_K));

	Label* JuL = (Label*)this->getChildByTag(105);
	JuL->setString(StringUtils::format("%d", Singletons::getInstance()->ju_L));

	Label* label3 = (Label*)this->getChildByTag(7);
	label3->setString(StringUtils::format("%d", Singletons::getInstance()->money));

	if (Singletons::getInstance()->ju_S >= 10.5)
	{
		if (Singletons::getInstance()->ju_S == 11)
		{
			Singletons::getInstance()->money = (Singletons::getInstance()->money) + (Singletons::getInstance()->samsung_2 * 1);
			Singletons::getInstance()->ju_S = 10;
		}
	}
	//ss
	if (Singletons::getInstance()->ju_S >= 10.5)
	{
		if (Singletons::getInstance()->ju_S == 12)
		{
			Singletons::getInstance()->money = (Singletons::getInstance()->money) + (Singletons::getInstance()->samsung_2 * 2);
			Singletons::getInstance()->ju_S = 10;
		}
	}

	if (Singletons::getInstance()->ju_S >= 10.5)
	{
		if (Singletons::getInstance()->ju_S == 13)
		{
			Singletons::getInstance()->money = (Singletons::getInstance()->money) + (Singletons::getInstance()->samsung_2 * 3);
			Singletons::getInstance()->ju_S = 10;
		}
	}

	if (Singletons::getInstance()->ju_S >= 10.5)
	{
		if (Singletons::getInstance()->ju_S == 14)
		{
			Singletons::getInstance()->money = (Singletons::getInstance()->money) + (Singletons::getInstance()->samsung_2 * 4);
			Singletons::getInstance()->ju_S = 10;
		}
	}

	if (Singletons::getInstance()->ju_S >= 10.5)
	{
		if (Singletons::getInstance()->ju_S == 15)
		{
			Singletons::getInstance()->money = (Singletons::getInstance()->money) + (Singletons::getInstance()->samsung_2 * 5);
			Singletons::getInstance()->ju_S = 10;
		}
	}

	if (Singletons::getInstance()->ju_S >= 10.5)
	{
		if (Singletons::getInstance()->ju_S == 16)
		{
			Singletons::getInstance()->money = (Singletons::getInstance()->money) + (Singletons::getInstance()->samsung_2 * 6);
			Singletons::getInstance()->ju_S = 10;
		}
	}

	if (Singletons::getInstance()->ju_S >= 10.5)
	{
		if (Singletons::getInstance()->ju_S == 17)
		{
			Singletons::getInstance()->money = (Singletons::getInstance()->money) + (Singletons::getInstance()->samsung_2 * 7);
			Singletons::getInstance()->ju_S = 10;
		}
	}

	if (Singletons::getInstance()->ju_S >= 10.5)
	{
		if (Singletons::getInstance()->ju_S == 18)
		{
			Singletons::getInstance()->money = (Singletons::getInstance()->money) + (Singletons::getInstance()->samsung_2 * 8);
			Singletons::getInstance()->ju_S = 10;
		}
	}

	if (Singletons::getInstance()->ju_S >= 10.5)
	{
		if (Singletons::getInstance()->ju_S == 19)
		{
			Singletons::getInstance()->money = (Singletons::getInstance()->money) + (Singletons::getInstance()->samsung_2 * 9);
			Singletons::getInstance()->ju_S = 10;
		}
	}
	if (Singletons::getInstance()->ju_A >= 10.5)
	{
		if (Singletons::getInstance()->ju_A == 11)
		{
			Singletons::getInstance()->money = (Singletons::getInstance()->money) + (Singletons::getInstance()->apple_2 * 1);
			Singletons::getInstance()->ju_A = 10;
		}
	}
	//ss
	if (Singletons::getInstance()->ju_A >= 10.5)
	{
		if (Singletons::getInstance()->ju_A == 12)
		{
			Singletons::getInstance()->money = (Singletons::getInstance()->money) + (Singletons::getInstance()->apple_2 * 2);
			Singletons::getInstance()->ju_A = 10;
		}
	}

	if (Singletons::getInstance()->ju_A >= 10.5)
	{
		if (Singletons::getInstance()->ju_A == 13)
		{
			Singletons::getInstance()->money = (Singletons::getInstance()->money) + (Singletons::getInstance()->apple_2 * 3);
			Singletons::getInstance()->ju_A = 10;
		}
	}

	if (Singletons::getInstance()->ju_A >= 10.5)
	{
		if (Singletons::getInstance()->ju_A == 14)
		{
			Singletons::getInstance()->money = (Singletons::getInstance()->money) + (Singletons::getInstance()->apple_2 * 4);
			Singletons::getInstance()->ju_A = 10;
		}
	}

	if (Singletons::getInstance()->ju_A >= 10.5)
	{
		if (Singletons::getInstance()->ju_A == 15)
		{
			Singletons::getInstance()->money = (Singletons::getInstance()->money) + (Singletons::getInstance()->apple_2 * 5);
			Singletons::getInstance()->ju_A = 10;
		}
	}

	if (Singletons::getInstance()->ju_A >= 10.5)
	{
		if (Singletons::getInstance()->ju_A == 16)
		{
			Singletons::getInstance()->money = (Singletons::getInstance()->money) + (Singletons::getInstance()->apple_2 * 6);
			Singletons::getInstance()->ju_A = 10;
		}
	}

	if (Singletons::getInstance()->ju_A >= 10.5)
	{
		if (Singletons::getInstance()->ju_A == 17)
		{
			Singletons::getInstance()->money = (Singletons::getInstance()->money) + (Singletons::getInstance()->apple_2 * 7);
			Singletons::getInstance()->ju_A = 10;
		}
	}

	if (Singletons::getInstance()->ju_A >= 10.5)
	{
		if (Singletons::getInstance()->ju_A == 18)
		{
			Singletons::getInstance()->money = (Singletons::getInstance()->money) + (Singletons::getInstance()->apple_2 * 8);
			Singletons::getInstance()->ju_A = 10;
		}
	}

	if (Singletons::getInstance()->ju_A >= 10.5)
	{
		if (Singletons::getInstance()->ju_A == 19)
		{
			Singletons::getInstance()->money = (Singletons::getInstance()->money) + (Singletons::getInstance()->apple_2 * 9);
			Singletons::getInstance()->ju_A = 10;
		}
	}
	if (Singletons::getInstance()->ju_H >= 10.5)
	{
		if (Singletons::getInstance()->ju_H == 11)
		{
			Singletons::getInstance()->money = (Singletons::getInstance()->money) + (Singletons::getInstance()->hanhwa_2 * 1);
			Singletons::getInstance()->ju_H = 10;
		}
	}
	//ss
	if (Singletons::getInstance()->ju_H >= 10.5)
	{
		if (Singletons::getInstance()->ju_H == 12)
		{
			Singletons::getInstance()->money = (Singletons::getInstance()->money) + (Singletons::getInstance()->hanhwa_2 * 2);
			Singletons::getInstance()->ju_H = 10;
		}
	}

	if (Singletons::getInstance()->ju_H >= 10.5)
	{
		if (Singletons::getInstance()->ju_H == 13)
		{
			Singletons::getInstance()->money = (Singletons::getInstance()->money) + (Singletons::getInstance()->hanhwa_2 * 3);
			Singletons::getInstance()->ju_H = 10;
		}
	}

	if (Singletons::getInstance()->ju_H >= 10.5)
	{
		if (Singletons::getInstance()->ju_H == 14)
		{
			Singletons::getInstance()->money = (Singletons::getInstance()->money) + (Singletons::getInstance()->hanhwa_2 * 4);
			Singletons::getInstance()->ju_H = 10;
		}
	}

	if (Singletons::getInstance()->ju_H >= 10.5)
	{
		if (Singletons::getInstance()->ju_H == 15)
		{
			Singletons::getInstance()->money = (Singletons::getInstance()->money) + (Singletons::getInstance()->hanhwa_2 * 5);
			Singletons::getInstance()->ju_H = 10;
		}
	}

	if (Singletons::getInstance()->ju_H >= 10.5)
	{
		if (Singletons::getInstance()->ju_H == 16)
		{
			Singletons::getInstance()->money = (Singletons::getInstance()->money) + (Singletons::getInstance()->hanhwa_2 * 6);
			Singletons::getInstance()->ju_H = 10;
		}
	}

	if (Singletons::getInstance()->ju_H >= 10.5)
	{
		if (Singletons::getInstance()->ju_H == 17)
		{
			Singletons::getInstance()->money = (Singletons::getInstance()->money) + (Singletons::getInstance()->hanhwa_2 * 7);
			Singletons::getInstance()->ju_H = 10;
		}
	}

	if (Singletons::getInstance()->ju_H >= 10.5)
	{
		if (Singletons::getInstance()->ju_H == 18)
		{
			Singletons::getInstance()->money = (Singletons::getInstance()->money) + (Singletons::getInstance()->hanhwa_2 * 8);
			Singletons::getInstance()->ju_H = 10;
		}
	}

	if (Singletons::getInstance()->ju_H >= 10.5)
	{
		if (Singletons::getInstance()->ju_H == 19)
		{
			Singletons::getInstance()->money = (Singletons::getInstance()->money) + (Singletons::getInstance()->hanhwa_2 * 9);
			Singletons::getInstance()->ju_H = 10;
		}
	}
	if (Singletons::getInstance()->ju_K >= 10.5)
	{
		if (Singletons::getInstance()->ju_K == 11)
		{
			Singletons::getInstance()->money = (Singletons::getInstance()->money) + (Singletons::getInstance()->kia_2 * 1);
			Singletons::getInstance()->ju_K = 10;
		}
	}
	//ss
	if (Singletons::getInstance()->ju_K >= 10.5)
	{
		if (Singletons::getInstance()->ju_K == 12)
		{
			Singletons::getInstance()->money = (Singletons::getInstance()->money) + (Singletons::getInstance()->kia_2 * 2);
			Singletons::getInstance()->ju_K = 10;
		}
	}

	if (Singletons::getInstance()->ju_K >= 10.5)
	{
		if (Singletons::getInstance()->ju_K == 13)
		{
			Singletons::getInstance()->money = (Singletons::getInstance()->money) + (Singletons::getInstance()->kia_2 * 3);
			Singletons::getInstance()->ju_K = 10;
		}
	}

	if (Singletons::getInstance()->ju_K >= 10.5)
	{
		if (Singletons::getInstance()->ju_K == 14)
		{
			Singletons::getInstance()->money = (Singletons::getInstance()->money) + (Singletons::getInstance()->kia_2 * 4);
			Singletons::getInstance()->ju_K = 10;
		}
	}

	if (Singletons::getInstance()->ju_K >= 10.5)
	{
		if (Singletons::getInstance()->ju_K == 15)
		{
			Singletons::getInstance()->money = (Singletons::getInstance()->money) + (Singletons::getInstance()->kia_2 * 5);
			Singletons::getInstance()->ju_K = 10;
		}
	}

	if (Singletons::getInstance()->ju_K >= 10.5)
	{
		if (Singletons::getInstance()->ju_K == 16)
		{
			Singletons::getInstance()->money = (Singletons::getInstance()->money) + (Singletons::getInstance()->kia_2 * 6);
			Singletons::getInstance()->ju_K = 10;
		}
	}

	if (Singletons::getInstance()->ju_K >= 10.5)
	{
		if (Singletons::getInstance()->ju_K == 17)
		{
			Singletons::getInstance()->money = (Singletons::getInstance()->money) + (Singletons::getInstance()->kia_2 * 7);
			Singletons::getInstance()->ju_K = 10;
		}
	}

	if (Singletons::getInstance()->ju_K >= 10.5)
	{
		if (Singletons::getInstance()->ju_K == 18)
		{
			Singletons::getInstance()->money = (Singletons::getInstance()->money) + (Singletons::getInstance()->kia_2 * 8);
			Singletons::getInstance()->ju_K = 10;
		}
	}

	if (Singletons::getInstance()->ju_K >= 10.5)
	{
		if (Singletons::getInstance()->ju_K == 19)
		{
			Singletons::getInstance()->money = (Singletons::getInstance()->money) + (Singletons::getInstance()->kia_2 * 9);
			Singletons::getInstance()->ju_K = 10;
		}
	}
	if (Singletons::getInstance()->ju_L >= 10.5)
	{
		if (Singletons::getInstance()->ju_L == 11)
		{
			Singletons::getInstance()->money = (Singletons::getInstance()->money) + (Singletons::getInstance()->lg_2 * 1);
			Singletons::getInstance()->ju_L = 10;
		}
	}
	//ss
	if (Singletons::getInstance()->ju_L >= 10.5)
	{
		if (Singletons::getInstance()->ju_L == 12)
		{
			Singletons::getInstance()->money = (Singletons::getInstance()->money) + (Singletons::getInstance()->lg_2 * 2);
			Singletons::getInstance()->ju_L = 10;
		}
	}

	if (Singletons::getInstance()->ju_L >= 10.5)
	{
		if (Singletons::getInstance()->ju_L == 13)
		{
			Singletons::getInstance()->money = (Singletons::getInstance()->money) + (Singletons::getInstance()->lg_2 * 3);
			Singletons::getInstance()->ju_L = 10;
		}
	}

	if (Singletons::getInstance()->ju_L >= 10.5)
	{
		if (Singletons::getInstance()->ju_L == 14)
		{
			Singletons::getInstance()->money = (Singletons::getInstance()->money) + (Singletons::getInstance()->lg_2 * 4);
			Singletons::getInstance()->ju_L = 10;
		}
	}

	if (Singletons::getInstance()->ju_L >= 10.5)
	{
		if (Singletons::getInstance()->ju_L == 15)
		{
			Singletons::getInstance()->money = (Singletons::getInstance()->money) + (Singletons::getInstance()->lg_2 * 5);
			Singletons::getInstance()->ju_L = 10;
		}
	}

	if (Singletons::getInstance()->ju_L >= 10.5)
	{
		if (Singletons::getInstance()->ju_L == 16)
		{
			Singletons::getInstance()->money = (Singletons::getInstance()->money) + (Singletons::getInstance()->lg_2 * 6);
			Singletons::getInstance()->ju_L = 10;
		}
	}

	if (Singletons::getInstance()->ju_L >= 10.5)
	{
		if (Singletons::getInstance()->ju_L == 17)
		{
			Singletons::getInstance()->money = (Singletons::getInstance()->money) + (Singletons::getInstance()->lg_2 * 7);
			Singletons::getInstance()->ju_L = 10;
		}
	}

	if (Singletons::getInstance()->ju_L >= 10.5)
	{
		if (Singletons::getInstance()->ju_L == 18)
		{
			Singletons::getInstance()->money = (Singletons::getInstance()->money) + (Singletons::getInstance()->lg_2 * 8);
			Singletons::getInstance()->ju_L = 10;
		}
	}

	if (Singletons::getInstance()->ju_L >= 10.5)
	{
		if (Singletons::getInstance()->ju_L == 19)
		{
			Singletons::getInstance()->money = (Singletons::getInstance()->money) + (Singletons::getInstance()->lg_2 * 9);
			Singletons::getInstance()->ju_L = 10;
		}
	}

	

}
void InvestScene::InitBackGround()
{
	auto sprite = Sprite::create("MiniGameResources/stock_exchange.png");
	sprite->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	this->addChild(sprite, 0);
}
void InvestScene::InitLabel()
{
	
	//돈
	Label* money = Label::createWithTTF(StringUtils::format(""), "MiniGameResources/CuteFont.ttf", 40);
	money->setAnchorPoint(Point(0.5, 0));
	money->setPosition(Point(890, 710));
	money->setColor(Color3B::WHITE);
	money->setTag(7);
	this->addChild(money, 3);
	//별삼
	Label* score_s = Label::createWithTTF(StringUtils::format("%d", Singletons::getInstance()->samsung_3), "MiniGameResources/CuteFont.ttf", 40);
	score_s->setAnchorPoint(Point(0.5, 0));
	score_s->setPosition(Point(176, 375));
	score_s->setColor(Color3B::WHITE);
	score_s->setTag(106);
	this->addChild(score_s, 4);

	Label* score_s_A = Label::createWithTTF(StringUtils::format("%.1f", (Singletons::getInstance()->samsung_A)*100), "MiniGameResources/CuteFont.ttf", 40);
	score_s_A->setAnchorPoint(Point(0.5, 0));
	score_s_A->setPosition(Point(176, 267));
	score_s_A->setColor(Color3B::WHITE);
	score_s_A->setTag(107);
	this->addChild(score_s_A, 4);

	Label* score_s_2 = Label::createWithTTF(StringUtils::format("%d", Singletons::getInstance()->samsung_2), "MiniGameResources/CuteFont.ttf", 40);
	score_s_2->setAnchorPoint(Point(0.5, 0));
	score_s_2->setPosition(Point(176, 135));
	score_s_2->setColor(Color3B::WHITE);
	score_s_2->setTag(108);
	this->addChild(score_s_2, 4);

	
	
	//파인애플
	Label* score_a = Label::createWithTTF(StringUtils::format("%d", Singletons::getInstance()->apple_3), "MiniGameResources/CuteFont.ttf", 40);
	score_a->setAnchorPoint(Point(0.5, 0));
	score_a->setPosition(Point(336, 375));
	score_a->setColor(Color3B::WHITE);
	score_a->setTag(109);
	this->addChild(score_a, 4);

	Label* score_a_A = Label::createWithTTF(StringUtils::format("%.1f", (Singletons::getInstance()->apple_A) * 100), "MiniGameResources/CuteFont.ttf", 40);
	score_a_A->setAnchorPoint(Point(0.5, 0));
	score_a_A->setPosition(Point(336, 267));
	score_a_A->setColor(Color3B::WHITE);
	score_a_A->setTag(110);
	this->addChild(score_a_A, 4);

	Label* score_a_2 = Label::createWithTTF(StringUtils::format("%d", Singletons::getInstance()->apple_2 ), "MiniGameResources/CuteFont.ttf", 40);
	score_a_2->setAnchorPoint(Point(0.5, 0));
	score_a_2->setPosition(Point(336, 135));
	score_a_2->setColor(Color3B::WHITE);
	score_a_2->setTag(111);
	this->addChild(score_a_2, 4);

	
	//한화

	Label* score_h = Label::createWithTTF(StringUtils::format("%d", Singletons::getInstance()->hanhwa_3), "MiniGameResources/CuteFont.ttf", 40);
	score_h->setAnchorPoint(Point(0.5, 0));
	score_h->setPosition(Point(496, 375));
	score_h->setColor(Color3B::WHITE);
	score_h->setTag(112);
	this->addChild(score_h, 4);

	Label* score_h_A = Label::createWithTTF(StringUtils::format("%.1f", (Singletons::getInstance()->hanhwa_A) * 100), "MiniGameResources/CuteFont.ttf", 40);
	score_h_A->setAnchorPoint(Point(0.5, 0));
	score_h_A->setPosition(Point(496, 267));
	score_h_A->setColor(Color3B::WHITE);
	score_h_A->setTag(113);
	this->addChild(score_h_A, 4);

	Label* score_h_2 = Label::createWithTTF(StringUtils::format("%d", Singletons::getInstance()->hanhwa_2), "MiniGameResources/CuteFont.ttf", 40);
	score_h_2->setAnchorPoint(Point(0.5, 0));
	score_h_2->setPosition(Point(496, 135));
	score_h_2->setColor(Color3B::WHITE);
	score_h_2->setTag(114);
	this->addChild(score_h_2, 4);


	
	//기아
	Label* score_k = Label::createWithTTF(StringUtils::format("%d", Singletons::getInstance()->kia_3), "MiniGameResources/CuteFont.ttf", 40);
	score_k->setAnchorPoint(Point(0.5, 0));
	score_k->setPosition(Point(656, 375));
	score_k->setColor(Color3B::WHITE);
	score_k->setTag(115);
	this->addChild(score_k, 4);

	Label* score_k_A = Label::createWithTTF(StringUtils::format("%.1f", (Singletons::getInstance()->kia_A) * 100), "MiniGameResources/CuteFont.ttf", 40);
	score_k_A->setAnchorPoint(Point(0.5, 0));
	score_k_A->setPosition(Point(656, 267));
	score_k_A->setColor(Color3B::WHITE);
	score_k_A->setTag(116);
	this->addChild(score_k_A, 4);

	Label* score_k_2 = Label::createWithTTF(StringUtils::format("%d", Singletons::getInstance()->kia_2), "MiniGameResources/CuteFont.ttf", 40);
	score_k_2->setAnchorPoint(Point(0.5, 0));
	score_k_2->setPosition(Point(656, 135));
	score_k_2->setColor(Color3B::WHITE);
	score_k_2->setTag(117);
	this->addChild(score_k_2, 4);



	//엘쥐
	Label* score_l = Label::createWithTTF(StringUtils::format("%d", Singletons::getInstance()->lg_3), "MiniGameResources/CuteFont.ttf", 40);
	score_l->setAnchorPoint(Point(0.5, 0));
	score_l->setPosition(Point(816, 375));
	score_l->setColor(Color3B::WHITE);
	score_l->setTag(118);
	this->addChild(score_l, 4);

	Label* score_l_A = Label::createWithTTF(StringUtils::format("%.1f", (Singletons::getInstance()->lg_A) * 100), "MiniGameResources/CuteFont.ttf", 40);
	score_l_A->setAnchorPoint(Point(0.5, 0));
	score_l_A->setPosition(Point(816, 267));
	score_l_A->setColor(Color3B::WHITE);
	score_l_A->setTag(119);
	this->addChild(score_l_A, 4);

	Label* score_l_2 = Label::createWithTTF(StringUtils::format("%d", Singletons::getInstance()->lg_2), "MiniGameResources/CuteFont.ttf", 40);
	score_l_2->setAnchorPoint(Point(0.5, 0));
	score_l_2->setPosition(Point(816, 135));
	score_l_2->setColor(Color3B::WHITE);
	score_l_2->setTag(120);
	this->addChild(score_l_2, 4);
	///////////////////////////////////////////////
	Label* JS = Label::createWithTTF(StringUtils::format("%d", Singletons::getInstance()->ju_S), "MiniGameResources/CuteFont.ttf", 40);
	JS->setAnchorPoint(Point(0.5, 0));
	JS->setPosition(Point(176, 684));
	JS->setColor(Color3B::WHITE);
	JS->setTag(101);
	this->addChild(JS, 4);

	Label* JA = Label::createWithTTF(StringUtils::format("%d", Singletons::getInstance()->ju_A), "MiniGameResources/CuteFont.ttf", 40);
	JA->setAnchorPoint(Point(0.5, 0));
	JA->setPosition(Point(336, 684));
	JA->setColor(Color3B::WHITE);
	JA->setTag(102);
	this->addChild(JA, 4);

	Label* JH = Label::createWithTTF(StringUtils::format("%d", Singletons::getInstance()->ju_H), "MiniGameResources/CuteFont.ttf", 40);
	JH->setAnchorPoint(Point(0.5, 0));
	JH->setPosition(Point(496, 684));
	JH->setColor(Color3B::WHITE);
	JH->setTag(103);
	this->addChild(JH, 4);

	Label* JK = Label::createWithTTF(StringUtils::format("%d", Singletons::getInstance()->ju_K), "MiniGameResources/CuteFont.ttf", 40);
	JK->setAnchorPoint(Point(0.5, 0));
	JK->setPosition(Point(656, 684));
	JK->setColor(Color3B::WHITE);
	JK->setTag(104);
	this->addChild(JK, 4);

	Label* JL = Label::createWithTTF(StringUtils::format("%d", Singletons::getInstance()->ju_L), "MiniGameResources/CuteFont.ttf", 40);
	JL->setAnchorPoint(Point(0.5, 0));
	JL->setPosition(Point(816, 684));
	JL->setColor(Color3B::WHITE);
	JL->setTag(105);
	this->addChild(JL, 4);
}
// 인트로 선택창
void InvestScene::InitMenu()
{
	//삭제 판업
	auto cancel = MenuItemImage::create(
		"MiniGameResources/invest_exit.png",
		"MiniGameResources/invest_exitpr.png",
		CC_CALLBACK_1(InvestScene::newplay, this));
	cancel->setAnchorPoint(Point(0.5, 0.5));
	cancel->setPosition(Point(960, 45));

	auto canceltext = Menu::create(cancel, NULL);
	canceltext->setAnchorPoint(Point(0.5, 0.5));
	canceltext->setPosition(Point(0, 0));
	canceltext->setTag(129);
	this->addChild(canceltext, 6);
	//투자 판업
	Sprite* sub = Sprite::create("MiniGameResources/UI_invest.png");
	sub->setAnchorPoint(Point(0.5, 0.5));
	sub->setPosition(Point(501, 380));
	sub->setTag(44);
	this->addChild(sub, 1);
	
	Sprite* sub_1 = Sprite::create("MiniGameResources/UI_investpop.png");
	sub_1->setAnchorPoint(Point(0.5, 0.5));
	sub_1->setPosition(Point(500.5,707));
	sub_1->setTag(45);
	this->addChild(sub_1, 1);

	//삼성 구매
	auto text_item = MenuItemImage::create(
		"MiniGameResources/UI_investbot2.png",
		"MiniGameResources/UI_investbot2pr.png",
		CC_CALLBACK_1(InvestScene::buy_S, this));
	text_item->setAnchorPoint(Point(0.5, 0.5));
	text_item->setPosition(Point(136, 45));

	auto text = Menu::create(text_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(130);
	this->addChild(text, 5);

	//삼성판매
	auto text_sell_S = MenuItemImage::create(
		"MiniGameResources/UI_investbot3.png",
		"MiniGameResources/UI_investbot3pr.png",
		CC_CALLBACK_1(InvestScene::sell_S, this));
	text_sell_S->setAnchorPoint(Point(0.5, 0.5));
	text_sell_S->setPosition(Point(216, 45));

	auto sell_S = Menu::create(text_sell_S, NULL);
	sell_S->setAnchorPoint(Point(0.5, 0.5));
	sell_S->setPosition(Point(0, 0));
	sell_S->setTag(130);
	this->addChild(sell_S, 5);

	//애플 구매
	auto text_item_AA = MenuItemImage::create(
		"MiniGameResources/UI_investbot2.png",
		"MiniGameResources/UI_investbot2pr.png",
		CC_CALLBACK_1(InvestScene::buy_A, this));
	text_item_AA->setAnchorPoint(Point(0.5, 0.5));
	text_item_AA->setPosition(Point(296, 45));

	auto text_item_A = Menu::create(text_item_AA, NULL);
	text_item_A->setAnchorPoint(Point(0.5, 0.5));
	text_item_A->setPosition(Point(0, 0));
	text_item_A->setTag(131);
	this->addChild(text_item_A, 5);

	//애플판매
	auto text_sell_A = MenuItemImage::create(
		"MiniGameResources/UI_investbot3.png",
		"MiniGameResources/UI_investbot3pr.png",
		CC_CALLBACK_1(InvestScene::sell_A, this));
	text_sell_A->setAnchorPoint(Point(0.5, 0.5));
	text_sell_A->setPosition(Point(376, 45));

	auto sell_A = Menu::create(text_sell_A, NULL);
	sell_A->setAnchorPoint(Point(0.5, 0.5));
	sell_A->setPosition(Point(0, 0));
	sell_A->setTag(130);
	this->addChild(sell_A, 5);

	//한화 구매
	auto text_item_HH = MenuItemImage::create(
		"MiniGameResources/UI_investbot2.png",
		"MiniGameResources/UI_investbot2pr.png",
		CC_CALLBACK_1(InvestScene::buy_H, this));
	text_item_HH->setAnchorPoint(Point(0.5, 0.5));
	text_item_HH->setPosition(Point(456, 45));

	auto text_item_H = Menu::create(text_item_HH, NULL);
	text_item_H->setAnchorPoint(Point(0.5, 0.5));
	text_item_H->setPosition(Point(0, 0));
	text_item_H->setTag(132);
	this->addChild(text_item_H, 5);

	//한화판매
	auto text_sell_H = MenuItemImage::create(
		"MiniGameResources/UI_investbot3.png",
		"MiniGameResources/UI_investbot3pr.png",
		CC_CALLBACK_1(InvestScene::sell_H, this));
	text_sell_H->setAnchorPoint(Point(0.5, 0.5));
	text_sell_H->setPosition(Point(536, 45));

	auto sell_H = Menu::create(text_sell_H, NULL);
	sell_H->setAnchorPoint(Point(0.5, 0.5));
	sell_H->setPosition(Point(0, 0));
	sell_H->setTag(130);
	this->addChild(sell_H, 5);

	//기아 구매
	auto text_item_Kk= MenuItemImage::create(
		"MiniGameResources/UI_investbot2.png",
		"MiniGameResources/UI_investbot2pr.png",
		CC_CALLBACK_1(InvestScene::buy_K, this));
	text_item_Kk->setAnchorPoint(Point(0.5, 0.5));
	text_item_Kk->setPosition(Point(626, 45));

	auto text_item_K = Menu::create(text_item_Kk, NULL);
	text_item_K->setAnchorPoint(Point(0.5, 0.5));
	text_item_K->setPosition(Point(0, 0));
	text_item_K->setTag(133);
	this->addChild(text_item_K, 5);

	//기아판매
	auto text_sell_K = MenuItemImage::create(
		"MiniGameResources/UI_investbot3.png",
		"MiniGameResources/UI_investbot3pr.png",
		CC_CALLBACK_1(InvestScene::sell_K, this));
	text_sell_K->setAnchorPoint(Point(0.5, 0.5));
	text_sell_K->setPosition(Point(706, 45));

	auto sell_K = Menu::create(text_sell_K, NULL);
	sell_K->setAnchorPoint(Point(0.5, 0.5));
	sell_K->setPosition(Point(0, 0));
	sell_K->setTag(130);
	this->addChild(sell_K, 5);

	//엘쥐 구매
	auto text_item_LL = MenuItemImage::create(
		"MiniGameResources/UI_investbot2.png",
		"MiniGameResources/UI_investbot2pr.png",
		CC_CALLBACK_1(InvestScene::buy_L, this));
	text_item_LL->setAnchorPoint(Point(0.5, 0.5));
	text_item_LL->setPosition(Point(776, 45));

	auto text_item_L = Menu::create(text_item_LL, NULL);
	text_item_L->setAnchorPoint(Point(0.5, 0.5));
	text_item_L->setPosition(Point(0, 0));
	text_item_L->setTag(134);
	this->addChild(text_item_L, 5);

	//엘쥐판매
	auto text_sell_L = MenuItemImage::create(
		"MiniGameResources/UI_investbot3.png",
		"MiniGameResources/UI_investbot3pr.png",
		CC_CALLBACK_1(InvestScene::sell_L, this));
	text_sell_L->setAnchorPoint(Point(0.5, 0.5));
	text_sell_L->setPosition(Point(856, 45));

	auto sell_L = Menu::create(text_sell_L, NULL);
	sell_L->setAnchorPoint(Point(0.5, 0.5));
	sell_L->setPosition(Point(0, 0));
	sell_L->setTag(130);
	this->addChild(sell_L, 5);
	
}

//삼성구매
void InvestScene::buy_S(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);
	{
		Singletons::getInstance()->num_S = 1;
		if (open == false) {

			open = true;

			//삭제 판업
			auto cancel = MenuItemImage::create(
				"MiniGameResources/UI_investX.png",
				"MiniGameResources/UI_investXpr.png",
				CC_CALLBACK_1(InvestScene::cancelbuy, this));
			cancel->setAnchorPoint(Point(0.5, 0.5));
			cancel->setPosition(Point(662, 517));

			auto canceltext = Menu::create(cancel, NULL);
			canceltext->setAnchorPoint(Point(0.5, 0.5));
			canceltext->setPosition(Point(0, 0));
			canceltext->setTag(165);
			this->addChild(canceltext, 7);
			//구매한들
			char MyString[100];
			WideCharToMultiByte(CP_UTF8, 0, L"몇 주를 구매하시겠습니까?", -1, MyString, 100, NULL, NULL);
			auto name = Label::createWithTTF(MyString, "fonts/ABC.ttf", 25);
			name->setAnchorPoint(Point(0.5, 0.5));
			name->setPosition(Point(530, 480));
			name->setColor(Color3B::BLACK);
			name->setTag(164);
			this->addChild(name, 7);

			//구매 판업창

			Sprite* mainchr = Sprite::create("MiniGameResources/invest_pop.png");
			mainchr->setAnchorPoint(Point(0.5, 0));
			mainchr->setPosition(Point(523, 280));
			mainchr->setTag(166);
			this->addChild(mainchr, 6);

			//한개구매
			auto text_item_1 = MenuItemImage::create(
				"MiniGameResources/text1.png",
				"MiniGameResources/text1pr.png",
				CC_CALLBACK_1(InvestScene::buy_1, this));
			text_item_1->setAnchorPoint(Point(0.5, 0.5));
			text_item_1->setPosition(Point(440, 425));

			auto text_item_L = Menu::create(text_item_1, NULL);
			text_item_L->setAnchorPoint(Point(0.5, 0.5));
			text_item_L->setPosition(Point(0, 0));
			text_item_L->setTag(146);
			this->addChild(text_item_L, 7);

			//두개구매
			auto text_item_L2 = MenuItemImage::create(
				"MiniGameResources/text2.png",
				"MiniGameResources/text2pr.png",
				CC_CALLBACK_1(InvestScene::buy_2, this));
			text_item_L2->setAnchorPoint(Point(0.5, 0.5));
			text_item_L2->setPosition(Point(480, 425));

			auto text_item_2 = Menu::create(text_item_L2, NULL);
			text_item_2->setAnchorPoint(Point(0.5, 0.5));
			text_item_2->setPosition(Point(0, 0));
			text_item_2->setTag(135);
			this->addChild(text_item_2, 7);

			//세개구매
			auto text_item_L3 = MenuItemImage::create(
				"MiniGameResources/text3.png",
				"MiniGameResources/text3pr.png",
				CC_CALLBACK_1(InvestScene::buy_3, this));
			text_item_L3->setAnchorPoint(Point(0.5, 0.5));
			text_item_L3->setPosition(Point(520, 425));

			auto text_item_3 = Menu::create(text_item_L3, NULL);
			text_item_3->setAnchorPoint(Point(0.5, 0.5));
			text_item_3->setPosition(Point(0, 0));
			text_item_3->setTag(136);
			this->addChild(text_item_3, 7);

			//네개구매
			auto text_item_L4 = MenuItemImage::create(
				"MiniGameResources/text4.png",
				"MiniGameResources/text4pr.png",
				CC_CALLBACK_1(InvestScene::buy_4, this));
			text_item_L4->setAnchorPoint(Point(0.5, 0.5));
			text_item_L4->setPosition(Point(560, 425));

			auto text_item_4 = Menu::create(text_item_L4, NULL);
			text_item_4->setAnchorPoint(Point(0.5, 0.5));
			text_item_4->setPosition(Point(0, 0));
			text_item_4->setTag(137);
			this->addChild(text_item_4, 7);

			//다섯개구매
			auto text_item_L5 = MenuItemImage::create(
				"MiniGameResources/text5.png",
				"MiniGameResources/text5pr.png",
				CC_CALLBACK_1(InvestScene::buy_5, this));
			text_item_L5->setAnchorPoint(Point(0.5, 0.5));
			text_item_L5->setPosition(Point(600, 425));

			auto text_item_5 = Menu::create(text_item_L5, NULL);
			text_item_5->setAnchorPoint(Point(0.5, 0.5));
			text_item_5->setPosition(Point(0, 0));
			text_item_5->setTag(138);
			this->addChild(text_item_5, 7);

			//여섯개구매
			auto text_item_L6 = MenuItemImage::create(
				"MiniGameResources/text6.png",
				"MiniGameResources/text6pr.png",
				CC_CALLBACK_1(InvestScene::buy_6, this));
			text_item_L6->setAnchorPoint(Point(0.5, 0.5));
			text_item_L6->setPosition(Point(440, 375));

			auto text_item_6 = Menu::create(text_item_L6, NULL);
			text_item_6->setAnchorPoint(Point(0.5, 0.5));
			text_item_6->setPosition(Point(0, 0));
			text_item_6->setTag(139);
			this->addChild(text_item_6, 7);

			//일곱개구매
			auto text_item_L7 = MenuItemImage::create(
				"MiniGameResources/text7.png",
				"MiniGameResources/text7pr.png",
				CC_CALLBACK_1(InvestScene::buy_7, this));
			text_item_L7->setAnchorPoint(Point(0.5, 0.5));
			text_item_L7->setPosition(Point(480, 375));

			auto text_item_7 = Menu::create(text_item_L7, NULL);
			text_item_7->setAnchorPoint(Point(0.5, 0.5));
			text_item_7->setPosition(Point(0, 0));
			text_item_7->setTag(140);
			this->addChild(text_item_7, 7);

			//여덟개구매
			auto text_item_L8 = MenuItemImage::create(
				"MiniGameResources/text8.png",
				"MiniGameResources/text8pr.png",
				CC_CALLBACK_1(InvestScene::buy_8, this));
			text_item_L8->setAnchorPoint(Point(0.5, 0.5));
			text_item_L8->setPosition(Point(520, 375));

			auto text_item_8 = Menu::create(text_item_L8, NULL);
			text_item_8->setAnchorPoint(Point(0.5, 0.5));
			text_item_8->setPosition(Point(0, 0));
			text_item_8->setTag(141);
			this->addChild(text_item_8, 7);

			//아홉개구매
			auto text_item_L9 = MenuItemImage::create(
				"MiniGameResources/text9.png",
				"MiniGameResources/text9pr.png",
				CC_CALLBACK_1(InvestScene::buy_9, this));
			text_item_L9->setAnchorPoint(Point(0.5, 0.5));
			text_item_L9->setPosition(Point(560, 375));

			auto text_item_9 = Menu::create(text_item_L9, NULL);
			text_item_9->setAnchorPoint(Point(0.5, 0.5));
			text_item_9->setPosition(Point(0, 0));
			text_item_9->setTag(142);
			this->addChild(text_item_9, 7);

			//열개구매
			auto text_item_L10 = MenuItemImage::create(
				"MiniGameResources/text10.png",
				"MiniGameResources/text10pr.png",
				CC_CALLBACK_1(InvestScene::buy_10, this));
			text_item_L10->setAnchorPoint(Point(0.5, 0.5));
			text_item_L10->setPosition(Point(600, 375));

			auto text_item_10 = Menu::create(text_item_L10, NULL);
			text_item_10->setAnchorPoint(Point(0.5, 0.5));
			text_item_10->setPosition(Point(0, 0));
			text_item_10->setTag(143);
			this->addChild(text_item_10, 7);
		}
		else if (open == true)
		{
			Singletons::getInstance()->num_S = 0;
			Singletons::getInstance()->num_A = 0;
			Singletons::getInstance()->num_H = 0;
			Singletons::getInstance()->num_K = 0;
			Singletons::getInstance()->num_L = 0;
			removeChildByTag(164);
			removeChildByTag(165);
			removeChildByTag(166);
			removeChildByTag(146);
			removeChildByTag(135);
			removeChildByTag(136);
			removeChildByTag(137);
			removeChildByTag(138);
			removeChildByTag(139);
			removeChildByTag(140);
			removeChildByTag(141);
			removeChildByTag(142);
			removeChildByTag(143);
			removeChildByTag(161);
			removeChildByTag(162);


			open = false;
		}
	}
	
		if (Singletons::getInstance()->ju_S == 10)

		{
			removeChildByTag(164);
			removeChildByTag(165);
			removeChildByTag(166);
			removeChildByTag(146);
			removeChildByTag(135);
			removeChildByTag(136);
			removeChildByTag(137);
			removeChildByTag(138);
			removeChildByTag(139);
			removeChildByTag(140);
			removeChildByTag(141);
			removeChildByTag(142);
			removeChildByTag(143);
			removeChildByTag(161);
			removeChildByTag(162);

			Sprite* info = Sprite::create("MiniGameResources/pop_dontbuy.png");
			info->setAnchorPoint(Point(0.5, 0));
			info->setPosition(Point(520, 410));
			info->setTag(161);
			this->addChild(info, 5);

			auto cancel_1 = MenuItemImage::create(
				"MiniGameResources/pop_enter.png",
				"MiniGameResources/pop_enterpr.png",
				CC_CALLBACK_1(InvestScene::cancelbuy, this));
			cancel_1->setAnchorPoint(Point(0.5, 0.5));
			cancel_1->setPosition(Point(520, 450));

			auto canceltext_1 = Menu::create(cancel_1, NULL);
			canceltext_1->setAnchorPoint(Point(0.5, 0.5));
			canceltext_1->setPosition(Point(0, 0));
			canceltext_1->setTag(162);
			this->addChild(canceltext_1, 7);
		}

	

}

//삼성판매
void InvestScene::sell_S(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);
	Singletons::getInstance()->num_S = 2;
	if (open == false) {

		open = true;

		//삭제 판업
		auto cancel = MenuItemImage::create(
			"MiniGameResources/UI_investX.png",
			"MiniGameResources/UI_investXpr.png",
			CC_CALLBACK_1(InvestScene::cancelbuy, this));
		cancel->setAnchorPoint(Point(0.5, 0.5));
		cancel->setPosition(Point(662, 517));

		auto canceltext = Menu::create(cancel, NULL);
		canceltext->setAnchorPoint(Point(0.5, 0.5));
		canceltext->setPosition(Point(0, 0));
		canceltext->setTag(165);
		this->addChild(canceltext, 7);
		//구매한들
		char MyString[100];
		WideCharToMultiByte(CP_UTF8, 0, L"몇 주를 판매하시겠습니까?", -1, MyString, 100, NULL, NULL);
		auto name = Label::createWithTTF(MyString, "fonts/ABC.ttf", 25);
		name->setAnchorPoint(Point(0.5, 0.5));
		name->setPosition(Point(530, 480));
		name->setColor(Color3B::BLACK);
		name->setTag(164);
		this->addChild(name, 7);

		//구매 판업창

		Sprite* mainchr = Sprite::create("MiniGameResources/invest_pop.png");
		mainchr->setAnchorPoint(Point(0.5, 0));
		mainchr->setPosition(Point(523, 280));
		mainchr->setTag(166);
		this->addChild(mainchr, 6);

		//한개구매
		auto text_item_1 = MenuItemImage::create(
			"MiniGameResources/textred1.png",
			"MiniGameResources/textred1pr.png",
			CC_CALLBACK_1(InvestScene::sell_1, this));
		text_item_1->setAnchorPoint(Point(0.5, 0.5));
		text_item_1->setPosition(Point(440, 425));

		auto text_item_L = Menu::create(text_item_1, NULL);
		text_item_L->setAnchorPoint(Point(0.5, 0.5));
		text_item_L->setPosition(Point(0, 0));
		text_item_L->setTag(146);
		this->addChild(text_item_L, 7);

		//두개구매
		auto text_item_L2 = MenuItemImage::create(
			"MiniGameResources/textred2.png",
			"MiniGameResources/textred2pr.png",
			CC_CALLBACK_1(InvestScene::sell_2, this));
		text_item_L2->setAnchorPoint(Point(0.5, 0.5));
		text_item_L2->setPosition(Point(480, 425));

		auto text_item_2 = Menu::create(text_item_L2, NULL);
		text_item_2->setAnchorPoint(Point(0.5, 0.5));
		text_item_2->setPosition(Point(0, 0));
		text_item_2->setTag(135);
		this->addChild(text_item_2, 7);

		//세개구매
		auto text_item_L3 = MenuItemImage::create(
			"MiniGameResources/textred3.png",
			"MiniGameResources/textred3pr.png",
			CC_CALLBACK_1(InvestScene::sell_3, this));
		text_item_L3->setAnchorPoint(Point(0.5, 0.5));
		text_item_L3->setPosition(Point(520, 425));

		auto text_item_3 = Menu::create(text_item_L3, NULL);
		text_item_3->setAnchorPoint(Point(0.5, 0.5));
		text_item_3->setPosition(Point(0, 0));
		text_item_3->setTag(136);
		this->addChild(text_item_3, 7);

		//네개구매
		auto text_item_L4 = MenuItemImage::create(
			"MiniGameResources/textred4.png",
			"MiniGameResources/textred4pr.png",
			CC_CALLBACK_1(InvestScene::sell_4, this));
		text_item_L4->setAnchorPoint(Point(0.5, 0.5));
		text_item_L4->setPosition(Point(560, 425));

		auto text_item_4 = Menu::create(text_item_L4, NULL);
		text_item_4->setAnchorPoint(Point(0.5, 0.5));
		text_item_4->setPosition(Point(0, 0));
		text_item_4->setTag(137);
		this->addChild(text_item_4, 7);

		//다섯개구매
		auto text_item_L5 = MenuItemImage::create(
			"MiniGameResources/textred5.png",
			"MiniGameResources/textred5pr.png",
			CC_CALLBACK_1(InvestScene::sell_5, this));
		text_item_L5->setAnchorPoint(Point(0.5, 0.5));
		text_item_L5->setPosition(Point(600, 425));

		auto text_item_5 = Menu::create(text_item_L5, NULL);
		text_item_5->setAnchorPoint(Point(0.5, 0.5));
		text_item_5->setPosition(Point(0, 0));
		text_item_5->setTag(138);
		this->addChild(text_item_5, 7);

		//여섯개구매
		auto text_item_L6 = MenuItemImage::create(
			"MiniGameResources/textred6.png",
			"MiniGameResources/textred6pr.png",
			CC_CALLBACK_1(InvestScene::sell_6, this));
		text_item_L6->setAnchorPoint(Point(0.5, 0.5));
		text_item_L6->setPosition(Point(440, 375));

		auto text_item_6 = Menu::create(text_item_L6, NULL);
		text_item_6->setAnchorPoint(Point(0.5, 0.5));
		text_item_6->setPosition(Point(0, 0));
		text_item_6->setTag(139);
		this->addChild(text_item_6, 7);

		//일곱개구매
		auto text_item_L7 = MenuItemImage::create(
			"MiniGameResources/textred7.png",
			"MiniGameResources/textred7pr.png",
			CC_CALLBACK_1(InvestScene::sell_7, this));
		text_item_L7->setAnchorPoint(Point(0.5, 0.5));
		text_item_L7->setPosition(Point(480, 375));

		auto text_item_7 = Menu::create(text_item_L7, NULL);
		text_item_7->setAnchorPoint(Point(0.5, 0.5));
		text_item_7->setPosition(Point(0, 0));
		text_item_7->setTag(140);
		this->addChild(text_item_7, 7);

		//여덟개구매
		auto text_item_L8 = MenuItemImage::create(
			"MiniGameResources/textred8.png",
			"MiniGameResources/textred8pr.png",
			CC_CALLBACK_1(InvestScene::sell_8, this));
		text_item_L8->setAnchorPoint(Point(0.5, 0.5));
		text_item_L8->setPosition(Point(520, 375));

		auto text_item_8 = Menu::create(text_item_L8, NULL);
		text_item_8->setAnchorPoint(Point(0.5, 0.5));
		text_item_8->setPosition(Point(0, 0));
		text_item_8->setTag(141);
		this->addChild(text_item_8, 7);

		//아홉개구매
		auto text_item_L9 = MenuItemImage::create(
			"MiniGameResources/textred9.png",
			"MiniGameResources/textred9pr.png",
			CC_CALLBACK_1(InvestScene::sell_9, this));
		text_item_L9->setAnchorPoint(Point(0.5, 0.5));
		text_item_L9->setPosition(Point(560, 375));

		auto text_item_9 = Menu::create(text_item_L9, NULL);
		text_item_9->setAnchorPoint(Point(0.5, 0.5));
		text_item_9->setPosition(Point(0, 0));
		text_item_9->setTag(142);
		this->addChild(text_item_9, 7);

		//열개구매
		auto text_item_L10 = MenuItemImage::create(
			"MiniGameResources/textred10.png",
			"MiniGameResources/textred10pr.png",
			CC_CALLBACK_1(InvestScene::sell_10, this));
		text_item_L10->setAnchorPoint(Point(0.5, 0.5));
		text_item_L10->setPosition(Point(600, 375));

		auto text_item_10 = Menu::create(text_item_L10, NULL);
		text_item_10->setAnchorPoint(Point(0.5, 0.5));
		text_item_10->setPosition(Point(0, 0));
		text_item_10->setTag(143);
		this->addChild(text_item_10, 7);


	}

	else if (open == true)
	{
		Singletons::getInstance()->num_S = 0;
		Singletons::getInstance()->num_A = 0;
		Singletons::getInstance()->num_H = 0;
		Singletons::getInstance()->num_K = 0;
		Singletons::getInstance()->num_L = 0;
		removeChildByTag(164);
		removeChildByTag(165);
		removeChildByTag(166);
		removeChildByTag(146);
		removeChildByTag(135);
		removeChildByTag(136);
		removeChildByTag(137);
		removeChildByTag(138);
		removeChildByTag(139);
		removeChildByTag(140);
		removeChildByTag(141);
		removeChildByTag(142);
		removeChildByTag(143);
		removeChildByTag(161);
		removeChildByTag(162);


		open = false;
	}
}
//애플구매
void InvestScene::buy_A(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);
	Singletons::getInstance()->num_A= 1;
	if (open == false) {

		open = true;

		//삭제 판업
		auto cancel = MenuItemImage::create(
			"MiniGameResources/UI_investX.png",
			"MiniGameResources/UI_investXpr.png",
			CC_CALLBACK_1(InvestScene::cancelbuy, this));
		cancel->setAnchorPoint(Point(0.5, 0.5));
		cancel->setPosition(Point(662, 517));

		auto canceltext = Menu::create(cancel, NULL);
		canceltext->setAnchorPoint(Point(0.5, 0.5));
		canceltext->setPosition(Point(0, 0));
		canceltext->setTag(165);
		this->addChild(canceltext, 7);
		//구매한들
		char MyString[100];
		WideCharToMultiByte(CP_UTF8, 0, L"몇 주를 구매하시겠습니까?", -1, MyString, 100, NULL, NULL);
		auto name = Label::createWithTTF(MyString, "fonts/ABC.ttf", 25);
		name->setAnchorPoint(Point(0.5, 0.5));
		name->setPosition(Point(530, 480));
		name->setColor(Color3B::BLACK);
		name->setTag(164);
		this->addChild(name, 7);

		//구매 판업창

		Sprite* mainchr = Sprite::create("MiniGameResources/invest_pop.png");
		mainchr->setAnchorPoint(Point(0.5, 0));
		mainchr->setPosition(Point(523, 280));
		mainchr->setTag(166);
		this->addChild(mainchr, 6);

		//한개구매
		auto text_item_1 = MenuItemImage::create(
			"MiniGameResources/text1.png",
			"MiniGameResources/text1pr.png",
			CC_CALLBACK_1(InvestScene::buy_1, this));
		text_item_1->setAnchorPoint(Point(0.5, 0.5));
		text_item_1->setPosition(Point(440, 425));

		auto text_item_L = Menu::create(text_item_1, NULL);
		text_item_L->setAnchorPoint(Point(0.5, 0.5));
		text_item_L->setPosition(Point(0, 0));
		text_item_L->setTag(146);
		this->addChild(text_item_L, 7);

		//두개구매
		auto text_item_L2 = MenuItemImage::create(
			"MiniGameResources/text2.png",
			"MiniGameResources/text2pr.png",
			CC_CALLBACK_1(InvestScene::buy_2, this));
		text_item_L2->setAnchorPoint(Point(0.5, 0.5));
		text_item_L2->setPosition(Point(480, 425));

		auto text_item_2 = Menu::create(text_item_L2, NULL);
		text_item_2->setAnchorPoint(Point(0.5, 0.5));
		text_item_2->setPosition(Point(0, 0));
		text_item_2->setTag(135);
		this->addChild(text_item_2, 7);

		//세개구매
		auto text_item_L3 = MenuItemImage::create(
			"MiniGameResources/text3.png",
			"MiniGameResources/text3pr.png",
			CC_CALLBACK_1(InvestScene::buy_3, this));
		text_item_L3->setAnchorPoint(Point(0.5, 0.5));
		text_item_L3->setPosition(Point(520, 425));

		auto text_item_3 = Menu::create(text_item_L3, NULL);
		text_item_3->setAnchorPoint(Point(0.5, 0.5));
		text_item_3->setPosition(Point(0, 0));
		text_item_3->setTag(136);
		this->addChild(text_item_3, 7);

		//네개구매
		auto text_item_L4 = MenuItemImage::create(
			"MiniGameResources/text4.png",
			"MiniGameResources/text4pr.png",
			CC_CALLBACK_1(InvestScene::buy_4, this));
		text_item_L4->setAnchorPoint(Point(0.5, 0.5));
		text_item_L4->setPosition(Point(560, 425));

		auto text_item_4 = Menu::create(text_item_L4, NULL);
		text_item_4->setAnchorPoint(Point(0.5, 0.5));
		text_item_4->setPosition(Point(0, 0));
		text_item_4->setTag(137);
		this->addChild(text_item_4, 7);

		//다섯개구매
		auto text_item_L5 = MenuItemImage::create(
			"MiniGameResources/text5.png",
			"MiniGameResources/text5pr.png",
			CC_CALLBACK_1(InvestScene::buy_5, this));
		text_item_L5->setAnchorPoint(Point(0.5, 0.5));
		text_item_L5->setPosition(Point(600, 425));

		auto text_item_5 = Menu::create(text_item_L5, NULL);
		text_item_5->setAnchorPoint(Point(0.5, 0.5));
		text_item_5->setPosition(Point(0, 0));
		text_item_5->setTag(138);
		this->addChild(text_item_5, 7);

		//여섯개구매
		auto text_item_L6 = MenuItemImage::create(
			"MiniGameResources/text6.png",
			"MiniGameResources/text6pr.png",
			CC_CALLBACK_1(InvestScene::buy_6, this));
		text_item_L6->setAnchorPoint(Point(0.5, 0.5));
		text_item_L6->setPosition(Point(440, 375));

		auto text_item_6 = Menu::create(text_item_L6, NULL);
		text_item_6->setAnchorPoint(Point(0.5, 0.5));
		text_item_6->setPosition(Point(0, 0));
		text_item_6->setTag(139);
		this->addChild(text_item_6, 7);

		//일곱개구매
		auto text_item_L7 = MenuItemImage::create(
			"MiniGameResources/text7.png",
			"MiniGameResources/text7pr.png",
			CC_CALLBACK_1(InvestScene::buy_7, this));
		text_item_L7->setAnchorPoint(Point(0.5, 0.5));
		text_item_L7->setPosition(Point(480, 375));

		auto text_item_7 = Menu::create(text_item_L7, NULL);
		text_item_7->setAnchorPoint(Point(0.5, 0.5));
		text_item_7->setPosition(Point(0, 0));
		text_item_7->setTag(140);
		this->addChild(text_item_7, 7);

		//여덟개구매
		auto text_item_L8 = MenuItemImage::create(
			"MiniGameResources/text8.png",
			"MiniGameResources/text8pr.png",
			CC_CALLBACK_1(InvestScene::buy_8, this));
		text_item_L8->setAnchorPoint(Point(0.5, 0.5));
		text_item_L8->setPosition(Point(520, 375));

		auto text_item_8 = Menu::create(text_item_L8, NULL);
		text_item_8->setAnchorPoint(Point(0.5, 0.5));
		text_item_8->setPosition(Point(0, 0));
		text_item_8->setTag(141);
		this->addChild(text_item_8, 7);

		//아홉개구매
		auto text_item_L9 = MenuItemImage::create(
			"MiniGameResources/text9.png",
			"MiniGameResources/text9pr.png",
			CC_CALLBACK_1(InvestScene::buy_9, this));
		text_item_L9->setAnchorPoint(Point(0.5, 0.5));
		text_item_L9->setPosition(Point(560, 375));

		auto text_item_9 = Menu::create(text_item_L9, NULL);
		text_item_9->setAnchorPoint(Point(0.5, 0.5));
		text_item_9->setPosition(Point(0, 0));
		text_item_9->setTag(142);
		this->addChild(text_item_9, 7);

		//열개구매
		auto text_item_L10 = MenuItemImage::create(
			"MiniGameResources/text10.png",
			"MiniGameResources/text10pr.png",
			CC_CALLBACK_1(InvestScene::buy_10, this));
		text_item_L10->setAnchorPoint(Point(0.5, 0.5));
		text_item_L10->setPosition(Point(600, 375));

		auto text_item_10 = Menu::create(text_item_L10, NULL);
		text_item_10->setAnchorPoint(Point(0.5, 0.5));
		text_item_10->setPosition(Point(0, 0));
		text_item_10->setTag(143);
		this->addChild(text_item_10, 7);


	}

	else if (open == true)
	{
		Singletons::getInstance()->num_S = 0;
		Singletons::getInstance()->num_A = 0;
		Singletons::getInstance()->num_H = 0;
		Singletons::getInstance()->num_K = 0;
		Singletons::getInstance()->num_L = 0;
		removeChildByTag(164);
		removeChildByTag(165);
		removeChildByTag(166);
		removeChildByTag(146);
		removeChildByTag(135);
		removeChildByTag(136);
		removeChildByTag(137);
		removeChildByTag(138);
		removeChildByTag(139);
		removeChildByTag(140);
		removeChildByTag(141);
		removeChildByTag(142);
		removeChildByTag(143);
		removeChildByTag(161);
		removeChildByTag(162);


		open = false;
	}

	if (Singletons::getInstance()->ju_A == 10)

	{
		removeChildByTag(164);
		removeChildByTag(165);
		removeChildByTag(166);
		removeChildByTag(146);
		removeChildByTag(135);
		removeChildByTag(136);
		removeChildByTag(137);
		removeChildByTag(138);
		removeChildByTag(139);
		removeChildByTag(140);
		removeChildByTag(141);
		removeChildByTag(142);
		removeChildByTag(143);
		removeChildByTag(161);
		removeChildByTag(162);

		Sprite* info = Sprite::create("MiniGameResources/pop_dontbuy.png");
		info->setAnchorPoint(Point(0.5, 0));
		info->setPosition(Point(520, 410));
		info->setTag(161);
		this->addChild(info, 5);

		auto cancel_1 = MenuItemImage::create(
			"MiniGameResources/pop_enter.png",
			"MiniGameResources/pop_enterpr.png",
			CC_CALLBACK_1(InvestScene::cancelbuy, this));
		cancel_1->setAnchorPoint(Point(0.5, 0.5));
		cancel_1->setPosition(Point(520, 450));

		auto canceltext_1 = Menu::create(cancel_1, NULL);
		canceltext_1->setAnchorPoint(Point(0.5, 0.5));
		canceltext_1->setPosition(Point(0, 0));
		canceltext_1->setTag(162);
		this->addChild(canceltext_1, 7);
	}
}
//애플판매
void InvestScene::sell_A(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);
	Singletons::getInstance()->num_A = 2;
	if (open == false) {

		open = true;

		//삭제 판업
		auto cancel = MenuItemImage::create(
			"MiniGameResources/UI_investX.png",
			"MiniGameResources/UI_investXpr.png",
			CC_CALLBACK_1(InvestScene::cancelbuy, this));
		cancel->setAnchorPoint(Point(0.5, 0.5));
		cancel->setPosition(Point(662, 517));

		auto canceltext = Menu::create(cancel, NULL);
		canceltext->setAnchorPoint(Point(0.5, 0.5));
		canceltext->setPosition(Point(0, 0));
		canceltext->setTag(165);
		this->addChild(canceltext, 7);
		//구매한들
		char MyString[100];
		WideCharToMultiByte(CP_UTF8, 0, L"몇 주를 판매하시겠습니까?", -1, MyString, 100, NULL, NULL);
		auto name = Label::createWithTTF(MyString, "fonts/ABC.ttf", 25);
		name->setAnchorPoint(Point(0.5, 0.5));
		name->setPosition(Point(530, 480));
		name->setColor(Color3B::BLACK);
		name->setTag(164);
		this->addChild(name, 7);

		//구매 판업창

		Sprite* mainchr = Sprite::create("MiniGameResources/invest_pop.png");
		mainchr->setAnchorPoint(Point(0.5, 0));
		mainchr->setPosition(Point(523, 280));
		mainchr->setTag(166);
		this->addChild(mainchr, 6);

		//한개구매
		auto text_item_1 = MenuItemImage::create(
			"MiniGameResources/textred1.png",
			"MiniGameResources/textred1pr.png",
			CC_CALLBACK_1(InvestScene::sell_1, this));
		text_item_1->setAnchorPoint(Point(0.5, 0.5));
		text_item_1->setPosition(Point(440, 425));

		auto text_item_L = Menu::create(text_item_1, NULL);
		text_item_L->setAnchorPoint(Point(0.5, 0.5));
		text_item_L->setPosition(Point(0, 0));
		text_item_L->setTag(146);
		this->addChild(text_item_L, 7);

		//두개구매
		auto text_item_L2 = MenuItemImage::create(
			"MiniGameResources/textred2.png",
			"MiniGameResources/textred2pr.png",
			CC_CALLBACK_1(InvestScene::sell_2, this));
		text_item_L2->setAnchorPoint(Point(0.5, 0.5));
		text_item_L2->setPosition(Point(480, 425));

		auto text_item_2 = Menu::create(text_item_L2, NULL);
		text_item_2->setAnchorPoint(Point(0.5, 0.5));
		text_item_2->setPosition(Point(0, 0));
		text_item_2->setTag(135);
		this->addChild(text_item_2, 7);

		//세개구매
		auto text_item_L3 = MenuItemImage::create(
			"MiniGameResources/textred3.png",
			"MiniGameResources/textred3pr.png",
			CC_CALLBACK_1(InvestScene::sell_3, this));
		text_item_L3->setAnchorPoint(Point(0.5, 0.5));
		text_item_L3->setPosition(Point(520, 425));

		auto text_item_3 = Menu::create(text_item_L3, NULL);
		text_item_3->setAnchorPoint(Point(0.5, 0.5));
		text_item_3->setPosition(Point(0, 0));
		text_item_3->setTag(136);
		this->addChild(text_item_3, 7);

		//네개구매
		auto text_item_L4 = MenuItemImage::create(
			"MiniGameResources/textred4.png",
			"MiniGameResources/textred4pr.png",
			CC_CALLBACK_1(InvestScene::sell_4, this));
		text_item_L4->setAnchorPoint(Point(0.5, 0.5));
		text_item_L4->setPosition(Point(560, 425));

		auto text_item_4 = Menu::create(text_item_L4, NULL);
		text_item_4->setAnchorPoint(Point(0.5, 0.5));
		text_item_4->setPosition(Point(0, 0));
		text_item_4->setTag(137);
		this->addChild(text_item_4, 7);

		//다섯개구매
		auto text_item_L5 = MenuItemImage::create(
			"MiniGameResources/textred5.png",
			"MiniGameResources/textred5pr.png",
			CC_CALLBACK_1(InvestScene::sell_5, this));
		text_item_L5->setAnchorPoint(Point(0.5, 0.5));
		text_item_L5->setPosition(Point(600, 425));

		auto text_item_5 = Menu::create(text_item_L5, NULL);
		text_item_5->setAnchorPoint(Point(0.5, 0.5));
		text_item_5->setPosition(Point(0, 0));
		text_item_5->setTag(138);
		this->addChild(text_item_5, 7);

		//여섯개구매
		auto text_item_L6 = MenuItemImage::create(
			"MiniGameResources/textred6.png",
			"MiniGameResources/textred6pr.png",
			CC_CALLBACK_1(InvestScene::sell_6, this));
		text_item_L6->setAnchorPoint(Point(0.5, 0.5));
		text_item_L6->setPosition(Point(440, 375));

		auto text_item_6 = Menu::create(text_item_L6, NULL);
		text_item_6->setAnchorPoint(Point(0.5, 0.5));
		text_item_6->setPosition(Point(0, 0));
		text_item_6->setTag(139);
		this->addChild(text_item_6, 7);

		//일곱개구매
		auto text_item_L7 = MenuItemImage::create(
			"MiniGameResources/textred7.png",
			"MiniGameResources/textred7pr.png",
			CC_CALLBACK_1(InvestScene::sell_7, this));
		text_item_L7->setAnchorPoint(Point(0.5, 0.5));
		text_item_L7->setPosition(Point(480, 375));

		auto text_item_7 = Menu::create(text_item_L7, NULL);
		text_item_7->setAnchorPoint(Point(0.5, 0.5));
		text_item_7->setPosition(Point(0, 0));
		text_item_7->setTag(140);
		this->addChild(text_item_7, 7);

		//여덟개구매
		auto text_item_L8 = MenuItemImage::create(
			"MiniGameResources/textred8.png",
			"MiniGameResources/textred8pr.png",
			CC_CALLBACK_1(InvestScene::sell_8, this));
		text_item_L8->setAnchorPoint(Point(0.5, 0.5));
		text_item_L8->setPosition(Point(520, 375));

		auto text_item_8 = Menu::create(text_item_L8, NULL);
		text_item_8->setAnchorPoint(Point(0.5, 0.5));
		text_item_8->setPosition(Point(0, 0));
		text_item_8->setTag(141);
		this->addChild(text_item_8, 7);

		//아홉개구매
		auto text_item_L9 = MenuItemImage::create(
			"MiniGameResources/textred9.png",
			"MiniGameResources/textred9pr.png",
			CC_CALLBACK_1(InvestScene::sell_9, this));
		text_item_L9->setAnchorPoint(Point(0.5, 0.5));
		text_item_L9->setPosition(Point(560, 375));

		auto text_item_9 = Menu::create(text_item_L9, NULL);
		text_item_9->setAnchorPoint(Point(0.5, 0.5));
		text_item_9->setPosition(Point(0, 0));
		text_item_9->setTag(142);
		this->addChild(text_item_9, 7);

		//열개구매
		auto text_item_L10 = MenuItemImage::create(
			"MiniGameResources/textred10.png",
			"MiniGameResources/textred10pr.png",
			CC_CALLBACK_1(InvestScene::sell_10, this));
		text_item_L10->setAnchorPoint(Point(0.5, 0.5));
		text_item_L10->setPosition(Point(600, 375));

		auto text_item_10 = Menu::create(text_item_L10, NULL);
		text_item_10->setAnchorPoint(Point(0.5, 0.5));
		text_item_10->setPosition(Point(0, 0));
		text_item_10->setTag(143);
		this->addChild(text_item_10, 7);


	}

	else if (open == true)
	{
		Singletons::getInstance()->num_S = 0;
		Singletons::getInstance()->num_A = 0;
		Singletons::getInstance()->num_H = 0;
		Singletons::getInstance()->num_K = 0;
		Singletons::getInstance()->num_L = 0;
		removeChildByTag(164);
		removeChildByTag(165);
		removeChildByTag(166);
		removeChildByTag(146);
		removeChildByTag(135);
		removeChildByTag(136);
		removeChildByTag(137);
		removeChildByTag(138);
		removeChildByTag(139);
		removeChildByTag(140);
		removeChildByTag(141);
		removeChildByTag(142);
		removeChildByTag(143);
		removeChildByTag(161);
		removeChildByTag(162);


		open = false;
	}
}
//하ㅏㄴ화구매
void InvestScene::buy_H(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);
	Singletons::getInstance()->num_H= 1;
	if (open == false) {

		open = true;

		//삭제 판업
		auto cancel = MenuItemImage::create(
			"MiniGameResources/UI_investX.png",
			"MiniGameResources/UI_investXpr.png",
			CC_CALLBACK_1(InvestScene::cancelbuy, this));
		cancel->setAnchorPoint(Point(0.5, 0.5));
		cancel->setPosition(Point(662, 517));

		auto canceltext = Menu::create(cancel, NULL);
		canceltext->setAnchorPoint(Point(0.5, 0.5));
		canceltext->setPosition(Point(0, 0));
		canceltext->setTag(165);
		this->addChild(canceltext, 7);
		//구매한들
		char MyString[100];
		WideCharToMultiByte(CP_UTF8, 0, L"몇 주를 구매하시겠습니까?", -1, MyString, 100, NULL, NULL);
		auto name = Label::createWithTTF(MyString, "fonts/ABC.ttf", 25);
		name->setAnchorPoint(Point(0.5, 0.5));
		name->setPosition(Point(530, 480));
		name->setColor(Color3B::BLACK);
		name->setTag(164);
		this->addChild(name, 7);

		//구매 판업창

		Sprite* mainchr = Sprite::create("MiniGameResources/invest_pop.png");
		mainchr->setAnchorPoint(Point(0.5, 0));
		mainchr->setPosition(Point(523, 280));
		mainchr->setTag(166);
		this->addChild(mainchr, 6);

		//한개구매
		auto text_item_1 = MenuItemImage::create(
			"MiniGameResources/text1.png",
			"MiniGameResources/text1pr.png",
			CC_CALLBACK_1(InvestScene::buy_1, this));
		text_item_1->setAnchorPoint(Point(0.5, 0.5));
		text_item_1->setPosition(Point(440, 425));

		auto text_item_L = Menu::create(text_item_1, NULL);
		text_item_L->setAnchorPoint(Point(0.5, 0.5));
		text_item_L->setPosition(Point(0, 0));
		text_item_L->setTag(146);
		this->addChild(text_item_L, 7);

		//두개구매
		auto text_item_L2 = MenuItemImage::create(
			"MiniGameResources/text2.png",
			"MiniGameResources/text2pr.png",
			CC_CALLBACK_1(InvestScene::buy_2, this));
		text_item_L2->setAnchorPoint(Point(0.5, 0.5));
		text_item_L2->setPosition(Point(480, 425));

		auto text_item_2 = Menu::create(text_item_L2, NULL);
		text_item_2->setAnchorPoint(Point(0.5, 0.5));
		text_item_2->setPosition(Point(0, 0));
		text_item_2->setTag(135);
		this->addChild(text_item_2, 7);

		//세개구매
		auto text_item_L3 = MenuItemImage::create(
			"MiniGameResources/text3.png",
			"MiniGameResources/text3pr.png",
			CC_CALLBACK_1(InvestScene::buy_3, this));
		text_item_L3->setAnchorPoint(Point(0.5, 0.5));
		text_item_L3->setPosition(Point(520, 425));

		auto text_item_3 = Menu::create(text_item_L3, NULL);
		text_item_3->setAnchorPoint(Point(0.5, 0.5));
		text_item_3->setPosition(Point(0, 0));
		text_item_3->setTag(136);
		this->addChild(text_item_3, 7);

		//네개구매
		auto text_item_L4 = MenuItemImage::create(
			"MiniGameResources/text4.png",
			"MiniGameResources/text4pr.png",
			CC_CALLBACK_1(InvestScene::buy_4, this));
		text_item_L4->setAnchorPoint(Point(0.5, 0.5));
		text_item_L4->setPosition(Point(560, 425));

		auto text_item_4 = Menu::create(text_item_L4, NULL);
		text_item_4->setAnchorPoint(Point(0.5, 0.5));
		text_item_4->setPosition(Point(0, 0));
		text_item_4->setTag(137);
		this->addChild(text_item_4, 7);

		//다섯개구매
		auto text_item_L5 = MenuItemImage::create(
			"MiniGameResources/text5.png",
			"MiniGameResources/text5pr.png",
			CC_CALLBACK_1(InvestScene::buy_5, this));
		text_item_L5->setAnchorPoint(Point(0.5, 0.5));
		text_item_L5->setPosition(Point(600, 425));

		auto text_item_5 = Menu::create(text_item_L5, NULL);
		text_item_5->setAnchorPoint(Point(0.5, 0.5));
		text_item_5->setPosition(Point(0, 0));
		text_item_5->setTag(138);
		this->addChild(text_item_5, 7);

		//여섯개구매
		auto text_item_L6 = MenuItemImage::create(
			"MiniGameResources/text6.png",
			"MiniGameResources/text6pr.png",
			CC_CALLBACK_1(InvestScene::buy_6, this));
		text_item_L6->setAnchorPoint(Point(0.5, 0.5));
		text_item_L6->setPosition(Point(440, 375));

		auto text_item_6 = Menu::create(text_item_L6, NULL);
		text_item_6->setAnchorPoint(Point(0.5, 0.5));
		text_item_6->setPosition(Point(0, 0));
		text_item_6->setTag(139);
		this->addChild(text_item_6, 7);

		//일곱개구매
		auto text_item_L7 = MenuItemImage::create(
			"MiniGameResources/text7.png",
			"MiniGameResources/text7pr.png",
			CC_CALLBACK_1(InvestScene::buy_7, this));
		text_item_L7->setAnchorPoint(Point(0.5, 0.5));
		text_item_L7->setPosition(Point(480, 375));

		auto text_item_7 = Menu::create(text_item_L7, NULL);
		text_item_7->setAnchorPoint(Point(0.5, 0.5));
		text_item_7->setPosition(Point(0, 0));
		text_item_7->setTag(140);
		this->addChild(text_item_7, 7);

		//여덟개구매
		auto text_item_L8 = MenuItemImage::create(
			"MiniGameResources/text8.png",
			"MiniGameResources/text8pr.png",
			CC_CALLBACK_1(InvestScene::buy_8, this));
		text_item_L8->setAnchorPoint(Point(0.5, 0.5));
		text_item_L8->setPosition(Point(520, 375));

		auto text_item_8 = Menu::create(text_item_L8, NULL);
		text_item_8->setAnchorPoint(Point(0.5, 0.5));
		text_item_8->setPosition(Point(0, 0));
		text_item_8->setTag(141);
		this->addChild(text_item_8, 7);

		//아홉개구매
		auto text_item_L9 = MenuItemImage::create(
			"MiniGameResources/text9.png",
			"MiniGameResources/text9pr.png",
			CC_CALLBACK_1(InvestScene::buy_9, this));
		text_item_L9->setAnchorPoint(Point(0.5, 0.5));
		text_item_L9->setPosition(Point(560, 375));

		auto text_item_9 = Menu::create(text_item_L9, NULL);
		text_item_9->setAnchorPoint(Point(0.5, 0.5));
		text_item_9->setPosition(Point(0, 0));
		text_item_9->setTag(142);
		this->addChild(text_item_9, 7);

		//열개구매
		auto text_item_L10 = MenuItemImage::create(
			"MiniGameResources/text10.png",
			"MiniGameResources/text10pr.png",
			CC_CALLBACK_1(InvestScene::buy_10, this));
		text_item_L10->setAnchorPoint(Point(0.5, 0.5));
		text_item_L10->setPosition(Point(600, 375));

		auto text_item_10 = Menu::create(text_item_L10, NULL);
		text_item_10->setAnchorPoint(Point(0.5, 0.5));
		text_item_10->setPosition(Point(0, 0));
		text_item_10->setTag(143);
		this->addChild(text_item_10, 7);


	}

	else if (open == true)
	{
		Singletons::getInstance()->num_S = 0;
		Singletons::getInstance()->num_A = 0;
		Singletons::getInstance()->num_H = 0;
		Singletons::getInstance()->num_K = 0;
		Singletons::getInstance()->num_L = 0;
		removeChildByTag(164);
		removeChildByTag(165);
		removeChildByTag(166);
		removeChildByTag(146);
		removeChildByTag(135);
		removeChildByTag(136);
		removeChildByTag(137);
		removeChildByTag(138);
		removeChildByTag(139);
		removeChildByTag(140);
		removeChildByTag(141);
		removeChildByTag(142);
		removeChildByTag(143);
		removeChildByTag(161);
		removeChildByTag(162);


		open = false;
	}
	if (Singletons::getInstance()->ju_H == 10)

	{
		removeChildByTag(164);
		removeChildByTag(165);
		removeChildByTag(166);
		removeChildByTag(146);
		removeChildByTag(135);
		removeChildByTag(136);
		removeChildByTag(137);
		removeChildByTag(138);
		removeChildByTag(139);
		removeChildByTag(140);
		removeChildByTag(141);
		removeChildByTag(142);
		removeChildByTag(143);
		removeChildByTag(161);
		removeChildByTag(162);

		Sprite* info = Sprite::create("MiniGameResources/pop_dontbuy.png");
		info->setAnchorPoint(Point(0.5, 0));
		info->setPosition(Point(520, 410));
		info->setTag(161);
		this->addChild(info, 5);

		auto cancel_1 = MenuItemImage::create(
			"MiniGameResources/pop_enter.png",
			"MiniGameResources/pop_enterpr.png",
			CC_CALLBACK_1(InvestScene::cancelbuy, this));
		cancel_1->setAnchorPoint(Point(0.5, 0.5));
		cancel_1->setPosition(Point(520, 450));

		auto canceltext_1 = Menu::create(cancel_1, NULL);
		canceltext_1->setAnchorPoint(Point(0.5, 0.5));
		canceltext_1->setPosition(Point(0, 0));
		canceltext_1->setTag(162);
		this->addChild(canceltext_1, 7);
	}
}
//한화판매
void InvestScene::sell_H(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);
	Singletons::getInstance()->num_H = 2;
	if (open == false) {

		open = true;

		//삭제 판업
		auto cancel = MenuItemImage::create(
			"MiniGameResources/UI_investX.png",
			"MiniGameResources/UI_investXpr.png",
			CC_CALLBACK_1(InvestScene::cancelbuy, this));
		cancel->setAnchorPoint(Point(0.5, 0.5));
		cancel->setPosition(Point(662, 517));

		auto canceltext = Menu::create(cancel, NULL);
		canceltext->setAnchorPoint(Point(0.5, 0.5));
		canceltext->setPosition(Point(0, 0));
		canceltext->setTag(165);
		this->addChild(canceltext, 7);
		//구매한들
		char MyString[100];
		WideCharToMultiByte(CP_UTF8, 0, L"몇 주를 판매하시겠습니까?", -1, MyString, 100, NULL, NULL);
		auto name = Label::createWithTTF(MyString, "fonts/ABC.ttf", 25);
		name->setAnchorPoint(Point(0.5, 0.5));
		name->setPosition(Point(530, 480));
		name->setColor(Color3B::BLACK);
		name->setTag(164);
		this->addChild(name, 7);

		//구매 판업창

		Sprite* mainchr = Sprite::create("MiniGameResources/invest_pop.png");
		mainchr->setAnchorPoint(Point(0.5, 0));
		mainchr->setPosition(Point(523, 280));
		mainchr->setTag(166);
		this->addChild(mainchr, 6);

		//한개구매
		auto text_item_1 = MenuItemImage::create(
			"MiniGameResources/textred1.png",
			"MiniGameResources/textred1pr.png",
			CC_CALLBACK_1(InvestScene::sell_1, this));
		text_item_1->setAnchorPoint(Point(0.5, 0.5));
		text_item_1->setPosition(Point(440, 425));

		auto text_item_L = Menu::create(text_item_1, NULL);
		text_item_L->setAnchorPoint(Point(0.5, 0.5));
		text_item_L->setPosition(Point(0, 0));
		text_item_L->setTag(146);
		this->addChild(text_item_L, 7);

		//두개구매
		auto text_item_L2 = MenuItemImage::create(
			"MiniGameResources/textred2.png",
			"MiniGameResources/textred2pr.png",
			CC_CALLBACK_1(InvestScene::sell_2, this));
		text_item_L2->setAnchorPoint(Point(0.5, 0.5));
		text_item_L2->setPosition(Point(480, 425));

		auto text_item_2 = Menu::create(text_item_L2, NULL);
		text_item_2->setAnchorPoint(Point(0.5, 0.5));
		text_item_2->setPosition(Point(0, 0));
		text_item_2->setTag(135);
		this->addChild(text_item_2, 7);

		//세개구매
		auto text_item_L3 = MenuItemImage::create(
			"MiniGameResources/textred3.png",
			"MiniGameResources/textred3pr.png",
			CC_CALLBACK_1(InvestScene::sell_3, this));
		text_item_L3->setAnchorPoint(Point(0.5, 0.5));
		text_item_L3->setPosition(Point(520, 425));

		auto text_item_3 = Menu::create(text_item_L3, NULL);
		text_item_3->setAnchorPoint(Point(0.5, 0.5));
		text_item_3->setPosition(Point(0, 0));
		text_item_3->setTag(136);
		this->addChild(text_item_3, 7);

		//네개구매
		auto text_item_L4 = MenuItemImage::create(
			"MiniGameResources/textred4.png",
			"MiniGameResources/textred4pr.png",
			CC_CALLBACK_1(InvestScene::sell_4, this));
		text_item_L4->setAnchorPoint(Point(0.5, 0.5));
		text_item_L4->setPosition(Point(560, 425));

		auto text_item_4 = Menu::create(text_item_L4, NULL);
		text_item_4->setAnchorPoint(Point(0.5, 0.5));
		text_item_4->setPosition(Point(0, 0));
		text_item_4->setTag(137);
		this->addChild(text_item_4, 7);

		//다섯개구매
		auto text_item_L5 = MenuItemImage::create(
			"MiniGameResources/textred5.png",
			"MiniGameResources/textred5pr.png",
			CC_CALLBACK_1(InvestScene::sell_5, this));
		text_item_L5->setAnchorPoint(Point(0.5, 0.5));
		text_item_L5->setPosition(Point(600, 425));

		auto text_item_5 = Menu::create(text_item_L5, NULL);
		text_item_5->setAnchorPoint(Point(0.5, 0.5));
		text_item_5->setPosition(Point(0, 0));
		text_item_5->setTag(138);
		this->addChild(text_item_5, 7);

		//여섯개구매
		auto text_item_L6 = MenuItemImage::create(
			"MiniGameResources/textred6.png",
			"MiniGameResources/textred6pr.png",
			CC_CALLBACK_1(InvestScene::sell_6, this));
		text_item_L6->setAnchorPoint(Point(0.5, 0.5));
		text_item_L6->setPosition(Point(440, 375));

		auto text_item_6 = Menu::create(text_item_L6, NULL);
		text_item_6->setAnchorPoint(Point(0.5, 0.5));
		text_item_6->setPosition(Point(0, 0));
		text_item_6->setTag(139);
		this->addChild(text_item_6, 7);

		//일곱개구매
		auto text_item_L7 = MenuItemImage::create(
			"MiniGameResources/textred7.png",
			"MiniGameResources/textred7pr.png",
			CC_CALLBACK_1(InvestScene::sell_7, this));
		text_item_L7->setAnchorPoint(Point(0.5, 0.5));
		text_item_L7->setPosition(Point(480, 375));

		auto text_item_7 = Menu::create(text_item_L7, NULL);
		text_item_7->setAnchorPoint(Point(0.5, 0.5));
		text_item_7->setPosition(Point(0, 0));
		text_item_7->setTag(140);
		this->addChild(text_item_7, 7);

		//여덟개구매
		auto text_item_L8 = MenuItemImage::create(
			"MiniGameResources/textred8.png",
			"MiniGameResources/textred8pr.png",
			CC_CALLBACK_1(InvestScene::sell_8, this));
		text_item_L8->setAnchorPoint(Point(0.5, 0.5));
		text_item_L8->setPosition(Point(520, 375));

		auto text_item_8 = Menu::create(text_item_L8, NULL);
		text_item_8->setAnchorPoint(Point(0.5, 0.5));
		text_item_8->setPosition(Point(0, 0));
		text_item_8->setTag(141);
		this->addChild(text_item_8, 7);

		//아홉개구매
		auto text_item_L9 = MenuItemImage::create(
			"MiniGameResources/textred9.png",
			"MiniGameResources/textred9pr.png",
			CC_CALLBACK_1(InvestScene::sell_9, this));
		text_item_L9->setAnchorPoint(Point(0.5, 0.5));
		text_item_L9->setPosition(Point(560, 375));

		auto text_item_9 = Menu::create(text_item_L9, NULL);
		text_item_9->setAnchorPoint(Point(0.5, 0.5));
		text_item_9->setPosition(Point(0, 0));
		text_item_9->setTag(142);
		this->addChild(text_item_9, 7);

		//열개구매
		auto text_item_L10 = MenuItemImage::create(
			"MiniGameResources/textred10.png",
			"MiniGameResources/textred10pr.png",
			CC_CALLBACK_1(InvestScene::sell_10, this));
		text_item_L10->setAnchorPoint(Point(0.5, 0.5));
		text_item_L10->setPosition(Point(600, 375));

		auto text_item_10 = Menu::create(text_item_L10, NULL);
		text_item_10->setAnchorPoint(Point(0.5, 0.5));
		text_item_10->setPosition(Point(0, 0));
		text_item_10->setTag(143);
		this->addChild(text_item_10, 7);


	}

	else if (open == true)
	{
		Singletons::getInstance()->num_S = 0;
		Singletons::getInstance()->num_A = 0;
		Singletons::getInstance()->num_H = 0;
		Singletons::getInstance()->num_K = 0;
		Singletons::getInstance()->num_L = 0;
		removeChildByTag(164);
		removeChildByTag(165);
		removeChildByTag(166);
		removeChildByTag(146);
		removeChildByTag(135);
		removeChildByTag(136);
		removeChildByTag(137);
		removeChildByTag(138);
		removeChildByTag(139);
		removeChildByTag(140);
		removeChildByTag(141);
		removeChildByTag(142);
		removeChildByTag(143);
		removeChildByTag(161);
		removeChildByTag(162);


		open = false;
	}
}
//기아구매
void InvestScene::buy_K(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);
	Singletons::getInstance()->num_K= 1;
	if (open == false) {

		open = true;

		//삭제 판업
		auto cancel = MenuItemImage::create(
			"MiniGameResources/UI_investX.png",
			"MiniGameResources/UI_investXpr.png",
			CC_CALLBACK_1(InvestScene::cancelbuy, this));
		cancel->setAnchorPoint(Point(0.5, 0.5));
		cancel->setPosition(Point(662, 517));

		auto canceltext = Menu::create(cancel, NULL);
		canceltext->setAnchorPoint(Point(0.5, 0.5));
		canceltext->setPosition(Point(0, 0));
		canceltext->setTag(165);
		this->addChild(canceltext, 7);
		//구매한들
		char MyString[100];
		WideCharToMultiByte(CP_UTF8, 0, L"몇 주를 구매하시겠습니까?", -1, MyString, 100, NULL, NULL);
		auto name = Label::createWithTTF(MyString, "fonts/ABC.ttf", 25);
		name->setAnchorPoint(Point(0.5, 0.5));
		name->setPosition(Point(530, 480));
		name->setColor(Color3B::BLACK);
		name->setTag(164);
		this->addChild(name, 7);

		//구매 판업창

		Sprite* mainchr = Sprite::create("MiniGameResources/invest_pop.png");
		mainchr->setAnchorPoint(Point(0.5, 0));
		mainchr->setPosition(Point(523, 280));
		mainchr->setTag(166);
		this->addChild(mainchr, 6);

		//한개구매
		auto text_item_1 = MenuItemImage::create(
			"MiniGameResources/text1.png",
			"MiniGameResources/text1pr.png",
			CC_CALLBACK_1(InvestScene::buy_1, this));
		text_item_1->setAnchorPoint(Point(0.5, 0.5));
		text_item_1->setPosition(Point(440, 425));

		auto text_item_L = Menu::create(text_item_1, NULL);
		text_item_L->setAnchorPoint(Point(0.5, 0.5));
		text_item_L->setPosition(Point(0, 0));
		text_item_L->setTag(146);
		this->addChild(text_item_L, 7);

		//두개구매
		auto text_item_L2 = MenuItemImage::create(
			"MiniGameResources/text2.png",
			"MiniGameResources/text2pr.png",
			CC_CALLBACK_1(InvestScene::buy_2, this));
		text_item_L2->setAnchorPoint(Point(0.5, 0.5));
		text_item_L2->setPosition(Point(480, 425));

		auto text_item_2 = Menu::create(text_item_L2, NULL);
		text_item_2->setAnchorPoint(Point(0.5, 0.5));
		text_item_2->setPosition(Point(0, 0));
		text_item_2->setTag(135);
		this->addChild(text_item_2, 7);

		//세개구매
		auto text_item_L3 = MenuItemImage::create(
			"MiniGameResources/text3.png",
			"MiniGameResources/text3pr.png",
			CC_CALLBACK_1(InvestScene::buy_3, this));
		text_item_L3->setAnchorPoint(Point(0.5, 0.5));
		text_item_L3->setPosition(Point(520, 425));

		auto text_item_3 = Menu::create(text_item_L3, NULL);
		text_item_3->setAnchorPoint(Point(0.5, 0.5));
		text_item_3->setPosition(Point(0, 0));
		text_item_3->setTag(136);
		this->addChild(text_item_3, 7);

		//네개구매
		auto text_item_L4 = MenuItemImage::create(
			"MiniGameResources/text4.png",
			"MiniGameResources/text4pr.png",
			CC_CALLBACK_1(InvestScene::buy_4, this));
		text_item_L4->setAnchorPoint(Point(0.5, 0.5));
		text_item_L4->setPosition(Point(560, 425));

		auto text_item_4 = Menu::create(text_item_L4, NULL);
		text_item_4->setAnchorPoint(Point(0.5, 0.5));
		text_item_4->setPosition(Point(0, 0));
		text_item_4->setTag(137);
		this->addChild(text_item_4, 7);

		//다섯개구매
		auto text_item_L5 = MenuItemImage::create(
			"MiniGameResources/text5.png",
			"MiniGameResources/text5pr.png",
			CC_CALLBACK_1(InvestScene::buy_5, this));
		text_item_L5->setAnchorPoint(Point(0.5, 0.5));
		text_item_L5->setPosition(Point(600, 425));

		auto text_item_5 = Menu::create(text_item_L5, NULL);
		text_item_5->setAnchorPoint(Point(0.5, 0.5));
		text_item_5->setPosition(Point(0, 0));
		text_item_5->setTag(138);
		this->addChild(text_item_5, 7);

		//여섯개구매
		auto text_item_L6 = MenuItemImage::create(
			"MiniGameResources/text6.png",
			"MiniGameResources/text6pr.png",
			CC_CALLBACK_1(InvestScene::buy_6, this));
		text_item_L6->setAnchorPoint(Point(0.5, 0.5));
		text_item_L6->setPosition(Point(440, 375));

		auto text_item_6 = Menu::create(text_item_L6, NULL);
		text_item_6->setAnchorPoint(Point(0.5, 0.5));
		text_item_6->setPosition(Point(0, 0));
		text_item_6->setTag(139);
		this->addChild(text_item_6, 7);

		//일곱개구매
		auto text_item_L7 = MenuItemImage::create(
			"MiniGameResources/text7.png",
			"MiniGameResources/text7pr.png",
			CC_CALLBACK_1(InvestScene::buy_7, this));
		text_item_L7->setAnchorPoint(Point(0.5, 0.5));
		text_item_L7->setPosition(Point(480, 375));

		auto text_item_7 = Menu::create(text_item_L7, NULL);
		text_item_7->setAnchorPoint(Point(0.5, 0.5));
		text_item_7->setPosition(Point(0, 0));
		text_item_7->setTag(140);
		this->addChild(text_item_7, 7);

		//여덟개구매
		auto text_item_L8 = MenuItemImage::create(
			"MiniGameResources/text8.png",
			"MiniGameResources/text8pr.png",
			CC_CALLBACK_1(InvestScene::buy_8, this));
		text_item_L8->setAnchorPoint(Point(0.5, 0.5));
		text_item_L8->setPosition(Point(520, 375));

		auto text_item_8 = Menu::create(text_item_L8, NULL);
		text_item_8->setAnchorPoint(Point(0.5, 0.5));
		text_item_8->setPosition(Point(0, 0));
		text_item_8->setTag(141);
		this->addChild(text_item_8, 7);

		//아홉개구매
		auto text_item_L9 = MenuItemImage::create(
			"MiniGameResources/text9.png",
			"MiniGameResources/text9pr.png",
			CC_CALLBACK_1(InvestScene::buy_9, this));
		text_item_L9->setAnchorPoint(Point(0.5, 0.5));
		text_item_L9->setPosition(Point(560, 375));

		auto text_item_9 = Menu::create(text_item_L9, NULL);
		text_item_9->setAnchorPoint(Point(0.5, 0.5));
		text_item_9->setPosition(Point(0, 0));
		text_item_9->setTag(142);
		this->addChild(text_item_9, 7);

		//열개구매
		auto text_item_L10 = MenuItemImage::create(
			"MiniGameResources/text10.png",
			"MiniGameResources/text10pr.png",
			CC_CALLBACK_1(InvestScene::buy_10, this));
		text_item_L10->setAnchorPoint(Point(0.5, 0.5));
		text_item_L10->setPosition(Point(600, 375));

		auto text_item_10 = Menu::create(text_item_L10, NULL);
		text_item_10->setAnchorPoint(Point(0.5, 0.5));
		text_item_10->setPosition(Point(0, 0));
		text_item_10->setTag(143);
		this->addChild(text_item_10, 7);


	}

	else if (open == true)
	{
		Singletons::getInstance()->num_S = 0;
		Singletons::getInstance()->num_A = 0;
		Singletons::getInstance()->num_H = 0;
		Singletons::getInstance()->num_K = 0;
		Singletons::getInstance()->num_L = 0;
		removeChildByTag(164);
		removeChildByTag(165);
		removeChildByTag(166);
		removeChildByTag(146);
		removeChildByTag(135);
		removeChildByTag(136);
		removeChildByTag(137);
		removeChildByTag(138);
		removeChildByTag(139);
		removeChildByTag(140);
		removeChildByTag(141);
		removeChildByTag(142);
		removeChildByTag(143);
		removeChildByTag(161);
		removeChildByTag(162);


		open = false;
	}
	if (Singletons::getInstance()->ju_K == 10)

	{
		removeChildByTag(164);
		removeChildByTag(165);
		removeChildByTag(166);
		removeChildByTag(146);
		removeChildByTag(135);
		removeChildByTag(136);
		removeChildByTag(137);
		removeChildByTag(138);
		removeChildByTag(139);
		removeChildByTag(140);
		removeChildByTag(141);
		removeChildByTag(142);
		removeChildByTag(143);
		removeChildByTag(161);
		removeChildByTag(162);

		Sprite* info = Sprite::create("MiniGameResources/pop_dontbuy.png");
		info->setAnchorPoint(Point(0.5, 0));
		info->setPosition(Point(520, 410));
		info->setTag(161);
		this->addChild(info, 5);

		auto cancel_1 = MenuItemImage::create(
			"MiniGameResources/pop_enter.png",
			"MiniGameResources/pop_enterpr.png",
			CC_CALLBACK_1(InvestScene::cancelbuy, this));
		cancel_1->setAnchorPoint(Point(0.5, 0.5));
		cancel_1->setPosition(Point(520, 450));

		auto canceltext_1 = Menu::create(cancel_1, NULL);
		canceltext_1->setAnchorPoint(Point(0.5, 0.5));
		canceltext_1->setPosition(Point(0, 0));
		canceltext_1->setTag(162);
		this->addChild(canceltext_1, 7);
	}
}
//기아판매
void InvestScene::sell_K(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);
	Singletons::getInstance()->num_K = 2;
	if (open == false) {

		open = true;

		//삭제 판업
		auto cancel = MenuItemImage::create(
			"MiniGameResources/UI_investX.png",
			"MiniGameResources/UI_investXpr.png",
			CC_CALLBACK_1(InvestScene::cancelbuy, this));
		cancel->setAnchorPoint(Point(0.5, 0.5));
		cancel->setPosition(Point(662, 517));

		auto canceltext = Menu::create(cancel, NULL);
		canceltext->setAnchorPoint(Point(0.5, 0.5));
		canceltext->setPosition(Point(0, 0));
		canceltext->setTag(165);
		this->addChild(canceltext, 7);
		//구매한들
		char MyString[100];
		WideCharToMultiByte(CP_UTF8, 0, L"몇 주를 판매하시겠습니까?", -1, MyString, 100, NULL, NULL);
		auto name = Label::createWithTTF(MyString, "fonts/ABC.ttf", 25);
		name->setAnchorPoint(Point(0.5, 0.5));
		name->setPosition(Point(530, 480));
		name->setColor(Color3B::BLACK);
		name->setTag(164);
		this->addChild(name, 7);

		//구매 판업창

		Sprite* mainchr = Sprite::create("MiniGameResources/invest_pop.png");
		mainchr->setAnchorPoint(Point(0.5, 0));
		mainchr->setPosition(Point(523, 280));
		mainchr->setTag(166);
		this->addChild(mainchr, 6);

		//한개구매
		auto text_item_1 = MenuItemImage::create(
			"MiniGameResources/textred1.png",
			"MiniGameResources/textred1pr.png",
			CC_CALLBACK_1(InvestScene::sell_1, this));
		text_item_1->setAnchorPoint(Point(0.5, 0.5));
		text_item_1->setPosition(Point(440, 425));

		auto text_item_L = Menu::create(text_item_1, NULL);
		text_item_L->setAnchorPoint(Point(0.5, 0.5));
		text_item_L->setPosition(Point(0, 0));
		text_item_L->setTag(146);
		this->addChild(text_item_L, 7);

		//두개구매
		auto text_item_L2 = MenuItemImage::create(
			"MiniGameResources/textred2.png",
			"MiniGameResources/textred2pr.png",
			CC_CALLBACK_1(InvestScene::sell_2, this));
		text_item_L2->setAnchorPoint(Point(0.5, 0.5));
		text_item_L2->setPosition(Point(480, 425));

		auto text_item_2 = Menu::create(text_item_L2, NULL);
		text_item_2->setAnchorPoint(Point(0.5, 0.5));
		text_item_2->setPosition(Point(0, 0));
		text_item_2->setTag(135);
		this->addChild(text_item_2, 7);

		//세개구매
		auto text_item_L3 = MenuItemImage::create(
			"MiniGameResources/textred3.png",
			"MiniGameResources/textred3pr.png",
			CC_CALLBACK_1(InvestScene::sell_3, this));
		text_item_L3->setAnchorPoint(Point(0.5, 0.5));
		text_item_L3->setPosition(Point(520, 425));

		auto text_item_3 = Menu::create(text_item_L3, NULL);
		text_item_3->setAnchorPoint(Point(0.5, 0.5));
		text_item_3->setPosition(Point(0, 0));
		text_item_3->setTag(136);
		this->addChild(text_item_3, 7);

		//네개구매
		auto text_item_L4 = MenuItemImage::create(
			"MiniGameResources/textred4.png",
			"MiniGameResources/textred4pr.png",
			CC_CALLBACK_1(InvestScene::sell_4, this));
		text_item_L4->setAnchorPoint(Point(0.5, 0.5));
		text_item_L4->setPosition(Point(560, 425));

		auto text_item_4 = Menu::create(text_item_L4, NULL);
		text_item_4->setAnchorPoint(Point(0.5, 0.5));
		text_item_4->setPosition(Point(0, 0));
		text_item_4->setTag(137);
		this->addChild(text_item_4, 7);

		//다섯개구매
		auto text_item_L5 = MenuItemImage::create(
			"MiniGameResources/textred5.png",
			"MiniGameResources/textred5pr.png",
			CC_CALLBACK_1(InvestScene::sell_5, this));
		text_item_L5->setAnchorPoint(Point(0.5, 0.5));
		text_item_L5->setPosition(Point(600, 425));

		auto text_item_5 = Menu::create(text_item_L5, NULL);
		text_item_5->setAnchorPoint(Point(0.5, 0.5));
		text_item_5->setPosition(Point(0, 0));
		text_item_5->setTag(138);
		this->addChild(text_item_5, 7);

		//여섯개구매
		auto text_item_L6 = MenuItemImage::create(
			"MiniGameResources/textred6.png",
			"MiniGameResources/textred6pr.png",
			CC_CALLBACK_1(InvestScene::sell_6, this));
		text_item_L6->setAnchorPoint(Point(0.5, 0.5));
		text_item_L6->setPosition(Point(440, 375));

		auto text_item_6 = Menu::create(text_item_L6, NULL);
		text_item_6->setAnchorPoint(Point(0.5, 0.5));
		text_item_6->setPosition(Point(0, 0));
		text_item_6->setTag(139);
		this->addChild(text_item_6, 7);

		//일곱개구매
		auto text_item_L7 = MenuItemImage::create(
			"MiniGameResources/textred7.png",
			"MiniGameResources/textred7pr.png",
			CC_CALLBACK_1(InvestScene::sell_7, this));
		text_item_L7->setAnchorPoint(Point(0.5, 0.5));
		text_item_L7->setPosition(Point(480, 375));

		auto text_item_7 = Menu::create(text_item_L7, NULL);
		text_item_7->setAnchorPoint(Point(0.5, 0.5));
		text_item_7->setPosition(Point(0, 0));
		text_item_7->setTag(140);
		this->addChild(text_item_7, 7);

		//여덟개구매
		auto text_item_L8 = MenuItemImage::create(
			"MiniGameResources/textred8.png",
			"MiniGameResources/textred8pr.png",
			CC_CALLBACK_1(InvestScene::sell_8, this));
		text_item_L8->setAnchorPoint(Point(0.5, 0.5));
		text_item_L8->setPosition(Point(520, 375));

		auto text_item_8 = Menu::create(text_item_L8, NULL);
		text_item_8->setAnchorPoint(Point(0.5, 0.5));
		text_item_8->setPosition(Point(0, 0));
		text_item_8->setTag(141);
		this->addChild(text_item_8, 7);

		//아홉개구매
		auto text_item_L9 = MenuItemImage::create(
			"MiniGameResources/textred9.png",
			"MiniGameResources/textred9pr.png",
			CC_CALLBACK_1(InvestScene::sell_9, this));
		text_item_L9->setAnchorPoint(Point(0.5, 0.5));
		text_item_L9->setPosition(Point(560, 375));

		auto text_item_9 = Menu::create(text_item_L9, NULL);
		text_item_9->setAnchorPoint(Point(0.5, 0.5));
		text_item_9->setPosition(Point(0, 0));
		text_item_9->setTag(142);
		this->addChild(text_item_9, 7);

		//열개구매
		auto text_item_L10 = MenuItemImage::create(
			"MiniGameResources/textred10.png",
			"MiniGameResources/textred10pr.png",
			CC_CALLBACK_1(InvestScene::sell_10, this));
		text_item_L10->setAnchorPoint(Point(0.5, 0.5));
		text_item_L10->setPosition(Point(600, 375));

		auto text_item_10 = Menu::create(text_item_L10, NULL);
		text_item_10->setAnchorPoint(Point(0.5, 0.5));
		text_item_10->setPosition(Point(0, 0));
		text_item_10->setTag(143);
		this->addChild(text_item_10, 7);


	}

	else if (open == true)
	{
		Singletons::getInstance()->num_S = 0;
		Singletons::getInstance()->num_A = 0;
		Singletons::getInstance()->num_H = 0;
		Singletons::getInstance()->num_K = 0;
		Singletons::getInstance()->num_L = 0;
		removeChildByTag(164);
		removeChildByTag(165);
		removeChildByTag(166);
		removeChildByTag(146);
		removeChildByTag(135);
		removeChildByTag(136);
		removeChildByTag(137);
		removeChildByTag(138);
		removeChildByTag(139);
		removeChildByTag(140);
		removeChildByTag(141);
		removeChildByTag(142);
		removeChildByTag(143);
		removeChildByTag(161);
		removeChildByTag(162);


		open = false;
	}
}
//엘쥐구매
void InvestScene::buy_L(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);
	Singletons::getInstance()->num_L= 1;
	if (open == false) {

		open = true;

		//삭제 판업
		auto cancel = MenuItemImage::create(
			"MiniGameResources/UI_investX.png",
			"MiniGameResources/UI_investXpr.png",
			CC_CALLBACK_1(InvestScene::cancelbuy, this));
		cancel->setAnchorPoint(Point(0.5, 0.5));
		cancel->setPosition(Point(662, 517));

		auto canceltext = Menu::create(cancel, NULL);
		canceltext->setAnchorPoint(Point(0.5, 0.5));
		canceltext->setPosition(Point(0, 0));
		canceltext->setTag(165);
		this->addChild(canceltext, 7);
		//구매한들
		char MyString[100];
		WideCharToMultiByte(CP_UTF8, 0, L"몇 주를 구매하시겠습니까?", -1, MyString, 100, NULL, NULL);
		auto name = Label::createWithTTF(MyString, "fonts/ABC.ttf", 25);
		name->setAnchorPoint(Point(0.5, 0.5));
		name->setPosition(Point(530, 480));
		name->setColor(Color3B::BLACK);
		name->setTag(164);
		this->addChild(name, 7);

		//구매 판업창

		Sprite* mainchr = Sprite::create("MiniGameResources/invest_pop.png");
		mainchr->setAnchorPoint(Point(0.5, 0));
		mainchr->setPosition(Point(523, 280));
		mainchr->setTag(166);
		this->addChild(mainchr, 6);

		//한개구매
		auto text_item_1 = MenuItemImage::create(
			"MiniGameResources/text1.png",
			"MiniGameResources/text1pr.png",
			CC_CALLBACK_1(InvestScene::buy_1, this));
		text_item_1->setAnchorPoint(Point(0.5, 0.5));
		text_item_1->setPosition(Point(440, 425));

		auto text_item_L = Menu::create(text_item_1, NULL);
		text_item_L->setAnchorPoint(Point(0.5, 0.5));
		text_item_L->setPosition(Point(0, 0));
		text_item_L->setTag(146);
		this->addChild(text_item_L, 7);

		//두개구매
		auto text_item_L2 = MenuItemImage::create(
			"MiniGameResources/text2.png",
			"MiniGameResources/text2pr.png",
			CC_CALLBACK_1(InvestScene::buy_2, this));
		text_item_L2->setAnchorPoint(Point(0.5, 0.5));
		text_item_L2->setPosition(Point(480, 425));

		auto text_item_2 = Menu::create(text_item_L2, NULL);
		text_item_2->setAnchorPoint(Point(0.5, 0.5));
		text_item_2->setPosition(Point(0, 0));
		text_item_2->setTag(135);
		this->addChild(text_item_2, 7);

		//세개구매
		auto text_item_L3 = MenuItemImage::create(
			"MiniGameResources/text3.png",
			"MiniGameResources/text3pr.png",
			CC_CALLBACK_1(InvestScene::buy_3, this));
		text_item_L3->setAnchorPoint(Point(0.5, 0.5));
		text_item_L3->setPosition(Point(520, 425));

		auto text_item_3 = Menu::create(text_item_L3, NULL);
		text_item_3->setAnchorPoint(Point(0.5, 0.5));
		text_item_3->setPosition(Point(0, 0));
		text_item_3->setTag(136);
		this->addChild(text_item_3, 7);

		//네개구매
		auto text_item_L4 = MenuItemImage::create(
			"MiniGameResources/text4.png",
			"MiniGameResources/text4pr.png",
			CC_CALLBACK_1(InvestScene::buy_4, this));
		text_item_L4->setAnchorPoint(Point(0.5, 0.5));
		text_item_L4->setPosition(Point(560, 425));

		auto text_item_4 = Menu::create(text_item_L4, NULL);
		text_item_4->setAnchorPoint(Point(0.5, 0.5));
		text_item_4->setPosition(Point(0, 0));
		text_item_4->setTag(137);
		this->addChild(text_item_4, 7);

		//다섯개구매
		auto text_item_L5 = MenuItemImage::create(
			"MiniGameResources/text5.png",
			"MiniGameResources/text5pr.png",
			CC_CALLBACK_1(InvestScene::buy_5, this));
		text_item_L5->setAnchorPoint(Point(0.5, 0.5));
		text_item_L5->setPosition(Point(600, 425));

		auto text_item_5 = Menu::create(text_item_L5, NULL);
		text_item_5->setAnchorPoint(Point(0.5, 0.5));
		text_item_5->setPosition(Point(0, 0));
		text_item_5->setTag(138);
		this->addChild(text_item_5, 7);

		//여섯개구매
		auto text_item_L6 = MenuItemImage::create(
			"MiniGameResources/text6.png",
			"MiniGameResources/text6pr.png",
			CC_CALLBACK_1(InvestScene::buy_6, this));
		text_item_L6->setAnchorPoint(Point(0.5, 0.5));
		text_item_L6->setPosition(Point(440, 375));

		auto text_item_6 = Menu::create(text_item_L6, NULL);
		text_item_6->setAnchorPoint(Point(0.5, 0.5));
		text_item_6->setPosition(Point(0, 0));
		text_item_6->setTag(139);
		this->addChild(text_item_6, 7);

		//일곱개구매
		auto text_item_L7 = MenuItemImage::create(
			"MiniGameResources/text7.png",
			"MiniGameResources/text7pr.png",
			CC_CALLBACK_1(InvestScene::buy_7, this));
		text_item_L7->setAnchorPoint(Point(0.5, 0.5));
		text_item_L7->setPosition(Point(480, 375));

		auto text_item_7 = Menu::create(text_item_L7, NULL);
		text_item_7->setAnchorPoint(Point(0.5, 0.5));
		text_item_7->setPosition(Point(0, 0));
		text_item_7->setTag(140);
		this->addChild(text_item_7, 7);

		//여덟개구매
		auto text_item_L8 = MenuItemImage::create(
			"MiniGameResources/text8.png",
			"MiniGameResources/text8pr.png",
			CC_CALLBACK_1(InvestScene::buy_8, this));
		text_item_L8->setAnchorPoint(Point(0.5, 0.5));
		text_item_L8->setPosition(Point(520, 375));

		auto text_item_8 = Menu::create(text_item_L8, NULL);
		text_item_8->setAnchorPoint(Point(0.5, 0.5));
		text_item_8->setPosition(Point(0, 0));
		text_item_8->setTag(141);
		this->addChild(text_item_8, 7);

		//아홉개구매
		auto text_item_L9 = MenuItemImage::create(
			"MiniGameResources/text9.png",
			"MiniGameResources/text9pr.png",
			CC_CALLBACK_1(InvestScene::buy_9, this));
		text_item_L9->setAnchorPoint(Point(0.5, 0.5));
		text_item_L9->setPosition(Point(560, 375));

		auto text_item_9 = Menu::create(text_item_L9, NULL);
		text_item_9->setAnchorPoint(Point(0.5, 0.5));
		text_item_9->setPosition(Point(0, 0));
		text_item_9->setTag(142);
		this->addChild(text_item_9, 7);

		//열개구매
		auto text_item_L10 = MenuItemImage::create(
			"MiniGameResources/text10.png",
			"MiniGameResources/text10pr.png",
			CC_CALLBACK_1(InvestScene::buy_10, this));
		text_item_L10->setAnchorPoint(Point(0.5, 0.5));
		text_item_L10->setPosition(Point(600, 375));

		auto text_item_10 = Menu::create(text_item_L10, NULL);
		text_item_10->setAnchorPoint(Point(0.5, 0.5));
		text_item_10->setPosition(Point(0, 0));
		text_item_10->setTag(143);
		this->addChild(text_item_10, 7);


	}

	else if (open == true)
	{
		Singletons::getInstance()->num_S = 0;
		Singletons::getInstance()->num_A = 0;
		Singletons::getInstance()->num_H = 0;
		Singletons::getInstance()->num_K = 0;
		Singletons::getInstance()->num_L = 0;
		removeChildByTag(164);
		removeChildByTag(165);
		removeChildByTag(166);
		removeChildByTag(146);
		removeChildByTag(135);
		removeChildByTag(136);
		removeChildByTag(137);
		removeChildByTag(138);
		removeChildByTag(139);
		removeChildByTag(140);
		removeChildByTag(141);
		removeChildByTag(142);
		removeChildByTag(143);
		removeChildByTag(161);
		removeChildByTag(162);


		open = false;
	}

	if (Singletons::getInstance()->ju_L == 10)

	{
		removeChildByTag(164);
		removeChildByTag(165);
		removeChildByTag(166);
		removeChildByTag(146);
		removeChildByTag(135);
		removeChildByTag(136);
		removeChildByTag(137);
		removeChildByTag(138);
		removeChildByTag(139);
		removeChildByTag(140);
		removeChildByTag(141);
		removeChildByTag(142);
		removeChildByTag(143);
		removeChildByTag(161);
		removeChildByTag(162);

		Sprite* info = Sprite::create("MiniGameResources/pop_dontbuy.png");
		info->setAnchorPoint(Point(0.5, 0));
		info->setPosition(Point(520, 410));
		info->setTag(161);
		this->addChild(info, 5);

		auto cancel_1 = MenuItemImage::create(
			"MiniGameResources/pop_enter.png",
			"MiniGameResources/pop_enterpr.png",
			CC_CALLBACK_1(InvestScene::cancelbuy, this));
		cancel_1->setAnchorPoint(Point(0.5, 0.5));
		cancel_1->setPosition(Point(520, 450));

		auto canceltext_1 = Menu::create(cancel_1, NULL);
		canceltext_1->setAnchorPoint(Point(0.5, 0.5));
		canceltext_1->setPosition(Point(0, 0));
		canceltext_1->setTag(162);
		this->addChild(canceltext_1, 7);
	}
}
//엘쥐판매
void InvestScene::sell_L(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);
	Singletons::getInstance()->num_L = 2;
	if (open == false) {

		open = true;

		//삭제 판업
		auto cancel = MenuItemImage::create(
			"MiniGameResources/UI_investX.png",
			"MiniGameResources/UI_investXpr.png",
			CC_CALLBACK_1(InvestScene::cancelbuy, this));
		cancel->setAnchorPoint(Point(0.5, 0.5));
		cancel->setPosition(Point(662, 517));

		auto canceltext = Menu::create(cancel, NULL);
		canceltext->setAnchorPoint(Point(0.5, 0.5));
		canceltext->setPosition(Point(0, 0));
		canceltext->setTag(165);
		this->addChild(canceltext, 7);
		//구매한들
		char MyString[100];
		WideCharToMultiByte(CP_UTF8, 0, L"몇 주를 판매하시겠습니까?", -1, MyString, 100, NULL, NULL);
		auto name = Label::createWithTTF(MyString, "fonts/ABC.ttf", 25);
		name->setAnchorPoint(Point(0.5, 0.5));
		name->setPosition(Point(530, 480));
		name->setColor(Color3B::BLACK);
		name->setTag(164);
		this->addChild(name, 7);

		//구매 판업창

		Sprite* mainchr = Sprite::create("MiniGameResources/invest_pop.png");
		mainchr->setAnchorPoint(Point(0.5, 0));
		mainchr->setPosition(Point(523, 280));
		mainchr->setTag(166);
		this->addChild(mainchr, 6);

		//한개구매
		auto text_item_1 = MenuItemImage::create(
			"MiniGameResources/textred1.png",
			"MiniGameResources/textred1pr.png",
			CC_CALLBACK_1(InvestScene::sell_1, this));
		text_item_1->setAnchorPoint(Point(0.5, 0.5));
		text_item_1->setPosition(Point(440, 425));

		auto text_item_L = Menu::create(text_item_1, NULL);
		text_item_L->setAnchorPoint(Point(0.5, 0.5));
		text_item_L->setPosition(Point(0, 0));
		text_item_L->setTag(146);
		this->addChild(text_item_L, 7);

		//두개구매
		auto text_item_L2 = MenuItemImage::create(
			"MiniGameResources/textred2.png",
			"MiniGameResources/textred2pr.png",
			CC_CALLBACK_1(InvestScene::sell_2, this));
		text_item_L2->setAnchorPoint(Point(0.5, 0.5));
		text_item_L2->setPosition(Point(480, 425));

		auto text_item_2 = Menu::create(text_item_L2, NULL);
		text_item_2->setAnchorPoint(Point(0.5, 0.5));
		text_item_2->setPosition(Point(0, 0));
		text_item_2->setTag(135);
		this->addChild(text_item_2, 7);

		//세개구매
		auto text_item_L3 = MenuItemImage::create(
			"MiniGameResources/textred3.png",
			"MiniGameResources/textred3pr.png",
			CC_CALLBACK_1(InvestScene::sell_3, this));
		text_item_L3->setAnchorPoint(Point(0.5, 0.5));
		text_item_L3->setPosition(Point(520, 425));

		auto text_item_3 = Menu::create(text_item_L3, NULL);
		text_item_3->setAnchorPoint(Point(0.5, 0.5));
		text_item_3->setPosition(Point(0, 0));
		text_item_3->setTag(136);
		this->addChild(text_item_3, 7);

		//네개구매
		auto text_item_L4 = MenuItemImage::create(
			"MiniGameResources/textred4.png",
			"MiniGameResources/textred4pr.png",
			CC_CALLBACK_1(InvestScene::sell_4, this));
		text_item_L4->setAnchorPoint(Point(0.5, 0.5));
		text_item_L4->setPosition(Point(560, 425));

		auto text_item_4 = Menu::create(text_item_L4, NULL);
		text_item_4->setAnchorPoint(Point(0.5, 0.5));
		text_item_4->setPosition(Point(0, 0));
		text_item_4->setTag(137);
		this->addChild(text_item_4, 7);

		//다섯개구매
		auto text_item_L5 = MenuItemImage::create(
			"MiniGameResources/textred5.png",
			"MiniGameResources/textred5pr.png",
			CC_CALLBACK_1(InvestScene::sell_5, this));
		text_item_L5->setAnchorPoint(Point(0.5, 0.5));
		text_item_L5->setPosition(Point(600, 425));

		auto text_item_5 = Menu::create(text_item_L5, NULL);
		text_item_5->setAnchorPoint(Point(0.5, 0.5));
		text_item_5->setPosition(Point(0, 0));
		text_item_5->setTag(138);
		this->addChild(text_item_5, 7);

		//여섯개구매
		auto text_item_L6 = MenuItemImage::create(
			"MiniGameResources/textred6.png",
			"MiniGameResources/textred6pr.png",
			CC_CALLBACK_1(InvestScene::sell_6, this));
		text_item_L6->setAnchorPoint(Point(0.5, 0.5));
		text_item_L6->setPosition(Point(440, 375));

		auto text_item_6 = Menu::create(text_item_L6, NULL);
		text_item_6->setAnchorPoint(Point(0.5, 0.5));
		text_item_6->setPosition(Point(0, 0));
		text_item_6->setTag(139);
		this->addChild(text_item_6, 7);

		//일곱개구매
		auto text_item_L7 = MenuItemImage::create(
			"MiniGameResources/textred7.png",
			"MiniGameResources/textred7pr.png",
			CC_CALLBACK_1(InvestScene::sell_7, this));
		text_item_L7->setAnchorPoint(Point(0.5, 0.5));
		text_item_L7->setPosition(Point(480, 375));

		auto text_item_7 = Menu::create(text_item_L7, NULL);
		text_item_7->setAnchorPoint(Point(0.5, 0.5));
		text_item_7->setPosition(Point(0, 0));
		text_item_7->setTag(140);
		this->addChild(text_item_7, 7);

		//여덟개구매
		auto text_item_L8 = MenuItemImage::create(
			"MiniGameResources/textred8.png",
			"MiniGameResources/textred8pr.png",
			CC_CALLBACK_1(InvestScene::sell_8, this));
		text_item_L8->setAnchorPoint(Point(0.5, 0.5));
		text_item_L8->setPosition(Point(520, 375));

		auto text_item_8 = Menu::create(text_item_L8, NULL);
		text_item_8->setAnchorPoint(Point(0.5, 0.5));
		text_item_8->setPosition(Point(0, 0));
		text_item_8->setTag(141);
		this->addChild(text_item_8, 7);

		//아홉개구매
		auto text_item_L9 = MenuItemImage::create(
			"MiniGameResources/textred9.png",
			"MiniGameResources/textred9pr.png",
			CC_CALLBACK_1(InvestScene::sell_9, this));
		text_item_L9->setAnchorPoint(Point(0.5, 0.5));
		text_item_L9->setPosition(Point(560, 375));

		auto text_item_9 = Menu::create(text_item_L9, NULL);
		text_item_9->setAnchorPoint(Point(0.5, 0.5));
		text_item_9->setPosition(Point(0, 0));
		text_item_9->setTag(142);
		this->addChild(text_item_9, 7);

		//열개구매
		auto text_item_L10 = MenuItemImage::create(
			"MiniGameResources/textred10.png",
			"MiniGameResources/textred10pr.png",
			CC_CALLBACK_1(InvestScene::sell_10, this));
		text_item_L10->setAnchorPoint(Point(0.5, 0.5));
		text_item_L10->setPosition(Point(600, 375));

		auto text_item_10 = Menu::create(text_item_L10, NULL);
		text_item_10->setAnchorPoint(Point(0.5, 0.5));
		text_item_10->setPosition(Point(0, 0));
		text_item_10->setTag(143);
		this->addChild(text_item_10, 7);


	}

	else if (open == true)
	{
		Singletons::getInstance()->num_S = 0;
		Singletons::getInstance()->num_A = 0;
		Singletons::getInstance()->num_H = 0;
		Singletons::getInstance()->num_K = 0;
		Singletons::getInstance()->num_L = 0;
		removeChildByTag(164);
		removeChildByTag(165);
		removeChildByTag(166);
		removeChildByTag(146);
		removeChildByTag(135);
		removeChildByTag(136);
		removeChildByTag(137);
		removeChildByTag(138);
		removeChildByTag(139);
		removeChildByTag(140);
		removeChildByTag(141);
		removeChildByTag(142);
		removeChildByTag(143);
		removeChildByTag(161);
		removeChildByTag(162);


		open = false;
	}
}
////취소
//auto text_item_C = MenuItemImage::create(
//	"MiniGameResources/UI_no.png",
//	"MiniGameResources/UI_nopr.png",
//	CC_CALLBACK_1(InvestScene::cancelsell, this));
//text_item_C->setAnchorPoint(Point(0.5, 0.5));
//text_item_C->setPosition(Point(570, 350));

//auto text_item_10C = Menu::create(text_item_C, NULL);
//text_item_10C->setAnchorPoint(Point(0.5, 0.5));
//text_item_10C->setPosition(Point(0, 0));
//text_item_10C->setTag(144);
//this->addChild(text_item_10C, 7);

////확인
//auto text_item_LT = MenuItemImage::create(
//	"MiniGameResources/UI_enter.png",
//	"MiniGameResources/UI_enterpr.png",
//	CC_CALLBACK_1(InvestScene::buy, this));
//text_item_LT->setAnchorPoint(Point(0.5, 0.5));
//text_item_LT->setPosition(Point(470, 350));

//auto text_item_L10T = Menu::create(text_item_LT, NULL);
//text_item_L10T->setAnchorPoint(Point(0.5, 0.5));
//text_item_L10T->setPosition(Point(0, 0));
//text_item_L10T->setTag(145);
//this->addChild(text_item_L10T, 7);

//한주구매
void InvestScene::buy_1(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);
	//삼성구매
	{
		if (Singletons::getInstance()->money >= Singletons::getInstance()->samsung_1)
		{
			if (Singletons::getInstance()->num_S == 1)
			{
				Singletons::getInstance()->ju_S = Singletons::getInstance()->ju_S + 1;
				Singletons::getInstance()->money = Singletons::getInstance()->money - (Singletons::getInstance()->samsung_1 * 1);
				removeChildByTag(164);
				removeChildByTag(165);
				removeChildByTag(166);
				removeChildByTag(146);
				removeChildByTag(135);
				removeChildByTag(136);
				removeChildByTag(137);
				removeChildByTag(138);
				removeChildByTag(139);
				removeChildByTag(140);
				removeChildByTag(141);
				removeChildByTag(142);
				removeChildByTag(143);
				removeChildByTag(161);
				removeChildByTag(162);
			}
		}
		else if( Singletons::getInstance()->num_S == 1&&Singletons::getInstance()->money < Singletons::getInstance()->samsung_1)
		{
			removeChildByTag(164);
			removeChildByTag(165);
			removeChildByTag(166);
			removeChildByTag(146);
			removeChildByTag(135);
			removeChildByTag(136);
			removeChildByTag(137);
			removeChildByTag(138);
			removeChildByTag(139);
			removeChildByTag(140);
			removeChildByTag(141);
			removeChildByTag(142);
			removeChildByTag(143);
			removeChildByTag(161);
			removeChildByTag(162);

			Sprite* info = Sprite::create("MiniGameResources/pop_nomoney.png");
			info->setAnchorPoint(Point(0.5, 0));
			info->setPosition(Point(520, 410));
			info->setTag(164);
			this->addChild(info, 5);

			auto cancel = MenuItemImage::create(
				"MiniGameResources/pop_enter.png",
				"MiniGameResources/pop_enterpr.png",
				CC_CALLBACK_1(InvestScene::cancelbuy, this));
			cancel->setAnchorPoint(Point(0.5, 0.5));
			cancel->setPosition(Point(520, 450));

			auto canceltext = Menu::create(cancel, NULL);
			canceltext->setAnchorPoint(Point(0.5, 0.5));
			canceltext->setPosition(Point(0, 0));
			canceltext->setTag(165);
			this->addChild(canceltext, 7);
		}
		Singletons::getInstance()->num_S = 0;
	}
	
	//애플구매
	{
		if (Singletons::getInstance()->money >= Singletons::getInstance()->apple_1)
		{
			if (Singletons::getInstance()->num_A == 1)
			{
				Singletons::getInstance()->ju_A = Singletons::getInstance()->ju_A + 1;
				Singletons::getInstance()->money = Singletons::getInstance()->money - (Singletons::getInstance()->apple_1 * 1);
				removeChildByTag(164);
				removeChildByTag(165);
				removeChildByTag(166);
				removeChildByTag(146);
				removeChildByTag(135);
				removeChildByTag(136);
				removeChildByTag(137);
				removeChildByTag(138);
				removeChildByTag(139);
				removeChildByTag(140);
				removeChildByTag(141);
				removeChildByTag(142);
				removeChildByTag(143);
				removeChildByTag(161);
				removeChildByTag(162);
			}
		}
		else if (Singletons::getInstance()->num_A == 1 && Singletons::getInstance()->money < Singletons::getInstance()->apple_1)
		{
			removeChildByTag(164);
			removeChildByTag(165);
			removeChildByTag(166);
			removeChildByTag(146);
			removeChildByTag(135);
			removeChildByTag(136);
			removeChildByTag(137);
			removeChildByTag(138);
			removeChildByTag(139);
			removeChildByTag(140);
			removeChildByTag(141);
			removeChildByTag(142);
			removeChildByTag(143);
			removeChildByTag(161);
			removeChildByTag(162);

			Sprite* info = Sprite::create("MiniGameResources/pop_nomoney.png");
			info->setAnchorPoint(Point(0.5, 0));
			info->setPosition(Point(520, 410));
			info->setTag(164);
			this->addChild(info, 5);

			auto cancel = MenuItemImage::create(
				"MiniGameResources/pop_enter.png",
				"MiniGameResources/pop_enterpr.png",
				CC_CALLBACK_1(InvestScene::cancelbuy, this));
			cancel->setAnchorPoint(Point(0.5, 0.5));
			cancel->setPosition(Point(520, 450));

			auto canceltext = Menu::create(cancel, NULL);
			canceltext->setAnchorPoint(Point(0.5, 0.5));
			canceltext->setPosition(Point(0, 0));
			canceltext->setTag(165);
			this->addChild(canceltext, 7);
		}
		Singletons::getInstance()->num_A = 0;
	}

	//한화구매
	{
		if (Singletons::getInstance()->money >= Singletons::getInstance()->hanhwa_1)
		{
			if (Singletons::getInstance()->num_H == 1)
			{
				Singletons::getInstance()->ju_H = Singletons::getInstance()->ju_H + 1;
				Singletons::getInstance()->money = Singletons::getInstance()->money - (Singletons::getInstance()->hanhwa_1 * 1);
				removeChildByTag(164);
				removeChildByTag(165);
				removeChildByTag(166);
				removeChildByTag(146);
				removeChildByTag(135);
				removeChildByTag(136);
				removeChildByTag(137);
				removeChildByTag(138);
				removeChildByTag(139);
				removeChildByTag(140);
				removeChildByTag(141);
				removeChildByTag(142);
				removeChildByTag(143);
				removeChildByTag(161);
				removeChildByTag(162);
			}
		}
		else if (Singletons::getInstance()->num_H == 1 && Singletons::getInstance()->money < Singletons::getInstance()->hanhwa_1)
		{
			removeChildByTag(164);
			removeChildByTag(165);
			removeChildByTag(166);
			removeChildByTag(146);
			removeChildByTag(135);
			removeChildByTag(136);
			removeChildByTag(137);
			removeChildByTag(138);
			removeChildByTag(139);
			removeChildByTag(140);
			removeChildByTag(141);
			removeChildByTag(142);
			removeChildByTag(143);
			removeChildByTag(161);
			removeChildByTag(162);

			Sprite* info = Sprite::create("MiniGameResources/pop_nomoney.png");
			info->setAnchorPoint(Point(0.5, 0));
			info->setPosition(Point(520, 410));
			info->setTag(164);
			this->addChild(info, 5);

			auto cancel = MenuItemImage::create(
				"MiniGameResources/pop_enter.png",
				"MiniGameResources/pop_enterpr.png",
				CC_CALLBACK_1(InvestScene::cancelbuy, this));
			cancel->setAnchorPoint(Point(0.5, 0.5));
			cancel->setPosition(Point(520, 450));

			auto canceltext = Menu::create(cancel, NULL);
			canceltext->setAnchorPoint(Point(0.5, 0.5));
			canceltext->setPosition(Point(0, 0));
			canceltext->setTag(165);
			this->addChild(canceltext, 7);
		}
		Singletons::getInstance()->num_H = 0;
	}

	//기아구매
	{
		if (Singletons::getInstance()->money >= Singletons::getInstance()->kia_1)
		{
			if (Singletons::getInstance()->num_K == 1)
			{
				Singletons::getInstance()->ju_K = Singletons::getInstance()->ju_K + 1;
				Singletons::getInstance()->money = Singletons::getInstance()->money - (Singletons::getInstance()->kia_1 * 1);
				removeChildByTag(164);
				removeChildByTag(165);
				removeChildByTag(166);
				removeChildByTag(146);
				removeChildByTag(135);
				removeChildByTag(136);
				removeChildByTag(137);
				removeChildByTag(138);
				removeChildByTag(139);
				removeChildByTag(140);
				removeChildByTag(141);
				removeChildByTag(142);
				removeChildByTag(143);
				removeChildByTag(161);
				removeChildByTag(162);
			}
		}
		else if (Singletons::getInstance()->num_K == 1 && Singletons::getInstance()->money < Singletons::getInstance()->hanhwa_1)
		{
			removeChildByTag(164);
			removeChildByTag(165);
			removeChildByTag(166);
			removeChildByTag(146);
			removeChildByTag(135);
			removeChildByTag(136);
			removeChildByTag(137);
			removeChildByTag(138);
			removeChildByTag(139);
			removeChildByTag(140);
			removeChildByTag(141);
			removeChildByTag(142);
			removeChildByTag(143);
			removeChildByTag(161);
			removeChildByTag(162);

			Sprite* info = Sprite::create("MiniGameResources/pop_nomoney.png");
			info->setAnchorPoint(Point(0.5, 0));
			info->setPosition(Point(520, 410));
			info->setTag(164);
			this->addChild(info, 5);

			auto cancel = MenuItemImage::create(
				"MiniGameResources/pop_enter.png",
				"MiniGameResources/pop_enterpr.png",
				CC_CALLBACK_1(InvestScene::cancelbuy, this));
			cancel->setAnchorPoint(Point(0.5, 0.5));
			cancel->setPosition(Point(520, 450));

			auto canceltext = Menu::create(cancel, NULL);
			canceltext->setAnchorPoint(Point(0.5, 0.5));
			canceltext->setPosition(Point(0, 0));
			canceltext->setTag(165);
			this->addChild(canceltext, 7);
		}
		Singletons::getInstance()->num_K = 0;
	}
	//엘쥐구매
	{
		if (Singletons::getInstance()->money >= Singletons::getInstance()->lg_1)
		{
			if (Singletons::getInstance()->num_L == 1)
			{
				Singletons::getInstance()->ju_L = Singletons::getInstance()->ju_L + 1;
				Singletons::getInstance()->money = Singletons::getInstance()->money - (Singletons::getInstance()->lg_1 * 1);
				removeChildByTag(164);
				removeChildByTag(165);
				removeChildByTag(166);
				removeChildByTag(146);
				removeChildByTag(135);
				removeChildByTag(136);
				removeChildByTag(137);
				removeChildByTag(138);
				removeChildByTag(139);
				removeChildByTag(140);
				removeChildByTag(141);
				removeChildByTag(142);
				 removeChildByTag(143);
				removeChildByTag(161);
				removeChildByTag(162);
			}
		}
		else if (Singletons::getInstance()->num_L == 1 && Singletons::getInstance()->money < Singletons::getInstance()->lg_1)
		{
			removeChildByTag(164);
			removeChildByTag(165);
			removeChildByTag(166);
			removeChildByTag(146);
			removeChildByTag(135);
			removeChildByTag(136);
			removeChildByTag(137);
			removeChildByTag(138);
			removeChildByTag(139);
			removeChildByTag(140);
			removeChildByTag(141);
			removeChildByTag(142);
			removeChildByTag(143);
			removeChildByTag(161);
			removeChildByTag(162);

			Sprite* info = Sprite::create("MiniGameResources/pop_nomoney.png");
			info->setAnchorPoint(Point(0.5, 0));
			info->setPosition(Point(520, 410));
			info->setTag(164);
			this->addChild(info, 5);

			auto cancel = MenuItemImage::create(
				"MiniGameResources/pop_enter.png",
				"MiniGameResources/pop_enterpr.png",
				CC_CALLBACK_1(InvestScene::cancelbuy, this));
			cancel->setAnchorPoint(Point(0.5, 0.5));
			cancel->setPosition(Point(520, 450));

			auto canceltext = Menu::create(cancel, NULL);
			canceltext->setAnchorPoint(Point(0.5, 0.5));
			canceltext->setPosition(Point(0, 0));
			canceltext->setTag(165);
			this->addChild(canceltext, 7);
		}
		Singletons::getInstance()->num_L = 0;
	}
	
}

//2주구매
void InvestScene::buy_2(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);
	//삼성구매
	{
		if (Singletons::getInstance()->money >= Singletons::getInstance()->samsung_1*2)
		{
			if (Singletons::getInstance()->num_S == 1)
			{
				Singletons::getInstance()->ju_S = Singletons::getInstance()->ju_S + 2;
				Singletons::getInstance()->money = Singletons::getInstance()->money - (Singletons::getInstance()->samsung_1 * 2);
				removeChildByTag(164);
				removeChildByTag(165);
				removeChildByTag(166);
				removeChildByTag(146);
				removeChildByTag(135);
				removeChildByTag(136);
				removeChildByTag(137);
				removeChildByTag(138);
				removeChildByTag(139);
				removeChildByTag(140);
				removeChildByTag(141);
				removeChildByTag(142);
				removeChildByTag(143);
				removeChildByTag(161);
				removeChildByTag(162);

			}
		}
		else if (Singletons::getInstance()->num_S == 1 && Singletons::getInstance()->money < Singletons::getInstance()->samsung_1*2)
		{
			removeChildByTag(164);
			removeChildByTag(165);
			removeChildByTag(166);
			removeChildByTag(146);
			removeChildByTag(135);
			removeChildByTag(136);
			removeChildByTag(137);
			removeChildByTag(138);
			removeChildByTag(139);
			removeChildByTag(140);
			removeChildByTag(141);
			removeChildByTag(142);
			removeChildByTag(143);
			removeChildByTag(161);
			removeChildByTag(162);


			Sprite* info = Sprite::create("MiniGameResources/pop_nomoney.png");
			info->setAnchorPoint(Point(0.5, 0));
			info->setPosition(Point(520, 410));
			info->setTag(164);
			this->addChild(info, 5);

			auto cancel = MenuItemImage::create(
				"MiniGameResources/pop_enter.png",
				"MiniGameResources/pop_enterpr.png",
				CC_CALLBACK_1(InvestScene::cancelbuy, this));
			cancel->setAnchorPoint(Point(0.5, 0.5));
			cancel->setPosition(Point(520, 450));

			auto canceltext = Menu::create(cancel, NULL);
			canceltext->setAnchorPoint(Point(0.5, 0.5));
			canceltext->setPosition(Point(0, 0));
			canceltext->setTag(165);
			this->addChild(canceltext, 7);
		}
		Singletons::getInstance()->num_S = 0;
	}

	//애플구매
	{
		if (Singletons::getInstance()->money >= Singletons::getInstance()->apple_1 * 2)
		{
			if (Singletons::getInstance()->num_A == 1)
			{
				Singletons::getInstance()->ju_A = Singletons::getInstance()->ju_A + 2;
				Singletons::getInstance()->money = Singletons::getInstance()->money - (Singletons::getInstance()->apple_1 * 2);
				removeChildByTag(164);
				removeChildByTag(165);
				removeChildByTag(166);
				removeChildByTag(146);
				removeChildByTag(135);
				removeChildByTag(136);
				removeChildByTag(137);
				removeChildByTag(138);
				removeChildByTag(139);
				removeChildByTag(140);
				removeChildByTag(141);
				removeChildByTag(142);
				removeChildByTag(143);
				removeChildByTag(161);
				removeChildByTag(162);

			}
		}
		else if (Singletons::getInstance()->num_A == 1 && Singletons::getInstance()->money < Singletons::getInstance()->apple_1 * 2)
		{
			removeChildByTag(164);
			removeChildByTag(165);
			removeChildByTag(166);
			removeChildByTag(146);
			removeChildByTag(135);
			removeChildByTag(136);
			removeChildByTag(137);
			removeChildByTag(138);
			removeChildByTag(139);
			removeChildByTag(140);
			removeChildByTag(141);
			removeChildByTag(142);
			removeChildByTag(143);
			removeChildByTag(161);
			removeChildByTag(162);


			Sprite* info = Sprite::create("MiniGameResources/pop_nomoney.png");
			info->setAnchorPoint(Point(0.5, 0));
			info->setPosition(Point(520, 410));
			info->setTag(164);
			this->addChild(info, 5);

			auto cancel = MenuItemImage::create(
				"MiniGameResources/pop_enter.png",
				"MiniGameResources/pop_enterpr.png",
				CC_CALLBACK_1(InvestScene::cancelbuy, this));
			cancel->setAnchorPoint(Point(0.5, 0.5));
			cancel->setPosition(Point(520, 450));

			auto canceltext = Menu::create(cancel, NULL);
			canceltext->setAnchorPoint(Point(0.5, 0.5));
			canceltext->setPosition(Point(0, 0));
			canceltext->setTag(165);
			this->addChild(canceltext, 7);
		}
		Singletons::getInstance()->num_A = 0;
	}

	//한화구매
	{
		if (Singletons::getInstance()->money >= Singletons::getInstance()->hanhwa_1 * 2)
		{
			if (Singletons::getInstance()->num_H == 1)
			{
				Singletons::getInstance()->ju_H = Singletons::getInstance()->ju_H + 2;
				Singletons::getInstance()->money = Singletons::getInstance()->money - (Singletons::getInstance()->hanhwa_1 * 2);
				removeChildByTag(164);
				removeChildByTag(165);
				removeChildByTag(166);
				removeChildByTag(146);
				removeChildByTag(135);
				removeChildByTag(136);
				removeChildByTag(137);
				removeChildByTag(138);
				removeChildByTag(139);
				removeChildByTag(140);
				removeChildByTag(141);
				removeChildByTag(142);
				removeChildByTag(143);
				removeChildByTag(161);
				removeChildByTag(162);

			}
		}
		else if (Singletons::getInstance()->num_H == 1 && Singletons::getInstance()->money < Singletons::getInstance()->hanhwa_1 * 2)
		{
			removeChildByTag(164);
			removeChildByTag(165);
			removeChildByTag(166);
			removeChildByTag(146);
			removeChildByTag(135);
			removeChildByTag(136);
			removeChildByTag(137);
			removeChildByTag(138);
			removeChildByTag(139);
			removeChildByTag(140);
			removeChildByTag(141);
			removeChildByTag(142);
			removeChildByTag(143);
			removeChildByTag(161);
			removeChildByTag(162);


			Sprite* info = Sprite::create("MiniGameResources/pop_nomoney.png");
			info->setAnchorPoint(Point(0.5, 0));
			info->setPosition(Point(520, 410));
			info->setTag(164);
			this->addChild(info, 5);

			auto cancel = MenuItemImage::create(
				"MiniGameResources/pop_enter.png",
				"MiniGameResources/pop_enterpr.png",
				CC_CALLBACK_1(InvestScene::cancelbuy, this));
			cancel->setAnchorPoint(Point(0.5, 0.5));
			cancel->setPosition(Point(520, 450));

			auto canceltext = Menu::create(cancel, NULL);
			canceltext->setAnchorPoint(Point(0.5, 0.5));
			canceltext->setPosition(Point(0, 0));
			canceltext->setTag(165);
			this->addChild(canceltext, 7);
		}
		Singletons::getInstance()->num_H = 0;
	}

	//기아구매
	{
		if (Singletons::getInstance()->money >= Singletons::getInstance()->kia_1 * 2)
		{
			if (Singletons::getInstance()->num_K == 1)
			{
				Singletons::getInstance()->ju_K = Singletons::getInstance()->ju_K + 2;
				Singletons::getInstance()->money = Singletons::getInstance()->money - (Singletons::getInstance()->kia_1 * 2);
				removeChildByTag(164);
				removeChildByTag(165);
				removeChildByTag(166);
				removeChildByTag(146);
				removeChildByTag(135);
				removeChildByTag(136);
				removeChildByTag(137);
				removeChildByTag(138);
				removeChildByTag(139);
				removeChildByTag(140);
				removeChildByTag(141);
				removeChildByTag(142);
				removeChildByTag(143);
				removeChildByTag(161);
				removeChildByTag(162);

			}
		}
		else if (Singletons::getInstance()->num_K == 1 && Singletons::getInstance()->money < Singletons::getInstance()->kia_1 * 2)
		{
			removeChildByTag(164);
			removeChildByTag(165);
			removeChildByTag(166);
			removeChildByTag(146);
			removeChildByTag(135);
			removeChildByTag(136);
			removeChildByTag(137);
			removeChildByTag(138);
			removeChildByTag(139);
			removeChildByTag(140);
			removeChildByTag(141);
			removeChildByTag(142);
			removeChildByTag(143);
			removeChildByTag(161);
			removeChildByTag(162);

			Sprite* info = Sprite::create("MiniGameResources/pop_nomoney.png");
			info->setAnchorPoint(Point(0.5, 0));
			info->setPosition(Point(520, 410));
			info->setTag(164);
			this->addChild(info, 5);

			auto cancel = MenuItemImage::create(
				"MiniGameResources/pop_enter.png",
				"MiniGameResources/pop_enterpr.png",
				CC_CALLBACK_1(InvestScene::cancelbuy, this));
			cancel->setAnchorPoint(Point(0.5, 0.5));
			cancel->setPosition(Point(520, 450));

			auto canceltext = Menu::create(cancel, NULL);
			canceltext->setAnchorPoint(Point(0.5, 0.5));
			canceltext->setPosition(Point(0, 0));
			canceltext->setTag(165);
			this->addChild(canceltext, 7);
		}
		Singletons::getInstance()->num_K = 0;
	}

	//엘쥐구매
	{
		if (Singletons::getInstance()->money >= Singletons::getInstance()->lg_1 * 2)
		{
			if (Singletons::getInstance()->num_L == 1)
			{
				Singletons::getInstance()->ju_L = Singletons::getInstance()->ju_L + 2;
				Singletons::getInstance()->money = Singletons::getInstance()->money - (Singletons::getInstance()->lg_1 * 2);
				removeChildByTag(164);
				removeChildByTag(165);
				removeChildByTag(166);
				removeChildByTag(146);
				removeChildByTag(135);
				removeChildByTag(136);
				removeChildByTag(137);
				removeChildByTag(138);
				removeChildByTag(139);
				removeChildByTag(140);
				removeChildByTag(141);
				removeChildByTag(142);
				removeChildByTag(143);
				removeChildByTag(161);
				removeChildByTag(162);

			}
		}
		else if (Singletons::getInstance()->num_L == 1 && Singletons::getInstance()->money < Singletons::getInstance()->samsung_1 * 2)
		{
			removeChildByTag(164);
			removeChildByTag(165);
			removeChildByTag(166);
			removeChildByTag(146);
			removeChildByTag(135);
			removeChildByTag(136);
			removeChildByTag(137);
			removeChildByTag(138);
			removeChildByTag(139);
			removeChildByTag(140);
			removeChildByTag(141);
			removeChildByTag(142);
			removeChildByTag(143);
			removeChildByTag(161);
			removeChildByTag(162);

			Sprite* info = Sprite::create("MiniGameResources/pop_nomoney.png");
			info->setAnchorPoint(Point(0.5, 0));
			info->setPosition(Point(520, 410));
			info->setTag(164);
			this->addChild(info, 5);

			auto cancel = MenuItemImage::create(
				"MiniGameResources/pop_enter.png",
				"MiniGameResources/pop_enterpr.png",
				CC_CALLBACK_1(InvestScene::cancelbuy, this));
			cancel->setAnchorPoint(Point(0.5, 0.5));
			cancel->setPosition(Point(520, 450));

			auto canceltext = Menu::create(cancel, NULL);
			canceltext->setAnchorPoint(Point(0.5, 0.5));
			canceltext->setPosition(Point(0, 0));
			canceltext->setTag(165);
			this->addChild(canceltext, 7);
		}
		Singletons::getInstance()->num_S = 0;
	}

}

//3주구매
void InvestScene::buy_3(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);
	//삼성구매
	{
		if (Singletons::getInstance()->money >= Singletons::getInstance()->samsung_1 * 3)
		{
			if (Singletons::getInstance()->num_S == 1)
			{
				Singletons::getInstance()->ju_S = Singletons::getInstance()->ju_S + 3;
				Singletons::getInstance()->money = Singletons::getInstance()->money - (Singletons::getInstance()->samsung_1 * 3);
				removeChildByTag(164);
				removeChildByTag(165);
				removeChildByTag(166);
				removeChildByTag(146);
				removeChildByTag(135);
				removeChildByTag(136);
				removeChildByTag(137);
				removeChildByTag(138);
				removeChildByTag(139);
				removeChildByTag(140);
				removeChildByTag(141);
				removeChildByTag(142);
				removeChildByTag(143);
				removeChildByTag(161);
				removeChildByTag(162);

			}
		}
		else if (Singletons::getInstance()->num_S == 1 && Singletons::getInstance()->money < Singletons::getInstance()->samsung_1 * 3)
		{
			removeChildByTag(164);
			removeChildByTag(165);
			removeChildByTag(166);
			removeChildByTag(146);
			removeChildByTag(135);
			removeChildByTag(136);
			removeChildByTag(137);
			removeChildByTag(138);
			removeChildByTag(139);
			removeChildByTag(140);
			removeChildByTag(141);
			removeChildByTag(142);
			removeChildByTag(143);
			removeChildByTag(161);
			removeChildByTag(162);

			Sprite* info = Sprite::create("MiniGameResources/pop_nomoney.png");
			info->setAnchorPoint(Point(0.5, 0));
			info->setPosition(Point(520, 410));
			info->setTag(164);
			this->addChild(info, 5);

			auto cancel = MenuItemImage::create(
				"MiniGameResources/pop_enter.png",
				"MiniGameResources/pop_enterpr.png",
				CC_CALLBACK_1(InvestScene::cancelbuy, this));
			cancel->setAnchorPoint(Point(0.5, 0.5));
			cancel->setPosition(Point(520, 450));

			auto canceltext = Menu::create(cancel, NULL);
			canceltext->setAnchorPoint(Point(0.5, 0.5));
			canceltext->setPosition(Point(0, 0));
			canceltext->setTag(165);
			this->addChild(canceltext, 7);
		}
		Singletons::getInstance()->num_S = 0;
	}

	//애플구매
	{
		if (Singletons::getInstance()->money >= Singletons::getInstance()->apple_1 * 3)
		{
			if (Singletons::getInstance()->num_A == 1)
			{
				Singletons::getInstance()->ju_A = Singletons::getInstance()->ju_A + 3;
				Singletons::getInstance()->money = Singletons::getInstance()->money - (Singletons::getInstance()->apple_1 * 3);
				removeChildByTag(164);
				removeChildByTag(165);
				removeChildByTag(166);
				removeChildByTag(146);
				removeChildByTag(135);
				removeChildByTag(136);
				removeChildByTag(137);
				removeChildByTag(138);
				removeChildByTag(139);
				removeChildByTag(140);
				removeChildByTag(141);
				removeChildByTag(142);
				removeChildByTag(143);
				removeChildByTag(161);
				removeChildByTag(162);

			}
		}
		else if (Singletons::getInstance()->num_A == 1 && Singletons::getInstance()->money < Singletons::getInstance()->apple_1 * 3)
		{
			removeChildByTag(164);
			removeChildByTag(165);
			removeChildByTag(166);
			removeChildByTag(146);
			removeChildByTag(135);
			removeChildByTag(136);
			removeChildByTag(137);
			removeChildByTag(138);
			removeChildByTag(139);
			removeChildByTag(140);
			removeChildByTag(141);
			removeChildByTag(142);
			removeChildByTag(143);
			removeChildByTag(161);
			removeChildByTag(162);

			Sprite* info = Sprite::create("MiniGameResources/pop_nomoney.png");
			info->setAnchorPoint(Point(0.5, 0));
			info->setPosition(Point(520, 410));
			info->setTag(164);
			this->addChild(info, 5);

			auto cancel = MenuItemImage::create(
				"MiniGameResources/pop_enter.png",
				"MiniGameResources/pop_enterpr.png",
				CC_CALLBACK_1(InvestScene::cancelbuy, this));
			cancel->setAnchorPoint(Point(0.5, 0.5));
			cancel->setPosition(Point(520, 450));

			auto canceltext = Menu::create(cancel, NULL);
			canceltext->setAnchorPoint(Point(0.5, 0.5));
			canceltext->setPosition(Point(0, 0));
			canceltext->setTag(165);
			this->addChild(canceltext, 7);
		}
		Singletons::getInstance()->num_A = 0;
	}

	//한화구매
	{
		if (Singletons::getInstance()->money >= Singletons::getInstance()->hanhwa_1 * 3)
		{
			if (Singletons::getInstance()->num_H == 1)
			{
				Singletons::getInstance()->ju_H = Singletons::getInstance()->ju_H + 3;
				Singletons::getInstance()->money = Singletons::getInstance()->money - (Singletons::getInstance()->hanhwa_1 * 3);
				removeChildByTag(164);
				removeChildByTag(165);
				removeChildByTag(166);
				removeChildByTag(146);
				removeChildByTag(135);
				removeChildByTag(136);
				removeChildByTag(137);
				removeChildByTag(138);
				removeChildByTag(139);
				removeChildByTag(140);
				removeChildByTag(141);
				removeChildByTag(142);
				removeChildByTag(143);
				removeChildByTag(161);
				removeChildByTag(162);

			}
		}
		else if (Singletons::getInstance()->num_H == 1 && Singletons::getInstance()->money < Singletons::getInstance()->hanhwa_1 * 3)
		{
			removeChildByTag(164);
			removeChildByTag(165);
			removeChildByTag(166);
			removeChildByTag(146);
			removeChildByTag(135);
			removeChildByTag(136);
			removeChildByTag(137);
			removeChildByTag(138);
			removeChildByTag(139);
			removeChildByTag(140);
			removeChildByTag(141);
			removeChildByTag(142);
			removeChildByTag(143);
			removeChildByTag(161);
			removeChildByTag(162);

			Sprite* info = Sprite::create("MiniGameResources/pop_nomoney.png");
			info->setAnchorPoint(Point(0.5, 0));
			info->setPosition(Point(520, 410));
			info->setTag(164);
			this->addChild(info, 5);

			auto cancel = MenuItemImage::create(
				"MiniGameResources/pop_enter.png",
				"MiniGameResources/pop_enterpr.png",
				CC_CALLBACK_1(InvestScene::cancelbuy, this));
			cancel->setAnchorPoint(Point(0.5, 0.5));
			cancel->setPosition(Point(520, 450));

			auto canceltext = Menu::create(cancel, NULL);
			canceltext->setAnchorPoint(Point(0.5, 0.5));
			canceltext->setPosition(Point(0, 0));
			canceltext->setTag(165);
			this->addChild(canceltext, 7);
		}
		Singletons::getInstance()->num_H = 0;
	}

	//기아구매
	{
		if (Singletons::getInstance()->money >= Singletons::getInstance()->kia_1 * 3)
		{
			if (Singletons::getInstance()->num_K == 1)
			{
				Singletons::getInstance()->ju_K = Singletons::getInstance()->ju_K + 3;
				Singletons::getInstance()->money = Singletons::getInstance()->money - (Singletons::getInstance()->kia_1 * 3);
				removeChildByTag(164);
				removeChildByTag(165);
				removeChildByTag(166);
				removeChildByTag(146);
				removeChildByTag(135);
				removeChildByTag(136);
				removeChildByTag(137);
				removeChildByTag(138);
				removeChildByTag(139);
				removeChildByTag(140);
				removeChildByTag(141);
				removeChildByTag(142);
				removeChildByTag(143);
				removeChildByTag(161);
				removeChildByTag(162);

			}
		}
		else if (Singletons::getInstance()->num_K == 1 && Singletons::getInstance()->money < Singletons::getInstance()->kia_1 * 3)
		{
			removeChildByTag(164);
			removeChildByTag(165);
			removeChildByTag(166);
			removeChildByTag(146);
			removeChildByTag(135);
			removeChildByTag(136);
			removeChildByTag(137);
			removeChildByTag(138);
			removeChildByTag(139);
			removeChildByTag(140);
			removeChildByTag(141);
			removeChildByTag(142);
			removeChildByTag(143);
			removeChildByTag(161);
			removeChildByTag(162);

			Sprite* info = Sprite::create("MiniGameResources/pop_nomoney.png");
			info->setAnchorPoint(Point(0.5, 0));
			info->setPosition(Point(520, 410));
			info->setTag(164);
			this->addChild(info, 5);

			auto cancel = MenuItemImage::create(
				"MiniGameResources/pop_enter.png",
				"MiniGameResources/pop_enterpr.png",
				CC_CALLBACK_1(InvestScene::cancelbuy, this));
			cancel->setAnchorPoint(Point(0.5, 0.5));
			cancel->setPosition(Point(520, 450));

			auto canceltext = Menu::create(cancel, NULL);
			canceltext->setAnchorPoint(Point(0.5, 0.5));
			canceltext->setPosition(Point(0, 0));
			canceltext->setTag(165);
			this->addChild(canceltext, 7);
		}
		Singletons::getInstance()->num_K = 0;
	}

	//엘쥐구매
	{
		if (Singletons::getInstance()->money >= Singletons::getInstance()->lg_1 * 3)
		{
			if (Singletons::getInstance()->num_L == 1)
			{
				Singletons::getInstance()->ju_L = Singletons::getInstance()->ju_L + 3;
				Singletons::getInstance()->money = Singletons::getInstance()->money - (Singletons::getInstance()->lg_1 * 3);
				removeChildByTag(164);
				removeChildByTag(165);
				removeChildByTag(166);
				removeChildByTag(146);
				removeChildByTag(135);
				removeChildByTag(136);
				removeChildByTag(137);
				removeChildByTag(138);
				removeChildByTag(139);
				removeChildByTag(140);
				removeChildByTag(141);
				removeChildByTag(142);
				removeChildByTag(143);
				removeChildByTag(161);
				removeChildByTag(162);

			}
		}
		else if (Singletons::getInstance()->num_L == 1 && Singletons::getInstance()->money < Singletons::getInstance()->samsung_1 * 3)
		{
			removeChildByTag(164);
			removeChildByTag(165);
			removeChildByTag(166);
			removeChildByTag(146);
			removeChildByTag(135);
			removeChildByTag(136);
			removeChildByTag(137);
			removeChildByTag(138);
			removeChildByTag(139);
			removeChildByTag(140);
			removeChildByTag(141);
			removeChildByTag(142);
			removeChildByTag(143);
			removeChildByTag(161);
			removeChildByTag(162);

			Sprite* info = Sprite::create("MiniGameResources/pop_nomoney.png");
			info->setAnchorPoint(Point(0.5, 0));
			info->setPosition(Point(520, 410));
			info->setTag(164);
			this->addChild(info, 5);

			auto cancel = MenuItemImage::create(
				"MiniGameResources/pop_enter.png",
				"MiniGameResources/pop_enterpr.png",
				CC_CALLBACK_1(InvestScene::cancelbuy, this));
			cancel->setAnchorPoint(Point(0.5, 0.5));
			cancel->setPosition(Point(520, 450));

			auto canceltext = Menu::create(cancel, NULL);
			canceltext->setAnchorPoint(Point(0.5, 0.5));
			canceltext->setPosition(Point(0, 0));
			canceltext->setTag(165);
			this->addChild(canceltext, 7);
		}
		Singletons::getInstance()->num_S = 0;
	}
	
}

//4주구매
void InvestScene::buy_4(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);
	//삼성구매
	{
		if (Singletons::getInstance()->money >= Singletons::getInstance()->samsung_1 * 4)
		{
			if (Singletons::getInstance()->num_S == 1)
			{
				Singletons::getInstance()->ju_S = Singletons::getInstance()->ju_S + 4;
				Singletons::getInstance()->money = Singletons::getInstance()->money - (Singletons::getInstance()->samsung_1 * 4);
				removeChildByTag(164);
				removeChildByTag(165);
				removeChildByTag(166);
				removeChildByTag(146);
				removeChildByTag(135);
				removeChildByTag(136);
				removeChildByTag(137);
				removeChildByTag(138);
				removeChildByTag(139);
				removeChildByTag(140);
				removeChildByTag(141);
				removeChildByTag(142);
				removeChildByTag(143);
				removeChildByTag(161);
				removeChildByTag(162);

			}
		}
		else if (Singletons::getInstance()->num_S == 1 && Singletons::getInstance()->money < Singletons::getInstance()->samsung_1 * 4)
		{
			removeChildByTag(164);
			removeChildByTag(165);
			removeChildByTag(166);
			removeChildByTag(146);
			removeChildByTag(135);
			removeChildByTag(136);
			removeChildByTag(137);
			removeChildByTag(138);
			removeChildByTag(139);
			removeChildByTag(140);
			removeChildByTag(141);
			removeChildByTag(142);
			removeChildByTag(143);
			removeChildByTag(161);
			removeChildByTag(162);

			Sprite* info = Sprite::create("MiniGameResources/pop_nomoney.png");
			info->setAnchorPoint(Point(0.5, 0));
			info->setPosition(Point(520, 410));
			info->setTag(164);
			this->addChild(info, 5);

			auto cancel = MenuItemImage::create(
				"MiniGameResources/pop_enter.png",
				"MiniGameResources/pop_enterpr.png",
				CC_CALLBACK_1(InvestScene::cancelbuy, this));
			cancel->setAnchorPoint(Point(0.5, 0.5));
			cancel->setPosition(Point(520, 450));

			auto canceltext = Menu::create(cancel, NULL);
			canceltext->setAnchorPoint(Point(0.5, 0.5));
			canceltext->setPosition(Point(0, 0));
			canceltext->setTag(165);
			this->addChild(canceltext, 7);
		}
		Singletons::getInstance()->num_S = 0;
	}

	//애플구매
	{
		if (Singletons::getInstance()->money >= Singletons::getInstance()->apple_1 * 4)
		{
			if (Singletons::getInstance()->num_A == 1)
			{
				Singletons::getInstance()->ju_A = Singletons::getInstance()->ju_A + 4;
				Singletons::getInstance()->money = Singletons::getInstance()->money - (Singletons::getInstance()->apple_1 * 4);
				removeChildByTag(164);
				removeChildByTag(165);
				removeChildByTag(166);
				removeChildByTag(146);
				removeChildByTag(135);
				removeChildByTag(136);
				removeChildByTag(137);
				removeChildByTag(138);
				removeChildByTag(139);
				removeChildByTag(140);
				removeChildByTag(141);
				removeChildByTag(142);
				removeChildByTag(143);
				removeChildByTag(161);
				removeChildByTag(162);

			}
		}
		else if (Singletons::getInstance()->num_A == 1 && Singletons::getInstance()->money < Singletons::getInstance()->apple_1 * 4)
		{
			removeChildByTag(164);
			removeChildByTag(165);
			removeChildByTag(166);
			removeChildByTag(146);
			removeChildByTag(135);
			removeChildByTag(136);
			removeChildByTag(137);
			removeChildByTag(138);
			removeChildByTag(139);
			removeChildByTag(140);
			removeChildByTag(141);
			removeChildByTag(142);
			removeChildByTag(143);
			removeChildByTag(161);
			removeChildByTag(162);

			Sprite* info = Sprite::create("MiniGameResources/pop_nomoney.png");
			info->setAnchorPoint(Point(0.5, 0));
			info->setPosition(Point(520, 410));
			info->setTag(164);
			this->addChild(info, 5);

			auto cancel = MenuItemImage::create(
				"MiniGameResources/pop_enter.png",
				"MiniGameResources/pop_enterpr.png",
				CC_CALLBACK_1(InvestScene::cancelbuy, this));
			cancel->setAnchorPoint(Point(0.5, 0.5));
			cancel->setPosition(Point(520, 450));

			auto canceltext = Menu::create(cancel, NULL);
			canceltext->setAnchorPoint(Point(0.5, 0.5));
			canceltext->setPosition(Point(0, 0));
			canceltext->setTag(165);
			this->addChild(canceltext, 7);
		}
		Singletons::getInstance()->num_A = 0;
	}

	//한화구매
	{
		if (Singletons::getInstance()->money >= Singletons::getInstance()->hanhwa_1 * 4)
		{
			if (Singletons::getInstance()->num_H == 1)
			{
				Singletons::getInstance()->ju_H = Singletons::getInstance()->ju_H + 4;
				Singletons::getInstance()->money = Singletons::getInstance()->money - (Singletons::getInstance()->hanhwa_1 * 4);
				removeChildByTag(164);
				removeChildByTag(165);
				removeChildByTag(166);
				removeChildByTag(146);
				removeChildByTag(135);
				removeChildByTag(136);
				removeChildByTag(137);
				removeChildByTag(138);
				removeChildByTag(139);
				removeChildByTag(140);
				removeChildByTag(141);
				removeChildByTag(142);
				removeChildByTag(143);
				removeChildByTag(161);
				removeChildByTag(162);

			}
		}
		else if (Singletons::getInstance()->num_H == 1 && Singletons::getInstance()->money < Singletons::getInstance()->hanhwa_1 * 4)
		{
			removeChildByTag(164);
			removeChildByTag(165);
			removeChildByTag(166);
			removeChildByTag(146);
			removeChildByTag(135);
			removeChildByTag(136);
			removeChildByTag(137);
			removeChildByTag(138);
			removeChildByTag(139);
			removeChildByTag(140);
			removeChildByTag(141);
			removeChildByTag(142);
			removeChildByTag(143);
			removeChildByTag(161);
			removeChildByTag(162);

			Sprite* info = Sprite::create("MiniGameResources/pop_nomoney.png");
			info->setAnchorPoint(Point(0.5, 0));
			info->setPosition(Point(520, 410));
			info->setTag(164);
			this->addChild(info, 5);

			auto cancel = MenuItemImage::create(
				"MiniGameResources/pop_enter.png",
				"MiniGameResources/pop_enterpr.png",
				CC_CALLBACK_1(InvestScene::cancelbuy, this));
			cancel->setAnchorPoint(Point(0.5, 0.5));
			cancel->setPosition(Point(520, 450));

			auto canceltext = Menu::create(cancel, NULL);
			canceltext->setAnchorPoint(Point(0.5, 0.5));
			canceltext->setPosition(Point(0, 0));
			canceltext->setTag(165);
			this->addChild(canceltext, 7);
		}
		Singletons::getInstance()->num_H = 0;
	}

	//기아구매
	{
		if (Singletons::getInstance()->money >= Singletons::getInstance()->kia_1 * 4)
		{
			if (Singletons::getInstance()->num_K == 1)
			{
				Singletons::getInstance()->ju_K = Singletons::getInstance()->ju_K + 4;
				Singletons::getInstance()->money = Singletons::getInstance()->money - (Singletons::getInstance()->kia_1 * 4);
				removeChildByTag(164);
				removeChildByTag(165);
				removeChildByTag(166);
				removeChildByTag(146);
				removeChildByTag(135);
				removeChildByTag(136);
				removeChildByTag(137);
				removeChildByTag(138);
				removeChildByTag(139);
				removeChildByTag(140);
				removeChildByTag(141);
				removeChildByTag(142);
				removeChildByTag(143);
				removeChildByTag(161);
				removeChildByTag(162);

			}
		}
		else if (Singletons::getInstance()->num_K == 1 && Singletons::getInstance()->money < Singletons::getInstance()->kia_1 * 4)
		{
			removeChildByTag(164);
			removeChildByTag(165);
			removeChildByTag(166);
			removeChildByTag(146);
			removeChildByTag(135);
			removeChildByTag(136);
			removeChildByTag(137);
			removeChildByTag(138);
			removeChildByTag(139);
			removeChildByTag(140);
			removeChildByTag(141);
			removeChildByTag(142);
			removeChildByTag(143);
			removeChildByTag(161);
			removeChildByTag(162);

			Sprite* info = Sprite::create("MiniGameResources/pop_nomoney.png");
			info->setAnchorPoint(Point(0.5, 0));
			info->setPosition(Point(520, 410));
			info->setTag(164);
			this->addChild(info, 5);

			auto cancel = MenuItemImage::create(
				"MiniGameResources/pop_enter.png",
				"MiniGameResources/pop_enterpr.png",
				CC_CALLBACK_1(InvestScene::cancelbuy, this));
			cancel->setAnchorPoint(Point(0.5, 0.5));
			cancel->setPosition(Point(520, 450));

			auto canceltext = Menu::create(cancel, NULL);
			canceltext->setAnchorPoint(Point(0.5, 0.5));
			canceltext->setPosition(Point(0, 0));
			canceltext->setTag(165);
			this->addChild(canceltext, 7);
		}
		Singletons::getInstance()->num_K = 0;
	}

	//엘쥐구매
	{
		if (Singletons::getInstance()->money >= Singletons::getInstance()->lg_1 * 4)
		{
			if (Singletons::getInstance()->num_L == 1)
			{
				Singletons::getInstance()->ju_L = Singletons::getInstance()->ju_L + 4;
				Singletons::getInstance()->money = Singletons::getInstance()->money - (Singletons::getInstance()->lg_1 * 4);
				removeChildByTag(164);
				removeChildByTag(165);
				removeChildByTag(166);
				removeChildByTag(146);
				removeChildByTag(135);
				removeChildByTag(136);
				removeChildByTag(137);
				removeChildByTag(138);
				removeChildByTag(139);
				removeChildByTag(140);
				removeChildByTag(141);
				removeChildByTag(142);
				removeChildByTag(143);
				removeChildByTag(161);
				removeChildByTag(162);

			}
		}
		else if (Singletons::getInstance()->num_L == 1 && Singletons::getInstance()->money < Singletons::getInstance()->samsung_1 * 4)
		{
			removeChildByTag(164);
			removeChildByTag(165);
			removeChildByTag(166);
			removeChildByTag(146);
			removeChildByTag(135);
			removeChildByTag(136);
			removeChildByTag(137);
			removeChildByTag(138);
			removeChildByTag(139);
			removeChildByTag(140);
			removeChildByTag(141);
			removeChildByTag(142);
			removeChildByTag(143);
			removeChildByTag(161);
			removeChildByTag(162);

			Sprite* info = Sprite::create("MiniGameResources/pop_nomoney.png");
			info->setAnchorPoint(Point(0.5, 0));
			info->setPosition(Point(520, 410));
			info->setTag(164);
			this->addChild(info, 5);

			auto cancel = MenuItemImage::create(
				"MiniGameResources/pop_enter.png",
				"MiniGameResources/pop_enterpr.png",
				CC_CALLBACK_1(InvestScene::cancelbuy, this));
			cancel->setAnchorPoint(Point(0.5, 0.5));
			cancel->setPosition(Point(520, 450));

			auto canceltext = Menu::create(cancel, NULL);
			canceltext->setAnchorPoint(Point(0.5, 0.5));
			canceltext->setPosition(Point(0, 0));
			canceltext->setTag(165);
			this->addChild(canceltext, 7);
		}
		Singletons::getInstance()->num_S = 0;
	}
	
}

//5주구매
void InvestScene::buy_5(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);
	//삼성구매
	{
		if (Singletons::getInstance()->money >= Singletons::getInstance()->samsung_1 * 5)
		{
			if (Singletons::getInstance()->num_S == 1)
			{
				Singletons::getInstance()->ju_S = Singletons::getInstance()->ju_S + 5;
				Singletons::getInstance()->money = Singletons::getInstance()->money - (Singletons::getInstance()->samsung_1 * 5);
				removeChildByTag(164);
				removeChildByTag(165);
				removeChildByTag(166);
				removeChildByTag(146);
				removeChildByTag(135);
				removeChildByTag(136);
				removeChildByTag(137);
				removeChildByTag(138);
				removeChildByTag(139);
				removeChildByTag(140);
				removeChildByTag(141);
				removeChildByTag(142);
				removeChildByTag(143);
				removeChildByTag(161);
				removeChildByTag(162);

			}
		}
		else if (Singletons::getInstance()->num_S == 1 && Singletons::getInstance()->money < Singletons::getInstance()->samsung_1 * 5)
		{
			removeChildByTag(164);
			removeChildByTag(165);
			removeChildByTag(166);
			removeChildByTag(146);
			removeChildByTag(135);
			removeChildByTag(136);
			removeChildByTag(137);
			removeChildByTag(138);
			removeChildByTag(139);
			removeChildByTag(140);
			removeChildByTag(141);
			removeChildByTag(142);
			removeChildByTag(143);
			removeChildByTag(161);
			removeChildByTag(162);

			Sprite* info = Sprite::create("MiniGameResources/pop_nomoney.png");
			info->setAnchorPoint(Point(0.5, 0));
			info->setPosition(Point(520, 410));
			info->setTag(164);
			this->addChild(info, 5);

			auto cancel = MenuItemImage::create(
				"MiniGameResources/pop_enter.png",
				"MiniGameResources/pop_enterpr.png",
				CC_CALLBACK_1(InvestScene::cancelbuy, this));
			cancel->setAnchorPoint(Point(0.5, 0.5));
			cancel->setPosition(Point(520, 450));

			auto canceltext = Menu::create(cancel, NULL);
			canceltext->setAnchorPoint(Point(0.5, 0.5));
			canceltext->setPosition(Point(0, 0));
			canceltext->setTag(165);
			this->addChild(canceltext, 7);
		}
		Singletons::getInstance()->num_S = 0;
	}

	//애플구매
	{
		if (Singletons::getInstance()->money >= Singletons::getInstance()->apple_1 * 5)
		{
			if (Singletons::getInstance()->num_A == 1)
			{
				Singletons::getInstance()->ju_A = Singletons::getInstance()->ju_A + 5;
				Singletons::getInstance()->money = Singletons::getInstance()->money - (Singletons::getInstance()->apple_1 * 5);
				removeChildByTag(164);
				removeChildByTag(165);
				removeChildByTag(166);
				removeChildByTag(146);
				removeChildByTag(135);
				removeChildByTag(136);
				removeChildByTag(137);
				removeChildByTag(138);
				removeChildByTag(139);
				removeChildByTag(140);
				removeChildByTag(141);
				removeChildByTag(142);
				removeChildByTag(143);
				removeChildByTag(161);
				removeChildByTag(162);

			}
		}
		else if (Singletons::getInstance()->num_A == 1 && Singletons::getInstance()->money < Singletons::getInstance()->apple_1 * 5)
		{
			removeChildByTag(164);
			removeChildByTag(165);
			removeChildByTag(166);
			removeChildByTag(146);
			removeChildByTag(135);
			removeChildByTag(136);
			removeChildByTag(137);
			removeChildByTag(138);
			removeChildByTag(139);
			removeChildByTag(140);
			removeChildByTag(141);
			removeChildByTag(142);
			removeChildByTag(143);
			removeChildByTag(161);
			removeChildByTag(162);

			Sprite* info = Sprite::create("MiniGameResources/pop_nomoney.png");
			info->setAnchorPoint(Point(0.5, 0));
			info->setPosition(Point(520, 410));
			info->setTag(164);
			this->addChild(info, 5);

			auto cancel = MenuItemImage::create(
				"MiniGameResources/pop_enter.png",
				"MiniGameResources/pop_enterpr.png",
				CC_CALLBACK_1(InvestScene::cancelbuy, this));
			cancel->setAnchorPoint(Point(0.5, 0.5));
			cancel->setPosition(Point(520, 450));

			auto canceltext = Menu::create(cancel, NULL);
			canceltext->setAnchorPoint(Point(0.5, 0.5));
			canceltext->setPosition(Point(0, 0));
			canceltext->setTag(165);
			this->addChild(canceltext, 7);
		}
		Singletons::getInstance()->num_A = 0;
	}

	//한화구매
	{
		if (Singletons::getInstance()->money >= Singletons::getInstance()->hanhwa_1 * 5)
		{
			if (Singletons::getInstance()->num_H == 1)
			{
				Singletons::getInstance()->ju_H = Singletons::getInstance()->ju_H + 5;
				Singletons::getInstance()->money = Singletons::getInstance()->money - (Singletons::getInstance()->hanhwa_1 * 5);
				removeChildByTag(164);
				removeChildByTag(165);
				removeChildByTag(166);
				removeChildByTag(146);
				removeChildByTag(135);
				removeChildByTag(136);
				removeChildByTag(137);
				removeChildByTag(138);
				removeChildByTag(139);
				removeChildByTag(140);
				removeChildByTag(141);
				removeChildByTag(142);
				removeChildByTag(143);
				removeChildByTag(161);
				removeChildByTag(162);

			}
		}
		else if (Singletons::getInstance()->num_H == 1 && Singletons::getInstance()->money < Singletons::getInstance()->hanhwa_1 * 5)
		{
			removeChildByTag(164);
			removeChildByTag(165);
			removeChildByTag(166);
			removeChildByTag(146);
			removeChildByTag(135);
			removeChildByTag(136);
			removeChildByTag(137);
			removeChildByTag(138);
			removeChildByTag(139);
			removeChildByTag(140);
			removeChildByTag(141);
			removeChildByTag(142);
			removeChildByTag(143);
			removeChildByTag(161);
			removeChildByTag(162);

			Sprite* info = Sprite::create("MiniGameResources/pop_nomoney.png");
			info->setAnchorPoint(Point(0.5, 0));
			info->setPosition(Point(520, 410));
			info->setTag(164);
			this->addChild(info, 5);

			auto cancel = MenuItemImage::create(
				"MiniGameResources/pop_enter.png",
				"MiniGameResources/pop_enterpr.png",
				CC_CALLBACK_1(InvestScene::cancelbuy, this));
			cancel->setAnchorPoint(Point(0.5, 0.5));
			cancel->setPosition(Point(520, 450));

			auto canceltext = Menu::create(cancel, NULL);
			canceltext->setAnchorPoint(Point(0.5, 0.5));
			canceltext->setPosition(Point(0, 0));
			canceltext->setTag(165);
			this->addChild(canceltext, 7);
		}
		Singletons::getInstance()->num_H = 0;
	}

	//기아구매
	{
		if (Singletons::getInstance()->money >= Singletons::getInstance()->kia_1 * 5)
		{
			if (Singletons::getInstance()->num_K == 1)
			{
				Singletons::getInstance()->ju_K = Singletons::getInstance()->ju_K + 5;
				Singletons::getInstance()->money = Singletons::getInstance()->money - (Singletons::getInstance()->kia_1 * 5);
				removeChildByTag(164);
				removeChildByTag(165);
				removeChildByTag(166);
				removeChildByTag(146);
				removeChildByTag(135);
				removeChildByTag(136);
				removeChildByTag(137);
				removeChildByTag(138);
				removeChildByTag(139);
				removeChildByTag(140);
				removeChildByTag(141);
				removeChildByTag(142);
				removeChildByTag(143);
				removeChildByTag(161);
				removeChildByTag(162);

			}
		}
		else if (Singletons::getInstance()->num_K == 1 && Singletons::getInstance()->money < Singletons::getInstance()->kia_1 * 5)
		{
			removeChildByTag(164);
			removeChildByTag(165);
			removeChildByTag(166);
			removeChildByTag(146);
			removeChildByTag(135);
			removeChildByTag(136);
			removeChildByTag(137);
			removeChildByTag(138);
			removeChildByTag(139);
			removeChildByTag(140);
			removeChildByTag(141);
			removeChildByTag(142);
			removeChildByTag(143);
			removeChildByTag(161);
			removeChildByTag(162);

			Sprite* info = Sprite::create("MiniGameResources/pop_nomoney.png");
			info->setAnchorPoint(Point(0.5, 0));
			info->setPosition(Point(520, 410));
			info->setTag(164);
			this->addChild(info, 5);

			auto cancel = MenuItemImage::create(
				"MiniGameResources/pop_enter.png",
				"MiniGameResources/pop_enterpr.png",
				CC_CALLBACK_1(InvestScene::cancelbuy, this));
			cancel->setAnchorPoint(Point(0.5, 0.5));
			cancel->setPosition(Point(520, 450));

			auto canceltext = Menu::create(cancel, NULL);
			canceltext->setAnchorPoint(Point(0.5, 0.5));
			canceltext->setPosition(Point(0, 0));
			canceltext->setTag(165);
			this->addChild(canceltext, 7);
		}
		Singletons::getInstance()->num_K = 0;
	}

	//엘쥐구매
	{
		if (Singletons::getInstance()->money >= Singletons::getInstance()->lg_1 * 5)
		{
			if (Singletons::getInstance()->num_L == 1)
			{
				Singletons::getInstance()->ju_L = Singletons::getInstance()->ju_L + 5;
				Singletons::getInstance()->money = Singletons::getInstance()->money - (Singletons::getInstance()->lg_1 * 5);
				removeChildByTag(164);
				removeChildByTag(165);
				removeChildByTag(166);
				removeChildByTag(146);
				removeChildByTag(135);
				removeChildByTag(136);
				removeChildByTag(137);
				removeChildByTag(138);
				removeChildByTag(139);
				removeChildByTag(140);
				removeChildByTag(141);
				removeChildByTag(142);
				removeChildByTag(143);
				removeChildByTag(161);
				removeChildByTag(162);

			}
		}
		else if (Singletons::getInstance()->num_L == 1 && Singletons::getInstance()->money < Singletons::getInstance()->samsung_1 * 5)
		{
			removeChildByTag(164);
			removeChildByTag(165);
			removeChildByTag(166);
			removeChildByTag(146);
			removeChildByTag(135);
			removeChildByTag(136);
			removeChildByTag(137);
			removeChildByTag(138);
			removeChildByTag(139);
			removeChildByTag(140);
			removeChildByTag(141);
			removeChildByTag(142);
			removeChildByTag(143);
			removeChildByTag(161);
			removeChildByTag(162);

			Sprite* info = Sprite::create("MiniGameResources/pop_nomoney.png");
			info->setAnchorPoint(Point(0.5, 0));
			info->setPosition(Point(520, 410));
			info->setTag(164);
			this->addChild(info, 5);

			auto cancel = MenuItemImage::create(
				"MiniGameResources/pop_enter.png",
				"MiniGameResources/pop_enterpr.png",
				CC_CALLBACK_1(InvestScene::cancelbuy, this));
			cancel->setAnchorPoint(Point(0.5, 0.5));
			cancel->setPosition(Point(520, 450));

			auto canceltext = Menu::create(cancel, NULL);
			canceltext->setAnchorPoint(Point(0.5, 0.5));
			canceltext->setPosition(Point(0, 0));
			canceltext->setTag(165);
			this->addChild(canceltext, 7);
		}
		Singletons::getInstance()->num_S = 0;
	}
	
}

//6주구매
void InvestScene::buy_6(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);
	//삼성구매
	{
		if (Singletons::getInstance()->money >= Singletons::getInstance()->samsung_1 * 6)
		{
			if (Singletons::getInstance()->num_S == 1)
			{
				Singletons::getInstance()->ju_S = Singletons::getInstance()->ju_S + 6;
				Singletons::getInstance()->money = Singletons::getInstance()->money - (Singletons::getInstance()->samsung_1 * 6);
				removeChildByTag(164);
				removeChildByTag(165);
				removeChildByTag(166);
				removeChildByTag(146);
				removeChildByTag(135);
				removeChildByTag(136);
				removeChildByTag(137);
				removeChildByTag(138);
				removeChildByTag(139);
				removeChildByTag(140);
				removeChildByTag(141);
				removeChildByTag(142);
				removeChildByTag(143);
				removeChildByTag(161);
				removeChildByTag(162);

			}
		}
		else if (Singletons::getInstance()->num_S == 1 && Singletons::getInstance()->money < Singletons::getInstance()->samsung_1 * 6)
		{
			removeChildByTag(164);
			removeChildByTag(165);
			removeChildByTag(166);
			removeChildByTag(146);
			removeChildByTag(135);
			removeChildByTag(136);
			removeChildByTag(137);
			removeChildByTag(138);
			removeChildByTag(139);
			removeChildByTag(140);
			removeChildByTag(141);
			removeChildByTag(142);
			removeChildByTag(143);
			removeChildByTag(161);
			removeChildByTag(162);

			Sprite* info = Sprite::create("MiniGameResources/pop_nomoney.png");
			info->setAnchorPoint(Point(0.5, 0));
			info->setPosition(Point(520, 410));
			info->setTag(164);
			this->addChild(info, 5);

			auto cancel = MenuItemImage::create(
				"MiniGameResources/pop_enter.png",
				"MiniGameResources/pop_enterpr.png",
				CC_CALLBACK_1(InvestScene::cancelbuy, this));
			cancel->setAnchorPoint(Point(0.5, 0.5));
			cancel->setPosition(Point(520, 450));

			auto canceltext = Menu::create(cancel, NULL);
			canceltext->setAnchorPoint(Point(0.5, 0.5));
			canceltext->setPosition(Point(0, 0));
			canceltext->setTag(165);
			this->addChild(canceltext, 7);
		}
		Singletons::getInstance()->num_S = 0;
	}

	//애플구매
	{
		if (Singletons::getInstance()->money >= Singletons::getInstance()->apple_1 * 6)
		{
			if (Singletons::getInstance()->num_A == 1)
			{
				Singletons::getInstance()->ju_A = Singletons::getInstance()->ju_A + 6;
				Singletons::getInstance()->money = Singletons::getInstance()->money - (Singletons::getInstance()->apple_1 * 6);
				removeChildByTag(164);
				removeChildByTag(165);
				removeChildByTag(166);
				removeChildByTag(146);
				removeChildByTag(135);
				removeChildByTag(136);
				removeChildByTag(137);
				removeChildByTag(138);
				removeChildByTag(139);
				removeChildByTag(140);
				removeChildByTag(141);
				removeChildByTag(142);
				removeChildByTag(143);
				removeChildByTag(161);
				removeChildByTag(162);

			}
		}
		else if (Singletons::getInstance()->num_A == 1 && Singletons::getInstance()->money < Singletons::getInstance()->apple_1 * 6)
		{
			removeChildByTag(164);
			removeChildByTag(165);
			removeChildByTag(166);
			removeChildByTag(146);
			removeChildByTag(135);
			removeChildByTag(136);
			removeChildByTag(137);
			removeChildByTag(138);
			removeChildByTag(139);
			removeChildByTag(140);
			removeChildByTag(141);
			removeChildByTag(142);
			removeChildByTag(143);
			removeChildByTag(161);
			removeChildByTag(162);

			Sprite* info = Sprite::create("MiniGameResources/pop_nomoney.png");
			info->setAnchorPoint(Point(0.5, 0));
			info->setPosition(Point(520, 410));
			info->setTag(164);
			this->addChild(info, 5);

			auto cancel = MenuItemImage::create(
				"MiniGameResources/pop_enter.png",
				"MiniGameResources/pop_enterpr.png",
				CC_CALLBACK_1(InvestScene::cancelbuy, this));
			cancel->setAnchorPoint(Point(0.5, 0.5));
			cancel->setPosition(Point(520, 450));

			auto canceltext = Menu::create(cancel, NULL);
			canceltext->setAnchorPoint(Point(0.5, 0.5));
			canceltext->setPosition(Point(0, 0));
			canceltext->setTag(165);
			this->addChild(canceltext, 7);
		}
		Singletons::getInstance()->num_A = 0;
	}

	//한화구매
	{
		if (Singletons::getInstance()->money >= Singletons::getInstance()->hanhwa_1 * 6)
		{
			if (Singletons::getInstance()->num_H == 1)
			{
				Singletons::getInstance()->ju_H = Singletons::getInstance()->ju_H + 6;
				Singletons::getInstance()->money = Singletons::getInstance()->money - (Singletons::getInstance()->hanhwa_1 * 6);
				removeChildByTag(164);
				removeChildByTag(165);
				removeChildByTag(166);
				removeChildByTag(146);
				removeChildByTag(135);
				removeChildByTag(136);
				removeChildByTag(137);
				removeChildByTag(138);
				removeChildByTag(139);
				removeChildByTag(140);
				removeChildByTag(141);
				removeChildByTag(142);
				removeChildByTag(143);
				removeChildByTag(161);
				removeChildByTag(162);

			}
		}
		else if (Singletons::getInstance()->num_H == 1 && Singletons::getInstance()->money < Singletons::getInstance()->hanhwa_1 * 6)
		{
			removeChildByTag(164);
			removeChildByTag(165);
			removeChildByTag(166);
			removeChildByTag(146);
			removeChildByTag(135);
			removeChildByTag(136);
			removeChildByTag(137);
			removeChildByTag(138);
			removeChildByTag(139);
			removeChildByTag(140);
			removeChildByTag(141);
			removeChildByTag(142);
			removeChildByTag(143);
			removeChildByTag(161);
			removeChildByTag(162);

			Sprite* info = Sprite::create("MiniGameResources/pop_nomoney.png");
			info->setAnchorPoint(Point(0.5, 0));
			info->setPosition(Point(520, 410));
			info->setTag(164);
			this->addChild(info, 5);

			auto cancel = MenuItemImage::create(
				"MiniGameResources/pop_enter.png",
				"MiniGameResources/pop_enterpr.png",
				CC_CALLBACK_1(InvestScene::cancelbuy, this));
			cancel->setAnchorPoint(Point(0.5, 0.5));
			cancel->setPosition(Point(520, 450));

			auto canceltext = Menu::create(cancel, NULL);
			canceltext->setAnchorPoint(Point(0.5, 0.5));
			canceltext->setPosition(Point(0, 0));
			canceltext->setTag(165);
			this->addChild(canceltext, 7);
		}
		Singletons::getInstance()->num_H = 0;
	}

	//기아구매
	{
		if (Singletons::getInstance()->money >= Singletons::getInstance()->kia_1 * 6)
		{
			if (Singletons::getInstance()->num_K == 1)
			{
				Singletons::getInstance()->ju_K = Singletons::getInstance()->ju_K + 6;
				Singletons::getInstance()->money = Singletons::getInstance()->money - (Singletons::getInstance()->kia_1 * 6);
				removeChildByTag(164);
				removeChildByTag(165);
				removeChildByTag(166);
				removeChildByTag(146);
				removeChildByTag(135);
				removeChildByTag(136);
				removeChildByTag(137);
				removeChildByTag(138);
				removeChildByTag(139);
				removeChildByTag(140);
				removeChildByTag(141);
				removeChildByTag(142);
				removeChildByTag(143);
				removeChildByTag(161);
				removeChildByTag(162);

			}
		}
		else if (Singletons::getInstance()->num_K == 1 && Singletons::getInstance()->money < Singletons::getInstance()->kia_1 * 6)
		{
			removeChildByTag(164);
			removeChildByTag(165);
			removeChildByTag(166);
			removeChildByTag(146);
			removeChildByTag(135);
			removeChildByTag(136);
			removeChildByTag(137);
			removeChildByTag(138);
			removeChildByTag(139);
			removeChildByTag(140);
			removeChildByTag(141);
			removeChildByTag(142);
			removeChildByTag(143);
			removeChildByTag(161);
			removeChildByTag(162);

			Sprite* info = Sprite::create("MiniGameResources/pop_nomoney.png");
			info->setAnchorPoint(Point(0.5, 0));
			info->setPosition(Point(520, 410));
			info->setTag(164);
			this->addChild(info, 5);

			auto cancel = MenuItemImage::create(
				"MiniGameResources/pop_enter.png",
				"MiniGameResources/pop_enterpr.png",
				CC_CALLBACK_1(InvestScene::cancelbuy, this));
			cancel->setAnchorPoint(Point(0.5, 0.5));
			cancel->setPosition(Point(520, 450));

			auto canceltext = Menu::create(cancel, NULL);
			canceltext->setAnchorPoint(Point(0.5, 0.5));
			canceltext->setPosition(Point(0, 0));
			canceltext->setTag(165);
			this->addChild(canceltext, 7);
		}
		Singletons::getInstance()->num_K = 0;
	}

	//엘쥐구매
	{
		if (Singletons::getInstance()->money >= Singletons::getInstance()->lg_1 * 6)
		{
			if (Singletons::getInstance()->num_L == 1)
			{
				Singletons::getInstance()->ju_L = Singletons::getInstance()->ju_L + 6;
				Singletons::getInstance()->money = Singletons::getInstance()->money - (Singletons::getInstance()->lg_1 * 6);
				removeChildByTag(164);
				removeChildByTag(165);
				removeChildByTag(166);
				removeChildByTag(146);
				removeChildByTag(135);
				removeChildByTag(136);
				removeChildByTag(137);
				removeChildByTag(138);
				removeChildByTag(139);
				removeChildByTag(140);
				removeChildByTag(141);
				removeChildByTag(142);
				removeChildByTag(143);
				removeChildByTag(161);
				removeChildByTag(162);

			}
		}
		else if (Singletons::getInstance()->num_L == 1 && Singletons::getInstance()->money < Singletons::getInstance()->samsung_1 * 6)
		{
			removeChildByTag(164);
			removeChildByTag(165);
			removeChildByTag(166);
			removeChildByTag(146);
			removeChildByTag(135);
			removeChildByTag(136);
			removeChildByTag(137);
			removeChildByTag(138);
			removeChildByTag(139);
			removeChildByTag(140);
			removeChildByTag(141);
			removeChildByTag(142);
			removeChildByTag(143);
			removeChildByTag(161);
			removeChildByTag(162);

			Sprite* info = Sprite::create("MiniGameResources/pop_nomoney.png");
			info->setAnchorPoint(Point(0.5, 0));
			info->setPosition(Point(520, 410));
			info->setTag(164);
			this->addChild(info, 5);

			auto cancel = MenuItemImage::create(
				"MiniGameResources/pop_enter.png",
				"MiniGameResources/pop_enterpr.png",
				CC_CALLBACK_1(InvestScene::cancelbuy, this));
			cancel->setAnchorPoint(Point(0.5, 0.5));
			cancel->setPosition(Point(520, 450));

			auto canceltext = Menu::create(cancel, NULL);
			canceltext->setAnchorPoint(Point(0.5, 0.5));
			canceltext->setPosition(Point(0, 0));
			canceltext->setTag(165);
			this->addChild(canceltext, 7);
		}
		Singletons::getInstance()->num_S = 0;
	}

}

//7주구매
void InvestScene::buy_7(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);

	//삼성구매
	{
		if (Singletons::getInstance()->money >= Singletons::getInstance()->samsung_1 * 7)
		{
			if (Singletons::getInstance()->num_S == 1)
			{
				Singletons::getInstance()->ju_S = Singletons::getInstance()->ju_S + 7;
				Singletons::getInstance()->money = Singletons::getInstance()->money - (Singletons::getInstance()->samsung_1 * 7);
				removeChildByTag(164);
				removeChildByTag(165);
				removeChildByTag(166);
				removeChildByTag(146);
				removeChildByTag(135);
				removeChildByTag(136);
				removeChildByTag(137);
				removeChildByTag(138);
				removeChildByTag(139);
				removeChildByTag(140);
				removeChildByTag(141);
				removeChildByTag(142);
				removeChildByTag(143);
				removeChildByTag(161);
				removeChildByTag(162);

			}
		}
		else if (Singletons::getInstance()->num_S == 1 && Singletons::getInstance()->money < Singletons::getInstance()->samsung_1 * 7)
		{
			removeChildByTag(164);
			removeChildByTag(165);
			removeChildByTag(166);
			removeChildByTag(146);
			removeChildByTag(135);
			removeChildByTag(136);
			removeChildByTag(137);
			removeChildByTag(138);
			removeChildByTag(139);
			removeChildByTag(140);
			removeChildByTag(141);
			removeChildByTag(142);
			removeChildByTag(143);
			removeChildByTag(161);
			removeChildByTag(162);

			Sprite* info = Sprite::create("MiniGameResources/pop_nomoney.png");
			info->setAnchorPoint(Point(0.5, 0));
			info->setPosition(Point(520, 410));
			info->setTag(164);
			this->addChild(info, 5);

			auto cancel = MenuItemImage::create(
				"MiniGameResources/pop_enter.png",
				"MiniGameResources/pop_enterpr.png",
				CC_CALLBACK_1(InvestScene::cancelbuy, this));
			cancel->setAnchorPoint(Point(0.5, 0.5));
			cancel->setPosition(Point(520, 450));

			auto canceltext = Menu::create(cancel, NULL);
			canceltext->setAnchorPoint(Point(0.5, 0.5));
			canceltext->setPosition(Point(0, 0));
			canceltext->setTag(165);
			this->addChild(canceltext, 7);
		}
		Singletons::getInstance()->num_S = 0;
	}

	//애플구매
	{
		if (Singletons::getInstance()->money >= Singletons::getInstance()->apple_1 * 7)
		{
			if (Singletons::getInstance()->num_A == 1)
			{
				Singletons::getInstance()->ju_A = Singletons::getInstance()->ju_A + 7;
				Singletons::getInstance()->money = Singletons::getInstance()->money - (Singletons::getInstance()->apple_1 * 7);
				removeChildByTag(164);
				removeChildByTag(165);
				removeChildByTag(166);
				removeChildByTag(146);
				removeChildByTag(135);
				removeChildByTag(136);
				removeChildByTag(137);
				removeChildByTag(138);
				removeChildByTag(139);
				removeChildByTag(140);
				removeChildByTag(141);
				removeChildByTag(142);
				removeChildByTag(143);
				removeChildByTag(161);
				removeChildByTag(162);

			}
		}
		else if (Singletons::getInstance()->num_A == 1 && Singletons::getInstance()->money < Singletons::getInstance()->apple_1 * 7)
		{
			removeChildByTag(164);
			removeChildByTag(165);
			removeChildByTag(166);
			removeChildByTag(146);
			removeChildByTag(135);
			removeChildByTag(136);
			removeChildByTag(137);
			removeChildByTag(138);
			removeChildByTag(139);
			removeChildByTag(140);
			removeChildByTag(141);
			removeChildByTag(142);
			removeChildByTag(143);
			removeChildByTag(161);
			removeChildByTag(162);

			Sprite* info = Sprite::create("MiniGameResources/pop_nomoney.png");
			info->setAnchorPoint(Point(0.5, 0));
			info->setPosition(Point(520, 410));
			info->setTag(164);
			this->addChild(info, 5);

			auto cancel = MenuItemImage::create(
				"MiniGameResources/pop_enter.png",
				"MiniGameResources/pop_enterpr.png",
				CC_CALLBACK_1(InvestScene::cancelbuy, this));
			cancel->setAnchorPoint(Point(0.5, 0.5));
			cancel->setPosition(Point(520, 450));

			auto canceltext = Menu::create(cancel, NULL);
			canceltext->setAnchorPoint(Point(0.5, 0.5));
			canceltext->setPosition(Point(0, 0));
			canceltext->setTag(165);
			this->addChild(canceltext, 7);
		}
		Singletons::getInstance()->num_A = 0;
	}

	//한화구매
	{
		if (Singletons::getInstance()->money >= Singletons::getInstance()->hanhwa_1 * 7)
		{
			if (Singletons::getInstance()->num_H == 1)
			{
				Singletons::getInstance()->ju_H = Singletons::getInstance()->ju_H + 7;
				Singletons::getInstance()->money = Singletons::getInstance()->money - (Singletons::getInstance()->hanhwa_1 * 7);
				removeChildByTag(164);
				removeChildByTag(165);
				removeChildByTag(166);
				removeChildByTag(146);
				removeChildByTag(135);
				removeChildByTag(136);
				removeChildByTag(137);
				removeChildByTag(138);
				removeChildByTag(139);
				removeChildByTag(140);
				removeChildByTag(141);
				removeChildByTag(142);
				removeChildByTag(143);
				removeChildByTag(161);
				removeChildByTag(162);

			}
		}
		else if (Singletons::getInstance()->num_H == 1 && Singletons::getInstance()->money < Singletons::getInstance()->hanhwa_1 * 7)
		{
			removeChildByTag(164);
			removeChildByTag(165);
			removeChildByTag(166);
			removeChildByTag(146);
			removeChildByTag(135);
			removeChildByTag(136);
			removeChildByTag(137);
			removeChildByTag(138);
			removeChildByTag(139);
			removeChildByTag(140);
			removeChildByTag(141);
			removeChildByTag(142);
			removeChildByTag(143);
			removeChildByTag(161);
			removeChildByTag(162);

			Sprite* info = Sprite::create("MiniGameResources/pop_nomoney.png");
			info->setAnchorPoint(Point(0.5, 0));
			info->setPosition(Point(520, 410));
			info->setTag(164);
			this->addChild(info, 5);

			auto cancel = MenuItemImage::create(
				"MiniGameResources/pop_enter.png",
				"MiniGameResources/pop_enterpr.png",
				CC_CALLBACK_1(InvestScene::cancelbuy, this));
			cancel->setAnchorPoint(Point(0.5, 0.5));
			cancel->setPosition(Point(520, 450));

			auto canceltext = Menu::create(cancel, NULL);
			canceltext->setAnchorPoint(Point(0.5, 0.5));
			canceltext->setPosition(Point(0, 0));
			canceltext->setTag(165);
			this->addChild(canceltext, 7);
		}
		Singletons::getInstance()->num_H = 0;
	}

	//기아구매
	{
		if (Singletons::getInstance()->money >= Singletons::getInstance()->kia_1 * 7)
		{
			if (Singletons::getInstance()->num_K == 1)
			{
				Singletons::getInstance()->ju_K = Singletons::getInstance()->ju_K + 7;
				Singletons::getInstance()->money = Singletons::getInstance()->money - (Singletons::getInstance()->kia_1 * 7);
				removeChildByTag(164);
				removeChildByTag(165);
				removeChildByTag(166);
				removeChildByTag(146);
				removeChildByTag(135);
				removeChildByTag(136);
				removeChildByTag(137);
				removeChildByTag(138);
				removeChildByTag(139);
				removeChildByTag(140);
				removeChildByTag(141);
				removeChildByTag(142);
				removeChildByTag(143);
				removeChildByTag(161);
				removeChildByTag(162);

			}
		}
		else if (Singletons::getInstance()->num_K == 1 && Singletons::getInstance()->money < Singletons::getInstance()->kia_1 * 7)
		{
			removeChildByTag(164);
			removeChildByTag(165);
			removeChildByTag(166);
			removeChildByTag(146);
			removeChildByTag(135);
			removeChildByTag(136);
			removeChildByTag(137);
			removeChildByTag(138);
			removeChildByTag(139);
			removeChildByTag(140);
			removeChildByTag(141);
			removeChildByTag(142);
			removeChildByTag(143);
			removeChildByTag(161);
			removeChildByTag(162);

			Sprite* info = Sprite::create("MiniGameResources/pop_nomoney.png");
			info->setAnchorPoint(Point(0.5, 0));
			info->setPosition(Point(520, 410));
			info->setTag(164);
			this->addChild(info, 5);

			auto cancel = MenuItemImage::create(
				"MiniGameResources/pop_enter.png",
				"MiniGameResources/pop_enterpr.png",
				CC_CALLBACK_1(InvestScene::cancelbuy, this));
			cancel->setAnchorPoint(Point(0.5, 0.5));
			cancel->setPosition(Point(520, 450));

			auto canceltext = Menu::create(cancel, NULL);
			canceltext->setAnchorPoint(Point(0.5, 0.5));
			canceltext->setPosition(Point(0, 0));
			canceltext->setTag(165);
			this->addChild(canceltext, 7);
		}
		Singletons::getInstance()->num_K = 0;
	}

	//엘쥐구매
	{
		if (Singletons::getInstance()->money >= Singletons::getInstance()->lg_1 * 7)
		{
			if (Singletons::getInstance()->num_L == 1)
			{
				Singletons::getInstance()->ju_L = Singletons::getInstance()->ju_L + 7;
				Singletons::getInstance()->money = Singletons::getInstance()->money - (Singletons::getInstance()->lg_1 * 7);
				removeChildByTag(164);
				removeChildByTag(165);
				removeChildByTag(166);
				removeChildByTag(146);
				removeChildByTag(135);
				removeChildByTag(136);
				removeChildByTag(137);
				removeChildByTag(138);
				removeChildByTag(139);
				removeChildByTag(140);
				removeChildByTag(141);
				removeChildByTag(142);
				removeChildByTag(143);
				removeChildByTag(161);
				removeChildByTag(162);

			}
		}
		else if (Singletons::getInstance()->num_L == 1 && Singletons::getInstance()->money < Singletons::getInstance()->samsung_1 * 7)
		{
			removeChildByTag(164);
			removeChildByTag(165);
			removeChildByTag(166);
			removeChildByTag(146);
			removeChildByTag(135);
			removeChildByTag(136);
			removeChildByTag(137);
			removeChildByTag(138);
			removeChildByTag(139);
			removeChildByTag(140);
			removeChildByTag(141);
			removeChildByTag(142);
			removeChildByTag(143);
			removeChildByTag(161);
			removeChildByTag(162);

			Sprite* info = Sprite::create("MiniGameResources/pop_nomoney.png");
			info->setAnchorPoint(Point(0.5, 0));
			info->setPosition(Point(520, 410));
			info->setTag(164);
			this->addChild(info, 5);

			auto cancel = MenuItemImage::create(
				"MiniGameResources/pop_enter.png",
				"MiniGameResources/pop_enterpr.png",
				CC_CALLBACK_1(InvestScene::cancelbuy, this));
			cancel->setAnchorPoint(Point(0.5, 0.5));
			cancel->setPosition(Point(520, 450));

			auto canceltext = Menu::create(cancel, NULL);
			canceltext->setAnchorPoint(Point(0.5, 0.5));
			canceltext->setPosition(Point(0, 0));
			canceltext->setTag(165);
			this->addChild(canceltext, 7);
		}
		Singletons::getInstance()->num_S = 0;
	}

}

//8주구매
void InvestScene::buy_8(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);
	//삼성구매
	{
		if (Singletons::getInstance()->money >= Singletons::getInstance()->samsung_1 * 8)
		{
			if (Singletons::getInstance()->num_S == 1)
			{
				Singletons::getInstance()->ju_S = Singletons::getInstance()->ju_S + 8;
				Singletons::getInstance()->money = Singletons::getInstance()->money - (Singletons::getInstance()->samsung_1 * 8);
				removeChildByTag(164);
				removeChildByTag(165);
				removeChildByTag(166);
				removeChildByTag(146);
				removeChildByTag(135);
				removeChildByTag(136);
				removeChildByTag(137);
				removeChildByTag(138);
				removeChildByTag(139);
				removeChildByTag(140);
				removeChildByTag(141);
				removeChildByTag(142);
				removeChildByTag(143);
				removeChildByTag(161);
				removeChildByTag(162);

			}
		}
		else if (Singletons::getInstance()->num_S == 1 && Singletons::getInstance()->money < Singletons::getInstance()->samsung_1 * 8)
		{
			removeChildByTag(164);
			removeChildByTag(165);
			removeChildByTag(166);
			removeChildByTag(146);
			removeChildByTag(135);
			removeChildByTag(136);
			removeChildByTag(137);
			removeChildByTag(138);
			removeChildByTag(139);
			removeChildByTag(140);
			removeChildByTag(141);
			removeChildByTag(142);
			removeChildByTag(143);
			removeChildByTag(161);
			removeChildByTag(162);

			Sprite* info = Sprite::create("MiniGameResources/pop_nomoney.png");
			info->setAnchorPoint(Point(0.5, 0));
			info->setPosition(Point(520, 410));
			info->setTag(164);
			this->addChild(info, 5);

			auto cancel = MenuItemImage::create(
				"MiniGameResources/pop_enter.png",
				"MiniGameResources/pop_enterpr.png",
				CC_CALLBACK_1(InvestScene::cancelbuy, this));
			cancel->setAnchorPoint(Point(0.5, 0.5));
			cancel->setPosition(Point(520, 450));

			auto canceltext = Menu::create(cancel, NULL);
			canceltext->setAnchorPoint(Point(0.5, 0.5));
			canceltext->setPosition(Point(0, 0));
			canceltext->setTag(165);
			this->addChild(canceltext, 7);
		}
		Singletons::getInstance()->num_S = 0;
	}

	//애플구매
	{
		if (Singletons::getInstance()->money >= Singletons::getInstance()->apple_1 * 8)
		{
			if (Singletons::getInstance()->num_A == 1)
			{
				Singletons::getInstance()->ju_A = Singletons::getInstance()->ju_A + 8;
				Singletons::getInstance()->money = Singletons::getInstance()->money - (Singletons::getInstance()->apple_1 * 8);
				removeChildByTag(164);
				removeChildByTag(165);
				removeChildByTag(166);
				removeChildByTag(146);
				removeChildByTag(135);
				removeChildByTag(136);
				removeChildByTag(137);
				removeChildByTag(138);
				removeChildByTag(139);
				removeChildByTag(140);
				removeChildByTag(141);
				removeChildByTag(142);
				removeChildByTag(143); removeChildByTag(161);
				removeChildByTag(162);

			}
		}
		else if (Singletons::getInstance()->num_A == 1 && Singletons::getInstance()->money < Singletons::getInstance()->apple_1 * 8)
		{
			removeChildByTag(164);
			removeChildByTag(165);
			removeChildByTag(166);
			removeChildByTag(146);
			removeChildByTag(135);
			removeChildByTag(136);
			removeChildByTag(137);
			removeChildByTag(138);
			removeChildByTag(139);
			removeChildByTag(140);
			removeChildByTag(141);
			removeChildByTag(142);
			removeChildByTag(143); removeChildByTag(161);
			removeChildByTag(162);


			Sprite* info = Sprite::create("MiniGameResources/pop_nomoney.png");
			info->setAnchorPoint(Point(0.5, 0));
			info->setPosition(Point(520, 410));
			info->setTag(164);
			this->addChild(info, 5);

			auto cancel = MenuItemImage::create(
				"MiniGameResources/pop_enter.png",
				"MiniGameResources/pop_enterpr.png",
				CC_CALLBACK_1(InvestScene::cancelbuy, this));
			cancel->setAnchorPoint(Point(0.5, 0.5));
			cancel->setPosition(Point(520, 450));

			auto canceltext = Menu::create(cancel, NULL);
			canceltext->setAnchorPoint(Point(0.5, 0.5));
			canceltext->setPosition(Point(0, 0));
			canceltext->setTag(165);
			this->addChild(canceltext, 7);
		}
		Singletons::getInstance()->num_A = 0;
	}

	//한화구매
	{
		if (Singletons::getInstance()->money >= Singletons::getInstance()->hanhwa_1 * 8)
		{
			if (Singletons::getInstance()->num_H == 1)
			{
				Singletons::getInstance()->ju_H = Singletons::getInstance()->ju_H + 8;
				Singletons::getInstance()->money = Singletons::getInstance()->money - (Singletons::getInstance()->hanhwa_1 * 8);
				removeChildByTag(164);
				removeChildByTag(165);
				removeChildByTag(166);
				removeChildByTag(146);
				removeChildByTag(135);
				removeChildByTag(136);
				removeChildByTag(137);
				removeChildByTag(138);
				removeChildByTag(139);
				removeChildByTag(140);
				removeChildByTag(141);
				removeChildByTag(142);
				removeChildByTag(143); removeChildByTag(161);
				removeChildByTag(162);

			}
		}
		else if (Singletons::getInstance()->num_H == 1 && Singletons::getInstance()->money < Singletons::getInstance()->hanhwa_1 * 8)
		{
			removeChildByTag(164);
			removeChildByTag(165);
			removeChildByTag(166);
			removeChildByTag(146);
			removeChildByTag(135);
			removeChildByTag(136);
			removeChildByTag(137);
			removeChildByTag(138);
			removeChildByTag(139);
			removeChildByTag(140);
			removeChildByTag(141);
			removeChildByTag(142);
			removeChildByTag(143); removeChildByTag(161);
			removeChildByTag(162);


			Sprite* info = Sprite::create("MiniGameResources/pop_nomoney.png");
			info->setAnchorPoint(Point(0.5, 0));
			info->setPosition(Point(520, 410));
			info->setTag(164);
			this->addChild(info, 5);

			auto cancel = MenuItemImage::create(
				"MiniGameResources/pop_enter.png",
				"MiniGameResources/pop_enterpr.png",
				CC_CALLBACK_1(InvestScene::cancelbuy, this));
			cancel->setAnchorPoint(Point(0.5, 0.5));
			cancel->setPosition(Point(520, 450));

			auto canceltext = Menu::create(cancel, NULL);
			canceltext->setAnchorPoint(Point(0.5, 0.5));
			canceltext->setPosition(Point(0, 0));
			canceltext->setTag(165);
			this->addChild(canceltext, 7);
		}
		Singletons::getInstance()->num_H = 0;
	}

	//기아구매
	{
		if (Singletons::getInstance()->money >= Singletons::getInstance()->kia_1 * 8)
		{
			if (Singletons::getInstance()->num_K == 1)
			{
				Singletons::getInstance()->ju_K = Singletons::getInstance()->ju_K + 8;
				Singletons::getInstance()->money = Singletons::getInstance()->money - (Singletons::getInstance()->kia_1 * 8);
				removeChildByTag(164);
				removeChildByTag(165);
				removeChildByTag(166);
				removeChildByTag(146);
				removeChildByTag(135);
				removeChildByTag(136);
				removeChildByTag(137);
				removeChildByTag(138);
				removeChildByTag(139);
				removeChildByTag(140);
				removeChildByTag(141);
				removeChildByTag(142);
				removeChildByTag(143); removeChildByTag(161);
				removeChildByTag(162);

			}
		}
		else if (Singletons::getInstance()->num_K == 1 && Singletons::getInstance()->money < Singletons::getInstance()->kia_1 * 8)
		{
			removeChildByTag(164);
			removeChildByTag(165);
			removeChildByTag(166);
			removeChildByTag(146);
			removeChildByTag(135);
			removeChildByTag(136);
			removeChildByTag(137);
			removeChildByTag(138);
			removeChildByTag(139);
			removeChildByTag(140);
			removeChildByTag(141);
			removeChildByTag(142);
			removeChildByTag(143); removeChildByTag(161);
			removeChildByTag(162);


			Sprite* info = Sprite::create("MiniGameResources/pop_nomoney.png");
			info->setAnchorPoint(Point(0.5, 0));
			info->setPosition(Point(520, 410));
			info->setTag(164);
			this->addChild(info, 5);

			auto cancel = MenuItemImage::create(
				"MiniGameResources/pop_enter.png",
				"MiniGameResources/pop_enterpr.png",
				CC_CALLBACK_1(InvestScene::cancelbuy, this));
			cancel->setAnchorPoint(Point(0.5, 0.5));
			cancel->setPosition(Point(520, 450));

			auto canceltext = Menu::create(cancel, NULL);
			canceltext->setAnchorPoint(Point(0.5, 0.5));
			canceltext->setPosition(Point(0, 0));
			canceltext->setTag(165);
			this->addChild(canceltext, 7);
		}
		Singletons::getInstance()->num_K = 0;
	}

	//엘쥐구매
	{
		if (Singletons::getInstance()->money >= Singletons::getInstance()->lg_1 * 8)
		{
			if (Singletons::getInstance()->num_L == 1)
			{
				Singletons::getInstance()->ju_L = Singletons::getInstance()->ju_L + 8;
				Singletons::getInstance()->money = Singletons::getInstance()->money - (Singletons::getInstance()->lg_1 * 8);
				removeChildByTag(164);
				removeChildByTag(165);
				removeChildByTag(166);
				removeChildByTag(146);
				removeChildByTag(135);
				removeChildByTag(136);
				removeChildByTag(137);
				removeChildByTag(138);
				removeChildByTag(139);
				removeChildByTag(140);
				removeChildByTag(141);
				removeChildByTag(142);
				removeChildByTag(143); removeChildByTag(161);
				removeChildByTag(162);

			}
		}
		else if (Singletons::getInstance()->num_L == 1 && Singletons::getInstance()->money < Singletons::getInstance()->samsung_1 * 8)
		{
			removeChildByTag(164);
			removeChildByTag(165);
			removeChildByTag(166);
			removeChildByTag(146);
			removeChildByTag(135);
			removeChildByTag(136);
			removeChildByTag(137);
			removeChildByTag(138);
			removeChildByTag(139);
			removeChildByTag(140);
			removeChildByTag(141);
			removeChildByTag(142);
			removeChildByTag(143); removeChildByTag(161);
			removeChildByTag(162);


			Sprite* info = Sprite::create("MiniGameResources/pop_nomoney.png");
			info->setAnchorPoint(Point(0.5, 0));
			info->setPosition(Point(520, 410));
			info->setTag(164);
			this->addChild(info, 5);

			auto cancel = MenuItemImage::create(
				"MiniGameResources/pop_enter.png",
				"MiniGameResources/pop_enterpr.png",
				CC_CALLBACK_1(InvestScene::cancelbuy, this));
			cancel->setAnchorPoint(Point(0.5, 0.5));
			cancel->setPosition(Point(520, 450));

			auto canceltext = Menu::create(cancel, NULL);
			canceltext->setAnchorPoint(Point(0.5, 0.5));
			canceltext->setPosition(Point(0, 0));
			canceltext->setTag(165);
			this->addChild(canceltext, 7);
		}
		Singletons::getInstance()->num_S = 0;
	}
	
}

//9주구매
void InvestScene::buy_9(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);
	//삼성구매
	{
		if (Singletons::getInstance()->money >= Singletons::getInstance()->samsung_1 * 9)
		{
			if (Singletons::getInstance()->num_S == 1)
			{
				Singletons::getInstance()->ju_S = Singletons::getInstance()->ju_S + 9;
				Singletons::getInstance()->money = Singletons::getInstance()->money - (Singletons::getInstance()->samsung_1 * 9);
				removeChildByTag(164);
				removeChildByTag(165);
				removeChildByTag(166);
				removeChildByTag(146);
				removeChildByTag(135);
				removeChildByTag(136);
				removeChildByTag(137);
				removeChildByTag(138);
				removeChildByTag(139);
				removeChildByTag(140);
				removeChildByTag(141);
				removeChildByTag(142);
				removeChildByTag(143); removeChildByTag(161);
				removeChildByTag(162);

			}
		}
		else if (Singletons::getInstance()->num_S == 1 && Singletons::getInstance()->money < Singletons::getInstance()->samsung_1 * 9)
		{
			removeChildByTag(164);
			removeChildByTag(165);
			removeChildByTag(166);
			removeChildByTag(146);
			removeChildByTag(135);
			removeChildByTag(136);
			removeChildByTag(137);
			removeChildByTag(138);
			removeChildByTag(139);
			removeChildByTag(140);
			removeChildByTag(141);
			removeChildByTag(142);
			removeChildByTag(143); removeChildByTag(161);
			removeChildByTag(162);


			Sprite* info = Sprite::create("MiniGameResources/pop_nomoney.png");
			info->setAnchorPoint(Point(0.5, 0));
			info->setPosition(Point(520, 410));
			info->setTag(164);
			this->addChild(info, 5);

			auto cancel = MenuItemImage::create(
				"MiniGameResources/pop_enter.png",
				"MiniGameResources/pop_enterpr.png",
				CC_CALLBACK_1(InvestScene::cancelbuy, this));
			cancel->setAnchorPoint(Point(0.5, 0.5));
			cancel->setPosition(Point(520, 450));

			auto canceltext = Menu::create(cancel, NULL);
			canceltext->setAnchorPoint(Point(0.5, 0.5));
			canceltext->setPosition(Point(0, 0));
			canceltext->setTag(165);
			this->addChild(canceltext, 7);
		}
		Singletons::getInstance()->num_S = 0;
	}

	//애플구매
	{
		if (Singletons::getInstance()->money >= Singletons::getInstance()->apple_1 * 9)
		{
			if (Singletons::getInstance()->num_A == 1)
			{
				Singletons::getInstance()->ju_A = Singletons::getInstance()->ju_A + 9;
				Singletons::getInstance()->money = Singletons::getInstance()->money - (Singletons::getInstance()->apple_1 * 9);
				removeChildByTag(164);
				removeChildByTag(165);
				removeChildByTag(166);
				removeChildByTag(146);
				removeChildByTag(135);
				removeChildByTag(136);
				removeChildByTag(137);
				removeChildByTag(138);
				removeChildByTag(139);
				removeChildByTag(140);
				removeChildByTag(141);
				removeChildByTag(142);
				removeChildByTag(143); removeChildByTag(161);
				removeChildByTag(162);

			}
		}
		else if (Singletons::getInstance()->num_A == 1 && Singletons::getInstance()->money < Singletons::getInstance()->apple_1 * 9)
		{
			removeChildByTag(164);
			removeChildByTag(165);
			removeChildByTag(166);
			removeChildByTag(146);
			removeChildByTag(135);
			removeChildByTag(136);
			removeChildByTag(137);
			removeChildByTag(138);
			removeChildByTag(139);
			removeChildByTag(140);
			removeChildByTag(141);
			removeChildByTag(142);
			removeChildByTag(143); removeChildByTag(161);
			removeChildByTag(162);


			Sprite* info = Sprite::create("MiniGameResources/pop_nomoney.png");
			info->setAnchorPoint(Point(0.5, 0));
			info->setPosition(Point(520, 410));
			info->setTag(164);
			this->addChild(info, 5);

			auto cancel = MenuItemImage::create(
				"MiniGameResources/pop_enter.png",
				"MiniGameResources/pop_enterpr.png",
				CC_CALLBACK_1(InvestScene::cancelbuy, this));
			cancel->setAnchorPoint(Point(0.5, 0.5));
			cancel->setPosition(Point(520, 450));

			auto canceltext = Menu::create(cancel, NULL);
			canceltext->setAnchorPoint(Point(0.5, 0.5));
			canceltext->setPosition(Point(0, 0));
			canceltext->setTag(165);
			this->addChild(canceltext, 7);
		}
		Singletons::getInstance()->num_A = 0;
	}

	//한화구매
	{
		if (Singletons::getInstance()->money >= Singletons::getInstance()->hanhwa_1 * 9)
		{
			if (Singletons::getInstance()->num_H == 1)
			{
				Singletons::getInstance()->ju_H = Singletons::getInstance()->ju_H + 9;
				Singletons::getInstance()->money = Singletons::getInstance()->money - (Singletons::getInstance()->hanhwa_1 * 9);
				removeChildByTag(164);
				removeChildByTag(165);
				removeChildByTag(166);
				removeChildByTag(146);
				removeChildByTag(135);
				removeChildByTag(136);
				removeChildByTag(137);
				removeChildByTag(138);
				removeChildByTag(139);
				removeChildByTag(140);
				removeChildByTag(141);
				removeChildByTag(142);
				removeChildByTag(143); removeChildByTag(161);
				removeChildByTag(162);

			}
		}
		else if (Singletons::getInstance()->num_H == 1 && Singletons::getInstance()->money < Singletons::getInstance()->hanhwa_1 * 9)
		{
			removeChildByTag(164);
			removeChildByTag(165);
			removeChildByTag(166);
			removeChildByTag(146);
			removeChildByTag(135);
			removeChildByTag(136);
			removeChildByTag(137);
			removeChildByTag(138);
			removeChildByTag(139);
			removeChildByTag(140);
			removeChildByTag(141);
			removeChildByTag(142);
			removeChildByTag(143); removeChildByTag(161);
			removeChildByTag(162);


			Sprite* info = Sprite::create("MiniGameResources/pop_nomoney.png");
			info->setAnchorPoint(Point(0.5, 0));
			info->setPosition(Point(520, 410));
			info->setTag(164);
			this->addChild(info, 5);

			auto cancel = MenuItemImage::create(
				"MiniGameResources/pop_enter.png",
				"MiniGameResources/pop_enterpr.png",
				CC_CALLBACK_1(InvestScene::cancelbuy, this));
			cancel->setAnchorPoint(Point(0.5, 0.5));
			cancel->setPosition(Point(520, 450));

			auto canceltext = Menu::create(cancel, NULL);
			canceltext->setAnchorPoint(Point(0.5, 0.5));
			canceltext->setPosition(Point(0, 0));
			canceltext->setTag(165);
			this->addChild(canceltext, 7);
		}
		Singletons::getInstance()->num_H = 0;
	}

	//기아구매
	{
		if (Singletons::getInstance()->money >= Singletons::getInstance()->kia_1 * 9)
		{
			if (Singletons::getInstance()->num_K == 1)
			{
				Singletons::getInstance()->ju_K = Singletons::getInstance()->ju_K + 9;
				Singletons::getInstance()->money = Singletons::getInstance()->money - (Singletons::getInstance()->kia_1 * 9);
				removeChildByTag(164);
				removeChildByTag(165);
				removeChildByTag(166);
				removeChildByTag(146);
				removeChildByTag(135);
				removeChildByTag(136);
				removeChildByTag(137);
				removeChildByTag(138);
				removeChildByTag(139);
				removeChildByTag(140);
				removeChildByTag(141);
				removeChildByTag(142);
				removeChildByTag(143); removeChildByTag(161);
				removeChildByTag(162);

			}
		}
		else if (Singletons::getInstance()->num_K == 1 && Singletons::getInstance()->money < Singletons::getInstance()->kia_1 * 9)
		{
			removeChildByTag(164);
			removeChildByTag(165);
			removeChildByTag(166);
			removeChildByTag(146);
			removeChildByTag(135);
			removeChildByTag(136);
			removeChildByTag(137);
			removeChildByTag(138);
			removeChildByTag(139);
			removeChildByTag(140);
			removeChildByTag(141);
			removeChildByTag(142);
			removeChildByTag(143); removeChildByTag(161);
			removeChildByTag(162);


			Sprite* info = Sprite::create("MiniGameResources/pop_nomoney.png");
			info->setAnchorPoint(Point(0.5, 0));
			info->setPosition(Point(520, 410));
			info->setTag(164);
			this->addChild(info, 5);

			auto cancel = MenuItemImage::create(
				"MiniGameResources/pop_enter.png",
				"MiniGameResources/pop_enterpr.png",
				CC_CALLBACK_1(InvestScene::cancelbuy, this));
			cancel->setAnchorPoint(Point(0.5, 0.5));
			cancel->setPosition(Point(520, 450));

			auto canceltext = Menu::create(cancel, NULL);
			canceltext->setAnchorPoint(Point(0.5, 0.5));
			canceltext->setPosition(Point(0, 0));
			canceltext->setTag(165);
			this->addChild(canceltext, 7);
		}
		Singletons::getInstance()->num_K = 0;
	}

	//엘쥐구매
	{
		if (Singletons::getInstance()->money >= Singletons::getInstance()->lg_1 * 9)
		{
			if (Singletons::getInstance()->num_L == 1)
			{
				Singletons::getInstance()->ju_L = Singletons::getInstance()->ju_L + 9;
				Singletons::getInstance()->money = Singletons::getInstance()->money - (Singletons::getInstance()->lg_1 * 9);
				removeChildByTag(164);
				removeChildByTag(165);
				removeChildByTag(166);
				removeChildByTag(146);
				removeChildByTag(135);
				removeChildByTag(136);
				removeChildByTag(137);
				removeChildByTag(138);
				removeChildByTag(139);
				removeChildByTag(140);
				removeChildByTag(141);
				removeChildByTag(142); removeChildByTag(161);
				removeChildByTag(162);

				removeChildByTag(143);
			}
		}
		else if (Singletons::getInstance()->num_L == 1 && Singletons::getInstance()->money < Singletons::getInstance()->samsung_1 * 9)
		{
			removeChildByTag(164);
			removeChildByTag(165);
			removeChildByTag(166);
			removeChildByTag(146);
			removeChildByTag(135);
			removeChildByTag(136);
			removeChildByTag(137);
			removeChildByTag(138);
			removeChildByTag(139);
			removeChildByTag(140);
			removeChildByTag(141);
			removeChildByTag(142);
			removeChildByTag(143); removeChildByTag(161);
			removeChildByTag(162);


			Sprite* info = Sprite::create("MiniGameResources/pop_nomoney.png");
			info->setAnchorPoint(Point(0.5, 0));
			info->setPosition(Point(520, 410));
			info->setTag(164);
			this->addChild(info, 5);

			auto cancel = MenuItemImage::create(
				"MiniGameResources/pop_enter.png",
				"MiniGameResources/pop_enterpr.png",
				CC_CALLBACK_1(InvestScene::cancelbuy, this));
			cancel->setAnchorPoint(Point(0.5, 0.5));
			cancel->setPosition(Point(520, 450));

			auto canceltext = Menu::create(cancel, NULL);
			canceltext->setAnchorPoint(Point(0.5, 0.5));
			canceltext->setPosition(Point(0, 0));
			canceltext->setTag(165);
			this->addChild(canceltext, 7);
		}
		Singletons::getInstance()->num_S = 0;
	}
	
}

//10주구매
void InvestScene::buy_10(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);
	//삼성구매
	{


		if (Singletons::getInstance()->money >= Singletons::getInstance()->samsung_1 * 10)
		{
			if (Singletons::getInstance()->num_S == 1)
			{
				Singletons::getInstance()->ju_S = Singletons::getInstance()->ju_S + 10;
				Singletons::getInstance()->money = Singletons::getInstance()->money - (Singletons::getInstance()->samsung_1 * 10);
				removeChildByTag(164);
				removeChildByTag(165);
				removeChildByTag(166);
				removeChildByTag(146);
				removeChildByTag(135);
				removeChildByTag(136);
				removeChildByTag(137);
				removeChildByTag(138);
				removeChildByTag(139);
				removeChildByTag(140);
				removeChildByTag(141);
				removeChildByTag(142);
				removeChildByTag(143); removeChildByTag(161);
				removeChildByTag(162);

			}
		}
		else if (Singletons::getInstance()->num_S == 1 && Singletons::getInstance()->money < Singletons::getInstance()->samsung_1 * 10)
		{
			removeChildByTag(164);
			removeChildByTag(165);
			removeChildByTag(166);
			removeChildByTag(146);
			removeChildByTag(135);
			removeChildByTag(136);
			removeChildByTag(137);
			removeChildByTag(138);
			removeChildByTag(139);
			removeChildByTag(140);
			removeChildByTag(141);
			removeChildByTag(142);
			removeChildByTag(143); removeChildByTag(161);
			removeChildByTag(162);


			Sprite* info = Sprite::create("MiniGameResources/pop_nomoney.png");
			info->setAnchorPoint(Point(0.5, 0));
			info->setPosition(Point(520, 410));
			info->setTag(164);
			this->addChild(info, 5);

			auto cancel = MenuItemImage::create(
				"MiniGameResources/pop_enter.png",
				"MiniGameResources/pop_enterpr.png",
				CC_CALLBACK_1(InvestScene::cancelbuy, this));
			cancel->setAnchorPoint(Point(0.5, 0.5));
			cancel->setPosition(Point(520, 450));

			auto canceltext = Menu::create(cancel, NULL);
			canceltext->setAnchorPoint(Point(0.5, 0.5));
			canceltext->setPosition(Point(0, 0));
			canceltext->setTag(165);
			this->addChild(canceltext, 7);
		}
		Singletons::getInstance()->num_S = 0;
	}

	//애플구매
	{
		if (Singletons::getInstance()->money >= Singletons::getInstance()->apple_1 * 10)
		{
			if (Singletons::getInstance()->num_A == 1)
			{
				Singletons::getInstance()->ju_A = Singletons::getInstance()->ju_A + 10;
				Singletons::getInstance()->money = Singletons::getInstance()->money - (Singletons::getInstance()->apple_1 * 10);
				removeChildByTag(164);
				removeChildByTag(165);
				removeChildByTag(166);
				removeChildByTag(146);
				removeChildByTag(135);
				removeChildByTag(136);
				removeChildByTag(137);
				removeChildByTag(138);
				removeChildByTag(139);
				removeChildByTag(140); removeChildByTag(161);
				removeChildByTag(162);

				removeChildByTag(141);
				removeChildByTag(142);
				removeChildByTag(143);
			}
		}
		else if (Singletons::getInstance()->num_A == 1 && Singletons::getInstance()->money < Singletons::getInstance()->apple_1 * 10)
		{
			removeChildByTag(164);
			removeChildByTag(165);
			removeChildByTag(166);
			removeChildByTag(146);
			removeChildByTag(135);
			removeChildByTag(136);
			removeChildByTag(137);
			removeChildByTag(138);
			removeChildByTag(139);
			removeChildByTag(140);
			removeChildByTag(141);
			removeChildByTag(142); removeChildByTag(161);
			removeChildByTag(162);

			removeChildByTag(143);

			Sprite* info = Sprite::create("MiniGameResources/pop_nomoney.png");
			info->setAnchorPoint(Point(0.5, 0));
			info->setPosition(Point(520, 410));
			info->setTag(164);
			this->addChild(info, 5);

			auto cancel = MenuItemImage::create(
				"MiniGameResources/pop_enter.png",
				"MiniGameResources/pop_enterpr.png",
				CC_CALLBACK_1(InvestScene::cancelbuy, this));
			cancel->setAnchorPoint(Point(0.5, 0.5));
			cancel->setPosition(Point(520, 450));

			auto canceltext = Menu::create(cancel, NULL);
			canceltext->setAnchorPoint(Point(0.5, 0.5));
			canceltext->setPosition(Point(0, 0));
			canceltext->setTag(165);
			this->addChild(canceltext, 7);
		}
		Singletons::getInstance()->num_A = 0;
	}

	//한화구매
	{
		if (Singletons::getInstance()->money >= Singletons::getInstance()->hanhwa_1 * 10)
		{
			if (Singletons::getInstance()->num_H == 1)
			{
				Singletons::getInstance()->ju_H = Singletons::getInstance()->ju_H + 10;
				Singletons::getInstance()->money = Singletons::getInstance()->money - (Singletons::getInstance()->hanhwa_1 * 10);
				removeChildByTag(164);
				removeChildByTag(165);
				removeChildByTag(166);
				removeChildByTag(146);
				removeChildByTag(135);
				removeChildByTag(136);
				removeChildByTag(137);
				removeChildByTag(138);
				removeChildByTag(139);
				removeChildByTag(140);
				removeChildByTag(141); removeChildByTag(161);
				removeChildByTag(162);

				removeChildByTag(142);
				removeChildByTag(143);
			}
		}
		else if (Singletons::getInstance()->num_H == 1 && Singletons::getInstance()->money < Singletons::getInstance()->hanhwa_1 * 10)
		{
			removeChildByTag(164);
			removeChildByTag(165);
			removeChildByTag(166);
			removeChildByTag(146);
			removeChildByTag(135);
			removeChildByTag(136);
			removeChildByTag(137);
			removeChildByTag(138);
			removeChildByTag(139);
			removeChildByTag(140); removeChildByTag(161);
			removeChildByTag(162);

			removeChildByTag(141);
			removeChildByTag(142);
			removeChildByTag(143);

			Sprite* info = Sprite::create("MiniGameResources/pop_nomoney.png");
			info->setAnchorPoint(Point(0.5, 0));
			info->setPosition(Point(520, 410));
			info->setTag(164);
			this->addChild(info, 5);

			auto cancel = MenuItemImage::create(
				"MiniGameResources/pop_enter.png",
				"MiniGameResources/pop_enterpr.png",
				CC_CALLBACK_1(InvestScene::cancelbuy, this));
			cancel->setAnchorPoint(Point(0.5, 0.5));
			cancel->setPosition(Point(520, 450));

			auto canceltext = Menu::create(cancel, NULL);
			canceltext->setAnchorPoint(Point(0.5, 0.5));
			canceltext->setPosition(Point(0, 0));
			canceltext->setTag(165);
			this->addChild(canceltext, 7);
		}
		Singletons::getInstance()->num_H = 0;
	}

	//기아구매
	{
		if (Singletons::getInstance()->money >= Singletons::getInstance()->kia_1 * 10)
		{
			if (Singletons::getInstance()->num_K == 1)
			{
				Singletons::getInstance()->ju_K = Singletons::getInstance()->ju_K + 10;
				Singletons::getInstance()->money = Singletons::getInstance()->money - (Singletons::getInstance()->kia_1 * 10);
				removeChildByTag(164);
				removeChildByTag(165);
				removeChildByTag(166);
				removeChildByTag(146);
				removeChildByTag(135);
				removeChildByTag(136); removeChildByTag(161);
				removeChildByTag(162);

				removeChildByTag(137);
				removeChildByTag(138);
				removeChildByTag(139);
				removeChildByTag(140);
				removeChildByTag(141);
				removeChildByTag(142);
				removeChildByTag(143);
			}
		}
		else if (Singletons::getInstance()->num_K == 1 && Singletons::getInstance()->money < Singletons::getInstance()->kia_1 * 10)
		{
			removeChildByTag(164);
			removeChildByTag(165);
			removeChildByTag(166);
			removeChildByTag(146);
			removeChildByTag(135);
			removeChildByTag(136);
			removeChildByTag(137);
			removeChildByTag(138); removeChildByTag(161);
			removeChildByTag(162);

			removeChildByTag(139);
			removeChildByTag(140);
			removeChildByTag(141);
			removeChildByTag(142);
			removeChildByTag(143);

			Sprite* info = Sprite::create("MiniGameResources/pop_nomoney.png");
			info->setAnchorPoint(Point(0.5, 0));
			info->setPosition(Point(520, 410));
			info->setTag(164);
			this->addChild(info, 5);

			auto cancel = MenuItemImage::create(
				"MiniGameResources/pop_enter.png",
				"MiniGameResources/pop_enterpr.png",
				CC_CALLBACK_1(InvestScene::cancelbuy, this));
			cancel->setAnchorPoint(Point(0.5, 0.5));
			cancel->setPosition(Point(520, 450));

			auto canceltext = Menu::create(cancel, NULL);
			canceltext->setAnchorPoint(Point(0.5, 0.5));
			canceltext->setPosition(Point(0, 0));
			canceltext->setTag(165);
			this->addChild(canceltext, 7);
		}
		Singletons::getInstance()->num_K = 0;
	}

	//엘쥐구매
	{
		if (Singletons::getInstance()->money >= Singletons::getInstance()->lg_1 * 10)
		{
			if (Singletons::getInstance()->num_L == 1)
			{
				Singletons::getInstance()->ju_L = Singletons::getInstance()->ju_L + 10;
				Singletons::getInstance()->money = Singletons::getInstance()->money - (Singletons::getInstance()->lg_1 * 10);
				removeChildByTag(164);
				removeChildByTag(165);
				removeChildByTag(166);
				removeChildByTag(146);
				removeChildByTag(135);
				removeChildByTag(136);
				removeChildByTag(137);
				removeChildByTag(138); removeChildByTag(161);
				removeChildByTag(162);

				removeChildByTag(139);
				removeChildByTag(140);
				removeChildByTag(141);
				removeChildByTag(142);
				removeChildByTag(143);
			}
		}
		else if (Singletons::getInstance()->num_L == 1 && Singletons::getInstance()->money < Singletons::getInstance()->samsung_1 * 10)
		{
			removeChildByTag(164);
			removeChildByTag(165);
			removeChildByTag(166);
			removeChildByTag(146);
			removeChildByTag(135);
			removeChildByTag(136);
			removeChildByTag(137);
			removeChildByTag(138);
			removeChildByTag(139); removeChildByTag(161);
			removeChildByTag(162);

			removeChildByTag(140);
			removeChildByTag(141);
			removeChildByTag(142);
			removeChildByTag(143);

			Sprite* info = Sprite::create("MiniGameResources/pop_nomoney.png");
			info->setAnchorPoint(Point(0.5, 0));
			info->setPosition(Point(520, 410));
			info->setTag(164);
			this->addChild(info, 5);

			auto cancel = MenuItemImage::create(
				"MiniGameResources/pop_enter.png",
				"MiniGameResources/pop_enterpr.png",
				CC_CALLBACK_1(InvestScene::cancelbuy, this));
			cancel->setAnchorPoint(Point(0.5, 0.5));
			cancel->setPosition(Point(520, 450));

			auto canceltext = Menu::create(cancel, NULL);
			canceltext->setAnchorPoint(Point(0.5, 0.5));
			canceltext->setPosition(Point(0, 0));
			canceltext->setTag(165);
			this->addChild(canceltext, 7);
		}
		Singletons::getInstance()->num_S = 0;
	}
	
}
void InvestScene::system(Ref *pSender)
{
}
void InvestScene::cancel(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);
	Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
	Director::getInstance()->replaceScene(BudongScene::createScene());
}
void InvestScene::cancelbuy(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);

	removeChildByTag(161);
	removeChildByTag(162);
	removeChildByTag(164);
	removeChildByTag(165);
	removeChildByTag(166);
	removeChildByTag(146);
	removeChildByTag(135);
	removeChildByTag(136);
	removeChildByTag(137);
	removeChildByTag(138);
	removeChildByTag(139);
	removeChildByTag(140);
	removeChildByTag(141);
	removeChildByTag(142);
	removeChildByTag(143);
	removeChildByTag(164);
	removeChildByTag(165); removeChildByTag(161);
	removeChildByTag(162);

	
}
void InvestScene::sell_1(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);
	//삼성판매
	{
		if (Singletons::getInstance()->ju_S >= 1)
		{
			if (Singletons::getInstance()->num_S == 2)
			{
				Singletons::getInstance()->ju_S = Singletons::getInstance()->ju_S - 1;
				Singletons::getInstance()->money = Singletons::getInstance()->money + (Singletons::getInstance()->samsung_1 * 1);
				removeChildByTag(164);
				removeChildByTag(165);
				removeChildByTag(166);
				removeChildByTag(146);
				removeChildByTag(135);
				removeChildByTag(136);
				removeChildByTag(137);
				removeChildByTag(138);
				removeChildByTag(139);
				removeChildByTag(140);
				removeChildByTag(141);
				removeChildByTag(142);
				removeChildByTag(143); removeChildByTag(161);
				removeChildByTag(162);

			}
		}
		else if (Singletons::getInstance()->num_S == 2 && Singletons::getInstance()->ju_S == 0)
		{
			removeChildByTag(164);
			removeChildByTag(165);
			removeChildByTag(166);
			removeChildByTag(146);
			removeChildByTag(135);
			removeChildByTag(136);
			removeChildByTag(137);
			removeChildByTag(138);
			removeChildByTag(139);
			removeChildByTag(140);
			removeChildByTag(141); removeChildByTag(161);
			removeChildByTag(162);

			removeChildByTag(142);
			removeChildByTag(143);

			Sprite* info = Sprite::create("MiniGameResources/pop_noinvest.png");
			info->setAnchorPoint(Point(0.5, 0));
			info->setPosition(Point(520, 410));
			info->setTag(164);
			this->addChild(info, 5);

			auto cancel = MenuItemImage::create(
				"MiniGameResources/pop_enter.png",
				"MiniGameResources/pop_enterpr.png",
				CC_CALLBACK_1(InvestScene::cancelbuy, this));
			cancel->setAnchorPoint(Point(0.5, 0.5));
			cancel->setPosition(Point(520, 450));

			auto canceltext = Menu::create(cancel, NULL);
			canceltext->setAnchorPoint(Point(0.5, 0.5));
			canceltext->setPosition(Point(0, 0));
			canceltext->setTag(165);
			this->addChild(canceltext, 7);
		}
		Singletons::getInstance()->num_S = 0;
	}

	//애플판매
	{
		if (Singletons::getInstance()->ju_A >= 1)
		{
			if (Singletons::getInstance()->num_A == 2)
			{
				Singletons::getInstance()->ju_A = Singletons::getInstance()->ju_A - 1;
				Singletons::getInstance()->money = Singletons::getInstance()->money + (Singletons::getInstance()->apple_1 * 1);
				removeChildByTag(164);
				removeChildByTag(165);
				removeChildByTag(166);
				removeChildByTag(146); removeChildByTag(161);
				removeChildByTag(162);

				removeChildByTag(135);
				removeChildByTag(136);
				removeChildByTag(137);
				removeChildByTag(138);
				removeChildByTag(139);
				removeChildByTag(140);
				removeChildByTag(141);
				removeChildByTag(142);
				removeChildByTag(143);
			}
		}
		else if (Singletons::getInstance()->num_A == 2 && Singletons::getInstance()->ju_A == 0)
		{
			removeChildByTag(164);
			removeChildByTag(165);
			removeChildByTag(166);
			removeChildByTag(146);
			removeChildByTag(135);
			removeChildByTag(136);
			removeChildByTag(137);
			removeChildByTag(138);
			removeChildByTag(139);
			removeChildByTag(140);
			removeChildByTag(141); removeChildByTag(161);
			removeChildByTag(162);

			removeChildByTag(142);
			removeChildByTag(143);

			Sprite* info = Sprite::create("MiniGameResources/pop_noinvest.png");
			info->setAnchorPoint(Point(0.5, 0));
			info->setPosition(Point(520, 410));
			info->setTag(164);
			this->addChild(info, 5);

			auto cancel = MenuItemImage::create(
				"MiniGameResources/pop_enter.png",
				"MiniGameResources/pop_enterpr.png",
				CC_CALLBACK_1(InvestScene::cancelbuy, this));
			cancel->setAnchorPoint(Point(0.5, 0.5));
			cancel->setPosition(Point(520, 450));

			auto canceltext = Menu::create(cancel, NULL);
			canceltext->setAnchorPoint(Point(0.5, 0.5));
			canceltext->setPosition(Point(0, 0));
			canceltext->setTag(165);
			this->addChild(canceltext, 7);
		}
		Singletons::getInstance()->num_A = 0;
	}

	//하놔판매
	{
		if (Singletons::getInstance()->ju_H >= 1)
		{
			if (Singletons::getInstance()->num_H == 2)
			{
				Singletons::getInstance()->ju_H = Singletons::getInstance()->ju_H - 1;
				Singletons::getInstance()->money = Singletons::getInstance()->money + (Singletons::getInstance()->hanhwa_1 * 1);
				removeChildByTag(164);
				removeChildByTag(165);
				removeChildByTag(166);
				removeChildByTag(146);
				removeChildByTag(135);
				removeChildByTag(136); removeChildByTag(161);
				removeChildByTag(162);

				removeChildByTag(137);
				removeChildByTag(138);
				removeChildByTag(139);
				removeChildByTag(140);
				removeChildByTag(141);
				removeChildByTag(142);
				removeChildByTag(143);
			}
		}
		else if (Singletons::getInstance()->num_H == 2 && Singletons::getInstance()->ju_H == 0)
		{
			removeChildByTag(164);
			removeChildByTag(165);
			removeChildByTag(166);
			removeChildByTag(146);
			removeChildByTag(135);
			removeChildByTag(136);
			removeChildByTag(137);
			removeChildByTag(138);
			removeChildByTag(139);
			removeChildByTag(140); removeChildByTag(161);
			removeChildByTag(162);

			removeChildByTag(141);
			removeChildByTag(142);
			removeChildByTag(143);

			Sprite* info = Sprite::create("MiniGameResources/pop_noinvest.png");
			info->setAnchorPoint(Point(0.5, 0));
			info->setPosition(Point(520, 410));
			info->setTag(164);
			this->addChild(info, 5);

			auto cancel = MenuItemImage::create(
				"MiniGameResources/pop_enter.png",
				"MiniGameResources/pop_enterpr.png",
				CC_CALLBACK_1(InvestScene::cancelbuy, this));
			cancel->setAnchorPoint(Point(0.5, 0.5));
			cancel->setPosition(Point(520, 450));

			auto canceltext = Menu::create(cancel, NULL);
			canceltext->setAnchorPoint(Point(0.5, 0.5));
			canceltext->setPosition(Point(0, 0));
			canceltext->setTag(165);
			this->addChild(canceltext, 7);
		}
		Singletons::getInstance()->num_H = 0;
	}

	//기아판매
	{
		if (Singletons::getInstance()->ju_K >= 1)
		{
			if (Singletons::getInstance()->num_K == 2)
			{
				Singletons::getInstance()->ju_K = Singletons::getInstance()->ju_K - 1;
				Singletons::getInstance()->money = Singletons::getInstance()->money + (Singletons::getInstance()->kia_1 * 1);
				removeChildByTag(164);
				removeChildByTag(165);
				removeChildByTag(166);
				removeChildByTag(146);
				removeChildByTag(135);
				removeChildByTag(136);
				removeChildByTag(137);
				removeChildByTag(138);
				removeChildByTag(139); removeChildByTag(161);
				removeChildByTag(162);

				removeChildByTag(140);
				removeChildByTag(141);
				removeChildByTag(142);
				removeChildByTag(143);
			}
		}
		else if (Singletons::getInstance()->num_K == 2 && Singletons::getInstance()->ju_K == 0)
		{
			removeChildByTag(164);
			removeChildByTag(165);
			removeChildByTag(166);
			removeChildByTag(146);
			removeChildByTag(135);
			removeChildByTag(136);
			removeChildByTag(137); removeChildByTag(161);
			removeChildByTag(162);

			removeChildByTag(138);
			removeChildByTag(139);
			removeChildByTag(140);
			removeChildByTag(141);
			removeChildByTag(142);
			removeChildByTag(143);

			Sprite* info = Sprite::create("MiniGameResources/pop_noinvest.png");
			info->setAnchorPoint(Point(0.5, 0));
			info->setPosition(Point(520, 410));
			info->setTag(164);
			this->addChild(info, 5);

			auto cancel = MenuItemImage::create(
				"MiniGameResources/pop_enter.png",
				"MiniGameResources/pop_enterpr.png",
				CC_CALLBACK_1(InvestScene::cancelbuy, this));
			cancel->setAnchorPoint(Point(0.5, 0.5));
			cancel->setPosition(Point(520, 450));

			auto canceltext = Menu::create(cancel, NULL);
			canceltext->setAnchorPoint(Point(0.5, 0.5));
			canceltext->setPosition(Point(0, 0));
			canceltext->setTag(165);
			this->addChild(canceltext, 7);
		}
		Singletons::getInstance()->num_K = 0;
	}
	//엘쥐판매
	{
		if (Singletons::getInstance()->ju_L >= 1)
		{
			if (Singletons::getInstance()->num_L == 2)
			{
				Singletons::getInstance()->ju_L = Singletons::getInstance()->ju_L - 1;
				Singletons::getInstance()->money = Singletons::getInstance()->money + (Singletons::getInstance()->lg_1 * 1);
				removeChildByTag(164);
				removeChildByTag(165);
				removeChildByTag(166);
				removeChildByTag(146);
				removeChildByTag(135);
				removeChildByTag(136);
				removeChildByTag(137);
				removeChildByTag(138); removeChildByTag(161);
				removeChildByTag(162);

				removeChildByTag(139);
				removeChildByTag(140);
				removeChildByTag(141);
				removeChildByTag(142);
				removeChildByTag(143);
			}
		}
		else if (Singletons::getInstance()->num_L == 2 && Singletons::getInstance()->ju_L == 0)
		{
			removeChildByTag(164);
			removeChildByTag(165);
			removeChildByTag(166);
			removeChildByTag(146);
			removeChildByTag(135);
			removeChildByTag(136);
			removeChildByTag(137);
			removeChildByTag(138); removeChildByTag(161);
			removeChildByTag(162);

			removeChildByTag(139);
			removeChildByTag(140);
			removeChildByTag(141);
			removeChildByTag(142);
			removeChildByTag(143);

			Sprite* info = Sprite::create("MiniGameResources/pop_noinvest.png");
			info->setAnchorPoint(Point(0.5, 0));
			info->setPosition(Point(520, 410));
			info->setTag(164);
			this->addChild(info, 5);

			auto cancel = MenuItemImage::create(
				"MiniGameResources/pop_enter.png",
				"MiniGameResources/pop_enterpr.png",
				CC_CALLBACK_1(InvestScene::cancelbuy, this));
			cancel->setAnchorPoint(Point(0.5, 0.5));
			cancel->setPosition(Point(520, 450));

			auto canceltext = Menu::create(cancel, NULL);
			canceltext->setAnchorPoint(Point(0.5, 0.5));
			canceltext->setPosition(Point(0, 0));
			canceltext->setTag(165);
			this->addChild(canceltext, 7);
		}
		Singletons::getInstance()->num_L = 0;
	}


}
void InvestScene::sell_2(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);
	//삼성판매
	{
		if (Singletons::getInstance()->ju_S >= 2)
		{
			if (Singletons::getInstance()->num_S == 2)
			{
				Singletons::getInstance()->ju_S = Singletons::getInstance()->ju_S - 2;
				Singletons::getInstance()->money = Singletons::getInstance()->money + (Singletons::getInstance()->samsung_1 * 2);
				removeChildByTag(164);
				removeChildByTag(165);
				removeChildByTag(166);
				removeChildByTag(146);
				removeChildByTag(135);
				removeChildByTag(136);
				removeChildByTag(137);
				removeChildByTag(138);
				removeChildByTag(139);
				removeChildByTag(140);
				removeChildByTag(141); removeChildByTag(161);
				removeChildByTag(162);

				removeChildByTag(142);
				removeChildByTag(143);
			}
		}
		else if (Singletons::getInstance()->num_S == 2 && Singletons::getInstance()->ju_S <=1)
		{
			removeChildByTag(164);
			removeChildByTag(165);
			removeChildByTag(166);
			removeChildByTag(146);
			removeChildByTag(135);
			removeChildByTag(136);
			removeChildByTag(137);
			removeChildByTag(138);
			removeChildByTag(139); removeChildByTag(161);
			removeChildByTag(162);

			removeChildByTag(140);
			removeChildByTag(141);
			removeChildByTag(142);
			removeChildByTag(143);

			Sprite* info = Sprite::create("MiniGameResources/pop_noinvest.png");
			info->setAnchorPoint(Point(0.5, 0));
			info->setPosition(Point(520, 410));
			info->setTag(164);
			this->addChild(info, 5);

			auto cancel = MenuItemImage::create(
				"MiniGameResources/pop_enter.png",
				"MiniGameResources/pop_enterpr.png",
				CC_CALLBACK_1(InvestScene::cancelbuy, this));
			cancel->setAnchorPoint(Point(0.5, 0.5));
			cancel->setPosition(Point(520, 450));

			auto canceltext = Menu::create(cancel, NULL);
			canceltext->setAnchorPoint(Point(0.5, 0.5));
			canceltext->setPosition(Point(0, 0));
			canceltext->setTag(165);
			this->addChild(canceltext, 7);
		}
		Singletons::getInstance()->num_S = 0;
	}

	//애플판매
	{
		if (Singletons::getInstance()->ju_A >= 2)
		{
			if (Singletons::getInstance()->num_A == 2)
			{
				Singletons::getInstance()->ju_A = Singletons::getInstance()->ju_A - 2;
				Singletons::getInstance()->money = Singletons::getInstance()->money + (Singletons::getInstance()->apple_1 * 2);
				removeChildByTag(164);
				removeChildByTag(165);
				removeChildByTag(166);
				removeChildByTag(146);
				removeChildByTag(135);
				removeChildByTag(136);
				removeChildByTag(137); removeChildByTag(161);
				removeChildByTag(162);

				removeChildByTag(138);
				removeChildByTag(139);
				removeChildByTag(140);
				removeChildByTag(141);
				removeChildByTag(142);
				removeChildByTag(143);
			}
		}
		else if (Singletons::getInstance()->num_A == 2 && Singletons::getInstance()->ju_A <= 1)
		{
			removeChildByTag(164);
			removeChildByTag(165);
			removeChildByTag(166);
			removeChildByTag(146);
			removeChildByTag(135);
			removeChildByTag(136);
			removeChildByTag(137); removeChildByTag(161);
			removeChildByTag(162);

			removeChildByTag(138);
			removeChildByTag(139);
			removeChildByTag(140);
			removeChildByTag(141);
			removeChildByTag(142);
			removeChildByTag(143);

			Sprite* info = Sprite::create("MiniGameResources/pop_noinvest.png");
			info->setAnchorPoint(Point(0.5, 0));
			info->setPosition(Point(520, 410));
			info->setTag(164);
			this->addChild(info, 5);

			auto cancel = MenuItemImage::create(
				"MiniGameResources/pop_enter.png",
				"MiniGameResources/pop_enterpr.png",
				CC_CALLBACK_1(InvestScene::cancelbuy, this));
			cancel->setAnchorPoint(Point(0.5, 0.5));
			cancel->setPosition(Point(520, 450));

			auto canceltext = Menu::create(cancel, NULL);
			canceltext->setAnchorPoint(Point(0.5, 0.5));
			canceltext->setPosition(Point(0, 0));
			canceltext->setTag(165);
			this->addChild(canceltext, 7);
		}
		Singletons::getInstance()->num_A = 0;
	}

	//하놔판매
	{
		if (Singletons::getInstance()->ju_H >= 2)
		{
			if (Singletons::getInstance()->num_H == 2)
			{
				Singletons::getInstance()->ju_H = Singletons::getInstance()->ju_H - 2;
				Singletons::getInstance()->money = Singletons::getInstance()->money + (Singletons::getInstance()->hanhwa_1 * 2);
				removeChildByTag(164);
				removeChildByTag(165);
				removeChildByTag(166);
				removeChildByTag(146);
				removeChildByTag(135);
				removeChildByTag(136);
				removeChildByTag(137);
				removeChildByTag(138);
				removeChildByTag(139);
				removeChildByTag(140); removeChildByTag(161);
				removeChildByTag(162);

				removeChildByTag(141);
				removeChildByTag(142);
				removeChildByTag(143);
			}
		}
		else if (Singletons::getInstance()->num_H == 2 && Singletons::getInstance()->ju_H <= 1)
		{
			removeChildByTag(164);
			removeChildByTag(165);
			removeChildByTag(166);
			removeChildByTag(146);
			removeChildByTag(135);
			removeChildByTag(136);
			removeChildByTag(137);
			removeChildByTag(138);
			removeChildByTag(139); removeChildByTag(161);
			removeChildByTag(162);

			removeChildByTag(140);
			removeChildByTag(141);
			removeChildByTag(142);
			removeChildByTag(143);

			Sprite* info = Sprite::create("MiniGameResources/pop_noinvest.png");
			info->setAnchorPoint(Point(0.5, 0));
			info->setPosition(Point(520, 410));
			info->setTag(164);
			this->addChild(info, 5);

			auto cancel = MenuItemImage::create(
				"MiniGameResources/pop_enter.png",
				"MiniGameResources/pop_enterpr.png",
				CC_CALLBACK_1(InvestScene::cancelbuy, this));
			cancel->setAnchorPoint(Point(0.5, 0.5));
			cancel->setPosition(Point(520, 450));

			auto canceltext = Menu::create(cancel, NULL);
			canceltext->setAnchorPoint(Point(0.5, 0.5));
			canceltext->setPosition(Point(0, 0));
			canceltext->setTag(165);
			this->addChild(canceltext, 7);
		}
		Singletons::getInstance()->num_H = 0;
	}

	//기아판매
	{
		if (Singletons::getInstance()->ju_K >= 2)
		{
			if (Singletons::getInstance()->num_K == 2)
			{
				Singletons::getInstance()->ju_K = Singletons::getInstance()->ju_K - 2;
				Singletons::getInstance()->money = Singletons::getInstance()->money + (Singletons::getInstance()->kia_1 * 2);
				removeChildByTag(164);
				removeChildByTag(165);
				removeChildByTag(166);
				removeChildByTag(146);
				removeChildByTag(135);
				removeChildByTag(136);
				removeChildByTag(137);
				removeChildByTag(138);
				removeChildByTag(139); removeChildByTag(161);
				removeChildByTag(162);

				removeChildByTag(140);
				removeChildByTag(141);
				removeChildByTag(142);
				removeChildByTag(143);
			}
		}
		else if (Singletons::getInstance()->num_K == 2 && Singletons::getInstance()->ju_K <= 1)
		{
			removeChildByTag(164);
			removeChildByTag(165);
			removeChildByTag(166);
			removeChildByTag(146);
			removeChildByTag(135);
			removeChildByTag(136);
			removeChildByTag(137);
			removeChildByTag(138); removeChildByTag(161);
			removeChildByTag(162);

			removeChildByTag(139);
			removeChildByTag(140);
			removeChildByTag(141);
			removeChildByTag(142);
			removeChildByTag(143);

			Sprite* info = Sprite::create("MiniGameResources/pop_noinvest.png");
			info->setAnchorPoint(Point(0.5, 0));
			info->setPosition(Point(520, 410));
			info->setTag(164);
			this->addChild(info, 5);

			auto cancel = MenuItemImage::create(
				"MiniGameResources/pop_enter.png",
				"MiniGameResources/pop_enterpr.png",
				CC_CALLBACK_1(InvestScene::cancelbuy, this));
			cancel->setAnchorPoint(Point(0.5, 0.5));
			cancel->setPosition(Point(520, 450));

			auto canceltext = Menu::create(cancel, NULL);
			canceltext->setAnchorPoint(Point(0.5, 0.5));
			canceltext->setPosition(Point(0, 0));
			canceltext->setTag(165);
			this->addChild(canceltext, 7);
		}
		Singletons::getInstance()->num_K = 0;
	}
	//엘쥐판매
	{
		if (Singletons::getInstance()->ju_L >= 2)
		{
			if (Singletons::getInstance()->num_L == 2)
			{
				Singletons::getInstance()->ju_L = Singletons::getInstance()->ju_L - 2;
				Singletons::getInstance()->money = Singletons::getInstance()->money + (Singletons::getInstance()->lg_1 * 2);
				removeChildByTag(164);
				removeChildByTag(165);
				removeChildByTag(166);
				removeChildByTag(146);
				removeChildByTag(135);
				removeChildByTag(136);
				removeChildByTag(137); removeChildByTag(161);
				removeChildByTag(162);

				removeChildByTag(138);
				removeChildByTag(139);
				removeChildByTag(140);
				removeChildByTag(141);
				removeChildByTag(142);
				removeChildByTag(143);
			}
		}
		else if (Singletons::getInstance()->num_L == 2 && Singletons::getInstance()->ju_L <= 1)
		{
			removeChildByTag(164);
			removeChildByTag(165);
			removeChildByTag(166);
			removeChildByTag(146);
			removeChildByTag(135);
			removeChildByTag(136);
			removeChildByTag(137);
			removeChildByTag(138); removeChildByTag(161);
			removeChildByTag(162);

			removeChildByTag(139);
			removeChildByTag(140);
			removeChildByTag(141);
			removeChildByTag(142);
			removeChildByTag(143);

			Sprite* info = Sprite::create("MiniGameResources/pop_noinvest.png");
			info->setAnchorPoint(Point(0.5, 0));
			info->setPosition(Point(520, 410));
			info->setTag(164);
			this->addChild(info, 5);

			auto cancel = MenuItemImage::create(
				"MiniGameResources/pop_enter.png",
				"MiniGameResources/pop_enterpr.png",
				CC_CALLBACK_1(InvestScene::cancelbuy, this));
			cancel->setAnchorPoint(Point(0.5, 0.5));
			cancel->setPosition(Point(520, 450));

			auto canceltext = Menu::create(cancel, NULL);
			canceltext->setAnchorPoint(Point(0.5, 0.5));
			canceltext->setPosition(Point(0, 0));
			canceltext->setTag(165);
			this->addChild(canceltext, 7);
		}
		Singletons::getInstance()->num_L = 0;
	}
}
void InvestScene::sell_3(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);
	//삼성판매
	{
		if (Singletons::getInstance()->ju_S >= 3)
		{
			if (Singletons::getInstance()->num_S == 2)
			{
				Singletons::getInstance()->ju_S = Singletons::getInstance()->ju_S - 3;
				Singletons::getInstance()->money = Singletons::getInstance()->money + (Singletons::getInstance()->samsung_1 * 3);
				removeChildByTag(164);
				removeChildByTag(165);
				removeChildByTag(166);
				removeChildByTag(146);
				removeChildByTag(135);
				removeChildByTag(136);
				removeChildByTag(137);
				removeChildByTag(138); removeChildByTag(161);
				removeChildByTag(162);

				removeChildByTag(139);
				removeChildByTag(140);
				removeChildByTag(141);
				removeChildByTag(142);
				removeChildByTag(143);
			}
		}
		else if (Singletons::getInstance()->num_S == 2 && Singletons::getInstance()->ju_S <= 2)
		{
			removeChildByTag(164);
			removeChildByTag(165);
			removeChildByTag(166);
			removeChildByTag(146);
			removeChildByTag(135);
			removeChildByTag(136);
			removeChildByTag(137);
			removeChildByTag(138);
			removeChildByTag(139);
			removeChildByTag(140); removeChildByTag(161);
			removeChildByTag(162);

			removeChildByTag(141);
			removeChildByTag(142);
			removeChildByTag(143);

			Sprite* info = Sprite::create("MiniGameResources/pop_noinvest.png");
			info->setAnchorPoint(Point(0.5, 0));
			info->setPosition(Point(520, 410));
			info->setTag(164);
			this->addChild(info, 5);

			auto cancel = MenuItemImage::create(
				"MiniGameResources/pop_enter.png",
				"MiniGameResources/pop_enterpr.png",
				CC_CALLBACK_1(InvestScene::cancelbuy, this));
			cancel->setAnchorPoint(Point(0.5, 0.5));
			cancel->setPosition(Point(520, 450));

			auto canceltext = Menu::create(cancel, NULL);
			canceltext->setAnchorPoint(Point(0.5, 0.5));
			canceltext->setPosition(Point(0, 0));
			canceltext->setTag(165);
			this->addChild(canceltext, 7);
		}
		Singletons::getInstance()->num_S = 0;
	}

	//애플판매
	{
		if (Singletons::getInstance()->ju_A >= 3)
		{
			if (Singletons::getInstance()->num_A == 2)
			{
				Singletons::getInstance()->ju_A = Singletons::getInstance()->ju_A - 3;
				Singletons::getInstance()->money = Singletons::getInstance()->money + (Singletons::getInstance()->apple_1 * 3);
				removeChildByTag(164);
				removeChildByTag(165);
				removeChildByTag(166);
				removeChildByTag(146);
				removeChildByTag(135);
				removeChildByTag(136);
				removeChildByTag(137);
				removeChildByTag(138);
				removeChildByTag(139);
				removeChildByTag(140); removeChildByTag(161);
				removeChildByTag(162);

				removeChildByTag(141);
				removeChildByTag(142);
				removeChildByTag(143);
			}
		}
		else if (Singletons::getInstance()->num_A == 2 && Singletons::getInstance()->ju_A <= 2)
		{
			removeChildByTag(164);
			removeChildByTag(165);
			removeChildByTag(166);
			removeChildByTag(146);
			removeChildByTag(135);
			removeChildByTag(136); removeChildByTag(161);
			removeChildByTag(162);

			removeChildByTag(137);
			removeChildByTag(138);
			removeChildByTag(139);
			removeChildByTag(140);
			removeChildByTag(141);
			removeChildByTag(142);
			removeChildByTag(143);

			Sprite* info = Sprite::create("MiniGameResources/pop_noinvest.png");
			info->setAnchorPoint(Point(0.5, 0));
			info->setPosition(Point(520, 410));
			info->setTag(164);
			this->addChild(info, 5);

			auto cancel = MenuItemImage::create(
				"MiniGameResources/pop_enter.png",
				"MiniGameResources/pop_enterpr.png",
				CC_CALLBACK_1(InvestScene::cancelbuy, this));
			cancel->setAnchorPoint(Point(0.5, 0.5));
			cancel->setPosition(Point(520, 450));

			auto canceltext = Menu::create(cancel, NULL);
			canceltext->setAnchorPoint(Point(0.5, 0.5));
			canceltext->setPosition(Point(0, 0));
			canceltext->setTag(165);
			this->addChild(canceltext, 7);
		}
		Singletons::getInstance()->num_A = 0;
	}

	//하놔판매
	{
		if (Singletons::getInstance()->ju_H >= 3)
		{
			if (Singletons::getInstance()->num_H == 2)
			{
				Singletons::getInstance()->ju_H = Singletons::getInstance()->ju_H - 3;
				Singletons::getInstance()->money = Singletons::getInstance()->money + (Singletons::getInstance()->hanhwa_1 * 3);
				removeChildByTag(164);
				removeChildByTag(165);
				removeChildByTag(166);
				removeChildByTag(146);
				removeChildByTag(135);
				removeChildByTag(136);
				removeChildByTag(137);
				removeChildByTag(138);
				removeChildByTag(139); removeChildByTag(161);
				removeChildByTag(162);
				
				removeChildByTag(140);
				removeChildByTag(141);
				removeChildByTag(142);
				removeChildByTag(143);
			}
		}
		else if (Singletons::getInstance()->num_H == 2 && Singletons::getInstance()->ju_H <= 2)
		{
			removeChildByTag(164);
			removeChildByTag(165);
			removeChildByTag(166);
			removeChildByTag(146);
			removeChildByTag(135);
			removeChildByTag(136);
			removeChildByTag(137);
			removeChildByTag(138);
			removeChildByTag(139); removeChildByTag(161);
			removeChildByTag(162);

			removeChildByTag(140);
			removeChildByTag(141);
			removeChildByTag(142);
			removeChildByTag(143);

			Sprite* info = Sprite::create("MiniGameResources/pop_noinvest.png");
			info->setAnchorPoint(Point(0.5, 0));
			info->setPosition(Point(520, 410));
			info->setTag(164);
			this->addChild(info, 5);

			auto cancel = MenuItemImage::create(
				"MiniGameResources/pop_enter.png",
				"MiniGameResources/pop_enterpr.png",
				CC_CALLBACK_1(InvestScene::cancelbuy, this));
			cancel->setAnchorPoint(Point(0.5, 0.5));
			cancel->setPosition(Point(520, 450));

			auto canceltext = Menu::create(cancel, NULL);
			canceltext->setAnchorPoint(Point(0.5, 0.5));
			canceltext->setPosition(Point(0, 0));
			canceltext->setTag(165);
			this->addChild(canceltext, 7);
		}
		Singletons::getInstance()->num_H = 0;
	}

	//기아판매
	{
		if (Singletons::getInstance()->ju_K >= 3)
		{
			if (Singletons::getInstance()->num_K == 2)
			{
				Singletons::getInstance()->ju_K = Singletons::getInstance()->ju_K - 3;
				Singletons::getInstance()->money = Singletons::getInstance()->money + (Singletons::getInstance()->kia_1 * 3);
				removeChildByTag(164);
				removeChildByTag(165);
				removeChildByTag(166);
				removeChildByTag(146);
				removeChildByTag(135);
				removeChildByTag(136);
				removeChildByTag(137);
				removeChildByTag(138); removeChildByTag(161);
				removeChildByTag(162);

				removeChildByTag(139);
				removeChildByTag(140);
				removeChildByTag(141);
				removeChildByTag(142);
				removeChildByTag(143);
			}
		}
		else if (Singletons::getInstance()->num_K == 2 && Singletons::getInstance()->ju_K <= 2)
		{
			removeChildByTag(164);
			removeChildByTag(165);
			removeChildByTag(166);
			removeChildByTag(146);
			removeChildByTag(135);
			removeChildByTag(136);
			removeChildByTag(137);
			removeChildByTag(138);
			removeChildByTag(139);
			removeChildByTag(140); removeChildByTag(161);
			removeChildByTag(162);

			removeChildByTag(141);
			removeChildByTag(142);
			removeChildByTag(143);

			Sprite* info = Sprite::create("MiniGameResources/pop_noinvest.png");
			info->setAnchorPoint(Point(0.5, 0));
			info->setPosition(Point(520, 410));
			info->setTag(164);
			this->addChild(info, 5);

			auto cancel = MenuItemImage::create(
				"MiniGameResources/pop_enter.png",
				"MiniGameResources/pop_enterpr.png",
				CC_CALLBACK_1(InvestScene::cancelbuy, this));
			cancel->setAnchorPoint(Point(0.5, 0.5));
			cancel->setPosition(Point(520, 450));

			auto canceltext = Menu::create(cancel, NULL);
			canceltext->setAnchorPoint(Point(0.5, 0.5));
			canceltext->setPosition(Point(0, 0));
			canceltext->setTag(165);
			this->addChild(canceltext, 7);
		}
		Singletons::getInstance()->num_K = 0;
	}
	//엘쥐판매
	{
		if (Singletons::getInstance()->ju_L >= 3)
		{
			if (Singletons::getInstance()->num_L == 2)
			{
				Singletons::getInstance()->ju_L = Singletons::getInstance()->ju_L - 3;
				Singletons::getInstance()->money = Singletons::getInstance()->money + (Singletons::getInstance()->lg_1 * 3);
				removeChildByTag(164);
				removeChildByTag(165);
				removeChildByTag(166);
				removeChildByTag(146);
				removeChildByTag(135);
				removeChildByTag(136);
				removeChildByTag(137);
				removeChildByTag(138);
				removeChildByTag(139);
				removeChildByTag(140); removeChildByTag(161);
				removeChildByTag(162);

				removeChildByTag(141);
				removeChildByTag(142);
				removeChildByTag(143);
			}
		}
		else if (Singletons::getInstance()->num_L == 2 && Singletons::getInstance()->ju_L <= 2)
		{
			removeChildByTag(164);
			removeChildByTag(165);
			removeChildByTag(166);
			removeChildByTag(146);
			removeChildByTag(135);
			removeChildByTag(136);
			removeChildByTag(137);
			removeChildByTag(138);
			removeChildByTag(139);
			removeChildByTag(140); removeChildByTag(161);
			removeChildByTag(162);

			removeChildByTag(141);
			removeChildByTag(142);
			removeChildByTag(143);

			Sprite* info = Sprite::create("MiniGameResources/pop_noinvest.png");
			info->setAnchorPoint(Point(0.5, 0));
			info->setPosition(Point(520, 410));
			info->setTag(164);
			this->addChild(info, 5);

			auto cancel = MenuItemImage::create(
				"MiniGameResources/pop_enter.png",
				"MiniGameResources/pop_enterpr.png",
				CC_CALLBACK_1(InvestScene::cancelbuy, this));
			cancel->setAnchorPoint(Point(0.5, 0.5));
			cancel->setPosition(Point(520, 450));

			auto canceltext = Menu::create(cancel, NULL);
			canceltext->setAnchorPoint(Point(0.5, 0.5));
			canceltext->setPosition(Point(0, 0));
			canceltext->setTag(165);
			this->addChild(canceltext, 7);
		}
		Singletons::getInstance()->num_L = 0;
	}
}
void InvestScene::sell_4(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);
	//삼성판매
	{
		if (Singletons::getInstance()->ju_S >= 4)
		{
			if (Singletons::getInstance()->num_S == 2)
			{
				Singletons::getInstance()->ju_S = Singletons::getInstance()->ju_S - 4;
				Singletons::getInstance()->money = Singletons::getInstance()->money + (Singletons::getInstance()->samsung_1 * 4);
				removeChildByTag(164);
				removeChildByTag(165);
				removeChildByTag(166);
				removeChildByTag(146);
				removeChildByTag(135);
				removeChildByTag(136);
				removeChildByTag(137);
				removeChildByTag(138); removeChildByTag(161);
				removeChildByTag(162);

				removeChildByTag(139);
				removeChildByTag(140);
				removeChildByTag(141);
				removeChildByTag(142);
				removeChildByTag(143);
			}
		}
		else if (Singletons::getInstance()->num_S == 2 && Singletons::getInstance()->ju_S <= 3)
		{
			removeChildByTag(164);
			removeChildByTag(165);
			removeChildByTag(166);
			removeChildByTag(146);
			removeChildByTag(135);
			removeChildByTag(136);
			removeChildByTag(137); removeChildByTag(161);
			removeChildByTag(162);

			removeChildByTag(138);
			removeChildByTag(139);
			removeChildByTag(140);
			removeChildByTag(141);
			removeChildByTag(142);
			removeChildByTag(143);

			Sprite* info = Sprite::create("MiniGameResources/pop_noinvest.png");
			info->setAnchorPoint(Point(0.5, 0));
			info->setPosition(Point(520, 410));
			info->setTag(164);
			this->addChild(info, 5);

			auto cancel = MenuItemImage::create(
				"MiniGameResources/pop_enter.png",
				"MiniGameResources/pop_enterpr.png",
				CC_CALLBACK_1(InvestScene::cancelbuy, this));
			cancel->setAnchorPoint(Point(0.5, 0.5));
			cancel->setPosition(Point(520, 450));

			auto canceltext = Menu::create(cancel, NULL);
			canceltext->setAnchorPoint(Point(0.5, 0.5));
			canceltext->setPosition(Point(0, 0));
			canceltext->setTag(165);
			this->addChild(canceltext, 7);
		}
		Singletons::getInstance()->num_S = 0;
	}

	//애플판매
	{
		if (Singletons::getInstance()->ju_A >= 4)
		{
			if (Singletons::getInstance()->num_A == 2)
			{
				Singletons::getInstance()->ju_A = Singletons::getInstance()->ju_A - 4;
				Singletons::getInstance()->money = Singletons::getInstance()->money + (Singletons::getInstance()->apple_1 * 4);
				removeChildByTag(164);
				removeChildByTag(165);
				removeChildByTag(166);
				removeChildByTag(146);
				removeChildByTag(135);
				removeChildByTag(136);
				removeChildByTag(137);
				removeChildByTag(138);
				removeChildByTag(139);
				removeChildByTag(140); removeChildByTag(161);
				removeChildByTag(162);

				removeChildByTag(141);
				removeChildByTag(142);
				removeChildByTag(143);
			}
		}
		else if (Singletons::getInstance()->num_A == 2 && Singletons::getInstance()->ju_A <= 3)
		{
			removeChildByTag(164);
			removeChildByTag(165);
			removeChildByTag(166);
			removeChildByTag(146);
			removeChildByTag(135);
			removeChildByTag(136);
			removeChildByTag(137);
			removeChildByTag(138);
			removeChildByTag(139);
			removeChildByTag(140); removeChildByTag(161);
			removeChildByTag(162);

			removeChildByTag(141);
			removeChildByTag(142);
			removeChildByTag(143);

			Sprite* info = Sprite::create("MiniGameResources/pop_noinvest.png");
			info->setAnchorPoint(Point(0.5, 0));
			info->setPosition(Point(520, 410));
			info->setTag(164);
			this->addChild(info, 5);

			auto cancel = MenuItemImage::create(
				"MiniGameResources/pop_enter.png",
				"MiniGameResources/pop_enterpr.png",
				CC_CALLBACK_1(InvestScene::cancelbuy, this));
			cancel->setAnchorPoint(Point(0.5, 0.5));
			cancel->setPosition(Point(520, 450));

			auto canceltext = Menu::create(cancel, NULL);
			canceltext->setAnchorPoint(Point(0.5, 0.5));
			canceltext->setPosition(Point(0, 0));
			canceltext->setTag(165);
			this->addChild(canceltext, 7);
		}
		Singletons::getInstance()->num_A = 0;
	}

	//하놔판매
	{
		if (Singletons::getInstance()->ju_H >= 4)
		{
			if (Singletons::getInstance()->num_H == 2)
			{
				Singletons::getInstance()->ju_H = Singletons::getInstance()->ju_H - 4;
				Singletons::getInstance()->money = Singletons::getInstance()->money + (Singletons::getInstance()->hanhwa_1 * 4);
				removeChildByTag(164);
				removeChildByTag(165);
				removeChildByTag(166);
				removeChildByTag(146);
				removeChildByTag(135);
				removeChildByTag(136);
				removeChildByTag(137);
				removeChildByTag(138);
				removeChildByTag(139); removeChildByTag(161);
				removeChildByTag(162);

				removeChildByTag(140);
				removeChildByTag(141);
				removeChildByTag(142);
				removeChildByTag(143);
			}
		}
		else if (Singletons::getInstance()->num_H == 2 && Singletons::getInstance()->ju_H <= 3)
		{
			removeChildByTag(164);
			removeChildByTag(165);
			removeChildByTag(166);
			removeChildByTag(146);
			removeChildByTag(135);
			removeChildByTag(136);
			removeChildByTag(137);
			removeChildByTag(138);
			removeChildByTag(139);
			removeChildByTag(140);
			removeChildByTag(141);
			removeChildByTag(142); removeChildByTag(161);
			removeChildByTag(162);

			removeChildByTag(143);

			Sprite* info = Sprite::create("MiniGameResources/pop_noinvest.png");
			info->setAnchorPoint(Point(0.5, 0));
			info->setPosition(Point(520, 410));
			info->setTag(164);
			this->addChild(info, 5);

			auto cancel = MenuItemImage::create(
				"MiniGameResources/pop_enter.png",
				"MiniGameResources/pop_enterpr.png",
				CC_CALLBACK_1(InvestScene::cancelbuy, this));
			cancel->setAnchorPoint(Point(0.5, 0.5));
			cancel->setPosition(Point(520, 450));

			auto canceltext = Menu::create(cancel, NULL);
			canceltext->setAnchorPoint(Point(0.5, 0.5));
			canceltext->setPosition(Point(0, 0));
			canceltext->setTag(165);
			this->addChild(canceltext, 7);
		}
		Singletons::getInstance()->num_H = 0;
	}

	//기아판매
	{
		if (Singletons::getInstance()->ju_K >= 4)
		{
			if (Singletons::getInstance()->num_K == 2)
			{
				Singletons::getInstance()->ju_K = Singletons::getInstance()->ju_K - 4;
				Singletons::getInstance()->money = Singletons::getInstance()->money + (Singletons::getInstance()->kia_1 * 4);
				removeChildByTag(164);
				removeChildByTag(165);
				removeChildByTag(166);
				removeChildByTag(146);
				removeChildByTag(135);
				removeChildByTag(136);
				removeChildByTag(137);
				removeChildByTag(138);
				removeChildByTag(139);
				removeChildByTag(140); removeChildByTag(161);
				removeChildByTag(162);

				removeChildByTag(141);
				removeChildByTag(142);
				removeChildByTag(143);
			}
		}
		else if (Singletons::getInstance()->num_K == 2 && Singletons::getInstance()->ju_K <= 3)
		{
			removeChildByTag(164);
			removeChildByTag(165);
			removeChildByTag(166);
			removeChildByTag(146);
			removeChildByTag(135);
			removeChildByTag(136);
			removeChildByTag(137);
			removeChildByTag(138);
			removeChildByTag(139);
			removeChildByTag(140);
			removeChildByTag(141);
			removeChildByTag(142); removeChildByTag(161);
			removeChildByTag(162);

			removeChildByTag(143);

			Sprite* info = Sprite::create("MiniGameResources/pop_noinvest.png");
			info->setAnchorPoint(Point(0.5, 0));
			info->setPosition(Point(520, 410));
			info->setTag(164);
			this->addChild(info, 5);

			auto cancel = MenuItemImage::create(
				"MiniGameResources/pop_enter.png",
				"MiniGameResources/pop_enterpr.png",
				CC_CALLBACK_1(InvestScene::cancelbuy, this));
			cancel->setAnchorPoint(Point(0.5, 0.5));
			cancel->setPosition(Point(520, 450));

			auto canceltext = Menu::create(cancel, NULL);
			canceltext->setAnchorPoint(Point(0.5, 0.5));
			canceltext->setPosition(Point(0, 0));
			canceltext->setTag(165);
			this->addChild(canceltext, 7);
		}
		Singletons::getInstance()->num_K = 0;
	}
	//엘쥐판매
	{
		if (Singletons::getInstance()->ju_L >= 4)
		{
			if (Singletons::getInstance()->num_L == 2)
			{
				Singletons::getInstance()->ju_L = Singletons::getInstance()->ju_L - 4;
				Singletons::getInstance()->money = Singletons::getInstance()->money + (Singletons::getInstance()->lg_1 * 4);
				removeChildByTag(164);
				removeChildByTag(165);
				removeChildByTag(166);
				removeChildByTag(146);
				removeChildByTag(135);
				removeChildByTag(136);
				removeChildByTag(137);
				removeChildByTag(138);
				removeChildByTag(139);
				removeChildByTag(140); removeChildByTag(161);
				removeChildByTag(162);

				removeChildByTag(141);
				removeChildByTag(142);
				removeChildByTag(143);
			}
		}
		else if (Singletons::getInstance()->num_L == 2 && Singletons::getInstance()->ju_L <= 3)
		{
			removeChildByTag(164);
			removeChildByTag(165);
			removeChildByTag(166);
			removeChildByTag(146);
			removeChildByTag(135);
			removeChildByTag(136);
			removeChildByTag(137);
			removeChildByTag(138);
			removeChildByTag(139);
			removeChildByTag(140);
			removeChildByTag(141);
			removeChildByTag(142);
			removeChildByTag(143); removeChildByTag(161);
			removeChildByTag(162);


			Sprite* info = Sprite::create("MiniGameResources/pop_noinvest.png");
			info->setAnchorPoint(Point(0.5, 0));
			info->setPosition(Point(520, 410));
			info->setTag(164);
			this->addChild(info, 5);

			auto cancel = MenuItemImage::create(
				"MiniGameResources/pop_enter.png",
				"MiniGameResources/pop_enterpr.png",
				CC_CALLBACK_1(InvestScene::cancelbuy, this));
			cancel->setAnchorPoint(Point(0.5, 0.5));
			cancel->setPosition(Point(520, 450));

			auto canceltext = Menu::create(cancel, NULL);
			canceltext->setAnchorPoint(Point(0.5, 0.5));
			canceltext->setPosition(Point(0, 0));
			canceltext->setTag(165);
			this->addChild(canceltext, 7);
		}
		Singletons::getInstance()->num_L = 0;
	}
}
void InvestScene::sell_5(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);
	//삼성판매
	{
		if (Singletons::getInstance()->ju_S >= 5)
		{
			if (Singletons::getInstance()->num_S == 2)
			{
				Singletons::getInstance()->ju_S = Singletons::getInstance()->ju_S - 5;
				Singletons::getInstance()->money = Singletons::getInstance()->money + (Singletons::getInstance()->samsung_1 * 5);
				removeChildByTag(164);
				removeChildByTag(165);
				removeChildByTag(166);
				removeChildByTag(146);
				removeChildByTag(135);
				removeChildByTag(136);
				removeChildByTag(137);
				removeChildByTag(138);
				removeChildByTag(139); removeChildByTag(161);
				removeChildByTag(162);

				removeChildByTag(140);
				removeChildByTag(141);
				removeChildByTag(142);
				removeChildByTag(143);
			}
		}
		else if (Singletons::getInstance()->num_S == 2 && Singletons::getInstance()->ju_S <= 4)
		{
			removeChildByTag(164);
			removeChildByTag(165);
			removeChildByTag(166);
			removeChildByTag(146);
			removeChildByTag(135);
			removeChildByTag(136);
			removeChildByTag(137);
			removeChildByTag(138);
			removeChildByTag(139);
			removeChildByTag(140); removeChildByTag(161);
			removeChildByTag(162);

			removeChildByTag(141);
			removeChildByTag(142);
			removeChildByTag(143);

			Sprite* info = Sprite::create("MiniGameResources/pop_noinvest.png");
			info->setAnchorPoint(Point(0.5, 0));
			info->setPosition(Point(520, 410));
			info->setTag(164);
			this->addChild(info, 5);

			auto cancel = MenuItemImage::create(
				"MiniGameResources/pop_enter.png",
				"MiniGameResources/pop_enterpr.png",
				CC_CALLBACK_1(InvestScene::cancelbuy, this));
			cancel->setAnchorPoint(Point(0.5, 0.5));
			cancel->setPosition(Point(520, 450));

			auto canceltext = Menu::create(cancel, NULL);
			canceltext->setAnchorPoint(Point(0.5, 0.5));
			canceltext->setPosition(Point(0, 0));
			canceltext->setTag(165);
			this->addChild(canceltext, 7);
		}
		Singletons::getInstance()->num_S = 0;
	}

	//애플판매
	{
		if (Singletons::getInstance()->ju_A >= 5)
		{
			if (Singletons::getInstance()->num_A == 2)
			{
				Singletons::getInstance()->ju_A = Singletons::getInstance()->ju_A - 5;
				Singletons::getInstance()->money = Singletons::getInstance()->money + (Singletons::getInstance()->apple_1 * 5);
				removeChildByTag(164);
				removeChildByTag(165);
				removeChildByTag(166);
				removeChildByTag(146);
				removeChildByTag(135);
				removeChildByTag(136);
				removeChildByTag(137);
				removeChildByTag(138);
				removeChildByTag(139);
				removeChildByTag(140);
				removeChildByTag(141); removeChildByTag(161);
				removeChildByTag(162);

				removeChildByTag(142);
				removeChildByTag(143);
			}
		}
		else if (Singletons::getInstance()->num_A == 2 && Singletons::getInstance()->ju_A <= 4)
		{
			removeChildByTag(164);
			removeChildByTag(165);
			removeChildByTag(166);
			removeChildByTag(146);
			removeChildByTag(135);
			removeChildByTag(136);
			removeChildByTag(137);
			removeChildByTag(138);
			removeChildByTag(139);
			removeChildByTag(140); removeChildByTag(161);
			removeChildByTag(162);

			removeChildByTag(141);
			removeChildByTag(142);
			removeChildByTag(143);

			Sprite* info = Sprite::create("MiniGameResources/pop_noinvest.png");
			info->setAnchorPoint(Point(0.5, 0));
			info->setPosition(Point(520, 410));
			info->setTag(164);
			this->addChild(info, 5);

			auto cancel = MenuItemImage::create(
				"MiniGameResources/pop_enter.png",
				"MiniGameResources/pop_enterpr.png",
				CC_CALLBACK_1(InvestScene::cancelbuy, this));
			cancel->setAnchorPoint(Point(0.5, 0.5));
			cancel->setPosition(Point(520, 450));

			auto canceltext = Menu::create(cancel, NULL);
			canceltext->setAnchorPoint(Point(0.5, 0.5));
			canceltext->setPosition(Point(0, 0));
			canceltext->setTag(165);
			this->addChild(canceltext, 7);
		}
		Singletons::getInstance()->num_A = 0;
	}

	//하놔판매
	{
		if (Singletons::getInstance()->ju_H >= 5)
		{
			if (Singletons::getInstance()->num_H == 2)
			{
				Singletons::getInstance()->ju_H = Singletons::getInstance()->ju_H - 5;
				Singletons::getInstance()->money = Singletons::getInstance()->money + (Singletons::getInstance()->hanhwa_1 * 5);
				removeChildByTag(164);
				removeChildByTag(165);
				removeChildByTag(166);
				removeChildByTag(146);
				removeChildByTag(135);
				removeChildByTag(136);
				removeChildByTag(137);
				removeChildByTag(138);
				removeChildByTag(139);
				removeChildByTag(140);
				removeChildByTag(141); removeChildByTag(161);
				removeChildByTag(162);

				removeChildByTag(142);
				removeChildByTag(143);
			}
		}
		else if (Singletons::getInstance()->num_H == 2 && Singletons::getInstance()->ju_H <= 4)
		{
			removeChildByTag(164);
			removeChildByTag(165);
			removeChildByTag(166);
			removeChildByTag(146);
			removeChildByTag(135);
			removeChildByTag(136);
			removeChildByTag(137);
			removeChildByTag(138);
			removeChildByTag(139);
			removeChildByTag(140);
			removeChildByTag(141); removeChildByTag(161);
			removeChildByTag(162);

			removeChildByTag(142);
			removeChildByTag(143);

			Sprite* info = Sprite::create("MiniGameResources/pop_noinvest.png");
			info->setAnchorPoint(Point(0.5, 0));
			info->setPosition(Point(520, 410));
			info->setTag(164);
			this->addChild(info, 5);

			auto cancel = MenuItemImage::create(
				"MiniGameResources/pop_enter.png",
				"MiniGameResources/pop_enterpr.png",
				CC_CALLBACK_1(InvestScene::cancelbuy, this));
			cancel->setAnchorPoint(Point(0.5, 0.5));
			cancel->setPosition(Point(520, 450));

			auto canceltext = Menu::create(cancel, NULL);
			canceltext->setAnchorPoint(Point(0.5, 0.5));
			canceltext->setPosition(Point(0, 0));
			canceltext->setTag(165);
			this->addChild(canceltext, 7);
		}
		Singletons::getInstance()->num_H = 0;
	}

	//기아판매
	{
		if (Singletons::getInstance()->ju_K >= 5)
		{
			if (Singletons::getInstance()->num_K == 2)
			{
				Singletons::getInstance()->ju_K = Singletons::getInstance()->ju_K - 5;
				Singletons::getInstance()->money = Singletons::getInstance()->money + (Singletons::getInstance()->kia_1 * 5);
				removeChildByTag(164);
				removeChildByTag(165);
				removeChildByTag(166);
				removeChildByTag(146);
				removeChildByTag(135);
				removeChildByTag(136);
				removeChildByTag(137);
				removeChildByTag(138);
				removeChildByTag(139); removeChildByTag(161);
				removeChildByTag(162);

				removeChildByTag(140);
				removeChildByTag(141);
				removeChildByTag(142);
				removeChildByTag(143);
			}
		}
		else if (Singletons::getInstance()->num_K == 2 && Singletons::getInstance()->ju_K <= 4)
		{
			removeChildByTag(164);
			removeChildByTag(165);
			removeChildByTag(166);
			removeChildByTag(146);
			removeChildByTag(135);
			removeChildByTag(136);
			removeChildByTag(137);
			removeChildByTag(138);
			removeChildByTag(139); removeChildByTag(161);
			removeChildByTag(162);

			removeChildByTag(140);
			removeChildByTag(141);
			removeChildByTag(142);
			removeChildByTag(143);

			Sprite* info = Sprite::create("MiniGameResources/pop_noinvest.png");
			info->setAnchorPoint(Point(0.5, 0));
			info->setPosition(Point(520, 410));
			info->setTag(164);
			this->addChild(info, 5);

			auto cancel = MenuItemImage::create(
				"MiniGameResources/pop_enter.png",
				"MiniGameResources/pop_enterpr.png",
				CC_CALLBACK_1(InvestScene::cancelbuy, this));
			cancel->setAnchorPoint(Point(0.5, 0.5));
			cancel->setPosition(Point(520, 450));

			auto canceltext = Menu::create(cancel, NULL);
			canceltext->setAnchorPoint(Point(0.5, 0.5));
			canceltext->setPosition(Point(0, 0));
			canceltext->setTag(165);
			this->addChild(canceltext, 7);
		}
		Singletons::getInstance()->num_K = 0;
	}
	//엘쥐판매
	{
		if (Singletons::getInstance()->ju_L >= 5)
		{
			if (Singletons::getInstance()->num_L == 2)
			{
				Singletons::getInstance()->ju_L = Singletons::getInstance()->ju_L - 5;
				Singletons::getInstance()->money = Singletons::getInstance()->money + (Singletons::getInstance()->lg_1 * 5);
				removeChildByTag(164);
				removeChildByTag(165);
				removeChildByTag(166);
				removeChildByTag(146);
				removeChildByTag(135);
				removeChildByTag(136);
				removeChildByTag(137);
				removeChildByTag(138);
				removeChildByTag(139);
				removeChildByTag(140); removeChildByTag(161);
				removeChildByTag(162);

				removeChildByTag(141);
				removeChildByTag(142);
				removeChildByTag(143);
			}
		}
		else if (Singletons::getInstance()->num_L == 2 && Singletons::getInstance()->ju_L <= 4)
		{
			removeChildByTag(164);
			removeChildByTag(165);
			removeChildByTag(166);
			removeChildByTag(146);
			removeChildByTag(135);
			removeChildByTag(136);
			removeChildByTag(137);
			removeChildByTag(138);
			removeChildByTag(139); removeChildByTag(161);
			removeChildByTag(162);

			removeChildByTag(140);
			removeChildByTag(141);
			removeChildByTag(142);
			removeChildByTag(143);

			Sprite* info = Sprite::create("MiniGameResources/pop_noinvest.png");
			info->setAnchorPoint(Point(0.5, 0));
			info->setPosition(Point(520, 410));
			info->setTag(164);
			this->addChild(info, 5);

			auto cancel = MenuItemImage::create(
				"MiniGameResources/pop_enter.png",
				"MiniGameResources/pop_enterpr.png",
				CC_CALLBACK_1(InvestScene::cancelbuy, this));
			cancel->setAnchorPoint(Point(0.5, 0.5));
			cancel->setPosition(Point(520, 450));

			auto canceltext = Menu::create(cancel, NULL);
			canceltext->setAnchorPoint(Point(0.5, 0.5));
			canceltext->setPosition(Point(0, 0));
			canceltext->setTag(165);
			this->addChild(canceltext, 7);
		}
		Singletons::getInstance()->num_L = 0;
	}
}
void InvestScene::sell_6(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);
	//삼성판매
	{
		if (Singletons::getInstance()->ju_S >= 6)
		{
			if (Singletons::getInstance()->num_S == 2)
			{
				Singletons::getInstance()->ju_S = Singletons::getInstance()->ju_S - 6;
				Singletons::getInstance()->money = Singletons::getInstance()->money + (Singletons::getInstance()->samsung_1 * 6);
				removeChildByTag(164);
				removeChildByTag(165);
				removeChildByTag(166);
				removeChildByTag(146);
				removeChildByTag(135);
				removeChildByTag(136);
				removeChildByTag(137);
				removeChildByTag(138);
				removeChildByTag(139);
				removeChildByTag(140);
				removeChildByTag(141);
				removeChildByTag(142);
				removeChildByTag(143); removeChildByTag(161);
				removeChildByTag(162);

			}
		}
		else if (Singletons::getInstance()->num_S == 2 && Singletons::getInstance()->ju_S <= 5)
		{
			removeChildByTag(164);
			removeChildByTag(165);
			removeChildByTag(166);
			removeChildByTag(146);
			removeChildByTag(135);
			removeChildByTag(136);
			removeChildByTag(137);
			removeChildByTag(138);
			removeChildByTag(139);
			removeChildByTag(140);
			removeChildByTag(141);
			removeChildByTag(142);
			removeChildByTag(143);
			removeChildByTag(161);
			removeChildByTag(162);

			Sprite* info = Sprite::create("MiniGameResources/pop_noinvest.png");
			info->setAnchorPoint(Point(0.5, 0));
			info->setPosition(Point(520, 410));
			info->setTag(164);
			this->addChild(info, 5);

			auto cancel = MenuItemImage::create(
				"MiniGameResources/pop_enter.png",
				"MiniGameResources/pop_enterpr.png",
				CC_CALLBACK_1(InvestScene::cancelbuy, this));
			cancel->setAnchorPoint(Point(0.5, 0.5));
			cancel->setPosition(Point(520, 450));

			auto canceltext = Menu::create(cancel, NULL);
			canceltext->setAnchorPoint(Point(0.5, 0.5));
			canceltext->setPosition(Point(0, 0));
			canceltext->setTag(165);
			this->addChild(canceltext, 7);
		}
		Singletons::getInstance()->num_S = 0;
	}

	//애플판매
	{
		if (Singletons::getInstance()->ju_A >= 6)
		{
			if (Singletons::getInstance()->num_A == 2)
			{
				Singletons::getInstance()->ju_A = Singletons::getInstance()->ju_A - 6;
				Singletons::getInstance()->money = Singletons::getInstance()->money + (Singletons::getInstance()->apple_1 * 6);
				removeChildByTag(164);
				removeChildByTag(165);
				removeChildByTag(166);
				removeChildByTag(146);
				removeChildByTag(135);
				removeChildByTag(136);
				removeChildByTag(137); removeChildByTag(161);
				removeChildByTag(162);

				removeChildByTag(138);
				removeChildByTag(139);
				removeChildByTag(140);
				removeChildByTag(141);
				removeChildByTag(142);
				removeChildByTag(143);
			}
		}
		else if (Singletons::getInstance()->num_A == 2 && Singletons::getInstance()->ju_A <= 5)
		{
			removeChildByTag(164);
			removeChildByTag(165);
			removeChildByTag(166);
			removeChildByTag(146);
			removeChildByTag(135);
			removeChildByTag(136);
			removeChildByTag(137);
			removeChildByTag(138);
			removeChildByTag(139);
			removeChildByTag(140);
			removeChildByTag(141);
			removeChildByTag(142);
			removeChildByTag(143);
			removeChildByTag(161);
			removeChildByTag(162);

			Sprite* info = Sprite::create("MiniGameResources/pop_noinvest.png");
			info->setAnchorPoint(Point(0.5, 0));
			info->setPosition(Point(520, 410));
			info->setTag(164);
			this->addChild(info, 5);

			auto cancel = MenuItemImage::create(
				"MiniGameResources/pop_enter.png",
				"MiniGameResources/pop_enterpr.png",
				CC_CALLBACK_1(InvestScene::cancelbuy, this));
			cancel->setAnchorPoint(Point(0.5, 0.5));
			cancel->setPosition(Point(520, 450));

			auto canceltext = Menu::create(cancel, NULL);
			canceltext->setAnchorPoint(Point(0.5, 0.5));
			canceltext->setPosition(Point(0, 0));
			canceltext->setTag(165);
			this->addChild(canceltext, 7);
		}
		Singletons::getInstance()->num_A = 0;
	}

	//하놔판매
	{
		if (Singletons::getInstance()->ju_H >= 6)
		{
			if (Singletons::getInstance()->num_H == 2)
			{
				Singletons::getInstance()->ju_H = Singletons::getInstance()->ju_H - 6;
				Singletons::getInstance()->money = Singletons::getInstance()->money + (Singletons::getInstance()->hanhwa_1 * 6);
				removeChildByTag(164);
				removeChildByTag(165);
				removeChildByTag(166);
				removeChildByTag(146);
				removeChildByTag(135);
				removeChildByTag(136);
				removeChildByTag(137); removeChildByTag(161);
				removeChildByTag(162);

				removeChildByTag(138);
				removeChildByTag(139);
				removeChildByTag(140);
				removeChildByTag(141);
				removeChildByTag(142);
				removeChildByTag(143);
			}
		}
		else if (Singletons::getInstance()->num_H == 2 && Singletons::getInstance()->ju_H <= 5)
		{
			removeChildByTag(164);
			removeChildByTag(165);
			removeChildByTag(166);
			removeChildByTag(146);
			removeChildByTag(135);
			removeChildByTag(136);
			removeChildByTag(137);
			removeChildByTag(138);
			removeChildByTag(139);
			removeChildByTag(140);
			removeChildByTag(141);
			removeChildByTag(142);
			removeChildByTag(143);
			removeChildByTag(161);
			removeChildByTag(162);

			Sprite* info = Sprite::create("MiniGameResources/pop_noinvest.png");
			info->setAnchorPoint(Point(0.5, 0));
			info->setPosition(Point(520, 410));
			info->setTag(164);
			this->addChild(info, 5);

			auto cancel = MenuItemImage::create(
				"MiniGameResources/pop_enter.png",
				"MiniGameResources/pop_enterpr.png",
				CC_CALLBACK_1(InvestScene::cancelbuy, this));
			cancel->setAnchorPoint(Point(0.5, 0.5));
			cancel->setPosition(Point(520, 450));

			auto canceltext = Menu::create(cancel, NULL);
			canceltext->setAnchorPoint(Point(0.5, 0.5));
			canceltext->setPosition(Point(0, 0));
			canceltext->setTag(165);
			this->addChild(canceltext, 7);
		}
		Singletons::getInstance()->num_H = 0;
	}

	//기아판매
	{
		if (Singletons::getInstance()->ju_K >= 6)
		{
			if (Singletons::getInstance()->num_K == 2)
			{
				Singletons::getInstance()->ju_K = Singletons::getInstance()->ju_K - 6;
				Singletons::getInstance()->money = Singletons::getInstance()->money + (Singletons::getInstance()->kia_1 * 6);
				removeChildByTag(164);
				removeChildByTag(165);
				removeChildByTag(166);
				removeChildByTag(146);
				removeChildByTag(135);
				removeChildByTag(136);
				removeChildByTag(137);
				removeChildByTag(138);
				removeChildByTag(139); removeChildByTag(161);
				removeChildByTag(162);

				removeChildByTag(140);
				removeChildByTag(141);
				removeChildByTag(142);
				removeChildByTag(143);
			}
		}
		else if (Singletons::getInstance()->num_K == 2 && Singletons::getInstance()->ju_K <=5)
		{
			removeChildByTag(164);
			removeChildByTag(165);
			removeChildByTag(166);
			removeChildByTag(146);
			removeChildByTag(135);
			removeChildByTag(136);
			removeChildByTag(137);
			removeChildByTag(138); removeChildByTag(161);
			removeChildByTag(162);

			removeChildByTag(139);
			removeChildByTag(140);
			removeChildByTag(141);
			removeChildByTag(142);
			removeChildByTag(143);

			Sprite* info = Sprite::create("MiniGameResources/pop_noinvest.png");
			info->setAnchorPoint(Point(0.5, 0));
			info->setPosition(Point(520, 410));
			info->setTag(164);
			this->addChild(info, 5);

			auto cancel = MenuItemImage::create(
				"MiniGameResources/pop_enter.png",
				"MiniGameResources/pop_enterpr.png",
				CC_CALLBACK_1(InvestScene::cancelbuy, this));
			cancel->setAnchorPoint(Point(0.5, 0.5));
			cancel->setPosition(Point(520, 450));

			auto canceltext = Menu::create(cancel, NULL);
			canceltext->setAnchorPoint(Point(0.5, 0.5));
			canceltext->setPosition(Point(0, 0));
			canceltext->setTag(165);
			this->addChild(canceltext, 7);
		}
		Singletons::getInstance()->num_K = 0;
	}
	//엘쥐판매
	{
		if (Singletons::getInstance()->ju_L >= 6)
		{
			if (Singletons::getInstance()->num_L == 2)
			{
				Singletons::getInstance()->ju_L = Singletons::getInstance()->ju_L - 6;
				Singletons::getInstance()->money = Singletons::getInstance()->money + (Singletons::getInstance()->lg_1 * 6);
				removeChildByTag(164);
				removeChildByTag(165);
				removeChildByTag(166);
				removeChildByTag(146);
				removeChildByTag(135);
				removeChildByTag(136);
				removeChildByTag(137);
				removeChildByTag(138);
				removeChildByTag(139);
				removeChildByTag(140);
				removeChildByTag(141);
				removeChildByTag(142); removeChildByTag(161);
				removeChildByTag(162);

				removeChildByTag(143);
			}
		}
		else if (Singletons::getInstance()->num_L == 2 && Singletons::getInstance()->ju_L <= 5)
		{
			removeChildByTag(164);
			removeChildByTag(165);
			removeChildByTag(166);
			removeChildByTag(146);
			removeChildByTag(135);
			removeChildByTag(136);
			removeChildByTag(137);
			removeChildByTag(138);
			removeChildByTag(139);
			removeChildByTag(140); removeChildByTag(161);
			removeChildByTag(162);

			removeChildByTag(141);
			removeChildByTag(142);
			removeChildByTag(143);

			Sprite* info = Sprite::create("MiniGameResources/pop_noinvest.png");
			info->setAnchorPoint(Point(0.5, 0));
			info->setPosition(Point(520, 410));
			info->setTag(164);
			this->addChild(info, 5);

			auto cancel = MenuItemImage::create(
				"MiniGameResources/pop_enter.png",
				"MiniGameResources/pop_enterpr.png",
				CC_CALLBACK_1(InvestScene::cancelbuy, this));
			cancel->setAnchorPoint(Point(0.5, 0.5));
			cancel->setPosition(Point(520, 450));

			auto canceltext = Menu::create(cancel, NULL);
			canceltext->setAnchorPoint(Point(0.5, 0.5));
			canceltext->setPosition(Point(0, 0));
			canceltext->setTag(165);
			this->addChild(canceltext, 7);
		}
		Singletons::getInstance()->num_L = 0;
	}
}
void InvestScene::sell_7(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);
	//삼성판매
	{
		if (Singletons::getInstance()->ju_S >= 7)
		{
			if (Singletons::getInstance()->num_S == 2)
			{
				Singletons::getInstance()->ju_S = Singletons::getInstance()->ju_S - 7;
				Singletons::getInstance()->money = Singletons::getInstance()->money + (Singletons::getInstance()->samsung_1 * 7);
				removeChildByTag(164);
				removeChildByTag(165);
				removeChildByTag(166);
				removeChildByTag(146);
				removeChildByTag(135);
				removeChildByTag(136);
				removeChildByTag(137);
				removeChildByTag(138); removeChildByTag(161);
				removeChildByTag(162);

				removeChildByTag(139);
				removeChildByTag(140);
				removeChildByTag(141);
				removeChildByTag(142);
				removeChildByTag(143);
			}
		}
		else if (Singletons::getInstance()->num_S == 2 && Singletons::getInstance()->ju_S <= 6)
		{
			removeChildByTag(164);
			removeChildByTag(165);
			removeChildByTag(166);
			removeChildByTag(146);
			removeChildByTag(135);
			removeChildByTag(136);
			removeChildByTag(137);
			removeChildByTag(138);
			removeChildByTag(139);
			removeChildByTag(140); removeChildByTag(161);
			removeChildByTag(162);

			removeChildByTag(141);
			removeChildByTag(142);
			removeChildByTag(143);

			Sprite* info = Sprite::create("MiniGameResources/pop_noinvest.png");
			info->setAnchorPoint(Point(0.5, 0));
			info->setPosition(Point(520, 410));
			info->setTag(164);
			this->addChild(info, 5);

			auto cancel = MenuItemImage::create(
				"MiniGameResources/pop_enter.png",
				"MiniGameResources/pop_enterpr.png",
				CC_CALLBACK_1(InvestScene::cancelbuy, this));
			cancel->setAnchorPoint(Point(0.5, 0.5));
			cancel->setPosition(Point(520, 450));

			auto canceltext = Menu::create(cancel, NULL);
			canceltext->setAnchorPoint(Point(0.5, 0.5));
			canceltext->setPosition(Point(0, 0));
			canceltext->setTag(165);
			this->addChild(canceltext, 7);
		}
		Singletons::getInstance()->num_S = 0;
	}

	//애플판매
	{
		if (Singletons::getInstance()->ju_A >= 7)
		{
			if (Singletons::getInstance()->num_A == 2)
			{
				Singletons::getInstance()->ju_A = Singletons::getInstance()->ju_A - 7;
				Singletons::getInstance()->money = Singletons::getInstance()->money + (Singletons::getInstance()->apple_1 * 7);
				removeChildByTag(164);
				removeChildByTag(165);
				removeChildByTag(166);
				removeChildByTag(146);
				removeChildByTag(135);
				removeChildByTag(136);
				removeChildByTag(137);
				removeChildByTag(138); removeChildByTag(161);
				removeChildByTag(162);

				removeChildByTag(139);
				removeChildByTag(140);
				removeChildByTag(141);
				removeChildByTag(142);
				removeChildByTag(143);
			}
		}
		else if (Singletons::getInstance()->num_A == 2 && Singletons::getInstance()->ju_A <= 6)
		{
			removeChildByTag(164);
			removeChildByTag(165);
			removeChildByTag(166);
			removeChildByTag(146);
			removeChildByTag(135);
			removeChildByTag(136);
			removeChildByTag(137);
			removeChildByTag(138); removeChildByTag(161);
			removeChildByTag(162);

			removeChildByTag(139);
			removeChildByTag(140);
			removeChildByTag(141);
			removeChildByTag(142);
			removeChildByTag(143);

			Sprite* info = Sprite::create("MiniGameResources/pop_noinvest.png");
			info->setAnchorPoint(Point(0.5, 0));
			info->setPosition(Point(520, 410));
			info->setTag(164);
			this->addChild(info, 5);

			auto cancel = MenuItemImage::create(
				"MiniGameResources/pop_enter.png",
				"MiniGameResources/pop_enterpr.png",
				CC_CALLBACK_1(InvestScene::cancelbuy, this));
			cancel->setAnchorPoint(Point(0.5, 0.5));
			cancel->setPosition(Point(520, 450));

			auto canceltext = Menu::create(cancel, NULL);
			canceltext->setAnchorPoint(Point(0.5, 0.5));
			canceltext->setPosition(Point(0, 0));
			canceltext->setTag(165);
			this->addChild(canceltext, 7);
		}
		Singletons::getInstance()->num_A = 0;
	}

	//하놔판매
	{
		if (Singletons::getInstance()->ju_H >= 7)
		{
			if (Singletons::getInstance()->num_H == 2)
			{
				Singletons::getInstance()->ju_H = Singletons::getInstance()->ju_H - 7;
				Singletons::getInstance()->money = Singletons::getInstance()->money + (Singletons::getInstance()->hanhwa_1 * 7);
				removeChildByTag(164);
				removeChildByTag(165);
				removeChildByTag(166);
				removeChildByTag(146);
				removeChildByTag(135);
				removeChildByTag(136); removeChildByTag(161);
				removeChildByTag(162);

				removeChildByTag(137);
				removeChildByTag(138);
				removeChildByTag(139);
				removeChildByTag(140);
				removeChildByTag(141);
				removeChildByTag(142);
				removeChildByTag(143);
			}
		}
		else if (Singletons::getInstance()->num_H == 2 && Singletons::getInstance()->ju_H <= 6)
		{
			removeChildByTag(164);
			removeChildByTag(165);
			removeChildByTag(166);
			removeChildByTag(146);
			removeChildByTag(135);
			removeChildByTag(136);
			removeChildByTag(137);
			removeChildByTag(138);
			removeChildByTag(139);
			removeChildByTag(140); removeChildByTag(161);
			removeChildByTag(162);

			removeChildByTag(141);
			removeChildByTag(142);
			removeChildByTag(143);

			Sprite* info = Sprite::create("MiniGameResources/pop_noinvest.png");
			info->setAnchorPoint(Point(0.5, 0));
			info->setPosition(Point(520, 410));
			info->setTag(164);
			this->addChild(info, 5);

			auto cancel = MenuItemImage::create(
				"MiniGameResources/pop_enter.png",
				"MiniGameResources/pop_enterpr.png",
				CC_CALLBACK_1(InvestScene::cancelbuy, this));
			cancel->setAnchorPoint(Point(0.5, 0.5));
			cancel->setPosition(Point(520, 450));

			auto canceltext = Menu::create(cancel, NULL);
			canceltext->setAnchorPoint(Point(0.5, 0.5));
			canceltext->setPosition(Point(0, 0));
			canceltext->setTag(165);
			this->addChild(canceltext, 7);
		}
		Singletons::getInstance()->num_H = 0;
	}

	//기아판매
	{
		if (Singletons::getInstance()->ju_K >= 7)
		{
			if (Singletons::getInstance()->num_K == 2)
			{
				Singletons::getInstance()->ju_K = Singletons::getInstance()->ju_K - 7;
				Singletons::getInstance()->money = Singletons::getInstance()->money + (Singletons::getInstance()->kia_1 * 7);
				removeChildByTag(164);
				removeChildByTag(165);
				removeChildByTag(166);
				removeChildByTag(146);
				removeChildByTag(135);
				removeChildByTag(136); removeChildByTag(161);
				removeChildByTag(162);

				removeChildByTag(137);
				removeChildByTag(138);
				removeChildByTag(139);
				removeChildByTag(140);
				removeChildByTag(141);
				removeChildByTag(142);
				removeChildByTag(143);
			}
		}
		else if (Singletons::getInstance()->num_K == 2 && Singletons::getInstance()->ju_K <= 6)
		{
			removeChildByTag(164);
			removeChildByTag(165);
			removeChildByTag(166);
			removeChildByTag(146);
			removeChildByTag(135);
			removeChildByTag(136);
			removeChildByTag(137);
			removeChildByTag(138);
			removeChildByTag(139);
			removeChildByTag(140);
			removeChildByTag(141); removeChildByTag(161);
			removeChildByTag(162);

			removeChildByTag(142);
			removeChildByTag(143);

			Sprite* info = Sprite::create("MiniGameResources/pop_noinvest.png");
			info->setAnchorPoint(Point(0.5, 0));
			info->setPosition(Point(520, 410));
			info->setTag(164);
			this->addChild(info, 5);

			auto cancel = MenuItemImage::create(
				"MiniGameResources/pop_enter.png",
				"MiniGameResources/pop_enterpr.png",
				CC_CALLBACK_1(InvestScene::cancelbuy, this));
			cancel->setAnchorPoint(Point(0.5, 0.5));
			cancel->setPosition(Point(520, 450));

			auto canceltext = Menu::create(cancel, NULL);
			canceltext->setAnchorPoint(Point(0.5, 0.5));
			canceltext->setPosition(Point(0, 0));
			canceltext->setTag(165);
			this->addChild(canceltext, 7);
		}
		Singletons::getInstance()->num_K = 0;
	}
	//엘쥐판매
	{
		if (Singletons::getInstance()->ju_L >= 7)
		{
			if (Singletons::getInstance()->num_L == 2)
			{
				Singletons::getInstance()->ju_L = Singletons::getInstance()->ju_L - 7;
				Singletons::getInstance()->money = Singletons::getInstance()->money + (Singletons::getInstance()->lg_1 * 7);
				removeChildByTag(164);
				removeChildByTag(165);
				removeChildByTag(166);
				removeChildByTag(146);
				removeChildByTag(135);
				removeChildByTag(136); removeChildByTag(161);
				removeChildByTag(162);

				removeChildByTag(137);
				removeChildByTag(138);
				removeChildByTag(139);
				removeChildByTag(140);
				removeChildByTag(141);
				removeChildByTag(142);
				removeChildByTag(143);
			}
		}
		else if (Singletons::getInstance()->num_L == 2 && Singletons::getInstance()->ju_L <= 6)
		{
			removeChildByTag(164);
			removeChildByTag(165);
			removeChildByTag(166);
			removeChildByTag(146);
			removeChildByTag(135);
			removeChildByTag(136);
			removeChildByTag(137);
			removeChildByTag(138); removeChildByTag(161);
			removeChildByTag(162);

			removeChildByTag(139);
			removeChildByTag(140);
			removeChildByTag(141);
			removeChildByTag(142);
			removeChildByTag(143);

			Sprite* info = Sprite::create("MiniGameResources/pop_noinvest.png");
			info->setAnchorPoint(Point(0.5, 0));
			info->setPosition(Point(520, 410));
			info->setTag(164);
			this->addChild(info, 5);

			auto cancel = MenuItemImage::create(
				"MiniGameResources/pop_enter.png",
				"MiniGameResources/pop_enterpr.png",
				CC_CALLBACK_1(InvestScene::cancelbuy, this));
			cancel->setAnchorPoint(Point(0.5, 0.5));
			cancel->setPosition(Point(520, 450));

			auto canceltext = Menu::create(cancel, NULL);
			canceltext->setAnchorPoint(Point(0.5, 0.5));
			canceltext->setPosition(Point(0, 0));
			canceltext->setTag(165);
			this->addChild(canceltext, 7);
		}
		Singletons::getInstance()->num_L = 0;
	}
}
void InvestScene::sell_8(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);
	//삼성판매
	{
		if (Singletons::getInstance()->ju_S >= 8)
		{
			if (Singletons::getInstance()->num_S == 2)
			{
				Singletons::getInstance()->ju_S = Singletons::getInstance()->ju_S - 8;
				Singletons::getInstance()->money = Singletons::getInstance()->money + (Singletons::getInstance()->samsung_1 * 8);
				removeChildByTag(164);
				removeChildByTag(165);
				removeChildByTag(166);
				removeChildByTag(146);
				removeChildByTag(135);
				removeChildByTag(136);
				removeChildByTag(137);
				removeChildByTag(138); removeChildByTag(161);
				removeChildByTag(162);

				removeChildByTag(139);
				removeChildByTag(140);
				removeChildByTag(141);
				removeChildByTag(142);
				removeChildByTag(143);
			}
		}
		else if (Singletons::getInstance()->num_S == 2 && Singletons::getInstance()->ju_S <= 7)
		{
			removeChildByTag(164);
			removeChildByTag(165);
			removeChildByTag(166);
			removeChildByTag(146);
			removeChildByTag(135);
			removeChildByTag(136);
			removeChildByTag(137);
			removeChildByTag(138);
			removeChildByTag(139);
			removeChildByTag(140);
			removeChildByTag(141);
			removeChildByTag(142); removeChildByTag(161);
			removeChildByTag(162);

			removeChildByTag(143);

			Sprite* info = Sprite::create("MiniGameResources/pop_noinvest.png");
			info->setAnchorPoint(Point(0.5, 0));
			info->setPosition(Point(520, 410));
			info->setTag(164);
			this->addChild(info, 5);

			auto cancel = MenuItemImage::create(
				"MiniGameResources/pop_enter.png",
				"MiniGameResources/pop_enterpr.png",
				CC_CALLBACK_1(InvestScene::cancelbuy, this));
			cancel->setAnchorPoint(Point(0.5, 0.5));
			cancel->setPosition(Point(520, 450));

			auto canceltext = Menu::create(cancel, NULL);
			canceltext->setAnchorPoint(Point(0.5, 0.5));
			canceltext->setPosition(Point(0, 0));
			canceltext->setTag(165);
			this->addChild(canceltext, 7);
		}
		Singletons::getInstance()->num_S = 0;
	}

	//애플판매
	{
		if (Singletons::getInstance()->ju_A >= 8)
		{
			if (Singletons::getInstance()->num_A == 2)
			{
				Singletons::getInstance()->ju_A = Singletons::getInstance()->ju_A - 8;
				Singletons::getInstance()->money = Singletons::getInstance()->money + (Singletons::getInstance()->apple_1 * 8);
				removeChildByTag(164);
				removeChildByTag(165);
				removeChildByTag(166);
				removeChildByTag(146);
				removeChildByTag(135);
				removeChildByTag(136);
				removeChildByTag(137); removeChildByTag(161);
				removeChildByTag(162);

				removeChildByTag(138);
				removeChildByTag(139);
				removeChildByTag(140);
				removeChildByTag(141);
				removeChildByTag(142);
				removeChildByTag(143);
			}
		}
		else if (Singletons::getInstance()->num_A == 2 && Singletons::getInstance()->ju_A <= 7)
		{
			removeChildByTag(164);
			removeChildByTag(165);
			removeChildByTag(166);
			removeChildByTag(146);
			removeChildByTag(135);
			removeChildByTag(136);
			removeChildByTag(137); removeChildByTag(161);
			removeChildByTag(162);

			removeChildByTag(138);
			removeChildByTag(139);
			removeChildByTag(140);
			removeChildByTag(141);
			removeChildByTag(142);
			removeChildByTag(143);

			Sprite* info = Sprite::create("MiniGameResources/pop_noinvest.png");
			info->setAnchorPoint(Point(0.5, 0));
			info->setPosition(Point(520, 410));
			info->setTag(164);
			this->addChild(info, 5);

			auto cancel = MenuItemImage::create(
				"MiniGameResources/pop_enter.png",
				"MiniGameResources/pop_enterpr.png",
				CC_CALLBACK_1(InvestScene::cancelbuy, this));
			cancel->setAnchorPoint(Point(0.5, 0.5));
			cancel->setPosition(Point(520, 450));

			auto canceltext = Menu::create(cancel, NULL);
			canceltext->setAnchorPoint(Point(0.5, 0.5));
			canceltext->setPosition(Point(0, 0));
			canceltext->setTag(165);
			this->addChild(canceltext, 7);
		}
		Singletons::getInstance()->num_A = 0;
	}

	//하놔판매
	{
		if (Singletons::getInstance()->ju_H >= 8)
		{
			if (Singletons::getInstance()->num_H == 2)
			{
				Singletons::getInstance()->ju_H = Singletons::getInstance()->ju_H - 8;
				Singletons::getInstance()->money = Singletons::getInstance()->money + (Singletons::getInstance()->hanhwa_1 * 8);
				removeChildByTag(164);
				removeChildByTag(165);
				removeChildByTag(166);
				removeChildByTag(146);
				removeChildByTag(135);
				removeChildByTag(136);
				removeChildByTag(137); removeChildByTag(161);
				removeChildByTag(162);

				removeChildByTag(138);
				removeChildByTag(139);
				removeChildByTag(140);
				removeChildByTag(141);
				removeChildByTag(142);
				removeChildByTag(143);
			}
		}
		else if (Singletons::getInstance()->num_H == 2 && Singletons::getInstance()->ju_H <= 7)
		{
			removeChildByTag(164);
			removeChildByTag(165);
			removeChildByTag(166);
			removeChildByTag(146);
			removeChildByTag(135);
			removeChildByTag(136);
			removeChildByTag(137);
			removeChildByTag(138);
			removeChildByTag(139); removeChildByTag(161);
			removeChildByTag(162);

			removeChildByTag(140);
			removeChildByTag(141);
			removeChildByTag(142);
			removeChildByTag(143);

			Sprite* info = Sprite::create("MiniGameResources/pop_noinvest.png");
			info->setAnchorPoint(Point(0.5, 0));
			info->setPosition(Point(520, 410));
			info->setTag(164);
			this->addChild(info, 5);

			auto cancel = MenuItemImage::create(
				"MiniGameResources/pop_enter.png",
				"MiniGameResources/pop_enterpr.png",
				CC_CALLBACK_1(InvestScene::cancelbuy, this));
			cancel->setAnchorPoint(Point(0.5, 0.5));
			cancel->setPosition(Point(520, 450));

			auto canceltext = Menu::create(cancel, NULL);
			canceltext->setAnchorPoint(Point(0.5, 0.5));
			canceltext->setPosition(Point(0, 0));
			canceltext->setTag(165);
			this->addChild(canceltext, 7);
		}
		Singletons::getInstance()->num_H = 0;
	}

	//기아판매
	{
		if (Singletons::getInstance()->ju_K >= 8)
		{
			if (Singletons::getInstance()->num_K == 2)
			{
				Singletons::getInstance()->ju_K = Singletons::getInstance()->ju_K - 8;
				Singletons::getInstance()->money = Singletons::getInstance()->money + (Singletons::getInstance()->kia_1 * 8);
				removeChildByTag(164);
				removeChildByTag(165);
				removeChildByTag(166);
				removeChildByTag(146);
				removeChildByTag(135);
				removeChildByTag(136);
				removeChildByTag(137);
				removeChildByTag(138); removeChildByTag(161);
				removeChildByTag(162);

				removeChildByTag(139);
				removeChildByTag(140);
				removeChildByTag(141);
				removeChildByTag(142);
				removeChildByTag(143);
			}
		}
		else if (Singletons::getInstance()->num_K == 2 && Singletons::getInstance()->ju_K <= 7)
		{
			removeChildByTag(164);
			removeChildByTag(165);
			removeChildByTag(166);
			removeChildByTag(146);
			removeChildByTag(135);
			removeChildByTag(136);
			removeChildByTag(137);
			removeChildByTag(138); removeChildByTag(161);
			removeChildByTag(162);

			removeChildByTag(139);
			removeChildByTag(140);
			removeChildByTag(141);
			removeChildByTag(142);
			removeChildByTag(143);

			Sprite* info = Sprite::create("MiniGameResources/pop_noinvest.png");
			info->setAnchorPoint(Point(0.5, 0));
			info->setPosition(Point(520, 410));
			info->setTag(164);
			this->addChild(info, 5);

			auto cancel = MenuItemImage::create(
				"MiniGameResources/pop_enter.png",
				"MiniGameResources/pop_enterpr.png",
				CC_CALLBACK_1(InvestScene::cancelbuy, this));
			cancel->setAnchorPoint(Point(0.5, 0.5));
			cancel->setPosition(Point(520, 450));

			auto canceltext = Menu::create(cancel, NULL);
			canceltext->setAnchorPoint(Point(0.5, 0.5));
			canceltext->setPosition(Point(0, 0));
			canceltext->setTag(165);
			this->addChild(canceltext, 7);
		}
		Singletons::getInstance()->num_K = 0;
	}
	//엘쥐판매
	{
		if (Singletons::getInstance()->ju_L >= 8)
		{
			if (Singletons::getInstance()->num_L == 2)
			{
				Singletons::getInstance()->ju_L = Singletons::getInstance()->ju_L - 8;
				Singletons::getInstance()->money = Singletons::getInstance()->money + (Singletons::getInstance()->lg_1 * 8);
				removeChildByTag(164);
				removeChildByTag(165);
				removeChildByTag(166);
				removeChildByTag(146);
				removeChildByTag(135);
				removeChildByTag(136); removeChildByTag(161);
				removeChildByTag(162);

				removeChildByTag(137);
				removeChildByTag(138);
				removeChildByTag(139);
				removeChildByTag(140);
				removeChildByTag(141);
				removeChildByTag(142);
				removeChildByTag(143);
			}
		}
		else if (Singletons::getInstance()->num_L == 2 && Singletons::getInstance()->ju_L <= 7)
		{
			removeChildByTag(164);
			removeChildByTag(165);
			removeChildByTag(166);
			removeChildByTag(146);
			removeChildByTag(135);
			removeChildByTag(136);
			removeChildByTag(137); removeChildByTag(161);
			removeChildByTag(162);

			removeChildByTag(138);
			removeChildByTag(139);
			removeChildByTag(140);
			removeChildByTag(141);
			removeChildByTag(142);
			removeChildByTag(143);

			Sprite* info = Sprite::create("MiniGameResources/pop_noinvest.png");
			info->setAnchorPoint(Point(0.5, 0));
			info->setPosition(Point(520, 410));
			info->setTag(164);
			this->addChild(info, 5);

			auto cancel = MenuItemImage::create(
				"MiniGameResources/pop_enter.png",
				"MiniGameResources/pop_enterpr.png",
				CC_CALLBACK_1(InvestScene::cancelbuy, this));
			cancel->setAnchorPoint(Point(0.5, 0.5));
			cancel->setPosition(Point(520, 450));

			auto canceltext = Menu::create(cancel, NULL);
			canceltext->setAnchorPoint(Point(0.5, 0.5));
			canceltext->setPosition(Point(0, 0));
			canceltext->setTag(165);
			this->addChild(canceltext, 7);
		}
		Singletons::getInstance()->num_L = 0;
	}
}
void InvestScene::sell_9(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);
	//삼성판매
	{
		if (Singletons::getInstance()->ju_S >= 9)
		{
			if (Singletons::getInstance()->num_S == 2)
			{
				Singletons::getInstance()->ju_S = Singletons::getInstance()->ju_S - 9;
				Singletons::getInstance()->money = Singletons::getInstance()->money + (Singletons::getInstance()->samsung_1 * 9);
				removeChildByTag(164);
				removeChildByTag(165);
				removeChildByTag(166);
				removeChildByTag(146);
				removeChildByTag(135);
				removeChildByTag(136);
				removeChildByTag(137);
				removeChildByTag(138);
				removeChildByTag(139);
				removeChildByTag(140); removeChildByTag(161);
				removeChildByTag(162);

				removeChildByTag(141);
				removeChildByTag(142);
				removeChildByTag(143);
			}
		}
		else if (Singletons::getInstance()->num_S == 2 && Singletons::getInstance()->ju_S <= 8)
		{
			removeChildByTag(164);
			removeChildByTag(165);
			removeChildByTag(166);
			removeChildByTag(146);
			removeChildByTag(135);
			removeChildByTag(136); removeChildByTag(161);
			removeChildByTag(162);

			removeChildByTag(137);
			removeChildByTag(138);
			removeChildByTag(139);
			removeChildByTag(140);
			removeChildByTag(141);
			removeChildByTag(142);
			removeChildByTag(143);

			Sprite* info = Sprite::create("MiniGameResources/pop_noinvest.png");
			info->setAnchorPoint(Point(0.5, 0));
			info->setPosition(Point(520, 410));
			info->setTag(164);
			this->addChild(info, 5);

			auto cancel = MenuItemImage::create(
				"MiniGameResources/pop_enter.png",
				"MiniGameResources/pop_enterpr.png",
				CC_CALLBACK_1(InvestScene::cancelbuy, this));
			cancel->setAnchorPoint(Point(0.5, 0.5));
			cancel->setPosition(Point(520, 450));

			auto canceltext = Menu::create(cancel, NULL);
			canceltext->setAnchorPoint(Point(0.5, 0.5));
			canceltext->setPosition(Point(0, 0));
			canceltext->setTag(165);
			this->addChild(canceltext, 7);
		}
		Singletons::getInstance()->num_S = 0;
	}

	//애플판매
	{
		if (Singletons::getInstance()->ju_A >= 9)
		{
			if (Singletons::getInstance()->num_A == 2)
			{
				Singletons::getInstance()->ju_A = Singletons::getInstance()->ju_A - 9;
				Singletons::getInstance()->money = Singletons::getInstance()->money + (Singletons::getInstance()->apple_1 * 9);
				removeChildByTag(164);
				removeChildByTag(165);
				removeChildByTag(166);
				removeChildByTag(146);
				removeChildByTag(135);
				removeChildByTag(136);
				removeChildByTag(137); removeChildByTag(161);
				removeChildByTag(162);

				removeChildByTag(138);
				removeChildByTag(139);
				removeChildByTag(140);
				removeChildByTag(141);
				removeChildByTag(142);
				removeChildByTag(143);
			}
		}
		else if (Singletons::getInstance()->num_A == 2 && Singletons::getInstance()->ju_A <= 8)
		{
			removeChildByTag(164);
			removeChildByTag(165);
			removeChildByTag(166);
			removeChildByTag(146);
			removeChildByTag(135); removeChildByTag(161);
			removeChildByTag(162);

			removeChildByTag(136);
			removeChildByTag(137);
			removeChildByTag(138);
			removeChildByTag(139);
			removeChildByTag(140);
			removeChildByTag(141);
			removeChildByTag(142);
			removeChildByTag(143);

			Sprite* info = Sprite::create("MiniGameResources/pop_noinvest.png");
			info->setAnchorPoint(Point(0.5, 0));
			info->setPosition(Point(520, 410));
			info->setTag(164);
			this->addChild(info, 5);

			auto cancel = MenuItemImage::create(
				"MiniGameResources/pop_enter.png",
				"MiniGameResources/pop_enterpr.png",
				CC_CALLBACK_1(InvestScene::cancelbuy, this));
			cancel->setAnchorPoint(Point(0.5, 0.5));
			cancel->setPosition(Point(520, 450));

			auto canceltext = Menu::create(cancel, NULL);
			canceltext->setAnchorPoint(Point(0.5, 0.5));
			canceltext->setPosition(Point(0, 0));
			canceltext->setTag(165);
			this->addChild(canceltext, 7);
		}
		Singletons::getInstance()->num_A = 0;
	}

	//하놔판매
	{
		if (Singletons::getInstance()->ju_H >= 9)
		{
			if (Singletons::getInstance()->num_H == 2)
			{
				Singletons::getInstance()->ju_H = Singletons::getInstance()->ju_H - 9;
				Singletons::getInstance()->money = Singletons::getInstance()->money + (Singletons::getInstance()->hanhwa_1 * 9);
				removeChildByTag(164);
				removeChildByTag(165);
				removeChildByTag(166);
				removeChildByTag(146);
				removeChildByTag(135);
				removeChildByTag(136); removeChildByTag(161);
				removeChildByTag(162);

				removeChildByTag(137);
				removeChildByTag(138);
				removeChildByTag(139);
				removeChildByTag(140);
				removeChildByTag(141);
				removeChildByTag(142);
				removeChildByTag(143);
			}
		}
		else if (Singletons::getInstance()->num_H == 2 && Singletons::getInstance()->ju_H <= 8)
		{
			removeChildByTag(164);
			removeChildByTag(165);
			removeChildByTag(166);
			removeChildByTag(146);
			removeChildByTag(135);
			removeChildByTag(136);
			removeChildByTag(137);
			removeChildByTag(138);
			removeChildByTag(139);
			removeChildByTag(140);
			removeChildByTag(141); removeChildByTag(161);
			removeChildByTag(162);

			removeChildByTag(142);
			removeChildByTag(143);

			Sprite* info = Sprite::create("MiniGameResources/pop_noinvest.png");
			info->setAnchorPoint(Point(0.5, 0));
			info->setPosition(Point(520, 410));
			info->setTag(164);
			this->addChild(info, 5);

			auto cancel = MenuItemImage::create(
				"MiniGameResources/pop_enter.png",
				"MiniGameResources/pop_enterpr.png",
				CC_CALLBACK_1(InvestScene::cancelbuy, this));
			cancel->setAnchorPoint(Point(0.5, 0.5));
			cancel->setPosition(Point(520, 450));

			auto canceltext = Menu::create(cancel, NULL);
			canceltext->setAnchorPoint(Point(0.5, 0.5));
			canceltext->setPosition(Point(0, 0));
			canceltext->setTag(165);
			this->addChild(canceltext, 7);
		}
		Singletons::getInstance()->num_H = 0;
	}

	//기아판매
	{
		if (Singletons::getInstance()->ju_K >= 9)
		{
			if (Singletons::getInstance()->num_K == 2)
			{
				Singletons::getInstance()->ju_K = Singletons::getInstance()->ju_K - 9;
				Singletons::getInstance()->money = Singletons::getInstance()->money + (Singletons::getInstance()->kia_1 * 9);
				removeChildByTag(164);
				removeChildByTag(165);
				removeChildByTag(166);
				removeChildByTag(146);
				removeChildByTag(135);
				removeChildByTag(136);
				removeChildByTag(137);
				removeChildByTag(138); removeChildByTag(161);
				removeChildByTag(162);

				removeChildByTag(139);
				removeChildByTag(140);
				removeChildByTag(141);
				removeChildByTag(142);
				removeChildByTag(143);
			}
		}
		else if (Singletons::getInstance()->num_K == 2 && Singletons::getInstance()->ju_K <= 8)
		{
			removeChildByTag(164);
			removeChildByTag(165);
			removeChildByTag(166);
			removeChildByTag(146);
			removeChildByTag(135);
			removeChildByTag(136);
			removeChildByTag(137);
			removeChildByTag(138); removeChildByTag(161);
			removeChildByTag(162);

			removeChildByTag(139);
			removeChildByTag(140);
			removeChildByTag(141);
			removeChildByTag(142);
			removeChildByTag(143);

			Sprite* info = Sprite::create("MiniGameResources/pop_noinvest.png");
			info->setAnchorPoint(Point(0.5, 0));
			info->setPosition(Point(520, 410));
			info->setTag(164);
			this->addChild(info, 5);

			auto cancel = MenuItemImage::create(
				"MiniGameResources/pop_enter.png",
				"MiniGameResources/pop_enterpr.png",
				CC_CALLBACK_1(InvestScene::cancelbuy, this));
			cancel->setAnchorPoint(Point(0.5, 0.5));
			cancel->setPosition(Point(520, 450));

			auto canceltext = Menu::create(cancel, NULL);
			canceltext->setAnchorPoint(Point(0.5, 0.5));
			canceltext->setPosition(Point(0, 0));
			canceltext->setTag(165);
			this->addChild(canceltext, 7);
		}
		Singletons::getInstance()->num_K = 0;
	}
	//엘쥐판매
	{
		if (Singletons::getInstance()->ju_L >= 9)
		{
			if (Singletons::getInstance()->num_L == 2)
			{
				Singletons::getInstance()->ju_L = Singletons::getInstance()->ju_L - 9;
				Singletons::getInstance()->money = Singletons::getInstance()->money + (Singletons::getInstance()->lg_1 * 9);
				removeChildByTag(164);
				removeChildByTag(165);
				removeChildByTag(166);
				removeChildByTag(146);
				removeChildByTag(135);
				removeChildByTag(136);
				removeChildByTag(137);
				removeChildByTag(138);
				removeChildByTag(139);
				removeChildByTag(140); removeChildByTag(161);
				removeChildByTag(162);

				removeChildByTag(141);
				removeChildByTag(142);
				removeChildByTag(143);
			}
		}
		else if (Singletons::getInstance()->num_L == 2 && Singletons::getInstance()->ju_L <= 8)
		{
			removeChildByTag(164);
			removeChildByTag(165);
			removeChildByTag(166);
			removeChildByTag(146);
			removeChildByTag(135);
			removeChildByTag(136);
			removeChildByTag(137);
			removeChildByTag(138); removeChildByTag(161);
			removeChildByTag(162);

			removeChildByTag(139);
			removeChildByTag(140);
			removeChildByTag(141);
			removeChildByTag(142);
			removeChildByTag(143);

			Sprite* info = Sprite::create("MiniGameResources/pop_noinvest.png");
			info->setAnchorPoint(Point(0.5, 0));
			info->setPosition(Point(520, 410));
			info->setTag(164);
			this->addChild(info, 5);

			auto cancel = MenuItemImage::create(
				"MiniGameResources/pop_enter.png",
				"MiniGameResources/pop_enterpr.png",
				CC_CALLBACK_1(InvestScene::cancelbuy, this));
			cancel->setAnchorPoint(Point(0.5, 0.5));
			cancel->setPosition(Point(520, 450));

			auto canceltext = Menu::create(cancel, NULL);
			canceltext->setAnchorPoint(Point(0.5, 0.5));
			canceltext->setPosition(Point(0, 0));
			canceltext->setTag(165);
			this->addChild(canceltext, 7);
		}
		Singletons::getInstance()->num_L = 0;
	}
}
void InvestScene::sell_10(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);
	//삼성판매
	{
		if (Singletons::getInstance()->ju_S >= 10)
		{
			if (Singletons::getInstance()->num_S == 2)
			{
				Singletons::getInstance()->ju_S = Singletons::getInstance()->ju_S - 10;
				Singletons::getInstance()->money = Singletons::getInstance()->money + (Singletons::getInstance()->samsung_1 * 10);
				removeChildByTag(164);
				removeChildByTag(165);
				removeChildByTag(166);
				removeChildByTag(146);
				removeChildByTag(135);
				removeChildByTag(136);
				removeChildByTag(137); removeChildByTag(161);
				removeChildByTag(162);

				removeChildByTag(138);
				removeChildByTag(139);
				removeChildByTag(140);
				removeChildByTag(141);
				removeChildByTag(142);
				removeChildByTag(143);
			}
		}
		else if (Singletons::getInstance()->num_S == 2 && Singletons::getInstance()->ju_S <= 9)
		{
			removeChildByTag(164);
			removeChildByTag(165);
			removeChildByTag(166);
			removeChildByTag(146);
			removeChildByTag(135); removeChildByTag(161);
			removeChildByTag(162);

			removeChildByTag(137);
			removeChildByTag(138);
			removeChildByTag(139);
			removeChildByTag(140);
			removeChildByTag(141);
			removeChildByTag(142);
			removeChildByTag(143);

			Sprite* info = Sprite::create("MiniGameResources/pop_noinvest.png");
			info->setAnchorPoint(Point(0.5, 0));
			info->setPosition(Point(520, 410));
			info->setTag(164);
			this->addChild(info, 5);

			auto cancel = MenuItemImage::create(
				"MiniGameResources/pop_enter.png",
				"MiniGameResources/pop_enterpr.png",
				CC_CALLBACK_1(InvestScene::cancelbuy, this));
			cancel->setAnchorPoint(Point(0.5, 0.5));
			cancel->setPosition(Point(520, 450));

			auto canceltext = Menu::create(cancel, NULL);
			canceltext->setAnchorPoint(Point(0.5, 0.5));
			canceltext->setPosition(Point(0, 0));
			canceltext->setTag(165);
			this->addChild(canceltext, 7);
		}
		Singletons::getInstance()->num_S = 0;
	}

	//애플판매
	{
		if (Singletons::getInstance()->ju_A >= 10)
		{
			if (Singletons::getInstance()->num_A == 2)
			{
				Singletons::getInstance()->ju_A = Singletons::getInstance()->ju_A - 10;
				Singletons::getInstance()->money = Singletons::getInstance()->money + (Singletons::getInstance()->apple_1 * 10);
				removeChildByTag(164);
				removeChildByTag(165);
				removeChildByTag(166);
				removeChildByTag(146);
				removeChildByTag(135);
				removeChildByTag(136);
				removeChildByTag(137); removeChildByTag(161);
				removeChildByTag(162);

				removeChildByTag(138);
				removeChildByTag(139);
				removeChildByTag(140);
				removeChildByTag(141);
				removeChildByTag(142);
				removeChildByTag(143);
			}
		}
		else if (Singletons::getInstance()->num_A== 2 && Singletons::getInstance()->ju_A <= 9)
		{
			removeChildByTag(164);
			removeChildByTag(165);
			removeChildByTag(166);
			removeChildByTag(146);
			removeChildByTag(135); removeChildByTag(161);
			removeChildByTag(162);

			removeChildByTag(137);
			removeChildByTag(138);
			removeChildByTag(139);
			removeChildByTag(140);
			removeChildByTag(141);
			removeChildByTag(142);
			removeChildByTag(143);

			Sprite* info = Sprite::create("MiniGameResources/pop_noinvest.png");
			info->setAnchorPoint(Point(0.5, 0));
			info->setPosition(Point(520, 410));
			info->setTag(164);
			this->addChild(info, 5);

			auto cancel = MenuItemImage::create(
				"MiniGameResources/pop_enter.png",
				"MiniGameResources/pop_enterpr.png",
				CC_CALLBACK_1(InvestScene::cancelbuy, this));
			cancel->setAnchorPoint(Point(0.5, 0.5));
			cancel->setPosition(Point(520, 450));

			auto canceltext = Menu::create(cancel, NULL);
			canceltext->setAnchorPoint(Point(0.5, 0.5));
			canceltext->setPosition(Point(0, 0));
			canceltext->setTag(165);
			this->addChild(canceltext, 7);
		}
		Singletons::getInstance()->num_A = 0;
	}

	//하놔판매
	{
		if (Singletons::getInstance()->ju_H >= 10)
		{
			if (Singletons::getInstance()->num_H == 2)
			{
				Singletons::getInstance()->ju_H = Singletons::getInstance()->ju_H - 10;
				Singletons::getInstance()->money = Singletons::getInstance()->money + (Singletons::getInstance()->hanhwa_1 * 10);
				removeChildByTag(164);
				removeChildByTag(165);
				removeChildByTag(166);
				removeChildByTag(146);
				removeChildByTag(135); removeChildByTag(161);
				removeChildByTag(162);

				removeChildByTag(136);
				removeChildByTag(137);
				removeChildByTag(138);
				removeChildByTag(139);
				removeChildByTag(140);
				removeChildByTag(141);
				removeChildByTag(142);
				removeChildByTag(143);
			}
		}
		else if (Singletons::getInstance()->num_H == 2 && Singletons::getInstance()->ju_H <= 9)
		{
			removeChildByTag(164);
			removeChildByTag(165);
			removeChildByTag(166);
			removeChildByTag(146);
			removeChildByTag(135);
			removeChildByTag(136);
			removeChildByTag(137);
			removeChildByTag(138); removeChildByTag(161);
			removeChildByTag(162);

			removeChildByTag(139);
			removeChildByTag(140);
			removeChildByTag(141);
			removeChildByTag(142);
			removeChildByTag(143);

			Sprite* info = Sprite::create("MiniGameResources/pop_noinvest.png");
			info->setAnchorPoint(Point(0.5, 0));
			info->setPosition(Point(520, 410));
			info->setTag(164);
			this->addChild(info, 5);

			auto cancel = MenuItemImage::create(
				"MiniGameResources/pop_enter.png",
				"MiniGameResources/pop_enterpr.png",
				CC_CALLBACK_1(InvestScene::cancelbuy, this));
			cancel->setAnchorPoint(Point(0.5, 0.5));
			cancel->setPosition(Point(520, 450));

			auto canceltext = Menu::create(cancel, NULL);
			canceltext->setAnchorPoint(Point(0.5, 0.5));
			canceltext->setPosition(Point(0, 0));
			canceltext->setTag(165);
			this->addChild(canceltext, 7);
		}
		Singletons::getInstance()->num_H = 0;
	}

	//기아판매
	{
		if (Singletons::getInstance()->ju_K >= 10)
		{
			if (Singletons::getInstance()->num_K == 2)
			{
				Singletons::getInstance()->ju_K = Singletons::getInstance()->ju_K - 10;
				Singletons::getInstance()->money = Singletons::getInstance()->money + (Singletons::getInstance()->kia_1 * 10);
				removeChildByTag(164);
				removeChildByTag(165);
				removeChildByTag(166);
				removeChildByTag(146);
				removeChildByTag(135);
				removeChildByTag(136); removeChildByTag(161);
				removeChildByTag(162);

				removeChildByTag(137);
				removeChildByTag(138);
				removeChildByTag(139);
				removeChildByTag(140);
				removeChildByTag(141);
				removeChildByTag(142);
				removeChildByTag(143);
			}
		}
		else if (Singletons::getInstance()->num_K == 2 && Singletons::getInstance()->ju_K <= 9)
		{
			removeChildByTag(164);
			removeChildByTag(165);
			removeChildByTag(166);
			removeChildByTag(146);
			removeChildByTag(135);
			removeChildByTag(136); removeChildByTag(161);
			removeChildByTag(162);

			removeChildByTag(137);
			removeChildByTag(138);
			removeChildByTag(139);
			removeChildByTag(140);
			removeChildByTag(141);
			removeChildByTag(142);
			removeChildByTag(143);

			Sprite* info = Sprite::create("MiniGameResources/pop_noinvest.png");
			info->setAnchorPoint(Point(0.5, 0));
			info->setPosition(Point(520, 410));
			info->setTag(164);
			this->addChild(info, 5);

			auto cancel = MenuItemImage::create(
				"MiniGameResources/pop_enter.png",
				"MiniGameResources/pop_enterpr.png",
				CC_CALLBACK_1(InvestScene::cancelbuy, this));
			cancel->setAnchorPoint(Point(0.5, 0.5));
			cancel->setPosition(Point(520, 450));

			auto canceltext = Menu::create(cancel, NULL);
			canceltext->setAnchorPoint(Point(0.5, 0.5));
			canceltext->setPosition(Point(0, 0));
			canceltext->setTag(165);
			this->addChild(canceltext, 7);
		}
		Singletons::getInstance()->num_K = 0;
	}
	//엘쥐판매
	{
		if (Singletons::getInstance()->ju_L >= 10)
		{
			if (Singletons::getInstance()->num_L == 2)
			{
				Singletons::getInstance()->ju_L = Singletons::getInstance()->ju_L - 10;
				Singletons::getInstance()->money = Singletons::getInstance()->money + (Singletons::getInstance()->lg_1 * 10);
				removeChildByTag(164);
				removeChildByTag(165);
				removeChildByTag(166);
				removeChildByTag(146);
				removeChildByTag(135);
				removeChildByTag(136);
				removeChildByTag(137); removeChildByTag(161);
				removeChildByTag(162);

				removeChildByTag(138);
				removeChildByTag(139);
				removeChildByTag(140);
				removeChildByTag(141);
				removeChildByTag(142);
				removeChildByTag(143);
			}
		}
		else if (Singletons::getInstance()->num_L == 2 && Singletons::getInstance()->ju_L <= 9)
		{
			removeChildByTag(164);
			removeChildByTag(165);
			removeChildByTag(166);
			removeChildByTag(146);
			removeChildByTag(135);
			removeChildByTag(136);
			removeChildByTag(137); removeChildByTag(161);
			removeChildByTag(162);

			removeChildByTag(139);
			removeChildByTag(140);
			removeChildByTag(141);
			removeChildByTag(142);
			removeChildByTag(143);

			Sprite* info = Sprite::create("MiniGameResources/pop_noinvest.png");
			info->setAnchorPoint(Point(0.5, 0));
			info->setPosition(Point(520, 410));
			info->setTag(164);
			this->addChild(info, 5);

			auto cancel = MenuItemImage::create(
				"MiniGameResources/pop_enter.png",
				"MiniGameResources/pop_enterpr.png",
				CC_CALLBACK_1(InvestScene::cancelbuy, this));
			cancel->setAnchorPoint(Point(0.5, 0.5));
			cancel->setPosition(Point(520, 450));

			auto canceltext = Menu::create(cancel, NULL);
			canceltext->setAnchorPoint(Point(0.5, 0.5));
			canceltext->setPosition(Point(0, 0));
			canceltext->setTag(165);
			this->addChild(canceltext, 7);
		}
		Singletons::getInstance()->num_L = 0;
	}
}
//10주이상 구매 불가
void InvestScene::newplay(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);
	Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
	Director::getInstance()->replaceScene(NextDayScene::createScene());
	
}



//bool InvestScene::onTouchBegan(Touch* touch, Event* unused_event)
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
