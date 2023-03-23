/* 2254298 信11 范潇 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()//TODO:输出为浮点数的且未指定格式的，均要求 double 型，C++为 cout 缺省输出，C 为%lf 的缺省输出
{
	int i,j;
	for (i = 1; i <= 9; i++) {
		for (j = 1; j <= 9; j++) {
			if (j <= i&&i*j<=9) {
				printf("%dx%d=%d   ", j, i, i * j);
			}
			else if (j <= i && i * j >= 10) {
				printf("%dx%d=%d  ", j, i, i * j);
			}
			if (j == 9) {
				printf("\n");
			}
		}
	}
	return 0;
}