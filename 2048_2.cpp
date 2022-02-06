#include "niveau_2.h"

int main() {
	initscr();
	curs_set(0); // enlève le curseur
	srand(time(0));
	Plateau P = plateauInitial();
	//Plateau P = { {1024,1024,0,0}, {0,0,0,0},{0,0,0,0},{0,0,0,0},{2} };
	//Plateau P = {{2,4,2,0}, {4,2,4,4}, {2,4,2,2}, {4,2,4,16},{2}};
	dessineC(P);
	bool gg = true;
	while(not estTermine(P)) {
		int dir = directionC();
		if ( deplacement(P,dir) != P ) {
			P = ajouteCase(deplacement(P,dir));
			dessineC(P);
			refresh();
			if (estGagnant(P) and gg){
				gg = false;
				printw("\nBravo, vous avez réussi à obtenir une tuile 2048. Toutes nos félicitations !\n");
				printw("Il ne vous reste plus qu'à améliorer votre score, peut-être plus haut que votre record...\n");
			}
		}
	}
	clear();
	printw("Vous avez perdu..\nAppuyez sur r pour rejouer ou q pour quitter.\n");
	char touche;
	touche = getch();
	while ( touche != 'r' and touche != 'q' ) {
		printw("\nSaisie invalide. Saisissez à nouveau une touche.\n");
		touche = getch();
	}
	if ( touche == 'r' ) {
		main();
	} else {
		endwin();
		return 0;
	}
	endwin();
}