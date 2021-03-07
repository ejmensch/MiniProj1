/*
 * Dog.cpp
 *
 *  Created on: Mar 3, 2021
 *      Authors: Ethan Mensch, Bryce Leslie
 */
#include "Dog.hpp"
#include <iostream>
#include <string.h>
using namespace std;

Dog::Dog(string n) {
	name = n;
	strength = 50;
	x = y = 0;
}

	// constructor, sets the name to be whatever name gets passed in, the
	 //strength to be 50 (I just picked 50 - you want another number, go for it!) and I made
	 //the original coordinates be 0 and 0 because the compiler yells at me a tiny little yell
	 //if I don't initialize all my fields in the constructor

Dog::Dog(){
	name = 'd';
	strength = 50;
	x = y = 0;
};
/* constructor, I made the default be fluffy, but you can make it anything you like!!
* I set the strength to be 50 (again, I just picked 50), and I made the original
* coordinates be 0 and 0 because...
*/

bool Dog::changeStrength(int amt){
	if(strength <= 0){
		die();
		return false;
	}
	else{
		strength=strength-amt;
		return true;
	}

}
/*changeStrength modifies the strength property by whatever amt is (basically adding here)
* It then calls printDog method to print out current information about the dog.
* It also checks to make sure that the dog object's strength is >0.
* If the dog object's strength is 0 or less, it calls the die method.
* It returns true if the strength is still >0 and false otherwise.
*/

void Dog::die(){
	cout<<"Dang brodie, you're a terrible dog owner. Your dog has died, shame on you."<<endl;
}
/* This method just prints out a sad pathetic death of a dog message, letting everyone
* know of the demise of the dog object. My message has ACK!!! and judgmental statements
* about how the user is a cruel, heartless person for letting a puppy dog die, but
* yours can be whatever you like.
*/

void Dog::printDog() {
	cout << "Dog name: " << name << endl;
	cout << "Current strength: " << strength << endl;
}

void Dog::won(){
	cout<<"Good job dawg, you were successfully able to guide your dog through the evil forest!"<<endl;
};
/* again, just a message about the user's incredible prowess in successfully navigating the
* sweet little puppy dog through the evil forest to the other side. You can make it whatever
* you like.
*/

void Dog::reset(){
	strength=50;
	x = y= 0;
};
/* this method just resets the strength (for me it was 50) and the x and y to 0 and 0.
*
*/



