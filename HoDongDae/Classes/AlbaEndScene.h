#ifndef __INTRO_SCENE_H__
#define __INTRO_SCENE_H__

#include "cocos2d.h"
USING_NS_CC;

class AlbaEndScene : public cocos2d::Layer
{
private:
	Size visibleSize;
	Vec2 origin;
public:
    static cocos2d::Scene* createScene();

	virtual bool init();
	virtual void update(float delta) override;

	void InitBackGround();
	void initLabel();
	void setAnswer();
	void Menuitem();
	void Check_1(Ref *pSender);
	void Check_2(Ref *pSender);
	void storyAspr(Ref *pSender);
    CREATE_FUNC(AlbaEndScene);
};

#endif 
