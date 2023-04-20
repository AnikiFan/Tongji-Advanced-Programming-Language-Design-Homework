/* 2254298 信11 范潇 */
#include<iostream>
using namespace std;
int main()
{

	int array[21] = { 0 }, i, j, temp, t, s;
	cout << "请输入任意个正整数（升序，最多20个），0或负数结束输入" << endl;
	for (i = 0; i < 21; i++) {
		cin >> temp;
		if (temp > 0) {
			array[i] = temp;
		}
		else
			break;
		if (array[20] != 0) {
			cin.clear();
			cin.ignore(10000000, '\n');//删了这个以后会死循环
		}
	}
	if (array[0] == 0)
		cout << "无有效输入" << endl;
	else {
		cout << "原数组为：" << endl;
		for (i = 0; i < 20; i++)
			if (array[i] != 0)
				cout << array[i] << " ";
		cout << endl;
		cout << "请输入要插入的正整数" << endl;//这里没有对于输入不为正数的情况进行处理,所以如果输入非正数的话输出会不正确
		cin >> temp;
		for (i = 0; i < 20; i++)
			if (array[i] <= temp && temp < array[i + 1])
				break;
		if (i == 20)
			array[20] = temp;
		else {
			t = array[i + 1];
			array[i + 1] = temp;
			for (j = i + 1; j < 20; j++) {
				s = array[j + 1];
				array[j + 1] = t;
				t = s;

			}
		}
		cout << "插入后的数组为：" << endl;
		for (i = 0; i < 21; i++)
			if (array[i] != 0)
				cout << array[i] << " ";
		cout << endl;
	}

	return 0;
}