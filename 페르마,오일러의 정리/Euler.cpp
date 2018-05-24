#include<iostream>
#include"Fermat_Euler.h"
using namespace std;
static unsigned __int64 Euler_Prime[1000] = { 0 }; // 소인수분해후 저장장소

void Euler_Main()
{
	int a_value = 0, exp_value = 0, euler_moduler = 0;
	cout << "오일러의 정리 프로그램 입니다." << endl << "밑 지수 모듈러값을 차례대로 입력하세요." << endl;
	cout << "지수의 값을 모르면 0을 입력해 주세요." << endl;
	cin >> a_value >> exp_value >> euler_moduler;
	int euler_temp = Euler(euler_moduler);
	if (exp_value == 0)
	{
		cout << "지수 : " << euler_temp << endl;
	}
	else
	{
		if (Euler_GCD(a_value, euler_moduler) == 1)
		{
			cout << "Euler : " << euler_temp << endl;
			cout << a_value << "^" << euler_temp << " = " << 1 << "(mod " << euler_moduler << ")" << endl;
			cout << exp_value << " = " << euler_temp << "*" << exp_value / euler_temp << "+" << exp_value % euler_temp << endl;
			cout << "Remain Result : " << Result_Euler(a_value, exp_value, euler_temp, euler_moduler) << endl;
		}
		else if (Euler_GCD(a_value, euler_moduler) != 1 && Euler_GCD(Euler_GCD(a_value, euler_moduler), exp_value) != 1)
		{
			cout << "세 수의 최대공약수 : " << Euler_GCD(Euler_GCD(a_value, euler_moduler), exp_value) << endl;
			a_value = a_value / Euler_GCD(Euler_GCD(a_value, euler_moduler), exp_value);
			exp_value = exp_value / Euler_GCD(Euler_GCD(a_value, euler_moduler), exp_value);
			euler_moduler = euler_moduler / Euler_GCD(Euler_GCD(a_value, euler_moduler), exp_value);
			cout << "Euler : " << euler_temp << endl;
			cout << a_value << "^" << euler_temp << " = " << 1 << "(mod " << euler_moduler << ")" << endl;
			cout << exp_value << " = " << euler_temp << "*" << exp_value / euler_temp << "+" << exp_value % euler_temp << endl;
			cout << "Remain Result : " << Result_Euler(a_value, exp_value, euler_temp, euler_moduler) << endl;
		}
		else
		{
			cout << "밑의 값과 모듈러값이 1이 아니면 수행할 수 없습니다. " << endl;
		}
	}
}

// 생성일 : 17.07.18(화)
// 목 적 : 오일러값을 이용하여 식의 나머지 값을 계산하는 함수
//			초기에 입력한 식의 나머지값을 계산한다.
int Result_Euler(int a_value, int exp_value, int Euler_temp, int euler_moduler)
{
	unsigned __int64 result_temp = 1;
	if (exp_value > Euler_temp)
	{
		for (int i = 0; i < exp_value%Euler_temp; i++)
		{
			if (result_temp > 10000000)
			{
				result_temp %= euler_moduler;
				result_temp *= a_value;
			}
			else
			{
				result_temp *= a_value;
			}
		}
		return result_temp%euler_moduler;
	}
	else
	{
		for (int i = 0; i < exp_value; i++)
		{
			if (result_temp > 10000000)
			{
				result_temp %= euler_moduler;
				result_temp *= a_value;
			}
			else
			{
				result_temp *= a_value;
			}
		}
		return result_temp%euler_moduler;
	}
}

// 생성일 : 17.06.29(목)
// 목  적 : bool 함수를 이용하여 소수 판별후 true, false 를 판단하게 하는 함수 , + 소인수 분해를 위해 값을 저장하는 기능
bool Euler_IsPrime(unsigned __int64 euler_moduler)
{
	int z = 0, k = 0, i = 2, j = 0;
	int count = 1;
	for (j; j <= 10; j++)
	{
		for (i; i*i < euler_moduler; i++) //소수판별
		{
			if (euler_moduler%i == 0)
			{
				Euler_Prime[z] = i;
				if (Euler_Prime[k - 2] == Euler_Prime[k]) // 현재의 값과 과거의 값이 같다면 카운트업 하고 초기화
				{
					Euler_Prime[z] = i;
					Euler_Prime[k - 1] += count;
					Euler_Prime[k] = 0;
					euler_moduler /= i;
					break;
				}
				else  // 그냥 진행 
				{
					k += 2;
					Euler_Prime[z] = i;
					euler_moduler /= i;
					Euler_Prime[z + 1] += count;
					z += 2;
					break;
				}
			}
		}
	}
	if (Euler_Prime[1] == 0 && Euler_Prime[2] == 0) // 소수이면 나누어 지는게 없으므로 입력값이 소수 
	{
		Euler_Prime[0] = euler_moduler;
		Euler_Prime[1] = count;
		return true;
	}
	else if (euler_moduler != 1) // 나누어지고 남은것 마지막에 추가
	{
		if (Euler_Prime[z - 2] == euler_moduler)
		{
			Euler_Prime[z - 1] += count;
		}
		else
		{
			Euler_Prime[z] = euler_moduler;
			Euler_Prime[z + 1] += count;
		}
		return false;
	}
	else // 모든 과정을 잘 모르겟지만 나머지 과정에 대해서 거짓이라고 출력해주기 위해
	{
		return false;
	}
}

// 생성일 : 17.06.30 (금) 
// 목  적 : 소수 판별 후 오일러 값을 출력하는 함수, (float)로 각각 형변환을 하면 분수처럼 사용할 수 있음을 알게 됨
int  Euler(int euler_moduler)
{
	int s = 0;
	double s_temp = euler_moduler;
	if (Euler_IsPrime(euler_moduler)) // bool함수는 if문의 조건에도 넣을수 있다.
	{
		cout << "소수입니다." << endl;
		return (Euler_Prime[0] - 1);
	}
	else
	{
		if (Euler_Prime[4] == 0 && Euler_Prime[1] == 1 && Euler_Prime[3] == 1) //p*q꼴
		{
			cout << "p*q꼴 입니다." << endl;
			cout << Euler_Prime[0] << " * " << Euler_Prime[2] << endl;
			return (Euler_Prime[0] - 1)*(Euler_Prime[2] - 1);
		}
		else if (Euler_Prime[1] != 0 && Euler_Prime[2] == 0)// p^k 꼴
		{
			cout << " p^k 꼴 입니다." << endl;
			cout << Euler_Prime[0] << "^" << Euler_Prime[1] << " - " << Euler_Prime[0] << "^" << Euler_Prime[1] - 1 << endl;
			return (pow(Euler_Prime[0], Euler_Prime[1]) - pow(Euler_Prime[0], Euler_Prime[1] - 1));
		}
		else//p^k * p1^k1 * p2^k2 .... 꼴 
		{
			cout << "p^k * p1^k1 * p2^k2 .... 꼴입니다." << endl;
			cout << euler_moduler << "*";
			while (Euler_Prime[s] != 0)
			{
				if (Euler_Prime[s + 2] == 0)
				{
					s_temp *= (double)((Euler_Prime[s] - 1) / (double)Euler_Prime[s]); // 분수꼴 저장을 하기위한 형변환 실행
					cout << (Euler_Prime[s] - 1) << "/" << Euler_Prime[s] << endl;
				}
				else
				{
					s_temp *= (double)((Euler_Prime[s] - 1) / (double)Euler_Prime[s]); // 분수꼴 저장을 하기위한 형변환 실행
					cout << (Euler_Prime[s] - 1) << "/" << Euler_Prime[s] << "*";
				}
				s += 2;
			}
			return s_temp;
		}
	}
}

//생성일 : 17.07.18
//목  적 : 최대공약수가 1일때만 오일러의 정리가 실행될수 있으므로 비교값을 위하여 유클리드 알고리즘을 이용하여 최대공약수를 구하기 위함
int Euler_GCD(int a_value, int euler_moduler)
{
	return euler_moduler ? Euler_GCD(euler_moduler, a_value%euler_moduler) : a_value;
}