/* 2254298 信11 范潇 */
#define  _CRT_SECURE_NO_WARNINGS
#include<math.h>//单位为亿,(仟佰拾)万,(仟佰拾)圆,角,分/整
#include<stdio.h>
#include<string.h>
const char chnstr[] = "零壹贰叁肆伍陆柒捌玖"; /* 所有输出大写 "零" ~ "玖" 的地方，只允许从这个数组中取值 */
char result[256];  /* 除result外，不再允许定义任何形式的全局变量 */
char temp[10];
int main()
{
	strncat(temp, &chnstr[0], 2);
	strncat(temp, &chnstr[2], 2);

	printf("%s", temp);
	return 0;
}