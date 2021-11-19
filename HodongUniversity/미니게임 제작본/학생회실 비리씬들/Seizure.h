#ifndef __MAIN_SCENE_H__
#define __MAIN_SCENE_H__

#include "cocos2d.h"
USING_NS_CC;

class Seizure : public cocos2d::Layer
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
	
    CREATE_FUNC(Seizure);
};

#endif 
