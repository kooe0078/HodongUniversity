#ifndef __MINIGAMEMAIN_SCENE2_H__
#define __MINIGAMEMAIN_SCENE2_H__

#include "cocos2d.h"
USING_NS_CC;

class MiniGameMainScene_2 : public cocos2d::Layer
{
private:
	Size visibleSize;
	Vec2 origin;
	Sprite* Garbage_1[30];
	Sprite* Garbage_2[60];
	Sprite* Garbage_3[70];
	int GameScore = 0;
public:
    static cocos2d::Scene* createScene();
	
    virtual bool init();
	virtual void update(float delta) override;

	void InitBackGround();
	void InitSprite();
	void InitLabel();
	void SetGarbage(float delta);
	void SetLabel(float delta);
	void Score(float ft);

	virtual void onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);
	virtual void onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);
	
    CREATE_FUNC(MiniGameMainScene_2);
};

#endif 
