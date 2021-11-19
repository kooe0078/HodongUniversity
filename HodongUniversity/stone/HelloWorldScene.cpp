#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"

//사운드 할라면 꼭 필요
using namespace CocosDenshion;
USING_NS_CC;

Scene* HelloWorld::createScene()
{
    auto scene = Scene::create();
    auto layer = HelloWorld::create();
    scene->addChild(layer);

    return scene;
}

bool HelloWorld::init()
{

    if ( !Layer::init() )
    {
        return false;
    }

	visibleSize = Director::getInstance()->getVisibleSize();
	origin      = Director::getInstance()->getVisibleOrigin();
	
	InitSprite();
	InitLabel();
	InitSpriteByLayer();
	InitMenu();
	InitSound();

	//터치 리스너 등록
	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = CC_CALLBACK_2(HelloWorld::onTouchBegan, this);
	Director::getInstance()->getEventDispatcher()->addEventListenerWithFixedPriority(listener, 1);

	//반복시간 안정한 스케쥴은 지정한 fps 속도로 반복 
	this->schedule(schedule_selector(HelloWorld::update));
	//반복시간 정한 스케쥴은 그 시간마다 호출
	this->schedule(schedule_selector(HelloWorld::Tick), 1.0f);
	//딜레이 타임 후 한번만	불러지게 하기
	//this->scheduleOnce(schedule_selector(HelloWorld::Tick), 10.0f);

    return true;
}
void HelloWorld::update(float ft)
{
	//씬 자체적으로 반복 되야하는 내용
}

bool HelloWorld::onTouchBegan(Touch* touch, Event* unused_event)
{
	Animation();

	//마우스가 누른 위치 받기
	Point location;
	location = touch->getLocation();

	return false;
}

void HelloWorld::InitSprite()
{ 
	auto sprite = Sprite::create("CocosResources/overWatch.jpg");
	sprite->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	this->addChild(sprite, 0);

	//Action을 위한 예제 스프라이트
	auto mario = Sprite::create("CocosResources/mario.png");
	mario->setScale(0.1);
	mario->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	mario->setTag(1);
	this->addChild(mario, 1);
}
void HelloWorld::InitLabel()
{
	auto label = Label::createWithTTF("OVERWATCH", "CocosResources/CuteFont.ttf", 24);
	label->setPosition(Vec2(origin.x + visibleSize.width / 2,
		origin.y + visibleSize.height - label->getContentSize().height));
	this->addChild(label, 1);
}
void HelloWorld::InitSpriteByLayer()
{
	auto layer = Layer::create();

	for (int i = 0; i < 600; i += 60)
	{
		auto sprite = Sprite::create("CocosResources/mercy.png");
		sprite->setAnchorPoint(Point(0.5, 0.5));
		sprite->setScale(0.1);
		sprite->setPosition(i, 300);
		layer->addChild(sprite, 1);
	}

	this->addChild(layer);
}
void HelloWorld::InitMenu()
{
	auto closeItem = MenuItemImage::create(
		"CloseNormal.png",
		"CloseSelected.png",
		CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width / 2,
		origin.y + closeItem->getContentSize().height / 2));

	auto menu = Menu::create(closeItem, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 1);
}
void HelloWorld::InitSound()
{
	//사운드는 크게 배경음 효과음이 있음
	//발걸음 효과음은 자주 불러짐으로 preload 해두면 좋음
	
	//메모리에 불러 놓기
	SimpleAudioEngine::getInstance()->preloadBackgroundMusic("CocosResources/BackGroundSound.mp3");
	SimpleAudioEngine::getInstance()->preloadEffect("CocosResources/Flap.mp3");

	//배경음
	SimpleAudioEngine::getInstance()->playBackgroundMusic("CocosResources/BackGroundSound.mp3", false); //반복 꺼둠
	//효과음
	SimpleAudioEngine::getInstance()->playEffect("CocosResources/Flap.mp3", true); // 반복 꺼둠 반환형이 int 필요하면 값을 저장해둔다.
	
	////배경음 정지, 일시정지, 이어재생
	//SimpleAudioEngine::getInstance()->stopBackgroundMusic(); //인자값에 true 넣으면 메모리 해제도 됨
	//SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
	//SimpleAudioEngine::getInstance()->resumeBackgroundMusic();

	////효과음 모두정지, 정지, 일시정지, 이어재생
	//SimpleAudioEngine::getInstance()->stopAllEffects();
	//SimpleAudioEngine::getInstance()->pauseAllEffects();
	//SimpleAudioEngine::sharedEngine()->resumeAllEffects();
	////SimpleAudioEngine::getInstance()->pauseEffect(unsigned int nSoundId);
	////SimpleAudioEngine::getInstance()->resumeEffect(unsigned int nSoundId);
	//
	////볼륨 범위는 0 ~ 1
	//SimpleAudioEngine::getInstance()->setBackgroundMusicVolume(1);
	//SimpleAudioEngine::getInstance()->setEffectsVolume(1);
	//SimpleAudioEngine::getInstance()->getBackgroundMusicVolume();	 //반환형이 float
	//SimpleAudioEngine::getInstance()->getEffectsVolume();			 //반환형이 float

	////배경음이 재생중인지 확인
	//SimpleAudioEngine::getInstance()->isBackgroundMusicPlaying(); //bool형이 반환형

	//효과음 해제
	//SimpleAudioEngine::getInstance()->unloadEffect(이름);
}

void HelloWorld::PostionAction()
{
	Sprite* mario = (Sprite *)this->getChildByTag(1);
	
	//auto action = MoveBy::create(3, Point(200, 0));
	//auto action = MoveTo::create(3, Point(200, 0));

	auto action = JumpBy::create(3.0f, Point(200, 200), 100, 5);
	
	//ccBezierConfig bezier;
	//bezier.controlPoint_1 = Point(150, 150);  // 첫번째 위치
	//bezier.controlPoint_2 = Point(250, 50);    // 두번째 위치
	//bezier.endPosition = Point(350, 0);    // 마지막 위치
	//auto action = BezierBy::create(3.0f, bezier);    // 시간, BezierConfig

	//auto action = Place::create(Point(200, 200));    // 위치

	mario->runAction(action);
}
void HelloWorld::ScaleAction()
{
	Sprite* mario = (Sprite *)this->getChildByTag(1);
	auto action = ScaleBy::create(3.0f, 2.0);
	mario->runAction(action);
}
void HelloWorld::RotationAction()
{
	Sprite* mario = (Sprite *)this->getChildByTag(1);
	auto action = RotateBy::create(3.0f, 90); // Z축 기준
	mario->runAction(action);
}
void HelloWorld::VisibleAction()
{
	Sprite* mario = (Sprite *)this->getChildByTag(1);
	//auto action = Show::create();
	//auto action = Hide::create();
	//auto action = Blink::create(3.0f, 4); 몇 초동안 몇번 깜빡이는지
	auto action = ToggleVisibility::create(); //보이면 안보이게 안보이면 보이게 설정
	mario->runAction(action);
}
void HelloWorld::OpacityAction()
{
	Sprite* mario = (Sprite *)this->getChildByTag(1);
	/*auto action = FadeIn::create(3.0f);    
	auto action = FadeOut::create(3.0f);    */
	auto action = FadeTo::create(3.0f, 128);    
	mario->runAction(action);
}
void HelloWorld::EtcAction()
{
	Sprite* mario = (Sprite *)this->getChildByTag(1);
	//auto action = FlipX::create(true); // 해당스프라이트 y 축 기준 뒤집기
	//auto action = RemoveSelf::create(false); // 자기삭제
	auto action = TintTo::create(3.0f, 0, 0, 255); // 색상변경
	mario->runAction(action);

	//이외에도 세밀한 동작 액션들이 있따.
	//액션을 멈추고 싶을때는
	//mario->stopAction 
	//mario->stopActionByTag
	//같은 것들을 이용
}
void HelloWorld::ApplyAction()
{
	//조합 및 반복 액션들.

	Sprite* mario = (Sprite *)this->getChildByTag(1);
	
	auto action_0 = MoveBy::create(1.0f, Point(100, 0));
	auto action_1 = DelayTime::create(1.0f); //지연시간
	auto action_2 = action_0->reverse(); // action_0을 반대로 실행 몇몇 액션만 설정가능(By만 가능하다고 보면 댐)

	//순차적
	auto action = Sequence::create(action_0, action_1, action_2, NULL);
	
	//동시
	//auto action = Spawn::create(action_0, action_2,NULL);

	//함수 호출 액션
	//CallFunc 는 단순 함수 호출
	//auto callAction = CallFunc::create(CC_CALLBACK_0(HelloWorld::someFunc, this));
	//void someFunc(); //호출 함수 형태

	//CallFuncN 은 주체를 넘겨줄때
	//auto callAction =  CallFuncN::create(CC_CALLBACK_1(HelloWorld::someHunc, this));
	//void someFunc(Node *pSender); //호출 함수 형태

	//반복
	auto reAction = Repeat::create(action, 10);    // 액션 , 횟수
	auto refAction = RepeatForever::create(action);    // 액션

	mario->runAction(refAction);
}

void HelloWorld::Animation()
{
	//	Sprite->Animation->Animate->runAction
	//	- 먼저 기준이 되는(애니메이션을 할) 스프라이트를 만듭니다.
	//	- 애니메이션 객체를 만들고 프레임을 추가합니다.
	//	- 애니메이션 객체를 가지고 애니메이터 객체를 만듭니다.
	//	- 만든 애니메이터 객체를 스프라이트에 액션으로 실행합니다.
	
	Sprite* mario = (Sprite *)this->getChildByTag(1);
	auto animation = Animation::create();
	animation->setDelayPerUnit(0.3);
	animation->addSpriteFrameWithFileName("CocosResources/mario.png");
	animation->addSpriteFrameWithFileName("CocosResources/mario2.png");
	auto animate = Animate::create(animation);
	auto action = RepeatForever::create(animate);
	mario->runAction(action);
}
void HelloWorld::ChangeScene()
{
	//스택구조로 돌아감, 그전 씬의 메모리가 남아있음
	//Director::getInstance()->pushScene(씬의 이름);
	//Director::getInstance()->popScene();
	
	//push 다른 방법 
	//auto scene = 씬이름::createScene();
	//Director::getInstance()->pushScene(scene);

	//전환하려 하는 씬으로 전환, 그전 씬의 메모리가 날아감
	//Director::getInstance()->replaceScene(씬의 이름);
	//또는
	//auto scene = 씬이름::createScene();
	//Director::getInstance()->replaceScene(scene);

	//씬 전환 효과
	//auto scene = TransitionCrossFade::create(3.0, 씬이름::createScene());
	//Director::getInstance()->replaceScene(scene);
	//각종 전환 효과는 책에 있음
}

void HelloWorld::Tick(float delta)
{
	log("tick");
}
void HelloWorld::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
