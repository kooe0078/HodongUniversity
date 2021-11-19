#include "MT_L1.h"
#include "EndScene.h"
#include "SimpleAudioEngine.h"

//사운드 할라면 꼭 필요
using namespace CocosDenshion;
USING_NS_CC;

Scene* MT_L1::createScene()
{
    auto scene = Scene::create();
    auto layer = MT_L1::create();
    scene->addChild(layer);

    return scene;
}

bool MT_L1::init()
{

    if ( !Layer::init() )
    {
        return false;
    }

	InitBackGround();
	InitMenu();

	//배경음악
	//SimpleAudioEngine::getInstance()->playBackgroundMusic("MiniGameResources/MainBackSound.mp3", true);
	
    return true;
}
void MT_L1::InitBackGround()
{
	auto sprite = Sprite::create("Cor/back_3.png");
	sprite->setPosition(Point(512, 384));
	this->addChild(sprite, 0);
}
void MT_L1::InitMenu()
{
	// 다음 버튼
	auto textA_item = MenuItemImage::create(
		"Cor/ok_button.png",
		"Cor/ok_buttonpr.png",
		CC_CALLBACK_1(MT_L1::story1, this));
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
	WideCharToMultiByte(CP_UTF8, 0, L"호동: 이번에 받은 예산이 이거니까...", -1, MyString, 200, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "Cor/ABC.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(729);
	this->addChild(name, 3);
}
void MT_L1::story1(Ref * pSender)
{
	removeChildByTag(709);
	removeChildByTag(729);

	char MyString[100];
	WideCharToMultiByte(CP_UTF8, 0, L"호동: 이거빼고 저거빼고 하면....", -1, MyString, 100, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "Cor/ABC.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(730);
	this->addChild(name, 3);

	auto textA_item = MenuItemImage::create(
		"Cor/ok_button.png",
		"Cor/ok_buttonpr.png",
		CC_CALLBACK_1(MT_L1::story1_2, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(710);
	this->addChild(text, 5);
}
void MT_L1::story1_2(Ref * pSender)
{
	removeChildByTag(710);
	removeChildByTag(730);

	char MyString[100];
	WideCharToMultiByte(CP_UTF8, 0, L"호동: 요정도는 떼어먹어도 되겠지? 후후...", -1, MyString, 100, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "Cor/ABC.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(731);
	this->addChild(name, 3);

	auto textA_item = MenuItemImage::create(
		"Cor/ok_button.png",
		"Cor/ok_buttonpr.png",
		CC_CALLBACK_1(MT_L1::story1_3, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(711);
	this->addChild(text, 5);
}
void MT_L1::story1_3(Ref * pSender)
{
	removeChildByTag(731);
	removeChildByTag(711);

	char MyString[200];
	WideCharToMultiByte(CP_UTF8, 0, L"10만원을 획득하였습니다.\n위험도가 10증가하였습니다.", -1, MyString, 200, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "Cor/ABC.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(732);
	this->addChild(name, 3);

	auto textA_item = MenuItemImage::create(
		"Cor/ok_button.png",
		"Cor/ok_buttonpr.png",
		CC_CALLBACK_1(MT_L1::story1_4, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(712);
	this->addChild(text, 5);
}
void MT_L1::story1_4(Ref * pSender)
{
	removeChildByTag(732);
	removeChildByTag(712);
	removeChildByTag(701);

	// 소지금 10만원 증가식 삽입

	Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
	Director::getInstance()->replaceScene(MT_L1::createScene()); // NextDay씬으로 변경
}