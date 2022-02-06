#include <ncurses.h>
#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

typedef vector<vector<int> > Plateau;
typedef vector<int> Ligne; // création de l'alias Ligne

Plateau plateauVide() {
    Plateau plateau;
    plateau = Plateau(4);
    for (int i = 0; i < 4; i++) {
        plateau[i] = vector<int>(4);
        for ( int j = 0; j < 4; j++ ) {
            plateau[i][j] = 0;
        }
    }
    return plateau;
}

// convertit un entier en const char * en passant par un string
char const *convertit(int i) {
	string transition = to_string(i); // convertit un entier i en string ( dans transition )
	char const *num_char = transition.c_str(); // convertit un string transition en const char * (dans num_char)
	return num_char;
}

void affichePlateauC(Plateau plateau) {
	clear(); //clear le terminal
	for ( int i = 0; i < 4; i++ ) {
		for ( int j = 0; j < 4; j++ ) {
			printw(convertit(plateau[i][j]));
			printw(" ");
		}
		printw("\n");
	}
	refresh(); // met à jour l'affichage
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

void afficheLigne(Ligne ligne) {
    for (int i =0; i<4;i++) {
        cout << ligne[i] << " ";
    }
    cout << endl;
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

Ligne deplacementLigneGauche(Ligne ligne) {
	Ligne copie = empileLigne(ligne);
	copie = triLigne(copie);
	return copie;
}

Plateau deplacementGauche(Plateau plateau) {
	Plateau copie = plateau;
	for (int i = 0 ; i < 4 ; i++) {
		copie[i] = deplacementLigneGauche(plateau[i]);
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
    keypad(stdscr, TRUE);
	// cout << "Choisissez une direction à l'aide des flèches directionnelles" << endl;
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


int MaxiPlateau(Plateau plateau) {
	int maxi = 0;
	for (Ligne & ligne : plateau){
		for (int x : ligne){
			if (x > maxi){
				maxi = x;
			}
		}
	}
	return maxi;
}

string dessineC(Plateau p) {
	clear();
	start_color(); // dit au programme que l'on va utiliser des couleurs
	init_color(COLOR_YELLOW,1000,500,0); // redéfinition de color yellow avec un code couleur rgb sur 1000 (au lieu de 255)
	init_color(COLOR_MAGENTA,976,259,620); // pareil sur magenta
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
	return a;
	// refresh();
}

bool estTermine(Plateau plateau) {  
	int c = 0;
	for (Ligne & val : plateau){
		for (int v : val){
			if (v == 0){
				return false;
			}
		}
	}
	return true;
}

bool estGagnant(Plateau plateau) {
	return stoi(dessineC(plateau)) >= 2048;
}

int main() {
	initscr();
	curs_set(0); // enlève le curseur
	srand(time(0));
	Plateau P = plateauInitial();
	dessineC(P);
	
	while(not estTermine(P)) {
		int dir = directionC();
		if ( deplacement(P,dir) != P ) {
			P = ajouteCase(deplacement(P,dir));
			dessineC(P);
		}
	}
	endwin();
}
