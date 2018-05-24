#include<iostream>
#include<ctime>
#include"Integer.h"
using namespace std;

//소수 판별 실행 함수
//기능
//time함수에 있는 clock_t 변수를 이용해서 시간값을 입력 받고
//그 두 변수의 차이를 CLOCKS_PER_SEC 를 이용해서 나누어서
//시간이 얼마나 걸렷는지 알수있다.
//또 unsinged __int64 변수를 사용하였기 때문에
//1800경 정도의 숫자까지 판단이 가능하다.
void Is_Prime_Main()
{
	cout << "소수판별 프로그램입니다." << endl;
	unsigned __int64 x;
	cout << "소수인지 판별할 수를 입력하세요." << endl;
	cin >> x;
	clock_t start, end;
	start = clock();
	Is_Prime(x);
	end = clock();
	double time = (double)(end - start) / CLOCKS_PER_SEC;
	cout << time << endl;
}

//소수 판별 함수
bool Is_Prime(unsigned __int64 num)
{
	for (int i = 3; i*i <= num; i += 2)
	{
		if (num % 2 == 0)
		{
			num /= 2;
			cout << "2로 나누어 떨어집니다." << endl;
			cout << "합성수입니다." << endl;
			return false;
		}
		else if (num % i == 0)
		{
			num /= i;
			cout << i << "로 나누어 떨어집니다." << endl;
			cout << "합성수입니다." << endl;
			return false;
		}
	}
	cout << "소수입니다." << endl;
	return true;
}