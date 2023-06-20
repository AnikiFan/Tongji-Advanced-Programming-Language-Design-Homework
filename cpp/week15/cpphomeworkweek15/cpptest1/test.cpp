/* warning, this file is reserved for testing file only*/
/* warning, this file is reserved for testing file only*/
/* warning, this file is reserved for testing file only*/
#include<iostream>
using namespace std;
#define srcage 10
struct test
{
	double a;
	double b;
}test1;
struct demo
{
	char a;
	test test1;
}demo1;
int fun(int num)
{
	if (num == 1) {
		cout <<"第一个学生说:我" << srcage << "岁了" << endl;
		return srcage+2;
	}
	int temp = fun(num - 1) + 2;
	cout <<"第"<<num<<"个学生说:"<< "我" << temp << "岁了" << endl;
	return temp+2;
}
int main()
{
	int a = { 1,2 };
	cout << *a++ << endl;
	return 0;
}