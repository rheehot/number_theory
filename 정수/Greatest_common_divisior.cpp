#include<iostream>
#include"Integer.h"

//Greatest Common Divisor �ִ�����
void GCD_Main(void)
{
	std::cout << "�ִ������� ���ϴ� ���α׷��Դϴ�." << std::endl;
	int num1 = 0, num2 = 0;
	printf("�ִ������� Ȯ���� �� ���� �Է��Ͻÿ� : ");
	scanf_s("%d %d", &num1, &num2);

	if (num1<0 || num2<0)
	{
		printf("�� ���� �ٽ��Է��Ͻÿ�.");
		GCD_Main();
	}
	else if (num1 == 0)
	{
		printf("�� ������ �ִ����� : %d \n", num2);
	}
	else if (num2 == 0)
	{
		printf("�� ������ �ִ����� : %d \n", num1);
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
	printf("�� ������ �ִ����� : %d \n", num2);
}