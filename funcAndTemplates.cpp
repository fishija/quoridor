#include "funcAndTemplate.h"
#include <fstream>
#include <string>
#include <iostream>
#include <climits>
#include <cstdlib>

using namespace std;
//wypisywanie menu
void mainMenu() {
	cout << "Menu:" << endl;
	cout << "1.Player vs PC" << endl;
	cout << "2.Player vs Player" << endl;
	cout << "3.Show player's games" << endl;
	cout << "4.Exit game." << endl;
	cout << "wpisz [1-4]:" << endl;
}
//czyszczenie bufora
void clearForCin() {
	cin.clear();
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
//losowanie liczb
int chooseRandom(int od, int ile) {
	int x = rand() % ile + od;
	return x;
}
//zapisz wynik gry
void saveResult(string nick1, string nick2, int round, int wallsP1, int wallsP2, int howEnded, int who) {
	string nameData1 = nick1 + ".txt";
	string nameData2 = nick2 + ".txt";
	std::ofstream data1(nameData1, ios::app);
	std::ofstream data2(nameData2, ios::app);

	string end;
	if (howEnded) {
		end = "EXIT";
	}
	else {
		end = "Win";
	}
	if (who) {
		data1 << nick1 << " " << wallsP1 << " Walls left" << endl;
		data1 << nick2 << " " << wallsP2 << " Walls left" << endl;
		data1 << "Round " << round << ": " << nick2 << " " << end << endl;
		data1 << "------------------------------" << endl;
		data2 << nick1 << " " << wallsP1 << " Walls left" << endl;
		data2 << nick2 << " " << wallsP2 << " Walls left" << endl;
		data2 << "Round " << round << ": " << nick2 << " " << end << endl;
		data2 << "------------------------------" << endl;
	}
	else {
		data1 << nick1 << " " << wallsP1 << " Walls left" << endl;
		data1 << nick2 << " " << wallsP2 << " Walls left" << endl;
		data1 << "Round " << round << ": " << nick1 << " " << end << endl;
		data1 << "------------------------------" << endl;
		data2 << nick1 << " " << wallsP1 << " Walls left" << endl;
		data2 << nick2 << " " << wallsP2 << " Walls left" << endl;
		data2 << "Round " << round << ": " << nick1 << " " << end << endl;
		data2 << "------------------------------" << endl;
	}
}

