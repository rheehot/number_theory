#include <iostream>
#include"hapdong.h"
using namespace std;

void Bar_Cod_Main() 
{
	cout << "일차합동식의 응용 바코드 프로그램입니다." << endl;
	unsigned __int64 bar = 0;
	cout << "바코드 13자리 입력하세요" << endl;
	cin >> bar;
	if (bar >= 1000000000000 && bar < 10000000000000) 
	{
		Bar_Code(bar);
	}
	else 
	{
		cout << "바코드 숫자 입력을 잘못하셨습니다" << endl;
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
		cout << "올바른 바코드입니다" << endl;
	}
	else 
	{
		cout << "올바르지않은 바코드입니다" << endl;
	}
}