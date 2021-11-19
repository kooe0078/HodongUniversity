#include "MainScene.h"
#include "EndScene.h"
#include "SimpleAudioEngine.h"

//사운드 할라면 꼭 필요
using namespace CocosDenshion;
USING_NS_CC;

Scene* MainScene::createScene()
{
    auto scene = Scene::create();
    auto layer = MainScene::create();
    scene->addChild(layer);

    return scene;
}

bool MainScene::init()
{

    if ( !Layer::init() )
    {
        return false;
    }

	SimpleAudioEngine::getInstance()->playBackgroundMusic("MiniGameResources/MainBackSound.mp3", true); // 브금

	initBG();
	Card();

    return true;
}
void MainScene::initBG() // 배경
{
	auto spr = CCSprite::create("CardGame/BG.png");
	spr->setPosition(Point(512, 384));
	this->addChild(spr, 0);
}
void MainScene::Minion() // 상대 필드 하수인
{
	auto sprite = Sprite::create("CardGame/Simri2.png");
	sprite->setScale(1.0f);
	sprite->setPosition(Point(200, 450));
	this->addChild(sprite, 4);
	/*Sprite* Korkron = Sprite::create("CardGame/Korkron.png");
	Korkron->setAnchorPoint();
	Korkron->setPosition(Point(512, 600));
	this->addChild(Korkron);*/
}
void MainScene::Card() // 카드 사용
{
	auto Card_1 = MenuItemImage::create(
		"CardGame/Sim.png",
		"CardGame/Sim.png",
		CC_CALLBACK_1(MainScene::Check_1, this));
	Card_1->setPosition(Point(482, 50));

	auto menu1 = Menu::create(Card_1, NULL);
	menu1->setPosition(Vec2::ZERO);
	this->addChild(menu1, 1);
}
void MainScene::Check_1(Ref *pSender) // 카드 선택
{
	auto Card_1 = MenuItemImage::create(
		"CardGame/Simri.png",
		"CardGame/Simri.png",
		CC_CALLBACK_1(MainScene::Play_1, this));
	Card_1->setPosition(Point(282, 418));

	auto menu1 = Menu::create(Card_1, NULL);
	menu1->setPosition(Vec2::ZERO);
	menu1->setTag(551);
	this->addChild(menu1, 3);

	auto Card_2 = MenuItemImage::create(
		"CardGame/Jungbae.png",
		"CardGame/Jungbae.png",
		CC_CALLBACK_1(MainScene::Play_2, this));
	Card_2->setPosition(Point(512, 418));

	auto menu2 = Menu::create(Card_2, NULL);
	menu2->setPosition(Vec2::ZERO);
	menu2->setTag(552);
	this->addChild(menu2, 3);

	auto Card_3 = MenuItemImage::create(
		"CardGame/Jungbae.png",
		"CardGame/Jungbae.png",
		CC_CALLBACK_1(MainScene::Play_3, this));
	Card_3->setPosition(Point(742, 418));

	auto menu3 = Menu::create(Card_3, NULL);
	menu3->setPosition(Vec2::ZERO);
	menu3->setTag(553);
	this->addChild(menu3, 3);
}
void MainScene::Play_1(Ref *pSender) // 카드 선택1
{
	removeChildByTag(551);
	removeChildByTag(552);
	removeChildByTag(553);

	auto sprite = Sprite::create("CardGame/Simri2.png");
	sprite->setScale(1.0f);
	sprite->setPosition(Point(200, 450));
	sprite->setOpacity(0);
	this->addChild(sprite, 4);

	auto action_fadein = FadeIn::create(1.5f);
	auto action_fadeout = FadeOut::create(1.5f);
	auto action_seq = Sequence::create(action_fadein, action_fadeout, NULL);
	sprite->runAction(action_seq);

	auto Case_1 = MenuItemImage::create(
		"CardGame/Leeroy.png",
		"CardGame/Leeroy.png",
		CC_CALLBACK_1(MainScene::Case_1, this));
	Case_1->setPosition(Point(512, 350));

	auto summon_1 = Menu::create(Case_1, NULL);
	summon_1->setPosition(Vec2::ZERO);
	summon_1->setTag(555);
	this->addChild(summon_1, 3);
}
void MainScene::Play_2(Ref *pSender) // 카드 선택2
{
	removeChildByTag(551);
	removeChildByTag(552);
	removeChildByTag(553);

	auto sprite = Sprite::create("CardGame/Jungbae2.png");
	sprite->setScale(1.0f);
	sprite->setPosition(Point(200, 450));
	sprite->setOpacity(1);
	this->addChild(sprite, 4);

	auto action_fadein = FadeIn::create(1.5f);
	auto action_fadeout = FadeOut::create(1.5f);
	auto action_seq = Sequence::create(action_fadein, action_fadeout, NULL);
	sprite->runAction(action_seq);

	auto Case_2 = MenuItemImage::create(
		"CardGame/Card.png",
		"CardGame/Card.png",
		CC_CALLBACK_1(MainScene::Case_2, this));
	Case_2->setPosition(Point(512, 250));

	auto summon_2 = Menu::create(Case_2, NULL);
	summon_2->setPosition(Vec2::ZERO);
	summon_2->setTag(556);
	this->addChild(summon_2, 3);
}
void MainScene::Play_3(Ref *pSender) // 카드 선택3
{
	removeChildByTag(551);
	removeChildByTag(552);
	removeChildByTag(553);

	auto sprite = Sprite::create("CardGame/Card.png");
	sprite->setScale(1.0f);
	sprite->setPosition(Point(200, 450));
	sprite->setOpacity(2);
	this->addChild(sprite, 4);

	auto action_fadein = FadeIn::create(1.5f);
	auto action_fadeout = FadeOut::create(1.5f);
	auto action_seq = Sequence::create(action_fadein, action_fadeout, NULL);
	sprite->runAction(action_seq);

	auto Case_3 = MenuItemImage::create(
		"CardGame/Card.png",
		"CardGame/Card.png",
		CC_CALLBACK_1(MainScene::Case_3, this));
	Case_3->setPosition(Point(512, 250));

	auto summon_3 = Menu::create(Case_3, NULL);
	summon_3->setPosition(Vec2::ZERO);
	summon_3->setTag(557);
	this->addChild(summon_3, 3);
}
void MainScene::Case_1(Ref *pSender) // 리로이 클릭
{
	auto sprite = Sprite::create("CardGame/Arrow.png"); // 화살표
	sprite->setScale(1.0f);
	sprite->setPosition(Point(512, 500));
	this->addChild(sprite, 4);

	auto Kill = MenuItemImage::create(
		"CardGame/Skull.png",
		"CardGame/Skull.png",
		CC_CALLBACK_1(MainScene::Kill_1, this));
	Kill->setPosition(Point(512, 620));

	auto summon = Menu::create(Kill, NULL);
	summon->setPosition(Vec2::ZERO);
	summon->setTag(565);
	this->addChild(summon, 3);
	
}
void MainScene::Case_2(Ref *pSender) // 정배
{
	auto Hit_2 = MenuItemImage::create(
		"CardGame/Card.png",
		"CardGame/Card.png",
		CC_CALLBACK_1(MainScene::Hit_2, this));
	Hit_2->setPosition(Point(512, 250));

	auto summon_2 = Menu::create(Hit_2, NULL);
	summon_2->setPosition(Vec2::ZERO);
	summon_2->setTag(561);
	this->addChild(summon_2, 3);
}
void MainScene::Case_3(Ref *pSender) // 미정
{

}
void MainScene::Hit_1(Ref *pSender) // 리로이
{
	
}
void MainScene::Hit_2(Ref *pSender)
{

}
void MainScene::Hit_3(Ref *pSender)
{

}
void MainScene::Kill_1(Ref *pSender)
{

}