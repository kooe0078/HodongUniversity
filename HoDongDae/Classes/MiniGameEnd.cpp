#include "MiniGameEnd.h"
#include "SimpleAudioEngine.h"
#include "NextDayScene.h"
#include "sinngleton.h"
//사운드 할라면 꼭 필요
using namespace CocosDenshion;
USING_NS_CC;

Scene* MiniGameEnd::createScene()
{
    auto scene = Scene::create();
    auto layer = MiniGameEnd::create();
    scene->addChild(layer);

    return scene;
}

bool MiniGameEnd::init()
{

    if ( !Layer::init() )
    {
        return false;
    }
	
	InitBackGround();
	initLabel();
	Menuitem();

	//배경음악
	//SimpleAudioEngine::getInstance()->playBackgroundMusic("MiniGameResources/MiniGameEndMusic.mp3", true);

    return true;
}
void MiniGameEnd::update(float ft)
{
	//씬 자체적으로 반복 되야하는 내용
}
void MiniGameEnd::InitBackGround()
{
	auto spr = CCSprite::create("ServiceMiniGame/volunteer.png");
	spr->setPosition(Point(512, 384));
	this->addChild(spr, 0);

	Sprite* overSpr = Sprite::create("QuizGame/Back.png");
	overSpr->setAnchorPoint(Point(0.5, 0.5));
	overSpr->setPosition(Point(512, 384));
	overSpr->setTag(548);
	this->addChild(overSpr, 0);
}
void MiniGameEnd::initLabel() // 정답 :
{
	char Q1[200];
	WideCharToMultiByte(CP_UTF8, 0, L"개수 : ", -1, Q1, 200, NULL, NULL);
	auto Quiz = Label::createWithTTF(Q1, "QuizGame/ABC.ttf", 27);
	Quiz->setAnchorPoint(Point(0, 1));
	Quiz->setPosition(Point(350, 650));
	Quiz->setTag(549);
	Quiz->setColor(Color3B::BLACK);
	this->addChild(Quiz);

	auto label_0 = Label::create("", "QuizGame/ABC.ttf", 27);
	label_0->setAnchorPoint(Point(0, 1));
	label_0->setPosition(Point(500, 650));
	label_0->setTag(550);
	label_0->setColor(Color3B::RED);
	this->addChild(label_0);

	setAnswer();
}
void MiniGameEnd::setAnswer() // 정답 개수
{
	auto label = (Label*)this->getChildByTag(550);
	label->setString(StringUtils::format("%d", Singletons::getInstance()->GameScore));
}
void MiniGameEnd::Menuitem() // 확인 버튼
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);
	auto Back = MenuItemImage::create(
		"QuizGame/UI_enter.png",
		"QuizGame/UI_enterpr.png",
		CC_CALLBACK_1(MiniGameEnd::Check_0, this));
	Back->setPosition(Point(512, 250));

	auto menu1 = Menu::create(Back, NULL);
	menu1->setPosition(Vec2::ZERO);
	menu1->setTag(551);
	this->addChild(menu1, 2);
}
void MiniGameEnd::Check_0(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);

	removeChildByTag(550);
	removeChildByTag(551);
	removeChildByTag(549);
	removeChildByTag(548);

	if (Singletons::getInstance()->bongnum == 1)
	{
		if (Singletons::getInstance()->GameScore <= 69)
		{


			char MyString[100];
			WideCharToMultiByte(CP_UTF8, 0, L"호동: 좀 더 노력할걸;;\n\n(인성을 6획득하였습니다.)", -1, MyString, 100, NULL, NULL);
			auto name = Label::createWithTTF(MyString, "fonts/Bold.ttf", 30);
			name->setAnchorPoint(Point(0, 1));
			name->setPosition(Point(40, 150));
			name->setColor(Color3B::WHITE);
			name->setTag(20);
			this->addChild(name, 3);

			auto storyA_item = MenuItemImage::create(
				"MiniGameResources/UI_Textlblack.png",
				"MiniGameResources/UI_Textlblack.png",

				CC_CALLBACK_1(MiniGameEnd::storyAspr, this));
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
				CC_CALLBACK_1(MiniGameEnd::Check_1, this));
			textA_item->setAnchorPoint(Point(0.5, 0.5));
			textA_item->setPosition(Point(950, 65));

			auto text = Menu::create(textA_item, NULL);
			text->setAnchorPoint(Point(0.5, 0.5));
			text->setPosition(Point(0, 0));
			text->setTag(130);
			this->addChild(text, 5);


			Singletons::getInstance()->m_insung = Singletons::getInstance()->m_insung + 6;
		}

		if (Singletons::getInstance()->GameScore >= 70)
		{
			char MyString[100];
			WideCharToMultiByte(CP_UTF8, 0, L"호동: 공원이 더 깨끗해진 느낌인걸?\n\n(인성을 10획득하였습니다.)", -1, MyString, 100, NULL, NULL);
			auto name = Label::createWithTTF(MyString, "fonts/Bold.ttf", 30);
			name->setAnchorPoint(Point(0, 1));
			name->setPosition(Point(40, 150));
			name->setColor(Color3B::WHITE);
			name->setTag(20);
			this->addChild(name, 3);

			auto storyA_item = MenuItemImage::create(
				"MiniGameResources/UI_Textlblack.png",
				"MiniGameResources/UI_Textlblack.png",

				CC_CALLBACK_1(MiniGameEnd::storyAspr, this));
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
				CC_CALLBACK_1(MiniGameEnd::Check_1, this));
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
		Singletons::getInstance()->bongnum = 0;
	}
	
	if (Singletons::getInstance()->bongnum == 2)
	{
		if (Singletons::getInstance()->GameScore <= 69)
		{


			char MyString[200];
			WideCharToMultiByte(CP_UTF8, 0, L"호동: 오늘은 그다지 노력하지 못한것같아.\n\n(인성을 8획득하였습니다.)", -1, MyString, 200, NULL, NULL);
			auto name = Label::createWithTTF(MyString, "fonts/Bold.ttf", 30);
			name->setAnchorPoint(Point(0, 1));
			name->setPosition(Point(40, 150));
			name->setColor(Color3B::WHITE);
			name->setTag(20);
			this->addChild(name, 3);

			auto storyA_item = MenuItemImage::create(
				"MiniGameResources/UI_Textlblack.png",
				"MiniGameResources/UI_Textlblack.png",

				CC_CALLBACK_1(MiniGameEnd::storyAspr, this));
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
				CC_CALLBACK_1(MiniGameEnd::Check_1, this));
			textA_item->setAnchorPoint(Point(0.5, 0.5));
			textA_item->setPosition(Point(950, 65));

			auto text = Menu::create(textA_item, NULL);
			text->setAnchorPoint(Point(0.5, 0.5));
			text->setPosition(Point(0, 0));
			text->setTag(130);
			this->addChild(text, 5);


			Singletons::getInstance()->m_insung = Singletons::getInstance()->m_insung + 8;
		}

		if (Singletons::getInstance()->GameScore >= 70)
		{
			char MyString[200];
			WideCharToMultiByte(CP_UTF8, 0, L"호동: 힘든 하루였지만 환경을 위해서라면 이정도쯤이야!\n\n(인성을 12획득하였습니다.)", -1, MyString, 200, NULL, NULL);
			auto name = Label::createWithTTF(MyString, "fonts/Bold.ttf", 30);
			name->setAnchorPoint(Point(0, 1));
			name->setPosition(Point(40, 150));
			name->setColor(Color3B::WHITE);
			name->setTag(20);
			this->addChild(name, 3);

			auto storyA_item = MenuItemImage::create(
				"MiniGameResources/UI_Textlblack.png",
				"MiniGameResources/UI_Textlblack.png",

				CC_CALLBACK_1(MiniGameEnd::storyAspr, this));
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
				CC_CALLBACK_1(MiniGameEnd::Check_1, this));
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

			Singletons::getInstance()->m_insung = Singletons::getInstance()->m_insung + 12;
		}
		Singletons::getInstance()->bongnum = 0;
	}

	if (Singletons::getInstance()->bongnum == 3)
	{
		if (Singletons::getInstance()->GameScore <= 69)
		{


			char MyString[200];
			WideCharToMultiByte(CP_UTF8, 0, L"호동: 한 것도 없는데 너무 피곤해... 빨리가서 자야겠어...\n\n(인성을 10획득하였습니다.)", -1, MyString, 200, NULL, NULL);
			auto name = Label::createWithTTF(MyString, "fonts/Bold.ttf", 30);
			name->setAnchorPoint(Point(0, 1));
			name->setPosition(Point(40, 150));
			name->setColor(Color3B::WHITE);
			name->setTag(20);
			this->addChild(name, 3);

			auto storyA_item = MenuItemImage::create(
				"MiniGameResources/UI_Textlblack.png",
				"MiniGameResources/UI_Textlblack.png",

				CC_CALLBACK_1(MiniGameEnd::storyAspr, this));
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
				CC_CALLBACK_1(MiniGameEnd::Check_1, this));
			textA_item->setAnchorPoint(Point(0.5, 0.5));
			textA_item->setPosition(Point(950, 65));

			auto text = Menu::create(textA_item, NULL);
			text->setAnchorPoint(Point(0.5, 0.5));
			text->setPosition(Point(0, 0));
			text->setTag(130);
			this->addChild(text, 5);


			Singletons::getInstance()->m_insung = Singletons::getInstance()->m_insung + 10;
		}

		if (Singletons::getInstance()->GameScore >= 70)
		{
			char MyString[100];
			WideCharToMultiByte(CP_UTF8, 0, L"호동: 너무 뿌듯하다! 다음에 또 와야겠어! \n\n(인성을 14획득하였습니다.)", -1, MyString, 100, NULL, NULL);
			auto name = Label::createWithTTF(MyString, "fonts/Bold.ttf", 30);
			name->setAnchorPoint(Point(0, 1));
			name->setPosition(Point(40, 150));
			name->setColor(Color3B::WHITE);
			name->setTag(20);
			this->addChild(name, 3);

			auto storyA_item = MenuItemImage::create(
				"MiniGameResources/UI_Textlblack.png",
				"MiniGameResources/UI_Textlblack.png",

				CC_CALLBACK_1(MiniGameEnd::storyAspr, this));
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
				CC_CALLBACK_1(MiniGameEnd::Check_1, this));
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

			Singletons::getInstance()->m_insung = Singletons::getInstance()->m_insung + 14;
		}
		Singletons::getInstance()->bongnum = 0;
	}
	
}
void MiniGameEnd::Check_1(Ref *pSender) // 메인화면으로
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);

	Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
	Director::getInstance()->replaceScene(NextDayScene::createScene());

	UserDefault::getInstance()->setIntegerForKey("Qnum", 0); // Qnum을 0으로 초기화 
	Singletons::getInstance()->Qnum = UserDefault::getInstance()->getIntegerForKey("Qnum");
	UserDefault::getInstance()->flush();

	UserDefault::getInstance()->setIntegerForKey("Answer", 0); // Answer을 0으로 초기화
	Singletons::getInstance()->Answer = UserDefault::getInstance()->getIntegerForKey("Answer");
	UserDefault::getInstance()->flush();

	UserDefault::getInstance()->setIntegerForKey("GameScore", 30); // GameScore을 30으로 초기화
	Singletons::getInstance()->GameScore = UserDefault::getInstance()->getIntegerForKey("GameScore");
	UserDefault::getInstance()->flush();
}

void MiniGameEnd::storyAspr(Ref *pSender)
{

}