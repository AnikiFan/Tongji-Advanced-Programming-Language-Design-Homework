/* 2254298 信11 范潇 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()//TODO:输出为浮点数的且未指定格式的，均要求 double 型，C++为 cout 缺省输出，C 为%lf 的缺省输出
{
	int year, month, day;
	printf("请输入年，月，日\n");//TODO:逗号为中文全角
	scanf("%d%d%d", &year, &month, &day);
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

				printf("输入错误-日与月的关系非法\n");
			else
				printf("%d-%d-%d是%d年的第%d天\n", year, month, day, year, month / 2 * 31 + (month - 1) / 2 * 30 - (month >= 3) * 1 + (month >= 9) * 1 - (month >= 10) * 1 + (month >= 11) * 1 - (month >= 12) * 1 + (month >= 13) * 1 + day);//TODO:中间无空格,-为英文半角
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
				printf("输入错误-日与月的关系非法\n");
			else
				printf("%d-%d-%d是%d年的第%d天\n", year, month, day, year, month / 2 * 31 + (month - 1) / 2 * 30 - (month >= 3) * 2 + (month >= 9) * 1 - (month >= 10) * 1 + (month >= 11) * 1 - (month >= 12) * 1 + (month >= 13) * 1 + day);//TODO:中间无空格,-为英文半角
		}
	}
	else
		printf("输入错误-月份不正确\n");//TODO:如果月日同时错，先判断月，输出此句
	return 0;
}