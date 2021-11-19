#include "Ledger.h"
#include "NextDayScene.h"
#include "SimpleAudioEngine.h"
#include "sinngleton.h"
#include "Percent100.h"
//사운드 할라면 꼭 필요
using namespace CocosDenshion;
USING_NS_CC;

Scene* Ledger::createScene()
{
    auto scene = Scene::create();
    auto layer = Ledger::create();
    scene->addChild(layer);

    return scene;
}

bool Ledger::init()
{

    if ( !Layer::init() )
    {
        return false;
    }

	InitBackGround();
	InitMenu();

    return true;
}
void Ledger::InitBackGround()
{
	auto sprite = Sprite::create("Cor/back_biri4.png");
	sprite->setPosition(Point(512, 384));
	this->addChild(sprite, 0);
}
void Ledger::InitMenu()
{
	// 다음 버튼
	auto textA_item = MenuItemImage::create(
		"Cor/ok_button.png",
		"Cor/ok_buttonpr.png",
		CC_CALLBACK_1(Ledger::story1, this));
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
	WideCharToMultiByte(CP_UTF8, 0, L"호동(학회장): 이번 행사 장부내역입니다.\n이번 행사는 학회비에서 얼마를 사용하였고....", -1, MyString, 200, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "Cor/ABC.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(729);
	this->addChild(name, 3);
}
void Ledger::story1(Ref * pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);
	removeChildByTag(709);
	removeChildByTag(729);

	char MyString[100];
	WideCharToMultiByte(CP_UTF8, 0, L"호동: ...이상으로 학회비 사용내역이었습니다.", -1, MyString, 100, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "Cor/ABC.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(730);
	this->addChild(name, 3);

	auto textA_item = MenuItemImage::create(
		"Cor/ok_button.png",
		"Cor/ok_buttonpr.png",
		CC_CALLBACK_1(Ledger::story1_2, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(710);
	this->addChild(text, 5);
}
void Ledger::story1_2(Ref * pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);
	removeChildByTag(710);
	removeChildByTag(730);
	removeChildByTag(701);

	Sprite* mainchr = Sprite::create("Cor/people1.png");
	mainchr->setAnchorPoint(Point(0.5, 0));
	mainchr->setScale(1.5);
	mainchr->setPosition(Point(820, 180));
	mainchr->setTag(702);
	this->addChild(mainchr, 1);

	char MyString[100];
	WideCharToMultiByte(CP_UTF8, 0, L"관중: (짝짝짝짝짝짝짝)", -1, MyString, 100, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "Cor/ABC.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(731);
	this->addChild(name, 3);

	auto textA_item = MenuItemImage::create(
		"Cor/ok_button.png",
		"Cor/ok_buttonpr.png",
		CC_CALLBACK_1(Ledger::story1_3, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(711);
	this->addChild(text, 5);
}
void Ledger::story1_3(Ref * pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);
	removeChildByTag(731);
	removeChildByTag(711);
	removeChildByTag(702);

	//메인캐릭터
	Sprite* mainchr = Sprite::create("Cor/main_char.png");
	mainchr->setAnchorPoint(Point(0.5, 0));
	mainchr->setPosition(Point(120, 80));
	mainchr->setTag(701);
	this->addChild(mainchr, 1);

	char MyString[200];
	WideCharToMultiByte(CP_UTF8, 0, L"호동: (그리고 나는 이번행사로 한 몫 크게 챙길 수 있었지. 크큭..멍청이들)", -1, MyString, 200, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "Cor/ABC.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(732);
	this->addChild(name, 3);

	auto textA_item = MenuItemImage::create(
		"Cor/ok_button.png",
		"Cor/ok_buttonpr.png",
		CC_CALLBACK_1(Ledger::story1_4, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(712);
	this->addChild(text, 5);
}
void Ledger::story1_4(Ref * pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);
	removeChildByTag(732);
	removeChildByTag(712);

	char MyString[100];
	WideCharToMultiByte(CP_UTF8, 0, L"(돈을 획득하였습니다.)\n\n(위험도가 40 증가하였습니다.)", -1, MyString, 100, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "Cor/ABC.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(733);
	this->addChild(name, 3);

	auto textA_item = MenuItemImage::create(
		"Cor/ok_button.png",
		"Cor/ok_buttonpr.png",
		CC_CALLBACK_1(Ledger::story1_5, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(713);
	this->addChild(text, 5);
	int arr[10] = { 1000000, 2000000, 3000000, 4000000, 5000000,6000000,7000000,8000000,9000000,10000000 };
	srand((double)time(NULL));

	int random = rand() % 10;
	Singletons::getInstance()->moneyget = arr[random];

	Singletons::getInstance()->money = Singletons::getInstance()->money + Singletons::getInstance()->moneyget;
	Singletons::getInstance()->Danger = Singletons::getInstance()->Danger + 40;

}
void Ledger::story1_5(Ref * pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);
	removeChildByTag(733);
	removeChildByTag(713);
	removeChildByTag(701);
	removeChildByTag(702);

	// 소지금 5만원 증가식 삽입
	if (Singletons::getInstance()->Danger >= 100)
	{
		Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
		Director::getInstance()->replaceScene(Percent100::createScene());
	}
	if (Singletons::getInstance()->Danger <= 99)
	{
		Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
		Director::getInstance()->replaceScene(NextDayScene::createScene()); // NextDay씬으로 변경
	}
}