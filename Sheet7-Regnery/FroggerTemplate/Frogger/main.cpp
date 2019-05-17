#include "Terminal.h"
#include "Frog.h"
#include "Car.h"
#include <iostream>
#include <chrono>
#include "Game.h"
#include "Teich.h"

int main()
{
	//Generiert neues Terminal
	Terminal term(80, 50);
	//Initialisiert neues Spiel
	Game game(term);


//Framework
while (!game.is_done()) {
			//Update das Spiel
			game.update();
			//Update die Grafik
			game.draw();
}

	term.close();
}
