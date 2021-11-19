#ifndef __RANK_SCENE_H__
#define __RANK_SCENE_H__

#include "cocos2d.h"
USING_NS_CC;

class RankingScene : public cocos2d::Layer
{
private:
	int i;
public:
    static cocos2d::Scene* createScene();

    virtual bool init();

	void InitBackGround();
	void InitDay();
	void setDay();
	void talkLabel();
	void talk1(Ref * pSender);
	void talk2(Ref * pSender);
	void talk3(Ref * pSender);
	void talkend(Ref * pSender);


    CREATE_FUNC(RankingScene);
};

#endif 
