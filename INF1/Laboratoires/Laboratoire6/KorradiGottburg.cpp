/*
 -------------------------------------------------------------------------------
 Laboratoire  : Laboratoire 06
 Fichier      : KorradiGottburgLabo6.cpp

 Auteurs      : - Michael Gottburg (INF1)
			    - Frederic Korradi (INF1)

 Dates        : - 15.11.2016 (debut du projet)
			    - 16.11.2016 (rendu du projet)

 Buts         : - Chapitre 3a et 3b | Utilisation de boucles

 Remarque(s)  : - Aucune remarque particuliere

 Compilateurs : - MinGW-g++ 4.8.1 (Windows)
			    - gcc version 4.9.2 (Linux)
 -------------------------------------------------------------------------------
*/

#include <iostream>

using namespace std;

int main() {
	//Declaration des variables
	int input = 1;
	int inputCount = 0;
	int lastInput = 0;
	int repetitionCount = 0;
	bool isIncreasing = true;

	//Debut du programme
	cout << "Valeurs : ";
	while (input) {
		cin >> input;
		if (!cin.fail()) {
			if (lastInput) { // Aucun traitement sur le premier nombre saisi
				if (input != lastInput) { //si last input vaut 0, premier nbr
					inputCount++;
					if (repetitionCount) {
						cout << ++repetitionCount << 'x';
						repetitionCount = 0; // Reinitialisation du compteur
					}
					if (input) {
						if (input < lastInput) {
							isIncreasing = false; // La suite n'est pas croissante
						}
						cout << lastInput << ',';
					}
					else {
						cout << lastInput; // Derniere valeur avant le 0
					} // Affichage sans virgule
				}
				else {
					repetitionCount++;
				}
			}
			lastInput = input;
		}
		else {
			cout << "Erreur : Un ou plusieurs des caracteres saisis ne sont pas des entiers." << endl;
			return 1; // Retour de 1 pour arrêter le programme en erreur.
		}
	}

	if (inputCount > 1) {
		/* Affichage du type de suite (croissante ou non) en fonction de isIncreasing */
		cout << endl << "Suite " << (isIncreasing ? "croissante" : "non croissante") << endl;
	}
	else {
		cout << endl << (inputCount ? "Une seule valeur saisie." : "Aucune valeur saisie.") << endl;
	}
	return 0;
}
