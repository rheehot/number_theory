#ifndef __HAPDONG_H_
#define __HAPDONG_H_
int Hapdong_Main();//합동식 파트 실행 함수

int T_Uclid(int a, int b);
void Perfect_Factor(int fac);//완전잉여계 출력
void Reduced_Residue_System(int fac, int *red);//기약잉여계 출력...and걸러주기
void Not_Reduced_Residue_System(int fac, int *red);//기약잉여계가 되지못한 아이들의 이유
void Residue_Class(int fac);
void Complete_Residue_System_Main();

bool prime_number(int num);
unsigned __int64 factoreal(unsigned __int64 num, unsigned __int64 mod);
void Willson_Main();

void First_Hapdong_Main();//일차합동식 실행 함수
int First_HapDong(int a, int b, int m); // 일차합동식 판별 함수
int First_Hapdong_GCD(int a, int b); // 최대공약수 판별 함수 ( 유클리드 알고리즘 )

void Isbn_Main();// ISBN실행함수
void ISBN10(unsigned __int64 isbn10); // ISBN10자리 판별함수
void ISBN13(unsigned __int64 isbn13); // ISBN13자리 판별함수

void Bar_Cod_Main(); // 바코드 실행 함수
void Bar_Code(unsigned __int64 bar_code); // 바코드 판별 함수

void Identify_Testing_Main();//주민등록번호 판별 함수 (에러 안잡는 판별 함수)
int Testing_POW(int a, int b); // 제곱하는 함수


void Identify_Main(); // 주민등록번호 판별 함수 (에러 잡는 함수)
int Identify_POW(int a, int b); // 제곱하는 함수

void Linked_Main(); // 연립일차합동식 실행함수
int China_Inverse(int m, int mod_M); // 중국인의 나머지 정리에서 필요한 역원을 구하는 함수
void Sum_China(int b, int m, int mod_M); // 중국인의 나머지 정리의 계산값들을 다 더하는 함수
int Hap_Gcd(int m1, int m2); // 중국인의 나머지 정리에서 최대공약수를 구하는 함수
int Linked_HapDong(int a, int b, int m); // 일차합동식의 해를 구해주는 함수.

#endif __HAPDONG_H_