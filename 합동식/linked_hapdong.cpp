#include<iostream>
#include"hapdong.h"
using namespace std;
static int China_result = 0; //  �߱����� ������ ������ ��갪���� �����ϴ� ����

// ������ : 17.07.15 (��)
// ��  �� : ���������յ����� ���ϱ� ���Ͽ�
// ��  ��
//1. �ִ������� ���ϴ� ��� 2. ������ ���ϴ� ��� 3. �߱����� ������ ���� 4. ���� �ΰ��� �� ������ �� �����ϴ� ���
void Linked_Main()
{
	cout << "���� �����յ��� ���α׷��Դϴ�." << endl;
	int a1 = 0, b1 = 0, m1 = 0;
	int a2 = 0, b2 = 0, m2 = 0;
	int a3 = 0, b3 = 0, m3 = 0;
	int Gcd_count = 1;
	int mod_M;
	int select = 0;
	cout << "2���� �յ����� ����Ͻ÷��� 1��" << endl << "3���� �յ����� ����Ͻ÷��� 2��" << endl;
	cin >> select;
	if (select == 1) // 2���� �����յ���
	{
		cout << "a = b (mod m)�� ���� �Է��� �ּ���." << endl;
		cout << "<����>" << endl << " 4 = 15 (mod 11) -> 4 15 11" << endl;
		cout << " 2x = 7 (mod 13) -> 2 7 13" << endl;
		cout << "ù��° ��" << endl;
		cin >> a1; cin >> b1; cin >> m1;
		cout << a1 << " x = " << b1 << "(mod " << m1 << ")" << endl;
		cout << "�ι�° ��" << endl;
		cin >> a2 >> b2 >> m2;
		cout << a2 << "x = " << b2 << "(mod " << m2 << ")" << endl;
		mod_M = m1 * m2;
		if (Hap_Gcd(m1, m2) == 1)  // ��ⷯ�� �ΰ��� ���μ��� ���
		{
			if (a1 != 1 || a2 != 1) // x = b (mod M) �� ���� �ƴϸ� ����� �ȵǱ� ������ ��ȯ�ϴ� �κ�;
			{
				if (a1 != 1 && a2 != 1)
				{
					Gcd_count = (Hap_Gcd(Hap_Gcd(b1, m1), a1))*(Hap_Gcd(Hap_Gcd(b2, m2), a2));
					b1 = Linked_HapDong(a1, b1, m1);
					a1 = 1;
					b2 = Linked_HapDong(a2, b2, m2);
					a2 = 1;
				}
				else if (a1 != 1)
				{
					b1 = Linked_HapDong(a1, b1, m1);
					a1 = 1;
				}
				else
				{
					b2 = Linked_HapDong(a2, b2, m2);
					a2 = 1;
				}
			}
			if (b1 == b2) // �������� ���� ��ⷯ���� �ٸ���� �ִ������� 1�̸� ��ⷯ���� �����ָ� �ȴ�.
			{
				cout << " a = b(mod m1*m2) " << endl;;
				cout << "x = " << b2 << "(mod " << mod_M << ")" << endl;
			}
			else // �������� �ٸ��� ��ⷯ���� �ٸ��� �߱����� ������ ���� ���
			{
				Sum_China(b1, m1, mod_M);
				Sum_China(b2, m2, mod_M);
				if (Gcd_count != 1) // �ʱ⿡ �ִ������� 1�� �ƴѰ� �����ϸ� �ִ����� ����ŭ �ذ� ���´�.
				{
					for (int i = 0; i < Gcd_count; i++)
					{
						cout << "result : " << (China_result + (mod_M / Gcd_count)*i) % mod_M << " + (" << mod_M << " * K )" << "(mod " << mod_M << "), K�� ������ ����" << endl;
					}
				}
				else
				{
					cout << "result : " << China_result%mod_M << " + (" << mod_M << " * K" << "(mod " << mod_M << ") ), K�� ������ ����" << endl;
				}
			}
		}
		else // ���μҰ� �ƴѰ��
		{
			if (m1 > m2)
			{
				int temp = 0;
				temp = a1; a1 = a2; a2 = temp;
				temp = b1; b1 = b2; b1 = temp;
				temp = m1; m1 = m2; m1 = temp;
			}
			if (a1 != 1 || a2 != 1) // x = b (mod M) �� ���� �ƴϸ� ����� �ȵǱ� ������ ��ȯ�ϴ� �κ�;
			{
				if (a1 != 1 && a2 != 1)
				{
					Gcd_count = (Hap_Gcd(Hap_Gcd(b1, m1), a1))*(Hap_Gcd(Hap_Gcd(b2, m2), a2));
					b1 = Linked_HapDong(a1, b1, m1);
					a1 = 1;
					b2 = Linked_HapDong(a2, b2, m2);
					a2 = 1;
				}
				else if (a1 != 1)
				{
					b1 = Linked_HapDong(a1, b1, m1);
					a1 = 1;
				}
				else
				{
					b2 = Linked_HapDong(a2, b2, m2);
					a2 = 1;
				}
			}
			if (a1 == a2 && b1 == b2) // �������� ���� ��ⷯ���� �ٸ���� �ִ������� 1�̸� ��ⷯ���� �����ָ� �ȴ�.
			{
				cout << " a = b(mod m1*m2) " << endl;;
				cout << "x = " << b2 << "(mod " << mod_M << ")" << endl;
			}
			else // �������� �ٸ��� ��ⷯ���� �ٸ��� �߱����� ������ ���� ���
			{
				int Last_B = 0;
				Gcd_count = Hap_Gcd(m1, b2 - b1);
				cout << "Gcd_count : " << Gcd_count << endl;
				Last_B = Linked_HapDong(m1, b2 - b1, m2); // 2
				Linked_HapDong(1, Last_B, m2 / Gcd_count); // 4
				cout << " x = " << Last_B + m1*Linked_HapDong(1, Last_B, mod_M / Gcd_count) << " (mod " << mod_M / Gcd_count << ")" << endl;
			}
		}
	}
	else if (select == 2)
	{
		cout << "a = b (mod m)�� ���� �Է��� �ּ���." << endl;
		cout << "����) 4 = 15 mod 11 -> 4 15 11" << endl;
		cout << " 2x = 7 mod 13 -> 2 7 13" << endl;
		cout << "ù��° ��" << endl;
		cin >> a1 >> b1 >> m1;
		cout << "�ι�° ��" << endl;
		cin >> a2 >> b2 >> m2;
		cout << "����° ��" << endl;
		cin >> a3 >> b3 >> m3;
		mod_M = m1 * m2*m3;
		if (Hap_Gcd(m1, m2) == 1 && Hap_Gcd(m2, m3) == 1 && Hap_Gcd(m1, m3) == 1)
		{
			if (Hap_Gcd(m1, m2) == 1)  // ��ⷯ�� �ΰ��� ���μ��� ���
			{
				if (a1 != 1 || a2 != 1) // x = b (mod M) �� ���� �ƴϸ� ����� �ȵǱ� ������ ��ȯ�ϴ� �κ�;
				{
					if (a1 != 1 && a2 != 1)
					{
						Gcd_count = (Hap_Gcd(Hap_Gcd(b1, m1), a1))*(Hap_Gcd(Hap_Gcd(b2, m2), a2));
						b1 = Linked_HapDong(a1, b1, m1);
						a1 = 1;
						b2 = Linked_HapDong(a2, b2, m2);
						a2 = 1;
						b3 = Linked_HapDong(a3, b3, m3);
						a3 = 1;
					}
					else if (a1 != 1)
					{
						b1 = Linked_HapDong(a1, b1, m1);
						a1 = 1;
					}
					else if (a2 != 2)
					{
						b2 = Linked_HapDong(a2, b2, m2);
						a2 = 1;
					}
					else
					{
						b3 = Linked_HapDong(a3, b3, m3);
						a3 = 1;
					}
				}
				if (b1 == b2 && b1 == b3) // �������� ���� ��ⷯ���� �ٸ���� �ִ������� 1�̸� ��ⷯ���� �����ָ� �ȴ�.
				{
					cout << " a = b(mod M) " << endl;;
					cout << "x = " << b3 << "(mod " << mod_M << ")" << endl;
				}
				else // �������� �ٸ��� ��ⷯ���� �ٸ��� �߱����� ������ ���� ���
				{
					Sum_China(b1, m1, mod_M);
					Sum_China(b2, m2, mod_M);
					Sum_China(b3, m3, mod_M);
					if (Gcd_count != 1) // �ʱ⿡ �ִ������� 1�� �ƴѰ� �����ϸ� �ִ����� ����ŭ �ذ� ���´�.
					{
						for (int i = 0; i < Gcd_count; i++)
						{
							cout << "result : " << (China_result + (mod_M / Gcd_count)*i) % mod_M << " + (" << mod_M << " * K )" << "(mod " << mod_M << "), K�� ������ ����" << endl;
						}
					}
					else
					{
						cout << "result : " << China_result%mod_M << " + (" << mod_M << " * K" << ") (mod " << mod_M << "), K�� ������ ����" << endl;
					}
				}
			}
		}
		else
		{
			cout << "���� ���� �� �����ϴ�." << endl;
		}
	}
}

/* ������ : 17.07.15(��)
��  �� : �����յ��� �ʼ������� �ΰ��� ��ⷯ ���� �ִ������� 1���� ���ϴ� �Լ�.
��  ��
���׿����ڸ� �̿��Ͽ� m2�� �ڸ��� 0��(0�� ��ǻ�ͷ� ������ �ǹ��ϱ� ����) �ö����� �ݺ�����
������ ���� m1���� ���ϸ� �� m1���� �ִ��������� m1���� return�Ѵ�.*/
int Hap_Gcd(int m1, int m2)
{
	return  m2 ? Hap_Gcd(m2, m1%m2) : m1;
}


/* ������ : 17.07.15(��)
��  �� : �߱����� ������ ������ ������� �� ���ϱ� ���� �Լ�
��  ��
static ���� ������ ������ ���� �����Ͽ��Լ��� ����Ǵ��� ���� ����ȴ�.*/
void Sum_China(int b, int m, int mod_M)
{
	China_result += (b*(mod_M / m)* China_Inverse(m, mod_M));
	cout << " M�� : " << mod_M / m << ' ' << " N�� : " << China_Inverse(m, mod_M) << endl;
}


//	������ : 17.07.15(��)
// ��  �� : �߱����� ������ �������� �ʿ��� ������ ���ϱ� ���ϱ� ���ؼ� ����
int China_Inverse(int m, int mod_M)
{
	int inverse = 1;
	int value = 1;
	while (true)
	{
		if ((((mod_M / m)*value) % m) == 1)
		{
			return value;
		}
		value++;
	}
}

// ������ : 17.07.12 (��)
// ��  �� :  �����յ����� ���ϱ� ����
// ��  �� :  �����յ����� �ظ� �����ش�.
int Linked_HapDong(int a, int b, int m)
{
	int x_result = 1;
	int gcd1 = Hap_Gcd(a, m);
	int gcd2 = Hap_Gcd(gcd1, b);
	if (b%gcd1 == 0)
	{
		if (gcd2 != 1)
		{
			a = a / gcd2; b = b / gcd2; m = m / gcd2;
			while (true)
			{
				if ((a*x_result) % m == b%m)
				{
					return x_result;
				}
				x_result++;
			}
		}
		else
		{
			while (true)
			{
				if ((a*x_result) % m == b%m)
				{
					return x_result;
				}
				x_result++;
			}
		}
	}
}