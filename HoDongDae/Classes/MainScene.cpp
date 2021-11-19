#include "MainScene.h"
#include "EndScene.h"
#include "SimpleAudioEngine.h"
#include "MiniGameMainScene_1.h"
#include "MapScene.h"
#include "NextDayScene.h"
#include "sinngleton.h"
#include "StoryChangeScene.h"
#include "ContestScene.h"
#include "QuizScene.h"

//#include "KoreanUTF8.h"
//사운드 할라면 꼭 필요
using namespace CocosDenshion;
USING_NS_CC;
//static std::string m_id="";

Scene* MainScene::createScene()
{
    auto scene = Scene::create();
    auto layer = MainScene::create();
	
    scene->addChild(layer);

    return scene;
}

bool MainScene::init()
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
	SimpleAudioEngine::getInstance()->playBackgroundMusic("sound/campus sound.mp3", true);
	//스케쥴
	this->schedule(schedule_selector(MainScene::update));
//	this->schedule(schedule_selector(MainScene::ShowChar));
	this->schedule(schedule_selector(MainScene::SetLabel), 0.001f);
	//터치 리스너 등록
	/*auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = CC_CALLBACK_2(MainScene::onTouchBegan, this);
	Director::getInstance()->getEventDispatcher()->addEventListenerWithFixedPriority(listener, 1);*/

	////키보드 리스너
	//auto keylistener = EventListenerKeyboard::create();
	//keylistener->onKeyPressed = CC_CALLBACK_2(MainScene::onKeyPressed, this);
	//keylistener->onKeyReleased = CC_CALLBACK_2(MainScene::onKeyReleased, this);
	//_eventDispatcher->addEventListenerWithSceneGraphPriority(keylistener, this);
	//Singletons::getInstance()->day;
		//= UserDefault::getInstance()->getIntegerForKey("SaveUsing");
	
    return true;
}

void MainScene::InitBackGround()
{
	auto sprite = Sprite::create("MiniGameResources/Main_Scene.png");
	sprite->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	this->addChild(sprite, 0);
}

//void MainScene::ShowChar(float f)
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
void MainScene::InitMenu()
{
	 //tag160~
	//int soundID_0=CocosDenshion::SimpleAudioEngine::getInstance()->playEffect
	
	//이동창
	auto menu_item = MenuItemImage::create(
		"MiniGameResources/UI_Select1.png",
		"MiniGameResources/UI_Selectpush2.png",
		
		CC_CALLBACK_1(MainScene::menuspr, this));
	menu_item->setAnchorPoint(Point(0.5, 0.5));
	menu_item->setPosition(Point(70,630));

	auto menu = Menu::create(menu_item, NULL);
	menu->setAnchorPoint(Point(0.5, 0.5));
	menu->setPosition(Point(0, 0));
	menu->setTag(200);
	this->addChild(menu, 1);
	//행동창
	auto action_item = MenuItemImage::create(
		"MiniGameResources/UI_Select2.png",
		"MiniGameResources/UI_Selectpush1.png",
		CC_CALLBACK_1(MainScene::actionspr, this));
	action_item->setAnchorPoint(Point(0.5, 0.5));
	action_item->setPosition(Point(70, 565));

	auto action = Menu::create(action_item, NULL);
	action->setAnchorPoint(Point(0.5, 0.5));
	action->setPosition(Point(0, 0));
	action->setTag(201);
	this->addChild(action, 1);
	//내정보창
	auto info_item = MenuItemImage::create(
		"MiniGameResources/UI_Select3.png",
		"MiniGameResources/UI_Selectpush4.png",
		CC_CALLBACK_1(MainScene::infospr, this));
	info_item->setAnchorPoint(Point(0.5, 0.5));
	info_item->setPosition(Point(70, 500));

	auto info = Menu::create(info_item, NULL);
	info->setAnchorPoint(Point(0.5, 0.5));
	info->setPosition(Point(0, 0));
	info->setTag(202);
	this->addChild(info, 1);
	//일정창
	auto plan_item = MenuItemImage::create(
		"MiniGameResources/UI_Select6.png",
		"MiniGameResources/UI_Selectpush5.png",
		CC_CALLBACK_1(MainScene::planspr, this));
	plan_item->setAnchorPoint(Point(0.5, 0.5));
	plan_item->setPosition(Point(70, 435));

	auto plan = Menu::create(plan_item, NULL);
	plan->setAnchorPoint(Point(0.5, 0.5));
	plan->setPosition(Point(0, 0));
	plan->setTag(203);
	this->addChild(plan, 1);
	//시스템창
	auto system_item = MenuItemImage::create(
		"MiniGameResources/UI_Select5.png",
		"MiniGameResources/UI_Selectpush6.png",
		CC_CALLBACK_1(MainScene::systemspr, this));
	system_item->setAnchorPoint(Point(0.5, 0.5));
	system_item->setPosition(Point(70, 370));

	auto system = Menu::create(system_item, NULL);
	system->setAnchorPoint(Point(0.5, 0.5));
	system->setPosition(Point(0, 0));
	system->setTag(204);
	this->addChild(system, 1);
	//종료창
	auto fin_item = MenuItemImage::create(
		"MiniGameResources/UI_Select7.png",
		"MiniGameResources/UI_Selectpush7.png",
		CC_CALLBACK_1(MainScene::finalspr, this));
	fin_item->setAnchorPoint(Point(0.5, 0.5));
	fin_item->setPosition(Point(70, 305));

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

	//우측상단 판업창
	
	Sprite* mainchr_1 = Sprite::create("MiniGameResources/guesyang.png");
	mainchr_1->setAnchorPoint(Point(0.5, 0));
	mainchr_1->setPosition(Point(845, 604));
	mainchr_1->setTag(206);
	this->addChild(mainchr_1, 1);

//auto text_item = MenuItemImage::create(
//	"MiniGameResources/ok_button.png",
//	"MiniGameResources/ok_buttonpr.png",
//	CC_CALLBACK_1(MainScene::nextday, this));
//text_item->setAnchorPoint(Point(0.5, 0.5));
//text_item->setPosition(Point(950, 65));
//
//auto text = Menu::create(text_item, NULL);
//text->setAnchorPoint(Point(0.5, 0.5));
//text->setPosition(Point(0, 0));
//text->setTag(1011);
//this->addChild(text, 5);
//Singletons::getInstance()->money = Singletons::getInstance()->money + 1;

}
//내정보 판업창
void MainScene::infospr(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("MiniGameResources/button_click_16_sound_effects_.mp3", false);
	if (open == false) {
		open = true;
		//tag 18~22
		//창 지우기
		auto cancel_item = MenuItemImage::create(
			"MiniGameResources/XIcon.png",
			"MiniGameResources/XIconpress.png",
			CC_CALLBACK_1(MainScene::cancelcon, this));
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
				this->addChild(spr2,6);
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
				this->addChild(spr2,6);
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
				this->addChild(spr2,6);
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
				this->addChild(spr2,6);
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
				this->addChild(spr2,6);
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
				this->addChild(spr2,6);
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
				this->addChild(spr2,6);
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
				this->addChild(spr2,6);
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
				this->addChild(spr2,6);
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
				this->addChild(spr2,6);
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
		removeChildByTag(231);
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
void MainScene::systemspr(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("MiniGameResources/button_click_16_sound_effects_.mp3", false);
	if (open == false)
	{
		open = true;
		//저장하기
		
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
			CC_CALLBACK_1(MainScene::cancelcon, this));
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
			CC_CALLBACK_1(MainScene::soundoff, this));
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
		removeChildByTag(231);
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
//시스템-저장하기


//불러오기
//Singletons::getInstance()->day = UserDefault::setInstance()->setIntegerForKey("SaveUsing");

void MainScene::soundoff(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("MiniGameResources/button_click_16_sound_effects_.mp3", false);
	SimpleAudioEngine::getInstance()->stopBackgroundMusic();		
	removeChildByTag(110);
	//노래 오프
	auto off_item = MenuItemImage::create(
		"MiniGameResources/off_swich.png",
		"MiniGameResources/off_swich.png",
		CC_CALLBACK_1(MainScene::soundon, this));
	off_item->setAnchorPoint(Point(0.5, 0.5));
	off_item->setPosition(Point(610,430));

	auto off = Menu::create(off_item, NULL);
	off->setAnchorPoint(Point(0.5, 0.5));
	off->setPosition(Point(0, 0));
	off->setTag(111);
	this->addChild(off, 3);
}
void MainScene::soundon(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("MiniGameResources/button_click_16_sound_effects_.mp3", false);
	//노래 다시 온
	SimpleAudioEngine::getInstance()->playBackgroundMusic("sound/campus sound..mp3", true);
	removeChildByTag(111);
	auto on_item = MenuItemImage::create(
		"MiniGameResources/on_swich.png",
		"MiniGameResources/on_swich.png",
		CC_CALLBACK_1(MainScene::soundoff, this));
	on_item->setAnchorPoint(Point(0.5, 0.5));
	on_item->setPosition(Point(610, 430));

	auto on = Menu::create(on_item, NULL);
	on->setAnchorPoint(Point(0.5, 0.5));
	on->setPosition(Point(0, 0));
	on->setTag(110);
	this->addChild(on, 3);
}
//행동 클릭시 메뉴창
void MainScene::actionspr(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("MiniGameResources/button_click_16_sound_effects_.mp3", false);
	if (open == false) {

		open = true;
		//tag 8~11
		//대화하기
		auto action_item = MenuItemImage::create(
			"MiniGameResources/UI_move1.png",
			"MiniGameResources/UI_move1pr.png",
			// 임시 
			CC_CALLBACK_1(MainScene::tell, this));
		action_item->setPosition(Point(0, 0));

		auto Study = Menu::create(action_item, NULL);
		Study->setAnchorPoint(Point(0.5, 0.5));
		Study->setPosition(Point(200, 565));
		Study->setTag(8);
		this->addChild(Study, 1);
		//공모전
		auto action_item1 = MenuItemImage::create(
			"MiniGameResources/UI_move12.png",
			"MiniGameResources/UI_move12pr.png",
			// 임시 
			CC_CALLBACK_1(MainScene::servicespr, this));
		action_item1->setPosition(Point(0, 0));

		auto service = Menu::create(action_item1, NULL);
		service->setAnchorPoint(Point(0.5, 0.5));
		service->setPosition(Point(200, 505));
		service->setTag(9);
		this->addChild(service, 1);
		//공부하기
		auto action_item2 = MenuItemImage::create(
			"MiniGameResources/UI_move4.png",
			"MiniGameResources/UI_move4pr.png",
			// 임시 
			CC_CALLBACK_1(MainScene::quiz, this));
		action_item2->setPosition(Point(0, 0));

		auto say = Menu::create(action_item2, NULL);
		say->setAnchorPoint(Point(0.5, 0.5));
		say->setPosition(Point(200, 445));
		say->setTag(10);
		this->addChild(say, 1);
		//첵읽기
		auto action_item3 = MenuItemImage::create(
			"MiniGameResources/UI_move6.png",
			"MiniGameResources/UI_move6pr.png",
			// 임시 
			CC_CALLBACK_1(MainScene::read, this));
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
		removeChildByTag(231);
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
//공부하기
void MainScene::quiz(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("MiniGameResources/button_click_16_sound_effects_.mp3", false);
	Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
	Director::getInstance()->replaceScene(QuizScene::createScene());
}

//이동 클릭시 메뉴창
void MainScene::menuspr(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("MiniGameResources/button_click_16_sound_effects_.mp3", false);
	Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
	Director::getInstance()->replaceScene(MapScene::createScene());
	
}
//공모전
void MainScene::servicespr(Ref *pSender)
{
	if (open == false) {

		open = true;
		SimpleAudioEngine::getInstance()->playEffect("MiniGameResources/button_click_16_sound_effects_.mp3", false);

		removeChildByTag(119);
		removeChildByTag(120);
		removeChildByTag(200);
		removeChildByTag(201);
		removeChildByTag(202);
		removeChildByTag(203);
		removeChildByTag(204);
		removeChildByTag(205);
		removeChildByTag(8);
		removeChildByTag(9);
		removeChildByTag(10);
		removeChildByTag(11);

		//창 지우기
		auto cancel_item = MenuItemImage::create(
			"MiniGameResources/XIcon.png",
			"MiniGameResources/XIconpress.png",
			CC_CALLBACK_1(MainScene::cancelcon, this));
		cancel_item->setAnchorPoint(Point(0.5, 0.5));
		cancel_item->setPosition(Point(710, 710));

		auto cancel = Menu::create(cancel_item, NULL);
		cancel->setAnchorPoint(Point(0.5, 0.5));
		cancel->setPosition(Point(0, 0));
		cancel->setTag(164);
		this->addChild(cancel, 4);

		Sprite* info = Sprite::create("MiniGameResources/UI_gongmo.png");
		info->setAnchorPoint(Point(0.5, 0));
		info->setPosition(Point(512, 110));
		info->setTag(160);
		this->addChild(info, 2);

		auto action_item1 = MenuItemImage::create(
			"MiniGameResources/gongmolv1.png",
			"MiniGameResources/gongmolv1pr.png",
			// 임시 
			CC_CALLBACK_1(MainScene::gonmoA, this));
		action_item1->setPosition(Point(0, 0));

		auto play = Menu::create(action_item1, NULL);
		play->setAnchorPoint(Point(0.5, 0.5));
		play->setPosition(Point(512, 625));
		play->setTag(161);
		this->addChild(play, 3);

		auto action_item2 = MenuItemImage::create(
			"MiniGameResources/gongmolv2.png",
			"MiniGameResources/gongmolv2pr.png",
			// 임시 
			CC_CALLBACK_1(MainScene::gonmoB, this));
		action_item2->setPosition(Point(0, 0));

		auto playB = Menu::create(action_item2, NULL);
		playB->setAnchorPoint(Point(0.5, 0.5));
		playB->setPosition(Point(512, 425));
		playB->setTag(162);
		this->addChild(playB, 3);

		auto action_item3 = MenuItemImage::create(
			"MiniGameResources/gongmolv3.png",
			"MiniGameResources/gongmolv3pr.png",
			// 임시 
			CC_CALLBACK_1(MainScene::gonmoC, this));
		action_item3->setPosition(Point(0, 0));

		auto playC = Menu::create(action_item3, NULL);
		playC->setAnchorPoint(Point(0.5, 0.5));
		playC->setPosition(Point(512, 225));
		playC->setTag(163);
		this->addChild(playC, 3);
	}
	else if (open == true)
	
	{
		removeChildByTag(164);
		removeChildByTag(160);
		removeChildByTag(161);
		removeChildByTag(162);
		removeChildByTag(163);

		open = false;
	}
}
//공모전 레베르1
void MainScene::gonmoA(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("MiniGameResources/button_click_16_sound_effects_.mp3", false);
	removeChildByTag(164);
	removeChildByTag(160);
	removeChildByTag(161);		
	removeChildByTag(162);
	removeChildByTag(163);




	char MyString[50];
	WideCharToMultiByte(CP_UTF8, 0, L"참여하시겠습니까?", -1, MyString, 50, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "fonts/ABC.ttf", 25);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(420, 525));
	name->setColor(Color3B::BLACK);
	name->setTag(168);
	this->addChild(name, 5);

	Sprite* info = Sprite::create("MiniGameResources/UI_gongentro.png");
	info->setAnchorPoint(Point(0.5, 0));
	info->setPosition(Point(512, 410));
	info->setTag(165);
	this->addChild(info, 4);

	auto action_item = MenuItemImage::create(
		"MiniGameResources/UI_enter.png",
		"MiniGameResources/UI_enterpr.png",
		// 임시 
		CC_CALLBACK_1(MainScene::gonmoAjoin, this));
	action_item->setPosition(Point(0, 0));

	auto play = Menu::create(action_item, NULL);
	play->setAnchorPoint(Point(0.5, 0.5));
	play->setPosition(Point(452, 455));
	play->setTag(166);
	this->addChild(play, 5);

	auto action_item3 = MenuItemImage::create(
		"MiniGameResources/UI_no.png",
		"MiniGameResources/UI_nopr.png",
		// 임시 
		CC_CALLBACK_1(MainScene::cancelcon, this));
	action_item3->setPosition(Point(0, 0));

	auto playC = Menu::create(action_item3, NULL);
	playC->setAnchorPoint(Point(0.5, 0.5));
	playC->setPosition(Point(572, 455));
	playC->setTag(167);
	this->addChild(playC, 5);

}
//공모전1 쪼인
void MainScene::gonmoAjoin(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("MiniGameResources/button_click_16_sound_effects_.mp3", false);
	Singletons::getInstance()->gonmonum = 1;

	if (Singletons::getInstance()->money < 50000)
	{
		removeChildByTag(165);
		removeChildByTag(166);
		removeChildByTag(167);
		removeChildByTag(168);
	
		Sprite* info = Sprite::create("MiniGameResources/pop_nomoney.png");
		info->setAnchorPoint(Point(0.5, 0));
		info->setPosition(Point(520, 410));
		info->setTag(164);
		this->addChild(info, 5);

		auto cancel = MenuItemImage::create(
			"MiniGameResources/pop_enter.png",
			"MiniGameResources/pop_enterpr.png",
			CC_CALLBACK_1(MainScene::cancelcon, this));
		cancel->setAnchorPoint(Point(0.5, 0.5));
		cancel->setPosition(Point(520, 450));

		auto canceltext = Menu::create(cancel, NULL);
		canceltext->setAnchorPoint(Point(0.5, 0.5));
		canceltext->setPosition(Point(0, 0));
		canceltext->setTag(165);
		this->addChild(canceltext, 7);
	}
	if (Singletons::getInstance()->money >= 50000)
	{
		Singletons::getInstance()->money = Singletons::getInstance()->money - 50000;
		Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
		Director::getInstance()->replaceScene(ContestScene::createScene());
	}
}
//공모전 레베루2
void MainScene::gonmoB(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("MiniGameResources/button_click_16_sound_effects_.mp3", false);
	removeChildByTag(164);
	removeChildByTag(160);
	removeChildByTag(161);
	removeChildByTag(162);
	removeChildByTag(163);

	char MyString[50];
	WideCharToMultiByte(CP_UTF8, 0, L"참여하시겠습니까?", -1, MyString, 50, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "fonts/ABC.ttf", 25);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(420, 525));
	name->setColor(Color3B::BLACK);
	name->setTag(168);
	this->addChild(name, 5);

	Sprite* info = Sprite::create("MiniGameResources/UI_gongentro.png");
	info->setAnchorPoint(Point(0.5, 0));
	info->setPosition(Point(512, 410));
	info->setTag(165);
	this->addChild(info, 4);

	auto action_item = MenuItemImage::create(
		"MiniGameResources/UI_enter.png",
		"MiniGameResources/UI_enterpr.png",
		// 임시 
		CC_CALLBACK_1(MainScene::gonmoBjoin, this));
	action_item->setPosition(Point(0, 0));

	auto play = Menu::create(action_item, NULL);
	play->setAnchorPoint(Point(0.5, 0.5));
	play->setPosition(Point(452, 455));
	play->setTag(166);
	this->addChild(play, 5);

	auto action_item3 = MenuItemImage::create(
		"MiniGameResources/UI_no.png",
		"MiniGameResources/UI_nopr.png",
		// 임시 
		CC_CALLBACK_1(MainScene::cancelcon, this));
	action_item3->setPosition(Point(0, 0));

	auto playC = Menu::create(action_item3, NULL);
	playC->setAnchorPoint(Point(0.5, 0.5));
	playC->setPosition(Point(572, 455));
	playC->setTag(167);
	this->addChild(playC, 5);
}
//공모전2 쪼인
void MainScene::gonmoBjoin(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("MiniGameResources/button_click_16_sound_effects_.mp3", false);
	Singletons::getInstance()->gonmonum = 2;

	if (Singletons::getInstance()->money < 100000)
	{
		removeChildByTag(165);
		removeChildByTag(166);
		removeChildByTag(167);
		removeChildByTag(168);

		Sprite* info = Sprite::create("MiniGameResources/pop_nomoney.png");
		info->setAnchorPoint(Point(0.5, 0));
		info->setPosition(Point(520, 410));
		info->setTag(164);
		this->addChild(info, 5);

		auto cancel = MenuItemImage::create(
			"MiniGameResources/pop_enter.png",
			"MiniGameResources/pop_enterpr.png",
			CC_CALLBACK_1(MainScene::cancelcon, this));
		cancel->setAnchorPoint(Point(0.5, 0.5));
		cancel->setPosition(Point(520, 450));

		auto canceltext = Menu::create(cancel, NULL);
		canceltext->setAnchorPoint(Point(0.5, 0.5));
		canceltext->setPosition(Point(0, 0));
		canceltext->setTag(165);
		this->addChild(canceltext, 7);
	}
	if (Singletons::getInstance()->money >= 100000)
	{
		Singletons::getInstance()->money = Singletons::getInstance()->money - 100000;
		Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
		Director::getInstance()->replaceScene(ContestScene::createScene());
	}
}

//공모전 레베루3
void MainScene::gonmoC(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("MiniGameResources/button_click_16_sound_effects_.mp3", false);
	removeChildByTag(164);
	removeChildByTag(160);
	removeChildByTag(161);
	removeChildByTag(162);
	removeChildByTag(163);

	char MyString[50];
	WideCharToMultiByte(CP_UTF8, 0, L"참여하시겠습니까?", -1, MyString, 50, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "fonts/ABC.ttf", 25);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(420, 525));
	name->setColor(Color3B::BLACK);
	name->setTag(168);
	this->addChild(name, 5);

	Sprite* info = Sprite::create("MiniGameResources/UI_gongentro.png");
	info->setAnchorPoint(Point(0.5, 0));
	info->setPosition(Point(512, 410));
	info->setTag(165);
	this->addChild(info, 4);

	auto action_item = MenuItemImage::create(
		"MiniGameResources/UI_enter.png",
		"MiniGameResources/UI_enterpr.png",
		// 임시 
		CC_CALLBACK_1(MainScene::gonmoCjoin, this));
	action_item->setPosition(Point(0, 0));

	auto play = Menu::create(action_item, NULL);
	play->setAnchorPoint(Point(0.5, 0.5));
	play->setPosition(Point(452, 455));
	play->setTag(166);
	this->addChild(play, 5);

	auto action_item3 = MenuItemImage::create(
		"MiniGameResources/UI_no.png",
		"MiniGameResources/UI_nopr.png",
		// 임시 
		CC_CALLBACK_1(MainScene::cancelcon, this));
	action_item3->setPosition(Point(0, 0));

	auto playC = Menu::create(action_item3, NULL);
	playC->setAnchorPoint(Point(0.5, 0.5));
	playC->setPosition(Point(572, 455));
	playC->setTag(167);
	this->addChild(playC, 5);
}
//공모전3 쪼인
void MainScene::gonmoCjoin(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("MiniGameResources/button_click_16_sound_effects_.mp3", false);
	Singletons::getInstance()->gonmonum = 3;

	if (Singletons::getInstance()->money < 300000)
	{
		removeChildByTag(165);
		removeChildByTag(166);
		removeChildByTag(167);
		removeChildByTag(168);

		Sprite* info = Sprite::create("MiniGameResources/pop_nomoney.png");
		info->setAnchorPoint(Point(0.5, 0));
		info->setPosition(Point(520, 410));
		info->setTag(164);
		this->addChild(info, 5);

		auto cancel = MenuItemImage::create(
			"MiniGameResources/pop_enter.png",
			"MiniGameResources/pop_enterpr.png",
			CC_CALLBACK_1(MainScene::cancelcon, this));
		cancel->setAnchorPoint(Point(0.5, 0.5));
		cancel->setPosition(Point(520, 450));

		auto canceltext = Menu::create(cancel, NULL);
		canceltext->setAnchorPoint(Point(0.5, 0.5));
		canceltext->setPosition(Point(0, 0));
		canceltext->setTag(165);
		this->addChild(canceltext, 7);
	}
	if (Singletons::getInstance()->money >= 300000)
	{
		Singletons::getInstance()->money = Singletons::getInstance()->money - 300000;
		Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
		Director::getInstance()->replaceScene(ContestScene::createScene());
	}
}

//행동-대화하기
void MainScene::tell(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("MiniGameResources/button_click_16_sound_effects_.mp3", false);
	Singletons::getInstance()->num_5 = 1;
	Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
	Director::getInstance()->replaceScene(StoryChangeScene::createScene());
}

//행동-읽기
void MainScene::read(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("MiniGameResources/button_click_16_sound_effects_.mp3", false);
	

	if (open == false) {

		open = true;

		removeChildByTag(119);
		removeChildByTag(120);
		removeChildByTag(200);
		removeChildByTag(201);
		removeChildByTag(202);
		removeChildByTag(203);
		removeChildByTag(204);
		removeChildByTag(205);
		removeChildByTag(8);
		removeChildByTag(9);
		removeChildByTag(10);
		removeChildByTag(11);

		//SimpleAudioEngine::getInstance()->playEffect("MiniGameResources/button_click_16_sound_effects_.mp3", false);

	//auto click = Sprite::create("MiniGameResources/noorugi.png");
	//click->setAnchorPoint(Point(0.5, 0.5));
	//click->setPosition(Point(630, 265));
	//click->setTag(230);
	//this->addChild(click, 3);
	//auto animation = Animation::create();
	//animation->setDelayPerUnit(0.3);
	//animation->addSpriteFrameWithFile("MiniGameResources/noorugi.png");
	//animation->addSpriteFrameWithFile("MiniGameResources/ddegi.png");

	//auto animate = Animate::create(animation);
	//
	//auto rep = RepeatForever::create(animate);
	//click->runAction(rep);

		auto action_item3 = MenuItemImage::create(
			"MiniGameResources/today_book.png",
			"MiniGameResources/today_book.png",
			// 임시 
			CC_CALLBACK_1(MainScene::bookopen, this));
		action_item3->setPosition(Point(0, 0));

		auto play = Menu::create(action_item3, NULL);
		play->setAnchorPoint(Point(0.5, 0));
		play->setPosition(Point(520, 400));
		play->setTag(231);
		this->addChild(play, 2);

		//창 지우기
		auto cancel_item = MenuItemImage::create(
			"MiniGameResources/XIcon.png",
			"MiniGameResources/XIconpress.png",
			CC_CALLBACK_1(MainScene::cancelcon, this));
		cancel_item->setAnchorPoint(Point(0.5, 0.5));
		cancel_item->setPosition(Point(630, 550));

		auto cancel = Menu::create(cancel_item, NULL);
		cancel->setAnchorPoint(Point(0.5, 0.5));
		cancel->setPosition(Point(0, 0));
		cancel->setTag(164);
		this->addChild(cancel, 4);

	}
	else if (open == true)
	{
		removeChildByTag(230);

		removeChildByTag(231);

		open = false;
	}
}

//행동-릭기-책오픈
void MainScene::bookopen(Ref *pSender)
{

	SimpleAudioEngine::getInstance()->playEffect("sound/Page turn sound effect.mp3", false);
	removeChildByTag(119);
	removeChildByTag(120);
	removeChildByTag(164);
	removeChildByTag(200);
	removeChildByTag(201);
	removeChildByTag(202);
	removeChildByTag(203);
	removeChildByTag(204);
	removeChildByTag(205);
	removeChildByTag(8);
	removeChildByTag(9);
	removeChildByTag(10);
	removeChildByTag(11);
	int i, num;

	srand((double)time(NULL));
	for (i = 0; i < 1; i++)
	{
		num = rand() % 18 + 1;
	}
	
	if (num == 1)
	{
		//tag129.131~148
		//명언1
		auto text_item = MenuItemImage::create(
			"MiniGameResources/ok_button.png",
			"MiniGameResources/ok_buttonpr.png",
			CC_CALLBACK_1(MainScene::bookcloseA, this));
		text_item->setAnchorPoint(Point(0.5, 0.5));
		text_item->setPosition(Point(770, 265));

		auto text = Menu::create(text_item, NULL);
		text->setAnchorPoint(Point(0.5, 0.5));
		text->setPosition(Point(0, 0));
		text->setTag(130);
		this->addChild(text, 5);

		char MyString[200];
		WideCharToMultiByte(CP_UTF8, 0, L"모든사람이 일생을 바친 뒤에 남는 것은 \n       모은 것이 아니라 뿌린 것이다.\n\n             - 제라르 핸드리 - ", -1, MyString, 200, NULL, NULL);
		auto name = Label::createWithTTF(MyString, "fonts/ABC.ttf", 25);
		name->setAnchorPoint(Point(0, 1));
		name->setPosition(Point(340, 480));
		name->setColor(Color3B::BLACK);
		name->setTag(128);
		this->addChild(name, 4);
	}
	if (num == 2)
	{
		//명언1
		auto text_item = MenuItemImage::create(
			"MiniGameResources/ok_button.png",
			"MiniGameResources/ok_buttonpr.png",
			CC_CALLBACK_1(MainScene::bookcloseA, this));
		text_item->setAnchorPoint(Point(0.5, 0.5));
		text_item->setPosition(Point(770, 265));

		auto text = Menu::create(text_item, NULL);
		text->setAnchorPoint(Point(0.5, 0.5));
		text->setPosition(Point(0, 0));
		text->setTag(130);
		this->addChild(text, 5);

		char MyString[200];
		WideCharToMultiByte(CP_UTF8, 0, L"         상황은 바뀌지 않는다.\n   다만 우리가 변하는 것 뿐이다.\n \n       - 헨리 데이비드 소로우 - ", -1, MyString, 200, NULL, NULL);
		auto name = Label::createWithTTF(MyString, "fonts/ABC.ttf", 25);
		name->setAnchorPoint(Point(0, 1));
		name->setPosition(Point(350, 480));
		name->setColor(Color3B::BLACK);
		name->setTag(131);
		this->addChild(name, 4);
	}
	if (num == 3)
	{
		//명언1
		auto text_item = MenuItemImage::create(
			"MiniGameResources/ok_button.png",
			"MiniGameResources/ok_buttonpr.png",
			CC_CALLBACK_1(MainScene::bookcloseA, this));
		text_item->setAnchorPoint(Point(0.5, 0.5));
		text_item->setPosition(Point(770, 265));

		auto text = Menu::create(text_item, NULL);
		text->setAnchorPoint(Point(0.5, 0.5));
		text->setPosition(Point(0, 0));
		text->setTag(130);
		this->addChild(text, 5);

		char MyString[200];
		WideCharToMultiByte(CP_UTF8, 0, L" 당신이 있는 곳에서 가진것을 가지고\n      당신이 할 수 있는 것을 해라.\n\n             - 테니 루즈벨트 - ", -1, MyString, 200, NULL, NULL);
		auto name = Label::createWithTTF(MyString, "fonts/ABC.ttf", 25);
		name->setAnchorPoint(Point(0, 1));
		name->setPosition(Point(340, 480));
		name->setColor(Color3B::BLACK);
		name->setTag(132);
		this->addChild(name, 4);
	}
	if (num == 4)
	{
		//명언1
		auto text_item = MenuItemImage::create(
			"MiniGameResources/ok_button.png",
			"MiniGameResources/ok_buttonpr.png",
			CC_CALLBACK_1(MainScene::bookcloseA, this));
		text_item->setAnchorPoint(Point(0.5, 0.5));
		text_item->setPosition(Point(770, 265));

		auto text = Menu::create(text_item, NULL);
		text->setAnchorPoint(Point(0.5, 0.5));
		text->setPosition(Point(0, 0));
		text->setTag(130);
		this->addChild(text, 5);

		char MyString[200];
		WideCharToMultiByte(CP_UTF8, 0, L"       인생은 우리가 만드는 것이다. \n  항상 그래왔고 앞으로도 그럴 것이다.\n\n               - 그랜마 모제스 - ", -1, MyString, 200, NULL, NULL);
		auto name = Label::createWithTTF(MyString, "fonts/ABC.ttf", 25);
		name->setAnchorPoint(Point(0, 1));
		name->setPosition(Point(330, 480));
		name->setColor(Color3B::BLACK);
		name->setTag(133);
		this->addChild(name, 4);
	}
	if (num == 5)
	{
		//명언1
		auto text_item = MenuItemImage::create(
		"MiniGameResources/ok_button.png",
			"MiniGameResources/ok_buttonpr.png",
			CC_CALLBACK_1(MainScene::bookcloseA, this));
			text_item->setAnchorPoint(Point(0.5, 0.5));
			text_item->setPosition(Point(770, 265));

			auto text = Menu::create(text_item, NULL);
			text->setAnchorPoint(Point(0.5, 0.5));
			text->setPosition(Point(0, 0));
			text->setTag(130);
			this->addChild(text, 5);

		char MyString[200];
		WideCharToMultiByte(CP_UTF8, 0, L" 좋아하지 않는 사람에 대한 생각으로\n         시간을 낭비하지 마라.\n\n              - 데일 카네기 - ", -1, MyString, 200, NULL, NULL);
		auto name = Label::createWithTTF(MyString, "fonts/ABC.ttf", 25);
		name->setAnchorPoint(Point(0, 1));
		name->setPosition(Point(340, 480));
		name->setColor(Color3B::BLACK);
		name->setTag(134);
		this->addChild(name, 4);
	}
	if (num == 6)
	{
		//명언1
		auto text_item = MenuItemImage::create(
			"MiniGameResources/ok_button.png",
			"MiniGameResources/ok_buttonpr.png",
			CC_CALLBACK_1(MainScene::bookcloseA, this));
		text_item->setAnchorPoint(Point(0.5, 0.5));
		text_item->setPosition(Point(770, 265));

		auto text = Menu::create(text_item, NULL);
		text->setAnchorPoint(Point(0.5, 0.5));
		text->setPosition(Point(0, 0));
		text->setTag(130);
		this->addChild(text, 5);

		char MyString[300];
		WideCharToMultiByte(CP_UTF8, 0, L"       친구에는 세 부류가 있다.     \n음식과같아서 매일 필요한 친구.\n     약과같아서 가끔 필요한 친구.\n질병과 같아서 항상 피해야하는 친구.\n\n                - 탈무드 - ", -1, MyString, 300, NULL, NULL);
		auto name = Label::createWithTTF(MyString, "fonts/ABC.ttf", 25);
		name->setAnchorPoint(Point(0, 1));
		name->setPosition(Point(350, 490));
		name->setColor(Color3B::BLACK);
		name->setTag(135);
		this->addChild(name, 4);
	}
	if (num == 7)
	{
		//명언1
		auto text_item = MenuItemImage::create(
			"MiniGameResources/ok_button.png",
			"MiniGameResources/ok_buttonpr.png",
			CC_CALLBACK_1(MainScene::bookcloseA, this));
		text_item->setAnchorPoint(Point(0.5, 0.5));
		text_item->setPosition(Point(770, 265));

		auto text = Menu::create(text_item, NULL);
		text->setAnchorPoint(Point(0.5, 0.5));
		text->setPosition(Point(0, 0));
		text->setTag(130);
		this->addChild(text, 5);

		char MyString[200]; 
		WideCharToMultiByte(CP_UTF8, 0, L"'할수있다.잘 될 것이다.'라고 결심하라.\n       그리고 나서 방법을 찾아라.\n\n            - 에이브러햄 링컨 - ", -1, MyString, 200, NULL, NULL);
		auto name = Label::createWithTTF(MyString, "fonts/ABC.ttf", 25);
		name->setAnchorPoint(Point(0, 1));
		name->setPosition(Point(340, 480));
		name->setColor(Color3B::BLACK);
		name->setTag(136);
		this->addChild(name, 4);
	}
	if (num == 8)
	{
		//명언1
		auto text_item = MenuItemImage::create(
			"MiniGameResources/ok_button.png",
			"MiniGameResources/ok_buttonpr.png",
			CC_CALLBACK_1(MainScene::bookcloseA, this));
		text_item->setAnchorPoint(Point(0.5, 0.5));
		text_item->setPosition(Point(770, 265));

		auto text = Menu::create(text_item, NULL);
		text->setAnchorPoint(Point(0.5, 0.5));
		text->setPosition(Point(0, 0));
		text->setTag(130);
		this->addChild(text, 5);

		char MyString[200];
		WideCharToMultiByte(CP_UTF8, 0, L"어떤 것이 당신의 계획대로 되지 않는다고 해서\n           그것이 불필요한 것은 아니다.\n\n                  - 토마스 A.에디슨 - ", -1, MyString, 200, NULL, NULL);
		auto name = Label::createWithTTF(MyString, "fonts/ABC.ttf", 25);
		name->setAnchorPoint(Point(0, 1));
		name->setPosition(Point(300, 480));
		name->setColor(Color3B::BLACK);
		name->setTag(137);
		this->addChild(name, 4);
	}
	if (num == 9)
	{
		//명언1
		auto text_item = MenuItemImage::create(
			"MiniGameResources/ok_button.png",
			"MiniGameResources/ok_buttonpr.png",
			CC_CALLBACK_1(MainScene::bookcloseA, this));
		text_item->setAnchorPoint(Point(0.5, 0.5));
		text_item->setPosition(Point(770, 265));

		auto text = Menu::create(text_item, NULL);
		text->setAnchorPoint(Point(0.5, 0.5));
		text->setPosition(Point(0, 0));
		text->setTag(130);
		this->addChild(text, 5);

		char MyString[200];
		WideCharToMultiByte(CP_UTF8, 0, L" 오랫동안 꿈을 그리는 사람은\n     마침내 그 꿈을 닮아간다.\n\n         - 앙드레 말로 - ", -1, MyString, 200, NULL, NULL);
		auto name = Label::createWithTTF(MyString, "fonts/ABC.ttf", 25);
		name->setAnchorPoint(Point(0, 1));
		name->setPosition(Point(375, 480));
		name->setColor(Color3B::BLACK);
		name->setTag(138);
		this->addChild(name, 4);
	}
	if (num == 10)
	{
		//명언1
		auto text_item = MenuItemImage::create(
			"MiniGameResources/ok_button.png",
			"MiniGameResources/ok_buttonpr.png",
			CC_CALLBACK_1(MainScene::bookcloseA, this));
		text_item->setAnchorPoint(Point(0.5, 0.5));
		text_item->setPosition(Point(770, 265));

		auto text = Menu::create(text_item, NULL);
		text->setAnchorPoint(Point(0.5, 0.5));
		text->setPosition(Point(0, 0));
		text->setTag(130);
		this->addChild(text, 5);

		char MyString[200];
		WideCharToMultiByte(CP_UTF8, 0, L"               밤이 어두울 때에\n               더 많은 별을 본다.\n\n            - 토마스 A.에디슨 - ", -1, MyString, 200, NULL, NULL);
		auto name = Label::createWithTTF(MyString, "fonts/ABC.ttf", 25);
		name->setAnchorPoint(Point(0, 1));
		name->setPosition(Point(340, 480));
		name->setColor(Color3B::BLACK);
		name->setTag(139);
		this->addChild(name, 4);
	}
	if (num == 11)
	{
		//명언1
		auto text_item = MenuItemImage::create(
			"MiniGameResources/ok_button.png",
			"MiniGameResources/ok_buttonpr.png",
			CC_CALLBACK_1(MainScene::bookcloseA, this));
		text_item->setAnchorPoint(Point(0.5, 0.5));
		text_item->setPosition(Point(770, 265));

		auto text = Menu::create(text_item, NULL);
		text->setAnchorPoint(Point(0.5, 0.5));
		text->setPosition(Point(0, 0));
		text->setTag(130);
		this->addChild(text, 5);

		char MyString[200];
		WideCharToMultiByte(CP_UTF8, 0, L"자신감은 위대한 과업의 첫째 요건이다.\n\n                - 사무엘 존슨 - ", -1, MyString, 200, NULL, NULL);
		auto name = Label::createWithTTF(MyString, "fonts/ABC.ttf", 25);
		name->setAnchorPoint(Point(0, 1));
		name->setPosition(Point(330, 480));
		name->setColor(Color3B::BLACK);
		name->setTag(140);
		this->addChild(name, 4);
	}
	if (num == 12)
	{
		//명언1
		auto text_item = MenuItemImage::create(
			"MiniGameResources/ok_button.png",
			"MiniGameResources/ok_buttonpr.png",
			CC_CALLBACK_1(MainScene::bookcloseA, this));
		text_item->setAnchorPoint(Point(0.5, 0.5));
		text_item->setPosition(Point(770, 265));

		auto text = Menu::create(text_item, NULL);
		text->setAnchorPoint(Point(0.5, 0.5));
		text->setPosition(Point(0, 0));
		text->setTag(130);
		this->addChild(text, 5);

		char MyString[200];
		WideCharToMultiByte(CP_UTF8, 0, L"    행복의 비결은 포기해야 할 것을\n            포기하는 것이다.\n\n            - 앤드류 카네기 - ", -1, MyString, 200, NULL, NULL);
		auto name = Label::createWithTTF(MyString, "fonts/ABC.ttf", 25);
		name->setAnchorPoint(Point(0, 1));
		name->setPosition(Point(345, 480));
		name->setColor(Color3B::BLACK);
		name->setTag(141);
		this->addChild(name, 4);
	}
	if (num == 13)
	{
		//명언1
		auto text_item = MenuItemImage::create(
			"MiniGameResources/ok_button.png",
			"MiniGameResources/ok_buttonpr.png",
			CC_CALLBACK_1(MainScene::bookcloseA, this));
		text_item->setAnchorPoint(Point(0.5, 0.5));
		text_item->setPosition(Point(770, 265));

		auto text = Menu::create(text_item, NULL);
		text->setAnchorPoint(Point(0.5, 0.5));
		text->setPosition(Point(0, 0));
		text->setTag(130);
		this->addChild(text, 5);

		char MyString[200];
		WideCharToMultiByte(CP_UTF8, 0, L"      Boys, be ambitious!\n      소년이여, 야망을 가져라!\n\n          - 윌리암 클라크 - ", -1, MyString, 200, NULL, NULL);
		auto name = Label::createWithTTF(MyString, "fonts/ABC.ttf", 25);
		name->setAnchorPoint(Point(0, 1));
		name->setPosition(Point(365, 480));
		name->setColor(Color3B::BLACK);
		name->setTag(142);
		this->addChild(name, 4);
	}
	if (num == 14)
	{
		//명언1
		auto text_item = MenuItemImage::create(
			"MiniGameResources/ok_button.png",
			"MiniGameResources/ok_buttonpr.png",
			CC_CALLBACK_1(MainScene::bookcloseA, this));
		text_item->setAnchorPoint(Point(0.5, 0.5));
		text_item->setPosition(Point(770, 265));

		auto text = Menu::create(text_item, NULL);
		text->setAnchorPoint(Point(0.5, 0.5));
		text->setPosition(Point(0, 0));
		text->setTag(130);
		this->addChild(text, 5);

		char MyString[200];
		WideCharToMultiByte(CP_UTF8, 0, L"   Time is money\n     시간은 금이다.\n\n - 벤자민 프랭클린 - ", -1, MyString, 200, NULL, NULL);
		auto name = Label::createWithTTF(MyString, "fonts/ABC.ttf", 25);
		name->setAnchorPoint(Point(0, 1));
		name->setPosition(Point(410, 480));
		name->setColor(Color3B::BLACK);
		name->setTag(143);
		this->addChild(name, 4);
	}
	if (num == 15)
	{
		auto text_item = MenuItemImage::create(
			"MiniGameResources/ok_button.png",
			"MiniGameResources/ok_buttonpr.png",
			CC_CALLBACK_1(MainScene::bookcloseB, this));
		text_item->setAnchorPoint(Point(0.5, 0.5));
		text_item->setPosition(Point(770, 265));

		auto text = Menu::create(text_item, NULL);
		text->setAnchorPoint(Point(0.5, 0.5));
		text->setPosition(Point(0, 0));
		text->setTag(130);
		this->addChild(text, 5);

		//명언1
		char MyString[200];
		WideCharToMultiByte(CP_UTF8, 0, L"나만 힘든건 아니지만 니가더 힘든걸 안다고\n          내가 안 힘든 것도 아니다.\n\n                    - 유병재- ", -1, MyString, 200, NULL, NULL);
		auto name = Label::createWithTTF(MyString, "fonts/ABC.ttf", 25);
		name->setAnchorPoint(Point(0, 1));
		name->setPosition(Point(320, 480));
		name->setColor(Color3B::BLACK);
		name->setTag(144);
		this->addChild(name, 4);
	}
		if (num == 16)
		{
			auto text_item = MenuItemImage::create(
				"MiniGameResources/ok_button.png",
				"MiniGameResources/ok_buttonpr.png",
				CC_CALLBACK_1(MainScene::bookcloseB, this));
			text_item->setAnchorPoint(Point(0.5, 0.5));
			text_item->setPosition(Point(770, 265));

			auto text = Menu::create(text_item, NULL);
			text->setAnchorPoint(Point(0.5, 0.5));
			text->setPosition(Point(0, 0));
			text->setTag(130);
			this->addChild(text, 5);

			//명언1
			char MyString[200];
			WideCharToMultiByte(CP_UTF8, 0, L"성공은 1%의 재능과 99%의 빽.\n\n               - 박명수 - ", -1, MyString, 200, NULL, NULL);
			auto name = Label::createWithTTF(MyString, "fonts/ABC.ttf", 25);
			name->setAnchorPoint(Point(0, 1));
			name->setPosition(Point(365, 480));
			name->setColor(Color3B::BLACK);
			name->setTag(145);
			this->addChild(name, 4);
	}
		if (num == 17)
		{
			auto text_item = MenuItemImage::create(
				"MiniGameResources/ok_button.png",
				"MiniGameResources/ok_buttonpr.png",
				CC_CALLBACK_1(MainScene::bookcloseC, this));
			text_item->setAnchorPoint(Point(0.5, 0.5));
			text_item->setPosition(Point(770, 265));

			auto text = Menu::create(text_item, NULL);
			text->setAnchorPoint(Point(0.5, 0.5));
			text->setPosition(Point(0, 0));
			text->setTag(130);
			this->addChild(text, 5);
			//명언1
			char MyString[20];
			WideCharToMultiByte(CP_UTF8, 0, L"...?", -1, MyString, 20, NULL, NULL);
			auto name = Label::createWithTTF(MyString, "fonts/ABC.ttf", 25);
			name->setAnchorPoint(Point(0, 1));
			name->setPosition(Point(505, 450));
			name->setColor(Color3B::BLACK);
			name->setTag(146);
			this->addChild(name, 4);
		}
		if (num == 18)
		{
			auto text_item = MenuItemImage::create(
				"MiniGameResources/ok_button.png",
				"MiniGameResources/ok_buttonpr.png",
				CC_CALLBACK_1(MainScene::bookcloseC, this));
			text_item->setAnchorPoint(Point(0.5, 0.5));
			text_item->setPosition(Point(770, 265));

			auto text = Menu::create(text_item, NULL);
			text->setAnchorPoint(Point(0.5, 0.5));
			text->setPosition(Point(0, 0));
			text->setTag(130);
			this->addChild(text, 5);
			//명언1
			char MyString[20];
			WideCharToMultiByte(CP_UTF8, 0, L"...?", -1, MyString, 20, NULL, NULL);
			auto name = Label::createWithTTF(MyString, "fonts/ABC.ttf", 25);
			name->setAnchorPoint(Point(0, 1));
			name->setPosition(Point(505, 450));
			name->setColor(Color3B::BLACK);
			name->setTag(147);
			this->addChild(name, 4);
		}
		

	auto action_item3 = MenuItemImage::create(
		"MiniGameResources/Today_goodt.png",
		"MiniGameResources/Today_goodt.png",
		// 임시 
		CC_CALLBACK_1(MainScene::trash, this));
	action_item3->setPosition(Point(0, 0));

	auto play = Menu::create(action_item3, NULL);
	play->setAnchorPoint(Point(0.5, 0.5));
	play->setPosition(Point(520, 430));
	play->setTag(148);
	this->addChild(play, 2);
}
//평범한 명언들 책닫기
void MainScene::bookcloseA(Ref *pSender)
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
	removeChildByTag(144);
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
	removeChildByTag(231);
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
	auto action_item3 = MenuItemImage::create(
		"MiniGameResources/today_book.png",
		"MiniGameResources/today_book.png",
		// 임시 
		CC_CALLBACK_1(MainScene::trash, this));
	action_item3->setPosition(Point(0, 0));

	auto play = Menu::create(action_item3, NULL);
	play->setAnchorPoint(Point(0.5, 0));
	play->setPosition(Point(520, 400));
	play->setTag(119);
	this->addChild(play, 1);
	Sprite* info = Sprite::create("MiniGameResources/UI_Textlblack.png");
	info->setAnchorPoint(Point(0.5, 0.5));
	info->setPosition(Point(510, 100));
	info->setTag(145);
	this->addChild(info, 3);

	char MyString[200];
	WideCharToMultiByte(CP_UTF8, 0, L"아주 유익한 내용이었다. 지식이 향상된 느낌이다.\n\n(지식 10이 증가하였습니다.)", -1, MyString, 200, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "fonts/ABC.ttf", 25);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(146);
	this->addChild(name, 4);

	auto text_item = MenuItemImage::create(
		"MiniGameResources/ok_button.png",
		"MiniGameResources/ok_buttonpr.png",
		CC_CALLBACK_1(MainScene::nextday, this));
	text_item->setAnchorPoint(Point(0.5, 0.5));
	text_item->setPosition(Point(950, 65));

	auto text = Menu::create(text_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(130);
	this->addChild(text, 5);
	//지식량 증가
	Singletons::getInstance()->m_jisik=Singletons::getInstance()->m_jisik + 10;
	//요일 증가
	
}
void MainScene::bookcloseB(Ref *pSender)
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
	removeChildByTag(144);
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
	removeChildByTag(231);
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
	auto action_item3 = MenuItemImage::create(
		"MiniGameResources/today_book.png",
		"MiniGameResources/today_book.png",
		// 임시 
		CC_CALLBACK_1(MainScene::trash, this));
	action_item3->setPosition(Point(0, 0));

	auto play = Menu::create(action_item3, NULL);
	play->setAnchorPoint(Point(0.5, 0));
	play->setPosition(Point(520, 400));
	play->setTag(119);
	this->addChild(play, 1);
	Sprite* info = Sprite::create("MiniGameResources/UI_Textlblack.png");
	info->setAnchorPoint(Point(0.5, 0.5));
	info->setPosition(Point(510, 100));
	info->setTag(145);
	this->addChild(info, 3);

	char MyString[200];
	WideCharToMultiByte(CP_UTF8, 0, L"가슴이 끓어오르는 듯한 느낌이야! 정말 훌륭한 책이다.\n\n(지식 15이 증가하였습니다.)", -1, MyString, 200, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "fonts/ABC.ttf", 25);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(146);
	this->addChild(name, 4);

	auto text_item = MenuItemImage::create(
		"MiniGameResources/ok_button.png",
		"MiniGameResources/ok_buttonpr.png",
		CC_CALLBACK_1(MainScene::nextday, this));
	text_item->setAnchorPoint(Point(0.5, 0.5));
	text_item->setPosition(Point(950, 65));

	auto text = Menu::create(text_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(130);
	this->addChild(text, 5);
	//지식량 증가
	Singletons::getInstance()->m_jisik = Singletons::getInstance()->m_jisik + 15;
	//요일 증가
	
}
//책읽고 멍떄림
void MainScene::bookcloseC(Ref *pSender)
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
	removeChildByTag(144);
	removeChildByTag(145);
	removeChildByTag(146);
	removeChildByTag(147);
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
	removeChildByTag(231);
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
	auto action_item3 = MenuItemImage::create(
		"MiniGameResources/today_book.png",
		"MiniGameResources/today_book.png",
		// 임시 
		CC_CALLBACK_1(MainScene::trash, this));
	action_item3->setPosition(Point(0, 0));

	auto play = Menu::create(action_item3, NULL);
	play->setAnchorPoint(Point(0.5, 0));
	play->setPosition(Point(520, 400));
	play->setTag(119);
	this->addChild(play, 1);
	Sprite* info = Sprite::create("MiniGameResources/UI_Textlblack.png");
	info->setAnchorPoint(Point(0.5, 0.5));
	info->setPosition(Point(510, 100));
	info->setTag(145);
	this->addChild(info, 3);

	char MyString[200];
	WideCharToMultiByte(CP_UTF8, 0, L"음냐... 엇..? 졸아버렸잖아?\n\n(지식이 증가하지 않았습니다.)", -1, MyString, 200, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "fonts/ABC.ttf", 25);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(146);
	this->addChild(name, 4);

	auto text_item = MenuItemImage::create(
		"MiniGameResources/ok_button.png",
		"MiniGameResources/ok_buttonpr.png",
		CC_CALLBACK_1(MainScene::nextday, this));
	text_item->setAnchorPoint(Point(0.5, 0.5));
	text_item->setPosition(Point(950, 65));

	auto text = Menu::create(text_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(130);
	this->addChild(text, 5);
	//지식량 증가
	
	//요일 증가

}
//행동후 다음날로 넘어갈떄
void MainScene::nextday(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("MiniGameResources/button_click_16_sound_effects_.mp3", false);
	Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
	Director::getInstance()->replaceScene(NextDayScene::createScene());
}
void MainScene::trash(Ref *pSender)
{
	//필요없는함수 이리이리 모여라
}
//일지 판업창
void MainScene::planspr(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("MiniGameResources/button_click_16_sound_effects_.mp3", false);
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
				CC_CALLBACK_1(MainScene::cancelcon, this));
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
			removeChildByTag(231);
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


void MainScene::cancelcon(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("MiniGameResources/button_click_16_sound_effects_.mp3", false);
	removeChildByTag(168);
	removeChildByTag(165);
	removeChildByTag(166);
	removeChildByTag(167);


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
	removeChildByTag(231);
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

	InitMenu();
}

void MainScene::finalspr(Ref *pSender)
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
			CC_CALLBACK_1(MainScene::exitspr, this));
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
			CC_CALLBACK_1(MainScene::cancelcon, this));
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
		removeChildByTag(231);
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
void MainScene::exitspr(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("MiniGameResources/button_click_16_sound_effects_.mp3", false);
	Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif
}

void MainScene::SetLabel(float delta)
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
	//		CC_CALLBACK_1(MainScene::exitspr, this));
	//	exitok_item->setPosition(Point(0, 0));


	//	auto exitok = Menu::create(exitok_item, NULL);
	//	exitok->setAnchorPoint(Point(0.5, 0.5));
	//	exitok->setPosition(Point(480, 435));
	//	exitok->setTag(52);
	//	this->addChild(exitok, 2);
	//}
}
	void MainScene::InitLabel()
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