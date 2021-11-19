#include "BiriSceneD.h"
#include "NextDayScene.h"
#include "SimpleAudioEngine.h"
#include "MainBiriScene.h"
#include "sinngleton.h"
//#include "MainScene.h"
//사운드 할라면 꼭 필요
using namespace CocosDenshion;
USING_NS_CC;

Scene* BiriSceneD::createScene()
{
    auto scene = Scene::create();
    auto layer = BiriSceneD::create();
    scene->addChild(layer);

    return scene;
}

bool BiriSceneD::init()
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

	/*this->scheduleOnce(schedule_selector(BiriSceneD::GoHome), 2.0f);
*/
    return true;
}
void BiriSceneD::update(float ft)
{
	//씬 자체적으로 반복 되야하는 내용
}
void BiriSceneD::InitBackGround()
{
	auto sprite = Sprite::create("MiniGameResources//back_8.png");
	sprite->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	this->addChild(sprite, 0);
}
void BiriSceneD::InitLabel()
{
	
}
// 인트로 선택창
void BiriSceneD::InitMenu()
{
	//스토리A창
	auto storyA_item = MenuItemImage::create(
		"MiniGameResources/UI_Textlblack.png",
		"MiniGameResources/UI_Textlblack.png",

		CC_CALLBACK_1(BiriSceneD::storyAspr, this));
	storyA_item->setAnchorPoint(Point(0.5, 0.5));
	storyA_item->setPosition(Point(510, 100));

	auto storyA = Menu::create(storyA_item, NULL);
	storyA->setAnchorPoint(Point(0.5, 0.5));
	storyA->setPosition(Point(0, 0));
	storyA->setTag(4);
	this->addChild(storyA,2);

	char MyString[100];
	WideCharToMultiByte(CP_UTF8, 0, L"호동: (오늘은 토론대회가 있는날이다.)", -1, MyString, 100, NULL, NULL);
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
		CC_CALLBACK_1(BiriSceneD::storyA, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(131);
	this->addChild(text, 5);
}
void BiriSceneD::storyAspr(Ref *pSender)
{

}

void BiriSceneD::storyA(Ref *pSender)
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
		CC_CALLBACK_1(BiriSceneD::storyAA, this));
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
		CC_CALLBACK_1(BiriSceneD::storyAAAA, this));
	textB_item->setAnchorPoint(Point(0.5, 0.5));
	textB_item->setPosition(Point(700, 105));

	auto textB = Menu::create(textB_item, NULL);
	textB->setAnchorPoint(Point(0.5, 0.5));
	textB->setPosition(Point(0, 0));
	textB->setTag(134);
	this->addChild(textB, 5);



}
void BiriSceneD::storyAA(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);
	removeChildByTag(133);
	removeChildByTag(134);
	removeChildByTag(131);
	removeChildByTag(21);

	Sprite* mainchr = Sprite::create("MiniGameResources/mc_chara.png");
	mainchr->setAnchorPoint(Point(0.5, 0));
	mainchr->setPosition(Point(800, 0));
	mainchr->setTag(231);
	this->addChild(mainchr, 1);



	char MyString[200];
	WideCharToMultiByte(CP_UTF8, 0, L"사회자: 올해도 어김없이 돌아왔습니다! 토론대회! \n‘아산의 물가는 왜 이렇게 비싼가’에 대한 주제로 지금 시작합니다!\n토론 시작해주세요!", -1, MyString, 200, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "fonts/Bold.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(22);
	this->addChild(name, 3);


	auto textA_item = MenuItemImage::create(
		"MiniGameResources/ok_button.png",
		"MiniGameResources/ok_buttonpr.png",
		CC_CALLBACK_1(BiriSceneD::storyAAA, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(132);
	this->addChild(text, 5);

}

void BiriSceneD::storyAAA(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);
	removeChildByTag(132);
	removeChildByTag(22);
	removeChildByTag(231);
	
	char MyString[100];
	WideCharToMultiByte(CP_UTF8, 0, L"호동: 아산의 물가가 비싼이유는 말이죠!", -1, MyString, 100, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "fonts/Bold.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(23);
	this->addChild(name, 3);


	auto textA_item = MenuItemImage::create(
		"MiniGameResources/ok_button.png",
		"MiniGameResources/ok_buttonpr.png",
		CC_CALLBACK_1(BiriSceneD::storyAAAAAA, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(133);
	this->addChild(text, 5);
}
void BiriSceneD::storyAAAA(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);
	removeChildByTag(134);
	removeChildByTag(133);
	removeChildByTag(24);
	Singletons::getInstance()->backnum = 3;
	char MyString[100];
	WideCharToMultiByte(CP_UTF8, 0, L"호동: (토론따위 흥미 없지롱~)", -1, MyString, 100, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "fonts/Bold.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(23);
	this->addChild(name, 3);


	auto textA_item = MenuItemImage::create(
		"MiniGameResources/ok_button.png",
		"MiniGameResources/ok_buttonpr.png",
		CC_CALLBACK_1(BiriSceneD::storyAAAAA, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(133);
	this->addChild(text, 5);
}
void BiriSceneD::storyAAAAA(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);
	log("start1 after delay");
	auto scene = TransitionCrossFade::create(1.5, MainBiriScene::createScene());
	Director::getInstance()->replaceScene(scene);
//Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
//Director::getInstance()->replaceScene(MainBiriScene::createScene());
}
void BiriSceneD::storyAAAAAA(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);
	removeChildByTag(133);
	removeChildByTag(23);
	removeChildByTag(136);
	removeChildByTag(26);
	//춤
	auto textA_item_1 = MenuItemImage::create(
		"MiniGameResources/texts7.png",
		"MiniGameResources/texts7.png",
		CC_CALLBACK_1(BiriSceneD::storyA_1, this));
	textA_item_1->setAnchorPoint(Point(0.5, 0.5));
	textA_item_1->setPosition(Point(240, 105));

	auto text_1 = Menu::create(textA_item_1, NULL);
	text_1->setAnchorPoint(Point(0.5, 0.5));
	text_1->setPosition(Point(0, 0));
	text_1->setTag(137);
	this->addChild(text_1, 5);
	//노래
	auto textA_item = MenuItemImage::create(
		"MiniGameResources/texts8.png",
		"MiniGameResources/texts8.png",
		CC_CALLBACK_1(BiriSceneD::storyA_2, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(760, 105));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(138);
	this->addChild(text, 5);
}


//하니 대화씬2
void BiriSceneD::storyA_1(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);
	//모하니 대화씬1
	removeChildByTag(137);
	removeChildByTag(138);

	Sprite* mainchr = Sprite::create("MiniGameResources/mc_chara.png");
	mainchr->setAnchorPoint(Point(0.5, 0));
	mainchr->setPosition(Point(800, 0));
	mainchr->setTag(231);
	this->addChild(mainchr, 1);

	char MyString[100];
	WideCharToMultiByte(CP_UTF8, 0, L"사회자: 호동군 날카롭습니다! 핵심을 찔렀어요!", -1, MyString, 100, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "fonts/Bold.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(21);
	this->addChild(name, 3);


	auto textA_item = MenuItemImage::create(
		"MiniGameResources/ok_button.png",
		"MiniGameResources/ok_buttonpr.png",
		CC_CALLBACK_1(BiriSceneD::storyAA_1, this));
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
void BiriSceneD::storyAA_1(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);
	removeChildByTag(131);
	removeChildByTag(21);
	char MyString[100];
	WideCharToMultiByte(CP_UTF8, 0, L"사회자: 그렇게 되서 이번 대회의 우승은 호동이입니다!", -1, MyString, 100, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "fonts/Bold.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(22);
	this->addChild(name, 3);


	auto textA_item = MenuItemImage::create(
		"MiniGameResources/ok_button.png",
		"MiniGameResources/ok_buttonpr.png",
		CC_CALLBACK_1(BiriSceneD::storyAAA_1, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(132);
	this->addChild(text, 5);
}
void BiriSceneD::storyAAA_1(Ref *pSender)
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

	char MyString[200];
	WideCharToMultiByte(CP_UTF8, 0, L"호동: (식은죽 먹기군..) \n\n(10만원과 30의 모든능력치를 획득하였습니다.) ", -1, MyString, 200, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "fonts/Bold.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(23);
	this->addChild(name, 3);


	auto textA_item = MenuItemImage::create(
		"MiniGameResources/ok_button.png",
		"MiniGameResources/ok_buttonpr.png",
		CC_CALLBACK_1(BiriSceneD::GoHome, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(133);
	this->addChild(text, 5);

	Singletons::getInstance()->m_friendly = Singletons::getInstance()->m_friendly + 30;
	Singletons::getInstance()->m_hak = Singletons::getInstance()->m_hak + 30;
	Singletons::getInstance()->m_insung = Singletons::getInstance()->m_insung + 30;
	Singletons::getInstance()->m_jisik = Singletons::getInstance()->m_jisik + 30;
	Singletons::getInstance()->money = Singletons::getInstance()->money + 100000;
}

//하니 대화씬3
void BiriSceneD::storyA_2(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);
	removeChildByTag(137);
	removeChildByTag(138);

	char MyString[100];
	WideCharToMultiByte(CP_UTF8, 0, L"호동: 신고해서 조치를 취해야합니다!", -1, MyString, 100, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "fonts/Bold.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(21);
	this->addChild(name, 3);


	auto textA_item = MenuItemImage::create(
		"MiniGameResources/ok_button.png",
		"MiniGameResources/ok_buttonpr.png",
		CC_CALLBACK_1(BiriSceneD::storyAA_2, this));
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
void BiriSceneD::storyAA_2(Ref *pSender)
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
	WideCharToMultiByte(CP_UTF8, 0, L"사회자: ...저 선수 퇴장시켜주세요!", -1, MyString, 100, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "fonts/Bold.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(22);
	this->addChild(name, 3);


	auto textA_item = MenuItemImage::create(
		"MiniGameResources/ok_button.png",
		"MiniGameResources/ok_buttonpr.png",
		CC_CALLBACK_1(BiriSceneD::storyAAA_2, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(132);
	this->addChild(text, 5);
}
void BiriSceneD::storyfin(Ref *pSender)
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
		CC_CALLBACK_1(BiriSceneD::GoHome, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(133);
	this->addChild(text, 5);

}
void BiriSceneD::storyAAA_2(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);
	removeChildByTag(132);
	removeChildByTag(22);
	removeChildByTag(231);

	char MyString[200];
	WideCharToMultiByte(CP_UTF8, 0, L"호동: 말도안되... 이럴수가!\n\n(모든 등력치가 10 증가하였습니다.)", -1, MyString, 200, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "fonts/Bold.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(23);
	this->addChild(name, 3);

	auto textA_item = MenuItemImage::create(
		"MiniGameResources/ok_button.png",
		"MiniGameResources/ok_buttonpr.png",
		CC_CALLBACK_1(BiriSceneD::GoHome, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(132);
	this->addChild(text, 5);

	Singletons::getInstance()->m_friendly = Singletons::getInstance()->m_friendly + 10;
	Singletons::getInstance()->m_hak = Singletons::getInstance()->m_hak + 10;
	Singletons::getInstance()->m_insung = Singletons::getInstance()->m_insung + 10;
	Singletons::getInstance()->m_jisik = Singletons::getInstance()->m_jisik + 10;

}


void BiriSceneD::GoHome(Ref *pSender)
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
	
	

void BiriSceneD::skipspr(Ref *pSender)
{
	
}
