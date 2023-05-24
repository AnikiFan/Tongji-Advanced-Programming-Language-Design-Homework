/* 2254298 信11 范潇 */
#pragma once
using namespace std;
#include<iostream>
#include<conio.h>
#include<iomanip>
#include"cmd_console_tools.h"
#include<Windows.h>

//颜色
#define defaultColor 0,7
#define black 0,0
#define background black
#define highlight 14,0

void reload(void);

void module1(int rowMax, int colMax, int matrix[][10]);
void module2(int rowMax, int colMax);
void module3(int rowMax, int colMax);
void module4(int rowMax, int colMax);
void module5(int rowMax, int colMax);
void module6(int rowMax, int colMax);
void module7(int rowMax, int colMax);
void matrixGenerator(int matrix[][10], int rowInterval, int colInterval, int rowMax, int colMax, int srcxcoo, int srcycoo);
int search(int srcRow, int srcCol, int matrix[][10], int rowMax, int colMax, int option, int x, int y, int rowInterval, int colInterval);//xy为第一个元素的坐标
void getCoordinate(int& row, int& col, int rowMax, int colMax);
void matrixInitialize(int rowMax, int colMax, int matrix[][10]);