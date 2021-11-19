#include "ParkTalk.h"
#include "SimpleAudioEngine.h"
#include "sinngleton.h"
#include "NextDayScene.h"
//���� �Ҷ�� �� �ʿ�
using namespace CocosDenshion;
USING_NS_CC;

Scene* ParkTalk::createScene()
{
    auto scene = Scene::create();
    auto layer = ParkTalk::create();
    scene->addChild(layer);

    return scene;
}

bool ParkTalk::init()
{

    if ( !Layer::init() )
    {
        return false;
    }

	visibleSize = Director::getInstance()->getVisibleSize();
	origin      = Director::getInstance()->getVisibleOrigin();

	InitBackGround();
	InitMenu();

	//�������
	//SimpleAudioEngine::getInstance()->playBackgroundMusic("ParkTalk/IntroBackSound.mp3", true);

    return true;
}
void ParkTalk::InitBackGround()
{
	auto sprite = Sprite::create("ParkTalk/bongsa.png");
	sprite->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	this->addChild(sprite, 0);
}
// ��Ʈ�� ����â
void ParkTalk::InitMenu()
{
	
	int i, num;

	srand((double)time(NULL));
	for (i = 0; i < 1; i++)
	{
		num = rand() % 7 + 1;
	}
	
	// �ѵ��� ��ȭ 1
	if (num == 1)
	{
		auto textA_item = MenuItemImage::create(
			"ParkTalk/ok_button.png",
			"ParkTalk/ok_buttonpr.png",
			CC_CALLBACK_1(ParkTalk::storyA, this));
		textA_item->setAnchorPoint(Point(0.5, 0.5));
		textA_item->setPosition(Point(950, 65));

		auto text = Menu::create(textA_item, NULL);
		text->setAnchorPoint(Point(0.5, 0.5));
		text->setPosition(Point(0, 0));
		text->setTag(130);
		this->addChild(text, 5);

	}
	// �ѵ��� ��ȭ 2
	if (num == 2)
	{
		auto textA_item = MenuItemImage::create(
			"ParkTalk/ok_button.png",
			"ParkTalk/ok_buttonpr.png",
			CC_CALLBACK_1(ParkTalk::storyA_1, this));
		textA_item->setAnchorPoint(Point(0.5, 0.5));
		textA_item->setPosition(Point(950, 65));

		auto text = Menu::create(textA_item, NULL);
		text->setAnchorPoint(Point(0.5, 0.5));
		text->setPosition(Point(0, 0));
		text->setTag(130);
		this->addChild(text, 5);
	}
	// ������ ��ȭ 1
	if (num == 3)
	{
		auto textA_item = MenuItemImage::create(
			"ParkTalk/ok_button.png",
			"ParkTalk/ok_buttonpr.png",
			CC_CALLBACK_1(ParkTalk::storyB, this));
		textA_item->setAnchorPoint(Point(0.5, 0.5));
		textA_item->setPosition(Point(950, 65));

		auto text = Menu::create(textA_item, NULL);
		text->setAnchorPoint(Point(0.5, 0.5));
		text->setPosition(Point(0, 0));
		text->setTag(130);
		this->addChild(text, 5);
	}
	// ������ ��ȭ 2
	if (num == 4)
	{
		auto textA_item = MenuItemImage::create(
			"ParkTalk/ok_button.png",
			"ParkTalk/ok_buttonpr.png",
			CC_CALLBACK_1(ParkTalk::storyB_1, this));
		textA_item->setAnchorPoint(Point(0.5, 0.5));
		textA_item->setPosition(Point(950, 65));

		auto text = Menu::create(textA_item, NULL);
		text->setAnchorPoint(Point(0.5, 0.5));
		text->setPosition(Point(0, 0));
		text->setTag(130);
		this->addChild(text, 5);
	}
	// ������ ��ȭ 1
	if (num == 5)
	{
		auto textA_item = MenuItemImage::create(
			"ParkTalk/ok_button.png",
			"ParkTalk/ok_buttonpr.png",
			CC_CALLBACK_1(ParkTalk::storyC, this));
		textA_item->setAnchorPoint(Point(0.5, 0.5));
		textA_item->setPosition(Point(950, 65));

		auto text = Menu::create(textA_item, NULL);
		text->setAnchorPoint(Point(0.5, 0.5));
		text->setPosition(Point(0, 0));
		text->setTag(130);
		this->addChild(text, 5);
	}
	// ������ ��ȭ 2
	if (num == 6)
	{
		auto textA_item = MenuItemImage::create(
			"ParkTalk/ok_button.png",
			"ParkTalk/ok_buttonpr.png",
			CC_CALLBACK_1(ParkTalk::storyC_1, this));
		textA_item->setAnchorPoint(Point(0.5, 0.5));
		textA_item->setPosition(Point(950, 65));

		auto text = Menu::create(textA_item, NULL);
		text->setAnchorPoint(Point(0.5, 0.5));
		text->setPosition(Point(0, 0));
		text->setTag(130);
		this->addChild(text, 5);
	}
	// ����
	if (num == 7)
	{
		auto textA_item = MenuItemImage::create(
			"ParkTalk/ok_button.png",
			"ParkTalk/ok_buttonpr.png",
			CC_CALLBACK_1(ParkTalk::storyD, this));
		textA_item->setAnchorPoint(Point(0.5, 0.5));
		textA_item->setPosition(Point(950, 65));

		auto text = Menu::create(textA_item, NULL);
		text->setAnchorPoint(Point(0.5, 0.5));
		text->setPosition(Point(0, 0));
		text->setTag(130);
		this->addChild(text, 5);
	}
	
	// �ؽ�Ʈ â
	auto sprite = Sprite::create("ParkTalk/UI_Textlblack.png");
	sprite->setAnchorPoint(Point(0.5, 0.5));
	sprite->setPosition(Point(510, 100));
	sprite->setTag(200);
	this->addChild(sprite, 2);

	// ���� ĳ����
	Sprite* mainchr = Sprite::create("ParkTalk/main_char.png");
	mainchr->setAnchorPoint(Point(0.5, 0));
	mainchr->setPosition(Point(120, 80));
	mainchr->setTag(166);
	this->addChild(mainchr, 1);

	char MyString[200];
	WideCharToMultiByte(CP_UTF8, 0, L"ȣ��: ���� �̷��� ��å�ϴ°͵� �������ʱ�.", -1, MyString, 200, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "ParkTalk/Bold.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(21);
	this->addChild(name, 3);
}
// �ѵ��� ��ȭ�� 1
void ParkTalk::storyA(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);

	removeChildByTag(130);
	removeChildByTag(21);

	char MyString[100];
	WideCharToMultiByte(CP_UTF8, 0, L"(�ѵ����� ������.)", -1, MyString, 100, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "ParkTalk/Bold.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(21);
	this->addChild(name, 3);

	
	auto textA_item = MenuItemImage::create(
		"ParkTalk/ok_button.png",
		"ParkTalk/ok_buttonpr.png",
		CC_CALLBACK_1(ParkTalk::storyAA, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(131);
	this->addChild(text, 5);

	Sprite* mainchr = Sprite::create("ParkTalk/park_chara1.png");
	mainchr->setAnchorPoint(Point(0.5, 0));
	mainchr->setPosition(Point(800, 0));
	mainchr->setTag(231);
	this->addChild(mainchr, 1);
}
void ParkTalk::storyAA(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);

	removeChildByTag(131);
	removeChildByTag(21);

	char MyString[100];
	WideCharToMultiByte(CP_UTF8, 0, L"ȣ�� : �ȳ��ϼ��� ��������!", -1, MyString, 100, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "ParkTalk/Bold.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(22);
	this->addChild(name, 3);


	auto textA_item = MenuItemImage::create(
		"ParkTalk/ok_button.png",
		"ParkTalk/ok_buttonpr.png",
		CC_CALLBACK_1(ParkTalk::storyAAA, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(132);
	this->addChild(text, 5);

}
void ParkTalk::storyAAA(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);

	removeChildByTag(132);
	removeChildByTag(22);

	char MyString[100];
	WideCharToMultiByte(CP_UTF8, 0, L"���� : �� �׷�. ȣ���̱���!", -1, MyString, 100, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "ParkTalk/Bold.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(23);
	this->addChild(name, 3);


	auto textA_item = MenuItemImage::create(
		"ParkTalk/ok_button.png",
		"ParkTalk/ok_buttonpr.png",
		CC_CALLBACK_1(ParkTalk::storyAAAA, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(133);
	this->addChild(text, 5);
}
void ParkTalk::storyAAAA(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);

	removeChildByTag(133);
	removeChildByTag(23);

	char MyString[100];
	WideCharToMultiByte(CP_UTF8, 0, L"ȣ�� : ���⼭ ���ϼ���?", -1, MyString, 100, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "ParkTalk/Bold.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(24);
	this->addChild(name, 3);

	
	auto textA_item = MenuItemImage::create(
		"ParkTalk/ok_button.png",
		"ParkTalk/ok_buttonpr.png",
		CC_CALLBACK_1(ParkTalk::storyAAAAA, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(134);
	this->addChild(text, 5);
}
void ParkTalk::storyAAAAA(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);

	removeChildByTag(134);
	removeChildByTag(24);

	char MyString[400];
	WideCharToMultiByte(CP_UTF8, 0, L"���� : å �а��־���. å�� ������ ����̶�� ���ݾ�?\n�ʵ� �ð��� �� �̷��� å�̳� �о��.", -1, MyString, 400, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "ParkTalk/Bold.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(25);
	this->addChild(name, 3);


	auto textA_item = MenuItemImage::create(
		"ParkTalk/ok_button.png",
		"ParkTalk/ok_buttonpr.png",
		CC_CALLBACK_1(ParkTalk::storyAAAAAA, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(135);
	this->addChild(text, 5);
}
void ParkTalk::storyAAAAAA(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);

	removeChildByTag(135);
	removeChildByTag(25);

	char MyString[100];
	WideCharToMultiByte(CP_UTF8, 0, L"ȣ�� : ��...", -1, MyString, 100, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "ParkTalk/Bold.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(26);
	this->addChild(name, 3);


	auto textA_item = MenuItemImage::create(
		"ParkTalk/ok_button.png",
		"ParkTalk/ok_buttonpr.png",
		CC_CALLBACK_1(ParkTalk::storyAAAAAAA, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(136);
	this->addChild(text, 5);
}
void ParkTalk::storyAAAAAAA(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);

	removeChildByTag(136);
	removeChildByTag(26);

	char MyString[100];
	WideCharToMultiByte(CP_UTF8, 0, L"(ǰ���� ��������.)\n\n (ģ�е��� 12 �����Ͽ����ϴ�.)", -1, MyString, 100, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "ParkTalk/Bold.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(26);
	this->addChild(name, 3);


	auto textA_item = MenuItemImage::create(
		"ParkTalk/ok_button.png",
		"ParkTalk/ok_buttonpr.png",
		CC_CALLBACK_1(ParkTalk::GoHome, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(136);
	this->addChild(text, 5);

	Singletons::getInstance()->m_friendly = Singletons::getInstance()->m_friendly + 12;
}
// �ѵ��� ��ȭ�� 2
void ParkTalk::storyA_1(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);

	//���ϴ� ��ȭ��1
	removeChildByTag(130);
	removeChildByTag(21);

	char MyString[100];
	WideCharToMultiByte(CP_UTF8, 0, L"(�ѵ����� ������.)", -1, MyString, 100, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "ParkTalk/Bold.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(21);
	this->addChild(name, 3);


	auto textA_item = MenuItemImage::create(
		"ParkTalk/ok_button.png",
		"ParkTalk/ok_buttonpr.png",
		CC_CALLBACK_1(ParkTalk::storyAA_1, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(131);
	this->addChild(text, 5);

	Sprite* mainchr = Sprite::create("ParkTalk/park_chara1.png");
	mainchr->setAnchorPoint(Point(0.5, 0));
	mainchr->setPosition(Point(800, 0));
	mainchr->setTag(231);
	this->addChild(mainchr, 1);
}
void ParkTalk::storyAA_1(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);

	removeChildByTag(131);
	removeChildByTag(21);
	char MyString[500];
	WideCharToMultiByte(CP_UTF8, 0, L"���� : ȣ����. '�� ����� �ΰ��� �װ� ���� å���� �� �� �ִ�.'��� \n���������� ���� ���ݾ�?\n�ʵ� å�� �о�°� ��� ȣ����?", -1, MyString, 500, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "ParkTalk/Bold.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(22);
	this->addChild(name, 3);


	auto textA_item = MenuItemImage::create(
		"ParkTalk/ok_button.png",
		"ParkTalk/ok_buttonpr.png",
		CC_CALLBACK_1(ParkTalk::storyAAA_1, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(132);
	this->addChild(text, 5);
}
void ParkTalk::storyAAA_1(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);

	removeChildByTag(132);
	removeChildByTag(22);

	char MyString[200];
	WideCharToMultiByte(CP_UTF8, 0, L"ȣ�� : ���� å �а� �ְŵ��? (���� ��ȭå������...)", -1, MyString, 200, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "ParkTalk/Bold.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(23);
	this->addChild(name, 3);


	auto textA_item = MenuItemImage::create(
		"ParkTalk/ok_button.png",
		"ParkTalk/ok_buttonpr.png",
		CC_CALLBACK_1(ParkTalk::storyAAAA_1, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(133);
	this->addChild(text, 5);
}
void ParkTalk::storyAAAA_1(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);

	removeChildByTag(133);
	removeChildByTag(23);

	char MyString[300];
	WideCharToMultiByte(CP_UTF8, 0, L"���� : �׷�? �׷� �ֱٿ� ���� å�߿� ��￡ ���� ������ �����ٷ�?", -1, MyString, 300, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "ParkTalk/Bold.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(24);
	this->addChild(name, 3);


	auto textA_item = MenuItemImage::create(
		"ParkTalk/ok_button.png",
		"ParkTalk/ok_buttonpr.png",
		CC_CALLBACK_1(ParkTalk::storyAAAAA_1, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(134);
	this->addChild(text, 5);
}
void ParkTalk::storyAAAAA_1(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);

	removeChildByTag(134);
	removeChildByTag(24);

	char MyString[300];
	WideCharToMultiByte(CP_UTF8, 0, L"ȣ�� : ��... '��� ������ ù ������ �ʿ�� ����.'��� ���� ��￡ ���׿�.", -1, MyString, 300, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "ParkTalk/Bold.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(25);
	this->addChild(name, 3);


	auto textA_item = MenuItemImage::create(
		"ParkTalk/ok_button.png",
		"ParkTalk/ok_buttonpr.png",
		CC_CALLBACK_1(ParkTalk::storyAAAAAA_1, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(135);
	this->addChild(text, 5);
}
void ParkTalk::storyAAAAAA_1(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);

	removeChildByTag(135);
	removeChildByTag(25);

	char MyString[200];
	WideCharToMultiByte(CP_UTF8, 0, L"���� : ���� ���� ���ΰ�! �������� �߱���!", -1, MyString, 200, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "ParkTalk/Bold.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(26);
	this->addChild(name, 3);


	auto textA_item = MenuItemImage::create(
		"ParkTalk/ok_button.png",
		"ParkTalk/ok_buttonpr.png",
		CC_CALLBACK_1(ParkTalk::storyAAAAAAA_1, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(136);
	this->addChild(text, 5);
}
void ParkTalk::storyAAAAAAA_1(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);

	removeChildByTag(136);
	removeChildByTag(26);

	char MyString[400];
	WideCharToMultiByte(CP_UTF8, 0, L"ȣ�� : ��...�� (���������� �𸣰����� �ϴ� �ƴ� ô�ؾ߰ڴ�.\nå �� �о�߰ڴ°�?)\n\n (ģ�е��� 10 �����Ͽ����ϴ�.)", -1, MyString, 400, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "ParkTalk/Bold.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(26);
	this->addChild(name, 3);


	auto textA_item = MenuItemImage::create(
		"ParkTalk/ok_button.png",
		"ParkTalk/ok_buttonpr.png",
		CC_CALLBACK_1(ParkTalk::GoHome, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(136);
	this->addChild(text, 5);

	Singletons::getInstance()->m_friendly = Singletons::getInstance()->m_friendly + 10;
}
// ������ ��ȭ�� 1
void ParkTalk::storyB(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);

	removeChildByTag(130);
	removeChildByTag(21);

	char MyString[100];
	WideCharToMultiByte(CP_UTF8, 0, L"(�������� ������.)", -1, MyString, 100, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "ParkTalk/Bold.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(21);
	this->addChild(name, 3);


	auto textA_item = MenuItemImage::create(
		"ParkTalk/ok_button.png",
		"ParkTalk/ok_buttonpr.png",
		CC_CALLBACK_1(ParkTalk::storyBB, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(131);
	this->addChild(text, 5);

	Sprite* mainchr = Sprite::create("ParkTalk/park_chara2.png");
	mainchr->setAnchorPoint(Point(0.5, 0));
	mainchr->setPosition(Point(800, 0));
	mainchr->setTag(231);
	this->addChild(mainchr, 1);
}
void ParkTalk::storyBB(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);

	removeChildByTag(131);
	removeChildByTag(21);
	char MyString[100];
	WideCharToMultiByte(CP_UTF8, 0, L"ȣ��: �ȳ��ϼ��� ����.", -1, MyString, 100, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "ParkTalk/Bold.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(22);
	this->addChild(name, 3);


	auto textA_item = MenuItemImage::create(
		"ParkTalk/ok_button.png",
		"ParkTalk/ok_buttonpr.png",
		CC_CALLBACK_1(ParkTalk::storyBBB, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(132);
	this->addChild(text, 5);
}
void ParkTalk::storyBBB(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);

	removeChildByTag(132);
	removeChildByTag(22);

	char MyString[200];
	WideCharToMultiByte(CP_UTF8, 0, L"���� : ȣ���̱���! ���� ���� ���� �ʴ�?", -1, MyString, 200, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "ParkTalk/Bold.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(23);
	this->addChild(name, 3);


	auto textA_item = MenuItemImage::create(
		"ParkTalk/ok_button.png",
		"ParkTalk/ok_buttonpr.png",
		CC_CALLBACK_1(ParkTalk::storyBBBB, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(133);
	this->addChild(text, 5);
}
void ParkTalk::storyBBBB(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);

	removeChildByTag(133);
	removeChildByTag(23);

	char MyString[100];
	WideCharToMultiByte(CP_UTF8, 0, L"ȣ�� : �������� ��å�Ͻô� �ſ���?", -1, MyString, 100, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "ParkTalk/Bold.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(24);
	this->addChild(name, 3);


	auto textA_item = MenuItemImage::create(
		"ParkTalk/ok_button.png",
		"ParkTalk/ok_buttonpr.png",
		CC_CALLBACK_1(ParkTalk::storyBBBBB, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(134);
	this->addChild(text, 5);
}
void ParkTalk::storyBBBBB(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);

	removeChildByTag(134);
	removeChildByTag(24);

	char MyString[100];
	WideCharToMultiByte(CP_UTF8, 0, L"���� : �׷�. ų���� ������ �ʹٰ� �ؼ�.", -1, MyString, 100, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "ParkTalk/Bold.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(25);
	this->addChild(name, 3);


	auto textA_item = MenuItemImage::create(
		"ParkTalk/ok_button.png",
		"ParkTalk/ok_buttonpr.png",
		CC_CALLBACK_1(ParkTalk::storyBBBBBB, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(135);
	this->addChild(text, 5);
}
void ParkTalk::storyBBBBBB(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);

	removeChildByTag(135);
	removeChildByTag(25);

	char MyString[100];
	WideCharToMultiByte(CP_UTF8, 0, L"ȣ�� : �ȳ� ų����~", -1, MyString, 100, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "ParkTalk/Bold.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(26);
	this->addChild(name, 3);


	auto textA_item = MenuItemImage::create(
		"ParkTalk/ok_button.png",
		"ParkTalk/ok_buttonpr.png",
		CC_CALLBACK_1(ParkTalk::storyBBBBBBB, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(136);
	this->addChild(text, 5);
}
void ParkTalk::storyBBBBBBB(Ref * pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);

	removeChildByTag(136);
	removeChildByTag(26);

	char MyString[100];
	WideCharToMultiByte(CP_UTF8, 0, L"ų���� : ����!\n\n(ģ�е��� 12 ����Ͽ����ϴ�.)", -1, MyString, 100, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "ParkTalk/Bold.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(27);
	this->addChild(name, 3);


	auto textA_item = MenuItemImage::create(
		"ParkTalk/ok_button.png",
		"ParkTalk/ok_buttonpr.png",
		CC_CALLBACK_1(ParkTalk::GoHome, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(137);
	this->addChild(text, 5);

	Singletons::getInstance()->m_friendly = Singletons::getInstance()->m_friendly + 12;
}
 // ������ ��ȭ�� 2
void ParkTalk::storyB_1(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);

	removeChildByTag(130);
	removeChildByTag(21);

	char MyString[200];
	WideCharToMultiByte(CP_UTF8, 0, L"(���� Ŀ�ٶ� ��ü�� �����ؿԴ�!!)", -1, MyString, 200, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "ParkTalk/Bold.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(21);
	this->addChild(name, 3);


	auto textA_item = MenuItemImage::create(
		"ParkTalk/ok_button.png",
		"ParkTalk/ok_buttonpr.png",
		CC_CALLBACK_1(ParkTalk::storyBB_1, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(131);
	this->addChild(text, 5);

	Sprite* mainchr = Sprite::create("ParkTalk/park_chara2.png");
	mainchr->setAnchorPoint(Point(0.5, 0));
	mainchr->setPosition(Point(800, 0));
	mainchr->setTag(231);
	this->addChild(mainchr, 1);
}
void ParkTalk::storyBB_1(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);

	removeChildByTag(131);
	removeChildByTag(21);
	char MyString[100];
	WideCharToMultiByte(CP_UTF8, 0, L"ų���� : ����!", -1, MyString, 100, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "ParkTalk/Bold.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(22);
	this->addChild(name, 3);


	auto textA_item = MenuItemImage::create(
		"ParkTalk/ok_button.png",
		"ParkTalk/ok_buttonpr.png",
		CC_CALLBACK_1(ParkTalk::storyBBB_1, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(132);
	this->addChild(text, 5);
}
void ParkTalk::storyBBB_1(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);

	removeChildByTag(132);
	removeChildByTag(22);

	char MyString[100];
	WideCharToMultiByte(CP_UTF8, 0, L"ȣ�� : ���! ��¦�̾� ų�����ݾ�?", -1, MyString, 100, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "ParkTalk/Bold.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(23);
	this->addChild(name, 3);


	auto textA_item = MenuItemImage::create(
		"ParkTalk/ok_button.png",
		"ParkTalk/ok_buttonpr.png",
		CC_CALLBACK_1(ParkTalk::storyBBBB_1, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(133);
	this->addChild(text, 5);
}
void ParkTalk::storyBBBB_1(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);

	removeChildByTag(133);
	removeChildByTag(23);

	char MyString[100];
	WideCharToMultiByte(CP_UTF8, 0, L"ų���� : ������..", -1, MyString, 100, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "ParkTalk/Bold.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(24);
	this->addChild(name, 3);


	auto textA_item = MenuItemImage::create(
		"ParkTalk/ok_button.png",
		"ParkTalk/ok_buttonpr.png",
		CC_CALLBACK_1(ParkTalk::storyBBBBB_1, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(134);
	this->addChild(text, 5);
}
void ParkTalk::storyBBBBB_1(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);

	removeChildByTag(134);
	removeChildByTag(24);

	char MyString[100];
	WideCharToMultiByte(CP_UTF8, 0, L"ȣ�� : ���� �����ĳ��°ž�?", -1, MyString, 100, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "ParkTalk/Bold.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(25);
	this->addChild(name, 3);


	auto textA_item = MenuItemImage::create(
		"ParkTalk/ok_button.png",
		"ParkTalk/ok_buttonpr.png",
		CC_CALLBACK_1(ParkTalk::storyBBBBB_2, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(135);
	this->addChild(text, 5);
}
void ParkTalk::storyBBBBB_2(Ref * pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);

	removeChildByTag(135);
	removeChildByTag(25);

	char MyString[300];
	WideCharToMultiByte(CP_UTF8, 0, L"���� : ����... ȣ���� �װ� ����ᱸ��. �༮�� ���ڱ� �پ��...", -1, MyString, 300, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "ParkTalk/Bold.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(26);
	this->addChild(name, 3);


	auto textA_item = MenuItemImage::create(
		"ParkTalk/ok_button.png",
		"ParkTalk/ok_buttonpr.png",
		CC_CALLBACK_1(ParkTalk::storyBBBBB_3, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(136);
	this->addChild(text, 5);
}
void ParkTalk::storyBBBBB_3(Ref * pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);

	removeChildByTag(136);
	removeChildByTag(26);

	char MyString[300];
	WideCharToMultiByte(CP_UTF8, 0, L"ȣ�� : ����.. Ȱ�����׿�. �������� ����������~\n\n(ģ�е��� 11 ����Ͽ����ϴ�.)", -1, MyString, 300, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "ParkTalk/Bold.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(27);
	this->addChild(name, 3);


	auto textA_item = MenuItemImage::create(
		"ParkTalk/ok_button.png",
		"ParkTalk/ok_buttonpr.png",
		CC_CALLBACK_1(ParkTalk::GoHome, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(137);
	this->addChild(text, 5);

	Singletons::getInstance()->m_friendly = Singletons::getInstance()->m_friendly + 11;
}
 // ������ ��ȭ�� 1
void ParkTalk::storyC(Ref * pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);

	removeChildByTag(130);
	removeChildByTag(21);

	char MyString[200];
	WideCharToMultiByte(CP_UTF8, 0, L"(�������� ������.)", -1, MyString, 200, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "ParkTalk/Bold.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(21);
	this->addChild(name, 3);


	auto textA_item = MenuItemImage::create(
		"ParkTalk/ok_button.png",
		"ParkTalk/ok_buttonpr.png",
		CC_CALLBACK_1(ParkTalk::storyC1, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(131);
	this->addChild(text, 5);

	Sprite* mainchr = Sprite::create("ParkTalk/park_chara3.png");
	mainchr->setAnchorPoint(Point(0.5, 0));
	mainchr->setPosition(Point(800, 0));
	mainchr->setTag(231);
	this->addChild(mainchr, 1);
}
void ParkTalk::storyC1(Ref * pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);

	removeChildByTag(131);
	removeChildByTag(21);
	char MyString[100];
	WideCharToMultiByte(CP_UTF8, 0, L"������ : ����...", -1, MyString, 100, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "ParkTalk/Bold.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(22);
	this->addChild(name, 3);


	auto textA_item = MenuItemImage::create(
		"ParkTalk/ok_button.png",
		"ParkTalk/ok_buttonpr.png",
		CC_CALLBACK_1(ParkTalk::storyC2, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(132);
	this->addChild(text, 5);
}
void ParkTalk::storyC2(Ref * pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);

	removeChildByTag(132);
	removeChildByTag(22);

	char MyString[100];
	WideCharToMultiByte(CP_UTF8, 0, L"ȣ�� : ���� ���̿���?", -1, MyString, 100, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "ParkTalk/Bold.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(23);
	this->addChild(name, 3);


	auto textA_item = MenuItemImage::create(
		"ParkTalk/ok_button.png",
		"ParkTalk/ok_buttonpr.png",
		CC_CALLBACK_1(ParkTalk::storyC3, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(133);
	this->addChild(text, 5);
}
void ParkTalk::storyC3(Ref * pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);

	removeChildByTag(133);
	removeChildByTag(23);

	char MyString[200];
	WideCharToMultiByte(CP_UTF8, 0, L"������ : �ǿ��̾�... �� ���� ����ϸ� ���ڴ�...", -1, MyString, 200, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "ParkTalk/Bold.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(24);
	this->addChild(name, 3);


	auto textA_item = MenuItemImage::create(
		"ParkTalk/ok_button.png",
		"ParkTalk/ok_buttonpr.png",
		CC_CALLBACK_1(ParkTalk::storyC4, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(134);
	this->addChild(text, 5);
}
void ParkTalk::storyC4(Ref * pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);

	removeChildByTag(134);
	removeChildByTag(24);

	char MyString[200];
	WideCharToMultiByte(CP_UTF8, 0, L"ȣ�� : ���� �ص帱 �� �ִ� ���̾��׿�..", -1, MyString, 200, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "ParkTalk/Bold.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(25);
	this->addChild(name, 3);


	auto textA_item = MenuItemImage::create(
		"ParkTalk/ok_button.png",
		"ParkTalk/ok_buttonpr.png",
		CC_CALLBACK_1(ParkTalk::storyC5, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(135);
	this->addChild(text, 5);
}
void ParkTalk::storyC5(Ref * pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);

	removeChildByTag(135);
	removeChildByTag(25);

	char MyString[400];
	WideCharToMultiByte(CP_UTF8, 0, L"������ : �׷�... �� �� ������ �뷡�� ���°ž�!\n������ ������ �÷��� �̾߱�! ", -1, MyString, 400, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "ParkTalk/Bold.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(26);
	this->addChild(name, 3);


	auto textA_item = MenuItemImage::create(
		"ParkTalk/ok_button.png",
		"ParkTalk/ok_buttonpr.png",
		CC_CALLBACK_1(ParkTalk::storyC6, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(136);
	this->addChild(text, 5);
}
void ParkTalk::storyC6(Ref * pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);

	removeChildByTag(136);
	removeChildByTag(26);

	char MyString[400];
	WideCharToMultiByte(CP_UTF8, 0, L"ȣ�� : (���� �뷡�� ũ�� ���� �� �� ������)\n\n(ģ�е��� 11 ����Ͽ����ϴ�.)", -1, MyString, 400, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "ParkTalk/Bold.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(27);
	this->addChild(name, 3);


	auto textA_item = MenuItemImage::create(
		"ParkTalk/ok_button.png",
		"ParkTalk/ok_buttonpr.png",
		CC_CALLBACK_1(ParkTalk::GoHome, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(137);
	this->addChild(text, 5);

	Singletons::getInstance()->m_friendly = Singletons::getInstance()->m_friendly + 11;
}
// ������ ��ȭ�� 2
void ParkTalk::storyC_1(Ref * pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);

	removeChildByTag(130);
	removeChildByTag(21);

	char MyString[200];
	WideCharToMultiByte(CP_UTF8, 0, L"(�������� ������.)", -1, MyString, 200, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "ParkTalk/Bold.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(21);
	this->addChild(name, 3);


	auto textA_item = MenuItemImage::create(
		"ParkTalk/ok_button.png",
		"ParkTalk/ok_buttonpr.png",
		CC_CALLBACK_1(ParkTalk::storyC1_1, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(131);
	this->addChild(text, 5);

	Sprite* mainchr = Sprite::create("ParkTalk/park_chara3.png");
	mainchr->setAnchorPoint(Point(0.5, 0));
	mainchr->setPosition(Point(800, 0));
	mainchr->setTag(231);
	this->addChild(mainchr, 1);
}
void ParkTalk::storyC1_1(Ref * pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);

	removeChildByTag(131);
	removeChildByTag(21);
	char MyString[400];
	WideCharToMultiByte(CP_UTF8, 0, L"������ : ���� ȣ���� �� ��ģ �����.\n��.��.ģ.��. ��ħ ī���� �Գ�?", -1, MyString, 400, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "ParkTalk/Bold.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(22);
	this->addChild(name, 3);


	auto textA_item = MenuItemImage::create(
		"ParkTalk/ok_button.png",
		"ParkTalk/ok_buttonpr.png",
		CC_CALLBACK_1(ParkTalk::storyC2_1, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(132);
	this->addChild(text, 5);
}
void ParkTalk::storyC2_1(Ref * pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);

	removeChildByTag(132);
	removeChildByTag(22);

	char MyString[400];
	WideCharToMultiByte(CP_UTF8, 0, L"������ : ��! ..... ȣ����... ����.... \n������ ������ڴµ�... ��� ����....", -1, MyString, 400, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "ParkTalk/Bold.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(23);
	this->addChild(name, 3);


	auto textA_item = MenuItemImage::create(
		"ParkTalk/ok_button.png",
		"ParkTalk/ok_buttonpr.png",
		CC_CALLBACK_1(ParkTalk::storyC3_1, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(133);
	this->addChild(text, 5);
}
void ParkTalk::storyC3_1(Ref * pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);

	removeChildByTag(133);
	removeChildByTag(23);

	char MyString[300];
	WideCharToMultiByte(CP_UTF8, 0, L"ȣ�� :  ���� �� �𸣰ڳ׿�... ���ֿ� ���� �ƴ°� ���.", -1, MyString, 300, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "ParkTalk/Bold.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(24);
	this->addChild(name, 3);


	auto textA_item = MenuItemImage::create(
		"ParkTalk/ok_button.png",
		"ParkTalk/ok_buttonpr.png",
		CC_CALLBACK_1(ParkTalk::storyC4_1, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(134);
	this->addChild(text, 5);
}
void ParkTalk::storyC4_1(Ref * pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);

	removeChildByTag(134);
	removeChildByTag(24);

	char MyString[300];
	WideCharToMultiByte(CP_UTF8, 0, L"������ : ����.. �׷�... �� ���� �ٽ� ������ ������ �ڴ�.", -1, MyString, 300, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "ParkTalk/Bold.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(25);
	this->addChild(name, 3);


	auto textA_item = MenuItemImage::create(
		"ParkTalk/ok_button.png",
		"ParkTalk/ok_buttonpr.png",
		CC_CALLBACK_1(ParkTalk::storyC5_1, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(135);
	this->addChild(text, 5);
}
void ParkTalk::storyC5_1(Ref * pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);

	removeChildByTag(135);
	removeChildByTag(25);

	char MyString[400];
	WideCharToMultiByte(CP_UTF8, 0, L"ȣ�� : (��ø����� �� ����.)\n\n(ģ�е��� 13 ����Ͽ����ϴ�.)", -1, MyString, 400, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "ParkTalk/Bold.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(26);
	this->addChild(name, 3);


	auto textA_item = MenuItemImage::create(
		"ParkTalk/ok_button.png",
		"ParkTalk/ok_buttonpr.png",
		CC_CALLBACK_1(ParkTalk::GoHome, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(136);
	this->addChild(text, 5);

	Singletons::getInstance()->m_friendly = Singletons::getInstance()->m_friendly + 13;
}
 // ���� ����
void ParkTalk::storyD(Ref * pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);

	removeChildByTag(130);
	removeChildByTag(21);

	char MyString[200];
	WideCharToMultiByte(CP_UTF8, 0, L"(��ٴڿ� ������ �����⸦ �ֿ� �����ߴ�.)", -1, MyString, 200, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "ParkTalk/Bold.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(21);
	this->addChild(name, 3);


	auto textA_item = MenuItemImage::create(
		"ParkTalk/ok_button.png",
		"ParkTalk/ok_buttonpr.png",
		CC_CALLBACK_1(ParkTalk::storyD1, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(131);
	this->addChild(text, 5);
}
void ParkTalk::storyD1(Ref * pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);

	removeChildByTag(131);
	removeChildByTag(21);
	char MyString[400];
	WideCharToMultiByte(CP_UTF8, 0, L"ȣ�� : �ʹ��ϳ� �����. ���������� �ִµ� ������..\n\n(�μ��� 8 ����Ͽ����ϴ�.)", -1, MyString, 400, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "ParkTalk/Bold.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(22);
	this->addChild(name, 3);


	auto textA_item = MenuItemImage::create(
		"ParkTalk/ok_button.png",
		"ParkTalk/ok_buttonpr.png",
		CC_CALLBACK_1(ParkTalk::storyD2, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(132);
	this->addChild(text, 5);

	Singletons::getInstance()->m_insung = Singletons::getInstance()->m_insung + 8;
}
void ParkTalk::storyD2(Ref * pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);

	removeChildByTag(132);
	removeChildByTag(22);

	char MyString[400];
	WideCharToMultiByte(CP_UTF8, 0, L"�������� �ҸӴϰ� ���� �뵷�� �ּ̽��ϴ�.\n\n(10000�� ȹ���߽��ϴ�.)", -1, MyString, 400, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "ParkTalk/Bold.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(23);
	this->addChild(name, 3);


	auto textA_item = MenuItemImage::create(
		"ParkTalk/ok_button.png",
		"ParkTalk/ok_buttonpr.png",
		CC_CALLBACK_1(ParkTalk::GoHome, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(133);
	this->addChild(text, 5);

	Singletons::getInstance()->money = Singletons::getInstance()->money + 10000;
}

void ParkTalk::storyfin(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);

	removeChildByTag(132);
	removeChildByTag(22);
	char MyString[100];
	WideCharToMultiByte(CP_UTF8, 0, L"", -1, MyString, 100, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "ParkTalk/Bold.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(23);
	this->addChild(name, 3);


	auto textA_item = MenuItemImage::create(
		"ParkTalk/ok_button.png",
		"ParkTalk/ok_buttonpr.png",
		CC_CALLBACK_1(ParkTalk::GoHome, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(133);
	this->addChild(text, 5);
}
void ParkTalk::GoHome(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);

	// NextDayScene���� ����
	Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
	Director::getInstance()->replaceScene(NextDayScene::createScene());
}
