#include "Rook1.h"
#include"Piece1.h"
#include<iostream>
#include<string>
#include<Windows.h>
#include"Position1.h"
#include"Header.h"
#include"Board1.h"
using namespace std;

void Rook::prntRook(int rc, int cc)
{
	for (int ln = 0; ln < s / 2; ln++)
	{
		gotoRowCol(ln + rc, cc);
		cout << char(-37);
	}
	for (int ln = 2, cl = 1; ln < s / 2 + 2; ln++)
	{
		gotoRowCol(ln + rc, cc - cl);
		for (int sl = 0; sl < cl * 2 + 1; sl++)
			cout << char(-37);
	}
}


Rook::Rook(Position P, COLOR _C, Board* b)
	:Piece(P, _C, b)
{

}
void Rook::draw(int rc,int cc)
{
	if (this->C == WHITE)
	{
		SetClr(6);
		prntRook(rc, cc);
	}
	else
	{
		SetClr(9);
		prntRook(rc, cc);
	}
}
void Rook::getPieceID(char& pieceID)
{
	if (this->getColor() == BLACK)
		pieceID = 'R';
	else
		pieceID = 'r';
}
bool Rook::Legality(const Board& B, Position S, Position D, int Turn)const 
{
	return (B.getPieceAt(S.r, S.c)->horizontalCheck(B, S, D) && B.getPieceAt(S.r, S.c)->horizontalPathClear(B, S, D))
		||
		(B.getPieceAt(S.r, S.c)->verticleCheck(B, S, D) && B.getPieceAt(S.r, S.c)->verticalPathClear(B, S, D));
}