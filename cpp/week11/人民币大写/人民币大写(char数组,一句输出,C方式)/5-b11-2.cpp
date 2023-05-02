/* 2254298 信11 范潇 */
#include <iostream>
#include <string>
#include<math.h>
#include<iomanip>
//可按需增加需要的头文件
using namespace std;

const char chnstr[] = "零壹贰叁肆伍陆柒捌玖"; /* 所有输出大写 "零" ~ "玖" 的地方，只允许从这个数组中取值 */
string result;  /* 除result外，不再允许定义任何形式的全局变量 */

/* --允许添加需要的函数 --*/
void daxie(int num, int flag_of_zero)
{
	/* 不允许对本函数做任何修改 */
	switch (num) {
		case 0:
			if (flag_of_zero) {
				result += chnstr[0];
				result += chnstr[1];
			}
			break;
		case 1:
			result += chnstr[2];
			result += chnstr[3];
			break;
		case 2:
			result += chnstr[4];
			result += chnstr[5];
			break;
		case 3:
			result += chnstr[6];
			result += chnstr[7];
			break;
		case 4:
			result += chnstr[8];
			result += chnstr[9];
			break;
		case 5:
			result += chnstr[10];
			result += chnstr[11];
			break;
		case 6:
			result += chnstr[12];
			result += chnstr[13];
			break;
		case 7:
			result += chnstr[14];
			result += chnstr[15];
			break;
		case 8:
			result += chnstr[16];
			result += chnstr[17];
			break;
		case 9:
			result += chnstr[18];
			result += chnstr[19];
			break;
	}
}
/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int main()
{
	/* --允许添加需要的内容 --*/
	double number;
	int  sh, ba, qi, wa, sw, bw, qw, yi, sy, by, yu, ji, fe;
	bool zh = true, febl = false, jibl = false, wabl = false, yubl = false, yibl = false;//zh为真时有整,其他位数对应bl值默认为负,即认为该为为0
	bool zero = false, nozero = false;
	cout << setiosflags(ios::left);
	cout << "请输入[0-100亿)之间的数字:" << endl;
	while (1) {
		cin >> number;
		if ((0.01 <= number && number <= 9999999999.99 || number == 0) && !cin.rdstate())
			break;
		else {
			cin.clear();
			cin.ignore(10000000, '\n');//删了这个以后会死循环
		}
		cout << "请输入[0 - 100亿)之间的数字:" << endl;
	}
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
		result += "佰";
		zero = false;
		nozero = true;
	}
	else if (nozero && !zero && (sy || yi))
		zero = true;

	daxie(sy, nozero && !zero && (yi));
	if (sy) {//是否为零
		result += "拾";
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
		result += "亿";
		zero = false;
	}

	daxie(qw, nozero && !zero && (bw || sw || wa));
	if (qw) {//是否为零
		result += "仟";
		zero = false;
		nozero = true;
	}
	else if (nozero && !zero && (bw || sw || wa))
		zero = true;

	daxie(bw, nozero && !zero && (sw || wa));
	if (bw) {//是否为零
		result += "佰";
		zero = false;
		nozero = true;
	}
	else if (nozero && !zero && (sw || wa))
		zero = true;


	daxie(sw, nozero && !zero && (wa));
	if (sw) {//是否为零
		result += "拾";
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
		result += "万";
		zero = false;
	}

	daxie(qi, nozero && !zero && (ba || sh || yu));
	if (qi) {//是否为零
		result += "仟";
		zero = false;
		nozero = true;
	}
	else if (nozero && !zero && (ba || sh || yu))
		zero = true;



	daxie(ba, nozero && !zero && (sh || yu));
	if (ba) {//是否为零
		result += "佰";
		zero = false;
		nozero = true;
	}
	else if (nozero && !zero && (sh || yu))
		zero = true;


	daxie(sh, nozero && !zero && (yu));
	if (sh) {//是否为零
		result += "拾";
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
		result += "圆";
	}

	if (yibl || wabl || yubl) {
		result += "圆";
	}
	//角和分

	daxie(ji, febl && nozero);
	if (jibl) {
		result += "角";
	}

	daxie(fe, 0);
	if (febl) {
		result += "分";
	}
	//整
	if (zh) {
		result += "整";
	}

	cout << result << endl;  /* 转换得到的大写结果，只允许用本语句输出，其它地方不允许以任何形式对大写结果进行全部/部分输出 */
	return 0;
}