#include "HappyEnd.h"
#include "EndScene.h"
#include "SimpleAudioEngine.h"

//사운드 할라면 꼭 필요
using namespace CocosDenshion;
USING_NS_CC;

Scene* HappyEnd::createScene()
{
	auto scene = Scene::create();
	auto layer = HappyEnd::create();
	scene->addChild(layer);

	return scene;
}

bool HappyEnd::init()
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
void HappyEnd::InitBackGround()
{
	auto sprite = Sprite::create("Rank/happyendscene.png");
	sprite->setPosition(Point(512, 384));
	this->addChild(sprite, 0);
}
void HappyEnd::InitMenu()
{
	// 다음 버튼
	auto textA_item = MenuItemImage::create(
		"Rank/ok_button.png",
		"Rank/ok_buttonpr.png",
		CC_CALLBACK_1(HappyEnd::story1, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(709);
	this->addChild(text, 5);

	//자동차
	Sprite* mainchr = Sprite::create("Rank/hodongcar.png");
	mainchr->setAnchorPoint(Point(0.5, 0));
	mainchr->setPosition(Point(120, 80));
	mainchr->setTag(701);
	this->addChild(mainchr, 1);

	//텍스트 창
	auto sprite = Sprite::create("Rank/UI_Textlblack.png");
	sprite->setAnchorPoint(Point(0.5, 0.5));
	sprite->setPosition(Point(510, 100));
	sprite->setTag(700);
	this->addChild(sprite, 2);

	// 캐릭터 대사
	char MyString[200];
	WideCharToMultiByte(CP_UTF8, 0, L"(부릉~)", -1, MyString, 200, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "Rank/ABC.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(729);
	this->addChild(name, 3);
}
void HappyEnd::story1(Ref * pSender)
{
	removeChildByTag(709);
	removeChildByTag(729);

	// 메인 캐릭터
	Sprite* mainchr = Sprite::create("Rank/hadsome_mainchar.png");
	mainchr->setAnchorPoint(Point(0.5, 0));
	mainchr->setPosition(Point(120, 80));
	mainchr->setTag(702);
	this->addChild(mainchr, 1);

	char MyString[100];
	WideCharToMultiByte(CP_UTF8, 0, L"호동 : 아쉽군... 이제 떠날 때가 된 건가...", -1, MyString, 100, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "Rank/ABC.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(730);
	this->addChild(name, 3);

	auto textA_item = MenuItemImage::create(
		"Rank/ok_button.png",
		"Rank/ok_buttonpr.png",
		CC_CALLBACK_1(HappyEnd::story1_2, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(710);
	this->addChild(text, 5);
}
void HappyEnd::story1_2(Ref * pSender)
{
	removeChildByTag(710);
	removeChildByTag(730);

	char MyString[100];
	WideCharToMultiByte(CP_UTF8, 0, L"호동 : 참 재미있었어. 여러가지로 말이지 후후후...", -1, MyString, 100, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "Rank/ABC.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(731);
	this->addChild(name, 3);

	auto textA_item = MenuItemImage::create(
		"Rank/ok_button.png",
		"Rank/ok_buttonpr.png",
		CC_CALLBACK_1(HappyEnd::story1_3, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(711);
	this->addChild(text, 5);
}
void HappyEnd::story1_3(Ref * pSender)
{
	removeChildByTag(731);
	removeChildByTag(711);

	char MyString[400];
	WideCharToMultiByte(CP_UTF8, 0, L"호동 : 고맙다! 호동대! 네 덕분에 정말 많은 것을 얻었어!!\n그럼 가볼까~ 금수저의 생활을 즐기러! 바이바이 호동대~ ", -1, MyString, 400, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "Rank/ABC.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(732);
	this->addChild(name, 3);

	auto textA_item = MenuItemImage::create(
		"Rank/ok_button.png",
		"Rank/ok_buttonpr.png",
		CC_CALLBACK_1(HappyEnd::story1_4, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(712);
	this->addChild(text, 5);
}
void HappyEnd::story1_4(Ref * pSender)
{
	removeChildByTag(732);
	removeChildByTag(712);
	removeChildByTag(701);

	Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
	auto scene = TransitionCrossFade::create(1.5, RankingScene::createScene());
	Director::getInstance()->replaceScene(scene);
}