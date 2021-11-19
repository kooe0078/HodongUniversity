#ifndef __INVEST_SCENE_H__
#define __INVEST_SCENE_H__

#include "cocos2d.h"
USING_NS_CC;

class InvestScene : public cocos2d::Layer
{
private:
	Size visibleSize;
	Vec2 origin;
	bool open = false;
	

public:
    static cocos2d::Scene* createScene();

    virtual bool init();
	virtual void update(float delta) override;

	void InitBackGround();
	void InitLabel();
	void InitMenu();
	void newplay(Ref *pSender);
	void system(Ref *pSender);
	void buy_S(Ref *pSender);
	void buy_A(Ref *pSender);
	void buy_H(Ref *pSender);
	void buy_K(Ref *pSender);
	void buy_L(Ref *pSender);
	void sell_S(Ref *pSender);
	void sell_A(Ref *pSender);
	void sell_H(Ref *pSender);
	void sell_K(Ref *pSender);
	void sell_L(Ref *pSender);
	void buy_1(Ref *pSender);
	void buy_2(Ref *pSender);
	void buy_3(Ref *pSender);
	void buy_4(Ref *pSender);
	void buy_5(Ref *pSender);
	void buy_6(Ref *pSender);
	void buy_7(Ref *pSender);
	void buy_8(Ref *pSender);
	void buy_9(Ref *pSender);
	void buy_10(Ref *pSender);
	void sell_1(Ref *pSender);
	void sell_2(Ref *pSender);
	void sell_3(Ref *pSender);
	void sell_4(Ref *pSender);
	void sell_5(Ref *pSender);
	void sell_6(Ref *pSender);
	void sell_7(Ref *pSender);
	void sell_8(Ref *pSender);
	void sell_9(Ref *pSender);
	void sell_10(Ref *pSender);
	void cancelbuy(Ref *pSender);
	void cancel(Ref *pSender);

	/*virtual bool onTouchBegan(Touch* touch, Event* unused_event);*/
	//virtual void onTouchMoved(Touch *touch, Event *event);
	//virtual void onTouchEnded(Touch *touch, Event *event);
    CREATE_FUNC(InvestScene);
};

#endif 
