/* 2254298 信11 范潇 */
#include"popstar.h"
void matrixInitialize(int rowMax, int colMax, int matrix[][10])
{
	int i, x, y;
	cout << "  | ";
	for (i = 0; i < colMax; i++)
		cout << setw(2) << i;
	cout << endl;
	cout << setw(5 + 2 * colMax) << setfill('=') << endl;
	cct_getxy(x, y);
	for (i = 0; i < rowMax; i++)
		cout << (char)('A' + i) << " | " << endl;
	matrixGenerator(matrix, 0, 1, rowMax, colMax, x + 4, y);
}
void getCoordinate(int& row, int& col, int rowMax, int colMax)
{
	int x, y;
	char input[100];
	cout << "请以字母+数字形式[例：c2]输入矩阵坐标：";
	cct_getxy(x, y);
	while (1) {
		cin.getline(input, 99);
		if ((input[0] >= 'a' && input[0] <= ('a' + rowMax - 1) || input[0] >= 'A' && input[0] <= ('A' + rowMax - 1)) && (input[1] >= '0' && input[1] <= '0' + colMax - 1)) {
			row = input[0];
			col = input[1];
			break;
		}
		cout << "输入错误，请重新输入.";
		cct_showch(x, y, background, 20);
		cct_setcolor(defaultColor);
		cct_gotoxy(x, y);
		input[0] = '\0';
		input[1] = '\0';
	}
	return;
}

void module1(int rowMax, int colMax, int matrix[][10])
{
	cout << "当前数组:" << endl;
	matrixInitialize(rowMax, colMax, matrix);
	cout << endl;
	return;
}
void module2(int rowMax, int colMax)
{
	return;
}
void module3(int rowMax, int colMax)
{
	return;
}