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

	void initBG(); // ���
	void Card(); // ī��
	void Minion(); // ��� �ʵ� �ϼ���

	void Check_1(Ref *pSender); // ī�� ���
	void Play_1(Ref *pSender); // ī�� ���� 1
	void Play_2(Ref *pSender); // ī�� ���� 2
	void Play_3(Ref *pSender); // ī�� ���� 3
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
