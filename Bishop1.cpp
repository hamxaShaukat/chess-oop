#include "Bishop1.h"
#include"Piece1.h"
#include<iostream>
#include<string>
#include<Windows.h>
#include"Position1.h"
#include"Header.h"
#include"Board1.h"
using namespace std;

void Bishop::prntBishop(int rc, int cc)
{
	for (int ln = 0; ln < s / 2 + 1; ln++)
	{
		gotoRowCol(ln + rc, cc - ln);
		for (int sl = 0; sl < ln * 2 + 1; sl++)
		{
			cout << char(-37);
		}
	}
	for (int ln = 3, cl = 1; ln < s / 2 + 2; ln++, cl++)
	{
		gotoRowCol(ln + rc, cc - cl);
		for (int sl = 0; sl < cl * 2 + 1; sl++)
		{
			cout << char(-37);
		}
	}

}
void Bishop::getPieceID(char& pieceID)
{
	if (this->getColor() == BLACK)
		pieceID = 'B';
	else
		pieceID = 'b';
}

Bishop::Bishop(Position P, COLOR _C, Board* b)
	:Piece(P, _C, b)
{

}
void Bishop::draw(int rc,int cc)
{
	if (this->C == WHITE)
	{
		SetClr(6);
		prntBishop(rc, cc);
	}
	else
	{
		SetClr(9);
		prntBishop(rc, cc);
	}
}

bool Bishop::Legality(const Board& B, Position S, Position D, int Turn) const 
{
	return B.getPieceAt(S.r,S.c)->diagonalCheck(B, S, D)    
		                  &&
		   B.getPieceAt(S.r,S.c)->diagonalPathClear(B, S, D);
}