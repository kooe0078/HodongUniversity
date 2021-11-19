#ifndef __MAIN_SCENE_H__
#define __MAIN_SCENE_H__

#include "cocos2d.h"
USING_NS_CC;

class MainScene : public cocos2d::Layer
{
private:
	Sprite* Quiz[12];
	int i;
	#define TAG_LABEL_QUIZ 0
public:
    static cocos2d::Scene* createScene();
	
    virtual bool init();

	void initBG(); // 배경
	void initTopMenuLabel(); // 상단 라벨
	void setLabelQuiz(); // 상단 문제수
	void initLabelQ(); // 문제
	void initMenuA(); // 답 눌렀을 때
	void CheckA_1(Ref *pSender); // 1번 답 확인
	void CheckA_2(Ref *pSender); // 2번 답 확인
	void CheckA_3(Ref *pSender); // 3번 답 확인
	void CheckA_4(Ref *pSender); // 4번 답 확인

    CREATE_FUNC(MainScene);
};

#endif 
