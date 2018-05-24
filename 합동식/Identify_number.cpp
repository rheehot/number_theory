#include <iostream>
#include"hapdong.h"
using namespace std;
static int Front[6] = { 0 };
static int Back[7] = { 0 };

void Identify_Main()
{
	cout << "일차합동식의 응용 주민등록번호 판별 프로그램입니다." << endl;
	cout << "이 프로그램은 잘못 값이 있으면 알려줍니다" << endl;
	int front_num = 0; //주민등록번호 앞자리 입력받는 공간
	int back_num = 0; //주민등록번호 뒷자리 입력받는 공간
	int z = 5; // POW연산을 하기위한 초기값
	int save_num = 0; // 연산한 값을 저장하는 공간
	cout << "주민등록번호를 입력하세요." << endl;
	cout << "ex) 124718 3051287" << endl;
	cin >> front_num >> back_num;
	if (front_num / 10000 < 20) // 2000년대생
	{
		if (back_num / 1000000 == 3 || back_num / 1000000 == 4) //뒷자리 3 or 4 여야한다
		{
			if ((front_num / 100) % 100 < 13) // 12월 달안에있는지 확인
			{
				if ((front_num / 100) % 100 % 2 == 1 || ((front_num / 100) % 100) == 8) // 홀수달이나 8월달은 31일까지있다
				{
					if ((front_num % 100 < 32 && front_num % 100 > 0)) // 1일이상 31일 이하일때 ok
					{
						if ((back_num / 100) % 100 > 0 && (back_num / 100) % 100 < 96) // 뒷자리 지역번호가 0복다 크고 96보다 작으면 ok
						{
							for (int i = 0; i < 6; i++) // 앞자리를 각 배열의 한칸씩에 저장하는 함수
							{
								Front[i] = ((front_num / Identify_POW(10, z)) % 10);
								z--;
							}
							z = 6; //뒷자리는 한자리 더 많으므로 초기값 변경
							for (int i = 0; i < 7; i++) // 뒷자리를 각 배열의 한칸씩에 저장하는 함수
							{
								Back[i] = ((back_num / Identify_POW(10, z)) % 10);
								z--;
							}
							int i = 0;
							while (i<12) // 12번째 자리까지 반복하는 이유는 13번째 자리는 에러검출하는 번호이다.
							{
								if (i < 6)
								{
									save_num += (Front[i] * (2 + i));
									cout << (Front[i] * (2 + i)) << '+';
								}
								else if (i<8)
								{
									save_num += (Back[i - 6] * (i + 2));
									cout << (Back[i - 6] * (i + 2)) << '+';
								}
								else
								{
									if (i == 11)
									{
										save_num += (Back[i - 6] * (i - 6));
										cout << (Back[i - 6] * (i - 6)) << '=';
									}
									else
									{
										save_num += (Back[i - 6] * (i - 6));
										cout << (Back[i - 6] * (i - 6)) << '+';
									}
								}
								i++;
							}
							cout << save_num << endl;
							if (((11 - (save_num % 11)) % 10) == Back[6]) // 11-a의 값이 주민등록번호 제일 마지막 자리와 같아야 한다.		
							{										/*a는 12번째 자리까지 공식에 넣은 값의 mod 11 값이다.*/
								cout << "(11 - ( 각자리수 계산값 % 11))%10-> " << (11 - (save_num % 11)) % 10 << " = " << Back[6] << " <-주민등록번호 뒷자리 7번째 자리" << endl;
								cout << "올바른 주민등록번호입니다." << endl;
							}
							else
							{
								cout << "(11 - ( 각자리수 계산값 % 11))%10-> " << (11 - (save_num % 11)) % 10 << " != " << Back[6] << " <-주민등록번호 뒷자리 7번째 자리" << endl;
								cout << "올바르지 않는 주민등록번호입니다." << endl;
							}
						}
						else //뒷자리 지역번호 짤
						{
							cout << "지역번호가 올바르지 않습니다." << endl;
						}
					}
					else // 1~31일 아니면 x
					{
						cout << "1~31일 범위에서 벗어났습니다. 다시 확인해 주세요." << endl;
					}
				}
				else if ((front_num / 100) % 100 == 2) // 2월일때 28일 또는 29일인데 윤년이면 2월 29일까지있다
				{
					if ((front_num / 10000) % 4 == 0) // 윤달인지 아닌지 확인
					{
						if (front_num % 100 < 30 && front_num % 100 > 0) // 1일에서 29일까지 있어야 한다
						{
							for (int i = 0; i < 6; i++) // 앞자리를 각 배열의 한칸씩에 저장하는 함수
							{
								Front[i] = ((front_num / Identify_POW(10, z)) % 10);
								z--;
							}
							z = 6; //뒷자리는 한자리 더 많으므로 초기값 변경
							for (int i = 0; i < 7; i++) // 뒷자리를 각 배열의 한칸씩에 저장하는 함수
							{
								Back[i] = ((back_num / Identify_POW(10, z)) % 10);
								z--;
							}
							int i = 0;
							while (i<12) // 12번째 자리까지 반복하는 이유는 13번째 자리는 에러검출하는 번호이다.
							{
								if (i < 6)
								{
									save_num += (Front[i] * (2 + i));
									cout << (Front[i] * (2 + i)) << '+';
								}
								else if (i<8)
								{
									save_num += (Back[i - 6] * (i + 2));
									cout << (Back[i - 6] * (i + 2)) << '+';
								}
								else
								{
									if (i == 11)
									{
										save_num += (Back[i - 6] * (i - 6));
										cout << (Back[i - 6] * (i - 6)) << '=';
									}
									else
									{
										save_num += (Back[i - 6] * (i - 6));
										cout << (Back[i - 6] * (i - 6)) << '+';
									}
								}
								i++;
							}
							cout << save_num << endl;
							if (((11 - (save_num % 11)) % 10) == Back[6]) // 11-a의 값이 주민등록번호 제일 마지막 자리와 같아야 한다.		
							{										/*a는 12번째 자리까지 공식에 넣은 값의 mod 11 값이다.*/
								cout << "(11 - ( 각자리수 계산값 % 11))%10-> " << (11 - (save_num % 11)) % 10 << " = " << Back[6] << " <-주민등록번호 뒷자리 7번째 자리" << endl;
								cout << "올바른 주민등록번호입니다." << endl;
							}
							else
							{
								cout << "(11 - ( 각자리수 계산값 % 11))%10-> " << (11 - (save_num % 11)) % 10 << " != " << Back[6] << " <-주민등록번호 뒷자리 7번째 자리" << endl;
								cout << "올바르지 않는 주민등록번호입니다." << endl;
							}
						}
						else // 1일보다 작거나 30일 이상이면 짤
						{
							cout << "1일~30일 범위가 아닙니다." << endl;
						}
					}
					else // 윤달 아니면 1이상 28 이하로 존재
					{
						if (front_num % 100 > 0 && front_num % 100 < 29) // 0~29일 사이인지 아닌지 확인
						{
							for (int i = 0; i < 6; i++) // 앞자리를 각 배열의 한칸씩에 저장하는 함수
							{
								Front[i] = ((front_num / Identify_POW(10, z)) % 10);
								z--;
							}
							z = 6; //뒷자리는 한자리 더 많으므로 초기값 변경
							for (int i = 0; i < 7; i++) // 뒷자리를 각 배열의 한칸씩에 저장하는 함수
							{
								Back[i] = ((back_num / Identify_POW(10, z)) % 10);
								z--;
							}
							int i = 0;
							while (i<12) // 12번째 자리까지 반복하는 이유는 13번째 자리는 에러검출하는 번호이다.
							{
								if (i < 6)
								{
									save_num += (Front[i] * (2 + i));
									cout << (Front[i] * (2 + i)) << '+';
								}
								else if (i<8)
								{
									save_num += (Back[i - 6] * (i + 2));
									cout << (Back[i - 6] * (i + 2)) << '+';
								}
								else
								{
									if (i == 11)
									{
										save_num += (Back[i - 6] * (i - 6));
										cout << (Back[i - 6] * (i - 6)) << '=';
									}
									else
									{
										save_num += (Back[i - 6] * (i - 6));
										cout << (Back[i - 6] * (i - 6)) << '+';
									}
								}
								i++;
							}
							cout << save_num << endl;
							if (((11 - (save_num % 11)) % 10) == Back[6]) // 11-a의 값이 주민등록번호 제일 마지막 자리와 같아야 한다.		
							{										/*a는 12번째 자리까지 공식에 넣은 값의 mod 11 값이다.*/
								cout << "(11 - ( 각자리수 계산값 % 11))%10-> " << (11 - (save_num % 11)) % 10 << " = " << Back[6] << " <-주민등록번호 뒷자리 7번째 자리" << endl;
								cout << "올바른 주민등록번호입니다." << endl;
							}
							else
							{
								cout << "(11 - ( 각자리수 계산값 % 11))%10-> " << (11 - (save_num % 11)) % 10 << " != " << Back[6] << " <-주민등록번호 뒷자리 7번째 자리" << endl;
								cout << "올바르지 않는 주민등록번호입니다." << endl;
							}
						}
						else // 1~29 범위가 아니면 짤
						{
							cout << "1일~29일 범위가 아닙니다. 다시 확인하세요" << endl;
						}
					}
				}
				else // 나머지 짝수달
				{
					if ((front_num % 100 < 31 && front_num % 100 > 0)) // 1일이상 31일 이하일때 ok
					{
						if ((back_num / 100) % 100 > 0 && (back_num / 100) % 100 < 96) // 뒷자리 지역번호가 0복다 크고 96보다 작으면 ok
						{
							for (int i = 0; i < 6; i++) // 앞자리를 각 배열의 한칸씩에 저장하는 함수
							{
								Front[i] = ((front_num / Identify_POW(10, z)) % 10);
								z--;
							}
							z = 6; //뒷자리는 한자리 더 많으므로 초기값 변경
							for (int i = 0; i < 7; i++) // 뒷자리를 각 배열의 한칸씩에 저장하는 함수
							{
								Back[i] = ((back_num / Identify_POW(10, z)) % 10);
								z--;
							}
							int i = 0;
							while (i<12) // 12번째 자리까지 반복하는 이유는 13번째 자리는 에러검출하는 번호이다.
							{
								if (i < 6)
								{
									save_num += (Front[i] * (2 + i));
									cout << (Front[i] * (2 + i)) << '+';
								}
								else if (i<8)
								{
									save_num += (Back[i - 6] * (i + 2));
									cout << (Back[i - 6] * (i + 2)) << '+';
								}
								else
								{
									if (i == 11)
									{
										save_num += (Back[i - 6] * (i - 6));
										cout << (Back[i - 6] * (i - 6)) << '=';
									}
									else
									{
										save_num += (Back[i - 6] * (i - 6));
										cout << (Back[i - 6] * (i - 6)) << '+';
									}
								}
								i++;
							}
							cout << save_num << endl;
							if (((11 - (save_num % 11)) % 10) == Back[6]) // 11-a의 값이 주민등록번호 제일 마지막 자리와 같아야 한다.		
							{										/*a는 12번째 자리까지 공식에 넣은 값의 mod 11 값이다.*/
								cout << "(11 - ( 각자리수 계산값 % 11))%10-> " << (11 - (save_num % 11)) % 10 << " = " << Back[6] << " <-주민등록번호 뒷자리 7번째 자리" << endl;
								cout << "올바른 주민등록번호입니다." << endl;
							}
							else
							{
								cout << "(11 - ( 각자리수 계산값 % 11))%10-> " << (11 - (save_num % 11)) % 10 << " != " << Back[6] << " <-주민등록번호 뒷자리 7번째 자리" << endl;
								cout << "올바르지 않는 주민등록번호입니다." << endl;
							}
						}
						else //뒷자리 지역번호 짤
						{
							cout << "지역번호가 올바르지 않습니다." << endl;
						}
					}
					else // 1~30일 아니면 x
					{
						cout << "1~30일 범위에서 벗어났습니다. 다시 확인해 주세요." << endl;
					}
				}
			}
			else // 12월 안에 없으면 짤
			{
				cout << "1년은 12월까지밖에 없습니다." << endl;
			}
		}
		else // 뒷자리 3 or 4 아니면 짤
		{
			cout << "주민등록번호 뒷자리 첫번째가 올바르지 않습니다." << endl;
		}
	}
	else // 1900년대생
	{
		if (back_num / 1000000 == 1 || back_num / 1000000 == 2) // 뒷자리 1or 2인지 확인
		{
			if ((front_num / 100) % 100 < 13) // 12월 달안에있는지 확인
			{
				if ((front_num / 100) % 100 % 2 == 1 || ((front_num / 100) % 100) == 8) // 홀수달이나 8월달은 31일까지있다
				{
					if ((front_num % 100 < 32 && front_num % 100 > 0)) // 1일이상 31일 이하일때 ok
					{
						if ((back_num / 100) % 100 > 0 && (back_num / 100) % 100 < 96) // 뒷자리 지역번호가 0복다 크고 96보다 작으면 ok
						{
							for (int i = 0; i < 6; i++) // 앞자리를 각 배열의 한칸씩에 저장하는 함수
							{
								Front[i] = ((front_num / Identify_POW(10, z)) % 10);
								z--;
							}
							z = 6; //뒷자리는 한자리 더 많으므로 초기값 변경
							for (int i = 0; i < 7; i++) // 뒷자리를 각 배열의 한칸씩에 저장하는 함수
							{
								Back[i] = ((back_num / Identify_POW(10, z)) % 10);
								z--;
							}
							int i = 0;
							while (i<12) // 12번째 자리까지 반복하는 이유는 13번째 자리는 에러검출하는 번호이다.
							{
								if (i < 6)
								{
									save_num += (Front[i] * (2 + i));
									cout << (Front[i] * (2 + i)) << '+';
								}
								else if (i<8)
								{
									save_num += (Back[i - 6] * (i + 2));
									cout << (Back[i - 6] * (i + 2)) << '+';
								}
								else
								{
									if (i == 11)
									{
										save_num += (Back[i - 6] * (i - 6));
										cout << (Back[i - 6] * (i - 6)) << '=';
									}
									else
									{
										save_num += (Back[i - 6] * (i - 6));
										cout << (Back[i - 6] * (i - 6)) << '+';
									}
								}
								i++;
							}
							cout << save_num << endl;
							if (((11 - (save_num % 11)) % 10) == Back[6]) // 11-a의 값이 주민등록번호 제일 마지막 자리와 같아야 한다.		
							{										/*a는 12번째 자리까지 공식에 넣은 값의 mod 11 값이다.*/
								cout << "(11 - ( 각자리수 계산값 % 11))%10-> " << (11 - (save_num % 11)) % 10 << " = " << Back[6] << " <-주민등록번호 뒷자리 7번째 자리" << endl;
								cout << "올바른 주민등록번호입니다." << endl;
							}
							else
							{
								cout << "(11 - ( 각자리수 계산값 % 11))%10-> " << (11 - (save_num % 11)) % 10 << " != " << Back[6] << " <-주민등록번호 뒷자리 7번째 자리" << endl;
								cout << "올바르지 않는 주민등록번호입니다." << endl;
							}
						}
						else //뒷자리 지역번호 짤
						{
							cout << "뒷자리 지역번호가 잘못되었습니다." << endl;
						}
					}
					else // 1~31일 아니면 x
					{
						cout << "1일~31일 범위를 벗어났습니다." << endl;
					}
				}
				else if ((front_num / 100) % 100 == 2) // 2월일때 28일 또는 29일인데 윤년이면 2월 29일까지있다
				{
					if ((front_num / 10000) % 4 == 0) // 윤달인지 아닌지 확인
					{
						if (front_num % 100 < 30 && front_num % 100 > 0) // 1일에서 29일까지 있어야 한다
						{
							for (int i = 0; i < 6; i++) // 앞자리를 각 배열의 한칸씩에 저장하는 함수
							{
								Front[i] = ((front_num / Identify_POW(10, z)) % 10);
								z--;
							}
							z = 6; //뒷자리는 한자리 더 많으므로 초기값 변경
							for (int i = 0; i < 7; i++) // 뒷자리를 각 배열의 한칸씩에 저장하는 함수
							{
								Back[i] = ((back_num / Identify_POW(10, z)) % 10);
								z--;
							}
							int i = 0;
							while (i<12) // 12번째 자리까지 반복하는 이유는 13번째 자리는 에러검출하는 번호이다.
							{
								if (i < 6)
								{
									save_num += (Front[i] * (2 + i));
									cout << (Front[i] * (2 + i)) << '+';
								}
								else if (i<8)
								{
									save_num += (Back[i - 6] * (i + 2));
									cout << (Back[i - 6] * (i + 2)) << '+';
								}
								else
								{
									if (i == 11)
									{
										save_num += (Back[i - 6] * (i - 6));
										cout << (Back[i - 6] * (i - 6)) << '=';
									}
									else
									{
										save_num += (Back[i - 6] * (i - 6));
										cout << (Back[i - 6] * (i - 6)) << '+';
									}
								}
								i++;
							}
							cout << save_num << endl;
							if (((11 - (save_num % 11)) % 10) == Back[6]) // 11-a의 값이 주민등록번호 제일 마지막 자리와 같아야 한다.		
							{										/*a는 12번째 자리까지 공식에 넣은 값의 mod 11 값이다.*/
								cout << "(11 - ( 각자리수 계산값 % 11))%10-> " << (11 - (save_num % 11)) % 10 << " = " << Back[6] << " <-주민등록번호 뒷자리 7번째 자리" << endl;
								cout << "올바른 주민등록번호입니다." << endl;
							}
							else
							{
								cout << "(11 - ( 각자리수 계산값 % 11))%10-> " << (11 - (save_num % 11)) % 10 << " != " << Back[6] << " <-주민등록번호 뒷자리 7번째 자리" << endl;
								cout << "올바르지 않는 주민등록번호입니다." << endl;
							}
						}
						else // 1일보다 작거나 30일 이상이면 짤
						{
							cout << "1일에서 30일 까지밖에 없습니다." << endl;
						}
					}
					else // 윤달 아니면 1이상 28 이하로 존재
					{
						if (front_num % 100 > 0 && front_num % 100 < 29) // 확인해보고
						{
							for (int i = 0; i < 6; i++) // 앞자리를 각 배열의 한칸씩에 저장하는 함수
							{
								Front[i] = ((front_num / Identify_POW(10, z)) % 10);
								z--;
							}
							z = 6; //뒷자리는 한자리 더 많으므로 초기값 변경
							for (int i = 0; i < 7; i++) // 뒷자리를 각 배열의 한칸씩에 저장하는 함수
							{
								Back[i] = ((back_num / Identify_POW(10, z)) % 10);
								z--;
							}
							int i = 0;
							while (i<12) // 12번째 자리까지 반복하는 이유는 13번째 자리는 에러검출하는 번호이다.
							{
								if (i < 6)
								{
									save_num += (Front[i] * (2 + i));
									cout << (Front[i] * (2 + i)) << '+';
								}
								else if (i<8)
								{
									save_num += (Back[i - 6] * (i + 2));
									cout << (Back[i - 6] * (i + 2)) << '+';
								}
								else
								{
									if (i == 11)
									{
										save_num += (Back[i - 6] * (i - 6));
										cout << (Back[i - 6] * (i - 6)) << '=';
									}
									else
									{
										save_num += (Back[i - 6] * (i - 6));
										cout << (Back[i - 6] * (i - 6)) << '+';
									}
								}
								i++;
							}
							cout << save_num << endl;
							if (((11 - (save_num % 11)) % 10) == Back[6]) // 11-a의 값이 주민등록번호 제일 마지막 자리와 같아야 한다.		
							{										/*a는 12번째 자리까지 공식에 넣은 값의 mod 11 값이다.*/
								cout << "(11 - ( 각자리수 계산값 % 11))%10-> " << (11 - (save_num % 11)) % 10 << " = " << Back[6] << " <-주민등록번호 뒷자리 7번째 자리" << endl;
								cout << "올바른 주민등록번호입니다." << endl;
							}
							else
							{
								cout << "(11 - ( 각자리수 계산값 % 11))%10-> " << (11 - (save_num % 11)) % 10 << " != " << Back[6] << " <-주민등록번호 뒷자리 7번째 자리" << endl;
								cout << "올바르지 않는 주민등록번호입니다." << endl;
							}
						}
						else // 아니면 짤
						{
							cout << "1~29일 범위 밖입니다." << endl;
						}
					}
				}
				else // 나머지 짝수달
				{
					if ((front_num % 100 < 31 && front_num % 100 > 0)) // 1일이상 31일 이하일때 ok
					{
						if ((back_num / 100) % 100 > 0 && (back_num / 100) % 100 < 96) // 뒷자리 지역번호가 0복다 크고 96보다 작으면 ok
						{
							for (int i = 0; i < 6; i++) // 앞자리를 각 배열의 한칸씩에 저장하는 함수
							{
								Front[i] = ((front_num / Identify_POW(10, z)) % 10);
								z--;
							}
							z = 6; //뒷자리는 한자리 더 많으므로 초기값 변경
							for (int i = 0; i < 7; i++) // 뒷자리를 각 배열의 한칸씩에 저장하는 함수
							{
								Back[i] = ((back_num / Identify_POW(10, z)) % 10);
								z--;
							}
							int i = 0;
							while (i<12) // 12번째 자리까지 반복하는 이유는 13번째 자리는 에러검출하는 번호이다.
							{
								if (i < 6)
								{
									save_num += (Front[i] * (2 + i));
									cout << (Front[i] * (2 + i)) << '+';
								}
								else if (i<8)
								{
									save_num += (Back[i - 6] * (i + 2));
									cout << (Back[i - 6] * (i + 2)) << '+';
								}
								else
								{
									if (i == 11)
									{
										save_num += (Back[i - 6] * (i - 6));
										cout << (Back[i - 6] * (i - 6)) << '=';
									}
									else
									{
										save_num += (Back[i - 6] * (i - 6));
										cout << (Back[i - 6] * (i - 6)) << '+';
									}
								}
								i++;
							}
							cout << save_num << endl;
							if (((11 - (save_num % 11)) % 10) == Back[6]) // 11-a의 값이 주민등록번호 제일 마지막 자리와 같아야 한다.		
							{										/*a는 12번째 자리까지 공식에 넣은 값의 mod 11 값이다.*/
								cout << "(11 - ( 각자리수 계산값 % 11))%10-> " << (11 - (save_num % 11)) % 10 << " = " << Back[6] << " <-주민등록번호 뒷자리 7번째 자리" << endl;
								cout << "올바른 주민등록번호입니다." << endl;
							}
							else
							{
								cout << "(11 - ( 각자리수 계산값 % 11))%10-> " << (11 - (save_num % 11)) % 10 << " != " << Back[6] << " <-주민등록번호 뒷자리 7번째 자리" << endl;
								cout << "올바르지 않는 주민등록번호입니다." << endl;
							}
						}
						else //뒷자리 지역번호 짤
						{
							cout << "지역번호가 올바르지 않습니다." << endl;
						}
					}
					else // 1~30일 아니면 x
					{
						cout << "1~30일 범위에서 벗어났습니다. 다시 확인해 주세요." << endl;
					}
				}
			}
			else // 12월 안에 없으면 짤
			{
				cout << "1년은 12월 까지 있습니다." << endl;
			}
		}
		else // 뒷자리 1 or 2 아니면 짤 
		{
			cout << "주민등록번호 뒷자리가 잘못되었습니다." << endl;
		}
	}
}
// 생성일 : 17.07.13(목)
// 목  적 : 제곱기능을 math헤더의 pow함수를 쓰지않고 직접 구현하여 쓰기 위하여
// 기  능
/* 1. (10,20)을 입력했다면 10^20 계산을 하게 도와준다.*/
int Identify_POW(int a, int b)
{
	int result = 1;
	for (int i = 0; i < b; i++)
	{
		result *= a;
	}
	return result;
}