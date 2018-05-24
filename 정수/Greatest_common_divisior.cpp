#include<iostream>
#include"Integer.h"

//Greatest Common Divisor 최대공약수
void GCD_Main(void)
{
	std::cout << "최대공약수를 구하는 프로그램입니다." << std::endl;
	int num1 = 0, num2 = 0;
	printf("최대공약수를 확인할 두 수를 입력하시오 : ");
	scanf_s("%d %d", &num1, &num2);

	if (num1<0 || num2<0)
	{
		printf("두 수를 다시입력하시오.");
		GCD_Main();
	}
	else if (num1 == 0)
	{
		printf("두 정수의 최대공약수 : %d \n", num2);
	}
	else if (num2 == 0)
	{
		printf("두 정수의 최대공약수 : %d \n", num1);
	}
	while (1)
	{
		if (num1>num2)
		{
			printf("%d %d \n", num1, num2);
			num1 = num1 - num2;
		}
		else if (num2>num1)
		{
			printf("%d %d \n", num2, num1);
			num2 = num2 - num1;
		}
		else if (num1 == num2)
		{
			printf("%d %d \n", num1, num2);
			break;
		}
	}
	printf("두 정수의 최대공약수 : %d \n", num2);
}