#include "Shop2.h"
#include "EndScene.h"
#include "SimpleAudioEngine.h"
#include "Shop.h"

//���� �Ҷ�� �� �ʿ�
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
void Shop2::initBG() // ���, ���� ����â
{
	auto spr = CCSprite::create("Shop/map_purchase2.png");
	spr->setPosition(Point(512, 384));
	this->addChild(spr);
}
void Shop2::MenuLabel() // ���� ����
{
	// 1�� ����
	char Q1[200];
	WideCharToMultiByte(CP_UTF8, 0, L"ũ�������� ���� ���� �� �� �ִ� ���̴�.\n�̰� ��� ���� ���̵鿡�� ������ �ǰ���??\n���� : 7����          �μ� +5", -1, Q1, 200, NULL, NULL);
	auto EX1 = Label::createWithTTF(Q1, "Shop/ABC.ttf", 30);
	EX1->setAnchorPoint(Point(0, 1));
	EX1->setPosition(Point(330, 735));
	EX1->setColor(Color3B::BLACK);
	this->addChild(EX1, 2);
	// 2�� ����
	WideCharToMultiByte(CP_UTF8, 0, L"�츮���� �ڿ������ü�� �����̴�.\n���濡 �ϳ����� �ް� �ٳ�� �ڴ�.\n���� : 10����          �μ� +10", -1, Q1, 200, NULL, NULL);
	auto EX2 = Label::createWithTTF(Q1, "Shop/ABC.ttf", 30);
	EX2->setAnchorPoint(Point(0, 1));
	EX2->setPosition(Point(330, 625));
	EX2->setColor(Color3B::BLACK);
	this->addChild(EX2, 2);
	//3�� ����
	WideCharToMultiByte(CP_UTF8, 0, L"�������� ��ȣ��ü�� �����̴�.\n���̵��� ���ܿ��� ������ ���� �� ����...\n���� : 20����         �μ� +20", -1, Q1, 200, NULL, NULL);
	auto EX3 = Label::createWithTTF(Q1, "Shop/ABC.ttf", 30);
	EX3->setAnchorPoint(Point(0, 1));
	EX3->setPosition(Point(330, 515));
	EX3->setColor(Color3B::BLACK);
	this->addChild(EX3, 2);
	// 4�� ����
	WideCharToMultiByte(CP_UTF8, 0, L"���б� ������ ��ﳪ�� ���̴�.\nģ���鿡�� �������ָ� ������ �� ����.\n���� : 7����          ģ�е� +5", -1, Q1, 200, NULL, NULL);
	auto EX4 = Label::createWithTTF(Q1, "Shop/ABC.ttf", 30);
	EX4->setAnchorPoint(Point(0, 1));
	EX4->setPosition(Point(330, 405));
	EX4->setColor(Color3B::BLACK);
	this->addChild(EX4, 2);
	// 5�� ����
	WideCharToMultiByte(CP_UTF8, 0, L"����ģ������ �ָ� ������ �� ���� ���̴�.\n�ٵ� �� ��ģ�� ���ݾ�? �� �ȵɰž� �Ƹ�....\n���� : 10����          ģ�е� +10", -1, Q1, 200, NULL, NULL);
	auto EX5 = Label::createWithTTF(Q1, "Shop/ABC.ttf", 30);
	EX5->setAnchorPoint(Point(0, 1));
	EX5->setPosition(Point(330, 295));
	EX5->setColor(Color3B::BLACK);
	this->addChild(EX5, 2);
	// 6�� ����
	WideCharToMultiByte(CP_UTF8, 0, L"���������� ����� ���������̴�.\n������ ������ ����ִ����� �ƹ��� �𸥴�.\n���� : 20����         ģ�е� +20", -1, Q1, 200, NULL, NULL);
	auto EX6 = Label::createWithTTF(Q1, "Shop/ABC.ttf", 30);
	EX6->setAnchorPoint(Point(0, 1));
	EX6->setPosition(Point(330, 185));
	EX6->setColor(Color3B::BLACK);
	this->addChild(EX6, 2);
}
void Shop2::Menuitem() // ���� ��ư
{
	// 1�� ����
	auto Back1 = MenuItemImage::create(
		"Shop/purchase_buy.png",
		"Shop/purchase_buypr.png",
		CC_CALLBACK_1(Shop2::Pur1, this));
	Back1->setPosition(Point(922, 682));

	auto menu1 = Menu::create(Back1, NULL);
	menu1->setPosition(Vec2::ZERO);
	this->addChild(menu1, 2);
	// 2�� ����
	auto Back2 = MenuItemImage::create(
		"Shop/purchase_buy.png",
		"Shop/purchase_buypr.png",
		CC_CALLBACK_1(Shop2::Pur2, this));
	Back2->setPosition(Point(922, 572));

	auto menu2 = Menu::create(Back2, NULL);
	menu2->setPosition(Vec2::ZERO);
	this->addChild(menu2, 2);
	//3�� ����
	auto Back3 = MenuItemImage::create(
		"Shop/purchase_buy.png",
		"Shop/purchase_buypr.png",
		CC_CALLBACK_1(Shop2::Pur3, this));
	Back3->setPosition(Point(922, 462));
	//
	auto menu3 = Menu::create(Back3, NULL);
	menu3->setPosition(Vec2::ZERO);
	this->addChild(menu3, 2);
	// 4�� ����
	auto Back4 = MenuItemImage::create(
		"Shop/purchase_buy.png",
		"Shop/purchase_buypr.png",
		CC_CALLBACK_1(Shop2::Pur4, this));
	Back4->setPosition(Point(922, 352));

	auto menu4 = Menu::create(Back4, NULL);
	menu4->setPosition(Vec2::ZERO);
	this->addChild(menu4, 2);
	// 5�� ����
	auto Back5 = MenuItemImage::create(
		"Shop/purchase_buy.png",
		"Shop/purchase_buypr.png",
		CC_CALLBACK_1(Shop2::Pur5, this));
	Back5->setPosition(Point(922, 242));

	auto menu5 = Menu::create(Back5, NULL);
	menu5->setPosition(Vec2::ZERO);
	this->addChild(menu5, 2);
	// 6�� ����
	auto Back6 = MenuItemImage::create(
		"Shop/purchase_buy.png",
		"Shop/purchase_buypr.png",
		CC_CALLBACK_1(Shop2::Pur6, this));
	Back6->setPosition(Point(922, 132));

	auto menu6 = Menu::create(Back6, NULL);
	menu6->setPosition(Vec2::ZERO);
	this->addChild(menu6, 2);
}
void Shop2::Pur1(Ref * pSender) // 1�� ����
{		

}				  			  
void Shop2::Pur2(Ref * pSender) // 2�� ����
{			

}				  			  
void Shop2::Pur3(Ref * pSender) // 3�� ����
{		

}				  		  
void Shop2::Pur4(Ref * pSender) // 4�� ����
{		

}				  		  
void Shop2::Pur5(Ref * pSender) // 5�� ����
{		

}				  			  
void Shop2::Pur6(Ref * pSender) // 6�� ����
{

}
void Shop2::Next() // ���� 1������
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
void Shop2::Go(Ref * pSender) // �Ѿ��
{
	Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
	Director::getInstance()->replaceScene(Shop::createScene());
}
void Shop2::Exit() // ���� ������
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
void Shop2::Back(Ref * pSender) // ������
{
	Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
	Director::getInstance()->replaceScene(EndScene::createScene());
}