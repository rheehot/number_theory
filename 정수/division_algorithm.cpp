#include<iostream>
#include"integer.h"
using namespace std;

//������ ���� ���� �Լ�
void Divison_Algorithm_Main(void)
{
	cout << "������ ���� ���� �Լ�" << endl;
	//���� ��ġ�鼭 �߰��� ��¹��̶� C++�� ���
	int num1 = 0, num2 = 0;
	printf("�� ������ �Է��Ͻÿ� : ");
	scanf_s("%d %d", &num1, &num2);

	if (num1>0 && num2>0)
	{
		if (num1>num2)
		{
			printf("������ : %d \n \n", num1);
			printf("��  �� : %d \n \n", num2);
			printf("    �� : %d \n \n", num1 / num2);
			printf("������ : %d \n \n", num1%num2);
		}
		if (num2>num1)
		{
			printf("������ : %d \n \n", num2);
			printf("��  �� : %d \n \n", num1);
			printf("    �� : %d \n \n", num2 / num1);
			printf("������ : %d \n \n", num2%num1);
		}
	}
	else if (num1<0 || num2<0)
	{
		if (num1<0)
		{
			printf("������ : %d \n \n", num1);
			printf("��  �� : %d \n \n", num2);
		}
		if (num2<0)
		{
			printf("������ : %d \n \n", num2);
			printf("��  �� : %d \n \n", num1);
		}
	}
	else
	{
		printf("�� ������ �ٽ��Է��Ͻÿ�. \n");
	}
}