/* 2254298 ĞÅ11 ·¶äì */
#include<iostream>
using namespace std;
#define eraseNum 100
#define length comp[0]
#define uppercaseNum comp[1]
#define lowercaseNum comp[2]
#define digitNum comp[3]
#define otherNum comp[4]
#define codeNum 10
#define getInputNum 30
int main()
{
	char str[eraseNum],input[getInputNum];
	int i,j,k,num[5],comp[5];
	cin.getline(str, eraseNum, '\n');
	for (i = 0; i < 5; i++)
		cin >> num[i];
	for (i = 0; i < codeNum; i++) {
		k = 0;
		for (j = 0; j < 5; j++)
			comp[j] = num[j];
		cin.getline(input, getInputNum, '/n');
		while (input[k] != 0) {
			if (input[k] >= 'A' && input[k] <= 'Z')
				uppercaseNum --;
			if (input[k] >= 'a' && input[k] <= 'z')
				lowercaseNum--;
			if (input[k] >= '0' && input[k] <= '9')
				digitNum--;
			if
		}

	}

	return 0;
}