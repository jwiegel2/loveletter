#include <iostream>
#include <algorithm>
#include <array>
#include <random>
#include <chrono>
#include <list>
#include <vector>
#include <string>
#include <stdio.h>

// Start pointer at 1 since you remove 1 card at the beginning of play
int pointer = 1;
int numPlayers = 0;
std::array<int,16> deck {1,1,1,1,1,2,2,3,3,4,4,5,5,6,7,8};

class Player;

std::vector<Player> players;

class Player
{
	// Cards currently in the players hand
	std::list<int> hand;

	int playerNumber;
	// Is player protected by handmaid?
	bool isProtected = false;
	// Has player lost yet?
	bool isLoser = false;

	private:

	void draw(){
		hand.push_front(deck[pointer]);
		pointer++;
	}

	void printHand(int card){
		switch(card) {
			case 1 : std::cout << "  [Guard]  ";
				break;
			case 2 : std::cout << "  [Priest]  ";
				break;
			case 3 : std::cout << "  [Baron]  ";
				break;
			case 4 : std::cout << "  [Handmaid]  ";
				break;
			case 5 : std::cout << "  [Prince]  ";
				break;
			case 6 : std::cout << "  [King]  ";
				break;
			case 7 : std::cout << "  [Countess]  ";
				break;
			case 8 : std::cout << "  [Princess]  ";
				break;
		}
	}
	
	void selectCard(){
		// Wait for player to type valid card name, then allow options depending
		// on which card was selected
		bool validCard = false;
		while(!validCard){
			std::cout << "Which card will you play? ";
			std::string input;
			std::cin >> input;
			std::transform(input.begin(), input.end(), input.begin(), ::tolower);
			if(input.compare("guard") == 0){
				validCard = checkValid(1);
				if(validCard) action(1);
			}
			else if(input.compare("priest") == 0){
				validCard = checkValid(2);
				if(validCard) action(2);
			}
			else if(input.compare("baron") == 0){
				validCard = checkValid(3);
				if(validCard) action(3);
			}
			else if(input.compare("handmaid") == 0){
				validCard = checkValid(4);
				if(validCard) action(4);
			}
			else if(input.compare("prince") == 0){
				validCard = checkValid(5);
				if(validCard) action(5);
			}
			else if(input.compare("king") == 0){
				validCard = checkValid(6);
				if(validCard) action(6);
			}
			else if(input.compare("countess") == 0){
				validCard = checkValid(7);
				if(validCard) action(7);
			}
			else if(input.compare("princess") == 0){
				validCard = checkValid(8);
				if(validCard) action(8);
			}
		}
	}

	bool checkValid(int card){
		if(hand.front() == card || hand.back() == card){
			if(hand.front() == card) hand.pop_front();
			else hand.pop_back();
			return true;
		}
		std::cout << "Enter the name of a card in your hand.\n";
		return false;
	}

	void action(int card){
		switch(card){
			case 1 : {
				std::cout << "Select target player: ";
				
				break;
			}
			case 2 : {
				std::cout << "Select target player: ";
				
				break;
			}
			case 3 : {
				std::cout << "Select target player: ";
				
				break;
			}
			case 4 : {
				std::cout << "You are protected for 1 turn.\n";
				isProtected = true;
				break;
			}
			case 5 : {
				std::cout << "Select target player: ";
				
				break;
			}
			case 6 : {
				std::cout << "Select target player: ";
				
				break;
			}
			case 7 : {
				std::cout << "You discarded the countess.\n";
				break;
			}
			case 8 : {
				std::cout << "You discarded the princess. You lose.\n";
				break;
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
		selectCard();
	}

	bool getLoser(){
		return isLoser;
	}
	

};

int main() {
	// Determine if user inputted number of players is valid
	bool valid = false;
	std::string input = "";

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

	// Add players to player list
	for (int i = 1; i < numPlayers + 1; i++){
		players.push_back(Player(i));
	}

	int turn = 0;

	// TODO
	// Each player has an action, then the next player goes. Continue until
	// only one player remains or until there are no cards left.
	while(numPlayers > 1 || pointer < 16){
		if(!players.at(turn).getLoser()){
			players.at(turn).turn();
		}
	}

	return 0;
}






