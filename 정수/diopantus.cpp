#include<iostream>
#include"Integer.h"
using namespace std;
static int DUclid[100] = { 0 };
static int Di = 0;

void Diopantus_Main()
{
	int a = 0, b = 0, c = 0, greatest_common_diviser = 0, m = 0;
	int x0; /* x의 일반해*/ int y0;/* y의 일반해 */
	int x; /* x의 특수해*/  int	y;/* y의 특수해*/
	int k1, k2; // 임의의 정수. 
	int i = 0;
	cout << "디오판투스방정식 프로그램을 실행하셨습니다." << endl;
	cout << "두개의 식에서만 계산이 가능합니다." << endl;
	cout << "ax + by = c 에서 a,b,c에 대해 입력해주세요." << endl;
	cin >> a >> b >> c;
	greatest_common_diviser = GCD(a, b);
	m = c / greatest_common_diviser; // M값
	cout << a << "와(과) " << b << "의 최대공약수는 " << greatest_common_diviser << " 입니다." << endl;
	if (c%greatest_common_diviser == 0)
	{
		cout << "해가 나누어 떨어집니다." << endl;
		Diopantus_Uclid(a, b, 1, 0, 0, 1);
		x0 = DUclid[0]; y0 = DUclid[1];
		cout << "x = x0 + ((b/d)*k) , y = y0 + ((a/d)*k) k는 임의의 정수" << endl;
		x = x0*m; k1 = (b / greatest_common_diviser);
		y = y0*m; k2 = (a / greatest_common_diviser);
		while (true)
		{
			if (x + (k1*i) > 0 && y + (k2*i) > 0)
			{
				cout << "x와 y가 둘다 양수일 때를 만족하는 k의 값 : " << i << endl;
				break;
			}
			i++;
		}
		cout << "< 특수해 >" << endl << "x0 : " << x << ' ' << "y0 : " << y << endl;
		cout << "< 일반해 >" << endl;
		cout << " x = " << x << "+(" << k1 << "* k) , 단 k는 임의의 정수" << endl;
		cout << " y = " << y << "-(" << k2 << "* k) , 단 k는 임의의 정수" << endl;

	}
	else
	{
		cout << "해가 나누어 떨어지지 않습니다." << endl;
	}
}

// 생성일 : 17.07.11 (화)
// 목  적 : 최대공약수가 무었인지 확인하여 return 시키기 위함.
// 기  능 : 1.최대공약수가 얼마인지 구한다.
//			2.return값에서 0이 아닌 정수는 true를 의미하고 0은 false 를 의미하는 것을 이용하여
//			삼항연산자(조건연산자)를 이용해서 재귀함수를 만들어 유클리드 알고리즘을 짧고 간결하게 만들었다.
int GCD(int a, int b)
{
	int temp = 0;
	if (b != 0)
	{
		cout << a / b << ' ' << a << ' ' << b << ' ' << a%b << endl;
	}
	else
	{
		cout << "  " << a << ' ' << b << endl;
	}
	return b ? GCD(b, a%b) : a;
}

// 생성일 : 17.07.11(화)
// 목  적 : s값과 t값을 이용해서 디오판투스 방정식의 일반해를 구하기 위하여
// 기  능 : 1. static 함수를 이용하여 정적 영역에 값을 저장하여 함수가 종료시에도 값이 사라지지 않게 하여 참조자를 이용하여 리턴하지 않고
//			불필요한 호출을 줄였다.
//			2. static 배열의 초기값에 값을 재 초기화 하면서 실제로 리턴해주고 싶은 값에 대해 손쉽게 접근 할 수 있다.
//			3. c++에서 호환되는 c언어의 오른쪽 정렬 기능을 사용하면서 출력값이 깔끔하게 정리된다
int Diopantus_Uclid(int a, int b, int s1, int s2, int t1, int t2)
{
	int s = 0, t = 0;
	if (b == 0)
	{
		printf(" %6d %3d %7d %3d %7d %3d \n", a, b, s1, s2, t1, t2);
		DUclid[0] = s1, DUclid[1] = t1;
	}
	else
	{
		DUclid[Di] = a, DUclid[Di + 1] = b;
		s = s1 - ((a / b)*s2); t = t1 - ((a / b)*t2);
		printf("%3d %3d %3d %3d %3d %3d %3d %3d %3d %3d \n", a / b, a, b, a%b, s1, s2, s1 - ((a / b)*s2), t1, t2, t1 - ((a / b)*t2));
		Di++;
	}
	return b ? Diopantus_Uclid(b, a%b, s2, s, t2, t) : a;
}