#include<iostream>
#include"NumberTheory.h"
using namespace std;

int Primitive_Root_Main()
{
	int input_Primitive_Root_value = 0;
	cout << "----------------------------------------------" << endl;
	cout << "Part4. ���ñ�" << endl;
	cout << "1��. ���� ���ϴ� ���α׷�" << endl;
	cout << "2��. ���ñ� ���ϴ� ���α׷�" << endl;
	cout << "����� �� ���� ���ڸ� �Է��ϸ� �˴ϴ�." << endl;
	cout << "----------------------------------------------" << endl;
	cin >> input_Primitive_Root_value;
	cout << "----------------------------------------------" << endl;
	switch (input_Primitive_Root_value){
	case 1: // ���� ���ϴ� ���α׷�
		Order_Main();
		break;
	case 2: // ���ñ� ���̺� ���ϴ� ���α׷�
		Primitive_Root_Table_Main();
		break;
	default:
		return 0;
	}
}