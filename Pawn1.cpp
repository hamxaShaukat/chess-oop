#include "Pawn1.h"
#include"Piece1.h"
#include<iostream>
#include<string>
#include<Windows.h>
#include"Position1.h"
#include"Header.h"
#include"Board1.h"
using namespace std;


void Pawn::prntPawn(int rc, int cc)
{
	for (int ln = 0; ln < s / 2; ln++)
	{
		gotoRowCol(ln + rc, cc - ln);
		for (int sl = 0; sl < ln * 2 + 1; sl++)
			cout << char(-37);
	}
	for (int ln = 2, cl = 0; ln < s / 2 + 2; ln++, cl++)
	{
		gotoRowCol(ln + rc, cc - cl);
		for (int sl = 0; sl < cl * 2 + 1; sl++)
			cout << char(-37);
	}
}


Pawn::Pawn(Position P, COLOR _C, Board* b)
	:Piece(P, _C, b)
{
}
void Pawn::getPieceID(char& pieceID)
{
	if (this->getColor() == BLACK)
	{
		pieceID = 'P';
	}
	else
		pieceID = 'p';
}
void Pawn::draw(int rc, int cc)
{
	if (this->C == WHITE)
	{
		SetClr(6);
		prntPawn(rc, cc);
	}
	else
	{
		SetClr(9);
		prntPawn(rc, cc);
	}

}
bool Pawn::Legality(const Board& B, Position S, Position D, int Turn)const
{

	int delR = abs(D.r - S.r);
	if (Turn == 0)
	{
		if (S.r == 1)
		{
			return (B.getPieceAt(S.r, S.c)->verticleCheck(B, S, D) && B.getPieceAt(D.r, D.c) == nullptr && delR <= 2 && S.r < D.r)
				|| (B.getPieceAt(S.r, S.c)->diagonalCheck(B,S,D) && B.getPieceAt(D.r, D.c) != nullptr && delR <= 1 && S.r < D.r);
		}
		else
		{
			return (B.getPieceAt(S.r, S.c)->verticleCheck(B, S, D) && B.getPieceAt(D.r, D.c) == nullptr && delR == 1 && S.r < D.r)
				|| (B.getPieceAt(S.r, S.c)->diagonalCheck(B, S, D) && B.getPieceAt(D.r, D.c) != nullptr && delR <= 1 && S.r < D.r);
		}

	}
	else
	{
		if (S.r == 6)
		{

			return (B.getPieceAt(S.r, S.c)->verticleCheck(B, S, D) && B.getPieceAt(D.r, D.c) == nullptr && delR <= 2 && S.r > D.r)
				|| (B.getPieceAt(S.r, S.c)->diagonalCheck(B, S, D) && B.getPieceAt(D.r, D.c) != nullptr && delR <= 1 && S.r > D.r);
		}
		else
		{
			return (B.getPieceAt(S.r, S.c)->verticleCheck(B, S, D) && B.getPieceAt(D.r, D.c) == nullptr && delR == 1 && S.r > D.r)
				|| (B.getPieceAt(S.r, S.c)->diagonalCheck(B, S, D) && B.getPieceAt(D.r, D.c) != nullptr && delR <= 1 && S.r > D.r);
		}
	}


	/*int delR = abs(D.r - S.r);
		if (Turn == 0)
		{
			if (S.r == 1)
			{
				return B.getPieceAt(S.r, S.c)->verticleCheck(B, S, D) && B.getPieceAt(D.r, D.c) == nullptr && delR <= 2 && S.r < D.r;
			}
			else
			{	
				return (B.getPieceAt(S.r, S.c)->verticleCheck(B, S, D) && B.getPieceAt(D.r, D.c) == nullptr && delR == 1 && S.r < D.r);
			}

		}
		else
		{
			if (S.r == 6)
			{

				return (B.getPieceAt(S.r, S.c)->verticleCheck(B, S, D) && B.getPieceAt(D.r, D.c) == nullptr && delR <= 2 && S.r > D.r);
			}
			else
			{
				return (B.getPieceAt(S.r, S.c)->verticleCheck(B, S, D) && B.getPieceAt(D.r, D.c) == nullptr && delR == 1 && S.r > D.r);
			}
		}*/
}