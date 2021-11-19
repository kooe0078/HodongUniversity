#include "MiroScene3.h"
#include "MiroEndScene3.h"
#include "SimpleAudioEngine.h"
#include "singleton.h"

//사운드 할라면 꼭 필요
using namespace CocosDenshion;
USING_NS_CC;

Scene* MiroScene3::createScene()
{
    auto scene = Scene::create();
    auto layer = MiroScene3::create();
    scene->addChild(layer);

    return scene;
}

bool MiroScene3::init()
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
	Singletons::getInstance()->currClock3;
	UserDefault::getInstance()->setIntegerForKey("currClock3", Singletons::getInstance()->currClock3);
	Singletons::getInstance()->currClock3 = UserDefault::getInstance()->getIntegerForKey("currClock3");

	// 드래그 액션
	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = CC_CALLBACK_2(MiroScene3::onTouchBegan, this);
	listener->onTouchMoved = CC_CALLBACK_2(MiroScene3::onTouchMoved, this);
	listener->onTouchEnded = CC_CALLBACK_2(MiroScene3::onTouchEnded, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

	sprReady(); // READY 효과
	this->scheduleOnce(schedule_selector(MiroScene3::sprStart), 1.1f); // GO 효과 스케줄 처리
	this->schedule(schedule_selector(MiroScene3::SetLabel), 1.0f); // 시간 스케줄 처리

	//배경음악
	//SimpleAudioEngine::getInstance()->playBackgroundMusic("MiniGameResources/MainBackSound.mp3", true);
	
    return true;
}
void MiroScene3::BG() // 배경
{
	auto spr = CCSprite::create("MiroGame/miro_BG.png");
	spr->setPosition(Point(512, 384));
	this->addChild(spr);
}
void MiroScene3::Movepoint() // 움직일거
{
	auto movebutton = Sprite::create("MiroGame/miro_Point.png");
	movebutton->setAnchorPoint(Point(0.5, 0.5));
	movebutton->setTag(580);
	movebutton->setPosition(Point(862, 95));
	movebutton->getBoundingBox();
	this->addChild(movebutton, 1);
}
void MiroScene3::Wall() // 벽
{
	auto spr = Sprite::create("MiroGame/11.png");
	spr->setPosition(Point(50, 384));
	spr->setTag(581);
	this->addChild(spr); 

	auto spr2 = Sprite::create("MiroGame/22.png");
	spr2->setPosition(Point(512, 20));
	spr2->setTag(582);
	this->addChild(spr2);

	auto spr3 = Sprite::create("MiroGame/33.png");
	spr3->setPosition(Point(974, 384));
	spr3->setTag(583);
	this->addChild(spr3);

	auto spr4 = Sprite::create("MiroGame/44.png");
	spr4->setPosition(Point(512, 758));
	spr4->setTag(610);
	this->addChild(spr4);

	auto spr5 = Sprite::create("MiroGame/55.png");
	spr5->setPosition(Point(610, 608));
	spr5->setTag(611);
	this->addChild(spr5);

	auto spr6 = Sprite::create("MiroGame/66.png");
	spr6->setPosition(Point(410, 414));
	spr6->setTag(612);
	this->addChild(spr6);

	auto spr7 = Sprite::create("MiroGame/77.png");
	spr7->setPosition(Point(610, 200));
	spr7->setTag(613);
	this->addChild(spr7);
}
void MiroScene3::Potal() // 도착지점
{
	auto spr = Sprite::create("MiroGame/finish.png");
	spr->setPosition(Point(862, 700));
	spr->setTag(584);
	this->addChild(spr);
}
bool MiroScene3::onTouchBegan(Touch *touch, Event *event) // 마우스 클릭
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

void MiroScene3::onTouchMoved(Touch *touch, Event *event) // 마우스 드래그
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
		Sprite* wall_5 = (Sprite*)this->getChildByTag(610);
		Rect   rect_5 = wall_5->getBoundingBox(); // 벽 충돌판정
		Sprite* wall_6 = (Sprite*)this->getChildByTag(611);
		Rect   rect_6 = wall_6->getBoundingBox(); // 벽 충돌판정
		Sprite* wall_7 = (Sprite*)this->getChildByTag(612);
		Rect   rect_7 = wall_7->getBoundingBox(); // 벽 충돌판정
		Sprite* wall_8 = (Sprite*)this->getChildByTag(613);
		Rect   rect_8 = wall_8->getBoundingBox(); // 벽 충돌판정

		if (rect_1.containsPoint(location))// 벽 충돌시
		{
			rect1 = false;
			movebutton->setPosition(Point(862, 95));
		}
		if (rect_2.containsPoint(location))// 벽 충돌시
		{
			rect1 = false;
			movebutton->setPosition(Point(862, 95));
		}
		if (rect_3.containsPoint(location))// 벽 충돌시
		{
			rect1 = false;
			movebutton->setPosition(Point(862, 95));
		}
		if (rect_4.containsPoint(location)) // 클리어 지점 도착시
		{
			rect1 = false;
			TimeCheck = false;

			auto spr = CCSprite::create("MiroGame/clear.png");
			spr->setPosition(Point(512, 384));
			this->addChild(spr);

			Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
			auto scene = TransitionCrossFade::create(1.5, MiroEndScene3::createScene());
			Director::getInstance()->replaceScene(scene);
		}
		if (rect_5.containsPoint(location))// 벽 충돌시
		{
			rect1 = false;
			movebutton->setPosition(Point(862, 95));
		}
		if (rect_6.containsPoint(location))// 벽 충돌시
		{
			rect1 = false;
			movebutton->setPosition(Point(862, 95));
		}
		if (rect_7.containsPoint(location))// 벽 충돌시
		{
			rect1 = false;
			movebutton->setPosition(Point(862, 95));
		}
		if (rect_8.containsPoint(location))// 벽 충돌시
		{
			rect1 = false;
			movebutton->setPosition(Point(862, 95));
		}
	}
}
void MiroScene3::onTouchEnded(Touch *touch, Event *event) // 마우스 클릭 해제
{
	rect1 = false;
	auto movebutton = (Sprite*)this->getChildByTag(580);
	movebutton->setPosition(Point(862, 95));
}
void MiroScene3::sprReady() // 준비 로고
{
	auto sprite = Sprite::create("MiroGame/ready.png");
	sprite->setPosition(Point(512, 384));
	sprite->setOpacity(0);
	this->addChild(sprite, 3);

	auto action_fadein = FadeIn::create(1.0f);
	auto action_fadeout = FadeOut::create(0.1f);
	auto action_seq = Sequence::create(action_fadein, action_fadeout, NULL);
	sprite->runAction(action_seq);
}
void MiroScene3::sprStart(float delta) // 시작 로고
{
	auto sprite = Sprite::create("MiroGame/go.png");
	sprite->setPosition(Point(512, 384));
	sprite->setOpacity(1);
	this->addChild(sprite, 3);

	auto action_fadein = FadeIn::create(1.0f);
	auto action_fadeout = FadeOut::create(0.1f);
	auto action_seq = Sequence::create(action_fadein, action_fadeout, NULL);
	sprite->runAction(action_seq);
}
void MiroScene3::TimeLimit() // 시간 제한, 설명
{
	char Q1[200];
	WideCharToMultiByte(CP_UTF8, 0, L"남은 시간 : ", -1, Q1, 200, NULL, NULL);
	auto Time = Label::createWithTTF(Q1, "MiroGame/ABC.ttf", 22);
	Time->setAnchorPoint(Point(0, 1));
	Time->setPosition(Point(70, 645));
	Time->setColor(Color3B::RED);
	this->addChild(Time, 2);

	char Q2[200];
	WideCharToMultiByte(CP_UTF8, 0, L"마우스로 아이콘을 들고 길을 따라 도착 지점에 옮겨주세요!!", -1, Q1, 200, NULL, NULL);
	auto A = Label::createWithTTF(Q1, "MiroGame/ABC.ttf", 22);
	A->setAnchorPoint(Point(0, 1));
	A->setPosition(Point(210, 414));
	A->setColor(Color3B::RED);
	this->addChild(A, 2);
}
void MiroScene3::InitLabel() // 시간 설정
{
	Label* label = Label::createWithTTF(StringUtils::format(""), "MiroGame/ABC.ttf", 25);
	label->setAnchorPoint(Point(0, 1));
	label->setPosition(Point(180, 645));
	label->setColor(Color3B::RED);
	label->setTag(585);
	this->addChild(label, 2);
}
void MiroScene3::SetLabel(float delta) // 시간 경과
{
	Singletons::getInstance()->currClock3 = UserDefault::getInstance()->getIntegerForKey("currClock3") - 1;
	UserDefault::getInstance()->setIntegerForKey("currClock3", Singletons::getInstance()->currClock3);
	UserDefault::getInstance()->flush();

	Label* label = (Label*)this->getChildByTag(585);
	label->setString(StringUtils::format("%d", Singletons::getInstance()->currClock3));

	if (Singletons::getInstance()->currClock3 == 0) // 시간이 다 될 경우
	{
		if (TimeCheck == true)
		{
			auto spr = CCSprite::create("MiroGame/fail.png");
			spr->setPosition(Point(512, 384));
			this->addChild(spr);
		
			Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
			auto scene = TransitionCrossFade::create(1.5f, MiroEndScene3::createScene());
			Director::getInstance()->replaceScene(scene);
		}
	}
}