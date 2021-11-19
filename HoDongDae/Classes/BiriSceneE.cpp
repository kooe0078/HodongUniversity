#include "BiriSceneE.h"
#include "NextDayScene.h"
#include "SimpleAudioEngine.h"
#include "MainBiriScene.h"
#include "sinngleton.h"
//#include "MainScene.h"
//사운드 할라면 꼭 필요
using namespace CocosDenshion;
USING_NS_CC;

Scene* BiriSceneE::createScene()
{
    auto scene = Scene::create();
    auto layer = BiriSceneE::create();
    scene->addChild(layer);

    return scene;
}

bool BiriSceneE::init()
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
	SimpleAudioEngine::getInstance()->playBackgroundMusic("sound/event sound2.mp3", true);

	/*this->scheduleOnce(schedule_selector(BiriSceneE::GoHome), 2.0f);
*/
    return true;
}
void BiriSceneE::update(float ft)
{
	//씬 자체적으로 반복 되야하는 내용
}
void BiriSceneE::InitBackGround()
{
	auto sprite = Sprite::create("MiniGameResources//back_9.png");
	sprite->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	this->addChild(sprite, 0);
}
void BiriSceneE::InitLabel()
{
	
}
// 인트로 선택창
void BiriSceneE::InitMenu()
{
	//스토리A창
	auto storyA_item = MenuItemImage::create(
		"MiniGameResources/UI_Textlblack.png",
		"MiniGameResources/UI_Textlblack.png",

		CC_CALLBACK_1(BiriSceneE::storyAspr, this));
	storyA_item->setAnchorPoint(Point(0.5, 0.5));
	storyA_item->setPosition(Point(510, 100));

	auto storyA = Menu::create(storyA_item, NULL);
	storyA->setAnchorPoint(Point(0.5, 0.5));
	storyA->setPosition(Point(0, 0));
	storyA->setTag(4);
	this->addChild(storyA,2);

	char MyString[100];
	WideCharToMultiByte(CP_UTF8, 0, L"호동: (오늘은 체육대회가 있는날이다.)", -1, MyString, 100, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "fonts/Bold.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(21);
	this->addChild(name, 3);


	//메인캐릭터
	Sprite* mainchr = Sprite::create("MiniGameResources/main_char.png");
	mainchr->setAnchorPoint(Point(0.5, 0));
	mainchr->setPosition(Point(120, 80));
	mainchr->setTag(166);
	this->addChild(mainchr, 1);

	auto textA_item = MenuItemImage::create(
		"MiniGameResources/ok_button.png",
		"MiniGameResources/ok_buttonpr.png",
		CC_CALLBACK_1(BiriSceneE::storyA, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(131);
	this->addChild(text, 5);
}
void BiriSceneE::storyAspr(Ref *pSender)
{

}

void BiriSceneE::storyA(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);
	//선택씬
	removeChildByTag(131);
	removeChildByTag(130);
	removeChildByTag(21);


	//간다
	auto textA_item = MenuItemImage::create(
		"MiniGameResources/text_yes.png",
		"MiniGameResources/text_yes.png",
		CC_CALLBACK_1(BiriSceneE::storyAA, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(300, 105));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(133);
	this->addChild(text, 5);

	//안간다
	auto textB_item = MenuItemImage::create(
		"MiniGameResources/text_no.png",
		"MiniGameResources/text_no.png",
		CC_CALLBACK_1(BiriSceneE::storyAAAA, this));
	textB_item->setAnchorPoint(Point(0.5, 0.5));
	textB_item->setPosition(Point(700, 105));

	auto textB = Menu::create(textB_item, NULL);
	textB->setAnchorPoint(Point(0.5, 0.5));
	textB->setPosition(Point(0, 0));
	textB->setTag(134);
	this->addChild(textB, 5);



}
void BiriSceneE::storyAA(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);
	removeChildByTag(133);
	removeChildByTag(134);
	removeChildByTag(131);
	removeChildByTag(21);
	char MyString[100];
	WideCharToMultiByte(CP_UTF8, 0, L"호동: 오호! 정말 활기찬걸? 그럼 어떤 종목에 참가해볼까?", -1, MyString, 100, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "fonts/Bold.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(22);
	this->addChild(name, 3);


	auto textA_item = MenuItemImage::create(
		"MiniGameResources/ok_button.png",
		"MiniGameResources/ok_buttonpr.png",
		CC_CALLBACK_1(BiriSceneE::storyAAA, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(132);
	this->addChild(text, 5);

}

void BiriSceneE::storyAAA(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);
	removeChildByTag(132);
	removeChildByTag(22);

	Sprite* mainchr = Sprite::create("MiniGameResources/mc_chara.png");
	mainchr->setAnchorPoint(Point(0.5, 0));
	mainchr->setPosition(Point(800, 0));
	mainchr->setTag(231);
	this->addChild(mainchr, 1);

	char MyString[100];
	WideCharToMultiByte(CP_UTF8, 0, L"사회자: 그럼 이제! 장기자랑 시간이~~ 돌아~~ 왔습니다!!!", -1, MyString, 100, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "fonts/Bold.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(23);
	this->addChild(name, 3);


	auto textA_item = MenuItemImage::create(
		"MiniGameResources/ok_button.png",
		"MiniGameResources/ok_buttonpr.png",
		CC_CALLBACK_1(BiriSceneE::storyAAAAAA, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(133);
	this->addChild(text, 5);
}
void BiriSceneE::storyAAAA(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);
	removeChildByTag(134);
	removeChildByTag(133);
	removeChildByTag(24);
	Singletons::getInstance()->backnum = 4;
	char MyString[100];
	WideCharToMultiByte(CP_UTF8, 0, L"호동: (땀냄새 나는건 싫단 말이지~)", -1, MyString, 100, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "fonts/Bold.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(23);
	this->addChild(name, 3);


	auto textA_item = MenuItemImage::create(
		"MiniGameResources/ok_button.png",
		"MiniGameResources/ok_buttonpr.png",
		CC_CALLBACK_1(BiriSceneE::storyAAAAA, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(133);
	this->addChild(text, 5);
}
void BiriSceneE::storyAAAAA(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);
	log("start1 after delay");
	auto scene = TransitionCrossFade::create(1.5, MainBiriScene::createScene());
	Director::getInstance()->replaceScene(scene);
//Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
//Director::getInstance()->replaceScene(MainBiriScene::createScene());
}
void BiriSceneE::storyAAAAAA(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);
	removeChildByTag(133);
	removeChildByTag(23);
	removeChildByTag(231);
	char MyString[100];
	WideCharToMultiByte(CP_UTF8, 0, L"호동: (무엇을 할까?)", -1, MyString, 100, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "fonts/Bold.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(26);
	this->addChild(name, 3);


	auto textA_item = MenuItemImage::create(
		"MiniGameResources/ok_button.png",
		"MiniGameResources/ok_buttonpr.png",
		CC_CALLBACK_1(BiriSceneE::storyAAAAAAA, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(136);
	this->addChild(text, 5);
}
void BiriSceneE::storyAAAAAAA(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);
	removeChildByTag(136);
	removeChildByTag(26);
	//춤
	auto textA_item_1 = MenuItemImage::create(
		"MiniGameResources/texts9.png",
		"MiniGameResources/texts9.png",
		CC_CALLBACK_1(BiriSceneE::storyA_1, this));
	textA_item_1->setAnchorPoint(Point(0.5, 0.5));
	textA_item_1->setPosition(Point(240, 105));

	auto text_1 = Menu::create(textA_item_1, NULL);
	text_1->setAnchorPoint(Point(0.5, 0.5));
	text_1->setPosition(Point(0, 0));
	text_1->setTag(137);
	this->addChild(text_1, 5);
	//노래
	auto textA_item = MenuItemImage::create(
		"MiniGameResources/texts10.png",
		"MiniGameResources/texts10.png",
		CC_CALLBACK_1(BiriSceneE::storyA_2, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(760, 105));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(138);
	this->addChild(text, 5);
}

//하니 대화씬2
void BiriSceneE::storyA_1(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);
	//모하니 대화씬1
	removeChildByTag(137);
	removeChildByTag(138);

	char MyString[100];
	WideCharToMultiByte(CP_UTF8, 0, L"호동: (축구나 해볼까?)", -1, MyString, 100, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "fonts/Bold.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(21);
	this->addChild(name, 3);


	auto textA_item = MenuItemImage::create(
		"MiniGameResources/ok_button.png",
		"MiniGameResources/ok_buttonpr.png",
		CC_CALLBACK_1(BiriSceneE::storyAA_1, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(131);
	this->addChild(text, 5);

	//Sprite* mainchr = Sprite::create("MiniGameResources/friend1.png");
	//mainchr->setAnchorPoint(Point(0.5, 0));
	//mainchr->setPosition(Point(800, 0));
	//mainchr->setTag(231);
	//this->addChild(mainchr, 1);
}
void BiriSceneE::storyAA_1(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);
	removeChildByTag(131);
	removeChildByTag(21);

	Sprite* mainchr = Sprite::create("MiniGameResources/mc_chara.png");
	mainchr->setAnchorPoint(Point(0.5, 0));
	mainchr->setPosition(Point(800, 0));
	mainchr->setTag(231);
	this->addChild(mainchr, 1);


	char MyString[100];
	WideCharToMultiByte(CP_UTF8, 0, L"중계: 아. 마지막공격 1:1찬스! 호동선수 골문 앞인데요!! 슈웃!", -1, MyString, 100, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "fonts/Bold.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(22);
	this->addChild(name, 3);


	auto textA_item = MenuItemImage::create(
		"MiniGameResources/ok_button.png",
		"MiniGameResources/ok_buttonpr.png",
		CC_CALLBACK_1(BiriSceneE::storyAAA_1, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(132);
	this->addChild(text, 5);
}
void BiriSceneE::storyAAA_1(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);
	removeChildByTag(132);
	removeChildByTag(22);
	removeChildByTag(231);

	Sprite* mainchr = Sprite::create("MiniGameResources/mc_chara.png");
	mainchr->setAnchorPoint(Point(0.5, 0));
	mainchr->setPosition(Point(800, 0));
	mainchr->setTag(231);
	this->addChild(mainchr, 1);

	char MyString[100];
	WideCharToMultiByte(CP_UTF8, 0, L"호동: (아잇쿠!) ", -1, MyString, 100, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "fonts/Bold.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(23);
	this->addChild(name, 3);


	auto textA_item = MenuItemImage::create(
		"MiniGameResources/ok_button.png",
		"MiniGameResources/ok_buttonpr.png",
		CC_CALLBACK_1(BiriSceneE::storyAAAA_1, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(133);
	this->addChild(text, 5);
}
void BiriSceneE::storyAAAA_1(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);
	removeChildByTag(133);
	removeChildByTag(23);




	char MyString[100];
	WideCharToMultiByte(CP_UTF8, 0, L"(호동은 헛발질을 했다.)", -1, MyString, 100, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "fonts/Bold.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(24);
	this->addChild(name, 3);


	auto textA_item = MenuItemImage::create(
		"MiniGameResources/ok_button.png",
		"MiniGameResources/ok_buttonpr.png",
		CC_CALLBACK_1(BiriSceneE::storyAAAAA_1, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(134);
	this->addChild(text, 5);
}
void BiriSceneE::storyAAAAA_1(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);
	removeChildByTag(134);
	removeChildByTag(24);

	Sprite* mainchr = Sprite::create("MiniGameResources/mc_chara.png");
	mainchr->setAnchorPoint(Point(0.5, 0));
	mainchr->setPosition(Point(800, 0));
	mainchr->setTag(231);
	this->addChild(mainchr, 1);

	char MyString[100];
	WideCharToMultiByte(CP_UTF8, 0, L"중계: 아!!! 여기서 헛발질을 하네요! 경기종료!! 3:2 호동팀의 패배!", -1, MyString, 100, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "fonts/Bold.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(25);
	this->addChild(name, 3);


	auto textA_item = MenuItemImage::create(
		"MiniGameResources/ok_button.png",
		"MiniGameResources/ok_buttonpr.png",
		CC_CALLBACK_1(BiriSceneE::storyAAAAAA_1, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(135);
	this->addChild(text, 5);
}
void BiriSceneE::storyAAAAAA_1(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);
	removeChildByTag(135);
	removeChildByTag(25);
	removeChildByTag(231);

	char MyString[200];
	WideCharToMultiByte(CP_UTF8, 0, L"호동: 하... 거하게 저질러 버렸군..반성해야겠는걸.\n\n(모든 능력치가 10 증가하였습니다.)", -1, MyString, 200, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "fonts/Bold.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(26);
	this->addChild(name, 3);


	auto textA_item = MenuItemImage::create(
		"MiniGameResources/ok_button.png",
		"MiniGameResources/ok_buttonpr.png",
		CC_CALLBACK_1(BiriSceneE::GoHome, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(136);
	this->addChild(text, 5);

	Singletons::getInstance()->m_friendly = Singletons::getInstance()->m_friendly + 10;
	Singletons::getInstance()->m_hak = Singletons::getInstance()->m_hak + 10;
	Singletons::getInstance()->m_insung = Singletons::getInstance()->m_insung + 10;
	Singletons::getInstance()->m_jisik = Singletons::getInstance()->m_jisik + 10;

}

void BiriSceneE::storyfin(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);
	removeChildByTag(132);
	removeChildByTag(22);
	char MyString[100];
	WideCharToMultiByte(CP_UTF8, 0, L"", -1, MyString, 100, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "fonts/Bold.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(23);
	this->addChild(name, 3);


	auto textA_item = MenuItemImage::create(
		"MiniGameResources/ok_button.png",
		"MiniGameResources/ok_buttonpr.png",
		CC_CALLBACK_1(BiriSceneE::GoHome, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(133);
	this->addChild(text, 5);
}
//하니 대화씬3
void BiriSceneE::storyA_2(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);
	removeChildByTag(137);
	removeChildByTag(138);

	Sprite* mainchr = Sprite::create("MiniGameResources/mc_chara.png");
	mainchr->setAnchorPoint(Point(0.5, 0));
	mainchr->setPosition(Point(800, 0));
	mainchr->setTag(231);
	this->addChild(mainchr, 1);


	char MyString[100];
	WideCharToMultiByte(CP_UTF8, 0, L"중계: 아 저 선수 누구죠? 너무 잘해요!! 던지는 족족 3점이네요!", -1, MyString, 100, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "fonts/Bold.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(21);
	this->addChild(name, 3);


	auto textA_item = MenuItemImage::create(
		"MiniGameResources/ok_button.png",
		"MiniGameResources/ok_buttonpr.png",
		CC_CALLBACK_1(BiriSceneE::storyAA_2, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(131);
	this->addChild(text, 5);

	//Sprite* mainchr = Sprite::create("MiniGameResources/friend1.png");
	//mainchr->setAnchorPoint(Point(0.5, 0));
	//mainchr->setPosition(Point(800, 0));
	//mainchr->setTag(231);
	//this->addChild(mainchr, 1);
}
void BiriSceneE::storyAA_2(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);
	removeChildByTag(131);
	removeChildByTag(21);
	removeChildByTag(231);

	char MyString[100];
	WideCharToMultiByte(CP_UTF8, 0, L"호동: 휴우~ 오랜만인데 잘 되는군!", -1, MyString, 100, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "fonts/Bold.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(22);
	this->addChild(name, 3);


	auto textA_item = MenuItemImage::create(
		"MiniGameResources/ok_button.png",
		"MiniGameResources/ok_buttonpr.png",
		CC_CALLBACK_1(BiriSceneE::storyAAA_2, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(132);
	this->addChild(text, 5);
}
void BiriSceneE::storyAAA_2(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);
	removeChildByTag(132);
	removeChildByTag(22);

	Sprite* mainchr = Sprite::create("MiniGameResources/mc_chara.png");
	mainchr->setAnchorPoint(Point(0.5, 0));
	mainchr->setPosition(Point(800, 0));
	mainchr->setTag(231);
	this->addChild(mainchr, 1);



	char MyString[100];
	WideCharToMultiByte(CP_UTF8, 0, L"중계: 너무나도 큰 점수차! 88 : 32 경기종료!", -1, MyString, 100, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "fonts/Bold.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(23);
	this->addChild(name, 3);

	auto textA_item = MenuItemImage::create(
		"MiniGameResources/ok_button.png",
		"MiniGameResources/ok_buttonpr.png",
		CC_CALLBACK_1(BiriSceneE::storyAAAA_2T, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(132);
	this->addChild(text, 5);
}

void BiriSceneE::storyAAAA_2T(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);
	removeChildByTag(132);
	removeChildByTag(231);
	removeChildByTag(23);




	char MyString[100];
	WideCharToMultiByte(CP_UTF8, 0, L"관중: 휘이~", -1, MyString, 100, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "fonts/Bold.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(24);
	this->addChild(name, 3);


	auto textA_item = MenuItemImage::create(
		"MiniGameResources/ok_button.png",
		"MiniGameResources/ok_buttonpr.png",
		CC_CALLBACK_1(BiriSceneE::storyAAAA_2F, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(134);
	this->addChild(text, 5);
}

void BiriSceneE::storyAAAA_2F(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);
	removeChildByTag(134);

	removeChildByTag(24);
	
	char MyString[200];
	WideCharToMultiByte(CP_UTF8, 0, L"호동: 만족스러운 결과야.\n\n(20만원과 30의 모든 능력치를 획득하였습니다.)", -1, MyString, 200, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "fonts/Bold.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(24);
	this->addChild(name, 3);


	auto textA_item = MenuItemImage::create(
		"MiniGameResources/ok_button.png",
		"MiniGameResources/ok_buttonpr.png",
		CC_CALLBACK_1(BiriSceneE::GoHome, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(134);
	this->addChild(text, 5);

	Singletons::getInstance()->m_friendly = Singletons::getInstance()->m_friendly + 30;
	Singletons::getInstance()->m_hak = Singletons::getInstance()->m_hak + 30;
	Singletons::getInstance()->m_insung = Singletons::getInstance()->m_insung + 30;
	Singletons::getInstance()->m_jisik = Singletons::getInstance()->m_jisik + 30;
	Singletons::getInstance()->money = Singletons::getInstance()->money + 200000;
}


void BiriSceneE::GoHome(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);
	//log("start1 after delay");
	///*Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
	//Director::getInstance()->replaceScene(IntroSceneB::createScene());*/
	//auto scene = TransitionCrossFade::create(1.5, NextDayScene::createScene());
	//Director::getInstance()->replaceScene(scene);
	Singletons::getInstance()->day = Singletons::getInstance()->day + 1;
	Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
	Director::getInstance()->replaceScene(NextDayScene::createScene());
}
	
	

void BiriSceneE::skipspr(Ref *pSender)
{
	
}
