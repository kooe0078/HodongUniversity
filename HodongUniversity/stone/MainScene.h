#ifndef __MAIN_SCENE_H__
#define __MAIN_SCENE_H__

#include "cocos2d.h"
USING_NS_CC;

class MainScene : public cocos2d::Layer
{
private:
	int i;
public:
    static cocos2d::Scene* createScene();
	
    virtual bool init();

	void initBG(); // 배경
	void Card(); // 카드
	void Minion(); // 상대 필드 하수인

	void Check_1(Ref *pSender); // 카드 사용
	void Play_1(Ref *pSender); // 카드 선택 1
	void Play_2(Ref *pSender); // 카드 선택 2
	void Play_3(Ref *pSender); // 카드 선택 3
	void Case_1(Ref *pSender);
	void Case_2(Ref *pSender);
	void Case_3(Ref *pSender);
	void Hit_1(Ref *pSender);
	void Hit_2(Ref *pSender);
	void Hit_3(Ref *pSender);
	void Kill_1(Ref *pSender);

    CREATE_FUNC(MainScene);
};

#endif 
