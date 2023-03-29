#include <iostream>
using namespace std;
int main()
{
    int fun(int x, int y);
    int x = 10, y = 15;
    fun(x, y);
    return 0;
}
void f()
{
    fun(10, 15);
}
int fun(int x, int y)
{
    /* 注意：输出必须改为自己学号-姓名 */
    cout << "2254298-范潇" << endl;
    cout << "x=" << x << endl;
    cout << "y=" << y << endl;
    return 0;
}
