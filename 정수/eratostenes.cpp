#include <iostream>
#include"Integer.h"
using namespace std;
#define MAX_SIZE 100000000
static int Prime[MAX_SIZE] = { 0 }; // Prime 배열을 초기화

//에라토스테네스의 체 실행함수
void Eratostenes_Main()
{
	cout << "에라토스테네스의 체 프로그램입니다." << endl;
	int number = 0, P_NP = 0, play = 0;
	int z = 0;
	int count = 0;
	cout << "테이블 만들고싶은 숫자 범위를 입력하세요" << endl;
	cout << "(100000000까지만 가능합니다.)" << endl;
	cin >> number;
	Table(number);
	Show();
	cout << endl << endl;
	while (true) // 채의 과정을 여러번 보여주기 위해 반복함수사용
	{
		P_NP = Prime[z];
		if (P_NP*P_NP <= number) // 에라토스테네스의
		{
			cout << ":::::" << Prime[z] << "(으)로 거른 결과 :::::" << endl;
			z++;
			PrimeTable(P_NP);
			cout << endl;
			cout << "끝내시려면 0을 입력하시고 진행하시려면 아무 값을 넣어주시기 바랍니다." << endl;
			cin >> play;
			if (play == 0)
			{
				break;
			}
		}
		else
		{
			cout << "체로 다 걸러 졌습니다." << endl << "< 결 과 >" << endl;
			Show();
			cout << endl;
			while (count < MAX_SIZE)
			{
				Prime[count++] = 0; // 소수배열의 초기화;
			}
			break;
		}
	}
}

// 생성일 : 17.07.01(토)
// 목  적 : Prime 함수 내부의 값이 있는 모든 수들을 출력하는 함수
void Show()
{
	int count = 0;
	for (int i = 0; i < MAX_SIZE; i++)
	{
		if (Prime[i] == 0)
		{
			break;
		}
		else
		{
			cout << Prime[i] << ' ';
			count++;
			if (count % 20 == 0)// 너무 길게 나와 30번째 숫자에서 띄워쓰기 해주기 위함
			{
				cout << endl;
			}
		}

	}
}

// 생성일 : 17.07.01 (토)
// 목  적 : 초기 범위 설정후 테이블 생성을 위해 초기화 하는 함수
void Table(int num)
{
	for (int i = 0; i < num - 1; i++)
	{
		Prime[i] = i + 2;
	}
}

// 생성일 : 17.07.01 (토)
// 목  적 : 채 거르는 함수 , 소수들을 출력하기 위한 과정을 출력하기 위함.
void PrimeTable(int num)
{
	int count = 0;
	int z = 0;
	int i = 0;
	if (num != 0)
	{
		while (Prime[i] != 0)
		{
			if (Prime[i] == num || Prime[i] % num != 0)
			{
				Prime[z++] = Prime[i];
			}
			i++;
		}
		while (z <= MAX_SIZE)
		{
			Prime[z++] = 0;
		}
		Show();
	}
}