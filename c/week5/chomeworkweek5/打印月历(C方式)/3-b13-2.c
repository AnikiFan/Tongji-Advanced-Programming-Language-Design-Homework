/* 2254298 信11 范潇 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()//TODO:输出为浮点数的且未指定格式的，均要求 double 型，C++为 cout 缺省输出，C 为%lf 的缺省输出
{
	int year, month, week, day, i = 0,ret;
	while (1) {
		printf("请输入年份(2000-2030)和月份(1-12) : ");
		ret=scanf("%d%d", &year,&month);
		if (year >= 2000 && year <= 2030 && month >= 1 && month <= 12 && ret == 2)
			break;
		printf("输入非法，请重新输入\n");
		if (ret != 2) {
			while (getchar() != '\n')
				;
		}
	}
	while (1) {
		printf("请输入%d年%d月1日的星期(0-6表示星期日-星期六) : ",year,month);
		ret = scanf("%d", &week);
		printf("\n");
		if (week >= 0 && week <= 6 && ret == 1)
			break;
		printf("输入非法，请重新输入\n");
		if (ret != 1) {
			while (getchar() != '\n')
				;

		}
	}
	printf("%d年%d月的月历为: \n",year,month);
	printf("星期日  星期一  星期二  星期三  星期四  星期五  星期六\n");
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
		printf("        ");
		i++;
	}
	for (i = 1; i <= day; i++) {
		printf("%4d    ",i);
		if (!((week + i) % 7) || i == day) {
			printf("\n");
		}
	}
	return 0;
}