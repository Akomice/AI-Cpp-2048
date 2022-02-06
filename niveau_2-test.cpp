// Les tests de toutes les fonctions du niveau 2 se trouvent ici :p
#include "niveau_2.h"
#include <iostream>
using namespace std;


void test_plateauVide() {
    Plateau plateau = plateauVide();
    for ( int i = 0; i < 4; i++ ) {
        for ( int j = 0; j < 4; j++) {
            CHECK( plateau[i][j] == 0 );
            CHECK( not (plateau[i][j] == 1) );
            CHECK( plateau[i][j] != 3 );
        }
    }
}

int main() {
    test_plateauVide();
}
//Pour compiler, faire g++ -g  -o fichier_test fichier_test.cpp modele.cpp