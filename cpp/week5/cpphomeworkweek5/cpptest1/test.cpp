/* 2254298 信11 范潇 */
#include <iostream>
using namespace std;

int main()
{
	int x;

	while (1) {
		cout << "请输入x的值[0-100] : ";
		cin >> x;   //读入x的方式必须是 cin>>int型变量，不允许其他方式
		if (x >= 0 && x <= 100 && !cin.rdstate())
			break;
		else if (cin.rdstate()) {
			cin.clear();//如果在这句后面加cin.sync()的话对于vs而言没区别,但是用dev编译出来的程序当输入为字母时会多要求一次输入
			cin.ignore(10000000, '\n');//删了这个以后会死循环
			cout << "\0x8";
		}
	}

	cout << "cin.good()=" << cin.good() << " x=" << x << endl; //此句不准动，并且要求输出时good为1

	return 0;
}