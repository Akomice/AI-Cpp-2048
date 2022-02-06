#include "modele.h"

int ai(Plateau plateau) {
    Plateau copie = plateau;
    Plateau copie2 = plateau;
    bool isValid = true;
    int search_length = 15;
    vector<int> score_plateau = { 0, 0, 0, 0 };
    vector<int> premier_coup = { 1, 2, 3, 4 };
    for ( int i = 0; i < 4; i++ ) {
        if ( deplacement(plateau,premier_coup[i]) != plateau ) {
            copie = ajouteCase(deplacement(plateau,premier_coup[i]));
            score_plateau[i] += score_debile(copie);
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
                    score_plateau[i] += score_debile(copie2);
                    move_number+=1;
                }
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