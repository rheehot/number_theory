#include <iostream>
#include"hapdong.h"
using namespace std;
static int Front[6] = { 0 };
static int Back[7] = { 0 };

void Identify_Testing_Main()
{
	cout << "�ֹε�Ϲ�ȣ �Ǻ� ���α׷��Դϴ�." << endl;
	cout << "�� ���α׷��� ���� �´��� �ƴ����� �Ǵ��� �ݴϴ�." << endl;
	int front_num = 0; //�ֹε�Ϲ�ȣ ���ڸ� �Է¹޴� ����
	int back_num = 0; //�ֹε�Ϲ�ȣ ���ڸ� �Է¹޴� ����
	int z = 5; // POW������ �ϱ����� �ʱⰪ
	int save_num = 0; // ������ ���� �����ϴ� ����
	cout << "�ֹε�Ϲ�ȣ�� �Է��ϼ���." << endl;
	cin >> front_num >> back_num;
	for (int i = 0; i < 6; i++) // ���ڸ��� �� �迭�� ��ĭ���� �����ϴ� �Լ�
	{
		Front[i] = ((front_num / Testing_POW(10, z)) % 10);
		z--;
	}
	z = 6; //���ڸ��� ���ڸ� �� �����Ƿ� �ʱⰪ ����
	for (int i = 0; i < 7; i++) // ���ڸ��� �� �迭�� ��ĭ���� �����ϴ� �Լ�
	{
		Back[i] = ((back_num / Testing_POW(10, z)) % 10);
		z--;
	}
	int i = 0;
	while (i<12) // 12��° �ڸ����� �ݺ��ϴ� ������ 13��° �ڸ��� ���������ϴ� ��ȣ�̴�.
	{
		if (i < 6)
		{
			save_num += (Front[i] * (2 + i));
			cout << (Front[i] * (2 + i)) << '+';
		}
		else if (i<8)
		{
			save_num += (Back[i - 6] * (i + 2));
			cout << (Back[i - 6] * (i + 2)) << '+';
		}
		else
		{
			if (i == 11)
			{
				save_num += (Back[i - 6] * (i - 6));
				cout << (Back[i - 6] * (i - 6)) << '=';
			}
			else
			{
				save_num += (Back[i - 6] * (i - 6));
				cout << (Back[i - 6] * (i - 6)) << '+';
			}
		}
		i++;
	}
	cout << save_num << endl;
	if (((11 - (save_num % 11)) % 10) == Back[6]) // 11-a�� ���� �ֹε�Ϲ�ȣ ���� ������ �ڸ��� ���ƾ� �Ѵ�.		
	{										/*a�� 12��° �ڸ����� ���Ŀ� ���� ���� mod 11 ���̴�.*/
		cout << "(11 - ( ���ڸ��� ��갪 % 11))%10-> " << (11 - (save_num % 11)) % 10 << " = " << Back[6] << " <-�ֹε�Ϲ�ȣ ���ڸ� 7��° �ڸ�" << endl;
		cout << "�ùٸ� �ֹε�Ϲ�ȣ�Դϴ�." << endl;
	}
	else
	{
		cout << "(11 - ( ���ڸ��� ��갪 % 11))%10-> " << (11 - (save_num % 11)) % 10 << " != " << Back[6] << " <-�ֹε�Ϲ�ȣ ���ڸ� 7��° �ڸ�" << endl;
		cout << "�ùٸ��� �ʴ� �ֹε�Ϲ�ȣ�Դϴ�." << endl;
	}
}
// ������ : 17.07.13(��)
// ��  �� : ��������� math����� pow�Լ��� �����ʰ� ���� �����Ͽ� ���� ���Ͽ�
// ��  ��
/* 1. (10,20)�� �Է��ߴٸ� 10^20 ����� �ϰ� �����ش�.*/
int Testing_POW(int a, int b)
{
	int result = 1;
	for (int i = 0; i < b; i++)
	{
		result *= a;
	}
	return result;
}