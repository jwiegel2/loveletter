#include <iostream>
#include <algorithm>
#include <array>
#include <random>
#include <chrono>
#include <list>
#include <string>
#include <stdio.h>

// Start pointer at 1 since you remove 1 card at the beginning of play
int pointer = 1;
std::array<int,16> deck {1,1,1,1,1,2,2,3,3,4,4,5,5,6,7,8};

class Player
{
	// Cards currently in the players hand
	std::list<int> hand;

	int playerNumber;
	// Is player protected by handmaid?
	bool isProtected = false;

	private:

	void draw(){
		hand.push_front(deck[pointer]);
		pointer++;
	}

	void printHand(int card){
		switch(card) {
			case 1 : std::cout << "  [Guard]  ";
			case 2 : std::cout << "  [Priest]  ";
			case 3 : std::cout << "  [Baron]  ";
			case 4 : std::cout << "  [Handmaid]  ";
			case 5 : std::cout << "  [Prince]  ";
			case 6 : std::cout << "  [King]  ";
			case 7 : std::cout << "  [Countess]  ";
			case 8 : std::cout << "  [Princess]  ";
		}
	}
	
	void selectCard(){
		// Wait for player to type valid card name, then allow options depending
		// on which card was selected
		bool validCard = false;
		while(!validCard){
			std::string input;
			std::cin >> input;
			std::transform(input.begin(), input.end(), input.begin(), ::tolower);
			if(input.compare("guard") == 0){
				validCard = checkValid(1);
				std::cout << "Select target player: ";
			}
			else if(input.compare("priest") == 0){
				validCard = checkValid(2);
				std::cout << "Select target player: ";
			}
			else if(input.compare("baron") == 0){
				validCard = checkValid(3);
				std::cout << "Select target player: ";
			}
			else if(input.compare("handmaid") == 0){
				validCard = checkValid(4);
				std::cout << "Select target player: ";
			}
			else if(input.compare("prince") == 0){
				validCard = checkValid(5);
				std::cout << "Select target player: ";
			}
			else if(input.compare("king") == 0){
				validCard = checkValid(6);
				std::cout << "Select target player: ";
			}
			else if(input.compare("countess") == 0){
				validCard = checkValid(7);
				std::cout << "Select target player: ";
			}
			else if(input.compare("princess") == 0){
				validCard = checkValid(8);
				std::cout << "Select target player: ";
			}
			else std::cout << "Enter the name of a card in your hand.\n";
		}
	}

	bool checkValid(int card){
		if(hand.front() == card || hand.back() == card){
			if(hand.front() == card) hand.pop_front();
			else hand.pop_back();
			return true;
		}
		else return false;
	}

	void action(int card){
		switch(card){
			case 1 : {
				std::cout << "Select target player: ";
			}
		}
	}

	public:
	
	Player(int playerNumber){
		this->playerNumber = playerNumber;
		hand.push_front(deck[pointer]);
		pointer++;
	}

	void turn(){
		isProtected = false;
		draw();
		printHand(hand.front());
		printHand(hand.back());
		std::cout << '\n';
		std::cout << "Which card will you play?";
		selectCard();
	}

};

int main() {
	// Determine if user inputted number of players is valid
	bool valid = false;
	std::string input = "";
	int numPlayers = 0;

	while(!valid){
		std::cout << "Please enter the number of players (2-4): ";
		std::getline(std::cin, input);

		if(input.compare("2") == 0){
			numPlayers = 2;
			valid = true;
		}
		else if(input.compare("3") == 0){
			numPlayers = 3;
			valid = true;
		}
		else if(input.compare("4") == 0){
			numPlayers = 4;
			valid = true;
		}
		else std::cout << "Enter a number between 2 and 4.\n";
	}
	
	
	// Generate random number to shuffle deck
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

	shuffle (deck.begin(), deck.end(), std::default_random_engine(seed));

	std::cout << "shuffled elements:";
	for (int& x: deck) std::cout << ' ' << x;
	std::cout << '\n';

	return 0;
}
