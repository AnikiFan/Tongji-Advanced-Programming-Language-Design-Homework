/* 2254298 信11 范潇 */
#include"popstar.h"
void blockGenrator(int x, int y, int colorCode)
{//xy是星星的坐标
	int color[10][2] = colorBoard, i, j;
	cct_gotoxy(x - 2, y - 1);
	cct_setcolor(color[colorCode][0], color[colorCode][1]);
	for (i = 0; i < blockheight; i++) {
		for (j = 0; j < blockwidth; j++) {
			cout << " ";
			delay;
		}
		cct_gotoxy(x - 2, y + i);
	}

	cct_gotoxy(x - 2, y - 1);
	cct_setcolor(color[colorCode][0], 0);
	cct_getxy(x, y);
	delay;
	cout << "╔═╗" << endl;
	cct_gotoxy(x, y + 1);
	delay;
	cout << "║  ║" << endl;
	cct_gotoxy(x, y + 2);
	delay;
	cout << "╚═╝" << endl;
	cct_gotoxy(x + 2, y + 1);
	cct_setcolor(color[colorCode][0], 0);
	delay;
	cout << "★";
}
void inverseBlock(int x, int y, int colorCode)
{
	int color[10][2] = colorBoard;
	cct_setcolor(color[colorCode][0], 15);
	cct_gotoxy(x - 2, y - 1);
	cct_getxy(x, y);
	cout << "╔═╗" << endl;
	cct_gotoxy(x, y + 1);
	cout << "║  ║" << endl;
	cct_gotoxy(x, y + 2);
	cout << "╚═╝" << endl;
	cct_gotoxy(x + 2, y + 1);
	cout << "★";
	cct_setcolor(defaultColor);
	return;
}
void reverseBlock(int x, int y, int colorCode)
{
	int color[10][2] = colorBoard;
	cct_setcolor(color[colorCode][0], 0);
	cct_gotoxy(x - 2, y - 1);
	cct_getxy(x, y);
	cout << "╔═╗" << endl;
	cct_gotoxy(x, y + 1);
	cout << "║  ║" << endl;
	cct_gotoxy(x, y + 2);
	cout << "╚═╝" << endl;
	cct_gotoxy(x + 2, y + 1);
	cout << "★";
	cct_setcolor(defaultColor);
	return;
}
void matrixInitialize(int maxRow, int maxCol, bool frame, int matrix[][10])
{
	int i, j;
	cct_setconsoleborder(55 + (maxCol - 8) * 6 + frame * 14 + frame * 2 * (maxCol - 8), 32 + (maxRow - 8) * 3 + frame * 7 + frame * (maxRow - 8), 55 + (maxCol - 8) * 6 + frame * 14 + frame * 2 * (maxCol - 8), 32 + (maxRow - 8) * 3 + frame * 7 + frame * (maxRow - 8));
	cout << "屏幕当前设置为: " << 32 + (maxRow - 8) * 3 + frame * 7 + frame * (maxRow - 8) << "行" << 55 + (maxCol - 8) * 6 + frame * 14 + frame * 2 * (maxCol - 8) << "列" << endl;
	for (i = 0; i < maxCol; i++) {
		delay;
		cct_showint(6 + i * (6 + 2 * frame), 1, i, defaultColor, 1);
	}
	for (i = 0; i < maxRow; i++) {
		delay;
		cct_showch(0, 4 + i * (3 + frame), 'A' + i, defaultColor, 1);
	}
	for (i = 0; i < maxCol; i++)
		for (j = 0; j < maxRow; j++)
			blockGenrator(6 + i * (6 + 2 * frame), 4 + j * (3 + frame), matrix[i][j]);
	cct_setcolor(inverseColor);
	cct_gotoxy(2, 2);
	delay;
	cout << "╔";
	cct_gotoxy(6 + (maxCol - 1) * (6 + 2 * frame) + 4, 2);
	delay;
	cout << "╗";
	cct_gotoxy(2, 4 + (maxRow - 1) * (3 + frame) + 2);
	delay;
	cout << "╚";
	cct_gotoxy(6 + (maxCol - 1) * (6 + 2 * frame) + 4, 4 + (maxRow - 1) * (3 + frame) + 2);
	delay;
	cout << "╝";
	cct_setcolor(inverseColor);
	i = 4;
	while (i < 6 + (maxCol - 1) * (6 + 2 * frame) + 4) {
		cct_gotoxy(i, 2);
		delay;
		cout << "═";
		cct_gotoxy(i, 4 + (maxRow - 1) * (3 + frame) + 2);
		delay;
		cout << "═";
		i++;
		i++;
	}
	i = 3;
	while (i < 4 + (maxRow - 1) * (3 + frame) + 2) {
		cct_gotoxy(2, i);
		delay;
		cout << "║";
		cct_gotoxy(6 + (maxCol - 1) * (6 + 2 * frame) + 4, i);
		delay;
		cout << "║";
		i++;
	}
	cct_setcolor(inverseColor);
	if (frame) {
		for (i = 0; i < maxCol - 1; i++) {
			cct_gotoxy(6 + i * (6 + 2 * frame) + 4, 2);
			delay;
			cout << "╦";
			cct_gotoxy(6 + i * (6 + 2 * frame) + 4, 4 + (maxRow - 1) * (3 + frame) + 2);
			delay;
			cout << "╩";
		}
		for (i = 0; i < maxRow - 1; i++) {
			cct_gotoxy(2, 4 + i * (3 + frame) + 2);
			delay;
			cout << "╠";
			cct_gotoxy(6 + (maxCol - 1) * (6 + 2 * frame) + 4, 4 + i * (3 + frame) + 2);
			delay;
			cout << "╣";
		}
		for (i = 0; i < maxCol - 1; i++) {
			j = 3;
			while (j < 4 + (maxRow - 1) * (3 + frame) + 2) {
				cct_gotoxy(6 + i * (6 + 2 * frame) + 4, j);
				delay;
				cout << "║";
				j++;
			}
			j = 4;
			while (j < 6 + (maxCol - 1) * (6 + 2 * frame) + 4) {
				cct_gotoxy(j, 4 + i * (3 + frame) + 2);
				delay;
				cout << "═";
				j++;
				j++;
			}
		}
		for (i = 0; i < maxCol - 1; i++)
			for (j = 0; j < maxRow - 1; j++) {
				cct_gotoxy(6 + i * (6 + 2 * frame) + 4, 4 + j * (3 + frame) + 2);
				delay;
				cout << "╬";
			}
	}
	cct_setcolor(defaultColor);
	return;
}
void module4(int rowMax, int colMax, int matrix[][10])
{
	bool frame = false,first=true;
	int x=-1 , y=-1 ;
	cct_cls();
	matrixInitialize(rowMax, colMax, frame, matrix);
	if (1) {
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
				if (Y > 2 && Y < 4 + (rowMax - 1) * (3 + frame) + 2 && X>2 && X < 6 + (colMax - 1) * (6 + 2 * frame) + 4) {

					inverseBlock(6 + ((X - 4) / blockwidth) * (6 + 2 * frame), 4 + ((Y - 3) / blockheight) * (3 + frame), matrix[(X - 4) / blockwidth][((Y - 3) / blockheight)]);
					if ((x != 6 + ((X - 4) / blockwidth) * (6 + 2 * frame) || y != 4 + ((Y - 3) / blockheight) * (3 + frame))&&!first)
						reverseBlock(x, y, matrix[(x - 4) / blockwidth][((y - 3) / blockheight)]);
					if (first) 
						first = false;
					x = 6 + ((X - 4) / blockwidth) * (6 + 2 * frame);
					y = 4 + ((Y - 3) / blockheight) * (3 + frame);
					cct_gotoxy(0, 32 + (rowMax - 8) * 3 + frame * 7 + frame * (rowMax - 8) - 4);
					cout << "[当前鼠标] " << (char)('A' + (Y - 3) / blockheight) << "行" << (X - 4) / blockwidth << "列";
				}
				else {
					
					if (!first) {
						reverseBlock(x, y, matrix[(x - 4) / blockwidth][((y - 3) / blockheight)]);
						first = true;
					}
cct_gotoxy(0, 32 + (rowMax - 8) * 3 + frame * 7 + frame * (rowMax - 8) - 4);
					cout << "[当前鼠标] 位置非法";
				}

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
	cct_gotoxy(0, 32 + (rowMax - 8) * 3 + frame * 7 + frame * (rowMax - 8) - 3);
	return;
}
void module5(int rowMax, int colMax, int matrix[][10])
{
	bool frame = true;
	cct_cls();
	matrixInitialize(rowMax, colMax, frame, matrix);

	cct_gotoxy(0, 32 + (rowMax - 8) * 3 + frame * 7 + frame * (rowMax - 8) - 3);
	return;
}
void module6(int rowMax, int colMax, int matrix[][10])
{
	return;
}
void module7(int rowMax, int colMax, int matrix[][10])
{
	return;
}

