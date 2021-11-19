#ifndef __MIRO_SCENE_H__
#define __MIRO_SCENE_H__

#include "cocos2d.h"
USING_NS_CC;

class MiroScene2 : public cocos2d::Layer
{
private:
	bool rect1 = false;
	bool TimeCheck = true; // 시간 정지용
public:
    static cocos2d::Scene* createScene();
	cocos2d::Vector<cocos2d::Sprite*> mpData;

    virtual bool init();

	void BG();
	void Movepoint();
	void Wall();
	void Potal();

	bool onTouchBegan(Touch * touch, Event * event);
	void onTouchMoved(Touch * touch, Event * event);
	void onTouchEnded(Touch *touch, Event *event);

	void sprReady();
	void sprStart(float delta);
	void TimeLimit();
	void InitLabel();
	void SetLabel(float delta);

	
    CREATE_FUNC(MiroScene2);
};

#endif 
