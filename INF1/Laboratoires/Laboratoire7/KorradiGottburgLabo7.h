/** Doxygen commentaries
* \file
* \brief
* \details
* \author
* \date
* \version
* \copyright
* \remarks si plusieurs lignes
* \remark si une seule ligne
*/

#include <string>
#include <limits>

using namespace std;
/**
* \brief Fonction exercice1 : Demande un nombre à l'utilisateur et le passe à la fonction isPerfectSquare.
* \details La fonction  a pour but de demander un nomber à l'utilisateur tant que ce n'est pas un nombre entier, puis de le passer à la fonction isPerfectSquare afin de déterminer si c'est un carré parfait. Le résultat sera ensuite affiché.
* \remark La fonction ne reçoit aucun argument en paramètre.
*/
void exercice1(int value);


/**
* \brief Fonction exercice2 : Demande un nombre à l'utilisateur et le passe à la fonction displayDiamond.
* \remark La fonction ne reçoit aucun argument en paramètre.
* \details La fonction  a pour but de demander un nombre à l'utilisateur et le passe à la fonction displayDiamond.
*/
void exercice2(int value);


/**
* \brief Fonction exercice4 : Demande un nombre entier positif à l'utilisateur et le passe à la fonction displayFibonacci.
* \remark La fonction ne reçoit aucun argument en paramètre.
* \details La fonction  a pour but de demander un nombre entier positif (la saisie est contrôlée et redemandée tant qu'elle est incorrect) et de le passer à la fonction displayFibonacci.

*/
void exercice4();


/**
* \brief Fonction exercice5 : Demande une suite de charactères à l'utilisateur afin d'en afficher les détails
* \remark La fonction ne reçoit aucun argument en paramètre.
* \details La fonction  a pour but de demander une suite de charactère à l'utilisateur, qui se terminera avec un #. Le nombre de charactères, le nombre de mot, la longueur max des mots ainsi que le nombre de charactères non alpha-numériques sera affiché.
*/
void exercice5();


/**
* \brief Fonction afficher : Affiche le nombre de fois qu'elle est appelée
* \remark La fonction ne reçoit aucun argument en paramètre.
* \details La fonction  a pour but d'afficher le nombre de fois qu'elle à été appelée. Pour cela, une variable globale est incrémentée à chaque appel, et c'est celle-là qu'on affiche.
*/
void afficher(unsigned int& count);


/**
* \brief Fonction displayDiamond : affiche un losange selon le nombre en entrée
* \param[in] int nombre : Paramètre d'entrée de type entier
* \details La fonction  a pour but d'afficher un losange composé de '*' vaec 2*n-1 lignes

*/
void displayDiamond(int value);


/**
* \brief Fonction displayFibonacci : affiche le nombre saisi d'itérations de la suite de Fibonacci.
* \param[in] int nombre : Paramètre d'entrée de type entier
* \details La fonction  a pour but d'afficher la suite de Fibonacci pour le nombre d'itérations saisi en entrée par l'utilisateur.
*/
void displayFibonacci(int value);

/**
*
*
*
*/

int get_input(string message, int max, int min = 1);
