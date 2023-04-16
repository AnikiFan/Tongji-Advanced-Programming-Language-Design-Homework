/* 2254298 信11 范潇 */
#include<iostream>
#include<math.h>
#define delta b * b - 4 * a * c
using namespace std;
void dif_real_roots(double a, double b, double c)
{
	double neg, pos;
	neg = (-b - sqrt(delta)) / (2 * a);
	pos = (-b + sqrt(delta)) / (2 * a);
	if (fabs(sqrt(delta) / (2 * a)) < 1e-6)
		neg = pos = -b / (2 * a);
	if (fabs(pos) < 1e-6)
		pos = 0;
	if (fabs(neg) < 1e-6)
		neg = 0;
	cout << "有两个不等实根：" << endl;
	if (a > 0) {
		cout << "x1=" << pos << endl;
		cout << "x2=" << neg << endl;
	}
	else {
		cout << "x1=" << neg << endl;
		cout << "x2=" << pos << endl;
	}
	return;
}