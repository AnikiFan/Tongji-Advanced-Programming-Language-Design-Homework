/* 2254298 信11 范潇 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX_X 26
#define MAX_Y 10
int main()
{
	int i, j, boom[MAX_Y + 2][MAX_X + 2] = { 0 }, num[MAX_Y + 2][MAX_X + 2] = { 0 }, sum = 0, validflag = 1;//扩大了一圈
	char input[MAX_Y + 2][MAX_X + 2] = { 0 }, correct[MAX_Y + 2][MAX_X + 2] = { 0 }, temp;

	for (i = 1; i < MAX_Y + 1; i++)
		for (j = 1; j < MAX_X + 1; j++) {
			temp = 0;
			while (temp != '*' && !(temp >= '0' && temp <= '8'))
				scanf("%c", &temp);
			input[i][j] = temp;

			//scanf("%c%c", &input[i][j],&temp);
			//printf("[%d][%d]%c\n",i,j, temp);
		}


 //for (i = 1; i < MAX_Y + 1; i++) {
 //	for (j = 1; j < MAX_X + 1; j++)
 //		printf("%c ", input[i][j]);
 //	printf("\n");
 //}
 //printf("\n");

	for (i = 1; i < MAX_Y + 1; i++)
		for (j = 1; j < MAX_X + 1; j++) {
			if (input[i][j] == '*') {
				boom[i][j]++;
				sum++;
			}
		}

//	for (i = 1; i < MAX_Y + 1; i++) {
//		for (j = 1; j < MAX_X + 1; j++)
//			printf("%d ", boom[i][j]);
//		printf("\n");
//	}

	if (sum != 50)
		printf("错误1\n");
	else {
		for (i = 1; i < MAX_Y + 1; i++)
			for (j = 1; j < MAX_X + 1; j++)
				num[i][j] += (boom[i - 1][j - 1] + boom[i - 1][j] + boom[i][j - 1] + boom[i + 1][j + 1] + boom[i + 1][j] + boom[i][j + 1] + boom[i + 1][j - 1] + boom[i - 1][j + 1]);
		for (i = 1; i < MAX_Y + 1; i++)
			for (j = 1; j < MAX_X + 1; j++)
				if (!boom[i][j] && (num[i][j]+'0') != input[i][j]) {
					validflag--;
				}
		if (validflag==1)
			printf("正确\n");
		else
			printf("错误2\n");
	}
	return 0;
}