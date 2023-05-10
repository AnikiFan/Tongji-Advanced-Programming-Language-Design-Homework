/* warning, this file is reserved for testing file only*/
/* warning, this file is reserved for testing file only*/
/* warning, this file is reserved for testing file only*/
#include<iostream>
#include<typeinfo>
using namespace std;
int main()
{
	int  a=0,*p=&a;
	int b=0, * q = &b;

	cout << p << endl;
	cout << p + 1 << endl;
	cout << ((p + 1) - p)==(1*sizeof(int)) ;

	return 0;
}