#include "MiroScene.h"
#include "MiroEndScene.h"
#include "SimpleAudioEngine.h"
#include "sinngleton.h"

//사운드 할라면 꼭 필요
using namespace CocosDenshion;
USING_NS_CC;

Scene* MiroScene::createScene()
{
    auto scene = Scene::create();
    auto layer = MiroScene::create();
    scene->addChild(layer);

    return scene;
}

bool MiroScene::init()
{

    if ( !Layer::init() )
    {
        return false;
    }

	BG();
	Movepoint();
	Wall();
	Potal();
	TimeLimit();
	InitLabel();

	//싱글톤
	Singletons::getInstance()->currClock;
	UserDefault::getInstance()->setIntegerForKey("currClock", Singletons::getInstance()->currClock);
	Singletons::getInstance()->currClock = UserDefault::getInstance()->getIntegerForKey("currClock");

	// 드래그 액션
	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = CC_CALLBACK_2(MiroScene::onTouchBegan, this);
	listener->onTouchMoved = CC_CALLBACK_2(MiroScene::onTouchMoved, this);
	listener->onTouchEnded = CC_CALLBACK_2(MiroScene::onTouchEnded, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

	sprReady(); // READY 효과
	this->scheduleOnce(schedule_selector(MiroScene::sprStart), 1.1f); // GO 효과 스케줄 처리
	this->schedule(schedule_selector(MiroScene::SetLabel), 1.0f); // 시간 스케줄 처리

	//배경음악
	SimpleAudioEngine::getInstance()->playBackgroundMusic("sound/game_sound.mp3", true);
	
    return true;
}
void MiroScene::BG() // 배경
{
	auto spr = CCSprite::create("MiroGame/miro_BG.png");
	spr->setPosition(Point(512, 384));
	this->addChild(spr);
}
void MiroScene::Movepoint() // 움직일거
{
	auto movebutton = Sprite::create("MiroGame/miro_Point.png");
	movebutton->setAnchorPoint(Point(0.5, 0.5));
	movebutton->setTag(580);
	movebutton->setPosition(Point(50, 70));
	movebutton->getBoundingBox();
	this->addChild(movebutton, 1);
}
void MiroScene::Wall() // 벽
{
	auto spr = Sprite::create("MiroGame/miro_block1.png");
	spr->setPosition(Point(306, 531.5));
	spr->setTag(581);
	this->addChild(spr); 

	auto spr2 = Sprite::create("MiroGame/miro_block2.png");
	spr2->setPosition(Point(601, 102));
	spr2->setTag(582);
	this->addChild(spr2);

	auto spr3 = Sprite::create("MiroGame/miro_block3.png");
	spr3->setPosition(Point(864, 334.5));
	spr3->setTag(583);
	this->addChild(spr3);

}
void MiroScene::Potal() // 도착지점
{
	auto spr = Sprite::create("MiroGame/finish.png");
	spr->setPosition(Point(960, 690));
	spr->setTag(584);
	this->addChild(spr);
}
bool MiroScene::onTouchBegan(Touch *touch, Event *event) // 마우스 클릭
{

	Point location = touch->getLocation();

	auto movebutton = (Sprite*)this->getChildByTag(580);
	if (movebutton->getPositionX() <= location.x + 40 && movebutton->getPositionX() >= location.x - 40 &
		movebutton->getPositionY() <= location.y + 40 && movebutton->getPositionY() >= location.y - 40)
	{
		rect1 = true;
	}

	return true;
}

void MiroScene::onTouchMoved(Touch *touch, Event *event) // 마우스 드래그
{
	if (rect1 == true)
	{
		Point location = touch->getLocation();
		auto movebutton = (Sprite*)this->getChildByTag(580);
		movebutton->setPosition(location);// 드래그

		Sprite* wall_1 = (Sprite*)this->getChildByTag(581);
		Rect   rect_1 = wall_1->getBoundingBox(); // 벽 충돌판정
		Sprite* wall_2 = (Sprite*)this->getChildByTag(582);
		Rect   rect_2 = wall_2->getBoundingBox(); // 벽 충돌판정
		Sprite* wall_3 = (Sprite*)this->getChildByTag(583);
		Rect   rect_3 = wall_3->getBoundingBox(); // 벽 충돌판정
		Sprite* Potal_1 = (Sprite*)this->getChildByTag(584);
		Rect   rect_4 = Potal_1->getBoundingBox(); // 도착지점 충돌판정

		if (rect_1.containsPoint(location))// 벽 충돌시
		{
			rect1 = false;
			movebutton->setPosition(Point(50, 70));
		}
		if (rect_2.containsPoint(location))// 벽 충돌시
		{
			rect1 = false;
			movebutton->setPosition(Point(50, 70));
		}
		if (rect_3.containsPoint(location))// 벽 충돌시
		{
			rect1 = false;
			movebutton->setPosition(Point(50, 70));
		}
		if (rect_4.containsPoint(location)) // 클리어 지점 도착시
		{
			rect1 == false;
			auto action = FadeOut::create(0.01f);
			movebutton->runAction(action);



		
			auto spr = CCSprite::create("MiroGame/clear.png");
			spr->setPosition(Point(512, 384));
			this->addChild(spr);

			/*uto text_item = MenuItemImage::create(
				"MiniGameResources/ok_button.png",
				"MiniGameResources/ok_buttonpr.png",
				CC_CALLBACK_1(MiroScene::nextday, this));
			text_item->setAnchorPoint(Point(0.5, 0.5));
			text_item->setPosition(Point(950, 65));

			auto text = Menu::create(text_item, NULL);
			text->setAnchorPoint(Point(0.5, 0.5));
			text->setPosition(Point(0, 0));
			text->setTag(130);
			this->addChild(text, 5);*/

			Singletons::getInstance()->mironum = 1;
		}
	}
}
//void MainScene::systemspr(Ref *pSender)
//{
//	Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
//	auto scene = TransitionCrossFade::create(1.5, MiroEndScene::createScene());
//	Director::getInstance()->replaceScene(scene);
//}
void MiroScene::onTouchEnded(Touch *touch, Event *event) // 마우스 클릭 해제
{
	rect1 = false;
	auto movebutton = (Sprite*)this->getChildByTag(580);
	movebutton->setPosition(Point(50, 70));
}
void MiroScene::sprReady() // 준비 로고
{
	auto sprite = Sprite::create("MiroGame/ready.png");
	sprite->setPosition(Point(512, 384));
	sprite->setOpacity(0);
	this->addChild(sprite);

	auto action_fadein = FadeIn::create(1.0f);
	auto action_fadeout = FadeOut::create(0.1f);
	auto action_seq = Sequence::create(action_fadein, action_fadeout, NULL);
	sprite->runAction(action_seq);
}
void MiroScene::sprStart(float delta) // 시작 로고
{
	auto sprite = Sprite::create("MiroGame/go.png");
	sprite->setPosition(Point(512, 384));
	sprite->setOpacity(1);
	this->addChild(sprite);

	auto action_fadein = FadeIn::create(1.0f);
	auto action_fadeout = FadeOut::create(0.1f);
	auto action_seq = Sequence::create(action_fadein, action_fadeout, NULL);
	sprite->runAction(action_seq);
}
void MiroScene::TimeLimit() // 시간 제한, 설명
{
	char Q1[200];
	WideCharToMultiByte(CP_UTF8, 0, L"남은 시간 : ", -1, Q1, 200, NULL, NULL);
	auto Time = Label::createWithTTF(Q1, "MiroGame/ABC.ttf", 22);
	Time->setAnchorPoint(Point(0, 1));
	Time->setPosition(Point(90, 645));
	Time->setColor(Color3B::RED);
	this->addChild(Time, 2);

	char Q2[200];
	WideCharToMultiByte(CP_UTF8, 0, L" <- 마우스로 아이콘을 들고 길을 따라 도착 지점에 옮겨주세요!!", -1, Q1, 200, NULL, NULL);
	auto A = Label::createWithTTF(Q1, "MiroGame/ABC.ttf", 22);
	A->setAnchorPoint(Point(0, 1));
	A->setPosition(Point(201, 102));
	A->setColor(Color3B::RED);
	this->addChild(A, 2);
}
void MiroScene::InitLabel() // 시간 설정
{
	Label* label = Label::createWithTTF(StringUtils::format(""), "MiroGame/ABC.ttf", 30);
	label->setAnchorPoint(Point(0, 1));
	label->setPosition(Point(200, 650));
	label->setColor(Color3B::RED);
	label->setTag(585);
	this->addChild(label, 2);
}
void MiroScene::SetLabel(float delta) // 시간 경과
{
	Singletons::getInstance()->currClock = UserDefault::getInstance()->getIntegerForKey("currClock") - 1;
	UserDefault::getInstance()->setIntegerForKey("currClock", Singletons::getInstance()->currClock);
	UserDefault::getInstance()->flush();

	Label* label = (Label*)this->getChildByTag(585);
	label->setString(StringUtils::format("%d", Singletons::getInstance()->currClock));

	if (Singletons::getInstance()->currClock == 0) // 시간이 다 될 경우
	{
		if (Singletons::getInstance()->mironum == 0)
		{
			auto spr = CCSprite::create("MiroGame/fail.png");
			spr->setPosition(Point(512, 384));
			this->addChild(spr);

			Singletons::getInstance()->mironum = 2;

			Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
			auto scene = TransitionCrossFade::create(1.5, MiroEndScene::createScene());
			Director::getInstance()->replaceScene(scene);
		}
		if (Singletons::getInstance()->mironum == 1)
		{
			Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
			auto scene = TransitionCrossFade::create(1.5, MiroEndScene::createScene());
			Director::getInstance()->replaceScene(scene);
		}
		
	}
}