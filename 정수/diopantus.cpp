#include<iostream>
#include"Integer.h"
using namespace std;
static int DUclid[100] = { 0 };
static int Di = 0;

void Diopantus_Main()
{
	int a = 0, b = 0, c = 0, greatest_common_diviser = 0, m = 0;
	int x0; /* x�� �Ϲ���*/ int y0;/* y�� �Ϲ��� */
	int x; /* x�� Ư����*/  int	y;/* y�� Ư����*/
	int k1, k2; // ������ ����. 
	int i = 0;
	cout << "��������������� ���α׷��� �����ϼ̽��ϴ�." << endl;
	cout << "�ΰ��� �Ŀ����� ����� �����մϴ�." << endl;
	cout << "ax + by = c ���� a,b,c�� ���� �Է����ּ���." << endl;
	cin >> a >> b >> c;
	greatest_common_diviser = GCD(a, b);
	m = c / greatest_common_diviser; // M��
	cout << a << "��(��) " << b << "�� �ִ������� " << greatest_common_diviser << " �Դϴ�." << endl;
	if (c%greatest_common_diviser == 0)
	{
		cout << "�ذ� ������ �������ϴ�." << endl;
		Diopantus_Uclid(a, b, 1, 0, 0, 1);
		x0 = DUclid[0]; y0 = DUclid[1];
		cout << "x = x0 + ((b/d)*k) , y = y0 + ((a/d)*k) k�� ������ ����" << endl;
		x = x0*m; k1 = (b / greatest_common_diviser);
		y = y0*m; k2 = (a / greatest_common_diviser);
		while (true)
		{
			if (x + (k1*i) > 0 && y + (k2*i) > 0)
			{
				cout << "x�� y�� �Ѵ� ����� ���� �����ϴ� k�� �� : " << i << endl;
				break;
			}
			i++;
		}
		cout << "< Ư���� >" << endl << "x0 : " << x << ' ' << "y0 : " << y << endl;
		cout << "< �Ϲ��� >" << endl;
		cout << " x = " << x << "+(" << k1 << "* k) , �� k�� ������ ����" << endl;
		cout << " y = " << y << "-(" << k2 << "* k) , �� k�� ������ ����" << endl;

	}
	else
	{
		cout << "�ذ� ������ �������� �ʽ��ϴ�." << endl;
	}
}

// ������ : 17.07.11 (ȭ)
// ��  �� : �ִ������� �������� Ȯ���Ͽ� return ��Ű�� ����.
// ��  �� : 1.�ִ������� ������ ���Ѵ�.
//			2.return������ 0�� �ƴ� ������ true�� �ǹ��ϰ� 0�� false �� �ǹ��ϴ� ���� �̿��Ͽ�
//			���׿�����(���ǿ�����)�� �̿��ؼ� ����Լ��� ����� ��Ŭ���� �˰����� ª�� �����ϰ� �������.
int GCD(int a, int b)
{
	int temp = 0;
	if (b != 0)
	{
		cout << a / b << ' ' << a << ' ' << b << ' ' << a%b << endl;
	}
	else
	{
		cout << "  " << a << ' ' << b << endl;
	}
	return b ? GCD(b, a%b) : a;
}

// ������ : 17.07.11(ȭ)
// ��  �� : s���� t���� �̿��ؼ� ��������� �������� �Ϲ��ظ� ���ϱ� ���Ͽ�
// ��  �� : 1. static �Լ��� �̿��Ͽ� ���� ������ ���� �����Ͽ� �Լ��� ����ÿ��� ���� ������� �ʰ� �Ͽ� �����ڸ� �̿��Ͽ� �������� �ʰ�
//			���ʿ��� ȣ���� �ٿ���.
//			2. static �迭�� �ʱⰪ�� ���� �� �ʱ�ȭ �ϸ鼭 ������ �������ְ� ���� ���� ���� �ս��� ���� �� �� �ִ�.
//			3. c++���� ȣȯ�Ǵ� c����� ������ ���� ����� ����ϸ鼭 ��°��� ����ϰ� �����ȴ�
int Diopantus_Uclid(int a, int b, int s1, int s2, int t1, int t2)
{
	int s = 0, t = 0;
	if (b == 0)
	{
		printf(" %6d %3d %7d %3d %7d %3d \n", a, b, s1, s2, t1, t2);
		DUclid[0] = s1, DUclid[1] = t1;
	}
	else
	{
		DUclid[Di] = a, DUclid[Di + 1] = b;
		s = s1 - ((a / b)*s2); t = t1 - ((a / b)*t2);
		printf("%3d %3d %3d %3d %3d %3d %3d %3d %3d %3d \n", a / b, a, b, a%b, s1, s2, s1 - ((a / b)*s2), t1, t2, t1 - ((a / b)*t2));
		Di++;
	}
	return b ? Diopantus_Uclid(b, a%b, s2, s, t2, t) : a;
}