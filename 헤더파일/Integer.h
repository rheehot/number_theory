#ifndef __INTEGER_H_
#define __INTEGER_H_

int Integer_Main();// ������Ʈ ���� �Լ�

void Divisor_Multiple_Main(void);//��� ��� �����Լ�

void GCD_Main(void);//�� ���� �ִ����� ���� �Լ�

void Divison_Algorithm_Main(void);//���������� ���� �Լ�

void Euclidean_Algorithm_Main(void);//��Ŭ���� ȣ���� ���� �Լ�

void Uclid_Main();// ��Ŭ���� �˰��� ���� �Լ�

void Upgrade_Uclid_Main(); // Ȯ��� ��Ŭ���� �˰��� ���� �Լ�
int Upgrade_Uclid(int a, int b, int s1, int s2, int t1, int t2); //Ȯ��� ��Ŭ���� �˰��� �Լ�

void Diopantus_Main(); // ��������� �����Լ�
int Diopantus_Uclid(int a, int b, int s1, int s2, int t1, int t2); // ������佺 �����Ŀ��� ���� ��Ŭ���� �˰��� �Լ�
int GCD(int a, int b); // �ִ����� ���ϴ� �Լ�

void Is_Prime_Main();//�Ҽ� �Ǻ� �˰��� �����Լ�
bool Is_Prime(unsigned __int64 num); // �Ҽ� �Ǻ� �˰��� �Լ�

void Prime_Arr_Main();//���μ����� �����Լ�
void Prime_Arr(unsigned __int64 num); // ���μ����� �˰��� �Լ�

void Eratostenes_Main();//�����佺�׳׽� �����Լ�
void PrimeTable(int num);//ü�� �Ÿ��� �����Լ�
void Table(int num); //�Է¹��� ����ŭ ���� ���忡 �ʱ⿡ ���̺� ���� ����� �Լ�.
void Show();//ü�� �Ÿ��� ���� ����Լ�

#endif __INTEGER_H_
