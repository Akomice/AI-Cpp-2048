// Les tests de toutes les fonctions se trouvent ici :p
#include "modele.h"
#include <iostream>
using namespace std;

/** Infrastructure minimale de test **/
#define CHECK(test) if (!(test)) cout << "Test failed in file " << __FILE__ << " line " << __LINE__ << ": " #test << endl

void test_plateauVide() {
    Plateau plateau = plateauVide();
    for ( Ligne & ligne : plateau) {
        for ( int j : ligne) {
            CHECK( j == 0 );
            CHECK( not (j == 1) );
            CHECK( j != 3 );
        }
    }
}

void test_plateauInitial() {
    Plateau plateau = plateauInitial();
    int i = 0;
    for ( int k = 0 ; k < plateau.size() ; k++) {
        if (k<4) {
            CHECK(plateau[k].size() == 4);
            for ( int j = 0 ; j < 4 ; j++) {
                if (plateau[k][j]==2 or plateau[k][j]==4) {
                    i++;
                }
                
            }
        } else {
            CHECK( plateau[k][0] == 0 ); //regarde si le score est valide et nul
        }
    }
    CHECK( i == 2 );
}

void test_tireDeuxOuQuatre() { // En chantier (je m'apelle teuse)
    Ligne l = {0, 0, 0};
    for (int i = 0; i < 10000; i++) {
        int a = tireDeuxOuQuatre();
        if (a == 2){
            l[0]++;
        } else if (a == 4 ){
            l[1]++;
        } else {
            l[2]++;
        }
    }
    CHECK(l[0] > 8900 and l[0] < 9100);
    CHECK(l[1] > 900 and l[1] < 1100);
    CHECK(l[2] == 0);
}

void test_ajouteCase(){
    Plateau P1 = {
        {2, 4, 0, 0},
        {4, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0}};
    Plateau P1_bis = ajouteCase(P1);
    int a = 0;
    int b = 0;
    for (int i = 0; i < P1.size(); i++){
        for (int j = 0; j < P1[i].size(); j++){
            if (P1[i][j] > 1){
                a++;
            }
            if (P1_bis[i][j] > 1){
                b++;
            }
        }
    }
    CHECK((a + 1) == b);
    CHECK(P1_bis[4][0] == 0);
}

void test_empileLigne(){
    Ligne L1 = {4, 0, 4, 2};
    Ligne L1_bis = {8, 0, 0, 2};
    CHECK(empileLigne(L1) == L1_bis);
    Ligne L2 = {4, 0, 2, 2};
    Ligne L2_bis = {4, 0, 4, 0};
    CHECK(empileLigne(L2) == L2_bis);
    Ligne L3 = {4, 0, 0, 0};
    Ligne L3_bis = {4, 0, 0, 0};
    CHECK(empileLigne(L3) == L3_bis);
    Ligne L4 = {4, 0, 8, 0};
    Ligne L4_bis = {4, 0, 8, 0};
    CHECK(empileLigne(L4) == L4_bis);
}

void test_triLigne(){
    Ligne L1 = {4, 0, 4, 2};
    Ligne L1_bis = {4, 4, 2, 0};
    CHECK(triLigne(L1) == L1_bis);
    Ligne L2 = {4, 0, 2, 2};
    Ligne L2_bis = {4, 2, 2, 0};
    CHECK(triLigne(L2) == L2_bis);
    Ligne L3 = {4, 0, 0, 0};
    Ligne L3_bis = {4, 0, 0, 0};
    CHECK(triLigne(L3) == L3_bis);
    Ligne L4 = {4, 0, 8, 0};
    Ligne L4_bis = {4, 8, 0, 0};
    CHECK(triLigne(L4) == L4_bis);
}

void test_deplacementGauche(){
    Plateau P1 = {
        {2, 4, 0, 0},
        {4, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0}};
    Plateau P1_bis = {
        {2, 4, 0, 0},
        {4, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0}};
    CHECK(deplacementGauche(P1) == P1_bis);
    Plateau P2 = {
        {2, 4, 0, 0},
        {4, 0, 4, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0}};
    Plateau P2_bis = {
        {2, 4, 0, 0},
        {8, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {8}};
    CHECK(deplacementGauche(P2) == P2_bis);
    Plateau P3 = {
        {2, 4, 0, 2},
        {4, 0, 4, 0},
        {0, 0, 0, 0},
        {0, 0, 2, 0},
        {0}};
    Plateau P3_bis = {
        {2, 4, 2, 0},
        {8, 0, 0, 0},
        {0, 0, 0, 0},
        {2, 0, 0, 0},
        {8}};
    CHECK(deplacementGauche(P3) == P3_bis);
}
void test_rotation(){
    Plateau P1 = {
        {2, 4, 0, 0},
        {4, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0}};
    Plateau P1_bis = {
        {0, 0, 4, 2},
        {0, 0, 0, 4},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0}};
    CHECK(rotation(P1) == P1_bis);
    Plateau P2 = {
        {2, 4, 0, 0},
        {4, 0, 4, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0}};
    Plateau P2_bis = {
        {0, 0, 4, 2},
        {0, 0, 0, 4},
        {0, 0, 4, 0},
        {0, 0, 0, 0},
        {0}};
    CHECK(rotation(P2) == P2_bis);
    Plateau P3 = {
        {2, 4, 0, 2},
        {4, 0, 4, 0},
        {0, 0, 0, 0},
        {0, 0, 2, 0},
        {0}};
    Plateau P3_bis = {
        {0, 0, 4, 2},
        {0, 0, 0, 4},
        {2, 0, 4, 0},
        {0, 0, 0, 2},
        {0}};
    CHECK(rotation(P3) == P3_bis);
}

void test_deplacementDroite(){
    Plateau P1 = {
        {2, 4, 0, 0},
        {4, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0}};
    Plateau P1_bis = {
        {0, 0, 2, 4},
        {0, 0, 0, 4},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0}};
    CHECK(deplacementDroite(P1) == P1_bis);
    Plateau P2 = {
        {2, 4, 0, 0},
        {4, 0, 4, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0}};
    Plateau P2_bis = {
        {0, 0, 2, 4},
        {0, 0, 0, 8},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {8}};
    CHECK(deplacementDroite(P2) == P2_bis);
    Plateau P3 = {
        {2, 4, 0, 2},
        {4, 0, 4, 0},
        {0, 0, 0, 0},
        {0, 0, 2, 0},
        {0}};
    Plateau P3_bis = {
        {0, 2, 4, 2},
        {0, 0, 0, 8},
        {0, 0, 0, 0},
        {0, 0, 0, 2},
        {8}};
    CHECK(deplacementDroite(P3) == P3_bis);    
}

void test_deplacementHaut(){
    Plateau P1 = {
        {2, 4, 0, 0},
        {4, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0}};
    Plateau P1_bis = {
        {2, 4, 0, 0},
        {4, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0}};
    CHECK(deplacementHaut(P1) == P1_bis);
    Plateau P2 = {
        {2, 4, 0, 0},
        {4, 0, 4, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0}};
    Plateau P2_bis = {
        {2, 4, 4, 0},
        {4, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0}};
    CHECK(deplacementHaut(P2) == P2_bis);
    Plateau P3 = {
        {2, 4, 0, 2},
        {4, 4, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 2, 0},
        {0}};
    Plateau P3_bis = {
        {2, 8, 2, 2},
        {4, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {8}};
    CHECK(deplacementHaut(P3) == P3_bis);    
}

void test_deplacementBas(){
    Plateau P1 = {
        {2, 4, 0, 0},
        {4, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0}};
    Plateau P1_bis = {
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {2, 0, 0, 0},
        {4, 4, 0, 0},
        {0}};
    CHECK(deplacementBas(P1) == P1_bis);
    Plateau P2 = {
        {2, 4, 0, 0},
        {4, 0, 4, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0}};
    Plateau P2_bis = {
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {2, 0, 0, 0},
        {4, 4, 4, 0},
        {0}};
    CHECK(deplacementBas(P2) == P2_bis);
    Plateau P3 = {
        {2, 4, 0, 2},
        {4, 4, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 2, 0},
        {0}};
    Plateau P3_bis = {
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {2, 0, 0, 0},
        {4, 8, 2, 2},
        {8}};
    CHECK(deplacementBas(P3) == P3_bis);    
}

int main() {
    srand(time(0));
    test_plateauVide();
    test_plateauInitial();
    test_tireDeuxOuQuatre();
    test_triLigne();
    test_empileLigne();
    test_deplacementGauche();
    test_rotation();
    test_deplacementDroite();
    test_deplacementHaut();
    test_deplacementBas();
}