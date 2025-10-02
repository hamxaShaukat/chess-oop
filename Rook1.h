#pragma once
#include"Piece1.h"
class Piece;

class Rook :public Piece
{
public:
	void prntRook(int rc, int cc);
	Rook(Position, COLOR, Board*);
	void draw(int rc,int cc) ;
	void getPieceID(char& pieceID);
	bool Legality(const Board& B, Position S, Position D, int Turn)const;
};

