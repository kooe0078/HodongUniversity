#include "Up4.h"
#include "SimpleAudioEngine.h"

//사운드 할라면 꼭 필요
using namespace CocosDenshion;
USING_NS_CC;

Scene* Up4::createScene()
{
	auto scene = Scene::create();
	auto layer = Up4::create();
	scene->addChild(layer);

	return scene;
}

bool Up4::init()
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
void Up4::InitBackGround()
{
	auto sprite = Sprite::create("LVUP/StuduntUnion.png");
	sprite->setPosition(Point(512, 384));
	sprite->setTag(600);
	this->addChild(sprite, 0);
}
void Up4::InitMenu()
{
	// 다음 버튼
	auto textA_item = MenuItemImage::create(
		"LVUP/ok_button.png",
		"LVUP/ok_buttonpr.png",
		CC_CALLBACK_1(Up4::story1, this));
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
	char MyString[400];
	WideCharToMultiByte(CP_UTF8, 0, L"공유기 : 호동아! 네가 학생회에서 정말 열심히한다는 소리를 들었다. \n이번에는 학생회장에 출마해 보는 것이 어떻겠니?", -1, MyString, 400, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "LVUP/ABC.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(729);
	this->addChild(name, 3);
}
void Up4::story1(Ref * pSender)
{
	removeChildByTag(709);
	removeChildByTag(729);

	// 김창룡
	Sprite* mainchr = Sprite::create("LVUP/inside_chara1.png");
	mainchr->setAnchorPoint(Point(0.5, 0));
	mainchr->setPosition(Point(620, 10));
	mainchr->setTag(702);
	this->addChild(mainchr, 1);

	char MyString[400];
	WideCharToMultiByte(CP_UTF8, 0, L"김창룡 : 맞아. 나도 이젠 졸업반이라 학생회장에는 네가 어울릴거라 생각해.", -1, MyString, 400, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "LVUP/ABC.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(730);
	this->addChild(name, 3);

	auto textA_item = MenuItemImage::create(
		"LVUP/ok_button.png",
		"LVUP/ok_buttonpr.png",
		CC_CALLBACK_1(Up4::story1_2, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(710);
	this->addChild(text, 5);
}
void Up4::story1_2(Ref * pSender)
{
	removeChildByTag(710);
	removeChildByTag(730);

	// 메인 캐릭터
	Sprite* mainchr = Sprite::create("LVUP/main_char.png");
	mainchr->setAnchorPoint(Point(0.5, 0));
	mainchr->setPosition(Point(120, 80));
	mainchr->setTag(703);
	this->addChild(mainchr, 1);

	char MyString[200];
	WideCharToMultiByte(CP_UTF8, 0, L"호동 : 정말요? 감사합니다! 학생회장이 되도록 노력해볼게요!", -1, MyString, 200, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "LVUP/ABC.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(731);
	this->addChild(name, 3);

	auto textA_item = MenuItemImage::create(
		"LVUP/ok_button.png",
		"LVUP/ok_buttonpr.png",
		CC_CALLBACK_1(Up4::story1_3, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(711);
	this->addChild(text, 5);
}
void Up4::story1_3(Ref * pSender)
{
	removeChildByTag(731);
	removeChildByTag(711);
	removeChildByTag(701);
	removeChildByTag(702);
	removeChildByTag(703);
	removeChildByTag(600);

	char MyString[200];
	WideCharToMultiByte(CP_UTF8, 0, L".....", -1, MyString, 200, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "LVUP/ABC.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(732);
	this->addChild(name, 3);

	auto textA_item = MenuItemImage::create(
		"LVUP/ok_button.png",
		"LVUP/ok_buttonpr.png",
		CC_CALLBACK_1(Up4::story1_4, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(712);
	this->addChild(text, 5);
}
void Up4::story1_4(Ref * pSender)
{
	removeChildByTag(732);
	removeChildByTag(712);

	auto sprite = Sprite::create("LVUP/vote_back.png");
	sprite->setPosition(Point(512, 384));
	sprite->setTag(601);
	this->addChild(sprite, 0);

	// 임원
	Sprite* mainchr = Sprite::create("LVUP/student_chara.png");
	mainchr->setAnchorPoint(Point(0.5, 0));
	mainchr->setPosition(Point(820, 10));
	mainchr->setTag(704);
	this->addChild(mainchr, 1);

	char MyString[400];
	WideCharToMultiByte(CP_UTF8, 0, L"임원 : 그럼 지금부터 학생회 선출투표를 시작하겠습니다.", -1, MyString, 400, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "LVUP/ABC.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(733);
	this->addChild(name, 3);

	auto textA_item = MenuItemImage::create(
		"LVUP/ok_button.png",
		"LVUP/ok_buttonpr.png",
		CC_CALLBACK_1(Up4::story1_5, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(713);
	this->addChild(text, 5);
}
void Up4::story1_5(Ref * pSender)
{
	removeChildByTag(733);
	removeChildByTag(713);

	char MyString[100];
	WideCharToMultiByte(CP_UTF8, 0, L".....", -1, MyString, 100, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "LVUP/ABC.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(734);
	this->addChild(name, 3);

	auto textA_item = MenuItemImage::create(
		"LVUP/ok_button.png",
		"LVUP/ok_buttonpr.png",
		CC_CALLBACK_1(Up4::story1_6, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(714);
	this->addChild(text, 5);
}
void Up4::story1_6(Ref * pSender)
{
	removeChildByTag(734);
	removeChildByTag(714);

	char MyString[200];
	WideCharToMultiByte(CP_UTF8, 0, L"임원 : 이번 학생회장은 호동 학생으로 선정 되었습니다. 축하해 주세요!", -1, MyString, 200, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "LVUP/ABC.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(735);
	this->addChild(name, 3);

	auto textA_item = MenuItemImage::create(
		"LVUP/ok_button.png",
		"LVUP/ok_buttonpr.png",
		CC_CALLBACK_1(Up4::story1_7, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(715);
	this->addChild(text, 5);
}
void Up4::story1_7(Ref * pSender)
{
	removeChildByTag(735);
	removeChildByTag(715);
	removeChildByTag(704);

	// 메인 캐릭터
	Sprite* mainchr = Sprite::create("LVUP/main_char.png");
	mainchr->setAnchorPoint(Point(0.5, 0));
	mainchr->setPosition(Point(120, 80));
	mainchr->setTag(705);
	this->addChild(mainchr, 1);

	char MyString[200];
	WideCharToMultiByte(CP_UTF8, 0, L"호동 : 감사합니다. 지금까지보다 더 열심히 하겠습니다!", -1, MyString, 200, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "LVUP/ABC.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(736);
	this->addChild(name, 3);

	auto textA_item = MenuItemImage::create(
		"LVUP/ok_button.png",
		"LVUP/ok_buttonpr.png",
		CC_CALLBACK_1(Up4::story1_8, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(716);
	this->addChild(text, 5);
}
void Up4::story1_8(Ref * pSender)
{
	removeChildByTag(736);
	removeChildByTag(716);

	char MyString[200];
	WideCharToMultiByte(CP_UTF8, 0, L"(호동은 학생회장이 되었다.)", -1, MyString, 200, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "LVUP/ABC.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(737);
	this->addChild(name, 3);

	auto textA_item = MenuItemImage::create(
		"LVUP/ok_button.png",
		"LVUP/ok_buttonpr.png",
		CC_CALLBACK_1(Up4::story1_9, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(717);
	this->addChild(text, 5);
}
void Up4::story1_9(Ref * pSender)
{
	removeChildByTag(737);
	removeChildByTag(717);
	removeChildByTag(705);

	// 학생회실 이동 코드로 변경
	Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
	Director::getInstance()->replaceScene(Up4::createScene());
}

