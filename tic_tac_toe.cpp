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
	
	if ()

	if (diagonalIdx.contains(idx)) {

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
		grid[idx / 3][idx % 3] = playerTracker == 1 ? 'O' : 'X';
		playerTracker = (playerTracker + 1) % 3;

		if (playerTracker == 0) playerTracker++;


		if (isGameOver(idx)) {
			break;
		}



	}
}