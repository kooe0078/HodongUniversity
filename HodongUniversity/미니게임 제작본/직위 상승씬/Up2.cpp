#include "Up2.h"
#include "SimpleAudioEngine.h"

//사운드 할라면 꼭 필요
using namespace CocosDenshion;
USING_NS_CC;

Scene* Up2::createScene()
{
	auto scene = Scene::create();
	auto layer = Up2::create();
	scene->addChild(layer);

	return scene;
}

bool Up2::init()
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
void Up2::InitBackGround()
{
	auto sprite = Sprite::create("LVUP/StuduntUnion.png");
	sprite->setPosition(Point(512, 384));
	this->addChild(sprite, 0);
}
void Up2::InitMenu()
{
	// 다음 버튼
	auto textA_item = MenuItemImage::create(
		"LVUP/ok_button.png",
		"LVUP/ok_buttonpr.png",
		CC_CALLBACK_1(Up2::story1, this));
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
	WideCharToMultiByte(CP_UTF8, 0, L"공유기 : 호동이 요즘 잘나가~ ", -1, MyString, 200, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "LVUP/ABC.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(729);
	this->addChild(name, 3);
}
void Up2::story1(Ref * pSender)
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
	WideCharToMultiByte(CP_UTF8, 0, L"호동 : 하하... 너무 띄워주지 마세요~", -1, MyString, 100, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "LVUP/ABC.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(730);
	this->addChild(name, 3);

	auto textA_item = MenuItemImage::create(
		"LVUP/ok_button.png",
		"LVUP/ok_buttonpr.png",
		CC_CALLBACK_1(Up2::story1_2, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(710);
	this->addChild(text, 5);
}
void Up2::story1_2(Ref * pSender)
{
	removeChildByTag(710);
	removeChildByTag(730);

	char MyString[100];
	WideCharToMultiByte(CP_UTF8, 0, L"공유기 : 학생회에 총무 자리가 비는데 한번 해볼래? 내가 추천해줄게~", -1, MyString, 100, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "LVUP/ABC.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(731);
	this->addChild(name, 3);

	auto textA_item = MenuItemImage::create(
		"LVUP/ok_button.png",
		"LVUP/ok_buttonpr.png",
		CC_CALLBACK_1(Up2::story1_3, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(711);
	this->addChild(text, 5);
}
void Up2::story1_3(Ref * pSender)
{
	removeChildByTag(731);
	removeChildByTag(711);

	char MyString[200];
	WideCharToMultiByte(CP_UTF8, 0, L"호동 : 정말요? 저 하고싶어요! 하게 해주세요!!", -1, MyString, 200, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "LVUP/ABC.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(732);
	this->addChild(name, 3);

	auto textA_item = MenuItemImage::create(
		"LVUP/ok_button.png",
		"LVUP/ok_buttonpr.png",
		CC_CALLBACK_1(Up2::story1_4, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(712);
	this->addChild(text, 5);
}
void Up2::story1_4(Ref * pSender)
{
	removeChildByTag(732);
	removeChildByTag(712);

	char MyString[400];
	WideCharToMultiByte(CP_UTF8, 0, L"공유기 : 열정적이네. 그래~ 추천해줄게!", -1, MyString, 400, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "LVUP/ABC.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(733);
	this->addChild(name, 3);

	auto textA_item = MenuItemImage::create(
		"LVUP/ok_button.png",
		"LVUP/ok_buttonpr.png",
		CC_CALLBACK_1(Up2::story1_5, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(713);
	this->addChild(text, 5);
}
void Up2::story1_5(Ref * pSender)
{
	removeChildByTag(733);
	removeChildByTag(713);

	char MyString[100];
	WideCharToMultiByte(CP_UTF8, 0, L"호동 : 감사합니다! 열심히 하겠습니다!!", -1, MyString, 100, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "LVUP/ABC.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(734);
	this->addChild(name, 3);

	auto textA_item = MenuItemImage::create(
		"LVUP/ok_button.png",
		"LVUP/ok_buttonpr.png",
		CC_CALLBACK_1(Up2::story1_6, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(714);
	this->addChild(text, 5);
}
void Up2::story1_6(Ref * pSender)
{
	removeChildByTag(734);
	removeChildByTag(714);

	char MyString[200];
	WideCharToMultiByte(CP_UTF8, 0, L"(호동은 총무가 되었다.)", -1, MyString, 200, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "LVUP/ABC.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(735);
	this->addChild(name, 3);

	auto textA_item = MenuItemImage::create(
		"LVUP/ok_button.png",
		"LVUP/ok_buttonpr.png",
		CC_CALLBACK_1(Up2::story1_7, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(715);
	this->addChild(text, 5);
}
void Up2::story1_7(Ref * pSender)
{
	removeChildByTag(736);
	removeChildByTag(716);
	removeChildByTag(702);
	removeChildByTag(701);

	// 학생회실 이동 코드로 변경
	Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
	Director::getInstance()->replaceScene(Up2::createScene());
}

