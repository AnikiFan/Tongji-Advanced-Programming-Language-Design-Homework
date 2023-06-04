#include<iostream>
using namespace std;
void subfun(void);
char Global = 1;
static float StaticGlobal = 1.0;
int ExternGlobal = 1;
void fun( int Formal )
{
	int Auto = 1;
	static int  Local = 1;
	Global = 2;
	Formal = 2;
	Auto = 2;
	Local = 2;
	StaticGlobal = 2.0;
}
void Array(long* pLongLong)
{
	const char* p = "test";
	return;
}
void LongLong(long long &a)
{
	return;
}
int main()
{
	int input = 10;
	double Double ,*p=&Double;
	unsigned int UnsignedInt[10] = { 0,1,2,3,4,5,6,7,8,9 },*pUnsignedInt=UnsignedInt ;
	long LongInt[10][10] = { {1,2,3},{4,5,6},{7},{8},{9} };
	long long LongLong = 1;
	fun(10);
	Array(LongInt[0]);
	ExternGlobal = 2;
	Double = 2.0;
	subfun();
	cout << *(pUnsignedInt += 20) << endl;
	return 0;
}