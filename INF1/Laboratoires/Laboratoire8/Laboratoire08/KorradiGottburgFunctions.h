
#ifndef KORRADIGOTTBURGFUNCTIONS_H
#define KORRADIGOTTBURGFUNCTIONS_H

/**
* \mainpage A propos
* \subpage Exercice1
* \subpage Exercice2
* \subpage Exercice4
* \subpage Exercice5
* \subpage afficher
* \subpage getInput
* \subpage main
* \subpage inRange
* \subpage checkWordLength
* \subpage printCharNTimes
* \file Function.h
* \brief Prototypage des fonctions
* \details Prototype chaque fonctions du Functions.cpp
* \author Frederic Korradi
* \author Michael Gottburg
* \version 1.0
* \date 2016-11-29
* \warning Tout fonctionne bien
* \remark Notre code est parfait
* \copyright GNU Public License and HEIG-VD
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <limits>

using namespace std;
/**
* \page Exercice1
* \brief Fonction exercice1 : Verifie si le nombre recu en parametre est un nombre entier.
* \param[in] value : valeur saisie par l'utilisateur
* \details La fonction  a pour but de demander un nomber a l'utilisateur tant que ce n'est pas un nombre entier,
puis de le passer a la fonction isPerfectSquare afin de determiner si c'est un carre parfait. Le resultat sera ensuite affiche.
*/
void exercice1(int value);


/**
* \page Exercice2
* \brief Fonction exercice2 : Recoit un nombre saisi dans la fonction main et affiche un losange.
* \param[in] value : valeur saisie par l'utilisateur
* \details Recoit un nombre saisi dans la fonction principale et affiche un losange de 2 * n - 1 lignes (avec n : le nombre saisi).
*/
void exercice2(int value);


/**
* \page Exercice4
* \brief Fonction exercice4 : Recoit un nombre saisi dans la fonction main et affiche le premières occurences de la suite de Fibonacci
*
* La fonction  a pour but de demander un nombre entier positif (la saisie est contrôlee et redemandee tant qu'elle est incorrect) et
* de le passer a la fonction displayFibonacci.
*/
void exercice4(int value);


/**
* \page Exercice5
* \brief Fonction exercice5 : Demande une suite de characteres a l'utilisateur afin d'en afficher les details
* \remark La fonction ne recoit aucun argument en parametre car elle fait la saisie elle meme.
*
* La fonction  a pour but de demander une suite de charactere a l'utilisateur, qui se terminera avec un #. Le nombre de characteres,
* le nombre de mot, la longueur max des mots ainsi que le nombre de characteres non alpha-numeriques sera affiche.
*/
void exercice5();


/**
* \page afficher
* \brief Fonction afficher : Affiche le nombre de fois qu'elle est appelee
* \param[in,out] count : valeur affichee et incremeneee a chaque passage
*
* La fonction  a pour but d'afficher le nombre de fois qu'elle a ete appelee. Pour cela, une variable globale est incrementee
* a chaque appel, et c'est celle-la qu'on affiche.
*/
void afficher(unsigned int& count);

/**
* \page getInput
* \brief
* \param[in] message : Parammetre d'entree de type string qui donne le message affiche a l'ecran lors de la saisie.
* \param[in] max : Parametre d'entree de type entier qui definie la borne superieure de la saisie.
* \param[in] min : Parametre d'entree de type entier qui definie la borne inferieure de la saisie.
* \details
* \retval Value (valeur saisie par l'utilisateur
*/
int getInput(string const& message, int max, int min = 1);

/**
* \page inRange
* \brief Verifie que la saisie utilisateur est contenue entre les deux bornes max et min.
* \param[in] value : valeur saisie par l'utilisateur
* \param[in] max : Parametre d'entree de type entier qui definie la borne superieure de la saisie.
* \param[in] min : Parametre d'entree de type entier qui definie la borne inferieure de la saisie.
* \details Verifie que la valeur contenue dans value se situe bien entre les deux bornes max et min incluses.
* \retval value (valeur saisie par l'utilisateur).
*/
bool inRange(int value, int min, int max);

/**
* \page checkWordLength
* \brief Verifie si le mot courrant est plus long que le mot le plus long.
* \param[in,out] word_length_max : Parametre de type entier passe en reference contenant la taille du mot le plus long.
* \param[in] word_length : parametre de type entier qui contient la taille du mot a comparer avec word_length_max
*
* Cette fonction va comparer la taille du mot le plus long avec le mot courant. Si ce mot est plus long,
* il va changer la valeur de word_length_max, passe en reference.
*/
void checkWordLength(int& word_lenght_max, int word_length);

/**
* \page printCharNTimes
* \brief imprime un charactere n fois.
* \param[in] nTimes : parametre de type entier qui definit le nombre de fois que le charactere dois être affiche a l'ecran.
* \param[in] charToPrint : parametre de type char qui donne quel est le charactere a imprimer n fois.
* \details Cette fonction va imprimer le charactere contenu dans la variable charToPrint nTimes fois.
* \remark Obliger de print un string vide a la fin, sinon il n'y a rien a fill dans la ligne.
*/
void printCharNTimes(int nTimes, char charToPrint = ' ');


void initialize(int choice, int tab1[]);
int copyTab1InTab2(int tab1[], int tab2[], const short& size);

#endif
