#pragma once

#include <vector>
#include <string>
#include <set>
#include <unordered_map>

using namespace std;

class TicTacToe {
private:
	int totalMoves;
	int gridSize;
	int playerTracker;
	bool isValidMove(const int& idx);
	bool isGameOver(const int& idx);
	vector<vector<char>> grid;
	set<int> diagonalIdxUp { 2, 6 };
	set<int> diagonalIdxDown { 0, 8 };
	unordered_map <int, char> playerSymbolMapping { { 1, 'O' }, { 2, 'X' } };

public:
	TicTacToe(int gridSize = 3);
	// void resetGrid();
	void printGrid();
	void startGame();
};