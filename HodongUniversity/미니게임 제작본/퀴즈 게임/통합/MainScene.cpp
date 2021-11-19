#include "EndScene.h"
#include "MainScene.h"
#include "SimpleAudioEngine.h"
#include <stdlib.h>
#include "singleton.h"

//사운드 할라면 꼭 필요
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

	SimpleAudioEngine::getInstance()->playBackgroundMusic("MiniGameResources/MainBackSound.mp3", true); // 브금

	initBG();
	initLabelQ();
	initMenuA();

    return true;
}
void MainScene::initBG() // 칠판 배경
{
	auto spr = CCSprite::create("QuizGame/black_board.png");
	spr->setPosition(Point(512, 384));
	this->addChild(spr, 0);
}
void MainScene::initTopMenuLabel() // 정답 수 상단 배치
{
	auto label_0 = Label::createWithSystemFont("", "", 20);
	label_0->setAnchorPoint(Point(0, 1));
	label_0->setPosition(Point(10, 10));
	label_0->setTag(TAG_LABEL_QUIZ);
	label_0->setColor(Color3B::RED);
	this->addChild(label_0, 1);

	setLabelQuiz();
}
void MainScene::setLabelQuiz() // 정답 수
{
	auto label = (Label*)this->getChildByTag(TAG_LABEL_QUIZ);
	label->setString(StringUtils::format("Answer : %d/3", Singletons::getInstance()->Answer));
}
void MainScene::initLabelQ() // 문제
{
	if (i == 0)
	{
		char Q1[200];
		WideCharToMultiByte(CP_UTF8, 0, L"개미네 집 주소는?", -1, Q1, 200, NULL, NULL);
		auto Quiz = Label::createWithTTF(Q1, "QuizGame/ABC.ttf", 27);
		Quiz->setAnchorPoint(Point(0, 1));
		Quiz->setPosition(Point(90, 650));
		Quiz->setColor(Color3B::BLACK);
		Quiz->setTag(500);
		this->addChild(Quiz, 2);
		// 답 2번
		WideCharToMultiByte(CP_UTF8, 0, L"미국 라스베가스 캘리포니아주 땅굴 3번째 집\n\n허리도 가늘군 만지면 부서지리\n\n충청남도 아산시 배방읍 호서로\n\n강원도 횡성군 오천면 의왕리", -1, Q1, 400, NULL, NULL);
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
		WideCharToMultiByte(CP_UTF8, 0, L"타이타닉의 구명보트에는 몇 명이 탈 수 있을까?", -1, Q1, 200, NULL, NULL);
		auto Quiz = Label::createWithTTF(Q1, "QuizGame/ABC.ttf", 27);
		Quiz->setAnchorPoint(Point(0, 1));
		Quiz->setPosition(Point(90, 650));
		Quiz->setColor(Color3B::BLACK);
		Quiz->setTag(501);
		this->addChild(Quiz, 2);
		// 답 4번
		WideCharToMultiByte(CP_UTF8, 0, L"서른마흔다섯명\n\n4명\n\n5명\n\n9명", -1, Q1, 200, NULL, NULL);
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
		WideCharToMultiByte(CP_UTF8, 0, L"서울시민 모두가 동시에 외치면 무슨 말이 될까?", -1, Q1, 200, NULL, NULL);
		auto Quiz = Label::createWithTTF(Q1, "QuizGame/ABC.ttf", 27);
		Quiz->setAnchorPoint(Point(0, 1));
		Quiz->setPosition(Point(90, 650));
		Quiz->setColor(Color3B::BLACK);
		Quiz->setTag(502);
		this->addChild(Quiz, 2);
		// 답 3번
		WideCharToMultiByte(CP_UTF8, 0, L"소음공해\n\n갓겜 검은사막 합시다\n\n천만의 말씀\n\n개소리", -1, Q1, 200, NULL, NULL);
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
		WideCharToMultiByte(CP_UTF8, 0, L"검어도 검고 희어도 검고 붉어도 검은 것은?", -1, Q1, 200, NULL, NULL);
		auto Quiz = Label::createWithTTF(Q1, "QuizGame/ABC.ttf", 27);
		Quiz->setAnchorPoint(Point(0, 1));
		Quiz->setPosition(Point(90, 650));
		Quiz->setColor(Color3B::BLACK);
		Quiz->setTag(503);
		this->addChild(Quiz, 2);
		// 답 1번
		WideCharToMultiByte(CP_UTF8, 0, L"그림자\n\n나의 양심\n\n명탐정 코난의 범인\n\n콜라", -1, Q1, 200, NULL, NULL);
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
		WideCharToMultiByte(CP_UTF8, 0, L"'한번도 실수를 하지 않은 사람은 결코 새로운 것을 시도해보지 않은 사람이다.'\n라는 명언을 남긴 사람은 누구인가?", -1, Q1, 200, NULL, NULL);
		auto Quiz = Label::createWithTTF(Q1, "QuizGame/ABC.ttf", 27);
		Quiz->setAnchorPoint(Point(0, 1));
		Quiz->setPosition(Point(90, 650));
		Quiz->setColor(Color3B::BLACK);
		Quiz->setTag(504);
		this->addChild(Quiz, 2);
		// 답 2번
		WideCharToMultiByte(CP_UTF8, 0, L"블라디미르 푸틴\n\n알버트 아인슈타인\n\n배태연\n\n소크라테스", -1, Q1, 200, NULL, NULL);
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
		WideCharToMultiByte(CP_UTF8, 0, L"'어떤 것이 당신의 계획대로 되지 않는다고 해서 그것이 불필요한 것은 아니다.'\n라는 명언을 남긴 사람은 누구인가?", -1, Q1, 200, NULL, NULL);
		auto Quiz = Label::createWithTTF(Q1, "QuizGame/ABC.ttf", 27);
		Quiz->setAnchorPoint(Point(0, 1));
		Quiz->setPosition(Point(90, 650));
		Quiz->setColor(Color3B::BLACK);
		Quiz->setTag(505);
		this->addChild(Quiz, 2);
		// 답 3번
		WideCharToMultiByte(CP_UTF8, 0, L"알버트 아인슈타인\n\n아돌프 히틀러\n\n토마스 A.에디슨\n\n다스베이더", -1, Q1, 200, NULL, NULL);
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
		WideCharToMultiByte(CP_UTF8, 0, L"'오랫동안 꿈을 그리는 사람은 마침내 그 꿈을 닮아간다.'\n라는 명언을 남긴 사람은 누구인가?", -1, Q1, 200, NULL, NULL);
		auto Quiz = Label::createWithTTF(Q1, "QuizGame/ABC.ttf", 27);
		Quiz->setAnchorPoint(Point(0, 1));
		Quiz->setPosition(Point(90, 650));
		Quiz->setColor(Color3B::BLACK);
		Quiz->setTag(506);
		this->addChild(Quiz, 2);
		// 답 4번
		WideCharToMultiByte(CP_UTF8, 0, L"소크라테스\n\n이순신\n\n버락 오바마\n\n앙드레 말로", -1, Q1, 200, NULL, NULL);
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
		WideCharToMultiByte(CP_UTF8, 0, L"'밤이 어두울 때에 더 많은 별을 본다.'\n라는 명언을 남긴 사람은 누구인가?", -1, Q1, 200, NULL, NULL);
		auto Quiz = Label::createWithTTF(Q1, "QuizGame/ABC.ttf", 27);
		Quiz->setAnchorPoint(Point(0, 1));
		Quiz->setPosition(Point(90, 650));
		Quiz->setColor(Color3B::BLACK);
		Quiz->setTag(507);
		this->addChild(Quiz, 2);
		// 답 1번
		WideCharToMultiByte(CP_UTF8, 0, L"토마스 A.에디슨\n\n손지우\n\n블라디미르 푸틴\n\n알버트 아인슈타인", -1, Q1, 200, NULL, NULL);
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
		WideCharToMultiByte(CP_UTF8, 0, L"명나라를 공격하는 원정에 마지못해 참여한 이성계는 좌군도통사 조민수를 \n설득하여 군대를 고려 우왕과 최영 장군에게로 돌렸다.\n이것을 ( )이라고 한다.", -1, Q1, 400, NULL, NULL);
		auto Quiz = Label::createWithTTF(Q1, "QuizGame/ABC.ttf", 27);
		Quiz->setAnchorPoint(Point(0, 1));
		Quiz->setPosition(Point(90, 650));
		Quiz->setColor(Color3B::BLACK);
		Quiz->setTag(508);
		this->addChild(Quiz, 2);
		// 답 1번
		WideCharToMultiByte(CP_UTF8, 0, L"위화도 회군\n\n위화도 횡령\n\n조선 정벌\n\n갑자사화", -1, Q1, 200, NULL, NULL);
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
		WideCharToMultiByte(CP_UTF8, 0, L"원나라에서 홍건적의 반란이 일어나는 것을 보고, \n원의 힘이 약해진 것을 확신하여 개혁정책을 폈던 고려의 왕은 누구인가?", -1, Q1, 400, NULL, NULL);
		auto Quiz = Label::createWithTTF(Q1, "QuizGame/ABC.ttf", 27);
		Quiz->setAnchorPoint(Point(0, 1));
		Quiz->setPosition(Point(90, 650));
		Quiz->setColor(Color3B::BLACK);
		Quiz->setTag(509);
		this->addChild(Quiz, 2);
		// 답 4번
		WideCharToMultiByte(CP_UTF8, 0, L"충선왕\n\n충목왕\n\n충렬왕\n\n공민왕", -1, Q1, 200, NULL, NULL);
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
		WideCharToMultiByte(CP_UTF8, 0, L"독일의 수도는?", -1, Q1, 200, NULL, NULL);
		auto Quiz = Label::createWithTTF(Q1, "QuizGame/ABC.ttf", 27);
		Quiz->setAnchorPoint(Point(0, 1));
		Quiz->setPosition(Point(90, 650));
		Quiz->setColor(Color3B::BLACK);
		Quiz->setTag(510);
		this->addChild(Quiz, 2);
		// 답 3번
		WideCharToMultiByte(CP_UTF8, 0, L"런던\n\n뮌헨\n\n베를린\n\n상트 페테르부르크", -1, Q1, 200, NULL, NULL);
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
		WideCharToMultiByte(CP_UTF8, 0, L"독일 퓌센에 위치한 백조의 성으로 불리는 아름다운 성은?", -1, Q1, 200, NULL, NULL);
		auto Quiz = Label::createWithTTF(Q1, "QuizGame/ABC.ttf", 27);
		Quiz->setAnchorPoint(Point(0, 1));
		Quiz->setPosition(Point(90, 650));
		Quiz->setColor(Color3B::BLACK);
		Quiz->setTag(511);
		this->addChild(Quiz, 2);
		// 답 3번
		WideCharToMultiByte(CP_UTF8, 0, L"오사카 성\n\n상보르 성\n\n노이슈반슈타인 성\n\n디즈니 성", -1, Q1, 200, NULL, NULL);
		auto Answer = Label::createWithTTF(Q1, "QuizGame/ABC.ttf", 27);
		Answer->setAnchorPoint(Point(0, 1));
		Answer->setPosition(Point(140, 400));
		Answer->setColor(Color3B::BLACK);
		Answer->setTag(531);
		this->addChild(Answer, 2);
	}
}
void MainScene::initMenuA() // 답 번호
{
	auto button_1 = MenuItemImage::create(
		"QuizGame/number1.png",
		"QuizGame/number1_touch.png",
		CC_CALLBACK_1(MainScene::CheckA_1, this));
	button_1->setPosition(Point(110, 385));

	auto menu1 = Menu::create(button_1, NULL);
	menu1->setPosition(Vec2::ZERO);
	this->addChild(menu1, 2); // 1번

	auto button_2 = MenuItemImage::create(
		"QuizGame/number2.png",
		"QuizGame/number2_touch.png",
		CC_CALLBACK_1(MainScene::CheckA_2, this));
	button_2->setPosition(Point(110, 330));

	auto menu2 = Menu::create(button_2, NULL);
	menu2->setPosition(Point::ZERO);
	this->addChild(menu2, 2); // 2번

	auto button_3 = MenuItemImage::create(
		"QuizGame/number3.png",
		"QuizGame/number3_touch.png",
		CC_CALLBACK_1(MainScene::CheckA_3, this));
	button_3->setPosition(Point(110, 275));

	auto menu3 = Menu::create(button_3, NULL);
	menu3->setPosition(Point::ZERO);
	this->addChild(menu3, 2); // 3번

	auto button_4 = MenuItemImage::create(
		"QuizGame/number4.png",
		"QuizGame/number4_touch.png",
		CC_CALLBACK_1(MainScene::CheckA_4, this));
	button_4->setPosition(Point(110, 220));

	auto menu4 = Menu::create(button_4, NULL);
	menu4->setPosition(Point::ZERO);
	this->addChild(menu4, 2); // 4번
}
void MainScene::CheckA_1(Ref * pSender) // 1번 답 확인
{
	if (i == 3 || i == 7 || i == 8) // 1번 정답
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
void MainScene::CheckA_2(Ref * pSender) // 2번 답 확인
{
	if (i == 0 || i == 4) // 2번 정답
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
void MainScene::CheckA_3(Ref * pSender) // 3번 답 확인
{
	if (i == 2 || i == 5 || i == 10 || i == 11) // 3번 정답
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
void MainScene::CheckA_4(Ref * pSender) // 4번 답 확인
{
	if (i == 1 || i == 6 || i == 9) // 4번 정답
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