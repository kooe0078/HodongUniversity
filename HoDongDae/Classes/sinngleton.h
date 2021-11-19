#pragma once

#include <iostream>
#include <string>
using namespace std;
class Singletons
{
private:
	Singletons() {};
	static Singletons* m_pInstance;

	//bool newspaper = false;
public:
	static Singletons* getInstance();
	static void releaseInstance();
	//여기 밑부터 내가 선언한 변수 위에는 건들이지 마셈
	/*int MasterHogam = 100;
	string Name;
	int LMJ_episodecheck = 1;
	int CHM_episodecheck = 1;
	int YJH_episodecheck = 1;
	int Cgallerycheck = 0;
	int Lgallerycheck = 0;
	int minigameclear = 0;
	int CHM = 0;
	int LMJ = 0;
	int YJH = 0;
	bool bgm = false;
	bool bgm1 = false;*/
	//////////////////////////////////////////////////
	// put additional variables here
	//사용 예시 변수
	//여러 cpp에서 사용할 변수 여기에 선언
	/*int Using=0;*/
	int day=1;
	int month = 3;

	int totalpoint = 0;
	int m_jisik = 0;
	int m_insung = 0;
	int m_hak = 0;
	int m_friendly = 0;
	int hodongscore = 0;
	int money = 0;
	//변동후 가격
	int samsung_1 = 50000;
	int apple_1 = 50000;
	int hanhwa_1 = 30000;
	int kia_1 = 30000;
	int lg_1 = 30000;

	int samsung_2 = 50000;
	int apple_2 = 50000;
	int hanhwa_2 = 30000;
	int kia_2 = 30000;
	int lg_2 = 30000;

	int samsung_3 = 50000;
	int apple_3 = 50000;
	int hanhwa_3 = 30000;
	int kia_3 = 30000;
	int lg_3 = 30000;
	//변동률
	float samsung_A = 0;
	float apple_A = 0;
	float hanhwa_A = 0;
	float kia_A = 0;
	float lg_A = 0;

	//몇주()주식
	int ju_S = 0;
	int ju_A = 0;
	int ju_H = 0;
	int ju_K = 0;
	int ju_L = 0;

	//각회사 넘버
	int num_S = 0;
	int num_A= 0;
	int num_H= 0;
	int num_K= 0;
	int num_L= 0;

	int newspaper = 0;
	int player_1 = 0;
	int player_2 = 0;
	int player_3 = 0;
	int player_4 = 0;
	int score_1 = 0;
	int score_2 = 0;
	int score_3 = 0;
	int score_4 = 0;
	int si = 0;
	int Qnum = 0; // 문제 수
	int Answer = 0; // 정답 수
	int CardOK = 0;
	int num_3 = 0;
	int num_4 = 0;
	int num_5 = 0;
	int backnum = 0;;
	int buy = 0;
	int currClock = 6;
	int currClock2 = 7;
	int currClock3 = 6;
	int aurrClock = 11;
	int Many = 0;
	int mironum = 0;
	int GameScore = 0;
	int bongnum = 0;
	int gonmonum = 0;
	int jik = 1;
	int moneyget = 0;
	int Danger = 0;
	//엔딩이후
	int DayGone = 0;
	int ranking[5] = { 0 };
	int cycle;
	int cycle1 = 0;
	int cycle2 = 0;
	int cycle3 = 0;
	int cycle4 = 0;
	int cycle5 = 0;
	//string Name="";
};