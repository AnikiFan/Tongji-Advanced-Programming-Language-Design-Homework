/* 2254298 信11 范潇 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define max 1000
int main()//TODO:输出为浮点数的且未指定格式的，均要求 double 型，C++为 cout 缺省输出，C 为%lf 的缺省输出
{
	int array[max], inverse[max], i, j, temp, t;
	for (i = 0; i < max; i++)
		array[i] = -1;
	printf("请输入成绩（最多1000个），负数结束输入\n");
	for (i = 0; i < max; i++) {
		scanf("%d", &temp);
		if (temp >= 0)
			array[i] = temp;
		else
			break;
	}
	if (array[0] == -1)
		printf("无有效输入\n");
	else {
		printf("输入的数组为:\n");
		for (i = 0; i < max; i++) {
			if (array[i] >= 0)
				printf("%d ", array[i]);
			if (array[i] >= 0 && !((i + 1) % 10))
				printf("\n");
			else if (array[i] >= 0 && array[i + 1] == -1) {//i不会等于999
				printf("\n");
				break;
			}
		}
		printf("分数与人数的对应关系为:\n");
		for (i = 0; i < max - 1; i++)//冒泡法排序
			for (j = 0; j < max - (i + 1); j++)
				if (array[j] > array[j + 1]) {
					t = array[j];
					array[j] = array[j + 1];
					array[j + 1] = t;
				}
		for (i = 0; i < max; i++)
			inverse[i] = array[max - 1 - i];
	}
	j = -1;
	for (i = 0; i < max - 1; i++) {
		if (inverse[i + 1] < inverse[i]) {
			printf("%d %d\n", inverse[i], i - j);
			j = i;

		}
		if (inverse[max - 1] != -1)
			printf("%d %d\n", inverse[max - 1], max - 1 - j);
	}
	return 0;
}