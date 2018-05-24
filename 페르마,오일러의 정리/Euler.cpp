#include<iostream>
#include"Fermat_Euler.h"
using namespace std;
static unsigned __int64 Euler_Prime[1000] = { 0 }; // ���μ������� �������

void Euler_Main()
{
	int a_value = 0, exp_value = 0, euler_moduler = 0;
	cout << "���Ϸ��� ���� ���α׷� �Դϴ�." << endl << "�� ���� ��ⷯ���� ���ʴ�� �Է��ϼ���." << endl;
	cout << "������ ���� �𸣸� 0�� �Է��� �ּ���." << endl;
	cin >> a_value >> exp_value >> euler_moduler;
	int euler_temp = Euler(euler_moduler);
	if (exp_value == 0)
	{
		cout << "���� : " << euler_temp << endl;
	}
	else
	{
		if (Euler_GCD(a_value, euler_moduler) == 1)
		{
			cout << "Euler : " << euler_temp << endl;
			cout << a_value << "^" << euler_temp << " = " << 1 << "(mod " << euler_moduler << ")" << endl;
			cout << exp_value << " = " << euler_temp << "*" << exp_value / euler_temp << "+" << exp_value % euler_temp << endl;
			cout << "Remain Result : " << Result_Euler(a_value, exp_value, euler_temp, euler_moduler) << endl;
		}
		else if (Euler_GCD(a_value, euler_moduler) != 1 && Euler_GCD(Euler_GCD(a_value, euler_moduler), exp_value) != 1)
		{
			cout << "�� ���� �ִ����� : " << Euler_GCD(Euler_GCD(a_value, euler_moduler), exp_value) << endl;
			a_value = a_value / Euler_GCD(Euler_GCD(a_value, euler_moduler), exp_value);
			exp_value = exp_value / Euler_GCD(Euler_GCD(a_value, euler_moduler), exp_value);
			euler_moduler = euler_moduler / Euler_GCD(Euler_GCD(a_value, euler_moduler), exp_value);
			cout << "Euler : " << euler_temp << endl;
			cout << a_value << "^" << euler_temp << " = " << 1 << "(mod " << euler_moduler << ")" << endl;
			cout << exp_value << " = " << euler_temp << "*" << exp_value / euler_temp << "+" << exp_value % euler_temp << endl;
			cout << "Remain Result : " << Result_Euler(a_value, exp_value, euler_temp, euler_moduler) << endl;
		}
		else
		{
			cout << "���� ���� ��ⷯ���� 1�� �ƴϸ� ������ �� �����ϴ�. " << endl;
		}
	}
}

// ������ : 17.07.18(ȭ)
// �� �� : ���Ϸ����� �̿��Ͽ� ���� ������ ���� ����ϴ� �Լ�
//			�ʱ⿡ �Է��� ���� ���������� ����Ѵ�.
int Result_Euler(int a_value, int exp_value, int Euler_temp, int euler_moduler)
{
	unsigned __int64 result_temp = 1;
	if (exp_value > Euler_temp)
	{
		for (int i = 0; i < exp_value%Euler_temp; i++)
		{
			if (result_temp > 10000000)
			{
				result_temp %= euler_moduler;
				result_temp *= a_value;
			}
			else
			{
				result_temp *= a_value;
			}
		}
		return result_temp%euler_moduler;
	}
	else
	{
		for (int i = 0; i < exp_value; i++)
		{
			if (result_temp > 10000000)
			{
				result_temp %= euler_moduler;
				result_temp *= a_value;
			}
			else
			{
				result_temp *= a_value;
			}
		}
		return result_temp%euler_moduler;
	}
}

// ������ : 17.06.29(��)
// ��  �� : bool �Լ��� �̿��Ͽ� �Ҽ� �Ǻ��� true, false �� �Ǵ��ϰ� �ϴ� �Լ� , + ���μ� ���ظ� ���� ���� �����ϴ� ���
bool Euler_IsPrime(unsigned __int64 euler_moduler)
{
	int z = 0, k = 0, i = 2, j = 0;
	int count = 1;
	for (j; j <= 10; j++)
	{
		for (i; i*i < euler_moduler; i++) //�Ҽ��Ǻ�
		{
			if (euler_moduler%i == 0)
			{
				Euler_Prime[z] = i;
				if (Euler_Prime[k - 2] == Euler_Prime[k]) // ������ ���� ������ ���� ���ٸ� ī��Ʈ�� �ϰ� �ʱ�ȭ
				{
					Euler_Prime[z] = i;
					Euler_Prime[k - 1] += count;
					Euler_Prime[k] = 0;
					euler_moduler /= i;
					break;
				}
				else  // �׳� ���� 
				{
					k += 2;
					Euler_Prime[z] = i;
					euler_moduler /= i;
					Euler_Prime[z + 1] += count;
					z += 2;
					break;
				}
			}
		}
	}
	if (Euler_Prime[1] == 0 && Euler_Prime[2] == 0) // �Ҽ��̸� ������ ���°� �����Ƿ� �Է°��� �Ҽ� 
	{
		Euler_Prime[0] = euler_moduler;
		Euler_Prime[1] = count;
		return true;
	}
	else if (euler_moduler != 1) // ���������� ������ �������� �߰�
	{
		if (Euler_Prime[z - 2] == euler_moduler)
		{
			Euler_Prime[z - 1] += count;
		}
		else
		{
			Euler_Prime[z] = euler_moduler;
			Euler_Prime[z + 1] += count;
		}
		return false;
	}
	else // ��� ������ �� �𸣰����� ������ ������ ���ؼ� �����̶�� ������ֱ� ����
	{
		return false;
	}
}

// ������ : 17.06.30 (��) 
// ��  �� : �Ҽ� �Ǻ� �� ���Ϸ� ���� ����ϴ� �Լ�, (float)�� ���� ����ȯ�� �ϸ� �м�ó�� ����� �� ������ �˰� ��
int  Euler(int euler_moduler)
{
	int s = 0;
	double s_temp = euler_moduler;
	if (Euler_IsPrime(euler_moduler)) // bool�Լ��� if���� ���ǿ��� ������ �ִ�.
	{
		cout << "�Ҽ��Դϴ�." << endl;
		return (Euler_Prime[0] - 1);
	}
	else
	{
		if (Euler_Prime[4] == 0 && Euler_Prime[1] == 1 && Euler_Prime[3] == 1) //p*q��
		{
			cout << "p*q�� �Դϴ�." << endl;
			cout << Euler_Prime[0] << " * " << Euler_Prime[2] << endl;
			return (Euler_Prime[0] - 1)*(Euler_Prime[2] - 1);
		}
		else if (Euler_Prime[1] != 0 && Euler_Prime[2] == 0)// p^k ��
		{
			cout << " p^k �� �Դϴ�." << endl;
			cout << Euler_Prime[0] << "^" << Euler_Prime[1] << " - " << Euler_Prime[0] << "^" << Euler_Prime[1] - 1 << endl;
			return (pow(Euler_Prime[0], Euler_Prime[1]) - pow(Euler_Prime[0], Euler_Prime[1] - 1));
		}
		else//p^k * p1^k1 * p2^k2 .... �� 
		{
			cout << "p^k * p1^k1 * p2^k2 .... ���Դϴ�." << endl;
			cout << euler_moduler << "*";
			while (Euler_Prime[s] != 0)
			{
				if (Euler_Prime[s + 2] == 0)
				{
					s_temp *= (double)((Euler_Prime[s] - 1) / (double)Euler_Prime[s]); // �м��� ������ �ϱ����� ����ȯ ����
					cout << (Euler_Prime[s] - 1) << "/" << Euler_Prime[s] << endl;
				}
				else
				{
					s_temp *= (double)((Euler_Prime[s] - 1) / (double)Euler_Prime[s]); // �м��� ������ �ϱ����� ����ȯ ����
					cout << (Euler_Prime[s] - 1) << "/" << Euler_Prime[s] << "*";
				}
				s += 2;
			}
			return s_temp;
		}
	}
}

//������ : 17.07.18
//��  �� : �ִ������� 1�϶��� ���Ϸ��� ������ ����ɼ� �����Ƿ� �񱳰��� ���Ͽ� ��Ŭ���� �˰����� �̿��Ͽ� �ִ������� ���ϱ� ����
int Euler_GCD(int a_value, int euler_moduler)
{
	return euler_moduler ? Euler_GCD(euler_moduler, a_value%euler_moduler) : a_value;
}