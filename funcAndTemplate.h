#ifndef funcAndTemplates_h
#define funcAndTemplates_h

#include <iostream>
using namespace std;

void clearForCin();

void mainMenu();

int chooseRandom(int, int);

void saveResult(string nick1, string nick2, int round, int wallsP1, int wallsP2, int howEnded, int who);

template <typename T>
T checkInput(T min, T max) {
	if (typeid(T) == typeid(char)) {
		char input;
		while (!(cin >> input) || input<min || input>max || getchar() != '\n') {
			cout << "ERROR, try again:" << endl;
			clearForCin();
		}
		return input;
	}
	else {
		int a;
		while (!(cin >> a) || a<min || a>max || getchar() != '\n') {
			cout << "ERROR, try again:" << endl;
			clearForCin();
		}
		return a;
	}
}

#endif /* funcAndTemplates_h*/