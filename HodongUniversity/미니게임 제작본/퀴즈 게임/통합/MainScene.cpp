#include "EndScene.h"
#include "MainScene.h"
#include "SimpleAudioEngine.h"
#include <stdlib.h>
#include "singleton.h"

//���� �Ҷ�� �� �ʿ�
using namespace CocosDenshion;
USING_NS_CC;

Scene* MainScene::createScene()
{
    auto scene = Scene::create();
    auto layer = MainScene::create();
    scene->addChild(layer);

    return scene;
}

bool MainScene::init()
{
	srand((unsigned)time(NULL));
	i = rand() % 12;

    if ( !Layer::init() )
    {
        return false;
    }

	Singletons::getInstance()->Qnum;
	UserDefault::getInstance()->setIntegerForKey("Qnum", Singletons::getInstance()->Qnum);
	Singletons::getInstance()->Qnum = UserDefault::getInstance()->getIntegerForKey("Qnum");
	Singletons::getInstance()->Answer;
	UserDefault::getInstance()->setIntegerForKey("Answer", Singletons::getInstance()->Answer);
	Singletons::getInstance()->Answer = UserDefault::getInstance()->getIntegerForKey("Answer");

	SimpleAudioEngine::getInstance()->playBackgroundMusic("MiniGameResources/MainBackSound.mp3", true); // ���

	initBG();
	initLabelQ();
	initMenuA();

    return true;
}
void MainScene::initBG() // ĥ�� ���
{
	auto spr = CCSprite::create("QuizGame/black_board.png");
	spr->setPosition(Point(512, 384));
	this->addChild(spr, 0);
}
void MainScene::initTopMenuLabel() // ���� �� ��� ��ġ
{
	auto label_0 = Label::createWithSystemFont("", "", 20);
	label_0->setAnchorPoint(Point(0, 1));
	label_0->setPosition(Point(10, 10));
	label_0->setTag(TAG_LABEL_QUIZ);
	label_0->setColor(Color3B::RED);
	this->addChild(label_0, 1);

	setLabelQuiz();
}
void MainScene::setLabelQuiz() // ���� ��
{
	auto label = (Label*)this->getChildByTag(TAG_LABEL_QUIZ);
	label->setString(StringUtils::format("Answer : %d/3", Singletons::getInstance()->Answer));
}
void MainScene::initLabelQ() // ����
{
	if (i == 0)
	{
		char Q1[200];
		WideCharToMultiByte(CP_UTF8, 0, L"���̳� �� �ּҴ�?", -1, Q1, 200, NULL, NULL);
		auto Quiz = Label::createWithTTF(Q1, "QuizGame/ABC.ttf", 27);
		Quiz->setAnchorPoint(Point(0, 1));
		Quiz->setPosition(Point(90, 650));
		Quiz->setColor(Color3B::BLACK);
		Quiz->setTag(500);
		this->addChild(Quiz, 2);
		// �� 2��
		WideCharToMultiByte(CP_UTF8, 0, L"�̱� �󽺺����� Ķ�����Ͼ��� ���� 3��° ��\n\n�㸮�� ���ñ� ������ �μ�����\n\n��û���� �ƻ�� ����� ȣ����\n\n������ Ⱦ���� ��õ�� �ǿո�", -1, Q1, 400, NULL, NULL);
		auto Answer = Label::createWithTTF(Q1, "QuizGame/ABC.ttf", 27);
		Answer->setAnchorPoint(Point(0, 1));
		Answer->setPosition(Point(140, 400));
		Answer->setColor(Color3B::BLACK);
		Answer->setTag(520);
		this->addChild(Answer, 2);
	}
	if (i == 1)
	{
		char Q1[200];
		WideCharToMultiByte(CP_UTF8, 0, L"Ÿ��Ÿ���� ����Ʈ���� �� ���� Ż �� ������?", -1, Q1, 200, NULL, NULL);
		auto Quiz = Label::createWithTTF(Q1, "QuizGame/ABC.ttf", 27);
		Quiz->setAnchorPoint(Point(0, 1));
		Quiz->setPosition(Point(90, 650));
		Quiz->setColor(Color3B::BLACK);
		Quiz->setTag(501);
		this->addChild(Quiz, 2);
		// �� 4��
		WideCharToMultiByte(CP_UTF8, 0, L"��������ټ���\n\n4��\n\n5��\n\n9��", -1, Q1, 200, NULL, NULL);
		auto Answer = Label::createWithTTF(Q1, "QuizGame/ABC.ttf", 27);
		Answer->setAnchorPoint(Point(0, 1));
		Answer->setPosition(Point(140, 400));
		Answer->setColor(Color3B::BLACK);
		Answer->setTag(521);
		this->addChild(Answer, 2);
	}
	if (i == 2)
	{
		char Q1[200];
		WideCharToMultiByte(CP_UTF8, 0, L"����ù� ��ΰ� ���ÿ� ��ġ�� ���� ���� �ɱ�?", -1, Q1, 200, NULL, NULL);
		auto Quiz = Label::createWithTTF(Q1, "QuizGame/ABC.ttf", 27);
		Quiz->setAnchorPoint(Point(0, 1));
		Quiz->setPosition(Point(90, 650));
		Quiz->setColor(Color3B::BLACK);
		Quiz->setTag(502);
		this->addChild(Quiz, 2);
		// �� 3��
		WideCharToMultiByte(CP_UTF8, 0, L"��������\n\n���� �����縷 �սô�\n\nõ���� ����\n\n���Ҹ�", -1, Q1, 200, NULL, NULL);
		auto Answer = Label::createWithTTF(Q1, "QuizGame/ABC.ttf", 27);
		Answer->setAnchorPoint(Point(0, 1));
		Answer->setPosition(Point(140, 400));
		Answer->setColor(Color3B::BLACK);
		Answer->setTag(522);
		this->addChild(Answer, 2);
	}
	if (i == 3)
	{
		char Q1[200];
		WideCharToMultiByte(CP_UTF8, 0, L"�˾ �˰� �� �˰� �Ӿ ���� ����?", -1, Q1, 200, NULL, NULL);
		auto Quiz = Label::createWithTTF(Q1, "QuizGame/ABC.ttf", 27);
		Quiz->setAnchorPoint(Point(0, 1));
		Quiz->setPosition(Point(90, 650));
		Quiz->setColor(Color3B::BLACK);
		Quiz->setTag(503);
		this->addChild(Quiz, 2);
		// �� 1��
		WideCharToMultiByte(CP_UTF8, 0, L"�׸���\n\n���� ���\n\n��Ž�� �ڳ��� ����\n\n�ݶ�", -1, Q1, 200, NULL, NULL);
		auto Answer = Label::createWithTTF(Q1, "QuizGame/ABC.ttf", 27);
		Answer->setAnchorPoint(Point(0, 1));
		Answer->setPosition(Point(140, 400));
		Answer->setColor(Color3B::BLACK);
		Answer->setTag(523);
		this->addChild(Answer, 2);
	}
	if (i == 4)
	{
		char Q1[200];
		WideCharToMultiByte(CP_UTF8, 0, L"'�ѹ��� �Ǽ��� ���� ���� ����� ���� ���ο� ���� �õ��غ��� ���� ����̴�.'\n��� ����� ���� ����� �����ΰ�?", -1, Q1, 200, NULL, NULL);
		auto Quiz = Label::createWithTTF(Q1, "QuizGame/ABC.ttf", 27);
		Quiz->setAnchorPoint(Point(0, 1));
		Quiz->setPosition(Point(90, 650));
		Quiz->setColor(Color3B::BLACK);
		Quiz->setTag(504);
		this->addChild(Quiz, 2);
		// �� 2��
		WideCharToMultiByte(CP_UTF8, 0, L"����̸� Ǫƾ\n\n�˹�Ʈ ���ν�Ÿ��\n\n���¿�\n\n��ũ���׽�", -1, Q1, 200, NULL, NULL);
		auto Answer = Label::createWithTTF(Q1, "QuizGame/ABC.ttf", 27);
		Answer->setAnchorPoint(Point(0, 1));
		Answer->setPosition(Point(140, 400));
		Answer->setColor(Color3B::BLACK);
		Answer->setTag(524);
		this->addChild(Answer, 2);
	}
	if (i == 5)
	{
		char Q1[200];
		WideCharToMultiByte(CP_UTF8, 0, L"'� ���� ����� ��ȹ��� ���� �ʴ´ٰ� �ؼ� �װ��� ���ʿ��� ���� �ƴϴ�.'\n��� ����� ���� ����� �����ΰ�?", -1, Q1, 200, NULL, NULL);
		auto Quiz = Label::createWithTTF(Q1, "QuizGame/ABC.ttf", 27);
		Quiz->setAnchorPoint(Point(0, 1));
		Quiz->setPosition(Point(90, 650));
		Quiz->setColor(Color3B::BLACK);
		Quiz->setTag(505);
		this->addChild(Quiz, 2);
		// �� 3��
		WideCharToMultiByte(CP_UTF8, 0, L"�˹�Ʈ ���ν�Ÿ��\n\n�Ƶ��� ��Ʋ��\n\n�丶�� A.����\n\n�ٽ����̴�", -1, Q1, 200, NULL, NULL);
		auto Answer = Label::createWithTTF(Q1, "QuizGame/ABC.ttf", 27);
		Answer->setAnchorPoint(Point(0, 1));
		Answer->setPosition(Point(140, 400));
		Answer->setColor(Color3B::BLACK);
		Answer->setTag(525);
		this->addChild(Answer, 2);
	}
	if (i == 6)
	{
		char Q1[200];
		WideCharToMultiByte(CP_UTF8, 0, L"'�������� ���� �׸��� ����� ��ħ�� �� ���� ��ư���.'\n��� ����� ���� ����� �����ΰ�?", -1, Q1, 200, NULL, NULL);
		auto Quiz = Label::createWithTTF(Q1, "QuizGame/ABC.ttf", 27);
		Quiz->setAnchorPoint(Point(0, 1));
		Quiz->setPosition(Point(90, 650));
		Quiz->setColor(Color3B::BLACK);
		Quiz->setTag(506);
		this->addChild(Quiz, 2);
		// �� 4��
		WideCharToMultiByte(CP_UTF8, 0, L"��ũ���׽�\n\n�̼���\n\n���� ���ٸ�\n\n�ӵ巹 ����", -1, Q1, 200, NULL, NULL);
		auto Answer = Label::createWithTTF(Q1, "QuizGame/ABC.ttf", 27);
		Answer->setAnchorPoint(Point(0, 1));
		Answer->setPosition(Point(140, 400));
		Answer->setColor(Color3B::BLACK);
		Answer->setTag(526);
		this->addChild(Answer, 2);
	}
	if (i == 7)
	{
		char Q1[200];
		WideCharToMultiByte(CP_UTF8, 0, L"'���� ��ο� ���� �� ���� ���� ����.'\n��� ����� ���� ����� �����ΰ�?", -1, Q1, 200, NULL, NULL);
		auto Quiz = Label::createWithTTF(Q1, "QuizGame/ABC.ttf", 27);
		Quiz->setAnchorPoint(Point(0, 1));
		Quiz->setPosition(Point(90, 650));
		Quiz->setColor(Color3B::BLACK);
		Quiz->setTag(507);
		this->addChild(Quiz, 2);
		// �� 1��
		WideCharToMultiByte(CP_UTF8, 0, L"�丶�� A.����\n\n������\n\n����̸� Ǫƾ\n\n�˹�Ʈ ���ν�Ÿ��", -1, Q1, 200, NULL, NULL);
		auto Answer = Label::createWithTTF(Q1, "QuizGame/ABC.ttf", 27);
		Answer->setAnchorPoint(Point(0, 1));
		Answer->setPosition(Point(140, 400));
		Answer->setColor(Color3B::BLACK);
		Answer->setTag(527);
		this->addChild(Answer, 2);
	}
	if (i == 8)
	{
		char Q1[400];
		WideCharToMultiByte(CP_UTF8, 0, L"���� �����ϴ� ������ �������� ������ �̼���� �±������ ���μ��� \n�����Ͽ� ���븦 ��� ��հ� �ֿ� �屺���Է� ���ȴ�.\n�̰��� ( )�̶�� �Ѵ�.", -1, Q1, 400, NULL, NULL);
		auto Quiz = Label::createWithTTF(Q1, "QuizGame/ABC.ttf", 27);
		Quiz->setAnchorPoint(Point(0, 1));
		Quiz->setPosition(Point(90, 650));
		Quiz->setColor(Color3B::BLACK);
		Quiz->setTag(508);
		this->addChild(Quiz, 2);
		// �� 1��
		WideCharToMultiByte(CP_UTF8, 0, L"��ȭ�� ȸ��\n\n��ȭ�� Ⱦ��\n\n���� ����\n\n���ڻ�ȭ", -1, Q1, 200, NULL, NULL);
		auto Answer = Label::createWithTTF(Q1, "QuizGame/ABC.ttf", 27);
		Answer->setAnchorPoint(Point(0, 1));
		Answer->setPosition(Point(140, 400));
		Answer->setColor(Color3B::BLACK);
		Answer->setTag(528);
		this->addChild(Answer, 2);
	}
	if (i == 9)
	{
		char Q1[400];
		WideCharToMultiByte(CP_UTF8, 0, L"�����󿡼� ȫ������ �ݶ��� �Ͼ�� ���� ����, \n���� ���� ������ ���� Ȯ���Ͽ� ������å�� ��� ����� ���� �����ΰ�?", -1, Q1, 400, NULL, NULL);
		auto Quiz = Label::createWithTTF(Q1, "QuizGame/ABC.ttf", 27);
		Quiz->setAnchorPoint(Point(0, 1));
		Quiz->setPosition(Point(90, 650));
		Quiz->setColor(Color3B::BLACK);
		Quiz->setTag(509);
		this->addChild(Quiz, 2);
		// �� 4��
		WideCharToMultiByte(CP_UTF8, 0, L"�漱��\n\n����\n\n��Ŀ�\n\n���ο�", -1, Q1, 200, NULL, NULL);
		auto Answer = Label::createWithTTF(Q1, "QuizGame/ABC.ttf", 27);
		Answer->setAnchorPoint(Point(0, 1));
		Answer->setPosition(Point(140, 400));
		Answer->setColor(Color3B::BLACK);
		Answer->setTag(529);
		this->addChild(Answer, 2);
	}
	if (i == 10)
	{
		char Q1[200];
		WideCharToMultiByte(CP_UTF8, 0, L"������ ������?", -1, Q1, 200, NULL, NULL);
		auto Quiz = Label::createWithTTF(Q1, "QuizGame/ABC.ttf", 27);
		Quiz->setAnchorPoint(Point(0, 1));
		Quiz->setPosition(Point(90, 650));
		Quiz->setColor(Color3B::BLACK);
		Quiz->setTag(510);
		this->addChild(Quiz, 2);
		// �� 3��
		WideCharToMultiByte(CP_UTF8, 0, L"����\n\n����\n\n������\n\n��Ʈ ���׸��θ�ũ", -1, Q1, 200, NULL, NULL);
		auto Answer = Label::createWithTTF(Q1, "QuizGame/ABC.ttf", 27);
		Answer->setAnchorPoint(Point(0, 1));
		Answer->setPosition(Point(140, 400));
		Answer->setColor(Color3B::BLACK);
		Answer->setTag(530);
		this->addChild(Answer, 2);
	}
	if (i == 11)
	{
		char Q1[200];
		WideCharToMultiByte(CP_UTF8, 0, L"���� Ƕ���� ��ġ�� ������ ������ �Ҹ��� �Ƹ��ٿ� ����?", -1, Q1, 200, NULL, NULL);
		auto Quiz = Label::createWithTTF(Q1, "QuizGame/ABC.ttf", 27);
		Quiz->setAnchorPoint(Point(0, 1));
		Quiz->setPosition(Point(90, 650));
		Quiz->setColor(Color3B::BLACK);
		Quiz->setTag(511);
		this->addChild(Quiz, 2);
		// �� 3��
		WideCharToMultiByte(CP_UTF8, 0, L"����ī ��\n\n�󺸸� ��\n\n���̽��ݽ�Ÿ�� ��\n\n����� ��", -1, Q1, 200, NULL, NULL);
		auto Answer = Label::createWithTTF(Q1, "QuizGame/ABC.ttf", 27);
		Answer->setAnchorPoint(Point(0, 1));
		Answer->setPosition(Point(140, 400));
		Answer->setColor(Color3B::BLACK);
		Answer->setTag(531);
		this->addChild(Answer, 2);
	}
}
void MainScene::initMenuA() // �� ��ȣ
{
	auto button_1 = MenuItemImage::create(
		"QuizGame/number1.png",
		"QuizGame/number1_touch.png",
		CC_CALLBACK_1(MainScene::CheckA_1, this));
	button_1->setPosition(Point(110, 385));

	auto menu1 = Menu::create(button_1, NULL);
	menu1->setPosition(Vec2::ZERO);
	this->addChild(menu1, 2); // 1��

	auto button_2 = MenuItemImage::create(
		"QuizGame/number2.png",
		"QuizGame/number2_touch.png",
		CC_CALLBACK_1(MainScene::CheckA_2, this));
	button_2->setPosition(Point(110, 330));

	auto menu2 = Menu::create(button_2, NULL);
	menu2->setPosition(Point::ZERO);
	this->addChild(menu2, 2); // 2��

	auto button_3 = MenuItemImage::create(
		"QuizGame/number3.png",
		"QuizGame/number3_touch.png",
		CC_CALLBACK_1(MainScene::CheckA_3, this));
	button_3->setPosition(Point(110, 275));

	auto menu3 = Menu::create(button_3, NULL);
	menu3->setPosition(Point::ZERO);
	this->addChild(menu3, 2); // 3��

	auto button_4 = MenuItemImage::create(
		"QuizGame/number4.png",
		"QuizGame/number4_touch.png",
		CC_CALLBACK_1(MainScene::CheckA_4, this));
	button_4->setPosition(Point(110, 220));

	auto menu4 = Menu::create(button_4, NULL);
	menu4->setPosition(Point::ZERO);
	this->addChild(menu4, 2); // 4��
}
void MainScene::CheckA_1(Ref * pSender) // 1�� �� Ȯ��
{
	if (i == 3 || i == 7 || i == 8) // 1�� ����
	{
		auto spr = CCSprite::create("QuizGame/o.png");
		spr->setPosition(Point(512, 384));
		this->addChild(spr, 3);

		Singletons::getInstance()->Answer = UserDefault::getInstance()->getIntegerForKey("Answer") + 1;
		UserDefault::getInstance()->setIntegerForKey("Answer", Singletons::getInstance()->Answer);
		UserDefault::getInstance()->flush();

		if (Singletons::getInstance()->Qnum == 2)
		{
			Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
			auto scene = TransitionCrossFade::create(1.5, EndScene::createScene());
			Director::getInstance()->replaceScene(scene);
		}
		else if (Singletons::getInstance()->Qnum < 2)
		{
			Singletons::getInstance()->Qnum = UserDefault::getInstance()->getIntegerForKey("Qnum") + 1;
			UserDefault::getInstance()->setIntegerForKey("Qnum", Singletons::getInstance()->Qnum);
			UserDefault::getInstance()->flush();

			Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
			auto scene = TransitionCrossFade::create(1.5, MainScene::createScene());
			Director::getInstance()->replaceScene(scene);
		}
	}
	else
	{
		auto spr = CCSprite::create("QuizGame/x.png");
		spr->setPosition(Point(512, 384));
		this->addChild(spr, 3);

		if (Singletons::getInstance()->Qnum == 2)
		{
			Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
			auto scene = TransitionCrossFade::create(1.5, EndScene::createScene());
			Director::getInstance()->replaceScene(scene);
		}
		else if (Singletons::getInstance()->Qnum < 2)
		{
			Singletons::getInstance()->Qnum = UserDefault::getInstance()->getIntegerForKey("Qnum") + 1;
			UserDefault::getInstance()->setIntegerForKey("Qnum", Singletons::getInstance()->Qnum);
			UserDefault::getInstance()->flush();

			Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
			auto scene = TransitionCrossFade::create(1.5, MainScene::createScene());
			Director::getInstance()->replaceScene(scene);
		}
	}
}
void MainScene::CheckA_2(Ref * pSender) // 2�� �� Ȯ��
{
	if (i == 0 || i == 4) // 2�� ����
	{
		auto spr = CCSprite::create("QuizGame/o.png");
		spr->setPosition(Point(512, 384));
		this->addChild(spr, 3);

		Singletons::getInstance()->Answer = UserDefault::getInstance()->getIntegerForKey("Answer") + 1;
		UserDefault::getInstance()->setIntegerForKey("Answer", Singletons::getInstance()->Answer);
		UserDefault::getInstance()->flush();

		if (Singletons::getInstance()->Qnum == 2)
		{
			Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
			auto scene = TransitionCrossFade::create(1.5, EndScene::createScene());
			Director::getInstance()->replaceScene(scene);
		}
		else if (Singletons::getInstance()->Qnum < 2)
		{
			Singletons::getInstance()->Qnum = UserDefault::getInstance()->getIntegerForKey("Qnum") + 1;
			UserDefault::getInstance()->setIntegerForKey("Qnum", Singletons::getInstance()->Qnum);
			UserDefault::getInstance()->flush();

			Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
			auto scene = TransitionCrossFade::create(1.5, MainScene::createScene());
			Director::getInstance()->replaceScene(scene);
		}
	}
	else
	{
		auto spr = CCSprite::create("QuizGame/x.png");
		spr->setPosition(Point(512, 384));
		this->addChild(spr, 3);

		if (Singletons::getInstance()->Qnum == 2)
		{
			Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
			auto scene = TransitionCrossFade::create(1.5, EndScene::createScene());
			Director::getInstance()->replaceScene(scene);
		}
		else if (Singletons::getInstance()->Qnum < 2)
		{
			Singletons::getInstance()->Qnum = UserDefault::getInstance()->getIntegerForKey("Qnum") + 1;
			UserDefault::getInstance()->setIntegerForKey("Qnum", Singletons::getInstance()->Qnum);
			UserDefault::getInstance()->flush();

			Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
			auto scene = TransitionCrossFade::create(1.5, MainScene::createScene());
			Director::getInstance()->replaceScene(scene);
		}
	}
}
void MainScene::CheckA_3(Ref * pSender) // 3�� �� Ȯ��
{
	if (i == 2 || i == 5 || i == 10 || i == 11) // 3�� ����
	{
		auto spr = CCSprite::create("QuizGame/o.png");
		spr->setPosition(Point(512, 384));
		this->addChild(spr, 3);

		Singletons::getInstance()->Answer = UserDefault::getInstance()->getIntegerForKey("Answer") + 1;
		UserDefault::getInstance()->setIntegerForKey("Answer", Singletons::getInstance()->Answer);
		UserDefault::getInstance()->flush();

		if (Singletons::getInstance()->Qnum == 2)
		{
			Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
			auto scene = TransitionCrossFade::create(1.5, EndScene::createScene());
			Director::getInstance()->replaceScene(scene);
		}
		else if (Singletons::getInstance()->Qnum < 2)
		{
			Singletons::getInstance()->Qnum = UserDefault::getInstance()->getIntegerForKey("Qnum") + 1;
			UserDefault::getInstance()->setIntegerForKey("Qnum", Singletons::getInstance()->Qnum);
			UserDefault::getInstance()->flush();

			Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
			auto scene = TransitionCrossFade::create(1.5, MainScene::createScene());
			Director::getInstance()->replaceScene(scene);
		}
	}
	else
	{
		auto spr = CCSprite::create("QuizGame/x.png");
		spr->setPosition(Point(512, 384));
		this->addChild(spr, 3);

		if (Singletons::getInstance()->Qnum == 2)
		{
			Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
			auto scene = TransitionCrossFade::create(1.5, EndScene::createScene());
			Director::getInstance()->replaceScene(scene);
		}
		else if (Singletons::getInstance()->Qnum < 2)
		{
			Singletons::getInstance()->Qnum = UserDefault::getInstance()->getIntegerForKey("Qnum") + 1;
			UserDefault::getInstance()->setIntegerForKey("Qnum", Singletons::getInstance()->Qnum);
			UserDefault::getInstance()->flush();

			Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
			auto scene = TransitionCrossFade::create(1.5, MainScene::createScene());
			Director::getInstance()->replaceScene(scene);
		}
	}
}
void MainScene::CheckA_4(Ref * pSender) // 4�� �� Ȯ��
{
	if (i == 1 || i == 6 || i == 9) // 4�� ����
	{
		auto spr = CCSprite::create("QuizGame/o.png");
		spr->setPosition(Point(512, 384));
		this->addChild(spr, 3);

		Singletons::getInstance()->Answer = UserDefault::getInstance()->getIntegerForKey("Answer") + 1;
		UserDefault::getInstance()->setIntegerForKey("Answer", Singletons::getInstance()->Answer);
		UserDefault::getInstance()->flush();

		if (Singletons::getInstance()->Qnum == 2)
		{
			Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
			auto scene = TransitionCrossFade::create(1.5, EndScene::createScene());
			Director::getInstance()->replaceScene(scene);
		}
		else if (Singletons::getInstance()->Qnum < 2)
		{
			Singletons::getInstance()->Qnum = UserDefault::getInstance()->getIntegerForKey("Qnum") + 1;
			UserDefault::getInstance()->setIntegerForKey("Qnum", Singletons::getInstance()->Qnum);
			UserDefault::getInstance()->flush();

			Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
			auto scene = TransitionCrossFade::create(1.5, MainScene::createScene());
			Director::getInstance()->replaceScene(scene);
		}
	}
	else
	{
		auto spr = CCSprite::create("QuizGame/x.png");
		spr->setPosition(Point(512, 384));
		this->addChild(spr, 3);

		if (Singletons::getInstance()->Qnum == 2)
		{
			Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
			auto scene = TransitionCrossFade::create(1.5, EndScene::createScene());
			Director::getInstance()->replaceScene(scene);
		}
		else if (Singletons::getInstance()->Qnum < 2)
		{
			Singletons::getInstance()->Qnum = UserDefault::getInstance()->getIntegerForKey("Qnum") + 1;
			UserDefault::getInstance()->setIntegerForKey("Qnum", Singletons::getInstance()->Qnum);
			UserDefault::getInstance()->flush();

			Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
			auto scene = TransitionCrossFade::create(1.5, MainScene::createScene());
			Director::getInstance()->replaceScene(scene);
		}
	}
}