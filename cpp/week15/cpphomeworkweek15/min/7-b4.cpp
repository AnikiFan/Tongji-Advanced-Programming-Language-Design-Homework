/* 2254298 信11 范潇 */
#include<iostream>
using namespace std;
int min(int a, int b, int c = 0, int d = 0)
{
	if (c)
		a = a <= c ? a : c;
	if (d)
		a = a <= d ? a : d;
	return a <= b ? a : b;
}
int main()
{
	int number[4] = { 0 }, num, i;
	bool valid;
	while (1) {
		while (1) {
			cout << "请输入个数num及num个正整数:" << endl;
			cin >> num;
			if (num == 2 || num == 3 || num == 4)
				break;
			else if (cin.rdstate()) {
				cin.clear();
				cin.ignore(1000000, '\n');

			}
			else {
				cout << "个数输入错误" << endl;
				return 0;
			}
		}
		valid = true;
		for (i = 0; i < num; i++) {
			cin >> number[i];
			if (cin.rdstate()) {


				valid = false;
				break;
			}
			else if (number[i] <= 0)
				valid = false;
		}
		if (valid) {
			cout << "min=" << min(number[0], number[1], number[2], number[3]);
			break;
		}
		cin.clear();
		cin.ignore(100000, '\n');
		number[0] = 0;
		number[1] = 0;
		number[2] = 0;
		number[3] = 0;
	}
	cout << endl;
	return 0;
}