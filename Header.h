#pragma once
#include<iostream>
#include<string>
#include<stack>
#include<Windows.h>
using namespace std;
enum COLOR { BLACK, WHITE = 15 };
#define brows 10
#define bcols 10
#define dimension 8
#define s 5


void getRowColbyLeftClick(int& rpos, int& cpos);
void gotoRowCol(int rpos, int cpos);
void SetClr(int clr);
