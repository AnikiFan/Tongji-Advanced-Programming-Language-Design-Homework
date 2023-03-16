/* 2254298 信11 范潇 */
#include<iostream>
using namespace std;
int main()
{
	int score;
	cout << "请输入成绩[0-100]" << endl;
	cin >> score;
	if (score >= 85 && score <= 100) {
		cout << "优" << endl;
	}
	else if (score >= 70 && score < 85) {
		cout << "良" << endl;
	}
	else if (score >= 60 && score < 70) {
		cout << "及格" << endl;
	}
	else if (score >= 0 && score < 60) {
		cout << "不及格" << endl;
	}
	else {
		cout << "输入错误" << endl;
	}
	return 0;
}