#include<iostream>
#include"Integer.h"
using namespace std;

//��Ŭ���� �˰��� ���� �Լ�
void Uclid_Main() 
{
	cout << "��Ŭ���� �˰����� �����ϼ̽��ϴ�." << endl; 
	//���� ��ġ�鼭 �߰��� �����̶� c++ �ҽ��� �ۼ�
	int num1 = 0, num2 = 0, temp = 0;
	printf("�ִ������� Ȯ���� �� ���� �Է��Ͻÿ� : ");
	scanf_s("%d %d", &num1, &num2);

	if (num1 <= 0 || num2 <= 0)
	{
		printf("�� ���� �ٽ��Է��Ͻÿ�.");
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

	printf("�� ���� �ִ����� : %d \n", num1);
}