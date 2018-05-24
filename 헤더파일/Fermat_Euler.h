#ifndef __FERMAT_EULER_H_
#define __FERMAT_EULER_H_
int Fermat_Euler_Main();//�丣�� ����, ���Ϸ� ���� ��Ʈ ���� �Լ�

void Euler_Main();//���Ϸ��Լ� �����Լ�
bool Euler_IsPrime(unsigned __int64 euler_moduler); // �Ҽ����� �ƴ��� �Ǵ��ؼ� ���μ� ���� �ϴ� �Լ�
int  Euler(int euler_moduler);//���Ϸ����� ���ϴ� �Լ�
int Result_Euler(int a_value, int exp_value, int Euler_temp, int euler_moduler); //���Ϸ����� �̿��Ͽ� ���� ������ ���� ���ϴ� �Լ�
int Euler_GCD(int a_value, int euler_moduler);//���Ϸ����� ��Ŭ���� �˰���


void FerMat_Main();//�丣�� ���� �Լ�
int Fermat(int mod); // �丣�� ���� �Լ�
bool Fermat_is_Prime(int num); // �丣���� ������ ����� �Ҽ� ���� �ƴ��� �Ǵ�
int Fermat_Gcd(int a_value, int fermat_moduler);//a�� m�� �ִ������� 1���� �Ǵ�.
unsigned __int64 Fermat_Pow(int a_value, int exp);//���������� ���� ������ġ
static int fermat_value = 0; // �丣�� ���� ����Լ����� ������ֱ� ���� ����


#endif  __FERMAT_EULER_H_