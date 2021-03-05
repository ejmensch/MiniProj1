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
	/*bool keepPlaying = true;
	while (keepPlaying) {
		cout << "What level of difficulty do you want (e, m, or h)?" << endl;
		char c;
		cin >> c;
		level = c;
		startx = rand() % size;
		starty = 0;
		endx = rand() % size;
		endy = size - 1;
		mydog.x = startx;
		mydog.y = starty;*/
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
	int i,j,x;   //i is row , j is column... we can change that later
	for(i=0; i < 20; i++){
		for(j=0; j < 20; j++){
			if (level == 'e') {
				if(i % 2 != 0){
					x=rand()%5;
					if(x==1){
						x=rand()%5;
						if(x==1){
							board[i][j] = 'F';
						}
					}
				}
				if (j % 2 != 0) {
					x = rand() % 5;
					if (x == 1) {
						x = rand()%5;
						if (x == 1) {
							board[i][j] = 'F';
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
							board[i][j] = 'F';
						}
					}
				}
				if (j % 2 != 0) {
					x = rand() % 6;
					if (x == 1) {
						x = rand()%6;
						if (x == 1) {
							board[i][j] = 'F';
						}
					}
				}
			}
			if (level == 'h') {
				if(i % 2 != 0){
					x=rand()%8;
					if(x==1){
						x=rand()%8;
						if(x==1){
							board[i][j] = 'F';
						}
					}
				}
				if (j % 2 != 0) {
					x = rand() % 8;
					if (x == 1) {
						x = rand()%8;
						if (x == 1) {
							board[i][j] = 'F';
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
	int i,j,x;   //i is row , j is column... we can change that later
	for(i=0; i < 20; i++){
		for(j=0; j < 20; j++){
			if (level == 'e') {
				if(i % 2 != 0){
					x=rand()%8;
					if(x==1){
						x=rand()%8;
						if(x==1){
							board[i][j] = 'F';
						}
					}
				}
				if (j % 2 != 0) {
					x = rand() % 8;
					if (x == 1) {
						x = rand()%8;
						if (x == 1) {
							board[i][j] = 'F';
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
							board[i][j] = 'F';
						}
					}
				}
				if (j % 2 != 0) {
					x = rand() % 6;
					if (x == 1) {
						x = rand()%6;
						if (x == 1) {
							board[i][j] = 'F';
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
							board[i][j] = 'F';
						}
					}
				}
				if (j % 2 != 0) {
					x = rand() % 5;
					if (x == 1) {
						x = rand()%5;
						if (x == 1) {
							board[i][j] = 'F';
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
	for(i=0; i < 20; i++){
		for(j=0; j < 20; j++){
			board[i][j] = ' ';
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




	/*for(j=0; j<20; j++){ //top/bottom borders *put these in print board later and figure out how to make them a border*
		board[0][j]='_';
		board[19][j]='_';
	}
	for(i=0;i<21;i++){ //side borders *same thing I said above-EM*
		board[i][0]='|';
		board[i][19]='|';
	}*/
}
void Board::printBoard() {
	/* (8 pts) code for the printBoard method goes here
	 */
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
}
bool Board::moveDog(char c) {
	// (12 pts) code for the moveDog method goes here

}
















