#include<iostream> 
#include"Primitive_Root.h"
using namespace std;

#define MAX_SIZE 10000000
#define SWAP(x,y,t) ( (t)=(x), (x)=(y), (y)=(t) );
static unsigned __int64 G_Prime[MAX_SIZE] = { 0 }; //소인수 분해된 소수들의 저장공간
static unsigned __int64 G_Divisor[MAX_SIZE] = { 0 }; // 오일러 값의 약수들의 저장공간
static unsigned __int64 G_Table[MAX_SIZE] = { 0 }; //원시근 값들을 랜덤하게 배열한 장소
static unsigned __int64 True_G[MAX_SIZE] = { 0 }; // 랜덤하게 저장된 값을고쳐서 보내는 장소

// 생성일 : 17.07.06
// 목  적 : 연산오류 나서 정수론용 POW랑 MOD 만듬
class Template_class
{
public:
	template <typename T>
	T POW(T  num, T exp, T mod) // 밑, 지수, 모듈러값 <- 정수론용..
	{
		T temp = 1;
		for (T i = 0; i < exp; i++)
		{
			temp *= num;
			temp = MOD(temp, mod);
		}
		return temp;
	}
	template <typename M>
	M MOD(M num, M mod)
	{
		M i = num / mod;
		while (true)
		{
			if (num>mod)
			{
				while (num>mod)
				{
					num = num - mod;
				}
				return num;
			}
			else
			{
				return num;
			}
		}
	}
};

// 생성완료일 : 17.07.07 (금)
// 구현한기능 : 소수판별함수,소인수분해,오일러함수,위수,원시근,유클리드알고리즘,에라토스테네스의 체 
void Primitive_Root_Table_Main()
{
	cout << "원시근 테이블을 구하는 프로그램입니다." << endl;
	cout << "<설명>" << endl << "입력한 법 M에 대한 원시근들을 구해주는 프로그램입니다." << endl;
	cout << "너무 큰수를 입력하게 되면 시간이 오래걸립니다." << endl;
	unsigned long long int number = 0;
	cout << "법M , 모듈러 값을 입력하세요" << endl;
	cin >> number;
	if (number == 1)
	{
		cout << "1은 구할 수 없습니다." << endl;
	}
	else
	{
		unsigned long long int temp = Primitive_Root_Euler(number);
		Show_G_Prime();
		cout << "Euler : " << temp << endl;
		G_Prime_Divisor(temp);
		cout << "Euler's Divisor : ";	Show_G_Divisor();
		Create_G_Table(Primitive_Root_Order(number), number, temp);
		G_show(number, temp);
		cout << endl;
	}
	Clear();
}

// 쓰고난 값들을 다 초기화 해주기위해서 만든 초기화 함수
void Clear()
{
	for (int count = 0; count < MAX_SIZE; count++)
	{
		G_Prime[count] = 0;
		G_Divisor[count] = 0;
		G_Table[count] = 0;
		True_G[count] = 0;
	}
}



// 생성일 : 17.07.02(일)
// 목  적 : 소수 출력 함수
void Show_G_Prime()
{
	int i = 0;
	while (G_Prime[i] != 0)
	{
		if (i % 2 == 0)
		{
			cout << G_Prime[i] << '^';
			i++;
		}
		else
		{
			if (G_Prime[i + 1] == 0)
			{
				cout << G_Prime[i] << " -> ";
				break;
			}
			else
			{
				cout << G_Prime[i] << '*';
				i++;
			}
		}
	}
	if (G_Prime[2] == 0 && G_Prime[1] == 1) {
		cout << "소수입니다.";
	}
	else
	{
		cout << "합성수입니다.";
	}
	cout << endl;
}



// 생성일 : 17.06.29(목)
// 목  적 : bool 함수를 이용하여 소수 판별후 true, false 를 판단하게 하는 함수 , + 소인수 분해를 위해 값을 저장하는 기능
bool G_IsPrime(unsigned __int64 num)
{
	int z = 0, k = 0, i = 2, j = 0;
	int count = 1;
	for (j; j <= 10; j++)
	{
		for (i; i < num; i++) //소수판별
		{
			if (num%i == 0)
			{
				G_Prime[z] = i;
				if (G_Prime[k - 2] == G_Prime[k]) // 현재의 값과 과거의 값이 같다면 카운트업 하고 초기화
				{
					G_Prime[z] = i;
					G_Prime[k - 1] += count;
					G_Prime[k] = 0;
					num /= i;
					break;
				}
				else  // 그냥 진행 
				{
					k += 2;
					G_Prime[z] = i;
					num /= i;
					G_Prime[z + 1] += count;
					z += 2;
					break;
				}
			}
		}
	}
	if (G_Prime[1] == 0 && G_Prime[2] == 0) // 소수이면 나누어 지는게 없으므로 입력값이 소수 
	{
		G_Prime[0] = num;
		G_Prime[1] += count;
		return true;
	}
	else if (num != 1) // 나누어지고 남은것 마지막에 추가
	{
		if (G_Prime[z - 2] == num)
		{
			G_Prime[z - 1] += count;
		}
		else
		{
			G_Prime[z] = num;
			G_Prime[z + 1] += count;
		}
		return false;
	}
	else // 나머지 과정은 예외라고 알려주기 위해
	{
		return false;
	}
}

// 생성일 : 17.06.30 (금) 
// 목  적 : 소수 판별 후 오일러 값을 출력하는 함수, (float)로 각각 형변환을 하면 분수처럼 사용할 수 있음을 알게 됨
unsigned __int64  Primitive_Root_Euler(unsigned __int64 num)
{
	int s = 0;
	double s_temp = num;
	if (G_IsPrime(num)) // bool함수는 if문의 조건에도 넣을수 있다.
	{
		return (G_Prime[0] - 1);
	}
	else
	{
		if (G_Prime[4] == 0 && G_Prime[1] == 1 && G_Prime[3] == 1) //p*q꼴
		{
			return (G_Prime[0] - 1)*(G_Prime[2] - 1);
		}
		else if (G_Prime[1] != 0 && G_Prime[2] == 0)// p^k 꼴
		{
			return (pow(G_Prime[0], G_Prime[1]) - pow(G_Prime[0], G_Prime[1] - 1));
		}
		else//p^k * p1^k1 * p2^k2 .... 꼴 
		{
			while (G_Prime[s] != 0)
			{
				s_temp *= (double)((G_Prime[s] - 1) / (double)G_Prime[s]); // 분수꼴 저장을 하기위한 형변환 실행
				s += 2;
			}
			return s_temp;
		}
	}
}

// 생성일 : 17.07.01 (토)
// 목  적 : 위수를 구하기 위해서는 오일러값의 약수가 필요로 한다. 따라서 오일러 값의 약수를 배열에 저장하는 함수이다.
void G_Prime_Divisor(unsigned __int64 num)
{
	int z = 0;
	for (int i = 1; i <= num; i++)
	{
		if (num%i == 0)
		{
			G_Divisor[z++] = i;
		}
	}
}

// 생성일 : 17.07.01 (토)
// 목  적 : 약수들이 저장이 잘 되었는지 출력하는 함수
void Show_G_Divisor()
{
	int i = 0;
	while (G_Divisor[i] > 0)
	{
		cout << G_Divisor[i] << ' ';
		i++;
	}
	cout << endl;
}

//  생성일 : 17.07.01 (토)
//  목  적 : 위수가 어떤것이 성립하는지 확인하기 위해 , fmod라는 함수 , 더블형일때 지원
//  수정일 : 17.07.05 (수) + 07.06 (목)
//  수정내용 : return 값이 temp 즉 위수가 아니라 a 만족하는 a를 리턴한다.
//  수정이유 : 테이블 생성을 위해서는 오일러 값과 오더값이 일치하는 떄의 a가 존재하면 되기 때문에 + pow 연산 및 mod 연산시 큰 수에서 오차 발생 template으로 함수 생성
unsigned __int64 Primitive_Root_Order(unsigned __int64 num)
{

	unsigned __int64 rvalue = 2, i = 0, j = 0;
	double temp = 0, result = 0;
	while (true)
	{
		if (G_Divisor[j] == 0)
		{
			temp = G_Divisor[j - 1];
			break;
		}
		j++;
	}
	while (true) // 약수 반복문 이용해서 증가시키면서 돌리기
	{
		//97입력 시에 에러가 발생한다!.. 5^24부터 값이 다르게 나타남 그래서 템플릿 클래스 만듬.
		Template_class template_class;
		if (Primitive_Root_Uclid(num, rvalue) == 1)
		{
			if (i != 0 && template_class.MOD(template_class.POW(rvalue, G_Divisor[i], num), num) == 1 && template_class.MOD(template_class.POW(rvalue, G_Divisor[i - 1], num), num) != 1 && i == j - 1)
			{
				return rvalue;
			}
			else if (i == (j - 1))
			{
				i = 0; rvalue++;
			}
			else
			{
				i++;
			}
		}
		else
		{
			rvalue++;
			if (rvalue >= num)
			{
				return 0;
			}
		}
	}
}
// 생성일 : 17.07.05(수)
// 목  적 : 최대공약수를 구하기위해
// 소멸일 : 17.07.10(월)
// 이  유 : 확장된 유클리드 알고리즘으로 최대공약수 까지 구할 수 있기 때문에 생략 하였다.
unsigned __int64  Primitive_Root_Uclid(unsigned __int64 a, unsigned __int64 b)
{
	return b ? Primitive_Root_Uclid(b, a%b) : a;
}

// 생성일 : 17.07.10(월)
// 목  적 : 확장된 유클리드 알고리즘을 통해 S값과 T값을 구하기 위하여
int Primitive_Root_Upgrade_Uclid(int a, int b, int s1, int s2, int t1, int t2)
{
	int s = 0, t = 0;
	static int i = 0;
	static int Uclid[100] = { 0 };
	if (b == 0)
	{
		printf(" %6d %3d %7d %3d %7d %3d \n", a, b, s1, s2, t1, t2);
		printf(" (%2d x %2d) + (%2d x %2d ) = ", Uclid[0], s1, Uclid[1], t1);
	}
	else
	{
		Uclid[i] = a, Uclid[i + 1] = b;
		s = s1 - ((a / b)*s2); t = t1 - ((a / b)*t2);
		printf("%3d %3d %3d %3d %3d %3d %3d %3d %3d %3d \n", a / b, a, b, a%b, s1, s2, s1 - ((a / b)*s2), t1, t2, t1 - ((a / b)*t2));
		i++;
	}
	return b ? Primitive_Root_Upgrade_Uclid(b, a%b, s2, s, t2, t) : a;
}
// 생성일 : 17.07.07(목)
// 목  적 : 원시근 테이블 생성
unsigned __int64 Create_G_Table(unsigned __int64 under_num, unsigned __int64 num, unsigned __int64 temp)
{
	Template_class template_class;
	unsigned __int64 up_exp = 0, j = 0;
	int first_count = 0; int second_count = 0; int third_count = 0;
	cout <<  "---------------number ^ i---------------" << endl;
	while (true)
	{
		if (Primitive_Root_Uclid(num, up_exp) == 1 || up_exp==0)
		{
			cout << under_num << "^" << up_exp << ' '; // a^i 구현
			first_count++;
			if (first_count % 10 == 0)
			{
				cout << endl << "----------------------------------------"<<endl;
			}
			if ((temp / Primitive_Root_Uclid(temp, up_exp)) == temp)
			{
				G_Table[j++] = template_class.POW(under_num, up_exp, num);
			}
		}
		if (up_exp >= num-1)
		{
			up_exp = 1;
			cout << endl << "------------" << under_num << "^i ( mod " << num << " )-------------" << endl;
			break;
		}
		else
		{
			up_exp++;
		}
	}
	while (true)
	{
		cout << template_class.POW(under_num, up_exp, num) << ' ';//이게 temp랑 같으면 원시근
		second_count++;
		if (second_count % 10==0)
		{
			cout << endl << "---------------------------------------" << endl;
		}
		if (up_exp >= num-1)
		{
			up_exp = 1;
			cout << endl << "-------------order_"<<num<<" "<<under_num<<"^i --------------" << endl;
			break;
		}
		else
		{
			up_exp++;
		}
	}
	while (true)
	{
		cout << temp / Primitive_Root_Uclid(temp, up_exp) << ' ';//이게 temp랑 같으면 원시근
		third_count++;
		if (third_count % 10==0)
		{
			cout << endl << "---------------------------------------" << endl;
		}
		if (up_exp >= num-1)
		{
			cout << endl << "---------------------------------------" << endl;
			return 0;
		}
		else
		{
			up_exp++;
		}
	}
}

// 생성일 : 17.07.07 (금)
// 목  적 : 원시근 목록 출력함수
void G_show(unsigned __int64 num, unsigned __int64 exp)
{
	int G_count = 0;
	cout << "< " << num << "의 원시근  >" << endl;
	int i = 0, j = 0, temp = 0, k = 0;
	for (i = exp; i > 0; i--) {
		for (j = 0; j < i; j++) {
			if (G_Table[j] > G_Table[j + 1] && G_Table[j] != 0)
				SWAP(G_Table[j], G_Table[j + 1], temp);
		}
	}
	for (int q = 1; q < 100; q++) // 중복항을 0으로 준다.
	{
		if (G_Table[q - 1] == G_Table[q])
		{
			G_Table[q] = 0;
		}
	}
	while (k < 100) // 0이 아닌것만 출력하면 원시근....
	{
		if (G_Table[k] != 0)
		{
			cout << G_Table[k] << ' ';
			G_count++;
			if (G_count % 10 == 0)
			{
				cout << endl;
			}
		}
		k++;
	}
	cout <<endl<< "---------------------------------------" << endl;
}


// 생성일 : 17.07.02 (일)
// 소멸일 : 17.07.05 (수)
// 목  적 : 원시근 판별 함수
// 소멸이유 : 원시근 테이블 생성시에 불필요하다.

void G_number(unsigned __int64 num)
{
	int i = 0, order_num = 0;
	while (1)
	{
		if (G_Divisor[i] == 0)
		{
			order_num = Primitive_Root_Order(num);
			if (G_Divisor[i - 1] == order_num)
			{
				cout << "Order : " << order_num << ' ' << "Euler : " << G_Divisor[i - 1] << endl;
				cout << "원시근입니다." << endl;
				break;
			}
			else
			{
				cout << "Order : " << order_num << ' ' << "Euler : " << G_Divisor[i - 1] << endl;
				cout << "원시근이 아닙니다." << endl;
				break;
			}
		}
		i++;
	}
}