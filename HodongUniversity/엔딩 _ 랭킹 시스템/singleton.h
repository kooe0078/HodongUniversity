#pragma once

#include <iostream>
#include <string>
using namespace std;
class Singletons
{
private:
	Singletons() {};
	static Singletons* m_pInstance;

public:
	static Singletons* getInstance();
	static void releaseInstance();
	//여기 밑부터 내가 선언한 변수 위에는 건들이지 마셈
	
	//////////////////////////////////////////////////
	// put additional variables here
	//사용 예시 변수
	//여러 cpp에서 사용할 변수 여기에 선언
	int DayGone = 0;
	int ranking[5] = { 0 };
	int cycle;
	int cycle1 = 0;
	int cycle2 = 0;
	int cycle3 = 0;
	int cycle4 = 0;
	int cycle5 = 0;
};