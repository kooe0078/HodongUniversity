#include "EndScene.h"
#include "SimpleAudioEngine.h"
#include "MainScene.h"
#include "singleton.h"
//사운드 할라면 꼭 필요
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
	Menuitem();

	//배경음악
	SimpleAudioEngine::getInstance()->playBackgroundMusic("MiniGameResources/EndSceneMusic.mp3", true);

    return true;
}
void EndScene::update(float ft)
{
	//씬 자체적으로 반복 되야하는 내용
}
void EndScene::InitBackGround()
{
	Sprite* overSpr = Sprite::create("QuizGame/Back.png");
	overSpr->setAnchorPoint(Point(0.5, 0.5));
	overSpr->setPosition(Point(512, 384));
	this->addChild(overSpr, 0);
}
void EndScene::initLabel() // 정답 :
{
	char Q1[200];
	WideCharToMultiByte(CP_UTF8, 0, L"맞춘 개수 : ", -1, Q1, 200, NULL, NULL);
	auto Quiz = Label::createWithTTF(Q1, "QuizGame/ABC.ttf", 27);
	Quiz->setAnchorPoint(Point(0, 1));
	Quiz->setPosition(Point(350, 650));
	Quiz->setColor(Color3B::BLACK);
	this->addChild(Quiz);

	auto label_0 = Label::create("", "QuizGame/ABC.ttf", 27);
	label_0->setAnchorPoint(Point(0, 1));
	label_0->setPosition(Point(500, 650));
	label_0->setTag(550);
	label_0->setColor(Color3B::RED);
	this->addChild(label_0);

	setAnswer();
}
void EndScene::setAnswer() // 정답 개수
{
	auto label = (Label*)this->getChildByTag(550);
	label->setString(StringUtils::format("%d", Singletons::getInstance()->Answer));
}
void EndScene::Menuitem() // 확인 버튼
{
	auto Back = MenuItemImage::create(
		"QuizGame/UI_enter.png",
		"QuizGame/UI_enterpr.png",
		CC_CALLBACK_1(EndScene::Check_1, this));
	Back->setPosition(Point(512, 250));

	auto menu1 = Menu::create(Back, NULL);
	menu1->setPosition(Vec2::ZERO);
	this->addChild(menu1, 2);
}
void EndScene::Check_1(Ref *pSender) // 메인화면으로
{
	Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
	Director::getInstance()->replaceScene(MainScene::createScene());

	UserDefault::getInstance()->setIntegerForKey("Qnum", 0); // Qnum을 0으로 초기화 
	Singletons::getInstance()->Qnum = UserDefault::getInstance()->getIntegerForKey("Qnum");
	UserDefault::getInstance()->flush();

	UserDefault::getInstance()->setIntegerForKey("Answer", 0); // Answer을 0으로 초기화
	Singletons::getInstance()->Answer = UserDefault::getInstance()->getIntegerForKey("Answer");
	UserDefault::getInstance()->flush();
}