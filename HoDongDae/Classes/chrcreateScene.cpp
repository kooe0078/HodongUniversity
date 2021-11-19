#include "chrcreateScene.h"
#include "SimpleAudioEngine.h"
#include "IntroScene.h"
//사운드 할라면 꼭 필요
using namespace CocosDenshion;
USING_NS_CC;

Scene* chrcreateScene::createScene()
{
    auto scene = Scene::create();
    auto layer = chrcreateScene::create();
    scene->addChild(layer);

    return scene;
}

bool chrcreateScene::init()
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
	SimpleAudioEngine::getInstance()->playBackgroundMusic("sound/campus sound.mp3", true);

    return true;
}
void chrcreateScene::update(float ft)
{
	//씬 자체적으로 반복 되야하는 내용
}
void chrcreateScene::InitBackGround()
{
	auto sprite = Sprite::create("MiniGameResources/Main_Scene.png");
	sprite->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	this->addChild(sprite, 0);
}
void chrcreateScene::InitLabel()
{
	

	
}

void chrcreateScene::InitMenu()
{
	//tag160~
	//int soundID_0=CocosDenshion::SimpleAudioEngine::getInstance()->playEffect

	//이동창
	auto menu_item = MenuItemImage::create(
		"MiniGameResources/UI_Select1.png",
		"MiniGameResources/UI_Selectpush2.png",

		CC_CALLBACK_1(chrcreateScene::system, this));
	menu_item->setAnchorPoint(Point(0.5, 0.5));
	menu_item->setPosition(Point(70, 630));

	auto menu = Menu::create(menu_item, NULL);
	menu->setAnchorPoint(Point(0.5, 0.5));
	menu->setPosition(Point(0, 0));
	menu->setTag(160);
	this->addChild(menu, 1);

	char MyStringA[100];
	WideCharToMultiByte(CP_UTF8, 0, L"<- 호동이를 원하는 장소로 이동시킵니다.", -1, MyStringA, 100, NULL, NULL);
	auto name = Label::createWithTTF(MyStringA, "fonts/ABC.ttf", 20);
	name->setAnchorPoint(Point(0.5, 0.5));
	name->setPosition(Point(312, 630));
	name->setColor(Color3B::BLACK);
	name->setTag(21);
	this->addChild(name, 3);
	//행동창
	auto action_item = MenuItemImage::create(
		"MiniGameResources/UI_Select2.png",
		"MiniGameResources/UI_Selectpush1.png",
		CC_CALLBACK_1(chrcreateScene::system, this));
	action_item->setAnchorPoint(Point(0.5, 0.5));
	action_item->setPosition(Point(70, 565));

	auto action = Menu::create(action_item, NULL);
	action->setAnchorPoint(Point(0.5, 0.5));
	action->setPosition(Point(0, 0));
	action->setTag(161);
	this->addChild(action, 1);

	char MyStringB[100];
	WideCharToMultiByte(CP_UTF8, 0, L"<- 호동이에게 원하는 행동을 시킵니다.", -1, MyStringB, 100, NULL, NULL);
	auto nameA = Label::createWithTTF(MyStringB, "fonts/ABC.ttf", 20);
	nameA->setAnchorPoint(Point(0.5, 0.5));
	nameA->setPosition(Point(303, 565));
	nameA->setColor(Color3B::BLACK);
	nameA->setTag(21);
	this->addChild(nameA, 3);
	//내정보창
	auto info_item = MenuItemImage::create(
		"MiniGameResources/UI_Select3.png",
		"MiniGameResources/UI_Selectpush4.png",
		CC_CALLBACK_1(chrcreateScene::system, this));
	info_item->setAnchorPoint(Point(0.5, 0.5));
	info_item->setPosition(Point(70, 500));

	auto info = Menu::create(info_item, NULL);
	info->setAnchorPoint(Point(0.5, 0.5));
	info->setPosition(Point(0, 0));
	info->setTag(162);
	this->addChild(info, 1);

	char MyStringC[200];
	WideCharToMultiByte(CP_UTF8, 0, L"    <- 호동이의 직위, 위험도, 능력치를 확인합니다.\n     직위는 일정 능력치가 오르면 자동으로 갱신됩니다.", -1, MyStringC, 200, NULL, NULL);
	auto nameB = Label::createWithTTF(MyStringC, "fonts/ABC.ttf", 20);
	nameB->setAnchorPoint(Point(0.5, 0.5));
	nameB->setPosition(Point(341, 500));
	nameB->setColor(Color3B::BLACK);
	nameB->setTag(21);
	this->addChild(nameB, 3);
	//일정창
	auto plan_item = MenuItemImage::create(
		"MiniGameResources/UI_Select6.png",
		"MiniGameResources/UI_Selectpush5.png",
		CC_CALLBACK_1(chrcreateScene::system, this));
	plan_item->setAnchorPoint(Point(0.5, 0.5));
	plan_item->setPosition(Point(70, 435));

	auto plan = Menu::create(plan_item, NULL);
	plan->setAnchorPoint(Point(0.5, 0.5));
	plan->setPosition(Point(0, 0));
	plan->setTag(163);
	this->addChild(plan, 1);

	char MyStringD[100];
	WideCharToMultiByte(CP_UTF8, 0, L"<- 학교행사 및 일정을 확인합니다.", -1, MyStringD, 100, NULL, NULL);
	auto nameC = Label::createWithTTF(MyStringD, "fonts/ABC.ttf", 20);
	nameC->setAnchorPoint(Point(0.5, 0.5));
	nameC->setPosition(Point(286, 435));
	nameC->setColor(Color3B::BLACK);
	nameC->setTag(21);
	this->addChild(nameC, 3);
	//시스템창
	auto system_item = MenuItemImage::create(
		"MiniGameResources/UI_Select5.png",
		"MiniGameResources/UI_Selectpush6.png",
		CC_CALLBACK_1(chrcreateScene::system, this));
	system_item->setAnchorPoint(Point(0.5, 0.5));
	system_item->setPosition(Point(70, 370));

	auto system = Menu::create(system_item, NULL);
	system->setAnchorPoint(Point(0.5, 0.5));
	system->setPosition(Point(0, 0));
	system->setTag(164);
	this->addChild(system, 1);

	char MyStringE[100];
	WideCharToMultiByte(CP_UTF8, 0, L"<- 배경음악 on/off를 실행합니다.", -1, MyStringE, 100, NULL, NULL);
	auto nameD = Label::createWithTTF(MyStringE, "fonts/ABC.ttf", 20);
	nameD->setAnchorPoint(Point(0.5, 0.5));
	nameD->setPosition(Point(290, 370));
	nameD->setColor(Color3B::BLACK);
	nameD->setTag(21);
	this->addChild(nameD, 3);
	//종료창
	auto fin_item = MenuItemImage::create(
		"MiniGameResources/UI_Select7.png",
		"MiniGameResources/UI_Selectpush7.png",
		CC_CALLBACK_1(chrcreateScene::system, this));
	fin_item->setAnchorPoint(Point(0.5, 0.5));
	fin_item->setPosition(Point(70, 305));

	auto fin = Menu::create(fin_item, NULL);
	fin->setAnchorPoint(Point(0.5, 0.5));
	fin->setPosition(Point(0, 0));
	fin->setTag(165);
	this->addChild(fin, 1);

	char MyStringF[100];
	WideCharToMultiByte(CP_UTF8, 0, L"<- 게임을 종료합니다.", -1, MyStringF, 100, NULL, NULL);
	auto nameE = Label::createWithTTF(MyStringF, "fonts/ABC.ttf", 20);
	nameE->setAnchorPoint(Point(0.5, 0.5));
	nameE->setPosition(Point(236, 305));
	nameE->setColor(Color3B::BLACK);
	nameE->setTag(21);
	this->addChild(nameE, 3);
	//시간창
	Sprite* month = Sprite::create("MiniGameResources/cal_month.png");
	month->setAnchorPoint(Point(0.5, 0));
	month->setPosition(Point(830, 650));
	//plan->setTag(44);
	this->addChild(month, 1);

	Sprite* day = Sprite::create("MiniGameResources/cal_day.png");
	day->setAnchorPoint(Point(0.5, 0));
	day->setPosition(Point(930, 651));
	//plan->setTag(44);
	this->addChild(day, 1);

	char MyStringG[200];  
	WideCharToMultiByte(CP_UTF8, 0, L"경과한 시간을 알수있습니다. ->\n행동을 할 경우 하루가 지나갑니다.\n매월 2일 위험도가 감소합니다.", -1, MyStringG, 200, NULL, NULL);
	auto nameF = Label::createWithTTF(MyStringG,"fonts/ABC.ttf", 20);
	nameF->setAnchorPoint(Point(0.5, 0.5));
	nameF->setPosition(Point(650, 660));
	nameF->setColor(Color3B::BLACK);
	nameF->setTag(21);
	this->addChild(nameF, 3);

	//머니창
	Sprite* money = Sprite::create("MiniGameResources/MONEY_UI.png");
	money->setAnchorPoint(Point(0.5, 0));
	money->setPosition(Point(780, 700));
	//plan->setTag(44);
	this->addChild(money, 1);

	char MyStringH[100];
	WideCharToMultiByte(CP_UTF8, 0, L"호동이가 현재 소지한 돈입니다. ->", -1, MyStringH, 100, NULL, NULL);
	auto nameG = Label::createWithTTF(MyStringH, "fonts/ABC.ttf", 20);
	nameG->setAnchorPoint(Point(0.5, 0.5));
	nameG->setPosition(Point(600, 730));
	nameG->setColor(Color3B::BLACK);
	nameG->setTag(21);
	this->addChild(nameG, 3);

	//메인캐릭터
	Sprite* mainchr = Sprite::create("MiniGameResources/main_char.png");
	mainchr->setAnchorPoint(Point(0.5, 0));
	mainchr->setPosition(Point(790, 30));
	mainchr->setTag(166);
	this->addChild(mainchr, 1);

	char MyStringI[100];
	WideCharToMultiByte(CP_UTF8, 0, L"이 게임의 주인공, 호동이 입니다. ->", -1, MyStringI, 100, NULL, NULL);
	auto nameH = Label::createWithTTF(MyStringI, "fonts/ABC.ttf", 20);
	nameH->setAnchorPoint(Point(0.5, 0.5));
	nameH->setPosition(Point(530, 270));
	nameH->setColor(Color3B::BLACK);
	nameH->setTag(21);
	this->addChild(nameH, 3);

	auto text_item = MenuItemImage::create(
		"MiniGameResources/ok_button.png",
		"MiniGameResources/ok_buttonpr.png",
		CC_CALLBACK_1(chrcreateScene::newplayspr, this));
	text_item->setAnchorPoint(Point(0.5, 0.5));
	text_item->setPosition(Point(880, 40));

	auto text = Menu::create(text_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(130);
	this->addChild(text, 5);


	
}
void chrcreateScene::fin(Ref *pSender)
{

}
void chrcreateScene::system(Ref *pSender)
{

}
void chrcreateScene::replayspr(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("MiniGameResources/button_click_16_sound_effects_.mp3", false);
	Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
	Director::getInstance()->replaceScene(IntroScene::createScene());
}
void chrcreateScene::newplayspr(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("MiniGameResources/button_click_16_sound_effects_.mp3", false);
	removeChildByTag(130);

	Sprite* exit = Sprite::create("MiniGameResources/UI_introduce.png");
	exit->setAnchorPoint(Point(0.5, 0));
	exit->setPosition(Point(515, 340));
	exit->setTag(50);
	this->addChild(exit, 4);

	char MyStringFA[200];
	WideCharToMultiByte(CP_UTF8, 0, L"목표:대학 생활 1년간 모든 수단을 동원해서 현금 6천만원을 모으자!", -1, MyStringFA, 200, NULL, NULL);
	auto nameFA = Label::createWithTTF(MyStringFA, "fonts/ABC.ttf", 28);
	nameFA->setAnchorPoint(Point(0, 1));
	nameFA->setPosition(Point(150, 425));
	nameFA->setColor(Color3B::BLACK);
	nameFA->setTag(51);
	this->addChild(nameFA, 5);

	auto text_item = MenuItemImage::create(
		"MiniGameResources/ok_button.png",
		"MiniGameResources/ok_buttonpr.png",
		CC_CALLBACK_1(chrcreateScene::replayspr, this));
	text_item->setAnchorPoint(Point(0.5, 0.5));
	text_item->setPosition(Point(865,366));

	auto text = Menu::create(text_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(140);
	this->addChild(text, 5);
}
