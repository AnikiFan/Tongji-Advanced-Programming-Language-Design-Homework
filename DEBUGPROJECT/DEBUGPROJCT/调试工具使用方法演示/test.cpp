/*2254298 信11 范潇*/
#include<iostream>
using namespace std;
void fun(void) 
{
	cout << "调用fun函数" << endl;
	cout << sqrt(0) << endl;
	cout << "fun函数调用结束" << endl;
	return;
}
int main()
{
	cout << "程序开始" << endl;
	cout << "test" << endl;
	fun();
	fun();
	cout << "程序结束" << endl;
	return 0;
}