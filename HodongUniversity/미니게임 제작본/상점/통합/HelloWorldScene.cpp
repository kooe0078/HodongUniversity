#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"

//���� �Ҷ�� �� �ʿ�
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

	//��ġ ������ ���
	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = CC_CALLBACK_2(HelloWorld::onTouchBegan, this);
	Director::getInstance()->getEventDispatcher()->addEventListenerWithFixedPriority(listener, 1);

	//�ݺ��ð� ������ �������� ������ fps �ӵ��� �ݺ� 
	this->schedule(schedule_selector(HelloWorld::update));
	//�ݺ��ð� ���� �������� �� �ð����� ȣ��
	this->schedule(schedule_selector(HelloWorld::Tick), 1.0f);
	//������ Ÿ�� �� �ѹ���	�ҷ����� �ϱ�
	//this->scheduleOnce(schedule_selector(HelloWorld::Tick), 10.0f);

    return true;
}
void HelloWorld::update(float ft)
{
	//�� ��ü������ �ݺ� �Ǿ��ϴ� ����
}

bool HelloWorld::onTouchBegan(Touch* touch, Event* unused_event)
{
	Animation();

	//���콺�� ���� ��ġ �ޱ�
	Point location;
	location = touch->getLocation();

	return false;
}

void HelloWorld::InitSprite()
{ 
	auto sprite = Sprite::create("CocosResources/overWatch.jpg");
	sprite->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	this->addChild(sprite, 0);

	//Action�� ���� ���� ��������Ʈ
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
	//����� ũ�� ����� ȿ������ ����
	//�߰��� ȿ������ ���� �ҷ������� preload �صθ� ����
	
	//�޸𸮿� �ҷ� ����
	SimpleAudioEngine::getInstance()->preloadBackgroundMusic("CocosResources/BackGroundSound.mp3");
	SimpleAudioEngine::getInstance()->preloadEffect("CocosResources/Flap.mp3");

	//�����
	SimpleAudioEngine::getInstance()->playBackgroundMusic("CocosResources/BackGroundSound.mp3", false); //�ݺ� ����
	//ȿ����
	SimpleAudioEngine::getInstance()->playEffect("CocosResources/Flap.mp3", true); // �ݺ� ���� ��ȯ���� int �ʿ��ϸ� ���� �����صд�.
	
	////����� ����, �Ͻ�����, �̾����
	//SimpleAudioEngine::getInstance()->stopBackgroundMusic(); //���ڰ��� true ������ �޸� ������ ��
	//SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
	//SimpleAudioEngine::getInstance()->resumeBackgroundMusic();

	////ȿ���� �������, ����, �Ͻ�����, �̾����
	//SimpleAudioEngine::getInstance()->stopAllEffects();
	//SimpleAudioEngine::getInstance()->pauseAllEffects();
	//SimpleAudioEngine::sharedEngine()->resumeAllEffects();
	////SimpleAudioEngine::getInstance()->pauseEffect(unsigned int nSoundId);
	////SimpleAudioEngine::getInstance()->resumeEffect(unsigned int nSoundId);
	//
	////���� ������ 0 ~ 1
	//SimpleAudioEngine::getInstance()->setBackgroundMusicVolume(1);
	//SimpleAudioEngine::getInstance()->setEffectsVolume(1);
	//SimpleAudioEngine::getInstance()->getBackgroundMusicVolume();	 //��ȯ���� float
	//SimpleAudioEngine::getInstance()->getEffectsVolume();			 //��ȯ���� float

	////������� ��������� Ȯ��
	//SimpleAudioEngine::getInstance()->isBackgroundMusicPlaying(); //bool���� ��ȯ��

	//ȿ���� ����
	//SimpleAudioEngine::getInstance()->unloadEffect(�̸�);
}

void HelloWorld::PostionAction()
{
	Sprite* mario = (Sprite *)this->getChildByTag(1);
	
	//auto action = MoveBy::create(3, Point(200, 0));
	//auto action = MoveTo::create(3, Point(200, 0));

	auto action = JumpBy::create(3.0f, Point(200, 200), 100, 5);
	
	//ccBezierConfig bezier;
	//bezier.controlPoint_1 = Point(150, 150);  // ù��° ��ġ
	//bezier.controlPoint_2 = Point(250, 50);    // �ι�° ��ġ
	//bezier.endPosition = Point(350, 0);    // ������ ��ġ
	//auto action = BezierBy::create(3.0f, bezier);    // �ð�, BezierConfig

	//auto action = Place::create(Point(200, 200));    // ��ġ

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
	auto action = RotateBy::create(3.0f, 90); // Z�� ����
	mario->runAction(action);
}
void HelloWorld::VisibleAction()
{
	Sprite* mario = (Sprite *)this->getChildByTag(1);
	//auto action = Show::create();
	//auto action = Hide::create();
	//auto action = Blink::create(3.0f, 4); �� �ʵ��� ��� �����̴���
	auto action = ToggleVisibility::create(); //���̸� �Ⱥ��̰� �Ⱥ��̸� ���̰� ����
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
	//auto action = FlipX::create(true); // �ش罺������Ʈ y �� ���� ������
	//auto action = RemoveSelf::create(false); // �ڱ����
	auto action = TintTo::create(3.0f, 0, 0, 255); // ���󺯰�
	mario->runAction(action);

	//�̿ܿ��� ������ ���� �׼ǵ��� �ֵ�.
	//�׼��� ���߰� ��������
	//mario->stopAction 
	//mario->stopActionByTag
	//���� �͵��� �̿�
}
void HelloWorld::ApplyAction()
{
	//���� �� �ݺ� �׼ǵ�.

	Sprite* mario = (Sprite *)this->getChildByTag(1);
	
	auto action_0 = MoveBy::create(1.0f, Point(100, 0));
	auto action_1 = DelayTime::create(1.0f); //�����ð�
	auto action_2 = action_0->reverse(); // action_0�� �ݴ�� ���� ��� �׼Ǹ� ��������(By�� �����ϴٰ� ���� ��)

	//������
	auto action = Sequence::create(action_0, action_1, action_2, NULL);
	
	//����
	//auto action = Spawn::create(action_0, action_2,NULL);

	//�Լ� ȣ�� �׼�
	//CallFunc �� �ܼ� �Լ� ȣ��
	//auto callAction = CallFunc::create(CC_CALLBACK_0(HelloWorld::someFunc, this));
	//void someFunc(); //ȣ�� �Լ� ����

	//CallFuncN �� ��ü�� �Ѱ��ٶ�
	//auto callAction =  CallFuncN::create(CC_CALLBACK_1(HelloWorld::someHunc, this));
	//void someFunc(Node *pSender); //ȣ�� �Լ� ����

	//�ݺ�
	auto reAction = Repeat::create(action, 10);    // �׼� , Ƚ��
	auto refAction = RepeatForever::create(action);    // �׼�

	mario->runAction(refAction);
}

void HelloWorld::Animation()
{
	//	Sprite->Animation->Animate->runAction
	//	- ���� ������ �Ǵ�(�ִϸ��̼��� ��) ��������Ʈ�� ����ϴ�.
	//	- �ִϸ��̼� ��ü�� ����� �������� �߰��մϴ�.
	//	- �ִϸ��̼� ��ü�� ������ �ִϸ����� ��ü�� ����ϴ�.
	//	- ���� �ִϸ����� ��ü�� ��������Ʈ�� �׼����� �����մϴ�.
	
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
	//���ñ����� ���ư�, ���� ���� �޸𸮰� ��������
	//Director::getInstance()->pushScene(���� �̸�);
	//Director::getInstance()->popScene();
	
	//push �ٸ� ��� 
	//auto scene = ���̸�::createScene();
	//Director::getInstance()->pushScene(scene);

	//��ȯ�Ϸ� �ϴ� ������ ��ȯ, ���� ���� �޸𸮰� ���ư�
	//Director::getInstance()->replaceScene(���� �̸�);
	//�Ǵ�
	//auto scene = ���̸�::createScene();
	//Director::getInstance()->replaceScene(scene);

	//�� ��ȯ ȿ��
	//auto scene = TransitionCrossFade::create(3.0, ���̸�::createScene());
	//Director::getInstance()->replaceScene(scene);
	//���� ��ȯ ȿ���� å�� ����
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
