/* 2254298 信11 范潇 */
#include<iostream>
using namespace std;
int is_power(int num, int base)
{
	if (num == 1)
		return 1;
	if (num % base != 0)
		return 0;
	else
		return(is_power(num / base, base));
}
int main()
{
	int base, n, i, input[10000], sum = 0;
	cout << "请输入数据的个数[1..10000]" << endl;
	cin >> n;
	cout << "请输入" << n << "个正整数" << endl;
	for (i = 0; i < n; i++)
		cin >> input[i];
	cout << "请输入基数[2..9]" << endl;
	cin >> base;
	for (i = 0; i < n; i++)
		if (is_power(input[i], base))
			sum++;
	cout << n << "个数中基数" << base << "的幂的个数 : " << sum << endl;
	return 0;
}