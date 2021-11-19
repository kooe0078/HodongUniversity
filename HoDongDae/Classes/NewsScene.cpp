#include "NewsScene.h"
#include "SimpleAudioEngine.h"
#include "MainScene.h"
#include "chrcreateScene.h"
#include "sinngleton.h"
#include "NextDayScene.h"
#include "BudongScene.h"
//���� �Ҷ�� �� �ʿ�
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
	
	////��ġ ������ ���
	//auto listener = EventListenerTouchOneByOne::create();
	//listener->onTouchBegan = CC_CALLBACK_2(NewsScene::onTouchBegan, this);
	//Director::getInstance()->getEventDispatcher()->addEventListenerWithFixedPriority(listener, 1);

	//�������
	SimpleAudioEngine::getInstance()->playBackgroundMusic("sound/1975.mp3", true);

    return true;
}
void NewsScene::update(float ft)
{
	//�� ��ü������ �ݺ� �Ǿ��ϴ� ����
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
// ��Ʈ�� ����â
void NewsScene::InitMenu()
{
	auto action_item3 = MenuItemImage::create(
		"MiniGameResources/UI_newspaper.png",
		"MiniGameResources/UI_newspaper.png",
		// �ӽ� 
		CC_CALLBACK_1(NewsScene::replayspr, this));
	action_item3->setPosition(Point(0, 0));

	auto play = Menu::create(action_item3, NULL);
	play->setAnchorPoint(Point(0.5, 0));
	play->setPosition(Point(520, 390));
	play->setTag(120);
	this->addChild(play, 1);

	int i,num;
	int j, num_2;
	//3�� ù����
	if (Singletons::getInstance()->month == 3)
	{
		if (Singletons::getInstance()->day == 13)
		{
			char MyString[200];
			WideCharToMultiByte(CP_UTF8, 0, L"����ȸ�� ���� û�������� ����... ������ �Ƚ��ϰ� ���Ǽ��־�... ��ǥ  ", -1, MyString, 200, NULL, NULL);
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
			//���ۼҽ�
		if (Singletons::getInstance()->day == 27 )
		{
			if (Singletons::getInstance()->num_3 == 3)
			{
				Singletons::getInstance()->num_3 = rand() % 2 + 1;
			}
			if (Singletons::getInstance()->num_3 == 1)
			{
				char MyString[200];
				WideCharToMultiByte(CP_UTF8, 0, L"����ȸ�� ���� û�������� �������� �߰� ��... ����ȸ�� ���Ļ��...", -1, MyString, 200, NULL, NULL);
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
				WideCharToMultiByte(CP_UTF8, 0, L"����ȸ�� �������� �� ��� ����... ������� ǥ��!", -1, MyString, 200, NULL, NULL);
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
	//4�� ù����
	if (Singletons::getInstance()->month == 4)
	{
		if (Singletons::getInstance()->day == 13)
		{
			char MyString[200];
			WideCharToMultiByte(CP_UTF8, 0, L"����ȸ�� �̰���ġ��ȸ�� ������ ���... ���� ���� ������ ����?", -1, MyString, 200, NULL, NULL);
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
				WideCharToMultiByte(CP_UTF8, 0, L"����ȸ�� �̰���ġ��ȸ�� ������ ��� ���Ƿ� ������ ������ ������... ����̹��� ���϶�!", -1, MyString, 300, NULL, NULL);
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
				WideCharToMultiByte(CP_UTF8, 0, L"�������� �ö��� �̰���ġ��ȸ��. ���� ���� ����� �̰���ġ��ȸ���� �ƴϾ����� ������... ������ ������ �庻�� ��Ƴ� ����ó�� �� ���̶�� ���� ��ǥ.", -1, MyString, 400, NULL, NULL);
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
	//5�� ù����
	if (Singletons::getInstance()->month == 5)
	{
		if (Singletons::getInstance()->day == 13 )
		{
			char MyString[200];
			WideCharToMultiByte(CP_UTF8, 0, L"Ű��ȸ�� �ڵ��� �Žø��� �ؿ� ���� �غ� ��...", -1, MyString, 200, NULL, NULL);
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
				WideCharToMultiByte(CP_UTF8, 0, L"Ű�� ȸ�� �ؿ����� �����... �ѱ������ ������ ����...", -1, MyString, 200, NULL, NULL);
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
				WideCharToMultiByte(CP_UTF8, 0, L"Ű��ȸ�� �ڵ��� K�ø��� �ܱ����� �뼺Ȳ! �������� ���������� �α����", -1, MyString, 200, NULL, NULL);
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
//	6�� ù����
	if (Singletons::getInstance()->month == 6)
	{
		if (Singletons::getInstance()->day == 13)
		{
			char MyString[200];
			WideCharToMultiByte(CP_UTF8, 0, L"����ȸ�� ���� ������ ���� �� ��ǥ �� ���ľ��� ���� ���� �� �־�... ��ǥ", -1, MyString, 200, NULL, NULL);
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
				WideCharToMultiByte(CP_UTF8, 0, L"����ȸ�� ��ǰ ���ۿ� �߻�! ���޽�ȯ�� ����!", -1, MyString, 300, NULL, NULL);
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
				WideCharToMultiByte(CP_UTF8, 0, L" ����ȸ���� ������ �Ѿ˸������ϸ� ���°��� �ϳ���... ����ȸ���� �������� ȿ�����پ ���� ����Ǿ� �Ź��� �����ϰԵ�����...", -1, MyString, 300, NULL, NULL);
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
	//7�� ù����
	if (Singletons::getInstance()->month == 7)
	{
		if (Singletons::getInstance()->day == 13 )
		{
			char MyString[200];
			WideCharToMultiByte(CP_UTF8, 0, L"���ξ���ȸ�� ���̻��� ������ ��� ����!", -1, MyString, 200, NULL, NULL);
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
				WideCharToMultiByte(CP_UTF8, 0, L"���ξ���ȸ�� ���̻��� ������ ���Ǹ� ���� ���� ��ɵ� ����ϱ� �ʹ� ������ ȯ������ ������... �ְ� �϶� ��...", -1, MyString, 300, NULL, NULL);
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
				WideCharToMultiByte(CP_UTF8, 0, L"���ξ��� ȸ�� ���̻��� ������ ���̻���ŭ �뼺��... �Ź��� ������...", -1, MyString, 300, NULL, NULL);
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
	//8�� ù����
	if (Singletons::getInstance()->month == 8)
	{
		if (Singletons::getInstance()->day == 13)
		{
			char MyString[200];
			WideCharToMultiByte(CP_UTF8, 0, L"����ȸ�� ������ �ȱ����� ������ ��Ƽ�ӽ������� �Žø��� ���", -1, MyString, 200, NULL, NULL);
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
				WideCharToMultiByte(CP_UTF8, 0, L"����ȸ�� ���ο� ��Ƽ�ӽ������� ��ü�� �طο� ���� ���� ��... ����ȸ�� ���Ļ��", -1, MyString, 300, NULL, NULL);
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
				WideCharToMultiByte(CP_UTF8, 0, L"����ȸ�� ��Ƽ�ӽ� ������... ������ ���� ������ �� �־�...", -1, MyString, 300, NULL, NULL);
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
	//9�� ù����
	if (Singletons::getInstance()->month == 9)
	{
		if (Singletons::getInstance()->day == 13)
		{
			char MyString[200];
			WideCharToMultiByte(CP_UTF8, 0, L"Ű��ȸ�� �ڵ����� �ڵ��� �� ���... ��ǥ", -1, MyString, 200, NULL, NULL);
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
				WideCharToMultiByte(CP_UTF8, 0, L"Ű��ȸ�� �ڵ����� �ڵ��� �ɰ��� ���� �߰���... ��� ����... ", -1, MyString, 300, NULL, NULL);
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
				WideCharToMultiByte(CP_UTF8, 0, L"Ű��ȸ�� �ڵ������ڵ��� ��������. ���� ���� ������ �ʿ䰡���� ������ã�ƿ�...", -1, MyString, 300, NULL, NULL);
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
	//10�� ù����
	if (Singletons::getInstance()->month == 10)
	{
		if (Singletons::getInstance()->day == 13)
		{
			char MyString[200];
			WideCharToMultiByte(CP_UTF8, 0, L"����ȸ�� �̰Ǿȸ�� �޸� ��� ������... ����ȸ�� �̷��� ��鸮��", -1, MyString, 200, NULL, NULL);
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
				WideCharToMultiByte(CP_UTF8, 0, L"����ȸ�� �̰Ǿȸ�� ���� ������... ���� �������� ġ����...����ȸ�� ������ ��� ���� �����...", -1, MyString, 300, NULL, NULL);
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
				WideCharToMultiByte(CP_UTF8, 0, L"�̰Ǿȸ�� ��� ��� �־�... �񼭰� �̰Ǿȸ���� ��ư�Ŵ�. ���Ĺ�ǥ", -1, MyString, 300, NULL, NULL);
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
	//11�� ù����
	if (Singletons::getInstance()->month == 11)
	{
		if (Singletons::getInstance()->day == 13)
		{
			char MyString[200];
			WideCharToMultiByte(CP_UTF8, 0, L"�Ѽ�ȸ�� ����Ʈ���� �ϰ�...", -1, MyString, 200, NULL, NULL);
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
				WideCharToMultiByte(CP_UTF8, 0, L"�Ѽ�ȸ�� ����Ʈ���� �νǰǼ��� ������... �Ѽ�ȸ�� ���Ļ��", -1, MyString, 300, NULL, NULL);
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
				WideCharToMultiByte(CP_UTF8, 0, L"�Ѽ�ȸ�� ����Ʈ���� ���� ����� �Ϸ縸�� ���� �ȷ�...", -1, MyString, 300, NULL, NULL);
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
	//12�� ù����
	if (Singletons::getInstance()->month == 12)
	{
		if (Singletons::getInstance()->day == 13)
		{
			char MyString[200];
			WideCharToMultiByte(CP_UTF8, 0, L"���ξ���ȸ�� IPC�� ������ �ϴ� 20�� û�� ���۽����� �÷��Ҿ�... ����Ȯ�� ��...", -1, MyString, 200, NULL, NULL);
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
				WideCharToMultiByte(CP_UTF8, 0, L"���ξ���ȸ���� IPC ��ð� ���� ���� ������ �ı���... ������� ��ǥ... ���ξ���ȸ�� ���Ļ��", -1, MyString, 300, NULL, NULL);
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
				WideCharToMultiByte(CP_UTF8, 0, L" ���ξ���ȸ���� IPC �ƹ��̻����... �÷����� ���� ��ð� �������� ���� �÷°���� ��������.", -1, MyString, 300, NULL, NULL);
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
	//1�� ù����
	if (Singletons::getInstance()->month == 1)
	{
		if (Singletons::getInstance()->day == 13 )
		{
			char MyString[200];
			WideCharToMultiByte(CP_UTF8, 0, L"�Ѽ� ȸ�� �ٴ尡 �α� ��Ը� ���� �ϰ�...", -1, MyString, 200, NULL, NULL);
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
				WideCharToMultiByte(CP_UTF8, 0, L" �Ѽ�ȸ�� ��Ը� ���� ȭ��߻�  ���� �������� �����ʾ�... �Ѽ�ȸ�� ����...", -1, MyString, 300, NULL, NULL);
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
				WideCharToMultiByte(CP_UTF8, 0, L"�Ѽ�ȸ�� ���� ���������� �Ǽ���...  �ְ� ����ϳ�...", -1, MyString, 300, NULL, NULL);
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
	//2�� ù����
	if (Singletons::getInstance()->month == 2)
	{
		if (Singletons::getInstance()->day == 13)
		{
			char MyString[200];
			WideCharToMultiByte(CP_UTF8, 0, L"���ξ���ȸ�� ��ģ���ϴٴ� ��� ȭ���� �Ǿ�...", -1, MyString, 200, NULL, NULL);
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
				WideCharToMultiByte(CP_UTF8, 0, L"��ټ��� ������ ��ģ�������� ���� �Ҹ�ȣ��... ������ ���Ļ��. ", -1, MyString, 300, NULL, NULL);
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
				WideCharToMultiByte(CP_UTF8, 0, L"���ξ��� �� ���� ģ���� 95%�̻� ����... ���ξ����� ������ ���÷��� �������� ��������.", -1, MyString, 300, NULL, NULL);
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
	WideCharToMultiByte(CP_UTF8, 0, L"�ſ� 13�ϰ� 27�Ͽ��� �Ź��� ���� �Ҽ��ֽ��ϴ�.", -1, MyString, 300, NULL, NULL);
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
	WideCharToMultiByte(CP_UTF8, 0, L"�ſ� 13�ϰ� 27�Ͽ��� �Ź��� ���� �Ҽ��ֽ��ϴ�.", -1, MyString, 300, NULL, NULL);
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
	WideCharToMultiByte(CP_UTF8, 0, L"�ſ� 14�ϰ� 28�Ͽ��� �Ź��� ���� �Ҽ��ֽ��ϴ�.", -1, MyString, 300, NULL, NULL);
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
//���� �ҽ����� ���ۼҽ����� �Ǵ��ϴ� �Լ�
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
	//����ĳ����
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
	//�ɷ�ġ�� õ�̻�
	if (Singletons::getInstance()->m_jisik + Singletons::getInstance()->m_hak >= 1000)
	{

			//num2 = rand() % 2 + 1;
		
		//���ۼҽ� 
		//if (num2 == 1)
		//{
			Singletons::getInstance()->num_3 = rand() % 2 + 1;
		//}
		////�����ҽ�
		//if (num2 == 2)
		//{
		//	Singletons::getInstance()->num_3 = 2;
		//}
	}
	//�ɷ�ġ�� õ�̸�
	if (Singletons::getInstance()->m_jisik + Singletons::getInstance()->m_hak >= 0 && Singletons::getInstance()->m_jisik + Singletons::getInstance()->m_hak <= 999)
	{
		Singletons::getInstance()->num_3 = 3;
	}

	
	//�ɷ�ġ õ�̻�, ���ۼҽ�
	if (Singletons::getInstance()->num_3 == 1)
	{
		
		
		num = rand() % 2 + 1;
\

		if (num == 1)
		{
			char MyString[200];
			WideCharToMultiByte(CP_UTF8, 0, L"ȣ��: (�� ���� �������ϰž�.  �����������ƾ߰ھ�!)", -1, MyString, 200, NULL, NULL);
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
			WideCharToMultiByte(CP_UTF8, 0, L"ȣ��: (��... �̰� �� �𸣰ڴ�. ���ݴ� �����غ��߰ھ�.)", -1, MyString, 200, NULL, NULL);
			auto name = Label::createWithTTF(MyString, "fonts/Bold.ttf", 30);
			name->setAnchorPoint(Point(0, 1));
			name->setPosition(Point(40, 150));
			name->setColor(Color3B::WHITE);
			name->setTag(21);
			this->addChild(name, 3);
		}
	}
	//�ɷ�ġ õ�̻�, �����ҽ�
	if (Singletons::getInstance()->num_3 == 2)
	{
		//srand((double)time(NULL));
		
			num1 = rand() % 2 +1;
		

		if (num1 == 1)
		{
			char MyString[200];
			WideCharToMultiByte(CP_UTF8, 0, L"ȣ��: (�������� �� ���� ��¥�ϰž�. �����ؾ߰ڴ°�? )", -1, MyString, 200, NULL, NULL);
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
			WideCharToMultiByte(CP_UTF8, 0, L"ȣ��: (��... �̰� �� �𸣰ڴ�. ���ݴ� �����غ��߰ھ�.)", -1, MyString, 200, NULL, NULL);
			auto nameA = Label::createWithTTF(MyString, "fonts/Bold.ttf", 30);
			nameA->setAnchorPoint(Point(0, 1));
			nameA->setPosition(Point(40, 150));
			nameA->setColor(Color3B::WHITE);
			nameA->setTag(23);
			this->addChild(nameA, 3);
		}
	}
	//�ɷ�ġ õ�̸�
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
			WideCharToMultiByte(CP_UTF8, 0, L"ȣ��: (��ȣ ��̷ο� ����ΰ�?)", -1, MyString, 200, NULL, NULL);
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
			WideCharToMultiByte(CP_UTF8, 0, L"ȣ��: (�̷� ���� �־���!)", -1, MyString, 200, NULL, NULL);
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
			WideCharToMultiByte(CP_UTF8, 0, L"ȣ��: (�������� �ϴ��� �߸𸣰ھ�. ���θ� �� �ؾ߰ڴ°�?)", -1, MyString, 200, NULL, NULL);
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
			WideCharToMultiByte(CP_UTF8, 0, L"ȣ��: (�̰� ����������? å�� �� �о�߰ڴ°�?)", -1, MyString, 200, NULL, NULL);
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
	//28�� �Ź������� �ؽ�Ʈ
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
	//����ĳ����
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
			WideCharToMultiByte(CP_UTF8, 0, L"ȣ��: (��ȣ ��̷ο� ����ΰ�?)", -1, MyString, 200, NULL, NULL);
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
			WideCharToMultiByte(CP_UTF8, 0, L"ȣ��: (�̷� ���� �־���!)", -1, MyString, 200, NULL, NULL);
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
			WideCharToMultiByte(CP_UTF8, 0, L"ȣ��: (�����ߴ� ����α�~)", -1, MyString, 200, NULL, NULL);
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
			WideCharToMultiByte(CP_UTF8, 0, L"ȣ��: (�׷���, ������ ������.)", -1, MyString, 200, NULL, NULL);
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
//�Ź��б�-�Ź�Ŭ��
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
