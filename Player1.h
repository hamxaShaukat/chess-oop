#pragma once
#include<string>
#include"Header.h"
#include "Position1.h"
using namespace std;
class Player {
private:
	string name;
	COLOR C;
	//static void getRowColbyLeftClick(int&, int&);
public:
	Player(string _n, COLOR c);
	string getName();
	COLOR getColor();
	Position selectCoordinate(Position P);
};

