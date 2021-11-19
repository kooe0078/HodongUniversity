#ifndef __MAIN_SCENE2_H__
#define __MAIN_SCENE2_H__

#include "cocos2d.h"
USING_NS_CC;

class Shop2 : public cocos2d::Layer
{
private:
	
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
	void InitLabel();
	void initBG();
	void MenuLabel();
	void Menuitem();
	virtual void update(float delta);
	void Pur7(Ref *pSender);
	void Pur8(Ref *pSender);
	void Pur9(Ref *pSender);
	void Pur10(Ref *pSender);
	void Pur11(Ref *pSender);
	void Pur12(Ref *pSender);
	void cancelbuy_2(Ref *pSender);
	void Next();
	void Go(Ref *pSender);

	void Exit();
	void Back(Ref *pSender);
	
    CREATE_FUNC(Shop2);
};

#endif 
