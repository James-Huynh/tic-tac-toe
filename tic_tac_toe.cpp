#include "tic_tac_toe.h"
#include <iostream>
#include <format>

using namespace std;

TicTacToe::TicTacToe(int gridSize) {
	this->totalMoves = 0;
	this->gridSize = gridSize;
	this->playerTracker = 1;

	for (int i = 0; i < gridSize; i++) {
		grid.push_back(vector<char>(gridSize, '-'));
	}
}

void TicTacToe::printGrid() {
	for (auto row : grid) {
		for (auto val : row) {
			cout << val << " ";
		}
		cout << endl << endl;
	}
}

bool TicTacToe::isValidMove(int idx) {
	if (grid[idx / 3][idx % 3] == '-') {
		return true;
	}
	else {
		return false;
	}
}

bool TicTacToe::isGameOver(int idx) {
	// todo
	int row = idx / 3;
	int column = idx % 3;
	char& playerSymbol = playerSymbolMapping[playerTracker];

	// row
	if (grid[row][0] == grid[row][1] == grid[row][2])
		return true;

	// column
	if (grid[0][column] == grid[1][column] == grid[2][column])
		return true;

	// diagonal
	if (diagonalIdx.contains(idx)) {
		if (grid[0][0] == grid[1][1] == grid[2][2] || grid[2][0] == grid[1][1] == grid[0][2])
			return true;
	}

	return false;
}

void TicTacToe::startGame() {
	string input;

	cout << "Type 'q' at any time to quit" << endl;
	cout << "Player 1 is O and player 2 is X" << endl << endl;

	while (true) {
		printGrid();
		cout << "Player " << playerTracker << "'s move: ";
		cin >> input;

		if (input == "q") {
			cout << "Exited Game" << endl;
			break;
		}

		while (!isValidMove(stoi(input) - 1)) {
			cout << "Invalid move, please enter a valid move: ";
			cin >> input;
		}
		totalMoves++;

		int idx = stoi(input) - 1;

		// update game state
		grid[idx / 3][idx % 3] = playerSymbolMapping[playerTracker];
		playerTracker = playerTracker == 1 ? 2 : 1;

		if (isGameOver(idx)) {
			cout << format("Player {} has won!", playerTracker);
			break;
		}



	}
}