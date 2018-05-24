#include<iostream>
#include"integer.h"

//유클리드 호제법 함수
void Euclidean_Algorithm_Main(void)
{
	std::cout << "유클리드 호제법을 실행하였습니다." << std::endl;
	int num1 = 0, num2 = 0, temp = 0;
	printf("최대공약수를 확인할 두 수를 입력하시오 : ");
	scanf_s("%d %d", &num1, &num2);

	if (num1 <= 0 || num2 <= 0)
	{
		printf("두 수를 다시입력하시오.");
		Euclidean_Algorithm_Main();
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
		printf("%d = %d * %d + %d \n", num1, num1 / num2, num2, num1%num2);
		num1 = num2;
		num2 = temp;
		if (temp == 0)
		{
			break;
		}
	}
	printf("두 수의 최대공약수 : %d \n", num1);
}