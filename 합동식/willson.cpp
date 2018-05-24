#include<iostream>
#include"hapdong.h"
using namespace std;

void Willson_Main() {
	unsigned __int64 num = 0;
	int fac = 0;
	cout << "값을 입력하세요" << endl;
	cin >> num;
	if (prime_number(num)) {
		fac = factoreal(num - 1, num);
		cout << fac << endl;
	}
}
//소수판별함수
//목적 : 소수인지 합성수인지 판단하고
//       참인지 거짓인지 리턴시킨다.
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
		cout << "5이상의 소수만 가능합니다" << endl;
		return false;
	}
	else if (a[1] == 0) {
		cout << "소수입니다" << endl << "연산을 시작합니다" << endl;
		return true;
	}
	else {
		cout << "합성수입니다" << endl;
		return false;
	}
}
//팩토리얼 함수
//목적 : 팩토리얼함수는 13만 해도 억단위를
//       넘기때문에 값을 계속해서 최소화  
//       시키면서 값을 리턴시켜준다.
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