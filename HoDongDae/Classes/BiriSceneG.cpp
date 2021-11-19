#include "BiriSceneG.h"
#include "NextDayScene.h"
#include "SimpleAudioEngine.h"
#include "MainBiriScene.h"
#include "sinngleton.h"
//#include "MainScene.h"
//���� �Ҷ�� �� �ʿ�
using namespace CocosDenshion;
USING_NS_CC;

Scene* BiriSceneG::createScene()
{
    auto scene = Scene::create();
    auto layer = BiriSceneG::create();
    scene->addChild(layer);

    return scene;
}

bool BiriSceneG::init()
{

    if ( !Layer::init() )
    {
        return false;
    }

	visibleSize = Director::getInstance()->getVisibleSize();
	origin      = Director::getInstance()->getVisibleOrigin();

	InitBackGround();
	InitLabel();
	InitMenu();
	
	////��ġ ������ ���
	//auto listener = EventListenerTouchOneByOne::create();
	//listener->onTouchBegan = CC_CALLBACK_2(IntroScene::onTouchBegan, this);
	//Director::getInstance()->getEventDispatcher()->addEventListenerWithFixedPriority(listener, 1);

	//�������
	SimpleAudioEngine::getInstance()->playBackgroundMusic("sound/event sound2.mp3", true);

	/*this->scheduleOnce(schedule_selector(BiriSceneG::GoHome), 2.0f);
*/
    return true;
}
void BiriSceneG::update(float ft)
{
	//�� ��ü������ �ݺ� �Ǿ��ϴ� ����
}
void BiriSceneG::InitBackGround()
{
	auto sprite = Sprite::create("MiniGameResources//back_11.png");
	sprite->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	this->addChild(sprite, 0);
}
void BiriSceneG::InitLabel()
{
	
}
// ��Ʈ�� ����â
void BiriSceneG::InitMenu()
{
	//���丮Aâ
	auto storyA_item = MenuItemImage::create(
		"MiniGameResources/UI_Textlblack.png",
		"MiniGameResources/UI_Textlblack.png",

		CC_CALLBACK_1(BiriSceneG::storyAspr, this));
	storyA_item->setAnchorPoint(Point(0.5, 0.5));
	storyA_item->setPosition(Point(510, 100));

	auto storyA = Menu::create(storyA_item, NULL);
	storyA->setAnchorPoint(Point(0.5, 0.5));
	storyA->setPosition(Point(0, 0));
	storyA->setTag(4);
	this->addChild(storyA,2);

	char MyString[100];
	WideCharToMultiByte(CP_UTF8, 0, L"ȣ��: (������ �۰��ʴ�����ȸ�� �ִ³��̴�.)", -1, MyString, 100, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "fonts/Bold.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(21);
	this->addChild(name, 3);


	//����ĳ����
	Sprite* mainchr = Sprite::create("MiniGameResources/main_char.png");
	mainchr->setAnchorPoint(Point(0.5, 0));
	mainchr->setPosition(Point(120, 80));
	mainchr->setTag(166);
	this->addChild(mainchr, 1);

	auto textA_item = MenuItemImage::create(
		"MiniGameResources/ok_button.png",
		"MiniGameResources/ok_buttonpr.png",
		CC_CALLBACK_1(BiriSceneG::storyA, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(131);
	this->addChild(text, 5);
}
void BiriSceneG::storyAspr(Ref *pSender)
{

}

void BiriSceneG::storyA(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);
	//���þ�
	removeChildByTag(131);
	removeChildByTag(130);
	removeChildByTag(21);


	//����
	auto textA_item = MenuItemImage::create(
		"MiniGameResources/text_yes.png",
		"MiniGameResources/text_yes.png",
		CC_CALLBACK_1(BiriSceneG::storyAA, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(300, 105));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(133);
	this->addChild(text, 5);

	//�Ȱ���
	auto textB_item = MenuItemImage::create(
		"MiniGameResources/text_no.png",
		"MiniGameResources/text_no.png",
		CC_CALLBACK_1(BiriSceneG::storyAAAA, this));
	textB_item->setAnchorPoint(Point(0.5, 0.5));
	textB_item->setPosition(Point(700, 105));

	auto textB = Menu::create(textB_item, NULL);
	textB->setAnchorPoint(Point(0.5, 0.5));
	textB->setPosition(Point(0, 0));
	textB->setTag(134);
	this->addChild(textB, 5);



}
void BiriSceneG::storyAA(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);
	removeChildByTag(133);
	removeChildByTag(134);
	removeChildByTag(131);
	removeChildByTag(21);
	char MyString[100];
	WideCharToMultiByte(CP_UTF8, 0, L"ȣ��: �� ��ǰ�� ���� �ɿ��� �� ����.", -1, MyString, 100, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "fonts/Bold.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(22);
	this->addChild(name, 3);


	auto textA_item = MenuItemImage::create(
		"MiniGameResources/ok_button.png",
		"MiniGameResources/ok_buttonpr.png",
		CC_CALLBACK_1(BiriSceneG::storyAAA, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(132);
	this->addChild(text, 5);

}

void BiriSceneG::storyAAA(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);
	removeChildByTag(132);
	removeChildByTag(22);

	Sprite* mainchr = Sprite::create("MiniGameResources/friend1.png");
	mainchr->setAnchorPoint(Point(0.5, 0));
	mainchr->setPosition(Point(800, 0));
	mainchr->setTag(231);
	this->addChild(mainchr, 1);


	char MyString[100];
	WideCharToMultiByte(CP_UTF8, 0, L"�ϴ�: ȣ���� Ȥ�� �̰� ���� ������� �ƴ�?", -1, MyString, 100, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "fonts/Bold.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(23);
	this->addChild(name, 3);


	auto textA_item = MenuItemImage::create(
		"MiniGameResources/ok_button.png",
		"MiniGameResources/ok_buttonpr.png",
		CC_CALLBACK_1(BiriSceneG::storyAAAAAA, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(133);
	this->addChild(text, 5);
}
void BiriSceneG::storyAAAA(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);
	removeChildByTag(134);
	removeChildByTag(133);
	removeChildByTag(24);

	Singletons::getInstance()->backnum = 6;
	char MyString[100];
	WideCharToMultiByte(CP_UTF8, 0, L"ȣ��: (�̹����� ����~)", -1, MyString, 100, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "fonts/Bold.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(23);
	this->addChild(name, 3);


	auto textA_item = MenuItemImage::create(
		"MiniGameResources/ok_button.png",
		"MiniGameResources/ok_buttonpr.png",
		CC_CALLBACK_1(BiriSceneG::storyAAAAA, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(133);
	this->addChild(text, 5);
}
void BiriSceneG::storyAAAAA(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);
	log("start1 after delay");
	auto scene = TransitionCrossFade::create(1.5, MainBiriScene::createScene());
	Director::getInstance()->replaceScene(scene);
//Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
//Director::getInstance()->replaceScene(MainBiriScene::createScene());
}
void BiriSceneG::storyAAAAAA(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false); removeChildByTag(133);
	removeChildByTag(23);
	removeChildByTag(231);
	char MyString[100];
	WideCharToMultiByte(CP_UTF8, 0, L"ȣ��: �̰� ������!", -1, MyString, 100, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "fonts/Bold.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(26);
	this->addChild(name, 3);


	auto textA_item = MenuItemImage::create(
		"MiniGameResources/ok_button.png",
		"MiniGameResources/ok_buttonpr.png",
		CC_CALLBACK_1(BiriSceneG::storyAAAAAAA, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(136);
	this->addChild(text, 5);
}
void BiriSceneG::storyAAAAAAA(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);
	removeChildByTag(136);
	removeChildByTag(26);
	//��
	auto textA_item_1 = MenuItemImage::create(
		"MiniGameResources/texts13.png",
		"MiniGameResources/texts13.png",
		CC_CALLBACK_1(BiriSceneG::storyA_1, this));
	textA_item_1->setAnchorPoint(Point(0.5, 0.5));
	textA_item_1->setPosition(Point(240, 105));

	auto text_1 = Menu::create(textA_item_1, NULL);
	text_1->setAnchorPoint(Point(0.5, 0.5));
	text_1->setPosition(Point(0, 0));
	text_1->setTag(137);
	this->addChild(text_1, 5);
	//�뷡
	auto textA_item = MenuItemImage::create(
		"MiniGameResources/texts14.png",
		"MiniGameResources/texts14.png",
		CC_CALLBACK_1(BiriSceneG::storyA_2, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(760, 105));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(138);
	this->addChild(text, 5);
}

//�ϴ� ��ȭ��2
void BiriSceneG::storyA_1(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);
	//���ϴ� ��ȭ��1
	removeChildByTag(137);
	removeChildByTag(138);


	Sprite* mainchr = Sprite::create("MiniGameResources/friend1.png");
	mainchr->setAnchorPoint(Point(0.5, 0));
	mainchr->setPosition(Point(800, 0));
	mainchr->setTag(231);
	this->addChild(mainchr, 1);


	char MyString[100];
	WideCharToMultiByte(CP_UTF8, 0, L"�ϴ�: ...�̰� �ƹ������� ������ �ƴ� �� ������?", -1, MyString, 100, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "fonts/Bold.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(21);
	this->addChild(name, 3);


	auto textA_item = MenuItemImage::create(
		"MiniGameResources/ok_button.png",
		"MiniGameResources/ok_buttonpr.png",
		CC_CALLBACK_1(BiriSceneG::storyAA_1, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(131);
	this->addChild(text, 5);

	//Sprite* mainchr = Sprite::create("MiniGameResources/friend1.png");
	//mainchr->setAnchorPoint(Point(0.5, 0));
	//mainchr->setPosition(Point(800, 0));
	//mainchr->setTag(231);
	//this->addChild(mainchr, 1);
}
void BiriSceneG::storyAA_1(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);
	removeChildByTag(131);
	removeChildByTag(21);
	removeChildByTag(231);

	char MyString[100];
	WideCharToMultiByte(CP_UTF8, 0, L"ȣ��: ��~ �׷���?\n\n(��� �ɷ�ġ�� 45 �����Ͽ����ϴ�.)", -1, MyString, 100, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "fonts/Bold.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(22);
	this->addChild(name, 3);


	auto textA_item = MenuItemImage::create(
		"MiniGameResources/ok_button.png",
		"MiniGameResources/ok_buttonpr.png",
		CC_CALLBACK_1(BiriSceneG::GoHome, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(132);
	this->addChild(text, 5);

	Singletons::getInstance()->m_friendly = Singletons::getInstance()->m_friendly + 45;
	Singletons::getInstance()->m_hak = Singletons::getInstance()->m_hak + 45;
	Singletons::getInstance()->m_insung = Singletons::getInstance()->m_insung + 45;
	Singletons::getInstance()->m_jisik = Singletons::getInstance()->m_jisik + 45;
}

void BiriSceneG::storyfin(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);
	removeChildByTag(132);
	removeChildByTag(22);
	char MyString[100];
	WideCharToMultiByte(CP_UTF8, 0, L"", -1, MyString, 100, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "fonts/Bold.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(23);
	this->addChild(name, 3);


	auto textA_item = MenuItemImage::create(
		"MiniGameResources/ok_button.png",
		"MiniGameResources/ok_buttonpr.png",
		CC_CALLBACK_1(BiriSceneG::GoHome, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(133);
	this->addChild(text, 5);
}
//�ϴ� ��ȭ��3
void BiriSceneG::storyA_2(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);
	removeChildByTag(137);
	removeChildByTag(138);

	Sprite* mainchr = Sprite::create("MiniGameResources/friend1.png");
	mainchr->setAnchorPoint(Point(0.5, 0));
	mainchr->setPosition(Point(800, 0));
	mainchr->setTag(231);
	this->addChild(mainchr, 1);

	char MyString[100];
	WideCharToMultiByte(CP_UTF8, 0, L"�ϴ�: �׷�����~ ȣ���� �� ���� �ȶ��ϱ���!", -1, MyString, 100, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "fonts/Bold.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(21);
	this->addChild(name, 3);


	auto textA_item = MenuItemImage::create(
		"MiniGameResources/ok_button.png",
		"MiniGameResources/ok_buttonpr.png",
		CC_CALLBACK_1(BiriSceneG::storyAA_2, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(131);
	this->addChild(text, 5);

	//Sprite* mainchr = Sprite::create("MiniGameResources/friend1.png");
	//mainchr->setAnchorPoint(Point(0.5, 0));
	//mainchr->setPosition(Point(800, 0));
	//mainchr->setTag(231);
	//this->addChild(mainchr, 1);
}
void BiriSceneG::storyAA_2(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);
	removeChildByTag(131);
	removeChildByTag(21);
	removeChildByTag(231);

	char MyString[100];
	WideCharToMultiByte(CP_UTF8, 0, L"ȣ��: �� �⺻����~\n\n(��� �ɷ�ġ�� 15 �����Ͽ����ϴ�.)", -1, MyString, 100, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "fonts/Bold.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(22);
	this->addChild(name, 3);


	auto textA_item = MenuItemImage::create(
		"MiniGameResources/ok_button.png",
		"MiniGameResources/ok_buttonpr.png",
		CC_CALLBACK_1(BiriSceneG::GoHome, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(132);
	this->addChild(text, 5);

	Singletons::getInstance()->m_friendly = Singletons::getInstance()->m_friendly + 15;
	Singletons::getInstance()->m_hak = Singletons::getInstance()->m_hak + 15;
	Singletons::getInstance()->m_insung = Singletons::getInstance()->m_insung + 15;
	Singletons::getInstance()->m_jisik = Singletons::getInstance()->m_jisik + 15;
}

void BiriSceneG::GoHome(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);
	//log("start1 after delay");
	///*Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
	//Director::getInstance()->replaceScene(IntroSceneB::createScene());*/
	//auto scene = TransitionCrossFade::create(1.5, NextDayScene::createScene());
	//Director::getInstance()->replaceScene(scene);
	Singletons::getInstance()->day = Singletons::getInstance()->day + 2;;
	Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
	Director::getInstance()->replaceScene(NextDayScene::createScene());
}
	
	

void BiriSceneG::skipspr(Ref *pSender)
{
	
}
