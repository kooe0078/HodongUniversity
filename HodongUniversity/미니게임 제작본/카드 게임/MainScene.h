#ifndef __MAIN_SCENE_H__
#define __MAIN_SCENE_H__

#include "cocos2d.h"
USING_NS_CC;

class MainScene : public cocos2d::Layer
{
private:
	#define TAG_LABEL_CARD 0
	#define TAG_LABEL_LlFE 1
	#define TAG_LABEL_READY 2
	#define TAG_LABEL_START 3
	#define TAG_SPRITE_O 4
	#define TAG_SPRlTE_X 5
	#define TAG_SPRITE_GAMEOVER 6
	#define TAG_SPRITE_GAMECLEAR 7
	#define TAG_SPRITE_CARD 600
public:
    static cocos2d::Scene* createScene();
	
    virtual bool init();

	bool onTouchBegan(Touch * touch, Event * unused_event);
	bool isTouch;

	Size winSize;

	void initBG();
	int life;
	int card[8];
	int countCard;
	void initGameData();

	void initLabel();
	void initTopMenuLabel();
	void setLabelCard();
	void setLabelLife();
	void initCard();

	void sprReady();
	void sprStart(float delta);
	void actionCard(float delta);
	void endCard(float delta);

	void initO();
	void initX();
	void actionOX(bool isO);
	void endOX();

	void actionGameEnd(bool isGameClear);
	void endGameEnd();

    CREATE_FUNC(MainScene);
};

#endif 
