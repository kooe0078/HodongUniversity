#ifndef __INTRO_SCENEA_H__
#define __INTRO_SCENEA_H__

#include "cocos2d.h"
USING_NS_CC;

class SchoolStoryScene : public cocos2d::Layer
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
	void storyAAA_1(Ref *pSender);
	void storyAAAA_1(Ref *pSender);
	void storyAAAAA_1(Ref *pSender);
	void storyAAAAAA_1(Ref *pSender);
	void storyAAAAAAA_1(Ref *pSender);

	void storyA_2(Ref *pSender);
	void storyAA_2(Ref *pSender);
	void storyAAA_2(Ref *pSender);
	void storyAAAA_2T(Ref *pSender);
	void storyAAAA_2F(Ref *pSender);
	void storyAAAA_2FF(Ref *pSender);
	void storyAAAAA_2(Ref *pSender);
	
	void storyB(Ref *pSender);
	void storyBB(Ref *pSender);
	void storyBBB(Ref *pSender);
	void storyBBBB(Ref *pSender);
	void storyBBBBB(Ref *pSender);
	void storyBBBBBB(Ref *pSender);

	void storyB_1(Ref *pSender);
	void storyBB_1(Ref *pSender);
	void storyBBB_1(Ref *pSender);
	void storyBBBB_1(Ref *pSender);
	void storyBBBBB_1(Ref *pSender);

	void storyB_2(Ref *pSender);
	void storyBB_2(Ref *pSender);
	void storyBBB_2(Ref *pSender);
	
	void storyC(Ref *pSender);
	void storyCC(Ref *pSender);
	void storyCCC(Ref *pSender);
	void storyCCCC(Ref *pSender);
	void storyCCCCC(Ref *pSender);
	void storyCCCCCC(Ref *pSender);

	void storyC_1(Ref *pSender);
	void storyCC_1(Ref *pSender);
	void storyCCC_1(Ref *pSender);
	void storyCCCC_1(Ref *pSender);
	void storyCCCCC_1(Ref *pSender);
	
	void storyC_21(Ref *pSender);
	void storyC_2(Ref *pSender);
	void storyCA_2(Ref *pSender);
	void storyCC_2(Ref *pSender);
	void storyCCC_2(Ref *pSender);
	void storyCCCC_2(Ref *pSender);
	void storyCCCCC_2(Ref *pSender);
	
	void storyfin(Ref *pSender);
	/*virtual bool onTouchBegan(Touch* touch, Event* unused_event);*/
	//virtual void onTouchMoved(Touch *touch, Event *event);
	//virtual void onTouchEnded(Touch *touch, Event *event);
    CREATE_FUNC(SchoolStoryScene);
};

#endif 
