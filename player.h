#ifndef player_h
#define player_h

#include <iostream>
#include "board.h"

using namespace std;

class player {
protected:
	int x;
	int y;
	int ileScian;
	string nick;

public:
	player();

	int getIleScian() { return ileScian; };
	int getX() { return x; };
	int getY() { return y; };
	void setPlayer(int, string);

	virtual void move(board &b) = 0;
	virtual void putWall(board &b) = 0;
};

class person :public player {
public:
	person();

	virtual void move(board &b);
	virtual void putWall(board &b);
};

class computer :public player {
public:
	computer();

	virtual void move(board &b);
	virtual void putWall(board &b);
};



#endif /* player_h*/
