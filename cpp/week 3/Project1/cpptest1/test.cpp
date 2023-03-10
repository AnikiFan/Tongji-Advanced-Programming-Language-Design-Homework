/* warning, this file is reserved for testing file only*/
/* warning, this file is reserved for testing file only*/
/* warning, this file is reserved for testing file only*/
#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
int main()
{
	double number,number1;
	cout << "请输入[0 - 100亿)之间的数字:" << endl;
	cin >> number;
	cout << floor(number / pow(10, 9)) << endl;//floor是为了防止进位
	cout << floor((number -= floor(number / pow(10, 9)) * pow(10, 9)) / pow(10, 8)) << endl;
	cout << floor((number -= floor(number / pow(10, 8)) * pow(10, 8)) / pow(10, 7)) << endl;
	cout << floor((number -= floor(number / pow(10, 7)) * pow(10, 7)) / pow(10, 6)) << endl;
	cout << floor((number -= floor(number / pow(10, 6)) * pow(10, 6)) / pow(10, 5)) << endl;
	cout << floor((number -= floor(number / pow(10, 5)) * pow(10, 5)) / pow(10, 4)) << endl;
	cout << floor((number -= floor(number / pow(10, 4)) * pow(10, 4)) / pow(10, 3)) << endl;
	cout << floor((number -= floor(number / pow(10, 3)) * pow(10, 3)) / pow(10, 2)) << endl;
	cout << floor((number -= floor(number / pow(10, 2)) * pow(10, 2)) / pow(10, 1)) << endl;
	cout << floor((number -= floor(number / pow(10, 1)) * pow(10, 1)) / pow(10, 0)) << endl;
	cout << number << endl;
	cout << floor((number -= floor(number )) *pow(10, 1)) << endl;
	cout << number << endl;
	number1 = number;
	cout << floor((number1 -= floor(number1 * pow(10, 1)) / pow(10, 1)) * pow(10, 2)) << endl;

	cout << number1 << endl;
	cout << floor(number1 * pow(10, 2)) << endl;
	cout << number1 << endl;

	cout << "   " << endl;
	number1 = 0.99;
	cout << floor((number1 -= floor(number1 * pow(10, 1)) / pow(10, 1)) * pow(10, 2)) << endl;

	cout << number1 << endl;
	cout << floor(number1 * pow(10, 2)) << endl;
	cout << number1 << endl;
	number = 0.99;
	cout << (number -= floor(number / pow(10, -1)) * pow(10, -1)) << endl;
	cout << "请输入[0 - 100亿)之间的数字:" << endl;
	cin >> number;
	cout <<123<< "\033\033\033"<<123;
	cout << setiosflags(ios::fixed) << setprecision(2) << setw(13) << setfill('0') << endl;
	cout<< "1" << number <<"1" <<endl;

	return 0;
}