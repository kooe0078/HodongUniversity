#ifndef __MAIN_SCENE_H__
#define __MAIN_SCENE_H__

#include "cocos2d.h"
//#include "extensions/cocos-ext.h"
//#include "KoreanUTF8.h"
USING_NS_CC;

class MainScene : public cocos2d::Layer
{
private:
	Size visibleSize;
	Vec2 origin;
	bool open = false;
	bool openB = false;
public:

    static cocos2d::Scene* createScene();
	cocos2d::Vector<cocos2d::Sprite*> mpData;

    virtual bool init();
	void InitMenu();
	void InitBackGround();
	void menuspr(Ref * pSender);
	void systemspr(Ref * pSender);
	void soundoff(Ref * pSender);
	void soundon(Ref * pSender);
	void actionspr(Ref *pSender);
	void InitLabel();
	void quiz(Ref *pSender);
	void infospr(Ref *pSende);
	void cancelcon(Ref *pSender);
	void planspr(Ref *pSender);
	void finalspr(Ref *pSender);
	void exitspr(Ref *pSender);
	void servicespr(Ref *pSender);
	void read(Ref *pSender);
	void bookopen(Ref *pSender);
	void bookcloseA(Ref *pSender);
	void bookcloseB(Ref *pSender);
	void bookcloseC(Ref *pSender);
	void nextday(Ref *pSender);
	void trash(Ref *pSender);
\
	void tell(Ref *pSender);
	void gonmoA(Ref *pSender);
	void gonmoAjoin(Ref *pSender);
	void gonmoB(Ref *pSender);
	void gonmoBjoin(Ref *pSender);
	void gonmoC(Ref *pSender);
	void gonmoCjoin(Ref *pSender);
	void SetLabel(float delta);


	//void ShowChar(float f);
    CREATE_FUNC(MainScene);
};

#endif 
