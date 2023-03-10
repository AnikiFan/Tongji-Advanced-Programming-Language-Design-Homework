/* 2254298 信11 范潇 */
#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
int main()
{
	int side1, side2, angle;
	double pi = 3.14159;
	cout << "请输入三角形的两边及其夹角(角度)" << endl;
	cin >> side1 >> side2 >> angle;
	cout << "三角形面积为 : " << setiosflags(ios::fixed) << setprecision(3) << float(0.5 * side1 * side2 * sin(pi / 180 * angle))<<endl;

	return 0;
}