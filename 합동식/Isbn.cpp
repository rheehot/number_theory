#include <iostream>
#include"hapdong.h"
using namespace std;

void Isbn_Main()
{
	cout << "일차합동식의 응용 ISBN프로그램입니다." << endl;
	cout << "숫자를 입력하시면 10자리인지 13자리인지 판단후" << endl;
	cout << " 알아서 실행 합니다." << endl;
	cout << "ISBN 숫자를 입력해 주세요" << endl;
	unsigned __int64 isbn = 0;
	cin >> isbn;
	if (isbn >= 1000000000 && isbn < 10000000000) 
	{
		cout << "10자리를 입력하셨습니다" << endl;
		ISBN10(isbn);
	}
	else if (isbn >= 1000000000000 && isbn < 10000000000000) 
	{
		cout << "13자리를 입력하셨습니다" << endl;
		ISBN13(isbn);
	}
	else
	{
		cout << "숫자 똑바로 입력하셈" << endl;
	}

}
//isbn13자리 판단
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
		cout << "올바른 번호입니다" << endl;
	}
	else
	{
		cout << "아닙니다" << endl;
	}
}


//isbn 10자리 판단
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
		cout << "올바른 번호입니다" << endl;
	}
	else 
	{
		cout << "아닙니다" << endl;
	}
}