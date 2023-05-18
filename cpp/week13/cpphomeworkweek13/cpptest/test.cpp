/* 2254298 ĞÅ11 ·¶äì */
#include<iostream>
using namespace std;
int main()
{
	float f = 123.456f;
	unsigned char* p = (unsigned char*)&f;
	cout << *p << endl;
	cout << (int)(*p) << endl;
	return 0;
}