#include "ParkTalk.h"
#include "SimpleAudioEngine.h"
#include "sinngleton.h"
#include "NextDayScene.h"
//사운드 할라면 꼭 필요
using namespace CocosDenshion;
USING_NS_CC;

Scene* ParkTalk::createScene()
{
    auto scene = Scene::create();
    auto layer = ParkTalk::create();
    scene->addChild(layer);

    return scene;
}

bool ParkTalk::init()
{

    if ( !Layer::init() )
    {
        return false;
    }

	visibleSize = Director::getInstance()->getVisibleSize();
	origin      = Director::getInstance()->getVisibleOrigin();

	InitBackGround();
	InitMenu();

	//배경음악
	//SimpleAudioEngine::getInstance()->playBackgroundMusic("ParkTalk/IntroBackSound.mp3", true);

    return true;
}
void ParkTalk::InitBackGround()
{
	auto sprite = Sprite::create("ParkTalk/bongsa.png");
	sprite->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	this->addChild(sprite, 0);
}
// 인트로 선택창
void ParkTalk::InitMenu()
{
	
	int i, num;

	srand((double)time(NULL));
	for (i = 0; i < 1; i++)
	{
		num = rand() % 7 + 1;
	}
	
	// 한동진 대화 1
	if (num == 1)
	{
		auto textA_item = MenuItemImage::create(
			"ParkTalk/ok_button.png",
			"ParkTalk/ok_buttonpr.png",
			CC_CALLBACK_1(ParkTalk::storyA, this));
		textA_item->setAnchorPoint(Point(0.5, 0.5));
		textA_item->setPosition(Point(950, 65));

		auto text = Menu::create(textA_item, NULL);
		text->setAnchorPoint(Point(0.5, 0.5));
		text->setPosition(Point(0, 0));
		text->setTag(130);
		this->addChild(text, 5);

	}
	// 한동진 대화 2
	if (num == 2)
	{
		auto textA_item = MenuItemImage::create(
			"ParkTalk/ok_button.png",
			"ParkTalk/ok_buttonpr.png",
			CC_CALLBACK_1(ParkTalk::storyA_1, this));
		textA_item->setAnchorPoint(Point(0.5, 0.5));
		textA_item->setPosition(Point(950, 65));

		auto text = Menu::create(textA_item, NULL);
		text->setAnchorPoint(Point(0.5, 0.5));
		text->setPosition(Point(0, 0));
		text->setTag(130);
		this->addChild(text, 5);
	}
	// 정찬돈 대화 1
	if (num == 3)
	{
		auto textA_item = MenuItemImage::create(
			"ParkTalk/ok_button.png",
			"ParkTalk/ok_buttonpr.png",
			CC_CALLBACK_1(ParkTalk::storyB, this));
		textA_item->setAnchorPoint(Point(0.5, 0.5));
		textA_item->setPosition(Point(950, 65));

		auto text = Menu::create(textA_item, NULL);
		text->setAnchorPoint(Point(0.5, 0.5));
		text->setPosition(Point(0, 0));
		text->setTag(130);
		this->addChild(text, 5);
	}
	// 정찬돈 대화 2
	if (num == 4)
	{
		auto textA_item = MenuItemImage::create(
			"ParkTalk/ok_button.png",
			"ParkTalk/ok_buttonpr.png",
			CC_CALLBACK_1(ParkTalk::storyB_1, this));
		textA_item->setAnchorPoint(Point(0.5, 0.5));
		textA_item->setPosition(Point(950, 65));

		auto text = Menu::create(textA_item, NULL);
		text->setAnchorPoint(Point(0.5, 0.5));
		text->setPosition(Point(0, 0));
		text->setTag(130);
		this->addChild(text, 5);
	}
	// 제이윌 대화 1
	if (num == 5)
	{
		auto textA_item = MenuItemImage::create(
			"ParkTalk/ok_button.png",
			"ParkTalk/ok_buttonpr.png",
			CC_CALLBACK_1(ParkTalk::storyC, this));
		textA_item->setAnchorPoint(Point(0.5, 0.5));
		textA_item->setPosition(Point(950, 65));

		auto text = Menu::create(textA_item, NULL);
		text->setAnchorPoint(Point(0.5, 0.5));
		text->setPosition(Point(0, 0));
		text->setTag(130);
		this->addChild(text, 5);
	}
	// 제이윌 대화 2
	if (num == 6)
	{
		auto textA_item = MenuItemImage::create(
			"ParkTalk/ok_button.png",
			"ParkTalk/ok_buttonpr.png",
			CC_CALLBACK_1(ParkTalk::storyC_1, this));
		textA_item->setAnchorPoint(Point(0.5, 0.5));
		textA_item->setPosition(Point(950, 65));

		auto text = Menu::create(textA_item, NULL);
		text->setAnchorPoint(Point(0.5, 0.5));
		text->setPosition(Point(0, 0));
		text->setTag(130);
		this->addChild(text, 5);
	}
	// 독백
	if (num == 7)
	{
		auto textA_item = MenuItemImage::create(
			"ParkTalk/ok_button.png",
			"ParkTalk/ok_buttonpr.png",
			CC_CALLBACK_1(ParkTalk::storyD, this));
		textA_item->setAnchorPoint(Point(0.5, 0.5));
		textA_item->setPosition(Point(950, 65));

		auto text = Menu::create(textA_item, NULL);
		text->setAnchorPoint(Point(0.5, 0.5));
		text->setPosition(Point(0, 0));
		text->setTag(130);
		this->addChild(text, 5);
	}
	
	// 텍스트 창
	auto sprite = Sprite::create("ParkTalk/UI_Textlblack.png");
	sprite->setAnchorPoint(Point(0.5, 0.5));
	sprite->setPosition(Point(510, 100));
	sprite->setTag(200);
	this->addChild(sprite, 2);

	// 메인 캐릭터
	Sprite* mainchr = Sprite::create("ParkTalk/main_char.png");
	mainchr->setAnchorPoint(Point(0.5, 0));
	mainchr->setPosition(Point(120, 80));
	mainchr->setTag(166);
	this->addChild(mainchr, 1);

	char MyString[200];
	WideCharToMultiByte(CP_UTF8, 0, L"호동: 가끔 이렇게 산책하는것도 나쁘지않군.", -1, MyString, 200, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "ParkTalk/Bold.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(21);
	this->addChild(name, 3);
}
// 한동진 대화씬 1
void ParkTalk::storyA(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);

	removeChildByTag(130);
	removeChildByTag(21);

	char MyString[100];
	WideCharToMultiByte(CP_UTF8, 0, L"(한동진을 만났다.)", -1, MyString, 100, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "ParkTalk/Bold.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(21);
	this->addChild(name, 3);

	
	auto textA_item = MenuItemImage::create(
		"ParkTalk/ok_button.png",
		"ParkTalk/ok_buttonpr.png",
		CC_CALLBACK_1(ParkTalk::storyAA, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(131);
	this->addChild(text, 5);

	Sprite* mainchr = Sprite::create("ParkTalk/park_chara1.png");
	mainchr->setAnchorPoint(Point(0.5, 0));
	mainchr->setPosition(Point(800, 0));
	mainchr->setTag(231);
	this->addChild(mainchr, 1);
}
void ParkTalk::storyAA(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);

	removeChildByTag(131);
	removeChildByTag(21);

	char MyString[100];
	WideCharToMultiByte(CP_UTF8, 0, L"호동 : 안녕하세요 동진이형!", -1, MyString, 100, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "ParkTalk/Bold.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(22);
	this->addChild(name, 3);


	auto textA_item = MenuItemImage::create(
		"ParkTalk/ok_button.png",
		"ParkTalk/ok_buttonpr.png",
		CC_CALLBACK_1(ParkTalk::storyAAA, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(132);
	this->addChild(text, 5);

}
void ParkTalk::storyAAA(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);

	removeChildByTag(132);
	removeChildByTag(22);

	char MyString[100];
	WideCharToMultiByte(CP_UTF8, 0, L"동진 : 어 그래. 호동이구나!", -1, MyString, 100, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "ParkTalk/Bold.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(23);
	this->addChild(name, 3);


	auto textA_item = MenuItemImage::create(
		"ParkTalk/ok_button.png",
		"ParkTalk/ok_buttonpr.png",
		CC_CALLBACK_1(ParkTalk::storyAAAA, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(133);
	this->addChild(text, 5);
}
void ParkTalk::storyAAAA(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);

	removeChildByTag(133);
	removeChildByTag(23);

	char MyString[100];
	WideCharToMultiByte(CP_UTF8, 0, L"호동 : 여기서 뭐하세요?", -1, MyString, 100, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "ParkTalk/Bold.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(24);
	this->addChild(name, 3);

	
	auto textA_item = MenuItemImage::create(
		"ParkTalk/ok_button.png",
		"ParkTalk/ok_buttonpr.png",
		CC_CALLBACK_1(ParkTalk::storyAAAAA, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(134);
	this->addChild(text, 5);
}
void ParkTalk::storyAAAAA(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);

	removeChildByTag(134);
	removeChildByTag(24);

	char MyString[400];
	WideCharToMultiByte(CP_UTF8, 0, L"동진 : 책 읽고있었지. 책은 마음의 양식이라고 하잖아?\n너도 시간날 때 이렇게 책이나 읽어봐.", -1, MyString, 400, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "ParkTalk/Bold.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(25);
	this->addChild(name, 3);


	auto textA_item = MenuItemImage::create(
		"ParkTalk/ok_button.png",
		"ParkTalk/ok_buttonpr.png",
		CC_CALLBACK_1(ParkTalk::storyAAAAAA, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(135);
	this->addChild(text, 5);
}
void ParkTalk::storyAAAAAA(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);

	removeChildByTag(135);
	removeChildByTag(25);

	char MyString[100];
	WideCharToMultiByte(CP_UTF8, 0, L"호동 : 네...", -1, MyString, 100, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "ParkTalk/Bold.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(26);
	this->addChild(name, 3);


	auto textA_item = MenuItemImage::create(
		"ParkTalk/ok_button.png",
		"ParkTalk/ok_buttonpr.png",
		CC_CALLBACK_1(ParkTalk::storyAAAAAAA, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(136);
	this->addChild(text, 5);
}
void ParkTalk::storyAAAAAAA(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);

	removeChildByTag(136);
	removeChildByTag(26);

	char MyString[100];
	WideCharToMultiByte(CP_UTF8, 0, L"(품격이 느껴졌어.)\n\n (친밀도가 12 증가하였습니다.)", -1, MyString, 100, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "ParkTalk/Bold.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(26);
	this->addChild(name, 3);


	auto textA_item = MenuItemImage::create(
		"ParkTalk/ok_button.png",
		"ParkTalk/ok_buttonpr.png",
		CC_CALLBACK_1(ParkTalk::GoHome, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(136);
	this->addChild(text, 5);

	Singletons::getInstance()->m_friendly = Singletons::getInstance()->m_friendly + 12;
}
// 한동진 대화씬 2
void ParkTalk::storyA_1(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);

	//모하니 대화씬1
	removeChildByTag(130);
	removeChildByTag(21);

	char MyString[100];
	WideCharToMultiByte(CP_UTF8, 0, L"(한동진을 만났다.)", -1, MyString, 100, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "ParkTalk/Bold.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(21);
	this->addChild(name, 3);


	auto textA_item = MenuItemImage::create(
		"ParkTalk/ok_button.png",
		"ParkTalk/ok_buttonpr.png",
		CC_CALLBACK_1(ParkTalk::storyAA_1, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(131);
	this->addChild(text, 5);

	Sprite* mainchr = Sprite::create("ParkTalk/park_chara1.png");
	mainchr->setAnchorPoint(Point(0.5, 0));
	mainchr->setPosition(Point(800, 0));
	mainchr->setTag(231);
	this->addChild(mainchr, 1);
}
void ParkTalk::storyAA_1(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);

	removeChildByTag(131);
	removeChildByTag(21);
	char MyString[500];
	WideCharToMultiByte(CP_UTF8, 0, L"동진 : 호동아. '그 사람은 인격은 그가 읽은 책으로 알 수 있다.'라는 \n스마일즈의 말이 있잖아?\n너도 책을 읽어보는게 어떠니 호동아?", -1, MyString, 500, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "ParkTalk/Bold.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(22);
	this->addChild(name, 3);


	auto textA_item = MenuItemImage::create(
		"ParkTalk/ok_button.png",
		"ParkTalk/ok_buttonpr.png",
		CC_CALLBACK_1(ParkTalk::storyAAA_1, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(132);
	this->addChild(text, 5);
}
void ParkTalk::storyAAA_1(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);

	removeChildByTag(132);
	removeChildByTag(22);

	char MyString[200];
	WideCharToMultiByte(CP_UTF8, 0, L"호동 : 저도 책 읽고 있거든요? (물론 만화책이지만...)", -1, MyString, 200, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "ParkTalk/Bold.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(23);
	this->addChild(name, 3);


	auto textA_item = MenuItemImage::create(
		"ParkTalk/ok_button.png",
		"ParkTalk/ok_buttonpr.png",
		CC_CALLBACK_1(ParkTalk::storyAAAA_1, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(133);
	this->addChild(text, 5);
}
void ParkTalk::storyAAAA_1(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);

	removeChildByTag(133);
	removeChildByTag(23);

	char MyString[300];
	WideCharToMultiByte(CP_UTF8, 0, L"동진 : 그래? 그럼 최근에 읽은 책중에 기억에 남는 구절을 말해줄래?", -1, MyString, 300, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "ParkTalk/Bold.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(24);
	this->addChild(name, 3);


	auto textA_item = MenuItemImage::create(
		"ParkTalk/ok_button.png",
		"ParkTalk/ok_buttonpr.png",
		CC_CALLBACK_1(ParkTalk::storyAAAAA_1, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(134);
	this->addChild(text, 5);
}
void ParkTalk::storyAAAAA_1(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);

	removeChildByTag(134);
	removeChildByTag(24);

	char MyString[300];
	WideCharToMultiByte(CP_UTF8, 0, L"호동 : 음... '모든 모험은 첫 걸음을 필요로 하지.'라는 말이 기억에 남네요.", -1, MyString, 300, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "ParkTalk/Bold.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(25);
	this->addChild(name, 3);


	auto textA_item = MenuItemImage::create(
		"ParkTalk/ok_button.png",
		"ParkTalk/ok_buttonpr.png",
		CC_CALLBACK_1(ParkTalk::storyAAAAAA_1, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(135);
	this->addChild(text, 5);
}
void ParkTalk::storyAAAAAA_1(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);

	removeChildByTag(135);
	removeChildByTag(25);

	char MyString[200];
	WideCharToMultiByte(CP_UTF8, 0, L"동진 : 정말 좋은 말인걸! 개권유익 했구나!", -1, MyString, 200, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "ParkTalk/Bold.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(26);
	this->addChild(name, 3);


	auto textA_item = MenuItemImage::create(
		"ParkTalk/ok_button.png",
		"ParkTalk/ok_buttonpr.png",
		CC_CALLBACK_1(ParkTalk::storyAAAAAAA_1, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(136);
	this->addChild(text, 5);
}
void ParkTalk::storyAAAAAAA_1(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);

	removeChildByTag(136);
	removeChildByTag(26);

	char MyString[400];
	WideCharToMultiByte(CP_UTF8, 0, L"호동 : 으...응 (무슨말인지 모르겠지만 일단 아는 척해야겠다.\n책 좀 읽어야겠는걸?)\n\n (친밀도가 10 증가하였습니다.)", -1, MyString, 400, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "ParkTalk/Bold.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(26);
	this->addChild(name, 3);


	auto textA_item = MenuItemImage::create(
		"ParkTalk/ok_button.png",
		"ParkTalk/ok_buttonpr.png",
		CC_CALLBACK_1(ParkTalk::GoHome, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(136);
	this->addChild(text, 5);

	Singletons::getInstance()->m_friendly = Singletons::getInstance()->m_friendly + 10;
}
// 정찬돈 대화씬 1
void ParkTalk::storyB(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);

	removeChildByTag(130);
	removeChildByTag(21);

	char MyString[100];
	WideCharToMultiByte(CP_UTF8, 0, L"(정찬돈를 만났다.)", -1, MyString, 100, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "ParkTalk/Bold.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(21);
	this->addChild(name, 3);


	auto textA_item = MenuItemImage::create(
		"ParkTalk/ok_button.png",
		"ParkTalk/ok_buttonpr.png",
		CC_CALLBACK_1(ParkTalk::storyBB, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(131);
	this->addChild(text, 5);

	Sprite* mainchr = Sprite::create("ParkTalk/park_chara2.png");
	mainchr->setAnchorPoint(Point(0.5, 0));
	mainchr->setPosition(Point(800, 0));
	mainchr->setTag(231);
	this->addChild(mainchr, 1);
}
void ParkTalk::storyBB(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);

	removeChildByTag(131);
	removeChildByTag(21);
	char MyString[100];
	WideCharToMultiByte(CP_UTF8, 0, L"호동: 안녕하세요 삼촌.", -1, MyString, 100, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "ParkTalk/Bold.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(22);
	this->addChild(name, 3);


	auto textA_item = MenuItemImage::create(
		"ParkTalk/ok_button.png",
		"ParkTalk/ok_buttonpr.png",
		CC_CALLBACK_1(ParkTalk::storyBBB, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(132);
	this->addChild(text, 5);
}
void ParkTalk::storyBBB(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);

	removeChildByTag(132);
	removeChildByTag(22);

	char MyString[200];
	WideCharToMultiByte(CP_UTF8, 0, L"찬돈 : 호동이구나! 날씨 정말 좋지 않니?", -1, MyString, 200, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "ParkTalk/Bold.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(23);
	this->addChild(name, 3);


	auto textA_item = MenuItemImage::create(
		"ParkTalk/ok_button.png",
		"ParkTalk/ok_buttonpr.png",
		CC_CALLBACK_1(ParkTalk::storyBBBB, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(133);
	this->addChild(text, 5);
}
void ParkTalk::storyBBBB(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);

	removeChildByTag(133);
	removeChildByTag(23);

	char MyString[100];
	WideCharToMultiByte(CP_UTF8, 0, L"호동 : 강아지랑 산책하시는 거에요?", -1, MyString, 100, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "ParkTalk/Bold.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(24);
	this->addChild(name, 3);


	auto textA_item = MenuItemImage::create(
		"ParkTalk/ok_button.png",
		"ParkTalk/ok_buttonpr.png",
		CC_CALLBACK_1(ParkTalk::storyBBBBB, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(134);
	this->addChild(text, 5);
}
void ParkTalk::storyBBBBB(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);

	removeChildByTag(134);
	removeChildByTag(24);

	char MyString[100];
	WideCharToMultiByte(CP_UTF8, 0, L"찬돈 : 그래. 킬러비가 나가고 싶다고 해서.", -1, MyString, 100, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "ParkTalk/Bold.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(25);
	this->addChild(name, 3);


	auto textA_item = MenuItemImage::create(
		"ParkTalk/ok_button.png",
		"ParkTalk/ok_buttonpr.png",
		CC_CALLBACK_1(ParkTalk::storyBBBBBB, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(135);
	this->addChild(text, 5);
}
void ParkTalk::storyBBBBBB(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);

	removeChildByTag(135);
	removeChildByTag(25);

	char MyString[100];
	WideCharToMultiByte(CP_UTF8, 0, L"호동 : 안녕 킬러비~", -1, MyString, 100, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "ParkTalk/Bold.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(26);
	this->addChild(name, 3);


	auto textA_item = MenuItemImage::create(
		"ParkTalk/ok_button.png",
		"ParkTalk/ok_buttonpr.png",
		CC_CALLBACK_1(ParkTalk::storyBBBBBBB, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(136);
	this->addChild(text, 5);
}
void ParkTalk::storyBBBBBBB(Ref * pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);

	removeChildByTag(136);
	removeChildByTag(26);

	char MyString[100];
	WideCharToMultiByte(CP_UTF8, 0, L"킬러비 : 컹컹!\n\n(친밀도가 12 상승하였습니다.)", -1, MyString, 100, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "ParkTalk/Bold.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(27);
	this->addChild(name, 3);


	auto textA_item = MenuItemImage::create(
		"ParkTalk/ok_button.png",
		"ParkTalk/ok_buttonpr.png",
		CC_CALLBACK_1(ParkTalk::GoHome, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(137);
	this->addChild(text, 5);

	Singletons::getInstance()->m_friendly = Singletons::getInstance()->m_friendly + 12;
}
 // 정찬돈 대화씬 2
void ParkTalk::storyB_1(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);

	removeChildByTag(130);
	removeChildByTag(21);

	char MyString[200];
	WideCharToMultiByte(CP_UTF8, 0, L"(무언가 커다란 물체가 돌진해왔다!!)", -1, MyString, 200, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "ParkTalk/Bold.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(21);
	this->addChild(name, 3);


	auto textA_item = MenuItemImage::create(
		"ParkTalk/ok_button.png",
		"ParkTalk/ok_buttonpr.png",
		CC_CALLBACK_1(ParkTalk::storyBB_1, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(131);
	this->addChild(text, 5);

	Sprite* mainchr = Sprite::create("ParkTalk/park_chara2.png");
	mainchr->setAnchorPoint(Point(0.5, 0));
	mainchr->setPosition(Point(800, 0));
	mainchr->setTag(231);
	this->addChild(mainchr, 1);
}
void ParkTalk::storyBB_1(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);

	removeChildByTag(131);
	removeChildByTag(21);
	char MyString[100];
	WideCharToMultiByte(CP_UTF8, 0, L"킬러비 : 컹컹!", -1, MyString, 100, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "ParkTalk/Bold.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(22);
	this->addChild(name, 3);


	auto textA_item = MenuItemImage::create(
		"ParkTalk/ok_button.png",
		"ParkTalk/ok_buttonpr.png",
		CC_CALLBACK_1(ParkTalk::storyBBB_1, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(132);
	this->addChild(text, 5);
}
void ParkTalk::storyBBB_1(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);

	removeChildByTag(132);
	removeChildByTag(22);

	char MyString[100];
	WideCharToMultiByte(CP_UTF8, 0, L"호동 : 우왁! 깜짝이야 킬러비잖아?", -1, MyString, 100, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "ParkTalk/Bold.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(23);
	this->addChild(name, 3);


	auto textA_item = MenuItemImage::create(
		"ParkTalk/ok_button.png",
		"ParkTalk/ok_buttonpr.png",
		CC_CALLBACK_1(ParkTalk::storyBBBB_1, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(133);
	this->addChild(text, 5);
}
void ParkTalk::storyBBBB_1(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);

	removeChildByTag(133);
	removeChildByTag(23);

	char MyString[100];
	WideCharToMultiByte(CP_UTF8, 0, L"킬러비 : 헥헥헥..", -1, MyString, 100, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "ParkTalk/Bold.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(24);
	this->addChild(name, 3);


	auto textA_item = MenuItemImage::create(
		"ParkTalk/ok_button.png",
		"ParkTalk/ok_buttonpr.png",
		CC_CALLBACK_1(ParkTalk::storyBBBBB_1, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(134);
	this->addChild(text, 5);
}
void ParkTalk::storyBBBBB_1(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);

	removeChildByTag(134);
	removeChildByTag(24);

	char MyString[100];
	WideCharToMultiByte(CP_UTF8, 0, L"호동 : 뭐야 도망쳐나온거야?", -1, MyString, 100, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "ParkTalk/Bold.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(25);
	this->addChild(name, 3);


	auto textA_item = MenuItemImage::create(
		"ParkTalk/ok_button.png",
		"ParkTalk/ok_buttonpr.png",
		CC_CALLBACK_1(ParkTalk::storyBBBBB_2, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(135);
	this->addChild(text, 5);
}
void ParkTalk::storyBBBBB_2(Ref * pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);

	removeChildByTag(135);
	removeChildByTag(25);

	char MyString[300];
	WideCharToMultiByte(CP_UTF8, 0, L"찬돈 : 헉헉... 호동아 네가 잡아줬구나. 녀석이 갑자기 뛰어가서...", -1, MyString, 300, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "ParkTalk/Bold.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(26);
	this->addChild(name, 3);


	auto textA_item = MenuItemImage::create(
		"ParkTalk/ok_button.png",
		"ParkTalk/ok_buttonpr.png",
		CC_CALLBACK_1(ParkTalk::storyBBBBB_3, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(136);
	this->addChild(text, 5);
}
void ParkTalk::storyBBBBB_3(Ref * pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);

	removeChildByTag(136);
	removeChildByTag(26);

	char MyString[300];
	WideCharToMultiByte(CP_UTF8, 0, L"호동 : 하하.. 활기차네요. 다음부턴 꽉잡으세요~\n\n(친밀도가 11 상승하였습니다.)", -1, MyString, 300, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "ParkTalk/Bold.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(27);
	this->addChild(name, 3);


	auto textA_item = MenuItemImage::create(
		"ParkTalk/ok_button.png",
		"ParkTalk/ok_buttonpr.png",
		CC_CALLBACK_1(ParkTalk::GoHome, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(137);
	this->addChild(text, 5);

	Singletons::getInstance()->m_friendly = Singletons::getInstance()->m_friendly + 11;
}
 // 제이윌 대화씬 1
void ParkTalk::storyC(Ref * pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);

	removeChildByTag(130);
	removeChildByTag(21);

	char MyString[200];
	WideCharToMultiByte(CP_UTF8, 0, L"(제이윌을 만났다.)", -1, MyString, 200, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "ParkTalk/Bold.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(21);
	this->addChild(name, 3);


	auto textA_item = MenuItemImage::create(
		"ParkTalk/ok_button.png",
		"ParkTalk/ok_buttonpr.png",
		CC_CALLBACK_1(ParkTalk::storyC1, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(131);
	this->addChild(text, 5);

	Sprite* mainchr = Sprite::create("ParkTalk/park_chara3.png");
	mainchr->setAnchorPoint(Point(0.5, 0));
	mainchr->setPosition(Point(800, 0));
	mainchr->setTag(231);
	this->addChild(mainchr, 1);
}
void ParkTalk::storyC1(Ref * pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);

	removeChildByTag(131);
	removeChildByTag(21);
	char MyString[100];
	WideCharToMultiByte(CP_UTF8, 0, L"제이윌 : 흑흑...", -1, MyString, 100, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "ParkTalk/Bold.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(22);
	this->addChild(name, 3);


	auto textA_item = MenuItemImage::create(
		"ParkTalk/ok_button.png",
		"ParkTalk/ok_buttonpr.png",
		CC_CALLBACK_1(ParkTalk::storyC2, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(132);
	this->addChild(text, 5);
}
void ParkTalk::storyC2(Ref * pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);

	removeChildByTag(132);
	removeChildByTag(22);

	char MyString[100];
	WideCharToMultiByte(CP_UTF8, 0, L"호동 : 무슨 일이에요?", -1, MyString, 100, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "ParkTalk/Bold.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(23);
	this->addChild(name, 3);


	auto textA_item = MenuItemImage::create(
		"ParkTalk/ok_button.png",
		"ParkTalk/ok_buttonpr.png",
		CC_CALLBACK_1(ParkTalk::storyC3, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(133);
	this->addChild(text, 5);
}
void ParkTalk::storyC3(Ref * pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);

	removeChildByTag(133);
	removeChildByTag(23);

	char MyString[200];
	WideCharToMultiByte(CP_UTF8, 0, L"제이윌 : 실연이야... 이 마음 어떻게하면 좋겠니...", -1, MyString, 200, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "ParkTalk/Bold.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(24);
	this->addChild(name, 3);


	auto textA_item = MenuItemImage::create(
		"ParkTalk/ok_button.png",
		"ParkTalk/ok_buttonpr.png",
		CC_CALLBACK_1(ParkTalk::storyC4, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(134);
	this->addChild(text, 5);
}
void ParkTalk::storyC4(Ref * pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);

	removeChildByTag(134);
	removeChildByTag(24);

	char MyString[200];
	WideCharToMultiByte(CP_UTF8, 0, L"호동 : 제가 해드릴 수 있는 말이없네요..", -1, MyString, 200, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "ParkTalk/Bold.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(25);
	this->addChild(name, 3);


	auto textA_item = MenuItemImage::create(
		"ParkTalk/ok_button.png",
		"ParkTalk/ok_buttonpr.png",
		CC_CALLBACK_1(ParkTalk::storyC5, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(135);
	this->addChild(text, 5);
}
void ParkTalk::storyC5(Ref * pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);

	removeChildByTag(135);
	removeChildByTag(25);

	char MyString[400];
	WideCharToMultiByte(CP_UTF8, 0, L"제이윌 : 그래... 아 이 마음을 노래로 쓰는거야!\n제목은 가슴이 시려운 이야기! ", -1, MyString, 400, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "ParkTalk/Bold.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(26);
	this->addChild(name, 3);


	auto textA_item = MenuItemImage::create(
		"ParkTalk/ok_button.png",
		"ParkTalk/ok_buttonpr.png",
		CC_CALLBACK_1(ParkTalk::storyC6, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(136);
	this->addChild(text, 5);
}
void ParkTalk::storyC6(Ref * pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);

	removeChildByTag(136);
	removeChildByTag(26);

	char MyString[400];
	WideCharToMultiByte(CP_UTF8, 0, L"호동 : (왠지 노래가 크게 성공 할 것 같은걸)\n\n(친밀도가 11 상승하였습니다.)", -1, MyString, 400, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "ParkTalk/Bold.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(27);
	this->addChild(name, 3);


	auto textA_item = MenuItemImage::create(
		"ParkTalk/ok_button.png",
		"ParkTalk/ok_buttonpr.png",
		CC_CALLBACK_1(ParkTalk::GoHome, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(137);
	this->addChild(text, 5);

	Singletons::getInstance()->m_friendly = Singletons::getInstance()->m_friendly + 11;
}
// 제이윌 대화씬 2
void ParkTalk::storyC_1(Ref * pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);

	removeChildByTag(130);
	removeChildByTag(21);

	char MyString[200];
	WideCharToMultiByte(CP_UTF8, 0, L"(제이윌을 만났다.)", -1, MyString, 200, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "ParkTalk/Bold.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(21);
	this->addChild(name, 3);


	auto textA_item = MenuItemImage::create(
		"ParkTalk/ok_button.png",
		"ParkTalk/ok_buttonpr.png",
		CC_CALLBACK_1(ParkTalk::storyC1_1, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(131);
	this->addChild(text, 5);

	Sprite* mainchr = Sprite::create("ParkTalk/park_chara3.png");
	mainchr->setAnchorPoint(Point(0.5, 0));
	mainchr->setPosition(Point(800, 0));
	mainchr->setTag(231);
	this->addChild(mainchr, 1);
}
void ParkTalk::storyC1_1(Ref * pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);

	removeChildByTag(131);
	removeChildByTag(21);
	char MyString[400];
	WideCharToMultiByte(CP_UTF8, 0, L"제이윌 : ㅎㅎ 호동아 형 여친 생겼다.\n여.자.친.구. 마침 카톡이 왔네?", -1, MyString, 400, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "ParkTalk/Bold.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(22);
	this->addChild(name, 3);


	auto textA_item = MenuItemImage::create(
		"ParkTalk/ok_button.png",
		"ParkTalk/ok_buttonpr.png",
		CC_CALLBACK_1(ParkTalk::storyC2_1, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(132);
	this->addChild(text, 5);
}
void ParkTalk::storyC2_1(Ref * pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);

	removeChildByTag(132);
	removeChildByTag(22);

	char MyString[400];
	WideCharToMultiByte(CP_UTF8, 0, L"제이윌 : 헉! ..... 호동아... 흑흑.... \n나보고 헤어지자는데... 어떻게 하지....", -1, MyString, 400, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "ParkTalk/Bold.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(23);
	this->addChild(name, 3);


	auto textA_item = MenuItemImage::create(
		"ParkTalk/ok_button.png",
		"ParkTalk/ok_buttonpr.png",
		CC_CALLBACK_1(ParkTalk::storyC3_1, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(133);
	this->addChild(text, 5);
}
void ParkTalk::storyC3_1(Ref * pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);

	removeChildByTag(133);
	removeChildByTag(23);

	char MyString[300];
	WideCharToMultiByte(CP_UTF8, 0, L"호동 :  저는 잘 모르겠네요... 연애에 대해 아는게 없어서.", -1, MyString, 300, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "ParkTalk/Bold.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(24);
	this->addChild(name, 3);


	auto textA_item = MenuItemImage::create(
		"ParkTalk/ok_button.png",
		"ParkTalk/ok_buttonpr.png",
		CC_CALLBACK_1(ParkTalk::storyC4_1, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(134);
	this->addChild(text, 5);
}
void ParkTalk::storyC4_1(Ref * pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);

	removeChildByTag(134);
	removeChildByTag(24);

	char MyString[300];
	WideCharToMultiByte(CP_UTF8, 0, L"제이윌 : 흑흑.. 그래... 난 빨리 다시 잡으러 가봐야 겠다.", -1, MyString, 300, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "ParkTalk/Bold.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(25);
	this->addChild(name, 3);


	auto textA_item = MenuItemImage::create(
		"ParkTalk/ok_button.png",
		"ParkTalk/ok_buttonpr.png",
		CC_CALLBACK_1(ParkTalk::storyC5_1, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(135);
	this->addChild(text, 5);
}
void ParkTalk::storyC5_1(Ref * pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);

	removeChildByTag(135);
	removeChildByTag(25);

	char MyString[400];
	WideCharToMultiByte(CP_UTF8, 0, L"호동 : (약올리더니 꼴 좋다.)\n\n(친밀도가 13 상승하였습니다.)", -1, MyString, 400, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "ParkTalk/Bold.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(26);
	this->addChild(name, 3);


	auto textA_item = MenuItemImage::create(
		"ParkTalk/ok_button.png",
		"ParkTalk/ok_buttonpr.png",
		CC_CALLBACK_1(ParkTalk::GoHome, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(136);
	this->addChild(text, 5);

	Singletons::getInstance()->m_friendly = Singletons::getInstance()->m_friendly + 13;
}
 // 랜덤 독백
void ParkTalk::storyD(Ref * pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);

	removeChildByTag(130);
	removeChildByTag(21);

	char MyString[200];
	WideCharToMultiByte(CP_UTF8, 0, L"(길바닥에 버려진 쓰레기를 주워 정리했다.)", -1, MyString, 200, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "ParkTalk/Bold.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(21);
	this->addChild(name, 3);


	auto textA_item = MenuItemImage::create(
		"ParkTalk/ok_button.png",
		"ParkTalk/ok_buttonpr.png",
		CC_CALLBACK_1(ParkTalk::storyD1, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(131);
	this->addChild(text, 5);
}
void ParkTalk::storyD1(Ref * pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);

	removeChildByTag(131);
	removeChildByTag(21);
	char MyString[400];
	WideCharToMultiByte(CP_UTF8, 0, L"호동 : 너무하네 사람들. 쓰레기통이 있는데 말이지..\n\n(인성이 8 상승하였습니다.)", -1, MyString, 400, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "ParkTalk/Bold.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(22);
	this->addChild(name, 3);


	auto textA_item = MenuItemImage::create(
		"ParkTalk/ok_button.png",
		"ParkTalk/ok_buttonpr.png",
		CC_CALLBACK_1(ParkTalk::storyD2, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(132);
	this->addChild(text, 5);

	Singletons::getInstance()->m_insung = Singletons::getInstance()->m_insung + 8;
}
void ParkTalk::storyD2(Ref * pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);

	removeChildByTag(132);
	removeChildByTag(22);

	char MyString[400];
	WideCharToMultiByte(CP_UTF8, 0, L"지나가던 할머니가 보고 용돈을 주셨습니다.\n\n(10000원 획득했습니다.)", -1, MyString, 400, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "ParkTalk/Bold.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(23);
	this->addChild(name, 3);


	auto textA_item = MenuItemImage::create(
		"ParkTalk/ok_button.png",
		"ParkTalk/ok_buttonpr.png",
		CC_CALLBACK_1(ParkTalk::GoHome, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(133);
	this->addChild(text, 5);

	Singletons::getInstance()->money = Singletons::getInstance()->money + 10000;
}

void ParkTalk::storyfin(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);

	removeChildByTag(132);
	removeChildByTag(22);
	char MyString[100];
	WideCharToMultiByte(CP_UTF8, 0, L"", -1, MyString, 100, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "ParkTalk/Bold.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(23);
	this->addChild(name, 3);


	auto textA_item = MenuItemImage::create(
		"ParkTalk/ok_button.png",
		"ParkTalk/ok_buttonpr.png",
		CC_CALLBACK_1(ParkTalk::GoHome, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(133);
	this->addChild(text, 5);
}
void ParkTalk::GoHome(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);

	// NextDayScene으로 변경
	Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
	Director::getInstance()->replaceScene(NextDayScene::createScene());
}
