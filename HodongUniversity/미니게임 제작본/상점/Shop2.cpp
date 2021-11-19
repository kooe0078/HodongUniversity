#include "Shop2.h"
#include "EndScene.h"
#include "SimpleAudioEngine.h"
#include "Shop.h"

//사운드 할라면 꼭 필요
using namespace CocosDenshion;
USING_NS_CC;

Scene* Shop2::createScene()
{
    auto scene = Scene::create();
    auto layer = Shop2::create();
    scene->addChild(layer);

    return scene;
}

bool Shop2::init()
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
void Shop2::initBG() // 배경, 물건 나열창
{
	auto spr = CCSprite::create("Shop/map_purchase2.png");
	spr->setPosition(Point(512, 384));
	this->addChild(spr);
}
void Shop2::MenuLabel() // 물건 설명
{
	// 1번 설명
	char Q1[200];
	WideCharToMultiByte(CP_UTF8, 0, L"크리스마스 시즌에 자주 볼 수 있는 씰이다.\n이걸 사면 아픈 아이들에게 도움이 되겠지??\n가격 : 7만원          인성 +5", -1, Q1, 200, NULL, NULL);
	auto EX1 = Label::createWithTTF(Q1, "Shop/ABC.ttf", 30);
	EX1->setAnchorPoint(Point(0, 1));
	EX1->setPosition(Point(330, 735));
	EX1->setColor(Color3B::BLACK);
	this->addChild(EX1, 2);
	// 2번 설명
	WideCharToMultiByte(CP_UTF8, 0, L"우리나라 자원봉사단체의 배지이다.\n가방에 하나쯤은 달고 다녀야 겠다.\n가격 : 10만원          인성 +10", -1, Q1, 200, NULL, NULL);
	auto EX2 = Label::createWithTTF(Q1, "Shop/ABC.ttf", 30);
	EX2->setAnchorPoint(Point(0, 1));
	EX2->setPosition(Point(330, 625));
	EX2->setColor(Color3B::BLACK);
	this->addChild(EX2, 2);
	//3번 설명
	WideCharToMultiByte(CP_UTF8, 0, L"국제적인 구호단체의 광고이다.\n아이들의 힘겨움이 전해져 오는 것 같다...\n가격 : 20만원         인성 +20", -1, Q1, 200, NULL, NULL);
	auto EX3 = Label::createWithTTF(Q1, "Shop/ABC.ttf", 30);
	EX3->setAnchorPoint(Point(0, 1));
	EX3->setPosition(Point(330, 515));
	EX3->setColor(Color3B::BLACK);
	this->addChild(EX3, 2);
	// 4번 설명
	WideCharToMultiByte(CP_UTF8, 0, L"중학교 시절이 기억나는 빵이다.\n친구들에게 가져다주면 좋아할 것 같다.\n가격 : 7만원          친밀도 +5", -1, Q1, 200, NULL, NULL);
	auto EX4 = Label::createWithTTF(Q1, "Shop/ABC.ttf", 30);
	EX4->setAnchorPoint(Point(0, 1));
	EX4->setPosition(Point(330, 405));
	EX4->setColor(Color3B::BLACK);
	this->addChild(EX4, 2);
	// 5번 설명
	WideCharToMultiByte(CP_UTF8, 0, L"여자친구에게 주면 좋아할 것 같은 꽃이다.\n근데 난 여친이 없잖아? 난 안될거야 아마....\n가격 : 10만원          친밀도 +10", -1, Q1, 200, NULL, NULL);
	auto EX5 = Label::createWithTTF(Q1, "Shop/ABC.ttf", 30);
	EX5->setAnchorPoint(Point(0, 1));
	EX5->setPosition(Point(330, 295));
	EX5->setColor(Color3B::BLACK);
	this->addChild(EX5, 2);
	// 6번 설명
	WideCharToMultiByte(CP_UTF8, 0, L"정성스럽게 포장된 선물상자이다.\n하지만 무엇이 들어있는지는 아무도 모른다.\n가격 : 20만원         친밀도 +20", -1, Q1, 200, NULL, NULL);
	auto EX6 = Label::createWithTTF(Q1, "Shop/ABC.ttf", 30);
	EX6->setAnchorPoint(Point(0, 1));
	EX6->setPosition(Point(330, 185));
	EX6->setColor(Color3B::BLACK);
	this->addChild(EX6, 2);
}
void Shop2::Menuitem() // 구매 버튼
{
	// 1번 구매
	auto Back1 = MenuItemImage::create(
		"Shop/purchase_buy.png",
		"Shop/purchase_buypr.png",
		CC_CALLBACK_1(Shop2::Pur1, this));
	Back1->setPosition(Point(922, 682));

	auto menu1 = Menu::create(Back1, NULL);
	menu1->setPosition(Vec2::ZERO);
	this->addChild(menu1, 2);
	// 2번 구매
	auto Back2 = MenuItemImage::create(
		"Shop/purchase_buy.png",
		"Shop/purchase_buypr.png",
		CC_CALLBACK_1(Shop2::Pur2, this));
	Back2->setPosition(Point(922, 572));

	auto menu2 = Menu::create(Back2, NULL);
	menu2->setPosition(Vec2::ZERO);
	this->addChild(menu2, 2);
	//3번 구매
	auto Back3 = MenuItemImage::create(
		"Shop/purchase_buy.png",
		"Shop/purchase_buypr.png",
		CC_CALLBACK_1(Shop2::Pur3, this));
	Back3->setPosition(Point(922, 462));
	//
	auto menu3 = Menu::create(Back3, NULL);
	menu3->setPosition(Vec2::ZERO);
	this->addChild(menu3, 2);
	// 4번 구매
	auto Back4 = MenuItemImage::create(
		"Shop/purchase_buy.png",
		"Shop/purchase_buypr.png",
		CC_CALLBACK_1(Shop2::Pur4, this));
	Back4->setPosition(Point(922, 352));

	auto menu4 = Menu::create(Back4, NULL);
	menu4->setPosition(Vec2::ZERO);
	this->addChild(menu4, 2);
	// 5번 구매
	auto Back5 = MenuItemImage::create(
		"Shop/purchase_buy.png",
		"Shop/purchase_buypr.png",
		CC_CALLBACK_1(Shop2::Pur5, this));
	Back5->setPosition(Point(922, 242));

	auto menu5 = Menu::create(Back5, NULL);
	menu5->setPosition(Vec2::ZERO);
	this->addChild(menu5, 2);
	// 6번 구매
	auto Back6 = MenuItemImage::create(
		"Shop/purchase_buy.png",
		"Shop/purchase_buypr.png",
		CC_CALLBACK_1(Shop2::Pur6, this));
	Back6->setPosition(Point(922, 132));

	auto menu6 = Menu::create(Back6, NULL);
	menu6->setPosition(Vec2::ZERO);
	this->addChild(menu6, 2);
}
void Shop2::Pur1(Ref * pSender) // 1번 구매
{		

}				  			  
void Shop2::Pur2(Ref * pSender) // 2번 구매
{			

}				  			  
void Shop2::Pur3(Ref * pSender) // 3번 구매
{		

}				  		  
void Shop2::Pur4(Ref * pSender) // 4번 구매
{		

}				  		  
void Shop2::Pur5(Ref * pSender) // 5번 구매
{		

}				  			  
void Shop2::Pur6(Ref * pSender) // 6번 구매
{

}
void Shop2::Next() // 상점 1번으로
{
	auto next = MenuItemImage::create(
		"Shop/purchase_backpr.png",
		"Shop/purchase_back.png",
		CC_CALLBACK_1(Shop2::Go, this));
	next->setPosition(Point(64, 384));

	auto menu1 = Menu::create(next, NULL);
	menu1->setPosition(Vec2::ZERO);
	this->addChild(menu1, 2);
}
void Shop2::Go(Ref * pSender) // 넘어가기
{
	Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
	Director::getInstance()->replaceScene(Shop::createScene());
}
void Shop2::Exit() // 상점 나가기
{
	auto exit = MenuItemImage::create(
		"Shop/purchase_exit.png",
		"Shop/purchase_exitpr.png",
		CC_CALLBACK_1(Shop2::Back, this));
	exit->setPosition(Point(904, 40));

	auto menu1 = Menu::create(exit, NULL);
	menu1->setPosition(Vec2::ZERO);
	this->addChild(menu1, 2);
}
void Shop2::Back(Ref * pSender) // 나가기
{
	Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
	Director::getInstance()->replaceScene(EndScene::createScene());
}