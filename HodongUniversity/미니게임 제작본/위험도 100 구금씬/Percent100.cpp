#include "Percent100.h"
#include "SimpleAudioEngine.h"

//���� �Ҷ�� �� �ʿ�
using namespace CocosDenshion;
USING_NS_CC;

Scene* Percent100::createScene()
{
    auto scene = Scene::create();
    auto layer = Percent100::create();
    scene->addChild(layer);

    return scene;
}

bool Percent100::init()
{

    if ( !Layer::init() )
    {
        return false;
    }

	visibleSize = Director::getInstance()->getVisibleSize();
	origin      = Director::getInstance()->getVisibleOrigin();

	InitBackGround();
	InitMenu();

	// ȿ����
	SimpleAudioEngine::getInstance()->playEffect("Percent100/penalty_sound.mp3", false);

    return true;
}
void Percent100::InitBackGround()
{
	auto sprite = Sprite::create("Percent100/danger_back.png");
	sprite->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	this->addChild(sprite, 0);
}
// ��Ʈ�� ����â
void Percent100::InitMenu()
{
	auto textA_item = MenuItemImage::create(
		"Percent100/ok_button.png",
		"Percent100/ok_buttonpr.png",
		CC_CALLBACK_1(Percent100::storyA, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(130);
	this->addChild(text, 5);
	
	// �ؽ�Ʈ â
	auto sprite = Sprite::create("Percent100/UI_Textlblack.png");
	sprite->setAnchorPoint(Point(0.5, 0.5));
	sprite->setPosition(Point(510, 100));
	sprite->setTag(200);
	this->addChild(sprite, 2);

	char MyString[100];
	WideCharToMultiByte(CP_UTF8, 0, L"ȣ���� ���̸� ���� ü�����ߴ�..", -1, MyString, 100, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "Percent100/ABC.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(21);
	this->addChild(name, 3);
}

void Percent100::storyA(Ref *pSender)
{
	removeChildByTag(130);
	removeChildByTag(21);

	// ���� ĳ����
	Sprite* mainchr = Sprite::create("Percent100/main_char.png");
	mainchr->setAnchorPoint(Point(0.5, 0));
	mainchr->setPosition(Point(120, 80));
	mainchr->setTag(166);
	this->addChild(mainchr, 1);

	char MyString[200];
	WideCharToMultiByte(CP_UTF8, 0, L"ȣ�� : �������� �ȱ׷��ڽ��ϴ�.. �˼��մϴ�...", -1, MyString, 200, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "Percent100/ABC.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(21);
	this->addChild(name, 3);

	auto textA_item = MenuItemImage::create(
		"Percent100/ok_button.png",
		"Percent100/ok_buttonpr.png",
		CC_CALLBACK_1(Percent100::storyAA, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(131);
	this->addChild(text, 5);
}
void Percent100::storyAA(Ref *pSender)
{
	removeChildByTag(131);
	removeChildByTag(21);

	char MyString[200];
	WideCharToMultiByte(CP_UTF8, 0, L"(���ϴ�... �������� �� �����ؾ߰ھ�.)", -1, MyString, 200, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "Percent100/ABC.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(22);
	this->addChild(name, 3);


	auto textA_item = MenuItemImage::create(
		"Percent100/ok_button.png",
		"Percent100/ok_buttonpr.png",
		CC_CALLBACK_1(Percent100::storyAAA, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(132);
	this->addChild(text, 5);

}
void Percent100::storyAAA(Ref *pSender)
{
	removeChildByTag(132);
	removeChildByTag(22);

	char MyString[400];
	WideCharToMultiByte(CP_UTF8, 0, L"���ݰ� �Բ� ���� �г�Ƽ�� �޾Ҵ�.\n\n(�ɷ�ġ 10%, �� 30%�� �����մϴ�.)", -1, MyString, 400, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "Percent100/ABC.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(23);
	this->addChild(name, 3);


	auto textA_item = MenuItemImage::create(
		"Percent100/ok_button.png",
		"Percent100/ok_buttonpr.png",
		CC_CALLBACK_1(Percent100::GoHome, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(133);
	this->addChild(text, 5);
}

void Percent100::GoHome(Ref *pSender)
{
	// �ɷ�ġ 10%, �� 30% ���� �� ����

	// �ٸ� ������ ����
	Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
	Director::getInstance()->replaceScene(Percent100::createScene());
}
