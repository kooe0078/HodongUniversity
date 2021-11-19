#include "BiriSceneA.h"
#include "NextDayScene.h"
#include "SimpleAudioEngine.h"
#include "MainBiriScene.h"
#include "sinngleton.h"
//#include "MainScene.h"
//사운드 할라면 꼭 필요
using namespace CocosDenshion;
USING_NS_CC;

Scene* BiriSceneA::createScene()
{
    auto scene = Scene::create();
    auto layer = BiriSceneA::create();
    scene->addChild(layer);

    return scene;
}

bool BiriSceneA::init()
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
	
	////터치 리스너 등록
	//auto listener = EventListenerTouchOneByOne::create();
	//listener->onTouchBegan = CC_CALLBACK_2(IntroScene::onTouchBegan, this);
	//Director::getInstance()->getEventDispatcher()->addEventListenerWithFixedPriority(listener, 1);

	//배경음악
	SimpleAudioEngine::getInstance()->playBackgroundMusic("sound/event sound2.mp3", true);

	/*this->scheduleOnce(schedule_selector(BiriSceneA::GoHome), 2.0f);
*/
    return true;
}
void BiriSceneA::update(float ft)
{
	//씬 자체적으로 반복 되야하는 내용
}
void BiriSceneA::InitBackGround()
{
	auto sprite = Sprite::create("MiniGameResources//back_3.png");
	sprite->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	this->addChild(sprite, 0);
}
void BiriSceneA::InitLabel()
{
	
}
// 인트로 선택창
void BiriSceneA::InitMenu()
{
	//스토리A창
	auto storyA_item = MenuItemImage::create(
		"MiniGameResources/UI_Textlblack.png",
		"MiniGameResources/UI_Textlblack.png",

		CC_CALLBACK_1(BiriSceneA::storyAspr, this));
	storyA_item->setAnchorPoint(Point(0.5, 0.5));
	storyA_item->setPosition(Point(510, 100));

	auto storyA = Menu::create(storyA_item, NULL);
	storyA->setAnchorPoint(Point(0.5, 0.5));
	storyA->setPosition(Point(0, 0));
	storyA->setTag(4);
	this->addChild(storyA,2);

	char MyString[100];
	WideCharToMultiByte(CP_UTF8, 0, L"호동: (오늘은 MT가 있는날이다.)", -1, MyString, 100, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "fonts/Bold.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(21);
	this->addChild(name, 3);


	//메인캐릭터
	Sprite* mainchr = Sprite::create("MiniGameResources/main_char.png");
	mainchr->setAnchorPoint(Point(0.5, 0));
	mainchr->setPosition(Point(120, 80));
	mainchr->setTag(166);
	this->addChild(mainchr, 1);

	auto textA_item = MenuItemImage::create(
		"MiniGameResources/ok_button.png",
		"MiniGameResources/ok_buttonpr.png",
		CC_CALLBACK_1(BiriSceneA::storyA, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(131);
	this->addChild(text, 5);
}
void BiriSceneA::storyAspr(Ref *pSender)
{

}

void BiriSceneA::storyA(Ref *pSender)
{
	//선택씬
	removeChildByTag(131);
	removeChildByTag(130);
	removeChildByTag(21);

	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);
	//간다
	auto textA_item = MenuItemImage::create(
		"MiniGameResources/text_yes.png",
		"MiniGameResources/text_yes.png",
		CC_CALLBACK_1(BiriSceneA::storyAA, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(300, 105));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(133);
	this->addChild(text, 5);

	//안간다
	auto textB_item = MenuItemImage::create(
		"MiniGameResources/text_no.png",
		"MiniGameResources/text_no.png",
		CC_CALLBACK_1(BiriSceneA::storyAAAA, this));
	textB_item->setAnchorPoint(Point(0.5, 0.5));
	textB_item->setPosition(Point(700, 105));

	auto textB = Menu::create(textB_item, NULL);
	textB->setAnchorPoint(Point(0.5, 0.5));
	textB->setPosition(Point(0, 0));
	textB->setTag(134);
	this->addChild(textB, 5);



}
void BiriSceneA::storyAA(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);
	removeChildByTag(133);
	removeChildByTag(134);
	removeChildByTag(131);
	removeChildByTag(21);
	char MyString[100];
	WideCharToMultiByte(CP_UTF8, 0, L"호동: (그럼 MT를 즐겨볼까?)", -1, MyString, 100, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "fonts/Bold.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(22);
	this->addChild(name, 3);


	auto textA_item = MenuItemImage::create(
		"MiniGameResources/ok_button.png",
		"MiniGameResources/ok_buttonpr.png",
		CC_CALLBACK_1(BiriSceneA::storyAAA, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(132);
	this->addChild(text, 5);

}

void BiriSceneA::storyAAA(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);
	removeChildByTag(132);
	removeChildByTag(22);

	Sprite* mainchr = Sprite::create("MiniGameResources/mc_chara.png");
	mainchr->setAnchorPoint(Point(0.5, 0));
	mainchr->setPosition(Point(800, 0));
	mainchr->setTag(231);
	this->addChild(mainchr, 1);

	char MyString[100];
	WideCharToMultiByte(CP_UTF8, 0, L"사회자: 그럼 이제! 장기자랑 시간이~~ 돌아~~ 왔습니다!!!", -1, MyString, 100, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "fonts/Bold.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(23);
	this->addChild(name, 3);


	auto textA_item = MenuItemImage::create(
		"MiniGameResources/ok_button.png",
		"MiniGameResources/ok_buttonpr.png",
		CC_CALLBACK_1(BiriSceneA::storyAAAAAA, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(133);
	this->addChild(text, 5);
}
void BiriSceneA::storyAAAA(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);
	removeChildByTag(134);
	removeChildByTag(133);
	removeChildByTag(24);
	Singletons::getInstance()->backnum = 0;
	char MyString[100];
	WideCharToMultiByte(CP_UTF8, 0, L"호동: (크킄... 어디 한번 뒤에서 움직여 볼까?)", -1, MyString, 100, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "fonts/Bold.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(23);
	this->addChild(name, 3);


	auto textA_item = MenuItemImage::create(
		"MiniGameResources/ok_button.png",
		"MiniGameResources/ok_buttonpr.png",
		CC_CALLBACK_1(BiriSceneA::storyAAAAA, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(133);
	this->addChild(text, 5);


}
void BiriSceneA::storyAAAAA(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);
	log("start1 after delay");
	auto scene = TransitionCrossFade::create(1.5, MainBiriScene::createScene());
	Director::getInstance()->replaceScene(scene);
//Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
//Director::getInstance()->replaceScene(MainBiriScene::createScene());
}
void BiriSceneA::storyAAAAAA(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);
	removeChildByTag(133);
	removeChildByTag(23);
	removeChildByTag(231);
	char MyString[100];
	WideCharToMultiByte(CP_UTF8, 0, L"호동: (무엇을 할까?)", -1, MyString, 100, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "fonts/Bold.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(26);
	this->addChild(name, 3);


	auto textA_item = MenuItemImage::create(
		"MiniGameResources/ok_button.png",
		"MiniGameResources/ok_buttonpr.png",
		CC_CALLBACK_1(BiriSceneA::storyAAAAAAA, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(136);
	this->addChild(text, 5);
}
void BiriSceneA::storyAAAAAAA(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);
	removeChildByTag(136);
	removeChildByTag(26);
	//춤
	auto textA_item_1 = MenuItemImage::create(
		"MiniGameResources/texts1.png",
		"MiniGameResources/texts1.png",
		CC_CALLBACK_1(BiriSceneA::storyA_1, this));
	textA_item_1->setAnchorPoint(Point(0.5, 0.5));
	textA_item_1->setPosition(Point(240, 105));

	auto text_1 = Menu::create(textA_item_1, NULL);
	text_1->setAnchorPoint(Point(0.5, 0.5));
	text_1->setPosition(Point(0, 0));
	text_1->setTag(137);
	this->addChild(text_1, 5);
	//노래
	auto textA_item = MenuItemImage::create(
		"MiniGameResources/texts2.png",
		"MiniGameResources/texts2.png",
		CC_CALLBACK_1(BiriSceneA::storyA_2, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(760, 105));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(138);
	this->addChild(text, 5);
}

//하니 대화씬2
void BiriSceneA::storyA_1(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);
	//모하니 대화씬1
	removeChildByTag(137);
	removeChildByTag(138);

	char MyString[100];
	WideCharToMultiByte(CP_UTF8, 0, L"호동: 역시 엠티는 이래야지! ", -1, MyString, 100, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "fonts/Bold.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(21);
	this->addChild(name, 3);


	auto textA_item = MenuItemImage::create(
		"MiniGameResources/ok_button.png",
		"MiniGameResources/ok_buttonpr.png",
		CC_CALLBACK_1(BiriSceneA::storyAA_1, this));
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
void BiriSceneA::storyAA_1(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);
	removeChildByTag(131);
	removeChildByTag(21);
	char MyString[100];
	WideCharToMultiByte(CP_UTF8, 0, L"(호동은 섹시댄스를 추었다.)", -1, MyString, 100, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "fonts/Bold.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(22);
	this->addChild(name, 3);


	auto textA_item = MenuItemImage::create(
		"MiniGameResources/ok_button.png",
		"MiniGameResources/ok_buttonpr.png",
		CC_CALLBACK_1(BiriSceneA::storyAAA_1, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(132);
	this->addChild(text, 5);
}
void BiriSceneA::storyAAA_1(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);
	removeChildByTag(132);
	removeChildByTag(22);
	

	Sprite* mainchr = Sprite::create("MiniGameResources/mc_chara.png");
	mainchr->setAnchorPoint(Point(0.5, 0));
	mainchr->setPosition(Point(800, 0));
	mainchr->setTag(231);
	this->addChild(mainchr, 1);

	char MyString[100];
	WideCharToMultiByte(CP_UTF8, 0, L"사회자: 아 ! 호동군의 웨이브!! ", -1, MyString, 100, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "fonts/Bold.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(23);
	this->addChild(name, 3);


	auto textA_item = MenuItemImage::create(
		"MiniGameResources/ok_button.png",
		"MiniGameResources/ok_buttonpr.png",
		CC_CALLBACK_1(BiriSceneA::storyAAAA_1, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(133);
	this->addChild(text, 5);
}
void BiriSceneA::storyAAAA_1(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);
	removeChildByTag(133);
	removeChildByTag(23);
	removeChildByTag(231);



	char MyString[100];
	WideCharToMultiByte(CP_UTF8, 0, L"관객: 꺄아악!", -1, MyString, 100, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "fonts/Bold.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(24);
	this->addChild(name, 3);


	auto textA_item = MenuItemImage::create(
		"MiniGameResources/ok_button.png",
		"MiniGameResources/ok_buttonpr.png",
		CC_CALLBACK_1(BiriSceneA::storyAAAAA_1, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(134);
	this->addChild(text, 5);
}
void BiriSceneA::storyAAAAA_1(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);
	removeChildByTag(134);
	removeChildByTag(24);

	char MyString[100];
	WideCharToMultiByte(CP_UTF8, 0, L"...", -1, MyString, 100, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "fonts/Bold.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(25);
	this->addChild(name, 3);


	auto textA_item = MenuItemImage::create(
		"MiniGameResources/ok_button.png",
		"MiniGameResources/ok_buttonpr.png",
		CC_CALLBACK_1(BiriSceneA::storyAAAAAA_1, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(135);
	this->addChild(text, 5);
}
void BiriSceneA::storyAAAAAA_1(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);
	removeChildByTag(135);
	removeChildByTag(25);

	char MyString[100];
	WideCharToMultiByte(CP_UTF8, 0, L"mt가 끝났다.", -1, MyString, 100, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "fonts/Bold.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(26);
	this->addChild(name, 3);


	auto textA_item = MenuItemImage::create(
		"MiniGameResources/ok_button.png",
		"MiniGameResources/ok_buttonpr.png",
		CC_CALLBACK_1(BiriSceneA::storyAAAAAAA_1, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(136);
	this->addChild(text, 5);
}
void BiriSceneA::storyAAAAAAA_1(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);
	removeChildByTag(136);
	removeChildByTag(26);

	char MyString[200];
	WideCharToMultiByte(CP_UTF8, 0, L"호동: 정말 재미있었어!\n\n (3만원과 45의 모든 능력치를 획득하였습니다.)", -1, MyString, 200, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "fonts/Bold.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(26);
	this->addChild(name, 3);


	auto textA_item = MenuItemImage::create(
		"MiniGameResources/ok_button.png",
		"MiniGameResources/ok_buttonpr.png",
		CC_CALLBACK_1(BiriSceneA::GoHome, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(136);
	this->addChild(text, 5);

	Singletons::getInstance()->m_friendly = Singletons::getInstance()->m_friendly+45;
	Singletons::getInstance()->m_hak = Singletons::getInstance()->m_hak+45;
	Singletons::getInstance()->m_insung = Singletons::getInstance()->m_insung+45;
	Singletons::getInstance()->m_jisik = Singletons::getInstance()->m_jisik+45;
	Singletons::getInstance()->money = Singletons::getInstance()->money+30000;
}
void BiriSceneA::storyfin(Ref *pSender)
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
		CC_CALLBACK_1(BiriSceneA::GoHome, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(133);
	this->addChild(text, 5);
}
//하니 대화씬3
void BiriSceneA::storyA_2(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);
	removeChildByTag(137);
	removeChildByTag(138);

	char MyString[100];
	WideCharToMultiByte(CP_UTF8, 0, L"호동: (내 목소리로 모두 사로잡아주지!)", -1, MyString, 100, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "fonts/Bold.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(21);
	this->addChild(name, 3);


	auto textA_item = MenuItemImage::create(
		"MiniGameResources/ok_button.png",
		"MiniGameResources/ok_buttonpr.png",
		CC_CALLBACK_1(BiriSceneA::storyAA_2, this));
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
void BiriSceneA::storyAA_2(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);
	removeChildByTag(131);
	removeChildByTag(21);
	char MyString[100];
	WideCharToMultiByte(CP_UTF8, 0, L"(호동은 노래를 불렀다.)", -1, MyString, 100, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "fonts/Bold.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(22);
	this->addChild(name, 3);


	auto textA_item = MenuItemImage::create(
		"MiniGameResources/ok_button.png",
		"MiniGameResources/ok_buttonpr.png",
		CC_CALLBACK_1(BiriSceneA::storyAAA_2, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(132);
	this->addChild(text, 5);
}
void BiriSceneA::storyAAA_2(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);
	removeChildByTag(132);
	removeChildByTag(22);

	char MyString[100];
	WideCharToMultiByte(CP_UTF8, 0, L"호동은 긴장해서 박자와 음정 모두 놓쳐버리고 말았다.", -1, MyString, 100, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "fonts/Bold.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(23);
	this->addChild(name, 3);

	auto textA_item = MenuItemImage::create(
		"MiniGameResources/ok_button.png",
		"MiniGameResources/ok_buttonpr.png",
		CC_CALLBACK_1(BiriSceneA::storyAAAA_2T, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(132);
	this->addChild(text, 5);
}

void BiriSceneA::storyAAAA_2T(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);
	removeChildByTag(132);
	
	removeChildByTag(23);




	char MyString[100];
	WideCharToMultiByte(CP_UTF8, 0, L"관객 : 큭큭 재 누구야? ", -1, MyString, 100, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "fonts/Bold.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(24);
	this->addChild(name, 3);


	auto textA_item = MenuItemImage::create(
		"MiniGameResources/ok_button.png",
		"MiniGameResources/ok_buttonpr.png",
		CC_CALLBACK_1(BiriSceneA::storyAAAA_2F, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(134);
	this->addChild(text, 5);
}

void BiriSceneA::storyAAAA_2F(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);
	removeChildByTag(134);

	removeChildByTag(24);
	
	char MyString[100];
	WideCharToMultiByte(CP_UTF8, 0, L"...", -1, MyString, 100, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "fonts/Bold.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(24);
	this->addChild(name, 3);


	auto textA_item = MenuItemImage::create(
		"MiniGameResources/ok_button.png",
		"MiniGameResources/ok_buttonpr.png",
		CC_CALLBACK_1(BiriSceneA::storyAAAA_2FF, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(134);
	this->addChild(text, 5);
}
void BiriSceneA::storyAAAA_2FF(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);
	removeChildByTag(134);
	removeChildByTag(24);

	char MyString[200];
	WideCharToMultiByte(CP_UTF8, 0, L"엠티가 끝났다. 호동은 부끄러웠지만 재미있었다고 생각했다.\n\n(모든 능력치가 15 증가하였습니다.)", -1, MyString, 200, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "fonts/Bold.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(24);
	this->addChild(name, 3);


	auto textA_item = MenuItemImage::create(
		"MiniGameResources/ok_button.png",
		"MiniGameResources/ok_buttonpr.png",
		CC_CALLBACK_1(BiriSceneA::GoHome, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(134);
	this->addChild(text, 5);

	Singletons::getInstance()->m_friendly = Singletons::getInstance()->m_friendly + 15;
	Singletons::getInstance()->m_hak = Singletons::getInstance()->m_hak + 15;
	Singletons::getInstance()->m_insung = Singletons::getInstance()->m_insung + 15;
	Singletons::getInstance()->m_jisik = Singletons::getInstance()->m_jisik + 15;
}

void BiriSceneA::GoHome(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);
	//log("start1 after delay");
	///*Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
	//Director::getInstance()->replaceScene(IntroSceneB::createScene());*/
	//auto scene = TransitionCrossFade::create(1.5, NextDayScene::createScene());
	//Director::getInstance()->replaceScene(scene);
	Singletons::getInstance()->day = Singletons::getInstance()->day + 2;
	Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
	Director::getInstance()->replaceScene(NextDayScene::createScene());
}
	
	

void BiriSceneA::skipspr(Ref *pSender)
{
	
}
