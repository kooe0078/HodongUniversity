#include "Seizure.h"
#include "NextDayScene.h"
#include "SimpleAudioEngine.h"
#include "sinngleton.h"
#include "Percent100.h"
//���� �Ҷ�� �� �ʿ�
using namespace CocosDenshion;
USING_NS_CC;

Scene* Seizure::createScene()
{
    auto scene = Scene::create();
    auto layer = Seizure::create();
    scene->addChild(layer);

    return scene;
}

bool Seizure::init()
{

    if ( !Layer::init() )
    {
        return false;
    }

	InitBackGround();
	InitMenu();
	
    return true;
}
void Seizure::InitBackGround()
{
	auto sprite = Sprite::create("Cor/inside_star.png");
	sprite->setPosition(Point(512, 384));
	this->addChild(sprite, 0);
}
void Seizure::InitMenu()
{
	
	// ���� ��ư
	auto textA_item = MenuItemImage::create(
		"Cor/ok_button.png",
		"Cor/ok_buttonpr.png",
		CC_CALLBACK_1(Seizure::story1, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(709);
	this->addChild(text, 5);

	//����ĳ����
	Sprite* mainchr = Sprite::create("Cor/main_char.png");
	mainchr->setAnchorPoint(Point(0.5, 0));
	mainchr->setPosition(Point(120, 80));
	mainchr->setTag(701);
	this->addChild(mainchr, 1);

	//�ؽ�Ʈ â
	auto sprite = Sprite::create("Cor/UI_Textlblack.png");
	sprite->setAnchorPoint(Point(0.5, 0.5));
	sprite->setPosition(Point(510, 100));
	sprite->setTag(700);
	this->addChild(sprite, 2);

	// ĳ���� ���
	char MyString[100];
	WideCharToMultiByte(CP_UTF8, 0, L"ȣ��(����): ����! ���� ȸ��� �Ѹ�� �������̾�! ������ ����!", -1, MyString, 100, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "Cor/ABC.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(729);
	this->addChild(name, 3);
}
void Seizure::story1(Ref * pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);

	removeChildByTag(709);
	removeChildByTag(729);

	Sprite* mainchr = Sprite::create("Cor/people1.png");
	mainchr->setAnchorPoint(Point(0.5, 0));
	mainchr->setScale(1.5);
	mainchr->setPosition(Point(820, 180));
	mainchr->setTag(702);
	this->addChild(mainchr, 1);

	char MyString[100];
	WideCharToMultiByte(CP_UTF8, 0, L"�ϵ�: �˾Ҿ� ����~~", -1, MyString, 100, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "Cor/ABC.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(730);
	this->addChild(name, 3);

	auto textA_item = MenuItemImage::create(
		"Cor/ok_button.png",
		"Cor/ok_buttonpr.png",
		CC_CALLBACK_1(Seizure::story1_2, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(710);
	this->addChild(text, 5);
}
void Seizure::story1_2(Ref * pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);

	removeChildByTag(710);
	removeChildByTag(730);
	removeChildByTag(701);
	removeChildByTag(702);

	char MyString[100];
	WideCharToMultiByte(CP_UTF8, 0, L"(������ ������ ��ΰ� ���ư���.)", -1, MyString, 100, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "Cor/ABC.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(731);
	this->addChild(name, 3);

	auto textA_item = MenuItemImage::create(
		"Cor/ok_button.png",
		"Cor/ok_buttonpr.png",
		CC_CALLBACK_1(Seizure::story1_3, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(711);
	this->addChild(text, 5);
}
void Seizure::story1_3(Ref * pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);

	removeChildByTag(731);
	removeChildByTag(711);

	//����ĳ����
	Sprite* mainchr = Sprite::create("Cor/main_char.png");
	mainchr->setAnchorPoint(Point(0.5, 0));
	mainchr->setPosition(Point(120, 80));
	mainchr->setTag(701);
	this->addChild(mainchr, 1);

	char MyString[100];
	WideCharToMultiByte(CP_UTF8, 0, L"ȣ��: (��! ���� ���ҳ�? ���� ���̵�)", -1, MyString, 100, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "Cor/ABC.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(732);
	this->addChild(name, 3);

	auto textA_item = MenuItemImage::create(
		"Cor/ok_button.png",
		"Cor/ok_buttonpr.png",
		CC_CALLBACK_1(Seizure::story1_4, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(712);
	this->addChild(text, 5);
}
void Seizure::story1_4(Ref * pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);

	removeChildByTag(732);
	removeChildByTag(712);

	char MyString[200];
	WideCharToMultiByte(CP_UTF8, 0, L"(���� ȹ���Ͽ����ϴ�.)\n\n(���赵�� 10 �����Ͽ����ϴ�.)", -1, MyString, 200, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "Cor/ABC.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(733);
	this->addChild(name, 3);

	auto textA_item = MenuItemImage::create(
		"Cor/ok_button.png",
		"Cor/ok_buttonpr.png",
		CC_CALLBACK_1(Seizure::story1_5, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(713);
	this->addChild(text, 5);

	int arr[5] = { 10000, 20000, 30000, 40000, 50000 };
	srand((double)time(NULL));

	int random = rand() % 5;
	Singletons::getInstance()->moneyget = arr[random];

	Singletons::getInstance()->money = Singletons::getInstance()->money + Singletons::getInstance()->moneyget;
	Singletons::getInstance()->Danger = Singletons::getInstance()->Danger + 10;
}
void Seizure::story1_5(Ref * pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);

	removeChildByTag(733);
	removeChildByTag(713);
	removeChildByTag(701);

	// ������ 5���� ������ ����
	if (Singletons::getInstance()->Danger >= 100)
	{
		Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
		Director::getInstance()->replaceScene(Percent100::createScene());
	}
	if (Singletons::getInstance()->Danger <= 99)
	{
		Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
		Director::getInstance()->replaceScene(NextDayScene::createScene()); // NextDay������ ����
	}
}