#include <iostream>

#include "board.h"

using namespace std;
//Konstruktor domyslny zapisujacy plansze
board::board() {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < r; j++) {
			if (i % 2 == 0 && j % 2 == 0) {
				box[i][j] = 'O';
			}
			else {
				box[i][j] = ' ';
			}
		}
	}
}
//dodawanie gracza do planszy
void board::addPlayer(int x, int y, int nr) {
	if (nr == 0) {
		box[y][x] = 'Y';
	}
	else {
		box[y][x] = 'Z';
	}
}
//przesuwanie pionka
void board::refreshPlayer(int x, int y, int nr) {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < r; j++) {
			if (nr == 0) {
				if (box[i][j] == 'Y' && (i != y || j != x)) {
					box[i][j] = 'O';
					box[y][x] = 'Y';
				}
			}
			else {
				if (box[i][j] == 'Z' && (i != y || j != x)) {
					box[i][j] = 'O';
					box[y][x] = 'Z';
				}
			}
		}
	}
}
//odswiezanie scian
void board::refreshWall(char xS, int yS, char xF, int yF) {
	box[yS][(int)xS - 'a'] = 'X';
	box[yF][(int)xF - 'a'] = 'X';
	box[(yF + yS) / 2][((int)xF - 'a' + (int)xS - 'a') / 2] = 'X';
}
//wypisywanie planszy
void board::print() {
	char x = 'a';
	int y = 0;
	cout << "   ";
	for (int i = 0; i < r; i++) {
		cout.width(2);
		cout << x++;
	}
	cout << endl;
	for (int i = 0; i < r; i++) {
		cout.width(3);
		cout << y++ << '|';
		for (int j = 0; j < r; j++) {
			cout << box[i][j];
			cout << " ";
		}
		cout << endl;
	}
}
//sprawdzanie czy ktos wygral
int board::checkIfWin(int y0, int y1) {
	if (y0 == 0 || y1 == 16) {
		return 1;
	}
	return 0;
}