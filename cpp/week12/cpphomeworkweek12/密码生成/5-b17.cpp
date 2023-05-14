/* 2254298 信11 范潇 */
#include<iostream>
#include<time.h>
using namespace std;
#define outputNum 10
static const char other[] = "!@#$%^&*-_=+,.?"; //共 15 个英文符号
int main()
{
	srand((unsigned int)(time(0)));
	int length, uppercaseNum, lowercaseNum, digitNum, otherNum, i, j, uppercaseNumTemp, lowercaseNumTemp, digitNumTemp, otherNumTemp;
	bool errorFlag = false;
	cout << "请输入密码长度(12-16)， 大写字母个数(≥2)， 小写字母个数(≥2)， 数字个数(≥2)， 其它符号个数(≥2)" << endl;
	cin >> length;
	if (!cin.rdstate()) {
		cin >> uppercaseNum;
		if (!cin.rdstate()) {
			cin >> lowercaseNum;
			if (!cin.rdstate()) {
				cin >> digitNum;
				if (!cin.rdstate()) {
					cin >> otherNum;
					if (cin.rdstate()) {
						cout << "输入非法" << endl;
						errorFlag = true;
					}
				}
				else {
					cout << "输入非法" << endl;
					errorFlag = true;
				}
			}
			else {
				cout << "输入非法" << endl;
				errorFlag = true;
			}
		}
		else {
			cout << "输入非法" << endl;
			errorFlag = true;
		}
	}
	else {
		cout << "输入非法" << endl;
		errorFlag = true;
	}
	if (!errorFlag) {
		if (length <= 11 || length >= 17)
			cout << "密码长度[" << length << "]不正确" << endl;
		else if (uppercaseNum <= 1 || uppercaseNum > length)
			cout << "大写字母个数[" << uppercaseNum << "]不正确" << endl;
		else if (lowercaseNum <= 1 || lowercaseNum > length)
			cout << "小写字母个数[" << lowercaseNum << "]不正确" << endl;
		else if (digitNum <= 1 || digitNum > length)
			cout << "数字个数[" << digitNum << "]不正确" << endl;
		else if (otherNum <= 1 || otherNum > length)
			cout << "其他符号个数[" << otherNum << "]不正确" << endl;
		else if (uppercaseNum + lowercaseNum + digitNum + otherNum > length)
			cout << "所有字符类型之和[" << uppercaseNum << "+" << lowercaseNum << "+" << digitNum << "+" << otherNum << "]大于总密码长度[" << length << "]" << endl;
		else {
			cout << length << " " << uppercaseNum << " " << lowercaseNum << " " << digitNum << " " << otherNum << endl;
			for (i = 0; i < outputNum; i++) {
				uppercaseNumTemp = uppercaseNum;
				lowercaseNumTemp = lowercaseNum;
				digitNumTemp = digitNum;
				otherNumTemp = otherNum;
				for (j = 0; j < length; j++) {

					if (uppercaseNumTemp == 0 && lowercaseNumTemp == 0 && digitNumTemp == 0 && otherNumTemp == 0)
						switch (rand() % 4) {
							case 0:
								cout << (char)('A' + rand() % 26);
								break;
							case 1:
								cout << (char)('a' + rand() % 26);
								break;
							case 2:
								cout << (char)('0' + rand() % 10);
								break;
							case 3:
								cout << other[rand() % 15];
								break;
							default:
								break;
						}
					else
						switch (rand() % 4) {
							case 0:
								if (uppercaseNumTemp == 0) {
									j--;
									break;
								}
								cout << (char)('A' + rand() % 26);
								uppercaseNumTemp--;
								break;
							case 1:
								if (lowercaseNumTemp == 0) {
									j--;
									break;
								}
								cout << (char)('a' + rand() % 26);
								lowercaseNumTemp--;
								break;
							case 2:
								if (digitNumTemp == 0) {
									j--;
									break;
								}
								cout << (char)('0' + rand() % 10);
								digitNumTemp--;
								break;
							case 3:
								if (otherNumTemp == 0) {
									j--;
									break;
								}
								cout << other[rand() % 15];
								otherNumTemp--;
								break;
							default:
								break;
						}
				}
				cout << endl;
			}
		}
	}
	return 0;
}