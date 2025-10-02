#pragma once
#include<fstream>
#include"Position1.h"
#include"Player1.h"
#include"Board1.h"
#include<vector>

class Board;
class Piece;

class Chess
{
	Position sourcePos;
	Position destinPos;
	Player* Pns[2];
	Board* B;
	stack<Board>undo;
	stack<Board>redo;
public:
	Chess();
	Chess(ifstream& Rdr);
	Position findKing(const Board& B, int Turn);
	void newGame();
	void loadGame();
	void displayTurnMsg(Player* P);
	void selSrc();
	void selDes();
	void remove();
	void saver(string Name);
	bool staleMate(const Board&,int);
	void performUndo(int &Turn);
	void performRedo(int &Turn);
	bool ispromote(const Board& B, Position sC, Position dC, int Turn);
	bool check(const Board& B, int Turn);
	bool selfCheck(const Board& B, int turn);
	bool checkMate(const Board& B, int Turn);
	bool isDefending(const Board& B, int Turn);
	void removeName();
	bool isValidSrc(Player*P,Position sourcePos);
	bool isValidDes(Player*P,Position destinPos);
	bool checkpos1(const Board& B, bool**& bMap, Position sC, int Turn);
	void highlight(const Board& B, bool** bMap, Position sC, int Turn);
	void doClr(int r, int c);
	void turnChange(int &Turn);
	bool Castling(int Turn);
	bool possibleKingMoves(const Board& B, Position,int);
	
};

