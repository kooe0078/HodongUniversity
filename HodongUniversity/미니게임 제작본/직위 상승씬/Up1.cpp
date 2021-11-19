#include "Up1.h"
#include "SimpleAudioEngine.h"

//사운드 할라면 꼭 필요
using namespace CocosDenshion;
USING_NS_CC;

Scene* Up1::createScene()
{
	auto scene = Scene::create();
	auto layer = Up1::create();
	scene->addChild(layer);

	return scene;
}

bool Up1::init()
{

	if (!Layer::init())
	{
		return false;
	}

	InitBackGround();
	InitMenu();

	//배경음악
	//SimpleAudioEngine::getInstance()->playBackgroundMusic("MiniGameResources/MainBackSound.mp3", true);

	return true;
}
void Up1::InitBackGround()
{
	auto sprite = Sprite::create("LVUP/StuduntUnion.png");
	sprite->setPosition(Point(512, 384));
	this->addChild(sprite, 0);
}
void Up1::InitMenu()
{
	// 다음 버튼
	auto textA_item = MenuItemImage::create(
		"LVUP/ok_button.png",
		"LVUP/ok_buttonpr.png",
		CC_CALLBACK_1(Up1::story1, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(709);
	this->addChild(text, 5);

	// 회장
	Sprite* mainchr = Sprite::create("LVUP/student_chara2.png");
	mainchr->setAnchorPoint(Point(0.5, 0));
	mainchr->setPosition(Point(820, 10));
	mainchr->setTag(701);
	this->addChild(mainchr, 1);

	//텍스트 창
	auto sprite = Sprite::create("LVUP/UI_Textlblack.png");
	sprite->setAnchorPoint(Point(0.5, 0.5));
	sprite->setPosition(Point(510, 100));
	sprite->setTag(700);
	this->addChild(sprite, 2);

	// 캐릭터 대사
	char MyString[200];
	WideCharToMultiByte(CP_UTF8, 0, L"공유기 : 그럼 지금부터 과대를 뽑겠습니다.\n희망하는 사람은 앞으로 나와주세요.", -1, MyString, 200, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "LVUP/ABC.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(729);
	this->addChild(name, 3);
}
void Up1::story1(Ref * pSender)
{
	removeChildByTag(709);
	removeChildByTag(729);

	// 메인 캐릭터
	Sprite* mainchr = Sprite::create("LVUP/main_char.png");
	mainchr->setAnchorPoint(Point(0.5, 0));
	mainchr->setPosition(Point(120, 80));
	mainchr->setTag(702);
	this->addChild(mainchr, 1);

	char MyString[100];
	WideCharToMultiByte(CP_UTF8, 0, L"(스윽...)", -1, MyString, 100, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "LVUP/ABC.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(730);
	this->addChild(name, 3);

	auto textA_item = MenuItemImage::create(
		"LVUP/ok_button.png",
		"LVUP/ok_buttonpr.png",
		CC_CALLBACK_1(Up1::story1_2, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(710);
	this->addChild(text, 5);
}
void Up1::story1_2(Ref * pSender)
{
	removeChildByTag(710);
	removeChildByTag(730);

	char MyString[100];
	WideCharToMultiByte(CP_UTF8, 0, L"공유기 : 자기소개 부탁해요~", -1, MyString, 100, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "LVUP/ABC.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(731);
	this->addChild(name, 3);

	auto textA_item = MenuItemImage::create(
		"LVUP/ok_button.png",
		"LVUP/ok_buttonpr.png",
		CC_CALLBACK_1(Up1::story1_3, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(711);
	this->addChild(text, 5);
}
void Up1::story1_3(Ref * pSender)
{
	removeChildByTag(731);
	removeChildByTag(711);

	char MyString[200];
	WideCharToMultiByte(CP_UTF8, 0, L"호동 : 이번에 과대로 출마하게 된 호동이라고 합니다. 잘 부탁드립니다!", -1, MyString, 200, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "LVUP/ABC.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(732);
	this->addChild(name, 3);

	auto textA_item = MenuItemImage::create(
		"LVUP/ok_button.png",
		"LVUP/ok_buttonpr.png",
		CC_CALLBACK_1(Up1::story1_4, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(712);
	this->addChild(text, 5);
}
void Up1::story1_4(Ref * pSender)
{
	removeChildByTag(732);
	removeChildByTag(712);
	
	char MyString[400];
	WideCharToMultiByte(CP_UTF8, 0, L"공유기 : 단독 출마인가요?  그렇다면 호 동 학생이 과대가 되었습니다!\n모두 축하해주세요.", -1, MyString, 400, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "LVUP/ABC.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(733);
	this->addChild(name, 3);

	auto textA_item = MenuItemImage::create(
		"LVUP/ok_button.png",
		"LVUP/ok_buttonpr.png",
		CC_CALLBACK_1(Up1::story1_5, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(713);
	this->addChild(text, 5);
}
void Up1::story1_5(Ref * pSender)
{
	removeChildByTag(733);
	removeChildByTag(713);
	removeChildByTag(701);

	// 관중
	Sprite* mainchr = Sprite::create("LVUP/people1.png");
	mainchr->setAnchorPoint(Point(0.5, 0));
	mainchr->setScale(1.5);
	mainchr->setPosition(Point(820, 180));
	mainchr->setTag(703);
	this->addChild(mainchr, 1);

	char MyString[100];
	WideCharToMultiByte(CP_UTF8, 0, L"(짝짝짝짝짝)", -1, MyString, 100, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "LVUP/ABC.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(734);
	this->addChild(name, 3);

	auto textA_item = MenuItemImage::create(
		"LVUP/ok_button.png",
		"LVUP/ok_buttonpr.png",
		CC_CALLBACK_1(Up1::story1_6, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(714);
	this->addChild(text, 5);
}
void Up1::story1_6(Ref * pSender)
{
	removeChildByTag(734);
	removeChildByTag(714);

	char MyString[200];
	WideCharToMultiByte(CP_UTF8, 0, L"호동 : 열심히 하겠습니다. 잘 부탁드립니다!", -1, MyString, 200, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "LVUP/ABC.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(735);
	this->addChild(name, 3);

	auto textA_item = MenuItemImage::create(
		"LVUP/ok_button.png",
		"LVUP/ok_buttonpr.png",
		CC_CALLBACK_1(Up1::story1_7, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(715);
	this->addChild(text, 5);
}
void Up1::story1_7(Ref * pSender)
{
	removeChildByTag(735);
	removeChildByTag(715);

	char MyString[200];
	WideCharToMultiByte(CP_UTF8, 0, L"(호동은 과대가 되었다.)", -1, MyString, 200, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "LVUP/ABC.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(736);
	this->addChild(name, 3);

	auto textA_item = MenuItemImage::create(
		"LVUP/ok_button.png",
		"LVUP/ok_buttonpr.png",
		CC_CALLBACK_1(Up1::story1_8, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(716);
	this->addChild(text, 5);
}
void Up1::story1_8(Ref * pSender)
{
	removeChildByTag(736);
	removeChildByTag(716);
	removeChildByTag(702);
	removeChildByTag(703);

	// 학생회실 이동 코드로 변경
	Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
	Director::getInstance()->replaceScene(Up1::createScene());
}

