#include <iostream>
#include"hapdong.h"
using namespace std;

void Bar_Cod_Main() 
{
	cout << "�����յ����� ���� ���ڵ� ���α׷��Դϴ�." << endl;
	unsigned __int64 bar = 0;
	cout << "���ڵ� 13�ڸ� �Է��ϼ���" << endl;
	cin >> bar;
	if (bar >= 1000000000000 && bar < 10000000000000) 
	{
		Bar_Code(bar);
	}
	else 
	{
		cout << "���ڵ� ���� �Է��� �߸��ϼ̽��ϴ�" << endl;
	}
}

void Bar_Code(unsigned __int64 bar_code) 
{
	unsigned __int64 bar = 10000000000000;
	int sum1 = 0;
	int sum2 = 0;
	int count = 1;
	while (1) {
		if (count % 2 == 1) 
		{
			sum1 = sum1 + bar_code%bar / (bar / 10);
		}
		else
		{
			sum2 = sum2 + bar_code%bar / (bar / 10);
		}
		count++;
		bar = bar / 10;
		if (count == 13)
		{
			break;
		}
	}
	sum2 = sum2 * 3;
	bar_code = bar_code % 10;
	if (bar_code == (240 - (sum1 + sum2)) % 10) 
	{
		cout << "�ùٸ� ���ڵ��Դϴ�" << endl;
	}
	else 
	{
		cout << "�ùٸ������� ���ڵ��Դϴ�" << endl;
	}
}