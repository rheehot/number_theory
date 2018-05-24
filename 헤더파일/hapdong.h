#ifndef __HAPDONG_H_
#define __HAPDONG_H_
int Hapdong_Main();//�յ��� ��Ʈ ���� �Լ�

int T_Uclid(int a, int b);
void Perfect_Factor(int fac);//�����׿��� ���
void Reduced_Residue_System(int fac, int *red);//����׿��� ���...and�ɷ��ֱ�
void Not_Reduced_Residue_System(int fac, int *red);//����׿��谡 �������� ���̵��� ����
void Residue_Class(int fac);
void Complete_Residue_System_Main();

bool prime_number(int num);
unsigned __int64 factoreal(unsigned __int64 num, unsigned __int64 mod);
void Willson_Main();

void First_Hapdong_Main();//�����յ��� ���� �Լ�
int First_HapDong(int a, int b, int m); // �����յ��� �Ǻ� �Լ�
int First_Hapdong_GCD(int a, int b); // �ִ����� �Ǻ� �Լ� ( ��Ŭ���� �˰��� )

void Isbn_Main();// ISBN�����Լ�
void ISBN10(unsigned __int64 isbn10); // ISBN10�ڸ� �Ǻ��Լ�
void ISBN13(unsigned __int64 isbn13); // ISBN13�ڸ� �Ǻ��Լ�

void Bar_Cod_Main(); // ���ڵ� ���� �Լ�
void Bar_Code(unsigned __int64 bar_code); // ���ڵ� �Ǻ� �Լ�

void Identify_Testing_Main();//�ֹε�Ϲ�ȣ �Ǻ� �Լ� (���� ����� �Ǻ� �Լ�)
int Testing_POW(int a, int b); // �����ϴ� �Լ�


void Identify_Main(); // �ֹε�Ϲ�ȣ �Ǻ� �Լ� (���� ��� �Լ�)
int Identify_POW(int a, int b); // �����ϴ� �Լ�

void Linked_Main(); // ���������յ��� �����Լ�
int China_Inverse(int m, int mod_M); // �߱����� ������ �������� �ʿ��� ������ ���ϴ� �Լ�
void Sum_China(int b, int m, int mod_M); // �߱����� ������ ������ ��갪���� �� ���ϴ� �Լ�
int Hap_Gcd(int m1, int m2); // �߱����� ������ �������� �ִ������� ���ϴ� �Լ�
int Linked_HapDong(int a, int b, int m); // �����յ����� �ظ� �����ִ� �Լ�.

#endif __HAPDONG_H_