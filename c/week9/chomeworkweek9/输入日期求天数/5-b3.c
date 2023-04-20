/* 2254298 信11 范潇 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define maxday {31,28,31,30,31,30,31,31,30,31,30,31}//二月还要额外判断
#define accumulate {0,31,59,90,120,151,181,212,243,273,304,334}//二月还要额外判断
int invaliddaytest(int y, int m, int d)
{
	int max[12] = maxday;
	max[1] += y % 4 == 0 && y % 100 != 0 || y % 400 == 0;
	return(1 <= d && d <= max[m-1]);
}
int currentday(int y, int m, int d)
{
	int i,accumulateday[12]=accumulate;
	for (i = 1; i < 12; i++)
		accumulateday[i]+= y % 4 == 0 && y % 100 != 0 || y % 400 == 0;
	return(accumulateday[m - 1] + d);
}
int main()//TODO:输出为浮点数的且未指定格式的，均要求 double 型，C++为 cout 缺省输出，C 为%lf 的缺省输出
{
	int year, month, day;
	int max[12] = maxday;
	printf("请输入年，月，日\n");//TODO:逗号为中文全角
	scanf("%d%d%d", &year, &month, &day);
	max[1] =year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
	if (month > 0 && month <= 12) {//判断月份是否合法
			if (day<1||day>max[month-1])
				printf("输入错误-日与月的关系非法\n");
			else
				printf("%d-%d-%d是%d年的第%d天\n", year, month, day, year, currentday(year,month,day));//TODO:中间无空格,-为英文半角
	}
	else
		printf("输入错误-月份不正确\n");//TODO:如果月日同时错，先判断月，输出此句
	return 0;
}