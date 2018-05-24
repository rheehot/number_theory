#include<iostream>
#include"hapdong.h"
using namespace std;

void Complete_Residue_System_Main() {
	int fac = 0;
	int reduced_residue_system[100] = { 0 };//기약잉여계가 아닌아이들 검출하여 저장해주는 배열
	int *reduced_residue_system_point = NULL;
	reduced_residue_system_point = &reduced_residue_system[0];
	cout << "값을 입력하세요" << endl;
	cin >> fac;
	Perfect_Factor(fac);
	Reduced_Residue_System(fac, reduced_residue_system_point);
	Not_Reduced_Residue_System(fac, reduced_residue_system_point);
	cout << "법 " << fac << " 에 관한 a의 잉여류에 대한a값을 입력하세요" << endl;
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
	cout << endl << "와 합동입니다" << endl;
}
//기약잉여계가 되지못한 아이들의 이유 및 출력
void Not_Reduced_Residue_System(int fac, int *red) {
	int max = 0;
	int i = 0;
	while (1) {
		if (red[0] == 0) {
			break;
		}
		max = red[i];
		cout << fac << " 와 " << max << "의 최대공약수 = " << T_Uclid(fac, max) << endl;
		i++;
		if (red[i] == 0) {
			break;
		}
	}
}
//기약잉여계 출력 및 기약잉여계가 되지못한 아이들 다른배열에 저장해주기
void Reduced_Residue_System(int fac, int *red) {
	cout << "<기약잉여계>" << endl << " [";
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
//완전잉여계를 출력하는 함수
void Perfect_Factor(int fac) {
	cout << "<완전 잉여계>" << endl << " [";
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
//유클리드 알고리즘
//목적 : 두 수의 최대공약수를 구하고 값을 return 해준다.
int T_Uclid(int a, int b) {
	int max = 0;//최대공약수 저장
	int temp = 0;
	if (b == 0) {//b에는 0이 들어갈 수 없다.
		cout << "소수입니다" << endl;
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