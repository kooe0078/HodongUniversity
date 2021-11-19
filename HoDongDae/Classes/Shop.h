#ifndef __MAIN_SCENE_HZ__
#define __MAIN_SCENE_HZ__

#include "cocos2d.h"
USING_NS_CC;

class Shop : public cocos2d::Layer
{
private:
	
public:
    static cocos2d::Scene* createScene();

    virtual bool init();

	void initBG();
	void MenuLabel();
	void Menuitem();
	virtual void update(float delta) override;
	void Pur1(Ref *pSender);
	void Pur2(Ref *pSender);
	void Pur3(Ref *pSender);
	void Pur4(Ref *pSender);
	void Pur5(Ref *pSender);
	void Pur6(Ref *pSender);
	void cancelbuy(Ref *pSender);
	void Next();
	void Go(Ref *pSender);

	void Exit();
	void Back(Ref *pSender);
	
    CREATE_FUNC(Shop);
};

#endif 
