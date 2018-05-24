#ifndef __FERMAT_EULER_H_
#define __FERMAT_EULER_H_
int Fermat_Euler_Main();//페르마 정리, 오일러 정리 파트 실행 함수

void Euler_Main();//오일러함수 실행함수
bool Euler_IsPrime(unsigned __int64 euler_moduler); // 소수인지 아닌지 판단해서 소인수 분해 하는 함수
int  Euler(int euler_moduler);//오일러값을 구하는 함수
int Result_Euler(int a_value, int exp_value, int Euler_temp, int euler_moduler); //오일러값을 이용하여 식의 나머지 값을 구하는 함수
int Euler_GCD(int a_value, int euler_moduler);//오일러값용 유클리드 알고리즘


void FerMat_Main();//페르마 실행 함수
int Fermat(int mod); // 페르마 정리 함수
bool Fermat_is_Prime(int num); // 페르마의 정리에 사용할 소수 인지 아닌지 판단
int Fermat_Gcd(int a_value, int fermat_moduler);//a와 m이 최대공약수가 1인지 판단.
unsigned __int64 Fermat_Pow(int a_value, int exp);//제곱연산을 위한 연산장치
static int fermat_value = 0; // 페르마 값을 모든함수에서 사용해주기 위해 선언


#endif  __FERMAT_EULER_H_