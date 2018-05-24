#include<iostream>
#include"NumberTheory.h"
using namespace std;

int Hapdong_Main()
{
	int input_hapdong_value = 0;
	cout << "----------------------------------------------" << endl;
	cout << "Part2. 합동" << endl;
	cout << "1번. 완전잉여계,기약잉여계" << endl;
	cout << "2번. 윌슨의 정리" << endl;
	cout << "3번. 일차합동식" << endl;
	cout << "4번. 일차합동식의 응용(ISBN 10, 13 자리 판별)" << endl;
	cout << "5번. 일차합동식의 응용(바코드 판별)" << endl;
	cout << "6번. 일차합동식의 응용(주민등록번호 판별,(에러 상관없이 값 계산))" << endl;
	cout << "7번. 일차합동식의 응용(주민등록번호 판별,(에러까지 판독)" << endl;
	cout << "8번. 연립일차합동식(중국인의 나머지정리 포함)" << endl;
	cout << "종료는 그 외의 숫자를 입력하면 됩니다." << endl;
	cout << "----------------------------------------------" << endl;
	cin >> input_hapdong_value;
	cout << "----------------------------------------------" << endl;
	switch (input_hapdong_value)
	{
	case 1:
		Complete_Residue_System_Main();
		break;
	case 2:
		Willson_Main();
		break;
	case 3:
		First_Hapdong_Main();
		break;
	case 4:
		Isbn_Main();
		break;
	case 5:
		Bar_Cod_Main();
		break;
	case 6:
		Identify_Testing_Main();
		break;
	case 7:
		Identify_Main();
		break;
	case 8:
		Linked_Main();
		break;
	default:
		return 0;
	}
}
