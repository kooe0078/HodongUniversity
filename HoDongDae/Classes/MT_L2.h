#ifndef __MAIN_SCENE_HLJ__
#define __MAIN_SCENE_HLJ__

#include "cocos2d.h"
USING_NS_CC;

class MT_L2 : public cocos2d::Layer
{
private:

public:
	static cocos2d::Scene* createScene();


	virtual bool init();

	void InitBackGround();
	void InitMenu();

	void story1(Ref* pSender);
	void story1_2(Ref* pSender);
	void story1_3(Ref* pSender);
	void story1_4(Ref* pSender);
	void story1_5(Ref* pSender);

	CREATE_FUNC(MT_L2);
};

#endif 