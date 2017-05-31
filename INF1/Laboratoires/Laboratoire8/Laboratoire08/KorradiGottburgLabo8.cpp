/**
* \file Function.h
* \brief Prototypage des fonctions
* \details Prototype chaque fonctions du Functions.cpp
* \author Frederic Korradi
* \author Michael Gottburg
* \version 1.0
* \date 2016 - 11 - 29
* \warning Tout fonctionne bien
* \remark Notre code est parfait
* \copyright GNU Public License and HEIG - VD
*/

#include "KorradiGottburgFunctions.h"

using namespace std;


/*
* \page main
* \brief Fonction principale du programme.Elle va decider quoi faire en fonction de l'input de l'utilisateur.
* \retval 0 si le programme c'est bien execute

* Fonction principale du programme. Elle demande a l'utilisateur de saisir une valeur. Ensuite, la valeur est traitee dans un switch:
*	-0 : quit le programme
*	-1 : Appel la fonction getInput et la passe en parametre a l'appel de la fonction exercice1()
*	-2 : Appel la fonction getInput et la passe en parametre a l'appel de la fonction exercice2()
*	-3 : Appel la fonction afficher avec en parametre la variable globale call_count
*	-4 : Appel la fonction getInput et la passe en parametre a l'appel de la fonction exercice4()
*	-5 : Appel la fonction exercice5()
*/
int main() {
	const string MESSAGE_CHOICE = "Choix : ";
	const string MESSAGE_EXIT = "Aurevoir.";
	const short MAX_CHOICE = 5;

	const short LENGTHTAB1AND2 = 15;
	const short LENGTHTAB3COLUMNS = 3;
	const short LENGTHTAB3RAWS = 6;


	int choice = 1;
	int tab1[LENGTHTAB1AND2] = {1,2,3,5,6,7,8,9,10,11,12,13,14,15};
	int tab2[LENGTHTAB1AND2] = {20,2,3,5,18,7,8,9,13,11,12,13,14,17};
	int tab3[LENGTHTAB3RAWS][LENGTHTAB3COLUMNS];
	
	while (choice) {
		choice = getInput(MESSAGE_CHOICE, MAX_CHOICE, 0);
		copy(tab1, tab2, LENGTHTAB1AND2);
		/*1: initialize
		* 2: copie
		* 3: print
		* 4: delete
		* 5: sort
		* 6: insert
		* 7: compare
		*/	
	}
	return 0;
}
