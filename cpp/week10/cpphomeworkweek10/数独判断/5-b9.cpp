/* 2254298 信11 范潇 */
#include<iostream>
using namespace std;
int main()
{
	int i = 0, j = 0, sudoku[81000], temp, invalidsudoku = 0, comparearray[9];
	cout << "请输入9*9的矩阵，值为1-9之间" << endl;
	while (i < 81) {

		while (1) {
			cin >> temp;
			if (temp >= 1 && temp <= 9 && !cin.rdstate()) {
				sudoku[i] = temp;
				break;
			}
			if (cin.rdstate()) {
				cin.clear();
				cin.ignore(10000000, '\n');//删了这个以后会死循环
			}

			cout << "请重新输入第" << i / 9 + 1 << "行" << (i + 1) % 9 << "列(行列均从1开始计数)的值" << endl;
		}

		i++;
	}
	for (i = 0; i < 9; i++) {
		for (j = 0; j < 9; j++)
			comparearray[j] = sudoku[j * 9 + i];
		invalidsudoku += ((comparearray[0] - 1 && comparearray[1] - 1 && comparearray[2] - 1 && comparearray[3] - 1 && comparearray[4] - 1 && comparearray[5] - 1 && comparearray[6] - 1 && comparearray[7] - 1 && comparearray[8]-1) ||
			(comparearray[0] - 2 && comparearray[1] - 2 && comparearray[2] - 2 && comparearray[3] - 2 && comparearray[4] - 2 && comparearray[5] - 2 && comparearray[6] - 2 && comparearray[7] - 2 && comparearray[8] - 2 ) ||
			(comparearray[0] - 3 && comparearray[1] - 3 && comparearray[2] - 3 && comparearray[3] - 3 && comparearray[4] - 3 && comparearray[5] - 3 && comparearray[6] - 3 && comparearray[7] - 3 && comparearray[8] - 3 ) ||
			(comparearray[0] - 4 && comparearray[1] - 4 && comparearray[2] - 4 && comparearray[3] - 4 && comparearray[4] - 4 && comparearray[5] - 4 && comparearray[6] - 4 && comparearray[7] - 4 && comparearray[8] - 4 ) ||
			(comparearray[0] - 5 && comparearray[1] - 5 && comparearray[2] - 5 && comparearray[3] - 5 && comparearray[4] - 5 && comparearray[5] - 5 && comparearray[6] - 5 && comparearray[7] - 5 && comparearray[8] - 5 ) ||
			(comparearray[0] - 6 && comparearray[1] - 6 && comparearray[2] - 6 && comparearray[3] - 6 && comparearray[4] - 6 && comparearray[5] - 6 && comparearray[6] - 6 && comparearray[7] - 6 && comparearray[8] - 6 ) ||
			(comparearray[0] - 7 && comparearray[1] - 7 && comparearray[2] - 7 && comparearray[3] - 7 && comparearray[4] - 7 && comparearray[5] - 7 && comparearray[6] - 7 && comparearray[7] - 7 && comparearray[8] - 7 ) ||
			(comparearray[0] - 8 && comparearray[1] - 8 && comparearray[2] - 8 && comparearray[3] - 8 && comparearray[4] - 8 && comparearray[5] - 8 && comparearray[6] - 8 && comparearray[7] - 8 && comparearray[8] - 8 ) ||
			(comparearray[0] - 9 && comparearray[1] - 9 && comparearray[2] - 9 && comparearray[3] - 9 && comparearray[4] - 9 && comparearray[5] - 9 && comparearray[6] - 9 && comparearray[7] - 9 && comparearray[8] - 9 ) );
	}
	for (i = 0; i < 9; i++) {
		for (j = 0; j < 9; j++)
			comparearray[j] = sudoku[i * 9 + j];
		invalidsudoku += ((comparearray[0] - 1 && comparearray[1] - 1 && comparearray[2] - 1 && comparearray[3] - 1 && comparearray[4] - 1 && comparearray[5] - 1 && comparearray[6] - 1 && comparearray[7] - 1 && comparearray[8] - 1 ) ||
			(comparearray[0] - 2 && comparearray[1] - 2 && comparearray[2] - 2 && comparearray[3] - 2 && comparearray[4] - 2 && comparearray[5] - 2 && comparearray[6] - 2 && comparearray[7] - 2 && comparearray[8] - 2) ||
			(comparearray[0] - 3 && comparearray[1] - 3 && comparearray[2] - 3 && comparearray[3] - 3 && comparearray[4] - 3 && comparearray[5] - 3 && comparearray[6] - 3 && comparearray[7] - 3 && comparearray[8] - 3) ||
			(comparearray[0] - 4 && comparearray[1] - 4 && comparearray[2] - 4 && comparearray[3] - 4 && comparearray[4] - 4 && comparearray[5] - 4 && comparearray[6] - 4 && comparearray[7] - 4 && comparearray[8] - 4) ||
			(comparearray[0] - 5 && comparearray[1] - 5 && comparearray[2] - 5 && comparearray[3] - 5 && comparearray[4] - 5 && comparearray[5] - 5 && comparearray[6] - 5 && comparearray[7] - 5 && comparearray[8] - 5) ||
			(comparearray[0] - 6 && comparearray[1] - 6 && comparearray[2] - 6 && comparearray[3] - 6 && comparearray[4] - 6 && comparearray[5] - 6 && comparearray[6] - 6 && comparearray[7] - 6 && comparearray[8] - 6) ||
			(comparearray[0] - 7 && comparearray[1] - 7 && comparearray[2] - 7 && comparearray[3] - 7 && comparearray[4] - 7 && comparearray[5] - 7 && comparearray[6] - 7 && comparearray[7] - 7 && comparearray[8] - 7) ||
			(comparearray[0] - 8 && comparearray[1] - 8 && comparearray[2] - 8 && comparearray[3] - 8 && comparearray[4] - 8 && comparearray[5] - 8 && comparearray[6] - 8 && comparearray[7] - 8 && comparearray[8] - 8) ||
			(comparearray[0] - 9 && comparearray[1] - 9 && comparearray[2] - 9 && comparearray[3] - 9 && comparearray[4] - 9 && comparearray[5] - 9 && comparearray[6] - 9 && comparearray[7] - 9 && comparearray[8] - 9));
	}
	for (int p = 0; p < 3; p++)
		for (int q = 0; q < 3; q++) {
			for (i = 0; i < 3; i++)
				for (j = 0; j < 3; j++)
					comparearray[i*3+j] = sudoku[p * 3 + q * 27 + i * 9 + j];
			invalidsudoku += ((comparearray[0] - 1 && comparearray[1] - 1 && comparearray[2] - 1 && comparearray[3] - 1 && comparearray[4] - 1 && comparearray[5] - 1 && comparearray[6] - 1 && comparearray[7] - 1 && comparearray[8] - 1 ) ||
				(comparearray[0] - 2 && comparearray[1] - 2 && comparearray[2] - 2 && comparearray[3] - 2 && comparearray[4] - 2 && comparearray[5] - 2 && comparearray[6] - 2 && comparearray[7] - 2 && comparearray[8] - 2 ) ||
				(comparearray[0] - 3 && comparearray[1] - 3 && comparearray[2] - 3 && comparearray[3] - 3 && comparearray[4] - 3 && comparearray[5] - 3 && comparearray[6] - 3 && comparearray[7] - 3 && comparearray[8] - 3 ) ||
				(comparearray[0] - 4 && comparearray[1] - 4 && comparearray[2] - 4 && comparearray[3] - 4 && comparearray[4] - 4 && comparearray[5] - 4 && comparearray[6] - 4 && comparearray[7] - 4 && comparearray[8] - 4 ) ||
				(comparearray[0] - 5 && comparearray[1] - 5 && comparearray[2] - 5 && comparearray[3] - 5 && comparearray[4] - 5 && comparearray[5] - 5 && comparearray[6] - 5 && comparearray[7] - 5 && comparearray[8] - 5 ) ||
				(comparearray[0] - 6 && comparearray[1] - 6 && comparearray[2] - 6 && comparearray[3] - 6 && comparearray[4] - 6 && comparearray[5] - 6 && comparearray[6] - 6 && comparearray[7] - 6 && comparearray[8] - 6 ) ||
				(comparearray[0] - 7 && comparearray[1] - 7 && comparearray[2] - 7 && comparearray[3] - 7 && comparearray[4] - 7 && comparearray[5] - 7 && comparearray[6] - 7 && comparearray[7] - 7 && comparearray[8] - 7 ) ||
				(comparearray[0] - 8 && comparearray[1] - 8 && comparearray[2] - 8 && comparearray[3] - 8 && comparearray[4] - 8 && comparearray[5] - 8 && comparearray[6] - 8 && comparearray[7] - 8 && comparearray[8] - 8 ) ||
				(comparearray[0] - 9 && comparearray[1] - 9 && comparearray[2] - 9 && comparearray[3] - 9 && comparearray[4] - 9 && comparearray[5] - 9 && comparearray[6] - 9 && comparearray[7] - 9 && comparearray[8] - 9 ));
		}
	cout << (invalidsudoku ? "不" : "") << "是数独的解";
	return 0;
}