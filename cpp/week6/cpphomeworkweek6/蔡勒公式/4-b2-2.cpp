/* 2254298 信11 范潇 */
#include<iostream>
#include<math.h>
using namespace std;

int zeller(int y, int m, int d)
{
	int c, w;
	y -= m == 1 || m == 2;
	c = y / 100;
	y %= 100;
	m += (m == 1 || m == 2) * 12;
	w = y + int(y / 4.0) + int(c / 4.0) - 2 * c + int(13 * (m + 1) / 5.0) + d - 1;
	return ((w + 77) % 7);//若只加7,则数据2000 4 13得出来的是-3
}

int invaliddaytest(int y,int m,int d)
{
	int max;
	switch (m) {
		case 1:
			max = 31;
			break;
		case 3:
			max = 31;
			break;
		case 5:
			max = 31;
			break;
		case 7:
			max = 31;
			break;
		case 8:
			max = 31;
			break;
		case 10:
			max = 31;
			break;
		case 12:
			max = 31;
			break;
		case 4:
			max = 30;
			break;
		case 6:
			max = 30;
			break;
		case 9:
			max = 30;
			break;
		case 11:
			max = 30;
			break;
		case 2:
			if (y % 4 == 0 && y % 100 != 0 || y % 400 == 0)
				max = 29;
			else
				max = 28;
			break;
	}
	return(1 <= d &&d<= max);
}

int main()
{
	int y, m, d;
	cout << "请输入年[1900-2100]、月、日：" << endl;
	while (1) {
		cin >> y >> m >> d;  
		if (y>=1900&&y<=2100  &&m>=1&&m<=12&&invaliddaytest(y,m,d)&& !cin.rdstate())
			break;
		else {
			cin.clear();
			cin.ignore(10000000, '\n');//删了这个以后会死循环
		}
		cout << "输入错误，请重新输入" << endl;
		cout << "请输入年[1900-2100]、月、日：" << endl;
	}
	switch (zeller(y,m,d)) {
		case 0:
			cout << "星期日" << endl;
			break;
		case 1:
			cout << "星期一" << endl;
			break;
		case 2:
			cout << "星期二" << endl;
			break;
		case 3:
			cout << "星期三" << endl;
			break;
		case 4:
			cout << "星期四" << endl;
			break;
		case 5:
			cout << "星期五" << endl;
			break;
		case 6:
			cout << "星期六" << endl;
			break;
	}
	return 0;
} 