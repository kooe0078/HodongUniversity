#include "ExerciseFin.h"
#include "NextDayScene.h"
#include "SimpleAudioEngine.h"
#include "MainBiriScene.h"
#include "sinngleton.h"
//#include "MainScene.h"
//사운드 할라면 꼭 필요
using namespace CocosDenshion;
USING_NS_CC;

Scene* ExerciseFin::createScene()
{
    auto scene = Scene::create();
    auto layer = ExerciseFin::create();
    scene->addChild(layer);

    return scene;
}

bool ExerciseFin::init()
{

    if ( !Layer::init() )
    {
        return false;
    }

	visibleSize = Director::getInstance()->getVisibleSize();
	origin      = Director::getInstance()->getVisibleOrigin();

	InitBackGround();
	InitLabel();
	InitMenu();
	
	////터치 리스너 등록
	//auto listener = EventListenerTouchOneByOne::create();
	//listener->onTouchBegan = CC_CALLBACK_2(IntroScene::onTouchBegan, this);
	//Director::getInstance()->getEventDispatcher()->addEventListenerWithFixedPriority(listener, 1);

	//배경음악
	//SimpleAudioEngine::getInstance()->playBackgroundMusic("MiniGameResources/IntroBackSound.mp3", true);

	/*this->scheduleOnce(schedule_selector(ExerciseFin::GoHome), 2.0f);
*/
    return true;
}
void ExerciseFin::update(float ft)
{
	//씬 자체적으로 반복 되야하는 내용
}
void ExerciseFin::InitBackGround()
{
	auto sprite = Sprite::create("ExerciseGame//practice_back.png");
	sprite->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	this->addChild(sprite, 0);
}
void ExerciseFin::InitLabel()
{
	
}
// 인트로 선택창
void ExerciseFin::InitMenu()
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);

	//스토리A창
	auto storyA_item = MenuItemImage::create(
		"MiniGameResources/UI_Textlblack.png",
		"MiniGameResources/UI_Textlblack.png",

		CC_CALLBACK_1(ExerciseFin::storyAspr, this));
	storyA_item->setAnchorPoint(Point(0.5, 0.5));
	storyA_item->setPosition(Point(510, 100));

	auto storyA = Menu::create(storyA_item, NULL);
	storyA->setAnchorPoint(Point(0.5, 0.5));
	storyA->setPosition(Point(0, 0));
	storyA->setTag(4);
	this->addChild(storyA,2);

	char MyString[100];
	WideCharToMultiByte(CP_UTF8, 0, L"호동: (열심히 운동했더니 기분이 맑아지는 느낌이다.)", -1, MyString, 100, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "fonts/Bold.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(21);
	this->addChild(name, 3);


	//메인캐릭터
	Sprite* mainchr = Sprite::create("MiniGameResources/main_char.png");
	mainchr->setAnchorPoint(Point(0.5, 0));
	mainchr->setPosition(Point(120, 80));
	mainchr->setTag(166);
	this->addChild(mainchr, 1);

	auto textA_item = MenuItemImage::create(
		"MiniGameResources/ok_button.png",
		"MiniGameResources/ok_buttonpr.png",
		CC_CALLBACK_1(ExerciseFin::storyA, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(131);
	this->addChild(text, 5);
}
void ExerciseFin::storyAspr(Ref *pSender)
{

}

void ExerciseFin::storyA(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);

	//선택씬
	removeChildByTag(131);
	removeChildByTag(130);
	removeChildByTag(21);



	
	char MyString[200];
	WideCharToMultiByte(CP_UTF8, 0, L"(인성이 8 증가하였습니다.)", -1, MyString, 200, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "fonts/Bold.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(22);
	this->addChild(name, 3);


	auto textA_item = MenuItemImage::create(
		"MiniGameResources/ok_button.png",
		"MiniGameResources/ok_buttonpr.png",
		CC_CALLBACK_1(ExerciseFin::GoHome, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(132);
	this->addChild(text, 5);

	Singletons::getInstance()->m_insung = Singletons::getInstance()->m_insung + 8;
}

void ExerciseFin::GoHome(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);

	//log("start1 after delay");
	///*Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
	//Director::getInstance()->replaceScene(IntroSceneB::createScene());*/
	//auto scene = TransitionCrossFade::create(1.5, NextDayScene::createScene());
	//Director::getInstance()->replaceScene(scene);
	Singletons::getInstance()->day = Singletons::getInstance()->day + 1;
	Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
	Director::getInstance()->replaceScene(NextDayScene::createScene());
}
	
	

void ExerciseFin::skipspr(Ref *pSender)
{
	
}
