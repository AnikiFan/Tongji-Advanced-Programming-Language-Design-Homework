/* 2254298 ÐÅ11 ·¶äì */
#pragma once
using namespace std;
#include<iostream>
#include<conio.h>
#include<iomanip>
#include"cmd_console_tools.h"

//ÑÕÉ«
#define defaultColor 0,7
#define black 0,0
#define background black


void reload(void);

void module1(int rowMax, int colMax, int matrix[][10]);
void module2(int rowMax, int colMax);
void module3(int rowMax, int colMax);
void module4(int rowMax, int colMax);
void module5(int rowMax, int colMax);
void module6(int rowMax, int colMax);
void module7(int rowMax, int colMax);
void matrixGenerator(int matrix[][10], int rowInterval, int colInterval, int rowMax, int colMax, int srcxcoo, int srcycoo);