#include "MiniGameEndScene.h"
#include "SimpleAudioEngine.h"
#include "MiniGameMainScene.h"
//���� �Ҷ�� �� �ʿ�
using namespace CocosDenshion;
USING_NS_CC;

Scene* MiniGameEndScene::createScene()
{
    auto scene = Scene::create();
    auto layer = MiniGameEndScene::create();
    scene->addChild(layer);

    return scene;
}

bool MiniGameEndScene::init()
{

    if ( !Layer::init() )
    {
        return false;
    }

	visibleSize = Director::getInstance()->getVisibleSize();
	origin      = Director::getInstance()->getVisibleOrigin();
	
	InitBackGround();

	//�������
	SimpleAudioEngine::getInstance()->playBackgroundMusic("MiniGameResources/EndSceneMusic.mp3", true);

    return true;
}
void MiniGameEndScene::update(float ft)
{
	//�� ��ü������ �ݺ� �Ǿ��ϴ� ����
}

void MiniGameEndScene::InitBackGround()
{
	Sprite* overSpr = Sprite::create("MiniGameResources/text_gameOver.png");
	overSpr->setAnchorPoint(Point(0.5, 0.5));
	overSpr->setPosition(Point(512, 394));
	this->addChild(overSpr);
}