#ifndef __INTRO_SCENED_H__
#define __INTRO_SCENED_H__

#include "cocos2d.h"
USING_NS_CC;

class IntroSceneD : public cocos2d::Layer
{
private:
	Size visibleSize;
	Vec2 origin;
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
	virtual void update(float delta) override;

	void InitBackGround();
	void InitLabel();
	void InitMenu();
	void storyAspr(Ref *pSender);
	void skipCspr(Ref *pSender);
	void start2 (float f);


	/*virtual bool onTouchBegan(Touch* touch, Event* unused_event);*/
	//virtual void onTouchMoved(Touch *touch, Event *event);
	//virtual void onTouchEnded(Touch *touch, Event *event);
    CREATE_FUNC(IntroSceneD);
};

#endif 
