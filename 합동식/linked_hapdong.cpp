#include<iostream>
#include"hapdong.h"
using namespace std;
static int China_result = 0; //  중국인의 나머지 정리의 계산값들을 저장하는 공간

// 생성일 : 17.07.15 (토)
// 목  적 : 연립일차합동식을 구하기 위하여
// 기  능
//1. 최대공약수를 구하는 기능 2. 역원을 구하는 기능 3. 중국인의 나머지 정리 4. 항이 두개일 때 세개일 때 선택하는 기능
void Linked_Main()
{
	cout << "연립 일차합동식 프로그램입니다." << endl;
	int a1 = 0, b1 = 0, m1 = 0;
	int a2 = 0, b2 = 0, m2 = 0;
	int a3 = 0, b3 = 0, m3 = 0;
	int Gcd_count = 1;
	int mod_M;
	int select = 0;
	cout << "2개의 합동식을 계산하시려면 1번" << endl << "3개의 합동식을 계산하시려면 2번" << endl;
	cin >> select;
	if (select == 1) // 2개의 연립합동식
	{
		cout << "a = b (mod m)의 꼴을 입력해 주세요." << endl;
		cout << "<예시>" << endl << " 4 = 15 (mod 11) -> 4 15 11" << endl;
		cout << " 2x = 7 (mod 13) -> 2 7 13" << endl;
		cout << "첫번째 식" << endl;
		cin >> a1; cin >> b1; cin >> m1;
		cout << a1 << " x = " << b1 << "(mod " << m1 << ")" << endl;
		cout << "두번째 식" << endl;
		cin >> a2 >> b2 >> m2;
		cout << a2 << "x = " << b2 << "(mod " << m2 << ")" << endl;
		mod_M = m1 * m2;
		if (Hap_Gcd(m1, m2) == 1)  // 모듈러값 두개가 서로소인 경우
		{
			if (a1 != 1 || a2 != 1) // x = b (mod M) 의 꼴이 아니면 계산이 안되기 때문에 변환하는 부분;
			{
				if (a1 != 1 && a2 != 1)
				{
					Gcd_count = (Hap_Gcd(Hap_Gcd(b1, m1), a1))*(Hap_Gcd(Hap_Gcd(b2, m2), a2));
					b1 = Linked_HapDong(a1, b1, m1);
					a1 = 1;
					b2 = Linked_HapDong(a2, b2, m2);
					a2 = 1;
				}
				else if (a1 != 1)
				{
					b1 = Linked_HapDong(a1, b1, m1);
					a1 = 1;
				}
				else
				{
					b2 = Linked_HapDong(a2, b2, m2);
					a2 = 1;
				}
			}
			if (b1 == b2) // 나머지는 같고 모듈러값만 다른경우 최대공약수가 1이면 모듈러값만 곱해주면 된다.
			{
				cout << " a = b(mod m1*m2) " << endl;;
				cout << "x = " << b2 << "(mod " << mod_M << ")" << endl;
			}
			else // 나머지가 다르고 모듈러값도 다르면 중국인의 나머지 정리 사용
			{
				Sum_China(b1, m1, mod_M);
				Sum_China(b2, m2, mod_M);
				if (Gcd_count != 1) // 초기에 최대공약수가 1이 아닌게 존재하면 최대공약수 값만큼 해가 나온다.
				{
					for (int i = 0; i < Gcd_count; i++)
					{
						cout << "result : " << (China_result + (mod_M / Gcd_count)*i) % mod_M << " + (" << mod_M << " * K )" << "(mod " << mod_M << "), K는 임의의 정수" << endl;
					}
				}
				else
				{
					cout << "result : " << China_result%mod_M << " + (" << mod_M << " * K" << "(mod " << mod_M << ") ), K는 임의의 정수" << endl;
				}
			}
		}
		else // 서로소가 아닌경우
		{
			if (m1 > m2)
			{
				int temp = 0;
				temp = a1; a1 = a2; a2 = temp;
				temp = b1; b1 = b2; b1 = temp;
				temp = m1; m1 = m2; m1 = temp;
			}
			if (a1 != 1 || a2 != 1) // x = b (mod M) 의 꼴이 아니면 계산이 안되기 때문에 변환하는 부분;
			{
				if (a1 != 1 && a2 != 1)
				{
					Gcd_count = (Hap_Gcd(Hap_Gcd(b1, m1), a1))*(Hap_Gcd(Hap_Gcd(b2, m2), a2));
					b1 = Linked_HapDong(a1, b1, m1);
					a1 = 1;
					b2 = Linked_HapDong(a2, b2, m2);
					a2 = 1;
				}
				else if (a1 != 1)
				{
					b1 = Linked_HapDong(a1, b1, m1);
					a1 = 1;
				}
				else
				{
					b2 = Linked_HapDong(a2, b2, m2);
					a2 = 1;
				}
			}
			if (a1 == a2 && b1 == b2) // 나머지는 같고 모듈러값만 다른경우 최대공약수가 1이면 모듈러값만 곱해주면 된다.
			{
				cout << " a = b(mod m1*m2) " << endl;;
				cout << "x = " << b2 << "(mod " << mod_M << ")" << endl;
			}
			else // 나머지가 다르고 모듈러값도 다르면 중국인의 나머지 정리 사용
			{
				int Last_B = 0;
				Gcd_count = Hap_Gcd(m1, b2 - b1);
				cout << "Gcd_count : " << Gcd_count << endl;
				Last_B = Linked_HapDong(m1, b2 - b1, m2); // 2
				Linked_HapDong(1, Last_B, m2 / Gcd_count); // 4
				cout << " x = " << Last_B + m1*Linked_HapDong(1, Last_B, mod_M / Gcd_count) << " (mod " << mod_M / Gcd_count << ")" << endl;
			}
		}
	}
	else if (select == 2)
	{
		cout << "a = b (mod m)의 꼴을 입력해 주세요." << endl;
		cout << "예시) 4 = 15 mod 11 -> 4 15 11" << endl;
		cout << " 2x = 7 mod 13 -> 2 7 13" << endl;
		cout << "첫번째 식" << endl;
		cin >> a1 >> b1 >> m1;
		cout << "두번째 식" << endl;
		cin >> a2 >> b2 >> m2;
		cout << "세번째 식" << endl;
		cin >> a3 >> b3 >> m3;
		mod_M = m1 * m2*m3;
		if (Hap_Gcd(m1, m2) == 1 && Hap_Gcd(m2, m3) == 1 && Hap_Gcd(m1, m3) == 1)
		{
			if (Hap_Gcd(m1, m2) == 1)  // 모듈러값 두개가 서로소인 경우
			{
				if (a1 != 1 || a2 != 1) // x = b (mod M) 의 꼴이 아니면 계산이 안되기 때문에 변환하는 부분;
				{
					if (a1 != 1 && a2 != 1)
					{
						Gcd_count = (Hap_Gcd(Hap_Gcd(b1, m1), a1))*(Hap_Gcd(Hap_Gcd(b2, m2), a2));
						b1 = Linked_HapDong(a1, b1, m1);
						a1 = 1;
						b2 = Linked_HapDong(a2, b2, m2);
						a2 = 1;
						b3 = Linked_HapDong(a3, b3, m3);
						a3 = 1;
					}
					else if (a1 != 1)
					{
						b1 = Linked_HapDong(a1, b1, m1);
						a1 = 1;
					}
					else if (a2 != 2)
					{
						b2 = Linked_HapDong(a2, b2, m2);
						a2 = 1;
					}
					else
					{
						b3 = Linked_HapDong(a3, b3, m3);
						a3 = 1;
					}
				}
				if (b1 == b2 && b1 == b3) // 나머지는 같고 모듈러값만 다른경우 최대공약수가 1이면 모듈러값만 곱해주면 된다.
				{
					cout << " a = b(mod M) " << endl;;
					cout << "x = " << b3 << "(mod " << mod_M << ")" << endl;
				}
				else // 나머지가 다르고 모듈러값도 다르면 중국인의 나머지 정리 사용
				{
					Sum_China(b1, m1, mod_M);
					Sum_China(b2, m2, mod_M);
					Sum_China(b3, m3, mod_M);
					if (Gcd_count != 1) // 초기에 최대공약수가 1이 아닌게 존재하면 최대공약수 값만큼 해가 나온다.
					{
						for (int i = 0; i < Gcd_count; i++)
						{
							cout << "result : " << (China_result + (mod_M / Gcd_count)*i) % mod_M << " + (" << mod_M << " * K )" << "(mod " << mod_M << "), K는 임의의 정수" << endl;
						}
					}
					else
					{
						cout << "result : " << China_result%mod_M << " + (" << mod_M << " * K" << ") (mod " << mod_M << "), K는 임의의 정수" << endl;
					}
				}
			}
		}
		else
		{
			cout << "값을 구할 수 없습니다." << endl;
		}
	}
}

/* 생성일 : 17.07.15(토)
목  적 : 연립합동식 필수조건인 두개의 모듈러 값이 최대공약수가 1인지 구하는 함수.
설  명
삼항연산자를 이용하여 m2의 자리에 0이(0은 컴퓨터로 거짓을 의미하기 때문) 올때까지 반복시켜
거짓일 때의 m1값을 구하면 그 m1값은 최대공약수여서 m1값을 return한다.*/
int Hap_Gcd(int m1, int m2)
{
	return  m2 ? Hap_Gcd(m2, m1%m2) : m1;
}


/* 생성일 : 17.07.15(토)
목  적 : 중국인의 나머지 정리의 결과값을 다 더하기 위한 함수
설  명
static 으로 선언한 공간에 값을 저장하여함수가 종료되더라도 값은 저장된다.*/
void Sum_China(int b, int m, int mod_M)
{
	China_result += (b*(mod_M / m)* China_Inverse(m, mod_M));
	cout << " M값 : " << mod_M / m << ' ' << " N값 : " << China_Inverse(m, mod_M) << endl;
}


//	생성일 : 17.07.15(토)
// 목  적 : 중국인의 나머지 정리에서 필요한 역원을 구하기 위하기 위해서 만듬
int China_Inverse(int m, int mod_M)
{
	int inverse = 1;
	int value = 1;
	while (true)
	{
		if ((((mod_M / m)*value) % m) == 1)
		{
			return value;
		}
		value++;
	}
}

// 생성일 : 17.07.12 (수)
// 목  적 :  일차합동식을 구하기 위해
// 기  능 :  일차합동식의 해를 구해준다.
int Linked_HapDong(int a, int b, int m)
{
	int x_result = 1;
	int gcd1 = Hap_Gcd(a, m);
	int gcd2 = Hap_Gcd(gcd1, b);
	if (b%gcd1 == 0)
	{
		if (gcd2 != 1)
		{
			a = a / gcd2; b = b / gcd2; m = m / gcd2;
			while (true)
			{
				if ((a*x_result) % m == b%m)
				{
					return x_result;
				}
				x_result++;
			}
		}
		else
		{
			while (true)
			{
				if ((a*x_result) % m == b%m)
				{
					return x_result;
				}
				x_result++;
			}
		}
	}
}