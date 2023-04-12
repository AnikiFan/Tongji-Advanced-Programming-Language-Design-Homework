/* 2254298 信11 范潇 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int num = 0;
/* ----具体要求----
   1、不允许添加其它头文件
   2、不允许定义全局变量、静态局部变量
   3、不允许添加其它函数
   4、main函数处理输入，允许循环
   --------------------------------------------------------------------- */

   /***************************************************************************
	 函数名称：
	 功    能：打印n层汉诺塔的移动顺序
	 输入参数：int n：层数
			   char src：起始柱
			   char tmp：中间柱
			   char dst：目标柱
	 返 回 值：
	 说    明：1、函数名、形参、返回类型均不准动
			   2、本函数不允许出现任何形式的循环
   ***************************************************************************/
   //对于n层汉诺塔,先将起始柱上的n-1层移至中间柱,然后将留在起始柱的底层移至目标柱,再将中间柱上的n-1层移至目标柱上.
void hanoi(int n, char src, char tmp, char dst)
{
	if (n == 1) {
		num++;
		printf("%5d:  1# %c-->%c\n", num, src, dst);
		return;
	}
	hanoi(n - 1, src, dst, tmp);
	num++;
	printf("%5d:%3d# %c-->%c\n", num, n, src, dst);
	hanoi(n - 1, tmp, src, dst);
	return;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：1、完成输入、调用递归函数
			2、处理输入错误时，允许使用循环
			3、为了统一检查，不再允许添加其它函数（输入起始/目标柱的代码不要求统一函数处理，均直接放在main中）
***************************************************************************/


int main()
{
	int n, ret;
	char src, tmp, dst;
	printf("请输入汉诺塔的层数(1-16)\n");
	while (1) {
		ret = scanf("%d", &n);
		while (getchar() != '\n')
			;
		if (n >= 0 && n <= 16 && ret == 1)
			break;
		printf("请输入汉诺塔的层数(1-16)\n");
	}


	printf("请输入起始柱(A-C)\n");
	while (1) {
		ret = scanf("%c", &src);
		while (getchar() != '\n')
			;
		if ((src == 'A' || src == 'B' || src == 'C' || src == 'a' || src == 'b' || src == 'c') && ret == 1) {
			switch (src) {
				case 'a':
					src = 'A';
					break;
				case 'b':
					src = 'B';
					break;
				case 'c':
					src = 'C';
					break;
			}
			break;
		}
		printf("请输入起始柱(A-C)\n");
	}

	printf("请输入目标柱(A-C)\n");
	while (1) {
		ret = scanf("%c", &dst);
		while (getchar() != '\n')
			;
		if ((dst == 'A' || dst == 'B' || dst == 'C' || dst == 'a' || dst == 'b' || dst == 'c') && ret == 1)
			break;
		if (dst == src || dst == (src - 32) || dst == (src + 32))
			printf("目标柱(%c)不能与起始柱(%c)相同\n", src, src);
		printf("请输入目标柱(A-C)\n");
	}
	switch (dst) {
		case 'a':
			dst = 'A';
			break;
		case 'b':
			dst = 'B';
			break;
		case 'c':
			dst = 'C';
			break;
	}
	printf("移动步骤为:\n");
	tmp = (int)(src != 'A') * (int)(dst != 'A') * 'A' + (int)(src != 'B') * (int)(dst != 'B') * 'B' + (int)(src != 'C') * (int)(dst != 'C') * 'C';
	hanoi(n, src, tmp, dst);
	return 0;
}