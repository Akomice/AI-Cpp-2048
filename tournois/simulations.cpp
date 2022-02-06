#include <iostream>
#include <vector>
#include <iomanip> 
#include <stdlib.h>
#include <stdexcept>
#include <ctime>
#include <time.h>
#include <stdio.h>
#include <unistd.h>
#include <fstream>

using namespace std;

typedef vector<vector<int> > Plateau;
typedef vector<int> Ligne;

#define CHECK(test) if (!(test)) cout << "Test failed in file " << __FILE__ << " line " << __LINE__ << ": " #test << endl

Plateau plateauVide() {
    Plateau plateau;
    plateau = Plateau(5);
    for (int i = 0; i < 4; i++) {
        plateau[i] = vector<int>(4);
        for ( int j = 0; j < 4; j++ ) {
            plateau[i][j] = 0;
        }
    }
	plateau[4] = vector<int>(2); // La place du score et du nombre de coups
    plateau[4] = {0,0};
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
    Ligne copie = ligne;
	for (int i =0; i < 4; i++){
		if (i != 0 and copie[i] == copie[a]){
			copie[a] = copie[a]*2;
			copie[i] = 0;
			a = i;
		} else if (copie[i] != 0) {
			a = i;
		}
	}
	return copie;
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
		copie = deplacementHaut(copie);
	} else if ( direction == 2 ) {
		copie = deplacementBas(copie);
	} else if ( direction == 3 ) {
		copie = deplacementDroite(copie);
	} else if ( direction == 4 ) {
		copie = deplacementGauche(copie);
	}
	return copie;
}

bool estPossible(Plateau p, int direction) {
	return (p != deplacement(p,direction));
}

void affichePlateau(Plateau p) {
    for (int i = 0 ; i < 4 ; i++) {
        for (int j = 0 ; j < 4 ; j++) {
            cout << p[i][j] << " ";
        }
        cout << endl;
    }
	cout << p[4][0] << " " << p[4][1] << endl;
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

// bool estTermine(Plateau plateau){
// 	// Reste-t-il une case vide au moins ?
// 	for (Ligne & val : plateau){
// 		for (int v : val){
// 			if (v == 0){
// 				return false;
// 			}
// 		}
// 	}
// 	// Sur ce plateau plein, y a t-il au moins une combinaison restante ?
// 	Plateau copie = plateau;
// 	for (int i = 0; i < 2; i++) {
// 		for (int k = 0; k < 4; k++) {
// 			for (int j = 0; j < 3; j++) {
// 				if (copie[k][j] == copie[k][j + 1]) {
// 					return false;
// 				}
// 			}
// 		}
// 		copie = rotation(copie);
// 	}
// 	return true;
// }

bool estTermine(Plateau plateau) {
    for (int i = 1; i < 5 ; i++ ) {
        if (estPossible(plateau,i)) {return false;}
    }
    return true;
}
bool estGagnant(Plateau plateau){
	return MaxiPlateau(plateau) >= 2048;
}

Plateau lit_config() {
    Plateau resultat = Plateau(5);
    ifstream inFile;
    inFile.open("configuration.txt");
    string x;
	char caractere;
	int lignes = 0;
	int nb_de_coups;
	int score;
	int i;
    while (inFile >> x) {
		stringstream file = stringstream(x);
        if (lignes == 0) {
			file >> nb_de_coups;
		} else if (lignes == 1) {
			file >> score;
		}
		else {
			i = lignes - 2;
			resultat[i] = Ligne(4);
			file >> resultat[i][0] >> caractere >> resultat[i][1] >> caractere >> resultat[i][2] >> caractere >> resultat[i][3] >> caractere;
		}
		lignes++;
    }
	inFile.close();
	resultat[4] = Ligne(2);
	resultat[4][0] = score;
	resultat[4][1] = nb_de_coups;
    return resultat;
}

void nom() {
	ofstream outFile;
	outFile.open("mouvements.txt",ios::trunc);
	outFile << "S&Y\n";
	outFile.close();
}

void ecrit(int nb, int coup) {
	ofstream outFile;
	outFile.open("mouvements.txt",ios::app);
	switch(coup) {
		case 1:
			outFile << nb << " H\n";
			break;
		case 2:
			outFile << nb << " B\n";
			break;
		case 3:
			outFile << nb << " D\n";
			break;
		case 4:
			outFile << nb << " G\n";
			break;
	}
	outFile.close();
}

int ai(Plateau plateau) {
    Plateau copie = plateau;
    Plateau copie2 = plateau;
    int search_per_move = 200;
    int search_length = 10;
    vector<int> score_plateau = { 0, 0, 0, 0 };
    vector<int> premier_coup = { 1, 2, 3, 4 };
    for ( int i = 0; i < 4; i++ ) {
        if ( deplacement(plateau,premier_coup[i]) != plateau ) {
            copie = ajouteCase(deplacement(plateau,premier_coup[i]));
            score_plateau[i] += copie[4][0];
        } else {
            continue;
        }
        for ( int k = 0; k < search_per_move; k++) {
            int move_number = 1;
            copie2 = copie;
            while ( (!estTermine(copie2)) and move_number < search_length ) {
                int n = 1 + (rand()%4);
                while (copie2 == deplacement(copie2,n)) {
                    n = 1 + (rand()%4);
                }
                copie2 = ajouteCase(deplacement(copie2,n));
                score_plateau[i] += copie2[4][0];
                move_number+=1;
            }
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

float moyenne(vector<int> tableau) {
    int somme = 0;
    int n = (int)tableau.size();
    for (int i = 0 ; i < n ; i ++) {
        somme += tableau[i];
    }
    return somme/n;
}

int main() {
	srand(time(0));
    // Ligne maxs = Ligne(100);
    // int nb = 0;
    // for (int i = 0 ; i < 100 ; i++) {
    //     Plateau P = plateauInitial();
    //     while (!estTermine(P)) {
    //         int coup = ai(P);
    //         P = ajouteCase(deplacement(P,coup));
    //     }
    //     cout << MaxiPlateau(P) << endl;
    //     maxs[i] = MaxiPlateau(P);
    // }
    // for (int j = 0 ; j <100; j++) {
    //     if (maxs[j]>=2048) {nb+=1;}
    // }
    // cout << "Nombre de 2048 : " << nb << endl;
	// return 0;
    Plateau P = {{0,0,0,0},{64,256,0,0},{32,8,2,0},{4,32,2,2},{2324}};
    affichePlateau(P);
    int n = ai(P);
    affichePlateau(deplacement(P,n));
}