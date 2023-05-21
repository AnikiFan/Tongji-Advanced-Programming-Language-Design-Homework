/* 2254298 信11 范潇 */
#include<iostream>
using namespace std;
#define max 82
int isValid(char *backward)
{
	char* forward=backward;
	if (*backward == '\n')
		return 1;
	while (*backward != '\n')
		backward++;
	backward--;
	while (*forward != '\n') {
		if (*forward != *backward)
			return 0;
		forward++;
		backward--;
	}
	return 1;
}
int main()
{
	char str[max];
	cout << "请输入一个长度小于80的字符串（回文串）" << endl;
	fgets(str,max,stdin);
	cout << (isValid(str) ? "yes": "no" )<< endl;
	return 0;
}