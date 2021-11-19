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
	int Qnum = 0; // ���� ��
	int Answer = 0; // ���� ��

};