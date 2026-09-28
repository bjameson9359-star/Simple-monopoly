

#pragma once

#include <iostream>
#include <vector>
#pragma once
#include <string>
#include "Player.h"
using namespace std;



class Board {


private:
	string placeName;
	// fuction elements
	int price;
	vector<int> rent;
	Player* owner;
	int level;
	// linked list elements
	static Board* first;
	static Board* last;
	Board* nextspot;


public:
	static Player* joe;

	Board ();

	Board(string n, int cost, vector<int> payments);

	void changenextspot(Board* newnextspot);

	static Board* navigate(int spot);

	static void createFirst(string n, int cost, vector<int> payments);

	static void addElement(string n, int cost, vector<int> payments);

	string getplaceName();

	Board* getnextspot();

	void setnextspot(Board* x);

	int getPrice();

	Player* getOwner();

	int getLevel();

	void setPrice(int x);

	void setOwner(Player* x);

	void setLevel(int x);

	int getRent();
};

