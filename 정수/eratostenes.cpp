#include <iostream>
#include"Integer.h"
using namespace std;
#define MAX_SIZE 100000000
static int Prime[MAX_SIZE] = { 0 }; // Prime �迭�� �ʱ�ȭ

//�����佺�׳׽��� ü �����Լ�
void Eratostenes_Main()
{
	cout << "�����佺�׳׽��� ü ���α׷��Դϴ�." << endl;
	int number = 0, P_NP = 0, play = 0;
	int z = 0;
	int count = 0;
	cout << "���̺� �������� ���� ������ �Է��ϼ���" << endl;
	cout << "(100000000������ �����մϴ�.)" << endl;
	cin >> number;
	Table(number);
	Show();
	cout << endl << endl;
	while (true) // ä�� ������ ������ �����ֱ� ���� �ݺ��Լ����
	{
		P_NP = Prime[z];
		if (P_NP*P_NP <= number) // �����佺�׳׽���
		{
			cout << ":::::" << Prime[z] << "(��)�� �Ÿ� ��� :::::" << endl;
			z++;
			PrimeTable(P_NP);
			cout << endl;
			cout << "�����÷��� 0�� �Է��Ͻð� �����Ͻ÷��� �ƹ� ���� �־��ֽñ� �ٶ��ϴ�." << endl;
			cin >> play;
			if (play == 0)
			{
				break;
			}
		}
		else
		{
			cout << "ü�� �� �ɷ� �����ϴ�." << endl << "< �� �� >" << endl;
			Show();
			cout << endl;
			while (count < MAX_SIZE)
			{
				Prime[count++] = 0; // �Ҽ��迭�� �ʱ�ȭ;
			}
			break;
		}
	}
}

// ������ : 17.07.01(��)
// ��  �� : Prime �Լ� ������ ���� �ִ� ��� ������ ����ϴ� �Լ�
void Show()
{
	int count = 0;
	for (int i = 0; i < MAX_SIZE; i++)
	{
		if (Prime[i] == 0)
		{
			break;
		}
		else
		{
			cout << Prime[i] << ' ';
			count++;
			if (count % 20 == 0)// �ʹ� ��� ���� 30��° ���ڿ��� ������� ���ֱ� ����
			{
				cout << endl;
			}
		}

	}
}

// ������ : 17.07.01 (��)
// ��  �� : �ʱ� ���� ������ ���̺� ������ ���� �ʱ�ȭ �ϴ� �Լ�
void Table(int num)
{
	for (int i = 0; i < num - 1; i++)
	{
		Prime[i] = i + 2;
	}
}

// ������ : 17.07.01 (��)
// ��  �� : ä �Ÿ��� �Լ� , �Ҽ����� ����ϱ� ���� ������ ����ϱ� ����.
void PrimeTable(int num)
{
	int count = 0;
	int z = 0;
	int i = 0;
	if (num != 0)
	{
		while (Prime[i] != 0)
		{
			if (Prime[i] == num || Prime[i] % num != 0)
			{
				Prime[z++] = Prime[i];
			}
			i++;
		}
		while (z <= MAX_SIZE)
		{
			Prime[z++] = 0;
		}
		Show();
	}
}