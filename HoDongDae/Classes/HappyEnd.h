#ifndef __HAPPY_SCENE_H__
#define __HAPPY_SCENE_H__

#include "cocos2d.h"
USING_NS_CC;

class HappyEnd : public cocos2d::Layer
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

	CREATE_FUNC(HappyEnd);
};

#endif 
