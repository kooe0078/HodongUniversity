#include "ContestScene.h"
#include "SimpleAudioEngine.h"
#include "ContestScene.h"
#include "chrcreateScene.h"
#include "sinngleton.h"
#include "NextDayScene.h"
//사운드 할라면 꼭 필요
using namespace CocosDenshion;
USING_NS_CC;

Scene* ContestScene::createScene()
{
    auto scene = Scene::create();
    auto layer = ContestScene::create();
    scene->addChild(layer);

    return scene;
}
//Singletons::getInstance()->score_1 = 0;
bool ContestScene::init()
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
	//listener->onTouchBegan = CC_CALLBACK_2(ContestScene::onTouchBegan, this);
	//Director::getInstance()->getEventDispatcher()->addEventListenerWithFixedPriority(listener, 1);

	//배경음악
	SimpleAudioEngine::getInstance()->playBackgroundMusic("sound/campus sound.mp3", true);

    return true;
}
void ContestScene::update(float ft)
{
	//씬 자체적으로 반복 되야하는 내용
}
void ContestScene::InitBackGround()
{
	auto sprite = Sprite::create("MiniGameResources/gongmo_back.png");
	sprite->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	this->addChild(sprite, 0);
}
void ContestScene::InitLabel()
{

}
// 인트로 선택창
void ContestScene::InitMenu()
{
	int i, num;
	srand((double)time(NULL));

	for (i = 0; i < 1; i++)
	{
		num = rand() % 7 + 1;
	}
	if (num == 1)
	{
		SimpleAudioEngine::getInstance()->playEffect("sound/win sound.mp3", false);

		Sprite* info = Sprite::create("MiniGameResources/main.png");
		info->setAnchorPoint(Point(0.5, 0));
		info->setPosition(Point(512, 260));
		info->setTag(1065);
		this->addChild(info, 4);

		auto newplay_item = MenuItemImage::create(
			"MiniGameResources/select1.png",
			"MiniGameResources/select1.png",

			CC_CALLBACK_1(ContestScene::check, this));
		newplay_item->setAnchorPoint(Point(0.5, 0.5));
		newplay_item->setPosition(Point(150, 390));

		auto newplay = Menu::create(newplay_item, NULL);
		newplay->setAnchorPoint(Point(0.5, 0.5));
		newplay->setPosition(Point(0, 0));
		newplay->setTag(4);
		this->addChild(newplay, 1);

		auto replay_item = MenuItemImage::create(
			"MiniGameResources/select2.png",
			"MiniGameResources/select2.png",

			CC_CALLBACK_1(ContestScene::check, this));
		replay_item->setAnchorPoint(Point(0.5, 0.5));
		replay_item->setPosition(Point(850, 390));

		auto replay = Menu::create(replay_item, NULL);
		replay->setAnchorPoint(Point(0.5, 0.5));
		replay->setPosition(Point(0, 0));
		replay->setTag(5);
		this->addChild(replay, 1);

		auto system_item = MenuItemImage::create(
			"MiniGameResources/select3.png",
			"MiniGameResources/select3.png",

			CC_CALLBACK_1(ContestScene::check, this));
		system_item->setAnchorPoint(Point(0.5, 0.5));
		system_item->setPosition(Point(510, 660));

		auto system = Menu::create(system_item, NULL);
		system->setAnchorPoint(Point(0.5, 0.5));
		system->setPosition(Point(0, 0));
		system->setTag(6);
		this->addChild(system, 1);

		auto fin_item = MenuItemImage::create(
			"MiniGameResources/select4.png",
			"MiniGameResources/select4.png",

			CC_CALLBACK_1(ContestScene::check, this));
		fin_item->setAnchorPoint(Point(0.5, 0.5));
		fin_item->setPosition(Point(510, 130));

		auto fin = Menu::create(fin_item, NULL);
		fin->setAnchorPoint(Point(0.5, 0.5));
		fin->setPosition(Point(0, 0));
		fin->setTag(7);

		this->addChild(fin, 1);
		auto fin_item_1 = MenuItemImage::create(
			"MiniGameResources/select5.png",
			"MiniGameResources/select5.png",

			CC_CALLBACK_1(ContestScene::check, this));
		fin_item_1->setAnchorPoint(Point(0.5, 0.5));
		fin_item_1->setPosition(Point(170, 660));

		auto fin_1 = Menu::create(fin_item_1, NULL);
		fin_1->setAnchorPoint(Point(0.5, 0.5));
		fin_1->setPosition(Point(0, 0));
		fin_1->setTag(8);
		this->addChild(fin_1, 1);

		auto fin_item_2 = MenuItemImage::create(
			"MiniGameResources/select6.png",
			"MiniGameResources/select6.png",

			CC_CALLBACK_1(ContestScene::check, this));
		fin_item_2->setAnchorPoint(Point(0.5, 0.5));
		fin_item_2->setPosition(Point(850, 130));

		auto fin_2 = Menu::create(fin_item_2, NULL);
		fin_2->setAnchorPoint(Point(0.5, 0.5));
		fin_2->setPosition(Point(0, 0));
		fin_2->setTag(9);
		this->addChild(fin_2, 1);

		auto fin_item_3 = MenuItemImage::create(
			"MiniGameResources/right_select.png",
			"MiniGameResources/right_select.png",

			CC_CALLBACK_1(ContestScene::rightcheck, this));
		fin_item_3->setAnchorPoint(Point(0.5, 0.5));
		fin_item_3->setPosition(Point(850, 660));

		auto fin_3 = Menu::create(fin_item_3, NULL);
		fin_3->setAnchorPoint(Point(0.5, 0.5));
		fin_3->setPosition(Point(0, 0));
		fin_3->setTag(10);
		this->addChild(fin_3, 1);

		auto fin_item_5 = MenuItemImage::create(
			"MiniGameResources/select7.png",
			"MiniGameResources/select7.png",

			CC_CALLBACK_1(ContestScene::check, this));
		fin_item_5->setAnchorPoint(Point(0.5, 0.5));
		fin_item_5->setPosition(Point(170, 130));

		auto fin_5 = Menu::create(fin_item_5, NULL);
		fin_5->setAnchorPoint(Point(0.5, 0.5));
		fin_5->setPosition(Point(0, 0));
		fin_5->setTag(11);
		this->addChild(fin_5, 1);
	}
	if (num == 2)
	{
		SimpleAudioEngine::getInstance()->playEffect("sound/win sound.mp3", false);

		Sprite* info = Sprite::create("gongmo_2/main2.png");
		info->setAnchorPoint(Point(0.5, 0));
		info->setPosition(Point(512, 260));
		info->setTag(1065);
		this->addChild(info, 4);

		auto newplay_item = MenuItemImage::create(
			"gongmo_2/select8.jpg",
			"gongmo_2/select8.jpg",

			CC_CALLBACK_1(ContestScene::check, this));
		newplay_item->setAnchorPoint(Point(0.5, 0.5));
		newplay_item->setPosition(Point(150, 390));

		auto newplay = Menu::create(newplay_item, NULL);
		newplay->setAnchorPoint(Point(0.5, 0.5));
		newplay->setPosition(Point(0, 0));
		newplay->setTag(4);
		this->addChild(newplay, 1);

		auto replay_item = MenuItemImage::create(
			"gongmo_2/select2.jpg",
			"gongmo_2/select2.jpg",

			CC_CALLBACK_1(ContestScene::check, this));
		replay_item->setAnchorPoint(Point(0.5, 0.5));
		replay_item->setPosition(Point(850, 390));

		auto replay = Menu::create(replay_item, NULL);
		replay->setAnchorPoint(Point(0.5, 0.5));
		replay->setPosition(Point(0, 0));
		replay->setTag(5);
		this->addChild(replay, 1);

		auto system_item = MenuItemImage::create(
			"gongmo_2/select3.jpg",
			"gongmo_2/select3.jpg",

			CC_CALLBACK_1(ContestScene::check, this));
		system_item->setAnchorPoint(Point(0.5, 0.5));
		system_item->setPosition(Point(510, 660));

		auto system = Menu::create(system_item, NULL);
		system->setAnchorPoint(Point(0.5, 0.5));
		system->setPosition(Point(0, 0));
		system->setTag(6);
		this->addChild(system, 1);

		auto fin_item = MenuItemImage::create(
			"gongmo_2/select4.jpg",
			"gongmo_2/select4.jpg",

			CC_CALLBACK_1(ContestScene::check, this));
		fin_item->setAnchorPoint(Point(0.5, 0.5));
		fin_item->setPosition(Point(510, 130));

		auto fin = Menu::create(fin_item, NULL);
		fin->setAnchorPoint(Point(0.5, 0.5));
		fin->setPosition(Point(0, 0));
		fin->setTag(7);

		this->addChild(fin, 1);
		auto fin_item_1 = MenuItemImage::create(
			"gongmo_2/select5.jpg",
			"gongmo_2/select5.jpg",

			CC_CALLBACK_1(ContestScene::check, this));
		fin_item_1->setAnchorPoint(Point(0.5, 0.5));
		fin_item_1->setPosition(Point(170, 660));

		auto fin_1 = Menu::create(fin_item_1, NULL);
		fin_1->setAnchorPoint(Point(0.5, 0.5));
		fin_1->setPosition(Point(0, 0));
		fin_1->setTag(8);
		this->addChild(fin_1, 1);

		auto fin_item_2 = MenuItemImage::create(
			"gongmo_2/select6.jpg",
			"gongmo_2/select6.jpg",

			CC_CALLBACK_1(ContestScene::check, this));
		fin_item_2->setAnchorPoint(Point(0.5, 0.5));
		fin_item_2->setPosition(Point(850, 130));

		auto fin_2 = Menu::create(fin_item_2, NULL);
		fin_2->setAnchorPoint(Point(0.5, 0.5));
		fin_2->setPosition(Point(0, 0));
		fin_2->setTag(9);
		this->addChild(fin_2, 1);

		auto fin_item_3 = MenuItemImage::create(
			"gongmo_2/select7.jpg",
			"gongmo_2/select7.jpg",

			CC_CALLBACK_1(ContestScene::check, this));
		fin_item_3->setAnchorPoint(Point(0.5, 0.5));
		fin_item_3->setPosition(Point(850, 660));

		auto fin_3 = Menu::create(fin_item_3, NULL);
		fin_3->setAnchorPoint(Point(0.5, 0.5));
		fin_3->setPosition(Point(0, 0));
		fin_3->setTag(10);
		this->addChild(fin_3, 1);

		auto fin_item_5 = MenuItemImage::create(
			"gongmo_2/right2.jpg",
			"gongmo_2/right2.jpg",

			CC_CALLBACK_1(ContestScene::rightcheck, this));
		fin_item_5->setAnchorPoint(Point(0.5, 0.5));
		fin_item_5->setPosition(Point(170, 130));

		auto fin_5 = Menu::create(fin_item_5, NULL);
		fin_5->setAnchorPoint(Point(0.5, 0.5));
		fin_5->setPosition(Point(0, 0));
		fin_5->setTag(11);
		this->addChild(fin_5, 1);
	}
	if (num == 3)
	{
		SimpleAudioEngine::getInstance()->playEffect("sound/win sound.mp3", false);

		Sprite* info = Sprite::create("gongmo_3/main3.png");
		info->setAnchorPoint(Point(0.5, 0));
		info->setPosition(Point(512, 260));
		info->setTag(1065);
		this->addChild(info, 4);

		auto newplay_item = MenuItemImage::create(
			"gongmo_3/select1.jpg",
			"gongmo_3/select1.jpg",

			CC_CALLBACK_1(ContestScene::check, this));
		newplay_item->setAnchorPoint(Point(0.5, 0.5));
		newplay_item->setPosition(Point(150, 390));

		auto newplay = Menu::create(newplay_item, NULL);
		newplay->setAnchorPoint(Point(0.5, 0.5));
		newplay->setPosition(Point(0, 0));
		newplay->setTag(4);
		this->addChild(newplay, 1);

		auto replay_item = MenuItemImage::create(
			"gongmo_3/select2.jpg",
			"gongmo_3/select2.jpg",

			CC_CALLBACK_1(ContestScene::check, this));
		replay_item->setAnchorPoint(Point(0.5, 0.5));
		replay_item->setPosition(Point(850, 390));

		auto replay = Menu::create(replay_item, NULL);
		replay->setAnchorPoint(Point(0.5, 0.5));
		replay->setPosition(Point(0, 0));
		replay->setTag(5);
		this->addChild(replay, 1);

		auto system_item = MenuItemImage::create(
			"gongmo_3/select3.jpg",
			"gongmo_3/select3.jpg",

			CC_CALLBACK_1(ContestScene::check, this));
		system_item->setAnchorPoint(Point(0.5, 0.5));
		system_item->setPosition(Point(510, 660));

		auto system = Menu::create(system_item, NULL);
		system->setAnchorPoint(Point(0.5, 0.5));
		system->setPosition(Point(0, 0));
		system->setTag(6);
		this->addChild(system, 1);

		auto fin_item = MenuItemImage::create(
			"gongmo_3/select4.jpg",
			"gongmo_3/select4.jpg",

			CC_CALLBACK_1(ContestScene::check, this));
		fin_item->setAnchorPoint(Point(0.5, 0.5));
		fin_item->setPosition(Point(510, 130));

		auto fin = Menu::create(fin_item, NULL);
		fin->setAnchorPoint(Point(0.5, 0.5));
		fin->setPosition(Point(0, 0));
		fin->setTag(7);

		this->addChild(fin, 1);
		auto fin_item_1 = MenuItemImage::create(
			"gongmo_3/select5.jpg",
			"gongmo_3/select5.jpg",

			CC_CALLBACK_1(ContestScene::check, this));
		fin_item_1->setAnchorPoint(Point(0.5, 0.5));
		fin_item_1->setPosition(Point(170, 660));

		auto fin_1 = Menu::create(fin_item_1, NULL);
		fin_1->setAnchorPoint(Point(0.5, 0.5));
		fin_1->setPosition(Point(0, 0));
		fin_1->setTag(8);
		this->addChild(fin_1, 1);

		auto fin_item_2 = MenuItemImage::create(
			"gongmo_3/select6.jpg",
			"gongmo_3/select6.jpg",

			CC_CALLBACK_1(ContestScene::check, this));
		fin_item_2->setAnchorPoint(Point(0.5, 0.5));
		fin_item_2->setPosition(Point(850, 130));

		auto fin_2 = Menu::create(fin_item_2, NULL);
		fin_2->setAnchorPoint(Point(0.5, 0.5));
		fin_2->setPosition(Point(0, 0));
		fin_2->setTag(9);
		this->addChild(fin_2, 1);

		auto fin_item_3 = MenuItemImage::create(
			"gongmo_3/select7.jpg",
			"gongmo_3/select7.jpg",

			CC_CALLBACK_1(ContestScene::check, this));
		fin_item_3->setAnchorPoint(Point(0.5, 0.5));
		fin_item_3->setPosition(Point(850, 660));

		auto fin_3 = Menu::create(fin_item_3, NULL);
		fin_3->setAnchorPoint(Point(0.5, 0.5));
		fin_3->setPosition(Point(0, 0));
		fin_3->setTag(10);
		this->addChild(fin_3, 1);

		auto fin_item_5 = MenuItemImage::create(
			"gongmo_3/right3.jpg",
			"gongmo_3/right3.jpg",

			CC_CALLBACK_1(ContestScene::rightcheck, this));
		fin_item_5->setAnchorPoint(Point(0.5, 0.5));
		fin_item_5->setPosition(Point(170, 130));

		auto fin_5 = Menu::create(fin_item_5, NULL);
		fin_5->setAnchorPoint(Point(0.5, 0.5));
		fin_5->setPosition(Point(0, 0));
		fin_5->setTag(11);
		this->addChild(fin_5, 1);
	}
	if (num == 4)
	{
		SimpleAudioEngine::getInstance()->playEffect("sound/win sound.mp3", false);

		Sprite* info = Sprite::create("gongmo_4/main4.png");
		info->setAnchorPoint(Point(0.5, 0));
		info->setPosition(Point(512, 260));
		info->setTag(1065);
		this->addChild(info, 4);

		auto newplay_item = MenuItemImage::create(
			"gongmo_4/select1.jpg",
			"gongmo_4/select1.jpg",

			CC_CALLBACK_1(ContestScene::check, this));
		newplay_item->setAnchorPoint(Point(0.5, 0.5));
		newplay_item->setPosition(Point(150, 390));

		auto newplay = Menu::create(newplay_item, NULL);
		newplay->setAnchorPoint(Point(0.5, 0.5));
		newplay->setPosition(Point(0, 0));
		newplay->setTag(4);
		this->addChild(newplay, 1);

		auto replay_item = MenuItemImage::create(
			"gongmo_4/select2.jpg",
			"gongmo_4/select2.jpg",

			CC_CALLBACK_1(ContestScene::check, this));
		replay_item->setAnchorPoint(Point(0.5, 0.5));
		replay_item->setPosition(Point(850, 390));

		auto replay = Menu::create(replay_item, NULL);
		replay->setAnchorPoint(Point(0.5, 0.5));
		replay->setPosition(Point(0, 0));
		replay->setTag(5);
		this->addChild(replay, 1);

		auto system_item = MenuItemImage::create(
			"gongmo_4/select3.jpg",
			"gongmo_4/select3.jpg",

			CC_CALLBACK_1(ContestScene::check, this));
		system_item->setAnchorPoint(Point(0.5, 0.5));
		system_item->setPosition(Point(510, 660));

		auto system = Menu::create(system_item, NULL);
		system->setAnchorPoint(Point(0.5, 0.5));
		system->setPosition(Point(0, 0));
		system->setTag(6);
		this->addChild(system, 1);

		auto fin_item = MenuItemImage::create(
			"gongmo_4/select4.jpg",
			"gongmo_4/select4.jpg",

			CC_CALLBACK_1(ContestScene::check, this));
		fin_item->setAnchorPoint(Point(0.5, 0.5));
		fin_item->setPosition(Point(510, 130));

		auto fin = Menu::create(fin_item, NULL);
		fin->setAnchorPoint(Point(0.5, 0.5));
		fin->setPosition(Point(0, 0));
		fin->setTag(7);

		this->addChild(fin, 1);
		auto fin_item_1 = MenuItemImage::create(
			"gongmo_4/right4.jpg",
			"gongmo_4/right4.jpg",

			CC_CALLBACK_1(ContestScene::rightcheck, this));
		fin_item_1->setAnchorPoint(Point(0.5, 0.5));
		fin_item_1->setPosition(Point(170, 660));

		auto fin_1 = Menu::create(fin_item_1, NULL);
		fin_1->setAnchorPoint(Point(0.5, 0.5));
		fin_1->setPosition(Point(0, 0));
		fin_1->setTag(8);
		this->addChild(fin_1, 1);

		auto fin_item_2 = MenuItemImage::create(
			"gongmo_4/select6.jpg",
			"gongmo_4/select6.jpg",

			CC_CALLBACK_1(ContestScene::check, this));
		fin_item_2->setAnchorPoint(Point(0.5, 0.5));
		fin_item_2->setPosition(Point(850, 130));

		auto fin_2 = Menu::create(fin_item_2, NULL);
		fin_2->setAnchorPoint(Point(0.5, 0.5));
		fin_2->setPosition(Point(0, 0));
		fin_2->setTag(9);
		this->addChild(fin_2, 1);

		auto fin_item_3 = MenuItemImage::create(
			"gongmo_4/select7.jpg",
			"gongmo_4/select7.jpg",

			CC_CALLBACK_1(ContestScene::check, this));
		fin_item_3->setAnchorPoint(Point(0.5, 0.5));
		fin_item_3->setPosition(Point(850, 660));

		auto fin_3 = Menu::create(fin_item_3, NULL);
		fin_3->setAnchorPoint(Point(0.5, 0.5));
		fin_3->setPosition(Point(0, 0));
		fin_3->setTag(10);
		this->addChild(fin_3, 1);

		auto fin_item_5 = MenuItemImage::create(
			"gongmo_4/select5.jpg",
			"gongmo_4/select5.jpg",

			CC_CALLBACK_1(ContestScene::check, this));
		fin_item_5->setAnchorPoint(Point(0.5, 0.5));
		fin_item_5->setPosition(Point(170, 130));

		auto fin_5 = Menu::create(fin_item_5, NULL);
		fin_5->setAnchorPoint(Point(0.5, 0.5));
		fin_5->setPosition(Point(0, 0));
		fin_5->setTag(11);
		this->addChild(fin_5, 1);
	}
	if (num == 5)
	{
		SimpleAudioEngine::getInstance()->playEffect("sound/win sound.mp3", false);

		Sprite* info = Sprite::create("gongmo_5/main5.png");
		info->setAnchorPoint(Point(0.5, 0));
		info->setPosition(Point(512, 260));
		info->setTag(1065);
		this->addChild(info, 4);

		auto newplay_item = MenuItemImage::create(
			"gongmo_5/select1.jpg",
			"gongmo_5/select1.jpg",

			CC_CALLBACK_1(ContestScene::check, this));
		newplay_item->setAnchorPoint(Point(0.5, 0.5));
		newplay_item->setPosition(Point(150, 390));

		auto newplay = Menu::create(newplay_item, NULL);
		newplay->setAnchorPoint(Point(0.5, 0.5));
		newplay->setPosition(Point(0, 0));
		newplay->setTag(4);
		this->addChild(newplay, 1);

		auto replay_item = MenuItemImage::create(
			"gongmo_5/select2.jpg",
			"gongmo_5/select2.jpg",

			CC_CALLBACK_1(ContestScene::check, this));
		replay_item->setAnchorPoint(Point(0.5, 0.5));
		replay_item->setPosition(Point(850, 390));

		auto replay = Menu::create(replay_item, NULL);
		replay->setAnchorPoint(Point(0.5, 0.5));
		replay->setPosition(Point(0, 0));
		replay->setTag(5);
		this->addChild(replay, 1);

		auto system_item = MenuItemImage::create(
			"gongmo_5/select3.jpg",
			"gongmo_5/select3.jpg",

			CC_CALLBACK_1(ContestScene::check, this));
		system_item->setAnchorPoint(Point(0.5, 0.5));
		system_item->setPosition(Point(510, 660));

		auto system = Menu::create(system_item, NULL);
		system->setAnchorPoint(Point(0.5, 0.5));
		system->setPosition(Point(0, 0));
		system->setTag(6);
		this->addChild(system, 1);

		auto fin_item = MenuItemImage::create(
			"gongmo_5/select4.jpg",
			"gongmo_5/select4.jpg",

			CC_CALLBACK_1(ContestScene::check, this));
		fin_item->setAnchorPoint(Point(0.5, 0.5));
		fin_item->setPosition(Point(510, 130));

		auto fin = Menu::create(fin_item, NULL);
		fin->setAnchorPoint(Point(0.5, 0.5));
		fin->setPosition(Point(0, 0));
		fin->setTag(7);

		this->addChild(fin, 1);
		auto fin_item_1 = MenuItemImage::create(
			"gongmo_5/select5.jpg",
			"gongmo_5/select5.jpg",

			CC_CALLBACK_1(ContestScene::check, this));
		fin_item_1->setAnchorPoint(Point(0.5, 0.5));
		fin_item_1->setPosition(Point(170, 660));

		auto fin_1 = Menu::create(fin_item_1, NULL);
		fin_1->setAnchorPoint(Point(0.5, 0.5));
		fin_1->setPosition(Point(0, 0));
		fin_1->setTag(8);
		this->addChild(fin_1, 1);

		auto fin_item_2 = MenuItemImage::create(
			"gongmo_5/right5.jpg",
			"gongmo_5/right5.jpg",

			CC_CALLBACK_1(ContestScene::rightcheck, this));
		fin_item_2->setAnchorPoint(Point(0.5, 0.5));
		fin_item_2->setPosition(Point(850, 130));

		auto fin_2 = Menu::create(fin_item_2, NULL);
		fin_2->setAnchorPoint(Point(0.5, 0.5));
		fin_2->setPosition(Point(0, 0));
		fin_2->setTag(9);
		this->addChild(fin_2, 1);

		auto fin_item_3 = MenuItemImage::create(
			"gongmo_5/select7.jpg",
			"gongmo_5/select7.jpg",

			CC_CALLBACK_1(ContestScene::check, this));
		fin_item_3->setAnchorPoint(Point(0.5, 0.5));
		fin_item_3->setPosition(Point(850, 660));

		auto fin_3 = Menu::create(fin_item_3, NULL);
		fin_3->setAnchorPoint(Point(0.5, 0.5));
		fin_3->setPosition(Point(0, 0));
		fin_3->setTag(10);
		this->addChild(fin_3, 1);

		auto fin_item_5 = MenuItemImage::create(
			"gongmo_5/select6.jpg",
			"gongmo_5/select6.jpg",

			CC_CALLBACK_1(ContestScene::check, this));
		fin_item_5->setAnchorPoint(Point(0.5, 0.5));
		fin_item_5->setPosition(Point(170, 130));

		auto fin_5 = Menu::create(fin_item_5, NULL);
		fin_5->setAnchorPoint(Point(0.5, 0.5));
		fin_5->setPosition(Point(0, 0));
		fin_5->setTag(11);
		this->addChild(fin_5, 1);
	}
	if (num == 6)
	{
		SimpleAudioEngine::getInstance()->playEffect("sound/win sound.mp3", false);

		Sprite* info = Sprite::create("gongmo_6/main6.png");
		info->setAnchorPoint(Point(0.5, 0));
		info->setPosition(Point(512, 260));
		info->setTag(1065);
		this->addChild(info, 4);

		auto newplay_item = MenuItemImage::create(
			"gongmo_6/right6.jpg",
			"gongmo_6/right6.jpg",

			CC_CALLBACK_1(ContestScene::rightcheck, this));
		newplay_item->setAnchorPoint(Point(0.5, 0.5));
		newplay_item->setPosition(Point(150, 390));

		auto newplay = Menu::create(newplay_item, NULL);
		newplay->setAnchorPoint(Point(0.5, 0.5));
		newplay->setPosition(Point(0, 0));
		newplay->setTag(4);
		this->addChild(newplay, 1);

		auto replay_item = MenuItemImage::create(
			"gongmo_6/select2.jpg",
			"gongmo_6/select2.jpg",

			CC_CALLBACK_1(ContestScene::check, this));
		replay_item->setAnchorPoint(Point(0.5, 0.5));
		replay_item->setPosition(Point(850, 390));

		auto replay = Menu::create(replay_item, NULL);
		replay->setAnchorPoint(Point(0.5, 0.5));
		replay->setPosition(Point(0, 0));
		replay->setTag(5);
		this->addChild(replay, 1);

		auto system_item = MenuItemImage::create(
			"gongmo_6/select3.jpg",
			"gongmo_6/select3.jpg",

			CC_CALLBACK_1(ContestScene::check, this));
		system_item->setAnchorPoint(Point(0.5, 0.5));
		system_item->setPosition(Point(510, 660));

		auto system = Menu::create(system_item, NULL);
		system->setAnchorPoint(Point(0.5, 0.5));
		system->setPosition(Point(0, 0));
		system->setTag(6);
		this->addChild(system, 1);

		auto fin_item = MenuItemImage::create(
			"gongmo_6/select4.jpg",
			"gongmo_6/select4.jpg",

			CC_CALLBACK_1(ContestScene::check, this));
		fin_item->setAnchorPoint(Point(0.5, 0.5));
		fin_item->setPosition(Point(510, 130));

		auto fin = Menu::create(fin_item, NULL);
		fin->setAnchorPoint(Point(0.5, 0.5));
		fin->setPosition(Point(0, 0));
		fin->setTag(7);

		this->addChild(fin, 1);
		auto fin_item_1 = MenuItemImage::create(
			"gongmo_6/select5.jpg",
			"gongmo_6/select5.jpg",

			CC_CALLBACK_1(ContestScene::check, this));
		fin_item_1->setAnchorPoint(Point(0.5, 0.5));
		fin_item_1->setPosition(Point(170, 660));

		auto fin_1 = Menu::create(fin_item_1, NULL);
		fin_1->setAnchorPoint(Point(0.5, 0.5));
		fin_1->setPosition(Point(0, 0));
		fin_1->setTag(8);
		this->addChild(fin_1, 1);

		auto fin_item_2 = MenuItemImage::create(
			"gongmo_6/select6.jpg",
			"gongmo_6/select6.jpg",

			CC_CALLBACK_1(ContestScene::check, this));
		fin_item_2->setAnchorPoint(Point(0.5, 0.5));
		fin_item_2->setPosition(Point(850, 130));

		auto fin_2 = Menu::create(fin_item_2, NULL);
		fin_2->setAnchorPoint(Point(0.5, 0.5));
		fin_2->setPosition(Point(0, 0));
		fin_2->setTag(9);
		this->addChild(fin_2, 1);

		auto fin_item_3 = MenuItemImage::create(
			"gongmo_6/select7.jpg",
			"gongmo_6/select7.jpg",

			CC_CALLBACK_1(ContestScene::check, this));
		fin_item_3->setAnchorPoint(Point(0.5, 0.5));
		fin_item_3->setPosition(Point(850, 660));

		auto fin_3 = Menu::create(fin_item_3, NULL);
		fin_3->setAnchorPoint(Point(0.5, 0.5));
		fin_3->setPosition(Point(0, 0));
		fin_3->setTag(10);
		this->addChild(fin_3, 1);

		auto fin_item_5 = MenuItemImage::create(
			"gongmo_6/select1.jpg",
			"gongmo_6/select1.jpg",

			CC_CALLBACK_1(ContestScene::check, this));
		fin_item_5->setAnchorPoint(Point(0.5, 0.5));
		fin_item_5->setPosition(Point(170, 130));

		auto fin_5 = Menu::create(fin_item_5, NULL);
		fin_5->setAnchorPoint(Point(0.5, 0.5));
		fin_5->setPosition(Point(0, 0));
		fin_5->setTag(11);
		this->addChild(fin_5, 1);
	}
	if (num == 7)
	{
		SimpleAudioEngine::getInstance()->playEffect("sound/win sound.mp3", false);

		Sprite* info = Sprite::create("gongmo_7/main7.png");
		info->setAnchorPoint(Point(0.5, 0));
		info->setPosition(Point(512, 260));
		info->setTag(1065);
		this->addChild(info, 4);

		auto newplay_item = MenuItemImage::create(
			"gongmo_7/select1.jpg",
			"gongmo_7/select1.jpg",

			CC_CALLBACK_1(ContestScene::check, this));
		newplay_item->setAnchorPoint(Point(0.5, 0.5));
		newplay_item->setPosition(Point(150, 390));

		auto newplay = Menu::create(newplay_item, NULL);
		newplay->setAnchorPoint(Point(0.5, 0.5));
		newplay->setPosition(Point(0, 0));
		newplay->setTag(4);
		this->addChild(newplay, 1);

		auto replay_item = MenuItemImage::create(
			"gongmo_7/select2.jpg",
			"gongmo_7/select2.jpg",

			CC_CALLBACK_1(ContestScene::check, this));
		replay_item->setAnchorPoint(Point(0.5, 0.5));
		replay_item->setPosition(Point(850, 390));

		auto replay = Menu::create(replay_item, NULL);
		replay->setAnchorPoint(Point(0.5, 0.5));
		replay->setPosition(Point(0, 0));
		replay->setTag(5);
		this->addChild(replay, 1);

		auto system_item = MenuItemImage::create(
			"gongmo_7/select3.jpg",
			"gongmo_7/select3.jpg",

			CC_CALLBACK_1(ContestScene::check, this));
		system_item->setAnchorPoint(Point(0.5, 0.5));
		system_item->setPosition(Point(510, 660));

		auto system = Menu::create(system_item, NULL);
		system->setAnchorPoint(Point(0.5, 0.5));
		system->setPosition(Point(0, 0));
		system->setTag(6);
		this->addChild(system, 1);

		auto fin_item = MenuItemImage::create(
			"gongmo_7/select4.jpg",
			"gongmo_7/select4.jpg",

			CC_CALLBACK_1(ContestScene::check, this));
		fin_item->setAnchorPoint(Point(0.5, 0.5));
		fin_item->setPosition(Point(510, 130));

		auto fin = Menu::create(fin_item, NULL);
		fin->setAnchorPoint(Point(0.5, 0.5));
		fin->setPosition(Point(0, 0));
		fin->setTag(7);

		this->addChild(fin, 1);
		auto fin_item_1 = MenuItemImage::create(
			"gongmo_7/select5.jpg",
			"gongmo_7/select5.jpg",

			CC_CALLBACK_1(ContestScene::check, this));
		fin_item_1->setAnchorPoint(Point(0.5, 0.5));
		fin_item_1->setPosition(Point(170, 660));

		auto fin_1 = Menu::create(fin_item_1, NULL);
		fin_1->setAnchorPoint(Point(0.5, 0.5));
		fin_1->setPosition(Point(0, 0));
		fin_1->setTag(8);
		this->addChild(fin_1, 1);

		auto fin_item_2 = MenuItemImage::create(
			"gongmo_7/select6.jpg",
			"gongmo_7/select6.jpg",

			CC_CALLBACK_1(ContestScene::check, this));
		fin_item_2->setAnchorPoint(Point(0.5, 0.5));
		fin_item_2->setPosition(Point(850, 130));

		auto fin_2 = Menu::create(fin_item_2, NULL);
		fin_2->setAnchorPoint(Point(0.5, 0.5));
		fin_2->setPosition(Point(0, 0));
		fin_2->setTag(9);
		this->addChild(fin_2, 1);

		auto fin_item_3 = MenuItemImage::create(
			"gongmo_7/select7.jpg",
			"gongmo_7/select7.jpg",

			CC_CALLBACK_1(ContestScene::check, this));
		fin_item_3->setAnchorPoint(Point(0.5, 0.5));
		fin_item_3->setPosition(Point(850, 660));

		auto fin_3 = Menu::create(fin_item_3, NULL);
		fin_3->setAnchorPoint(Point(0.5, 0.5));
		fin_3->setPosition(Point(0, 0));
		fin_3->setTag(10);
		this->addChild(fin_3, 1);

		auto fin_item_5 = MenuItemImage::create(
			"gongmo_7/right6.jpg",
			"gongmo_7/right6.jpg",

			CC_CALLBACK_1(ContestScene::rightcheck, this));
		fin_item_5->setAnchorPoint(Point(0.5, 0.5));
		fin_item_5->setPosition(Point(170, 130));

		auto fin_5 = Menu::create(fin_item_5, NULL);
		fin_5->setAnchorPoint(Point(0.5, 0.5));
		fin_5->setPosition(Point(0, 0));
		fin_5->setTag(11);
		this->addChild(fin_5, 1);
	}
}
	//정답체크
	void ContestScene::rightcheck(Ref *pSender)
	{
		SimpleAudioEngine::getInstance()->playEffect("sound/win sound.mp3", false);

		if (open == false) {

			open = true;

			char MyString[50];
			WideCharToMultiByte(CP_UTF8, 0, L"선택하시겠습니까?", -1, MyString, 50, NULL, NULL);
			auto name = Label::createWithTTF(MyString, "fonts/ABC.ttf", 25);
			name->setAnchorPoint(Point(0, 1));
			name->setPosition(Point(420, 525));
			name->setColor(Color3B::BLACK);
			name->setTag(164);
			this->addChild(name, 5);


			Sprite* info = Sprite::create("MiniGameResources/UI_gongentro.png");
			info->setAnchorPoint(Point(0.5, 0));
			info->setPosition(Point(512, 410));
			info->setTag(165);
			this->addChild(info, 4);

			auto action_item = MenuItemImage::create(
				"MiniGameResources/UI_enter.png",
				"MiniGameResources/UI_enterpr.png",
				// 임시 
				CC_CALLBACK_1(ContestScene::rightsystem, this));
			action_item->setPosition(Point(0, 0));

			auto play = Menu::create(action_item, NULL);
			play->setAnchorPoint(Point(0.5, 0.5));
			play->setPosition(Point(452, 455));
			play->setTag(166);
			this->addChild(play, 5);

			auto action_item3 = MenuItemImage::create(
				"MiniGameResources/UI_no.png",
				"MiniGameResources/UI_nopr.png",
				// 임시 
				CC_CALLBACK_1(ContestScene::cancelspr, this));
			action_item3->setPosition(Point(0, 0));

			auto playC = Menu::create(action_item3, NULL);
			playC->setAnchorPoint(Point(0.5, 0.5));
			playC->setPosition(Point(572, 455));
			playC->setTag(167);
			this->addChild(playC, 5);
		}
		else if (open == true)
		{
			removeChildByTag(164);
			removeChildByTag(165);
			removeChildByTag(166);
			removeChildByTag(167);
			open = false;
		}

	}

	void ContestScene::rightsystem(Ref *pSender)
	{
		SimpleAudioEngine::getInstance()->playEffect("sound/win sound.mp3", false);

		auto sprite = Sprite::create("MiniGameResources/allblack.png");
		sprite->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
		this->addChild(sprite, 0);
		removeChildByTag(4);
		removeChildByTag(5);
		removeChildByTag(6);
		removeChildByTag(7);
		removeChildByTag(8);
		removeChildByTag(9);
		removeChildByTag(10);
		removeChildByTag(11);

		removeChildByTag(164);
		removeChildByTag(165);
		removeChildByTag(166);
		removeChildByTag(167);
		removeChildByTag(1065);
		Sprite* info = Sprite::create("MiniGameResources/UI_gongmo.png");
		info->setAnchorPoint(Point(0.5, 0));
		info->setPosition(Point(512, 110));
		info->setTag(160);
		this->addChild(info, 2);

		int i;

		///
		if (Singletons::getInstance()->gonmonum == 1)
		{
			//player_1 능력치(1~299)
			srand((double)time(NULL));
			for (i = 0; i < 1; i++)
			{
				Singletons::getInstance()->score_1 = rand() % 299 + 1;

			}

			//player_2 능력치(1~299)
			for (i = 0; i < 1; i++)
			{
				Singletons::getInstance()->score_2 = rand() % 299 + 1;
			}

			//player_3 능력치(1~299)
			for (i = 0; i < 1; i++)
			{
				Singletons::getInstance()->score_3 = rand() % 299 + 1;
			}

			//player_4 능력치(1~299)
			for (i = 0; i < 1; i++)
			{
				Singletons::getInstance()->score_4 = rand() % 299 + 1;
			}
		}

		if (Singletons::getInstance()->gonmonum == 2)
		{
			//player_1 능력치(1~299)
			srand((double)time(NULL));
			for (i = 0; i < 1; i++)
			{
				Singletons::getInstance()->score_1 = rand() % 699 + 1;

			}

			//player_2 능력치(1~299)
			for (i = 0; i < 1; i++)
			{
				Singletons::getInstance()->score_2 = rand() % 699 + 1;
			}

			//player_3 능력치(1~299)
			for (i = 0; i < 1; i++)
			{
				Singletons::getInstance()->score_3 = rand() % 699 + 1;
			}

			//player_4 능력치(1~299)
			for (i = 0; i < 1; i++)
			{
				Singletons::getInstance()->score_4 = rand() % 699 + 1;
			}

		}

		if (Singletons::getInstance()->gonmonum == 3)
		{
			//player_1 능력치(1~299)
			srand((double)time(NULL));
			for (i = 0; i < 1; i++)
			{
				Singletons::getInstance()->score_1 = rand() % 1199 + 1;

			}

			//player_2 능력치(1~299)
			for (i = 0; i < 1; i++)
			{
				Singletons::getInstance()->score_2 = rand() % 1199 + 1;
			}

			//player_3 능력치(1~299)
			for (i = 0; i < 1; i++)
			{
				Singletons::getInstance()->score_3 = rand() % 1199 + 1;
			}

			//player_4 능력치(1~299)
			for (i = 0; i < 1; i++)
			{
				Singletons::getInstance()->score_4 = rand() % 1199 + 1;
			}
		}

	
		//다음
		auto action_item = MenuItemImage::create(
			"MiniGameResources/ok_button.png",
			"MiniGameResources/ok_buttonpr.png",
			// 임시 
			CC_CALLBACK_1(ContestScene::scorestage, this));
		action_item->setPosition(Point(0, 0));

		auto Study = Menu::create(action_item, NULL);
		Study->setAnchorPoint(Point(0.5, 0.5));
		Study->setPosition(Point(680, 160));
		Study->setTag(8);
		this->addChild(Study, 3);

		//호동이점수
		Singletons::getInstance()->hodongscore = (Singletons::getInstance()->m_jisik + Singletons::getInstance()->m_hak)*1.3;
		Label* score_0 = Label::createWithTTF(StringUtils::format(""), "MiniGameResources/CuteFont.ttf", 48);
		score_0->setAnchorPoint(Point(0.5, 0));
		score_0->setPosition(Point(520, 625));
		score_0->setColor(Color3B::BLACK);
		score_0->setTag(76);
		this->addChild(score_0, 7);

		Label* label0 = (Label*)this->getChildByTag(76);
		label0->setString(StringUtils::format("%d", Singletons::getInstance()->hodongscore));


		char MyString_0[50];
		WideCharToMultiByte(CP_UTF8, 0, L"호동: ", -1, MyString_0, 50, NULL, NULL);
		auto name_0 = Label::createWithTTF(MyString_0, "fonts/ABC.ttf", 25);
		name_0->setAnchorPoint(Point(0.5, 0.5));
		name_0->setPosition(Point(370, 650));
		name_0->setColor(Color3B::BLACK);
		name_0->setTag(51);
		this->addChild(name_0, 7);

		//player1점수
		char MyString[50];
		WideCharToMultiByte(CP_UTF8, 0, L"학생1: ", -1, MyString, 50, NULL, NULL);
		auto name = Label::createWithTTF(MyString, "fonts/ABC.ttf", 25);
		name->setAnchorPoint(Point(0.5, 0.5));
		name->setPosition(Point(370, 550));
		name->setColor(Color3B::BLACK);
		name->setTag(52);
		this->addChild(name, 7);

		Label* score_1 = Label::createWithTTF(StringUtils::format(""), "MiniGameResources/CuteFont.ttf", 48);
		score_1->setAnchorPoint(Point(0.5, 0));
		score_1->setPosition(Point(520, 525));
		score_1->setColor(Color3B::BLACK);
		score_1->setTag(77);
		this->addChild(score_1, 7);

		Label* label3 = (Label*)this->getChildByTag(77);
		label3->setString(StringUtils::format("%d", Singletons::getInstance()->score_1));

		//player2점수
		char MyString_2[50];
		WideCharToMultiByte(CP_UTF8, 0, L"학생2: ", -1, MyString_2, 50, NULL, NULL);
		auto name_2 = Label::createWithTTF(MyString_2, "fonts/ABC.ttf", 25);
		name_2->setAnchorPoint(Point(0.5, 0.5));
		name_2->setPosition(Point(370, 450));
		name_2->setColor(Color3B::BLACK);
		name_2->setTag(53);
		this->addChild(name_2, 7);

		Label* score_2 = Label::createWithTTF(StringUtils::format(""), "MiniGameResources/CuteFont.ttf", 48);
		score_2->setAnchorPoint(Point(0.5, 0));
		score_2->setPosition(Point(520, 425));
		score_2->setColor(Color3B::BLACK);
		score_2->setTag(78);
		this->addChild(score_2, 7);

		Label* label2 = (Label*)this->getChildByTag(78);
		label2->setString(StringUtils::format("%d", Singletons::getInstance()->score_2));

		//player3점수
		char MyString_3[50];
		WideCharToMultiByte(CP_UTF8, 0, L"학생3: ", -1, MyString_3, 50, NULL, NULL);
		auto name_3 = Label::createWithTTF(MyString_3, "fonts/ABC.ttf", 25);
		name_3->setAnchorPoint(Point(0.5, 0.5));
		name_3->setPosition(Point(370, 350));
		name_3->setColor(Color3B::BLACK);
		name_3->setTag(54);
		this->addChild(name_3, 4);

		Label* score_3 = Label::createWithTTF(StringUtils::format(""), "MiniGameResources/CuteFont.ttf", 48);
		score_3->setAnchorPoint(Point(0.5, 0));
		score_3->setPosition(Point(520, 325));
		score_3->setColor(Color3B::BLACK);
		score_3->setTag(79);
		this->addChild(score_3, 7);

		Label* label1 = (Label*)this->getChildByTag(79);
		label1->setString(StringUtils::format("%d", Singletons::getInstance()->score_3));

		//player4점수
		char MyString_4[50];
		WideCharToMultiByte(CP_UTF8, 0, L"학생4: ", -1, MyString_4, 50, NULL, NULL);
		auto name_4 = Label::createWithTTF(MyString_4, "fonts/ABC.ttf", 25);
		name_4->setAnchorPoint(Point(0.5, 0.5));
		name_4->setPosition(Point(370, 250));
		name_4->setColor(Color3B::BLACK);
		name_4->setTag(55);
		this->addChild(name_4, 4);

		Label* score_4 = Label::createWithTTF(StringUtils::format(""), "MiniGameResources/CuteFont.ttf", 48);
		score_4->setAnchorPoint(Point(0.5, 0));
		score_4->setPosition(Point(520, 225));
		score_4->setColor(Color3B::BLACK);
		score_4->setTag(80);
		this->addChild(score_4, 7);

		Label* label4 = (Label*)this->getChildByTag(80);
		label4->setString(StringUtils::format("%d", Singletons::getInstance()->score_4));


	}
	//틀린답 체크
void ContestScene::check(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/win sound.mp3", false);

	if (open == false) {

		open = true;

		char MyString[50];
		WideCharToMultiByte(CP_UTF8, 0, L"선택하시겠습니까?", -1, MyString, 50, NULL, NULL);
		auto name = Label::createWithTTF(MyString, "fonts/ABC.ttf", 25);
		name->setAnchorPoint(Point(0, 1));
		name->setPosition(Point(420, 525));
		name->setColor(Color3B::BLACK);
		name->setTag(164);
		this->addChild(name, 5);


		Sprite* info = Sprite::create("MiniGameResources/UI_gongentro.png");
		info->setAnchorPoint(Point(0.5, 0));
		info->setPosition(Point(512, 410));
		info->setTag(165);
		this->addChild(info, 4);

		auto action_item = MenuItemImage::create(
			"MiniGameResources/UI_enter.png",
			"MiniGameResources/UI_enterpr.png",
			// 임시 
			CC_CALLBACK_1(ContestScene::system, this));
		action_item->setPosition(Point(0, 0));

		auto play = Menu::create(action_item, NULL);
		play->setAnchorPoint(Point(0.5, 0.5));
		play->setPosition(Point(452, 455));
		play->setTag(166);
		this->addChild(play, 5);

		auto action_item3 = MenuItemImage::create(
			"MiniGameResources/UI_no.png",
			"MiniGameResources/UI_nopr.png",
			// 임시 
			CC_CALLBACK_1(ContestScene::cancelspr, this));
		action_item3->setPosition(Point(0, 0));

		auto playC = Menu::create(action_item3, NULL);
		playC->setAnchorPoint(Point(0.5, 0.5));
		playC->setPosition(Point(572, 455));
		playC->setTag(167);
		this->addChild(playC, 5);
	}
		else if (open == true)
		{
			removeChildByTag(164);
			removeChildByTag(165);
			removeChildByTag(166);
			removeChildByTag(167);
			open = false;
		}

}
	
void ContestScene::system(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/win sound.mp3", false);

	auto sprite = Sprite::create("MiniGameResources/allblack.png");
	sprite->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	this->addChild(sprite, 0);
	removeChildByTag(4);
	removeChildByTag(5);
	removeChildByTag(6);
	removeChildByTag(7);
	removeChildByTag(8);
	removeChildByTag(9);
	removeChildByTag(10);
	removeChildByTag(11);

	removeChildByTag(164);
	removeChildByTag(165);
	removeChildByTag(166);
	removeChildByTag(167);
	removeChildByTag(1065);
	Sprite* info = Sprite::create("MiniGameResources/UI_gongmo.png");
	info->setAnchorPoint(Point(0.5, 0));
	info->setPosition(Point(512, 110));
	info->setTag(160);
	this->addChild(info, 2);

	int i;
	
	///
	
	
	
	if (Singletons::getInstance()->gonmonum == 1)
	{
		//player_1 능력치(1~299)
		srand((double)time(NULL));
		for (i = 0; i < 1; i++)
		{
			Singletons::getInstance()->score_1 = rand() % 299 + 1;

		}

		//player_2 능력치(1~299)
		for (i = 0; i < 1; i++)
		{
			Singletons::getInstance()->score_2 = rand() % 299 + 1;
		}

		//player_3 능력치(1~299)
		for (i = 0; i < 1; i++)
		{
			Singletons::getInstance()->score_3 = rand() % 299 + 1;
		}

		//player_4 능력치(1~299)
		for (i = 0; i < 1; i++)
		{
			Singletons::getInstance()->score_4 = rand() % 299 + 1;
		}
	}

	if (Singletons::getInstance()->gonmonum == 2)
	{
		//player_1 능력치(1~299)
		srand((double)time(NULL));
		for (i = 0; i < 1; i++)
		{
			Singletons::getInstance()->score_1 = rand() % 699 + 1;

		}

		//player_2 능력치(1~299)
		for (i = 0; i < 1; i++)
		{
			Singletons::getInstance()->score_2 = rand() % 699 + 1;
		}

		//player_3 능력치(1~299)
		for (i = 0; i < 1; i++)
		{
			Singletons::getInstance()->score_3 = rand() % 699 + 1;
		}

		//player_4 능력치(1~299)
		for (i = 0; i < 1; i++)
		{
			Singletons::getInstance()->score_4 = rand() % 699 + 1;
		}

	}

	if (Singletons::getInstance()->gonmonum == 3)
	{
		//player_1 능력치(1~299)
		srand((double)time(NULL));
		for (i = 0; i < 1; i++)
		{
			Singletons::getInstance()->score_1 = rand() % 1199 + 1;

		}

		//player_2 능력치(1~299)
		for (i = 0; i < 1; i++)
		{
			Singletons::getInstance()->score_2 = rand() % 1199 + 1;
		}

		//player_3 능력치(1~299)
		for (i = 0; i < 1; i++)
		{
			Singletons::getInstance()->score_3 = rand() % 1199 + 1;
		}

		//player_4 능력치(1~299)
		for (i = 0; i < 1; i++)
		{
			Singletons::getInstance()->score_4 = rand() % 1199 + 1;
		}
	}

	
	//다음
	auto action_item = MenuItemImage::create(
		"MiniGameResources/ok_button.png",
		"MiniGameResources/ok_buttonpr.png",
		// 임시 
		CC_CALLBACK_1(ContestScene::scorestage, this));
	action_item->setPosition(Point(0, 0));

	auto Study = Menu::create(action_item, NULL);
	Study->setAnchorPoint(Point(0.5, 0.5));
	Study->setPosition(Point(680, 160));
	Study->setTag(8);
	this->addChild(Study, 3);
	
	//호동이점수
	Singletons::getInstance()->hodongscore = Singletons::getInstance()->m_jisik + Singletons::getInstance()->m_hak;
	Label* score_0 = Label::createWithTTF(StringUtils::format(""), "MiniGameResources/CuteFont.ttf", 48);
	score_0->setAnchorPoint(Point(0.5, 0));
	score_0->setPosition(Point(520, 625));
	score_0->setColor(Color3B::BLACK);
	score_0->setTag(76);
	this->addChild(score_0, 7);

	Label* label0 = (Label*)this->getChildByTag(76);
	label0->setString(StringUtils::format("%d", Singletons::getInstance()->hodongscore));


	char MyString_0[50];
	WideCharToMultiByte(CP_UTF8, 0, L"호동: ", -1, MyString_0, 50, NULL, NULL);
	auto name_0 = Label::createWithTTF(MyString_0, "fonts/ABC.ttf", 25);
	name_0->setAnchorPoint(Point(0.5, 0.5));
	name_0->setPosition(Point(370, 650));
	name_0->setColor(Color3B::BLACK);
	name_0->setTag(51);
	this->addChild(name_0, 7);

	//player1점수
	char MyString[50];
	WideCharToMultiByte(CP_UTF8, 0, L"학생1: ", -1, MyString, 50, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "fonts/ABC.ttf", 25);
	name->setAnchorPoint(Point(0.5, 0.5));
	name->setPosition(Point(370, 550));
	name->setColor(Color3B::BLACK);
	name->setTag(52);
	this->addChild(name, 7);

	Label* score_1 = Label::createWithTTF(StringUtils::format(""), "MiniGameResources/CuteFont.ttf", 48);
	score_1->setAnchorPoint(Point(0.5, 0));
	score_1->setPosition(Point(520, 525));
	score_1->setColor(Color3B::BLACK);
	score_1->setTag(77);
	this->addChild(score_1, 7);

	Label* label3 = (Label*)this->getChildByTag(77);
	label3->setString(StringUtils::format("%d", Singletons::getInstance()->score_1));

	//player2점수
	char MyString_2[50];
	WideCharToMultiByte(CP_UTF8, 0, L"학생2: ", -1, MyString_2, 50, NULL, NULL);
	auto name_2 = Label::createWithTTF(MyString_2, "fonts/ABC.ttf", 25);
	name_2->setAnchorPoint(Point(0.5, 0.5));
	name_2->setPosition(Point(370, 450));
	name_2->setColor(Color3B::BLACK);
	name_2->setTag(53);
	this->addChild(name_2, 7);

	Label* score_2 = Label::createWithTTF(StringUtils::format(""), "MiniGameResources/CuteFont.ttf", 48);
	score_2->setAnchorPoint(Point(0.5, 0));
	score_2->setPosition(Point(520, 425));
	score_2->setColor(Color3B::BLACK);
	score_2->setTag(78);
	this->addChild(score_2, 7);

	Label* label2 = (Label*)this->getChildByTag(78);
	label2->setString(StringUtils::format("%d", Singletons::getInstance()->score_2));

	//player3점수
	char MyString_3[50];
	WideCharToMultiByte(CP_UTF8, 0, L"학생3: ", -1, MyString_3, 50, NULL, NULL);
	auto name_3 = Label::createWithTTF(MyString_3, "fonts/ABC.ttf", 25);
	name_3->setAnchorPoint(Point(0.5, 0.5));
	name_3->setPosition(Point(370, 350));
	name_3->setColor(Color3B::BLACK);
	name_3->setTag(54);
	this->addChild(name_3, 4);

	Label* score_3 = Label::createWithTTF(StringUtils::format(""), "MiniGameResources/CuteFont.ttf", 48);
	score_3->setAnchorPoint(Point(0.5, 0));
	score_3->setPosition(Point(520, 325));
	score_3->setColor(Color3B::BLACK);
	score_3->setTag(79);
	this->addChild(score_3, 7);

	Label* label1 = (Label*)this->getChildByTag(79);
	label1->setString(StringUtils::format("%d", Singletons::getInstance()->score_3));

	//player4점수
	char MyString_4[50];
	WideCharToMultiByte(CP_UTF8, 0, L"학생4: ", -1, MyString_4, 50, NULL, NULL);
	auto name_4 = Label::createWithTTF(MyString_4, "fonts/ABC.ttf", 25);
	name_4->setAnchorPoint(Point(0.5, 0.5));
	name_4->setPosition(Point(370, 250));
	name_4->setColor(Color3B::BLACK);
	name_4->setTag(55);
	this->addChild(name_4, 4);

	Label* score_4 = Label::createWithTTF(StringUtils::format(""), "MiniGameResources/CuteFont.ttf", 48);
	score_4->setAnchorPoint(Point(0.5, 0));
	score_4->setPosition(Point(520, 225));
	score_4->setColor(Color3B::BLACK);
	score_4->setTag(80);
	this->addChild(score_4, 7);

	Label* label4 = (Label*)this->getChildByTag(80);
	label4->setString(StringUtils::format("%d", Singletons::getInstance()->score_4));


	//Singletons::getInstance()->money = Singletons::getInstance()->money - 50000;

}
void ContestScene::scorestage(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/win sound.mp3", false);
	removeChildByTag(8);
	int arr[5] = { Singletons::getInstance()->hodongscore ,
		Singletons::getInstance()->score_1,
		Singletons::getInstance()->score_2,
		Singletons::getInstance()->score_3,
		Singletons::getInstance()->score_4 };

	int  j, tmp;
	for (Singletons::getInstance()->si = 0; Singletons::getInstance()->si < 5; Singletons::getInstance()->si++)
	{
		for (j = 0; j < 4; j++)
		{
			if (arr[j] < arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}

	for (Singletons::getInstance()->si = 0; Singletons::getInstance()->si <= 5; Singletons::getInstance()->si++)
	{
		if (Singletons::getInstance()->hodongscore > arr[Singletons::getInstance()->si])
		{
			//보상받기
			auto action_item = MenuItemImage::create(
				"MiniGameResources/UI_bosang.png",
				"MiniGameResources/UI_bosangpr.png",
				// 임시 
				CC_CALLBACK_1(ContestScene::bosang, this));
			action_item->setPosition(Point(0, 0));

			auto Study = Menu::create(action_item, NULL);
			Study->setAnchorPoint(Point(0.5, 0.5));
			Study->setPosition(Point(630, 60));
			Study->setTag(8);
			this->addChild(Study, 3);

			if (Singletons::getInstance()->hodongscore == Singletons::getInstance()->score_1)
			{
				Singletons::getInstance()->si = Singletons::getInstance()->si - 1;
			}

			if (Singletons::getInstance()->hodongscore == Singletons::getInstance()->score_2)
			{
				Singletons::getInstance()->si = Singletons::getInstance()->si - 1;
			}

			if (Singletons::getInstance()->hodongscore == Singletons::getInstance()->score_3)
			{
				Singletons::getInstance()->si = Singletons::getInstance()->si - 1;
			}

			if (Singletons::getInstance()->hodongscore == Singletons::getInstance()->score_4)
			{
				Singletons::getInstance()->si = Singletons::getInstance()->si - 1;
			}

			//등수출력
			char MyString[50];
			WideCharToMultiByte(CP_UTF8, 0, L"등입니다. ", -1, MyString, 50, NULL, NULL);
			auto name = Label::createWithTTF(MyString, "fonts/ABC.ttf", 40);
			name->setAnchorPoint(Point(0.5, 0));
			name->setPosition(Point(480, 45));
			name->setColor(Color3B::WHITE);
			name->setTag(50);
			this->addChild(name, 4);

			Label* score_h = Label::createWithTTF(StringUtils::format("%d", Singletons::getInstance()->si ), "MiniGameResources/CuteFont.ttf", 70);
			score_h->setAnchorPoint(Point(0.5, 0));
			score_h->setPosition(Point(370, 25));
			score_h->setColor(Color3B::WHITE);
			score_h->setTag(100);
			this->addChild(score_h, 4);
			return;
		}
	}
	

	//Label* label1_h = (Label*)this->getChildByTag(100);
	//label1_h->setString(StringUtils::format("%d", si));
}
void ContestScene::bosang(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/money sound.mp3", false);

	auto sprite = Sprite::create("MiniGameResources/Main_Scene.png");
	sprite->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	this->addChild(sprite, 0);

	if (Singletons::getInstance()->si == 1)
	{
		if (Singletons::getInstance()->gonmonum == 1)
		{
			//메인캐릭터
			Sprite* mainchr = Sprite::create("MiniGameResources/main_char.png");
			mainchr->setAnchorPoint(Point(0.5, 0));
			mainchr->setPosition(Point(120, 80));
			mainchr->setTag(166);
			this->addChild(mainchr, 1);

			auto storyA_item = MenuItemImage::create(
				"MiniGameResources/UI_Textlblack.png",
				"MiniGameResources/UI_Textlblack.png",

				CC_CALLBACK_1(ContestScene::replayspr, this));
			storyA_item->setAnchorPoint(Point(0.5, 0.5));
			storyA_item->setPosition(Point(510, 100));

			auto storyA = Menu::create(storyA_item, NULL);
			storyA->setAnchorPoint(Point(0.5, 0.5));
			storyA->setPosition(Point(0, 0));
			storyA->setTag(4);
			this->addChild(storyA, 1);

			char MyString[200];
			WideCharToMultiByte(CP_UTF8, 0, L"크핫! 바로 이거지~\n\n(200000원을 획득하였습니다.)", -1, MyString, 200, NULL, NULL);
			auto name = Label::createWithTTF(MyString, "fonts/Bold.ttf", 30);
			name->setAnchorPoint(Point(0, 1));
			name->setPosition(Point(40, 150));
			name->setColor(Color3B::WHITE);
			name->setTag(20);
			this->addChild(name, 3);

			auto textA_item = MenuItemImage::create(
				"MiniGameResources/ok_button.png",
				"MiniGameResources/ok_buttonpr.png",
				CC_CALLBACK_1(ContestScene::Nextday, this));
			textA_item->setAnchorPoint(Point(0.5, 0.5));
			textA_item->setPosition(Point(950, 65));

			auto text = Menu::create(textA_item, NULL);
			text->setAnchorPoint(Point(0.5, 0.5));
			text->setPosition(Point(0, 0));
			text->setTag(136);
			this->addChild(text, 5);


			Singletons::getInstance()->money = Singletons::getInstance()->money + 200000;
		}

		if (Singletons::getInstance()->gonmonum == 2)
		{
			//메인캐릭터
			Sprite* mainchr = Sprite::create("MiniGameResources/main_char.png");
			mainchr->setAnchorPoint(Point(0.5, 0));
			mainchr->setPosition(Point(120, 80));
			mainchr->setTag(166);
			this->addChild(mainchr, 1);

			auto storyA_item = MenuItemImage::create(
				"MiniGameResources/UI_Textlblack.png",
				"MiniGameResources/UI_Textlblack.png",

				CC_CALLBACK_1(ContestScene::replayspr, this));
			storyA_item->setAnchorPoint(Point(0.5, 0.5));
			storyA_item->setPosition(Point(510, 100));

			auto storyA = Menu::create(storyA_item, NULL);
			storyA->setAnchorPoint(Point(0.5, 0.5));
			storyA->setPosition(Point(0, 0));
			storyA->setTag(4);
			this->addChild(storyA, 1);

			char MyString[200];
			WideCharToMultiByte(CP_UTF8, 0, L"크핫! 바로 이거지~\n\n(300000원을 획득하였습니다.)", -1, MyString, 200, NULL, NULL);
			auto name = Label::createWithTTF(MyString, "fonts/Bold.ttf", 30);
			name->setAnchorPoint(Point(0, 1));
			name->setPosition(Point(40, 150));
			name->setColor(Color3B::WHITE);
			name->setTag(20);
			this->addChild(name, 3);

			auto textA_item = MenuItemImage::create(
				"MiniGameResources/ok_button.png",
				"MiniGameResources/ok_buttonpr.png",
				CC_CALLBACK_1(ContestScene::Nextday, this));
			textA_item->setAnchorPoint(Point(0.5, 0.5));
			textA_item->setPosition(Point(950, 65));

			auto text = Menu::create(textA_item, NULL);
			text->setAnchorPoint(Point(0.5, 0.5));
			text->setPosition(Point(0, 0));
			text->setTag(136);
			this->addChild(text, 5);


			Singletons::getInstance()->money = Singletons::getInstance()->money + 300000;
		}

		if (Singletons::getInstance()->gonmonum == 3)
		{
			//메인캐릭터
			Sprite* mainchr = Sprite::create("MiniGameResources/main_char.png");
			mainchr->setAnchorPoint(Point(0.5, 0));
			mainchr->setPosition(Point(120, 80));
			mainchr->setTag(166);
			this->addChild(mainchr, 1);

			auto storyA_item = MenuItemImage::create(
				"MiniGameResources/UI_Textlblack.png",
				"MiniGameResources/UI_Textlblack.png",

				CC_CALLBACK_1(ContestScene::replayspr, this));
			storyA_item->setAnchorPoint(Point(0.5, 0.5));
			storyA_item->setPosition(Point(510, 100));

			auto storyA = Menu::create(storyA_item, NULL);
			storyA->setAnchorPoint(Point(0.5, 0.5));
			storyA->setPosition(Point(0, 0));
			storyA->setTag(4);
			this->addChild(storyA, 1);

			char MyString[200];
			WideCharToMultiByte(CP_UTF8, 0, L"크핫! 바로 이거지~\n\n(1000000원을 획득하였습니다.)", -1, MyString, 200, NULL, NULL);
			auto name = Label::createWithTTF(MyString, "fonts/Bold.ttf", 30);
			name->setAnchorPoint(Point(0, 1));
			name->setPosition(Point(40, 150));
			name->setColor(Color3B::WHITE);
			name->setTag(20);
			this->addChild(name, 3);

			auto textA_item = MenuItemImage::create(
				"MiniGameResources/ok_button.png",
				"MiniGameResources/ok_buttonpr.png",
				CC_CALLBACK_1(ContestScene::Nextday, this));
			textA_item->setAnchorPoint(Point(0.5, 0.5));
			textA_item->setPosition(Point(950, 65));

			auto text = Menu::create(textA_item, NULL);
			text->setAnchorPoint(Point(0.5, 0.5));
			text->setPosition(Point(0, 0));
			text->setTag(136);
			this->addChild(text, 5);


			Singletons::getInstance()->money = Singletons::getInstance()->money + 1000000;
		}
		Singletons::getInstance()->gonmonum = 0;
	}
	if (Singletons::getInstance()->si == 2)
	{
		if (Singletons::getInstance()->gonmonum == 1)
		{
			//메인캐릭터
			Sprite* mainchr = Sprite::create("MiniGameResources/main_char.png");
			mainchr->setAnchorPoint(Point(0.5, 0));
			mainchr->setPosition(Point(120, 80));
			mainchr->setTag(166);
			this->addChild(mainchr, 1);

			auto storyA_item = MenuItemImage::create(
				"MiniGameResources/UI_Textlblack.png",
				"MiniGameResources/UI_Textlblack.png",

				CC_CALLBACK_1(ContestScene::replayspr, this));
			storyA_item->setAnchorPoint(Point(0.5, 0.5));
			storyA_item->setPosition(Point(510, 100));

			auto storyA = Menu::create(storyA_item, NULL);
			storyA->setAnchorPoint(Point(0.5, 0.5));
			storyA->setPosition(Point(0, 0));
			storyA->setTag(4);
			this->addChild(storyA, 1);

			char MyString[200];
			WideCharToMultiByte(CP_UTF8, 0, L"이정도면 만족할만하지~\n\n(100000원을 획득하였습니다.)", -1, MyString, 200, NULL, NULL);
			auto name = Label::createWithTTF(MyString, "fonts/Bold.ttf", 30);
			name->setAnchorPoint(Point(0, 1));
			name->setPosition(Point(40, 150));
			name->setColor(Color3B::WHITE);
			name->setTag(20);
			this->addChild(name, 3);

			auto textA_item = MenuItemImage::create(
				"MiniGameResources/ok_button.png",
				"MiniGameResources/ok_buttonpr.png",
				CC_CALLBACK_1(ContestScene::Nextday, this));
			textA_item->setAnchorPoint(Point(0.5, 0.5));
			textA_item->setPosition(Point(950, 65));

			auto text = Menu::create(textA_item, NULL);
			text->setAnchorPoint(Point(0.5, 0.5));
			text->setPosition(Point(0, 0));
			text->setTag(136);
			this->addChild(text, 5);


			Singletons::getInstance()->money = Singletons::getInstance()->money + 100000;
		}
		if (Singletons::getInstance()->gonmonum == 2)
		{
			//메인캐릭터
			Sprite* mainchr = Sprite::create("MiniGameResources/main_char.png");
			mainchr->setAnchorPoint(Point(0.5, 0));
			mainchr->setPosition(Point(120, 80));
			mainchr->setTag(166);
			this->addChild(mainchr, 1);

			auto storyA_item = MenuItemImage::create(
				"MiniGameResources/UI_Textlblack.png",
				"MiniGameResources/UI_Textlblack.png",

				CC_CALLBACK_1(ContestScene::replayspr, this));
			storyA_item->setAnchorPoint(Point(0.5, 0.5));
			storyA_item->setPosition(Point(510, 100));

			auto storyA = Menu::create(storyA_item, NULL);
			storyA->setAnchorPoint(Point(0.5, 0.5));
			storyA->setPosition(Point(0, 0));
			storyA->setTag(4);
			this->addChild(storyA, 1);

			char MyString[200];
			WideCharToMultiByte(CP_UTF8, 0, L"이정도면 만족할만하지~\n\n(200000원을 획득하였습니다.)", -1, MyString, 200, NULL, NULL);
			auto name = Label::createWithTTF(MyString, "fonts/Bold.ttf", 30);
			name->setAnchorPoint(Point(0, 1));
			name->setPosition(Point(40, 150));
			name->setColor(Color3B::WHITE);
			name->setTag(20);
			this->addChild(name, 3);

			auto textA_item = MenuItemImage::create(
				"MiniGameResources/ok_button.png",
				"MiniGameResources/ok_buttonpr.png",
				CC_CALLBACK_1(ContestScene::Nextday, this));
			textA_item->setAnchorPoint(Point(0.5, 0.5));
			textA_item->setPosition(Point(950, 65));

			auto text = Menu::create(textA_item, NULL);
			text->setAnchorPoint(Point(0.5, 0.5));
			text->setPosition(Point(0, 0));
			text->setTag(136);
			this->addChild(text, 5);


			Singletons::getInstance()->money = Singletons::getInstance()->money + 200000;
		}
		if (Singletons::getInstance()->gonmonum == 3)
		{
			//메인캐릭터
			Sprite* mainchr = Sprite::create("MiniGameResources/main_char.png");
			mainchr->setAnchorPoint(Point(0.5, 0));
			mainchr->setPosition(Point(120, 80));
			mainchr->setTag(166);
			this->addChild(mainchr, 1);

			auto storyA_item = MenuItemImage::create(
				"MiniGameResources/UI_Textlblack.png",
				"MiniGameResources/UI_Textlblack.png",

				CC_CALLBACK_1(ContestScene::replayspr, this));
			storyA_item->setAnchorPoint(Point(0.5, 0.5));
			storyA_item->setPosition(Point(510, 100));

			auto storyA = Menu::create(storyA_item, NULL);
			storyA->setAnchorPoint(Point(0.5, 0.5));
			storyA->setPosition(Point(0, 0));
			storyA->setTag(4);
			this->addChild(storyA, 1);

			char MyString[200];
			WideCharToMultiByte(CP_UTF8, 0, L"이정도면 만족할만하지~\n\n(500000원을 획득하였습니다.)", -1, MyString, 200, NULL, NULL);
			auto name = Label::createWithTTF(MyString, "fonts/Bold.ttf", 30);
			name->setAnchorPoint(Point(0, 1));
			name->setPosition(Point(40, 150));
			name->setColor(Color3B::WHITE);
			name->setTag(20);
			this->addChild(name, 3);

			auto textA_item = MenuItemImage::create(
				"MiniGameResources/ok_button.png",
				"MiniGameResources/ok_buttonpr.png",
				CC_CALLBACK_1(ContestScene::Nextday, this));
			textA_item->setAnchorPoint(Point(0.5, 0.5));
			textA_item->setPosition(Point(950, 65));

			auto text = Menu::create(textA_item, NULL);
			text->setAnchorPoint(Point(0.5, 0.5));
			text->setPosition(Point(0, 0));
			text->setTag(136);
			this->addChild(text, 5);


			Singletons::getInstance()->money = Singletons::getInstance()->money + 500000;
		}
		Singletons::getInstance()->gonmonum = 0;
	}
	if (Singletons::getInstance()->si == 3)
	{
		if (Singletons::getInstance()->gonmonum == 1)
		{
			//메인캐릭터
			Sprite* mainchr = Sprite::create("MiniGameResources/main_char.png");
			mainchr->setAnchorPoint(Point(0.5, 0));
			mainchr->setPosition(Point(120, 80));
			mainchr->setTag(166);
			this->addChild(mainchr, 1);

			auto storyA_item = MenuItemImage::create(
				"MiniGameResources/UI_Textlblack.png",
				"MiniGameResources/UI_Textlblack.png",

				CC_CALLBACK_1(ContestScene::replayspr, this));
			storyA_item->setAnchorPoint(Point(0.5, 0.5));
			storyA_item->setPosition(Point(510, 100));

			auto storyA = Menu::create(storyA_item, NULL);
			storyA->setAnchorPoint(Point(0.5, 0.5));
			storyA->setPosition(Point(0, 0));
			storyA->setTag(4);
			this->addChild(storyA, 1);

			char MyString[200];
			WideCharToMultiByte(CP_UTF8, 0, L"애매한 성적인걸?\n\n(50000원을 획득하였습니다.)", -1, MyString, 200, NULL, NULL);
			auto name = Label::createWithTTF(MyString, "fonts/Bold.ttf", 30);
			name->setAnchorPoint(Point(0, 1));
			name->setPosition(Point(40, 150));
			name->setColor(Color3B::WHITE);
			name->setTag(20);
			this->addChild(name, 3);

			auto textA_item = MenuItemImage::create(
				"MiniGameResources/ok_button.png",
				"MiniGameResources/ok_buttonpr.png",
				CC_CALLBACK_1(ContestScene::Nextday, this));
			textA_item->setAnchorPoint(Point(0.5, 0.5));
			textA_item->setPosition(Point(950, 65));

			auto text = Menu::create(textA_item, NULL);
			text->setAnchorPoint(Point(0.5, 0.5));
			text->setPosition(Point(0, 0));
			text->setTag(136);
			this->addChild(text, 5);


			Singletons::getInstance()->money = Singletons::getInstance()->money + 50000;
		}

		if (Singletons::getInstance()->gonmonum == 2)
		{
			//메인캐릭터
			Sprite* mainchr = Sprite::create("MiniGameResources/main_char.png");
			mainchr->setAnchorPoint(Point(0.5, 0));
			mainchr->setPosition(Point(120, 80));
			mainchr->setTag(166);
			this->addChild(mainchr, 1);

			auto storyA_item = MenuItemImage::create(
				"MiniGameResources/UI_Textlblack.png",
				"MiniGameResources/UI_Textlblack.png",

				CC_CALLBACK_1(ContestScene::replayspr, this));
			storyA_item->setAnchorPoint(Point(0.5, 0.5));
			storyA_item->setPosition(Point(510, 100));

			auto storyA = Menu::create(storyA_item, NULL);
			storyA->setAnchorPoint(Point(0.5, 0.5));
			storyA->setPosition(Point(0, 0));
			storyA->setTag(4);
			this->addChild(storyA, 1);

			char MyString[200];
			WideCharToMultiByte(CP_UTF8, 0, L"애매한 성적인걸?\n\n(100000원을 획득하였습니다.)", -1, MyString, 200, NULL, NULL);
			auto name = Label::createWithTTF(MyString, "fonts/Bold.ttf", 30);
			name->setAnchorPoint(Point(0, 1));
			name->setPosition(Point(40, 150));
			name->setColor(Color3B::WHITE);
			name->setTag(20);
			this->addChild(name, 3);

			auto textA_item = MenuItemImage::create(
				"MiniGameResources/ok_button.png",
				"MiniGameResources/ok_buttonpr.png",
				CC_CALLBACK_1(ContestScene::Nextday, this));
			textA_item->setAnchorPoint(Point(0.5, 0.5));
			textA_item->setPosition(Point(950, 65));

			auto text = Menu::create(textA_item, NULL);
			text->setAnchorPoint(Point(0.5, 0.5));
			text->setPosition(Point(0, 0));
			text->setTag(136);
			this->addChild(text, 5);


			Singletons::getInstance()->money = Singletons::getInstance()->money + 100000;
		}

		if (Singletons::getInstance()->gonmonum == 3)
		{
			//메인캐릭터
			Sprite* mainchr = Sprite::create("MiniGameResources/main_char.png");
			mainchr->setAnchorPoint(Point(0.5, 0));
			mainchr->setPosition(Point(120, 80));
			mainchr->setTag(166);
			this->addChild(mainchr, 1);

			auto storyA_item = MenuItemImage::create(
				"MiniGameResources/UI_Textlblack.png",
				"MiniGameResources/UI_Textlblack.png",

				CC_CALLBACK_1(ContestScene::replayspr, this));
			storyA_item->setAnchorPoint(Point(0.5, 0.5));
			storyA_item->setPosition(Point(510, 100));

			auto storyA = Menu::create(storyA_item, NULL);
			storyA->setAnchorPoint(Point(0.5, 0.5));
			storyA->setPosition(Point(0, 0));
			storyA->setTag(4);
			this->addChild(storyA, 1);

			char MyString[200];
			WideCharToMultiByte(CP_UTF8, 0, L"애매한 성적인걸?\n\n(300000원을 획득하였습니다.)", -1, MyString, 200, NULL, NULL);
			auto name = Label::createWithTTF(MyString, "fonts/Bold.ttf", 30);
			name->setAnchorPoint(Point(0, 1));
			name->setPosition(Point(40, 150));
			name->setColor(Color3B::WHITE);
			name->setTag(20);
			this->addChild(name, 3);

			auto textA_item = MenuItemImage::create(
				"MiniGameResources/ok_button.png",
				"MiniGameResources/ok_buttonpr.png",
				CC_CALLBACK_1(ContestScene::Nextday, this));
			textA_item->setAnchorPoint(Point(0.5, 0.5));
			textA_item->setPosition(Point(950, 65));

			auto text = Menu::create(textA_item, NULL);
			text->setAnchorPoint(Point(0.5, 0.5));
			text->setPosition(Point(0, 0));
			text->setTag(136);
			this->addChild(text, 5);


			Singletons::getInstance()->money = Singletons::getInstance()->money + 300000;
		}
		Singletons::getInstance()->gonmonum = 0;
	}
	if (Singletons::getInstance()->si == 4)
	{
		if (Singletons::getInstance()->gonmonum == 1)
		{
			//메인캐릭터
			Sprite* mainchr = Sprite::create("MiniGameResources/main_char.png");
			mainchr->setAnchorPoint(Point(0.5, 0));
			mainchr->setPosition(Point(120, 80));
			mainchr->setTag(166);
			this->addChild(mainchr, 1);

			auto storyA_item = MenuItemImage::create(
				"MiniGameResources/UI_Textlblack.png",
				"MiniGameResources/UI_Textlblack.png",

				CC_CALLBACK_1(ContestScene::replayspr, this));
			storyA_item->setAnchorPoint(Point(0.5, 0.5));
			storyA_item->setPosition(Point(510, 100));

			auto storyA = Menu::create(storyA_item, NULL);
			storyA->setAnchorPoint(Point(0.5, 0.5));
			storyA->setPosition(Point(0, 0));
			storyA->setTag(4);
			this->addChild(storyA, 1);

			char MyString[200];
			WideCharToMultiByte(CP_UTF8, 0, L"좋지않아.. 많이 좋지않아..\n\n(10000원을 획득하였습니다.)", -1, MyString, 200, NULL, NULL);
			auto name = Label::createWithTTF(MyString, "fonts/Bold.ttf", 30);
			name->setAnchorPoint(Point(0, 1));
			name->setPosition(Point(40, 150));
			name->setColor(Color3B::WHITE);
			name->setTag(20);
			this->addChild(name, 3);

			auto textA_item = MenuItemImage::create(
				"MiniGameResources/ok_button.png",
				"MiniGameResources/ok_buttonpr.png",
				CC_CALLBACK_1(ContestScene::Nextday, this));
			textA_item->setAnchorPoint(Point(0.5, 0.5));
			textA_item->setPosition(Point(950, 65));

			auto text = Menu::create(textA_item, NULL);
			text->setAnchorPoint(Point(0.5, 0.5));
			text->setPosition(Point(0, 0));
			text->setTag(136);
			this->addChild(text, 5);

			Singletons::getInstance()->money = Singletons::getInstance()->money + 10000;
		}

		if (Singletons::getInstance()->gonmonum == 2)
		{
			//메인캐릭터
			Sprite* mainchr = Sprite::create("MiniGameResources/main_char.png");
			mainchr->setAnchorPoint(Point(0.5, 0));
			mainchr->setPosition(Point(120, 80));
			mainchr->setTag(166);
			this->addChild(mainchr, 1);

			auto storyA_item = MenuItemImage::create(
				"MiniGameResources/UI_Textlblack.png",
				"MiniGameResources/UI_Textlblack.png",

				CC_CALLBACK_1(ContestScene::replayspr, this));
			storyA_item->setAnchorPoint(Point(0.5, 0.5));
			storyA_item->setPosition(Point(510, 100));

			auto storyA = Menu::create(storyA_item, NULL);
			storyA->setAnchorPoint(Point(0.5, 0.5));
			storyA->setPosition(Point(0, 0));
			storyA->setTag(4);
			this->addChild(storyA, 1);

			char MyString[200];
			WideCharToMultiByte(CP_UTF8, 0, L"좋지않아.. 많이 좋지않아..\n\n(20000원을 획득하였습니다.)", -1, MyString, 200, NULL, NULL);
			auto name = Label::createWithTTF(MyString, "fonts/Bold.ttf", 30);
			name->setAnchorPoint(Point(0, 1));
			name->setPosition(Point(40, 150));
			name->setColor(Color3B::WHITE);
			name->setTag(20);
			this->addChild(name, 3);

			auto textA_item = MenuItemImage::create(
				"MiniGameResources/ok_button.png",
				"MiniGameResources/ok_buttonpr.png",
				CC_CALLBACK_1(ContestScene::Nextday, this));
			textA_item->setAnchorPoint(Point(0.5, 0.5));
			textA_item->setPosition(Point(950, 65));

			auto text = Menu::create(textA_item, NULL);
			text->setAnchorPoint(Point(0.5, 0.5));
			text->setPosition(Point(0, 0));
			text->setTag(136);
			this->addChild(text, 5);

			Singletons::getInstance()->money = Singletons::getInstance()->money + 20000;
		}

		if (Singletons::getInstance()->gonmonum == 3)
		{
			//메인캐릭터
			Sprite* mainchr = Sprite::create("MiniGameResources/main_char.png");
			mainchr->setAnchorPoint(Point(0.5, 0));
			mainchr->setPosition(Point(120, 80));
			mainchr->setTag(166);
			this->addChild(mainchr, 1);

			auto storyA_item = MenuItemImage::create(
				"MiniGameResources/UI_Textlblack.png",
				"MiniGameResources/UI_Textlblack.png",

				CC_CALLBACK_1(ContestScene::replayspr, this));
			storyA_item->setAnchorPoint(Point(0.5, 0.5));
			storyA_item->setPosition(Point(510, 100));

			auto storyA = Menu::create(storyA_item, NULL);
			storyA->setAnchorPoint(Point(0.5, 0.5));
			storyA->setPosition(Point(0, 0));
			storyA->setTag(4);
			this->addChild(storyA, 1);

			char MyString[200];
			WideCharToMultiByte(CP_UTF8, 0, L"좋지않아.. 많이 좋지않아..\n\n(40000원을 획득하였습니다.)", -1, MyString, 200, NULL, NULL);
			auto name = Label::createWithTTF(MyString, "fonts/Bold.ttf", 30);
			name->setAnchorPoint(Point(0, 1));
			name->setPosition(Point(40, 150));
			name->setColor(Color3B::WHITE);
			name->setTag(20);
			this->addChild(name, 3);

			auto textA_item = MenuItemImage::create(
				"MiniGameResources/ok_button.png",
				"MiniGameResources/ok_buttonpr.png",
				CC_CALLBACK_1(ContestScene::Nextday, this));
			textA_item->setAnchorPoint(Point(0.5, 0.5));
			textA_item->setPosition(Point(950, 65));

			auto text = Menu::create(textA_item, NULL);
			text->setAnchorPoint(Point(0.5, 0.5));
			text->setPosition(Point(0, 0));
			text->setTag(136);
			this->addChild(text, 5);

			Singletons::getInstance()->money = Singletons::getInstance()->money + 40000;
		}
		Singletons::getInstance()->gonmonum = 0;
	}
	if (Singletons::getInstance()->si == 5)
	{
		//메인캐릭터
		Sprite* mainchr = Sprite::create("MiniGameResources/main_char.png");
		mainchr->setAnchorPoint(Point(0.5, 0));
		mainchr->setPosition(Point(120, 80));
		mainchr->setTag(166);
		this->addChild(mainchr, 1);

		auto storyA_item = MenuItemImage::create(
			"MiniGameResources/UI_Textlblack.png",
			"MiniGameResources/UI_Textlblack.png",

			CC_CALLBACK_1(ContestScene::replayspr, this));
		storyA_item->setAnchorPoint(Point(0.5, 0.5));
		storyA_item->setPosition(Point(510, 100));

		auto storyA = Menu::create(storyA_item, NULL);
		storyA->setAnchorPoint(Point(0.5, 0.5));
		storyA->setPosition(Point(0, 0));
		storyA->setTag(4);
		this->addChild(storyA, 1);

		char MyString[200];
		WideCharToMultiByte(CP_UTF8, 0, L"으아... 망했다.. 준비좀 열심히 할걸..\n\n(상금을 획득하지 못했습니다.)", -1, MyString, 200, NULL, NULL);
		auto name = Label::createWithTTF(MyString, "fonts/Bold.ttf", 30);
		name->setAnchorPoint(Point(0, 1));
		name->setPosition(Point(40, 150));
		name->setColor(Color3B::WHITE);
		name->setTag(20);
		this->addChild(name, 3);

		auto textA_item = MenuItemImage::create(
			"MiniGameResources/ok_button.png",
			"MiniGameResources/ok_buttonpr.png",
			CC_CALLBACK_1(ContestScene::Nextday, this));
		textA_item->setAnchorPoint(Point(0.5, 0.5));
		textA_item->setPosition(Point(950, 65));

		auto text = Menu::create(textA_item, NULL);
		text->setAnchorPoint(Point(0.5, 0.5));
		text->setPosition(Point(0, 0));
		text->setTag(136);
		this->addChild(text, 5);

	}
	removeChildByTag(8);
	removeChildByTag(76);
	removeChildByTag(77);
	removeChildByTag(78);
	removeChildByTag(79);
	removeChildByTag(50);
	removeChildByTag(51);
	removeChildByTag(52);
	removeChildByTag(53);
	removeChildByTag(54);
	removeChildByTag(55);
	removeChildByTag(80);
	removeChildByTag(160);
	removeChildByTag(11);
	removeChildByTag(100);

}
void ContestScene::Nextday(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);

	Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
	Director::getInstance()->replaceScene(NextDayScene::createScene());
}
void ContestScene::cancelspr(Ref *pSender)
{
	removeChildByTag(164);
	removeChildByTag(165);
	removeChildByTag(166);
	removeChildByTag(167);
}
void ContestScene::replayspr(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);
	/*Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
	Director::getInstance()->replaceScene(ContestScene::createScene());*/
}
void ContestScene::newplay(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);
	Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
	Director::getInstance()->replaceScene(chrcreateScene::createScene());
}
//bool ContestScene::onTouchBegan(Touch* touch, Event* unused_event)
//{
//	Point location = touch->getLocation();
//	Sprite* spr = (Sprite*)this->getChildByTag(1);
//	Rect	rect = spr->getBoundingBox();
//
//	if (rect.containsPoint(location)) {
//		Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
//		Director::getInstance()->replaceScene(ContestScene::createScene());
//	}
//
//	return false;
//}
