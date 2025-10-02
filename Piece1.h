#pragma once
#include"Position1.h"
#include"Board1.h"
#include"Header.h"

class Board;

class Piece
{
protected:
	Position Pos;
	COLOR C;
	Board* B;
	char pieceID;
public:
	//Position findKing(const Board& B, Position dC, int Turn);
	bool horizontalPathClear(const Board & B,Position S, Position D);
	bool rightDiagonalPathClear(const Board & B,Position sC, Position dC);
	bool leftDiagonalPathClear(const Board & B,Position sC, Position dC);
	bool diagonalPathClear(const Board & B,Position sC, Position dC);
	bool verticalPathClear(const Board & B,Position sC, Position dC);
	bool horizontalCheck(const Board & B,Position sC, Position dC);
	bool verticleCheck(const Board & B,Position sC, Position dC);
	bool diagonalCheck(const Board & B,Position sC, Position dC);
	Piece(Position, COLOR _C, Board*);
	virtual void getPieceID(char& pieceID)=0;
	virtual void draw(int rc,int cc) = 0;
	virtual bool Legality(const Board& B,Position S,Position D, int Turn) const = 0;
	void move(Position);
	COLOR getColor();
};
