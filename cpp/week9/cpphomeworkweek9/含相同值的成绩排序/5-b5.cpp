/* 2254298 信11 范潇 */
#include<iostream>
using namespace std;
#define max 1000
int main()
{
	int array[max], inverse[max], i, j, temp, t, rank = 0;
	for (i = 0; i < max; i++)
		array[i] = -1;
	cout << "请输入成绩（最多1000个），负数结束输入" << endl;
	for (i = 0; i < max; i++) {
		cin >> temp;
		if (temp >= 0)
			array[i] = temp;
		else
			break;
	}
	if (array[0] == -1)
		cout << "无有效输入" << endl;
	else {
		cout << "输入的数组为:" << endl;
		for (i = 0; i < max; i++) {
			if (array[i] >= 0)
				cout << array[i] << " ";
			if (array[i] >= 0 && !((i + 1) % 10))
				cout << endl;
			else if (array[i] >= 0 && array[i + 1] == -1) {//i不会等于999
				cout << endl;
				break;
			}
		}
		cout << "分数与名次的对应关系为:" << endl;
		for (i = 0; i < max - 1; i++)//冒泡法排序
			for (j = 0; j < max - (i + 1); j++)
				if (array[j] > array[j + 1]) {
					t = array[j];
					array[j] = array[j + 1];
					array[j + 1] = t;
				}
		for (i = 0; i < max; i++)
			inverse[i] = array[max - 1 - i];
	}
	j = -1;
	for (i = 0; i < max - 1; i++) {
		if (inverse[i + 1] < inverse[i]) {
			temp = rank + 1;
			for (t = 0; t < i - j; t++) {

				cout << inverse[i] << " " << temp << endl;
				rank++;
			}
			j = i;

		}
		if (inverse[max - 1] != -1) {
			temp = rank + 1;
			for (t = 0; t < max - 1 - j; t++) 
				cout << inverse[max - 1] << " " << temp << endl;
		}
	}
	return 0;
}