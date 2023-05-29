/* warning, this file is reserved for testing file only*/
/* warning, this file is reserved for testing file only*/
/* warning, this file is reserved for testing file only*/
#include<iostream>
using namespace std;
int main()
{
	struct stduent {
		int a, b, c;
	};
	struct stduent s2 = {1,2,3};
	struct student s1[10] = {1,2,3};

	


	cout << s2.a << endl;
	cout << s2.b << endl;
	cout << s2.c << endl;


	return 0;
}