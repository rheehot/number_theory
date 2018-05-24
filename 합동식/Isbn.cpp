#include <iostream>
#include"hapdong.h"
using namespace std;

void Isbn_Main()
{
	cout << "�����յ����� ���� ISBN���α׷��Դϴ�." << endl;
	cout << "���ڸ� �Է��Ͻø� 10�ڸ����� 13�ڸ����� �Ǵ���" << endl;
	cout << " �˾Ƽ� ���� �մϴ�." << endl;
	cout << "ISBN ���ڸ� �Է��� �ּ���" << endl;
	unsigned __int64 isbn = 0;
	cin >> isbn;
	if (isbn >= 1000000000 && isbn < 10000000000) 
	{
		cout << "10�ڸ��� �Է��ϼ̽��ϴ�" << endl;
		ISBN10(isbn);
	}
	else if (isbn >= 1000000000000 && isbn < 10000000000000) 
	{
		cout << "13�ڸ��� �Է��ϼ̽��ϴ�" << endl;
		ISBN13(isbn);
	}
	else
	{
		cout << "���� �ȹٷ� �Է��ϼ�" << endl;
	}

}
//isbn13�ڸ� �Ǵ�
void ISBN13(unsigned __int64 isbn13) 
{
	unsigned __int64 j = 10000000000000;
	int sum = 0;
	int i = 1;
	while (1) 
	{
		if (i % 2 == 0) 
		{
			sum = sum + isbn13 % j / (j / 10) * 3;
			i++;
			j = j / 10;
		}
		else if (i % 2 == 1) 
		{
			sum = sum + isbn13 % j / (j / 10);
			i++;
			j = j / 10;
		}
		if (i == 13) 
		{
			break;
		}
	}
	if (isbn13 % 10 == 10 - (sum % 10)) 
	{
		cout << "�ùٸ� ��ȣ�Դϴ�" << endl;
	}
	else
	{
		cout << "�ƴմϴ�" << endl;
	}
}


//isbn 10�ڸ� �Ǵ�
void ISBN10(unsigned __int64 isbn10)
{
	unsigned __int64 j = 10000000000;
	int sum = 0;
	int i = 1;
	while (1) 
	{
		sum = sum + isbn10 % j / (j / 10) *i;
		i++;
		j = j / 10;
		if (i == 11) 
		{
			break;
		}
	}
	if (sum % 11 == isbn10 % 10) 
	{
		cout << "�ùٸ� ��ȣ�Դϴ�" << endl;
	}
	else 
	{
		cout << "�ƴմϴ�" << endl;
	}
}