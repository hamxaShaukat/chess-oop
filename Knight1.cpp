#include "Knight1.h"
#include"Piece1.h"
#include<iostream>
#include<string>
#include<Windows.h>
#include"Position1.h"
#include"Header.h"
#include"Board1.h"
using namespace std;

void Knight::prntKnight(int rc, int cc)
{
	for (int ln = 0; ln < s / 2; ln++)
	{
		gotoRowCol(ln + rc, cc - ln);
		for (int sl = 0; sl < ln * 2 + 1; sl++)
		{
			if (sl == 0)
				cout << char(-37);
			else
				continue;
		}
	}
	for (int ln = 2, cl = 1; ln < s / 2 + 2; ln++, cl++)
	{
		if (ln == 2)
		{
			gotoRowCol(ln + rc, cc - cl);
			for (int sl = 0; sl < cl * 2 + 1; sl++)
			{
				if (sl <= 1)
					cout << char(-37);
				else
					continue;
			}
		}
		else
		{
			gotoRowCol(ln + rc, cc - cl);
			for (int sl = 0; sl < cl * 2 + 1; sl++)
			{
				cout << char(-37);
			}
		}
	}
}




void Knight::getPieceID(char& pieceID)
{
	if (this->getColor() == BLACK)
		pieceID = 'H';
	else
		pieceID = 'h';
}


Knight::Knight(Position P, COLOR _C, Board* b)
	:Piece(P, _C, b)
{
}
void Knight::draw(int rc,int cc)
{
	if (this->C == WHITE)
	{
		SetClr(6);
		prntKnight(rc, cc);
	}
	else
	{
		SetClr(9);
		prntKnight(rc, cc);
	}
}
bool Knight::Legality(const Board& B, Position S, Position D, int Turn)const
{
	int delR, delC;
	delC = abs(D.c - S.c);
	delR = abs(D.r - S.r);
	return (delR == 2 && delC == 1) || (delR == 1 && delC == 2);
}