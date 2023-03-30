/* 2254298 信11 范潇 */
#include<iostream>//
#include<math.h>//单位为亿,(仟佰拾)万,(仟佰拾)圆,角,分/整
#include<iomanip>
using namespace std;
void daxie(int num, int flag_of_zero)
{
	/* 不允许对本函数做任何修改 */
	switch (num) {
		case 0:
			if (flag_of_zero)	//此标记什么意思请自行思考
				cout << "零";
			break;
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
		default:
			cout << "error";
			break;
	}
}
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

	daxie(by, nozero && !zero && (sy || yi));
	if (by) {//是否为零
		cout << "佰";
		zero = false;
		nozero = true;
	}
	else if (nozero && !zero && (sy || yi))
		zero = true;

	daxie(sy, nozero && !zero && (yi));
	if (sy) {//是否为零
		cout << "拾";
		zero = false;
		nozero = true;
	}
	else if (nozero && !zero && (yi))
		zero = true;

	daxie(yi, 0);
	if (yi) {//是否为零
		zero = false;
		nozero = true;
	}


	if (yibl) {
		cout << "亿";
		zero = false;
	}

	daxie(qw, nozero && !zero && (bw || sw || wa));
	if (qw) {//是否为零
		cout << "仟";
		zero = false;
		nozero = true;
	}
	else if (nozero && !zero && (bw || sw || wa))
		zero = true;

	daxie(bw, nozero && !zero && (sw || wa));
	if (bw) {//是否为零
		cout << "佰";
		zero = false;
		nozero = true;
	}
	else if (nozero && !zero && (sw || wa))
		zero = true;


	daxie(sw, nozero && !zero && (wa));
	if (sw) {//是否为零
		cout << "拾";
		zero = false;
		nozero = true;
	}
	else if (nozero && !zero && (wa))
		zero = true;


	daxie(wa, 0);
	if (wa) {//是否为零
		zero = false;
		nozero = true;
	}


	if (wabl) {
		cout << "万";
		zero = false;
	}

	daxie(qi, nozero && !zero && (ba || sh || yu));
	if (qi) {//是否为零
		cout << "仟";
		zero = false;
		nozero = true;
	}
	else if (nozero && !zero && (ba || sh || yu))
		zero = true;



	daxie(ba, nozero && !zero && (sh || yu));
	if (ba) {//是否为零
		cout << "佰";
		zero = false;
		nozero = true;
	}
	else if (nozero && !zero && (sh || yu))
		zero = true;


	daxie(sh, nozero && !zero && (yu));
	if (sh) {//是否为零
		cout << "拾";
		zero = false;
		nozero = true;
	}
	else if (nozero && !zero && (yu))
		zero = true;



	daxie(yu, 0);
	if (yu) {//是否为零
		zero = false;
		nozero = true;
	}

	if (!nozero && (!jibl && !febl)) {
		daxie(0, 1);
		cout << "圆";
	}

	if (yibl || wabl || yubl) {
		cout << "圆";
	}
	//角和分

	daxie(ji, febl && nozero);
	if (jibl) {
		cout << "角";
	}

	daxie(fe, 0);
	if (febl) {
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