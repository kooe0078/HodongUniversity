#include "CardEndScene.h"
#include "SimpleAudioEngine.h"
#include "MainScene.h"
#include "NextDayScene.h"
#include "sinngleton.h"
//사운드 할라면 꼭 필요
using namespace CocosDenshion;
USING_NS_CC;

Scene* CardEndScene::createScene()
{
    auto scene = Scene::create();
    auto layer = CardEndScene::create();
    scene->addChild(layer);

    return scene;
}

bool CardEndScene::init()
{

    if ( !Layer::init() )
    {
        return false;
    }
	
	InitBackGround();
	initLabel();
	setAnswer();
	Menuitem();

	//배경음악
	//SimpleAudioEngine::getInstance()->playBackgroundMusic("MiniGameResources/CardEndSceneMusic.mp3", true);

    return true;
}
void CardEndScene::update(float ft)
{
	//씬 자체적으로 반복 되야하는 내용
}

void CardEndScene::InitBackGround()
{
	Sprite* overSpr = Sprite::create("CardGame_2/Back.png");
	overSpr->setAnchorPoint(Point(0.5, 0.5));
	overSpr->setPosition(Point(512, 384));
	overSpr->setTag(23);
	this->addChild(overSpr, 2);
}
void CardEndScene::initLabel() // 카드 :
{
	char Q1[200];
	WideCharToMultiByte(CP_UTF8, 0, L"맞춘 개수 : ", -1, Q1, 200, NULL, NULL);
	auto Quiz = Label::createWithTTF(Q1, "CardGame_2/ABC.ttf", 27);
	Quiz->setAnchorPoint(Point(0, 1));
	Quiz->setPosition(Point(350, 650));
	Quiz->setColor(Color3B::BLACK);
	Quiz->setTag(24);
	this->addChild(Quiz, 2);


	Label* money = Label::createWithTTF(StringUtils::format(""), "CardGame_2/ABC.ttf", 27);
	money->setAnchorPoint(Point(0, 1));
	money->setPosition(Point(500, 650));
	money->setColor(Color3B::RED);
	money->setTag(560);
	this->addChild(money, 3);


	setAnswer();
}
void CardEndScene::setAnswer() // 카드 개수
{
	Label* label3 = (Label*)this->getChildByTag(560);
	label3->setString(StringUtils::format("%d", Singletons::getInstance()->CardOK));
}
void CardEndScene::Menuitem() // 확인 버튼
{
	auto Back = MenuItemImage::create(
		"CardGame_2/UI_enter.png",
		"CardGame_2/UI_enterpr.png",
		CC_CALLBACK_1(CardEndScene::Check_1, this));
	Back->setPosition(Point(512, 250));

	auto menu1 = Menu::create(Back, NULL);
	menu1->setPosition(Vec2::ZERO);
	menu1->setTag(25);
	this->addChild(menu1, 2);
}
void CardEndScene::storyAspr(Ref *pSender)
{

}
void CardEndScene::Check_1(Ref *pSender) // 메인화면으로
{
	removeChildByTag(560);
	removeChildByTag(25);
	removeChildByTag(24);
	removeChildByTag(23);
	if (Singletons::getInstance()->CardOK == 8)
	{
		SimpleAudioEngine::getInstance()->playEffect("MiniGameResources/button_click_16_sound_effects_.mp3", false);

		char MyString[200];
		WideCharToMultiByte(CP_UTF8, 0, L"호동: 이정도 게임.. 나한텐 껌이지!\n\n(100000원을 획득하였습니다.)", -1, MyString, 200, NULL, NULL);
		auto name = Label::createWithTTF(MyString, "fonts/Bold.ttf", 30);
		name->setAnchorPoint(Point(0, 1));
		name->setPosition(Point(40, 150));
		name->setColor(Color3B::WHITE);
		name->setTag(20);
		this->addChild(name, 3);

		auto storyA_item = MenuItemImage::create(
			"MiniGameResources/UI_Textlblack.png",
			"MiniGameResources/UI_Textlblack.png",

			CC_CALLBACK_1(CardEndScene::storyAspr, this));
		storyA_item->setAnchorPoint(Point(0.5, 0.5));
		storyA_item->setPosition(Point(510, 100));

		auto storyA = Menu::create(storyA_item, NULL);
		storyA->setAnchorPoint(Point(0.5, 0.5));
		storyA->setPosition(Point(0, 0));
		storyA->setTag(4);
		this->addChild(storyA, 2);


		//메인캐릭터
		Sprite* mainchr = Sprite::create("MiniGameResources/main_char.png");
		mainchr->setAnchorPoint(Point(0.5, 0));
		mainchr->setPosition(Point(120, 80));
		mainchr->setTag(166);
		this->addChild(mainchr, 1);

		auto textA_item = MenuItemImage::create(
			"MiniGameResources/ok_button.png",
			"MiniGameResources/ok_buttonpr.png",
			CC_CALLBACK_1(CardEndScene::Check_2, this));
		textA_item->setAnchorPoint(Point(0.5, 0.5));
		textA_item->setPosition(Point(950, 65));

		auto text = Menu::create(textA_item, NULL);
		text->setAnchorPoint(Point(0.5, 0.5));
		text->setPosition(Point(0, 0));
		text->setTag(130);
		this->addChild(text, 5);

		Singletons::getInstance()->money = Singletons::getInstance()->money + 100000;
	}
	if (Singletons::getInstance()->CardOK <= 7)
	{
		SimpleAudioEngine::getInstance()->playEffect("MiniGameResources/button_click_16_sound_effects_.mp3", false);

		char MyString[200];
		WideCharToMultiByte(CP_UTF8, 0, L"호동: 이거 너무 어려운거 아니야?\n\n(10000원을 획득하였습니다.)", -1, MyString, 200, NULL, NULL);
		auto name = Label::createWithTTF(MyString, "fonts/Bold.ttf", 30);
		name->setAnchorPoint(Point(0, 1));
		name->setPosition(Point(40, 150));
		name->setColor(Color3B::WHITE);
		name->setTag(20);
		this->addChild(name, 3);

		auto storyA_item = MenuItemImage::create(
			"MiniGameResources/UI_Textlblack.png",
			"MiniGameResources/UI_Textlblack.png",

			CC_CALLBACK_1(CardEndScene::storyAspr, this));
		storyA_item->setAnchorPoint(Point(0.5, 0.5));
		storyA_item->setPosition(Point(510, 100));

		auto storyA = Menu::create(storyA_item, NULL);
		storyA->setAnchorPoint(Point(0.5, 0.5));
		storyA->setPosition(Point(0, 0));
		storyA->setTag(4);
		this->addChild(storyA, 2);


		//메인캐릭터
		Sprite* mainchr = Sprite::create("MiniGameResources/main_char.png");
		mainchr->setAnchorPoint(Point(0.5, 0));
		mainchr->setPosition(Point(120, 80));
		mainchr->setTag(166);
		this->addChild(mainchr, 1);

		auto textA_item = MenuItemImage::create(
			"MiniGameResources/ok_button.png",
			"MiniGameResources/ok_buttonpr.png",
			CC_CALLBACK_1(CardEndScene::Check_2, this));
		textA_item->setAnchorPoint(Point(0.5, 0.5));
		textA_item->setPosition(Point(950, 65));

		auto text = Menu::create(textA_item, NULL);
		text->setAnchorPoint(Point(0.5, 0.5));
		text->setPosition(Point(0, 0));
		text->setTag(130);
		this->addChild(text, 5);

		Singletons::getInstance()->money = Singletons::getInstance()->money + 10000;
	}
	Singletons::getInstance()->CardOK = 0;
}
void CardEndScene::Check_2(Ref *pSender)
{
	Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
	Director::getInstance()->replaceScene(NextDayScene::createScene());
}
