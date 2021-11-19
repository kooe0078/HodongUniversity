#ifndef __ExerciseScene_SCENE_H__
#define __ExerciseScene_SCENE_H__

#include "cocos2d.h"
USING_NS_CC;

class ExerciseScene : public cocos2d::Layer
{
private:
	#define TAG_UP 594
	int Tra = 0;
	bool line = true;
public:
    static cocos2d::Scene* createScene();

    virtual bool init();

	void update(float ft);
	void endGame(float delta);
	void initBG();
	void initChar();
	void Gauge();
	void GaugeUp(float delta);
	void GaugeDown(float delta);
	void initLabel();

	virtual void onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);
	virtual void onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);
	
    CREATE_FUNC(ExerciseScene);
};

#endif 
