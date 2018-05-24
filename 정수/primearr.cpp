#include<iostream>
#include<ctime>
#include"Integer.h"
using namespace std;

static unsigned __int64 prime_arr[1000] = { 0 };

//소인수 분해 함수
//time함수에 있는 clock_t 변수를 이용해서 시간값을 입력 받고
//그 두 변수의 차이를 CLOCKS_PER_SEC 를 이용해서 나누어서
//시간이 얼마나 걸렷는지 알수있다.
//또 unsinged __int64 변수를 사용하였기 때문에
//1800경 정도의 숫자까지 판단이 가능하다.
//소수 판별과 거의 다를께 없다.
void Prime_Arr_Main()
{
	cout << "소인수분해 프로그램 입니다." << endl;
	unsigned __int64 x;
	cout << "소인수분해할 수를 입력하세요." << endl;
	cin >> x;
	clock_t start, end;
	start = clock(); 
	Prime_Arr(x);
	end = clock();
	int i = 0;
	while (i<100)
	{
		if(prime_arr[i]!=0)
		{
			if (i % 2 == 0)
			{
				cout <<' '<< prime_arr[i] ;
			}
			else
			{
				cout << " ^ " << prime_arr[i];
			}
		}
		i++;
	}
	double time = (double)(end - start) / CLOCKS_PER_SEC;
	cout <<"   소인수분해하는데 걸린 시간 : " <<time <<"초"<< endl;
}

//소인수 분해 함수
//소수로 나누어 떨어지는 부분이 있다면
//나누어 떨어지는 수를 바로 출력을 한다.
void Prime_Arr(unsigned __int64 num)
{
	int z = 0, k = 0;
	for (int j=2;j<=num;j++)
	{
		for (int i=2; i*i <= num; i++) //소수판별
		{
			if (num%i == 0)
			{
				prime_arr[z] = i;
				if (prime_arr[k - 2] == prime_arr[k]) // 현재의 값과 과거의 값이 같다면 카운트업 하고 초기화
				{
					prime_arr[z] = i;
					prime_arr[k - 1] += 1;
					prime_arr[k] = 0;
					num /= i;
					break;
				}
				else  // 그냥 진행 
				{
					k += 2;
					prime_arr[z] = i;
					num /= i;
					prime_arr[z + 1] += 1;
					z += 2;
					break;
				}
			}
		}
	}
	prime_arr[z] = num;
	prime_arr[z + 1] += 1;
}