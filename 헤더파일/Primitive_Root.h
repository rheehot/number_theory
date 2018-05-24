#ifndef __PRIMITIVE_ROOT_H__
#define __PRIMITIVE_ROOT_H__
int Primitive_Root_Main();//원시근 파트 실행 함수


/*위수구하는 프로그램 start*/
void Order_Main(); //위수 구하는 프로그램 실행함수
unsigned __int64  Euler(unsigned __int64 num); // 오일러 함수
bool O_IsPrime(unsigned __int64 num);  //소수판별함수
void Prime_Divisor(unsigned __int64 num); //오일러값의 약수를 구하는 함수
void Show_O_Divisor(); //약수들이 저장된 값을 출력하는 함수
void Show_O_Prime(); // 소인수 분해된 소수 출력하는함수
void Order(unsigned __int64 num); // 위수 구하는 함수
int Order_Pow(int num, int count, int moudler);// 위수용 제곱구하기 함수
/*위수구하는 프로그램 end*/

/*원시근 구하는 프로그램 start*/
void Primitive_Root_Table_Main();//원시근 테이블 실행 함수
unsigned __int64 Primitive_Root_Euler(unsigned __int64 num); // 오일러 함수
bool G_IsPrime(unsigned __int64 num);  //소수판별함수
void G_number(unsigned __int64 num); // 원시근 판별 함수
void G_Prime_Divisor(unsigned __int64 num); //오일러값의 약수를 구하는 함수
void Show_G_Divisor(); //약수들이 저장된 값을 출력하는 함수
void Show_G_Prime(); // 소인수 분해된 소수 출력하는함수
unsigned __int64 Primitive_Root_Order(unsigned __int64 num); // 위수 구하는 함수
unsigned __int64 Primitive_Root_Uclid(unsigned __int64 a, unsigned __int64 b); // 유클리드 알고리즘,최대공약수 구하기 
unsigned __int64 Create_G_Table(unsigned __int64 under_num, unsigned __int64 num, unsigned __int64 temp);
void G_show(unsigned __int64 num, unsigned __int64 exp);//원시근 테이블 보여주기 
int Primitive_Root_Upgrade_Uclid(int a, int b, int s1, int s2, int t1, int t2); // 확장된 유클리드 알고리즘 !!
void Clear(); // 계산후 저장된 값 삭제
/*원시근 구하는 프로그램 end*/
#endif __PRIMITIVE_ROOT_H__
