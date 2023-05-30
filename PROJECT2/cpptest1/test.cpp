/* warning, this file is reserved for testing file only*/
/* warning, this file is reserved for testing file only*/
/* warning, this file is reserved for testing file only*/
#include<iostream>
#include"cmd_console_tools.h"
#include <conio.h>
#include<iomanip>
using namespace std;

int main()
{

	if (0) {
		int X = 0, Y = 0;
		int ret, maction;
		int keycode1, keycode2;
		int loop = 1;

		cct_enable_mouse();

		/* 打印初始光标位置[0,0] */
		//		cout << "[当前鼠标位置] X:0  Y:0"; //打印初始鼠标位置

		while (loop) {
			/* 读鼠标/键盘，返回值为下述操作中的某一种, 当前鼠标位置在<X,Y>处 */
			ret = cct_read_keyboard_and_mouse(X, Y, maction, keycode1, keycode2);

			if (ret == CCT_MOUSE_EVENT) {
				/* 转到第7行进行打印 */
				cct_gotoxy(0, 7);
				cout << "[当前鼠标位置] X:" << setw(2) << X << " Y:" << setw(2) << Y << " 操作:";

				switch (maction) {
					case MOUSE_ONLY_MOVED:
						cout << "移动          " << endl;
						//showch(X, Y, '*');不打印任何内容
						break;
					case MOUSE_LEFT_BUTTON_CLICK:			//按下左键
						cout << "按下左键      " << endl;
						cct_showch(X, Y, '1');			//在鼠标指针位置显示1
						break;
					case MOUSE_LEFT_BUTTON_DOUBLE_CLICK:	//双击左键
						cout << "双击左键      " << endl;
						cct_showch(X, Y, '2');			//在鼠标指针位置显示2
						break;
					case MOUSE_RIGHT_BUTTON_CLICK:			//按下右键
						cout << "按下右键      " << endl;
						cct_showch(X, Y, '3');			//在鼠标指针位置显示3
						break;
					case MOUSE_RIGHT_BUTTON_DOUBLE_CLICK:	//双击右键
						cout << "双击右键      " << endl;
						cct_showch(X, Y, '4');			//在鼠标指针位置显示4
						loop = 0;
						break;
					case MOUSE_LEFTRIGHT_BUTTON_CLICK:		//同时按下左右键
						cout << "同时按下左右键" << endl;
						cct_showch(X, Y, '5');			//在鼠标指针位置显示5
						break;
					case MOUSE_WHEEL_CLICK:
						cout << "按下滚轮      " << endl;
						break;
					case MOUSE_WHEEL_MOVED_UP:
						cout << "滚轮向上移动  " << endl;
						break;
					case MOUSE_WHEEL_MOVED_DOWN:
						cout << "滚轮向下移动  " << endl;
						break;
					case MOUSE_NO_ACTION:
					default:
						cout << "其它操作" << endl;
						cct_showch(X, Y, '0');			//在鼠标指针位置显示0
						break;
				} //end of switch(maction)
			} //end of if (CCT_MOUSE_EVENT)
			else if (ret == CCT_KEYBOARD_EVENT) {
				/* 转到第9行进行打印 */
				cct_gotoxy(0, 9);
				cout << "[当前按键] : ";

				switch (keycode1) {
					case 27:	//ESC键
						loop = 0;
						cout << "ESC       ";
						break;
					case 32:	//SPACE键
						loop = 0;
						cout << "SPACE     ";
						break;
					case 224:
						switch (keycode2) {
							case KB_ARROW_UP:
								cout << "上箭头    ";
								break;
							case KB_ARROW_DOWN:
								cout << "下箭头    ";
								break;
							case KB_ARROW_LEFT:
								cout << "左箭头    ";
								break;
							case KB_ARROW_RIGHT:
								cout << "右箭头    ";
								break;
						}
						break;
					default:	//其他键直接打印ASCII值
						if (keycode2)
							cout << "Keycode=" << keycode1 << '/' << keycode2 << endl;
						else
							cout << "Keycode=" << keycode1 << endl;
						break;
				}//end of swicth(keycode1)
			}//end of else if(ret == CCT_KEYBOARD_EVENT）
		} //end of while(1)

		cct_disable_mouse();	//禁用鼠标
		cct_setcursor(CURSOR_VISIBLE_NORMAL);	//打开光标
	}
	cct_setconsoleborder(20, 20, 20, 20);
	cct_gotoxy(0, 0);
	cout << "00000";
	cct_gotoxy(0, 2);
	cout << "222222";
	cct_gotoxy(0, 1);
	cout << "&&&";
	cct_gotoxy(50, 50);
	cout << "**************";
	cout << endl << "@@";

	return 0;
}