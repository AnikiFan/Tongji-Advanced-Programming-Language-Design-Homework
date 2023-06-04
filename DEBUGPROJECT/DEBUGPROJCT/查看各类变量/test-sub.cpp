#include<iostream>
using namespace std;
static int StaticGlobal = 10;
 extern int ExternGlobal;
void subfun (void)
{
	StaticGlobal = 20;
	ExternGlobal = 20;
	return ;
}