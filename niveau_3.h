#include <SFML/Graphics.hpp>
#include <vector>
#include <iomanip> 
#include <stdlib.h>
#include <stdexcept>
#include <iostream>
using namespace sf;
using namespace std;

/** Infrastructure minimale de test **/
#define CHECK(test) if (!(test)) cout << "Test failed in file " << __FILE__ << " line " << __LINE__ << ": " #test << endl

typedef vector<vector<int> > Plateau;
typedef vector<int> Ligne; // création de l'alias Ligne

/** Des fonctions peuvent être ajoutés à ce fichier si besoin est (fonctions pour mettre à jour le score par exemple)
 **/

/** génère un Plateau de dimensions 4*4 ne contenant que des 0
 *  @return un Plateau vide
 **/
Plateau plateauVide();

/** génère deux nombres sur des cases aléatoires d'un Plateau vide
 *  @return un Plateau en début de jeu
 **/
Plateau plateauInitial();

/** génère aléatoirement un 2 ou un 4 avec des probabilités respectives de 9/10 et 1/10
 *  @return 2 ou 4
 **/
int tireDeuxOuQuatre();

/** génère une copie du Plateau et ajoute aléatoirement un 2 ou un 4
 * @return la copie du Plateau
 **/
Plateau ajouteCase(Plateau plateau);

/** génère une copie de la ligne et déplace les éléments de celle-ci vers la gauche
 * @return la copie de la ligne
 **/
Ligne triLigne(Ligne ligne);

/** additionne les éléments identiques d'une ligne si possible
 * @return ligne
 **/
Ligne empileLigne(Ligne ligne);

/** déplace les tuiles d'un Plateau vers la gauche et les combine si possible
 *  @param plateau le Plateau
 *  @return le Plateau une fois déplacé vers la gauche
 **/
Plateau deplacementGauche(Plateau plateau);

/** effectue une rotation du plateau de 90° vers la droite (sens horaire)
 *  @param copie une copie du plateau
 *  @return copie
 **/
Plateau rotation(Plateau plateau);

/** déplace les tuiles d'un Plateau vers la droite et les combine si possible
 *  @param plateau le Plateau
 *  @return le Plateau une fois déplacé vers la droite
 **/
Plateau deplacementDroite(Plateau plateau);

/** déplace les tuiles d'un Plateau vers le haut et les combine si possible
 *  @param plateau le Plateau
 *  @return le Plateau une fois déplacé vers le haut
 **/
Plateau deplacementHaut(Plateau plateau);

/** déplace les tuiles d'un Plateau vers le bas et les combine si possible
 *  @param plateau le Plateau
 *  @return le Plateau une fois déplacé vers le bas
 **/
Plateau deplacementBas(Plateau plateau);

/** on associe à chaque direction un entier :
*   haut : 1, bas : 2, droite : 3, gauche : 4
* le programme demande une direction à l'utilisateur et renvoie un entier selon la direction choisie :
* 1 si 'z', 2 si 's', 3 si 'd', 4 si 'q'
**/
int direction();

/** déplace les tuiles d'un Plateau dans la direction donnée et génère une nouvelle tuile si le déplacement est valide
 *  @param plateau le Plateau
 *  @param direction la direction
 *  @return le Plateau déplacé dans la direction
 **/
Plateau deplacement(Plateau plateau, int direction);

/** renvoie la valeur la plus grande d'un Plateau
 * @param plateau le Plateau
 * @param maxi l'élément le plus grand du plateau
 * @return maxi
 **/
int MaxiPlateau(Plateau plateau);

/** affiche un Plateau
 * @param plateau un Plateau
 **/
string dessine(Plateau p);

/** permet de savoir si une partie est terminée
 *  @param plateau un Plateau
 *  @return true si le plateau est vide, false sinon
 **/
bool estTermine(Plateau plateau);

/** permet de savoir si une partie est gagnée
 * @param plateau un Plateau
 * @return true si le plateau contient un 2048, false sinon
 **/
bool estGagnant(Plateau plateau);

/** affiche un Plateau avec le thème original du 2048
 * @param plateau un Plateau
 * @param window une fenêtre
 **/
void gdessine(Plateau plateau, RenderWindow& window);

/** affiche un Plateau avec un thème rose
 * @param plateau un Plateau
 **/
void gdessine2(Plateau plateau, RenderWindow& window);

/** le jeu classique, avec les couleurs du vrai 2048
 * @param window une fenêtre
 **/
int jeu(RenderWindow& window);

/** le jeu classique, avec un thème rose
 * @param window une fenêtre
 **/
int jeu2(RenderWindow& window);

/** une variante de jeu, avec le thème original
 * @param window une fenêtre
 **/
int jeu3(RenderWindow& window);

/** une variante de jeu, avec le thème rose
 * @param window une fenêtre
 **/
int jeu4(RenderWindow& window);

int main();