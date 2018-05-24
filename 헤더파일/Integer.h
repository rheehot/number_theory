#ifndef __INTEGER_H_
#define __INTEGER_H_

int Integer_Main();// 정수파트 실행 함수

void Divisor_Multiple_Main(void);//약수 배수 실행함수

void GCD_Main(void);//두 수의 최대공약수 실행 함수

void Divison_Algorithm_Main(void);//나눗셈정리 실행 함수

void Euclidean_Algorithm_Main(void);//유클리드 호제법 실행 함수

void Uclid_Main();// 유클리드 알고리즘 실행 함수

void Upgrade_Uclid_Main(); // 확장된 유클리드 알고리즘 실행 함수
int Upgrade_Uclid(int a, int b, int s1, int s2, int t1, int t2); //확장된 유클리드 알고리즘 함수

void Diopantus_Main(); // 디오판투스 실행함수
int Diopantus_Uclid(int a, int b, int s1, int s2, int t1, int t2); // 디오판토스 방정식에서 쓰는 유클리드 알고리즘 함수
int GCD(int a, int b); // 최대공약수 구하는 함수

void Is_Prime_Main();//소수 판별 알고리즘 실행함수
bool Is_Prime(unsigned __int64 num); // 소수 판별 알고리즘 함수

void Prime_Arr_Main();//소인수분해 실행함수
void Prime_Arr(unsigned __int64 num); // 소인수분해 알고리즘 함수

void Eratostenes_Main();//에라토스테네스 실행함수
void PrimeTable(int num);//체로 거르는 과정함수
void Table(int num); //입력받은 값만큼 값을 저장에 초기에 테이블에 값을 만드는 함수.
void Show();//체로 거르는 과정 출력함수

#endif __INTEGER_H_
