#include "modele.h"

Plateau plateauVide() {
    Plateau plateau;
    plateau = Plateau(5);
    for (int i = 0; i < 4; i++) {
        plateau[i] = vector<int>(4);
        for ( int j = 0; j < 4; j++ ) {
            plateau[i][j] = 0;
        }
    }
	plateau[4] = vector<int>(1); // La place du score 
    plateau[4][0] = 0;
    return plateau;
}

int tireDeuxOuQuatre() {
    if (rand()%10 == 0) {
        return 4;
    }
    return 2;
}

Plateau plateauInitial() {
	Plateau P = plateauVide();
	int x, y;
	x = rand()%4;
	y = rand()%4;
	P[x][y] = tireDeuxOuQuatre();
	int a, b;
    do {
		a = rand()%4;
		b = rand()%4;
	} while ( a == x and b == y);
	P[a][b] = tireDeuxOuQuatre();
    return P;
}

Plateau ajouteCase(Plateau plateau) {
	int a,b;
	Plateau copie = plateau;
	do {
		a = rand()%4;
		b = rand()%4;
	} while ( plateau[a][b] != 0 );
	copie[a][b] = tireDeuxOuQuatre();

	return copie;
}

Ligne triLigne(Ligne ligne) {
	Ligne copie = Ligne(4);
	int emplacementLibre = 0;
	for (int i = 0 ; i < 4 ; i++) {
		if (ligne[i] != 0) {
			copie[emplacementLibre] = ligne[i];
			emplacementLibre++;
		}
	}
	return copie;
}

Ligne empileLigne(Ligne ligne) {
	int a = 0;
	for (int i =0; i < 4; i++){
		if (i != 0 and ligne[i] == ligne[a]){
			ligne[a] = ligne[a]*2;
			ligne[i] = 0;
			a = i;
		} else if (ligne[i] != 0) {
			a = i;
		}
	}
	return ligne;
}

Plateau deplacementGauche(Plateau plateau) {
	Plateau copie = plateau;
	for (int i = 0 ; i < 4 ; i++) {
		copie[i] = empileLigne(plateau[i]);
		if (copie[i] != plateau[i]){
			for (int j = 0; j < 4; j++){
				if (copie[i][j] == 0 and plateau[i][j] != 0){
					copie[4][0] += 2 * plateau[i][j];
				}
			}
		}
		copie[i] = triLigne(copie[i]);
	}
	return copie;
}

Plateau rotation(Plateau plateau) {
	Plateau copie = plateau;
	for ( int i = 0; i < 4; i++) {
		for ( int j = 0; j < 4; j++) {
			copie[i][j] = plateau[3-j][i];
		}
	}
	return copie;
}

Plateau deplacementHaut(Plateau plateau) {
	return rotation(deplacementGauche(rotation(rotation(rotation(plateau)))));
}

Plateau deplacementDroite(Plateau plateau) {
	return rotation(rotation(deplacementGauche(rotation(rotation(plateau)))));
}

Plateau deplacementBas(Plateau plateau) {
	return rotation(rotation(rotation(deplacementGauche(rotation(plateau)))));
}

int direction() {
	char sens;
	cin >> sens;
	try {
		if ( sens == 'z' ) {
			return 1;
		} else if ( sens == 's' ) {
			return 2;
		} else if ( sens == 'd' ) {
			return 3;
		} else if ( sens == 'q' ) {
			return 4;
		} else {
			throw invalid_argument("Direction invalide!");
		}
	} catch ( invalid_argument & e ) {
	  }
	return direction();
}

Plateau deplacement(Plateau plateau, int direction ) {
	Plateau copie = plateau;
	if ( direction == 1) {
		copie = deplacementHaut(plateau);
	} else if ( direction == 2 ) {
		copie = deplacementBas(plateau);
	} else if ( direction == 3 ) {
		copie = deplacementDroite(plateau);
	} else if ( direction == 4 ) {
		copie = deplacementGauche(plateau);
	}
	return copie;
}

int MaxiPlateau(Plateau p){
	int maxi = 0;
	for (int i = 0; i <= 3; i++){
		for (int j= 0; j<=3;j++){
			if (p[i][j] > maxi ){
				maxi = p[i][j];
			}
		}
	}
	return maxi;
}

string dessine(Plateau p){
    string a = to_string(MaxiPlateau(p));
	int maxi = a.size();
	maxi += 2;
	int stars = maxi * 4 + 5;
    // première ligne
	for (int i = 0; i < stars; i++){
		cout << "*";
	}
	cout << endl;
    
	for (int i = 0; i < 4; i++){
		cout << "*";
		for (int j = 0; j < 4; j++){
			string tuile = to_string(p[i][j]);
			if (tuile == "0"){
				tuile = " ";
				for (int k = 1; k < maxi; k++){
					tuile += " ";
				}
			} else {
				int nb = (maxi - tuile.length()) / 2;
				for (int k = 0; k < nb; k++){
					tuile = " " + tuile;
                }
				for (int k = 0; k < int(nb + (maxi - tuile.length())%2); k++){
					tuile += " ";
                }
			}
			cout << tuile << "*";
		}
		cout << endl;
		for (int j = 0; j < stars; j++){
			cout << "*";
		}
		cout << endl;
	}
	cout << "SCORE : " << p[4][0] << endl;
    return a;
}

bool estTermine(Plateau plateau){
	// Reste-t-il une case vide au moins ?
	for (Ligne & val : plateau){
		for (int v : val){
			if (v == 0){
				return false;
			}
		}
	}
	// Sur ce plateau plein, y a t-il au moins une combinaison restante ?
	Plateau copie = plateau;
	for (int i = 0; i < 2; i++){
		for (int k = 0; k < 4; k++){
			for (int j = 0; j < 3; j++){
				if (copie[k][j] == copie[k][j + 1]){
					return false;
				}
			}
		}
		copie = rotation(copie);
	}
	return true;
}

bool estGagnant(Plateau plateau){
	return MaxiPlateau(plateau) >= 2048;
}