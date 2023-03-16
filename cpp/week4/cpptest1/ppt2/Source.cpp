#include <iostream>
using namespace std;
int main()
{
    int score;
    cout << "请输入成绩[0-100]" << endl;
    cin >> score;
    switch (int(score>100)+int(score>=85)+int(score>=70)+int(score>=60)+int(score>=0)) {
    case 4:
        cout << "优" << endl;
        break;
    case 3:
        cout << "良" << endl;
        break;
    case 2:
        cout << "及格" << endl;
        break;
    case 1:
        cout << "不及格" << endl;
        break;
    default:
        cout << "输入错误" << endl;
        break;
    }
    return 0;
}
