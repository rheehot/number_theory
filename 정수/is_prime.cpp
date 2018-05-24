#include<iostream>
#include<ctime>
#include"Integer.h"
using namespace std;

//�Ҽ� �Ǻ� ���� �Լ�
//���
//time�Լ��� �ִ� clock_t ������ �̿��ؼ� �ð����� �Է� �ް�
//�� �� ������ ���̸� CLOCKS_PER_SEC �� �̿��ؼ� �����
//�ð��� �󸶳� �ɷǴ��� �˼��ִ�.
//�� unsinged __int64 ������ ����Ͽ��� ������
//1800�� ������ ���ڱ��� �Ǵ��� �����ϴ�.
void Is_Prime_Main()
{
	cout << "�Ҽ��Ǻ� ���α׷��Դϴ�." << endl;
	unsigned __int64 x;
	cout << "�Ҽ����� �Ǻ��� ���� �Է��ϼ���." << endl;
	cin >> x;
	clock_t start, end;
	start = clock();
	Is_Prime(x);
	end = clock();
	double time = (double)(end - start) / CLOCKS_PER_SEC;
	cout << time << endl;
}

//�Ҽ� �Ǻ� �Լ�
bool Is_Prime(unsigned __int64 num)
{
	for (int i = 3; i*i <= num; i += 2)
	{
		if (num % 2 == 0)
		{
			num /= 2;
			cout << "2�� ������ �������ϴ�." << endl;
			cout << "�ռ����Դϴ�." << endl;
			return false;
		}
		else if (num % i == 0)
		{
			num /= i;
			cout << i << "�� ������ �������ϴ�." << endl;
			cout << "�ռ����Դϴ�." << endl;
			return false;
		}
	}
	cout << "�Ҽ��Դϴ�." << endl;
	return true;
}