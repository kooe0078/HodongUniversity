#ifndef __QUIZEND_SCENE_H__
#define __QUIZEND_SCENE_H__

#include "cocos2d.h"
USING_NS_CC;

class QuizEndScene : public cocos2d::Layer
{
private:

public:
    static cocos2d::Scene* createScene();

    virtual bool init();
	virtual void update(float delta) override;

	void InitBackGround();
	void initLabel();
	void setAnswer();
	void Menuitem();
	void Check_1(Ref *pSender);
	void Check_0(Ref *pSender);
	void storyAspr(Ref *pSender);
    CREATE_FUNC(QuizEndScene);
};

#endif 
