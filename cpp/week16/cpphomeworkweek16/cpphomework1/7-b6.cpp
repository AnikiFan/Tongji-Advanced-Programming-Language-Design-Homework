/* 2254298 信11 范潇 */
#include <iostream>
#include<cmath>
using namespace std;

/* 1、不允许定义任何类型的全局变量，包括常变量及宏定义等
   2、不允许给出任何形式的全局函数
*/

/* --- 将类的定义补充完整 --- */
class Days {
private:
	int year;
	int month;
	int day;
	//除上面的三个private数据成员外，不再允许添加任何类型的数据成员

	/* 下面可以补充需要的类成员函数的定义（不提供给外界，仅供本类的其它成员函数调用，因此声明为私有，数量不限，允许不定义） */

public:
	int calc_days();     //计算是当年的第几天

	/* 下面可以补充其它需要的类成员函数的定义(体外实现)，数量不限，允许不定义 */
	Days(int y, int m, int d);
};

/* --- 此处给出类成员函数的体外实现 --- */
Days::Days(int y, int m, int d)
{
	year = y;
	month = m;
	day = d;
}
int Days::calc_days()
{
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
				;
			else
				return month / 2 * 31 + (month - 1) / 2 * 30 - int(month >= 3) * 1 + int(month >= 9) * 1 - int(month >= 10) * 1 + int(month >= 11) * 1 - int(month >= 12) * 1 + int(month >= 13) * 1 + day;
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
				;
			else
				return  month / 2 * 31 + (month - 1) / 2 * 30 - int(month >= 3) * 2 + int(month >= 9) * 1 - int(month >= 10) * 1 + int(month >= 11) * 1 - int(month >= 12) * 1 + int(month >= 13) * 1 + day;
		}
	}
	else
		cout << "输入错误-月份不正确" << endl;//TODO:如果月日同时错，先判断月，输出此句
	return -1;
}
/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：main函数不准动
 ***************************************************************************/
int main()
{
	if (1) {
		Days d1(2020, 3, 18);
		cout << "应该输出78， 实际是：" << d1.calc_days() << endl;
	}

	if (1) {
		Days d1(2023, 3, 18);
		cout << "应该输出77， 实际是：" << d1.calc_days() << endl;
	}

	if (1) {
		Days d1(2020, 12, 31);
		cout << "应该输出366，实际是：" << d1.calc_days() << endl;
	}

	if (1) {
		Days d1(2023, 12, 31);
		cout << "应该输出365，实际是：" << d1.calc_days() << endl;
	}

	if (1) {
		Days d1(2020, 2, 29);
		cout << "应该输出60， 实际是：" << d1.calc_days() << endl;
	}

	if (1) {
		Days d1(2023, 2, 29);
		cout << "应该输出-1， 实际是：" << d1.calc_days() << endl;
	}

	return 0;
}
