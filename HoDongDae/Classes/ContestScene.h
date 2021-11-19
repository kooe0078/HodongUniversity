#ifndef __CONTEST_SCENE_H__
#define __CONTEST_SCENE_H__

#include "cocos2d.h"
USING_NS_CC;

class ContestScene : public cocos2d::Layer
{
private:
	Size visibleSize;
	Vec2 origin;

	bool open = false;
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
	virtual void update(float delta) override;

	void InitBackGround();
	void InitLabel();
	void InitMenu();
	void newplay(Ref *pSender);
	void system(Ref *pSender);
	void rightsystem(Ref *pSender);
	void check (Ref *pSender);
	void rightcheck(Ref *pSender);
	void scorestage(Ref *pSender);
	void cancelspr(Ref *pSender);
	void replayspr(Ref *pSender);
	void bosang(Ref *pSender);
	void Nextday(Ref *pSender);
	/*virtual bool onTouchBegan(Touch* touch, Event* unused_event);*/
	//virtual void onTouchMoved(Touch *touch, Event *event);
	//virtual void onTouchEnded(Touch *touch, Event *event);
    CREATE_FUNC(ContestScene);
};

#endif 
