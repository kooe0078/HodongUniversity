#include "BadEnd.h"
#include "EndScene.h"
#include "SimpleAudioEngine.h"
#include "RankingScene.h"
//���� �Ҷ�� �� �ʿ�
using namespace CocosDenshion;
USING_NS_CC;

Scene* BadEnd::createScene()
{
	auto scene = Scene::create();
	auto layer = BadEnd::create();
	scene->addChild(layer);

	return scene;
}

bool BadEnd::init()
{

	if (!Layer::init())
	{
		return false;
	}

	InitBackGround();
	InitMenu();

	//�������
	SimpleAudioEngine::getInstance()->playBackgroundMusic("sound/Dark_Lotus.mp3", true);

	return true;
}
void BadEnd::InitBackGround()
{
	auto sprite = Sprite::create("Rank/stock_exchange.png");
	sprite->setPosition(Point(512, 384));
	sprite->setTag(705);
	this->addChild(sprite, 0);
}
void BadEnd::InitMenu()
{

	// ���� ��ư
	auto textA_item = MenuItemImage::create(
		"Rank/ok_button.png",
		"Rank/ok_buttonpr.png",
		CC_CALLBACK_1(BadEnd::story1, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(709);
	this->addChild(text, 5);

	// ���� ĳ����
	Sprite* mainchr = Sprite::create("Rank/main_char.png");
	mainchr->setAnchorPoint(Point(0.5, 0));
	mainchr->setPosition(Point(120, 80));
	mainchr->setTag(701);
	this->addChild(mainchr, 1);
	
	//�ؽ�Ʈ â
	auto sprite = Sprite::create("Rank/UI_Textlblack.png");
	sprite->setAnchorPoint(Point(0.5, 0.5));
	sprite->setPosition(Point(510, 100));
	sprite->setTag(700);
	this->addChild(sprite, 2);

	// ĳ���� ���
	char MyString[200];
	WideCharToMultiByte(CP_UTF8, 0, L"ȣ�� : ����.... �� ���·δ� �ݼ����� �� �� ����!", -1, MyString, 200, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "Rank/ABC.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(729);
	this->addChild(name, 3);
}
void BadEnd::story1(Ref * pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("MiniGameResources/button_click_16_sound_effects_.mp3", false);

	removeChildByTag(709);
	removeChildByTag(729);

	char MyString[100];
	WideCharToMultiByte(CP_UTF8, 0, L"ȣ�� : ���� ���� �ֽĻ��̾�!!", -1, MyString, 100, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "Rank/ABC.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(730);
	this->addChild(name, 3);

	auto textA_item = MenuItemImage::create(
		"Rank/ok_button.png",
		"Rank/ok_buttonpr.png",
		CC_CALLBACK_1(BadEnd::story1_2, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(710);
	this->addChild(text, 5);
}
void BadEnd::story1_2(Ref * pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("MiniGameResources/button_click_16_sound_effects_.mp3", false);

	removeChildByTag(710);
	removeChildByTag(730);
	removeChildByTag(705);
	removeChildByTag(701);

	char MyString[100];
	WideCharToMultiByte(CP_UTF8, 0, L"(....)", -1, MyString, 100, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "Rank/ABC.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(731);
	this->addChild(name, 3);

	auto textA_item = MenuItemImage::create(
		"Rank/ok_button.png",
		"Rank/ok_buttonpr.png",
		CC_CALLBACK_1(BadEnd::story1_3, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(711);
	this->addChild(text, 5);
}
void BadEnd::story1_3(Ref * pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("MiniGameResources/button_click_16_sound_effects_.mp3", false);

	removeChildByTag(731);
	removeChildByTag(711);

	char MyString[400];
	WideCharToMultiByte(CP_UTF8, 0, L"�Ѵ� ��. ȣ���� �ֽ��� ��� ����� ������... �ᱹ ������ �Ǿ���.", -1, MyString, 400, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "Rank/ABC.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(732);
	this->addChild(name, 3);

	auto textA_item = MenuItemImage::create(
		"Rank/ok_button.png",
		"Rank/ok_buttonpr.png",
		CC_CALLBACK_1(BadEnd::story1_4, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(712);
	this->addChild(text, 5);
}
void BadEnd::story1_4(Ref * pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("MiniGameResources/button_click_16_sound_effects_.mp3", false);

	removeChildByTag(732);
	removeChildByTag(712);
	removeChildByTag(701);

	auto sprite = Sprite::create("Rank/badendsecene.png");
	sprite->setPosition(Point(512, 384));
	sprite->setTag(706);
	this->addChild(sprite, 0);

	char MyString[400];
	WideCharToMultiByte(CP_UTF8, 0, L"ȣ�� : ����...��Ǭ�� �ּ���... ��Ǭ�� �ּ���...", -1, MyString, 400, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "Rank/ABC.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(733);
	this->addChild(name, 3);

	auto textA_item = MenuItemImage::create(
		"Rank/ok_button.png",
		"Rank/ok_buttonpr.png",
		CC_CALLBACK_1(BadEnd::story1_5, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(713);
	this->addChild(text, 5);

}
void BadEnd::story1_5(Ref * pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("MiniGameResources/button_click_16_sound_effects_.mp3", false);

	Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
	auto scene = TransitionCrossFade::create(1.5, RankingScene::createScene());
	Director::getInstance()->replaceScene(scene);
}
