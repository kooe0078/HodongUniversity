#ifndef __MAIN_SCENE_H__
#define __MAIN_SCENE_H__

#include "cocos2d.h"
USING_NS_CC;

class AlbaScene : public cocos2d::Layer
{
private:
	bool click = false;
	int i = 0;
public:
    static cocos2d::Scene* createScene();

    virtual bool init();

	void initBG();
	void sprReady();
	void sprStart(float delta);
	void TimeLimit();
	void initLabel();
	void SetLabel(float delta);
	void SetLabel2(float delta);
	void initMove();
	void Released();

	bool onTouchBegan(Touch * touch, Event * event);
	void onTouchMoved(Touch * touch, Event * event);
	void onTouchEnded(Touch *touch, Event *event);
	
    CREATE_FUNC(AlbaScene);
};

#endif 
