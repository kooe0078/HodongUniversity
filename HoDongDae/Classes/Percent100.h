#ifndef __Percent100_SCENE_H__
#define __Percent100_SCENE_H__

#include "cocos2d.h"
USING_NS_CC;

class Percent100 : public cocos2d::Layer
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

    CREATE_FUNC(Percent100);
};

#endif 
