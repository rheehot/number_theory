#include<iostream>
#include<ctime>
#include"Integer.h"
using namespace std;

static unsigned __int64 prime_arr[1000] = { 0 };

//���μ� ���� �Լ�
//time�Լ��� �ִ� clock_t ������ �̿��ؼ� �ð����� �Է� �ް�
//�� �� ������ ���̸� CLOCKS_PER_SEC �� �̿��ؼ� �����
//�ð��� �󸶳� �ɷǴ��� �˼��ִ�.
//�� unsinged __int64 ������ ����Ͽ��� ������
//1800�� ������ ���ڱ��� �Ǵ��� �����ϴ�.
//�Ҽ� �Ǻ��� ���� �ٸ��� ����.
void Prime_Arr_Main()
{
	cout << "���μ����� ���α׷� �Դϴ�." << endl;
	unsigned __int64 x;
	cout << "���μ������� ���� �Է��ϼ���." << endl;
	cin >> x;
	clock_t start, end;
	start = clock(); 
	Prime_Arr(x);
	end = clock();
	int i = 0;
	while (i<100)
	{
		if(prime_arr[i]!=0)
		{
			if (i % 2 == 0)
			{
				cout <<' '<< prime_arr[i] ;
			}
			else
			{
				cout << " ^ " << prime_arr[i];
			}
		}
		i++;
	}
	double time = (double)(end - start) / CLOCKS_PER_SEC;
	cout <<"   ���μ������ϴµ� �ɸ� �ð� : " <<time <<"��"<< endl;
}

//���μ� ���� �Լ�
//�Ҽ��� ������ �������� �κ��� �ִٸ�
//������ �������� ���� �ٷ� ����� �Ѵ�.
void Prime_Arr(unsigned __int64 num)
{
	int z = 0, k = 0;
	for (int j=2;j<=num;j++)
	{
		for (int i=2; i*i <= num; i++) //�Ҽ��Ǻ�
		{
			if (num%i == 0)
			{
				prime_arr[z] = i;
				if (prime_arr[k - 2] == prime_arr[k]) // ������ ���� ������ ���� ���ٸ� ī��Ʈ�� �ϰ� �ʱ�ȭ
				{
					prime_arr[z] = i;
					prime_arr[k - 1] += 1;
					prime_arr[k] = 0;
					num /= i;
					break;
				}
				else  // �׳� ���� 
				{
					k += 2;
					prime_arr[z] = i;
					num /= i;
					prime_arr[z + 1] += 1;
					z += 2;
					break;
				}
			}
		}
	}
	prime_arr[z] = num;
	prime_arr[z + 1] += 1;
}