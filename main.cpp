#include<iostream>
#include"NumberTheory.h"
using namespace std;

int main()
{
	int select_part = 0;
	cout << endl << "������ ���α׷� �Դϴ�." << endl << endl;
	while (true)
	{
		cout << "----------------------------------------------" << endl;
		cout << "1��. ����" << endl;
		cout << "2��. �յ���" << endl;
		cout << "3��. �丣��, ���Ϸ� ����" << endl;
		cout << "4��. ���ñ�" << endl;
		cout << "����� �� ���� ���ڸ� �Է��ϸ� �˴ϴ�." << endl;
		cout << "----------------------------------------------" << endl;
		cin >> select_part;
		switch (select_part)
		{
		case 1:
			Integer_Main();
			break;
		case 2:
			Hapdong_Main();
			break;
		case 3:
			Fermat_Euler_Main();
			break;
		case 4:
			Primitive_Root_Main();
			break;
		default:
			return 0;
		}
	}
}