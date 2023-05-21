/* 2254298 信11 范潇 */
#include <iostream>
using namespace std;

#define  N  10	/* 假设最多转换10个数字 */

/* 不允许再定义其它函数、全局变量 */

int main()
{
	/* 如果有不需要的变量，允许删除，但不允许添加或替换为其它类型的变量 */
	char str[256], * p;
	int  a[N] = { 0 }, * pnum, * pa;
	bool is_num;

	/* 上面的定义不准动(删除不需要的变量除外)，下面为程序的具体实现，要求不得再定义任何变量、常量、常变量 */
	cout << "请输入间隔含有若干正负数字的字符串" << endl;
	gets_s(str);
	p = str;
	pa = a;
	is_num = false;
	while (*p != '\0') {
		if (*p >= '0' && *p <= '9') {
			if (is_num == false) {
				if (pa - a == 9)
					break;
				if (*a != 0)
					pa++;
			}
				*pa *= 10;
				*pa += *p - '0';
			is_num = true;
		}
		else if (is_num == true)
			is_num = false;
		p++;
	}
	cout << "共有" << (pa - a + 1)*(*pa!=0) << "个整数" << endl;
	pnum = a;
	if (*pa != 0) {
		while (pnum <= pa) {
			cout << *pnum << " ";
			pnum++;
		}
	}
	cout << endl;

	return 0;
}
