#pragma once
#include"Piece1.h"
#include"Bishop1.h"
#include"Rook1.h"
class Piece;

class Queen :public Piece
{
	Rook R;
	Bishop W;
public:
	Queen(Position, COLOR, Board*);
	void prntQueen(int rc, int cc);
	void draw(int rc,int cc);
	void getPieceID(char& pieceID);
	bool Legality(const Board& B, Position S, Position D, int Turn) const ;
};
