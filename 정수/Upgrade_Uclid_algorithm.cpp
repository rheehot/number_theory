#include<iostream>
#include"Integer.h"
using namespace std;

//Ȯ��� ��Ŭ���� ���� �Լ�
void Upgrade_Uclid_Main()
{
	int up_avalue = 0, up_bvalue = 0; //a,b �ʱ�ȭ
	int s1 = 1, s2 = 0, t1 = 0, t2 = 1; //s1,s2,t1,t2 �⺻�� ����
	cout << "Ȯ��� ��Ŭ���� �˰����� �����ϼ̽��ϴ�." << endl;
	cout << "a �� b�� �Է����ּ���." << endl;
	cin >> up_avalue >> up_bvalue;
	Upgrade_Uclid(up_avalue, up_bvalue, s1, s2, t1, t2);
}



// ������ : 17.07.10(��)
// ��  �� : Ȯ��� ��Ŭ���� �˰����� ���� �ִ������� ���ϰ� s���� t���� ���ϰ� �� ���� ��
int Upgrade_Uclid(int a, int b, int s1, int s2, int t1, int t2)
{
	int s = 0, t = 0;
	static int Upgrade_i = 0;
	static int Upgrad_Uclid[100] = { 0 };
	if (b == 0)
	{
		printf(" %6d %3d %7d %3d %7d %3d \n", a, b, s1, s2, t1, t2);//�������� ����Ǵ� ���� ��� ������ s,t�� ���� �ʿ䰡 ����.
		printf(" (%2d x %2d) + (%2d x %2d ) =  %d \n", Upgrad_Uclid[0], s1, Upgrad_Uclid[1], t1, Upgrad_Uclid[0] * s1 + Upgrad_Uclid[1] * t1);
	}
	else
	{
		Upgrad_Uclid[Upgrade_i] = a, Upgrad_Uclid[Upgrade_i + 1] = b; // ������ ���� �����ϱ�����
		s = s1 - ((a / b)*s2); t = t1 - ((a / b)*t2); // S �� s1- (q x s2) ,T �� t1 - ( q x t2)
		printf("%3d %3d %3d %3d %3d %3d %3d %3d %3d %3d \n", a / b, a, b, a%b, s1, s2, s1 - ((a / b)*s2), t1, t2, t1 - ((a / b)*t2));
		Upgrade_i++;
	}
	return b ? Upgrade_Uclid(b, a%b, s2, s, t2, t) : a; // ����Լ� , a%b�� 0�� �Ǹ� ������ ���̻� ������� �����Ƿ� a�� ȣ��ǰ� a�� �ִ����� �̴�.
}