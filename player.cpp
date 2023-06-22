#include <iostream>
#include <string>

#include "player.h"
#include "board.h"
#include "funcAndTemplate.h"

using namespace std;
//konstruktor domyslny
player::player() {
	x = 0;
	y = 0;
	nick = "n\a";
	ileScian = 10;
}
//ustawianie graczy
void player::setPlayer(int number, string name) {
	if (number == 0) {
		x = 8;
		y = 16;
		nick = name;
	}
	else {
		x = 8;
		y = 0;
		nick = name;
	}
	ileScian = 10;
}
//konstruktor domyslny
person::person() :player() {};
//przesuwanie osoby
void person::move(board &b) {
	cout << "u-up,d-down,l-left,r-right" << endl;
	char input = checkInput('a', 'z');

	switch (input) {
	case 'u':
		if (y == 0 || (b.getBox(x, y - 1)) == 'X' || (((b.getBox(x, y - 2)) != 'O') && y == 2)) {
			cout << "ERROR, can't move there" << endl;
			move(b);
			break;
		}
		if ((b.getBox(x, y - 2)) != 'O') {
			y -= 4;
			break;
		}
		y -= 2;
		break;

	case 'd':
		if (y == 16 || (b.getBox(x, y + 1)) == 'X' || (((b.getBox(x, y + 2)) != 'O') && y == 14)) {
			cout << "ERROR, can't move there" << endl;
			move(b);
			break;
		}
		if ((b.getBox(x, y + 2)) != 'O') {
			y += 4;
			break;
		}
		y += 2;
		break;

	case 'l':
		if (x == 0 || (b.getBox(x - 1, y)) == 'X' || (((b.getBox(x - 2, y)) != 'O') && x == 2)) {
			cout << "ERROR, can't move there" << endl;
			move(b);
			break;
		}
		if ((b.getBox(x - 2, y)) != 'O') {
			x -= 4;
			break;
		}
		x -= 2;
		break;

	case 'r':
		if (x == 16 || (b.getBox(x + 1, y)) == 'X' || (((b.getBox(x + 2, y)) != 'O') && x == 14)) {
			cout << "ERROR, can't move there" << endl;
			move(b);
			break;
		}
		if ((b.getBox(x + 2, y)) != 'O') {
			x += 4;
			break;
		}
		x += 2;
		break;

	default:
		cout << "ERROR, put u/d/r/l" << endl;
		move(b);
		break;
	}
}
//stawianie sciany
void person::putWall(board &b) {
	char xS, xE;
	int yS, yE;
	cout << "Put starting point of the wall (char for x and int for y)" << endl;
	while (1) {
		cout << "Start point x:";
		xS = checkInput('a', 'q');

		cout << "Start point y:";
		yS = checkInput(0, 16);

		cout << "End point x:";
		xE = checkInput('a', 'q');

		cout << "End point y:";
		yE = checkInput(0, 16);

		if ((fabs(xE - xS) != 2 && fabs(yE - yS) != 2) || (b.getBox((int)xS - 'a', yS)) != ' ' || (b.getBox(((int)xE - 'a' + (int)xS - 'a') / 2, (yE + yS) / 2)) != ' ' || (b.getBox((int)xE - 'a', yE)) != ' ' || (((int)xS - 'a') % 2 != 0 && yS % 2 != 0)) {
			cout << "Try again:" << endl;
			continue;
		}
		else {
			b.refreshWall(xS, yS, xE, yE);
			ileScian--;
			break;
		}
	}
}
//konstruktor domyslny
computer::computer() :player() {};
//stawianie sciany przez komputer
void computer::putWall(board &b) {
	char xS, xE;
	int yS, yE;
	while (1) {
		xS = chooseRandom('a', 15);
		yS = chooseRandom(0, 15);
		while (((int)xS - 'a') % 2 != 0 && yS % 2 != 0) {
			xS = chooseRandom('a', 15);
			yS = chooseRandom(0, 15);
		}
		if (((int)xS - 'a') % 2 != 0) {
			xE = xS;
			yE = yS + 2;
		}
		else {
			xE = xS + 2;
			yE = yS;
		}
		if ((fabs(xE - xS) != 2 && fabs(yE - yS) != 2) || (b.getBox((int)xS - 'a', yS)) != ' ' || (b.getBox(((int)xE - 'a' + (int)xS - 'a') / 2, (yE + yS) / 2)) != ' ' || (b.getBox((int)xE - 'a', yE)) != ' ') {
			continue;
		}
		else {
			b.refreshWall(xS, yS, xE, yE);
			ileScian--;
			break;
		}
	}
}
//ruszanie sie komputera
void computer::move(board &b) {
	int ran = chooseRandom(0, 101);
	char input;

	if (ran < 79) {
		input = 'd';
	}
	else if (ran < 89) {
		input = 'l';
	}
	else if (ran < 99) {
		input = 'r';
	}
	else {
		input = 'u';
	}

	switch (input) {
	case 'u':
		if (y == 0 || (b.getBox(x, y - 1)) == 'X' || (((b.getBox(x, y - 2)) != 'O') && y == 2)) {
			move(b);
			break;
		}
		if ((b.getBox(x, y - 2)) != 'O') {
			y -= 4;
			break;
		}
		y -= 2;
		break;

	case 'd':
		if (y == 16 || (b.getBox(x, y + 1)) == 'X' || (((b.getBox(x, y + 2)) != 'O') && y == 14)) {
			move(b);
			break;
		}
		if ((b.getBox(x, y + 2)) != 'O') {
			y += 4;
			break;
		}
		y += 2;
		break;

	case 'l':
		if (x == 0 || (b.getBox(x - 1, y)) == 'X' || (((b.getBox(x - 2, y)) != 'O') && x == 2)) {
			move(b);
			break;
		}
		if ((b.getBox(x - 2, y)) != 'O') {
			x -= 4;
			break;
		}
		x -= 2;
		break;

	case 'r':
		if (x == 16 || (b.getBox(x + 1, y)) == 'X' || (((b.getBox(x + 2, y)) != 'O') && x == 14)) {
			move(b);
			break;
		}
		if ((b.getBox(x + 2, y)) != 'O') {
			x += 4;
			break;
		}
		x += 2;
		break;

	default:
		move(b);
		break;
	}
}