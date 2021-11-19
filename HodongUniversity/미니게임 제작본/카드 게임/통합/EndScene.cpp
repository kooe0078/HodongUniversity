#include "EndScene.h"
#include "SimpleAudioEngine.h"
#include "MainScene.h"
#include "singleton.h"
//���� �Ҷ�� �� �ʿ�
using namespace CocosDenshion;
USING_NS_CC;

Scene* EndScene::createScene()
{
    auto scene = Scene::create();
    auto layer = EndScene::create();
    scene->addChild(layer);

    return scene;
}

bool EndScene::init()
{

    if ( !Layer::init() )
    {
        return false;
    }
	
	InitBackGround();
	initLabel();
	setAnswer();
	Menuitem();

	//�������
	SimpleAudioEngine::getInstance()->playBackgroundMusic("MiniGameResources/EndSceneMusic.mp3", true);

    return true;
}
void EndScene::update(float ft)
{
	//�� ��ü������ �ݺ� �Ǿ��ϴ� ����
}

void EndScene::InitBackGround()
{
	Sprite* overSpr = Sprite::create("CardGame_2/Back.png");
	overSpr->setAnchorPoint(Point(0.5, 0.5));
	overSpr->setPosition(Point(512, 384));
	this->addChild(overSpr);
}
void EndScene::initLabel() // ī�� :
{
	char Q1[200];
	WideCharToMultiByte(CP_UTF8, 0, L"���� ���� : ", -1, Q1, 200, NULL, NULL);
	auto Quiz = Label::createWithTTF(Q1, "CardGame_2/ABC.ttf", 27);
	Quiz->setAnchorPoint(Point(0, 1));
	Quiz->setPosition(Point(350, 650));
	Quiz->setColor(Color3B::BLACK);
	this->addChild(Quiz);

	auto label_0 = Label::create("", "CardGame_2/ABC.ttf", 27);
	label_0->setAnchorPoint(Point(0, 1));
	label_0->setPosition(Point(500, 650));
	label_0->setTag(560);
	label_0->setColor(Color3B::RED);
	this->addChild(label_0);

	setAnswer();
}
void EndScene::setAnswer() // ī�� ����
{
	auto label = (Label*)this->getChildByTag(560);
	label->setString(StringUtils::format("%d", Singletons::getInstance()->CardOK));
}
void EndScene::Menuitem() // Ȯ�� ��ư
{
	auto Back = MenuItemImage::create(
		"CardGame_2/UI_enter.png",
		"CardGame_2/UI_enterpr.png",
		CC_CALLBACK_1(EndScene::Check_1, this));
	Back->setPosition(Point(512, 250));

	auto menu1 = Menu::create(Back, NULL);
	menu1->setPosition(Vec2::ZERO);
	this->addChild(menu1, 2);
}
void EndScene::Check_1(Ref *pSender) // ����ȭ������
{
	Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
	Director::getInstance()->replaceScene(MainScene::createScene());

	UserDefault::getInstance()->setIntegerForKey("CardOK", 0); // CardOK�� 0���� �ʱ�ȭ
	Singletons::getInstance()->CardOK = UserDefault::getInstance()->getIntegerForKey("CardOK");
	UserDefault::getInstance()->flush();
}