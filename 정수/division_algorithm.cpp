#include<iostream>
#include"integer.h"
using namespace std;

//나눗셈 정리 실행 함수
void Divison_Algorithm_Main(void)
{
	cout << "나눗셈 정리 실행 함수" << endl;
	//파일 합치면서 추가한 출력문이라 C++로 사용
	int num1 = 0, num2 = 0;
	printf("두 정수를 입력하시오 : ");
	scanf_s("%d %d", &num1, &num2);

	if (num1>0 && num2>0)
	{
		if (num1>num2)
		{
			printf("피제수 : %d \n \n", num1);
			printf("제  수 : %d \n \n", num2);
			printf("    몫 : %d \n \n", num1 / num2);
			printf("나머지 : %d \n \n", num1%num2);
		}
		if (num2>num1)
		{
			printf("피제수 : %d \n \n", num2);
			printf("제  수 : %d \n \n", num1);
			printf("    몫 : %d \n \n", num2 / num1);
			printf("나머지 : %d \n \n", num2%num1);
		}
	}
	else if (num1<0 || num2<0)
	{
		if (num1<0)
		{
			printf("피제수 : %d \n \n", num1);
			printf("제  수 : %d \n \n", num2);
		}
		if (num2<0)
		{
			printf("피제수 : %d \n \n", num2);
			printf("제  수 : %d \n \n", num1);
		}
	}
	else
	{
		printf("두 정수를 다시입력하시오. \n");
	}
}