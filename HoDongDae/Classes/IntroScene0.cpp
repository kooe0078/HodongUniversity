#include "IntroScene0.h"
#include "SimpleAudioEngine.h"
#include "MainScene.h"
#include "IntroSceneA.h"
//���� �Ҷ�� �� �ʿ�
using namespace CocosDenshion;
USING_NS_CC;

Scene* IntroScene0::createScene()
{
    auto scene = Scene::create();
    auto layer = IntroScene0::create();
    scene->addChild(layer);

    return scene;
}

bool IntroScene0::init()
{

    if ( !Layer::init() )
    {
        return false;
    }

	visibleSize = Director::getInstance()->getVisibleSize();
	origin      = Director::getInstance()->getVisibleOrigin();

	InitBackGround();
	
	// ȿ����
	SimpleAudioEngine::getInstance()->playEffect("sound/gy.mp3", false);

	// ������
	this->scheduleOnce(schedule_selector(IntroScene0::next), 3.0f);

    return true;
}
void IntroScene0::update(float ft)
{
	//�� ��ü������ �ݺ� �Ǿ��ϴ� ����
}
void IntroScene0::InitBackGround()
{
	auto sprite = Sprite::create("MiniGameResources/bug.png");
	sprite->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	this->addChild(sprite, 0);
}
void IntroScene0::next(float delta)
{
	Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
	auto scene = TransitionCrossFade::create(1.0, IntroSceneA::createScene());
	Director::getInstance()->replaceScene(scene);
}

