/* 2254298 信11 范潇 */
#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	int year, month, week, day,i=0;
	while (1) {
		cout << "请输入年份(2000-2030)和月份(1-12) : ";
		cin >> year >> month;
		if (year >= 2000 && year <= 2030 && month >= 1 && month <= 12 && !cin.rdstate())
			break;
		else if (cin.rdstate()) {
			cin.clear();
			cin.sync();
			cin.ignore(10000000, '\n');//删了这个以后会死循环
		}
		cout << "输入非法，请重新输入" << endl;
	}
	while (1) {
		cout << "请输入" << year << "年" << month << "月1日的星期(0-6表示星期日-星期六) : ";
		cin >> week;
		cout << endl;
		if (week >= 0 && week <= 6 && !cin.rdstate())
			break;
		else if (cin.rdstate()) {
			cin.clear();
			cin.sync();
			cin.ignore(10000000, '\n');//删了这个以后会死循环
		}
		cout << "输入非法，请重新输入" << endl;
	}
	cout << year << "年" << month << "月的月历为:" << endl;
	cout << "星期日  星期一  星期二  星期三  星期四  星期五  星期六" << endl;
	switch (month) {
		case 1:
			day = 31;
			break;
		case 3:
			day = 31;
			break;
		case 5:
			day = 31;
			break;
		case 7:
			day = 31;
			break;
		case 8:
			day = 31;
			break;
		case 10:
			day = 31;
			break;
		case 12:
			day = 31;
			break;
		case 4:
			day = 30;
			break;
		case 6:
			day = 30;
			break;
		case 9:
			day = 30;
			break;
		case 11:
			day = 30;
			break;
		case 2:
			if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
				day = 29;
			else
				day = 28;
			break;
	}
	while (i <= week - 1) {
		cout << "        ";
		i++;
	}
	for (i = 1; i <= day; i++) {
		cout << setw(4) << i << "    ";
		if (!((week +  i) % 7)||i==day) {
			cout << endl;
		}
	}
	return 0;
}