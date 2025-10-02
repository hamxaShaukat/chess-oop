#include "Player1.h"
#include"Header.h"
#include<string>
using namespace std;




//Position Player::selectCoordinate(Position P)
//{
//	int r, c;
//	getRowColbyLeftClick(r, c);
//	P.r = r / brows;
//	P.c = c / bcols;
//	return P;
//
//}
Player::Player(string _n, COLOR c)
{
	this->name = _n;
	this->C = c;
}
string Player::getName()
{
	return this->name;
}
COLOR Player::getColor()
{
	return this->C;
}