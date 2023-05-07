/* 2254298 信11 范潇 */
#include <iostream>
#define MAX_X 26
#define MAX_Y 10
using namespace std;
int main()
{
	srand((unsigned int)(time(0)));
	int i, j, boom[MAX_Y + 2][MAX_X + 2] = { 0 }, h, l, num[MAX_Y + 2][MAX_X + 2] = { 0 };//扩大了一圈
	for (i = 0; i < 50; i++)
		while (1) {
			if (boom[h = (rand() % MAX_Y + 1)][l = (rand() % MAX_X + 1)] != 1) {
				boom[h][l] = 1;
				break;
			}
		}
	for (i = 1; i < MAX_Y + 1; i++)
		for (j = 1; j < MAX_X + 1; j++)
			num[i][j] += (boom[i - 1][j - 1] + boom[i - 1][j] + boom[i][j - 1] + boom[i + 1][j + 1] + boom[i + 1][j] + boom[i][j + 1] + boom[i + 1][j - 1] + boom[i - 1][j + 1]);
	for (i = 1; i < MAX_Y + 1; i++) {
		for (j = 1; j < MAX_X + 1; j++) {
			if (boom[i][j])
				cout << "* ";
			else
				cout << num[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	return 0;
}