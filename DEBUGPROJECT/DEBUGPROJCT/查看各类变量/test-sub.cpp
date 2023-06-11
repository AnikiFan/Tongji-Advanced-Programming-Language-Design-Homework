#include<iostream>
using namespace std;
static char staticGlobalVariable1[3][5] = { "bar" };
extern  char externGlobalVariable[5];
void fun(char *formalVariable,int * p,int & q)//3.4,3.6
{//2.2,2.3
	cout << &staticGlobalVariable1;
	*(formalVariable += (++*p + ++q));//3.8,3.9
	externGlobalVariable[0] = NULL;//2.4
	return;
}