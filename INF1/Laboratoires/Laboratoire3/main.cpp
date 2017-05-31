/*
---------------------------------------------------------------------------------
Laboratoire : Laboratoire 3
Fichier     : Korradi_Gottburg_Fournier.cpp
Auteur(s)   : Michael Gottburg
              Robin Fournier
              Frédéric Korradi

Date        : 06.10.2016

But         : Chapitres 1 et 2

Remarque(s) : Le programme ne fait aucun test. Si la saisie n'est pas correcte,
si autre chose que des enteiers positifs différets de zéro  (et supérieurs à 
quelques centaines de milions pour l'exercice 2.13)sont insérés, il pourra avoir 
des comportements bizzares.

Test(s)		: 
Pour l'exercice 2.11

1-	Avec des lettres, le programme est directement terminé.

====================================================================
Veuillez entrer r1 [cm]:
asdf
Veuillez entrer r2 [cm]:
Veuillez entrer h1 [cm]:
Veuillez entrer h2 [cm]:
Veuillez entrer h3 [cm]:
Volume total : -7473705422837147267337491982429699023260077014818229713612261046
57217135958038055653024307978404751423437069530614130328299808475833670721746556
0582183942004249763251343498174321532076032.00 cm3
====================================================================

2-	Avec des valeurs correctes :
====================================================================
Veuillez entrer r1 [cm]:
1
Veuillez entrer r2 [cm]:
1
Veuillez entrer h1 [cm]:
1
Veuillez entrer h2 [cm]:
1
Veuillez entrer h3 [cm]:
1
Volume total : 9.42 cm3
====================================================================

Pour l'exercice 2.13
1-	Avec des valeurs supérieurs à 2147483647, il affichera un nombre
	de chiffres incohérents.
========================== Exercice 2.13 ===========================

Veuillez saisir un nombre entier > 0 : 2147483647
Nombre saisi       : 2147483647
Nombre de chiffres : 10
Premier chiffre    : 2
Dernier chiffre    : 7
====================================================================
========================== Exercice 2.13 ===========================

Veuillez saisir un nombre entier > 0 : 2147483648
Nombre saisi       : 0
Nombre de chiffres : -2147483648
Premier chiffre    : 0
Dernier chiffre    : 0
====================================================================

2-	Avec 0 : 
========================== Exercice 2.13 ===========================

Veuillez saisir un nombre entier > 0 : 0
Nombre saisi       : 0
Nombre de chiffres : -2147483648
Premier chiffre    : 0
Dernier chiffre    : 0
====================================================================

3-	Avec un nombre négatif supérieur à 9:
========================== Exercice 2.13 ===========================

Veuillez saisir un nombre entier > 0 : -456
Nombre saisi       : -456
Nombre de chiffres : 3
Premier chiffre    : -5
Dernier chiffre    : -6
====================================================================

4-	Avec des lettres : 
========================== Exercice 2.13 ===========================

Veuillez saisir un nombre entier > 0 : asdf
Nombre saisi       : 0
Nombre de chiffres : -2147483648
Premier chiffre    : 0
Dernier chiffre    : 0
====================================================================

5-	Avec un nombre correct : 
========================== Exercice 2.13 ===========================

Veuillez saisir un nombre entier > 0 : 123
Nombre saisi       : 123
Nombre de chiffres : 3
Premier chiffre    : 1
Dernier chiffre    : 3
====================================================================

Compilateur : MinGW-g++ 4.8.1
---------------------------------------------------------------------------------
*/
#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>

using namespace std;

int main() {

	//Exercice 2.11
	const double PI = atan(1) * 4;
	double r1, r2, h1, h2, h3;
	cout << "========================== Exercice 2.11 ===========================" << endl << endl;
	cout << "               r1" << endl;
	cout << "              |--|" << endl;
	cout << "          ........      -" << endl;
	cout << "          ||||||||      | h2" << endl;
	cout << "         /        \\     -" << endl;
	cout << "        /          \\    |" << endl;
	cout << "       /            \\   | h3" << endl;
	cout << "       |------------|   -" << endl;
	cout << "       |            |   |" << endl;
	cout << "       |            |   |" << endl;
	cout << "       |            |   |" << endl;
	cout << "       |            |   |" << endl;
	cout << "       |            |   |" << endl;
	cout << "       |            |   |" << endl;
	cout << "       |            |   |" << endl;
	cout << "       |            |   | h4" << endl;
	cout << "       |            |   |" << endl;
	cout << "       |            |   |" << endl;
	cout << "       |            |   |" << endl;
	cout << "       |____________|   -" << endl;
	cout << "              |-----|" << endl;
	cout << "                 r2" << endl;
	cout << endl << endl;

	cout << "Veuillez entrer r1 [cm]:" << endl;
	cin >> r1;
	cout << "Veuillez entrer r2 [cm]:" << endl;
	cin >> r2;
	cout << "Veuillez entrer h1 [cm]:" << endl;
	cin >> h1;
	cout << "Veuillez entrer h2 [cm]:" << endl;
	cin >> h2;
	cout << "Veuillez entrer h3 [cm]:" << endl;
	cin >> h3;

	double volCylindre1 = PI * pow(r1, 2) * h1;
	double volCylindre2 = PI * pow(r2, 2) * h2;
	double volCone = (h3 * PI / 3)*(pow(r1, 2) + pow(r2, 2) + r1 * r2);
	double volTot = volCylindre1 + volCylindre2 + volCone;
	cout << setprecision(2);
	cout << fixed;
	cout << "Volume total : " << volTot << " cm3" << endl;
	cout << "====================================================================" << endl;

	//Exercice 2.13
	cout << "========================== Exercice 2.13 ===========================" << endl << endl;

	int saisieUtilisateur = 0, nbChiffres = 0, nbFirstChiffre = 0, nbLastChiffre = 0;
	cout << "Veuillez saisir un nombre entier > 0 : ";
	cin >> saisieUtilisateur;

	nbChiffres = floor(log10(abs(saisieUtilisateur))) + 1;
	nbFirstChiffre = floor(saisieUtilisateur / pow(10, nbChiffres - 1));
	nbLastChiffre = saisieUtilisateur % 10;

	cout << "Nombre saisi       : " << saisieUtilisateur << endl;
	cout << "Nombre de chiffres : " << nbChiffres << endl;
	cout << "Premier chiffre    : " << nbFirstChiffre << endl;
	cout << "Dernier chiffre    : " << nbLastChiffre << endl;
	cout << "====================================================================" << endl;
}
