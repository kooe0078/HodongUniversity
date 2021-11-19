#include "AlbaEndScene.h"
#include "SimpleAudioEngine.h"
#include "AlbaScene.h"
#include "singleton.h"

//사운드 할라면 꼭 필요
using namespace CocosDenshion;
USING_NS_CC;

Scene* AlbaEndScene::createScene()
{
    auto scene = Scene::create();
    auto layer = AlbaEndScene::create();
    scene->addChild(layer);

    return scene;
}

bool AlbaEndScene::init()
{

	if (!Layer::init())
	{
		return false;
	}

	InitBackGround();
	initLabel();
	Menuitem();

	//배경음악
	SimpleAudioEngine::getInstance()->playBackgroundMusic("MiniGameResources/AlbaEndSceneMusic.mp3", true);

	return true;
}
void AlbaEndScene::update(float ft)
{
	//씬 자체적으로 반복 되야하는 내용
}
void AlbaEndScene::InitBackGround()
{
	Sprite* overSpr = Sprite::create("AlbaGame/Back.png");
	overSpr->setAnchorPoint(Point(0.5, 0.5));
	overSpr->setPosition(Point(512, 384));
	this->addChild(overSpr, 0);
}
void AlbaEndScene::initLabel() // 옮김 :
{
	char Q1[200];
	WideCharToMultiByte(CP_UTF8, 0, L"옮긴 개수 : ", -1, Q1, 200, NULL, NULL);
	auto Quiz = Label::createWithTTF(Q1, "AlbaGame/ABC.ttf", 27);
	Quiz->setAnchorPoint(Point(0, 1));
	Quiz->setPosition(Point(350, 650));
	Quiz->setColor(Color3B::BLACK);
	this->addChild(Quiz);

	auto label_0 = Label::create("", "AlbaGame/ABC.ttf", 27);
	label_0->setAnchorPoint(Point(0, 1));
	label_0->setPosition(Point(500, 650));
	label_0->setTag(550);
	label_0->setColor(Color3B::RED);
	this->addChild(label_0);

	setAnswer();
}
void AlbaEndScene::setAnswer() // 옮긴 개수
{
	auto label = (Label*)this->getChildByTag(550);
	label->setString(StringUtils::format("%d", Singletons::getInstance()->Many));
}
void AlbaEndScene::Menuitem() // 확인 버튼
{
	auto Back = MenuItemImage::create(
		"AlbaGame/UI_enter.png",
		"AlbaGame/UI_enterpr.png",
		CC_CALLBACK_1(AlbaEndScene::Check_1, this));
	Back->setPosition(Point(512, 250));

	auto menu1 = Menu::create(Back, NULL);
	menu1->setPosition(Vec2::ZERO);
	this->addChild(menu1, 2);
}
void AlbaEndScene::Check_1(Ref *pSender) // 메인화면으로
{
	Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
	Director::getInstance()->replaceScene(MainScene::createScene());

	UserDefault::getInstance()->setIntegerForKey("aurrClock", 11); // aurrClock을 11으로 초기화 
	Singletons::getInstance()->aurrClock = UserDefault::getInstance()->getIntegerForKey("aurrClock");
	UserDefault::getInstance()->flush();

	UserDefault::getInstance()->setIntegerForKey("Many", 0); // Many을 0으로 초기화 
	Singletons::getInstance()->Many = UserDefault::getInstance()->getIntegerForKey("Many");
	UserDefault::getInstance()->flush();
}