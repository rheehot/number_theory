#include<iostream>
#include"hapdong.h"
using namespace std;

void Complete_Residue_System_Main() {
	int fac = 0;
	int reduced_residue_system[100] = { 0 };//����׿��谡 �ƴѾ��̵� �����Ͽ� �������ִ� �迭
	int *reduced_residue_system_point = NULL;
	reduced_residue_system_point = &reduced_residue_system[0];
	cout << "���� �Է��ϼ���" << endl;
	cin >> fac;
	Perfect_Factor(fac);
	Reduced_Residue_System(fac, reduced_residue_system_point);
	Not_Reduced_Residue_System(fac, reduced_residue_system_point);
	cout << "�� " << fac << " �� ���� a�� �׿����� ����a���� �Է��ϼ���" << endl;
	Residue_Class(fac);

}

//
void Residue_Class(int fac) {
	int num = 0;
	cin >> num;
	if (num > fac) {
		num = num%fac;
	}
	int numsample = num;
	for (int i = 0; i < 3; i++) {
		numsample = numsample - fac;
	}
	for (int i = 0; i < 6; i++) {
		cout << numsample << ' ';
		numsample = numsample + fac;
	}
	cout << endl << "�� �յ��Դϴ�" << endl;
}
//����׿��谡 �������� ���̵��� ���� �� ���
void Not_Reduced_Residue_System(int fac, int *red) {
	int max = 0;
	int i = 0;
	while (1) {
		if (red[0] == 0) {
			break;
		}
		max = red[i];
		cout << fac << " �� " << max << "�� �ִ����� = " << T_Uclid(fac, max) << endl;
		i++;
		if (red[i] == 0) {
			break;
		}
	}
}
//����׿��� ��� �� ����׿��谡 �������� ���̵� �ٸ��迭�� �������ֱ�
void Reduced_Residue_System(int fac, int *red) {
	cout << "<����׿���>" << endl << " [";
	int i = 1;
	int j = 0;
	int k = 0;
	while (1) {
		k = T_Uclid(fac, i);
		if (fac == i) {
			cout << "]" << endl;
			break;
		}
		else if (k != 1) {
			red[j++] = i;
		}
		else {
			cout << i << " ";
		}
		if (i != 0 && i % 25 == 0) {
			cout << endl << ' ';
		}
		i++;
	}
}
//�����׿��踦 ����ϴ� �Լ�
void Perfect_Factor(int fac) {
	cout << "<���� �׿���>" << endl << " [";
	int i = 0;
	while (1) {
		if (i == fac) {
			cout << i << "]" << endl;
			break;
		}
		if (i != 0 && i % 20 == 0) {
			cout << endl << ' ';
		}
		cout << i << ' ';
		i++;
	}
}
//��Ŭ���� �˰���
//���� : �� ���� �ִ������� ���ϰ� ���� return ���ش�.
int T_Uclid(int a, int b) {
	int max = 0;//�ִ����� ����
	int temp = 0;
	if (b == 0) {//b���� 0�� �� �� ����.
		cout << "�Ҽ��Դϴ�" << endl;
		return 0;
	}
	while (1) {
		max = a%b;
		if (max == 1) {
			return max;
		}
		else if (a == 1) {
			return a;
		}
		else if (max == 0) {
			return b;
		}
		else {
			a = b;
			b = max;
		}
	}
}