/* 2254298 信11 范潇 */
#include<iostream>
#include<math.h>
#include<iomanip>
using namespace std;
int main()
{
	int x,n=1,pi=1,i;
	double exp=1;
	cout << "请输入 x 的值[-10 ~ +65]" << endl;
	cin >> x;
	while (1) {
		pi = 1;
		for (i = 1; i <= n;  i++) {
			pi *= i;//累乘
		}
		if (pow(x, n) / pi < 1e-6) {
			break;
		}
		exp += pow(x, n) / pi;

		n++;
	}


	cout <<setprecision(10)<<"e^x=" <<exp<< endl;
	return 0;
}