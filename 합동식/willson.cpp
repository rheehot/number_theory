#include<iostream>
#include"hapdong.h"
using namespace std;

void Willson_Main() {
	unsigned __int64 num = 0;
	int fac = 0;
	cout << "���� �Է��ϼ���" << endl;
	cin >> num;
	if (prime_number(num)) {
		fac = factoreal(num - 1, num);
		cout << fac << endl;
	}
}
//�Ҽ��Ǻ��Լ�
//���� : �Ҽ����� �ռ������� �Ǵ��ϰ�
//       ������ �������� ���Ͻ�Ų��.
bool prime_number(int num) {
	int a[100] = { 0 };
	int j = 0;
	for (int i = 2; i <= num / 2; i++) {
		if (num%i == 0) {
			a[j] = i;
			j++;
		}
	}
	if (num == 2 || num == 3) {
		cout << "5�̻��� �Ҽ��� �����մϴ�" << endl;
		return false;
	}
	else if (a[1] == 0) {
		cout << "�Ҽ��Դϴ�" << endl << "������ �����մϴ�" << endl;
		return true;
	}
	else {
		cout << "�ռ����Դϴ�" << endl;
		return false;
	}
}
//���丮�� �Լ�
//���� : ���丮���Լ��� 13�� �ص� �������
//       �ѱ⶧���� ���� ����ؼ� �ּ�ȭ  
//       ��Ű�鼭 ���� ���Ͻ����ش�.
unsigned __int64 factoreal(unsigned __int64 num, unsigned __int64 mod) {
	unsigned __int64 fac = 1;
	for (int i = num; i > 1; i--) {
		fac *= i;
		if (fac > mod) {
			fac = fac%mod;
		}
	}
	return fac;
}