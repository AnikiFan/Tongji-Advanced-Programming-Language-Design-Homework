/* 2254298 信11 范潇 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	double radius, height, pi = 3.14159;
	printf("请输入半径和高度\n");
	scanf("%lf %lf", &radius, &height);
	printf("圆周长     : %.2f\n", 2.0 * pi * radius);
	printf("圆面积     : %.2f\n", pi * radius * radius);
	printf("圆球表面积 : %.2f\n", 4.0 * pi * radius * radius);
	printf("圆球体积   : %.2f\n", 4.0 / 3.0 * pi * radius * radius * radius);
	printf("圆柱体积   : %.2f\n", pi * radius * radius * height);
	return 0;
} 