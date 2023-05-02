/* 2254298 信11 范潇 */
#define maxday {31,28,31,30,31,30,31,31,30,31,30,31}//二月还要额外判断
#include<iostream>
#include<iomanip>
using namespace std;
int zeller(int y, int m, int d)
{
	int c, w;
	y -= m == 1 || m == 2;
	c = y / 100;
	y %= 100;
	m += (m == 1 || m == 2) * 12;
	w = y + int(y / 4.0) + int(c / 4.0) - 2 * c + int(13 * (m + 1) / 5.0) + d - 1;
	return ((w + 77) % 7);//若只加7,则数据2000 4 13得出来的是-3
}
int maxnum(int a, int b, int c)
{
	if (a < b)
		a = b;
	if (a < c)
		a = c;
	return a;

}
int main()
{
	int year, i, size[12], startposition[12], height[4], calaendarrow[4][200] = { {0},{0},{0},{0} }, j, k, lastday[12] = maxday, r;

	cout << "请输入年份[1900-2100]" << endl;
	cin >> year;
	lastday[1] += year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
	cout << year << "年的日历:" << endl;
	cout << endl;
	for (i = 0; i < 12; i++)
		size[i] = lastday[i] + (startposition[i] = zeller(year, i + 1, 1));
	for (i = 0; i < 4; i++)
		height[i] = (maxnum(size[3 * i], size[3 * i + 1], size[3 * i + 2]) - 1) / 7 + 1;
	for (i = 0; i < 4; i++)
		for (j = 0; j < 3; j++)
			for (k = 0; k < lastday[3 * i + j]; k++)
				calaendarrow[i][j * 7 * height[i] + startposition[3 * i + j] + k] = k + 1;


	for (r = 0; r < 4; r++) {



		cout << "            " << 1 + r * 3 << "月                             " << 2 + r * 3 << "月                             " << 3 + r * 3 << "月             " << endl;

		cout << "Sun Mon Tue Wed Thu Fri Sat     Sun Mon Tue Wed Thu Fri Sat     Sun Mon Tue Wed Thu Fri Sat" << endl;

		for (i = 0; i < height[r]; i++) {
			for (j = 0; j < 21; j++) {
				cout << setw(3) << setiosflags(ios::left);
				if (calaendarrow[r][j % 7 + j / 7 * height[r] * 7 + i * 7] == 0)
					cout << " ";
				else
					cout << calaendarrow[r][j % 7 + j / 7 * height[r] * 7 + i * 7];
				cout << " ";
				if ((j + 1) % 7 == 0)
					cout << "    ";
			}
			cout << endl;
		}
		cout << endl;
	}
	cout << endl;
	return 0;
}