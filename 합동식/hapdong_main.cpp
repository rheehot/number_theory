#include<iostream>
#include"NumberTheory.h"
using namespace std;

int Hapdong_Main()
{
	int input_hapdong_value = 0;
	cout << "----------------------------------------------" << endl;
	cout << "Part2. �յ�" << endl;
	cout << "1��. �����׿���,����׿���" << endl;
	cout << "2��. ������ ����" << endl;
	cout << "3��. �����յ���" << endl;
	cout << "4��. �����յ����� ����(ISBN 10, 13 �ڸ� �Ǻ�)" << endl;
	cout << "5��. �����յ����� ����(���ڵ� �Ǻ�)" << endl;
	cout << "6��. �����յ����� ����(�ֹε�Ϲ�ȣ �Ǻ�,(���� ������� �� ���))" << endl;
	cout << "7��. �����յ����� ����(�ֹε�Ϲ�ȣ �Ǻ�,(�������� �ǵ�)" << endl;
	cout << "8��. ���������յ���(�߱����� ���������� ����)" << endl;
	cout << "����� �� ���� ���ڸ� �Է��ϸ� �˴ϴ�." << endl;
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
