#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
USING_NS_CC;

class HelloWorld : public cocos2d::Layer
{
private:
	Size visibleSize;
	Vec2 origin;
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
	virtual void update(float delta) override;

	void InitSprite();
	void InitLabel();
	void InitSpriteByLayer();
	void InitMenu();
	void InitSound();

	void PostionAction();
	void ScaleAction();
	void RotationAction();
	void VisibleAction();
	void OpacityAction();
	void EtcAction();
	void ApplyAction();

	void Animation();
	void ChangeScene();

	void Tick(float delta);
    void menuCloseCallback(cocos2d::Ref* pSender);
    
	virtual bool onTouchBegan(Touch* touch, Event* unused_event);
	//virtual void onTouchMoved(Touch *touch, Event *event);
	//virtual void onTouchEnded(Touch *touch, Event *event);
    CREATE_FUNC(HelloWorld);
};

#endif 
