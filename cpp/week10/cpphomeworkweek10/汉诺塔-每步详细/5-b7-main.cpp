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
		switch (src) {
			case('A'):
				if (dst == 'C') {
					vertical(src, dst, Atop, Ctop, Astack[Atop - 1]);
					Cstack[Ctop++] = Astack[--Atop];

				}
				else {
					vertical(src, dst, Atop, Btop, Astack[Atop - 1]);
					Bstack[Btop++] = Astack[--Atop];

				}
				break;
			case('B'):
				if (dst == 'C') {
					vertical(src, dst, Btop, Ctop, Bstack[Btop - 1]);
					Cstack[Ctop++] = Bstack[--Btop];

				}
				else {
					vertical(src, dst, Btop, Atop, Bstack[Btop - 1]);
					Astack[Atop++] = Bstack[--Btop];

				}
				break;
			case('C'):
				if (dst == 'A') {
					vertical(src, dst, Ctop, Atop, Cstack[Ctop - 1]);
					Astack[Atop++] = Cstack[--Ctop];

				}
				else {
					vertical(src, dst, Ctop, Btop, Cstack[Ctop - 1]);
					Bstack[Btop++] = Cstack[--Ctop];

				}
				break;

		}

		cct_gotoxy(Bxcoordinate, Bycoordinate + 6);
		cout << "第" << setw(4) << num << " 步" << "(1#: " << src << arrow << dst << ")  ";
		if (display == 1)
			horizontal();


		return;
	}
	hanoi(n - 1, src, dst, tmp);
	num++;
	speedcontrol();
	switch (src) {
		case('A'):
			if (dst == 'C') {
				vertical(src, dst, Atop, Ctop, Astack[Atop - 1]);
				temp = (Cstack[Ctop++] = Astack[--Atop]);

			}
			else {
				vertical(src, dst, Atop, Btop, Astack[Atop - 1]);
				temp = (Bstack[Btop++] = Astack[--Atop]);

			}
			break;
		case('B'):
			if (dst == 'C') {
				vertical(src, dst, Btop, Ctop, Bstack[Btop - 1]);
				temp = (Cstack[Ctop++] = Bstack[--Btop]);

			}
			else {
				vertical(src, dst, Btop, Atop, Bstack[Btop - 1]);
				temp = (Astack[Atop++] = Bstack[--Btop]);

			}
			break;
		case('C'):
			if (dst == 'A') {
				vertical(src, dst, Ctop, Atop, Cstack[Ctop - 1]);
				temp = (Astack[Atop++] = Cstack[--Ctop]);

			}
			else {
				vertical(src, dst, Ctop, Btop, Cstack[Ctop - 1]);
				temp = (Bstack[Btop++] = Cstack[--Ctop]);

			}
			break;

	}

	cct_gotoxy(Bxcoordinate, Bycoordinate + 6);
	cout << "第" << setw(4) << num << " 步" << "(" << temp << "#: " << src << arrow << dst << ")  ";
	if (display == 1)
		horizontal();

	hanoi(n - 1, tmp, src, dst);
	return;
}


int main()
{
	int n, i;
	char src, tmp, dst;
	cout << "请输入汉诺塔的层数(1-10)" << endl;
	while (1) {
		cin >> n;
		if (n >= 0 && n <= 16 && !cin.rdstate()) {
			cin.clear();
			cin.ignore(10000000, '\n');//删了这个以后会死循环
			break;
		}
		cin.clear();
		cin.ignore(10000000, '\n');//删了这个以后会死循环
		cout << "请输入汉诺塔的层数(1-10)" << endl;
	}
	cout << "请输入起始柱(A-C)" << endl;
	while (1) {
		cin >> src;
		if ((src == 'A' || src == 'B' || src == 'C' || src == 'a' || src == 'b' || src == 'c') && !cin.rdstate()) {
			switch (src) {
				case 'a':
					src = 'A';
					break;
				case 'b':
					src = 'B';
					break;
				case 'c':
					src = 'C';
					break;
			}
			cin.clear();
			cin.ignore(10000000, '\n');//删了这个以后会死循环
			break;
		}
		cin.clear();
		cin.ignore(10000000, '\n');//删了这个以后会死循环
		cout << "请输入起始柱(A-C)" << endl;
	}
	cout << "请输入目标柱(A-C)" << endl;
	while (1) {
		cin >> dst;
		if ((dst == 'A' || dst == 'B' || dst == 'C' || dst == 'a' || dst == 'b' || dst == 'c') && !cin.rdstate()
			&& dst != src && dst != (src - 32) && dst != (src + 32)) {
			cin.clear();
			cin.ignore(10000000, '\n');//删了这个以后会死循环
			break;
		}
		cin.clear();
		cin.ignore(10000000, '\n');//删了这个以后会死循环
		if (dst == src || dst == (src - 32) || dst == (src + 32))
			cout << "目标柱(" << src << ")不能与起始柱(" << src << ")相同" << endl;
		cout << "请输入目标柱(A-C)" << endl;
	}
	switch (dst) {
		case 'a':
			dst = 'A';
			break;
		case 'b':
			dst = 'B';
			break;
		case 'c':
			dst = 'C';
			break;
	}
	tmp = 'A' + 'B' + 'C' - src - dst;
	switch (src) {
		case('A'):
			Atop = n;
			for (i = 0; i < n; i++)
				Astack[i] = n - i;
			break;
		case('B'):
			Btop = n;
			for (i = 0; i < n; i++)
				Bstack[i] = n - i;
			break;
		case('C'):
			Ctop = n;
			for (i = 0; i < n; i++)
				Cstack[i] = n - i;
			break;
	}
	cout << "请输入移动速度(0-5: 0-按回车单步演示 1-延时最长 5-延时最短)" << endl;
	while (1) {
		cin >> speed;
		if (speed >= 0 && speed <= 5 && !cin.rdstate()) {
			cin.clear();
			cin.ignore(10000000, '\n');//删了这个以后会死循环
			break;
		}
		cin.clear();
		cin.ignore(10000000, '\n');//删了这个以后会死循环
		cout << "请输入移动速度(0-5: 0-按回车单步演示 1-延时最长 5-延时最短)" << endl;
	}
	cout << "请输入是否显示内部数组值(0-不显示 1-显示)" << endl;
	while (1) {
		cin >> display;
		if (display >= 0 && display <= 1 && !cin.rdstate()) {
			cin.clear();
			cin.ignore(10000000, '\n');//删了这个以后会死循环
			break;
		}
		cin.clear();
		cin.ignore(10000000, '\n');//删了这个以后会死循环
		cout << "请输入是否显示内部数组值(0-不显示 1-显示)" << endl;
	}
	cct_cls();
	cout << "从 " << src << " 移动到 " << dst << "，共 " << n << " 层，延时设置为 " << speed << ", " << (display ? "" : "不") << "显示内部数组值" << endl;
	if (display == 1) {
		cct_gotoxy(Bxcoordinate, Bycoordinate + 6);
		cout << "初始:" << setw(16) << " ";
		horizontal();
		if (speed == 0) {
			while (_getch() != 13)
				;
			cct_gotoxy(Bxcoordinate - xcoordinatediff - 2, Bycoordinate - 1);
			cout << setfill('=') << setw(6 + 2 * xcoordinatediff) << " ";
			cout << setfill(' ');
			cct_gotoxy Bposition;
			cout << "B";
			cct_gotoxy(Bxcoordinate - xcoordinatediff, Bycoordinate);
			cout << "A";
			cct_gotoxy(Bxcoordinate + xcoordinatediff, Bycoordinate);
			cout << "C";
			for (i = 1; i < n + 1; i++) {
				cct_gotoxy(Bxcoordinate - ('B' - src) * xcoordinatediff, Bycoordinate - 1 - i);
				cout << n + 1 - i;
			}
			hanoi(n, src, tmp, dst);
		}
		else {
			cct_gotoxy(Bxcoordinate - xcoordinatediff - 2, Bycoordinate - 1);
			cout << setfill('=') << setw(6 + 2 * xcoordinatediff) << " ";
			cout << setfill(' ');
			cct_gotoxy Bposition;
			cout << "B";
			cct_gotoxy(Bxcoordinate - xcoordinatediff, Bycoordinate);
			cout << "A";
			cct_gotoxy(Bxcoordinate + xcoordinatediff, Bycoordinate);
			cout << "C";
			for (i = 1; i < n + 1; i++) {
				cct_gotoxy(Bxcoordinate - ('B' - src) * xcoordinatediff, Bycoordinate - 1 - i);
				cout << n + 1 - i;
			}
			hanoi(n, src, tmp, dst);
		}
	}
	else {
		cct_gotoxy(Bxcoordinate - xcoordinatediff - 2, Bycoordinate - 1);
		cout << setfill('=') << setw(6 + 2 * xcoordinatediff) << " ";
		cout << setfill(' ');
		cct_gotoxy Bposition;
		cout << "B";
		cct_gotoxy(Bxcoordinate - xcoordinatediff, Bycoordinate);
		cout << "A";
		cct_gotoxy(Bxcoordinate + xcoordinatediff, Bycoordinate);
		cout << "C";
		for (i = 1; i < n + 1; i++) {
			cct_gotoxy(Bxcoordinate - ('B' - src) * xcoordinatediff, Bycoordinate - 1 - i);
			cout << n + 1 - i;

		}
		hanoi(n, src, tmp, dst);
	}


	cct_gotoxy endposition;
	system("pause");
	return 0;

}