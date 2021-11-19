#ifndef __NEWS_SCENE_H__
#define __NEWS_SCENE_H__

#include "cocos2d.h"
USING_NS_CC;

class NewsScene : public cocos2d::Layer
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
	void Gojudgment(Ref *pSender);
	void Gojudgment_2(Ref *pSender);
	void system(Ref *pSender);
	void fin(Ref *pSender);
	void replayspr(Ref *pSender);

	/*virtual bool onTouchBegan(Touch* touch, Event* unused_event);*/
	//virtual void onTouchMoved(Touch *touch, Event *event);
	//virtual void onTouchEnded(Touch *touch, Event *event);
    CREATE_FUNC(NewsScene);
};

#endif 
