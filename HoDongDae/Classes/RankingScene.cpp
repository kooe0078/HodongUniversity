#include "RankingScene.h"
#include "SimpleAudioEngine.h"
#include "sinngleton.h"
#include "IntroScene.h"

//���� �Ҷ�� �� �ʿ�
using namespace CocosDenshion;
USING_NS_CC;

Scene* RankingScene::createScene()
{
    auto scene = Scene::create();
    auto layer = RankingScene::create();
    scene->addChild(layer);

    return scene;
}

bool RankingScene::init()
{

    if ( !Layer::init() )
    {
        return false;
    }

	InitBackGround();
	talkLabel();
	InitDay();

	//�������
	SimpleAudioEngine::getInstance()->playBackgroundMusic("sound/event sound.mp3", true);

    return true;
}
void RankingScene::InitBackGround()
{
	auto sprite = Sprite::create("Rank/Back.png");
	sprite->setPosition(Point(512, 384));
	this->addChild(sprite, 0);
}
void RankingScene::InitDay() // ���� �ϼ�
{
	char Q1[200];
	WideCharToMultiByte(CP_UTF8, 0, L"���� �ϼ� : ", -1, Q1, 200, NULL, NULL);
	auto Day = Label::createWithTTF(Q1, "Rank/ABC.ttf", 27);
	Day->setAnchorPoint(Point(0, 1));
	Day->setPosition(Point(350, 650));
	Day->setTag(804);
	Day->setColor(Color3B::BLACK);
	this->addChild(Day);

	auto label_0 = Label::create("", "Rank/ABC.ttf", 27);
	label_0->setAnchorPoint(Point(0, 1));
	label_0->setPosition(Point(500, 650));
	label_0->setTag(805);
	label_0->setColor(Color3B::RED);
	this->addChild(label_0);

	setDay();
}
void RankingScene::setDay() // �ϼ� Ȯ��
{
	auto label = (Label*)this->getChildByTag(805);
	label->setString(StringUtils::format("%d", Singletons::getInstance()->DayGone));
}
void RankingScene::talkLabel()
{
	
	// ���� ��ư
	auto textA_item = MenuItemImage::create(
		"Rank/ok_button.png",
		"Rank/ok_buttonpr.png",
		CC_CALLBACK_1(RankingScene::talk1, this));
	textA_item->setAnchorPoint(Point(0.5, 0.5));
	textA_item->setPosition(Point(950, 65));

	auto text = Menu::create(textA_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(801);
	this->addChild(text, 5);

	//�ؽ�Ʈ â
	auto sprite = Sprite::create("Rank/UI_Textlblack.png");
	sprite->setAnchorPoint(Point(0.5, 0.5));
	sprite->setPosition(Point(512, 100));
	sprite->setTag(800);
	this->addChild(sprite, 0);

	// ���
	char MyString[200];
	WideCharToMultiByte(CP_UTF8, 0, L"���ݱ��� ������ �÷��� ���ּż� �����մϴ�.\n�̰������� �÷��� �ߴ� ��ϵ��� ���� �ű�ϴ�.", -1, MyString, 200, NULL, NULL);
	auto ty = Label::createWithTTF(MyString, "Rank/ABC.ttf", 30);
	ty->setAnchorPoint(Point(0, 1));
	ty->setPosition(Point(40, 150));
	ty->setColor(Color3B::WHITE);
	ty->setTag(811);
	this->addChild(ty, 3);
}
void RankingScene::talk1(Ref * pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);

	removeChildByTag(801);
	removeChildByTag(811);

	// ���� ��ư
	auto item = MenuItemImage::create(
		"Rank/ok_button.png",
		"Rank/ok_buttonpr.png",
		CC_CALLBACK_1(RankingScene::talk2, this));
	item->setAnchorPoint(Point(0.5, 0.5));
	item->setPosition(Point(950, 65));

	auto text = Menu::create(item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(802);
	this->addChild(text, 5);

	// ���
	char MyString[200];
	WideCharToMultiByte(CP_UTF8, 0, L"ȭ�鿡�� ����� �÷��� �ϼ��� �˷��ݴϴ�.\n���� �� ��ġ�� ����Ǿ� ��ŷ���� �����ϴ�.", -1, MyString, 200, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "Rank/ABC.ttf", 30);
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(40, 150));
	name->setColor(Color3B::WHITE);
	name->setTag(812);
	this->addChild(name, 3);
}
void RankingScene::talk2(Ref * pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);

	removeChildByTag(802);
	removeChildByTag(812);
	removeChildByTag(800);
	removeChildByTag(804);
	removeChildByTag(805);

	// ȸ���� ��
	Singletons::getInstance()->cycle = UserDefault::getInstance()->getIntegerForKey("cycle");
	log("%d", Singletons::getInstance()->cycle);

	Singletons::getInstance()->ranking[Singletons::getInstance()->cycle] = Singletons::getInstance()->DayGone;
	if (Singletons::getInstance()->cycle == 0)
	{
		UserDefault::getInstance()->setIntegerForKey("ranking1", Singletons::getInstance()->DayGone);
		UserDefault::getInstance()->flush();
	}
	else if (Singletons::getInstance()->cycle == 1)
	{
		UserDefault::getInstance()->setIntegerForKey("ranking2", Singletons::getInstance()->DayGone);
		UserDefault::getInstance()->flush();
	}
	else if (Singletons::getInstance()->cycle == 2)
	{
		UserDefault::getInstance()->setIntegerForKey("ranking3", Singletons::getInstance()->DayGone);
		UserDefault::getInstance()->flush();
	}
	else if (Singletons::getInstance()->cycle == 3)
	{
		UserDefault::getInstance()->setIntegerForKey("ranking4", Singletons::getInstance()->DayGone);
		UserDefault::getInstance()->flush();
	}
	else if (Singletons::getInstance()->cycle == 4)
	{
		UserDefault::getInstance()->setIntegerForKey("ranking5", Singletons::getInstance()->DayGone);
		UserDefault::getInstance()->flush();
	}

	Singletons::getInstance()->ranking[0] = UserDefault::getInstance()->getIntegerForKey("ranking1");
	log("%d", Singletons::getInstance()->ranking[0]);
	Singletons::getInstance()->ranking[1] = UserDefault::getInstance()->getIntegerForKey("ranking2");
	log("%d", Singletons::getInstance()->ranking[1]);
	Singletons::getInstance()->ranking[2] = UserDefault::getInstance()->getIntegerForKey("ranking3");
	log("%d", Singletons::getInstance()->ranking[2]);
	Singletons::getInstance()->ranking[3] = UserDefault::getInstance()->getIntegerForKey("ranking4");
	log("%d", Singletons::getInstance()->ranking[3]);
	Singletons::getInstance()->ranking[4] = UserDefault::getInstance()->getIntegerForKey("ranking5");
	log("%d", Singletons::getInstance()->ranking[4]);

	int k;

	for (i = 0; i < 5; i++)
	{
		for (int j = i; j < 5; j++)
		{
			if (Singletons::getInstance()->ranking[i] > Singletons::getInstance()->ranking[j])
			{
				k = Singletons::getInstance()->ranking[i];
				Singletons::getInstance()->ranking[i] = Singletons::getInstance()->ranking[j];
				Singletons::getInstance()->ranking[j] = k;
			}
		}
	}


	// ���� ����
	char Q1[200];
	WideCharToMultiByte(CP_UTF8, 0, L" 1��: \n\n 2��: \n\n 3��: \n\n 4��: \n\n 5��: ", -1, Q1, 200, NULL, NULL);
	auto EX1 = Label::createWithTTF(Q1, "Rank/ABC.ttf", 27);
	EX1->setAnchorPoint(Point(0, 1));
	EX1->setPosition(Point(350, 650));
	EX1->setColor(Color3B::BLACK);
	this->addChild(EX1, 2);

	WideCharToMultiByte(CP_UTF8, 0, L" �� \n\n �� \n\n �� \n\n �� \n\n �� ", -1, Q1, 200, NULL, NULL);
	auto EX2 = Label::createWithTTF(Q1, "Rank/ABC.ttf", 27);
	EX2->setAnchorPoint(Point(0, 1));
	EX2->setPosition(Point(570, 650));
	EX2->setColor(Color3B::BLACK);
	this->addChild(EX2, 2);

	// ��ŷ ���� ��ġ
	auto label_0 = Label::create("", "Rank/ABC.ttf", 27);
	label_0->setAnchorPoint(Point(0, 1));
	label_0->setPosition(Point(500, 650));
	label_0->setTag(806);
	label_0->setColor(Color3B::RED);
	this->addChild(label_0);

	// ��ŷ ����
	auto label = (Label*)this->getChildByTag(806);
	label->setString(StringUtils::format(" %d \n\n %d \n\n %d \n\n %d \n\n %d ", Singletons::getInstance()->ranking[0], Singletons::getInstance()->ranking[1],
		Singletons::getInstance()->ranking[2], Singletons::getInstance()->ranking[3], Singletons::getInstance()->ranking[4]));

	// Ȯ�� ��ư
	auto ok = MenuItemImage::create(
		"Rank/UI_enter.png",
		"Rank/UI_enterpr.png",
		CC_CALLBACK_1(RankingScene::talk3, this));
	ok->setPosition(Point(506, 250));

	auto menu1 = Menu::create(ok, NULL);
	menu1->setPosition(Vec2::ZERO);
	menu1->setTag(807);
	this->addChild(menu1, 2);

	return;
}
void RankingScene::talk3(Ref * pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);

	removeChildByTag(807);

	if (Singletons::getInstance()->cycle == 5)
	{
		// cycle�� 0���� �ʱ�ȭ 
		Singletons::getInstance()->Singletons::getInstance()->cycle = UserDefault::getInstance()->getIntegerForKey("cycle") - 5;
		UserDefault::getInstance()->setIntegerForKey("cycle", Singletons::getInstance()->Singletons::getInstance()->cycle);
		UserDefault::getInstance()->flush();
	}
	else
	{
		// cycle 1 ����
		Singletons::getInstance()->Singletons::getInstance()->cycle = UserDefault::getInstance()->getIntegerForKey("cycle") + 1;
		UserDefault::getInstance()->setIntegerForKey("cycle", Singletons::getInstance()->Singletons::getInstance()->cycle);
		UserDefault::getInstance()->flush();
	}

	UserDefault::getInstance()->setIntegerForKey("cycle", Singletons::getInstance()->cycle); // cycle ����
	UserDefault::getInstance()->flush();

	UserDefault::getInstance()->setIntegerForKey("DayGone", 0); // DayGone�� 0���� �ʱ�ȭ 
	Singletons::getInstance()->DayGone = UserDefault::getInstance()->getIntegerForKey("DayGone");
	UserDefault::getInstance()->flush();

	// ���� ��ư
	auto item = MenuItemImage::create(
		"Rank/ok_button.png",
		"Rank/ok_buttonpr.png",
		CC_CALLBACK_1(RankingScene::talkend, this));
	item->setAnchorPoint(Point(0.5, 0.5));
	item->setPosition(Point(950, 65));

	auto text = Menu::create(item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(803);
	this->addChild(text, 5);

	//�ؽ�Ʈ â
	auto sprite = Sprite::create("Rank/UI_Textlblack.png");
	sprite->setAnchorPoint(Point(0.5, 0.5));
	sprite->setPosition(Point(512, 100));
	sprite->setTag(800);
	this->addChild(sprite, 0);

	// ���
	char MyString[200];
	WideCharToMultiByte(CP_UTF8, 0, L"���� ������ ��ǰ������ ������ ����ּż� �����մϴ�.", -1, MyString, 200, NULL, NULL);
	auto ty = Label::createWithTTF(MyString, "Rank/ABC.ttf", 30);
	ty->setAnchorPoint(Point(0, 1));
	ty->setPosition(Point(40, 150));
	ty->setColor(Color3B::WHITE);
	ty->setTag(813);
	this->addChild(ty, 3);
}
void RankingScene::talkend(Ref * pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);

	// ���� �޴��� ���ư��� �� �ۼ�
	Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
	Director::getInstance()->replaceScene(IntroScene::createScene());
}

