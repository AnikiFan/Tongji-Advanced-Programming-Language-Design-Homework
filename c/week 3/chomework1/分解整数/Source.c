/* 2254298 信11 范潇 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int number;
	printf( "请输入一个[1..30000]间的整数:\n") ;
	scanf("%d", &number);
	printf( "万位 : %d\n", number / 10000 );
	printf( "千位 : %d\n", (number -= number / 10000 * 10000) / 1000 );//乘除为左结合
	printf( "百位 : %d\n", (number -= number / 1000 * 1000) / 100 );
	printf( "十位 : %d\n", (number -= number / 100 * 100) / 10) ;
	printf( "个位 : %d\n", (number -= number / 10 * 10) / 1 );
	return 0;
}