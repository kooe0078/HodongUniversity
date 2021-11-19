#include "MiroEndScene2.h"
#include "SimpleAudioEngine.h"
#include "MiroScene2.h"
#include "sinngleton.h"
#include "NextDayScene.h"
//사운드 할라면 꼭 필요
using namespace CocosDenshion;
USING_NS_CC;

Scene* MiroEndScene2::createScene()
{
    auto scene = Scene::create();
    auto layer = MiroEndScene2::create();
    scene->addChild(layer);

    return scene;
}

bool MiroEndScene2::init()
{

    if ( !Layer::init() )
    {
        return false;
    }
	
	InitBackGround();
	initLabel();
	Setting();
	Menuitem();

	//배경음악
	//SimpleAudioEngine::getInstance()->playBackgroundMusic("MiniGameResources/MiroEndScene2Music.mp3", true);

    return true;
}
void MiroEndScene2::storyAspr(Ref *pSender)
{

}
void MiroEndScene2::InitBackGround()
{
	Sprite* overSpr = Sprite::create("MiroGame/Back.png");
	overSpr->setAnchorPoint(Point(0.5, 0.5));
	overSpr->setPosition(Point(512, 384));
	overSpr->setTag(550);
	this->addChild(overSpr, 0);
}
void MiroEndScene2::initLabel() // 남은 시간 :
{

}
void MiroEndScene2::Setting() // 남은 시간
{
	if (Singletons::getInstance()->mironum == 1)
	{
		char Q1[200];
		WideCharToMultiByte(CP_UTF8, 0, L" 성공 ", -1, Q1, 200, NULL, NULL);
		auto Time = Label::createWithTTF(Q1, "MiroGame/ABC.ttf",40 );
		Time->setAnchorPoint(Point(0, 1));
		Time->setPosition(Point(460, 645));
		Time->setColor(Color3B::RED);
		Time->setTag(551);
		this->addChild(Time, 2);

	}

	if (Singletons::getInstance()->mironum == 2)
	{
		char Q1[200];
		WideCharToMultiByte(CP_UTF8, 0, L" 실패 ", -1, Q1, 200, NULL, NULL);
		auto Time = Label::createWithTTF(Q1, "MiroGame/ABC.ttf", 40);
		Time->setAnchorPoint(Point(0, 1));
		Time->setPosition(Point(460, 645));
		Time->setColor(Color3B::RED);
		Time->setTag(552);
		this->addChild(Time, 2);

		
	}
}
void MiroEndScene2::Menuitem() // 확인 버튼
{
	auto Back = MenuItemImage::create(
		"MiroGame/UI_enter.png",
		"MiroGame/UI_enterpr.png",
		CC_CALLBACK_1(MiroEndScene2::Check, this));
	Back->setPosition(Point(512, 250));

	auto menu1 = Menu::create(Back, NULL);
	menu1->setPosition(Vec2::ZERO);
	menu1->setTag(553);
	this->addChild(menu1, 2);
}
void MiroEndScene2::Check(Ref *pSender) // 메인화면으로
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);

	removeChildByTag(550);
	removeChildByTag(551);
	removeChildByTag(552);
	removeChildByTag(553);

	if (Singletons::getInstance()->mironum == 1)
	{
		char MyString[100];
		WideCharToMultiByte(CP_UTF8, 0, L"호동: 운동이 되는걸~\n\n(인성을 14획득하였습니다.)", -1, MyString, 100, NULL, NULL);
		auto name = Label::createWithTTF(MyString, "fonts/Bold.ttf", 30);
		name->setAnchorPoint(Point(0, 1));
		name->setPosition(Point(40, 150));
		name->setColor(Color3B::WHITE);
		name->setTag(20);
		this->addChild(name, 3);

		auto storyA_item = MenuItemImage::create(
			"MiniGameResources/UI_Textlblack.png",
			"MiniGameResources/UI_Textlblack.png",

			CC_CALLBACK_1(MiroEndScene2::storyAspr, this));
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
			CC_CALLBACK_1(MiroEndScene2::Check_1, this));
		textA_item->setAnchorPoint(Point(0.5, 0.5));
		textA_item->setPosition(Point(950, 65));

		auto text = Menu::create(textA_item, NULL);
		text->setAnchorPoint(Point(0.5, 0.5));
		text->setPosition(Point(0, 0));
		text->setTag(130);
		this->addChild(text, 5);


		Singletons::getInstance()->m_insung = Singletons::getInstance()->m_insung + 14;
	}

	if (Singletons::getInstance()->mironum == 2)
	{
		char MyString[100];
		WideCharToMultiByte(CP_UTF8, 0, L"호동: 헉헉헉..\n\n(인성을 10획득하였습니다.)", -1, MyString, 100, NULL, NULL);
		auto name = Label::createWithTTF(MyString, "fonts/Bold.ttf", 30);
		name->setAnchorPoint(Point(0, 1));
		name->setPosition(Point(40, 150));
		name->setColor(Color3B::WHITE);
		name->setTag(20);
		this->addChild(name, 3);

		auto storyA_item = MenuItemImage::create(
			"MiniGameResources/UI_Textlblack.png",
			"MiniGameResources/UI_Textlblack.png",

			CC_CALLBACK_1(MiroEndScene2::storyAspr, this));
		storyA_item->setAnchorPoint(Point(0.5, 0.5));
		storyA_item->setPosition(Point(510, 100));

		auto storyA = Menu::create(storyA_item, NULL);
		storyA->setAnchorPoint(Point(0.5, 0.5));
		storyA->setPosition(Point(0, 0));
		storyA->setTag(4);
		this->addChild(storyA, 2);

		auto textA_item = MenuItemImage::create(
			"MiniGameResources/ok_button.png",
			"MiniGameResources/ok_buttonpr.png",
			CC_CALLBACK_1(MiroEndScene2::Check_1, this));
		textA_item->setAnchorPoint(Point(0.5, 0.5));
		textA_item->setPosition(Point(950, 65));

		auto text = Menu::create(textA_item, NULL);
		text->setAnchorPoint(Point(0.5, 0.5));
		text->setPosition(Point(0, 0));
		text->setTag(130);
		this->addChild(text, 5);


		//메인캐릭터
		Sprite* mainchr = Sprite::create("MiniGameResources/main_char.png");
		mainchr->setAnchorPoint(Point(0.5, 0));
		mainchr->setPosition(Point(120, 80));
		mainchr->setTag(166);
		this->addChild(mainchr, 1);

		Singletons::getInstance()->m_insung = Singletons::getInstance()->m_insung + 10;
	}
	Singletons::getInstance()->mironum = 0;
//Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
//Director::getInstance()->replaceScene(NextDayScene::createScene());
//
//UserDefault::getInstance()->setIntegerForKey("currClock2", 13); // currClock2을 13으로 초기화 
//Singletons::getInstance()->currClock2 = UserDefault::getInstance()->getIntegerForKey("currClock2");
//UserDefault::getInstance()->flush();

	
}
void MiroEndScene2::Check_1(Ref *pSender) // 메인화면으로
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);

	Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
	Director::getInstance()->replaceScene(NextDayScene::createScene());
	
	UserDefault::getInstance()->setIntegerForKey("currClock2", 7); // currClock2을 7으로 초기화 
	Singletons::getInstance()->currClock2 = UserDefault::getInstance()->getIntegerForKey("currClock2");
	UserDefault::getInstance()->flush();

}