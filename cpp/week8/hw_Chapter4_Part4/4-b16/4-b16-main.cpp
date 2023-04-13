/* 2254298 信11 范潇 */
#include<iostream>
#include<math.h>
#include "4-b16.h"
#define delta b * b - 4 * a * c
using namespace std;
int main()
{
	double a, b, c;
	cout << "请输入一元二次方程的三个系数a,b,c:" << endl;
	cin >> a >> b >> c;
	if (fabs(b) < 1e-6)
		b = 0;
	if (fabs(c) < 1e-6)
		c = 0;
	if (cin.rdstate() || fabs(a) < 1e-6)
		invalid();
	else if (fabs(delta) < 1e-6)
		same_real_root(a, b, c);
	else if (delta > 0)
		dif_real_roots(a, b, c);
	else
		im_roots(a, b, c);
	return 0;
}