/* 2254298 信11 范潇 */
#define Bxcoordinate 20
#define Bycoordinate 20
#define Bposition (Bxcoordinate,Bycoordinate)//B盘标识坐标
#define xcoordinatediff 10//A,B,C的x坐标之间的差
#define speed1 250
#define speed2 200
#define speed3 150
#define speed4 100
#define speed5 50
#define endposition (0,27)
#include <iostream>
#include <iomanip>
#include <conio.h>
#include<Windows.h>
#include"5-b7.h"
#define arrow "-->"
using namespace std;
int Atop, Btop, Ctop, Astack[10], Bstack[10], Cstack[10], num = 0, speed, display;//Atop,Btop,Ctop是栈顶+1处位置
void vertical(char src, char dst, int srctop, int dsttop, int moveelement)
{
	cct_gotoxy(Bxcoordinate - ('B' - src) * xcoordinatediff, Bycoordinate - 1 - srctop);
	cout << " ";
	cct_gotoxy(Bxcoordinate - ('B' - dst) * xcoordinatediff, Bycoordinate - 2 - dsttop);
	cout << moveelement;
	return;
}
void horizontal()
{
	int i, tenflag = 0;
	cout << "A:";
	for (i = 0; i < Atop; i++) {
		if (Astack[i] == 10)
			tenflag = 1;
		cout << setw(2) << Astack[i];
	}
	cout << setw(2 * (10 - Atop) + 3);
	tenflag = 0;

	cout << "B:";
	for (i = 0; i < Btop; i++) {
		if (Bstack[i] == 10)
			tenflag = 1;
		cout << setw(2) << Bstack[i];
	}
	cout << setw(2 * (10 - Btop) + 3);

	cout << "C:";
	for (i = 0; i < Ctop; i++) {
		if (Cstack[i] == 10)
			tenflag = 1;
		cout << setw(2) << Cstack[i];
	}
	cout << setw(2 * (10 - Ctop) + 3) << " ";
	cout << endl;
}

void speedcontrol()
{
	switch (speed) {
		case 0:
			while (_getch() != 13)
				;
			break;
		case 1:
			Sleep(speed1);
			break;
		case 2:
			Sleep(speed2);
			break;
		case 3:
			Sleep(speed3);
			break;
		case 4:
			Sleep(speed4);
			break;
		case 5:
			Sleep(speed5);
			break;
	}
	return;
}



void hanoi(int n, char src, char tmp, char dst)
{
	int temp;

	if (n == 1) {
		num++;
		speedcontrol();
		Stack[dst - 'A'][Top[dst - 'A']++] = Stack[src - 'A'][--Top[src - 'A']];

		cct_gotoxy(Bxcoordinate, Bycoordinate + 6);
		cout << "第" << setw(4) << num << " 步" << "(1#: " << src << arrow << dst << ")  ";
		if (display == 1)
			horizontal();


		return;
	}
	hanoi(n - 1, src, dst, tmp);
	num++;
	speedcontrol();
	Stack[dst - 'A'][Top[dst - 'A']++] = Stack[src - 'A'][--Top[src - 'A']];
	cct_gotoxy(Bxcoordinate, Bycoordinate + 6);
	cout << "第" << setw(4) << num << " 步" << "(" << temp << "#: " << src << arrow << dst << ")  ";
	if (display == 1)
		horizontal();

	hanoi(n - 1, tmp, src, dst);
	return;
}
