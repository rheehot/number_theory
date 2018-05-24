#include<iostream>
#include"Integer.h"
using namespace std;

//확장된 유클리드 실행 함수
void Upgrade_Uclid_Main()
{
	int up_avalue = 0, up_bvalue = 0; //a,b 초기화
	int s1 = 1, s2 = 0, t1 = 0, t2 = 1; //s1,s2,t1,t2 기본값 설정
	cout << "확장된 유클리드 알고리즘을 실행하셨습니다." << endl;
	cout << "a 와 b를 입력해주세요." << endl;
	cin >> up_avalue >> up_bvalue;
	Upgrade_Uclid(up_avalue, up_bvalue, s1, s2, t1, t2);
}



// 생성일 : 17.07.10(월)
// 목  적 : 확장된 유클리드 알고리즘을 통해 최대공약수를 구하고 s값과 t값을 구하고 이 식을 이
int Upgrade_Uclid(int a, int b, int s1, int s2, int t1, int t2)
{
	int s = 0, t = 0;
	static int Upgrade_i = 0;
	static int Upgrad_Uclid[100] = { 0 };
	if (b == 0)
	{
		printf(" %6d %3d %7d %3d %7d %3d \n", a, b, s1, s2, t1, t2);//마지막에 실행되는 문장 몫과 나머지 s,t의 값은 필요가 없다.
		printf(" (%2d x %2d) + (%2d x %2d ) =  %d \n", Upgrad_Uclid[0], s1, Upgrad_Uclid[1], t1, Upgrad_Uclid[0] * s1 + Upgrad_Uclid[1] * t1);
	}
	else
	{
		Upgrad_Uclid[Upgrade_i] = a, Upgrad_Uclid[Upgrade_i + 1] = b; // 최초의 값을 저장하기위함
		s = s1 - ((a / b)*s2); t = t1 - ((a / b)*t2); // S 는 s1- (q x s2) ,T 는 t1 - ( q x t2)
		printf("%3d %3d %3d %3d %3d %3d %3d %3d %3d %3d \n", a / b, a, b, a%b, s1, s2, s1 - ((a / b)*s2), t1, t2, t1 - ((a / b)*t2));
		Upgrade_i++;
	}
	return b ? Upgrade_Uclid(b, a%b, s2, s, t2, t) : a; // 재귀함수 , a%b가 0이 되면 연산이 더이상 진행되지 않으므로 a가 호출되고 a는 최대공약수 이다.
}