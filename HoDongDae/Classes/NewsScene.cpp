#include "NewsScene.h"
#include "SimpleAudioEngine.h"
#include "MainScene.h"
#include "chrcreateScene.h"
#include "sinngleton.h"
#include "NextDayScene.h"
#include "BudongScene.h"
//사운드 할라면 꼭 필요
using namespace CocosDenshion;
USING_NS_CC;

Scene* NewsScene::createScene()
{
    auto scene = Scene::create();
    auto layer = NewsScene::create();
    scene->addChild(layer);

    return scene;
}

bool NewsScene::init()
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
	//listener->onTouchBegan = CC_CALLBACK_2(NewsScene::onTouchBegan, this);
	//Director::getInstance()->getEventDispatcher()->addEventListenerWithFixedPriority(listener, 1);

	//배경음악
	SimpleAudioEngine::getInstance()->playBackgroundMusic("sound/1975.mp3", true);

    return true;
}
void NewsScene::update(float ft)
{
	//씬 자체적으로 반복 되야하는 내용
}
void NewsScene::InitBackGround()
{
	auto sprite = Sprite::create("MiniGameResources/stock_exchange.png");
	sprite->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	this->addChild(sprite, 0);
}
void NewsScene::InitLabel()
{
	

	
}
// 인트로 선택창
void NewsScene::InitMenu()
{
	auto action_item3 = MenuItemImage::create(
		"MiniGameResources/UI_newspaper.png",
		"MiniGameResources/UI_newspaper.png",
		// 임시 
		CC_CALLBACK_1(NewsScene::replayspr, this));
	action_item3->setPosition(Point(0, 0));

	auto play = Menu::create(action_item3, NULL);
	play->setAnchorPoint(Point(0.5, 0));
	play->setPosition(Point(520, 390));
	play->setTag(120);
	this->addChild(play, 1);

	int i,num;
	int j, num_2;
	//3월 첫주차
	if (Singletons::getInstance()->month == 3)
	{
		if (Singletons::getInstance()->day == 13)
		{
			char MyString[200];
			WideCharToMultiByte(CP_UTF8, 0, L"알지회사 신형 청정정수기 개발... 이제는 안심하고 마실수있어... 발표  ", -1, MyString, 200, NULL, NULL);
			auto name = Label::createWithTTF(MyString, "fonts/ABC.ttf", 25
				, Size(400, 200),
				TextHAlignment::CENTER,
				TextVAlignment::CENTER);
			name->setAnchorPoint(Point(0, 1));
			name->setPosition(Point(340, 520));
			name->setColor(Color3B::BLACK);
			name->setTag(128);
			this->addChild(name, 4);

			auto text_item = MenuItemImage::create(
				"MiniGameResources/ok_button.png",
				"MiniGameResources/ok_buttonpr.png",
				CC_CALLBACK_1(NewsScene::Gojudgment, this));
			text_item->setAnchorPoint(Point(0.5, 0.5));
			text_item->setPosition(Point(950, 65));

			auto text = Menu::create(text_item, NULL);
			text->setAnchorPoint(Point(0.5, 0.5));
			text->setPosition(Point(0, 0));
			text->setTag(130);
			this->addChild(text, 5);
		}
		//Singletons::getInstance()->num_3 == 1	
			//나쁜소식
		if (Singletons::getInstance()->day == 27 )
		{
			if (Singletons::getInstance()->num_3 == 3)
			{
				Singletons::getInstance()->num_3 = rand() % 2 + 1;
			}
			if (Singletons::getInstance()->num_3 == 1)
			{
				char MyString[200];
				WideCharToMultiByte(CP_UTF8, 0, L"알지회사 신형 청정정수기 오염물질 발견 돼... 알지회사 공식사과...", -1, MyString, 200, NULL, NULL);
				auto name = Label::createWithTTF(MyString, "fonts/ABC.ttf", 25
					, Size(400, 200),
					TextHAlignment::CENTER,
					TextVAlignment::CENTER);;
				name->setAnchorPoint(Point(0, 1));
				name->setPosition(Point(320, 520));
				name->setColor(Color3B::BLACK);
				name->setTag(144);
				this->addChild(name, 4);

				auto text_item = MenuItemImage::create(
					"MiniGameResources/ok_button.png",
					"MiniGameResources/ok_buttonpr.png",
					CC_CALLBACK_1(NewsScene::Gojudgment_2, this));
				text_item->setAnchorPoint(Point(0.5, 0.5));
				text_item->setPosition(Point(950, 65));

				auto text = Menu::create(text_item, NULL);
				text->setAnchorPoint(Point(0.5, 0.5));
				text->setPosition(Point(0, 0));
				text->setTag(131);
				this->addChild(text, 5);
				Singletons::getInstance()->num_3 == 0;
			}
			if (Singletons::getInstance()->num_3 == 2)
			{
				char MyString[200];
				WideCharToMultiByte(CP_UTF8, 0, L"알지회사 피해입은 고객 모두 보상... 참기업의 표본!", -1, MyString, 200, NULL, NULL);
				auto name = Label::createWithTTF(MyString, "fonts/ABC.ttf", 25
					, Size(400, 200),
					TextHAlignment::CENTER,
					TextVAlignment::CENTER);;
				name->setAnchorPoint(Point(0, 1));
				name->setPosition(Point(320, 520));
				name->setColor(Color3B::BLACK);
				name->setTag(144);
				this->addChild(name, 4);

				auto text_item = MenuItemImage::create(
					"MiniGameResources/ok_button.png",
					"MiniGameResources/ok_buttonpr.png",
					CC_CALLBACK_1(NewsScene::Gojudgment_2, this));
				text_item->setAnchorPoint(Point(0.5, 0.5));
				text_item->setPosition(Point(950, 65));

				auto text = Menu::create(text_item, NULL);
				text->setAnchorPoint(Point(0.5, 0.5));
				text->setPosition(Point(0, 0));
				text->setTag(131);
				this->addChild(text, 5);
				Singletons::getInstance()->num_3 == 0;
			}

	
		}
		
	}
	//4월 첫주차
	if (Singletons::getInstance()->month == 4)
	{
		if (Singletons::getInstance()->day == 13)
		{
			char MyString[200];
			WideCharToMultiByte(CP_UTF8, 0, L"별삼회사 이가물치부회장 구설수 논란... 영상에 찍힌 여성은 누구?", -1, MyString, 200, NULL, NULL);
			auto name = Label::createWithTTF(MyString, "fonts/ABC.ttf", 25
				, Size(400, 200),
				TextHAlignment::CENTER,
				TextVAlignment::CENTER);;
			name->setAnchorPoint(Point(0, 1));
			name->setPosition(Point(320, 520));
			name->setColor(Color3B::BLACK);
			name->setTag(144);
			this->addChild(name, 4);

			auto text_item = MenuItemImage::create(
				"MiniGameResources/ok_button.png",
				"MiniGameResources/ok_buttonpr.png",
				CC_CALLBACK_1(NewsScene::Gojudgment, this));
			text_item->setAnchorPoint(Point(0.5, 0.5));
			text_item->setPosition(Point(950, 65));

			auto text = Menu::create(text_item, NULL);
			text->setAnchorPoint(Point(0.5, 0.5));
			text->setPosition(Point(0, 0));
			text->setTag(130);
			this->addChild(text, 5);

		}
		
		if (Singletons::getInstance()->day == 27)
		{
			if (Singletons::getInstance()->num_3 == 3)
			{
				Singletons::getInstance()->num_3 = rand() % 2 + 1;
			}
			
			if (Singletons::getInstance()->num_3 == 1)
			{
				char MyString[300];
				WideCharToMultiByte(CP_UTF8, 0, L"별삼회사 이가물치부회장 구설수 논란 진실로 밝혀져 내연녀 존재해... 기업이미지 대하락!", -1, MyString, 300, NULL, NULL);
				auto name = Label::createWithTTF(MyString, "fonts/ABC.ttf", 25
					, Size(400, 200),
					TextHAlignment::CENTER,
					TextVAlignment::CENTER);;
				name->setAnchorPoint(Point(0, 1));
				name->setPosition(Point(320, 520));
				name->setColor(Color3B::BLACK);
				name->setTag(144);
				this->addChild(name, 4);

				auto text_item = MenuItemImage::create(
					"MiniGameResources/ok_button.png",
					"MiniGameResources/ok_buttonpr.png",
					CC_CALLBACK_1(NewsScene::fin, this));
				text_item->setAnchorPoint(Point(0.5, 0.5));
				text_item->setPosition(Point(950, 65));

				auto text = Menu::create(text_item, NULL);
				text->setAnchorPoint(Point(0.5, 0.5));
				text->setPosition(Point(0, 0));
				text->setTag(131);
				this->addChild(text, 5);
				Singletons::getInstance()->num_3 == 0;
			}
			if (Singletons::getInstance()->num_3 == 2)
			{
				char MyString[400];
				WideCharToMultiByte(CP_UTF8, 0, L"구설수에 올랐던 이가물치부회장. 영상에 찍힌 사람은 이가물치부회장이 아니었음이 밝혀져... 영상을 제작한 장본인 잡아내 엄중처벌 할 것이라고 공식 발표.", -1, MyString, 400, NULL, NULL);
				auto name = Label::createWithTTF(MyString, "fonts/ABC.ttf", 25
					, Size(400, 200),
					TextHAlignment::CENTER,
					TextVAlignment::CENTER);;
				name->setAnchorPoint(Point(0, 1));
				name->setPosition(Point(320, 520));
				name->setColor(Color3B::BLACK);
				name->setTag(144);
				this->addChild(name, 4);

				auto text_item = MenuItemImage::create(
					"MiniGameResources/ok_button.png",
					"MiniGameResources/ok_buttonpr.png",
					CC_CALLBACK_1(NewsScene::fin, this));
				text_item->setAnchorPoint(Point(0.5, 0.5));
				text_item->setPosition(Point(950, 65));

				auto text = Menu::create(text_item, NULL);
				text->setAnchorPoint(Point(0.5, 0.5));
				text->setPosition(Point(0, 0));
				text->setTag(131);
				this->addChild(text, 5);
				Singletons::getInstance()->num_3 == 0;
			}

		
		}
		
	}
	//5월 첫주차
	if (Singletons::getInstance()->month == 5)
	{
		if (Singletons::getInstance()->day == 13 )
		{
			char MyString[200];
			WideCharToMultiByte(CP_UTF8, 0, L"키악회사 자동차 신시리즈 해외 수출 준비 중...", -1, MyString, 200, NULL, NULL);
			auto name = Label::createWithTTF(MyString, "fonts/ABC.ttf", 25
				, Size(400, 200),
				TextHAlignment::CENTER,
				TextVAlignment::CENTER);;
			name->setAnchorPoint(Point(0, 1));
			name->setPosition(Point(320, 520));
			name->setColor(Color3B::BLACK);
			name->setTag(144);
			this->addChild(name, 4);

			auto text_item = MenuItemImage::create(
				"MiniGameResources/ok_button.png",
				"MiniGameResources/ok_buttonpr.png",
				CC_CALLBACK_1(NewsScene::Gojudgment, this));
			text_item->setAnchorPoint(Point(0.5, 0.5));
			text_item->setPosition(Point(950, 65));

			auto text = Menu::create(text_item, NULL);
			text->setAnchorPoint(Point(0.5, 0.5));
			text->setPosition(Point(0, 0));
			text->setTag(130);
			this->addChild(text, 5);
		}
		if (Singletons::getInstance()->day == 27)
		{
			if (Singletons::getInstance()->num_3 == 3)
			{
				Singletons::getInstance()->num_3 = rand() % 2 + 1;
			}
			if (Singletons::getInstance()->num_3 == 1)
			{
				char MyString[200];
				WideCharToMultiByte(CP_UTF8, 0, L"키악 회사 해외진출 대실패... 한국사업에 전념할 예정...", -1, MyString, 200, NULL, NULL);
				auto name = Label::createWithTTF(MyString, "fonts/ABC.ttf", 25
					, Size(400, 200),
					TextHAlignment::CENTER,
					TextVAlignment::CENTER);;
				name->setAnchorPoint(Point(0, 1));
				name->setPosition(Point(320, 520));
				name->setColor(Color3B::BLACK);
				name->setTag(144);
				this->addChild(name, 4);

				auto text_item = MenuItemImage::create(
					"MiniGameResources/ok_button.png",
					"MiniGameResources/ok_buttonpr.png",
					CC_CALLBACK_1(NewsScene::fin, this));
				text_item->setAnchorPoint(Point(0.5, 0.5));
				text_item->setPosition(Point(950, 65));

				auto text = Menu::create(text_item, NULL);
				text->setAnchorPoint(Point(0.5, 0.5));
				text->setPosition(Point(0, 0));
				text->setTag(131);
				this->addChild(text, 5);
				Singletons::getInstance()->num_3 == 0;
			}
			if (Singletons::getInstance()->num_3 == 2)
			{
				char MyString[200];
				WideCharToMultiByte(CP_UTF8, 0, L"키악회사 자동차 K시리즈 외국에서 대성황! 안정적인 승차감으로 인기대상승", -1, MyString, 200, NULL, NULL);
				auto name = Label::createWithTTF(MyString, "fonts/ABC.ttf", 25
					, Size(400, 200),
					TextHAlignment::CENTER,
					TextVAlignment::CENTER);;
				name->setAnchorPoint(Point(0, 1));
				name->setPosition(Point(320, 520));
				name->setColor(Color3B::BLACK);
				name->setTag(144);
				this->addChild(name, 4);

				auto text_item = MenuItemImage::create(
					"MiniGameResources/ok_button.png",
					"MiniGameResources/ok_buttonpr.png",
					CC_CALLBACK_1(NewsScene::fin, this));
				text_item->setAnchorPoint(Point(0.5, 0.5));
				text_item->setPosition(Point(950, 65));

				auto text = Menu::create(text_item, NULL);
				text->setAnchorPoint(Point(0.5, 0.5));
				text->setPosition(Point(0, 0));
				text->setTag(131);
				this->addChild(text, 5);
				Singletons::getInstance()->num_3 == 0;
			}


		}
		
	}
//	6월 첫주차
	if (Singletons::getInstance()->month == 6)
	{
		if (Singletons::getInstance()->day == 13)
		{
			char MyString[200];
			WideCharToMultiByte(CP_UTF8, 0, L"별삼회사 만능 내복약 개발 중 발표 곧 아픔없는 세상 만들 수 있어... 발표", -1, MyString, 200, NULL, NULL);
			auto name = Label::createWithTTF(MyString, "fonts/ABC.ttf", 25
				, Size(400, 200),
				TextHAlignment::CENTER,
				TextVAlignment::CENTER);;
			name->setAnchorPoint(Point(0, 1));
			name->setPosition(Point(320, 520));
			name->setColor(Color3B::BLACK);
			name->setTag(144);
			this->addChild(name, 4);

			auto text_item = MenuItemImage::create(
				"MiniGameResources/ok_button.png",
				"MiniGameResources/ok_buttonpr.png",
				CC_CALLBACK_1(NewsScene::Gojudgment, this));
			text_item->setAnchorPoint(Point(0.5, 0.5));
			text_item->setPosition(Point(950, 65));

			auto text = Menu::create(text_item, NULL);
			text->setAnchorPoint(Point(0.5, 0.5));
			text->setPosition(Point(0, 0));
			text->setTag(130);
			this->addChild(text, 5);
		}
		if (Singletons::getInstance()->day == 27)
		{
			if (Singletons::getInstance()->num_3 == 3)
			{
				Singletons::getInstance()->num_3 = rand() % 2 + 1;
			}
			if (Singletons::getInstance()->num_3 == 1)
			{
				char MyString[300];
				WideCharToMultiByte(CP_UTF8, 0, L"별삼회사 약품 부작용 발생! 응급실환자 급증!", -1, MyString, 300, NULL, NULL);
				auto name = Label::createWithTTF(MyString, "fonts/ABC.ttf", 25
					, Size(400, 200),
					TextHAlignment::CENTER,
					TextVAlignment::CENTER);;
				name->setAnchorPoint(Point(0, 1));
				name->setPosition(Point(320, 520));
				name->setColor(Color3B::BLACK);
				name->setTag(144);
				this->addChild(name, 4);

				auto text_item = MenuItemImage::create(
					"MiniGameResources/ok_button.png",
					"MiniGameResources/ok_buttonpr.png",
					CC_CALLBACK_1(NewsScene::fin, this));
				text_item->setAnchorPoint(Point(0.5, 0.5));
				text_item->setPosition(Point(950, 65));

				auto text = Menu::create(text_item, NULL);
				text->setAnchorPoint(Point(0.5, 0.5));
				text->setPosition(Point(0, 0));
				text->setTag(131);
				this->addChild(text, 5);
				Singletons::getInstance()->num_3 == 0;
			}
			if (Singletons::getInstance()->num_3 == 2)
			{
				char MyString[300];
				WideCharToMultiByte(CP_UTF8, 0, L" 별삼회사의 내복약 한알만복용하면 아픈것이 싹나아... 별삼회사의 내복약이 효과가뛰어난 것이 증명되어 매물이 부족하게될지경...", -1, MyString, 300, NULL, NULL);
				auto name = Label::createWithTTF(MyString, "fonts/ABC.ttf", 25
					, Size(400, 200),
					TextHAlignment::CENTER,
					TextVAlignment::CENTER);;
				name->setAnchorPoint(Point(0, 1));
				name->setPosition(Point(320, 520));
				name->setColor(Color3B::BLACK);
				name->setTag(144);
				this->addChild(name, 4);

				auto text_item = MenuItemImage::create(
					"MiniGameResources/ok_button.png",
					"MiniGameResources/ok_buttonpr.png",
					CC_CALLBACK_1(NewsScene::fin, this));
				text_item->setAnchorPoint(Point(0.5, 0.5));
				text_item->setPosition(Point(950, 65));

				auto text = Menu::create(text_item, NULL);
				text->setAnchorPoint(Point(0.5, 0.5));
				text->setPosition(Point(0, 0));
				text->setTag(131);
				this->addChild(text, 5);
				Singletons::getInstance()->num_3 == 0;
			}


		}
		
	}
	//7월 첫주차
	if (Singletons::getInstance()->month == 7)
	{
		if (Singletons::getInstance()->day == 13 )
		{
			char MyString[200];
			WideCharToMultiByte(CP_UTF8, 0, L"파인애플회사 아이뻥의 차기작 출시 예정!", -1, MyString, 200, NULL, NULL);
			auto name = Label::createWithTTF(MyString, "fonts/ABC.ttf", 25
				, Size(400, 200),
				TextHAlignment::CENTER,
				TextVAlignment::CENTER);;
			name->setAnchorPoint(Point(0, 1));
			name->setPosition(Point(320, 520));
			name->setColor(Color3B::BLACK);
			name->setTag(144);
			this->addChild(name, 4);

			auto text_item = MenuItemImage::create(
				"MiniGameResources/ok_button.png",
				"MiniGameResources/ok_buttonpr.png",
				CC_CALLBACK_1(NewsScene::Gojudgment, this));
			text_item->setAnchorPoint(Point(0.5, 0.5));
			text_item->setPosition(Point(950, 65));

			auto text = Menu::create(text_item, NULL);
			text->setAnchorPoint(Point(0.5, 0.5));
			text->setPosition(Point(0, 0));
			text->setTag(130);
			this->addChild(text, 5);

		}
		if (Singletons::getInstance()->day == 27 )
		{
			if (Singletons::getInstance()->num_3 == 3)
			{
				Singletons::getInstance()->num_3 = rand() % 2 + 1;
			}
			if (Singletons::getInstance()->num_3 == 1)
			{
				char MyString[300];
				WideCharToMultiByte(CP_UTF8, 0, L"파인애플회사 아이뻥의 차기작 편의를 위해 줄인 기능들 사용하기 너무 불편해 환불항의 빗발쳐... 주가 하락 중...", -1, MyString, 300, NULL, NULL);
				auto name = Label::createWithTTF(MyString, "fonts/ABC.ttf", 25
					, Size(400, 200),
					TextHAlignment::CENTER,
					TextVAlignment::CENTER);;
				name->setAnchorPoint(Point(0, 1));
				name->setPosition(Point(320, 520));
				name->setColor(Color3B::BLACK);
				name->setTag(144);
				this->addChild(name, 4);

				auto text_item = MenuItemImage::create(
					"MiniGameResources/ok_button.png",
					"MiniGameResources/ok_buttonpr.png",
					CC_CALLBACK_1(NewsScene::fin, this));
				text_item->setAnchorPoint(Point(0.5, 0.5));
				text_item->setPosition(Point(950, 65));

				auto text = Menu::create(text_item, NULL);
				text->setAnchorPoint(Point(0.5, 0.5));
				text->setPosition(Point(0, 0));
				text->setTag(131);
				this->addChild(text, 5);
				Singletons::getInstance()->num_3 == 0;
			}
			if (Singletons::getInstance()->num_3 == 2)
			{
				char MyString[300];
				WideCharToMultiByte(CP_UTF8, 0, L"파인애플 회사 아이뻥의 차기작 아이뻥만큼 대성공... 매물이 부족해...", -1, MyString, 300, NULL, NULL);
				auto name = Label::createWithTTF(MyString, "fonts/ABC.ttf", 25
					, Size(400, 200),
					TextHAlignment::CENTER,
					TextVAlignment::CENTER);;
				name->setAnchorPoint(Point(0, 1));
				name->setPosition(Point(320, 520));
				name->setColor(Color3B::BLACK);
				name->setTag(144);
				this->addChild(name, 4);

				auto text_item = MenuItemImage::create(
					"MiniGameResources/ok_button.png",
					"MiniGameResources/ok_buttonpr.png",
					CC_CALLBACK_1(NewsScene::fin, this));
				text_item->setAnchorPoint(Point(0.5, 0.5));
				text_item->setPosition(Point(950, 65));

				auto text = Menu::create(text_item, NULL);
				text->setAnchorPoint(Point(0.5, 0.5));
				text->setPosition(Point(0, 0));
				text->setTag(131);
				this->addChild(text, 5);
				Singletons::getInstance()->num_3 == 0;
			}


		}
		
	}
	//8월 첫주차
	if (Singletons::getInstance()->month == 8)
	{
		if (Singletons::getInstance()->day == 13)
		{
			char MyString[200];
			WideCharToMultiByte(CP_UTF8, 0, L"알지회사 던져도 안깨지는 벽돌폰 옵티머스프라임 신시리즈 출시", -1, MyString, 200, NULL, NULL);
			auto name = Label::createWithTTF(MyString, "fonts/ABC.ttf", 25
				, Size(400, 200),
				TextHAlignment::CENTER,
				TextVAlignment::CENTER);;
			name->setAnchorPoint(Point(0, 1));
			name->setPosition(Point(320, 520));
			name->setColor(Color3B::BLACK);
			name->setTag(144);
			this->addChild(name, 4);

			auto text_item = MenuItemImage::create(
				"MiniGameResources/ok_button.png",
				"MiniGameResources/ok_buttonpr.png",
				CC_CALLBACK_1(NewsScene::Gojudgment, this));
			text_item->setAnchorPoint(Point(0.5, 0.5));
			text_item->setPosition(Point(950, 65));

			auto text = Menu::create(text_item, NULL);
			text->setAnchorPoint(Point(0.5, 0.5));
			text->setPosition(Point(0, 0));
			text->setTag(130);
			this->addChild(text, 5);
		}
		if (Singletons::getInstance()->day == 27 )
		{
			if (Singletons::getInstance()->num_3 == 3)
			{
				Singletons::getInstance()->num_3 = rand() % 2 + 1;
			}
			if (Singletons::getInstance()->num_3 == 1)
			{
				char MyString[300];
				WideCharToMultiByte(CP_UTF8, 0, L"알지회사 새로운 옵티머스프라임 인체에 해로운 성분 검출 돼... 알지회사 공식사과", -1, MyString, 300, NULL, NULL);
				auto name = Label::createWithTTF(MyString, "fonts/ABC.ttf", 25
					, Size(400, 200),
					TextHAlignment::CENTER,
					TextVAlignment::CENTER);;
				name->setAnchorPoint(Point(0, 1));
				name->setPosition(Point(320, 520));
				name->setColor(Color3B::BLACK);
				name->setTag(144);
				this->addChild(name, 4);

				auto text_item = MenuItemImage::create(
					"MiniGameResources/ok_button.png",
					"MiniGameResources/ok_buttonpr.png",
					CC_CALLBACK_1(NewsScene::fin, this));
				text_item->setAnchorPoint(Point(0.5, 0.5));
				text_item->setPosition(Point(950, 65));

				auto text = Menu::create(text_item, NULL);
				text->setAnchorPoint(Point(0.5, 0.5));
				text->setPosition(Point(0, 0));
				text->setTag(131);
				this->addChild(text, 5);
				Singletons::getInstance()->num_3 == 0;
			}
			if (Singletons::getInstance()->num_3 == 2)
			{
				char MyString[300];
				WideCharToMultiByte(CP_UTF8, 0, L"알지회사 옵티머스 성공적... 더많은 물건 생산할 수 있어...", -1, MyString, 300, NULL, NULL);
				auto name = Label::createWithTTF(MyString, "fonts/ABC.ttf", 25
					, Size(400, 200),
					TextHAlignment::CENTER,
					TextVAlignment::CENTER);;
				name->setAnchorPoint(Point(0, 1));
				name->setPosition(Point(320, 520));
				name->setColor(Color3B::BLACK);
				name->setTag(144);
				this->addChild(name, 4);

				auto text_item = MenuItemImage::create(
					"MiniGameResources/ok_button.png",
					"MiniGameResources/ok_buttonpr.png",
					CC_CALLBACK_1(NewsScene::fin, this));
				text_item->setAnchorPoint(Point(0.5, 0.5));
				text_item->setPosition(Point(950, 65));

				auto text = Menu::create(text_item, NULL);
				text->setAnchorPoint(Point(0.5, 0.5));
				text->setPosition(Point(0, 0));
				text->setTag(131);
				this->addChild(text, 5);
				Singletons::getInstance()->num_3 == 0;
			}


		}
		
	}
	//9월 첫주차
	if (Singletons::getInstance()->month == 9)
	{
		if (Singletons::getInstance()->day == 13)
		{
			char MyString[200];
			WideCharToMultiByte(CP_UTF8, 0, L"키악회사 자동운전 자동차 곧 출시... 발표", -1, MyString, 200, NULL, NULL);
			auto name = Label::createWithTTF(MyString, "fonts/ABC.ttf", 25
				, Size(400, 200),
				TextHAlignment::CENTER,
				TextVAlignment::CENTER);;
			name->setAnchorPoint(Point(0, 1));
			name->setPosition(Point(320, 520));
			name->setColor(Color3B::BLACK);
			name->setTag(144);
			this->addChild(name, 4);

			auto text_item = MenuItemImage::create(
				"MiniGameResources/ok_button.png",
				"MiniGameResources/ok_buttonpr.png",
				CC_CALLBACK_1(NewsScene::Gojudgment, this));
			text_item->setAnchorPoint(Point(0.5, 0.5));
			text_item->setPosition(Point(950, 65));

			auto text = Menu::create(text_item, NULL);
			text->setAnchorPoint(Point(0.5, 0.5));
			text->setPosition(Point(0, 0));
			text->setTag(130);
			this->addChild(text, 5);
		}
		if (Singletons::getInstance()->day == 27)
		{
			if (Singletons::getInstance()->num_3 == 3)
			{
				Singletons::getInstance()->num_3 = rand() % 2 + 1;
			}
			if (Singletons::getInstance()->num_3 == 1)
			{
				char MyString[300];
				WideCharToMultiByte(CP_UTF8, 0, L"키악회사 자동운전 자동차 심각한 문제 발견해... 출시 지연... ", -1, MyString, 300, NULL, NULL);
				auto name = Label::createWithTTF(MyString, "fonts/ABC.ttf", 25
					, Size(400, 200),
					TextHAlignment::CENTER,
					TextVAlignment::CENTER);;
				name->setAnchorPoint(Point(0, 1));
				name->setPosition(Point(320, 520));
				name->setColor(Color3B::BLACK);
				name->setTag(144);
				this->addChild(name, 4);

				auto text_item = MenuItemImage::create(
					"MiniGameResources/ok_button.png",
					"MiniGameResources/ok_buttonpr.png",
					CC_CALLBACK_1(NewsScene::fin, this));
				text_item->setAnchorPoint(Point(0.5, 0.5));
				text_item->setPosition(Point(950, 65));

				auto text = Menu::create(text_item, NULL);
				text->setAnchorPoint(Point(0.5, 0.5));
				text->setPosition(Point(0, 0));
				text->setTag(131);
				this->addChild(text, 5);
				Singletons::getInstance()->num_3 == 0;
			}
			if (Singletons::getInstance()->num_3 == 2)
			{
				char MyString[300];
				WideCharToMultiByte(CP_UTF8, 0, L"키악회사 자동운전자동차 문제없어. 이제 정말 운전할 필요가없는 세상이찾아와...", -1, MyString, 300, NULL, NULL);
				auto name = Label::createWithTTF(MyString, "fonts/ABC.ttf", 25
					, Size(400, 200),
					TextHAlignment::CENTER,
					TextVAlignment::CENTER);;
				name->setAnchorPoint(Point(0, 1));
				name->setPosition(Point(320, 520));
				name->setColor(Color3B::BLACK);
				name->setTag(144);
				this->addChild(name, 4);

				auto text_item = MenuItemImage::create(
					"MiniGameResources/ok_button.png",
					"MiniGameResources/ok_buttonpr.png",
					CC_CALLBACK_1(NewsScene::fin, this));
				text_item->setAnchorPoint(Point(0.5, 0.5));
				text_item->setPosition(Point(950, 65));

				auto text = Menu::create(text_item, NULL);
				text->setAnchorPoint(Point(0.5, 0.5));
				text->setPosition(Point(0, 0));
				text->setTag(131);
				this->addChild(text, 5);
				Singletons::getInstance()->num_3 == 0;
			}


		}
		
	}
	//10월 첫주차
	if (Singletons::getInstance()->month == 10)
	{
		if (Singletons::getInstance()->day == 13)
		{
			char MyString[200];
			WideCharToMultiByte(CP_UTF8, 0, L"별삼회사 이건어물회장 뒷목 잡고 쓰러져... 별삼회사 이렇게 흔들리나", -1, MyString, 200, NULL, NULL);
			auto name = Label::createWithTTF(MyString, "fonts/ABC.ttf", 25
				, Size(400, 200),
				TextHAlignment::CENTER,
				TextVAlignment::CENTER);;
			name->setAnchorPoint(Point(0, 1));
			name->setPosition(Point(320, 520));
			name->setColor(Color3B::BLACK);
			name->setTag(144);
			this->addChild(name, 4);

			auto text_item = MenuItemImage::create(
				"MiniGameResources/ok_button.png",
				"MiniGameResources/ok_buttonpr.png",
				CC_CALLBACK_1(NewsScene::Gojudgment, this));
			text_item->setAnchorPoint(Point(0.5, 0.5));
			text_item->setPosition(Point(950, 65));

			auto text = Menu::create(text_item, NULL);
			text->setAnchorPoint(Point(0.5, 0.5));
			text->setPosition(Point(0, 0));
			text->setTag(130);
			this->addChild(text, 5);
		}
		if (Singletons::getInstance()->day == 27 )
		{
			if (Singletons::getInstance()->num_3 == 3)
			{
				Singletons::getInstance()->num_3 = rand() % 2 + 1;
			}
			if (Singletons::getInstance()->num_3 == 1)
			{
				char MyString[300];
				WideCharToMultiByte(CP_UTF8, 0, L"별삼회사 이건어물회장 정말 위독해... 지금 병원에서 치료중...별삼회사 앞으로 어떻게 될지 우려돼...", -1, MyString, 300, NULL, NULL);
				auto name = Label::createWithTTF(MyString, "fonts/ABC.ttf", 25
					, Size(400, 200),
					TextHAlignment::CENTER,
					TextVAlignment::CENTER);;
				name->setAnchorPoint(Point(0, 1));
				name->setPosition(Point(320, 520));
				name->setColor(Color3B::BLACK);
				name->setTag(144);
				this->addChild(name, 4);

				auto text_item = MenuItemImage::create(
					"MiniGameResources/ok_button.png",
					"MiniGameResources/ok_buttonpr.png",
					CC_CALLBACK_1(NewsScene::fin, this));
				text_item->setAnchorPoint(Point(0.5, 0.5));
				text_item->setPosition(Point(950, 65));

				auto text = Menu::create(text_item, NULL);
				text->setAnchorPoint(Point(0.5, 0.5));
				text->setPosition(Point(0, 0));
				text->setTag(131);
				this->addChild(text, 5);
				Singletons::getInstance()->num_3 == 0;
			}
			if (Singletons::getInstance()->num_3 == 2)
			{
				char MyString[300];
				WideCharToMultiByte(CP_UTF8, 0, L"이건어물회장 사실 살아 있어... 비서가 이건어물회장은 살아계신다. 공식발표", -1, MyString, 300, NULL, NULL);
				auto name = Label::createWithTTF(MyString, "fonts/ABC.ttf", 25
					, Size(400, 200),
					TextHAlignment::CENTER,
					TextVAlignment::CENTER);;
				name->setAnchorPoint(Point(0, 1));
				name->setPosition(Point(320, 520));
				name->setColor(Color3B::BLACK);
				name->setTag(144);
				this->addChild(name, 4);

				auto text_item = MenuItemImage::create(
					"MiniGameResources/ok_button.png",
					"MiniGameResources/ok_buttonpr.png",
					CC_CALLBACK_1(NewsScene::fin, this));
				text_item->setAnchorPoint(Point(0.5, 0.5));
				text_item->setPosition(Point(950, 65));

				auto text = Menu::create(text_item, NULL);
				text->setAnchorPoint(Point(0.5, 0.5));
				text->setPosition(Point(0, 0));
				text->setTag(131);
				this->addChild(text, 5);
				Singletons::getInstance()->num_3 == 0;
			}


		}
		
	}
	//11월 첫주차
	if (Singletons::getInstance()->month == 11)
	{
		if (Singletons::getInstance()->day == 13)
		{
			char MyString[200];
			WideCharToMultiByte(CP_UTF8, 0, L"한수회사 아파트단지 완공...", -1, MyString, 200, NULL, NULL);
			auto name = Label::createWithTTF(MyString, "fonts/ABC.ttf", 25
				, Size(400, 200),
				TextHAlignment::CENTER,
				TextVAlignment::CENTER);;
			name->setAnchorPoint(Point(0, 1));
			name->setPosition(Point(320, 520));
			name->setColor(Color3B::BLACK);
			name->setTag(144);
			this->addChild(name, 4);

			auto text_item = MenuItemImage::create(
				"MiniGameResources/ok_button.png",
				"MiniGameResources/ok_buttonpr.png",
				CC_CALLBACK_1(NewsScene::Gojudgment, this));
			text_item->setAnchorPoint(Point(0.5, 0.5));
			text_item->setPosition(Point(950, 65));

			auto text = Menu::create(text_item, NULL);
			text->setAnchorPoint(Point(0.5, 0.5));
			text->setPosition(Point(0, 0));
			text->setTag(130);
			this->addChild(text, 5);
		}
		if (Singletons::getInstance()->day == 27)
		{
			if (Singletons::getInstance()->num_3 == 3)
			{
				Singletons::getInstance()->num_3 = rand() % 2 + 1;
			}
			if (Singletons::getInstance()->num_3 == 1)
			{
				char MyString[300];
				WideCharToMultiByte(CP_UTF8, 0, L"한수회사 아파트단지 부실건설로 밝혀져... 한수회사 공식사과", -1, MyString, 300, NULL, NULL);
				auto name = Label::createWithTTF(MyString, "fonts/ABC.ttf", 25
					, Size(400, 200),
					TextHAlignment::CENTER,
					TextVAlignment::CENTER);;
				name->setAnchorPoint(Point(0, 1));
				name->setPosition(Point(320, 520));
				name->setColor(Color3B::BLACK);
				name->setTag(144);
				this->addChild(name, 4);

				auto text_item = MenuItemImage::create(
					"MiniGameResources/ok_button.png",
					"MiniGameResources/ok_buttonpr.png",
					CC_CALLBACK_1(NewsScene::fin, this));
				text_item->setAnchorPoint(Point(0.5, 0.5));
				text_item->setPosition(Point(950, 65));

				auto text = Menu::create(text_item, NULL);
				text->setAnchorPoint(Point(0.5, 0.5));
				text->setPosition(Point(0, 0));
				text->setTag(131);
				this->addChild(text, 5);
				Singletons::getInstance()->num_3 == 0;
			}
			if (Singletons::getInstance()->num_3 == 2)
			{
				char MyString[300];
				WideCharToMultiByte(CP_UTF8, 0, L"한수회사 아파트단지 역과 가까워 하루만에 모든방 팔려...", -1, MyString, 300, NULL, NULL);
				auto name = Label::createWithTTF(MyString, "fonts/ABC.ttf", 25
					, Size(400, 200),
					TextHAlignment::CENTER,
					TextVAlignment::CENTER);;
				name->setAnchorPoint(Point(0, 1));
				name->setPosition(Point(320, 520));
				name->setColor(Color3B::BLACK);
				name->setTag(144);
				this->addChild(name, 4);

				auto text_item = MenuItemImage::create(
					"MiniGameResources/ok_button.png",
					"MiniGameResources/ok_buttonpr.png",
					CC_CALLBACK_1(NewsScene::fin, this));
				text_item->setAnchorPoint(Point(0.5, 0.5));
				text_item->setPosition(Point(950, 65));

				auto text = Menu::create(text_item, NULL);
				text->setAnchorPoint(Point(0.5, 0.5));
				text->setPosition(Point(0, 0));
				text->setTag(131);
				this->addChild(text, 5);
				Singletons::getInstance()->num_3 == 0;
			}


		}
		
	}
	//12월 첫주차
	if (Singletons::getInstance()->month == 12)
	{
		if (Singletons::getInstance()->day == 13)
		{
			char MyString[200];
			WideCharToMultiByte(CP_UTF8, 0, L"파인애플회사 IPC로 게임을 하던 20대 청년 갑작스럽게 시력잃어... 진위확인 중...", -1, MyString, 200, NULL, NULL);
			auto name = Label::createWithTTF(MyString, "fonts/ABC.ttf", 25
				, Size(400, 200),
				TextHAlignment::CENTER,
				TextVAlignment::CENTER);;
			name->setAnchorPoint(Point(0, 1));
			name->setPosition(Point(320, 520));
			name->setColor(Color3B::BLACK);
			name->setTag(144);
			this->addChild(name, 4);

			auto text_item = MenuItemImage::create(
				"MiniGameResources/ok_button.png",
				"MiniGameResources/ok_buttonpr.png",
				CC_CALLBACK_1(NewsScene::Gojudgment, this));
			text_item->setAnchorPoint(Point(0.5, 0.5));
			text_item->setPosition(Point(950, 65));

			auto text = Menu::create(text_item, NULL);
			text->setAnchorPoint(Point(0.5, 0.5));
			text->setPosition(Point(0, 0));
			text->setTag(130);
			this->addChild(text, 5);
		}
		if (Singletons::getInstance()->day == 27 )
		{
			if (Singletons::getInstance()->num_3 == 3)
			{
				Singletons::getInstance()->num_3 = rand() % 2 + 1;
			}
			if (Singletons::getInstance()->num_3 == 1)
			{
				char MyString[300];
				WideCharToMultiByte(CP_UTF8, 0, L"파인애플회사의 IPC 장시간 사용시 눈에 조직이 파괴돼... 연구결과 발표... 파인애플회사 공식사과", -1, MyString, 300, NULL, NULL);
				auto name = Label::createWithTTF(MyString, "fonts/ABC.ttf", 25
					, Size(400, 200),
					TextHAlignment::CENTER,
					TextVAlignment::CENTER);;
				name->setAnchorPoint(Point(0, 1));
				name->setPosition(Point(320, 520));
				name->setColor(Color3B::BLACK);
				name->setTag(144);
				this->addChild(name, 4);

				auto text_item = MenuItemImage::create(
					"MiniGameResources/ok_button.png",
					"MiniGameResources/ok_buttonpr.png",
					CC_CALLBACK_1(NewsScene::fin, this));
				text_item->setAnchorPoint(Point(0.5, 0.5));
				text_item->setPosition(Point(950, 65));

				auto text = Menu::create(text_item, NULL);
				text->setAnchorPoint(Point(0.5, 0.5));
				text->setPosition(Point(0, 0));
				text->setTag(131);
				this->addChild(text, 5);
				Singletons::getInstance()->num_3 == 0;
			}
			if (Singletons::getInstance()->num_3 == 2)
			{
				char MyString[300];
				WideCharToMultiByte(CP_UTF8, 0, L" 파인애플회사의 IPC 아무이상없어... 시력잃은 남성 장시간 게임으로 인한 시력감퇴로 밝혀졌다.", -1, MyString, 300, NULL, NULL);
				auto name = Label::createWithTTF(MyString, "fonts/ABC.ttf", 25
					, Size(400, 200),
					TextHAlignment::CENTER,
					TextVAlignment::CENTER);;
				name->setAnchorPoint(Point(0, 1));
				name->setPosition(Point(320, 520));
				name->setColor(Color3B::BLACK);
				name->setTag(144);
				this->addChild(name, 4);

				auto text_item = MenuItemImage::create(
					"MiniGameResources/ok_button.png",
					"MiniGameResources/ok_buttonpr.png",
					CC_CALLBACK_1(NewsScene::fin, this));
				text_item->setAnchorPoint(Point(0.5, 0.5));
				text_item->setPosition(Point(950, 65));

				auto text = Menu::create(text_item, NULL);
				text->setAnchorPoint(Point(0.5, 0.5));
				text->setPosition(Point(0, 0));
				text->setTag(131);
				this->addChild(text, 5);
				Singletons::getInstance()->num_3 == 0;
			}

		}
		
	}
	//1월 첫주차
	if (Singletons::getInstance()->month == 1)
	{
		if (Singletons::getInstance()->day == 13 )
		{
			char MyString[200];
			WideCharToMultiByte(CP_UTF8, 0, L"한수 회사 바닷가 인근 대규모 공장 완공...", -1, MyString, 200, NULL, NULL);
			auto name = Label::createWithTTF(MyString, "fonts/ABC.ttf", 25
				, Size(400, 200),
				TextHAlignment::CENTER,
				TextVAlignment::CENTER);;
			name->setAnchorPoint(Point(0, 1));
			name->setPosition(Point(320, 520));
			name->setColor(Color3B::BLACK);
			name->setTag(144);
			this->addChild(name, 4);

			auto text_item = MenuItemImage::create(
				"MiniGameResources/ok_button.png",
				"MiniGameResources/ok_buttonpr.png",
				CC_CALLBACK_1(NewsScene::Gojudgment, this));
			text_item->setAnchorPoint(Point(0.5, 0.5));
			text_item->setPosition(Point(950, 65));

			auto text = Menu::create(text_item, NULL);
			text->setAnchorPoint(Point(0.5, 0.5));
			text->setPosition(Point(0, 0));
			text->setTag(130);
			this->addChild(text, 5);
		}
		if (Singletons::getInstance()->day == 27 )
		{
			if (Singletons::getInstance()->num_3 == 3)
			{
				Singletons::getInstance()->num_3 = rand() % 2 + 1;
			}
			if (Singletons::getInstance()->num_3 == 1)
			{
				char MyString[300];
				WideCharToMultiByte(CP_UTF8, 0, L" 한수회사 대규모 공장 화재발생  공장 흔적조차 남지않아... 한수회사 좌절...", -1, MyString, 300, NULL, NULL);
				auto name = Label::createWithTTF(MyString, "fonts/ABC.ttf", 25
					, Size(400, 200),
					TextHAlignment::CENTER,
					TextVAlignment::CENTER);;
				name->setAnchorPoint(Point(0, 1));
				name->setPosition(Point(320, 520));
				name->setColor(Color3B::BLACK);
				name->setTag(144);
				this->addChild(name, 4);

				auto text_item = MenuItemImage::create(
					"MiniGameResources/ok_button.png",
					"MiniGameResources/ok_buttonpr.png",
					CC_CALLBACK_1(NewsScene::fin, this));
				text_item->setAnchorPoint(Point(0.5, 0.5));
				text_item->setPosition(Point(950, 65));

				auto text = Menu::create(text_item, NULL);
				text->setAnchorPoint(Point(0.5, 0.5));
				text->setPosition(Point(0, 0));
				text->setTag(131);
				this->addChild(text, 5);
				Singletons::getInstance()->num_3 == 0;
			}
			if (Singletons::getInstance()->num_3 == 2)
			{
				char MyString[300];
				WideCharToMultiByte(CP_UTF8, 0, L"한수회사 공장 성공적으로 건설해...  주가 상승하나...", -1, MyString, 300, NULL, NULL);
				auto name = Label::createWithTTF(MyString, "fonts/ABC.ttf", 25
					, Size(400, 200),
					TextHAlignment::CENTER,
					TextVAlignment::CENTER);;
				name->setAnchorPoint(Point(0, 1));
				name->setPosition(Point(320, 520));
				name->setColor(Color3B::BLACK);
				name->setTag(144);
				this->addChild(name, 4);

				auto text_item = MenuItemImage::create(
					"MiniGameResources/ok_button.png",
					"MiniGameResources/ok_buttonpr.png",
					CC_CALLBACK_1(NewsScene::fin, this));
				text_item->setAnchorPoint(Point(0.5, 0.5));
				text_item->setPosition(Point(950, 65));

				auto text = Menu::create(text_item, NULL);
				text->setAnchorPoint(Point(0.5, 0.5));
				text->setPosition(Point(0, 0));
				text->setTag(131);
				this->addChild(text, 5);
				Singletons::getInstance()->num_3 == 0;
			}


		}
	
	}
	//2월 첫주차
	if (Singletons::getInstance()->month == 2)
	{
		if (Singletons::getInstance()->day == 13)
		{
			char MyString[200];
			WideCharToMultiByte(CP_UTF8, 0, L"파인애플회사 불친절하다는 댓글 화제가 되어...", -1, MyString, 200, NULL, NULL);
			auto name = Label::createWithTTF(MyString, "fonts/ABC.ttf", 25
				, Size(400, 200),
				TextHAlignment::CENTER,
				TextVAlignment::CENTER);;
			name->setAnchorPoint(Point(0, 1));
			name->setPosition(Point(320, 520));
			name->setColor(Color3B::BLACK);
			name->setTag(144);
			this->addChild(name, 4);

			auto text_item = MenuItemImage::create(
				"MiniGameResources/ok_button.png",
				"MiniGameResources/ok_buttonpr.png",
				CC_CALLBACK_1(NewsScene::Gojudgment, this));
			text_item->setAnchorPoint(Point(0.5, 0.5));
			text_item->setPosition(Point(950, 65));

			auto text = Menu::create(text_item, NULL);
			text->setAnchorPoint(Point(0.5, 0.5));
			text->setPosition(Point(0, 0));
			text->setTag(130);
			this->addChild(text, 5);
		}
		if (Singletons::getInstance()->day == 27 )
		{
			if (Singletons::getInstance()->num_3 == 3)
			{
				Singletons::getInstance()->num_3 = rand() % 2 + 1;
			}
			if (Singletons::getInstance()->num_3 == 1)
			{
				char MyString[300];
				WideCharToMultiByte(CP_UTF8, 0, L"대다수의 고객들이 불친절함으로 인한 불만호소... 애플측 공식사과. ", -1, MyString, 300, NULL, NULL);
				auto name = Label::createWithTTF(MyString, "fonts/ABC.ttf", 25
					, Size(400, 200),
					TextHAlignment::CENTER,
					TextVAlignment::CENTER);;
				name->setAnchorPoint(Point(0, 1));
				name->setPosition(Point(320, 520));
				name->setColor(Color3B::BLACK);
				name->setTag(144);
				this->addChild(name, 4);

				auto text_item = MenuItemImage::create(
					"MiniGameResources/ok_button.png",
					"MiniGameResources/ok_buttonpr.png",
					CC_CALLBACK_1(NewsScene::fin, this));
				text_item->setAnchorPoint(Point(0.5, 0.5));
				text_item->setPosition(Point(950, 65));

				auto text = Menu::create(text_item, NULL);
				text->setAnchorPoint(Point(0.5, 0.5));
				text->setPosition(Point(0, 0));
				text->setTag(131);
				this->addChild(text, 5);
				Singletons::getInstance()->num_3 == 0;
			}
			if (Singletons::getInstance()->num_3 == 2)
			{
				char MyString[300];
				WideCharToMultiByte(CP_UTF8, 0, L"파인애플 고객 설문 친절함 95%이상 나와... 파인애플을 저격한 악플러의 소행으로 밝혀졌다.", -1, MyString, 300, NULL, NULL);
				auto name = Label::createWithTTF(MyString, "fonts/ABC.ttf", 25
					, Size(400, 200),
					TextHAlignment::CENTER,
					TextVAlignment::CENTER);;
				name->setAnchorPoint(Point(0, 1));
				name->setPosition(Point(320, 520));
				name->setColor(Color3B::BLACK);
				name->setTag(144);
				this->addChild(name, 4);

				auto text_item = MenuItemImage::create(
					"MiniGameResources/ok_button.png",
					"MiniGameResources/ok_buttonpr.png",
					CC_CALLBACK_1(NewsScene::fin, this));
				text_item->setAnchorPoint(Point(0.5, 0.5));
				text_item->setPosition(Point(950, 65));

				auto text = Menu::create(text_item, NULL);
				text->setAnchorPoint(Point(0.5, 0.5));
				text->setPosition(Point(0, 0));
				text->setTag(131);
				this->addChild(text, 5);
				Singletons::getInstance()->num_3 == 0;
			}


		}
		
	}

if(Singletons::getInstance()->day>=1&& Singletons::getInstance()->day<=12)
{
	char MyString[300];
	WideCharToMultiByte(CP_UTF8, 0, L"매월 13일과 27일에만 신문을 구독 할수있습니다.", -1, MyString, 300, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "fonts/ABC.ttf", 25
		, Size(400, 200),
		TextHAlignment::CENTER,
		TextVAlignment::CENTER);;
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(320, 520));
	name->setColor(Color3B::BLACK);
	name->setTag(144);
	this->addChild(name, 4);

	auto text_item = MenuItemImage::create(
		"MiniGameResources/ok_button.png",
		"MiniGameResources/ok_buttonpr.png",
		CC_CALLBACK_1(NewsScene::system, this));
	text_item->setAnchorPoint(Point(0.5, 0.5));
	text_item->setPosition(Point(950, 65));

	auto text = Menu::create(text_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(131);
	this->addChild(text, 5);
}
if (Singletons::getInstance()->day >= 14 && Singletons::getInstance()->day <= 26)
{
	char MyString[300];
	WideCharToMultiByte(CP_UTF8, 0, L"매월 13일과 27일에만 신문을 구독 할수있습니다.", -1, MyString, 300, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "fonts/ABC.ttf", 25
		, Size(400, 200),
		TextHAlignment::CENTER,
		TextVAlignment::CENTER);;
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(320, 520));
	name->setColor(Color3B::BLACK);
	name->setTag(144);
	this->addChild(name, 4);

	auto text_item = MenuItemImage::create(
		"MiniGameResources/ok_button.png",
		"MiniGameResources/ok_buttonpr.png",
		CC_CALLBACK_1(NewsScene::system, this));
	text_item->setAnchorPoint(Point(0.5, 0.5));
	text_item->setPosition(Point(950, 65));

	auto text = Menu::create(text_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(131);
	this->addChild(text, 5);
}
if (Singletons::getInstance()->day >= 28 && Singletons::getInstance()->day <= 31)
{
	char MyString[300];
	WideCharToMultiByte(CP_UTF8, 0, L"매월 14일과 28일에만 신문을 구독 할수있습니다.", -1, MyString, 300, NULL, NULL);
	auto name = Label::createWithTTF(MyString, "fonts/ABC.ttf", 25
		, Size(400, 200),
		TextHAlignment::CENTER,
		TextVAlignment::CENTER);;
	name->setAnchorPoint(Point(0, 1));
	name->setPosition(Point(320, 520));
	name->setColor(Color3B::BLACK);
	name->setTag(144);
	this->addChild(name, 4);

	auto text_item = MenuItemImage::create(
		"MiniGameResources/ok_button.png",
		"MiniGameResources/ok_buttonpr.png",
		CC_CALLBACK_1(NewsScene::system, this));
	text_item->setAnchorPoint(Point(0.5, 0.5));
	text_item->setPosition(Point(950, 65));

	auto text = Menu::create(text_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(131);
	this->addChild(text, 5);
}
}
//좋은 소식일지 나쁜소식일지 판단하는 함수
void NewsScene::Gojudgment(Ref *pSender)
{
	srand((double)time(NULL));
	removeChildByTag(130);
	auto storyA_item = MenuItemImage::create(
		"MiniGameResources/UI_Textlblack.png",
		"MiniGameResources/UI_Textlblack.png",

		CC_CALLBACK_1(NewsScene::replayspr, this));
	storyA_item->setAnchorPoint(Point(0.5, 0.5));
	storyA_item->setPosition(Point(510, 100));

	auto storyA = Menu::create(storyA_item, NULL);
	storyA->setAnchorPoint(Point(0.5, 0.5));
	storyA->setPosition(Point(0, 0));
	storyA->setTag(4);
	this->addChild(storyA, 2);
	//메인캐릭터
	Sprite* mainchr = Sprite::create("MiniGameResources/main_char.png");
	mainchr->setAnchorPoint(Point(0.5, 0));
	mainchr->setPosition(Point(120, 80));
	mainchr->setTag(166);
	this->addChild(mainchr, 1);

	int num4;
	int num1,k;
	int i, num;
	int j,num2;
	srand((double)time(NULL));
	//능력치합 천이상
	if (Singletons::getInstance()->m_jisik + Singletons::getInstance()->m_hak >= 1000)
	{

			//num2 = rand() % 2 + 1;
		
		//나쁜소식 
		//if (num2 == 1)
		//{
			Singletons::getInstance()->num_3 = rand() % 2 + 1;
		//}
		////좋은소식
		//if (num2 == 2)
		//{
		//	Singletons::getInstance()->num_3 = 2;
		//}
	}
	//능력치합 천미만
	if (Singletons::getInstance()->m_jisik + Singletons::getInstance()->m_hak >= 0 && Singletons::getInstance()->m_jisik + Singletons::getInstance()->m_hak <= 999)
	{
		Singletons::getInstance()->num_3 = 3;
	}

	
	//능력치 천이상, 나쁜소식
	if (Singletons::getInstance()->num_3 == 1)
	{
		
		
		num = rand() % 2 + 1;
\

		if (num == 1)
		{
			char MyString[200];
			WideCharToMultiByte(CP_UTF8, 0, L"호동: (이 기사는 거짓말일거야.  투자하지말아야겠어!)", -1, MyString, 200, NULL, NULL);
			auto name_01 = Label::createWithTTF(MyString, "fonts/Bold.ttf", 30);
			name_01 ->setAnchorPoint(Point(0, 1));
			name_01 ->setPosition(Point(40, 150));
			name_01 ->setColor(Color3B::WHITE);
			name_01 ->setTag(20);
			this->addChild(name_01, 3);
		}

		else if (num == 2)
		{
			char MyString[200];
			WideCharToMultiByte(CP_UTF8, 0, L"호동: (음... 이건 잘 모르겠다. 조금더 생각해봐야겠어.)", -1, MyString, 200, NULL, NULL);
			auto name = Label::createWithTTF(MyString, "fonts/Bold.ttf", 30);
			name->setAnchorPoint(Point(0, 1));
			name->setPosition(Point(40, 150));
			name->setColor(Color3B::WHITE);
			name->setTag(21);
			this->addChild(name, 3);
		}
	}
	//능력치 천이상, 좋은소식
	if (Singletons::getInstance()->num_3 == 2)
	{
		//srand((double)time(NULL));
		
			num1 = rand() % 2 +1;
		

		if (num1 == 1)
		{
			char MyString[200];
			WideCharToMultiByte(CP_UTF8, 0, L"호동: (내생각에 이 기사는 진짜일거야. 투자해야겠는걸? )", -1, MyString, 200, NULL, NULL);
			auto name_02 = Label::createWithTTF(MyString, "fonts/Bold.ttf", 30);
			name_02->setAnchorPoint(Point(0, 1));
			name_02->setPosition(Point(40, 150));
			name_02->setColor(Color3B::WHITE);
			name_02->setTag(22);
			this->addChild(name_02, 3);
		}

		else if (num1 == 2)
		{
			char MyString[200];
			WideCharToMultiByte(CP_UTF8, 0, L"호동: (음... 이건 잘 모르겠다. 조금더 생각해봐야겠어.)", -1, MyString, 200, NULL, NULL);
			auto nameA = Label::createWithTTF(MyString, "fonts/Bold.ttf", 30);
			nameA->setAnchorPoint(Point(0, 1));
			nameA->setPosition(Point(40, 150));
			nameA->setColor(Color3B::WHITE);
			nameA->setTag(23);
			this->addChild(nameA, 3);
		}
	}
	//능력치 천미만
	if (Singletons::getInstance()->num_3 == 3)
	{
		srand((double)time(NULL));
		for (i = 0; i < 1; i++)
		{
			num4 = rand() % 4 + 1;
		}

		if (num4 == 1)
		{
			char MyString[200];
			WideCharToMultiByte(CP_UTF8, 0, L"호동: (오호 흥미로운 기사인걸?)", -1, MyString, 200, NULL, NULL);
			auto name_09 = Label::createWithTTF(MyString, "fonts/Bold.ttf", 30);
			name_09->setAnchorPoint(Point(0, 1));
			name_09->setPosition(Point(40, 150));
			name_09->setColor(Color3B::WHITE);
			name_09->setTag(21);
			this->addChild(name_09, 3);
		}

		if (num4 == 2)
		{
			char MyString[200];
			WideCharToMultiByte(CP_UTF8, 0, L"호동: (이런 일이 있었군!)", -1, MyString, 200, NULL, NULL);
			auto nameB = Label::createWithTTF(MyString, "fonts/Bold.ttf", 30);
			nameB->setAnchorPoint(Point(0, 1));
			nameB->setPosition(Point(40, 150));
			nameB->setColor(Color3B::WHITE);
			nameB->setTag(21);
			this->addChild(nameB, 3);
		}

		if (num4 == 3)
		{
			char MyString[200];
			WideCharToMultiByte(CP_UTF8, 0, L"호동: (무슨말을 하는지 잘모르겠어. 공부를 좀 해야겠는걸?)", -1, MyString, 200, NULL, NULL);
			auto name_13 = Label::createWithTTF(MyString, "fonts/Bold.ttf", 30);
			name_13->setAnchorPoint(Point(0, 1));
			name_13->setPosition(Point(40, 150));
			name_13->setColor(Color3B::WHITE);
			name_13->setTag(21);
			this->addChild(name_13, 3);
		}

		if (num4 == 4)
		{
			char MyString[200];
			WideCharToMultiByte(CP_UTF8, 0, L"호동: (이건 무슨말이지? 책을 좀 읽어야겠는걸?)", -1, MyString, 200, NULL, NULL);
			auto name_24 = Label::createWithTTF(MyString, "fonts/Bold.ttf", 30);
			 name_24->setAnchorPoint(Point(0, 1));
			 name_24->setPosition(Point(40, 150));
			 name_24->setColor(Color3B::WHITE);
			 name_24->setTag(21);
			this->addChild(name_24, 3);
		}
	}

	auto text_item = MenuItemImage::create(
		"MiniGameResources/ok_button.png",
		"MiniGameResources/ok_buttonpr.png",
		CC_CALLBACK_1(NewsScene::fin, this));
	text_item->setAnchorPoint(Point(0.5, 0.5));
	text_item->setPosition(Point(950, 65));

	auto text = Menu::create(text_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(131);
	this->addChild(text, 5);
}

void NewsScene::Gojudgment_2(Ref *pSender)
{
	int k, num5;
	//28일 신문구독후 텍스트
	removeChildByTag(130);
	auto storyA_item = MenuItemImage::create(
		"MiniGameResources/UI_Textlblack.png",
		"MiniGameResources/UI_Textlblack.png",

		CC_CALLBACK_1(NewsScene::replayspr, this));
	storyA_item->setAnchorPoint(Point(0.5, 0.5));
	storyA_item->setPosition(Point(510, 100));

	auto storyA = Menu::create(storyA_item, NULL);
	storyA->setAnchorPoint(Point(0.5, 0.5));
	storyA->setPosition(Point(0, 0));
	storyA->setTag(4);
	this->addChild(storyA, 2);
	//메인캐릭터
	Sprite* mainchr = Sprite::create("MiniGameResources/main_char.png");
	mainchr->setAnchorPoint(Point(0.5, 0));
	mainchr->setPosition(Point(120, 80));
	mainchr->setTag(166);
	this->addChild(mainchr, 1);
	
		srand((double)time(NULL));
		for (k = 0; k < 1; k++)
		{
			num5= rand() % 4 + 1;
		}

		if (num5 == 1)
		{
			char MyString[200];
			WideCharToMultiByte(CP_UTF8, 0, L"호동: (오호 흥미로운 기사인걸?)", -1, MyString, 200, NULL, NULL);
			auto name_09 = Label::createWithTTF(MyString, "fonts/Bold.ttf", 30);
			name_09->setAnchorPoint(Point(0, 1));
			name_09->setPosition(Point(40, 150));
			name_09->setColor(Color3B::WHITE);
			name_09->setTag(21);
			this->addChild(name_09, 3);
		}

		if (num5 == 2)
		{
			char MyString[200];
			WideCharToMultiByte(CP_UTF8, 0, L"호동: (이런 일이 있었군!)", -1, MyString, 200, NULL, NULL);
			auto nameB = Label::createWithTTF(MyString, "fonts/Bold.ttf", 30);
			nameB->setAnchorPoint(Point(0, 1));
			nameB->setPosition(Point(40, 150));
			nameB->setColor(Color3B::WHITE);
			nameB->setTag(21);
			this->addChild(nameB, 3);
		}

		if (num5 == 3)
		{
			char MyString[200];
			WideCharToMultiByte(CP_UTF8, 0, L"호동: (예상했던 결과로군~)", -1, MyString, 200, NULL, NULL);
			auto name_13 = Label::createWithTTF(MyString, "fonts/Bold.ttf", 30);
			name_13->setAnchorPoint(Point(0, 1));
			name_13->setPosition(Point(40, 150));
			name_13->setColor(Color3B::WHITE);
			name_13->setTag(21);
			this->addChild(name_13, 3);
		}

		if (num5 == 4)
		{
			char MyString[200];
			WideCharToMultiByte(CP_UTF8, 0, L"호동: (그렇군, 유익한 정보야.)", -1, MyString, 200, NULL, NULL);
			auto name_24 = Label::createWithTTF(MyString, "fonts/Bold.ttf", 30);
			name_24->setAnchorPoint(Point(0, 1));
			name_24->setPosition(Point(40, 150));
			name_24->setColor(Color3B::WHITE);
			name_24->setTag(21);
			this->addChild(name_24, 3);
		}
	


	auto text_item = MenuItemImage::create(
		"MiniGameResources/ok_button.png",
		"MiniGameResources/ok_buttonpr.png",
		CC_CALLBACK_1(NewsScene::fin, this));
	text_item->setAnchorPoint(Point(0.5, 0.5));
	text_item->setPosition(Point(950, 65));

	auto text = Menu::create(text_item, NULL);
	text->setAnchorPoint(Point(0.5, 0.5));
	text->setPosition(Point(0, 0));
	text->setTag(131);
	this->addChild(text, 5);
}

void NewsScene::fin(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);

	Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
	Director::getInstance()->replaceScene(NextDayScene::createScene());
}
//신문읽기-신문클릭
void NewsScene::system(Ref *pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button_click_16_sound_effects_.mp3", false);

	Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
	Director::getInstance()->replaceScene(BudongScene::createScene());
}
void NewsScene::replayspr(Ref *pSender)
{

}

//bool NewsScene::onTouchBegan(Touch* touch, Event* unused_event)
//{
//	Point location = touch->getLocation();
//	Sprite* spr = (Sprite*)this->getChildByTag(1);
//	Rect	rect = spr->getBoundingBox();
//
//	if (rect.containsPoint(location)) {
//		Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
//		Director::getInstance()->replaceScene(MainScene::createScene());
//	}
//
//	return false;
//}
