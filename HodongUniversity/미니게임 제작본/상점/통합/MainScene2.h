#ifndef __MAIN_SCENE2_H__
#define __MAIN_SCENE2_H__

#include "cocos2d.h"
USING_NS_CC;

class MainScene2 : public cocos2d::Layer
{
private:
	
public:
    static cocos2d::Scene* createScene();

    virtual bool init();

	void initBG();
	void MenuLabel();
	void Menuitem();

	void Pur1(Ref *pSender);
	void Pur2(Ref *pSender);
	void Pur3(Ref *pSender);
	void Pur4(Ref *pSender);
	void Pur5(Ref *pSender);
	void Pur6(Ref *pSender);

	void Next();
	void Go(Ref *pSender);

	void Exit();
	void Back(Ref *pSender);
	
    CREATE_FUNC(MainScene2);
};

#endif 
