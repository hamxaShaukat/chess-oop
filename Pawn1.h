#pragma once
#include"Piece1.h"
class Piece;

class Pawn :public Piece
{
public:
	Pawn(Position, COLOR, Board*);
	void draw(int rc, int cc);
	bool Legality(const Board& B, Position S, Position D, int Turn)const;
	void getPieceID(char& pieceID);
	void prntPawn(int rc, int cc);
};
