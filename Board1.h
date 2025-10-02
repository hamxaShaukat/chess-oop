#pragma once
#include"Header.h"
#include<fstream>
#include"Position1.h"
class Piece;

class Board
{
private:
	COLOR C;
	Piece*** Pcs;
	bool LegalMove[8][8];
public:
	Piece* getPieceAt(int r,int c)const;
	Board();
	Board(ifstream&Rdr);
	Board(const Board&B);
	void doClr(int r, int c);
	void L2R(int srow, int scol, int ecol);
	void T2B(int scol, int srow, int erow);
	void assign(const Board& B);
	void deleteMemory();
	void printRookButton();
	void printBishopButton();
	void printUndoButton();
	void printRedoButton();
	void printActionButton();
	void printKnightButton();
	void printQueenButton();
	void printPromotion();
	bool isBishop();
	bool isKnight();
	bool isRedo();
	bool isUndo();
	bool isQueen();
	bool isRook();
	void setPiece(Piece*, Position)const;
	void pawnToQueen(Position pos, int Turn);
	void pawnToKnight(Position pos, int Turn);
	void pawnToBishop(Position pos, int Turn);
	void pawnToRook(Position pos,int Turn);
	void movePiece(Position S, Position D);
	void movePiece(Position S, Position D)const;
	const void compBoard(int sr, int sc);
	const void drawBox(int sr, int sc);
	const void drawBoard();
	void prntBound(int sr, int sc);
	void doClrBound(int r, int c);
	~Board();


};
