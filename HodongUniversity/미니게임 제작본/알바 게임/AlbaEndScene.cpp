#include "AlbaEndScene.h"
#include "SimpleAudioEngine.h"
#include "AlbaScene.h"
#include "singleton.h"

//���� �Ҷ�� �� �ʿ�
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

	//�������
	SimpleAudioEngine::getInstance()->playBackgroundMusic("MiniGameResources/AlbaEndSceneMusic.mp3", true);

	return true;
}
void AlbaEndScene::update(float ft)
{
	//�� ��ü������ �ݺ� �Ǿ��ϴ� ����
}
void AlbaEndScene::InitBackGround()
{
	Sprite* overSpr = Sprite::create("AlbaGame/Back.png");
	overSpr->setAnchorPoint(Point(0.5, 0.5));
	overSpr->setPosition(Point(512, 384));
	this->addChild(overSpr, 0);
}
void AlbaEndScene::initLabel() // �ű� :
{
	char Q1[200];
	WideCharToMultiByte(CP_UTF8, 0, L"�ű� ���� : ", -1, Q1, 200, NULL, NULL);
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
void AlbaEndScene::setAnswer() // �ű� ����
{
	auto label = (Label*)this->getChildByTag(550);
	label->setString(StringUtils::format("%d", Singletons::getInstance()->Many));
}
void AlbaEndScene::Menuitem() // Ȯ�� ��ư
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
void AlbaEndScene::Check_1(Ref *pSender) // ����ȭ������
{
	Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
	Director::getInstance()->replaceScene(MainScene::createScene());

	UserDefault::getInstance()->setIntegerForKey("aurrClock", 11); // aurrClock�� 11���� �ʱ�ȭ 
	Singletons::getInstance()->aurrClock = UserDefault::getInstance()->getIntegerForKey("aurrClock");
	UserDefault::getInstance()->flush();

	UserDefault::getInstance()->setIntegerForKey("Many", 0); // Many�� 0���� �ʱ�ȭ 
	Singletons::getInstance()->Many = UserDefault::getInstance()->getIntegerForKey("Many");
	UserDefault::getInstance()->flush();
}