#ifndef __INSIDE_SCENE_H__
#define __INSIDE_SCENE_H__

#include "cocos2d.h"
//#include "extensions/cocos-ext.h"
//#include "KoreanUTF8.h"
USING_NS_CC;

class InsideScene : public cocos2d::Layer
{
private:
	Size visibleSize;
	Vec2 origin;
	bool open = false;
	bool openB = false;
	int day=1;
	int month = 3;
	int m_hak=999 ;
	int m_insung =999;
	int m_friendly =999;
	int m_jisik =999;
	int m_health =999;
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
	void finalspr(Ref *pSender);
	void exitspr(Ref *pSender);
	void alba(Ref *pSender);
	void play(Ref *pSender);
	void shop(Ref *pSender);
	void tell (Ref *pSender);
	void SetLabel(float delta);
	
    CREATE_FUNC(InsideScene);
};

#endif 
