/* 2254298 信11 范潇 */
#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include<cmath>
int main()
{
	double number;
	int temp;
	printf("请输入[0-100亿)之间的数字: \n");
	scanf("%lf", &number);
	number += 0.009;
	//加了该矫正值之后能避免小数点后第二位的数值改变,因为输入数据以小数点第二位为末尾,
	//所以当向下rounding的时候会改变小数点后第二位的数值,
	//加上该校正值后可避免该情况且不会改变小数点后第二位及之前的数值
	printf("%-7s%-2s%d\n", "十亿位", ":", (number / pow(10, 9)));//floor是为了防止进位
	printf("%-7s%-2s%d\n", "亿位", ":", ((number -= floor(number / pow(10, 9)) * pow(10, 9)) / pow(10, 8)));//一个中文字符占2个宽度
	printf("%-7s%-2s%d\n", "千万位", ":", ((number -= floor(number / pow(10, 8)) * pow(10, 8)) / pow(10, 7)));
	printf("%-7s%-2s%d\n", "百万位", ":", ((number -= floor(number / pow(10, 7)) * pow(10, 7)) / pow(10, 6)));
	printf("%-7s%-2s%d\n", "十万位", ":", ((number -= floor(number / pow(10, 6)) * pow(10, 6)) / pow(10, 5)));
	printf("%-7s%-2s%d\n", "万位", ":", ((number -= floor(number / pow(10, 5)) * pow(10, 5)) / pow(10, 4)));
	printf("%-7s%-2s%d\n", "千位", ":", ((number -= floor(number / pow(10, 4)) * pow(10, 4)) / pow(10, 3)));
	printf("%-7s%-2s%d\n", "百位", ":", ((number -= floor(number / pow(10, 3)) * pow(10, 3)) / pow(10, 2)));
	printf("%-7s%-2s%d\n", "十位", ":", ((number -= floor(number / pow(10, 2)) * pow(10, 2)) / pow(10, 1)));
	printf("%-7s%-2s%d\n", "圆", ":", ((number -= floor(number / pow(10, 1)) * pow(10, 1)) / pow(10, 0)));
	printf("%-7s%-2s%d\n", "角", ":", ((number -= floor(number / pow(10, 0)) * pow(10, 0)) / pow(10, -1)));
	printf("%-7s%-2s%d\n", "分", ":", ((number -= floor(number / pow(10, -1)) * pow(10, -1)) / pow(10, -2)));
	return 0;
}