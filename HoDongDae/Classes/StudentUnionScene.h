#ifndef __STUDENTUNION_SCENE_H__
#define __STUDENTUNION_SCENE_H__

#include "cocos2d.h"
//#include "extensions/cocos-ext.h"
//#include "KoreanUTF8.h"
USING_NS_CC;

class StudentUnionScene : public cocos2d::Layer
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
	void infospr(Ref *pSende);
	void cancelcon(Ref *pSender);
	void planspr(Ref *pSender);
	void jangbu(Ref *pSender);
	void hakhue(Ref *pSender);
	void biza(Ref *pSender);
	void sibal(Ref *pSender);
	void finalspr(Ref *pSender);
	void exitspr(Ref *pSender);
	void GoHome(Ref *pSender);
	void servicespr(Ref *pSender);
	void SetLabel(float delta);
	
    CREATE_FUNC(StudentUnionScene);
};

#endif 
