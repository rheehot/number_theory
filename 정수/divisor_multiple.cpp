#include<iostream>
#include"Integer.h"

//��� ��� ���� �ҽ�
void Divisor_Multiple_Main(void)
{
	std::cout << "��� ��� ���踦 �˾ƺ��� ���α׷��� �����ϼ˽��ϴ�" << std::endl;
	int num1 = 0, num2 = 0, temp = 0;
	printf("����� ������踦 Ȯ���� �� ���� �Է��Ͻÿ� : ");
	scanf_s("%d %d", &num1, &num2);

	if (num1 <= 0 && num2 <= 0)
	{
		printf("�� ���� �ٽ��Է��Ͻÿ�.");
	}
	else if (num1 > num2)
	{
		temp = num1;
		num1 = num2;
		num2 = temp;
	}
	if (num1 == 0 || num2 == 0)
	{
		printf("%d %d \n0�� ��������� ����̰� ��������� 0�Ǿ���̴�.\n���� �� ���� ����� ��������̴�. \n", num2, num1);
	}
	else if (num2%num1 == 0)
	{
		printf("%d �� %d�� ����̰� \n%d �� %d�� ����̴�.\n���� �� ���� ����� ��������̴�.\n", num1, num2, num2, num1);
	}
	else
	{
		printf("�� �� %d �� %d �� ����� ����� ���谡 �ƴϴ�.\n", num1, num2);
	}
}