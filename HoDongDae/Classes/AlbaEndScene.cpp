#include "AlbaEndScene.h"
#include "SimpleAudioEngine.h"
#include "AlbaScene.h"
#include "sinngleton.h"
#include "NextDayScene.h"
//사운드 할라면 꼭 필요
using namespace CocosDenshion;
USING_NS_CC; 

Scene* AlbaEndScene::createScene()
{
    auto scene = Scene::create();
    auto layer = AlbaEndScene::create();
    scene->addChild(layer);

    return scene;
}

bool AlbaEndScene::init()
{

	if (!Layer::init())
	{
		return false;
	}

	InitBackGround();
	initLabel();
	Menuitem();

	//배경음악
	//SimpleAudioEngine::getInstance()->playBackgroundMusic("MiniGameResources/AlbaEndSceneMusic.mp3", true);

	return true;
}
void AlbaEndScene::update(float ft)
{
	//씬 자체적으로 반복 되야하는 내용
}
void AlbaEndScene::InitBackGround()
{
	Sprite* overSpr = Sprite::create("AlbaGame/Back.png");
	overSpr->setAnchorPoint(Point(0.5, 0.5));
	overSpr->setPosition(Point(512, 384));
	overSpr->setTag(21);
	this->addChild(overSpr, 2);

}
void AlbaEndScene::initLabel() // 옮김 :
{
	Singletons::getInstance()->aurrClock = 11;
	
	char Q1[200];
	WideCharToMultiByte(CP_UTF8, 0, L"옮긴 개수 : ", -1, Q1, 200, NULL, NULL);
	auto Quiz = Label::createWithTTF(Q1, "AlbaGame/ABC.ttf", 27);
	Quiz->setAnchorPoint(Point(0, 1));
	Quiz->setPosition(Point(350, 650));
	Quiz->setColor(Color3B::BLACK);
	Quiz->setTag(22);
	this->addChild(Quiz, 2);

	
	Label* money = Label::createWithTTF(StringUtils::format(""), "AlbaGame/ABC.ttf", 27);
	money->setAnchorPoint(Point(0, 1));
	money->setPosition(Point(500, 650));
	money->setColor(Color3B::RED);
	money->setTag(550);
	this->addChild(money, 3);
	

	setAnswer();
}
void AlbaEndScene::setAnswer() // 옮긴 개수
{
	Label* label3 = (Label*)this->getChildByTag(550);
	label3->setString(StringUtils::format("%d", Singletons::getInstance()->Many));
	
	
}
void AlbaEndScene::Menuitem() // 확인 버튼
{
	SimpleAudioEngine::getInstance()->playEffect("MiniGameResources/button_click_16_sound_effects_.mp3", false);

	auto Back = MenuItemImage::create(
		"AlbaGame/UI_enter.png",
		"AlbaGame/UI_enterpr.png",
		CC_CALLBACK_1(AlbaEndScene::Check_1, this));
	Back->setPosition(Point(512, 250));

	auto menu1 = Menu::create(Back, NULL);
	menu1->setPosition(Vec2::ZERO);
	menu1->setTag(23);
	this->addChild(menu1, 2);

}
void AlbaEndScene::storyAspr(Ref *pSender)
{

}
void AlbaEndScene::Check_1(Ref *pSender) // 메인화면으로
{
	removeChildByTag(550);
	removeChildByTag(21);
	removeChildByTag(22);
	removeChildByTag(23);

	if (Singletons::getInstance()->m_insung <= 299)
	{
		if (Singletons::getInstance()->Many >= 14)
		{
			SimpleAudioEngine::getInstance()->playEffect("MiniGameResources/button_click_16_sound_effects_.mp3", false);

			char MyString[200];
			WideCharToMultiByte(CP_UTF8, 0, L"호동: 힘들지만.. 별다른 실수없이 완료했군!\n\n(알바비를 획득하였습니다.)", -1, MyString, 200, NULL, NULL);
			auto name = Label::createWithTTF(MyString, "fonts/Bold.ttf", 30);
			name->setAnchorPoint(Point(0, 1));
			name->setPosition(Point(40, 150));
			name->setColor(Color3B::WHITE);
			name->setTag(20);
			this->addChild(name, 3);

			auto storyA_item = MenuItemImage::create(
				"MiniGameResources/UI_Textlblack.png",
				"MiniGameResources/UI_Textlblack.png",

				CC_CALLBACK_1(AlbaEndScene::storyAspr, this));
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
				CC_CALLBACK_1(AlbaEndScene::Check_2, this));
			textA_item->setAnchorPoint(Point(0.5, 0.5));
			textA_item->setPosition(Point(950, 65));

			auto text = Menu::create(textA_item, NULL);
			text->setAnchorPoint(Point(0.5, 0.5));
			text->setPosition(Point(0, 0));
			text->setTag(130);
			this->addChild(text, 5);


			Singletons::getInstance()->money = Singletons::getInstance()->money + 1000 + (Singletons::getInstance()->m_insung * 50);
		}


		if (Singletons::getInstance()->Many <= 13)
		{
			SimpleAudioEngine::getInstance()->playEffect("MiniGameResources/button_click_16_sound_effects_.mp3", false);

			char MyString[200];
			WideCharToMultiByte(CP_UTF8, 0, L"호동: 실수 투성이였어...\n\n(알바비를 획득하였습니다..)", -1, MyString, 200, NULL, NULL);
			auto name = Label::createWithTTF(MyString, "fonts/Bold.ttf", 30);
			name->setAnchorPoint(Point(0, 1));
			name->setPosition(Point(40, 150));
			name->setColor(Color3B::WHITE);
			name->setTag(20);
			this->addChild(name, 3);

			auto storyA_item = MenuItemImage::create(
				"MiniGameResources/UI_Textlblack.png",
				"MiniGameResources/UI_Textlblack.png",

				CC_CALLBACK_1(AlbaEndScene::storyAspr, this));
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
				CC_CALLBACK_1(AlbaEndScene::Check_2, this));
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

			Singletons::getInstance()->money = Singletons::getInstance()->money + 1000 + (Singletons::getInstance()->m_insung * 30);
		}
		
	}

	if (Singletons::getInstance()->m_insung >=300 && Singletons::getInstance()->m_insung <= 599)
	{
		if (Singletons::getInstance()->Many >= 14)
		{
			SimpleAudioEngine::getInstance()->playEffect("MiniGameResources/button_click_16_sound_effects_.mp3", false);

			char MyString[200];
			WideCharToMultiByte(CP_UTF8, 0, L"호동: 슬슬 요령이 잡히기 시작했어!\n\n(알바비를 획득하였습니다.)", -1, MyString, 200, NULL, NULL);
			auto name = Label::createWithTTF(MyString, "fonts/Bold.ttf", 30);
			name->setAnchorPoint(Point(0, 1));
			name->setPosition(Point(40, 150));
			name->setColor(Color3B::WHITE);
			name->setTag(20);
			this->addChild(name, 3);

			auto storyA_item = MenuItemImage::create(
				"MiniGameResources/UI_Textlblack.png",
				"MiniGameResources/UI_Textlblack.png",

				CC_CALLBACK_1(AlbaEndScene::storyAspr, this));
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
				CC_CALLBACK_1(AlbaEndScene::Check_2, this));
			textA_item->setAnchorPoint(Point(0.5, 0.5));
			textA_item->setPosition(Point(950, 65));

			auto text = Menu::create(textA_item, NULL);
			text->setAnchorPoint(Point(0.5, 0.5));
			text->setPosition(Point(0, 0));
			text->setTag(130);
			this->addChild(text, 5);


			Singletons::getInstance()->money = Singletons::getInstance()->money + 5000 + (Singletons::getInstance()->m_insung * 60);
		}


		if (Singletons::getInstance()->Many <= 13)
		{
			SimpleAudioEngine::getInstance()->playEffect("MiniGameResources/button_click_16_sound_effects_.mp3", false);

			char MyString[200];
			WideCharToMultiByte(CP_UTF8, 0, L"호동: 돈벌기 참 어렵군...\n\n(알바비를 획득하였습니다..)", -1, MyString, 200, NULL, NULL);
			auto name = Label::createWithTTF(MyString, "fonts/Bold.ttf", 30);
			name->setAnchorPoint(Point(0, 1));
			name->setPosition(Point(40, 150));
			name->setColor(Color3B::WHITE);
			name->setTag(20);
			this->addChild(name, 3);

			auto storyA_item = MenuItemImage::create(
				"MiniGameResources/UI_Textlblack.png",
				"MiniGameResources/UI_Textlblack.png",

				CC_CALLBACK_1(AlbaEndScene::storyAspr, this));
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
				CC_CALLBACK_1(AlbaEndScene::Check_2, this));
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

			Singletons::getInstance()->money = Singletons::getInstance()->money + 5000 + (Singletons::getInstance()->m_insung * 40);
		}

	}
	if (Singletons::getInstance()->m_insung >= 600 )
	{
		if (Singletons::getInstance()->Many >= 14)
		{
			SimpleAudioEngine::getInstance()->playEffect("MiniGameResources/button_click_16_sound_effects_.mp3", false);

			char MyString[200];
			WideCharToMultiByte(CP_UTF8, 0, L"호동: 이정도 실적은 당연하지~\n\n(알바비를 획득하였습니다.)", -1, MyString, 200, NULL, NULL);
			auto name = Label::createWithTTF(MyString, "fonts/Bold.ttf", 30);
			name->setAnchorPoint(Point(0, 1));
			name->setPosition(Point(40, 150));
			name->setColor(Color3B::WHITE);
			name->setTag(20);
			this->addChild(name, 3);

			auto storyA_item = MenuItemImage::create(
				"MiniGameResources/UI_Textlblack.png",
				"MiniGameResources/UI_Textlblack.png",

				CC_CALLBACK_1(AlbaEndScene::storyAspr, this));
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
				CC_CALLBACK_1(AlbaEndScene::Check_2, this));
			textA_item->setAnchorPoint(Point(0.5, 0.5));
			textA_item->setPosition(Point(950, 65));

			auto text = Menu::create(textA_item, NULL);
			text->setAnchorPoint(Point(0.5, 0.5));
			text->setPosition(Point(0, 0));
			text->setTag(130);
			this->addChild(text, 5);


			Singletons::getInstance()->money = Singletons::getInstance()->money + 10000 + (Singletons::getInstance()->m_insung * 70);
		}


		if (Singletons::getInstance()->Many <= 13)
		{
			SimpleAudioEngine::getInstance()->playEffect("MiniGameResources/button_click_16_sound_effects_.mp3", false);

			char MyString[200];
			WideCharToMultiByte(CP_UTF8, 0, L"호동: 으... 오늘도 실수 투성이 ..\n\n(알바비를 획득하였습니다..)", -1, MyString, 200, NULL, NULL);
			auto name = Label::createWithTTF(MyString, "fonts/Bold.ttf", 30);
			name->setAnchorPoint(Point(0, 1));
			name->setPosition(Point(40, 150));
			name->setColor(Color3B::WHITE);
			name->setTag(20);
			this->addChild(name, 3);

			auto storyA_item = MenuItemImage::create(
				"MiniGameResources/UI_Textlblack.png",
				"MiniGameResources/UI_Textlblack.png",

				CC_CALLBACK_1(AlbaEndScene::storyAspr, this));
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
				CC_CALLBACK_1(AlbaEndScene::Check_2, this));
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

			Singletons::getInstance()->money = Singletons::getInstance()->money + 10000 + (Singletons::getInstance()->m_insung * 50);
		}

	}
	Singletons::getInstance()->Many = 0;
}
void AlbaEndScene::Check_2(Ref *pSender)
{
	Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
	Director::getInstance()->replaceScene(NextDayScene::createScene());
}
//Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
//Director::getInstance()->replaceScene(NextDayScene::createScene());
//
//UserDefault::getInstance()->setIntegerForKey("aurrClock", 11); // aurrClock을 11으로 초기화 
//Singletons::getInstance()->aurrClock = UserDefault::getInstance()->getIntegerForKey("aurrClock");
//UserDefault::getInstance()->flush();

//UserDefault::getInstance()->setIntegerForKey("Many", 0); // Many을 0으로 초기화 
//Singletons::getInstance()->Many = UserDefault::getInstance()->getIntegerForKey("Many");
//UserDefault::getInstance()->flush();
