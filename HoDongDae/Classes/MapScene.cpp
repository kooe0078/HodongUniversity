#include "MapScene.h"
#include "SimpleAudioEngine.h"
#include "MainScene.h"
#include "BudongScene.h"

#include "InsideScene.h"
#include "ParkScene.h"
#include "StudentUnionScene.h"
//���� �Ҷ�� �� �ʿ�
using namespace CocosDenshion;
USING_NS_CC;

Scene* MapScene::createScene()
{
    auto scene = Scene::create();
    auto layer = MapScene::create();
    scene->addChild(layer);

    return scene;
}

bool MapScene::init()
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
	
	////��ġ ������ ���
	//auto listener = EventListenerTouchOneByOne::create();
	//listener->onTouchBegan = CC_CALLBACK_2(IntroScene::onTouchBegan, this);
	//Director::getInstance()->getEventDispatcher()->addEventListenerWithFixedPriority(listener, 1);

	//�������
//	SimpleAudioEngine::getInstance()->playBackgroundMusic("MiniGameResources/IntroBackSound.mp3", true);

    return true;
}
void MapScene::update(float ft)
{
	//�� ��ü������ �ݺ� �Ǿ��ϴ� ����
}
void MapScene::InitBackGround()
{
	auto sprite = Sprite::create("MiniGameResources/map.png");
	sprite->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	this->addChild(sprite, 0);
}
void MapScene::InitLabel()
{
	
}
// ��
void MapScene::InitMenu()
{
		//tag30~35
		
		//ķ�۽�
		auto menu_item = MenuItemImage::create(
			"MiniGameResources/logo.png",
			"MiniGameResources/logo_press.png",
			CC_CALLBACK_1(MapScene::moveScene1, this));
		menu_item->setPosition(Point(0, 0));


		auto cam = Menu::create(menu_item, NULL);
		cam->setAnchorPoint(Point(0.5, 0.5));
		cam->setPosition(Point(520, 600));
		cam->setTag(30);
		this->addChild(cam, 3);

		Sprite* system1 = Sprite::create("MiniGameResources/map_textcam.png");
		system1->setAnchorPoint(Point(0.5, 0.5));
		system1->setPosition(Point(520, 430));
		//system1->setTag(109);
		this->addChild(system1, 3);

		//���ǰŷ���
		auto menu_item1 = MenuItemImage::create(
			"MiniGameResources/map_boodong.png",
			"MiniGameResources/map_boodongpr.png",
			CC_CALLBACK_1(MapScene::moveScene2, this));
		menu_item1->setPosition(Point(0, 0));


		auto budong = Menu::create(menu_item1, NULL);
		budong->setAnchorPoint(Point(0.5, 0.5));
		budong->setPosition(Point(825, 570));
		budong->setTag(31);
		this->addChild(budong, 3);

		Sprite* system2 = Sprite::create("MiniGameResources/map_textexchan.png");
		system2->setAnchorPoint(Point(0.5, 0.5));
		system2->setPosition(Point(825, 430));
		//system2->setTag(109);
		this->addChild(system2, 3);

		
		//��ȭ��
		auto menu_item3 = MenuItemImage::create(
			"MiniGameResources/map_inside.png",
			"MiniGameResources/map_insidepr.png",
			CC_CALLBACK_1(MapScene::moveScene4, this));
		menu_item3->setPosition(Point(0, 0));

		auto bunhwa = Menu::create(menu_item3, NULL);
		bunhwa->setAnchorPoint(Point(0.5, 0.5));
		bunhwa->setPosition(Point(200, 570));
		bunhwa->setTag(33);
		this->addChild(bunhwa, 3);

		Sprite* system4 = Sprite::create("MiniGameResources/map_textinside.png");
		system4->setAnchorPoint(Point(0.5, 0.5));
		system4->setPosition(Point(200, 430));
	//	system4->setTag(109);
		this->addChild(system4, 3);

		//����
		auto menu_item4 = MenuItemImage::create(
			"MiniGameResources/map_park.png",
			"MiniGameResources/map_parkpr.png",
			CC_CALLBACK_1(MapScene::moveScene5, this));
		menu_item4->setPosition(Point(0, 0));

		auto park = Menu::create(menu_item4, NULL);
		park->setAnchorPoint(Point(0.5, 0.5));
		park->setPosition(Point(125, 250));
		park->setTag(34);
		this->addChild(park, 3);

		Sprite* system5 = Sprite::create("MiniGameResources/map_textpark.png");
		system5->setAnchorPoint(Point(0.5, 0.5));
		system5->setPosition(Point(125, 110));
	//	system5->setTag(109);
		this->addChild(system5, 3);

		//�л�ȸ��
		auto menu_item5 = MenuItemImage::create(
			"MiniGameResources/map_student.png",
			"MiniGameResources/map_studentpr.png",
			CC_CALLBACK_1(MapScene::moveScene6, this));
		menu_item5->setPosition(Point(0, 0));

		auto student = Menu::create(menu_item5, NULL);
		student->setAnchorPoint(Point(0.5, 0.5));
		student->setPosition(Point(900, 250));
		student->setTag(35);
		this->addChild(student, 3);

		Sprite* system6 = Sprite::create("MiniGameResources/map_textstu.png");
		system6->setAnchorPoint(Point(0.5, 0.5));
		system6->setPosition(Point(900, 110));
	//	system6->setTag(109);
		this->addChild(system6, 3);
	
}

// �̵� Ŭ���� �ߴ� �޴�â 1,2,3 Ŭ���� ���� �ٸ� ��ҷ� �̵��ϴ� ��
void MapScene::moveScene1(Ref *pSender)
{
	// 1�� ��ư�� ������ �� �� �̵�
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);
	Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
	Director::getInstance()->replaceScene(MainScene::createScene());
}

void MapScene::moveScene2(Ref *pSender)
{
	// 2�� ��ư�� ������ �� �� �̵�
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);
	Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
	Director::getInstance()->replaceScene(BudongScene::createScene());
}




void MapScene::moveScene4(Ref *pSender)
{
	// 4�� ��ư�� ������ �� �� 
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);
	Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
	Director::getInstance()->replaceScene(InsideScene::createScene());
}

void MapScene::moveScene5(Ref *pSender)
{
	// 5�� ��ư�� ������ �� �� 
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);
	Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
	Director::getInstance()->replaceScene(ParkScene::createScene());
}

void MapScene::moveScene6(Ref *pSender)
{
	// 6�� ��ư�� ������ �� �� 
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);
	Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
	Director::getInstance()->replaceScene(StudentUnionScene::createScene());
}


//bool IntroScene::onTouchBegan(Touch* touch, Event* unused_event)
//{
//	Point location = touch->getLocation();
//	Sprite* spr = (Sprite*)this->getChildByTag(1);
//	Rect	rect = spr->getBoundingBox();
//
//	if (rect.containsPoint(location)) {
//		Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
//		Director::getInstance()->replaceScene(MainScene::createScene());
//	}
//
//	return false;
//}
