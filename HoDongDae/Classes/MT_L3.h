#ifndef __MAIN_SCENE_HLK__
#define __MAIN_SCENE_HLK__

#include "cocos2d.h"
USING_NS_CC;

class MT_L3 : public cocos2d::Layer
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

	CREATE_FUNC(MT_L3);
};

#endif 
