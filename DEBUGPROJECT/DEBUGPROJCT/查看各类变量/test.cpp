#include<iostream>
using namespace std;
void fun(char* formalVariable, int* p, int& q);
char externGlobalVariable[5] = "test";//3.3,3.7
static char staticGlobalVariable1[3][5] = { "foo" };//3.5
int main()
{
	int simpleVariable = 12, * pSimplevariable = &simpleVariable;//2.1,3.1,3.2
	char staticLocalVariable[][5] = { "one","two" };//2.2
	char localVariable[3][5] = { "foo" };
	fun(externGlobalVariable,pSimplevariable,simpleVariable);
	return 0;
}