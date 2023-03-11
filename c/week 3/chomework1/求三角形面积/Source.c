/* 2254298 信11 范潇 */
#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include<math.h>
int main()
{
	int side1, side2, angle;
	double pi = 3.14159;
	printf( "请输入三角形的两边及其夹角(角度)\n");
	scanf("%d %d %d", &side1, &side2, &angle);
	printf("三角形面积为 : %.3f", (float)(0.5 * side1 * side2 * sin(pi / 180.0 * angle)));

	return 0;
}