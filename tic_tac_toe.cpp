#include "tic_tac_toe.h"

#include <format>
#include <iostream>

using namespace std;

TicTacToe::TicTacToe(int gridSize) {
	this->totalMoves = 0;
	this->gridSize = gridSize;
	this->playerTracker = 1;

	for (int i = 0; i < gridSize; i++) {
		grid.push_back(vector<char>(gridSize, '-'));
	}

	buildOutputText();
}

void TicTacToe::buildOutputText() {
	outputTextMap["qToQuit"] = "Type 'q' at any time to quit";
	outputTextMap["playerSymbol"] = "Player 1 is O and player 2 is X";
	outputTextMap["invalidMove"] = "Invalid move, please enter a valid move: ";
	outputTextMap["IndexDescription"] = "The grid cells are indexed from 1 to 9.";
	outputTextMap["draw"] = "It's a draw! You're both winners and losers.";
}

void TicTacToe::printGrid() {
	for (auto& row : grid) {
		for (auto& cell : row) {
			cout << cell << " ";
		}
		cout << endl << endl;
	}
}

bool TicTacToe::isValidMove(const int& idx) {
	if (grid[idx / 3][idx % 3] == '-') {
		return true;
	} else {
		return false;
	}
}

bool TicTacToe::isGameOver(const int& idx) {
	int row = idx / 3;
	int column = idx % 3;
	char& playerSymbol = playerSymbolMapping[playerTracker];

	// row
	if (grid[row][0] == grid[row][1] && grid[row][1] == grid[row][2]) return true;

	// column
	if (grid[0][column] == grid[1][column] && grid[1][column] == grid[2][column])
		return true;

	// diagonals
	if (diagonalIdxUp.contains(idx) && grid[2][0] == grid[1][1] &&
		grid[1][1] == grid[0][2])
		return true;

	if (diagonalIdxDown.contains(idx) && grid[0][0] == grid[1][1] &&
		grid[1][1] == grid[2][2])
		return true;

	return false;
}

void TicTacToe::startGame() {
	string input;
	int idx;

	cout << outputTextMap["qToQuit"] << endl;
	cout << outputTextMap["playerSymbol"] << endl << endl;

	printGrid();
	while (true) {
		cout << "Player " << playerTracker << "'s move: ";
		cin >> input;

		if (input == "q") {
			cout << "Exited Game" << endl;
			break;
		}

		idx = stoi(input) - 1;
		while (!isValidMove(idx)) {
			cout << outputTextMap["invalidMove"];
			cin >> input;
			idx = stoi(input) - 1;
		}

		totalMoves++;

		// update game state
		grid[idx / 3][idx % 3] = playerSymbolMapping[playerTracker];
		printGrid();

		if (isGameOver(idx)) {
			cout << format("Player {} has won!", playerTracker) << endl;
			break;
		}

		if (totalMoves == gridSize) {
			cout << outputTextMap["draw"] << endl;
		}

		playerTracker = playerTracker == 1 ? 2 : 1;
	}
}