/* 2254298 信11 范潇 */
#include<iostream>
using namespace std;
int max(int a, int b)
{
	return a >= b ? a : b;
}
int max(int a, int b, int c)
{
	a = a >= c ? a : c;
	return a >= b ? a : b;
}
int max(int a, int b, int c, int d)
{
	a = a >= c ? a : c;
	a = a >= d ? a : d;
	return a >= b ? a : b;
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
			else if (number[i] <= 0) {

				valid = false;
			}
		}
		if (valid) {
			switch (num) {
				case 2:
					cout << "max=" << max(number[0], number[1]);
					break;
				case 3:
					cout << "max=" << max(number[0], number[1], number[2]);
					break;
				case 4:
					cout << "max=" << max(number[0], number[1], number[2], number[3]);
					break;
			}
			break;
		}
		cin.clear();
		cin.ignore(100000, '\n');
		number[0] = 1;
		number[1] = 1;
		number[2] = 1;
		number[3] = 1;
	}
	cout << endl;
	return 0;
}