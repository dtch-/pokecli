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
string ball_type;
string poke_stat;
int ball_rate;
int stat_reduct;
int poke_hp_max;
int poke_hp_cur;
int poke_catch_rate;
int fball;
int fcaught;

void balltype() {
	cout << "Which ball type?" << endl;
	cout << "\npoke\ngreat\nultra\nmaster\n" << endl;
	cin >> ball_type;
	cout << "\nball type is " << ball_type << "ball\n" << endl;
}

void getstats() {
	cout << "Enter Pokemon Catch Rate (3 - 255)" << endl;
	cin >> poke_catch_rate;
	cout << "\nEnter Pokemon Status:\nSLP\nFRZ\nPAR\nBRN\nPSN\nEnter nothing for no ailment" << endl;
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

	int m;
	int f;
	m = rand() % 255 + 1;

	poke_hp_max = 100;

	if (ball_type == "master") {
		cout << "Masterball was thrown." << endl;
		cout << "Pokemon was caught." << endl;
	}
	else if (ball_type == "poke") {
		cout << "Pokeball was thrown." << endl;
		cout << "Generating number between 0 and 255" << endl;
		int n;
		n = rand() % 255 + 1;
		fball = 12;
		f = (poke_hp_max * 255 * 4)/(poke_hp_cur * fball);
		cout << "N = " << n << endl; 
		
		if (n - stat_reduct <= 25 | f > m) {
			cout << "Pokemon was caught!" << endl;
		}
		else {
			cout << "Pokemon broke free!" << endl;
		}

	}
	else if (ball_type == "great") {
		cout << "Greatball was thrown." << endl;
		cout << "Generating number between 0 and 200" << endl;
		int n0;
		n0 = rand() % 200 + 1;
		fball = 8;
		f = (poke_hp_max * 255 * 4)/(poke_hp_cur * fball);
		cout << "N = " << n0 << endl;

		if (n0 - stat_reduct <= 25 | f > m){
			cout << "Pokemon was caught!" << endl;
		}
		else {
			cout << "Pokemon broke free!" << endl;
		}
	}
	else {
		cout << "Ultraball was thrown." << endl;
		cout << "Generating number between 0 and 150" << endl;
		int n1;
		n1 = rand() % 150 + 1;
		fball = 6;
		f = (poke_hp_max * 255 * 4)/(poke_hp_cur * fball);
		cout << "N = " << n1 << endl;
	
		if (n1 - stat_reduct <= 25 | f > m) {
			cout << "Pokemon was caught!" << endl;
		}
		else {
			cout << "Pokemon broke free!" << endl;
		}
	}
}

int main() {
	balltype();
	getstats();
	pokestat();
	ballrate();
}