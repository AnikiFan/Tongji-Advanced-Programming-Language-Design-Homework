/* 2254298 信11 范潇 */
#include"popstar.h"
/***************************************************************************
  函数名称：reload
  功    能：
  输入参数：
  返 回 值：
  说    明：按回车键继续,清屏集成为一个函数
***************************************************************************/
void reload(void)
{
	char input[100];
	int xcoo, ycoo;
	cout << "本小题结束，请输入End继续...";
	while (1) {
		cin.get(input, 99);
		if ((input[0] == 'E' || input[0] == 'e') &&
			(input[1] == 'N' || input[1] == 'n') &&
			(input[2] == 'D' || input[2] == 'd'))
			break;
		input[0] = 0;
		input[1] = 0;
		input[2] = 0;
		cout << "输入错误，请重新输入";
		cct_getxy(xcoo, ycoo);
		cct_showch(29, ycoo - 1, ' ', background, 20);
		cct_setcolor(defaultColor);
		cct_gotoxy(29, ycoo - 1);
	}
	cct_cls();
	return;
}
void searchPlus(void)
{
	return;
}
void search(int srcRow, int srcCol,int matrix[][10],int rowMax,int colMax)
{
	int pivot = matrix[srcRow][srcCol];
	if (srcRow != 0 && matrix[srcRow - 1][srcCol] == pivot) {
		search(srcRow-1,srcCol,matrix[])
	}
	return;
}