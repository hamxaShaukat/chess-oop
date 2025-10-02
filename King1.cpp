#include "King1.h"
#include"Piece1.h"
#include<iostream>
#include<string>
#include<Windows.h>
#include"Position1.h"
#include"Header.h"
#include"Board1.h"
using namespace std;
void King::prntKing(int rc, int cc)
{
	for (int ln = 0; ln < s / 2 + 2; ln++)
	{
		gotoRowCol(ln + rc, cc - ln);
		for (int sl = 0; sl < ln * 2 + 1; sl++)
			cout << char(-37);
	}
}
King::King(Position P, COLOR _C, Board* b)
	:Piece(P, _C, b),Q(P,_C,b)
{

}
void King::draw(int rc,int cc)
{
	if (this->C == WHITE)
	{
		SetClr(6);
		prntKing(rc, cc);
	}
	else
	{
		SetClr(9);
		prntKing(rc, cc);
	}
}

void King::getPieceID(char& pieceID)
{
	if (this->getColor() == BLACK)
		pieceID = 'K';
	else
		pieceID = 'k';
}

bool King::Legality(const Board& B, Position S, Position D, int Turn)const
{
	int delR, delC;
	delC = abs(D.c - S.c);
	delR = abs(D.r - S.r);
	return Q.Legality(B, S, D, Turn) && delC <= 1 && delR <= 1;
}