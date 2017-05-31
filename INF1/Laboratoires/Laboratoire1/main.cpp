/*
 -----------------------------------------------------------------------------------
 Laboratoire	: 01
 Fichier		: fournier.cpp
 Auteur(s)	: Robin Fournier
 Date			: 22.09.2016
 Classe		: INF1-1-E

 But			:	En utilisant NetBeans, écrire le plus proprement possible un programme C++ qui :
						1) demande à l'utilisateur de saisir 2 nombres entiers val1 et val2
						2) affiche à l'écran : la somme, la différence, le produit et le quotient de val1 et val2
						3) échange les valeurs des 2 variables et affiche à l’écran leur nouvelle valeur

 Remarque(s) :	=========================== Tests ===============================
				|	Valeurs		|			Résultat(s)			|	Remarque	|
				|	12 et 10	|	22, 2, 120, 1 reste 2		|		OK		|     
				|	a			|	message erreur (géré)		|		OK		|
				|	7 et aaa	|	message erreur (géré)		|		OK		|
				|				|	géré par C++				|		OK		|
				|	10 et 3		|	13, 7, 30, 3 reste 1		|		OK		|
				|	-5 et 89	|	84, -94, -445, 0 reste -5	|		OK		|
				|	-10 et -2	|	-12, -8, 20, 5 reste 0		|		OK		|
				=================================================================

 Compilateur : MinGW-g++ 4.8.1
 -----------------------------------------------------------------------------------
 */


#include <cstdlib>
#include <iostream>
#include <string>
#include <limits>

using namespace std;

int main(int argc, char** argv) {
	int iVal1 = 0, iVal2 = 0, iTemp = 0;

	cout << "Bonjour,\nVeuillez saisir un premier nombre s'il vous plait : ";
	cin >> iVal1; // saisie du nombre 1
	cout << "Puis un deuxieme s'il vous plait : ";
	cin >> iVal2; // saisie du nombre 2

	if (!cin.fail()) { // teste si il y a eu une exception lors de la saisie des nombres

		// affichage des valeurs pour chaque opération
		cout << endl << iVal1 << " + " << iVal2 << " = " << iVal1 + iVal2 << endl;
		cout << iVal1 << " - " << iVal2 << " = " << iVal1 - iVal2 << endl;
		cout << iVal1 << " * " << iVal2 << " = " << iVal1 * iVal2 << endl;
		cout << iVal1 << " / " << iVal2 << " = " << iVal1 / iVal2
			<< " reste " << iVal1 % iVal2 << endl;

		// échange des valeurs entre les deux variables et affichage
		iTemp = iVal2;
		iVal2 = iVal1;
		iVal1 = iTemp;
		cout << "\nLes nombres etaient " << iVal1 << " et " << iVal2 << " .\n";
	} else {

		// si exception lors de la saisie des nombres
		cout << "\n\nLes valeurs saisies sont incorrectes, redemarrez le programme et reessayez." << endl;
	}
	return 0;
}

