/* 2254298 信11 范潇 */
#include<iostream>
using namespace std;
int main()
{
	int year, month, week;
	cout << "请输入年份(2000-2030)和月份(1-12) : " << endl;
	cin >> year>>month;
	cout << "请输入"<<year<<"年"<<month<<"月1日的星期(0 - 6表示星期日 - 星期六) : " << endl;
	cin >> week;
	cout << year<<"年"<<month<<"月的月历为: " << endl;
	cout << "星期日  星期一  星期二  星期三  星期四  星期五  星期六" << endl;
	return 0;
}