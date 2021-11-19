#include "MT_L4.h"
#include "EndScene.h"
#include "SimpleAudioEngine.h"
#include "sinngleton.h"
#include "NextDayScene.h"
#include "Percent100.h"
//사운드 할라면 꼭 필요
using namespace CocosDenshion;
USING_NS_CC;

Scene* MT_L4::createScene()
{
	auto scene = Scene::create();
	auto layer = MT_L4::create();
	scene->addChild(layer);

	return scene;
}

bool MT_L4::init()
{

	if (!Layer::init())
	{
		return false;
	}

	InitBackGround();
	InitMenu();

	//배경음악
	SimpleAudioEngine::getInstance()->playBackgroundMusic("sound/1975.mp3", true);

	return true;
}
void MT_L4::InitBackGround()
{
	auto sprite = Sprite::create("Cor/back_biri4.png");
	sprite->setPosition(Point(512, 384));
	this->addChild(sprite, 0);
}
void MT_L4::InitMenu()
{
	// 다음 버튼
	auto textA_item = MenuItemImage::create(
		"Cor/ok_button.png",
		"Cor/ok_buttonpr.png",
		CC_CALLBACK_1(MT_L4::story1, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(709);
	this->addChild(text, 5);

	//메인캐릭터
	Sprite* mainchr = Sprite::create("Cor/main_char.png");
	mainchr->setAnchorPoint(Point(0.5, 0));
	mainchr->setPosition(Point(120, 80));
	mainchr->setTag(701);
	this->addChild(mainchr, 1);

	//텍스트 창
	auto sprite = Sprite::create("Cor/UI_Textlblack.png");
	sprite->setAnchorPoint(Point(0.5, 0.5));
	sprite->setPosition(Point(510, 100));
	sprite->setTag(700);
	this->addChild(sprite, 2);

	// 캐릭터 대사
	char MyString[200];
	WideCharToMultiByte(CP_UTF8, 0, L"호동: 학우분들! 현재 회비가 부족해 행사 진행에 문제가 있습니다!", -1, MyString, 200, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "Cor/ABC.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(729);
	this->addChild(name, 3);
}
void MT_L4::story1(Ref * pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);

	removeChildByTag(709);
	removeChildByTag(729);

	char MyString[200];
	WideCharToMultiByte(CP_UTF8, 0, L"호동: 지금부터 저에게 한사람당 만원씩 내주시길 바랍니다!", -1, MyString, 200, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "Cor/ABC.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(730);
	this->addChild(name, 3);

	auto textA_item = MenuItemImage::create(
		"Cor/ok_button.png",
		"Cor/ok_buttonpr.png",
		CC_CALLBACK_1(MT_L4::story1_2, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(710);
	this->addChild(text, 5);
}
void MT_L4::story1_2(Ref * pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);

	removeChildByTag(710);
	removeChildByTag(730);

	char MyString[100];
	WideCharToMultiByte(CP_UTF8, 0, L"호동: (흐흐흐. 바보들~)", -1, MyString, 100, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "Cor/ABC.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(731);
	this->addChild(name, 3);

	auto textA_item = MenuItemImage::create(
		"Cor/ok_button.png",
		"Cor/ok_buttonpr.png",
		CC_CALLBACK_1(MT_L4::story1_3, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(711);
	this->addChild(text, 5);
}
void MT_L4::story1_3(Ref * pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);

	removeChildByTag(731);
	removeChildByTag(711);

	char MyString[200];
	WideCharToMultiByte(CP_UTF8, 0, L"10만원을 획득하였습니다.\n위험도가 40증가하였습니다.", -1, MyString, 200, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "Cor/ABC.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(732);
	this->addChild(name, 3);

	auto textA_item = MenuItemImage::create(
		"Cor/ok_button.png",
		"Cor/ok_buttonpr.png",
		CC_CALLBACK_1(MT_L4::story1_4, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(712);
	this->addChild(text, 5);

	int arr[10] = { 1000000, 2000000, 3000000, 4000000, 5000000,6000000,7000000,8000000,9000000,10000000 };
	srand((double)time(NULL));

	int random = rand() % 10;
	Singletons::getInstance()->moneyget = arr[random];

	Singletons::getInstance()->money = Singletons::getInstance()->money + Singletons::getInstance()->moneyget;
	Singletons::getInstance()->Danger = Singletons::getInstance()->Danger + 40;

}
void MT_L4::story1_4(Ref * pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);

	removeChildByTag(732);
	removeChildByTag(712);
	removeChildByTag(701);

	// 소지금 10만원 증가식 삽입

	if (Singletons::getInstance()->month == 3 && Singletons::getInstance()->day == 15)
	{
		Singletons::getInstance()->day = Singletons::getInstance()->day + 2;
		if (Singletons::getInstance()->Danger >= 100)
		{
			Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
			Director::getInstance()->replaceScene(Percent100::createScene());
		}
		if (Singletons::getInstance()->Danger <= 99)
		{
			Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
			Director::getInstance()->replaceScene(NextDayScene::createScene());
		}
	}
	if (Singletons::getInstance()->month == 6 && Singletons::getInstance()->day == 23)
	{
		Singletons::getInstance()->day = Singletons::getInstance()->day + 3;
		if (Singletons::getInstance()->Danger >= 100)
		{
			Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
			Director::getInstance()->replaceScene(Percent100::createScene());
		}
		if (Singletons::getInstance()->Danger <= 99)
		{
			Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
			Director::getInstance()->replaceScene(NextDayScene::createScene());
		}
	}
	if (Singletons::getInstance()->month == 7 && Singletons::getInstance()->day == 2)
	{
		Singletons::getInstance()->day = Singletons::getInstance()->day + 1;
		if (Singletons::getInstance()->Danger >= 100)
		{
			Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
			Director::getInstance()->replaceScene(Percent100::createScene());
		}
		if (Singletons::getInstance()->Danger <= 99)
		{
			Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
			Director::getInstance()->replaceScene(NextDayScene::createScene());
		}
	}

	if (Singletons::getInstance()->month == 8 && Singletons::getInstance()->day == 10)
	{
		Singletons::getInstance()->day = Singletons::getInstance()->day + 1;
		if (Singletons::getInstance()->Danger >= 100)
		{
			Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
			Director::getInstance()->replaceScene(Percent100::createScene());
		}
		if (Singletons::getInstance()->Danger <= 99)
		{
			Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
			Director::getInstance()->replaceScene(NextDayScene::createScene());
		}
	}
	if (Singletons::getInstance()->month == 9 && Singletons::getInstance()->day == 29)
	{
		Singletons::getInstance()->day = Singletons::getInstance()->day + 1;
		if (Singletons::getInstance()->Danger >= 100)
		{
			Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
			Director::getInstance()->replaceScene(Percent100::createScene());
		}
		if (Singletons::getInstance()->Danger <= 99)
		{
			Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
			Director::getInstance()->replaceScene(NextDayScene::createScene());
		}
	}

	if (Singletons::getInstance()->month == 10 && Singletons::getInstance()->day == 23)
	{
		Singletons::getInstance()->day = Singletons::getInstance()->day + 2;
		if (Singletons::getInstance()->Danger >= 100)
		{
			Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
			Director::getInstance()->replaceScene(Percent100::createScene());
		}
		if (Singletons::getInstance()->Danger <= 99)
		{
			Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
			Director::getInstance()->replaceScene(NextDayScene::createScene());
		}
	}

	if (Singletons::getInstance()->month == 11 && Singletons::getInstance()->day == 2)
	{
		Singletons::getInstance()->day = Singletons::getInstance()->day + 2;
		if (Singletons::getInstance()->Danger >= 100)
		{
			Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
			Director::getInstance()->replaceScene(Percent100::createScene());
		}
		if (Singletons::getInstance()->Danger <= 99)
		{
			Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
			Director::getInstance()->replaceScene(NextDayScene::createScene());
		}
	}
}