#include <iostream>
#include "Board.h"
#include "Player.h"

using namespace std;




string playerName;
int location;
int money;

Player :: Player() {
	playerName = "nobody";
	location = 0;
	money = 20;
}

Player :: Player(string n, int m) {
	playerName = n;
	location = 0;
	money = m;
}

Player :: Player(string n, int m, int l) {
	playerName = n;
	location = l;
	money = m;
}

void Player :: printPlayer() {
	cout << playerName << ":\n" << "location: " << Board :: navigate(location)->getplaceName() << "\n" << "money: $" << money << endl;
}

void Player :: move() {
	int newLocation = (location + 1 + (rand() % 6 )) % 12;
	if(newLocation >= location) {
		cout << "you pass go collect 15";
		money += 15;
	}
	location = newLocation;
}

int Player :: getMoney() {
	return money;
}

int Player :: getLocation() {
	return location;
}

string Player :: getName() {
	return playerName;
}

void Player :: setMoney(int x) {
	money = x;
}

void Player :: addMoney(int x) {
	money += x;
}
void Player :: setlocation(int x) {
	location = x;
}

void Player :: setName(string x) {
	playerName = x;
}

