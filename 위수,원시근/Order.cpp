#include<iostream> // stdio.h ,  ** C�� ������ scanf_s �� ū ���� ���� ���� ���Ѵ�.
#include "Primitive_Root.h"

using namespace std;
#define MAX_SIZE 100000
static unsigned __int64 O_Prime[MAX_SIZE] = { 0 }; //���μ� ���ص� �Ҽ����� �������
static unsigned __int64 O_Divisor[MAX_SIZE] = { 0 }; // ���Ϸ� ���� ������� �������


void Order_Main()
{
	cout << "���� ���ϴ� ���α׷��Դϴ�" << endl;
	cout << "�Է��Ͻ� ��ⷯ ���� ������ ������ݴϴ�." << endl;
	unsigned long long int number=0;
	cout << "��M , ��ⷯ ���� �Է��ϼ���" << endl;
	cin >> number;
	if (number == 1)
	{
		cout << "1�� �Ҽ��� �ռ����� �ƴմϴ�. ������ ���� �� �����ϴ�." << endl;
		cout << "���α׷��� �����մϴ�." << endl;
	}
	else if (number < 1)
	{
		cout << "������ �����п��� ������� �ʽ��ϴ�." << endl;
		cout << "���α׷��� �����մϴ�." << endl;
	}
	else
	{
		unsigned long long int temp = Euler(number);
		Show_O_Prime();
		cout << "Euler : " << temp << endl;
		Prime_Divisor(temp);
		cout << "Euler's Divisor : ";
		Show_O_Divisor();
		Order(number);
		for (int clear = 0; clear < MAX_SIZE; clear++)
		{
			O_Prime[clear] = 0;
			O_Divisor[clear] = 0;
		}
	}
}


// ������ : 17.07.02(��)
// ��  �� : �Ҽ� ��� �Լ�
void Show_O_Prime()
{
	int i = 0;
	while (O_Prime[i] != 0)
	{
		if (i % 2 == 0)
		{
			cout << O_Prime[i] << '^';
			i++;
		}
		else
		{
			if (O_Prime[i + 1] == 0)
			{
				cout << O_Prime[i] << " -> ";
				break;
			}
			else
			{
				cout << O_Prime[i] << '*';
				i++;
			}
		}
	}
	if (O_Prime[2] == 0 && O_Prime[1] == 1) {
			cout << "�Ҽ��Դϴ�.";
	}
	else
	{
		cout << "�ռ����Դϴ�.";
	}
	cout << endl;
}



// ������ : 17.06.29(��)
// ��  �� : bool �Լ��� �̿��Ͽ� �Ҽ� �Ǻ��� true, false �� �Ǵ��ϰ� �ϴ� �Լ� , + ���μ� ���ظ� ���� ���� �����ϴ� ���
bool O_IsPrime(unsigned __int64 num)
{
	int z = 0, k = 0, i = 2, j = 0;
	int count = 1;
	for (j; j <= 1000; j++)
	{
		for (i; i*i <= num; i++) //�Ҽ��Ǻ�
		{
			if (num%i == 0)
			{
				O_Prime[z] = i;
				if (O_Prime[k - 2] == O_Prime[k]) // ������ ���� ������ ���� ���ٸ� ī��Ʈ�� �ϰ� �ʱ�ȭ
				{
					O_Prime[z] = i;
					O_Prime[k - 1] += count;
					O_Prime[k] = 0;
					num /= i;
					break;
				}
				else  // �׳� ���� 
				{
					k += 2;
					O_Prime[z] = i;
					num /= i;
					O_Prime[z + 1] += count;
					z += 2;
					break;
				}
			}
		}
	}
	if (O_Prime[1] == 0 && O_Prime[2] == 0) // �Ҽ��̸� ������ ���°� �����Ƿ� �Է°��� �Ҽ� 
	{
		O_Prime[0] = num;
		O_Prime[1] = count;
		return true;
	}
	else if (num != 1) // ���������� ������ �������� �߰�
	{
		if (O_Prime[z - 2] == num)
		{
			O_Prime[z - 1] += count;
		}
		else
		{
			O_Prime[z] = num;
			O_Prime[z + 1] += count;
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
unsigned __int64  Euler(unsigned __int64 num)
{
	int s = 0;
	double s_temp = num;
	if (O_IsPrime(num)) // bool�Լ��� if���� ���ǿ��� ������ �ִ�.
	{
		return (O_Prime[0] - 1);
	}
	else
	{
		while (1)
		{
			if (O_Prime[4] == 0 && O_Prime[1] == 1 && O_Prime[3] == 1) //p*q��
			{
				return (O_Prime[0] - 1)*(O_Prime[2] - 1);
			}
			else if (O_Prime[1] != 0 && O_Prime[2] == 0)// p^k ��
			{
				return (Order_Pow(O_Prime[0], O_Prime[1],num) - Order_Pow(O_Prime[0], O_Prime[1] - 1,num));
			}
			else//p^k * p1^k1 * p2^k2 .... �� 
			{
				while (O_Prime[s] != 0)
				{
					s_temp *= (double)((O_Prime[s] - 1) / (double)O_Prime[s]); // �м��� ������ �ϱ����� ����ȯ ����
					s += 2;
				}
				return s_temp;
			}
		}
	}
}

// ������ : 17.07.01 (��)
// ��  �� : ������ ���ϱ� ���ؼ��� ���Ϸ����� ����� �ʿ�� �Ѵ�. ���� ���Ϸ� ���� ����� �迭�� �����ϴ� �Լ��̴�.
void Prime_Divisor(unsigned __int64 num)
{
	int z = 0;
	for (int i = 1; i <= num; i++)
	{
		if (num%i == 0)
		{
			O_Divisor[z++] = i;
		}
	}
}

// ������ : 17.07.01 (��)
// ��  �� : ������� ������ �� �Ǿ����� ����ϴ� �Լ�
void Show_O_Divisor()
{
	int i = 0;
	while (O_Divisor[i] > 0)
	{
		cout << O_Divisor[i] << ' ';
		i++;
	}
	cout << endl;
}

//  ������ : 17.07.01 (��)
//  ��  �� : ������ ����� �����ϴ��� Ȯ���ϱ� ���� , fmod �� ���� ��m��
void Order(unsigned __int64 num)
{
	int a = 0, i = 0;
	unsigned __int64 result;
	int saveorder[MAX_SIZE] = { 0 };
	cout << "������ ���� a�� ���� �Է��Ͻÿ�." << endl;
	cout << "a  :  "; cin >> a;
	int Order_a = a;
	while (O_Divisor[i] != 0)
	{
		unsigned __int64 temp = O_Divisor[i];
		result = Order_Pow(Order_a, temp,num);
		if (result%num == 1)
		{
			cout << Order_a << " ^ " << temp << " = " << result%num <<" (mod"<< num <<") �����Դϴ�." << endl;
			cout << "a �� ���� : " << temp << endl;
			break;
		}
		else
		{
			cout << Order_a << " ^ " << temp << " = " << result%num <<" (mod"<<num<<")" <<endl;
		}
		i++;
	}
}

int Order_Pow(int num, int count,int moudler) {
	int save_pow_result = 1;
	while (count > 0) {
		save_pow_result = save_pow_result*num%moudler;
		count--;
	}
	return save_pow_result;
}