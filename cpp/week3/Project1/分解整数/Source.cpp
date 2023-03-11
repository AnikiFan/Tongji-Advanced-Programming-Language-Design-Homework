/* 2254298 信11 范潇 */
#include<iostream>
using namespace std;
int main()
{
	int number;
	cout << "请输入一个[1..30000]间的整数:" << endl;
	cin >> number;
	cout << "万位 : "<< number/10000<< endl;
	cout<< "千位 : "<<(number-= number / 10000*10000)/1000 << endl;//乘除为左结合
	cout<< "百位 : "<< (number -=  number / 1000 * 1000) / 100 << endl;
	cout<< "十位 : "<< (number -=  number / 100 * 100) / 10 << endl;
	cout << "个位 : " << (number -=  number / 10 * 10) / 1 << endl;
	return 0;
}