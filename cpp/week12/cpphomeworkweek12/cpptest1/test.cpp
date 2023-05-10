/* warning, this file is reserved for testing file only*/
/* warning, this file is reserved for testing file only*/
/* warning, this file is reserved for testing file only*/
#include<iostream>
#include<typeinfo>
#include<iomanip>
using namespace std;

int main()
{
	int i = 10, j = 15,*b=&i,*c=&j;
	cout << c - b << endl;
	cout << (int)c - (int)b << endl;
	cout << (int)(c - b) << endl;
}