#pragma once
#include <string>

using namespace std;

class Player {

private:
	string playerName;
	int location;
	int money;
public:

	Player();

	Player(string n, int m);

	Player(string n, int m, int l);

	void printPlayer();

	void move();

	int getMoney();

	int getLocation();

	string getName();

	void setMoney(int x);

	void addMoney(int x);

	void setlocation(int x);

	void setName(string x);
};