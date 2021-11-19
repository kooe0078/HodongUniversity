#include "Percent100.h"
#include "SimpleAudioEngine.h"

//사운드 할라면 꼭 필요
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

	// 효과음
	SimpleAudioEngine::getInstance()->playEffect("Percent100/penalty_sound.mp3", false);

    return true;
}
void Percent100::InitBackGround()
{
	auto sprite = Sprite::create("Percent100/danger_back.png");
	sprite->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	this->addChild(sprite, 0);
}
// 인트로 선택창
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
	
	// 텍스트 창
	auto sprite = Sprite::create("Percent100/UI_Textlblack.png");
	sprite->setAnchorPoint(Point(0.5, 0.5));
	sprite->setPosition(Point(510, 100));
	sprite->setTag(200);
	this->addChild(sprite, 2);

	char MyString[100];
	WideCharToMultiByte(CP_UTF8, 0, L"호동은 덜미를 잡혀 체포당했다..", -1, MyString, 100, NULL, NULL);
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

	// 메인 캐릭터
	Sprite* mainchr = Sprite::create("Percent100/main_char.png");
	mainchr->setAnchorPoint(Point(0.5, 0));
	mainchr->setPosition(Point(120, 80));
	mainchr->setTag(166);
	this->addChild(mainchr, 1);

	char MyString[200];
	WideCharToMultiByte(CP_UTF8, 0, L"호동 : 다음부턴 안그러겠습니다.. 죄송합니다...", -1, MyString, 200, NULL, NULL);
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
	WideCharToMultiByte(CP_UTF8, 0, L"(분하다... 다음부턴 더 조심해야겠어.)", -1, MyString, 200, NULL, NULL);
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
	WideCharToMultiByte(CP_UTF8, 0, L"벌금과 함께 각종 패널티를 받았다.\n\n(능력치 10%, 돈 30%가 감소합니다.)", -1, MyString, 400, NULL, NULL);
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
	// 능력치 10%, 돈 30% 감소 식 적용

	// 다른 씬으로 변경
	Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
	Director::getInstance()->replaceScene(Percent100::createScene());
}
