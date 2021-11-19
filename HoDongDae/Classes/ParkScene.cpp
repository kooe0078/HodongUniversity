#include "ParkScene.h"
#include "EndScene.h"
#include "SimpleAudioEngine.h"
#include "MapScene.h"
#include "MiniGameMainScene_1.h"
#include "MiniGameMainScene_2.h"
#include "MiniGameMainScene_3.h"
#include "sinngleton.h"
#include "MiroScene.h"
#include "MiroScene2.h"
#include "MiroScene3.h"
#include "ExerciseScene.h"
#include "StoryChangeScene.h"
//#include "KoreanUTF8.h"
//사운드 할라면 꼭 필요
using namespace CocosDenshion; 
USING_NS_CC;

Scene* ParkScene::createScene()
{
    auto scene = Scene::create();
    auto layer = ParkScene::create();
	
    scene->addChild(layer);

    return scene;
}

bool ParkScene::init()
{

    if ( !Layer::init() )
    {
        return false;
    }
	Size windowSize = Director::getInstance()->getWinSize();

	visibleSize = Director::getInstance()->getVisibleSize();
	origin      = Director::getInstance()->getVisibleOrigin();

	InitBackGround();
	InitMenu();
	InitLabel();
	//Vector 자세한 내용은 http://quse.kr/category/Cocos2D-X 참조하삼
	mpData = cocos2d::Vector<cocos2d::Sprite*>(100);
	
	//배경음악
	SimpleAudioEngine::getInstance()->playBackgroundMusic("sound/park sound.mp3", true);
	//스케쥴
	this->schedule(schedule_selector(ParkScene::update));
	this->schedule(schedule_selector(ParkScene::SetLabel), 0.001f);
	////키보드 리스너
	//auto keylistener = EventListenerKeyboard::create();
	//keylistener->onKeyPressed = CC_CALLBACK_2(ParkScene::onKeyPressed, this);
	//keylistener->onKeyReleased = CC_CALLBACK_2(ParkScene::onKeyReleased, this);
	//_eventDispatcher->addEventListenerWithSceneGraphPriority(keylistener, this);

    return true;
}

void ParkScene::InitBackGround()
{
	auto sprite = Sprite::create("MiniGameResources/bongsa.png");
	sprite->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	this->addChild(sprite, 0);
}

//메뉴창
void ParkScene::InitMenu()
{
	//이동창
	auto menu_item = MenuItemImage::create(
		"MiniGameResources/UI_Select1.png",
		"MiniGameResources/UI_Selectpush2.png",
		
		CC_CALLBACK_1(ParkScene::menuspr, this));
	menu_item->setAnchorPoint(Point(0.5, 0.5));
	menu_item->setPosition(Point(70,630));

	auto menu = Menu::create(menu_item, NULL);
	menu->setAnchorPoint(Point(0.5, 0.5));
	menu->setPosition(Point(0, 0));
	menu->setTag(4);
	this->addChild(menu, 1);
	//행동창
	auto action_item = MenuItemImage::create(
		"MiniGameResources/UI_Select2.png",
		"MiniGameResources/UI_Selectpush1.png",
		CC_CALLBACK_1(ParkScene::actionspr, this));
	action_item->setAnchorPoint(Point(0.5, 0.5));
	action_item->setPosition(Point(70, 565));

	auto action = Menu::create(action_item, NULL);
	action->setAnchorPoint(Point(0.5, 0.5));
	action->setPosition(Point(0, 0));
	action->setTag(4);
	this->addChild(action, 1);
	//내정보창
	auto info_item = MenuItemImage::create(
		"MiniGameResources/UI_Select3.png",
		"MiniGameResources/UI_Selectpush4.png",
		CC_CALLBACK_1(ParkScene::infospr, this));
	info_item->setAnchorPoint(Point(0.5, 0.5));
	info_item->setPosition(Point(70, 500));

	auto info = Menu::create(info_item, NULL);
	info->setAnchorPoint(Point(0.5, 0.5));
	info->setPosition(Point(0, 0));
	info->setTag(4);
	this->addChild(info, 1);
	//일정창
	auto plan_item = MenuItemImage::create(
		"MiniGameResources/UI_Select6.png",
		"MiniGameResources/UI_Selectpush5.png",
		CC_CALLBACK_1(ParkScene::planspr, this));
	plan_item->setAnchorPoint(Point(0.5, 0.5));
	plan_item->setPosition(Point(70, 435));

	auto plan = Menu::create(plan_item, NULL);
	plan->setAnchorPoint(Point(0.5, 0.5));
	plan->setPosition(Point(0, 0));
	plan->setTag(4);
	this->addChild(plan, 1);
	//시스템창
	auto system_item = MenuItemImage::create(
		"MiniGameResources/UI_Select5.png",
		"MiniGameResources/UI_Selectpush6.png",
		CC_CALLBACK_1(ParkScene::systemspr, this));
	system_item->setAnchorPoint(Point(0.5, 0.5));
	system_item->setPosition(Point(70, 370));

	auto system = Menu::create(system_item, NULL);
	system->setAnchorPoint(Point(0.5, 0.5));
	system->setPosition(Point(0, 0));
	system->setTag(4);
	this->addChild(system, 1);
	//종료창
	auto fin_item = MenuItemImage::create(
		"MiniGameResources/UI_Select7.png",
		"MiniGameResources/UI_Selectpush7.png",
		CC_CALLBACK_1(ParkScene::finalspr, this));
	fin_item->setAnchorPoint(Point(0.5, 0.5));
	fin_item->setPosition(Point(70, 305));

	auto fin = Menu::create(fin_item, NULL);
	fin->setAnchorPoint(Point(0.5, 0.5));
	fin->setPosition(Point(0, 0));
	fin->setTag(4);
	this->addChild(fin, 1);
	//시간창
	Sprite* month = Sprite::create("MiniGameResources/cal_month.png");
	month->setAnchorPoint(Point(0.5, 0));
	month->setPosition(Point(830, 650));
	//plan->setTag(44);
	this->addChild(month, 2);

	Sprite* day = Sprite::create("MiniGameResources/cal_day.png");
	day->setAnchorPoint(Point(0.5, 0));
	day->setPosition(Point(930, 651));
	//plan->setTag(44);
	this->addChild(day, 2);
	
	//머니창
	Sprite* money = Sprite::create("MiniGameResources/MONEY_UI.png");
	money->setAnchorPoint(Point(0.5, 0));
	money->setPosition(Point(780, 700));
	//plan->setTag(44);
	this->addChild(money, 2);


	//우측상단 판업창

	Sprite* mainchr_1 = Sprite::create("MiniGameResources/guesyang.png");
	mainchr_1->setAnchorPoint(Point(0.5, 0));
	mainchr_1->setPosition(Point(845, 604));
	mainchr_1->setTag(206);
	this->addChild(mainchr_1, 1);

	//메인캐릭터
	Sprite* mainchr = Sprite::create("MiniGameResources/main_char.png");
	mainchr->setAnchorPoint(Point(0.5, 0));
	mainchr->setPosition(Point(790, 30));
	//plan->setTag(44);
	this->addChild(mainchr, 1);
}
//내정보 판업창
void ParkScene::infospr(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("MiniGameResources/button_click_16_sound_effects_.mp3", false);
	if (open == false) {
		open = true;
		//tag 18~22
		//창 지우기
		auto cancel_item = MenuItemImage::create(
			"MiniGameResources/XIcon.png",
			"MiniGameResources/XIconpress.png",
			CC_CALLBACK_1(ParkScene::cancelcon, this));
		cancel_item->setAnchorPoint(Point(0.5, 0.5));
		cancel_item->setPosition(Point(730, 600));

		auto cancel = Menu::create(cancel_item, NULL);
		cancel->setAnchorPoint(Point(0.5, 0.5));
		cancel->setPosition(Point(0, 0));
		cancel->setTag(18);
		this->addChild(cancel, 4);

		//정보 판업
		Sprite* info = Sprite::create("MiniGameResources/inform.png");
		info->setAnchorPoint(Point(0.5, 0));
		info->setPosition(Point(510, 230));
		info->setTag(19);
		this->addChild(info, 3);

		//학력
		Label* hak = Label::createWithTTF(StringUtils::format(""), "MiniGameResources/CuteFont.ttf", 48);
		hak->setString(StringUtils::format("%d", Singletons::getInstance()->m_hak));
		hak->setAnchorPoint(Point(0.5, 0));
		hak->setPosition(Point(350, 260));
		hak->setColor(Color3B::BLACK);
		hak->setTag(100);
		this->addChild(hak, 5);
		//인성

		Label* insung = Label::createWithTTF(StringUtils::format(""), "MiniGameResources/CuteFont.ttf", 48);
		insung->setString(StringUtils::format("%d", Singletons::getInstance()->m_insung));
		insung->setAnchorPoint(Point(0.5, 0));
		insung->setPosition(Point(460, 260));
		insung->setColor(Color3B::BLACK);
		insung->setTag(101);
		this->addChild(insung, 5);
		//친화력
		Label* friendly = Label::createWithTTF(StringUtils::format(""), "MiniGameResources/CuteFont.ttf", 48);
		friendly->setString(StringUtils::format("%d", Singletons::getInstance()->m_friendly));
		friendly->setAnchorPoint(Point(0.5, 0));
		friendly->setPosition(Point(570, 260));
		friendly->setColor(Color3B::BLACK);
		friendly->setTag(102);
		this->addChild(friendly, 5);
		//지식
		Label* jisik = Label::createWithTTF(StringUtils::format(""), "MiniGameResources/CuteFont.ttf", 48);
		jisik->setString(StringUtils::format("%d", Singletons::getInstance()->m_jisik));
		jisik->setAnchorPoint(Point(0.5, 0));
		jisik->setPosition(Point(680, 260));
		jisik->setColor(Color3B::BLACK);
		jisik->setTag(103);
		this->addChild(jisik, 5);

		//직위
		if (Singletons::getInstance()->jik == 1)
		{
			Sprite* jik = Sprite::create("jik/1.png");
			jik->setAnchorPoint(Point(0.5, 0));
			jik->setPosition(Point(500, 430));
			jik->setTag(1900);
			this->addChild(jik, 3);
		}
		if (Singletons::getInstance()->jik == 2)
		{

			removeChildByTag(1902);
			removeChildByTag(1903);
			removeChildByTag(1904);
			Sprite* jik = Sprite::create("jik/2.png");
			jik->setAnchorPoint(Point(0.5, 0));
			jik->setPosition(Point(500, 430));
			jik->setTag(1901);
			this->addChild(jik, 3);
		}
		if (Singletons::getInstance()->jik == 3)
		{
			removeChildByTag(1901);

			removeChildByTag(1903);
			removeChildByTag(1904);
			Sprite* jik = Sprite::create("jik/3.png");
			jik->setAnchorPoint(Point(0.5, 0));
			jik->setPosition(Point(500, 430));
			jik->setTag(1902);
			this->addChild(jik, 3);
		}
		if (Singletons::getInstance()->jik == 4)
		{
			removeChildByTag(1901);
			removeChildByTag(1902);

			removeChildByTag(1904);
			Sprite* jik = Sprite::create("jik/4.png");
			jik->setAnchorPoint(Point(0.5, 0));
			jik->setPosition(Point(500, 430));
			jik->setTag(1903);
			this->addChild(jik, 3);
		}
		if (Singletons::getInstance()->jik == 5)
		{
			removeChildByTag(1901);
			removeChildByTag(1902);
			removeChildByTag(1903);

			Sprite* jik = Sprite::create("jik/5.png");
			jik->setAnchorPoint(Point(0.5, 0));
			jik->setPosition(Point(500, 430));
			jik->setTag(1904);
			this->addChild(jik, 3);
		}
		if (Singletons::getInstance()->Danger == 0)
		{
			removeChildByTag(601);
			removeChildByTag(602);
			removeChildByTag(603);
			removeChildByTag(604);
			removeChildByTag(605);
			removeChildByTag(606);
			removeChildByTag(607);
			removeChildByTag(608);
			removeChildByTag(609);
			removeChildByTag(610);
			auto spr1 = CCSprite::create("Percent/0percent.png");
			spr1->setPosition(Point(516.6, 410.3));
			spr1->setTag(600);
			this->addChild(spr1, 6);
		}

		if (10 <= Singletons::getInstance()->Danger && Singletons::getInstance()->Danger < 20)
		{
			removeChildByTag(600);

			removeChildByTag(602);
			removeChildByTag(603);
			removeChildByTag(604);
			removeChildByTag(605);
			removeChildByTag(606);
			removeChildByTag(607);
			removeChildByTag(608);
			removeChildByTag(609);
			removeChildByTag(610);
			auto spr2 = CCSprite::create("Percent/10percent.png");
			spr2->setPosition(Point(516.6, 410.3));
			spr2->setTag(601);
			this->addChild(spr2, 6);
		}
		else if (20 <= Singletons::getInstance()->Danger && Singletons::getInstance()->Danger < 30)
		{
			removeChildByTag(600);
			removeChildByTag(601);

			removeChildByTag(603);
			removeChildByTag(604);
			removeChildByTag(605);
			removeChildByTag(606);
			removeChildByTag(607);
			removeChildByTag(608);
			removeChildByTag(609);
			removeChildByTag(610);
			auto spr2 = CCSprite::create("Percent/20percent.png");
			spr2->setPosition(Point(516.6, 410.3));
			spr2->setTag(602);
			this->addChild(spr2, 6);
		}
		else if (30 <= Singletons::getInstance()->Danger && Singletons::getInstance()->Danger < 40)
		{
			removeChildByTag(600);
			removeChildByTag(601);
			removeChildByTag(602);

			removeChildByTag(604);
			removeChildByTag(605);
			removeChildByTag(606);
			removeChildByTag(607);
			removeChildByTag(608);
			removeChildByTag(609);
			removeChildByTag(610);
			auto spr2 = CCSprite::create("Percent/30percent.png");
			spr2->setPosition(Point(516.6, 410.3));
			spr2->setTag(603);
			this->addChild(spr2, 6);
		}
		else if (40 <= Singletons::getInstance()->Danger && Singletons::getInstance()->Danger < 50)
		{
			removeChildByTag(600);
			removeChildByTag(601);
			removeChildByTag(602);
			removeChildByTag(603);

			removeChildByTag(605);
			removeChildByTag(606);
			removeChildByTag(607);
			removeChildByTag(608);
			removeChildByTag(609);
			removeChildByTag(610);
			auto spr2 = CCSprite::create("Percent/40percent.png");
			spr2->setPosition(Point(516.6, 410.3));
			spr2->setTag(604);
			this->addChild(spr2, 6);
		}
		else if (50 <= Singletons::getInstance()->Danger && Singletons::getInstance()->Danger < 60)
		{
			removeChildByTag(600);
			removeChildByTag(601);
			removeChildByTag(602);
			removeChildByTag(603);
			removeChildByTag(604);

			removeChildByTag(606);
			removeChildByTag(607);
			removeChildByTag(608);
			removeChildByTag(609);
			removeChildByTag(610);
			auto spr2 = CCSprite::create("Percent/50percent.png");
			spr2->setPosition(Point(516.6, 410.3));
			spr2->setTag(605);
			this->addChild(spr2, 6);
		}
		else if (60 <= Singletons::getInstance()->Danger && Singletons::getInstance()->Danger < 70)
		{
			removeChildByTag(600);
			removeChildByTag(601);
			removeChildByTag(602);
			removeChildByTag(603);
			removeChildByTag(604);
			removeChildByTag(605);

			removeChildByTag(607);
			removeChildByTag(608);
			removeChildByTag(609);
			removeChildByTag(610);
			auto spr2 = CCSprite::create("Percent/60percent.png");
			spr2->setPosition(Point(516.6, 410.3));
			spr2->setTag(606);
			this->addChild(spr2, 6);
		}
		else if (70 <= Singletons::getInstance()->Danger && Singletons::getInstance()->Danger < 80)
		{
			removeChildByTag(600);
			removeChildByTag(601);
			removeChildByTag(602);
			removeChildByTag(603);
			removeChildByTag(604);
			removeChildByTag(605);
			removeChildByTag(606);

			removeChildByTag(608);
			removeChildByTag(609);
			removeChildByTag(610);
			auto spr2 = CCSprite::create("Percent/70percent.png");
			spr2->setPosition(Point(516.6, 410.3));
			spr2->setTag(607);
			this->addChild(spr2, 6);
		}
		else if (80 <= Singletons::getInstance()->Danger && Singletons::getInstance()->Danger < 90)
		{
			removeChildByTag(600);
			removeChildByTag(601);
			removeChildByTag(602);
			removeChildByTag(603);
			removeChildByTag(604);
			removeChildByTag(605);
			removeChildByTag(606);
			removeChildByTag(607);

			removeChildByTag(609);
			removeChildByTag(610);
			auto spr2 = CCSprite::create("Percent/80percent.png");
			spr2->setPosition(Point(516.6, 410.3));
			spr2->setTag(608);
			this->addChild(spr2, 6);
		}
		else if (90 <= Singletons::getInstance()->Danger && Singletons::getInstance()->Danger < 100)
		{
			removeChildByTag(600);
			removeChildByTag(601);
			removeChildByTag(602);
			removeChildByTag(603);
			removeChildByTag(604);
			removeChildByTag(605);
			removeChildByTag(606);
			removeChildByTag(607);
			removeChildByTag(608);

			removeChildByTag(610);
			auto spr2 = CCSprite::create("Percent/90percent.png");
			spr2->setPosition(Point(516.6, 410.3));
			spr2->setTag(609);
			this->addChild(spr2, 6);
		}
		else if (Singletons::getInstance()->Danger >= 100)
		{
			removeChildByTag(600);
			removeChildByTag(601);
			removeChildByTag(602);
			removeChildByTag(603);
			removeChildByTag(604);
			removeChildByTag(605);
			removeChildByTag(606);
			removeChildByTag(607);
			removeChildByTag(608);
			removeChildByTag(609);

			auto spr2 = CCSprite::create("Percent/100percent.png");
			spr2->setPosition(Point(516.6, 410.3));
			spr2->setTag(610);
			this->addChild(spr2, 6);
		}
	}
	else if (open == true)
	{
	
		removeChildByTag(8);
		removeChildByTag(9);
		removeChildByTag(10);
		removeChildByTag(11);
		removeChildByTag(30);
		removeChildByTag(31);
		removeChildByTag(32);
		removeChildByTag(40);
		removeChildByTag(41);
		removeChildByTag(42);
		removeChildByTag(43);
		removeChildByTag(44);
		removeChildByTag(45);
		removeChildByTag(46);
		removeChildByTag(47);
		removeChildByTag(48);
		removeChildByTag(18);
		removeChildByTag(19);
		removeChildByTag(20);
		removeChildByTag(21);
		removeChildByTag(22);
		removeChildByTag(50);
		removeChildByTag(51);
		removeChildByTag(52);
		removeChildByTag(53);
		removeChildByTag(100);
		removeChildByTag(101);
		removeChildByTag(102);
		removeChildByTag(103);
		removeChildByTag(104);
		removeChildByTag(109);
		removeChildByTag(110);
		removeChildByTag(111);
		removeChildByTag(320);
		removeChildByTag(321);
		removeChildByTag(322);
		removeChildByTag(323);
		removeChildByTag(324);
		removeChildByTag(325);
		removeChildByTag(326);
		removeChildByTag(1900);
		removeChildByTag(1901);
		removeChildByTag(1902);
		removeChildByTag(1903);
		removeChildByTag(1904);
		removeChildByTag(600);
		removeChildByTag(601);
		removeChildByTag(602);
		removeChildByTag(603);
		removeChildByTag(604);
		removeChildByTag(605);
		removeChildByTag(606);
		removeChildByTag(607);
		removeChildByTag(608);
		removeChildByTag(609);
		removeChildByTag(610);
		open = false;
	}
}
//시스템창
void ParkScene::systemspr(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);

	if (open == false)
	{
		open = true;
	
		//노래 on/off
		char MyString[50];
		WideCharToMultiByte(CP_UTF8, 0, L"배경음악 on/off", -1, MyString, 50, NULL, NULL);
		auto name = Label::createWithTTF(MyString, "fonts/ABC.ttf", 25);
		name->setAnchorPoint(Point(0, 1));
		name->setPosition(Point(358, 440));
		name->setColor(Color3B::BLACK);
		name->setTag(51);
		this->addChild(name, 4);
		//삭제
		auto cancel_item = MenuItemImage::create(
			"MiniGameResources/XIcon.png",
			"MiniGameResources/XIconpress.png",
			CC_CALLBACK_1(ParkScene::cancelcon, this));
		cancel_item->setAnchorPoint(Point(0.5, 0.5));
		cancel_item->setPosition(Point(697, 548));

		auto cancel = Menu::create(cancel_item, NULL);
		cancel->setAnchorPoint(Point(0.5, 0.5));
		cancel->setPosition(Point(0, 0));
		cancel->setTag(18);
		this->addChild(cancel, 3);
		//시스템판업창
		Sprite* system = Sprite::create("MiniGameResources/sistem_UI.png");
		system->setAnchorPoint(Point(0.5, 0));
		system->setPosition(Point(520, 260));
		system->setTag(109);
		this->addChild(system, 2);
		//노래 온
		auto on_item = MenuItemImage::create(
			"MiniGameResources/on_swich.png",
			"MiniGameResources/on_swich.png",
			CC_CALLBACK_1(ParkScene::soundoff, this));
		on_item->setAnchorPoint(Point(0.5, 0.5));
		on_item->setPosition(Point(610, 430));

		auto on = Menu::create(on_item, NULL);
		on->setAnchorPoint(Point(0.5, 0.5));
		on->setPosition(Point(0, 0));
		on->setTag(110);
		this->addChild(on, 3);
	}
	else if (open == true)
	{
		removeChildByTag(8);
		removeChildByTag(9);
		removeChildByTag(10);
		removeChildByTag(11);
		removeChildByTag(30);
		removeChildByTag(31);
		removeChildByTag(32);
		removeChildByTag(40);
		removeChildByTag(41);
		removeChildByTag(42);
		removeChildByTag(43);
		removeChildByTag(44);
		removeChildByTag(45);
		removeChildByTag(46);
		removeChildByTag(47);
		removeChildByTag(48);
		removeChildByTag(18);
		removeChildByTag(19);
		removeChildByTag(20);
		removeChildByTag(21);
		removeChildByTag(22);
		removeChildByTag(50);
		removeChildByTag(51);
		removeChildByTag(52);
		removeChildByTag(53);
		removeChildByTag(100);
		removeChildByTag(101);
		removeChildByTag(102);
		removeChildByTag(103);
		removeChildByTag(104);
		removeChildByTag(109);
		removeChildByTag(110);
		removeChildByTag(111);
		removeChildByTag(320);
		removeChildByTag(321);
		removeChildByTag(322);
		removeChildByTag(323);
		removeChildByTag(324);
		removeChildByTag(325);
		removeChildByTag(326);
		removeChildByTag(1900);
		removeChildByTag(1901);
		removeChildByTag(1902);
		removeChildByTag(1903);
		removeChildByTag(1904);
		removeChildByTag(600);
		removeChildByTag(601);
		removeChildByTag(602);
		removeChildByTag(603);
		removeChildByTag(604);
		removeChildByTag(605);
		removeChildByTag(606);
		removeChildByTag(607);
		removeChildByTag(608);
		removeChildByTag(609);
		removeChildByTag(610);
		open = false;
	}
	
}
void ParkScene::soundoff(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);

	SimpleAudioEngine::getInstance()->stopBackgroundMusic();		
	removeChildByTag(110);
	//노래 오프
	auto off_item = MenuItemImage::create(
		"MiniGameResources/off_swich.png",
		"MiniGameResources/off_swich.png",
		CC_CALLBACK_1(ParkScene::soundon, this));
	off_item->setAnchorPoint(Point(0.5, 0.5));
	off_item->setPosition(Point(610, 430));

	auto off = Menu::create(off_item, NULL);
	off->setAnchorPoint(Point(0.5, 0.5));
	off->setPosition(Point(0, 0));
	off->setTag(111);
	this->addChild(off, 3);
}
void ParkScene::soundon(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);

	//노래 다시 온
	SimpleAudioEngine::getInstance()->playBackgroundMusic("sound/park sound.mp3", true);
	removeChildByTag(111);
	auto on_item = MenuItemImage::create(
		"MiniGameResources/on_swich.png",
		"MiniGameResources/on_swich.png",
		CC_CALLBACK_1(ParkScene::soundoff, this));
	on_item->setAnchorPoint(Point(0.5, 0.5));
	on_item->setPosition(Point(610, 430));

	auto on = Menu::create(on_item, NULL);
	on->setAnchorPoint(Point(0.5, 0.5));
	on->setPosition(Point(0, 0));
	on->setTag(110);
	this->addChild(on, 3);
}
//행동 클릭시 메뉴창
void ParkScene::actionspr(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);

	if (open == false) {

		open = true;
		//tag 8~11
		//대화하기
		auto action_item = MenuItemImage::create(
			"MiniGameResources/UI_move1.png",
			"MiniGameResources/UI_move1pr.png",
			// 임시 
			CC_CALLBACK_1(ParkScene::tell, this));
		action_item->setPosition(Point(0, 0));

		auto Study = Menu::create(action_item, NULL);
		Study->setAnchorPoint(Point(0.5, 0.5));
		Study->setPosition(Point(200, 565));
		Study->setTag(8);
		this->addChild(Study, 1);
		//봉사하기
		auto action_item1 = MenuItemImage::create(
			"MiniGameResources/UI_move2.png",
			"MiniGameResources/UI_move2pr.png",
			// 임시 
			CC_CALLBACK_1(ParkScene::servicespr, this));
		action_item1->setPosition(Point(0, 0));

		auto service = Menu::create(action_item1, NULL);
		service->setAnchorPoint(Point(0.5, 0.5));
		service->setPosition(Point(200, 505));
		service->setTag(9);
		this->addChild(service, 1);
		//산책하기
		auto action_item2 = MenuItemImage::create(
			"MiniGameResources/UI_move15.png",
			"MiniGameResources/UI_move15pr.png",
			// 임시 
			CC_CALLBACK_1(ParkScene::miro, this));
		action_item2->setPosition(Point(0, 0));

		auto say = Menu::create(action_item2, NULL);
		say->setAnchorPoint(Point(0.5, 0.5));
		say->setPosition(Point(200, 445));
		say->setTag(10);
		this->addChild(say, 1);
		//운동하기
		auto action_item3 = MenuItemImage::create(
			"MiniGameResources/UI_move8.png",
			"MiniGameResources/UI_move8pr.png",
			// 임시 
			CC_CALLBACK_1(ParkScene::health, this));
		action_item3->setPosition(Point(0, 0));

		auto play = Menu::create(action_item3, NULL);
		play->setAnchorPoint(Point(0.5, 0.5));
		play->setPosition(Point(200, 385));
		play->setTag(11);
		this->addChild(play, 1);
	}

	else if (open == true)
	{
		removeChildByTag(8);
		removeChildByTag(9);
		removeChildByTag(10);
		removeChildByTag(11);
		removeChildByTag(30);
		removeChildByTag(31);
		removeChildByTag(32);
		removeChildByTag(40);
		removeChildByTag(41);
		removeChildByTag(42);
		removeChildByTag(43);
		removeChildByTag(44);
		removeChildByTag(45);
		removeChildByTag(46);
		removeChildByTag(47);
		removeChildByTag(48);
		removeChildByTag(18);
		removeChildByTag(19);
		removeChildByTag(20);
		removeChildByTag(21);
		removeChildByTag(22);
		removeChildByTag(50);
		removeChildByTag(51);
		removeChildByTag(52);
		removeChildByTag(53);
		removeChildByTag(100);
		removeChildByTag(101);
		removeChildByTag(102);
		removeChildByTag(103);
		removeChildByTag(104);
		removeChildByTag(109);
		removeChildByTag(110);
		removeChildByTag(111);
		removeChildByTag(320);
		removeChildByTag(321);
		removeChildByTag(322);
		removeChildByTag(323);
		removeChildByTag(324);
		removeChildByTag(325);
		removeChildByTag(326);
		removeChildByTag(1900);
		removeChildByTag(1901);
		removeChildByTag(1902);
		removeChildByTag(1903);
		removeChildByTag(1904);
		removeChildByTag(600);
		removeChildByTag(601);
		removeChildByTag(602);
		removeChildByTag(603);
		removeChildByTag(604);
		removeChildByTag(605);
		removeChildByTag(606);
		removeChildByTag(607);
		removeChildByTag(608);
		removeChildByTag(609);
		removeChildByTag(610);
		open = false;
	}
}
void ParkScene::tell(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);

	Singletons::getInstance()->num_5 = 3;
	Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
	Director::getInstance()->replaceScene(StoryChangeScene::createScene());
}
void ParkScene::miro(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);

	if (Singletons::getInstance()->m_insung <= 299)
	{
		Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
		Director::getInstance()->replaceScene(MiroScene::createScene());
	}
	if (Singletons::getInstance()->m_insung >=300&& Singletons::getInstance()->m_insung<=599)
	{
		Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
		Director::getInstance()->replaceScene(MiroScene3::createScene());
	}
	if (Singletons::getInstance()->m_insung >=600)
	{
		Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
		Director::getInstance()->replaceScene(MiroScene2::createScene());
	}
}
//이동 클릭시 메뉴창
void ParkScene::menuspr(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);
	Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
	Director::getInstance()->replaceScene(MapScene::createScene());
	
}
void ParkScene::servicespr(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);

	if (Singletons::getInstance()->m_insung <= 299)
	{
		Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
		Director::getInstance()->replaceScene(MiniGameMainScene_1::createScene());
	}
	
	if (Singletons::getInstance()->m_insung>=300 && Singletons::getInstance()->m_insung <= 599)
	{
		Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
		Director::getInstance()->replaceScene(MiniGameMainScene_2::createScene());
	}

	if (Singletons::getInstance()->m_insung >= 600)
	{
		Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
		Director::getInstance()->replaceScene(MiniGameMainScene_3::createScene());
	}
}
void ParkScene::health(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);

	Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
	Director::getInstance()->replaceScene(ExerciseScene::createScene());
}
//일지 판업창
void ParkScene::planspr(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);
		if (openB == false)
		{
			openB = true;
			removeChildByTag(46);
			removeChildByTag(47);
			//tag 44
			//노트창
			Sprite* plan = Sprite::create("MiniGameResources/NOTESKEDULE.png");
			plan->setAnchorPoint(Point(0.5, 0));
			plan->setPosition(Point(525, 130));
			plan->setTag(44);
			this->addChild(plan, 1);
			//창 지우기
			auto cancel_item = MenuItemImage::create(
				"MiniGameResources/XIcon.png",
				"MiniGameResources/XIconpress.png",
				CC_CALLBACK_1(ParkScene::cancelcon, this));
			cancel_item->setAnchorPoint(Point(0.5, 0.5));
			cancel_item->setPosition(Point(702, 658));

			auto cancel = Menu::create(cancel_item, NULL);
			cancel->setAnchorPoint(Point(0.5, 0.5));
			cancel->setPosition(Point(0, 0));
			cancel->setTag(48);
			this->addChild(cancel, 3);

			char MyString_1[100];
			WideCharToMultiByte(CP_UTF8, 0, L"3월 15-17일: MT", -1, MyString_1, 100, NULL, NULL);
			auto name_1 = Label::createWithTTF(MyString_1, "fonts/Bold.ttf", 25);
			name_1->setAnchorPoint(Point(0, 1));
			name_1->setPosition(Point(370, 630));
			name_1->setColor(Color3B::BLACK);
			name_1->setTag(320);
			this->addChild(name_1, 1);

			char MyString_2[100];
			WideCharToMultiByte(CP_UTF8, 0, L"6월 23-26일: 학교축제", -1, MyString_2, 100, NULL, NULL);
			auto name_2 = Label::createWithTTF(MyString_2, "fonts/Bold.ttf", 25);
			name_2->setAnchorPoint(Point(0, 1));
			name_2->setPosition(Point(370, 570));
			name_2->setColor(Color3B::BLACK);
			name_2->setTag(321);
			this->addChild(name_2, 1);

			char MyString_3[100];
			WideCharToMultiByte(CP_UTF8, 0, L"7월2-3일: 퀴즈대회", -1, MyString_3, 100, NULL, NULL);
			auto name_3 = Label::createWithTTF(MyString_3, "fonts/Bold.ttf", 25);
			name_3->setAnchorPoint(Point(0, 1));
			name_3->setPosition(Point(370, 500));
			name_3->setColor(Color3B::BLACK);
			name_3->setTag(322);
			this->addChild(name_3, 1);

			char MyString_4[100];
			WideCharToMultiByte(CP_UTF8, 0, L"8월10-11일: 토론대회", -1, MyString_4, 100, NULL, NULL);
			auto name_4 = Label::createWithTTF(MyString_4, "fonts/Bold.ttf", 25);
			name_4->setAnchorPoint(Point(0, 1));
			name_4->setPosition(Point(370, 430));
			name_4->setColor(Color3B::BLACK);
			name_4->setTag(323);
			this->addChild(name_4, 1);

			char MyString_5[100];
			WideCharToMultiByte(CP_UTF8, 0, L"9월29-30일: 체육대회", -1, MyString_5, 100, NULL, NULL);
			auto name_5 = Label::createWithTTF(MyString_5, "fonts/Bold.ttf", 25);
			name_5->setAnchorPoint(Point(0, 1));
			name_5->setPosition(Point(370, 360));
			name_5->setColor(Color3B::BLACK);
			name_5->setTag(324);
			this->addChild(name_5, 1);

			char MyString_6[100];
			WideCharToMultiByte(CP_UTF8, 0, L"10월23-25일: 예술 박람회", -1, MyString_6, 100, NULL, NULL);
			auto name_6 = Label::createWithTTF(MyString_6, "fonts/Bold.ttf", 25);
			name_6->setAnchorPoint(Point(0, 1));
			name_6->setPosition(Point(370, 290));
			name_6->setColor(Color3B::BLACK);
			name_6->setTag(325);
			this->addChild(name_6, 1);

			char MyString_7[100];
			WideCharToMultiByte(CP_UTF8, 0, L"11월 2-4일: 작가 초대전시회", -1, MyString_7, 100, NULL, NULL);
			auto name_7 = Label::createWithTTF(MyString_7, "fonts/Bold.ttf", 25);
			name_7->setAnchorPoint(Point(0, 1));
			name_7->setPosition(Point(370, 220));
			name_7->setColor(Color3B::BLACK);
			name_7->setTag(326);
			this->addChild(name_7, 1);
		}
		else if (openB == true) {
			removeChildByTag(8);
			removeChildByTag(9);
			removeChildByTag(10);
			removeChildByTag(11);
			removeChildByTag(30);
			removeChildByTag(31);
			removeChildByTag(32);
			removeChildByTag(40);
			removeChildByTag(41);
			removeChildByTag(42);
			removeChildByTag(43);
			removeChildByTag(44);
			removeChildByTag(45);
			removeChildByTag(46);
			removeChildByTag(47);
			removeChildByTag(48);
			removeChildByTag(48);
			removeChildByTag(18);
			removeChildByTag(19);
			removeChildByTag(20);
			removeChildByTag(21);
			removeChildByTag(22);
			removeChildByTag(50);
			removeChildByTag(51);
			removeChildByTag(52);
			removeChildByTag(53);
			removeChildByTag(100);
			removeChildByTag(101);
			removeChildByTag(102);
			removeChildByTag(103);
			removeChildByTag(104);
			removeChildByTag(109);
			removeChildByTag(110);
			removeChildByTag(111);
			removeChildByTag(320);
			removeChildByTag(321);
			removeChildByTag(322);
			removeChildByTag(323);
			removeChildByTag(324);
			removeChildByTag(325);
			removeChildByTag(326);
			removeChildByTag(1900);
			removeChildByTag(1901);
			removeChildByTag(1902);
			removeChildByTag(1903);
			removeChildByTag(1904);
			removeChildByTag(600);
			removeChildByTag(601);
			removeChildByTag(602);
			removeChildByTag(603);
			removeChildByTag(604);
			removeChildByTag(605);
			removeChildByTag(606);
			removeChildByTag(607);
			removeChildByTag(608);
			removeChildByTag(609);
			removeChildByTag(610);
			openB = false;
		}
	}


void ParkScene::cancelcon(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);

	removeChildByTag(8);
	removeChildByTag(9);
	removeChildByTag(10);
	removeChildByTag(11);
	removeChildByTag(30);
	removeChildByTag(31);
	removeChildByTag(32);
	removeChildByTag(40);
	removeChildByTag(41);
	removeChildByTag(42);
	removeChildByTag(43);
	removeChildByTag(44);
	removeChildByTag(45);
	removeChildByTag(46);
	removeChildByTag(47);
	removeChildByTag(48);
	removeChildByTag(18);
	removeChildByTag(19);
	removeChildByTag(20);
	removeChildByTag(21);
	removeChildByTag(22);
	removeChildByTag(50);
	removeChildByTag(51);
	removeChildByTag(52);
	removeChildByTag(53);
	removeChildByTag(100);
	removeChildByTag(101);
	removeChildByTag(102);
	removeChildByTag(103);
	removeChildByTag(104);
	removeChildByTag(109);
	removeChildByTag(110);
	removeChildByTag(111);
	removeChildByTag(320);
	removeChildByTag(321);
	removeChildByTag(322);
	removeChildByTag(323);
	removeChildByTag(324);
	removeChildByTag(325);
	removeChildByTag(326);
	removeChildByTag(1900);
	removeChildByTag(1901);
	removeChildByTag(1902);
	removeChildByTag(1903);
	removeChildByTag(1904);
	removeChildByTag(600);
	removeChildByTag(601);
	removeChildByTag(602);
	removeChildByTag(603);
	removeChildByTag(604);
	removeChildByTag(605);
	removeChildByTag(606);
	removeChildByTag(607);
	removeChildByTag(608);
	removeChildByTag(609);
	removeChildByTag(610);
}

void ParkScene::finalspr(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);

	if (open == false) {

		open = true;
		//tag 50~53
		//종료 판업창
		Sprite* exit = Sprite::create("MiniGameResources/UI_exit.png");
		exit->setAnchorPoint(Point(0.5, 0));
		exit->setPosition(Point(520, 400));
		exit->setTag(50);
		this->addChild(exit, 1);

		char MyString[50];
		WideCharToMultiByte(CP_UTF8, 0, L"종료하시겠습니까?", -1, MyString, 50, NULL, NULL);
		auto name = Label::createWithTTF(MyString, "fonts/ABC.ttf", 25);
		name->setAnchorPoint(Point(0, 1));
		name->setPosition(Point(430, 525));
		name->setColor(Color3B::BLACK);
		name->setTag(51);
		this->addChild(name, 4);
		
		//종료 수락
		auto exitok_item = MenuItemImage::create(
			"MiniGameResources/OIcon.png",
			"MiniGameResources/OIconpress.png",
			CC_CALLBACK_1(ParkScene::exitspr, this));
		exitok_item->setPosition(Point(0, 0));


		auto exitok = Menu::create(exitok_item, NULL);
		exitok->setAnchorPoint(Point(0.5, 0.5));
		exitok->setPosition(Point(480, 435));
		exitok->setTag(52);
		this->addChild(exitok, 2);
		//종료 거절
		auto refuse_item = MenuItemImage::create(
			"MiniGameResources/XIcon.png",
			"MiniGameResources/XIconpress.png",
			CC_CALLBACK_1(ParkScene::cancelcon, this));
		refuse_item->setPosition(Point(0, 0));


		auto refuse = Menu::create(refuse_item, NULL);
		refuse->setAnchorPoint(Point(0.5, 0.5));
		refuse->setPosition(Point(560, 435));
		refuse->setTag(53);
		this->addChild(refuse, 2);

	}

	else if (open == true)
	{
		removeChildByTag(8);
		removeChildByTag(9);
		removeChildByTag(10);
		removeChildByTag(11);
		removeChildByTag(30);
		removeChildByTag(31);
		removeChildByTag(32);
		removeChildByTag(40);
		removeChildByTag(41);
		removeChildByTag(42);
		removeChildByTag(43);
		removeChildByTag(44);
		removeChildByTag(45);
		removeChildByTag(46);
		removeChildByTag(47);
		removeChildByTag(48);
		removeChildByTag(18);
		removeChildByTag(19);
		removeChildByTag(20);
		removeChildByTag(21);
		removeChildByTag(22);
		removeChildByTag(50);
		removeChildByTag(51);
		removeChildByTag(52);
		removeChildByTag(53);
		removeChildByTag(100);
		removeChildByTag(101);
		removeChildByTag(102);
		removeChildByTag(103);
		removeChildByTag(104);
		removeChildByTag(109);
		removeChildByTag(110);
		removeChildByTag(111);
		removeChildByTag(320);
		removeChildByTag(321);
		removeChildByTag(322);
		removeChildByTag(323);
		removeChildByTag(324);
		removeChildByTag(325);
		removeChildByTag(326);
		removeChildByTag(1900);
		removeChildByTag(1901);
		removeChildByTag(1902);
		removeChildByTag(1903);
		removeChildByTag(1904);
		removeChildByTag(600);
		removeChildByTag(601);
		removeChildByTag(602);
		removeChildByTag(603);
		removeChildByTag(604);
		removeChildByTag(605);
		removeChildByTag(606);
		removeChildByTag(607);
		removeChildByTag(608);
		removeChildByTag(609);
		removeChildByTag(610);
		open = false;
	}
}
//종료 수락시
void ParkScene::exitspr(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);

	Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif
}

void ParkScene::SetLabel(float delta)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);

	Label* label = (Label*)this->getChildByTag(5);
	label->setString(StringUtils::format("%d", Singletons::getInstance()->day));


	Label* label_1 = (Label*)this->getChildByTag(6);
	label_1->setString(StringUtils::format("%d", Singletons::getInstance()->month));


	Label* label_2 = (Label*)this->getChildByTag(7);
	label_2->setString(StringUtils::format("%d", Singletons::getInstance()->money));


	if (Singletons::getInstance()->month == 1)
	{
		if (Singletons::getInstance()->day > 31.5)
		{
			Singletons::getInstance()->month += 1;
			Singletons::getInstance()->day = 1;
		}
	}
	if (Singletons::getInstance()->month == 2)
	{
		if (Singletons::getInstance()->day > 28.5)
		{
			Singletons::getInstance()->month += 1;
			Singletons::getInstance()->day = 1;
		}
	}
	if (Singletons::getInstance()->month == 3)
	{
		if (Singletons::getInstance()->day > 31.5)
		{
			Singletons::getInstance()->month += 1;
			Singletons::getInstance()->day = 1;
		}
	}
	if (Singletons::getInstance()->month == 4)
	{
		if (Singletons::getInstance()->day > 30.5)
		{
			Singletons::getInstance()->month += 1;
			Singletons::getInstance()->day = 1;
		}
	}
	if (Singletons::getInstance()->month == 5)
	{
		if (Singletons::getInstance()->day > 31.5)
		{
			Singletons::getInstance()->month += 1;
			Singletons::getInstance()->day = 1;
		}
	}
	if (Singletons::getInstance()->month == 6)
	{
		if (Singletons::getInstance()->day > 30.5)
		{
			Singletons::getInstance()->month += 1;
			Singletons::getInstance()->day = 1;
		}
	}
	if (Singletons::getInstance()->month == 7)
	{
		if (Singletons::getInstance()->day > 31.5)
		{
			Singletons::getInstance()->month += 1;
			Singletons::getInstance()->day = 1;
		}
	}
	if (Singletons::getInstance()->month == 8)
	{
		if (Singletons::getInstance()->day > 31.5)
		{
			Singletons::getInstance()->month += 1;
			Singletons::getInstance()->day = 1;
		}
	}
	if (Singletons::getInstance()->month == 9)
	{
		if (Singletons::getInstance()->day > 30.5)
		{
			Singletons::getInstance()->month += 1;
			Singletons::getInstance()->day = 1;
		}
	}
	if (Singletons::getInstance()->month == 10)
	{
		if (Singletons::getInstance()->day > 31.5)
		{
			Singletons::getInstance()->month += 1;
			Singletons::getInstance()->day = 1;
		}
	}
	if (Singletons::getInstance()->month == 11)
	{
		if (Singletons::getInstance()->day > 30.5)
		{
			Singletons::getInstance()->month += 1;
			Singletons::getInstance()->day = 1;
		}
	}
	if (Singletons::getInstance()->month == 12)
	{
		if (Singletons::getInstance()->day > 31.5)
		{
			Singletons::getInstance()->month += 1;
			Singletons::getInstance()->day = 1;
			Singletons::getInstance()->month = 1;
		}
	}


}
	void ParkScene::InitLabel()
{
		//요일
	Label* day = Label::createWithTTF(StringUtils::format(""), "MiniGameResources/CuteFont.ttf", 48);
	day->setAnchorPoint(Point(0.5, 0));
	day->setPosition(Point(890, 642));
	day->setColor(Color3B::BLACK);
	day->setTag(5);
	this->addChild(day, 3);
	//달
	Label* month = Label::createWithTTF(StringUtils::format(""), "MiniGameResources/CuteFont.ttf", 48);
	month->setAnchorPoint(Point(0.5, 0));
	month->setPosition(Point(790, 642));
	month->setColor(Color3B::BLACK);
	month->setTag(6);
	this->addChild(month, 3);

	//돈
	Label* money = Label::createWithTTF(StringUtils::format(""), "MiniGameResources/CuteFont.ttf", 40);
	money->setAnchorPoint(Point(0.5, 0));
	money->setPosition(Point(890, 710));
	money->setColor(Color3B::BLACK);
	money->setTag(7);
	this->addChild(money, 3);
}