/* 2254298 信11 范潇 */
#include <iostream>
#include <iomanip>
#define arrow "-->"
using namespace std;
int top[3]={0}, int plate[3][10]={0}, count;


void hanoi(int n, char src, char tmp, char dst)
{
	cout << setw(21) << "起始:";
	if (n == 1) {
		cout << " 1# " << src << arrow << dst << endl;
		return;
	}
	hanoi(n - 1, src, dst, tmp);
	cout << setw(2) << n << "# " << src << arrow << dst << endl;
	hanoi(n - 1, tmp, src, dst);
	return;
}


int main()
{
	int n,i;
	char src, tmp, dst;
	cout << "请输入汉诺塔的层数(1-16)" << endl;
	while (1) {
		cin >> n;
		if (n >= 0 && n <= 16 && !cin.rdstate()) {
			cin.clear();
			cin.ignore(10000000, '\n');//删了这个以后会死循环
			break;
		}
		cin.clear();
		cin.ignore(10000000, '\n');//删了这个以后会死循环
		cout << "请输入汉诺塔的层数(1-16)" << endl;
	}
	cout << "请输入起始柱(A-C)" << endl;
	while (1) {
		cin >> src;
		if ((src == 'A' || src == 'B' || src == 'C' || src == 'a' || src == 'b' || src == 'c') && !cin.rdstate()) {
			switch (src) {
				case 'a':
					src = 'A';
					break;
				case 'b':
					src = 'B';
					break;
				case 'c':
					src = 'C';
					break;
			}
			cin.clear();
			cin.ignore(10000000, '\n');//删了这个以后会死循环
			break;
		}
		cin.clear();
		cin.ignore(10000000, '\n');//删了这个以后会死循环
		cout << "请输入起始柱(A-C)" << endl;
	}
	cout << "请输入目标柱(A-C)" << endl;
	while (1) {
		cin >> dst;
		if ((dst == 'A' || dst == 'B' || dst == 'C' || dst == 'a' || dst == 'b' || dst == 'c') && !cin.rdstate()
			&& dst != src && dst != (src - 32) && dst != (src + 32)) {
			cin.clear();
			cin.ignore(10000000, '\n');//删了这个以后会死循环
			break;
		}
		cin.clear();
		cin.ignore(10000000, '\n');//删了这个以后会死循环
		if (dst == src || dst == (src - 32) || dst == (src + 32))
			cout << "目标柱(" << src << ")不能与起始柱(" << src << ")相同" << endl;
		cout << "请输入目标柱(A-C)" << endl;
	}
	switch (dst) {
		case 'a':
			dst = 'A';
			break;
		case 'b':
			dst = 'B';
			break;
		case 'c':
			dst = 'C';
			break;
	}
	cout << "移动步骤为:" << endl;
	tmp = int(src != 'A') * int(dst != 'A') * 'A' + int(src != 'B') * int(dst != 'B') * 'B' + int(src != 'C') * int(dst != 'C') * 'C';
	switch (src) {
		case('A'):
			top[0] = n;
			for (i = 0; i < n - 1; i++)
				plate[0][i] = n - i;
			break;
		case('B'):
			top[1] = n;
			for (i = 0; i < n - 1; i++)
				plate[1][i] = n - i;
			break;
		case('C'):
			top[1] = n;
			for (i = 0; i < n - 1; i++)
				plate[2][i] = n - i;
			break;
	}
	hanoi(n, src, tmp, dst);
	return 0;
}