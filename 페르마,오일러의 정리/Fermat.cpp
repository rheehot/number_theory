#include<iostream>
#include"Fermat_Euler.h"
using namespace std;

//생성일 : 17.07.18 (화)
//목  적 : 페르마 정리를 기본적으로 보여주기 위해
 //구  현 : 페르마 정리 기본성질,소수판별,최대공약수
void FerMat_Main()
{
	cout << "페르마의 정리 프로그램입니다." << endl;
	int a_value = 0, exp = 0, fermat_moduler = 0, default_value = 1;
	cout << "페르마의 정리로 문제를 풀 밑과 지수와 mod M의 값을 입력해주세요." << endl;
	cout << "2^18=x(mod17)->2 18 17" << endl;
	cin >> a_value >> exp >> fermat_moduler;
	if (Fermat_is_Prime(fermat_moduler))
	{
		if (Fermat_Gcd(a_value, fermat_moduler) == 1)
		{
			fermat_value = Fermat(fermat_moduler);
			cout << a_value << "^" << fermat_value << "=" << default_value << "(mod " << fermat_moduler << ")" << endl;
			if (exp == -1)//역원구하는 기능
			{
				cout << a_value << "^" << exp << " = " << a_value << "^" << fermat_value - 1 << "(mod " << fermat_moduler << ")" << endl;
				cout << "역원 값 : " << Fermat_Pow(a_value, fermat_value - 1) << endl;
			}
			else if (exp > fermat_moduler) // 임의의 x값의 결과를 찾는 기능
			{
				cout << exp << " = " << fermat_value << "*" << exp / fermat_value << "+" << exp % fermat_value << endl;
				cout << a_value << "^" << fermat_value << "= 1 (mod " << fermat_moduler << ")" << endl;
				cout << a_value << "^" << exp % fermat_value << " 을 계산합니다." << endl;
				cout << "나머지 값 : " << Fermat_Pow(a_value, exp % fermat_value) % fermat_moduler << endl;
			}
			else if (exp > 0)// 임의의 x값인데 노가다하면 되는 기능!
			{
				cout << a_value << "^" << exp << "%" << fermat_moduler << endl;
				cout << "식을 계산한 결과 : " << Fermat_Pow(a_value, exp) % fermat_moduler << endl;
			}
		}
		else
		{
			cout << "a의 값과 mod M의 값이 최대공약수가 1이 아닙니다." << endl;
		}
	}
	else
	{
		cout << "페르마의 정리는 소수일 때만 실행 가능합니다." << endl;
	}
}


//생성일 : 17.07.18 (화)
//목  적 : 페르마의 성질은 기본적으로 소수일때만 작동하기 때문이다.
int Fermat(int mod)
{
	if (Fermat_is_Prime(mod))
	{
		return mod - 1;
	}
	else
	{
		cout << "페르마의 정리는 소수일 때만 가능합니다." << endl;
		return 0;
	}
}


//생성일 : 17.07.18 (화)
//목  적 : 소수판별함수
bool Fermat_is_Prime(int num)
{
	for (int i = 2; i*i <= num; i++)
	{
		if (num%i == 0)
		{
			return false;
		}
	}
	return true;
}


//생성일 : 17.07.18 (화)
//목  적 : 유클리드 알고리즘을 이용하여 최대공약수를 구하기 위하여
int Fermat_Gcd(int a_value, int fermat_moduler)
{
	return fermat_moduler ? Fermat_Gcd(fermat_moduler, a_value%fermat_moduler) : a_value;
}

//생성일 : 17.07.18 (화)
//목  적 : 페르마에서 사용하는 제곱연산 함수
//기  능 : 매우 큰수에서는 모듈러 값을 이용하여 나누어 준다.
unsigned __int64 Fermat_Pow(int a_value, int exp)
{
	unsigned __int64 pow_result = 1;
	if (exp == 0) // 1반환
	{
		return pow_result;
	}
	else if (exp>0) // 결과값
	{
		for (int i = 1; i <= exp; i++)
		{
			if (pow_result > (fermat_value + 1))
			{
				pow_result %= (fermat_value + 1);
				pow_result *= a_value;
			}
			else
			{
				pow_result *= a_value;
			}
		}
		return pow_result;
	}
	else // 역원은 따로 구현예정 그외의 마이너스값계산불가..
	{
		cout << "잘못된 값입니다." << endl;
		return 0;
	}
}