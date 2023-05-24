/* 2254298 信11 范潇 */
#include"popstar.h"
void matrixInitialize(int rowMax, int colMax, int matrix[][10],bool zeroHighlight)
{
	int i, x, y;
	cout << "  |";
	for (i = 0; i < colMax; i++)
		cout << setiosflags(ios::right) << setw(3) << i << resetiosflags(ios::right);
	cout << endl;
	cout << setw(4 + 3 * colMax) << setfill('-') << "-" << endl;
	//
	//Sleep(1000);
	cct_getxy(x, y);
	for (i = 0; i < rowMax; i++) {
		cout << (char)('A' + i) << " | ";
		if (i != rowMax - 1)
			cout << endl;
	}
	matrixGenerator(matrix, 0, 2, rowMax, colMax, x + 5, y,zeroHighlight);
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
			if (input[0] >= 'A' && input[0] <= ('A' + rowMax - 1))
				row = input[0] - 'A';
			else
				row = input[0] - 'a';
			col = input[1] - '0';
			break;
		}
		cct_gotoxy(x, y);
		cout << "输入错误，请重新输入.";
		cct_showch(x, y, ' ', background, 30);
		cct_setcolor(defaultColor);
		cct_gotoxy(x, y);
		input[0] = '\0';
		input[1] = '\0';
	}
	return;
}

void module1(int rowMax, int colMax, int matrix[][10])
{
	int row, col, x, y, sum = 0, pivotMatrix[10][10] = { 0 },  i, j;
	cout << "当前数组:" << endl;
	cct_getxy(x, y);
	matrixInitialize(rowMax, colMax, matrix,false);
	while (1) {
		cout << endl;
		getCoordinate(row, col, rowMax, colMax);
		cout << "输入为" << (char)(row + 'A') << "行" << col << "列" << endl;
		sum = search(row, col, matrix, rowMax, colMax, 0, x + 5, y + 2, 0, 2, pivotMatrix, sum);
		if (sum == 1) {
			sum = 0;
			cout << "输入的矩阵坐标位置处无连续相同值，请重新输入" << endl;
		}
		else {
			cout<<endl << "查找结果数组:" << endl;
			cct_getxy(x, y);
			matrixInitialize(rowMax, colMax, pivotMatrix,false);
			for (i = 0; i < 10; i++)
				for (j = 0; j < 10; j++)
					pivotMatrix[i][j] = 0;
			search(row, col, matrix, rowMax, colMax, 2, x + 5, y + 2, 0, 2, pivotMatrix, sum);
			cct_gotoxy(x, y + 11);
			cout << endl << endl<<endl << "当前数组(不同色标识)"<<endl;
			for (i = 0; i < 10; i++)
				for (j = 0; j < 10; j++)
					pivotMatrix[i][j] = 0;
			cct_getxy(x, y);
			matrixInitialize(rowMax, colMax, matrix,false);
			search(row, col, matrix, rowMax, colMax, 1, x + 5, y + 2, 0, 2, pivotMatrix, sum);
			cct_gotoxy(x , y+13);
			break;
		}
	}
	//	cout << sum;
	return;
}
void module2(int rowMax, int colMax,int matrix[][10])
{
	int row, col, x, y, sum = 0, pivotMatrix[10][10] = { 0 }, i, j;
	char input;
	cout << "当前数组:" << endl;
	cct_getxy(x, y);
	matrixInitialize(rowMax, colMax, matrix,false);
	while (1) {
		cout << endl;
		getCoordinate(row, col, rowMax, colMax);
		cout << "输入为" << (char)(row + 'A') << "行" << col << "列" << endl;
		sum = search(row, col, matrix, rowMax, colMax, 0, x + 5, y + 2, 0, 2, pivotMatrix, sum);
		if (sum == 1) {
			sum = 0;
			cout << "输入的矩阵坐标位置处无连续相同值，请重新输入" << endl;
		}
		else {
			cout << endl << "查找结果数组:" << endl;
			cct_getxy(x, y);
			matrixInitialize(rowMax, colMax, pivotMatrix,false);
			for (i = 0; i < 10; i++)
				for (j = 0; j < 10; j++)
					pivotMatrix[i][j] = 0;
			search(row, col, matrix, rowMax, colMax, 2, x + 5, y + 2, 0, 2, pivotMatrix, sum);
			cct_gotoxy(x, y + 11);
			cout << endl << endl << endl << "当前数组(不同色标识)" << endl;
			for (i = 0; i < 10; i++)
				for (j = 0; j < 10; j++)
					pivotMatrix[i][j] = 0;
			cct_getxy(x, y);
			matrixInitialize(rowMax, colMax, matrix,false);
			search(row, col, matrix, rowMax, colMax, 1, x + 5, y + 2, 0, 2, pivotMatrix, sum);
			cct_gotoxy(x, y + 13);
			//之前部分与module1相同
			cout << "请确认是否把" << (char)(row + 'A') << col << "及周围的相同值消除(Y/N/Q)：";
			cct_getxy(x, y);
			while (1) {
				input = _getch();
				cout << input;
				if (input == 'y' || input == 'n' || input == 'q' || input == 'Y' ||input == 'N' || input == 'Q')
						break;
				cct_gotoxy(x, y);
				}
			switch (input) {
				default:
					break;
				case'y':
					input = 'Y';
						break;
				case'n':
					input = 'N';
					break;
				case'q':
					input = 'Q';
					break;
			}
			if (input == 'Y') {
				cout << endl;
				cout << endl << "相同值归并后的数组(不同色标识)：" << endl;
				cct_getxy(x, y);
				for (i = 0; i < 10; i++)
					for (j = 0; j < 10; j++)
						pivotMatrix[i][j] = 0;
				matrixInitialize(rowMax, colMax, matrix,false);
				sum = 0;
				search(row, col, matrix, rowMax, colMax, 3, x + 5, y + 2, 0, 2, pivotMatrix, sum);
				cct_gotoxy(x, y + 13);
				cout << "本次得分: " << sum * sum * 5 << " 总得分: " << sum * sum * 5 << endl;
				cout << endl << "按回车键进行数组下落操作..." ;
				while (_getch()!=13)
					;
				cout << endl;
				cout << "下落后的数组:" << endl;
				zeroMoving(matrix, rowMax, colMax);
				cct_getxy(x, y);
				matrixInitialize(rowMax, colMax, matrix, true);
				cct_gotoxy(x, y + 14);
			}
			else
				cout << endl; 
			break;
		}
	}
	return;
}
void module3(int rowMax, int colMax, int matrix[][10])
{
	return;
}