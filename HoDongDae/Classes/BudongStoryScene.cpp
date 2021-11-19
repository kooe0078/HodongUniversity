#include "BudongStoryScene.h"
#include "NextDayScene.h"
#include "SimpleAudioEngine.h"
#include "sinngleton.h"
//#include "MainScene.h"
//사운드 할라면 꼭 필요
using namespace CocosDenshion;
USING_NS_CC;

Scene* BudongStoryScene::createScene()
{
    auto scene = Scene::create();
    auto layer = BudongStoryScene::create();
    scene->addChild(layer);

    return scene;
}

bool BudongStoryScene::init()
{

    if ( !Layer::init() )
    {
        return false;
    }

	visibleSize = Director::getInstance()->getVisibleSize();
	origin      = Director::getInstance()->getVisibleOrigin();

	InitBackGround();
	InitLabel();
	InitMenu();
	
	////터치 리스너 등록
	//auto listener = EventListenerTouchOneByOne::create();
	//listener->onTouchBegan = CC_CALLBACK_2(IntroScene::onTouchBegan, this);
	//Director::getInstance()->getEventDispatcher()->addEventListenerWithFixedPriority(listener, 1);

	//배경음악
	SimpleAudioEngine::getInstance()->playBackgroundMusic("sound/invest sound.mp3", true);

	/*this->scheduleOnce(schedule_selector(BudongStoryScene::GoHome), 2.0f);
*/
    return true;
}
void BudongStoryScene::update(float ft)
{
	//씬 자체적으로 반복 되야하는 내용
}
void BudongStoryScene::InitBackGround()
{
	auto sprite = Sprite::create("MiniGameResources//stock_exchange.png");
	sprite->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	this->addChild(sprite, 0);
}
void BudongStoryScene::InitLabel()
{

}
// 인트로 선택창
void BudongStoryScene::InitMenu()
{
	//if(Singletons::getInstance()->)

	int i, num;
	
	srand((long)time(NULL));
	for (i = 0; i < 1; i++)
	{
		num = rand() % 3 + 1;
	}
	
	//모하니 대화씬1
	if (num == 1)
	{
		
		Sprite* mainchr = Sprite::create("MiniGameResources/main_char.png");
		mainchr->setAnchorPoint(Point(0.5, 0));
		mainchr->setPosition(Point(120, 80));
		mainchr->setTag(166);
		this->addChild(mainchr, 1);

		char MyString[100];
		WideCharToMultiByte(CP_UTF8, 0, L"호동: (유익한 정보가 있을까...)", -1, MyString, 100, NULL, NULL);
		auto name = Label::createWithTTF(MyString, "fonts/Bold.ttf", 30);
		name->setAnchorPoint(Point(0, 1));
		name->setPosition(Point(40, 150));
		name->setColor(Color3B::WHITE);
		name->setTag(21);
		this->addChild(name, 3);

		Sprite* mainchr_2 = Sprite::create("MiniGameResources/UI_Textlblack.png");
		mainchr_2->setAnchorPoint(Point(0.5, 0.5));
		mainchr_2->setPosition(Point(510, 100));
		mainchr_2->setTag(231);
		this->addChild(mainchr_2, 2);

		auto textA_item = MenuItemImage::create(
			"MiniGameResources/ok_button.png",
			"MiniGameResources/ok_buttonpr.png",
			CC_CALLBACK_1(BudongStoryScene::storyA, this));
		textA_item->setAnchorPoint(Point(0.5, 0.5));
		textA_item->setPosition(Point(950, 65));

		auto text = Menu::create(textA_item, NULL);
		text->setAnchorPoint(Point(0.5, 0.5));
		text->setPosition(Point(0, 0));
		text->setTag(130);
		this->addChild(text, 5);

	}
	//모하니 대화2
	if (num == 2)
	{
		
		Sprite* mainchr = Sprite::create("MiniGameResources/main_char.png");
		mainchr->setAnchorPoint(Point(0.5, 0));
		mainchr->setPosition(Point(120, 80));
		mainchr->setTag(166);
		this->addChild(mainchr, 1);

		char MyString[100];
		WideCharToMultiByte(CP_UTF8, 0, L"호동: (유익한 정보가 있을까...)", -1, MyString, 100, NULL, NULL);
		auto name = Label::createWithTTF(MyString, "fonts/Bold.ttf", 30);
		name->setAnchorPoint(Point(0, 1));
		name->setPosition(Point(40, 150));
		name->setColor(Color3B::WHITE);
		name->setTag(21);
		this->addChild(name, 3);

		Sprite* mainchr_2 = Sprite::create("MiniGameResources/UI_Textlblack.png");
		mainchr_2->setAnchorPoint(Point(0.5, 0.5));
		mainchr_2->setPosition(Point(510, 100));
		mainchr_2->setTag(231);
		this->addChild(mainchr_2, 2);

		auto textA_item = MenuItemImage::create(
			"MiniGameResources/ok_button.png",
			"MiniGameResources/ok_buttonpr.png",
			CC_CALLBACK_1(BudongStoryScene::storyA_1, this));
		textA_item->setAnchorPoint(Point(0.5, 0.5));
		textA_item->setPosition(Point(950, 65));

		auto text = Menu::create(textA_item, NULL);
		text->setAnchorPoint(Point(0.5, 0.5));
		text->setPosition(Point(0, 0));
		text->setTag(130);
		this->addChild(text, 5);
	}
	if (num == 3)
	{
		
		Sprite* mainchr = Sprite::create("MiniGameResources/main_char.png");
		mainchr->setAnchorPoint(Point(0.5, 0));
		mainchr->setPosition(Point(120, 80));
		mainchr->setTag(166);
		this->addChild(mainchr, 1);

		char MyString[100];
		WideCharToMultiByte(CP_UTF8, 0, L"호동: (유익한 정보가 있을까...)", -1, MyString, 100, NULL, NULL);
		auto name = Label::createWithTTF(MyString, "fonts/Bold.ttf", 30);
		name->setAnchorPoint(Point(0, 1));
		name->setPosition(Point(40, 150));
		name->setColor(Color3B::WHITE);
		name->setTag(21);
		this->addChild(name, 3);

		Sprite* mainchr_2 = Sprite::create("MiniGameResources/UI_Textlblack.png");
		mainchr_2->setAnchorPoint(Point(0.5, 0.5));
		mainchr_2->setPosition(Point(510, 100));
		mainchr_2->setTag(231);
		this->addChild(mainchr_2, 2);

		//모하니 대화씬3
		auto textA_item = MenuItemImage::create(
			"MiniGameResources/ok_button.png",
			"MiniGameResources/ok_buttonpr.png",
			CC_CALLBACK_1(BudongStoryScene::storyA_2, this));
		textA_item->setAnchorPoint(Point(0.5, 0.5));
		textA_item->setPosition(Point(950, 65));

		auto text = Menu::create(textA_item, NULL);
		text->setAnchorPoint(Point(0.5, 0.5));
		text->setPosition(Point(0, 0));
		text->setTag(130);
		this->addChild(text, 5);
	}
}
void BudongStoryScene::storyAspr(Ref *pSender)
{

}

void BudongStoryScene::storyA(Ref *pSender)
{
	//모하니 대화씬1
	removeChildByTag(130);
	removeChildByTag(21);

	SimpleAudioEngine::getInstance()->playEffect("MiniGameResources/button_click_16_sound_effects_.mp3", false);

	char MyString[100];
	WideCharToMultiByte(CP_UTF8, 0, L"호동: (투자자 아저씨를 만났다.)", -1, MyString, 100, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "fonts/Bold.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(21);
	this->addChild(name, 3);


	auto textA_item = MenuItemImage::create(
		"MiniGameResources/ok_button.png",
		"MiniGameResources/ok_buttonpr.png",
		CC_CALLBACK_1(BudongStoryScene::storyAA, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(131);
	this->addChild(text, 5);

	
}
void BudongStoryScene::storyAA(Ref *pSender)
{
	removeChildByTag(131);
	removeChildByTag(21);

	SimpleAudioEngine::getInstance()->playEffect("MiniGameResources/button_click_16_sound_effects_.mp3", false);

	char MyString[100];
	WideCharToMultiByte(CP_UTF8, 0, L"호동: 안녕하세요. 어떻게 투자할 곳은 정하셨어요?", -1, MyString, 100, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "fonts/Bold.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(22);
	this->addChild(name, 3);


	auto textA_item = MenuItemImage::create(
		"MiniGameResources/ok_button.png",
		"MiniGameResources/ok_buttonpr.png",
		CC_CALLBACK_1(BudongStoryScene::storyAAA, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(132);
	this->addChild(text, 5);

}

void BudongStoryScene::storyAAA(Ref *pSender)
{
	removeChildByTag(132);
	removeChildByTag(22);

	SimpleAudioEngine::getInstance()->playEffect("MiniGameResources/button_click_16_sound_effects_.mp3", false);

	Sprite* mainchr = Sprite::create("MiniGameResources/invest_man.png");
	mainchr->setAnchorPoint(Point(0.5, 0));
	mainchr->setPosition(Point(800, 0));
	mainchr->setTag(231);
	this->addChild(mainchr, 1);

	char MyString[150];
	WideCharToMultiByte(CP_UTF8, 0, L"아저씨: 호동이구나! 음.. 이건 비밀인데 이번에 난 별삼에 투자했어 ", -1, MyString, 150, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "fonts/Bold.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(23);
	this->addChild(name, 3);


	auto textA_item = MenuItemImage::create(
		"MiniGameResources/ok_button.png",
		"MiniGameResources/ok_buttonpr.png",
		CC_CALLBACK_1(BudongStoryScene::storyAAAA, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(133);
	this->addChild(text, 5);
}
void BudongStoryScene::storyAAAA(Ref *pSender)
{
	removeChildByTag(133);
	removeChildByTag(23);

	SimpleAudioEngine::getInstance()->playEffect("MiniGameResources/button_click_16_sound_effects_.mp3", false);

	char MyString[100];
	WideCharToMultiByte(CP_UTF8, 0, L"호동: (오호..) 뭐 유익한 정보라도 얻으셨나봐요?", -1, MyString, 100, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "fonts/Bold.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(24);
	this->addChild(name, 3);

	
	auto textA_item = MenuItemImage::create(
		"MiniGameResources/ok_button.png",
		"MiniGameResources/ok_buttonpr.png",
		CC_CALLBACK_1(BudongStoryScene::storyAAAAA, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(134);
	this->addChild(text, 5);
}
void BudongStoryScene::storyAAAAA(Ref *pSender)
{
	removeChildByTag(134);
	removeChildByTag(24);

	SimpleAudioEngine::getInstance()->playEffect("MiniGameResources/button_click_16_sound_effects_.mp3", false);

	char MyString[100];
	WideCharToMultiByte(CP_UTF8, 0, L"아저씨: 아니 그냥 느낌이 그래!", -1, MyString, 100, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "fonts/Bold.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(25);
	this->addChild(name, 3);


	auto textA_item = MenuItemImage::create(
		"MiniGameResources/ok_button.png",
		"MiniGameResources/ok_buttonpr.png",
		CC_CALLBACK_1(BudongStoryScene::storyAAAAAA, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(135);
	this->addChild(text, 5);
}
void BudongStoryScene::storyAAAAAA(Ref *pSender)
{
	removeChildByTag(135);
	removeChildByTag(25);

	SimpleAudioEngine::getInstance()->playEffect("MiniGameResources/button_click_16_sound_effects_.mp3", false);

	char MyString[200];
	WideCharToMultiByte(CP_UTF8, 0, L"호동: ... (따라가면 망할 것 같네)\n\n(친밀도가 10 증가하였습니다.)", -1, MyString, 200, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "fonts/Bold.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(26);
	this->addChild(name, 3);


	auto textA_item = MenuItemImage::create(
		"MiniGameResources/ok_button.png",
		"MiniGameResources/ok_buttonpr.png",
		CC_CALLBACK_1(BudongStoryScene::GoHome, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(136);
	this->addChild(text, 5);

	Singletons::getInstance()->m_friendly = Singletons::getInstance()->m_friendly + 10;
}


//하니 대화씬2
void BudongStoryScene::storyA_1(Ref *pSender)
{
	//모하니 대화씬1
	removeChildByTag(130);
	//removeChildByTag(20);
	removeChildByTag(21);

	SimpleAudioEngine::getInstance()->playEffect("MiniGameResources/button_click_16_sound_effects_.mp3", false);

	char MyString[100];
	WideCharToMultiByte(CP_UTF8, 0, L"호동: (투자자 아저씨를 만났다.)", -1, MyString, 100, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "fonts/Bold.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(21);
	this->addChild(name, 3);


	auto textA_item = MenuItemImage::create(
		"MiniGameResources/ok_button.png",
		"MiniGameResources/ok_buttonpr.png",
		CC_CALLBACK_1(BudongStoryScene::storyAA_1, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(131);
	this->addChild(text, 5);


}
void BudongStoryScene::storyAA_1(Ref *pSender)
{
	removeChildByTag(131);
	removeChildByTag(21);
	SimpleAudioEngine::getInstance()->playEffect("MiniGameResources/button_click_16_sound_effects_.mp3", false);

	char MyString[100];
	WideCharToMultiByte(CP_UTF8, 0, L"아저씨: 호동아.이번 정보는 확실하다.", -1, MyString, 100, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "fonts/Bold.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(22);
	this->addChild(name, 3);


	auto textA_item = MenuItemImage::create(
		"MiniGameResources/ok_button.png",
		"MiniGameResources/ok_buttonpr.png",
		CC_CALLBACK_1(BudongStoryScene::storyAAA_1, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(132);
	this->addChild(text, 5);

	Sprite* mainchr = Sprite::create("MiniGameResources/invest_man.png");
	mainchr->setAnchorPoint(Point(0.5, 0));
	mainchr->setPosition(Point(800, 0));
	mainchr->setTag(231);
	this->addChild(mainchr, 1);
}
void BudongStoryScene::storyAAA_1(Ref *pSender)
{
	removeChildByTag(132);
	removeChildByTag(22);

	SimpleAudioEngine::getInstance()->playEffect("MiniGameResources/button_click_16_sound_effects_.mp3", false);

	char MyString[100];
	WideCharToMultiByte(CP_UTF8, 0, L"호동: 무슨 정보요?", -1, MyString, 100, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "fonts/Bold.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(23);
	this->addChild(name, 3);


	auto textA_item = MenuItemImage::create(
		"MiniGameResources/ok_button.png",
		"MiniGameResources/ok_buttonpr.png",
		CC_CALLBACK_1(BudongStoryScene::storyAAAA_1, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(133);
	this->addChild(text, 5);
}
void BudongStoryScene::storyAAAA_1(Ref *pSender)
{
	removeChildByTag(133);
	removeChildByTag(23);
	SimpleAudioEngine::getInstance()->playEffect("MiniGameResources/button_click_16_sound_effects_.mp3", false);


	char MyString[200];
	WideCharToMultiByte(CP_UTF8, 0, L"아저씨: 지인이 알려줬는데 한수가 폭락할 것이라는구나.", -1, MyString, 200, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "fonts/Bold.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(24);
	this->addChild(name, 3);


	auto textA_item = MenuItemImage::create(
		"MiniGameResources/ok_button.png",
		"MiniGameResources/ok_buttonpr.png",
		CC_CALLBACK_1(BudongStoryScene::storyAAAAA_1, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(134);
	this->addChild(text, 5);
}
void BudongStoryScene::storyAAAAA_1(Ref *pSender)
{
	removeChildByTag(134);
	removeChildByTag(24);

	SimpleAudioEngine::getInstance()->playEffect("MiniGameResources/button_click_16_sound_effects_.mp3", false);

	char MyString[100];
	WideCharToMultiByte(CP_UTF8, 0, L"호동: 어째서요?", -1, MyString, 100, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "fonts/Bold.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(25);
	this->addChild(name, 3);


	auto textA_item = MenuItemImage::create(
		"MiniGameResources/ok_button.png",
		"MiniGameResources/ok_buttonpr.png",
		CC_CALLBACK_1(BudongStoryScene::storyAAAAAA_1, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(135);
	this->addChild(text, 5);
}
void BudongStoryScene::storyAAAAAA_1(Ref *pSender)
{
	removeChildByTag(135);
	removeChildByTag(25);

	SimpleAudioEngine::getInstance()->playEffect("MiniGameResources/button_click_16_sound_effects_.mp3", false);

	char MyString[150];
	WideCharToMultiByte(CP_UTF8, 0, L"아저씨: 그 이유를 듣지못했네? 다시 한번 물어보고오마!", -1, MyString, 150, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "fonts/Bold.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(26);
	this->addChild(name, 3);


	auto textA_item = MenuItemImage::create(
		"MiniGameResources/ok_button.png",
		"MiniGameResources/ok_buttonpr.png",
		CC_CALLBACK_1(BudongStoryScene::storyAAAAAAA_1, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(136);
	this->addChild(text, 5);
}
void BudongStoryScene::storyAAAAAAA_1(Ref *pSender)
{
	removeChildByTag(136);
	removeChildByTag(26);

	SimpleAudioEngine::getInstance()->playEffect("MiniGameResources/button_click_16_sound_effects_.mp3", false);

	char MyString[200];
	WideCharToMultiByte(CP_UTF8, 0, L"호동: 저 아저씨는 투자하면 안되겠어... ( 한숨 )\n\n (친밀도가 11 증가하였습니다.)", -1, MyString, 200, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "fonts/Bold.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(26);
	this->addChild(name, 3);


	auto textA_item = MenuItemImage::create(
		"MiniGameResources/ok_button.png",
		"MiniGameResources/ok_buttonpr.png",
		CC_CALLBACK_1(BudongStoryScene::GoHome, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(136);
	this->addChild(text, 5);

	Singletons::getInstance()->m_friendly = Singletons::getInstance()->m_friendly + 11;
}


//하니 대화씬3
void BudongStoryScene::storyA_2(Ref *pSender)
{
	removeChildByTag(130);
	//removeChildByTag(20);
	removeChildByTag(21);

	SimpleAudioEngine::getInstance()->playEffect("MiniGameResources/button_click_16_sound_effects_.mp3", false);

	char MyString[100];
	WideCharToMultiByte(CP_UTF8, 0, L"호동: (투자자 아저씨를 만났다.)", -1, MyString, 100, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "fonts/Bold.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(21);
	this->addChild(name, 3);


	auto textA_item = MenuItemImage::create(
		"MiniGameResources/ok_button.png",
		"MiniGameResources/ok_buttonpr.png",
		CC_CALLBACK_1(BudongStoryScene::storyAA_2, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(131);
	this->addChild(text, 5);


}
void BudongStoryScene::storyAA_2(Ref *pSender)
{
	removeChildByTag(131);
	removeChildByTag(21);

	SimpleAudioEngine::getInstance()->playEffect("MiniGameResources/button_click_16_sound_effects_.mp3", false);

	char MyString[100];
	WideCharToMultiByte(CP_UTF8, 0, L"호동: 안녕하세요 아저씨.", -1, MyString, 100, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "fonts/Bold.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(22);
	this->addChild(name, 3);


	auto textA_item = MenuItemImage::create(
		"MiniGameResources/ok_button.png",
		"MiniGameResources/ok_buttonpr.png",
		CC_CALLBACK_1(BudongStoryScene::storyAAA_2, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(132);
	this->addChild(text, 5);
}
void BudongStoryScene::storyAAA_2(Ref *pSender)
{
	removeChildByTag(132);
	removeChildByTag(22);

	SimpleAudioEngine::getInstance()->playEffect("MiniGameResources/button_click_16_sound_effects_.mp3", false);

	char MyString[100];
	WideCharToMultiByte(CP_UTF8, 0, L"아저씨: 안녕 호동아. 뭐 좋은 소식있니?", -1, MyString, 100, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "fonts/Bold.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(24);
	this->addChild(name, 3);


	auto textA_item = MenuItemImage::create(
		"MiniGameResources/ok_button.png",
		"MiniGameResources/ok_buttonpr.png",
		CC_CALLBACK_1(BudongStoryScene::storyAAAA_2T, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(134);
	this->addChild(text, 5);

	Sprite* mainchr = Sprite::create("MiniGameResources/invest_man.png");
	mainchr->setAnchorPoint(Point(0.5, 0));
	mainchr->setPosition(Point(800, 0));
	mainchr->setTag(231);
	this->addChild(mainchr, 1);
}

void BudongStoryScene::storyAAAA_2T(Ref *pSender)
{
	removeChildByTag(134);

	removeChildByTag(24);

	SimpleAudioEngine::getInstance()->playEffect("MiniGameResources/button_click_16_sound_effects_.mp3", false);

	char MyString[200];
	WideCharToMultiByte(CP_UTF8, 0, L"호동: 아니요. 딱히 좋다고 할만한 소식은 못들었어요.", -1, MyString, 200, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "fonts/Bold.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(23);
	this->addChild(name, 3);


	auto textA_item = MenuItemImage::create(
		"MiniGameResources/ok_button.png",
		"MiniGameResources/ok_buttonpr.png",
		CC_CALLBACK_1(BudongStoryScene::storyAAAA_2F, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(134);
	this->addChild(text, 5);
}

void BudongStoryScene::storyAAAA_2F(Ref *pSender)
{
	removeChildByTag(134);

	removeChildByTag(23);

	SimpleAudioEngine::getInstance()->playEffect("MiniGameResources/button_click_16_sound_effects_.mp3", false);

	char MyString[200];
	WideCharToMultiByte(CP_UTF8, 0, L"아저씨: 그렇구나... 난 저쪽에가서 좀 알아봐야겠다.", -1, MyString, 200, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "fonts/Bold.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(24);
	this->addChild(name, 3);


	auto textA_item = MenuItemImage::create(
		"MiniGameResources/ok_button.png",
		"MiniGameResources/ok_buttonpr.png",
		CC_CALLBACK_1(BudongStoryScene::storyAAAA_2FF, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(134);
	this->addChild(text, 5);
}
void BudongStoryScene::storyAAAA_2FF(Ref *pSender)
{
	removeChildByTag(134);
	removeChildByTag(24);


	SimpleAudioEngine::getInstance()->playEffect("MiniGameResources/button_click_16_sound_effects_.mp3", false);
	char MyString[100];
	WideCharToMultiByte(CP_UTF8, 0, L"호동: 네. 수고하세요~ 전 가볼게요", -1, MyString, 100, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "fonts/Bold.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(24);
	this->addChild(name, 3);


	auto textA_item = MenuItemImage::create(
		"MiniGameResources/ok_button.png",
		"MiniGameResources/ok_buttonpr.png",
		CC_CALLBACK_1(BudongStoryScene::storyAAAAA_2, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(134);
	this->addChild(text, 5);
}
void BudongStoryScene::storyAAAAA_2(Ref *pSender)
{
	removeChildByTag(134);
	removeChildByTag(24);

	SimpleAudioEngine::getInstance()->playEffect("MiniGameResources/button_click_16_sound_effects_.mp3", false);

	char MyString[200];
	WideCharToMultiByte(CP_UTF8, 0, L"아저씨: 그래 잘가라.\n\n (친밀도가 13 상승하였습니다.)", -1, MyString, 200, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "fonts/Bold.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(25);
	this->addChild(name, 3);


	auto textA_item = MenuItemImage::create(
		"MiniGameResources/ok_button.png",
		"MiniGameResources/ok_buttonpr.png",
		CC_CALLBACK_1(BudongStoryScene::GoHome, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(135);
	this->addChild(text, 5);

	Singletons::getInstance()->m_friendly = Singletons::getInstance()->m_friendly + 13;
}


void BudongStoryScene::GoHome(Ref *pSender)
{
	//log("start1 after delay");
	///*Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
	//Director::getInstance()->replaceScene(IntroSceneB::createScene());*/
	//auto scene = TransitionCrossFade::create(1.5, NextDayScene::createScene());
	//Director::getInstance()->replaceScene(scene);
	Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
	Director::getInstance()->replaceScene(NextDayScene::createScene());
}
	
	

void BudongStoryScene::skipspr(Ref *pSender)
{
	
}
