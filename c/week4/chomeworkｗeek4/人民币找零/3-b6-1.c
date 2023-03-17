/* 2254298 信11 范潇 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()//TODO:输出为浮点数的且未指定格式的，均要求 double 型，C++为 cout 缺省输出，C 为%lf 的缺省输出
{
	double num;

	int wsy = 0, esy = 0, sy = 0, wy = 0, yy = 0, wj = 0, yj = 0, wf = 0, ef = 0, yf = 0;//找零的张数
	printf("请输入找零值：\n");//TODO:（中文冒号）
	scanf("%lf", &num);
	num += 0.0001;

	if ((int)(num / 50)) {
		wsy = (int)(num / 50);
		num -= 50 * wsy;
	}
	if ((int)(num / 20)) {
		esy = (int)(num / 20);
		num -= 20 * esy;
	}
	if ((int)(num / 10)) {
		sy = (int)(num / 10);
		num -= 10 * sy;
	}
	if ((int)(num / 5)) {
		wy = (int)(num / 5);
		num -= 5 * wy;
	}
	if ((int)(num / 1)) {
		yy = (int)(num / 1);
		num -= 1 * yy;
	}
	if ((int)(num / 0.5)) {
		wj = (int)(num / 0.5);
		num -= 0.5 * wj;
	}
	if ((int)(num / 0.1)) {
		yj = (int)(num / 0.1);
		num -= 0.1 * yj;
	}
	if ((int)(num / 0.05)) {
		wf = (int)(num / 0.05);
		num -= 0.05 * wf;
	}
	if ((int)(num / 0.02)) {
		ef = (int)(num / 0.02);
		num -= 0.02 * ef;
	}
	if ((int)(num / 0.01)) {
		yf = (int)(num / 0.01);
		num -= 0.01 * yf;
	}
	//
	//输出
	//
	printf("共%d张找零，具体如下：\n",wsy + esy + sy + wy + yy + wj + yj + wf + ef + yf);//TODO:（中文逗号及冒号）
	if (wsy) {
		printf("50元 : %d张\n",wsy );//TODO:每种纸币的币值及数量（英文冒号，前后英文空格，上下对齐，数量为 0 不输出）
	}
	if (esy) {
		printf("20元 : %d张\n",esy );
	}
	if (sy) {
		printf("10元 : %d张\n",sy );
	}
	if (wy) {
		printf("5元  : %d张\n",wy );
	}
	if (yy) {
		printf("1元  : %d张\n",yy );
	}
	if (wj) {
		printf("5角  : %d张\n",wj );
	}
	if (yj) {
		printf("1角  : %d张\n",yj );
	}
	if (wf) {
		printf("5分  : %d张\n",wf );
	}
	if (ef) {
		printf("2分  : %d张\n",ef );
	}
	if (yf) {
		printf("1分  : %d张\n",yf );
	}
	return 0;
}