#include<iostream>
#include"hapdong.h"
using namespace std;

void First_Hapdong_Main()
{
	cout << "일차 합동식 프로그램 입니다." << endl;
	int a = 0, b = 0, m = 0, result = 0;
	cout << "ax = b (mod m)꼴에 맞춰 입력해주세요." << endl;
	cin >> a >> b >> m;
	result = First_HapDong(a, b, m);
	for (int i = 0; i<First_Hapdong_GCD(First_Hapdong_GCD(a, b), m); i++)
	{
		if (result == 0)
			break;
		cout << i + 1 << ") 일차방정식의 해 X = " << result + m / First_Hapdong_GCD(First_Hapdong_GCD(a, b), m)*i << endl;
	}
}

// 생성일 : 17.07.12 (수)
// 목  적 :  합동식을 구하기 위해
// 기  능 :  합동식의 해를 구해준다.
int First_HapDong(int a, int b, int m)
{
	int x_result = 1;
	int gcd1 = First_Hapdong_GCD(a, b), gcd2 = First_Hapdong_GCD(gcd1, m);
	if (gcd2 != 1)
	{
		a = a / gcd2; b = b / gcd2; m = m / gcd2;
		while (x_result<m)
		{
			if (a*x_result%m == b)
			{
				return x_result;
			}
			x_result++;
		}
	}
	else
	{
		while (x_result<m)
		{
			if (a*x_result%m == b)
			{
				return x_result;
			}
			x_result++;
		}
	}
	cout << "해가 없습니다." << endl;
	return 0;
}

//목 적 : 최대공약수를 구하기 위한 함수
int First_Hapdong_GCD(int a, int b)
{
	return b ? First_Hapdong_GCD(b, a%b) : a;
}