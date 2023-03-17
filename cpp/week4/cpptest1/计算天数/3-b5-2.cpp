/* 2254298 信11 范潇 */
#include<iostream>//TODO:年月日要求整型，不考虑输入非整型的错误
#include<cmath>
using namespace std;//TODO:年不考虑整型范围，任何合理整型均认为正确，包括负数，本题的年只判断是否闰年
int main()
{
	int year, month, day;
	cout << "请输入年，月，日" << endl;//TODO:逗号为中文全角
	cin >> year >> month >> day;
	if (month > 0 && month <= 12) {//判断月份是否合法
		if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) {//如果是闰年
			if (month == 2 && !(1 <= day && day <= 29) ||
				month == 1 && !(1 <= day && day <= 31) ||
				month == 3 && !(1 <= day && day <= 31) ||
				month == 5 && !(1 <= day && day <= 31) ||
				month == 7 && !(1 <= day && day <= 31) ||
				month == 8 && !(1 <= day && day <= 31) ||
				month == 10 && !(1 <= day && day <= 31) ||
				month == 12 && !(1 <= day && day <= 31) ||
				month == 4 && !(1 <= day && day <= 30) ||
				month == 6 && !(1 <= day && day <= 30) ||
				month == 9 && !(1 <= day && day <= 30) ||
				month == 11 && !(1 <= day && day <= 30))

				cout << "输入错误-日与月的关系非法" << endl;
			else
				cout << year << "-" << month << "-" << day << "是" << year << "年的第"
				<< month / 2 * 31 + (month - 1) / 2 * 30 - int(month >= 3) * 1 + int(month >= 9) * 1 - int(month >= 10) * 1 + int(month >= 11) * 1 - int(month >= 12) * 1 + int(month >= 13) * 1 + day
				<< "天" << endl;//TODO:中间无空格,-为英文半角
		}
		else {//不是闰年
			if (month == 2 && !(1 <= day && day <= 28) ||
				month == 1 && !(1 <= day && day <= 31) ||
				month == 3 && !(1 <= day && day <= 31) ||
				month == 5 && !(1 <= day && day <= 31) ||
				month == 7 && !(1 <= day && day <= 31) ||
				month == 8 && !(1 <= day && day <= 31) ||
				month == 10 && !(1 <= day && day <= 31) ||
				month == 12 && !(1 <= day && day <= 31) ||
				month == 4 && !(1 <= day && day <= 30) ||
				month == 6 && !(1 <= day && day <= 30) ||
				month == 9 && !(1 <= day && day <= 30) ||
				month == 11 && !(1 <= day && day <= 30))
				cout << "输入错误-日与月的关系非法" << endl;
			else
				cout << year << "-" << month << "-" << day << "是" << year << "年的第"
				<< month / 2 * 31 + (month - 1) / 2 * 30 - int(month >= 3) * 2 + int(month >= 9) * 1 - int(month >= 10) * 1 + int(month >= 11) * 1 - int(month >= 12) * 1 + int(month >= 13) * 1 + day
				<< "天" << endl;//TODO:中间无空格,-为英文半角
		}
	}
	else
		cout << "输入错误-月份不正确" << endl;//TODO:如果月日同时错，先判断月，输出此句
	return 0;
}