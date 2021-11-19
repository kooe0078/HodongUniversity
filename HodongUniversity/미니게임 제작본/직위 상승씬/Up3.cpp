#include "Up3.h"
#include "SimpleAudioEngine.h"

//사운드 할라면 꼭 필요
using namespace CocosDenshion;
USING_NS_CC;

Scene* Up3::createScene()
{
	auto scene = Scene::create();
	auto layer = Up3::create();
	scene->addChild(layer);

	return scene;
}

bool Up3::init()
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
void Up3::InitBackGround()
{
	auto sprite = Sprite::create("LVUP/StuduntUnion.png");
	sprite->setPosition(Point(512, 384));
	sprite->setTag(600);
	this->addChild(sprite, 0);
}
void Up3::InitMenu()
{
	// 다음 버튼
	auto textA_item = MenuItemImage::create(
		"LVUP/ok_button.png",
		"LVUP/ok_buttonpr.png",
		CC_CALLBACK_1(Up3::story1, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(709);
	this->addChild(text, 5);

	// 김창룡
	Sprite* mainchr = Sprite::create("LVUP/inside_chara1.png");
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
	WideCharToMultiByte(CP_UTF8, 0, L"김창룡 : 호동아. 형이랑 같이 회장선거 나가지않을래?", -1, MyString, 200, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "LVUP/ABC.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(729);
	this->addChild(name, 3);
}
void Up3::story1(Ref * pSender)
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
	WideCharToMultiByte(CP_UTF8, 0, L"호동 : 네? 저요? ", -1, MyString, 100, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "LVUP/ABC.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(730);
	this->addChild(name, 3);

	auto textA_item = MenuItemImage::create(
		"LVUP/ok_button.png",
		"LVUP/ok_buttonpr.png",
		CC_CALLBACK_1(Up3::story1_2, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(710);
	this->addChild(text, 5);
}
void Up3::story1_2(Ref * pSender)
{
	removeChildByTag(710);
	removeChildByTag(730);

	char MyString[400];
	WideCharToMultiByte(CP_UTF8, 0, L"김창룡 : 그래. 네 평판이 요즘 아주 좋더라고.\n너한테 부회장 자리를 부탁해도 될까??", -1, MyString, 400, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "LVUP/ABC.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(731);
	this->addChild(name, 3);

	auto textA_item = MenuItemImage::create(
		"LVUP/ok_button.png",
		"LVUP/ok_buttonpr.png",
		CC_CALLBACK_1(Up3::story1_3, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(711);
	this->addChild(text, 5);
}
void Up3::story1_3(Ref * pSender)
{
	removeChildByTag(731);
	removeChildByTag(711);

	char MyString[200];
	WideCharToMultiByte(CP_UTF8, 0, L"호동 : 네! 저 나가겠습니다!", -1, MyString, 200, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "LVUP/ABC.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(732);
	this->addChild(name, 3);

	auto textA_item = MenuItemImage::create(
		"LVUP/ok_button.png",
		"LVUP/ok_buttonpr.png",
		CC_CALLBACK_1(Up3::story1_4, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(712);
	this->addChild(text, 5);
}
void Up3::story1_4(Ref * pSender)
{
	removeChildByTag(732);
	removeChildByTag(712);
	removeChildByTag(600);
	removeChildByTag(701);
	removeChildByTag(702);

	char MyString[400];
	WideCharToMultiByte(CP_UTF8, 0, L".....", -1, MyString, 400, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "LVUP/ABC.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(733);
	this->addChild(name, 3);

	auto textA_item = MenuItemImage::create(
		"LVUP/ok_button.png",
		"LVUP/ok_buttonpr.png",
		CC_CALLBACK_1(Up3::story1_5, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(713);
	this->addChild(text, 5);
}
void Up3::story1_5(Ref * pSender)
{
	removeChildByTag(733);
	removeChildByTag(713);

	// 배경
	auto sprite = Sprite::create("LVUP/vote_back.png");
	sprite->setPosition(Point(512, 384));
	sprite->setTag(601);
	this->addChild(sprite, 0);

	// 임원
	Sprite* mainchr = Sprite::create("LVUP/student_chara.png");
	mainchr->setAnchorPoint(Point(0.5, 0));
	mainchr->setPosition(Point(820, 10));
	mainchr->setTag(703);
	this->addChild(mainchr, 1);

	char MyString[100];
	WideCharToMultiByte(CP_UTF8, 0, L"임원 : 그럼 지금부터 학생회장 선출투표를 시작하겠습니다.", -1, MyString, 100, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "LVUP/ABC.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(734);
	this->addChild(name, 3);

	auto textA_item = MenuItemImage::create(
		"LVUP/ok_button.png",
		"LVUP/ok_buttonpr.png",
		CC_CALLBACK_1(Up3::story1_6, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(714);
	this->addChild(text, 5);
}
void Up3::story1_6(Ref * pSender)
{
	removeChildByTag(734);
	removeChildByTag(714);

	char MyString[200];
	WideCharToMultiByte(CP_UTF8, 0, L".....", -1, MyString, 200, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "LVUP/ABC.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(735);
	this->addChild(name, 3);

	auto textA_item = MenuItemImage::create(
		"LVUP/ok_button.png",
		"LVUP/ok_buttonpr.png",
		CC_CALLBACK_1(Up3::story1_7, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(715);
	this->addChild(text, 5);
}
void Up3::story1_7(Ref * pSender)
{
	removeChildByTag(735);
	removeChildByTag(715);

	char MyString[400];
	WideCharToMultiByte(CP_UTF8, 0, L"임원 : 이상으로 개표를 마치겠습니다. 이번 학생회장은 김창룡 학생,\n부회장은 호동 학생으로 선정 되었습니다. 축하해 주세요!", -1, MyString, 400, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "LVUP/ABC.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(736);
	this->addChild(name, 3);

	auto textA_item = MenuItemImage::create(
		"LVUP/ok_button.png",
		"LVUP/ok_buttonpr.png",
		CC_CALLBACK_1(Up3::story1_8, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(716);
	this->addChild(text, 5);
}
void Up3::story1_8(Ref * pSender)
{
	removeChildByTag(736);
	removeChildByTag(716);
	removeChildByTag(703);

	// 김창룡
	Sprite* mainchr = Sprite::create("LVUP/inside_chara1.png");
	mainchr->setAnchorPoint(Point(0.5, 0));
	mainchr->setPosition(Point(820, 10));
	mainchr->setTag(704);
	this->addChild(mainchr, 1);

	// 메인 캐릭터
	Sprite* mainchr2 = Sprite::create("LVUP/main_char.png");
	mainchr2->setAnchorPoint(Point(0.5, 0));
	mainchr2->setPosition(Point(120, 80));
	mainchr2->setTag(705);
	this->addChild(mainchr2, 1);

	char MyString[400];
	WideCharToMultiByte(CP_UTF8, 0, L"호동, 김창룡 : 감사합니다! 열심히 하겠습니다!!", -1, MyString, 400, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "LVUP/ABC.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(737);
	this->addChild(name, 3);

	auto textA_item = MenuItemImage::create(
		"LVUP/ok_button.png",
		"LVUP/ok_buttonpr.png",
		CC_CALLBACK_1(Up3::story1_9, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(717);
	this->addChild(text, 5);
}
void Up3::story1_9(Ref * pSender)
{
	removeChildByTag(737);
	removeChildByTag(717);

	char MyString[400];
	WideCharToMultiByte(CP_UTF8, 0, L"(호동은 부회장이 되었다.)", -1, MyString, 400, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "LVUP/ABC.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(738);
	this->addChild(name, 3);

	auto textA_item = MenuItemImage::create(
		"LVUP/ok_button.png",
		"LVUP/ok_buttonpr.png",
		CC_CALLBACK_1(Up3::story1_10, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(718);
	this->addChild(text, 5);
}
void Up3::story1_10(Ref * pSender)
{
	removeChildByTag(738);
	removeChildByTag(718);
	removeChildByTag(704);
	removeChildByTag(705);

	// 학생회실 이동 코드로 변경
	Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
	Director::getInstance()->replaceScene(Up3::createScene());
}
