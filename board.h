#ifndef board_h
#define board_h

#define r 17

class board {
	friend class player;
	friend class gameSys;

	char box[r][r];

public:
	board();

	void addPlayer(int, int, int);
	void refreshPlayer(int, int, int);
	void refreshWall(char, int, char, int);
	void print();
	char getBox(int x, int y) { return box[y][x]; };
	int checkIfWin(int, int);
};

#endif /* board_h*/