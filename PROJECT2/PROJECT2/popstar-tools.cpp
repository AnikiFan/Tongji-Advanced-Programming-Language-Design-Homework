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
	//
	//cout << "*";
	//
	while (1) {
		cin.getline(input, 99,'\n');
		if ((input[0] == 'E' || input[0] == 'e') &&
			(input[1] == 'N' || input[1] == 'n') &&
			(input[2] == 'D' || input[2] == 'd'))
			break;
		input[0] = 0;
		input[1] = 0;
		input[2] = 0;
		cout << "输入错误，请重新输入";
		//
//cout << "*";
//
		cct_getxy(xcoo, ycoo);
		cct_showch(28, ycoo - 1, ' ', background, 20);
		cct_setcolor(defaultColor);
		cct_gotoxy(28, ycoo - 1);
	}
	cct_cls();
	return;
}
void searchPlus(int srcRow, int srcCol, int matrix[][10], int rowMax, int colMax, int option, int x, int y,int rowInterval,int colInterval,int pivot)
{
	switch (option) {
		case 1:
			cct_showch(x + srcCol - 1 + srcCol * colInterval, y + srcRow - 1 + srcRow * rowInterval, pivot,highlight, 1);
			cct_setcolor(defaultColor);
			break;
	}
	return;
}
int search(int srcRow, int srcCol, int matrix[][10], int rowMax, int colMax,int option,int x,int y, int rowInterval, int colInterval)//xy为第一个元素的坐标
{
	int pivot = matrix[srcRow][srcCol],sum=1;
	if (srcRow != 0 && matrix[srcRow - 1][srcCol] == pivot) {
		searchPlus(srcRow, srcCol, matrix, rowMax, colMax, option, x, y,rowInterval,colInterval,pivot);//对当前元素进行额外操作
		sum++;
		search(srcRow - 1, srcCol, matrix, rowMax, colMax,option,x,y,rowInterval,colInterval);
	}
	if (srcCol != 0 && matrix[srcRow][srcCol - 1] == pivot) {
		searchPlus(srcRow, srcCol, matrix, rowMax, colMax, option, x, y,rowInterval,colInterval,pivot);//对当前元素进行额外操作
		sum++;
		search(srcRow, srcCol - 1, matrix, rowMax, colMax,option,x,y,rowInterval,colInterval);
	}
	if (srcRow != rowMax && matrix[srcRow + 1][srcCol] == pivot) {
		searchPlus(srcRow, srcCol, matrix, rowMax, colMax, option, x, y,rowInterval,colInterval,pivot);//对当前元素进行额外操作
		sum++;
		search(srcRow + 1, srcCol, matrix, rowMax, colMax,option,x,y,rowInterval,colInterval);
	}
	if (srcCol != colMax && matrix[srcRow][srcCol + 1] == pivot) {
		searchPlus(srcRow, srcCol, matrix, rowMax, colMax, option, x, y,rowInterval,colInterval,pivot);//对当前元素进行额外操作
		sum++;
		search(srcRow, srcCol + 1, matrix, rowMax, colMax,option,x,y,rowInterval,colInterval);
	}
	return sum;
}
void matrixGenerator(int matrix[][10], int rowInterval, int colInterval, int rowMax, int colMax, int srcxcoo, int srcycoo)//起始坐标为(1,1)元位置,元素左侧有空格
{
	int i, j;
	cct_gotoxy(srcxcoo, srcycoo);
	cout << setfill(' ');
	for (i = 0; i < rowMax; i++) {
		for (j = 0; j < colMax; j++)
			cout << setw(colInterval + 1) << setiosflags(ios::left) << matrix[i][j];
		if(i!=rowMax-1)
		cct_gotoxy(srcxcoo, srcycoo + i * rowInterval + i + 1);
	}
	cout << endl;
	return;
}