
// tast1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "iostream"
using namespace std;
class CTerigele
{
private:
	int year;
	int month;
	int day;
	int hour;
	int minute;
	int second;
	int check();
public:
	CTerigele();
	CTerigele(int y, int m, int d, int h, int n, int s);
	int setTime(int y, int m, int d, int h, int n, int s);
	void displayTime();

};
CTerigele::CTerigele()
{
	year = 2019;
	month = 01;
	day = 01;
}
CTerigele::CTerigele(int y, int m, int d, int h, int n, int s)
{
	year = y;
	month = m;
	day = d;
	hour = h;
	minute = n;
	second = s;
	if (check() == 1 || check() == -1)
	{
		month = 0;
		day = 0;
		hour = 0;
		minute = 0;
		second = 0;
		cout << "设置了错误日期，月日已重置初始" << endl;
	}
}
int CTerigele::setTime(int y, int m, int d, int h, int n, int s)
{
	cin >> y >> m >> d >> h >> n >> s;
	year = y;
	month = m;
	day = d;
	hour = h;
	minute = n;
	second = s;
	if (check() == 1 || check() == -1)
	{
		month = 0;
		day = 0;
		hour = 0;
		minute = 0;
		second = 0;
		cout << "设置了错误日期，月日已置1" << endl;
		return -1;
	}

	return 0;
}
void CTerigele::displayTime()
{
	cout << year << "年" << month << "月" << day << "日" << endl << hour << "时" << minute << "分" << second << "秒" << endl;
}
int CTerigele::check()
{
	int flatYearDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	int leapYearDays[12] = { 31,29,31,30,31,30,31,31,30,31,30,31 };
	if (month > 12 || month < 1)
		return -1;
	if (year % 400 == 0 || (year % 100 != 0 && year % 4 == 0))
	{
		if (leapYearDays[month - 1] < day || day < 1)
			return 1;
	}
	else
	{
		if (flatYearDays[month - 1] < day || day < 1)
			return 1;
	}
	if (hour > 24 || hour < 0)
		return -1;
	if (minute > 60 || minute < 0)
		return -1;
	if (second > 60 || second < 0)
		return -1;
	return 0;
}

int main()
{
	CTerigele cm;
	cm.setTime(2019, 01, 01, 0, 0, 0);
	cm.displayTime();
	return 0;
}