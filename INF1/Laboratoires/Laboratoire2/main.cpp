/*
 -----------------------------------------------------------------------------------
 Laboratoire :  Lab02
 Fichier     :  GottburgFournierlabo2.cpp
 Auteur(s)   :  Michael Gottburg
                Robin Fournier
 
 Date        :  29.09.2016

 But         :  Calculer le prix d'une course en fonction de divers paramètres
                liés à celle-ci

Remarque(s) :	
============================================== Tests ================================================
|       Valeurs         |               Résultat(s)                 |   Remarque                    |
|   10, 0, 1, 3         |   28.5, 0, 28.35, 4.9(4.948)=> 66.75      |   OK                          |
|   9000, 850, 10000, 10|   25650, 382.5, 270005, 23683.3 (23683.4) |   Problème d'arrondi(-10 ct)  |
|                       |               => 319725.-                 |   et precision du cout insuff.|
|   0, 0, 0, 0          |   0, 0, 0, 0.4 (0.4) => 5.4               |	OK                          |
|   -10, -15, -58, -4   |   -28.5, -6.75, -1567.8, -127.85(-127.844)|	OK                          |
|                       |               => -1725.9                  |                               |
|   a,,,                |   0, 0, 0, 0.4 (0.4) => 5.4               |   empêche la saisie, OK       |
|   1, 2, 3, b          |   2.85, 0.9, 81, 7.18 (7.18) => 96.93     |   problème d'arrondi          |
|   10000000, 1500000000|   2.85e+007, 6.75e+008, -4.56368e+008,    |   dépacement des limites du   |
|   18888888, 9999999999|       1.97706e+007 => 2.66903e+008        |       int -> nmbre négatif    |
|   1.1, 2.2, 3.3, 4.4	|   3.135, 0.99, 81, 7.2 (7.21) => 97.335   |   OK                          |
=====================================================================================================
 
 Compilateur : gcc version 4.9.2 (Debian 4.9.2-10) & MinGW-g++ 4.8.1
 -----------------------------------------------------------------------------------
 */

#include <cstdlib>
#include <iostream>
#include <cmath>

using namespace std;

int main() {
    /* Constantes */
    const int PRIX_PRISE_EN_CHARGE = 5;
    const float TAXE = 0.08;
    const float PRIX_KM_HORS_VILLE = 0.45;
    const float PRIX_KM_VILLE = 2.85;
    const float PRIX_MINUTE = 0.45;

    /* Declaration / Initialisation */
    int nb_heures_course = 0;
    int nb_minutes_course = 0;
    int nb_minutes_total = 0;
    float nb_km_ville = 0;
    float nb_km_hors_ville = 0;
    double prix_km_ville = 0;
    double prix_km_hors_ville = 0;
    double prix_km_total = 0;
    double prix_duree = 0;
    double prix_total = 0;
    double prix_taxe = 0;
    double prix_taxe_arrondi = 0;

    /* Saisie des valeurs */
    std::cout << "Nombre de kilometres parcourus en ville : ";
    cin >> nb_km_ville;

    std::cout << "Nombre de kilometres parcourus hors ville : ";
    cin >> nb_km_hors_ville;

    std::cout << "Nombre d'heures qu'a dure la course  : ";
    cin >> nb_heures_course;

    std::cout << "Nombre de minutes qu'a dure la course  : ";
    cin >> nb_minutes_course;

    /* Calcul du prix en fonction de la distance */
    prix_km_ville = nb_km_ville * PRIX_KM_VILLE;
    prix_km_hors_ville = nb_km_hors_ville * PRIX_KM_HORS_VILLE;
    prix_km_total = prix_km_ville + prix_km_hors_ville;

    /* Calcul du prix en fonction de la duree */
    nb_minutes_total = (nb_heures_course * 60) + nb_minutes_course;
    prix_duree = nb_minutes_total * PRIX_MINUTE;

    /* Calcul du total et de la taxe */
    prix_total = PRIX_PRISE_EN_CHARGE + prix_km_total + prix_duree;
    prix_taxe = prix_total * TAXE;

    // arrondi au 5ct inf si nécessaire:
    prix_taxe_arrondi = floor((prix_taxe * pow(10, 1)) + 0.051) / pow(10, 1);

    /* Affichage de la facture */
    std::cout << endl << endl << "=========== FACTURE ===========" << endl;
    std::cout << "Tarif prise en charge : " << PRIX_PRISE_EN_CHARGE << " CHF." << endl;

    std::cout << "Nombre de kilometres parcourus en ville : " << nb_km_ville << " Km." << endl;
    std::cout << "Cout des kilometres parcourus en ville : " << prix_km_ville << " CHF." << endl;
    std::cout << "Tarif : " << PRIX_KM_VILLE << " CHF/Km ." << endl << endl;

    std::cout << "Nombre de kilometres parcourus hors ville : " << nb_km_hors_ville << " Km." << endl;
    std::cout << "Cout des kilometres parcourus hors ville : " << prix_km_hors_ville << " CHF." << endl;
    std::cout << "Tarif : " << PRIX_KM_HORS_VILLE << " CHF/Km ." << endl << endl;

    std::cout << "Duree de la course : " << nb_minutes_total << " min." << endl;
    std::cout << "Cout en fonction du temps de la course : " << prix_duree << " CHF." << endl;
    std::cout << "Tarif : " << PRIX_MINUTE << " CHF/min ." << endl << endl;

    std::cout << "Sous total : " << prix_total << " CHF." << endl;

    /* AJout de la taxe pour obtenir le prix final */
    prix_total += prix_taxe_arrondi;

    std::cout << "TVA : " << TAXE * 100 << "% ." << endl;
    std::cout << "Valeur ajoutee : " << prix_taxe_arrondi << " CHF. (" << prix_taxe << ")" << endl << endl << endl;
    std::cout << "Total : " << prix_total << " CHF." << endl;
    std::cout << "===============================" << endl;

    return 0;
}
