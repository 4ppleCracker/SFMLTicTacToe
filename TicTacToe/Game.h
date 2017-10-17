#pragma once
class Game
{
private:
	class board;
	board *Board;
	char HasWon;
	bool IsOnResetScreen;
public:
	Game(int w, int h);
	void NewGame(int w, int h);
	char** GetBoardMatrix();
	char Place(int x, int y, char Player);
	char GetPlayerAtBoardPosition(int x, int y);
	char GetHasWon();
	char GetIsOnReset();
};

