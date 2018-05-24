#include<iostream>
#include"NumberTheory.h"
using namespace std;

int Primitive_Root_Main()
{
	int input_Primitive_Root_value = 0;
	cout << "----------------------------------------------" << endl;
	cout << "Part4. 원시근" << endl;
	cout << "1번. 위수 구하는 프로그램" << endl;
	cout << "2번. 원시근 구하는 프로그램" << endl;
	cout << "종료는 그 외의 숫자를 입력하면 됩니다." << endl;
	cout << "----------------------------------------------" << endl;
	cin >> input_Primitive_Root_value;
	cout << "----------------------------------------------" << endl;
	switch (input_Primitive_Root_value){
	case 1: // 위수 구하는 프로그램
		Order_Main();
		break;
	case 2: // 원시근 테이블 구하는 프로그램
		Primitive_Root_Table_Main();
		break;
	default:
		return 0;
	}
}