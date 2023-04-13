/* 2254298 信11 范潇 */
#include<iostream>
#include<math.h>
#define delta b * b - 4 * a * c
using namespace std;
void same_real_root(double a, double b, double c)
{
	cout << "有两个相等实根：" << endl;
	if (-b / (2 * a) == -0)
		cout << "x1=x2=0" << endl;
	else
		cout << "x1=x2=" << -b / (2 * a) << endl;
	return;
}