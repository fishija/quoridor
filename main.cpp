//
//  main.cpp
//  QuorTest
//
//  Created by Jakub Miku³a on 13/05/2020.
//  Copyright © 2020 Jakub Miku³a. All rights reserved.
//

#include <fstream>
#include <string>
#include <ctime>

#include "player.h"
#include "board.h"
#include "funcAndTemplate.h"

#define r 17

using namespace std;

void game(int mode) {
	board b;
	string nick[2];
	int round = 0;
	int what = 0;
	player *player[2] = { NULL };

	//sprawdzanie jakich graczy stworzyc i tworzenie ich
	player[0] = new person;
	switch (mode) {
	case 1:
		player[1] = new computer;

		cout << "Podaj nick:" << endl;
		while (!(cin >> nick[0]) || getchar() != '\n') {
			cout << "ERROR, try again:" << endl;
			clearForCin();
		}
		nick[1] = "PC";
		system("cls");
		break;
	case 2:
		player[1] = new person;
		for (int i = 0; i < 2; i++) {
			cout << "Podaj " << (i + 1) << " nick:" << endl;
			while (!(cin >> nick[i]) || getchar() != '\n') {
				cout << "ERROR, try again:" << endl;
				clearForCin();
			}
		}
		system("cls");
		break;
	}

	for (int i = 0; i < 2; i++) {
		player[i]->setPlayer(i, nick[i]);
	}

	for (int i = 0; i < 2; i++) {
		b.addPlayer(player[i]->getX(), player[i]->getY(), i);
	}

	//petla gry
	while ((b.checkIfWin(player[0]->getY(), player[1]->getY())) == 0) {
		if (what == 3) {
			break;
		}
		for (int i = 0; i < 2; i++) {
			if (mode == 1 && i == 0 || mode == 2) {
				switch (i) {
				case 0:
					cout << "Players " << nick[i] << "(Y) move" << endl;
					break;
				case 1:
					cout << "Players " << nick[i] << "(Z) move" << endl;
					break;
				}
				cout << nick[0] << " " << player[0]->getIleScian() << " walls" << endl;
				cout << nick[1] << " " << player[1]->getIleScian() << " walls" << endl << endl;
				b.print();
			
				if (player[i]->getIleScian() != 0) {
					cout << "1-move,2-put wall,3-exit game" << endl;
					what = checkInput(1, 3);
				}
				else {
					cout << "1-move,3-exit game" << endl;
					while (!(cin >> what) || (what != 1 && what != 3)) {
						cout << "ERROR, try again:";
						clearForCin();
					}
				}
			}
			round++;
			if (mode == 1 && i == 1) {
				while (1) {
					int x = chooseRandom(0, 100);
					if (x < 50) {
						player[i]->move(b);
						break;
					}
					else if (player[i]->getIleScian() != 0) {
						player[i]->putWall(b);
						break;
					}
				}
				system("cls");
			}
			else if (what == 1) {
				player[i]->move(b);
				system("cls");
			}
			else if (what == 2) {
				player[i]->putWall(b);
				system("cls");
			}
			else {
				saveResult(nick[0], nick[1], round, player[0]->getIleScian(), player[1]->getIleScian(), 1, i);
				system("cls");
				break;
			}

			b.refreshPlayer(player[i]->getX(), player[i]->getY(), i);

			if (b.checkIfWin(player[0]->getY(), player[1]->getY())) {
				saveResult(nick[0], nick[1], round, player[0]->getIleScian(), player[1]->getIleScian(), 0, i);
				cout << "WIN! Player " << nick[i] << endl;
				b.print();
				cout << "Press Enter to Continue";
				cin.ignore();
				system("cls");
				break;
			}
		}
	}
	delete player[0];
	delete player[1];
}

int main(int argc, const char * argv[]) {
	int w = 1;
	srand(time(NULL));

	cout << "QUORIDOR" << endl << endl;
	//Petla programu
	while (w) {
		mainMenu();
		w = checkInput(1, 4);
		if (w == 1 || w == 2) {
			system("cls");
			game(w);
			continue;
		}
		else if (w == 3) {
			system("cls");
			cout << "Enter nick:" << endl;
			string nick;

			while (!(cin >> nick) || getchar() != '\n') {
				cout << "ERROR, try again:" << endl;
				clearForCin();
			}
			system("cls");
			nick += ".txt";
			ifstream data(nick);

			if (!data) {
				cout << "NO DATA" << endl;
			}
			string text;
			while (getline(data, text)) {
				cout << text << endl;
			}
			cout << "Press Enter to Continue";
			cin.ignore();
			system("cls");
			continue;
		}
		else {
			break;
		}
	}
	return 0;
}