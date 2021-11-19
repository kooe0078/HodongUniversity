#ifndef __hhhhhhh_SCENE_H__
#define __hhhhhhh_SCENE_H__

#include "cocos2d.h"
USING_NS_CC;

class hhhhhhh : public cocos2d::Layer
{
private:
	#define TAG_UP 594
	bool line = true;
public:
    static cocos2d::Scene* createScene();

    virtual bool init();

	void update(float ft);

	void Gauge();
	void GaugeUp(float delta);

	virtual void onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);
	virtual void onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);

	void click();
	void Pur1(Ref * pSender);
	
    CREATE_FUNC(hhhhhhh);
};

#endif 
