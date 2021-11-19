#include "Street.h"
#include "SimpleAudioEngine.h"

//사운드 할라면 꼭 필요
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

	//배경음악
	//SimpleAudioEngine::getInstance()->playBackgroundMusic("Street/IntroBackSound.mp3", true);

	return true;
}
void Street::InitBackGround()
{
	auto sprite = Sprite::create("Street/inside_star.png");
	sprite->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	this->addChild(sprite, 0);
}
// 인트로 선택창
void Street::InitMenu()
{
	int i, num;

	srand((double)time(NULL));
	for (i = 0; i < 1; i++)
	{
		num = rand() % 5 + 1;
	}

	// 김창룡 대화 1
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
	// 김창룡 대화 2
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
	// 김창룡 대화 3
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
	// 강혜정 대화 1
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
	// 강혜정 대화 2
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

	// 텍스트 창
	auto sprite = Sprite::create("Street/UI_Textlblack.png");
	sprite->setAnchorPoint(Point(0.5, 0.5));
	sprite->setPosition(Point(510, 100));
	sprite->setTag(200);
	this->addChild(sprite, 2);

	// 메인 캐릭터
	Sprite* mainchr = Sprite::create("Street/main_char.png");
	mainchr->setAnchorPoint(Point(0.5, 0));
	mainchr->setPosition(Point(120, 80));
	mainchr->setTag(166);
	this->addChild(mainchr, 1);

	char MyString[200];
	WideCharToMultiByte(CP_UTF8, 0, L"호동: 역시 번화가야~ 볼게 많군!!", -1, MyString, 200, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "Street/ABC.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(21);
	this->addChild(name, 3);
}
// 김창룡 대화씬 1
void Street::storyA(Ref *pSender)
{
	removeChildByTag(130);
	removeChildByTag(21);

	char MyString[100];
	WideCharToMultiByte(CP_UTF8, 0, L"(김창룡을 만났다.)", -1, MyString, 100, NULL, NULL);
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
	WideCharToMultiByte(CP_UTF8, 0, L"창룡 : 여어 호동~ 여긴 왠일로 나왔어?", -1, MyString, 200, NULL, NULL);
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
	WideCharToMultiByte(CP_UTF8, 0, L"호동 : 그냥 뭐 좀 사려고왔지~ 형 혹시 바빠? ", -1, MyString, 200, NULL, NULL);
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
	WideCharToMultiByte(CP_UTF8, 0, L"창룡 : 아니? 왜?", -1, MyString, 100, NULL, NULL);
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
	WideCharToMultiByte(CP_UTF8, 0, L"호동 : 그럼 밥이나 사주라 ㅎㅎ", -1, MyString, 400, NULL, NULL);
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
	WideCharToMultiByte(CP_UTF8, 0, L"창룡 : 뻔뻔한 놈... 그래 사줄게 가자.", -1, MyString, 200, NULL, NULL);
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
	WideCharToMultiByte(CP_UTF8, 0, L"호동 : 오오 땡큐~~\n\n (친밀도가 12 증가하였습니다.)", -1, MyString, 200, NULL, NULL);
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
// 김창룡 대화씬 2
void Street::storyA_1(Ref *pSender)
{
	removeChildByTag(130);
	removeChildByTag(21);

	char MyString[100];
	WideCharToMultiByte(CP_UTF8, 0, L"(김창룡을 만났다.)", -1, MyString, 100, NULL, NULL);
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
	WideCharToMultiByte(CP_UTF8, 0, L"호동 : 형. 할 것도 없는데 영화나 볼래?", -1, MyString, 200, NULL, NULL);
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
	WideCharToMultiByte(CP_UTF8, 0, L"창룡 : 남자 둘이서 뭔 영화야... 여친이랑 가.", -1, MyString, 200, NULL, NULL);
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
	WideCharToMultiByte(CP_UTF8, 0, L"호동 : 여친 없는거 알면서 너무하네;;", -1, MyString, 300, NULL, NULL);
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
	WideCharToMultiByte(CP_UTF8, 0, L"창룡 : 시끄러 임마. 피방이나 가자.", -1, MyString, 300, NULL, NULL);
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
	WideCharToMultiByte(CP_UTF8, 0, L"호동 : 그래...\n\n (친밀도가 1 증가하였습니다.)", -1, MyString, 200, NULL, NULL);
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
// 김창룡 대화씬 3
void Street::storyB(Ref *pSender)
{
	removeChildByTag(130);
	removeChildByTag(21);

	char MyString[100];
	WideCharToMultiByte(CP_UTF8, 0, L"(김창룡을 만났다.)", -1, MyString, 100, NULL, NULL);
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
	WideCharToMultiByte(CP_UTF8, 0, L"호동 : 아 밥 뭐먹지...", -1, MyString, 100, NULL, NULL);
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
	WideCharToMultiByte(CP_UTF8, 0, L"창룡 : 국밥먹으러 갈래??", -1, MyString, 200, NULL, NULL);
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
	WideCharToMultiByte(CP_UTF8, 0, L"호동 : 국밥은 별론데...", -1, MyString, 100, NULL, NULL);
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
	WideCharToMultiByte(CP_UTF8, 0, L"창룡 : 그럼 의견이라도 내 봐. 싫다고 하지말고", -1, MyString, 200, NULL, NULL);
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
	WideCharToMultiByte(CP_UTF8, 0, L"호동 : 그냥 국밥먹자. ", -1, MyString, 100, NULL, NULL);
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
	WideCharToMultiByte(CP_UTF8, 0, L"창룡 : 싱겁긴...\n\n(친밀도가 1 상승하였습니다.)", -1, MyString, 200, NULL, NULL);
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
// 강혜정 대화씬 1
void Street::storyB_1(Ref *pSender)
{
	removeChildByTag(130);
	removeChildByTag(21);

	char MyString[200];
	WideCharToMultiByte(CP_UTF8, 0, L"(공연을 하는 강혜정을 발견했다.)", -1, MyString, 200, NULL, NULL);
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
	WideCharToMultiByte(CP_UTF8, 0, L"혜정 : 커피를 너무~ 많이 마셨나봐요~\n ..... \n오늘은 그만 가야겠다.", -1, MyString, 300, NULL, NULL);
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
	WideCharToMultiByte(CP_UTF8, 0, L"호동 : 앵콜 앵콜~", -1, MyString, 100, NULL, NULL);
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
	WideCharToMultiByte(CP_UTF8, 0, L"혜정 : 호동아! 내 공연 봐주러온거야? 고마워!", -1, MyString, 200, NULL, NULL);
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
	WideCharToMultiByte(CP_UTF8, 0, L"호동 : 아니 뭘 이 정도 가지고~", -1, MyString, 200, NULL, NULL);
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
	WideCharToMultiByte(CP_UTF8, 0, L"혜정 : 내가 밥이나 사줄게 가자~", -1, MyString, 300, NULL, NULL);
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
	WideCharToMultiByte(CP_UTF8, 0, L"호동 : 진짜? 잘 먹을게~~\n\n(친밀도가 1 상승하였습니다.)", -1, MyString, 300, NULL, NULL);
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
// 강혜정 대화씬 2
void Street::storyC(Ref * pSender)
{
	removeChildByTag(130);
	removeChildByTag(21);

	char MyString[200];
	WideCharToMultiByte(CP_UTF8, 0, L"(공연을 하는 강혜정을 발견했다.)", -1, MyString, 200, NULL, NULL);
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
	WideCharToMultiByte(CP_UTF8, 0, L"혜정 : 호동아! 안녕~", -1, MyString, 100, NULL, NULL);
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
	WideCharToMultiByte(CP_UTF8, 0, L"호동 : 오늘도 공연하러 나온거야?", -1, MyString, 100, NULL, NULL);
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
	WideCharToMultiByte(CP_UTF8, 0, L"혜정 : 어.. 거의 매일 나오다 보니까 이제 안나오면 못참겠더라...", -1, MyString, 400, NULL, NULL);
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
	WideCharToMultiByte(CP_UTF8, 0, L"호동 : 이러다 유명 가수 되는거 야니야? 미리 싸인 받아야겠는걸?", -1, MyString, 400, NULL, NULL);
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
	WideCharToMultiByte(CP_UTF8, 0, L"혜정 : 오버하지마~ 어디 가는중 아니었어? 가던 길 가봐 ㅎㅎ ", -1, MyString, 400, NULL, NULL);
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
	WideCharToMultiByte(CP_UTF8, 0, L"호동 : 그래~ 누나도 공연 열심히해! 갈게~\n\n(친밀도가 1 상승하였습니다.)", -1, MyString, 400, NULL, NULL);
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
	// NextDayScene으로 변경
	Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
	Director::getInstance()->replaceScene(Street::createScene());
}
