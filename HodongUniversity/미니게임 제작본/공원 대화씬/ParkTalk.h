#ifndef __ParkTalk_SCENE_H__
#define __ParkTalk_SCENE_H__

#include "cocos2d.h"
USING_NS_CC;

class ParkTalk : public cocos2d::Layer
{
private:
	Size visibleSize;
	Vec2 origin;
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
	
	void InitBackGround();
	void InitMenu();
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
	
	void storyB(Ref *pSender);
	void storyBB(Ref *pSender);
	void storyBBB(Ref *pSender);
	void storyBBBB(Ref *pSender);
	void storyBBBBB(Ref *pSender);
	void storyBBBBBB(Ref *pSender);
	void storyBBBBBBB(Ref *pSender);

	void storyB_1(Ref *pSender);
	void storyBB_1(Ref *pSender);
	void storyBBB_1(Ref *pSender);
	void storyBBBB_1(Ref *pSender);
	void storyBBBBB_1(Ref *pSender);
	void storyBBBBB_2(Ref *pSender);
	void storyBBBBB_3(Ref *pSender);

	void storyC(Ref *pSender);
	void storyC1(Ref *pSender);
	void storyC2(Ref *pSender);
	void storyC3(Ref *pSender);
	void storyC4(Ref *pSender);
	void storyC5(Ref *pSender);
	void storyC6(Ref *pSender);

	void storyC_1(Ref *pSender);
	void storyC1_1(Ref *pSender);
	void storyC2_1(Ref *pSender);
	void storyC3_1(Ref *pSender);
	void storyC4_1(Ref *pSender);
	void storyC5_1(Ref *pSender);

	void storyD(Ref *pSender);
	void storyD1(Ref *pSender);
	void storyD2(Ref *pSender);
	
	void storyfin(Ref *pSender);

    CREATE_FUNC(ParkTalk);
};

#endif 
