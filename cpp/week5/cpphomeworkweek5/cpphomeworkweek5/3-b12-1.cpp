/* 2254298 信11 范潇 */
#include <iostream>
using namespace std;

int main()
{
	int x,state;

	while (1) {
		cout << "请输入x的值[0-100] : ";
		cin >> x;   //读入x的方式必须是 cin>>int型变量，不允许其他方式
		state=cin.rdstate();
		if (x >= 0 && x <= 100&& !state)
			break;
		else if (state) {
			cin.clear(0);	
			cin.sync();
			cin.ignore(10000000,'\n');//删了这个以后会死循环
		}
	}

	cout << "cin.good()=" << cin.good() << " x=" << x << endl; //此句不准动，并且要求输出时good为1

	return 0;
}