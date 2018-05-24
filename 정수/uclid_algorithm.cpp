#include<iostream>
#include"Integer.h"
using namespace std;

//유클리드 알고리즘 실행 함수
void Uclid_Main() 
{
	cout << "유클리드 알고리즘을 실행하셨습니다." << endl; 
	//파일 합치면서 추가한 사항이라 c++ 소스로 작성
	int num1 = 0, num2 = 0, temp = 0;
	printf("최대공약수를 확인할 두 수를 입력하시오 : ");
	scanf_s("%d %d", &num1, &num2);

	if (num1 <= 0 || num2 <= 0)
	{
		printf("두 수를 다시입력하시오.");
		Uclid_Main();
	}
	else if (num1<num2)
	{
		temp = num1;
		num1 = num2;
		num2 = temp;
	}

	while (1)
	{
		temp = num1%num2;
		printf("%5d %5d %5d %5d \n", num1 / num2, num1, num2, num1%num2);
		num1 = num2;
		num2 = temp;
		if (temp == 0)
		{
			break;
		}
	}

	printf("두 수의 최대공약수 : %d \n", num1);
}