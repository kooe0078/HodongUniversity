#include "Up2.h"
#include "SimpleAudioEngine.h"

//���� �Ҷ�� �� �ʿ�
using namespace CocosDenshion;
USING_NS_CC;

Scene* Up2::createScene()
{
	auto scene = Scene::create();
	auto layer = Up2::create();
	scene->addChild(layer);

	return scene;
}

bool Up2::init()
{

	if (!Layer::init())
	{
		return false;
	}

	InitBackGround();
	InitMenu();

	//�������
	//SimpleAudioEngine::getInstance()->playBackgroundMusic("MiniGameResources/MainBackSound.mp3", true);

	return true;
}
void Up2::InitBackGround()
{
	auto sprite = Sprite::create("LVUP/StuduntUnion.png");
	sprite->setPosition(Point(512, 384));
	this->addChild(sprite, 0);
}
void Up2::InitMenu()
{
	// ���� ��ư
	auto textA_item = MenuItemImage::create(
		"LVUP/ok_button.png",
		"LVUP/ok_buttonpr.png",
		CC_CALLBACK_1(Up2::story1, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(709);
	this->addChild(text, 5);

	// ȸ��
	Sprite* mainchr = Sprite::create("LVUP/student_chara2.png");
	mainchr->setAnchorPoint(Point(0.5, 0));
	mainchr->setPosition(Point(820, 10));
	mainchr->setTag(701);
	this->addChild(mainchr, 1);

	//�ؽ�Ʈ â
	auto sprite = Sprite::create("LVUP/UI_Textlblack.png");
	sprite->setAnchorPoint(Point(0.5, 0.5));
	sprite->setPosition(Point(510, 100));
	sprite->setTag(700);
	this->addChild(sprite, 2);

	// ĳ���� ���
	char MyString[200];
	WideCharToMultiByte(CP_UTF8, 0, L"������ : ȣ���� ���� �߳���~ ", -1, MyString, 200, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "LVUP/ABC.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(729);
	this->addChild(name, 3);
}
void Up2::story1(Ref * pSender)
{
	removeChildByTag(709);
	removeChildByTag(729);

	// ���� ĳ����
	Sprite* mainchr = Sprite::create("LVUP/main_char.png");
	mainchr->setAnchorPoint(Point(0.5, 0));
	mainchr->setPosition(Point(120, 80));
	mainchr->setTag(702);
	this->addChild(mainchr, 1);

	char MyString[100];
	WideCharToMultiByte(CP_UTF8, 0, L"ȣ�� : ����... �ʹ� ������� ������~", -1, MyString, 100, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "LVUP/ABC.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(730);
	this->addChild(name, 3);

	auto textA_item = MenuItemImage::create(
		"LVUP/ok_button.png",
		"LVUP/ok_buttonpr.png",
		CC_CALLBACK_1(Up2::story1_2, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(710);
	this->addChild(text, 5);
}
void Up2::story1_2(Ref * pSender)
{
	removeChildByTag(710);
	removeChildByTag(730);

	char MyString[100];
	WideCharToMultiByte(CP_UTF8, 0, L"������ : �л�ȸ�� �ѹ� �ڸ��� ��µ� �ѹ� �غ���? ���� ��õ���ٰ�~", -1, MyString, 100, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "LVUP/ABC.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(731);
	this->addChild(name, 3);

	auto textA_item = MenuItemImage::create(
		"LVUP/ok_button.png",
		"LVUP/ok_buttonpr.png",
		CC_CALLBACK_1(Up2::story1_3, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(711);
	this->addChild(text, 5);
}
void Up2::story1_3(Ref * pSender)
{
	removeChildByTag(731);
	removeChildByTag(711);

	char MyString[200];
	WideCharToMultiByte(CP_UTF8, 0, L"ȣ�� : ������? �� �ϰ�;��! �ϰ� ���ּ���!!", -1, MyString, 200, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "LVUP/ABC.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(732);
	this->addChild(name, 3);

	auto textA_item = MenuItemImage::create(
		"LVUP/ok_button.png",
		"LVUP/ok_buttonpr.png",
		CC_CALLBACK_1(Up2::story1_4, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(712);
	this->addChild(text, 5);
}
void Up2::story1_4(Ref * pSender)
{
	removeChildByTag(732);
	removeChildByTag(712);

	char MyString[400];
	WideCharToMultiByte(CP_UTF8, 0, L"������ : �������̳�. �׷�~ ��õ���ٰ�!", -1, MyString, 400, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "LVUP/ABC.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(733);
	this->addChild(name, 3);

	auto textA_item = MenuItemImage::create(
		"LVUP/ok_button.png",
		"LVUP/ok_buttonpr.png",
		CC_CALLBACK_1(Up2::story1_5, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(713);
	this->addChild(text, 5);
}
void Up2::story1_5(Ref * pSender)
{
	removeChildByTag(733);
	removeChildByTag(713);

	char MyString[100];
	WideCharToMultiByte(CP_UTF8, 0, L"ȣ�� : �����մϴ�! ������ �ϰڽ��ϴ�!!", -1, MyString, 100, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "LVUP/ABC.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(734);
	this->addChild(name, 3);

	auto textA_item = MenuItemImage::create(
		"LVUP/ok_button.png",
		"LVUP/ok_buttonpr.png",
		CC_CALLBACK_1(Up2::story1_6, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(714);
	this->addChild(text, 5);
}
void Up2::story1_6(Ref * pSender)
{
	removeChildByTag(734);
	removeChildByTag(714);

	char MyString[200];
	WideCharToMultiByte(CP_UTF8, 0, L"(ȣ���� �ѹ��� �Ǿ���.)", -1, MyString, 200, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "LVUP/ABC.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(735);
	this->addChild(name, 3);

	auto textA_item = MenuItemImage::create(
		"LVUP/ok_button.png",
		"LVUP/ok_buttonpr.png",
		CC_CALLBACK_1(Up2::story1_7, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(715);
	this->addChild(text, 5);
}
void Up2::story1_7(Ref * pSender)
{
	removeChildByTag(736);
	removeChildByTag(716);
	removeChildByTag(702);
	removeChildByTag(701);

	// �л�ȸ�� �̵� �ڵ�� ����
	Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
	Director::getInstance()->replaceScene(Up2::createScene());
}

