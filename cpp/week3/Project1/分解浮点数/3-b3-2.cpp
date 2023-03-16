/* 2254298 信11 范潇 */
#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
int main()
{
	double number;
	cout << setiosflags(ios::left) << "请输入[0-100亿)之间的数字: " << endl;
	cin >> number;
	number += 0.009;
	//加了该矫正值之后能避免小数点后第二位的数值改变,因为输入数据以小数点第二位为末尾,
	//所以当向下rounding的时候会改变小数点后第二位的数值,
	//加上该校正值后可避免该情况且不会改变小数点后第二位及之前的数值
	cout <<setw(6)<<"十亿位"<<" : "<<floor(number / pow(10, 9)) << endl;//floor是为了防止进位
	cout <<setw(6)<<"亿位"<<" : "<<floor((number -= floor(number / pow(10, 9)) * pow(10, 9)) / pow(10, 8)) << endl;//一个中文字符占2个宽度
	cout <<setw(6)<<"千万位"<<" : "<<floor((number -= floor(number / pow(10, 8)) * pow(10, 8)) / pow(10, 7)) << endl;
	cout <<setw(6)<<"百万位"<<" : "<<floor((number -= floor(number / pow(10, 7)) * pow(10, 7)) / pow(10, 6)) << endl;
	cout <<setw(6)<<"十万位"<<" : "<<floor((number -= floor(number / pow(10, 6)) * pow(10, 6)) / pow(10, 5)) << endl;
	cout <<setw(6)<<"万位"<<" : "<<floor((number -= floor(number / pow(10, 5)) * pow(10, 5)) / pow(10, 4)) << endl;
	cout <<setw(6)<<"千位"<<" : "<<floor((number -= floor(number / pow(10, 4)) * pow(10, 4)) / pow(10, 3)) << endl;
	cout <<setw(6)<<"百位"<<" : "<<floor((number -= floor(number / pow(10, 3)) * pow(10, 3)) / pow(10, 2)) << endl;
	cout <<setw(6)<<"十位"<<" : "<<floor((number -= floor(number / pow(10, 2)) * pow(10, 2)) / pow(10, 1)) << endl;
	cout <<setw(6)<<"圆"<<" : "<<floor((number -= floor(number / pow(10, 1)) * pow(10, 1)) / pow(10, 0)) << endl;
	cout <<setw(6)<<"角"<<" : "<<floor((number -= floor(number / pow(10, 0)) * pow(10, 0)) / pow(10, -1)) << endl;
	cout <<setw(6)<<"分"<<" : "<<floor((number -= floor(number / pow(10, -1)) * pow(10, -1)) / pow(10, -2)) << endl;
 
	return 0;
}