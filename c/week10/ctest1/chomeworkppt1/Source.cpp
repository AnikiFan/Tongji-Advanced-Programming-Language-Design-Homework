#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<string.h>
int main()
{
	char str[13], output[30];
	int  w;
	printf("请输入[3..12]间的字符串及显示宽度[len+1..20]\n");
	scanf("%s %d", str, &w); //不考虑输入错误
	printf("01234567890123456789\n"); //标尺
	if (w <= (int)strlen(str))
		w = strlen(str) + 1;
	sprintf(output, "%%-%ds*", w);
	printf(output, str);
	return 0;
}
