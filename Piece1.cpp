#include "Piece1.h"
#include"Position1.h"
#include"Board1.h"
#include"King1.h"
#include"Header.h"

Piece::Piece(Position P, COLOR _C, Board* b)
{
	this->Pos.r = P.r;
	this->Pos.c = P.c;
	this->C = _C;
	this->B = b;
}
void Piece::move(Position Ps)
{
	this->Pos.r = Ps.r;
	this->Pos.c = Ps.c;
}
COLOR Piece::getColor()
{
	return this->C;
}
//Position Piece::findKing(const Board& B, Position dC, int Turn)
//{
//	if (Turn == 0)
//	{
//		for (int i = 0; i < dimension; i++)
//		{
//			for (int j = 0; j < dimension; j++)
//			{
//				Piece*** P;
//				if (*P[i][j] == King(dC, BLACK, B))
//					dC.r = i, dC.c = j;
//			}
//		}
//	}
//	else
//	{
//		for (int i = 0; i < dimension; i++)
//		{
//			for (int j = 0; j < dimension; j++)
//			{
//				if (B[i][j] == 'K')
//					dC.r = i, dC.c = j;
//			}
//		}
//	}
//	return dC;
//}
bool Piece::horizontalPathClear(const Board &B,Position S, Position D)
{
	if (S.c < D.c)
	{
		for (int col = S.c + 1; col < D.c; col++)
		{
			if (B.getPieceAt(S.r, col) != nullptr)
			{
				return false;
			}
		}
		return true;
	}
	else if (S.c > D.c)
	{
		for (int col = D.c + 1; col < S.c; col++)
		{
			if (B.getPieceAt(S.r, col) != nullptr)
			{
				return false;
			}
		}
		return true;
	}
	else
		return false;
}
bool Piece::rightDiagonalPathClear(const Board &B,Position sC, Position dC)
{
	/*if (sC.r < dC.r)
	{
		int dr = abs(dC.r - sC.r - 1);
		for (int d = 1; d <= dr; d++)
		{
			if (B.getPieceAt(sC.r + d,sC.c - d) != nullptr)
			{
				return false;
			}
		}
		return true;
	}
	else
	{
		int dr = abs(sC.r - dC.r - 1);
		for (int d = 1; d <= dr; d++)
		{
			if (B.getPieceAt(dC.r + d,dC.c - d) != nullptr)
			{
				return false;
			}
		}
		return true;
	}*/
	if (sC.r < dC.r)
	{
		int dr = abs(dC.r - sC.r - 1);
		for (int d = 1; d <= dr; d++)
		{
			if (B.getPieceAt(sC.r + d, sC.c - d) != nullptr)
			{
				return false;
			}
		}
		return true;
	}
	else
	{
		int dr = abs(sC.r - dC.r - 1);
		for (int d = 1; d <= dr; d++)
		{
			if (B.getPieceAt(sC.r - d, sC.c - d) != nullptr)
			{
				return false;
			}
		}
		return true;
	}
}
bool Piece::leftDiagonalPathClear(const Board &B,Position sC, Position dC)
{
	if (sC.r < dC.r)
	{
		int dr = abs(dC.r - sC.r - 1);
		for (int d = 1; d <= dr; d++)
		{
			if (B.getPieceAt(sC.r + d, sC.c + d) != nullptr)
			{
				return false;
			}
		}
		return true;
	}
	else
	{
		int dr = abs(sC.r - dC.r - 1);
		for (int d = 1; d <= dr; d++)
		{
			if (B.getPieceAt(sC.r - d, sC.c + d) != nullptr)
			{
				return false;
			}
		}
		return true;
	}
}
bool Piece::verticalPathClear(const Board &B,Position sC, Position dC)
{
	if (sC.r < dC.r)
	{
		for (int rows = sC.r + 1; rows < dC.r; rows++)
		{
			if (B.getPieceAt(rows, sC.c) != nullptr)
			{
				return false;
			}
		}
		return true;
	}
	else if (sC.r > dC.r)
	{
		for (int rows = dC.r + 1; rows < sC.r; rows++)
		{
			if (B.getPieceAt(rows,sC.c) != nullptr)
			{
				return false;
			}
		}
		return true;
	}
	else
	{
		return false;
	}
}
bool Piece::horizontalCheck(const Board &B,Position sC, Position dC)
{
	if (sC.r == dC.r)
		return true;
	return false;
}
bool Piece::verticleCheck(const Board &B,Position sC, Position dC)
{
	if (sC.c == dC.c)
		return true;
	return false;
}
bool Piece::diagonalCheck(const Board &B,Position sC, Position dC)
{
	int DR = abs(sC.r - dC.r);
	int DC = abs(sC.c - dC.c);
	if (DR == DC)
	{
		return true;
	}
	return false;
}
bool Piece::diagonalPathClear(const Board& B, Position sC, Position dC)
{
	if ((sC.c - dC.c) < 0)
	{
		return leftDiagonalPathClear(B, sC, dC);
	}
	else
	{
		return rightDiagonalPathClear(B, sC, dC);
	}
}