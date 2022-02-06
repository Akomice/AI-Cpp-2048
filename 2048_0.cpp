#include "modele.h"

int main() {
	srand(time(0));
	bool gg = true;
	Plateau P = plateauInitial();
	dessine(P);
	while(not estTermine(P)) {
		int dir = direction();
		if ( deplacement(P,dir) != P ) {
			P = ajouteCase(deplacement(P,dir));
			dessine(P);
			if (estGagnant(P) and gg){ 
				gg = false;
				cout << "Bravo, vous avez réussi à obtenir une tuile 2048. Toutes nos félicitations !" << endl;
				cout << "Il ne vous reste plus qu'à améliorer votre score, peut-être plus haut que votre record..." << endl;
			}
		} else {
			dessine(P);
		}
	} 
	cout << "Vous avez perdu.." << endl << "Appuyez sur r pour rejouer ou q pour quitter." << endl;
	char touche;
	cin >> touche;
	while ( touche != 'r' and touche != 'q' ) {
		cout << "Saisie invalide. Saisissez à nouveau une touche." << endl;
		cin >> touche;
	}
	if ( touche == 'r' ) {
		main();
	} else {
		return 0;
	}
	
}