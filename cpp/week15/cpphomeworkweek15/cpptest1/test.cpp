/* warning, this file is reserved for testing file only*/
/* warning, this file is reserved for testing file only*/
/* warning, this file is reserved for testing file only*/
#include<iostream>
using namespace std;
int main()
{
	class Time {
	private:
		int hour;
		int minute;
		int sec;
	public:
		Time(int h = 0, int m = 0, int s = 0)
		{
			hour = h;
			minute = m;
			sec = s;
		}
		void display()
		{
			cout << hour << ':' << minute << ';' << sec << endl;
		}
	};
	Time t[10] = { (1,2,3),(4,5),6,7,8,9,10 };
	for (int i = 0; i < 10; i++)
		t[i].display();
	return 0;
}