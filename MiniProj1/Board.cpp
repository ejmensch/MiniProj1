/*
 * Board.cpp
 *
 *  Created on: Mar 3, 2021
 *      Author: Ethan Mensch, Bryce Leslie
 */
#include "Board.hpp"
#include <iostream>
using namespace std;

Board::Board(char diff, bool d) {
	level = diff;
	debug = d;
	wallStrength = 6;
	InitAll();
}
Board::Board(bool d) {
	level = 'e';
	debug = d;
	wallStrength = 6;
	InitAll();
}
Board::Board(char diff, string name, bool d) {
	level = diff;
	debug = d;
	mydog.name = name;
	wallStrength = 6;
	InitAll();
}
void Board::InitAll() {
	bool keepPlaying = true;
	while (keepPlaying) {
		cout << "What level of difficulty do you want (e, m, or h)?" << endl;
		char c;
		cin >> c;
		level = c;
		cout << "Pick a name for your dog:" <<endl;
		string n;
		cin >> n;
		mydog.name = n;
		startx = rand()%20 +1;
		starty = 1;
		endx = rand()%20 + 1;
		endy = 20;
		mydog.x = startx;
		mydog.y = starty;
		boardConfig();
		addFood();
		addTraps();
		printBoard();
		playGame();
		cout << "Play again? " << endl;
		string s = "no";
		cin >> s;
		if (s == "yes" || s == "Yes" || s == "Y" || s == "y") {
			keepPlaying = true;
			mydog.reset();
		}
		else {
			cout << "Thanks for playing!" << endl;
			keepPlaying = false;
		}
	}
}
void Board::playGame() {
	bool play = true;
	while (play) {
		cout << "Move (u, d, l, r) " << endl;
		char c;
		cin >> c;
		play = moveDog(c);
		printBoard();
	}
}

void Board::addFood() {
	/* (5 pts) code for the addFood method goes here
	 */
	int i,j,x;
	for(i=0; i < 22; i++){
		for(j=0; j < 22; j++){
			if (i > 1 and i < 21) {
				if (j > 1 and j < 21) {
					if (level == 'e') {
						if(i % 2 != 0){
							x=rand()%35;
							if(x==1){
								if (board[i][j] != board[endx][endy]) {
									board[i][j] = 'F';
								}
							}
						}
						if (j % 2 != 0) {
							x = rand()%35;
							if (x == 1) {
								if (board[i][j] != board[endx][endy]) {
									board[i][j] = 'F';
								}
							}
						}
					}
					if (level == 'm') {
						if(i % 2 != 0){
							x=rand()%20;
							if(x==1){
								if (board[i][j] != board[endx][endy]) {
									board[i][j] = 'F';
								}
							}
						}
						if (j % 2 != 0) {
							x = rand()%20;
							if (x == 1) {
								if (board[i][j] != board[endx][endy]) {
									board[i][j] = 'F';
								}
							}
						}
					}
					if (level == 'h') {
						if(i % 2 != 0){
							x=rand()%10;
							if(x==1){
								if (board[i][j] != board[endx][endy]) {
									board[i][j] = 'F';
								}
							}
						}
						if (j % 2 != 0) {
							x = rand()%10;
							if (x == 1) {
								if (board[i][j] != board[endx][endy]) {
									board[i][j] = 'F';
								}
							}
						}
					}
				}
			}

		}
	}
}
void Board::addTraps() {
	/* (5 pts) code for the addTraps method goes here
	 */
	int i,j,x;
	for(i=0; i < 22; i++){
		for(j=0; j < 22; j++){
			if (i > 1 and i < 21) {
				if (j > 1 and j < 21) {
					if (level == 'e') {
						if(i % 2 != 0){
							x=rand()%35;
							if(x==1){
								if (board[i][j] != board[endx][endy]) {
									board[i][j] = 'T';
								}
							}
						}
						if (j % 2 != 0) {
							x = rand()%35;
							if (x == 1) {
								if (board[i][j] != board[endx][endy]) {
									board[i][j] = 'T';
								}
							}
						}
					}
					if (level == 'm') {
						if(i % 2 != 0){
							x=rand()%20;
							if(x==1){
								if (board[i][j] != board[endx][endy]) {
									board[i][j] = 'T';
								}
							}
						}
						if (j % 2 != 0) {
							x = rand()%20;
							if (x == 1) {
								if (board[i][j] != board[endx][endy]) {
									board[i][j] = 'T';
								}
							}
						}
					}
					if (level == 'h') {
						if(i % 2 != 0){
							x=rand()%10;
							if(x==1){
								if (board[i][j] != board[endx][endy]) {
									board[i][j] = 'T';
								}
							}
						}
						if (j % 2 != 0) {
							x = rand()%10;
							if (x == 1) {
								if (board[i][j] != board[endx][endy]) {
									board[i][j] = 'T';
								}
							}
						}
					}
				}
			}

		}
	}
}
void Board::boardConfig() {
	/* (8 pts) code for the boardConfig method goes here
	 */
	int i,j,x;
	for(i=0; i < 22; i++){
		for(j=0; j < 22; j++) {
			board[i][j] = ' ';
			if (board[i][j] != 'D' or board[i][j] != 'E') {
				if (level == 'e') {
					if(i % 5 == 2){
						x=rand()%2;
						if(x==1){
							board[i][j] = '_';
						}
					}

					if (j % 4 == 3) {
						x = rand()%2;
						if (x == 1) {
							x = rand()%2;
							board[i][j] = '|';
						}
					}
				}
				if (level == 'm') {
					if(i % 5 == 2){
						x=rand()%2;
						if(x==1){
							board[i][j] = '_';
						}
					}

					if (j % 3 == 2) {
						x = rand()%2;
						if (x == 1) {
							x = rand()%2;
							board[i][j] = '|';
						}
					}
				}
				if (level == 'h') {
					if(i % 4 == 2){
						x=rand()%2;
						if(x==1){
							board[i][j] = '_';
						}
					}

					if (j % 3 == 2) {
						x = rand()%2;
						if (x == 1) {
							x = rand()%2;
							board[i][j] = '|';
						}
					}

				}
			}
		}
		board[endx][endy]='E';

	}
}
void Board::printBoard() {
	/* (8 pts) code for the printBoard method goes here
	 */
	int i,j;
	for (i = 0; i < size; i++) {
		for (j = 0; j < size; j++) {
			if (i==0) {
				board[i][j] = '_';
			}
			else if (i==21) {
				board[i][j] = '_';
			}
			else if (j==0) {
				board[i][j] = '|';
			}
			else if (j==21) {
				board[i][j] = '|';
			}
			if (board[startx][starty]) {
				board[startx][starty-1] = '>';
			}
			if (board[endx][endy]) {
				board[endx][endy+1] = '>';
			}
			cout << board[i][j] << " ";
			board[mydog.x][mydog.y]='D';
		}
		cout << endl;
	}
}
bool Board::moveDog(char c) {
	board[mydog.x][mydog.y]=' ';
	if (c == 'r') {
		mydog.y++;
		if (board[mydog.x][mydog.y] == '|' || board[mydog.x][mydog.y] == '_'){
			if(mydog.strength >= 6){
				cout<< "Do you want to break through? It'll cost 6 strength (y or n)"<<endl;
				char response;
				cin >> response;

				if (response == 'y'){
					mydog.changeStrength(-4);
				}
				else{
					mydog.y--;
					mydog.changeStrength(2);
				}
			}
			else {
				mydog.y--;
				mydog.changeStrength(2);
				cout<< "You can't break through, you'll kill your dog"<<endl;
			}
		}
		if(mydog.changeStrength(-2)==false){
			return false;
		}
		if(mydog.y==21){
			mydog.y = 20;
			cout<<"You can't exit there! You still lose 6 strength for trying"<<endl;
		}
	}
	if (c == 'l') {
		mydog.y--;
		if (board[mydog.x][mydog.y] == '|' || board[mydog.x][mydog.y] == '_'){
			if(mydog.strength > 6){
				cout<< "Do you want to break through? It'll cost 6 strength (y or n)"<<endl;
				char response;
				cin >> response;

				if (response == 'y'){
					mydog.changeStrength(-4);
				}
				else{
					mydog.y++;
					mydog.changeStrength(2);
				}
			}
			else {
				mydog.y++;
				mydog.changeStrength(2);
				cout<< "You can't break through, you'll kill your dog"<<endl;
			}
		}
		if (mydog.changeStrength(-2) == false) {
			return false;
		}
		if(mydog.y==0){
			mydog.y = 1;
			cout<<"You can't exit there! You still lose 6 strength for trying"<<endl;
		}
	}
	if (c == 'u') {
		mydog.x--;
		if (board[mydog.x][mydog.y] == '|' || board[mydog.x][mydog.y] == '_'){
			if(mydog.strength >= 6){
				cout<< "Do you want to break through? It'll cost 6 strength (y or n)"<<endl;
				char response;
				cin >> response;

				if (response == 'y'){
					mydog.changeStrength(-4);
				}
				else{
					mydog.x++;
					mydog.changeStrength(2);
				}
			}
			else {
				mydog.x++;
				mydog.changeStrength(2);
				cout<< "You can't break through, you'll kill your dog"<<endl;
			}
		}
		if (mydog.changeStrength(-2) == false) {
			return false;
		}
		if(mydog.x==0){
			mydog.x = 1;
			cout<<"You can't exit there! You still lose 6 strength for trying"<<endl;
		}
	}
	if (c == 'd') {
		mydog.x++;
		if (board[mydog.x][mydog.y] == '|' || board[mydog.x][mydog.y] == '_'){
			if(mydog.strength >= 6){
				cout<< "Do you want to break through? It'll cost 6 strength (y or n)"<<endl;
				char response;
				cin >> response;

				if (response == 'y'){
					mydog.changeStrength(-4);
				}
				else{
					mydog.x--;
					mydog.changeStrength(2);
				}
			}
			else {
				mydog.x--;
				mydog.changeStrength(2);
				cout<< "You can't break through, you'll kill your dog"<<endl;
			}
		}
		if (mydog.changeStrength(-2) == false) {
			return false;
		}
		if(mydog.x==21){
			mydog.x = 20;
			cout<<"You can't exit there! You still lose 6 strength for trying"<<endl;
		}
	}
	if (board[mydog.x][mydog.y] == board[endx][endy]) {
		mydog.won();
		return false;
	}
	if (board[mydog.x][mydog.y] == 'F'){
		int f = rand()% 18 + 2;
		mydog.changeStrength(f);
		cout<<"Good stuff dawg, your dog, "<< mydog.name <<", ate some grub and regained some strength"<<endl;
	}
	if (board[mydog.x][mydog.y] == 'T') {
		int t = rand() % 7 + 2;
		if(mydog.changeStrength(-t)== false){
			return false;
		}
		else {
			cout
			<< "Tough luck buddy, you led your dog, "<< mydog.name<<", into a trap and it lost some strength"
			<< endl;
		}
	}

	if (mydog.strength <= 0) {
		mydog.die();
		return false;
	}
	mydog.printDog();
	return true;
}
