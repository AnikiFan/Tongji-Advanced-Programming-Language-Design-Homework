#include <iostream>
#include <iomanip>
using namespace std;
int compare(int a, int b, int c)
{
	if (a < b)
		a = b;
	if (a < c)
		a = c;
	return a;

}
int main()
{
	cout << compare(1, 2, 3) << endl;
	cout << compare(2, 2, 3) << endl;
	cout << compare(3, 2, 1) << endl;
	cout << compare(2, 1, 3) << endl;
	return 0;
}
