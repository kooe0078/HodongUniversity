#ifndef __INTRO_SCENE_H__
#define __INTRO_SCENE_H__

#include "cocos2d.h"
USING_NS_CC;

class MiroEndScene3 : public cocos2d::Layer
{
private:

public:
    static cocos2d::Scene* createScene();

    virtual bool init();
	void storyAspr(Ref *pSender);
	void InitBackGround();
	void initLabel();
	void Setting();
	void Menuitem();
	void Check(Ref *pSender);
	void Check_1(Ref *pSender);
    CREATE_FUNC(MiroEndScene3);
};

#endif 
