#include<iostream>
#include"Integer.h"

//약수 배수 관계 소스
void Divisor_Multiple_Main(void)
{
	std::cout << "약수 배수 관계를 알아보는 프로그램을 실행하셧습니다" << std::endl;
	int num1 = 0, num2 = 0, temp = 0;
	printf("약수와 배수관계를 확인할 두 수를 입력하시오 : ");
	scanf_s("%d %d", &num1, &num2);

	if (num1 <= 0 && num2 <= 0)
	{
		printf("두 수를 다시입력하시오.");
	}
	else if (num1 > num2)
	{
		temp = num1;
		num1 = num2;
		num2 = temp;
	}
	if (num1 == 0 || num2 == 0)
	{
		printf("%d %d \n0은 모든정수의 배수이고 모든정수는 0의약수이다.\n따라서 두 수는 약수와 배수관계이다. \n", num2, num1);
	}
	else if (num2%num1 == 0)
	{
		printf("%d 은 %d의 약수이고 \n%d 은 %d의 배수이다.\n따라서 두 수는 약수와 배수관계이다.\n", num1, num2, num2, num1);
	}
	else
	{
		printf("두 수 %d 와 %d 는 약수와 배수의 관계가 아니다.\n", num1, num2);
	}
}