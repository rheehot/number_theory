#include <iostream>
#include"hapdong.h"
using namespace std;
static int Front[6] = { 0 };
static int Back[7] = { 0 };

void Identify_Testing_Main()
{
	cout << "주민등록번호 판별 프로그램입니다." << endl;
	cout << "이 프로그램은 값이 맞는지 아닌지만 판단해 줍니다." << endl;
	int front_num = 0; //주민등록번호 앞자리 입력받는 공간
	int back_num = 0; //주민등록번호 뒷자리 입력받는 공간
	int z = 5; // POW연산을 하기위한 초기값
	int save_num = 0; // 연산한 값을 저장하는 공간
	cout << "주민등록번호를 입력하세요." << endl;
	cin >> front_num >> back_num;
	for (int i = 0; i < 6; i++) // 앞자리를 각 배열의 한칸씩에 저장하는 함수
	{
		Front[i] = ((front_num / Testing_POW(10, z)) % 10);
		z--;
	}
	z = 6; //뒷자리는 한자리 더 많으므로 초기값 변경
	for (int i = 0; i < 7; i++) // 뒷자리를 각 배열의 한칸씩에 저장하는 함수
	{
		Back[i] = ((back_num / Testing_POW(10, z)) % 10);
		z--;
	}
	int i = 0;
	while (i<12) // 12번째 자리까지 반복하는 이유는 13번째 자리는 에러검출하는 번호이다.
	{
		if (i < 6)
		{
			save_num += (Front[i] * (2 + i));
			cout << (Front[i] * (2 + i)) << '+';
		}
		else if (i<8)
		{
			save_num += (Back[i - 6] * (i + 2));
			cout << (Back[i - 6] * (i + 2)) << '+';
		}
		else
		{
			if (i == 11)
			{
				save_num += (Back[i - 6] * (i - 6));
				cout << (Back[i - 6] * (i - 6)) << '=';
			}
			else
			{
				save_num += (Back[i - 6] * (i - 6));
				cout << (Back[i - 6] * (i - 6)) << '+';
			}
		}
		i++;
	}
	cout << save_num << endl;
	if (((11 - (save_num % 11)) % 10) == Back[6]) // 11-a의 값이 주민등록번호 제일 마지막 자리와 같아야 한다.		
	{										/*a는 12번째 자리까지 공식에 넣은 값의 mod 11 값이다.*/
		cout << "(11 - ( 각자리수 계산값 % 11))%10-> " << (11 - (save_num % 11)) % 10 << " = " << Back[6] << " <-주민등록번호 뒷자리 7번째 자리" << endl;
		cout << "올바른 주민등록번호입니다." << endl;
	}
	else
	{
		cout << "(11 - ( 각자리수 계산값 % 11))%10-> " << (11 - (save_num % 11)) % 10 << " != " << Back[6] << " <-주민등록번호 뒷자리 7번째 자리" << endl;
		cout << "올바르지 않는 주민등록번호입니다." << endl;
	}
}
// 생성일 : 17.07.13(목)
// 목  적 : 제곱기능을 math헤더의 pow함수를 쓰지않고 직접 구현하여 쓰기 위하여
// 기  능
/* 1. (10,20)을 입력했다면 10^20 계산을 하게 도와준다.*/
int Testing_POW(int a, int b)
{
	int result = 1;
	for (int i = 0; i < b; i++)
	{
		result *= a;
	}
	return result;
}