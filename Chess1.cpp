#include "Chess1.h"
#include"Piece1.h"
#include"Player1.h"
#include"Header.h"
#include"Board1.h"
#include<fstream>
#include<iostream>
#include<string>
#include<vector>
#include<Windows.h>
using namespace std;
Chess::Chess()
{
	Pns[0] = new Player("Hamza", WHITE);
	Pns[1] = new Player("Ali", BLACK);

	B = new Board();
	undo.push(*B);
}
Chess::Chess(ifstream&Rdr)
{
	Pns[0] = new Player("Hamza", WHITE);
	Pns[1] = new Player("Ali", BLACK);

	B = new Board(Rdr);
}
void Chess::remove()
{
	for (int i = 85; i < 115; i++)
	{
		gotoRowCol(6, i);
		cout << " ";
	}
}
void Chess::removeName()
{
	for (int i = 85; i < 115; i++)
	{
		gotoRowCol(5, i);
		cout << " ";
	}
}
void Chess::loadGame()
{
	//Niche wala Black hai aur ooper wala White
	bool** bMap;
	int Turn = 0;
	//B->compBoard(5, 5);
	//B->drawBoard();
	do
	{
		do
		{

			do {
				do
				{
					B->compBoard(5, 5);
					removeName();
					displayTurnMsg(Pns[Turn]);
					do
					{
						//B->printActionButton();
						//if (B->isUndo())
						//{
						//	performUndo(Turn);
						//	//turnChange(Turn);
						//}

						remove();
						selSrc();

					} while (isValidSrc(Pns[Turn], sourcePos) == false);

					checkpos1(*B, bMap, sourcePos, Turn);
					highlight(*B, bMap, sourcePos, Turn);
					remove();
					selDes();
				} while (isValidDes(Pns[Turn], destinPos) == false);
			} while (B->getPieceAt(sourcePos.r, sourcePos.c)->Legality(*B, sourcePos, destinPos, Turn) == false);
		} while (selfCheck(*B, Turn));
		B->movePiece(sourcePos, destinPos);
		undo.push(*B);
		while (!redo.empty())
		{
			redo.pop();
		}

		if (ispromote(*B, sourcePos, destinPos, Turn) == true)
		{
			B->printPromotion();
			if (B->isBishop() == true)
			{
				B->pawnToBishop(destinPos, Turn);
			}
			if (B->isKnight() == true)
			{
				B->pawnToKnight(destinPos, Turn);

			}
			if (B->isQueen() == true)
			{
				B->pawnToQueen(destinPos, Turn);

			}
			if (B->isRook() == true)
			{
				B->pawnToRook(destinPos, Turn);

			}
		}
		if (check(*B, Turn) == true)
		{
			gotoRowCol(8, 85);
			cout << "****************\n" << Pns[Turn] << "is in check";
		}
		if (/*!isDefending(*B,Turn) && */check(*B, Turn) && checkMate(*B, Turn))
		{
			gotoRowCol(10, 100);
			cout << "Checkmate";
			break;

		}
		//B->compBoard(5, 5);
		saver("saving.txt");
		turnChange(Turn);
		//Sleep(10000);
	} while (true);


}



void Chess::newGame()
{

	//Niche wala Black hai aur ooper wala White
	bool** bMap;
	int Turn = 0;
	int cst = 0;
	//B->compBoard(5, 5);
	//B->drawBoard();
	do
	{
		do
		{
			cst = 0;

			do {
				do
				{
					B->compBoard(5, 5);
					removeName();
					displayTurnMsg(Pns[Turn]);
					do
					{
						
						B->printActionButton();
						if (B->isUndo())
						{
							performUndo(Turn);
							//turnChange(Turn);
							B->compBoard(5, 5);
						}
						else if (B->isRedo())
						{
							performRedo(Turn);
							B->compBoard(5, 5);
						}
						displayTurnMsg(Pns[Turn]);
						remove();
						selSrc();
						if (sourcePos.r == 0 || sourcePos.r == 7)
						{
							char key;
							B->getPieceAt(sourcePos.r, sourcePos.c)->getPieceID(key);
							if (Turn == 0)
							{
								if (key == 'K')
								{
									if (Castling(Turn))
									{
										cst = 1;
										break;
									}
								}
							}
							else
							{
								if (key == 'k')
								{
									if (Castling(Turn))
									{
										cst = 1;
										break;
									}
								}
							}
						}

					} while (isValidSrc(Pns[Turn], sourcePos) == false);
					if (cst == 1)
						break;
					checkpos1(*B, bMap, sourcePos, Turn);
					highlight(*B, bMap, sourcePos, Turn);
					remove();
					selDes();
				} while (isValidDes(Pns[Turn], destinPos) == false);
				if (cst == 1)
					break;
			} while (B->getPieceAt(sourcePos.r, sourcePos.c)->Legality(*B, sourcePos, destinPos, Turn) == false);
		} while (selfCheck(*B,Turn));
		B->movePiece(sourcePos, destinPos);
		undo.push(*B);
		while (!redo.empty())
		{
			redo.pop();
		}

		if (ispromote(*B, sourcePos, destinPos, Turn) == true)
		{
			B->printPromotion();
			if (B->isBishop() == true)
			{
				B->pawnToBishop(destinPos, Turn);
			}
			if (B->isKnight() == true)
			{
				B->pawnToKnight(destinPos, Turn);

			}
			if (B->isQueen() == true)
			{
				B->pawnToQueen(destinPos, Turn);

			}
			if (B->isRook() == true)
			{
				B->pawnToRook(destinPos, Turn);

			}
		}
		if (check(*B, Turn) == true)
		{
			gotoRowCol(8,85);
			cout << "****************\n"<<Pns[!Turn]->getName() << "is in check";
			system("pause>0");
		}
		//turnChange(Turn);
		if (!isDefending(*B,Turn) && check(*B,Turn)/*&& checkMate(*B, Turn)*/)
		{
			gotoRowCol(10, 100);
			cout << "Checkmate";
			break;

		}
		//turnChange(Turn);
		//B->compBoard(5, 5);
		saver("saving.txt");
		turnChange(Turn);
		//Sleep(10000);
	} while (true);


}
bool Chess::Castling(int Turn)
{
	if (Turn == 0)
	{
		if (B->getPieceAt(0, 4) && B->getPieceAt(0, 4)->horizontalPathClear(*B, sourcePos, destinPos)
			&& !check(*B, Turn))
		{
			Position S, D;
			S.r = 0, S.c = 4;
			D.r = 0, D.c = 6;
			B->movePiece(S,D);
			D.r = 0, D.c = 5;
			S.r = 0, S.c = 7;
			B->movePiece(S, D);
			return true;


		}
		if (B->getPieceAt(0, 0) && B->getPieceAt(0, 4)->horizontalPathClear(*B, sourcePos, destinPos)
			&& !check(*B, Turn))
		{
			Position S, D;
			S.r = 0, S.c = 0;
			D.r = 0, D.c = 3;
			B->movePiece(S, D);
			D.r = 0, D.c = 2;
			S.r = 0, S.c = 4;
			B->movePiece(S, D);
			return true;
		}
		return false;
	}
	else
	{
		if (B->getPieceAt(7, 4) && B->getPieceAt(0, 4)->horizontalPathClear(*B, sourcePos, destinPos)
			&& !check(*B, Turn))
		{
			Position S, D;
			S.r = 7, S.c = 4;
			D.r = 7, D.c = 6;
			B->movePiece(S, D);
			D.r = 7, D.c = 5;
			S.r = 7, S.c = 7;
			B->movePiece(S, D);
			return true;


		}
		if (B->getPieceAt(7, 0) && B->getPieceAt(0, 4)->horizontalPathClear(*B, sourcePos, destinPos)
			&& !check(*B, Turn))
		{
			Position S, D;
			S.r = 7, S.c = 0;
			D.r = 7, D.c = 3;
			B->movePiece(S, D);
			D.r = 7, D.c = 2;
			S.r = 7, S.c = 4;
			B->movePiece(S, D);
			return true;
		}
		return false;
	}
}
void Chess::saver(string Name)
{
	ofstream Wrtr(Name);
	for (int i = 0; i < dimension; i++)
	{
		for (int j = 0; j < dimension; j++)
		{
			if (B->getPieceAt(i, j) == nullptr)
			{
				Wrtr << '-';
			}
			else
			{
				char key;
				B->getPieceAt(i, j)->getPieceID(key);
				Wrtr << key;
			}
		}
			Wrtr << endl;
	}
	
}
void Chess::displayTurnMsg(Player* P)
{
	gotoRowCol(5, 85);
	cout << "Its " << P->getName() << " 's Turn";
}
void Chess::selSrc()
{
	gotoRowCol(6, 85);
	cout << "Select your Geeti......";

	int r, c;
	getRowColbyLeftClick(r, c);
	sourcePos.r = r / brows;
	sourcePos.c = c / bcols;
}
void Chess::selDes()
{
	gotoRowCol(6, 85);
	cout << "Select your Jagah......";
	int r, c;
	getRowColbyLeftClick(r, c);
	destinPos.r = r / brows;
	destinPos.c = c / bcols;
}
bool Chess::isValidSrc(Player* p, Position Pos)
{
	if (Pos.r < 0 || Pos.r >= dimension || Pos.c < 0 || Pos.c >= dimension)
		return false;
	Piece* P = B->getPieceAt(Pos.r,Pos.c);
	return P != nullptr && P->getColor() == p->getColor();
}
bool Chess::isValidDes(Player* p, Position Pos)
{
	if(Pos.r<0 || Pos.r>=dimension || Pos.c<0 || Pos.c>=dimension)
		return false;
	Piece* P = B->getPieceAt(Pos.r,Pos.c);
	return (P == nullptr || P->getColor() != p->getColor());

}
void Chess::turnChange(int &Turn)
{
	if (Turn == 0)
		Turn = 1;
	else
		Turn = 0;
}
bool Chess::checkpos1(const Board& B, bool**& bMap, Position sC, int Turn)
{

	Position D;
	bMap = new bool* [dimension];
	for (int i = 0; i < dimension; i++)
		bMap[i] = new bool[dimension] {};

	for (int r = 0; r < dimension; r++)
	{
		for (int c = 0; c < dimension; c++)
		{
			D.r = r, D.c = c;
			if (isValidDes(Pns[Turn],D) && B.getPieceAt(sC.r,sC.c)->Legality(B, sC, D, Turn))
			{
				bMap[r][c] = true;
			}
		}
	}
	return bMap;
}
void Chess::highlight(const Board&B, bool** bMap, Position sC, int Turn)
{

	for (int r = 0; r < dimension; r++)
	{
		for (int c = 0; c < dimension; c++)
		{
			if (bMap[r][c] == true)
			{
				doClr(r, c);
			}
		}
	}
}
void Chess::doClr(int r, int c)
{
	r = r * brows + 5;
	c = c * bcols + 5;

	r = (r / bcols) * bcols;
	c = (c / bcols) * bcols;

	for (int i = c; i < c + bcols; i++)
	{
		gotoRowCol(r, i);
		SetClr(15);
		cout << char(-37);
	}
	for (int i = c + bcols - 1, j = r; j < r + bcols; j++)
	{
		gotoRowCol(j, i);
		SetClr(15);
		cout << char(-37);
	}
	for (int i = r + bcols - 1, j = (c + bcols) - 1; j >= c; j--)
	{
		gotoRowCol(i, j);
		SetClr(15);
		cout << char(-37);
	}

	for (int i = (r + bcols) - 1; i >= r; i--)
	{
		gotoRowCol(i, c);
		SetClr(15);
		cout << char(-37);
	}
}
Position Chess::findKing(const Board& B, int Turn)
{
	
	if (Turn == 0)
	{
		for (int i = 0; i < dimension; i++)
		{
			for (int j = 0; j < dimension; j++)
			{
				char key;
				Position dC;
				if (B.getPieceAt(i, j) == nullptr)
					continue;
				B.getPieceAt(i, j)->getPieceID(key);
				if (key == 'k')
				{
					dC.r = i, dC.c = j;
					return dC;
				}
			}
		}
	}
	else
	{
		for (int i = 0; i < dimension; i++)
		{
			for (int j = 0; j < dimension; j++)
			{
				char key;
				if (B.getPieceAt(i, j) == nullptr)
					continue;
				Position dC;
				B.getPieceAt(i, j)->getPieceID(key);
				if (key == 'K')
				{
					dC.r = i, dC.c = j;
					return dC;
				}
			}
		}
	}
}
bool Chess::check(const Board& B, int Turn)
{
	Position D;

	turnChange(Turn);
	D = findKing(B,Turn);
	turnChange(Turn);
	for (int i = 0; i < dimension; i++)
	{
		for (int j = 0; j < dimension; j++)
		{
			Position S;
			S.r = i, S.c = j;
			if (isValidSrc(Pns[Turn],S))
			{
				if (B.getPieceAt(S.r, S.c) != nullptr)
				{
					if (B.getPieceAt(S.r, S.c)->Legality(B, S, D, Turn))
						return true;
				}
			}
		}
	}
	return false;



	/*
	Piece* ptr1 = B.getPieceAt(sourcePos.r, sourcePos.c), 
		* ptr2 = B.getPieceAt(destinPos.r, destinPos.c);
	B.movePiece(sourcePos, destinPos);
	Position D = findKing(B, Turn);
	Position S;
	for (int i = 0; i < dimension; i++)
	{
		for (int j = 0; j < dimension; j++)
		{
			S.r = i, S.c = j;
			Piece* ptr3 = B.getPieceAt(i, j);
			if (ptr3 != nullptr)
			{
				if (ptr3->getColor() != Pns[Turn]->getColor())
				{
					if (isValidSrc(Pns[(Turn+1)%2], S) && B.getPieceAt(i, j)->Legality(B, S, D, Turn))
					{
						B.setPiece(ptr1, sourcePos);
						B.setPiece(ptr2, destinPos);
						return true;
					}
				}
			}
		}
	}
	B.setPiece(ptr1, sourcePos);
	B.setPiece(ptr2, destinPos);
	return false;
	*/
}
bool Chess::selfCheck(const Board& B, int turn)
{
	turnChange(turn);
	return check(B, turn);
}
bool Chess::isDefending(const Board& B,int Turn)
{
	//turnChange(Turn);
	Position D,sC;
	for (int i = 0; i < dimension; i++)
	{
		for (int j = 0; j < dimension; j++)
		{ 
			sC.r = i, sC.c = j;
			//Position kingPosition = findKing(B, Turn);
			if (isValidSrc(Pns[(Turn+1)%2], sC) == true)
			{
				for (int k = 0; k < dimension; k++)
				{
      					for (int l = 0; l < dimension; l++)
					{
						D.r = k, D.c = l;
						if (isValidDes(Pns[(Turn + 1) % 2],D) == true)
						{
							if (B.getPieceAt(sC.r, sC.c) == nullptr)
								continue;
							if (B.getPieceAt(sC.r, sC.c)->Legality(B, sC, D, (Turn + 1) % 2) == true)
							{
								Board tempBoard = B;
								tempBoard.movePiece(sC, D);
								//turnChange(Turn);
								if (check(tempBoard, (Turn + 1) % 2) == false)
								{
									//turnChange(Turn);
									return true;
								}
								
							}
						}
					}
				}
			}
		}
	}
	turnChange(Turn);
	return false;
}
bool Chess::checkMate(const Board& B, int Turn)
{
	/*
	turnChange(Turn);
	Position D;
	D = findKing(B, Turn);
	turnChange(Turn);
	for (int i = -1; i <= 1; i++)
	{
		for (int j = -1; j <= 1; j++)
		{
			Position S;
			S.r = sourcePos.r + i;
			S.c = sourcePos.c + j;
			if (isValidDes(Pns[Turn], S))
			{
				if()
			}
		}
	}
	*/
	return true;
	/*
	Board c(B);
	Position des = destinPos;
	Position SOS = sourcePos;
	turnChange(Turn);
	destinPos = findKing(B, Turn);
	int count = 0;
	if (!selfCheck(B, Turn))
	{
		sourcePos = SOS;
		destinPos = des;
		return false;
	}
	turnChange(Turn);
	for (int i = 0; i < dimension; i++)
	{
		for (int j = 0; j < dimension; j++)
		{
			
			
			sourcePos.r = i, sourcePos.c = j;
			if (isValidDes(Pns[Turn],sourcePos)
				&& B.getPieceAt(destinPos.r, destinPos.c)->Legality(B, destinPos, sourcePos, Turn))
			{
				c.movePiece(destinPos, sourcePos);
				if (!check(c, Turn))
				{
					sourcePos = SOS;
					destinPos = des;
					return false;
				}
				c.assign(B);
			}
		}
	}
	sourcePos = SOS;
	destinPos = des;
	return true;
	*/
}
bool Chess::staleMate(const Board& B,  int Turn)
{
	
	Position sC, D;
	turnChange(Turn);
	Position kingPosition = findKing(B, Turn);
	bool isKingChecked = check(B, Turn);
	if (!isKingChecked) {
		for (int i = 0; i < dimension; i++) {
			for (int j = 0; j < dimension; j++) {
				sC.r = i, sC.c = j;

				if (isValidSrc(Pns[Turn], sC)) {
					for (int k = 0; k < dimension; k++) {
						for (int l = 0; l < dimension; l++) {
							D.r = k, D.c = l;

							if (isValidDes(Pns[Turn], D)) {
								if (B.getPieceAt(i, j)->Legality(B, sC, D, Turn)) {
									return false;
								}
							}
						}
					}
				}
			}
		}
		return true;
	}
	else {
		return false;
	}
}
bool Chess::ispromote(const Board& B, Position sC, Position dC, int Turn)
{
	if (Turn == 0)
	{
		if (B.getPieceAt(dC.r, dC.c)->getColor() == WHITE)
		{
			char key;
			B.getPieceAt(dC.r, dC.c)->getPieceID(key);
			if (key != 'p')
				return false;
		}
		if (dC.r == 7)
			return true;
		return false;
	}
	else
	{
		if (B.getPieceAt(dC.r, dC.c)->getColor() == BLACK)
		{
			char key;
			B.getPieceAt(dC.r, dC.c)->getPieceID(key);
			if (key != 'P')
				return false;
		}
		if (dC.r == 0)
			return true;
		return false;
	}
}
void Chess::performUndo(int &Turn)
{
	if (undo.size() > 1)
	{

		redo.push(undo.top());
		undo.pop();
		//B->deleteMemory();
		B->assign(undo.top());
		turnChange(Turn);
	}
	else
	{
		gotoRowCol(8, 95);
		cout << "You dont have Undos";
	}
}
void Chess::performRedo(int &Turn)
{
	if (redo.size() > 0)
	{
		undo.push(*B);
		B->assign(redo.top());
		redo.pop();
		turnChange(Turn);
	} 
	else
	{
		gotoRowCol(8, 95);
		cout << "You dont have Undos";
	}
}