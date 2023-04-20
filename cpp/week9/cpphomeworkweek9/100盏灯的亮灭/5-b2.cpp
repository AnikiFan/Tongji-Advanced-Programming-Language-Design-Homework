/* 2254298 信11 范潇 */
#include<iostream>
using namespace std;
#define max 100
int main()
{
	int array[max] = { 0 },i,j;
	for (i = 0; i < max-1; i++) //最后一个单独处理
		for (j = i + 1; j < max; j += i+1)
			array[j-1] = !array[j-1];
	array[max-1] = !array[max-1];
	for (i = 0; i < max; i++) {
		if (array[i] == 1) {
			cout << i + 1;
			j = i + 1;
			while (j < 100) {
				if (array[j] == 1) {
					cout << " ";
					break;
				}
				j++;
			}
		}
	}
	cout << endl;
	return 0;
}