#include<iostream>
#include"NumberTheory.h"
using namespace std;

int Fermat_Euler_Main()
{
	int input_Fermat_Euler_value = 0;
	cout << "----------------------------------------------" << endl;
	cout << "Part3. 페르마 오일러의 정리" << endl;
	cout << "1번. 오일러 함수, 오일러 정리" << endl;
	cout << "2번. 페르마 정리, 페르마 정리를 이용한 역원구하기" << endl;
	cout << "종료는 그 외의 숫자를 입력하면 됩니다." << endl;
	cout << "----------------------------------------------" << endl;
	cin >> input_Fermat_Euler_value;
	cout << "----------------------------------------------" << endl;
	switch (input_Fermat_Euler_value)
	{
	case 1: // 위수구하기
		Euler_Main();
		break;
	case 2: // 
		FerMat_Main();
		break;
	default:
		return 0;
	}
}