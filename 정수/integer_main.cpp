#include<iostream>
#include"NumberTheory.h"
using namespace std;

int Integer_Main()
{
	int input_Integer_value = 0;
	cout <<  "----------------------------------------------" << endl;
	cout << "Part1. ����" << endl;
	cout << "1��. ���| ��� " << endl;
	cout << "2��. �ִ�����" << endl;
	cout << "3��. ������ ����" << endl;
	cout << "4��. ��Ŭ���� ȣ����" << endl;
	cout << "5��. ��Ŭ���� �˰���" << endl;
	cout << "6��. Ȯ��� ��Ŭ���� �˰���" << endl;
	cout << "7��. ��������� ������" << endl;
	cout << "8��. �Ҽ� �Ǻ� �˰���" << endl;
	cout << "9��. ���μ�����" << endl;
	cout << "10��. �����佺�׳׽��� ü" << endl;
	cout << "����� �� ���� ���ڸ� �Է��ϸ� �˴ϴ�." << endl;
	cout << "----------------------------------------------" << endl;
	cin >> input_Integer_value;
	cout << "----------------------------------------------" << endl;
	switch (input_Integer_value)
	{
	case 1://���: ���
		Divisor_Multiple_Main();
		break;
	case 2: //�ִ�����
		GCD_Main();
		break;
	case 3://������ �����
		Divison_Algorithm_Main();
		break;
	case 4://��Ŭ���� ȣ����
		Euclidean_Algorithm_Main();
		break;
	case 5: // ��Ŭ���� �˰���
		Uclid_Main();
		break;
	case 6: // Ȯ��� ��Ŭ���� �˰���
		Upgrade_Uclid_Main();
		break;
	case 7: // ��������� ������ 
		Diopantus_Main();
		break;
	case 8: //�Ҽ� �Ǻ� �˰���
		Is_Prime_Main();
		break;
	case 9: //���μ�����
		Prime_Arr_Main();
		break;
	case 10: //�����佺�׳׽��� ü
		Eratostenes_Main();
		break;
	default:
		return 0;
	}
}