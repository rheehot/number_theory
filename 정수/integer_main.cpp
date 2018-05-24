#include<iostream>
#include"NumberTheory.h"
using namespace std;

int Integer_Main()
{
	int input_Integer_value = 0;
	cout <<  "----------------------------------------------" << endl;
	cout << "Part1. 정수" << endl;
	cout << "1번. 약수| 배수 " << endl;
	cout << "2번. 최대공약수" << endl;
	cout << "3번. 나눗셈 정리" << endl;
	cout << "4번. 유클리드 호제법" << endl;
	cout << "5번. 유클리드 알고리즘" << endl;
	cout << "6번. 확장된 유클리드 알고리즘" << endl;
	cout << "7번. 디오판투스 방정식" << endl;
	cout << "8번. 소수 판별 알고리즘" << endl;
	cout << "9번. 소인수분해" << endl;
	cout << "10번. 에라토스테네스의 체" << endl;
	cout << "종료는 그 외의 숫자를 입력하면 됩니다." << endl;
	cout << "----------------------------------------------" << endl;
	cin >> input_Integer_value;
	cout << "----------------------------------------------" << endl;
	switch (input_Integer_value)
	{
	case 1://약수: 배수
		Divisor_Multiple_Main();
		break;
	case 2: //최대공약수
		GCD_Main();
		break;
	case 3://나눗셈 관계식
		Divison_Algorithm_Main();
		break;
	case 4://유클리드 호제법
		Euclidean_Algorithm_Main();
		break;
	case 5: // 유클리드 알고리즘
		Uclid_Main();
		break;
	case 6: // 확장된 유클리드 알고리즘
		Upgrade_Uclid_Main();
		break;
	case 7: // 디오판투스 방정식 
		Diopantus_Main();
		break;
	case 8: //소수 판별 알고리즘
		Is_Prime_Main();
		break;
	case 9: //소인수분해
		Prime_Arr_Main();
		break;
	case 10: //에라토스테네스의 체
		Eratostenes_Main();
		break;
	default:
		return 0;
	}
}