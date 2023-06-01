/* 2254298 信11 范潇 */
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<iomanip>
#include<conio.h>
using namespace std;
#define codeLength 3
#define seperateLength 3
#define infoLength 40
#define priceLength 10
#define columnWidth (infoLength+priceLength+codeLength)
#define boardWidth (2*columnWidth+seperateLength)
#define boardTitle "东急带学 2023春季菜单"
#define titleLength 21
#define maxNum 26
#define itemNum 20
#define discountNum 7
#define screenWidth boardWidth
#define screenHeight (itemNum/2+discountNum+30)
#define showcaseNum 2
#define maxOrderNum 1000000
int main()
{
	struct ITEM {
		char name[infoLength];
		double price;
		int count = 0;
	};
	struct DISCOUNT {
		int totalNum;//优惠涉及单品种类数量
		int eachNum[maxNum];//各个单品涉及的数量
		int eachCode[maxNum];//各个单品对应的代码
		double discount;//单个组合总金额
		char name[infoLength];
		int eachcount[maxNum] = { 0 };//各个单品满足的最大优惠个数
	};
	struct {
		int totalNum;//涉及单品种类数量
		int eachCode[maxNum];//各个单品总数
		int eachNum[maxNum];
		int showcase[50];
	}showcase[showcaseNum] = {
		{3,{7,8,9},{1,1,1},{8,9,7}},
		{2,{3,4},{3,4},{3,4,3,4,3,4,4}}
	};
	int i, j, k;
	double sum;
	bool valid;
	char command[100];
	sprintf(command, "mode con cols=%d lines=%d", screenWidth, screenHeight);
	system(command);
	system("cls");
	while (1) {
		ITEM item[maxNum] = {
		{"四喜烤麸",6},
		{"花椰菜",5},
		{"红糖馒头",4},
		{"猪肉刺身",7},
		{"焗蜗牛",2},
		//5
		{"咖喱饭",1},
		{"意大利面",1},
		{"鸭蛋",4},
		{"牡蛎",5},
		{"红茶",1},
		{"布丁",4},
		{"迎宾酒",1919.810},
		//7
		{"双吉芝士汉堡",10.5},
		{"柠檬红茶",6},
		//2
		{"培根双层安格斯厚牛堡",45},
		{"特浓抹茶雪冰",23.5},
		//2
		{"肉肉烤蘑菇披萨",33},
		{"日落梅梅茶",15},
		{"奶香菌菇脆塔",22.5},
		{"可口可乐",15}
		//4
		};
		DISCOUNT discount[maxNum] = {
		{5,{1,1,1,1,1},{0,1,2,3,4},1,"隔离餐"},
		{5,{1,1,1,1,1},{5,6,9,10,11},1145.14,"会员制套餐"},
		{1,{2},{7},5,"鸭蛋莫鸭蛋"},
		{1,{2},{8},6,"牡蛎莫牡蛎"},
		{2,{1,1},{12,13},13.9,"穷鬼套餐"},
		{2,{1,1},{14,15},50,"富哥套餐"},
		{4,{1,1,1,1},{16,17,18,19},66,"Genshin联动套餐"}
		};
		char order[maxOrderNum] = { 0 }, * p = order;
		int temp = 0;
		double tempdiscount = 0;
		cout << setw(boardWidth) << setfill('=') << " " << setfill(' ');
		cout << setw(columnWidth + titleLength / 2 + 2) << boardTitle << endl;
		cout << setw(boardWidth) << setfill('=') << " " << setfill(' ');
		for (i = 0; i < itemNum; i++) {
			cout << setw(codeLength - 1) << (char)('A' + i) << " " << setw(infoLength) << setiosflags(ios::left) << item[i].name << resetiosflags(ios::left)
				<< setw(priceLength) << setiosflags(ios::left) << item[i].price << resetiosflags(ios::left);
			if (i % 2 == 0)
				cout << setw(seperateLength - 1) << "|";
			if (i % 2 == 1)
				cout << endl;
		}
		cout << endl;
		cout << "[优惠信息] :" << endl;
		for (i = 0; i < discountNum; i++) {
			cout << discount[i].name << "=";
			for (j = 0; j < discount[i].totalNum; j++) {
				cout << item[discount[i].eachCode[j]].name;
				if (discount[i].eachNum[j] != 1)
					cout << "*" << discount[i].eachNum[j];
				if (j != discount[i].totalNum - 1)
					cout << "+";
			}
			cout << "=" << discount[i].discount << endl;
		}
		cout << endl;
		cout << "[输入规则说明] : " << endl;
		for (i = 0; i < showcaseNum; i++) {
			sum = 0;
			if (i % 2 == 0) {
				for (j = 0; j < showcase[i].totalNum; j++)
					sum += showcase[i].eachNum[j];
				for (j = 0; j < sum; j++)
					cout << (char)('A' + showcase[i].showcase[j]);
			}
			else {
				for (j = 0; j < showcase[i].totalNum; j++)
					sum += showcase[i].eachNum[j];
				for (j = 0; j < sum; j++)
					cout << (char)('a' + showcase[i].showcase[j]);
			}
			cout << "=";
			for (j = 0; j < showcase[i].totalNum; j++) {
				cout << item[showcase[i].eachCode[j]].name;
				if (showcase[i].eachNum[j] != 1)
					cout << "*" << showcase[i].eachNum[j];
				if (j != showcase[i].totalNum - 1)
					cout << "+";
			}
			if (i != showcaseNum - 1 && i % 2 == 0)
				cout << " / ";
			else if (i != showcaseNum - 1 && i % 2 == 1)
				cout << endl;
		}
		cout << endl;
		cout << "字母不分大小写,不限顺序,单独输入0则退出程序" << endl << endl << "请点单:";
		cin.getline(order, maxOrderNum);
		if (order[0] == '0' && order[1] == '\0') {
			cout << endl;
			return 0;
		}
		valid = true;
		while (*p != '\0') {
			if (*p > 'a' + itemNum - 1 || (*p < 'a' && *p>'A' + itemNum - 1) || *p < 'A') {
				cout << "输入错误,按任意键继续" << endl;
				_getch();
				valid = false;
				break;
			}
			if (*p >= 'A' && *p <= 'A' + itemNum - 1) {
				*p -= 'A' - 'a';//全部转换为小写
				item[*p - 'a'].count++;
				p++;
			}
			else {
				item[*p - 'a'].count++;
				p++;
			}

		}
		if (valid) {
			sum = 0;
			cout << "您的点单=";
			for (i = 0; i < itemNum; i++) {
				if (item[i].count == 1)
					cout << item[i].name << "+";
				else if (item[i].count > 1)
					cout << item[i].name << "*" << item[i].count << "+";
				if (item[i].count != 0)
					sum += item[i].count * item[i].price;
			}
			for (j = 0; j < discountNum; j++) {
				temp = 0;
				tempdiscount = 0;
				for (k = 0; k < discount[j].totalNum; k++)
					discount[j].eachcount[k] = item[discount[j].eachCode[k]].count / discount[j].eachNum[k];
				for (k = 0; k < discount[j].totalNum; k++) {
					temp = discount[j].eachcount[0];
					if (discount[j].eachcount[k] < temp)
						temp = discount[j].eachcount[k];
				}
				for (k = 0; k < discount[j].totalNum; k++)
					tempdiscount += discount[j].eachNum[k] * item[discount[j].eachCode[k]].price;
				tempdiscount = tempdiscount - discount[j].discount;//单次优惠金额
				sum -= tempdiscount * temp;
			}
			cout << '\b' << " ";
			cout << endl;
			cout << "共计: " << sum << "元" << endl;
			cout << "点单完成,按任意键继续" << endl;
			_getch();
		}
		system("cls");
	}
	return 0;
}