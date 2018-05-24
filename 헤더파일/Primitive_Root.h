#ifndef __PRIMITIVE_ROOT_H__
#define __PRIMITIVE_ROOT_H__
int Primitive_Root_Main();//���ñ� ��Ʈ ���� �Լ�


/*�������ϴ� ���α׷� start*/
void Order_Main(); //���� ���ϴ� ���α׷� �����Լ�
unsigned __int64  Euler(unsigned __int64 num); // ���Ϸ� �Լ�
bool O_IsPrime(unsigned __int64 num);  //�Ҽ��Ǻ��Լ�
void Prime_Divisor(unsigned __int64 num); //���Ϸ����� ����� ���ϴ� �Լ�
void Show_O_Divisor(); //������� ����� ���� ����ϴ� �Լ�
void Show_O_Prime(); // ���μ� ���ص� �Ҽ� ����ϴ��Լ�
void Order(unsigned __int64 num); // ���� ���ϴ� �Լ�
int Order_Pow(int num, int count, int moudler);// ������ �������ϱ� �Լ�
/*�������ϴ� ���α׷� end*/

/*���ñ� ���ϴ� ���α׷� start*/
void Primitive_Root_Table_Main();//���ñ� ���̺� ���� �Լ�
unsigned __int64 Primitive_Root_Euler(unsigned __int64 num); // ���Ϸ� �Լ�
bool G_IsPrime(unsigned __int64 num);  //�Ҽ��Ǻ��Լ�
void G_number(unsigned __int64 num); // ���ñ� �Ǻ� �Լ�
void G_Prime_Divisor(unsigned __int64 num); //���Ϸ����� ����� ���ϴ� �Լ�
void Show_G_Divisor(); //������� ����� ���� ����ϴ� �Լ�
void Show_G_Prime(); // ���μ� ���ص� �Ҽ� ����ϴ��Լ�
unsigned __int64 Primitive_Root_Order(unsigned __int64 num); // ���� ���ϴ� �Լ�
unsigned __int64 Primitive_Root_Uclid(unsigned __int64 a, unsigned __int64 b); // ��Ŭ���� �˰���,�ִ����� ���ϱ� 
unsigned __int64 Create_G_Table(unsigned __int64 under_num, unsigned __int64 num, unsigned __int64 temp);
void G_show(unsigned __int64 num, unsigned __int64 exp);//���ñ� ���̺� �����ֱ� 
int Primitive_Root_Upgrade_Uclid(int a, int b, int s1, int s2, int t1, int t2); // Ȯ��� ��Ŭ���� �˰��� !!
void Clear(); // ����� ����� �� ����
/*���ñ� ���ϴ� ���α׷� end*/
#endif __PRIMITIVE_ROOT_H__
