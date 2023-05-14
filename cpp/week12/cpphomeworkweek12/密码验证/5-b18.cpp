/* 2254298 信11 范潇 */
#include<iostream>
using namespace std;
#define eraseNum 100
#define length comp[0]
#define uppercaseNum comp[1]
#define lowercaseNum comp[2]
#define digitNum comp[3]
#define otherNum comp[4]
#define codeNum 10
#define getInputNum 100
#define validOtherNum 15
static const char other[] = "!@#$%^&*-_=+,.?"; //共 15 个英文符号
int main()
{
	char str[eraseNum],input[getInputNum];
	int i,j,k,l,num[5],comp[5];
	bool validOther = false,valideCode=true;
	cin.getline(str, eraseNum, 10);
	for (i = 0; i < 5; i++)
		cin >> num[i];
	cin.getline(input, getInputNum, 10);;//消除缓存区中的尾零
	for (i = 0; i < codeNum; i++) {
		k = 0;
		for (j = 0; j < 5; j++)
			comp[j] = num[j];

		cin.getline(input, getInputNum, 10);
		while (input[k] != 0) {
			if (k >= length) {
				valideCode = false;
				break;
			}
			else if (input[k] >= 'A' && input[k] <= 'Z')
				uppercaseNum --;
			else if (input[k] >= 'a' && input[k] <= 'z')
				lowercaseNum--;
			else if (input[k] >= '0' && input[k] <= '9')
				digitNum--;
			else {
				for (l = 0; l < validOtherNum; l++)
					if (input[k] == other[l]) {
						otherNum--;
						validOther = true;
						break;
					}
				if (!validOther) 
					break;
			}
			k++;
		}
		if (!(uppercaseNum <= 0 && lowercaseNum <= 0 && digitNum <= 0 && otherNum <= 0)) {
			//
			cout << "*"<<i << endl;
			//
			valideCode = false;
		}
		if (!valideCode)
			break;
	}
	if (valideCode)
		cout << "正确" << endl;
	else
		cout << "错误" << endl;
	return 0;
}