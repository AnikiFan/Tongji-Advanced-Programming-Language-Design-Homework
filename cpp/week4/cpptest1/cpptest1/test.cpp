/* 2254298 信11 范潇 */
#include<iostream>//
#include<cmath>//单位为亿,(仟佰拾)万,(仟佰拾)圆,角,分/整
#include<iomanip>
using namespace std;
int main()
{
	double number;
	int  sh, ba, qi, wa, sw, bw, qw, yi, yu, ji, fe;
	bool zh = true, febl = false, jibl = false, wabl = false, yubl = false, yibl = false, zero = false;//zh为真时有整,其他位数对应bl值默认为负,即认为该为为0
	cout << setiosflags(ios::left) << "请输入[0-100亿)之间的数字: " << endl;
	cin >> number;
	number += 0.009;
	yi = floor((number -= floor(number / pow(10, 9)) * pow(10, 9)) / pow(10, 8));//一个中文字符占2个宽度
	qw = floor((number -= floor(number / pow(10, 8)) * pow(10, 8)) / pow(10, 7));
	bw = floor((number -= floor(number / pow(10, 7)) * pow(10, 7)) / pow(10, 6));
	sw = floor((number -= floor(number / pow(10, 6)) * pow(10, 6)) / pow(10, 5));
	wa = floor((number -= floor(number / pow(10, 5)) * pow(10, 5)) / pow(10, 4));
	qi = floor((number -= floor(number / pow(10, 4)) * pow(10, 4)) / pow(10, 3));
	ba = floor((number -= floor(number / pow(10, 3)) * pow(10, 3)) / pow(10, 2));
	sh = floor((number -= floor(number / pow(10, 2)) * pow(10, 2)) / pow(10, 1));
	yu = floor((number -= floor(number / pow(10, 1)) * pow(10, 1)) / pow(10, 0));
	ji = floor((number -= floor(number / pow(10, 0)) * pow(10, 0)) / pow(10, -1));
	fe = floor((number -= floor(number / pow(10, -1)) * pow(10, -1)) / pow(10, -2));
	//判断是否有整
	if (fe != 0) {
		zh = false;
		febl = true;
	}
	if (ji != 0) {
		jibl = true;
	}
	//判断亿千圆
	if (yi) {
		yibl = true;
	}
	if (wa || sw || bw || qw) {
		wabl = true;
	}
	if (yu || sh || ba || qi) {
		yubl = true;
	}




	//
	//输出
	//
	if (yibl) {
		switch (yi) {
		case 1:
			cout << "壹";
			break;
		case 2:
			cout << "贰";
			break;
		case 3:
			cout << "叁";
			break;
		case 4:
			cout << "肆";
			break;
		case 5:
			cout << "伍";
			break;
		case 6:
			cout << "陆";
			break;
		case 7:
			cout << "柒";
			break;
		case 8:
			cout << "捌";
			break;
		case 9:
			cout << "玖";
			break;
		}
		cout << "亿";
	}
	if (yibl && !(qw)) {
		zero = true;
		cout << "零";
	}





	if (yibl || wabl || yubl) {
		cout << "圆";
	}
	//角和分
	if (jibl) {
		switch (ji) {
		case 1:
			cout << "壹";
			break;
		case 2:
			cout << "贰";
			break;
		case 3:
			cout << "叁";
			break;
		case 4:
			cout << "肆";
			break;
		case 5:
			cout << "伍";
			break;
		case 6:
			cout << "陆";
			break;
		case 7:
			cout << "柒";
			break;
		case 8:
			cout << "捌";
			break;
		case 9:
			cout << "玖";
			break;
		}
		cout << "角";
	}
	if (febl) {
		switch (fe) {
		case 1:
			cout << "壹";
			break;
		case 2:
			cout << "贰";
			break;
		case 3:
			cout << "叁";
			break;
		case 4:
			cout << "肆";
			break;
		case 5:
			cout << "伍";
			break;
		case 6:
			cout << "陆";
			break;
		case 7:
			cout << "柒";
			break;
		case 8:
			cout << "捌";
			break;
		case 9:
			cout << "玖";
			break;
		}
		cout << "分";
	}
	//整
	if (zh) {
		cout << "整" << endl;
	}
	else {
		cout << endl;
	}
	return 0;
}