/* 2254298 信11 范潇 */
#include<iostream>//
#include<math.h>//单位为亿,(仟佰拾)万,(仟佰拾)圆,角,分/整
#include<iomanip>
using namespace std;
int main()
{
	double number;
	int  sh, ba, qi, wa, sw, bw, qw, yi, sy, by, yu, ji, fe;
	bool zh = true, febl = false, jibl = false, wabl = false, yubl = false, yibl = false;//zh为真时有整,其他位数对应bl值默认为负,即认为该为为0
	bool zero = false, nozero = false;
	cout << setiosflags(ios::left) << "请输入[0-100亿)之间的数字:" << endl;
	cin >> number;
	number += 0.009;
	by = int(floor(number / pow(10, 10)));
	sy = int(floor((number -= floor(number / pow(10, 10)) * pow(10, 10)) / pow(10, 9)));
	yi = int(floor((number -= floor(number / pow(10, 9)) * pow(10, 9)) / pow(10, 8)));//一个中文字符占2个宽度
	qw = int(floor((number -= floor(number / pow(10, 8)) * pow(10, 8)) / pow(10, 7)));
	bw = int(floor((number -= floor(number / pow(10, 7)) * pow(10, 7)) / pow(10, 6)));
	sw = int(floor((number -= floor(number / pow(10, 6)) * pow(10, 6)) / pow(10, 5)));
	wa = int(floor((number -= floor(number / pow(10, 5)) * pow(10, 5)) / pow(10, 4)));
	qi = int(floor((number -= floor(number / pow(10, 4)) * pow(10, 4)) / pow(10, 3)));
	ba = int(floor((number -= floor(number / pow(10, 3)) * pow(10, 3)) / pow(10, 2)));
	sh = int(floor((number -= floor(number / pow(10, 2)) * pow(10, 2)) / pow(10, 1)));
	yu = int(floor((number -= floor(number / pow(10, 1)) * pow(10, 1)) / pow(10, 0)));
	ji = int(floor((number -= floor(number / pow(10, 0)) * pow(10, 0)) / pow(10, -1)));
	fe = int(floor((number -= floor(number / pow(10, -1)) * pow(10, -1)) / pow(10, -2)));
	//判断是否有整
	if (fe != 0) {
		zh = false;
		febl = true;
	}
	if (ji != 0) {
		jibl = true;
	}
	//判断亿千圆
	if (yi || sy || by) {
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
	cout << "大写结果是:" << endl;

	if (by) {//是否为零
		switch (by) {
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
		cout << "佰";
		zero = false;
		nozero = true;
	}
	else {
		if (nozero && !zero && (sy || yi)) {//之前是否有非零数
			cout << "零";
			zero = true;
		}
	}


	if (sy) {//是否为零
		switch (sy) {
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
		cout << "拾";
		zero = false;
		nozero = true;
	}
	else {
		if (nozero && !zero && (yi)) {//之前是否有非零数
			cout << "零";
			zero = true;
		}
	}


	if (yi) {//是否为零
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
		zero = false;
		nozero = true;
	}


	if (yibl) {
		cout << "亿";
		zero = false;
	}


	if (qw) {//是否为零
		switch (qw) {
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
		cout << "仟";
		zero = false;
		nozero = true;
	}
	else {
		if (nozero && !zero && (bw || sw || wa)) {//之前是否有非零数
			cout << "零";
			zero = true;
		}
	}



	if (bw) {//是否为零
		switch (bw) {
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
		cout << "佰";
		zero = false;
		nozero = true;
	}
	else {
		if (nozero && !zero && (sw || wa)) {//之前是否有非零数
			cout << "零";
			zero = true;
		}
	}



	if (sw) {//是否为零
		switch (sw) {
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
		cout << "拾";
		zero = false;
		nozero = true;
	}
	else {
		if (nozero && !zero && (wa)) {//之前是否有非零数
			cout << "零";
			zero = true;
		}
	}

	if (wa) {//是否为零
		switch (wa) {
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
		zero = false;
		nozero = true;
	}


	if (wabl) {
		cout << "万";
		zero = false;
	}


	if (qi) {//是否为零
		switch (qi) {
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
		cout << "仟";
		zero = false;
		nozero = true;
	}
	else {
		if (nozero && !zero && (ba || sh || yu)) {//之前是否有非零数
			cout << "零";
			zero = true;
		}
	}


	if (ba) {//是否为零
		switch (ba) {
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
		cout << "佰";
		zero = false;
		nozero = true;
	}
	else {
		if (nozero && !zero && (sh || yu)) {//之前是否有非零数
			cout << "零";
			zero = true;
		}
	}


	if (sh) {//是否为零
		switch (sh) {
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
		cout << "拾";
		zero = false;
		nozero = true;
	}
	else {
		if (nozero && !zero && (yu)) {//之前是否有非零数
			cout << "零";
			zero = true;
		}
	}


	if (yu) {//是否为零
		switch (yu) {
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
		zero = false;
		nozero = true;
	}


	if (!nozero && (!jibl && !febl)) {
		cout << "零圆";
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
	else if (febl && nozero) {
		cout << "零";
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