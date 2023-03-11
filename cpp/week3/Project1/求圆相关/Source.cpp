/* 2254298 信11 范潇 */
#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	double radius, height,pi=3.14159;
	cout << "请输入半径和高度" << endl;
	cin >> radius >> height;
	cout << setiosflags(ios::fixed) << setprecision(2);
	cout <<"圆周长     : "<<2.0*pi*radius <<endl;
	cout <<"圆面积     : "<< pi*radius*radius<<endl;
	cout <<"圆球表面积 : " <<4.0*pi * radius * radius<<endl;
	cout <<"圆球体积   : " <<4.0/3.0*pi * radius * radius * radius <<endl;
	cout <<"圆柱体积   : " << pi * radius * radius*height<<endl;
	return 0;
}