/* 2254298 信11 范潇 */
#include<iostream>
#include<iomanip>
using namespace std;
void generator(int output[][14], int n, int i)
{
	int j;
	if (i == 0) {
		output[0][n - 1] = 1;
		return;
	}
	generator(output, n, i - 1);
	for (j = n - i - 1; j < n; j++)
		output[i][j] = output[i - 1][j] + output[i - 1][j + 1];
	return;
}
int main()
{
	int  n, j, i, output[13][14] = { 0 };
	cout << "请输入要打印的行数[3..13]" << endl;
	cin >> n;
	cout << "--------------------------------------------------------------------------------" << endl;
	cout << "0         1         2         3         4         5         6         7         " << endl;
	cout << "01234567890123456789012345678901234567890123456789012345678901234567890123456789" << endl;
	cout << "--------------------------------------------------------------------------------" << endl;
	generator(output, n, n - 1);
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++)
			if (output[i][j] != 0)
				cout << setw(6) << output[i][j];
			else
				cout << setw(6) << " ";
		cout << endl;
	}
	cout << "--------------------------------------------------------------------------------" << endl;
	cout << "01234567890123456789012345678901234567890123456789012345678901234567890123456789" << endl;
	cout << "0         1         2         3         4         5         6         7         " << endl;
	cout << "--------------------------------------------------------------------------------" << endl;
	cout << endl;
	return 0;
}