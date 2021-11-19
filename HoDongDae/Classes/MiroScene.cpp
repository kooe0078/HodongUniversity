#include "MiroScene.h"
#include "MiroEndScene.h"
#include "SimpleAudioEngine.h"
#include "sinngleton.h"

//���� �Ҷ�� �� �ʿ�
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

	//�̱���
	Singletons::getInstance()->currClock;
	UserDefault::getInstance()->setIntegerForKey("currClock", Singletons::getInstance()->currClock);
	Singletons::getInstance()->currClock = UserDefault::getInstance()->getIntegerForKey("currClock");

	// �巡�� �׼�
	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = CC_CALLBACK_2(MiroScene::onTouchBegan, this);
	listener->onTouchMoved = CC_CALLBACK_2(MiroScene::onTouchMoved, this);
	listener->onTouchEnded = CC_CALLBACK_2(MiroScene::onTouchEnded, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

	sprReady(); // READY ȿ��
	this->scheduleOnce(schedule_selector(MiroScene::sprStart), 1.1f); // GO ȿ�� ������ ó��
	this->schedule(schedule_selector(MiroScene::SetLabel), 1.0f); // �ð� ������ ó��

	//�������
	SimpleAudioEngine::getInstance()->playBackgroundMusic("sound/game_sound.mp3", true);
	
    return true;
}
void MiroScene::BG() // ���
{
	auto spr = CCSprite::create("MiroGame/miro_BG.png");
	spr->setPosition(Point(512, 384));
	this->addChild(spr);
}
void MiroScene::Movepoint() // �����ϰ�
{
	auto movebutton = Sprite::create("MiroGame/miro_Point.png");
	movebutton->setAnchorPoint(Point(0.5, 0.5));
	movebutton->setTag(580);
	movebutton->setPosition(Point(50, 70));
	movebutton->getBoundingBox();
	this->addChild(movebutton, 1);
}
void MiroScene::Wall() // ��
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
void MiroScene::Potal() // ��������
{
	auto spr = Sprite::create("MiroGame/finish.png");
	spr->setPosition(Point(960, 690));
	spr->setTag(584);
	this->addChild(spr);
}
bool MiroScene::onTouchBegan(Touch *touch, Event *event) // ���콺 Ŭ��
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

void MiroScene::onTouchMoved(Touch *touch, Event *event) // ���콺 �巡��
{
	if (rect1 == true)
	{
		Point location = touch->getLocation();
		auto movebutton = (Sprite*)this->getChildByTag(580);
		movebutton->setPosition(location);// �巡��

		Sprite* wall_1 = (Sprite*)this->getChildByTag(581);
		Rect   rect_1 = wall_1->getBoundingBox(); // �� �浹����
		Sprite* wall_2 = (Sprite*)this->getChildByTag(582);
		Rect   rect_2 = wall_2->getBoundingBox(); // �� �浹����
		Sprite* wall_3 = (Sprite*)this->getChildByTag(583);
		Rect   rect_3 = wall_3->getBoundingBox(); // �� �浹����
		Sprite* Potal_1 = (Sprite*)this->getChildByTag(584);
		Rect   rect_4 = Potal_1->getBoundingBox(); // �������� �浹����

		if (rect_1.containsPoint(location))// �� �浹��
		{
			rect1 = false;
			movebutton->setPosition(Point(50, 70));
		}
		if (rect_2.containsPoint(location))// �� �浹��
		{
			rect1 = false;
			movebutton->setPosition(Point(50, 70));
		}
		if (rect_3.containsPoint(location))// �� �浹��
		{
			rect1 = false;
			movebutton->setPosition(Point(50, 70));
		}
		if (rect_4.containsPoint(location)) // Ŭ���� ���� ������
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
void MiroScene::onTouchEnded(Touch *touch, Event *event) // ���콺 Ŭ�� ����
{
	rect1 = false;
	auto movebutton = (Sprite*)this->getChildByTag(580);
	movebutton->setPosition(Point(50, 70));
}
void MiroScene::sprReady() // �غ� �ΰ�
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
void MiroScene::sprStart(float delta) // ���� �ΰ�
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
void MiroScene::TimeLimit() // �ð� ����, ����
{
	char Q1[200];
	WideCharToMultiByte(CP_UTF8, 0, L"���� �ð� : ", -1, Q1, 200, NULL, NULL);
	auto Time = Label::createWithTTF(Q1, "MiroGame/ABC.ttf", 22);
	Time->setAnchorPoint(Point(0, 1));
	Time->setPosition(Point(90, 645));
	Time->setColor(Color3B::RED);
	this->addChild(Time, 2);

	char Q2[200];
	WideCharToMultiByte(CP_UTF8, 0, L" <- ���콺�� �������� ��� ���� ���� ���� ������ �Ű��ּ���!!", -1, Q1, 200, NULL, NULL);
	auto A = Label::createWithTTF(Q1, "MiroGame/ABC.ttf", 22);
	A->setAnchorPoint(Point(0, 1));
	A->setPosition(Point(201, 102));
	A->setColor(Color3B::RED);
	this->addChild(A, 2);
}
void MiroScene::InitLabel() // �ð� ����
{
	Label* label = Label::createWithTTF(StringUtils::format(""), "MiroGame/ABC.ttf", 30);
	label->setAnchorPoint(Point(0, 1));
	label->setPosition(Point(200, 650));
	label->setColor(Color3B::RED);
	label->setTag(585);
	this->addChild(label, 2);
}
void MiroScene::SetLabel(float delta) // �ð� ���
{
	Singletons::getInstance()->currClock = UserDefault::getInstance()->getIntegerForKey("currClock") - 1;
	UserDefault::getInstance()->setIntegerForKey("currClock", Singletons::getInstance()->currClock);
	UserDefault::getInstance()->flush();

	Label* label = (Label*)this->getChildByTag(585);
	label->setString(StringUtils::format("%d", Singletons::getInstance()->currClock));

	if (Singletons::getInstance()->currClock == 0) // �ð��� �� �� ���
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