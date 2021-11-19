#include "Shop.h"
#include "EndScene.h"
#include "SimpleAudioEngine.h"
#include "Shop2.h"

//사운드 할라면 꼭 필요
using namespace CocosDenshion;
USING_NS_CC;

Scene* Shop::createScene()
{
    auto scene = Scene::create();
    auto layer = Shop::create();
    scene->addChild(layer);

    return scene;
}

bool Shop::init()
{

    if ( !Layer::init() )
    {
        return false;
    }

	initBG();
	MenuLabel();
	Menuitem();
	Next();
	Exit();

    return true;
}
void Shop::initBG() // 배경, 물건 나열창
{
	auto spr = CCSprite::create("Shop/map_purchase1.png");
	spr->setPosition(Point(512, 384));
	this->addChild(spr);
}
void Shop::MenuLabel() // 물건 설명
{
	// 1번 설명
	char Q1[200];
	WideCharToMultiByte(CP_UTF8, 0, L"요즘 초등학생이 푸는 학습지이다.\n이 나이먹고 이런걸 써야겠어??\n가격 : 7만원          학력 +5", -1, Q1, 200, NULL, NULL);
	auto EX1 = Label::createWithTTF(Q1, "Shop/ABC.ttf", 30);
	EX1->setAnchorPoint(Point(0, 1));
	EX1->setPosition(Point(245, 735));
	EX1->setColor(Color3B::BLACK);
	this->addChild(EX1, 2);
	// 2번 설명
	WideCharToMultiByte(CP_UTF8, 0, L"중학교 시절 쓰던 문제집이다.\n라면 받침으로 쓰면 딱 좋을것 같다.\n가격 : 10만원          학력 +10", -1, Q1, 200, NULL, NULL);
	auto EX2 = Label::createWithTTF(Q1, "Shop/ABC.ttf", 30);
	EX2->setAnchorPoint(Point(0, 1));
	EX2->setPosition(Point(245, 625));
	EX2->setColor(Color3B::BLACK);
	this->addChild(EX2, 2);
	//3번 설명
	WideCharToMultiByte(CP_UTF8, 0, L"보기만 해도 기분이 나빠지는 책이다.\n지금 당장이라도 창밖으로 던져버리고싶다...\n가격 : 20만원         학력 +20", -1, Q1, 200, NULL, NULL);
	auto EX3 = Label::createWithTTF(Q1, "Shop/ABC.ttf", 30);
	EX3->setAnchorPoint(Point(0, 1));
	EX3->setPosition(Point(245, 515));
	EX3->setColor(Color3B::BLACK);
	this->addChild(EX3, 2);
	// 4번 설명
	WideCharToMultiByte(CP_UTF8, 0, L"어린 시절에 보던 만화이다.\n나도 저걸 보고 농구선수를 꿈꿨었지...\n가격 : 7만원          지능 +5", -1, Q1, 200, NULL, NULL);
	auto EX4 = Label::createWithTTF(Q1, "Shop/ABC.ttf", 30);
	EX4->setAnchorPoint(Point(0, 1));
	EX4->setPosition(Point(245, 405));
	EX4->setColor(Color3B::BLACK);
	this->addChild(EX4, 2);
	// 5번 설명
	WideCharToMultiByte(CP_UTF8, 0, L"감수성이 풍부해질 것만 같은 시집이다.\n읽다보면 잠이 올것만 같다....\n가격 : 10만원          지능 +10", -1, Q1, 200, NULL, NULL);
	auto EX5 = Label::createWithTTF(Q1, "Shop/ABC.ttf", 30);
	EX5->setAnchorPoint(Point(0, 1));
	EX5->setPosition(Point(245, 295));
	EX5->setColor(Color3B::BLACK);
	this->addChild(EX5, 2);
	// 6번 설명
	WideCharToMultiByte(CP_UTF8, 0, L"엄청 두껍고 어려워 보이는 책이다.\n이건 도저히 사람이 보라고 쓴 책이 아닌것 같다.\n가격 : 20만원         지능 +20", -1, Q1, 200, NULL, NULL);
	auto EX6 = Label::createWithTTF(Q1, "Shop/ABC.ttf", 30);
	EX6->setAnchorPoint(Point(0, 1));
	EX6->setPosition(Point(245, 185));
	EX6->setColor(Color3B::BLACK);
	this->addChild(EX6, 2);
}
void Shop::Menuitem() // 구매 버튼
{
	// 1번 구매
	auto Back1 = MenuItemImage::create(
		"Shop/purchase_buy.png",
		"Shop/purchase_buypr.png",
		CC_CALLBACK_1(Shop::Pur1, this));
	Back1->setPosition(Point(870, 682));

	auto menu1 = Menu::create(Back1, NULL);
	menu1->setPosition(Vec2::ZERO);
	this->addChild(menu1, 2);
	// 2번 구매
	auto Back2 = MenuItemImage::create(
		"Shop/purchase_buy.png",
		"Shop/purchase_buypr.png",
		CC_CALLBACK_1(Shop::Pur2, this));
	Back2->setPosition(Point(870, 572));

	auto menu2 = Menu::create(Back2, NULL);
	menu2->setPosition(Vec2::ZERO);
	this->addChild(menu2, 2);
	//3번 구매
	auto Back3 = MenuItemImage::create(
		"Shop/purchase_buy.png",
		"Shop/purchase_buypr.png",
		CC_CALLBACK_1(Shop::Pur3, this));
	Back3->setPosition(Point(870, 462));
	//
	auto menu3 = Menu::create(Back3, NULL);
	menu3->setPosition(Vec2::ZERO);
	this->addChild(menu3, 2);
	// 4번 구매
	auto Back4 = MenuItemImage::create(
		"Shop/purchase_buy.png",
		"Shop/purchase_buypr.png",
		CC_CALLBACK_1(Shop::Pur4, this));
	Back4->setPosition(Point(870, 352));

	auto menu4 = Menu::create(Back4, NULL);
	menu4->setPosition(Vec2::ZERO);
	this->addChild(menu4, 2);
	// 5번 구매
	auto Back5 = MenuItemImage::create(
		"Shop/purchase_buy.png",
		"Shop/purchase_buypr.png",
		CC_CALLBACK_1(Shop::Pur5, this));
	Back5->setPosition(Point(870, 242));

	auto menu5 = Menu::create(Back5, NULL);
	menu5->setPosition(Vec2::ZERO);
	this->addChild(menu5, 2);
	// 6번 구매
	auto Back6 = MenuItemImage::create(
		"Shop/purchase_buy.png",
		"Shop/purchase_buypr.png",
		CC_CALLBACK_1(Shop::Pur6, this));
	Back6->setPosition(Point(870, 132));

	auto menu6 = Menu::create(Back6, NULL);
	menu6->setPosition(Vec2::ZERO);
	this->addChild(menu6, 2);
}
void Shop::Pur1(Ref * pSender) // 1번 구매
{		

}				  			  
void Shop::Pur2(Ref * pSender) // 2번 구매
{			

}				  			  
void Shop::Pur3(Ref * pSender) // 3번 구매
{		

}				  		  
void Shop::Pur4(Ref * pSender) // 4번 구매
{		

}				  		  
void Shop::Pur5(Ref * pSender) // 5번 구매
{		

}				  			  
void Shop::Pur6(Ref * pSender) // 6번 구매
{

}
void Shop::Next() // 상점 2번으로
{
	auto next = MenuItemImage::create(
		"Shop/purchase_next.png",
		"Shop/purchase_nextpr.png",
		CC_CALLBACK_1(Shop::Go, this));
	next->setPosition(Point(960, 384));

	auto menu1 = Menu::create(next, NULL);
	menu1->setPosition(Vec2::ZERO);
	this->addChild(menu1, 2);
}
void Shop::Go(Ref * pSender) // 넘어가기
{
	Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
	Director::getInstance()->replaceScene(Shop2::createScene());
}
void Shop::Exit() // 상점 나가기
{
	auto exit = MenuItemImage::create(
		"Shop/purchase_exit.png",
		"Shop/purchase_exitpr.png",
		CC_CALLBACK_1(Shop::Back, this));
	exit->setPosition(Point(904, 40));

	auto menu1 = Menu::create(exit, NULL);
	menu1->setPosition(Vec2::ZERO);
	this->addChild(menu1, 2);
}
void Shop::Back(Ref * pSender) // 나가기
{
	Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
	Director::getInstance()->replaceScene(EndScene::createScene());
}