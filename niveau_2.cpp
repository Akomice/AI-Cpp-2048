#include "niveau_2.h"

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

char const *convertit(int i) {
	string transition = to_string(i); // convertit un entier i en string ( dans transition )
	char const *num_char = transition.c_str(); // convertit un string transition en const char * (dans num_char)
	return num_char;
}

int tireDeuxOuQuatre() {
    if (rand()%10 == 0) {
        return 4;
    }
    return 2;
}

Plateau plateauInitial() {
	//Plateau P = {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
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
int directionC() {
    keypad(stdscr, TRUE); // permet d'autoriser la saisie du clavier sur le terminal
	int keyPressed = getch();
	switch(keyPressed) { 
		case KEY_UP:
			return 1;
		case KEY_DOWN:
			return 2;
		case KEY_RIGHT:
			return 3;
		case KEY_LEFT:
			return 4;
	}
	keypad(stdscr, FALSE);
	return 0;
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

string dessineC(Plateau p){
	clear();
	start_color(); // dit au programme que l'on va utiliser des couleurs
	init_color(COLOR_YELLOW,1000,500,0); // redéfinition de color yellow avec un code couleur rgb sur 1000 (au lieu de 255)
	if ( estGagnant(p) ) {
		init_color(COLOR_MAGENTA,831,686,216);
	} else {
	init_color(COLOR_MAGENTA,976,259,620); // pareil sur magenta
	}
	init_pair(1,COLOR_MAGENTA,COLOR_BLACK); // 1er groupe de couleurs : magenta black (magenta sur le caractère, black sur le fond)
	init_pair(2,COLOR_YELLOW,COLOR_BLACK); // 2e groupe de couleurs
    string a = to_string(MaxiPlateau(p));
	int maxi = a.size();
	maxi += 2;
	int stars = maxi * 4 + 5;
    // première ligne
	attron(COLOR_PAIR(1));  // utilisation des couleurs du groupe 1
	for (int i = 0; i < stars; i++){
		printw("*");
	}
	attroff(COLOR_PAIR(1));  // on arrête d'utiliser les couleurs du groupe 1
	printw("\n");
    
	for (int i = 0; i < 4; i++){
		attron(COLOR_PAIR(1));
		printw("*");
		attroff(COLOR_PAIR(1));
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
			attron(COLOR_PAIR(2));
			printw(tuile.c_str());
			attroff(COLOR_PAIR(2));
			attron(COLOR_PAIR(1));
			printw("*");
			attroff(COLOR_PAIR(1));
		}
		printw("\n");
		attron(COLOR_PAIR(1));
		for (int j = 0; j < stars; j++){
			printw("*");
		}
		attroff(COLOR_PAIR(1));
		printw("\n");
	}
	printw("\n");
	attron(COLOR_PAIR(1));
	printw("SCORE : ");
	printw(to_string(p[4][0]).c_str());
	attroff(COLOR_PAIR(1));
	return a;
	// refresh();
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

int ai(Plateau plateau) {
    Plateau copie = plateau;
    Plateau copie2 = plateau;
    bool isValid = true;
	int search_length = 10;
    vector<int> score_plateau = { 0, 0, 0, 0 };
    vector<int> premier_coup = { 1, 2, 3, 4 };
    for ( int i = 0; i < 4; i++ ) {
        if ( deplacement(plateau,premier_coup[i]) != plateau ) {
            copie = ajouteCase(deplacement(plateau,premier_coup[i]));
        } else {
            continue;
        }
        for ( int k = 0; k < search_length; k++) {
            int move_number = 1;
            copie2 = copie;
            isValid = true;
            while ( isValid and move_number < search_length ) {
                int n = rand()%4;
                if ( copie2 != deplacement(copie2,n)) {
                    copie2 = ajouteCase(deplacement(copie2,n ));
                    move_number+=1;
                } else {
					isValid = false;
				}
            }
			score_plateau[i]+=copie2[4][0];
        }
    }
    int index_max = 0;
    for ( int i = 0; i < 4; i++ ) {
        if ( score_plateau[index_max] < score_plateau[i] ) {
            index_max = i;
        }
    }
    return premier_coup[index_max];
}