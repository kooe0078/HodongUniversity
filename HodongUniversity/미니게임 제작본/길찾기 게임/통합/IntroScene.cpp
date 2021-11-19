#include "IntroScene.h"
#include "SimpleAudioEngine.h"
#include "MiroScene.h"
//���� �Ҷ�� �� �ʿ�
using namespace CocosDenshion;
USING_NS_CC;

Scene* IntroScene::createScene()
{
    auto scene = Scene::create();
    auto layer = IntroScene::create();
    scene->addChild(layer);

    return scene;
}

bool IntroScene::init()
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
	
	//��ġ ������ ���
	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = CC_CALLBACK_2(IntroScene::onTouchBegan, this);
	Director::getInstance()->getEventDispatcher()->addEventListenerWithFixedPriority(listener, 1);

	//�������
	SimpleAudioEngine::getInstance()->playBackgroundMusic("MiniGameResources/IntroBackSound.mp3", true);

    return true;
}
void IntroScene::update(float ft)
{
	//�� ��ü������ �ݺ� �Ǿ��ϴ� ����
}
void IntroScene::InitBackGround()
{
	auto sprite = Sprite::create("MiniGameResources/IntroBackGround.jpg");
	sprite->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	this->addChild(sprite, 0);
}
void IntroScene::InitLabel()
{
	auto label = Label::create(" ", "MiniGameResources/CuteFont.ttf", 60);
	label->setTextColor(Color4B(0, 0, 0, 255));
	label->setPosition(Vec2(origin.x + visibleSize.width / 2,
		origin.y + visibleSize.height - label->getContentSize().height * 2));
	this->addChild(label, 1);

	auto action_0 = Sequence::create(FadeOut::create(2), FadeIn::create(2), NULL);
	auto action_1 = RepeatForever::create(action_0);
	label->runAction(action_1);
}
void IntroScene::InitMenu()
{
	Sprite* spr = Sprite::create("MiniGameResources/button_play.png");
	spr->setTag(1);
	spr->setPosition(Point(origin.x + visibleSize.width / 2,
		origin.y + visibleSize.height / 2 - spr->getContentSize().height));
	this->addChild(spr, 1);
}
bool IntroScene::onTouchBegan(Touch* touch, Event* unused_event)
{
	Point location = touch->getLocation();
	Sprite* spr = (Sprite*)this->getChildByTag(1);
	Rect	rect = spr->getBoundingBox();

	if (rect.containsPoint(location)) {
		Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
		Director::getInstance()->replaceScene(MiroScene::createScene());
	}

	return false;
}
