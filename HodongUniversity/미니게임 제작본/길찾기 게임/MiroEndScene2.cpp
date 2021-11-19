#include "MiroEndScene2.h"
#include "SimpleAudioEngine.h"
#include "MiroScene2.h"
#include "singleton.h"
//���� �Ҷ�� �� �ʿ�
using namespace CocosDenshion;
USING_NS_CC;

Scene* MiroEndScene2::createScene()
{
    auto scene = Scene::create();
    auto layer = MiroEndScene2::create();
    scene->addChild(layer);

    return scene;
}

bool MiroEndScene2::init()
{

    if ( !Layer::init() )
    {
        return false;
    }
	
	InitBackGround();
	initLabel();
	Setting();
	Menuitem();

	//�������
	//SimpleAudioEngine::getInstance()->playBackgroundMusic("MiniGameResources/MiroEndScene2Music.mp3", true);

    return true;
}
void MiroEndScene2::InitBackGround()
{
	Sprite* overSpr = Sprite::create("MiroGame/Back.png");
	overSpr->setAnchorPoint(Point(0.5, 0.5));
	overSpr->setPosition(Point(512, 384));
	this->addChild(overSpr, 0);
}
void MiroEndScene2::initLabel() // ���� �ð� :
{
	char Q1[200];
	WideCharToMultiByte(CP_UTF8, 0, L"���� �ð� :          ��", -1, Q1, 200, NULL, NULL);
	auto Time = Label::createWithTTF(Q1, "MiroGame/ABC.ttf", 27);
	Time->setAnchorPoint(Point(0, 1));
	Time->setPosition(Point(350, 650));
	Time->setColor(Color3B::BLACK);
	this->addChild(Time);

	auto label_0 = Label::create("", "MiroGame/ABC.ttf", 27);
	label_0->setAnchorPoint(Point(0, 1));
	label_0->setPosition(Point(500, 650));
	label_0->setTag(550);
	label_0->setColor(Color3B::RED);
	this->addChild(label_0);

	Setting();
}
void MiroEndScene2::Setting() // ���� �ð�
{
	auto label = (Label*)this->getChildByTag(550);
	label->setString(StringUtils::format("%d", Singletons::getInstance()->currClock2));
}
void MiroEndScene2::Menuitem() // Ȯ�� ��ư
{
	auto Back = MenuItemImage::create(
		"MiroGame/UI_enter.png",
		"MiroGame/UI_enterpr.png",
		CC_CALLBACK_1(MiroEndScene2::Check, this));
	Back->setPosition(Point(512, 250));

	auto menu1 = Menu::create(Back, NULL);
	menu1->setPosition(Vec2::ZERO);
	this->addChild(menu1, 2);
}
void MiroEndScene2::Check(Ref *pSender) // ����ȭ������
{
	UserDefault::getInstance()->setIntegerForKey("currClock2", 13); // currClock2�� 13���� �ʱ�ȭ 
	Singletons::getInstance()->currClock2 = UserDefault::getInstance()->getIntegerForKey("currClock2");
	UserDefault::getInstance()->flush();

	Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
	Director::getInstance()->replaceScene(MiroScene2::createScene());
}