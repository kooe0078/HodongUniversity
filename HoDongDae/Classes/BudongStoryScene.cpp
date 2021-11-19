#include "BudongStoryScene.h"
#include "NextDayScene.h"
#include "SimpleAudioEngine.h"
#include "sinngleton.h"
//#include "MainScene.h"
//���� �Ҷ�� �� �ʿ�
using namespace CocosDenshion;
USING_NS_CC;

Scene* BudongStoryScene::createScene()
{
    auto scene = Scene::create();
    auto layer = BudongStoryScene::create();
    scene->addChild(layer);

    return scene;
}

bool BudongStoryScene::init()
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
	SimpleAudioEngine::getInstance()->playBackgroundMusic("sound/invest sound.mp3", true);

	/*this->scheduleOnce(schedule_selector(BudongStoryScene::GoHome), 2.0f);
*/
    return true;
}
void BudongStoryScene::update(float ft)
{
	//�� ��ü������ �ݺ� �Ǿ��ϴ� ����
}
void BudongStoryScene::InitBackGround()
{
	auto sprite = Sprite::create("MiniGameResources//stock_exchange.png");
	sprite->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	this->addChild(sprite, 0);
}
void BudongStoryScene::InitLabel()
{

}
// ��Ʈ�� ����â
void BudongStoryScene::InitMenu()
{
	//if(Singletons::getInstance()->)

	int i, num;
	
	srand((long)time(NULL));
	for (i = 0; i < 1; i++)
	{
		num = rand() % 3 + 1;
	}
	
	//���ϴ� ��ȭ��1
	if (num == 1)
	{
		
		Sprite* mainchr = Sprite::create("MiniGameResources/main_char.png");
		mainchr->setAnchorPoint(Point(0.5, 0));
		mainchr->setPosition(Point(120, 80));
		mainchr->setTag(166);
		this->addChild(mainchr, 1);

		char MyString[100];
		WideCharToMultiByte(CP_UTF8, 0, L"ȣ��: (������ ������ ������...)", -1, MyString, 100, NULL, NULL);
		auto name = Label::createWithTTF(MyString, "fonts/Bold.ttf", 30);
		name->setAnchorPoint(Point(0, 1));
		name->setPosition(Point(40, 150));
		name->setColor(Color3B::WHITE);
		name->setTag(21);
		this->addChild(name, 3);

		Sprite* mainchr_2 = Sprite::create("MiniGameResources/UI_Textlblack.png");
		mainchr_2->setAnchorPoint(Point(0.5, 0.5));
		mainchr_2->setPosition(Point(510, 100));
		mainchr_2->setTag(231);
		this->addChild(mainchr_2, 2);

		auto textA_item = MenuItemImage::create(
			"MiniGameResources/ok_button.png",
			"MiniGameResources/ok_buttonpr.png",
			CC_CALLBACK_1(BudongStoryScene::storyA, this));
		textA_item->setAnchorPoint(Point(0.5, 0.5));
		textA_item->setPosition(Point(950, 65));

		auto text = Menu::create(textA_item, NULL);
		text->setAnchorPoint(Point(0.5, 0.5));
		text->setPosition(Point(0, 0));
		text->setTag(130);
		this->addChild(text, 5);

	}
	//���ϴ� ��ȭ2
	if (num == 2)
	{
		
		Sprite* mainchr = Sprite::create("MiniGameResources/main_char.png");
		mainchr->setAnchorPoint(Point(0.5, 0));
		mainchr->setPosition(Point(120, 80));
		mainchr->setTag(166);
		this->addChild(mainchr, 1);

		char MyString[100];
		WideCharToMultiByte(CP_UTF8, 0, L"ȣ��: (������ ������ ������...)", -1, MyString, 100, NULL, NULL);
		auto name = Label::createWithTTF(MyString, "fonts/Bold.ttf", 30);
		name->setAnchorPoint(Point(0, 1));
		name->setPosition(Point(40, 150));
		name->setColor(Color3B::WHITE);
		name->setTag(21);
		this->addChild(name, 3);

		Sprite* mainchr_2 = Sprite::create("MiniGameResources/UI_Textlblack.png");
		mainchr_2->setAnchorPoint(Point(0.5, 0.5));
		mainchr_2->setPosition(Point(510, 100));
		mainchr_2->setTag(231);
		this->addChild(mainchr_2, 2);

		auto textA_item = MenuItemImage::create(
			"MiniGameResources/ok_button.png",
			"MiniGameResources/ok_buttonpr.png",
			CC_CALLBACK_1(BudongStoryScene::storyA_1, this));
		textA_item->setAnchorPoint(Point(0.5, 0.5));
		textA_item->setPosition(Point(950, 65));

		auto text = Menu::create(textA_item, NULL);
		text->setAnchorPoint(Point(0.5, 0.5));
		text->setPosition(Point(0, 0));
		text->setTag(130);
		this->addChild(text, 5);
	}
	if (num == 3)
	{
		
		Sprite* mainchr = Sprite::create("MiniGameResources/main_char.png");
		mainchr->setAnchorPoint(Point(0.5, 0));
		mainchr->setPosition(Point(120, 80));
		mainchr->setTag(166);
		this->addChild(mainchr, 1);

		char MyString[100];
		WideCharToMultiByte(CP_UTF8, 0, L"ȣ��: (������ ������ ������...)", -1, MyString, 100, NULL, NULL);
		auto name = Label::createWithTTF(MyString, "fonts/Bold.ttf", 30);
		name->setAnchorPoint(Point(0, 1));
		name->setPosition(Point(40, 150));
		name->setColor(Color3B::WHITE);
		name->setTag(21);
		this->addChild(name, 3);

		Sprite* mainchr_2 = Sprite::create("MiniGameResources/UI_Textlblack.png");
		mainchr_2->setAnchorPoint(Point(0.5, 0.5));
		mainchr_2->setPosition(Point(510, 100));
		mainchr_2->setTag(231);
		this->addChild(mainchr_2, 2);

		//���ϴ� ��ȭ��3
		auto textA_item = MenuItemImage::create(
			"MiniGameResources/ok_button.png",
			"MiniGameResources/ok_buttonpr.png",
			CC_CALLBACK_1(BudongStoryScene::storyA_2, this));
		textA_item->setAnchorPoint(Point(0.5, 0.5));
		textA_item->setPosition(Point(950, 65));

		auto text = Menu::create(textA_item, NULL);
		text->setAnchorPoint(Point(0.5, 0.5));
		text->setPosition(Point(0, 0));
		text->setTag(130);
		this->addChild(text, 5);
	}
}
void BudongStoryScene::storyAspr(Ref *pSender)
{

}

void BudongStoryScene::storyA(Ref *pSender)
{
	//���ϴ� ��ȭ��1
	removeChildByTag(130);
	removeChildByTag(21);

	SimpleAudioEngine::getInstance()->playEffect("MiniGameResources/button_click_16_sound_effects_.mp3", false);

	char MyString[100];
	WideCharToMultiByte(CP_UTF8, 0, L"ȣ��: (������ �������� ������.)", -1, MyString, 100, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "fonts/Bold.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(21);
	this->addChild(name, 3);


	auto textA_item = MenuItemImage::create(
		"MiniGameResources/ok_button.png",
		"MiniGameResources/ok_buttonpr.png",
		CC_CALLBACK_1(BudongStoryScene::storyAA, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(131);
	this->addChild(text, 5);

	
}
void BudongStoryScene::storyAA(Ref *pSender)
{
	removeChildByTag(131);
	removeChildByTag(21);

	SimpleAudioEngine::getInstance()->playEffect("MiniGameResources/button_click_16_sound_effects_.mp3", false);

	char MyString[100];
	WideCharToMultiByte(CP_UTF8, 0, L"ȣ��: �ȳ��ϼ���. ��� ������ ���� ���ϼ̾��?", -1, MyString, 100, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "fonts/Bold.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(22);
	this->addChild(name, 3);


	auto textA_item = MenuItemImage::create(
		"MiniGameResources/ok_button.png",
		"MiniGameResources/ok_buttonpr.png",
		CC_CALLBACK_1(BudongStoryScene::storyAAA, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(132);
	this->addChild(text, 5);

}

void BudongStoryScene::storyAAA(Ref *pSender)
{
	removeChildByTag(132);
	removeChildByTag(22);

	SimpleAudioEngine::getInstance()->playEffect("MiniGameResources/button_click_16_sound_effects_.mp3", false);

	Sprite* mainchr = Sprite::create("MiniGameResources/invest_man.png");
	mainchr->setAnchorPoint(Point(0.5, 0));
	mainchr->setPosition(Point(800, 0));
	mainchr->setTag(231);
	this->addChild(mainchr, 1);

	char MyString[150];
	WideCharToMultiByte(CP_UTF8, 0, L"������: ȣ���̱���! ��.. �̰� ����ε� �̹��� �� ���￡ �����߾� ", -1, MyString, 150, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "fonts/Bold.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(23);
	this->addChild(name, 3);


	auto textA_item = MenuItemImage::create(
		"MiniGameResources/ok_button.png",
		"MiniGameResources/ok_buttonpr.png",
		CC_CALLBACK_1(BudongStoryScene::storyAAAA, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(133);
	this->addChild(text, 5);
}
void BudongStoryScene::storyAAAA(Ref *pSender)
{
	removeChildByTag(133);
	removeChildByTag(23);

	SimpleAudioEngine::getInstance()->playEffect("MiniGameResources/button_click_16_sound_effects_.mp3", false);

	char MyString[100];
	WideCharToMultiByte(CP_UTF8, 0, L"ȣ��: (��ȣ..) �� ������ ������ �����̳�����?", -1, MyString, 100, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "fonts/Bold.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(24);
	this->addChild(name, 3);

	
	auto textA_item = MenuItemImage::create(
		"MiniGameResources/ok_button.png",
		"MiniGameResources/ok_buttonpr.png",
		CC_CALLBACK_1(BudongStoryScene::storyAAAAA, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(134);
	this->addChild(text, 5);
}
void BudongStoryScene::storyAAAAA(Ref *pSender)
{
	removeChildByTag(134);
	removeChildByTag(24);

	SimpleAudioEngine::getInstance()->playEffect("MiniGameResources/button_click_16_sound_effects_.mp3", false);

	char MyString[100];
	WideCharToMultiByte(CP_UTF8, 0, L"������: �ƴ� �׳� ������ �׷�!", -1, MyString, 100, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "fonts/Bold.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(25);
	this->addChild(name, 3);


	auto textA_item = MenuItemImage::create(
		"MiniGameResources/ok_button.png",
		"MiniGameResources/ok_buttonpr.png",
		CC_CALLBACK_1(BudongStoryScene::storyAAAAAA, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(135);
	this->addChild(text, 5);
}
void BudongStoryScene::storyAAAAAA(Ref *pSender)
{
	removeChildByTag(135);
	removeChildByTag(25);

	SimpleAudioEngine::getInstance()->playEffect("MiniGameResources/button_click_16_sound_effects_.mp3", false);

	char MyString[200];
	WideCharToMultiByte(CP_UTF8, 0, L"ȣ��: ... (���󰡸� ���� �� ����)\n\n(ģ�е��� 10 �����Ͽ����ϴ�.)", -1, MyString, 200, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "fonts/Bold.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(26);
	this->addChild(name, 3);


	auto textA_item = MenuItemImage::create(
		"MiniGameResources/ok_button.png",
		"MiniGameResources/ok_buttonpr.png",
		CC_CALLBACK_1(BudongStoryScene::GoHome, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(136);
	this->addChild(text, 5);

	Singletons::getInstance()->m_friendly = Singletons::getInstance()->m_friendly + 10;
}


//�ϴ� ��ȭ��2
void BudongStoryScene::storyA_1(Ref *pSender)
{
	//���ϴ� ��ȭ��1
	removeChildByTag(130);
	//removeChildByTag(20);
	removeChildByTag(21);

	SimpleAudioEngine::getInstance()->playEffect("MiniGameResources/button_click_16_sound_effects_.mp3", false);

	char MyString[100];
	WideCharToMultiByte(CP_UTF8, 0, L"ȣ��: (������ �������� ������.)", -1, MyString, 100, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "fonts/Bold.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(21);
	this->addChild(name, 3);


	auto textA_item = MenuItemImage::create(
		"MiniGameResources/ok_button.png",
		"MiniGameResources/ok_buttonpr.png",
		CC_CALLBACK_1(BudongStoryScene::storyAA_1, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(131);
	this->addChild(text, 5);


}
void BudongStoryScene::storyAA_1(Ref *pSender)
{
	removeChildByTag(131);
	removeChildByTag(21);
	SimpleAudioEngine::getInstance()->playEffect("MiniGameResources/button_click_16_sound_effects_.mp3", false);

	char MyString[100];
	WideCharToMultiByte(CP_UTF8, 0, L"������: ȣ����.�̹� ������ Ȯ���ϴ�.", -1, MyString, 100, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "fonts/Bold.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(22);
	this->addChild(name, 3);


	auto textA_item = MenuItemImage::create(
		"MiniGameResources/ok_button.png",
		"MiniGameResources/ok_buttonpr.png",
		CC_CALLBACK_1(BudongStoryScene::storyAAA_1, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(132);
	this->addChild(text, 5);

	Sprite* mainchr = Sprite::create("MiniGameResources/invest_man.png");
	mainchr->setAnchorPoint(Point(0.5, 0));
	mainchr->setPosition(Point(800, 0));
	mainchr->setTag(231);
	this->addChild(mainchr, 1);
}
void BudongStoryScene::storyAAA_1(Ref *pSender)
{
	removeChildByTag(132);
	removeChildByTag(22);

	SimpleAudioEngine::getInstance()->playEffect("MiniGameResources/button_click_16_sound_effects_.mp3", false);

	char MyString[100];
	WideCharToMultiByte(CP_UTF8, 0, L"ȣ��: ���� ������?", -1, MyString, 100, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "fonts/Bold.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(23);
	this->addChild(name, 3);


	auto textA_item = MenuItemImage::create(
		"MiniGameResources/ok_button.png",
		"MiniGameResources/ok_buttonpr.png",
		CC_CALLBACK_1(BudongStoryScene::storyAAAA_1, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(133);
	this->addChild(text, 5);
}
void BudongStoryScene::storyAAAA_1(Ref *pSender)
{
	removeChildByTag(133);
	removeChildByTag(23);
	SimpleAudioEngine::getInstance()->playEffect("MiniGameResources/button_click_16_sound_effects_.mp3", false);


	char MyString[200];
	WideCharToMultiByte(CP_UTF8, 0, L"������: ������ �˷���µ� �Ѽ��� ������ ���̶�±���.", -1, MyString, 200, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "fonts/Bold.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(24);
	this->addChild(name, 3);


	auto textA_item = MenuItemImage::create(
		"MiniGameResources/ok_button.png",
		"MiniGameResources/ok_buttonpr.png",
		CC_CALLBACK_1(BudongStoryScene::storyAAAAA_1, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(134);
	this->addChild(text, 5);
}
void BudongStoryScene::storyAAAAA_1(Ref *pSender)
{
	removeChildByTag(134);
	removeChildByTag(24);

	SimpleAudioEngine::getInstance()->playEffect("MiniGameResources/button_click_16_sound_effects_.mp3", false);

	char MyString[100];
	WideCharToMultiByte(CP_UTF8, 0, L"ȣ��: ��°����?", -1, MyString, 100, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "fonts/Bold.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(25);
	this->addChild(name, 3);


	auto textA_item = MenuItemImage::create(
		"MiniGameResources/ok_button.png",
		"MiniGameResources/ok_buttonpr.png",
		CC_CALLBACK_1(BudongStoryScene::storyAAAAAA_1, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(135);
	this->addChild(text, 5);
}
void BudongStoryScene::storyAAAAAA_1(Ref *pSender)
{
	removeChildByTag(135);
	removeChildByTag(25);

	SimpleAudioEngine::getInstance()->playEffect("MiniGameResources/button_click_16_sound_effects_.mp3", false);

	char MyString[150];
	WideCharToMultiByte(CP_UTF8, 0, L"������: �� ������ �������߳�? �ٽ� �ѹ� ��������!", -1, MyString, 150, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "fonts/Bold.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(26);
	this->addChild(name, 3);


	auto textA_item = MenuItemImage::create(
		"MiniGameResources/ok_button.png",
		"MiniGameResources/ok_buttonpr.png",
		CC_CALLBACK_1(BudongStoryScene::storyAAAAAAA_1, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(136);
	this->addChild(text, 5);
}
void BudongStoryScene::storyAAAAAAA_1(Ref *pSender)
{
	removeChildByTag(136);
	removeChildByTag(26);

	SimpleAudioEngine::getInstance()->playEffect("MiniGameResources/button_click_16_sound_effects_.mp3", false);

	char MyString[200];
	WideCharToMultiByte(CP_UTF8, 0, L"ȣ��: �� �������� �����ϸ� �ȵǰھ�... ( �Ѽ� )\n\n (ģ�е��� 11 �����Ͽ����ϴ�.)", -1, MyString, 200, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "fonts/Bold.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(26);
	this->addChild(name, 3);


	auto textA_item = MenuItemImage::create(
		"MiniGameResources/ok_button.png",
		"MiniGameResources/ok_buttonpr.png",
		CC_CALLBACK_1(BudongStoryScene::GoHome, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(136);
	this->addChild(text, 5);

	Singletons::getInstance()->m_friendly = Singletons::getInstance()->m_friendly + 11;
}


//�ϴ� ��ȭ��3
void BudongStoryScene::storyA_2(Ref *pSender)
{
	removeChildByTag(130);
	//removeChildByTag(20);
	removeChildByTag(21);

	SimpleAudioEngine::getInstance()->playEffect("MiniGameResources/button_click_16_sound_effects_.mp3", false);

	char MyString[100];
	WideCharToMultiByte(CP_UTF8, 0, L"ȣ��: (������ �������� ������.)", -1, MyString, 100, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "fonts/Bold.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(21);
	this->addChild(name, 3);


	auto textA_item = MenuItemImage::create(
		"MiniGameResources/ok_button.png",
		"MiniGameResources/ok_buttonpr.png",
		CC_CALLBACK_1(BudongStoryScene::storyAA_2, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(131);
	this->addChild(text, 5);


}
void BudongStoryScene::storyAA_2(Ref *pSender)
{
	removeChildByTag(131);
	removeChildByTag(21);

	SimpleAudioEngine::getInstance()->playEffect("MiniGameResources/button_click_16_sound_effects_.mp3", false);

	char MyString[100];
	WideCharToMultiByte(CP_UTF8, 0, L"ȣ��: �ȳ��ϼ��� ������.", -1, MyString, 100, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "fonts/Bold.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(22);
	this->addChild(name, 3);


	auto textA_item = MenuItemImage::create(
		"MiniGameResources/ok_button.png",
		"MiniGameResources/ok_buttonpr.png",
		CC_CALLBACK_1(BudongStoryScene::storyAAA_2, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(132);
	this->addChild(text, 5);
}
void BudongStoryScene::storyAAA_2(Ref *pSender)
{
	removeChildByTag(132);
	removeChildByTag(22);

	SimpleAudioEngine::getInstance()->playEffect("MiniGameResources/button_click_16_sound_effects_.mp3", false);

	char MyString[100];
	WideCharToMultiByte(CP_UTF8, 0, L"������: �ȳ� ȣ����. �� ���� �ҽ��ִ�?", -1, MyString, 100, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "fonts/Bold.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(24);
	this->addChild(name, 3);


	auto textA_item = MenuItemImage::create(
		"MiniGameResources/ok_button.png",
		"MiniGameResources/ok_buttonpr.png",
		CC_CALLBACK_1(BudongStoryScene::storyAAAA_2T, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(134);
	this->addChild(text, 5);

	Sprite* mainchr = Sprite::create("MiniGameResources/invest_man.png");
	mainchr->setAnchorPoint(Point(0.5, 0));
	mainchr->setPosition(Point(800, 0));
	mainchr->setTag(231);
	this->addChild(mainchr, 1);
}

void BudongStoryScene::storyAAAA_2T(Ref *pSender)
{
	removeChildByTag(134);

	removeChildByTag(24);

	SimpleAudioEngine::getInstance()->playEffect("MiniGameResources/button_click_16_sound_effects_.mp3", false);

	char MyString[200];
	WideCharToMultiByte(CP_UTF8, 0, L"ȣ��: �ƴϿ�. ���� ���ٰ� �Ҹ��� �ҽ��� ��������.", -1, MyString, 200, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "fonts/Bold.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(23);
	this->addChild(name, 3);


	auto textA_item = MenuItemImage::create(
		"MiniGameResources/ok_button.png",
		"MiniGameResources/ok_buttonpr.png",
		CC_CALLBACK_1(BudongStoryScene::storyAAAA_2F, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(134);
	this->addChild(text, 5);
}

void BudongStoryScene::storyAAAA_2F(Ref *pSender)
{
	removeChildByTag(134);

	removeChildByTag(23);

	SimpleAudioEngine::getInstance()->playEffect("MiniGameResources/button_click_16_sound_effects_.mp3", false);

	char MyString[200];
	WideCharToMultiByte(CP_UTF8, 0, L"������: �׷�����... �� ���ʿ����� �� �˾ƺ��߰ڴ�.", -1, MyString, 200, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "fonts/Bold.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(24);
	this->addChild(name, 3);


	auto textA_item = MenuItemImage::create(
		"MiniGameResources/ok_button.png",
		"MiniGameResources/ok_buttonpr.png",
		CC_CALLBACK_1(BudongStoryScene::storyAAAA_2FF, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(134);
	this->addChild(text, 5);
}
void BudongStoryScene::storyAAAA_2FF(Ref *pSender)
{
	removeChildByTag(134);
	removeChildByTag(24);


	SimpleAudioEngine::getInstance()->playEffect("MiniGameResources/button_click_16_sound_effects_.mp3", false);
	char MyString[100];
	WideCharToMultiByte(CP_UTF8, 0, L"ȣ��: ��. �����ϼ���~ �� �����Կ�", -1, MyString, 100, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "fonts/Bold.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(24);
	this->addChild(name, 3);


	auto textA_item = MenuItemImage::create(
		"MiniGameResources/ok_button.png",
		"MiniGameResources/ok_buttonpr.png",
		CC_CALLBACK_1(BudongStoryScene::storyAAAAA_2, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(134);
	this->addChild(text, 5);
}
void BudongStoryScene::storyAAAAA_2(Ref *pSender)
{
	removeChildByTag(134);
	removeChildByTag(24);

	SimpleAudioEngine::getInstance()->playEffect("MiniGameResources/button_click_16_sound_effects_.mp3", false);

	char MyString[200];
	WideCharToMultiByte(CP_UTF8, 0, L"������: �׷� �߰���.\n\n (ģ�е��� 13 ����Ͽ����ϴ�.)", -1, MyString, 200, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "fonts/Bold.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(25);
	this->addChild(name, 3);


	auto textA_item = MenuItemImage::create(
		"MiniGameResources/ok_button.png",
		"MiniGameResources/ok_buttonpr.png",
		CC_CALLBACK_1(BudongStoryScene::GoHome, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(135);
	this->addChild(text, 5);

	Singletons::getInstance()->m_friendly = Singletons::getInstance()->m_friendly + 13;
}


void BudongStoryScene::GoHome(Ref *pSender)
{
	//log("start1 after delay");
	///*Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
	//Director::getInstance()->replaceScene(IntroSceneB::createScene());*/
	//auto scene = TransitionCrossFade::create(1.5, NextDayScene::createScene());
	//Director::getInstance()->replaceScene(scene);
	Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
	Director::getInstance()->replaceScene(NextDayScene::createScene());
}
	
	

void BudongStoryScene::skipspr(Ref *pSender)
{
	
}
