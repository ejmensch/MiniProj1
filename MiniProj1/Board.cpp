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
	//bool keepPlaying = true;
	//while (keepPlaying) {
		//cout << "What level of difficulty do you want (e, m, or h)?" << endl;
		//char c;
		//cin >> c;
		//level = c;
		startx = rand()%20 +1;
		starty = 1;
		endx = rand()%20 + 1;
		endy = 20;
		mydog.x = startx;
		mydog.y = starty;
		//mydog.printDog();  //EM - i added this to test if it works for 7d.
		//mydog.die();  //same as above
		//mydog.won();  //same as above
		boardConfig();
		addFood();
		addTraps();
		printBoard();
		//playGame();
		//cout << "Play again? " << endl;
		//string s = "no";
		//cin >> s;
		//if (s == "yes" || s == "Yes" || s == "Y" || s == "y") {
			//keepPlaying = true;
			//mydog.reset();
		//}
		//else {
			//cout << "Thanks for playing!" << endl;
			//keepPlaying = false;
		//}
	//}
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
							x=rand()%8;
							if(x==1){
								x=rand()%8;
								if(x==1){
									if (board[i][j] != board[endx][endy]) {
										board[i][j] = 'T';
									}
								}
							}
						}
						if (j % 2 != 0) {
							x = rand() % 8;
							if (x == 1) {
								x = rand()%8;
								if (x == 1) {
									if (board[i][j] != board[endx][endy]) {
										board[i][j] = 'F';
									}
								}
							}
						}
					}
					if (level == 'm') {
						if(i % 2 != 0){
							x=rand()%6;
							if(x==1){
								x=rand()%6;
								if(x==1){
									if (board[i][j] != board[endx][endy]) {
										board[i][j] = 'F';
									}
								}
							}
						}
						if (j % 2 != 0) {
							x = rand() % 6;
							if (x == 1) {
								x = rand()%6;
								if (x == 1) {
									if (board[i][j] != board[endx][endy]) {
										board[i][j] = 'F';
									}
								}
							}
						}
					}
					if (level == 'h') {
						if(i % 2 != 0){
							x=rand()%5;
							if(x==1){
								x=rand()%5;
								if(x==1){
									if (board[i][j] != board[endx][endy]) {
										board[i][j] = 'F';
									}
								}
							}
						}
						if (j % 2 != 0) {
							x = rand() % 5;
							if (x == 1) {
								x = rand()%5;
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
							x=rand()%8;
							if(x==1){
								x=rand()%8;
								if(x==1){
									if (board[i][j] != board[endx][endy]) {
										board[i][j] = 'T';
									}
								}
							}
						}
						if (j % 2 != 0) {
							x = rand() % 8;
							if (x == 1) {
								x = rand()%8;
								if (x == 1) {
									if (board[i][j] != board[endx][endy]) {
										board[i][j] = 'T';
									}
								}
							}
						}
					}
					if (level == 'm') {
						if(i % 2 != 0){
							x=rand()%6;
							if(x==1){
								x=rand()%6;
								if(x==1){
									if (board[i][j] != board[endx][endy]) {
										board[i][j] = 'T';
									}
								}
							}
						}
						if (j % 2 != 0) {
							x = rand() % 6;
							if (x == 1) {
								x = rand()%6;
								if (x == 1) {
									if (board[i][j] != board[endx][endy]) {
										board[i][j] = 'T';
									}
								}
							}
						}
					}
					if (level == 'h') {
						if(i % 2 != 0){
							x=rand()%5;
							if(x==1){
								x=rand()%5;
								if(x==1){
									if (board[i][j] != board[endx][endy]) {
										board[i][j] = 'T';
									}
								}
							}
						}
						if (j % 2 != 0) {
							x = rand() % 5;
							if (x == 1) {
								x = rand()%5;
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
}
void Board::boardConfig() {
	/* (8 pts) code for the boardConfig method goes here
	 */
	int i,j,x;   //i is row , j is column... we can change that later
	for(i=0; i < 22; i++){
		for(j=0; j < 22; j++) {
			board[i][j] = ' ';
			if (board[i][j] != 'D' or board[i][j] != 'E') {
				if(i % 2 != 0){
					x=rand()%2;
					if(x==1){
						x=rand()%2;
						if(x==1){
							board[i][j] = '_';
						}
						if(x==0){
							board[i][j] = '|';
						}
					}
				}
				if (j % 2 != 0) {
					x = rand() % 2;
					if (x == 1) {
						x = rand() % 2;
						if (x == 1) {
							board[i][j] = '_';
						}
						if (x == 0) {
							board[i][j] = '|';
						}
					}
				}
			}
		}

			board[startx][starty]='D';//gotta put wall restrictions in cuz they could overlap doggo
			// Added wall restrictions, doggo safe for the first round - BL
			board[endx][endy]='E';

	}
}




	/*for(j=-1; j<size; j++){ //top/bottom borders *put these in print board later and figure out how to make them a border*
		board[0][j]='_';
		board[19][j]='_';
	}
	for(i=0;i<size;i++){ //side borders *same thing I said above-EM*
		board[i][0]='|';
		board[i][19]='|';
	}*/
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
			if (board[startx][starty] == board[i][j+1] or board[endx][endy] == board[i][j-1]) {
				board[i][j] = '-';
				cout << board[i][j] << ">";
			}
			else {
				cout << board[i][j] << " ";
			}
		}
		cout << endl;
	}
}
bool Board::moveDog(char c) {
	/*if (c=='r') {
		mydog.x++;
	}
	if (c=='l') {
		mydog.x--;
	}
	if (c=='u') {
		mydog.y--;
	}
	if (c=='d') {
		mydog.y++;
	}*/
	// This was just simple movements I was thinking of, but we need a way to connect D to the calls.
	// In other words, this code above does nothing. Still wanted to keep it in for now
}
















