#include "MiroEndScene.h"
#include "SimpleAudioEngine.h"
#include "MiroScene.h"
#include "singleton.h"
//사운드 할라면 꼭 필요
using namespace CocosDenshion;
USING_NS_CC;

Scene* MiroEndScene::createScene()
{
    auto scene = Scene::create();
    auto layer = MiroEndScene::create();
    scene->addChild(layer);

    return scene;
}

bool MiroEndScene::init()
{

    if ( !Layer::init() )
    {
        return false;
    }
	
	InitBackGround();
	initLabel();
	Setting();
	Menuitem();

	//배경음악
	SimpleAudioEngine::getInstance()->playBackgroundMusic("MiniGameResources/MiroEndSceneMusic.mp3", true);

    return true;
}
void MiroEndScene::InitBackGround()
{
	Sprite* overSpr = Sprite::create("MiroGame/Back.png");
	overSpr->setAnchorPoint(Point(0.5, 0.5));
	overSpr->setPosition(Point(512, 384));
	this->addChild(overSpr, 0);
}
void MiroEndScene::initLabel() // 남은 시간 :
{
	char Q1[200];
	WideCharToMultiByte(CP_UTF8, 0, L"남은 시간 :       초", -1, Q1, 200, NULL, NULL);
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
void MiroEndScene::Setting() // 남은 시간
{
	auto label = (Label*)this->getChildByTag(550);
	label->setString(StringUtils::format("%d", Singletons::getInstance()->currClock));
}
void MiroEndScene::Menuitem() // 확인 버튼
{
	auto Back = MenuItemImage::create(
		"MiroGame/UI_enter.png",
		"MiroGame/UI_enterpr.png",
		CC_CALLBACK_1(MiroEndScene::Check, this));
	Back->setPosition(Point(512, 250));

	auto menu1 = Menu::create(Back, NULL);
	menu1->setPosition(Vec2::ZERO);
	this->addChild(menu1, 2);
}
void MiroEndScene::Check(Ref *pSender) // 메인화면으로
{
	UserDefault::getInstance()->setIntegerForKey("currClock", 6); // currClock을 6으로 초기화 
	Singletons::getInstance()->currClock = UserDefault::getInstance()->getIntegerForKey("currClock");
	UserDefault::getInstance()->flush();

	Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
	Director::getInstance()->replaceScene(MiroScene::createScene());
}