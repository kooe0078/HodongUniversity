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
	//���� �غ��� ���� ������ ���� ������ �ǵ����� ����
	
	//////////////////////////////////////////////////
	// put additional variables here
	//��� ���� ����
	//���� cpp���� ����� ���� ���⿡ ����
	int DayGone = 0;
	int ranking[5] = { 0 };
	int cycle;
	int cycle1 = 0;
	int cycle2 = 0;
	int cycle3 = 0;
	int cycle4 = 0;
	int cycle5 = 0;
};