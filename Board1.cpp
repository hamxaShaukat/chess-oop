#include "Board1.h"
#include"Piece1.h"
#include"Header.h"
#include"Position1.h"
#include"Pawn1.h"
#include"King1.h"
#include"Knight1.h"
#include"Queen1.h"
#include"Rook1.h"
#include"Bishop1.h"
#include"Chess1.h"


Board::Board()
{
	Pcs = new Piece * *[dimension];
	for (int i = 0; i < dimension; i++)
	{
		Pcs[i] = new Piece * [dimension];
		for (int j = 0; j < dimension; j++)
		{
			Position P;
			P.r = i;
			P.c = j;
			if (i == 1)
			{
				Pcs[i][j] = new Pawn(P, WHITE, this);
			}
			else if (i == 6)
			{
				Pcs[i][j] = new Pawn(P, BLACK, this);
			}
			else if (i == 0)
			{
				switch (j)
				{
				case(0):
				case(7):
					Pcs[i][j] = new Rook(P, WHITE, this);
					break;
				case(1):
				case(6):
					Pcs[i][j] = new Knight(P, WHITE, this);
					break;
				case(2):
				case(5):
					Pcs[i][j] = new Bishop(P, WHITE, this);
					break;
				case(3):
					Pcs[i][j] = new Queen(P, WHITE, this);
					break;
				case(4):
					Pcs[i][j] = new King(P, WHITE, this);
					break;

				default:
					break;
				}

			}
			else if (i == 7)
			{
				switch (j)
				{
				case(0):
				case(7):
					Pcs[i][j] = new Rook(P, BLACK, this);
					break;
				case(1):
				case(6):
					Pcs[i][j] = new Knight(P, BLACK, this);
					break;
				case(2):
				case(5):
					Pcs[i][j] = new Bishop(P, BLACK, this);
					break;
				case(3):
					Pcs[i][j] = new Queen(P, BLACK, this);
					break;
				case(4):
					Pcs[i][j] = new King(P, BLACK, this);
					break;

				default:
					break;
				}
			}
			else
			{
				Pcs[i][j] = nullptr;
			}
		}
	}
}

Board::Board(ifstream& Rdr)
{
	Pcs = new Piece * *[dimension];

	for (int i = 0; i < dimension; i++)
	{
		Pcs[i] = new Piece * [dimension];
		for (int j = 0; j < dimension; j++)
		{
			Position P;
			P.r = i, P.c = j;
			char key;
			Rdr >> key;
			switch (key)
			{
			case('k'):
				this->Pcs[i][j] = new King(P, WHITE, this);
				break;
			case('p'):
				this->Pcs[i][j] = new Pawn(P, WHITE, this);
				break;
			case('h'):
				this->Pcs[i][j] = new Knight(P, WHITE, this);
				break;
			case('r'):
				this->Pcs[i][j] = new Rook(P, WHITE, this);
				break;
			case('b'):
				this->Pcs[i][j] = new Bishop(P, WHITE, this);
				break;
			case('q'):
				this->Pcs[i][j] = new Queen(P, WHITE, this);
				break;
			case('K'):
				this->Pcs[i][j] = new King(P, BLACK, this);
				break;
			case('P'):
				this->Pcs[i][j] = new Pawn(P, BLACK, this);
				break;
			case('H'):
				this->Pcs[i][j] = new Knight(P, BLACK, this);
				break;
			case('R'):
				this->Pcs[i][j] = new Rook(P, BLACK, this);
				break;
			case('B'):
				this->Pcs[i][j] = new Bishop(P, BLACK, this);
				break;
			case('Q'):
				this->Pcs[i][j] = new Queen(P, BLACK, this);
				break;
			case('-'):
				this->Pcs[i][j] = nullptr;
				break;
			default:
				break;
			}
		}
	}
}



Board::Board(const Board& B)
{
	//this->deleteMemory();
	this->assign(B);
}
Piece* Board::getPieceAt(int r,int c)const
{
	return Pcs[r][c];
}
void Board::assign(const Board& B1)
{
	this->Pcs = new Piece * *[dimension];
	for (int i = 0; i < dimension; i++)
	{
		this->Pcs[i] = new Piece * [dimension];
	}

	for (int i = 0; i < dimension; i++)
	{
		for (int j = 0; j < dimension; j++)
		{
			if (B1.getPieceAt(i, j) != nullptr)
			{
				Position P;
				P.r = i; P.c = j;
				char key;
				B1.getPieceAt(i, j)->getPieceID(key);

				switch (key)
				{
				case('k'):
					this->Pcs[i][j] = new King(P, WHITE, this);
					break;
				case('p'):
					this->Pcs[i][j] = new Pawn(P, WHITE, this);
					break;
				case('h'):
					this->Pcs[i][j] = new Knight(P, WHITE, this);
					break;
				case('r'):
					this->Pcs[i][j] = new Rook(P, WHITE, this);
					break;
				case('b'):
					this->Pcs[i][j] = new Bishop(P, WHITE, this);
					break;
				case('q'):
					this->Pcs[i][j] = new Queen(P, WHITE, this);
					break;
				case('K'):
					this->Pcs[i][j] = new King(P, BLACK, this);
					break;
				case('P'):
					this->Pcs[i][j] = new Pawn(P, BLACK, this);
					break;
				case('H'):
					this->Pcs[i][j] = new Knight(P, BLACK, this);
					break;
				case('R'):
					this->Pcs[i][j] = new Rook(P, BLACK, this);
					break;
				case('B'):
					this->Pcs[i][j] = new Bishop(P, BLACK, this);
					break;
				case('Q'):
					this->Pcs[i][j] = new Queen(P, BLACK, this);
					break;
				}
			}
			else
				this->Pcs[i][j] = nullptr;
		}
	}
}
void Board::deleteMemory()
{
	for (int i = 0; i < dimension; i++)
	{
		for (int j = 0; j < dimension; j++)
		{
			if(this->Pcs[i][j] != nullptr)
				delete this->Pcs[i][j];
		}
	}
	for (int i = 0; i < dimension; i++)
	{
		delete[]this->Pcs[i];
	}
	delete[]this->Pcs;
}
bool Board::isBishop()
{
	int r, c;
	getRowColbyLeftClick(r, c);
	if ((r > 40 && r<50) && (c > 90 && c < 100))
		return true;
	return false;

	//int r, c;
	//getRowColbyLeftClick(r, c);
	//if (r < 40 && c>90)
	//	return false;
	//else if (r > 50 && c < 80)
	//	return false;
	//return true;
}
bool Board::isKnight()
{
	int r, c;
	getRowColbyLeftClick(r, c);
	if ((r > 50 && r < 60) && (c > 90 && c < 100))
		return true;
	return false;

	/*int r, c;
	getRowColbyLeftClick(r, c);
	if (r < 40 && c>100)
		return false;
	else if (r > 50 && c < 90)
		return false;
	return true;*/
}
bool Board::isRedo()
{
	int r, c;
	getRowColbyLeftClick(r, c);
	if ((r > 20 && r < 30) && (c > 90 && c < 100))
		return true;
	return false;
}
bool Board::isUndo()
{
	int r, c;
	getRowColbyLeftClick(r, c);
	if ((r > 20 && r < 30) && (c > 80 && c < 90))
		return true;
	return false;
}
bool Board::isQueen()
{
	int r, c;
	getRowColbyLeftClick(r, c);
	if ((r > 70 && r < 80) && (c > 90 && c < 100))
		return true;
	return false;

	/*int r, c;
	getRowColbyLeftClick(r, c);
	if (r < 40 && c>120)
		return false;
	else if (r > 50 && c < 110)
		return false;
	return true;*/
}
bool Board::isRook()
{

	int r, c;
	getRowColbyLeftClick(r, c);
	if ((r > 60 && r < 70) && (c > 90 && c < 100))
		return true;
	return false;
	/*int r, c;
	getRowColbyLeftClick(r, c);
	if (r < 40 && c>110)
		return false;
	else if (r > 50 && c < 100)
		return false;
	return true;*/
}
void Board::printBishopButton()
{
	L2R(40, 90, 100);
	L2R(50, 90, 100);
	T2B(90, 40, 50);
	T2B(100, 40, 50);
	gotoRowCol(45, 95);
	cout << "Bish";
}
void Board::printKnightButton()
{
	L2R(50, 90, 100);
	L2R(60, 90, 100);
	T2B(90, 50, 60);
	T2B(100, 50, 60);
	gotoRowCol(55, 95);
	cout << "Kni";
}
void Board::printRookButton()
{
	L2R(60, 90, 100);
	L2R(70, 90, 100);
	T2B(90, 60, 70);
	T2B(100, 60, 70);
	gotoRowCol(65, 95);
	cout << "Rook";

}
void Board::printQueenButton()
{
	L2R(70, 90, 100);
	L2R(80, 90, 100);
	T2B(90, 70, 80);
	T2B(100, 70, 80);
	gotoRowCol(75, 95);
	cout << "Qun";
}
void Board::printUndoButton()
{
	L2R(20, 80, 90);
	L2R(30, 80, 90);
	T2B(80, 20, 30);
	T2B(90, 20, 30);
	gotoRowCol(25, 85);
	cout << "Undo";
}
void Board::printRedoButton()
{
	L2R(20, 90, 100);
	L2R(30, 90, 100);
	T2B(90, 20, 30);
	T2B(100, 20, 30);
	gotoRowCol(25, 95);
	cout << "Redo";
}
void Board::printActionButton()
{
	printUndoButton();
	printRedoButton();
}
void Board::printPromotion()
{
	printBishopButton();
	printRookButton();
	printKnightButton();
	printQueenButton();
}
void Board::pawnToQueen(Position pos,int Turn)
{
	if (Turn == 1)
	{
		delete[]Pcs[pos.r][pos.c];
		Pcs[pos.r][pos.c] = new Queen(pos, BLACK, this);
		
	}
	else
	{
		delete[]Pcs[pos.r][pos.c];
		Pcs[pos.r][pos.c] = new Queen(pos, WHITE, this);
		
	}
}
void Board::pawnToKnight(Position pos, int Turn)
{
	if (Turn == 1)
	{
		delete[]Pcs[pos.r][pos.c];
		Pcs[pos.r][pos.c] = new Knight(pos, BLACK, this);
		
	}
	else
	{
		delete[]Pcs[pos.r][pos.c];
		Pcs[pos.r][pos.c] = new Knight(pos, WHITE, this);
		
	}
}
void Board::pawnToBishop(Position pos, int Turn)
{
	if (Turn == 1)
	{
		delete[]Pcs[pos.r][pos.c];
		Pcs[pos.r][pos.c] = new Bishop(pos, BLACK, this);
		
	}
	else
	{
		delete[]Pcs[pos.r][pos.c];
		Pcs[pos.r][pos.c] = new Bishop(pos, WHITE, this);
		
	}
}
void Board::pawnToRook(Position pos, int Turn)
{
	if (Turn == 1)
	{
		delete[]Pcs[pos.r][pos.c];
		Pcs[pos.r][pos.c] = new Rook(pos, BLACK, this);
		
	}
	else
	{
		delete[]Pcs[pos.r][pos.c];
		Pcs[pos.r][pos.c] = new Rook(pos, WHITE, this);
		
	}
}
void Board::setPiece(Piece* P, Position S)const
{
	Pcs[S.r][S.c] = P;
}
void Board::movePiece(Position S, Position D)
{
	Pcs[D.r][D.c] = Pcs[S.r][S.c];
	Pcs[S.r][S.c] = nullptr;
	
}
void Board::movePiece(Position S, Position D) const
{
	Pcs[D.r][D.c] = Pcs[S.r][S.c];
	Pcs[S.r][S.c] = nullptr;

}
void Board::L2R(int srow,int scol, int ecol)
{
	for (int i = scol; i < ecol; i++)
	{
		gotoRowCol(srow, i);
		cout << char(-37);
	}
}
void Board::T2B(int scol, int srow, int erow)
{
	for (int i = srow; i < erow; i++)
	{
		gotoRowCol(i,scol);
		cout << char(-37);
	}
}
const void Board::compBoard(int sr, int sc)
{
	system("cls");
	//drawBoard();
	prntBound(0,0);
	for (int i = 0; i < dimension; i++)
	{
		for (int j = 0; j < dimension; j++)
		{
			if (Pcs[i][j] == nullptr)
			{
				
			}
			else
			{
				gotoRowCol(sr + i * brows, sr + j * brows);

				Pcs[i][j]->draw(sr + i * brows, sr + j * brows);
			}
		}
		cout << endl;
	}
}
const void Board::drawBoard()
{
	for (int i = 0; i < dimension; i++)
	{
		for (int j = 0; j < dimension; j++)
		{
			if ((i + j) % 2 == 0)
			{
				SetClr(4);
				drawBox(i * brows, j * bcols);
			}
			else
			{
				SetClr(7);
				drawBox(i * brows, j * bcols);
			}
		}
	}
}
const void Board::drawBox(int sr, int sc)
{
	for (int r = 0; r < brows; r++)
	{ 
		for (int c = 0; c < bcols; c++)
		{
			gotoRowCol(sr + r, sc + c);
			cout << char(-37);
		}
	}
}
void Board::prntBound(int sr, int sc)
{
	for (int r = 0; r < dimension; r++)
	{
		for (int c = 0; c < dimension; c++)
		{
			SetClr(14);
			gotoRowCol(sr + r, sc + c);
			doClrBound(sr + r, sc + c);
		}
	}
}
void Board::doClrBound(int r, int c)
{
	r = r * brows + 5;
	c = c * bcols + 5;

	r = (r / bcols) * bcols;
	c = (c / bcols) * bcols;

	for (int i = c; i < c + bcols; i++)
	{
		gotoRowCol(r, i);
		SetClr(2);
		cout << char(-37);
	}
	for (int i = c + bcols - 1, j = r; j < r + bcols; j++)
	{
		gotoRowCol(j, i);
		SetClr(2);
		cout << char(-37);
	}
	for (int i = r + bcols - 1, j = (c + bcols) - 1; j >= c; j--)
	{
		gotoRowCol(i, j);
		SetClr(2);
		cout << char(-37);
	}

	for (int i = (r + bcols) - 1; i >= r; i--)
	{
		gotoRowCol(i, c);
		SetClr(2);
		cout << char(-37);
	}
}
Board::~Board()
{
	this->deleteMemory();
}

