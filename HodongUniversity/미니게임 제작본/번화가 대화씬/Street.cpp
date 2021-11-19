#include "Street.h"
#include "SimpleAudioEngine.h"

//���� �Ҷ�� �� �ʿ�
using namespace CocosDenshion;
USING_NS_CC;

Scene* Street::createScene()
{
	auto scene = Scene::create();
	auto layer = Street::create();
	scene->addChild(layer);

	return scene;
}

bool Street::init()
{

	if (!Layer::init())
	{
		return false;
	}

	visibleSize = Director::getInstance()->getVisibleSize();
	origin = Director::getInstance()->getVisibleOrigin();

	InitBackGround();
	InitMenu();

	//�������
	//SimpleAudioEngine::getInstance()->playBackgroundMusic("Street/IntroBackSound.mp3", true);

	return true;
}
void Street::InitBackGround()
{
	auto sprite = Sprite::create("Street/inside_star.png");
	sprite->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	this->addChild(sprite, 0);
}
// ��Ʈ�� ����â
void Street::InitMenu()
{
	int i, num;

	srand((double)time(NULL));
	for (i = 0; i < 1; i++)
	{
		num = rand() % 5 + 1;
	}

	// ��â�� ��ȭ 1
	if (num == 1)
	{
		auto textA_item = MenuItemImage::create(
			"Street/ok_button.png",
			"Street/ok_buttonpr.png",
			CC_CALLBACK_1(Street::storyA, this));
		textA_item->setAnchorPoint(Point(0.5, 0.5));
		textA_item->setPosition(Point(950, 65));

		auto text = Menu::create(textA_item, NULL);
		text->setAnchorPoint(Point(0.5, 0.5));
		text->setPosition(Point(0, 0));
		text->setTag(130);
		this->addChild(text, 5);

	}
	// ��â�� ��ȭ 2
	if (num == 2)
	{
		auto textA_item = MenuItemImage::create(
			"Street/ok_button.png",
			"Street/ok_buttonpr.png",
			CC_CALLBACK_1(Street::storyA_1, this));
		textA_item->setAnchorPoint(Point(0.5, 0.5));
		textA_item->setPosition(Point(950, 65));

		auto text = Menu::create(textA_item, NULL);
		text->setAnchorPoint(Point(0.5, 0.5));
		text->setPosition(Point(0, 0));
		text->setTag(130);
		this->addChild(text, 5);
	}
	// ��â�� ��ȭ 3
	if (num == 3)
	{
		auto textA_item = MenuItemImage::create(
			"Street/ok_button.png",
			"Street/ok_buttonpr.png",
			CC_CALLBACK_1(Street::storyB, this));
		textA_item->setAnchorPoint(Point(0.5, 0.5));
		textA_item->setPosition(Point(950, 65));

		auto text = Menu::create(textA_item, NULL);
		text->setAnchorPoint(Point(0.5, 0.5));
		text->setPosition(Point(0, 0));
		text->setTag(130);
		this->addChild(text, 5);
	}
	// ������ ��ȭ 1
	if (num == 4)
	{
		auto textA_item = MenuItemImage::create(
			"Street/ok_button.png",
			"Street/ok_buttonpr.png",
			CC_CALLBACK_1(Street::storyB_1, this));
		textA_item->setAnchorPoint(Point(0.5, 0.5));
		textA_item->setPosition(Point(950, 65));

		auto text = Menu::create(textA_item, NULL);
		text->setAnchorPoint(Point(0.5, 0.5));
		text->setPosition(Point(0, 0));
		text->setTag(130);
		this->addChild(text, 5);
	}
	// ������ ��ȭ 2
	if (num == 5)
	{
		auto textA_item = MenuItemImage::create(
			"Street/ok_button.png",
			"Street/ok_buttonpr.png",
			CC_CALLBACK_1(Street::storyC, this));
		textA_item->setAnchorPoint(Point(0.5, 0.5));
		textA_item->setPosition(Point(950, 65));

		auto text = Menu::create(textA_item, NULL);
		text->setAnchorPoint(Point(0.5, 0.5));
		text->setPosition(Point(0, 0));
		text->setTag(130);
		this->addChild(text, 5);
	}

	// �ؽ�Ʈ â
	auto sprite = Sprite::create("Street/UI_Textlblack.png");
	sprite->setAnchorPoint(Point(0.5, 0.5));
	sprite->setPosition(Point(510, 100));
	sprite->setTag(200);
	this->addChild(sprite, 2);

	// ���� ĳ����
	Sprite* mainchr = Sprite::create("Street/main_char.png");
	mainchr->setAnchorPoint(Point(0.5, 0));
	mainchr->setPosition(Point(120, 80));
	mainchr->setTag(166);
	this->addChild(mainchr, 1);

	char MyString[200];
	WideCharToMultiByte(CP_UTF8, 0, L"ȣ��: ���� ��ȭ����~ ���� ����!!", -1, MyString, 200, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "Street/ABC.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(21);
	this->addChild(name, 3);
}
// ��â�� ��ȭ�� 1
void Street::storyA(Ref *pSender)
{
	removeChildByTag(130);
	removeChildByTag(21);

	char MyString[100];
	WideCharToMultiByte(CP_UTF8, 0, L"(��â���� ������.)", -1, MyString, 100, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "Street/ABC.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(21);
	this->addChild(name, 3);


	auto textA_item = MenuItemImage::create(
		"Street/ok_button.png",
		"Street/ok_buttonpr.png",
		CC_CALLBACK_1(Street::storyAA, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(131);
	this->addChild(text, 5);

	Sprite* mainchr = Sprite::create("Street/inside_chara1.png");
	mainchr->setAnchorPoint(Point(0.5, 0));
	mainchr->setPosition(Point(800, 0));
	mainchr->setTag(231);
	this->addChild(mainchr, 1);
}
void Street::storyAA(Ref *pSender)
{
	removeChildByTag(131);
	removeChildByTag(21);

	char MyString[200];
	WideCharToMultiByte(CP_UTF8, 0, L"â�� : ���� ȣ��~ ���� ���Ϸ� ���Ծ�?", -1, MyString, 200, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "Street/ABC.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(22);
	this->addChild(name, 3);


	auto textA_item = MenuItemImage::create(
		"Street/ok_button.png",
		"Street/ok_buttonpr.png",
		CC_CALLBACK_1(Street::storyAAA, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(132);
	this->addChild(text, 5);

}
void Street::storyAAA(Ref *pSender)
{
	removeChildByTag(132);
	removeChildByTag(22);

	char MyString[200];
	WideCharToMultiByte(CP_UTF8, 0, L"ȣ�� : �׳� �� �� ��������~ �� Ȥ�� �ٺ�? ", -1, MyString, 200, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "Street/ABC.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(23);
	this->addChild(name, 3);


	auto textA_item = MenuItemImage::create(
		"Street/ok_button.png",
		"Street/ok_buttonpr.png",
		CC_CALLBACK_1(Street::storyAAAA, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(133);
	this->addChild(text, 5);
}
void Street::storyAAAA(Ref *pSender)
{
	removeChildByTag(133);
	removeChildByTag(23);

	char MyString[100];
	WideCharToMultiByte(CP_UTF8, 0, L"â�� : �ƴ�? ��?", -1, MyString, 100, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "Street/ABC.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(24);
	this->addChild(name, 3);


	auto textA_item = MenuItemImage::create(
		"Street/ok_button.png",
		"Street/ok_buttonpr.png",
		CC_CALLBACK_1(Street::storyAAAAA, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(134);
	this->addChild(text, 5);
}
void Street::storyAAAAA(Ref *pSender)
{
	removeChildByTag(134);
	removeChildByTag(24);

	char MyString[400];
	WideCharToMultiByte(CP_UTF8, 0, L"ȣ�� : �׷� ���̳� ���ֶ� ����", -1, MyString, 400, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "Street/ABC.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(25);
	this->addChild(name, 3);


	auto textA_item = MenuItemImage::create(
		"Street/ok_button.png",
		"Street/ok_buttonpr.png",
		CC_CALLBACK_1(Street::storyAAAAAA, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(135);
	this->addChild(text, 5);
}
void Street::storyAAAAAA(Ref *pSender)
{
	removeChildByTag(135);
	removeChildByTag(25);

	char MyString[200];
	WideCharToMultiByte(CP_UTF8, 0, L"â�� : ������ ��... �׷� ���ٰ� ����.", -1, MyString, 200, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "Street/ABC.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(26);
	this->addChild(name, 3);


	auto textA_item = MenuItemImage::create(
		"Street/ok_button.png",
		"Street/ok_buttonpr.png",
		CC_CALLBACK_1(Street::storyAAAAAAA, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(136);
	this->addChild(text, 5);
}
void Street::storyAAAAAAA(Ref *pSender)
{
	removeChildByTag(136);
	removeChildByTag(26);

	char MyString[200];
	WideCharToMultiByte(CP_UTF8, 0, L"ȣ�� : ���� ��ť~~\n\n (ģ�е��� 12 �����Ͽ����ϴ�.)", -1, MyString, 200, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "Street/ABC.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(26);
	this->addChild(name, 3);


	auto textA_item = MenuItemImage::create(
		"Street/ok_button.png",
		"Street/ok_buttonpr.png",
		CC_CALLBACK_1(Street::storyfin, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(136);
	this->addChild(text, 5);
}
// ��â�� ��ȭ�� 2
void Street::storyA_1(Ref *pSender)
{
	removeChildByTag(130);
	removeChildByTag(21);

	char MyString[100];
	WideCharToMultiByte(CP_UTF8, 0, L"(��â���� ������.)", -1, MyString, 100, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "Street/ABC.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(21);
	this->addChild(name, 3);


	auto textA_item = MenuItemImage::create(
		"Street/ok_button.png",
		"Street/ok_buttonpr.png",
		CC_CALLBACK_1(Street::storyAA_1, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(131);
	this->addChild(text, 5);

	Sprite* mainchr = Sprite::create("Street/inside_chara1.png");
	mainchr->setAnchorPoint(Point(0.5, 0));
	mainchr->setPosition(Point(800, 0));
	mainchr->setTag(231);
	this->addChild(mainchr, 1);
}
void Street::storyAA_1(Ref *pSender)
{
	removeChildByTag(131);
	removeChildByTag(21);
	char MyString[200];
	WideCharToMultiByte(CP_UTF8, 0, L"ȣ�� : ��. �� �͵� ���µ� ��ȭ�� ����?", -1, MyString, 200, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "Street/ABC.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(22);
	this->addChild(name, 3);


	auto textA_item = MenuItemImage::create(
		"Street/ok_button.png",
		"Street/ok_buttonpr.png",
		CC_CALLBACK_1(Street::storyAAA_1, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(132);
	this->addChild(text, 5);
}
void Street::storyAAA_1(Ref *pSender)
{
	removeChildByTag(132);
	removeChildByTag(22);

	char MyString[200];
	WideCharToMultiByte(CP_UTF8, 0, L"â�� : ���� ���̼� �� ��ȭ��... ��ģ�̶� ��.", -1, MyString, 200, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "Street/ABC.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(23);
	this->addChild(name, 3);


	auto textA_item = MenuItemImage::create(
		"Street/ok_button.png",
		"Street/ok_buttonpr.png",
		CC_CALLBACK_1(Street::storyAAAA_1, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(133);
	this->addChild(text, 5);
}
void Street::storyAAAA_1(Ref *pSender)
{
	removeChildByTag(133);
	removeChildByTag(23);

	char MyString[300];
	WideCharToMultiByte(CP_UTF8, 0, L"ȣ�� : ��ģ ���°� �˸鼭 �ʹ��ϳ�;;", -1, MyString, 300, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "Street/ABC.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(24);
	this->addChild(name, 3);


	auto textA_item = MenuItemImage::create(
		"Street/ok_button.png",
		"Street/ok_buttonpr.png",
		CC_CALLBACK_1(Street::storyAAAAA_1, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(134);
	this->addChild(text, 5);
}
void Street::storyAAAAA_1(Ref *pSender)
{
	removeChildByTag(134);
	removeChildByTag(24);

	char MyString[300];
	WideCharToMultiByte(CP_UTF8, 0, L"â�� : �ò��� �Ӹ�. �ǹ��̳� ����.", -1, MyString, 300, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "Street/ABC.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(25);
	this->addChild(name, 3);


	auto textA_item = MenuItemImage::create(
		"Street/ok_button.png",
		"Street/ok_buttonpr.png",
		CC_CALLBACK_1(Street::storyAAAAAA_1, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(135);
	this->addChild(text, 5);
}
void Street::storyAAAAAA_1(Ref *pSender)
{
	removeChildByTag(135);
	removeChildByTag(25);

	char MyString[200];
	WideCharToMultiByte(CP_UTF8, 0, L"ȣ�� : �׷�...\n\n (ģ�е��� 1 �����Ͽ����ϴ�.)", -1, MyString, 200, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "Street/ABC.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(26);
	this->addChild(name, 3);


	auto textA_item = MenuItemImage::create(
		"Street/ok_button.png",
		"Street/ok_buttonpr.png",
		CC_CALLBACK_1(Street::storyfin, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(136);
	this->addChild(text, 5);
}
// ��â�� ��ȭ�� 3
void Street::storyB(Ref *pSender)
{
	removeChildByTag(130);
	removeChildByTag(21);

	char MyString[100];
	WideCharToMultiByte(CP_UTF8, 0, L"(��â���� ������.)", -1, MyString, 100, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "Street/ABC.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(21);
	this->addChild(name, 3);


	auto textA_item = MenuItemImage::create(
		"Street/ok_button.png",
		"Street/ok_buttonpr.png",
		CC_CALLBACK_1(Street::storyBB, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(131);
	this->addChild(text, 5);

	Sprite* mainchr = Sprite::create("Street/inside_chara1.png");
	mainchr->setAnchorPoint(Point(0.5, 0));
	mainchr->setPosition(Point(800, 0));
	mainchr->setTag(231);
	this->addChild(mainchr, 1);
}
void Street::storyBB(Ref *pSender)
{
	removeChildByTag(131);
	removeChildByTag(21);
	char MyString[100];
	WideCharToMultiByte(CP_UTF8, 0, L"ȣ�� : �� �� ������...", -1, MyString, 100, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "Street/ABC.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(22);
	this->addChild(name, 3);


	auto textA_item = MenuItemImage::create(
		"Street/ok_button.png",
		"Street/ok_buttonpr.png",
		CC_CALLBACK_1(Street::storyBBB, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(132);
	this->addChild(text, 5);
}
void Street::storyBBB(Ref *pSender)
{
	removeChildByTag(132);
	removeChildByTag(22);

	char MyString[200];
	WideCharToMultiByte(CP_UTF8, 0, L"â�� : ��������� ����??", -1, MyString, 200, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "Street/ABC.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(23);
	this->addChild(name, 3);


	auto textA_item = MenuItemImage::create(
		"Street/ok_button.png",
		"Street/ok_buttonpr.png",
		CC_CALLBACK_1(Street::storyBBBB, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(133);
	this->addChild(text, 5);
}
void Street::storyBBBB(Ref *pSender)
{
	removeChildByTag(133);
	removeChildByTag(23);

	char MyString[100];
	WideCharToMultiByte(CP_UTF8, 0, L"ȣ�� : ������ ���е�...", -1, MyString, 100, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "Street/ABC.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(24);
	this->addChild(name, 3);


	auto textA_item = MenuItemImage::create(
		"Street/ok_button.png",
		"Street/ok_buttonpr.png",
		CC_CALLBACK_1(Street::storyBBBBB, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(134);
	this->addChild(text, 5);
}
void Street::storyBBBBB(Ref *pSender)
{
	removeChildByTag(134);
	removeChildByTag(24);

	char MyString[200];
	WideCharToMultiByte(CP_UTF8, 0, L"â�� : �׷� �ǰ��̶� �� ��. �ȴٰ� ��������", -1, MyString, 200, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "Street/ABC.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(25);
	this->addChild(name, 3);


	auto textA_item = MenuItemImage::create(
		"Street/ok_button.png",
		"Street/ok_buttonpr.png",
		CC_CALLBACK_1(Street::storyBBBBBB, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(135);
	this->addChild(text, 5);
}
void Street::storyBBBBBB(Ref *pSender)
{
	removeChildByTag(135);
	removeChildByTag(25);

	char MyString[100];
	WideCharToMultiByte(CP_UTF8, 0, L"ȣ�� : �׳� �������. ", -1, MyString, 100, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "Street/ABC.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(26);
	this->addChild(name, 3);


	auto textA_item = MenuItemImage::create(
		"Street/ok_button.png",
		"Street/ok_buttonpr.png",
		CC_CALLBACK_1(Street::storyBBBBBBB, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(136);
	this->addChild(text, 5);
}
void Street::storyBBBBBBB(Ref * pSender)
{
	removeChildByTag(136);
	removeChildByTag(26);

	char MyString[200];
	WideCharToMultiByte(CP_UTF8, 0, L"â�� : �̰̱�...\n\n(ģ�е��� 1 ����Ͽ����ϴ�.)", -1, MyString, 200, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "Street/ABC.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(27);
	this->addChild(name, 3);


	auto textA_item = MenuItemImage::create(
		"Street/ok_button.png",
		"Street/ok_buttonpr.png",
		CC_CALLBACK_1(Street::storyfin, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(137);
	this->addChild(text, 5);
}
// ������ ��ȭ�� 1
void Street::storyB_1(Ref *pSender)
{
	removeChildByTag(130);
	removeChildByTag(21);

	char MyString[200];
	WideCharToMultiByte(CP_UTF8, 0, L"(������ �ϴ� �������� �߰��ߴ�.)", -1, MyString, 200, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "Street/ABC.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(21);
	this->addChild(name, 3);


	auto textA_item = MenuItemImage::create(
		"Street/ok_button.png",
		"Street/ok_buttonpr.png",
		CC_CALLBACK_1(Street::storyBB_1, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(131);
	this->addChild(text, 5);

	Sprite* mainchr = Sprite::create("Street/inside_chara2.png");
	mainchr->setAnchorPoint(Point(0.5, 0));
	mainchr->setPosition(Point(800, 0));
	mainchr->setTag(231);
	this->addChild(mainchr, 1);
}
void Street::storyBB_1(Ref *pSender)
{
	removeChildByTag(131);
	removeChildByTag(21);
	char MyString[300];
	WideCharToMultiByte(CP_UTF8, 0, L"���� : Ŀ�Ǹ� �ʹ�~ ���� ���̳�����~\n ..... \n������ �׸� ���߰ڴ�.", -1, MyString, 300, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "Street/ABC.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(22);
	this->addChild(name, 3);


	auto textA_item = MenuItemImage::create(
		"Street/ok_button.png",
		"Street/ok_buttonpr.png",
		CC_CALLBACK_1(Street::storyBBB_1, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(132);
	this->addChild(text, 5);
}
void Street::storyBBB_1(Ref *pSender)
{
	removeChildByTag(132);
	removeChildByTag(22);

	char MyString[100];
	WideCharToMultiByte(CP_UTF8, 0, L"ȣ�� : ���� ����~", -1, MyString, 100, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "Street/ABC.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(23);
	this->addChild(name, 3);


	auto textA_item = MenuItemImage::create(
		"Street/ok_button.png",
		"Street/ok_buttonpr.png",
		CC_CALLBACK_1(Street::storyBBBB_1, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(133);
	this->addChild(text, 5);
}
void Street::storyBBBB_1(Ref *pSender)
{
	removeChildByTag(133);
	removeChildByTag(23);

	char MyString[200];
	WideCharToMultiByte(CP_UTF8, 0, L"���� : ȣ����! �� ���� ���ַ��°ž�? ����!", -1, MyString, 200, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "Street/ABC.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(24);
	this->addChild(name, 3);


	auto textA_item = MenuItemImage::create(
		"Street/ok_button.png",
		"Street/ok_buttonpr.png",
		CC_CALLBACK_1(Street::storyBBBBB_1, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(134);
	this->addChild(text, 5);
}
void Street::storyBBBBB_1(Ref *pSender)
{
	removeChildByTag(134);
	removeChildByTag(24);

	char MyString[200];
	WideCharToMultiByte(CP_UTF8, 0, L"ȣ�� : �ƴ� �� �� ���� ������~", -1, MyString, 200, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "Street/ABC.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(25);
	this->addChild(name, 3);


	auto textA_item = MenuItemImage::create(
		"Street/ok_button.png",
		"Street/ok_buttonpr.png",
		CC_CALLBACK_1(Street::storyBBBBB_2, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(135);
	this->addChild(text, 5);
}
void Street::storyBBBBB_2(Ref * pSender)
{
	removeChildByTag(135);
	removeChildByTag(25);

	char MyString[300];
	WideCharToMultiByte(CP_UTF8, 0, L"���� : ���� ���̳� ���ٰ� ����~", -1, MyString, 300, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "Street/ABC.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(26);
	this->addChild(name, 3);


	auto textA_item = MenuItemImage::create(
		"Street/ok_button.png",
		"Street/ok_buttonpr.png",
		CC_CALLBACK_1(Street::storyBBBBB_3, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(136);
	this->addChild(text, 5);
}
void Street::storyBBBBB_3(Ref * pSender)
{
	removeChildByTag(136);
	removeChildByTag(26);

	char MyString[300];
	WideCharToMultiByte(CP_UTF8, 0, L"ȣ�� : ��¥? �� ������~~\n\n(ģ�е��� 1 ����Ͽ����ϴ�.)", -1, MyString, 300, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "Street/ABC.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(27);
	this->addChild(name, 3);


	auto textA_item = MenuItemImage::create(
		"Street/ok_button.png",
		"Street/ok_buttonpr.png",
		CC_CALLBACK_1(Street::storyfin, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(137);
	this->addChild(text, 5);
}
// ������ ��ȭ�� 2
void Street::storyC(Ref * pSender)
{
	removeChildByTag(130);
	removeChildByTag(21);

	char MyString[200];
	WideCharToMultiByte(CP_UTF8, 0, L"(������ �ϴ� �������� �߰��ߴ�.)", -1, MyString, 200, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "Street/ABC.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(21);
	this->addChild(name, 3);


	auto textA_item = MenuItemImage::create(
		"Street/ok_button.png",
		"Street/ok_buttonpr.png",
		CC_CALLBACK_1(Street::storyC1, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(131);
	this->addChild(text, 5);

	Sprite* mainchr = Sprite::create("Street/inside_chara2.png");
	mainchr->setAnchorPoint(Point(0.5, 0));
	mainchr->setPosition(Point(800, 0));
	mainchr->setTag(231);
	this->addChild(mainchr, 1);
}
void Street::storyC1(Ref * pSender)
{
	removeChildByTag(131);
	removeChildByTag(21);
	char MyString[100];
	WideCharToMultiByte(CP_UTF8, 0, L"���� : ȣ����! �ȳ�~", -1, MyString, 100, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "Street/ABC.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(22);
	this->addChild(name, 3);


	auto textA_item = MenuItemImage::create(
		"Street/ok_button.png",
		"Street/ok_buttonpr.png",
		CC_CALLBACK_1(Street::storyC2, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(132);
	this->addChild(text, 5);
}
void Street::storyC2(Ref * pSender)
{
	removeChildByTag(132);
	removeChildByTag(22);

	char MyString[100];
	WideCharToMultiByte(CP_UTF8, 0, L"ȣ�� : ���õ� �����Ϸ� ���°ž�?", -1, MyString, 100, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "Street/ABC.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(23);
	this->addChild(name, 3);


	auto textA_item = MenuItemImage::create(
		"Street/ok_button.png",
		"Street/ok_buttonpr.png",
		CC_CALLBACK_1(Street::storyC3, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(133);
	this->addChild(text, 5);
}
void Street::storyC3(Ref * pSender)
{
	removeChildByTag(133);
	removeChildByTag(23);

	char MyString[400];
	WideCharToMultiByte(CP_UTF8, 0, L"���� : ��.. ���� ���� ������ ���ϱ� ���� �ȳ����� �����ڴ���...", -1, MyString, 400, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "Street/ABC.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(24);
	this->addChild(name, 3);


	auto textA_item = MenuItemImage::create(
		"Street/ok_button.png",
		"Street/ok_buttonpr.png",
		CC_CALLBACK_1(Street::storyC4, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(134);
	this->addChild(text, 5);
}
void Street::storyC4(Ref * pSender)
{
	removeChildByTag(134);
	removeChildByTag(24);

	char MyString[400];
	WideCharToMultiByte(CP_UTF8, 0, L"ȣ�� : �̷��� ���� ���� �Ǵ°� �ߴϾ�? �̸� ���� �޾ƾ߰ڴ°�?", -1, MyString, 400, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "Street/ABC.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(25);
	this->addChild(name, 3);


	auto textA_item = MenuItemImage::create(
		"Street/ok_button.png",
		"Street/ok_buttonpr.png",
		CC_CALLBACK_1(Street::storyC5, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(135);
	this->addChild(text, 5);
}
void Street::storyC5(Ref * pSender)
{
	removeChildByTag(135);
	removeChildByTag(25);

	char MyString[400];
	WideCharToMultiByte(CP_UTF8, 0, L"���� : ����������~ ��� ������ �ƴϾ���? ���� �� ���� ���� ", -1, MyString, 400, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "Street/ABC.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(26);
	this->addChild(name, 3);


	auto textA_item = MenuItemImage::create(
		"Street/ok_button.png",
		"Street/ok_buttonpr.png",
		CC_CALLBACK_1(Street::storyC6, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(136);
	this->addChild(text, 5);
}
void Street::storyC6(Ref * pSender)
{
	removeChildByTag(136);
	removeChildByTag(26);

	char MyString[400];
	WideCharToMultiByte(CP_UTF8, 0, L"ȣ�� : �׷�~ ������ ���� ��������! ����~\n\n(ģ�е��� 1 ����Ͽ����ϴ�.)", -1, MyString, 400, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "Street/ABC.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(27);
	this->addChild(name, 3);


	auto textA_item = MenuItemImage::create(
		"Street/ok_button.png",
		"Street/ok_buttonpr.png",
		CC_CALLBACK_1(Street::storyfin, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(137);
	this->addChild(text, 5);
}

void Street::storyfin(Ref *pSender)
{
	removeChildByTag(132);
	removeChildByTag(22);
	char MyString[100];
	WideCharToMultiByte(CP_UTF8, 0, L"", -1, MyString, 100, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "Street/ABC.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(23);
	this->addChild(name, 3);


	auto textA_item = MenuItemImage::create(
		"Street/ok_button.png",
		"Street/ok_buttonpr.png",
		CC_CALLBACK_1(Street::GoHome, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(133);
	this->addChild(text, 5);
}
void Street::GoHome(Ref *pSender)
{
	// NextDayScene���� ����
	Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
	Director::getInstance()->replaceScene(Street::createScene());
}
