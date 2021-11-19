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

	void initBG(); // ���
	void initTopMenuLabel(); // ��� ��
	void setLabelQuiz(); // ��� ������
	void initLabelQ(); // ����
	void initMenuA(); // �� ������ ��
	void CheckA_1(Ref *pSender); // 1�� �� Ȯ��
	void CheckA_2(Ref *pSender); // 2�� �� Ȯ��
	void CheckA_3(Ref *pSender); // 3�� �� Ȯ��
	void CheckA_4(Ref *pSender); // 4�� �� Ȯ��

    CREATE_FUNC(MainScene);
};

#endif 
