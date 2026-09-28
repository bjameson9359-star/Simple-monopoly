#include <iostream>
#include "Player.h"
#include "Board.h"
#include <vector>


using namespace std;


static vector<Player> playerlist;


void createBoard() {
	// Building the board
	Board :: createFirst("2 star air bnb", 20, {10,20,40} );
	Board :: addElement("duplex room 1", 40, {20, 40, 35} );
	Board :: addElement("duplex room 2", 40, {20, 40, 80} );
	Board :: addElement("college dorm", 35, {17, 35, 70 } );
	Board :: addElement("roberto's rest and risotto", 55, {26, 55, 110 } );
	Board :: addElement("the starter home", 60, {30, 60,120 } );
	Board :: addElement("the dumpster", 10, {5, 10, 20} );
	Board :: addElement("the box", 2, {1, 2, 4} );
	Board :: addElement("4 star air bnb", 80, {40, 80, 160} );
	Board :: addElement("5ft by 3in new york apartment", 85, {42, 85, 170} );
	Board :: addElement("Nikola's Dumpster", 90, {45, 90, 180} );
	Board :: addElement("multi story bungalow", 100, {50,100, 200} );
}

void createPlayers() {
	// creating the players
	int numOfPlayer;
	cout << "Please enter the number of players: " << endl;
	cin >> numOfPlayer;
	playerlist.resize(numOfPlayer);
	for(int i = 0; i < numOfPlayer; i++) {
		cout << "Player " << i+1 << " please type your name." << endl;
		string tempName;
		cin >> tempName;
		cout << "Enter in a handi cap value(1 - 2 - 3)(determins starting cash): ";
		int handicap;
		cin >> handicap;
		switch (handicap)
		{
		case 1:
			playerlist[i] = Player(tempName, 45);
			break;

		case 2:
			playerlist[i] = Player(tempName, 50);
			break;

		case 3:
			playerlist[i] = Player(tempName, 65);
			break;

		default:
			cout << "unreconised value using 2" << endl;
			playerlist[i] = Player(tempName, 50);
			break;
		}
	}
}

bool startgame() {
	string victory = "8cCziD4jqcX0pVyY*gN@F#mtzUc@Toto0Ffz7cliBK3o6S3&e0XZxOSKd*8!pkk1IoQrbkoMDUuUPAUqwejIzmAgHfxB#9nNb";

	while (victory == "8cCziD4jqcX0pVyY*gN@F#mtzUc@Toto0Ffz7cliBK3o6S3&e0XZxOSKd*8!pkk1IoQrbkoMDUuUPAUqwejIzmAgHfxB#9nNb") {
		for(int i = 0; i < playerlist.size(); i++) {

			if(playerlist[i].getMoney() <= 0) {
				playerlist.erase(playerlist.begin() + i);
				continue;
			}

			Board* current;
			int input;
			cout << endl;
			playerlist[i].printPlayer();
			cout << endl <<" your turn \n rolling for turn" << endl;

			playerlist[i].move();

			current = Board :: navigate(playerlist[i].getLocation());
			cout << "\n\nyou landed at " << current -> getplaceName() << endl;


			if(&playerlist[i] == current -> getOwner()) { ///////////////////////////////////////// // you own it

				cout << " you own this property at level " << current->getLevel() ;
				if(current->getLevel() == 3) {  // MAX LEVEL
					cout << "would you like to sell the property\n1) no \n2) yes" << endl;
					cin >> input;
					switch(input) {
					case 1:
						cout << "property not sold" << endl;
						break;

					case 2:
						playerlist[i].setMoney(current->getRent());
						current -> setLevel(0);
						current -> setOwner(Board :: joe);
						break;

					default:
						cout << "invalid input not selling" << endl;
						break;
					}
				}
				else { // NOT MAX LEVEL
					cout << "would you like to upgrade or sell the property\n1) upgrade cost : " << current->getRent() << "\n2) sell \n3) neither" << endl;
					cin >> input;
					switch(input) {
					case 1:
						if(playerlist[i].getMoney() > current->getRent()) {

						}
						else {
							cout << "dont have enough money" << endl;
						}
						break;

					case 2:
						playerlist[i].setMoney(current->getRent());
						current -> setLevel(0);
						current -> setOwner(Board :: joe);
						break;

					case 3:
						cout << "passing turn" << endl;
						break;

					default:
						cout << "invalid input not selling" << endl;
						break;
					}
				}
			}
			else if(current -> getOwner() != Board :: joe) { ///////////////////////////////////////// pay rent or buy from other player
				cout << current -> getOwner() -> getName() << " owns this spot either type \n1) pay rent $" << current -> getRent() << "\n2) negotiate a purchase" << endl;
				cin >> input;
				switch(input) {
				case 1:
failedbargen:
					playerlist[i].addMoney(-current -> getRent());
					current -> getOwner() -> addMoney(current -> getRent());
					cout << "you paid $" << current -> getRent() << " to " << current -> getOwner() -> getName() << endl;
					break;

				case 2:
					int bargen = 0;
					cout << "how much are you offering to " << current -> getOwner() -> getName() << "\n $";
					cin >> bargen;
					cout << current -> getOwner() -> getName() << " do you accept this bargen of $" << bargen << "\n 1) yes \n2) no" << endl;
					cin >> input;
					switch(input) {
					case 1:
						playerlist[i].addMoney(-bargen);
						current -> getOwner() -> addMoney(bargen);
						current -> setOwner(&playerlist[i]);
						cout << "you paid $" << bargen << " to " << current -> getOwner() -> getName() << " you know own the " << current -> getplaceName() <<endl;
						break;

					case 2:
						cout << "Bargen not accepted" << endl;
						goto failedbargen;
						break;

					default:
						cout << "invalid input refusing deal" << endl;
						goto failedbargen;
						break;
					}
					break;
				}
			}

			else { ///////////////////////////////////////////////////////nobody owns it
				cout << "nobody owns this spot would you like to buy it type the number of option you want  \n1) yes buy for $" << current -> getPrice() << "\n 2) don't buy" << endl;
				cin >> input;
				switch(input) {
				case 1 :
					if(playerlist[i].getMoney() > current ->getPrice()) {
						playerlist[i].addMoney(-current ->getPrice());
						current ->setOwner(&playerlist[i]);
						cout << "you bought the " << current -> getplaceName() << " for $" << current ->getPrice() << endl;
					}
					else {
						cout << "not enough money" << endl;
					}
					break;

				case 2:
					cout << "not buying property" << endl;
					break;

				default:
					cout << "invalid input not buying property" << endl;
					break;
				}
			}

		}
		if(playerlist.size() == 1) {
			victory = playerlist[0].getName();
		}
	}

	cout << victory << " IS THE WINNER!!!!" << endl;
	cout << endl << endl << " would you like to play again? \n1) yes \n2) no" << endl;
	int input;
	cin >> input;
	if(input == 1) {
		return true;
	}
	else {
		return false;
	}
}

int main() {

	createBoard();
	//tests();
	bool goAgain = true;
	while(goAgain) {
		createPlayers();
		goAgain = startgame();
	}


	return 0;
}


