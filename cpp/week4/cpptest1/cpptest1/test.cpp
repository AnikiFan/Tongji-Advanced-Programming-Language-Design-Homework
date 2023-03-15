/* warning, this file is reserved for testing file only*/
/* warning, this file is reserved for testing file only*/
/* warning, this file is reserved for testing file only*/
#include<iostream>
using namespace std;
int main()
{
	double pi=0;
	int index = 1,k;

	while (1)
	{
		pi += ((2.0) * (index % 2) - 1) / (2.0 * index - 1);
		if ((((2.0) * (index % 2) - 1) / (2.0 * index - 1)) < 1.0e-8 && (((2.0) * (index % 2) - 1) / (2.0 * index - 1)>-1.0e-8))
			break;
		index++;
	}
	cout << pi*4 << endl;


	return 0;
}