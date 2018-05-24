#include<iostream>
#include"integer.h"

//��Ŭ���� ȣ���� �Լ�
void Euclidean_Algorithm_Main(void)
{
	std::cout << "��Ŭ���� ȣ������ �����Ͽ����ϴ�." << std::endl;
	int num1 = 0, num2 = 0, temp = 0;
	printf("�ִ������� Ȯ���� �� ���� �Է��Ͻÿ� : ");
	scanf_s("%d %d", &num1, &num2);

	if (num1 <= 0 || num2 <= 0)
	{
		printf("�� ���� �ٽ��Է��Ͻÿ�.");
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
	printf("�� ���� �ִ����� : %d \n", num1);
}