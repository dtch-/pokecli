// Pokeball Simulator
// Simulation to test Pokeballs.

// Information retrieved from bulbapedia
// http://bulbapedia.bulbagarden.net/wiki/Catch_rate#Capture_method_.28Generation_I.29

// Modified capture rate to include and give advantage to ultraball.

#include <iostream>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
using namespace std;

// Declaration of variables
string poke_stat;
int ball_type;
int ball_rate;
int stat_reduct;
int poke_hp_max;
int poke_hp_cur;
int poke_catch_rate;
int fball;
int fcaught;

void balltype() {
	cout << "Which ball type?" << endl;
	cout << "\n1) poke\n2) great\n3) ultra\n4) master\n" << endl;
	cin >> ball_type;
}

void getstats() {
	cout << "Enter Pokemon Catch Rate (3 - 255)" << endl;
	cin >> poke_catch_rate;
	cout << "\nEnter Pokemon Status:\nSLP\nFRZ\nPAR\nBRN\nPSN\nEnter N for no ailment" << endl;
	cin >> poke_stat;
	cout << "Enter health (1 - 100)" << endl;
	cin >> poke_hp_cur;
}

void pokestat() {
	if (poke_stat == "SLP" | poke_stat == "FRZ") {
		cout << "Pokemons status is " << poke_stat << ".\n" << endl;
		stat_reduct = 25;
	}
	else if (poke_stat == "PAR" | poke_stat == "BRN" | poke_stat == "PSN") {
		cout << "Pokemons status is " << poke_stat << ".\n" << endl;
		stat_reduct = 12;
	}
	else {
		cout << "Pokemons status is normal." << endl;
		stat_reduct = 0;
	}
}

void ballrate() {
	srand (time(NULL));

	int n;
	int m;
	int f;
	m = rand() % 255 + 1;

	poke_hp_max = 100;

	switch (ball_type) {
		case 1:
			n = rand() % 255 + 1;
			fball = 12;
			cout << "\nPokeball selected.\n";
			break;
		case 2:
			n = rand() % 200 + 1;
			fball = 8;
			cout << "\nGreatball selected.\n";
			break;
		case 3:
			n = rand() % 150 + 1;
			fball = 6;
			cout << "\nUltraball selected.\n";
			break;
		case 4:
			cout << "\nMasterball selected.\n";
			break;
		default:
			cout << "Illegal option." << endl;	
	}

	if (ball_type != 4) {

		f = (poke_hp_max * 255 * 4)/(poke_hp_cur * fball);

		if (n - stat_reduct <= 25 | f > m) {
			cout << "Pokemon was caught!" << endl;
		}

		else {
			cout << "Pokemon broke free!" << endl;
		}
	}
	else {
		cout << "Pokemon was caught!" << endl;
	}

}

int main() {
	balltype();
	getstats();
	pokestat();
	ballrate();
}