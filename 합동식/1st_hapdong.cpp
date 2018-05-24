#include<iostream>
#include"hapdong.h"
using namespace std;

void First_Hapdong_Main()
{
	cout << "���� �յ��� ���α׷� �Դϴ�." << endl;
	int a = 0, b = 0, m = 0, result = 0;
	cout << "ax = b (mod m)�ÿ� ���� �Է����ּ���." << endl;
	cin >> a >> b >> m;
	result = First_HapDong(a, b, m);
	for (int i = 0; i<First_Hapdong_GCD(First_Hapdong_GCD(a, b), m); i++)
	{
		if (result == 0)
			break;
		cout << i + 1 << ") ������������ �� X = " << result + m / First_Hapdong_GCD(First_Hapdong_GCD(a, b), m)*i << endl;
	}
}

// ������ : 17.07.12 (��)
// ��  �� :  �յ����� ���ϱ� ����
// ��  �� :  �յ����� �ظ� �����ش�.
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
	cout << "�ذ� �����ϴ�." << endl;
	return 0;
}

//�� �� : �ִ������� ���ϱ� ���� �Լ�
int First_Hapdong_GCD(int a, int b)
{
	return b ? First_Hapdong_GCD(b, a%b) : a;
}