#ifndef __INTRO_SCENE0_H__
#define __INTRO_SCENE0_H__

#include "cocos2d.h"
USING_NS_CC;

class IntroScene0 : public cocos2d::Layer
{
private:
	Size visibleSize;
	Vec2 origin;
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
	virtual void update(float delta) override;

	void InitBackGround();
	void next(float delta);
	
    CREATE_FUNC(IntroScene0);
};

#endif 
