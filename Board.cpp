#include <iostream>
#include <vector>
#include "Player.h"
#include "Board.h"
using namespace std;

Board* Board :: first;
Board* Board :: last;
Player* Board :: joe = new Player();

// fuction elements
string  placeName;
int  price;
vector<int>  rent;
Player* owner;
int level;

// linked list elements

Board* nextspot;

Board :: Board () {
	placeName = "default";
	price = 1000000000;
	rent = {1,2,3};
	owner = joe;
	level = 1;
}


Board :: Board(string n, int cost, vector<int> payments) {
	placeName = n;
	price = cost;
	rent = payments;
	owner = joe;
	nextspot = first;
	level = 1;
}

void changenextspot(Board* newnextspot) {
	nextspot = newnextspot;
}



Board* Board :: navigate(int spot) {
	Board* current = first;
	for(int i = 0; i < spot; i++) {
		current = current->getnextspot();
	}
	return current;
}


void Board :: createFirst(string n, int cost, vector<int> payments) {
	first = new Board(n, cost, payments);
	last = first;
}

void Board :: addElement(string n, int cost, vector<int> payments) {
	Board* addition = new Board(n, cost, payments);
	last -> setnextspot(addition);
	last = addition;
}

string Board :: getplaceName() {
	return placeName;
}

Board* Board ::  getnextspot() {
	return nextspot;
}

void  Board :: setnextspot(Board* x) {
	nextspot = x;
}

int Board:: getPrice() {
	return price;
}

Player* Board:: getOwner() {
	return owner;
}

int Board::  getLevel() {
	return level;
}

void Board:: setPrice(int x) {
	price = x;
}

void Board:: setOwner(Player* x) {
	owner = x;
}

void Board:: setLevel(int x) {
	level = x + 1;
}

int Board:: getRent() {
	return rent[level];
}



