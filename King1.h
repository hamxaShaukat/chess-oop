#pragma once
#include"Piece1.h"
#include"Queen1.h"
class Piece;

class King :public Piece
{
	Queen Q;
public:
	void prntKing(int rc, int cc);
	King(Position, COLOR, Board*);
	void draw(int rc,int cc);
	void getPieceID(char& pieceID);
	bool Legality(const Board& B, Position S, Position D, int Turn) const;
};
