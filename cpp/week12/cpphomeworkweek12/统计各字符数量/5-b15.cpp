/* 2254298 信11 范潇 */
#include<iostream>
#include<conio.h>
using namespace std;
#define line 3
#define max 128
int main()
{
	int i,j;
	char str[ line ][max],input;
	for (j = 0; j < line; j++) {
		cout << "请输入第"<<j+1<<"行" << endl;
		cin.getline(str[j], max);
	}
	for (j = 0; j < 3; j++)
		cout << str[j][0];
	return 0;
}