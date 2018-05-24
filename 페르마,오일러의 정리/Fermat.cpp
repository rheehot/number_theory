#include<iostream>
#include"Fermat_Euler.h"
using namespace std;

//������ : 17.07.18 (ȭ)
//��  �� : �丣�� ������ �⺻������ �����ֱ� ����
 //��  �� : �丣�� ���� �⺻����,�Ҽ��Ǻ�,�ִ�����
void FerMat_Main()
{
	cout << "�丣���� ���� ���α׷��Դϴ�." << endl;
	int a_value = 0, exp = 0, fermat_moduler = 0, default_value = 1;
	cout << "�丣���� ������ ������ Ǯ �ذ� ������ mod M�� ���� �Է����ּ���." << endl;
	cout << "2^18=x(mod17)->2 18 17" << endl;
	cin >> a_value >> exp >> fermat_moduler;
	if (Fermat_is_Prime(fermat_moduler))
	{
		if (Fermat_Gcd(a_value, fermat_moduler) == 1)
		{
			fermat_value = Fermat(fermat_moduler);
			cout << a_value << "^" << fermat_value << "=" << default_value << "(mod " << fermat_moduler << ")" << endl;
			if (exp == -1)//�������ϴ� ���
			{
				cout << a_value << "^" << exp << " = " << a_value << "^" << fermat_value - 1 << "(mod " << fermat_moduler << ")" << endl;
				cout << "���� �� : " << Fermat_Pow(a_value, fermat_value - 1) << endl;
			}
			else if (exp > fermat_moduler) // ������ x���� ����� ã�� ���
			{
				cout << exp << " = " << fermat_value << "*" << exp / fermat_value << "+" << exp % fermat_value << endl;
				cout << a_value << "^" << fermat_value << "= 1 (mod " << fermat_moduler << ")" << endl;
				cout << a_value << "^" << exp % fermat_value << " �� ����մϴ�." << endl;
				cout << "������ �� : " << Fermat_Pow(a_value, exp % fermat_value) % fermat_moduler << endl;
			}
			else if (exp > 0)// ������ x���ε� �밡���ϸ� �Ǵ� ���!
			{
				cout << a_value << "^" << exp << "%" << fermat_moduler << endl;
				cout << "���� ����� ��� : " << Fermat_Pow(a_value, exp) % fermat_moduler << endl;
			}
		}
		else
		{
			cout << "a�� ���� mod M�� ���� �ִ������� 1�� �ƴմϴ�." << endl;
		}
	}
	else
	{
		cout << "�丣���� ������ �Ҽ��� ���� ���� �����մϴ�." << endl;
	}
}


//������ : 17.07.18 (ȭ)
//��  �� : �丣���� ������ �⺻������ �Ҽ��϶��� �۵��ϱ� �����̴�.
int Fermat(int mod)
{
	if (Fermat_is_Prime(mod))
	{
		return mod - 1;
	}
	else
	{
		cout << "�丣���� ������ �Ҽ��� ���� �����մϴ�." << endl;
		return 0;
	}
}


//������ : 17.07.18 (ȭ)
//��  �� : �Ҽ��Ǻ��Լ�
bool Fermat_is_Prime(int num)
{
	for (int i = 2; i*i <= num; i++)
	{
		if (num%i == 0)
		{
			return false;
		}
	}
	return true;
}


//������ : 17.07.18 (ȭ)
//��  �� : ��Ŭ���� �˰����� �̿��Ͽ� �ִ������� ���ϱ� ���Ͽ�
int Fermat_Gcd(int a_value, int fermat_moduler)
{
	return fermat_moduler ? Fermat_Gcd(fermat_moduler, a_value%fermat_moduler) : a_value;
}

//������ : 17.07.18 (ȭ)
//��  �� : �丣������ ����ϴ� �������� �Լ�
//��  �� : �ſ� ū�������� ��ⷯ ���� �̿��Ͽ� ������ �ش�.
unsigned __int64 Fermat_Pow(int a_value, int exp)
{
	unsigned __int64 pow_result = 1;
	if (exp == 0) // 1��ȯ
	{
		return pow_result;
	}
	else if (exp>0) // �����
	{
		for (int i = 1; i <= exp; i++)
		{
			if (pow_result > (fermat_value + 1))
			{
				pow_result %= (fermat_value + 1);
				pow_result *= a_value;
			}
			else
			{
				pow_result *= a_value;
			}
		}
		return pow_result;
	}
	else // ������ ���� �������� �׿��� ���̳ʽ������Ұ�..
	{
		cout << "�߸��� ���Դϴ�." << endl;
		return 0;
	}
}