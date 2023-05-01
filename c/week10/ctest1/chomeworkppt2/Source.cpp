#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<string.h>
int main()
{
	char  output[30];
	int  w, digitw;
	double num;
	printf("请输入double型数据及显示总宽度,小数点后位数\n");
	scanf("%lf %d %d", &num, &w, &digitw); //不考虑输入错误
	printf("01234567890123456789\n"); //标尺
	sprintf(output, "%%%d.%dlf*", w, digitw);
	printf(output, num);
	return 0;
}
