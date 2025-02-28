/* 2254298 信11 范潇 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdbool.h>
#include<math.h>
#include<string.h>
//可按需增加需要的头文件
const char chnstr[] = "零壹贰叁肆伍陆柒捌玖拾"; /* 所有输出大写 "零" ~ "玖" 的地方，只允许从这个数组中取值 */
char result[256];  /* 除result外，不再允许定义任何形式的全局变量 */

/* --允许添加需要的函数 --*/
void daxie(int num, int flag_of_zero)
{
	switch (num) {
		case 0:
			if (flag_of_zero)
				strncat(result, &chnstr[0], 2);
			break;
		case 1:
			strncat(result, &chnstr[2], 2);
			break;
		case 2:
			strncat(result, &chnstr[4], 2);
			break;
		case 3:
			strncat(result, &chnstr[6], 2);
			break;
		case 4:
			strncat(result, &chnstr[8], 2);
			break;
		case 5:
			strncat(result, &chnstr[10], 2);
			break;
		case 6:
			strncat(result, &chnstr[12], 2);
			break;
		case 7:
			strncat(result, &chnstr[14], 2);
			break;
		case 8:
			strncat(result, &chnstr[16], 2);
			break;
		case 9:
			strncat(result, &chnstr[18], 2);
			break;
	}
	return;
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
	int  sh, ba, qi, wa, sw, bw, qw, yi, sy, by, yu, ji, fe, ret = 0;
	bool zh = true, febl = false, jibl = false, wabl = false, yubl = false, yibl = false;//zh为真时有整,其他位数对应bl值默认为负,即认为该为为0
	bool zero = false, nozero = false;
	char unit[] = "整分角圆拾佰仟万亿";
	printf("请输入[0-100亿)之间的数字:\n");

	while (1) {
		ret = scanf("%lf", &number);

		if ((0.01 <= number && number <= 9999999999.99 || number == 0) && ret == 1)
			break;
		printf("请输入[0-100亿)之间的数字:\n");
		if (ret != 1)
			while (getchar() != '\n')
				;
	}
	number += 0.009;
	by = (int)(floor(number / pow(10, 10)));
	sy = (int)(floor((number -= floor(number / pow(10, 10)) * pow(10, 10)) / pow(10, 9)));
	yi = (int)(floor((number -= floor(number / pow(10, 9)) * pow(10, 9)) / pow(10, 8)));//一个中文字符占2个宽度
	qw = (int)(floor((number -= floor(number / pow(10, 8)) * pow(10, 8)) / pow(10, 7)));
	bw = (int)(floor((number -= floor(number / pow(10, 7)) * pow(10, 7)) / pow(10, 6)));
	sw = (int)(floor((number -= floor(number / pow(10, 6)) * pow(10, 6)) / pow(10, 5)));
	wa = (int)(floor((number -= floor(number / pow(10, 5)) * pow(10, 5)) / pow(10, 4)));
	qi = (int)(floor((number -= floor(number / pow(10, 4)) * pow(10, 4)) / pow(10, 3)));
	ba = (int)(floor((number -= floor(number / pow(10, 3)) * pow(10, 3)) / pow(10, 2)));
	sh = (int)(floor((number -= floor(number / pow(10, 2)) * pow(10, 2)) / pow(10, 1)));
	yu = (int)(floor((number -= floor(number / pow(10, 1)) * pow(10, 1)) / pow(10, 0)));
	ji = (int)(floor((number -= floor(number / pow(10, 0)) * pow(10, 0)) / pow(10, -1)));
	fe = (int)(floor((number -= floor(number / pow(10, -1)) * pow(10, -1)) / pow(10, -2)));
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
	printf("大写结果是:\n");

	daxie(by, nozero && !zero && (sy || yi));
	if (by) {//是否为零
		strncat(result, &unit[10], 2);
		zero = false;
		nozero = true;
	}
	else if (nozero && !zero && (sy || yi))
		zero = true;

	daxie(sy, nozero && !zero && (yi));
	if (sy) {//是否为零
		strncat(result, &unit[8], 2);
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
		strncat(result, &unit[16], 2);
		zero = false;
	}

	daxie(qw, nozero && !zero && (bw || sw || wa));
	if (qw) {//是否为零
		strncat(result, &unit[12], 2);
		zero = false;
		nozero = true;
	}
	else if (nozero && !zero && (bw || sw || wa))
		zero = true;

	daxie(bw, nozero && !zero && (sw || wa));
	if (bw) {//是否为零
		strncat(result, &unit[10], 2);
		zero = false;
		nozero = true;
	}
	else if (nozero && !zero && (sw || wa))
		zero = true;


	daxie(sw, nozero && !zero && (wa));
	if (sw) {//是否为零
		strncat(result, &unit[8], 2);
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
		strncat(result, &unit[14], 2);
		zero = false;
	}

	daxie(qi, nozero && !zero && (ba || sh || yu));
	if (qi) {//是否为零
		strncat(result, &unit[12], 2);
		zero = false;
		nozero = true;
	}
	else if (nozero && !zero && (ba || sh || yu))
		zero = true;



	daxie(ba, nozero && !zero && (sh || yu));
	if (ba) {//是否为零
		strncat(result, &unit[10], 2);
		zero = false;
		nozero = true;
	}
	else if (nozero && !zero && (sh || yu))
		zero = true;


	daxie(sh, nozero && !zero && (yu));
	if (sh) {//是否为零
		strncat(result, &unit[8], 2);
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
		strncat(result, &unit[6], 2);
	}

	if (yibl || wabl || yubl) {
		strncat(result, &unit[6], 2);
	}
	//角和分

	daxie(ji, febl && nozero);
	if (jibl) {
		strncat(result, &unit[4], 2);
	}

	daxie(fe, 0);
	if (febl) {
		strncat(result, &unit[2], 2);
	}
	//整
	if (zh) {
		strncat(result, &unit[0], 2);
	}

	printf("%s\n", result);  /* 转换得到的大写结果，只允许用本语句输出，其它地方不允许以任何形式对大写结果进行全部/部分输出 */
	return 0;
}
