#pragma once

#include"Piece1.h"
class Piece;

class Knight :public Piece
{
public:
	Knight(Position, COLOR, Board*);
	void draw(int rc,int cc);
	void prntKnight(int rc, int cc);
	void getPieceID(char& pieceID);
	bool Legality(const Board& B, Position S, Position D, int Turn)const;
};
