/* warning, this file is reserved for testing file only*/
/* warning, this file is reserved for testing file only*/
/* warning, this file is reserved for testing file only*/
#include<iostream>
using namespace std;
Top[3], Stack[3][10];
void hanoi(int n, char src, char tmp, char dst)
{
	if (n == 1) {
		Stack[dst - 'A'][Top[dst - 'A']++] = Stack[src - 'A'][--Top[src - 'A']];
		//	num++;
		//	cout << "第" << setw(4) << num << " 步" << "(1#: " << src << arrow << dst << ")  ";
		return;
	}
	hanoi(n - 1, src, dst, tmp);

	Stack[dst - 'A'][Top[dst - 'A']++] = Stack[src - 'A'][--Top[src - 'A']];
	//num++;
	//cout << "第" << setw(4) << num << " 步" << "(" << temp << "#: " << src << arrow << dst << ")  ";
	hanoi(n - 1, tmp, src, dst);
	return;
}
int main()
{

	return 0;
}