#ifndef __BUDONGSTORY_SCENEG_H__
#define __BUDONGSTORY_SCENEG_H__

#include "cocos2d.h"
USING_NS_CC;

class BiriSceneG : public cocos2d::Layer
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
	void skipspr(Ref *pSender);
	void GoHome(Ref *pSender);

	void storyA(Ref *pSender);
	void storyAA(Ref *pSender);
	void storyAAA(Ref *pSender);
	void storyAAAA(Ref *pSender);
	void storyAAAAA(Ref *pSender);
	void storyAAAAAA(Ref *pSender);
	void storyAAAAAAA(Ref *pSender);

	void storyA_1(Ref *pSender);
	void storyAA_1(Ref *pSender);


	void storyA_2(Ref *pSender);
	void storyAA_2(Ref *pSender);

	
	
	void storyfin(Ref *pSender);
	/*virtual bool onTouchBegan(Touch* touch, Event* unused_event);*/
	//virtual void onTouchMoved(Touch *touch, Event *event);
	//virtual void onTouchEnded(Touch *touch, Event *event);
    CREATE_FUNC(BiriSceneG);
};

#endif 
