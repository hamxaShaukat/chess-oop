#pragma once
#include"Piece1.h"


class Piece;

class Bishop :public Piece
{
public:
	Bishop(Position, COLOR, Board*);
	void draw(int rc,int cc);
	void prntBishop(int rc, int cc);
	void getPieceID(char& pieceID);
	bool Legality(const Board& B, Position S, Position D, int Turn) const;
};
