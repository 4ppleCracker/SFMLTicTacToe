#include "stdafx.h"
#include "Game.h"
#include <iostream>

class Game::board {
public:
	//char** Matrix;
	char Matrix[3][3];
	int Height = 3;
	int Width = 3;
	board() {
		for (int i = 0; i < this->Height; i++) {
			for (int k = 0; k < this->Height; k++) {
				this->Matrix[i][k] = '-';
			}
		}
	}

	char Place(int x, int y, char Player) {
		if (this->Matrix[x][y] != 'X' && this->Matrix[x][y] != 'O') {
			this->Matrix[x][y] = Player;
		}
		else {
			return 'u';
		}
		if (
			(this->Matrix[0][0] == this->Matrix[0][1] && this->Matrix[0][0] == this->Matrix[0][2] && (this->Matrix[0][0] == 'X' || this->Matrix[0][0] == 'O')) || // top row        //
			(this->Matrix[1][0] == this->Matrix[1][1] && this->Matrix[1][0] == this->Matrix[1][2] && (this->Matrix[1][0] == 'X' || this->Matrix[1][0] == 'O')) || // middle row    //  Horizontal 
			(this->Matrix[2][0] == this->Matrix[2][1] && this->Matrix[2][0] == this->Matrix[2][2] && (this->Matrix[2][0] == 'X' || this->Matrix[2][0] == 'O')) || // bottom row   //

			(this->Matrix[0][0] == this->Matrix[1][0] && this->Matrix[0][0] == this->Matrix[2][0] && (this->Matrix[0][0] == 'X' || this->Matrix[0][0] == 'O')) || // left row     //
			(this->Matrix[0][1] == this->Matrix[1][1] && this->Matrix[0][1] == this->Matrix[2][1] && (this->Matrix[0][1] == 'X' || this->Matrix[0][1] == 'O')) || // middle row  //  Vertical 
			(this->Matrix[0][2] == this->Matrix[1][2] && this->Matrix[0][2] == this->Matrix[2][2] && (this->Matrix[0][2] == 'X' || this->Matrix[0][2] == 'O')) || // right row  //  

			(this->Matrix[0][0] == this->Matrix[1][1] && this->Matrix[0][0] == this->Matrix[2][2] && (this->Matrix[0][0] == 'X' || this->Matrix[0][0] == 'O')) || // Diagonal top-left > bottom-right
			(this->Matrix[2][0] == this->Matrix[1][1] && this->Matrix[2][0] == this->Matrix[0][2] && (this->Matrix[2][0] == 'X' || this->Matrix[2][0] == 'O')) // Diagonal bottom-left > top-right
			) return Player;
		else return '-';
		// TODO: Make it able to tie
		// Is every slot filled?
		for (int i = 0; i < this->Height; i++) {
			for (int k = 0; k < this->Height; k++) {
				this->Matrix[i][k]; // TODO
			}
		}


	}
	char TellMe(int x, int y) {
		return this->Matrix[x][y];
	}
};

Game::Game(int w, int h) {
	this->IsOnResetScreen = false;
	this->HasWon = '-';
	this->Board = new board;
}

void Game::NewGame(int w, int h) {
	this->IsOnResetScreen = false;
	this->HasWon = '-';
	delete this->Board;
	this->Board = new board;
}

char** Game::GetBoardMatrix() {
	//return this->Board->Matrix;
	return new char*[3];
}

char Game::Place(int x, int y, char Player)
{
	char t = this->Board->Place(x, y, Player);
	if (t == 'O' || t == 'X') this->HasWon = t;
	return t;
}

char Game::GetPlayerAtBoardPosition(int x, int y)
{
	char t = this->Board->TellMe(x, y);
	if (t == 'X' || t == 'O') {
		return this->Board->TellMe(x, y);
	}
	else {
		return '-';
	}
}

char Game::GetHasWon()
{
	if (this->HasWon == 'X' || this->HasWon == 'O') {
		this->IsOnResetScreen = true;
	}
	return this->HasWon;
}

char Game::GetIsOnReset() {
	return this->IsOnResetScreen;
}
