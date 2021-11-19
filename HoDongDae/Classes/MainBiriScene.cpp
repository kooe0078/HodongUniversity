#include "MainBiriScene.h"
#include "SimpleAudioEngine.h"
#include "NextDayScene.h"
#include "sinngleton.h"
#include "MT_L1.h"
#include "MT_L2.h"
#include "MT_L3.h"
#include "MT_L4.h"
//#include "KoreanUTF8.h"
//사운드 할라면 꼭 필요
using namespace CocosDenshion;
USING_NS_CC;
//static std::string m_id="";

Scene* MainBiriScene::createScene()
{
    auto scene = Scene::create();
    auto layer = MainBiriScene::create();
	
    scene->addChild(layer);

    return scene;
}

bool MainBiriScene::init()
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

	/*Label* chars = Label::createWithTTF(StringUtils::format(""), "MiniGameResources/CuteFont.ttf", 48);
	chars->setAnchorPoint(Point(0.5, 0));
	chars->setPosition(Point(335, 260));
	chars->setColor(Color3B::BLACK);
	chars->setTag(1515);
	this->addChild(chars, 5);*/

	//Vector 자세한 내용은 http://quse.kr/category/Cocos2D-X 참조하삼
	mpData = cocos2d::Vector<cocos2d::Sprite*>(100);
	
	//배경음악
	//SimpleAudioEngine::getInstance()->playBackgroundMusic("sound/event sound2.mp3", true);
	//스케쥴
	this->schedule(schedule_selector(MainBiriScene::update));
//	this->schedule(schedule_selector(MainBiriScene::ShowChar));
	this->schedule(schedule_selector(MainBiriScene::SetLabel), 0.001f);
	//터치 리스너 등록
	/*auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = CC_CALLBACK_2(MainBiriScene::onTouchBegan, this);
	Director::getInstance()->getEventDispatcher()->addEventListenerWithFixedPriority(listener, 1);*/

	////키보드 리스너
	//auto keylistener = EventListenerKeyboard::create();
	//keylistener->onKeyPressed = CC_CALLBACK_2(MainBiriScene::onKeyPressed, this);
	//keylistener->onKeyReleased = CC_CALLBACK_2(MainBiriScene::onKeyReleased, this);
	//_eventDispatcher->addEventListenerWithSceneGraphPriority(keylistener, this);
	//Singletons::getInstance()->day;
		//= UserDefault::getInstance()->getIntegerForKey("SaveUsing");
	
    return true;
}

void MainBiriScene::InitBackGround()
{

	{
		if (Singletons::getInstance()->backnum == 0)
		{
			auto sprite = Sprite::create("MiniGameResources/back_3.png");
			sprite->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
			this->addChild(sprite, 0);
		}
		Singletons::getInstance()->backnum = 0;
	}

	{
		if (Singletons::getInstance()->backnum == 1)
		{
			auto sprite = Sprite::create("MiniGameResources/back_6.png");
			sprite->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
			this->addChild(sprite, 0);
		}
		Singletons::getInstance()->backnum = 0;
	}

	{
		if (Singletons::getInstance()->backnum == 2)
		{
			auto sprite = Sprite::create("MiniGameResources/back_7.png");
			sprite->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
			this->addChild(sprite, 0);
		}
		Singletons::getInstance()->backnum = 0;
	}


	{
		if (Singletons::getInstance()->backnum == 3)
		{
			auto sprite = Sprite::create("MiniGameResources/back_8.png");
			sprite->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
			this->addChild(sprite, 0);
		}
		Singletons::getInstance()->backnum = 0;
	}

	{
		if (Singletons::getInstance()->backnum == 4)
		{
			auto sprite = Sprite::create("MiniGameResources/back_9.png");
			sprite->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
			this->addChild(sprite, 0);
		}
		Singletons::getInstance()->backnum = 0;
	}

	{
		if (Singletons::getInstance()->backnum == 5)
		{
			auto sprite = Sprite::create("MiniGameResources/back_10museum.png");
			sprite->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
			this->addChild(sprite, 0);
		}
		Singletons::getInstance()->backnum = 0;
	}

	{
		if (Singletons::getInstance()->backnum == 6)
		{
			auto sprite = Sprite::create("MiniGameResources/back_11.png");
			sprite->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
			this->addChild(sprite, 0);
		}
		Singletons::getInstance()->backnum = 0;
	}

	
}
//void MainBiriScene::ShowChar(float f)
//{
//
//
//	if (GetAsyncKeyState(VK_BACK) & 0x0001) {
//		if (m_id.length() > 0) {
//			m_id.erase(m_id.end() - 1);
//		}
//	}
//	for (char i = 'A'; i <= 'Z'; i++) {
//		if (GetAsyncKeyState(i) & 0x0001) {
//			if (m_id.length() > 13) {
//				m_id.erase(m_id.end() - 1);
//			}
//			m_id += tolower(i);
//		}
//	}
//
//	if (GetAsyncKeyState(VK_SPACE) & 0x0001) {
//		if (m_id.length() > 13) {
//			m_id.erase(m_id.end() - 1);
//		}
//		m_id += ' ';
//	}
//
//	Label* label = (Label*)this->getChildByTag(1515);
//	label->setString(StringUtils::format(m_id.c_str()));
//
//}
//메뉴창
void MainBiriScene::InitMenu()
{
	 //tag160~
	//int soundID_0=CocosDenshion::SimpleAudioEngine::getInstance()->playEffect
	
	//내정보

	auto action_item_5= MenuItemImage::create(
		"MiniGameResources/UI_Select3red.png",
		"MiniGameResources/UI_Select3redpr.png",
		CC_CALLBACK_1(MainBiriScene::infospr, this));
	action_item_5->setAnchorPoint(Point(0.5, 0.5));
	action_item_5->setPosition(Point(70, 565));

	auto action_8 = Menu::create(action_item_5, NULL);
	action_8->setAnchorPoint(Point(0.5, 0.5));
	action_8->setPosition(Point(0, 0));
	action_8->setTag(200);
	this->addChild(action_8, 1);

	//행동창
	auto action_item = MenuItemImage::create(
		"MiniGameResources/UI_Select2red.png",
		"MiniGameResources/UI_Select2redpr.png",
		CC_CALLBACK_1(MainBiriScene::actionspr, this));
	action_item->setAnchorPoint(Point(0.5, 0.5));
	action_item->setPosition(Point(70, 630));

	auto action = Menu::create(action_item, NULL);
	action->setAnchorPoint(Point(0.5, 0.5));
	action->setPosition(Point(0, 0));
	action->setTag(201);
	this->addChild(action, 1);
	

	

	//시스템창
	auto system_item = MenuItemImage::create(
		"MiniGameResources/UI_Select5red.png",
		"MiniGameResources/UI_Select5redpr.png",
		CC_CALLBACK_1(MainBiriScene::systemspr, this));
	system_item->setAnchorPoint(Point(0.5, 0.5));
	system_item->setPosition(Point(70, 500));

	auto system = Menu::create(system_item, NULL);
	system->setAnchorPoint(Point(0.5, 0.5));
	system->setPosition(Point(0, 0));
	system->setTag(204);
	this->addChild(system, 1);
	//종료창
	auto fin_item = MenuItemImage::create(
		"MiniGameResources/UI_Select7red.png",
		"MiniGameResources/UI_Select7redpr.png",
		CC_CALLBACK_1(MainBiriScene::finalspr, this));
	fin_item->setAnchorPoint(Point(0.5, 0.5));
	fin_item->setPosition(Point(70, 435));

	auto fin = Menu::create(fin_item, NULL);
	fin->setAnchorPoint(Point(0.5, 0.5));
	fin->setPosition(Point(0, 0));
	fin->setTag(205);
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

	//메인캐릭터
	Sprite* mainchr = Sprite::create("MiniGameResources/main_char.png");
	mainchr->setAnchorPoint(Point(0.5, 0));
	mainchr->setPosition(Point(790, 30));
	mainchr->setTag(206);
	this->addChild(mainchr, 1);
}
//내정보 판업창
void MainBiriScene::infospr(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("MiniGameResources/button_click_16_sound_effects_.mp3", false);
	if (open == false) {
		open = true;
		//tag 18~22
		//창 지우기
		auto cancel_item = MenuItemImage::create(
			"MiniGameResources/XIcon.png",
			"MiniGameResources/XIconpress.png",
			CC_CALLBACK_1(MainBiriScene::cancelcon, this));
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
void MainBiriScene::systemspr(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("MiniGameResources/button_click_16_sound_effects_.mp3", false);
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
			CC_CALLBACK_1(MainBiriScene::cancelcon, this));
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
			CC_CALLBACK_1(MainBiriScene::soundoff, this));
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

void MainBiriScene::soundoff(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("MiniGameResources/button_click_16_sound_effects_.mp3", false);
	SimpleAudioEngine::getInstance()->stopBackgroundMusic();		
	removeChildByTag(110);
	//노래 오프
	auto off_item = MenuItemImage::create(
		"MiniGameResources/off_swich.png",
		"MiniGameResources/off_swich.png",
		CC_CALLBACK_1(MainBiriScene::soundon, this));
	off_item->setAnchorPoint(Point(0.5, 0.5));
	off_item->setPosition(Point(610, 430));

	auto off = Menu::create(off_item, NULL);
	off->setAnchorPoint(Point(0.5, 0.5));
	off->setPosition(Point(0, 0));
	off->setTag(111);
	this->addChild(off, 3);
}
void MainBiriScene::soundon(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("MiniGameResources/button_click_16_sound_effects_.mp3", false);
	//노래 다시 온
	SimpleAudioEngine::getInstance()->playBackgroundMusic("sound/event sound2.mp3", true);
	removeChildByTag(111);
	auto on_item = MenuItemImage::create(
		"MiniGameResources/on_swich.png",
		"MiniGameResources/on_swich.png",
		CC_CALLBACK_1(MainBiriScene::soundoff, this));
	on_item->setAnchorPoint(Point(0.5, 0.5));
	on_item->setPosition(Point(610, 430));

	auto on = Menu::create(on_item, NULL);
	on->setAnchorPoint(Point(0.5, 0.5));
	on->setPosition(Point(0, 0));
	on->setTag(110);
	this->addChild(on, 3);
}
//행동 클릭시 메뉴창
void MainBiriScene::actionspr(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("MiniGameResources/button_click_16_sound_effects_.mp3", false);
	if (open == false) {

		open = true;
		//tag 8~11
		//상품바꾸기하기
		auto action_item = MenuItemImage::create(
			"MiniGameResources/UI_BIRI2.png",
			"MiniGameResources/UI_BIRI2pr.png",
			// 임시 
			CC_CALLBACK_1(MainBiriScene::tell, this));
		action_item->setPosition(Point(0, 0));

		auto Study = Menu::create(action_item, NULL);
		Study->setAnchorPoint(Point(0.5, 0.5));
		Study->setPosition(Point(200, 630));
		Study->setTag(8);
		this->addChild(Study, 1);
		//식비횡령
		auto action_item1 = MenuItemImage::create(
			"MiniGameResources/UI_BIRI3.png",
			"MiniGameResources/UI_BIRI3pr.png",
			// 임시 
			CC_CALLBACK_1(MainBiriScene::servicespr, this));
		action_item1->setPosition(Point(0, 0));

		auto service = Menu::create(action_item1, NULL);
		service->setAnchorPoint(Point(0.5, 0.5));
		service->setPosition(Point(200, 570));
		service->setTag(9);
		this->addChild(service, 1);
		//경비횡령
		auto action_item2 = MenuItemImage::create(
			"MiniGameResources/UI_BIRI4.png",
			"MiniGameResources/UI_BIRI4pr.png",
			// 임시 
			CC_CALLBACK_1(MainBiriScene::quiz, this));
		action_item2->setPosition(Point(0, 0));

		auto say = Menu::create(action_item2, NULL);
		say->setAnchorPoint(Point(0.5, 0.5));
		say->setPosition(Point(200, 510));
		say->setTag(10);
		this->addChild(say, 1);
		//회비걷기
		auto action_item3 = MenuItemImage::create(
			"MiniGameResources/UI_BIRI5.png",
			"MiniGameResources/UI_BIRI5pr.png",
			// 임시 
			CC_CALLBACK_1(MainBiriScene::read, this));
		action_item3->setPosition(Point(0, 0));

		auto play = Menu::create(action_item3, NULL);
		play->setAnchorPoint(Point(0.5, 0.5));
		play->setPosition(Point(200, 450));
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
		removeChildByTag(128);
		removeChildByTag(130);
		removeChildByTag(131);
		removeChildByTag(132);
		removeChildByTag(133);
		removeChildByTag(134);
		removeChildByTag(135);
		removeChildByTag(136);
		removeChildByTag(137);
		removeChildByTag(138);
		removeChildByTag(139);
		removeChildByTag(140);
		removeChildByTag(141);
		removeChildByTag(142);
		removeChildByTag(143);
		removeChildByTag(145);
		removeChildByTag(148);
		removeChildByTag(119);
		removeChildByTag(120);
		removeChildByTag(160);
		removeChildByTag(161);
		removeChildByTag(162);
		removeChildByTag(163);
		removeChildByTag(164);
		removeChildByTag(165);
		removeChildByTag(166);
		removeChildByTag(167);
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
void MainBiriScene::GoHome(Ref *pSender)
{
	Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
	Director::getInstance()->replaceScene(MainBiriScene::createScene());
}
//상품바꿔치기
void MainBiriScene::tell(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);
	if (Singletons::getInstance()->jik == 1)
	{

		Sprite* system = Sprite::create("MiniGameResources/pop_rank1.png");
		system->setAnchorPoint(Point(0.5, 0));
		system->setPosition(Point(520, 460));
		system->setTag(2100);
		this->addChild(system, 2);
		removeChildByTag(200);
		removeChildByTag(201);
		removeChildByTag(204);
		removeChildByTag(205);
		
		removeChildByTag(9);
		removeChildByTag(10);
		removeChildByTag(8);
		removeChildByTag(11);
		auto cancel_item = MenuItemImage::create(
			"MiniGameResources/XIcon.png",
			"MiniGameResources/XIconpress.png",
			CC_CALLBACK_1(MainBiriScene::GoHome, this));
		cancel_item->setAnchorPoint(Point(0.5, 0.5));
		cancel_item->setPosition(Point(520, 450));

		auto cancel = Menu::create(cancel_item, NULL);
		cancel->setAnchorPoint(Point(0.5, 0.5));
		cancel->setPosition(Point(0, 0));
		cancel->setTag(18);
		this->addChild(cancel, 3);
	}
	if (Singletons::getInstance()->jik >= 2)
	{
		Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
		Director::getInstance()->replaceScene(MT_L2::createScene());
	}
}
//식비횡령
void MainBiriScene::servicespr(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);
	if (Singletons::getInstance()->jik <= 2)
	{

		Sprite* system = Sprite::create("MiniGameResources/pop_rank2.png");
		system->setAnchorPoint(Point(0.5, 0));
		system->setPosition(Point(520, 460));
		system->setTag(2100);
		this->addChild(system, 2);
		removeChildByTag(200);
		removeChildByTag(201);
		removeChildByTag(204);
		removeChildByTag(205);

		removeChildByTag(9);
		removeChildByTag(10);
		removeChildByTag(8);
		removeChildByTag(11);
		auto cancel_item = MenuItemImage::create(
			"MiniGameResources/XIcon.png",
			"MiniGameResources/XIconpress.png",
			CC_CALLBACK_1(MainBiriScene::GoHome, this));
		cancel_item->setAnchorPoint(Point(0.5, 0.5));
		cancel_item->setPosition(Point(520, 450));

		auto cancel = Menu::create(cancel_item, NULL);
		cancel->setAnchorPoint(Point(0.5, 0.5));
		cancel->setPosition(Point(0, 0));
		cancel->setTag(18);
		this->addChild(cancel, 3);
	}
	if (Singletons::getInstance()->jik >= 3)
	{
		Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
		Director::getInstance()->replaceScene(MT_L3::createScene());
	}
	
}
//경비횡령
void MainBiriScene::quiz(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);
	if (Singletons::getInstance()->jik <= 3)
	{

		Sprite* system = Sprite::create("MiniGameResources/pop_rank3.png");
		system->setAnchorPoint(Point(0.5, 0));
		system->setPosition(Point(520, 460));
		system->setTag(2100);
		this->addChild(system, 2);
		removeChildByTag(200);
		removeChildByTag(201);
		removeChildByTag(204);
		removeChildByTag(205);

		removeChildByTag(9);
		removeChildByTag(10);
		removeChildByTag(8);
		removeChildByTag(11);
		auto cancel_item = MenuItemImage::create(
			"MiniGameResources/XIcon.png",
			"MiniGameResources/XIconpress.png",
			CC_CALLBACK_1(MainBiriScene::GoHome, this));
		cancel_item->setAnchorPoint(Point(0.5, 0.5));
		cancel_item->setPosition(Point(520, 450));

		auto cancel = Menu::create(cancel_item, NULL);
		cancel->setAnchorPoint(Point(0.5, 0.5));
		cancel->setPosition(Point(0, 0));
		cancel->setTag(18);
		this->addChild(cancel, 3);
	}
	if (Singletons::getInstance()->jik >= 4)
	{
		Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
		Director::getInstance()->replaceScene(MT_L1::createScene());
	}
	
}
//회비걷기
void MainBiriScene::read(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);
	if (Singletons::getInstance()->jik <= 4)
	{

		Sprite* system = Sprite::create("MiniGameResources/pop_rank3.png");
		system->setAnchorPoint(Point(0.5, 0));
		system->setPosition(Point(520, 460));
		system->setTag(2100);
		this->addChild(system, 2);

		removeChildByTag(200);
		removeChildByTag(201);
		removeChildByTag(204);
		removeChildByTag(205);

		removeChildByTag(9);
		removeChildByTag(10);
		removeChildByTag(8);
		removeChildByTag(11);
		auto cancel_item = MenuItemImage::create(
			"MiniGameResources/XIcon.png",
			"MiniGameResources/XIconpress.png",
			CC_CALLBACK_1(MainBiriScene::GoHome, this));
		cancel_item->setAnchorPoint(Point(0.5, 0.5));
		cancel_item->setPosition(Point(520, 450));

		auto cancel = Menu::create(cancel_item, NULL);
		cancel->setAnchorPoint(Point(0.5, 0.5));
		cancel->setPosition(Point(0, 0));
		cancel->setTag(18);
		this->addChild(cancel, 3);
	}
	if (Singletons::getInstance()->jik >= 5)
	{
		Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
		Director::getInstance()->replaceScene(MT_L4::createScene());
	}


}
//이동 클릭시 메뉴창
void MainBiriScene::menuspr(Ref *pSender)
{
	
}


//공모전 레베르1
void MainBiriScene::gonmoA(Ref *pSender)
{

	
}
//공모전1 쪼인
void MainBiriScene::gonmoAjoin(Ref *pSender)
{
	
}
//공모전 레베루2
void MainBiriScene::gonmoB(Ref *pSender)
{

}
//공모전 레베루3
void MainBiriScene::gonmoC(Ref *pSender)
{

}



//행동-릭기-책오픈
void MainBiriScene::bookopen(Ref *pSender)
{
	
}
void MainBiriScene::bookcloseB(Ref *pSender)
{
	
}
//행동후 다음날로 넘어갈떄
void MainBiriScene::nextday(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("MiniGameResources/button_click_16_sound_effects_.mp3", false);
	Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
	Director::getInstance()->replaceScene(NextDayScene::createScene());
}
void MainBiriScene::trash(Ref *pSender)
{
	//필요없는함수 이리이리 모여라
}
//일지 판업창
void MainBiriScene::planspr(Ref *pSender)
{

}


void MainBiriScene::cancelcon(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("MiniGameResources/button_click_16_sound_effects_.mp3", false);
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
	removeChildByTag(128);
	removeChildByTag(130);
	removeChildByTag(131);
	removeChildByTag(132);
	removeChildByTag(133);
	removeChildByTag(134);
	removeChildByTag(135);
	removeChildByTag(136);
	removeChildByTag(137);
	removeChildByTag(138);
	removeChildByTag(139);
	removeChildByTag(140);
	removeChildByTag(141);
	removeChildByTag(142);
	removeChildByTag(143);
	removeChildByTag(145);
	removeChildByTag(148);
	removeChildByTag(119);
	removeChildByTag(120);
	removeChildByTag(146);
	removeChildByTag(144);
	removeChildByTag(145);
	removeChildByTag(160);
	removeChildByTag(161);
	removeChildByTag(162);
	removeChildByTag(163);
	removeChildByTag(164);
	removeChildByTag(164);
	removeChildByTag(165);
	removeChildByTag(166);
	removeChildByTag(167);
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

void MainBiriScene::finalspr(Ref *pSender)
{
	
	SimpleAudioEngine::getInstance()->playEffect("MiniGameResources/button_click_16_sound_effects_.mp3", false);
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
			CC_CALLBACK_1(MainBiriScene::exitspr, this));
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
			CC_CALLBACK_1(MainBiriScene::cancelcon, this));
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
		removeChildByTag(128);
		removeChildByTag(130);
		removeChildByTag(131);
		removeChildByTag(132);
		removeChildByTag(133);
		removeChildByTag(134);
		removeChildByTag(135);
		removeChildByTag(136);
		removeChildByTag(137);
		removeChildByTag(138);
		removeChildByTag(139);
		removeChildByTag(140);
		removeChildByTag(141);
		removeChildByTag(142);
		removeChildByTag(143);
		removeChildByTag(145);
		removeChildByTag(148);
		removeChildByTag(119);
		removeChildByTag(120);
		removeChildByTag(160);
		removeChildByTag(161);
		removeChildByTag(162);
		removeChildByTag(163);
		removeChildByTag(164);
		removeChildByTag(165);
		removeChildByTag(166);
		removeChildByTag(167);
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
void MainBiriScene::exitspr(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("MiniGameResources/button_click_16_sound_effects_.mp3", false);
	Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif
}

void MainBiriScene::SetLabel(float delta)
{
	Label* label3 = (Label*)this->getChildByTag(7);
	label3->setString(StringUtils::format("%d", Singletons::getInstance()->money));

	Label* label = (Label*)this->getChildByTag(5);
	label->setString(StringUtils::format("%d", Singletons::getInstance()->day));

	Label* label2 = (Label*)this->getChildByTag(6);
	label2->setString(StringUtils::format("%d", Singletons::getInstance()->month));




	 
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
	
	//if (Singletons::getInstance()->day == 1)
	//{
	//	Singletons::getInstance()->newspaper = 1;
	//}

	//if (Singletons::getInstance()->day == 2)
	//{
	//	Singletons::getInstance()->newspaper = 0;
	//}

	//if (Singletons::getInstance()->newspaper == 1)
	//{
	//	auto exitok_item = MenuItemImage::create(
	//		"MiniGameResources/OIcon.png",
	//		"MiniGameResources/OIconpress.png",
	//		CC_CALLBACK_1(MainBiriScene::exitspr, this));
	//	exitok_item->setPosition(Point(0, 0));


	//	auto exitok = Menu::create(exitok_item, NULL);
	//	exitok->setAnchorPoint(Point(0.5, 0.5));
	//	exitok->setPosition(Point(480, 435));
	//	exitok->setTag(52);
	//	this->addChild(exitok, 2);
	//}
}
	void MainBiriScene::InitLabel()
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