/* 2254298 信11 范潇 */
#include<iostream>//TODO:不考虑输入错误的情况（非法字符、超过规定范围、小数点后三位以上等）
#include<iomanip>
using namespace std;
int main()
{
	double num;

	int wsy = 0, esy = 0, sy = 0, wy = 0, yy = 0, wj = 0, yj = 0, wf = 0, ef = 0, yf = 0;//找零的张数
	cout << "请输入找零值：" << endl;//TODO:（中文冒号）
	cin >> num;
	num += 0.0001;

	if (int(num / 50)) {
		wsy = int(num / 50);
		num -= 50 * wsy;
	}
	if (int(num / 20)) {
		esy = int(num / 20);
		num -= 20 * esy;
	}
	if (int(num / 10)) {
		sy = int(num / 10);
		num -= 10 * sy;
	}
	if (int(num / 5)) {
		wy = int(num / 5);
		num -= 5 * wy;
	}
	if (int(num / 1)) {
		yy = int(num / 1);
		num -= 1 * yy;
	}
	if (int(num / 0.5)) {
		wj = int(num / 0.5);
		num -= 0.5 * wj;
	}
	if (int(num / 0.1)) {
		yj = int(num / 0.1);
		num -= 0.1 * yj;
	}
	if (int(num / 0.05)) {
		wf = int(num / 0.05);
		num -= 0.05 * wf;
	}
	if (int(num / 0.02)) {
		ef = int(num / 0.02);
		num -= 0.02 * ef;
	}
	if (int(num / 0.01)) {
		yf = int(num / 0.01);
		num -= 0.01 * yf;
	}
	//
	//输出
	//
	cout << setiosflags(ios::left) << "共" << wsy + esy + sy + wy + yy + wj + yj + wf + ef + yf << "张找零，具体如下：" << endl;//TODO:（中文逗号及冒号）
	if (wsy) {
		cout << setw(4) << "50元" << " : " << wsy << "张" << endl;//TODO:每种纸币的币值及数量（英文冒号，前后英文空格，上下对齐，数量为 0 不输出）
	}
	if (esy) {
		cout << setw(4) << "20元" << " : " << esy << "张" << endl;
	}
	if (sy) {
		cout << setw(4) << "10元" << " : " << sy << "张" << endl;
	}
	if (wy) {
		cout << setw(4) << "5元" << " : " << wy << "张" << endl;
	}
	if (yy) {
		cout << setw(4) << "1元" << " : " << yy << "张" << endl;
	}
	if (wj) {
		cout << setw(4) << "5角" << " : " << wj << "张" << endl;
	}
	if (yj) {
		cout << setw(4) << "1角" << " : " << yj << "张" << endl;
	}
	if (wf) {
		cout << setw(4) << "5分" << " : " << wf << "张" << endl;
	}
	if (ef) {
		cout << setw(4) << "2分" << " : " << ef << "张" << endl;
	}
	if (yf) {
		cout << setw(4) << "1分" << " : " << yf << "张" << endl;
	}
	return 0;
}