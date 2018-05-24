#include<iostream> // stdio.h ,  ** C의 문제는 scanf_s 에 큰 값을 집어 넣지 못한다.
#include "Primitive_Root.h"

using namespace std;
#define MAX_SIZE 100000
static unsigned __int64 O_Prime[MAX_SIZE] = { 0 }; //소인수 분해된 소수들의 저장공간
static unsigned __int64 O_Divisor[MAX_SIZE] = { 0 }; // 오일러 값의 약수들의 저장공간


void Order_Main()
{
	cout << "위수 구하는 프로그램입니다" << endl;
	cout << "입력하신 모듈러 값의 위수를 출력해줍니다." << endl;
	unsigned long long int number=0;
	cout << "법M , 모듈러 값을 입력하세요" << endl;
	cin >> number;
	if (number == 1)
	{
		cout << "1은 소수도 합성수도 아닙니다. 위수를 구할 수 없습니다." << endl;
		cout << "프로그램을 종료합니다." << endl;
	}
	else if (number < 1)
	{
		cout << "음수는 정수론에서 계산하지 않습니다." << endl;
		cout << "프로그램을 종료합니다." << endl;
	}
	else
	{
		unsigned long long int temp = Euler(number);
		Show_O_Prime();
		cout << "Euler : " << temp << endl;
		Prime_Divisor(temp);
		cout << "Euler's Divisor : ";
		Show_O_Divisor();
		Order(number);
		for (int clear = 0; clear < MAX_SIZE; clear++)
		{
			O_Prime[clear] = 0;
			O_Divisor[clear] = 0;
		}
	}
}


// 생성일 : 17.07.02(일)
// 목  적 : 소수 출력 함수
void Show_O_Prime()
{
	int i = 0;
	while (O_Prime[i] != 0)
	{
		if (i % 2 == 0)
		{
			cout << O_Prime[i] << '^';
			i++;
		}
		else
		{
			if (O_Prime[i + 1] == 0)
			{
				cout << O_Prime[i] << " -> ";
				break;
			}
			else
			{
				cout << O_Prime[i] << '*';
				i++;
			}
		}
	}
	if (O_Prime[2] == 0 && O_Prime[1] == 1) {
			cout << "소수입니다.";
	}
	else
	{
		cout << "합성수입니다.";
	}
	cout << endl;
}



// 생성일 : 17.06.29(목)
// 목  적 : bool 함수를 이용하여 소수 판별후 true, false 를 판단하게 하는 함수 , + 소인수 분해를 위해 값을 저장하는 기능
bool O_IsPrime(unsigned __int64 num)
{
	int z = 0, k = 0, i = 2, j = 0;
	int count = 1;
	for (j; j <= 1000; j++)
	{
		for (i; i*i <= num; i++) //소수판별
		{
			if (num%i == 0)
			{
				O_Prime[z] = i;
				if (O_Prime[k - 2] == O_Prime[k]) // 현재의 값과 과거의 값이 같다면 카운트업 하고 초기화
				{
					O_Prime[z] = i;
					O_Prime[k - 1] += count;
					O_Prime[k] = 0;
					num /= i;
					break;
				}
				else  // 그냥 진행 
				{
					k += 2;
					O_Prime[z] = i;
					num /= i;
					O_Prime[z + 1] += count;
					z += 2;
					break;
				}
			}
		}
	}
	if (O_Prime[1] == 0 && O_Prime[2] == 0) // 소수이면 나누어 지는게 없으므로 입력값이 소수 
	{
		O_Prime[0] = num;
		O_Prime[1] = count;
		return true;
	}
	else if (num != 1) // 나누어지고 남은것 마지막에 추가
	{
		if (O_Prime[z - 2] == num)
		{
			O_Prime[z - 1] += count;
		}
		else
		{
			O_Prime[z] = num;
			O_Prime[z + 1] += count;
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
unsigned __int64  Euler(unsigned __int64 num)
{
	int s = 0;
	double s_temp = num;
	if (O_IsPrime(num)) // bool함수는 if문의 조건에도 넣을수 있다.
	{
		return (O_Prime[0] - 1);
	}
	else
	{
		while (1)
		{
			if (O_Prime[4] == 0 && O_Prime[1] == 1 && O_Prime[3] == 1) //p*q꼴
			{
				return (O_Prime[0] - 1)*(O_Prime[2] - 1);
			}
			else if (O_Prime[1] != 0 && O_Prime[2] == 0)// p^k 꼴
			{
				return (Order_Pow(O_Prime[0], O_Prime[1],num) - Order_Pow(O_Prime[0], O_Prime[1] - 1,num));
			}
			else//p^k * p1^k1 * p2^k2 .... 꼴 
			{
				while (O_Prime[s] != 0)
				{
					s_temp *= (double)((O_Prime[s] - 1) / (double)O_Prime[s]); // 분수꼴 저장을 하기위한 형변환 실행
					s += 2;
				}
				return s_temp;
			}
		}
	}
}

// 생성일 : 17.07.01 (토)
// 목  적 : 위수를 구하기 위해서는 오일러값의 약수가 필요로 한다. 따라서 오일러 값의 약수를 배열에 저장하는 함수이다.
void Prime_Divisor(unsigned __int64 num)
{
	int z = 0;
	for (int i = 1; i <= num; i++)
	{
		if (num%i == 0)
		{
			O_Divisor[z++] = i;
		}
	}
}

// 생성일 : 17.07.01 (토)
// 목  적 : 약수들이 저장이 잘 되었는지 출력하는 함수
void Show_O_Divisor()
{
	int i = 0;
	while (O_Divisor[i] > 0)
	{
		cout << O_Divisor[i] << ' ';
		i++;
	}
	cout << endl;
}

//  생성일 : 17.07.01 (토)
//  목  적 : 위수가 어떤것이 성립하는지 확인하기 위해 , fmod 를 새로 배웟다
void Order(unsigned __int64 num)
{
	int a = 0, i = 0;
	unsigned __int64 result;
	int saveorder[MAX_SIZE] = { 0 };
	cout << "위수를 구할 a의 값을 입력하시오." << endl;
	cout << "a  :  "; cin >> a;
	int Order_a = a;
	while (O_Divisor[i] != 0)
	{
		unsigned __int64 temp = O_Divisor[i];
		result = Order_Pow(Order_a, temp,num);
		if (result%num == 1)
		{
			cout << Order_a << " ^ " << temp << " = " << result%num <<" (mod"<< num <<") 위수입니다." << endl;
			cout << "a 의 위수 : " << temp << endl;
			break;
		}
		else
		{
			cout << Order_a << " ^ " << temp << " = " << result%num <<" (mod"<<num<<")" <<endl;
		}
		i++;
	}
}

int Order_Pow(int num, int count,int moudler) {
	int save_pow_result = 1;
	while (count > 0) {
		save_pow_result = save_pow_result*num%moudler;
		count--;
	}
	return save_pow_result;
}