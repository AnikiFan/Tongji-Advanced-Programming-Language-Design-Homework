/* 2254298 信11 范潇 */
#include <iostream>
#include <cstdio>
#include <conio.h>
#include <time.h>
#include <windows.h>
using namespace std;

const int MAX_X = 69;	//定义*组成的边框的宽度,中心位置为35
const int MAX_Y = 17;	//定义*组成的边框的高度,中心位置为9

/***************************************************************************
  函数名称：
  功    能：完成与system("cls")一样的功能，但效率高
  输入参数：
  返 回 值：
  说    明：清除整个屏幕缓冲区，不仅仅是可见窗口区域(使用当前颜色)
***************************************************************************/
void cls(const HANDLE hout)
{
	COORD coord = { 0, 0 };
	CONSOLE_SCREEN_BUFFER_INFO binfo; /* to get buffer info */
	DWORD num;

	/* 取当前缓冲区信息 */
	GetConsoleScreenBufferInfo(hout, &binfo);
	/* 填充字符 */
	FillConsoleOutputCharacter(hout, (TCHAR)' ', binfo.dwSize.X * binfo.dwSize.Y, coord, &num);
	/* 填充属性 */
	FillConsoleOutputAttribute(hout, binfo.wAttributes, binfo.dwSize.X * binfo.dwSize.Y, coord, &num);

	/* 光标回到(0,0) */
	SetConsoleCursorPosition(hout, coord);
	return;
}

/***************************************************************************
  函数名称：gotoxy
  功    能：将光标移动到指定位置
  输入参数：HANDLE hout ：输出设备句柄
			int X       ：指定位置的x坐标
			int Y       ：指定位置的y坐标
  返 回 值：无
  说    明：此函数不准修改
***************************************************************************/
void gotoxy(const HANDLE hout, const int X, const int Y)
{
	COORD coord;
	coord.X = X;
	coord.Y = Y;
	SetConsoleCursorPosition(hout, coord);
}

/***************************************************************************
  函数名称：showch
  功    能：在指定位置处打印一个指定的字符
  输入参数：HANDLE hout ：输出设备句柄
			int X       ：指定位置的x坐标
			int Y       ：指定位置的y坐标
			char ch     ：要打印的字符
  返 回 值：无
  说    明：此函数不准修改
***************************************************************************/
void showch(const HANDLE hout, const int X, const int Y, const char ch)
{
	gotoxy(hout, X, Y);
	putchar(ch);
}

/***************************************************************************
  函数名称：init_border
  功    能：显示初始的边框及随机字符
  输入参数：HANDLE hout：输出设备句柄
  返 回 值：无
  说    明：此函数不准修改
***************************************************************************/
void init_border(const HANDLE hout)
{
	gotoxy(hout, 0, 0);	//光标移回左上角(0,0)
	cout << "***********************************************************************" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "***********************************************************************" << endl;

	/* 随机显示20个大写字母，字母的值、XY坐标都随机显示
	   rand()函数的功能：随机生成一个在 0-32767 之间的整数
	   思考：在什么情况下，下面这个循环执行生成后，你看到的实际字母个数不足20个？ */
	   //当两个坐标相同时,后一个字母会覆盖掉前一个,从而不足20个
	int i;
	for (i = 0; i < 20; i++)
		showch(hout, rand() % MAX_X + 1, rand() % MAX_Y + 1, 'A' + rand() % 26);

	return;
}

/* -- 按需增加的若干函数可以放在此处 --*/

int menu(void)
{
	cout << "1.用I、J、K、L键控制上下左右(大小写均可，边界停止)" << endl;
	cout << "2.用I、J、K、L键控制上下左右(大小写均可，边界回绕)" << endl;
	cout << "3.用箭头键控制上下左右，边界停止" << endl;
	cout << "4.用箭头键控制上下左右，边界回绕" << endl;
	cout << "5.用箭头键控制上下左右(边界停止，演示大写HPKM可移动的错误，此项不需要实现)" << endl;
	cout << "6.用箭头键控制上下左右(边界回绕，演示大写HPKM可移动的错误，此项不需要实现)" << endl;
	cout << "0.退出" << endl;
	cout << "[请选择0-6]";
	return _getch();
}

void initialize() {
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE); //取标准输出设备对应的句柄


	/* 此句的作用是调用系统的cls命令清屏 */
	cls(hout);

	/* 显示初始的边框及其中的随机字符 */
	init_border(hout);
	gotoxy(hout, 35, 9);
	return;
}

void quitmodule()//按回车键才会退出
{
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE); //取标准输出设备对应的句柄
	gotoxy(hout, 0, 23);
	cout << "游戏结束，按回车键退出.";
	while (_getch() != 13)
		;
	return;
}

void move(bool alphamove, bool loop)
{
	int input, input2 = 0, x = 35, y = 9;
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE); //取标准输出设备对应的句柄
	while (1) {
		input = _getch();
		if (!alphamove && input == 224)
			input2 = _getch();//当键盘键入箭头键时,会读入两个键码
		if (input == 113 || input == 81)//退出
			break;
		if (input == 32)
			showch(hout, x, y, ' ');//消除
		if ((input == 105 || input == 73) && alphamove || !alphamove && input == 224 && input2 == 72)
			y--;
		if ((input == 107 || input == 75) && alphamove || !alphamove && input == 224 && input2 == 80)
			y++;
		if ((input == 106 || input == 74) && alphamove || !alphamove && input == 224 && input2 == 75)
			x--;
		if ((input == 108 || input == 76) && alphamove || !alphamove && input == 224 && input2 == 77)
			x++;
		if (x == 0)
			gotoxy(hout, x = 1 + loop * 68, y);
		else if (x == 70)
			gotoxy(hout, x = 69 - loop * 68, y);
		else if (y == 0)
			gotoxy(hout, x, y = 1 + 16 * loop);
		else if (y == 18)
			gotoxy(hout, x, y = 17 - 16 * loop);
		else gotoxy(hout, x, y);

	}
	quitmodule();
	return;
}

void module1() {
	initialize();
	move(true, false);
	return;
}

void module2() {
	initialize();
	move(true, true);
	return;
}

void module3() {
	initialize();
	move(false, false);
	return;
}

void module4() {
	initialize();
	move(false, true);
	return;
}

void module5() {
	initialize();
	int input, x = 35, y = 9;
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE); //取标准输出设备对应的句柄
	while (1) {
		input = _getch();
		if (input == 113 || input == 81)//退出
			break;
		if (input == 32)
			showch(hout, x, y, ' ');//消除
		if (input == 224)
			_getch();//清除缓冲区的第二个键符
		if (input == 105 || input == 73)
			y--;
		if (input == 107 || input == 75)
			y++;
		if (input == 106 || input == 74)
			x--;
		if (input == 108 || input == 76)
			x++;
		if (x == 0)
			gotoxy(hout, x = 1, y);
		else if (x == 70)
			gotoxy(hout, x = 69, y);
		else if (y == 0)
			gotoxy(hout, x, y = 1);
		else if (y == 18)
			gotoxy(hout, x, y = 17);
		else gotoxy(hout, x, y);
	}
	quitmodule();
	return;
}

void module6() {
	initialize();
	int input, x = 35, y = 9;
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE); //取标准输出设备对应的句柄
	while (1) {
		input = _getch();
		if (input == 113 || input == 81)//退出
			break;
		if (input == 32)
			showch(hout, x, y, ' ');//消除
		if (input == 224)
			_getch();//清除缓冲区的第二个键符
		if (input == 105 || input == 73)
			y--;
		if (input == 107 || input == 75)
			y++;
		if (input == 106 || input == 74)
			x--;
		if (input == 108 || input == 76)
			x++;
		if (x == 0)
			gotoxy(hout, x = 69, y);
		else if (x == 70)
			gotoxy(hout, x = 1, y);
		else if (y == 0)
			gotoxy(hout, x, y = 17);
		else if (y == 18)
			gotoxy(hout, x, y = 1);
		else gotoxy(hout, x, y);
	}
	quitmodule();
	return;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：main函数仅用于初始演示，可以按题目要求全部推翻重写
***************************************************************************/
int main()
{
	int temp;
	/* 生成伪随机数的种子，只需在程序开始时执行一次即可 */
	srand((unsigned int)(time(0)));
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE); //取标准输出设备对应的句柄
	bool game = true, alphamove = true, loop = false;//默认为用字母控制移动且无回绕




	while (game) {
		cls(hout);
		temp = menu();
		game = temp != 48;
		switch (temp - 48) {
			case 1:
				module1();
				break;
			case 2:
				module2();
				break;
			case 3:
				module3();
				break;
			case 4:
				module4();
				break;
			case 5:
				module5();
				break;
			case 6:
				module6();
				break;
		}
	}
	return 0;
}
/*
1.当按下键盘上的方向键时,会在缓冲区内加入两个键符,对于左箭头键而言,这两个键符的ascill码依次为224,75,
而K的ascill码也为75,由于224,和75并不是q和Q的ascill码,所以游戏场景不会退出,而程序在读取缓冲区中的224后会继续读取75,
从而向下移动.
2.当两个坐标相同时,后一个字母会覆盖掉前一个,从而不足20个
*/
