#include<iostream>
#include"NumberTheory.h"
using namespace std;

int main()
{
	int select_part = 0;
	cout << endl << "정수론 프로그램 입니다." << endl << endl;
	while (true)
	{
		cout << "----------------------------------------------" << endl;
		cout << "1번. 정수" << endl;
		cout << "2번. 합동식" << endl;
		cout << "3번. 페르마, 오일러 정리" << endl;
		cout << "4번. 원시근" << endl;
		cout << "종료는 그 외의 숫자를 입력하면 됩니다." << endl;
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