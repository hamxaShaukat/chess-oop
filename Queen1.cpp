#include "Queen1.h"
#include"Piece1.h"
#include<iostream>
#include<string>
#include<Windows.h>
#include"Position1.h"
#include"Header.h"
#include"Board1.h"
#include"Rook1.h"
#include"Bishop1.h"
using namespace std;


Queen::Queen(Position P, COLOR _C, Board* b)
	:Piece(P, _C, b),R(P,_C,b),W(P, _C, b)
{

}
void Queen::prntQueen(int rc, int cc)
{
	for (int ln = 0; ln < s / 2; ln++)
	{
		gotoRowCol(ln + rc, cc - ln);
		for (int sl = 0; sl < ln * 2 + 1; sl++)
			cout << char(-37);
	}
	for (int ln = 2, cl = 1; ln < s / 2 + 2; ln++, cl++)
	{
		gotoRowCol(ln + rc, cc - cl);
		for (int sl = 0; sl < cl * 2 + 1; sl++)
			cout << char(-37);
	}
}
void Queen::getPieceID(char& pieceID)
{
	if (this->getColor() == BLACK)
		pieceID = 'Q';
	else
		pieceID = 'q';
}
void Queen::draw(int rc,int cc)
{
	if (this->C == WHITE)
	{
		SetClr(6);
		prntQueen(rc, cc);
	}
	else
	{
		SetClr(9);
		prntQueen(rc, cc);
	}
}
bool Queen::Legality(const Board& B, Position S, Position D, int Turn)const
{
	/*
	return ((B.getPieceAt(S.r, S.c)->horizontalCheck(B, S, D) && B.getPieceAt(S.r, S.c)->horizontalPathClear(B, S, D))
		||
		(B.getPieceAt(S.r, S.c)->verticleCheck(B, S, D) && B.getPieceAt(S.r, S.c)->verticalPathClear(B, S, D)))
		&&
		(B.getPieceAt(S.r, S.c)->diagonalCheck(B, S, D)
		&&
		B.getPieceAt(S.r, S.c)->diagonalPathClear(B, S, D));
		*/
	return R.Legality(B,S,D,Turn) || W.Legality(B, S, D, Turn);
}