#include<iostream>
#include"NumberTheory.h"
using namespace std;

int Fermat_Euler_Main()
{
	int input_Fermat_Euler_value = 0;
	cout << "----------------------------------------------" << endl;
	cout << "Part3. �丣�� ���Ϸ��� ����" << endl;
	cout << "1��. ���Ϸ� �Լ�, ���Ϸ� ����" << endl;
	cout << "2��. �丣�� ����, �丣�� ������ �̿��� �������ϱ�" << endl;
	cout << "����� �� ���� ���ڸ� �Է��ϸ� �˴ϴ�." << endl;
	cout << "----------------------------------------------" << endl;
	cin >> input_Fermat_Euler_value;
	cout << "----------------------------------------------" << endl;
	switch (input_Fermat_Euler_value)
	{
	case 1: // �������ϱ�
		Euler_Main();
		break;
	case 2: // 
		FerMat_Main();
		break;
	default:
		return 0;
	}
}