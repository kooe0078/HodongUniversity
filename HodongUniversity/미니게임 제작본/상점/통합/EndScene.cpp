#include "EndScene.h"
#include "SimpleAudioEngine.h"
#include "MainScene.h"
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

	visibleSize = Director::getInstance()->getVisibleSize();
	origin      = Director::getInstance()->getVisibleOrigin();
	
	InitBackGround();

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
	Sprite* overSpr = Sprite::create("MiniGameResources/text_gameOver.png");
	overSpr->setAnchorPoint(Point(0.5, 0.5));
	overSpr->setPosition(Point(400, 300));
	this->addChild(overSpr);
}