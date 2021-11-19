#include "NextDayScene.h"
#include "MainScene.h"
#include "SimpleAudioEngine.h"
#include "sinngleton.h"
#include "NewsScene.h"
#include "BiriSceneA.h"
#include "BiriSceneB.h"
#include "BiriSceneC.h"
#include "BiriSceneD.h"
#include "BiriSceneE.h"
#include "BiriSceneF.h"
#include "BiriSceneG.h"
#include "HappyEnd.h"
#include "BadEnd.h"
//���� �Ҷ�� �� �ʿ�
using namespace CocosDenshion;
USING_NS_CC;

Scene* NextDayScene::createScene()
{
    auto scene = Scene::create();
    auto layer = NextDayScene::create();
    scene->addChild(layer);
	
    return scene;
}

bool NextDayScene::init()
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
	//�������
//	SimpleAudioEngine::getInstance()->playBackgroundMusic("MiniGameResources/IntroBackSound.mp3", true);
	this->scheduleOnce(schedule_selector(NextDayScene::start1), 1.0f);
	//this->scheduleOnce(schedule_selector(NextDayScene::callback), 0.1f);

    return true;
}

void NextDayScene::update(float ft)
{
	//�� ��ü������ �ݺ� �Ǿ��ϴ� ����
}
void NextDayScene::InitBackGround()
{
	auto sprite = Sprite::create("MiniGameResources/allblack.png");
	sprite->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	this->addChild(sprite, 0);
}
void NextDayScene::InitLabel()
{

}
void NextDayScene::start1(float f)
{
	Singletons::getInstance()->DayGone = Singletons::getInstance()->DayGone + 1;
	Singletons::getInstance()->day = Singletons::getInstance()->day + 1;

	Singletons::getInstance()->totalpoint = Singletons::getInstance()->m_friendly + Singletons::getInstance()->m_hak + Singletons::getInstance()->m_insung + Singletons::getInstance()->m_jisik;
	//Singletons::getInstance()->day = Singletons::getInstance()->month + 1;
	//Singletons::getInstance()->m_jisik = Singletons::getInstance()->m_jisik;
	//UserDefault::getInstance()->setIntegerForKey("SaveUsing", Singletons::getInstance()->day+1);
	//Singletons::getInstance()->day = UserDefault::getInstance()->getIntegerForKey("SaveUsing");
	//UserDefault::getInstance()->flush();
	//�����ϱ�
	//UserDefault::getInstance()->setIntegerForKey("SaveUsing", 1);
	//Singletons::getInstance()->day = UserDefault::getInstance()->getIntegerForKey("SaveUsing");
	//UserDefault::getInstance()->flush();
	log("start1 after delay");
	auto scene = TransitionCrossFade::create(0.5f, MainScene::createScene());
	Director::getInstance()->replaceScene(scene);

	if (Singletons::getInstance()->month == 1)
	{
		if (Singletons::getInstance()->day == 2)
		{
			Singletons::getInstance()->Danger = 0;
		}
	}
	if (Singletons::getInstance()->month == 2)
	{
		if (Singletons::getInstance()->day == 2)
		{
			Singletons::getInstance()->Danger = 0;
		}
	}
	if (Singletons::getInstance()->month == 3)
	{
		if (Singletons::getInstance()->day == 2)
		{
			Singletons::getInstance()->Danger = 0;
		}
	}
	if (Singletons::getInstance()->month == 4)
	{
		if (Singletons::getInstance()->day == 2)
		{
			Singletons::getInstance()->Danger = 0;
		}
	}
	if (Singletons::getInstance()->month == 5)
	{
		if (Singletons::getInstance()->day == 2)
		{
			Singletons::getInstance()->Danger = 0;
		}
	}
	if (Singletons::getInstance()->month == 6)
	{
		if (Singletons::getInstance()->day == 2)
		{
			Singletons::getInstance()->Danger = 0;
		}
	}
	if (Singletons::getInstance()->month == 7)
	{
		if (Singletons::getInstance()->day == 2)
		{
			Singletons::getInstance()->Danger = 0;
		}
	}
	if (Singletons::getInstance()->month == 8)
	{
		if (Singletons::getInstance()->day == 2)
		{
			Singletons::getInstance()->Danger = 0;
		}
	}
	if (Singletons::getInstance()->month == 9)
	{
		if (Singletons::getInstance()->day == 2)
		{
			Singletons::getInstance()->Danger = 0;
		}
	}
	if (Singletons::getInstance()->month == 10)
	{
		if (Singletons::getInstance()->day == 2)
		{
			Singletons::getInstance()->Danger = 0;
		}
	}
	if (Singletons::getInstance()->month == 11)
	{
		if (Singletons::getInstance()->day == 2)
		{
			Singletons::getInstance()->Danger = 0;
		}
	}
	if (Singletons::getInstance()->month == 12)
	{
		if (Singletons::getInstance()->day == 2)
		{
			Singletons::getInstance()->Danger = 0;
		}
	}
	if (Singletons::getInstance()->totalpoint <= 9)
	{
		Singletons::getInstance()->jik = 1;
	}
	if (Singletons::getInstance()->totalpoint >= 10&& Singletons::getInstance()->totalpoint <= 399)
	{
		Singletons::getInstance()->jik = 2;
	}
	if (Singletons::getInstance()->totalpoint >= 400 && Singletons::getInstance()->totalpoint <= 1199)
	{
		Singletons::getInstance()->jik = 3;
	}
	if (Singletons::getInstance()->totalpoint >= 1200 && Singletons::getInstance()->totalpoint <= 2099)
	{
		Singletons::getInstance()->jik = 4;
	}
	if (Singletons::getInstance()->totalpoint >= 2100 )
	{
		Singletons::getInstance()->jik = 5;
	}
	if (Singletons::getInstance()->month == 3 && Singletons::getInstance()->day == 15)
	{
		Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
		Director::getInstance()->replaceScene(BiriSceneA::createScene());
	}
	if (Singletons::getInstance()->month == 6 && Singletons::getInstance()->day == 23)
	{
		Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
		Director::getInstance()->replaceScene(BiriSceneB::createScene());
	}
	if (Singletons::getInstance()->month == 7 && Singletons::getInstance()->day == 2)
	{
		Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
		Director::getInstance()->replaceScene(BiriSceneC::createScene());
	}

	if (Singletons::getInstance()->month == 8 && Singletons::getInstance()->day == 10)
	{
		Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
		Director::getInstance()->replaceScene(BiriSceneD::createScene());
	}
	if (Singletons::getInstance()->month == 9 && Singletons::getInstance()->day == 29)
	{
		Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
		Director::getInstance()->replaceScene(BiriSceneE::createScene());
	}

	if (Singletons::getInstance()->month == 10 && Singletons::getInstance()->day == 23)
	{
		Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
		Director::getInstance()->replaceScene(BiriSceneF::createScene());
	}

	if (Singletons::getInstance()->month == 11 && Singletons::getInstance()->day == 2)
	{
		Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
		Director::getInstance()->replaceScene(BiriSceneG::createScene());
	}
	//���� �Ź� ����
	if (Singletons::getInstance()->day == 13)
	{
		log("start1 after delay");
		auto scene = TransitionCrossFade::create(1.5, NewsScene::createScene());
		Director::getInstance()->replaceScene(scene);
	}
	if (Singletons::getInstance()->day == 27)
	{
		log("start1 after delay");
		auto scene = TransitionCrossFade::create(1.5, NewsScene::createScene());
		Director::getInstance()->replaceScene(scene);
	}

	int i;
	//1���� ������
	
	//�ֽĺ���
	if (Singletons::getInstance()->day == 7)
	{
		

		double arr[4] = { -0.05, -0.1, 0.05, 0.1 };
		srand((double)time(NULL));
	
			int random= rand() % 4 ;
			Singletons::getInstance()->samsung_A = arr[random];
			int random_2 = rand() % 4;
			Singletons::getInstance()->apple_A = arr[random_2];
			int random_3 = rand() % 4;
			Singletons::getInstance()->hanhwa_A = arr[random_3];
			int random_4 = rand() % 4;
			Singletons::getInstance()->kia_A = arr[random_4];
			int random_5 = rand() % 4;
			Singletons::getInstance()->lg_A = arr[random_5];
			//�Ｚ
			Singletons::getInstance()->samsung_3 = Singletons::getInstance()->samsung_1;
			Singletons::getInstance()->samsung_2 = (Singletons::getInstance()->samsung_1) + (Singletons::getInstance()->samsung_1*Singletons::getInstance()->samsung_A);
			Singletons::getInstance()->samsung_1 = Singletons::getInstance()->samsung_2;
		
			//���ξ���
			Singletons::getInstance()->apple_3 = Singletons::getInstance()->apple_1;
			Singletons::getInstance()->apple_2 = (Singletons::getInstance()->apple_1) + (Singletons::getInstance()->apple_1*Singletons::getInstance()->apple_A);
			Singletons::getInstance()->apple_1 = Singletons::getInstance()->apple_2;

			//��ȭ
			Singletons::getInstance()->hanhwa_3 = Singletons::getInstance()->hanhwa_1;
			Singletons::getInstance()->hanhwa_2 = (Singletons::getInstance()->hanhwa_1) + (Singletons::getInstance()->hanhwa_1*Singletons::getInstance()->hanhwa_A);
			Singletons::getInstance()->hanhwa_1 = Singletons::getInstance()->hanhwa_2;

			//���
			Singletons::getInstance()->kia_3 = Singletons::getInstance()->kia_1;
			Singletons::getInstance()->kia_2 = (Singletons::getInstance()->kia_1) + (Singletons::getInstance()->kia_1*Singletons::getInstance()->kia_A);
			Singletons::getInstance()->kia_1 = Singletons::getInstance()->kia_2;

			//����
			Singletons::getInstance()->lg_3 = Singletons::getInstance()->lg_1;
			Singletons::getInstance()->lg_2 = (Singletons::getInstance()->lg_1) + (Singletons::getInstance()->lg_1*Singletons::getInstance()->lg_A);
			Singletons::getInstance()->lg_1 = Singletons::getInstance()->lg_2;

	}
	if (Singletons::getInstance()->day == 14)
	{
		
		

		double arr[4] = { -0.05, -0.1, 0.05, 0.1 };
		srand((double)time(NULL));

		int random = rand() % 4;
		Singletons::getInstance()->samsung_A = arr[random];
		int random_2 = rand() % 4;
		Singletons::getInstance()->apple_A = arr[random_2];
		int random_3 = rand() % 4;
		Singletons::getInstance()->hanhwa_A = arr[random_3];
		int random_4 = rand() % 4;
		Singletons::getInstance()->kia_A = arr[random_4];
		int random_5 = rand() % 4;
		Singletons::getInstance()->lg_A = arr[random_5];

		//�Ｚ
		Singletons::getInstance()->samsung_3 = Singletons::getInstance()->samsung_1;
		Singletons::getInstance()->samsung_2 = (Singletons::getInstance()->samsung_1) + (Singletons::getInstance()->samsung_1*Singletons::getInstance()->samsung_A);
		Singletons::getInstance()->samsung_1 = Singletons::getInstance()->samsung_2;

		//���ξ���
		Singletons::getInstance()->apple_3 = Singletons::getInstance()->apple_1;
		Singletons::getInstance()->apple_2 = (Singletons::getInstance()->apple_1) + (Singletons::getInstance()->apple_1*Singletons::getInstance()->apple_A);
		Singletons::getInstance()->apple_1 = Singletons::getInstance()->apple_2;

		//��ȭ
		Singletons::getInstance()->hanhwa_3 = Singletons::getInstance()->hanhwa_1;
		Singletons::getInstance()->hanhwa_2 = (Singletons::getInstance()->hanhwa_1) + (Singletons::getInstance()->hanhwa_1*Singletons::getInstance()->hanhwa_A);
		Singletons::getInstance()->hanhwa_1 = Singletons::getInstance()->hanhwa_2;

		//���
		Singletons::getInstance()->kia_3 = Singletons::getInstance()->kia_1;
		Singletons::getInstance()->kia_2 = (Singletons::getInstance()->kia_1) + (Singletons::getInstance()->kia_1*Singletons::getInstance()->kia_A);
		Singletons::getInstance()->kia_1 = Singletons::getInstance()->kia_2;

		//����
		Singletons::getInstance()->lg_3 = Singletons::getInstance()->lg_1;
		Singletons::getInstance()->lg_2 = (Singletons::getInstance()->lg_1) + (Singletons::getInstance()->lg_1*Singletons::getInstance()->lg_A);
		Singletons::getInstance()->lg_1 = Singletons::getInstance()->lg_2;

	}
	if (Singletons::getInstance()->day == 21)
	{
		double arr[4] = { -0.05, -0.1, 0.05, 0.1 };
		srand((double)time(NULL));

		int random = rand() % 4;
		Singletons::getInstance()->samsung_A = arr[random];
		int random_2 = rand() % 4;
		Singletons::getInstance()->apple_A = arr[random_2];
		int random_3 = rand() % 4;
		Singletons::getInstance()->hanhwa_A = arr[random_3];
		int random_4 = rand() % 4;
		Singletons::getInstance()->kia_A = arr[random_4];
		int random_5 = rand() % 4;
		Singletons::getInstance()->lg_A = arr[random_5];

		//�Ｚ
		Singletons::getInstance()->samsung_3 = Singletons::getInstance()->samsung_1;
		Singletons::getInstance()->samsung_2 = (Singletons::getInstance()->samsung_1) + (Singletons::getInstance()->samsung_1*Singletons::getInstance()->samsung_A);
		Singletons::getInstance()->samsung_1 = Singletons::getInstance()->samsung_2;

		//���ξ���
		Singletons::getInstance()->apple_3 = Singletons::getInstance()->apple_1;
		Singletons::getInstance()->apple_2 = (Singletons::getInstance()->apple_1) + (Singletons::getInstance()->apple_1*Singletons::getInstance()->apple_A);
		Singletons::getInstance()->apple_1 = Singletons::getInstance()->apple_2;

		//��ȭ
		Singletons::getInstance()->hanhwa_3 = Singletons::getInstance()->hanhwa_1;
		Singletons::getInstance()->hanhwa_2 = (Singletons::getInstance()->hanhwa_1) + (Singletons::getInstance()->hanhwa_1*Singletons::getInstance()->hanhwa_A);
		Singletons::getInstance()->hanhwa_1 = Singletons::getInstance()->hanhwa_2;

		//���
		Singletons::getInstance()->kia_3 = Singletons::getInstance()->kia_1;
		Singletons::getInstance()->kia_2 = (Singletons::getInstance()->kia_1) + (Singletons::getInstance()->kia_1*Singletons::getInstance()->kia_A);
		Singletons::getInstance()->kia_1 = Singletons::getInstance()->kia_2;

		//����
		Singletons::getInstance()->lg_3 = Singletons::getInstance()->lg_1;
		Singletons::getInstance()->lg_2 = (Singletons::getInstance()->lg_1) + (Singletons::getInstance()->lg_1*Singletons::getInstance()->lg_A);
		Singletons::getInstance()->lg_1 = Singletons::getInstance()->lg_2;
	}

	if (Singletons::getInstance()->day == 28)
	{
		if (Singletons::getInstance()->month == 3)
		{
			//���ۼҽ�
			if (Singletons::getInstance()->num_3 == 1)
			{
				double arr[3] = { -0.2, -0.3, -0.4 };
				srand((double)time(NULL));

				int random_5 = rand() % 3;
				Singletons::getInstance()->lg_A = arr[random_5];
			}
			//�����ҽ�
			else if (Singletons::getInstance()->num_3 == 2)
			{
				double arr[3] = { 0.2, 0.3, 0.4 };
				srand((double)time(NULL));

				int random_5 = rand() % 3;
				Singletons::getInstance()->lg_A = arr[random_5];
			}
			double arr[4] = { -0.05, -0.1, 0.05, 0.1 };
			srand((double)time(NULL));

			int random = rand() % 4;
			Singletons::getInstance()->samsung_A = arr[random];
			int random_2 = rand() % 4;
			Singletons::getInstance()->apple_A = arr[random_2];
			int random_3 = rand() % 4;
			Singletons::getInstance()->hanhwa_A = arr[random_3];
			int random_4 = rand() % 4;
			Singletons::getInstance()->kia_A = arr[random_4];
			//�Ｚ
			Singletons::getInstance()->samsung_3 = Singletons::getInstance()->samsung_1;
			Singletons::getInstance()->samsung_2 = (Singletons::getInstance()->samsung_1) + (Singletons::getInstance()->samsung_1*Singletons::getInstance()->samsung_A);
			Singletons::getInstance()->samsung_1 = Singletons::getInstance()->samsung_2;

			//���ξ���
			Singletons::getInstance()->apple_3 = Singletons::getInstance()->apple_1;
			Singletons::getInstance()->apple_2 = (Singletons::getInstance()->apple_1) + (Singletons::getInstance()->apple_1*Singletons::getInstance()->apple_A);
			Singletons::getInstance()->apple_1 = Singletons::getInstance()->apple_2;

			//��ȭ
			Singletons::getInstance()->hanhwa_3 = Singletons::getInstance()->hanhwa_1;
			Singletons::getInstance()->hanhwa_2 = (Singletons::getInstance()->hanhwa_1) + (Singletons::getInstance()->hanhwa_1*Singletons::getInstance()->hanhwa_A);
			Singletons::getInstance()->hanhwa_1 = Singletons::getInstance()->hanhwa_2;

			//���
			Singletons::getInstance()->kia_3 = Singletons::getInstance()->kia_1;
			Singletons::getInstance()->kia_2 = (Singletons::getInstance()->kia_1) + (Singletons::getInstance()->kia_1*Singletons::getInstance()->kia_A);
			Singletons::getInstance()->kia_1 = Singletons::getInstance()->kia_2;

			//����
			Singletons::getInstance()->lg_3 = Singletons::getInstance()->lg_1;
			Singletons::getInstance()->lg_2 = (Singletons::getInstance()->lg_1) + (Singletons::getInstance()->lg_1*Singletons::getInstance()->lg_A);
			Singletons::getInstance()->lg_1 = Singletons::getInstance()->lg_2;
		}
		if (Singletons::getInstance()->month == 4)
		{
			//���ۼҽ�
			if (Singletons::getInstance()->num_3 == 1)
			{
				double arr[3] = { -0.2, -0.3, -0.4 };
				srand((double)time(NULL));
				int random = rand() % 3;
				Singletons::getInstance()->samsung_A = arr[random];
				
			}
			//�����ҽ�
			else if (Singletons::getInstance()->num_3 == 2)
			{
				double arr[3] = { 0.2, 0.3, 0.4 };
				srand((double)time(NULL));

				int random = rand() % 3;
				Singletons::getInstance()->samsung_A = arr[random];
			}
			double arr[4] = { -0.05, -0.1, 0.05, 0.1 };
			srand((double)time(NULL));

			
			int random_2 = rand() % 4;
			Singletons::getInstance()->apple_A = arr[random_2];
			int random_3 = rand() % 4;
			Singletons::getInstance()->hanhwa_A = arr[random_3];
			int random_4 = rand() % 4;
			Singletons::getInstance()->kia_A = arr[random_4];
			int random_5 = rand() % 4;
			Singletons::getInstance()->lg_A = arr[random_5];
			//�Ｚ
			Singletons::getInstance()->samsung_3 = Singletons::getInstance()->samsung_1;
			Singletons::getInstance()->samsung_2 = (Singletons::getInstance()->samsung_1) + (Singletons::getInstance()->samsung_1*Singletons::getInstance()->samsung_A);
			Singletons::getInstance()->samsung_1 = Singletons::getInstance()->samsung_2;

			//���ξ���
			Singletons::getInstance()->apple_3 = Singletons::getInstance()->apple_1;
			Singletons::getInstance()->apple_2 = (Singletons::getInstance()->apple_1) + (Singletons::getInstance()->apple_1*Singletons::getInstance()->apple_A);
			Singletons::getInstance()->apple_1 = Singletons::getInstance()->apple_2;

			//��ȭ
			Singletons::getInstance()->hanhwa_3 = Singletons::getInstance()->hanhwa_1;
			Singletons::getInstance()->hanhwa_2 = (Singletons::getInstance()->hanhwa_1) + (Singletons::getInstance()->hanhwa_1*Singletons::getInstance()->hanhwa_A);
			Singletons::getInstance()->hanhwa_1 = Singletons::getInstance()->hanhwa_2;

			//���
			Singletons::getInstance()->kia_3 = Singletons::getInstance()->kia_1;
			Singletons::getInstance()->kia_2 = (Singletons::getInstance()->kia_1) + (Singletons::getInstance()->kia_1*Singletons::getInstance()->kia_A);
			Singletons::getInstance()->kia_1 = Singletons::getInstance()->kia_2;

			//����
			Singletons::getInstance()->lg_3 = Singletons::getInstance()->lg_1;
			Singletons::getInstance()->lg_2 = (Singletons::getInstance()->lg_1) + (Singletons::getInstance()->lg_1*Singletons::getInstance()->lg_A);
			Singletons::getInstance()->lg_1 = Singletons::getInstance()->lg_2;
		}
		if (Singletons::getInstance()->month == 5)
		{
			//���ۼҽ�
			if (Singletons::getInstance()->num_3 == 1)
			{
				double arr[3] = { -0.2, -0.3, -0.4 };
				srand((double)time(NULL));

				int random_4 = rand() % 3;
				Singletons::getInstance()->kia_A = arr[random_4];
			}
			//�����ҽ�
			else if (Singletons::getInstance()->num_3 == 2)
			{
				double arr[3] = { 0.2, 0.3, 0.4 };
				srand((double)time(NULL));

				int random_4 = rand() % 3;
				Singletons::getInstance()->kia_A = arr[random_4];
			}
			double arr[4] = { -0.05, -0.1, 0.05, 0.1 };
			srand((double)time(NULL));

			int random = rand() % 4;
			Singletons::getInstance()->samsung_A = arr[random];
			int random_2 = rand() % 4;
			Singletons::getInstance()->apple_A = arr[random_2];
			int random_3 = rand() % 4;
			Singletons::getInstance()->hanhwa_A = arr[random_3];
			
			int random_5 = rand() % 4;
			Singletons::getInstance()->lg_A = arr[random_5];
			//�Ｚ
			Singletons::getInstance()->samsung_3 = Singletons::getInstance()->samsung_1;
			Singletons::getInstance()->samsung_2 = (Singletons::getInstance()->samsung_1) + (Singletons::getInstance()->samsung_1*Singletons::getInstance()->samsung_A);
			Singletons::getInstance()->samsung_1 = Singletons::getInstance()->samsung_2;

			//���ξ���
			Singletons::getInstance()->apple_3 = Singletons::getInstance()->apple_1;
			Singletons::getInstance()->apple_2 = (Singletons::getInstance()->apple_1) + (Singletons::getInstance()->apple_1*Singletons::getInstance()->apple_A);
			Singletons::getInstance()->apple_1 = Singletons::getInstance()->apple_2;

			//��ȭ
			Singletons::getInstance()->hanhwa_3 = Singletons::getInstance()->hanhwa_1;
			Singletons::getInstance()->hanhwa_2 = (Singletons::getInstance()->hanhwa_1) + (Singletons::getInstance()->hanhwa_1*Singletons::getInstance()->hanhwa_A);
			Singletons::getInstance()->hanhwa_1 = Singletons::getInstance()->hanhwa_2;

			//���
			Singletons::getInstance()->kia_3 = Singletons::getInstance()->kia_1;
			Singletons::getInstance()->kia_2 = (Singletons::getInstance()->kia_1) + (Singletons::getInstance()->kia_1*Singletons::getInstance()->kia_A);
			Singletons::getInstance()->kia_1 = Singletons::getInstance()->kia_2;

			//����
			Singletons::getInstance()->lg_3 = Singletons::getInstance()->lg_1;
			Singletons::getInstance()->lg_2 = (Singletons::getInstance()->lg_1) + (Singletons::getInstance()->lg_1*Singletons::getInstance()->lg_A);
			Singletons::getInstance()->lg_1 = Singletons::getInstance()->lg_2;
		}
		if (Singletons::getInstance()->month == 6)
		{
			//���ۼҽ�
			if (Singletons::getInstance()->num_3 == 1)
			{
				double arr[3] = { -0.2, -0.3, -0.4 };
				srand((double)time(NULL));

				int random = rand() % 3;
				Singletons::getInstance()->samsung_A = arr[random];
			}
			//�����ҽ�
			else if (Singletons::getInstance()->num_3 == 2)
			{
				double arr[3] = { 0.2, 0.3, 0.4 };
				srand((double)time(NULL));

				int random = rand() % 3;
				Singletons::getInstance()->samsung_A = arr[random];
			}
			double arr[4] = { -0.05, -0.1, 0.05, 0.1 };
			srand((double)time(NULL));

			
			int random_2 = rand() % 4;
			Singletons::getInstance()->apple_A = arr[random_2];
			int random_3 = rand() % 4;
			Singletons::getInstance()->hanhwa_A = arr[random_3];
			int random_4 = rand() % 4;
			Singletons::getInstance()->kia_A = arr[random_4];
			int random_5 = rand() % 4;
			Singletons::getInstance()->lg_A = arr[random_5];
			//�Ｚ
			Singletons::getInstance()->samsung_3 = Singletons::getInstance()->samsung_1;
			Singletons::getInstance()->samsung_2 = (Singletons::getInstance()->samsung_1) + (Singletons::getInstance()->samsung_1*Singletons::getInstance()->samsung_A);
			Singletons::getInstance()->samsung_1 = Singletons::getInstance()->samsung_2;

			//���ξ���
			Singletons::getInstance()->apple_3 = Singletons::getInstance()->apple_1;
			Singletons::getInstance()->apple_2 = (Singletons::getInstance()->apple_1) + (Singletons::getInstance()->apple_1*Singletons::getInstance()->apple_A);
			Singletons::getInstance()->apple_1 = Singletons::getInstance()->apple_2;

			//��ȭ
			Singletons::getInstance()->hanhwa_3 = Singletons::getInstance()->hanhwa_1;
			Singletons::getInstance()->hanhwa_2 = (Singletons::getInstance()->hanhwa_1) + (Singletons::getInstance()->hanhwa_1*Singletons::getInstance()->hanhwa_A);
			Singletons::getInstance()->hanhwa_1 = Singletons::getInstance()->hanhwa_2;

			//���
			Singletons::getInstance()->kia_3 = Singletons::getInstance()->kia_1;
			Singletons::getInstance()->kia_2 = (Singletons::getInstance()->kia_1) + (Singletons::getInstance()->kia_1*Singletons::getInstance()->kia_A);
			Singletons::getInstance()->kia_1 = Singletons::getInstance()->kia_2;

			//����
			Singletons::getInstance()->lg_3 = Singletons::getInstance()->lg_1;
			Singletons::getInstance()->lg_2 = (Singletons::getInstance()->lg_1) + (Singletons::getInstance()->lg_1*Singletons::getInstance()->lg_A);
			Singletons::getInstance()->lg_1 = Singletons::getInstance()->lg_2;
		}
		if (Singletons::getInstance()->month == 7)
		{
			//���ۼҽ�
			if (Singletons::getInstance()->num_3 == 1)
			{
				double arr[3] = { -0.2, -0.3, -0.4 };
				srand((double)time(NULL));
				int random_2 = rand() % 3;
				Singletons::getInstance()->apple_A = arr[random_2];
			}
			//�����ҽ�
			else if (Singletons::getInstance()->num_3 == 2)
			{
				double arr[3] = { 0.2, 0.3, 0.4 };
				srand((double)time(NULL));

				int random_2 = rand() % 3;
				Singletons::getInstance()->apple_A = arr[random_2];
			}
			double arr[4] = { -0.05, -0.1, 0.05, 0.1 };
			srand((double)time(NULL));

			int random = rand() % 4;
			Singletons::getInstance()->samsung_A = arr[random];
			
			int random_3 = rand() % 4;
			Singletons::getInstance()->hanhwa_A = arr[random_3];
			int random_4 = rand() % 4;
			Singletons::getInstance()->kia_A = arr[random_4];
			int random_5 = rand() % 4;
			Singletons::getInstance()->lg_A = arr[random_5];
			//�Ｚ
			Singletons::getInstance()->samsung_3 = Singletons::getInstance()->samsung_1;
			Singletons::getInstance()->samsung_2 = (Singletons::getInstance()->samsung_1) + (Singletons::getInstance()->samsung_1*Singletons::getInstance()->samsung_A);
			Singletons::getInstance()->samsung_1 = Singletons::getInstance()->samsung_2;

			//���ξ���
			Singletons::getInstance()->apple_3 = Singletons::getInstance()->apple_1;
			Singletons::getInstance()->apple_2 = (Singletons::getInstance()->apple_1) + (Singletons::getInstance()->apple_1*Singletons::getInstance()->apple_A);
			Singletons::getInstance()->apple_1 = Singletons::getInstance()->apple_2;

			//��ȭ
			Singletons::getInstance()->hanhwa_3 = Singletons::getInstance()->hanhwa_1;
			Singletons::getInstance()->hanhwa_2 = (Singletons::getInstance()->hanhwa_1) + (Singletons::getInstance()->hanhwa_1*Singletons::getInstance()->hanhwa_A);
			Singletons::getInstance()->hanhwa_1 = Singletons::getInstance()->hanhwa_2;

			//���
			Singletons::getInstance()->kia_3 = Singletons::getInstance()->kia_1;
			Singletons::getInstance()->kia_2 = (Singletons::getInstance()->kia_1) + (Singletons::getInstance()->kia_1*Singletons::getInstance()->kia_A);
			Singletons::getInstance()->kia_1 = Singletons::getInstance()->kia_2;

			//����
			Singletons::getInstance()->lg_3 = Singletons::getInstance()->lg_1;
			Singletons::getInstance()->lg_2 = (Singletons::getInstance()->lg_1) + (Singletons::getInstance()->lg_1*Singletons::getInstance()->lg_A);
			Singletons::getInstance()->lg_1 = Singletons::getInstance()->lg_2;
		}
		if (Singletons::getInstance()->month == 8)
		{
			//���ۼҽ�
			if (Singletons::getInstance()->num_3 == 1)
			{
				double arr[3] = { -0.2, -0.3, -0.4 };
				srand((double)time(NULL));

				int random_5 = rand() % 3;
				Singletons::getInstance()->lg_A = arr[random_5];
			}
			//�����ҽ�
			else if (Singletons::getInstance()->num_3 == 2)
			{
				double arr[3] = { 0.2, 0.3, 0.4 };
				srand((double)time(NULL));

				int random_5 = rand() % 3;
				Singletons::getInstance()->lg_A = arr[random_5];
			}
			double arr[4] = { -0.05, -0.1, 0.05, 0.1 };
			srand((double)time(NULL));

			int random = rand() % 4;
			Singletons::getInstance()->samsung_A = arr[random];
			int random_2 = rand() % 4;
			Singletons::getInstance()->apple_A = arr[random_2];
			int random_3 = rand() % 4;
			Singletons::getInstance()->hanhwa_A = arr[random_3];
			int random_4 = rand() % 4;
			Singletons::getInstance()->kia_A = arr[random_4];
			//�Ｚ
			Singletons::getInstance()->samsung_3 = Singletons::getInstance()->samsung_1;
			Singletons::getInstance()->samsung_2 = (Singletons::getInstance()->samsung_1) + (Singletons::getInstance()->samsung_1*Singletons::getInstance()->samsung_A);
			Singletons::getInstance()->samsung_1 = Singletons::getInstance()->samsung_2;

			//���ξ���
			Singletons::getInstance()->apple_3 = Singletons::getInstance()->apple_1;
			Singletons::getInstance()->apple_2 = (Singletons::getInstance()->apple_1) + (Singletons::getInstance()->apple_1*Singletons::getInstance()->apple_A);
			Singletons::getInstance()->apple_1 = Singletons::getInstance()->apple_2;

			//��ȭ
			Singletons::getInstance()->hanhwa_3 = Singletons::getInstance()->hanhwa_1;
			Singletons::getInstance()->hanhwa_2 = (Singletons::getInstance()->hanhwa_1) + (Singletons::getInstance()->hanhwa_1*Singletons::getInstance()->hanhwa_A);
			Singletons::getInstance()->hanhwa_1 = Singletons::getInstance()->hanhwa_2;

			//���
			Singletons::getInstance()->kia_3 = Singletons::getInstance()->kia_1;
			Singletons::getInstance()->kia_2 = (Singletons::getInstance()->kia_1) + (Singletons::getInstance()->kia_1*Singletons::getInstance()->kia_A);
			Singletons::getInstance()->kia_1 = Singletons::getInstance()->kia_2;

			//����
			Singletons::getInstance()->lg_3 = Singletons::getInstance()->lg_1;
			Singletons::getInstance()->lg_2 = (Singletons::getInstance()->lg_1) + (Singletons::getInstance()->lg_1*Singletons::getInstance()->lg_A);
			Singletons::getInstance()->lg_1 = Singletons::getInstance()->lg_2;
		}
		if (Singletons::getInstance()->month == 9)
		{
			//���ۼҽ�
			if (Singletons::getInstance()->num_3 == 1)
			{
				double arr[3] = { -0.2, -0.3, -0.4 };
				srand((double)time(NULL));

				int random_4 = rand() % 3;
				Singletons::getInstance()->kia_A = arr[random_4];
			}
			//�����ҽ�
			else if (Singletons::getInstance()->num_3 == 2)
			{
				double arr[3] = { 0.2, 0.3, 0.4 };
				srand((double)time(NULL));

				int random_4 = rand() % 3;
				Singletons::getInstance()->kia_A = arr[random_4];
			}
			double arr[4] = { -0.05, -0.1, 0.05, 0.1 };
			srand((double)time(NULL));

			int random = rand() % 4;
			Singletons::getInstance()->samsung_A = arr[random];
			int random_2 = rand() % 4;
			Singletons::getInstance()->apple_A = arr[random_2];
			int random_3 = rand() % 4;
			Singletons::getInstance()->hanhwa_A = arr[random_3];
			
			int random_5 = rand() % 4;
			Singletons::getInstance()->lg_A = arr[random_5];
			//�Ｚ
			Singletons::getInstance()->samsung_3 = Singletons::getInstance()->samsung_1;
			Singletons::getInstance()->samsung_2 = (Singletons::getInstance()->samsung_1) + (Singletons::getInstance()->samsung_1*Singletons::getInstance()->samsung_A);
			Singletons::getInstance()->samsung_1 = Singletons::getInstance()->samsung_2;

			//���ξ���
			Singletons::getInstance()->apple_3 = Singletons::getInstance()->apple_1;
			Singletons::getInstance()->apple_2 = (Singletons::getInstance()->apple_1) + (Singletons::getInstance()->apple_1*Singletons::getInstance()->apple_A);
			Singletons::getInstance()->apple_1 = Singletons::getInstance()->apple_2;

			//��ȭ
			Singletons::getInstance()->hanhwa_3 = Singletons::getInstance()->hanhwa_1;
			Singletons::getInstance()->hanhwa_2 = (Singletons::getInstance()->hanhwa_1) + (Singletons::getInstance()->hanhwa_1*Singletons::getInstance()->hanhwa_A);
			Singletons::getInstance()->hanhwa_1 = Singletons::getInstance()->hanhwa_2;

			//���
			Singletons::getInstance()->kia_3 = Singletons::getInstance()->kia_1;
			Singletons::getInstance()->kia_2 = (Singletons::getInstance()->kia_1) + (Singletons::getInstance()->kia_1*Singletons::getInstance()->kia_A);
			Singletons::getInstance()->kia_1 = Singletons::getInstance()->kia_2;

			//����
			Singletons::getInstance()->lg_3 = Singletons::getInstance()->lg_1;
			Singletons::getInstance()->lg_2 = (Singletons::getInstance()->lg_1) + (Singletons::getInstance()->lg_1*Singletons::getInstance()->lg_A);
			Singletons::getInstance()->lg_1 = Singletons::getInstance()->lg_2;
		}
		if (Singletons::getInstance()->month == 10)
		{
			//���ۼҽ�
			if (Singletons::getInstance()->num_3 == 1)
			{
				double arr[3] = { -0.2, -0.3, -0.4 };
				srand((double)time(NULL));

				int random = rand() % 3;
				Singletons::getInstance()->samsung_A = arr[random];
			}
			//�����ҽ�
			else if (Singletons::getInstance()->num_3 == 2)
			{
				double arr[3] = { 0.2, 0.3, 0.4 };
				srand((double)time(NULL));

				int random = rand() % 3;
				Singletons::getInstance()->samsung_A = arr[random];
			}
			double arr[4] = { -0.05, -0.1, 0.05, 0.1 };
			srand((double)time(NULL));

			
			int random_2 = rand() % 4;
			Singletons::getInstance()->apple_A = arr[random_2];
			int random_3 = rand() % 4;
			Singletons::getInstance()->hanhwa_A = arr[random_3];
			int random_4 = rand() % 4;
			Singletons::getInstance()->kia_A = arr[random_4];
			int random_5 = rand() % 4;
			Singletons::getInstance()->lg_A = arr[random_5];
			//�Ｚ
			Singletons::getInstance()->samsung_3 = Singletons::getInstance()->samsung_1;
			Singletons::getInstance()->samsung_2 = (Singletons::getInstance()->samsung_1) + (Singletons::getInstance()->samsung_1*Singletons::getInstance()->samsung_A);
			Singletons::getInstance()->samsung_1 = Singletons::getInstance()->samsung_2;

			//���ξ���
			Singletons::getInstance()->apple_3 = Singletons::getInstance()->apple_1;
			Singletons::getInstance()->apple_2 = (Singletons::getInstance()->apple_1) + (Singletons::getInstance()->apple_1*Singletons::getInstance()->apple_A);
			Singletons::getInstance()->apple_1 = Singletons::getInstance()->apple_2;

			//��ȭ
			Singletons::getInstance()->hanhwa_3 = Singletons::getInstance()->hanhwa_1;
			Singletons::getInstance()->hanhwa_2 = (Singletons::getInstance()->hanhwa_1) + (Singletons::getInstance()->hanhwa_1*Singletons::getInstance()->hanhwa_A);
			Singletons::getInstance()->hanhwa_1 = Singletons::getInstance()->hanhwa_2;

			//���
			Singletons::getInstance()->kia_3 = Singletons::getInstance()->kia_1;
			Singletons::getInstance()->kia_2 = (Singletons::getInstance()->kia_1) + (Singletons::getInstance()->kia_1*Singletons::getInstance()->kia_A);
			Singletons::getInstance()->kia_1 = Singletons::getInstance()->kia_2;

			//����
			Singletons::getInstance()->lg_3 = Singletons::getInstance()->lg_1;
			Singletons::getInstance()->lg_2 = (Singletons::getInstance()->lg_1) + (Singletons::getInstance()->lg_1*Singletons::getInstance()->lg_A);
			Singletons::getInstance()->lg_1 = Singletons::getInstance()->lg_2;
		}
		if (Singletons::getInstance()->month == 11)
		{
			//���ۼҽ�
			if (Singletons::getInstance()->num_3 == 1)
			{
				double arr[3] = { -0.2, -0.3, -0.4 };
				srand((double)time(NULL));

				int random_3 = rand() % 3;
				Singletons::getInstance()->hanhwa_A = arr[random_3];
			}
			//�����ҽ�
			else if (Singletons::getInstance()->num_3 == 2)
			{
				double arr[3] = { 0.2, 0.3, 0.4 };
				srand((double)time(NULL));


				int random_3 = rand() % 3;
				Singletons::getInstance()->hanhwa_A = arr[random_3];
			}
			double arr[4] = { -0.05, -0.1, 0.05, 0.1 };
			srand((double)time(NULL));

			int random = rand() % 4;
			Singletons::getInstance()->samsung_A = arr[random];
			int random_2 = rand() % 4;
			Singletons::getInstance()->apple_A = arr[random_2];
			
			int random_4 = rand() % 4;
			Singletons::getInstance()->kia_A = arr[random_4];
			int random_5 = rand() % 4;
			Singletons::getInstance()->lg_A = arr[random_5];
			//�Ｚ
			Singletons::getInstance()->samsung_3 = Singletons::getInstance()->samsung_1;
			Singletons::getInstance()->samsung_2 = (Singletons::getInstance()->samsung_1) + (Singletons::getInstance()->samsung_1*Singletons::getInstance()->samsung_A);
			Singletons::getInstance()->samsung_1 = Singletons::getInstance()->samsung_2;

			//���ξ���
			Singletons::getInstance()->apple_3 = Singletons::getInstance()->apple_1;
			Singletons::getInstance()->apple_2 = (Singletons::getInstance()->apple_1) + (Singletons::getInstance()->apple_1*Singletons::getInstance()->apple_A);
			Singletons::getInstance()->apple_1 = Singletons::getInstance()->apple_2;

			//��ȭ
			Singletons::getInstance()->hanhwa_3 = Singletons::getInstance()->hanhwa_1;
			Singletons::getInstance()->hanhwa_2 = (Singletons::getInstance()->hanhwa_1) + (Singletons::getInstance()->hanhwa_1*Singletons::getInstance()->hanhwa_A);
			Singletons::getInstance()->hanhwa_1 = Singletons::getInstance()->hanhwa_2;

			//���
			Singletons::getInstance()->kia_3 = Singletons::getInstance()->kia_1;
			Singletons::getInstance()->kia_2 = (Singletons::getInstance()->kia_1) + (Singletons::getInstance()->kia_1*Singletons::getInstance()->kia_A);
			Singletons::getInstance()->kia_1 = Singletons::getInstance()->kia_2;

			//����
			Singletons::getInstance()->lg_3 = Singletons::getInstance()->lg_1;
			Singletons::getInstance()->lg_2 = (Singletons::getInstance()->lg_1) + (Singletons::getInstance()->lg_1*Singletons::getInstance()->lg_A);
			Singletons::getInstance()->lg_1 = Singletons::getInstance()->lg_2;
		}
		if (Singletons::getInstance()->month == 12)
		{
			//���ۼҽ�
			if (Singletons::getInstance()->num_3 == 1)
			{
				double arr[3] = { -0.2, -0.3, -0.4 };
				srand((double)time(NULL));

				int random_2 = rand() % 3;
				Singletons::getInstance()->apple_A = arr[random_2];
			}
			//�����ҽ�
			else if (Singletons::getInstance()->num_3 == 2)
			{
				double arr[3] = { 0.2, 0.3, 0.4 };
				srand((double)time(NULL));

				int random_2 = rand() % 3;
				Singletons::getInstance()->apple_A = arr[random_2];
			}
			double arr[4] = { -0.05, -0.1, 0.05, 0.1 };
			srand((double)time(NULL));

			int random = rand() % 4;
			Singletons::getInstance()->samsung_A = arr[random];
			
			int random_3 = rand() % 4;
			Singletons::getInstance()->hanhwa_A = arr[random_3];
			int random_4 = rand() % 4;
			Singletons::getInstance()->kia_A = arr[random_4];
			int random_5 = rand() % 4;
			Singletons::getInstance()->lg_A = arr[random_5];
			//�Ｚ
			Singletons::getInstance()->samsung_3 = Singletons::getInstance()->samsung_1;
			Singletons::getInstance()->samsung_2 = (Singletons::getInstance()->samsung_1) + (Singletons::getInstance()->samsung_1*Singletons::getInstance()->samsung_A);
			Singletons::getInstance()->samsung_1 = Singletons::getInstance()->samsung_2;

			//���ξ���
			Singletons::getInstance()->apple_3 = Singletons::getInstance()->apple_1;
			Singletons::getInstance()->apple_2 = (Singletons::getInstance()->apple_1) + (Singletons::getInstance()->apple_1*Singletons::getInstance()->apple_A);
			Singletons::getInstance()->apple_1 = Singletons::getInstance()->apple_2;

			//��ȭ
			Singletons::getInstance()->hanhwa_3 = Singletons::getInstance()->hanhwa_1;
			Singletons::getInstance()->hanhwa_2 = (Singletons::getInstance()->hanhwa_1) + (Singletons::getInstance()->hanhwa_1*Singletons::getInstance()->hanhwa_A);
			Singletons::getInstance()->hanhwa_1 = Singletons::getInstance()->hanhwa_2;

			//���
			Singletons::getInstance()->kia_3 = Singletons::getInstance()->kia_1;
			Singletons::getInstance()->kia_2 = (Singletons::getInstance()->kia_1) + (Singletons::getInstance()->kia_1*Singletons::getInstance()->kia_A);
			Singletons::getInstance()->kia_1 = Singletons::getInstance()->kia_2;

			//����
			Singletons::getInstance()->lg_3 = Singletons::getInstance()->lg_1;
			Singletons::getInstance()->lg_2 = (Singletons::getInstance()->lg_1) + (Singletons::getInstance()->lg_1*Singletons::getInstance()->lg_A);
			Singletons::getInstance()->lg_1 = Singletons::getInstance()->lg_2;
		}
		if (Singletons::getInstance()->month == 1)
		{
			//���ۼҽ�
			if (Singletons::getInstance()->num_3 == 1)
			{
				double arr[3] = { -0.2, -0.3, -0.4 };
				srand((double)time(NULL));

				int random_3 = rand() % 3;
				Singletons::getInstance()->hanhwa_A = arr[random_3];
			}
			//�����ҽ�
			else if (Singletons::getInstance()->num_3 == 2)
			{
				double arr[3] = { 0.2, 0.3, 0.4 };
				srand((double)time(NULL));

				int random_3 = rand() % 3;
				Singletons::getInstance()->hanhwa_A = arr[random_3];
			}
			double arr[4] = { -0.05, -0.1, 0.05, 0.1 };
			srand((double)time(NULL));

			int random = rand() % 4;
			Singletons::getInstance()->samsung_A = arr[random];
			int random_2 = rand() % 4;
			Singletons::getInstance()->apple_A = arr[random_2];
			
			int random_4 = rand() % 4;
			Singletons::getInstance()->kia_A = arr[random_4];
			int random_5 = rand() % 4;
			Singletons::getInstance()->lg_A = arr[random_5];
			//�Ｚ
			Singletons::getInstance()->samsung_3 = Singletons::getInstance()->samsung_1;
			Singletons::getInstance()->samsung_2 = (Singletons::getInstance()->samsung_1) + (Singletons::getInstance()->samsung_1*Singletons::getInstance()->samsung_A);
			Singletons::getInstance()->samsung_1 = Singletons::getInstance()->samsung_2;

			//���ξ���
			Singletons::getInstance()->apple_3 = Singletons::getInstance()->apple_1;
			Singletons::getInstance()->apple_2 = (Singletons::getInstance()->apple_1) + (Singletons::getInstance()->apple_1*Singletons::getInstance()->apple_A);
			Singletons::getInstance()->apple_1 = Singletons::getInstance()->apple_2;

			//��ȭ
			Singletons::getInstance()->hanhwa_3 = Singletons::getInstance()->hanhwa_1;
			Singletons::getInstance()->hanhwa_2 = (Singletons::getInstance()->hanhwa_1) + (Singletons::getInstance()->hanhwa_1*Singletons::getInstance()->hanhwa_A);
			Singletons::getInstance()->hanhwa_1 = Singletons::getInstance()->hanhwa_2;

			//���
			Singletons::getInstance()->kia_3 = Singletons::getInstance()->kia_1;
			Singletons::getInstance()->kia_2 = (Singletons::getInstance()->kia_1) + (Singletons::getInstance()->kia_1*Singletons::getInstance()->kia_A);
			Singletons::getInstance()->kia_1 = Singletons::getInstance()->kia_2;

			//����
			Singletons::getInstance()->lg_3 = Singletons::getInstance()->lg_1;
			Singletons::getInstance()->lg_2 = (Singletons::getInstance()->lg_1) + (Singletons::getInstance()->lg_1*Singletons::getInstance()->lg_A);
			Singletons::getInstance()->lg_1 = Singletons::getInstance()->lg_2;
		}
		if (Singletons::getInstance()->month == 2)
		{
			//���ۼҽ�
			if (Singletons::getInstance()->num_3 == 1)
			{
				double arr[3] = { -0.2, -0.3, -0.4 };
				srand((double)time(NULL));
				int random_2 = rand() % 3;
				Singletons::getInstance()->apple_A = arr[random_2];
			}
			//�����ҽ�
			else if (Singletons::getInstance()->num_3 == 2)
			{
				double arr[3] = { 0.2, 0.3, 0.4 };
				srand((double)time(NULL));

				int random_2 = rand() % 3;
				Singletons::getInstance()->apple_A = arr[random_2];
			}
			double arr[4] = { -0.05, -0.1, 0.05, 0.1 };
			srand((double)time(NULL));

			int random = rand() % 4;
			Singletons::getInstance()->samsung_A = arr[random];
			
			int random_3 = rand() % 4;
			Singletons::getInstance()->hanhwa_A = arr[random_3];
			int random_4 = rand() % 4;
			Singletons::getInstance()->kia_A = arr[random_4];

			int random_5 = rand() % 4;
			Singletons::getInstance()->lg_A = arr[random_5];
			//�Ｚ
			Singletons::getInstance()->samsung_3 = Singletons::getInstance()->samsung_1;
			Singletons::getInstance()->samsung_2 = (Singletons::getInstance()->samsung_1) + (Singletons::getInstance()->samsung_1*Singletons::getInstance()->samsung_A);
			Singletons::getInstance()->samsung_1 = Singletons::getInstance()->samsung_2;

			//���ξ���
			Singletons::getInstance()->apple_3 = Singletons::getInstance()->apple_1;
			Singletons::getInstance()->apple_2 = (Singletons::getInstance()->apple_1) + (Singletons::getInstance()->apple_1*Singletons::getInstance()->apple_A);
			Singletons::getInstance()->apple_1 = Singletons::getInstance()->apple_2;

			//��ȭ
			Singletons::getInstance()->hanhwa_3 = Singletons::getInstance()->hanhwa_1;
			Singletons::getInstance()->hanhwa_2 = (Singletons::getInstance()->hanhwa_1) + (Singletons::getInstance()->hanhwa_1*Singletons::getInstance()->hanhwa_A);
			Singletons::getInstance()->hanhwa_1 = Singletons::getInstance()->hanhwa_2;

			//���
			Singletons::getInstance()->kia_3 = Singletons::getInstance()->kia_1;
			Singletons::getInstance()->kia_2 = (Singletons::getInstance()->kia_1) + (Singletons::getInstance()->kia_1*Singletons::getInstance()->kia_A);
			Singletons::getInstance()->kia_1 = Singletons::getInstance()->kia_2;

			//����
			Singletons::getInstance()->lg_3 = Singletons::getInstance()->lg_1;
			Singletons::getInstance()->lg_2 = (Singletons::getInstance()->lg_1) + (Singletons::getInstance()->lg_1*Singletons::getInstance()->lg_A);
			Singletons::getInstance()->lg_1 = Singletons::getInstance()->lg_2;
		}
	}
	//��������

	//����
	if (Singletons::getInstance()->money >= 60000000)
	{

		Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
		Director::getInstance()->replaceScene(HappyEnd::createScene());
	}
	if (Singletons::getInstance()->month == 2 && Singletons::getInstance()->day >=28.5&&Singletons::getInstance()->day <= 29)
	{
		Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
		Director::getInstance()->replaceScene(BadEnd::createScene());
	}
}
// ��Ʈ�� ����â
void NextDayScene::InitMenu()
{
	
}
void NextDayScene::fin(Ref *pSender)
{
	
}
void NextDayScene::system(Ref *pSender)
{

}
void NextDayScene::replayspr(Ref *pSender)
{
	
}
void NextDayScene::newplayspr(Ref *pSender)
{

}
//bool NextDayScene::onTouchBegan(Touch* touch, Event* unused_event)
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
