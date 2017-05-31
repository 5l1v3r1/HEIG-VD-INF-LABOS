/*
 -----------------------------------------------------------------------------------
 Laboratoire : 04
 Fichier     : Fournier_Mbassi.cpp
 Auteur(s)   : Vladimir Mbassi
               Robin Fournier
 Date        : 12.10.2016

 But         : - Instructions conditionnelles
               - Vérification des valeurs saisies

 Remarque(s) :
 ============================================== Tests ===============================================
|       Valeurs         |               Résultat(s)                 |   Remarque                    |
|   0, 2, 3, 4          |   Message erreur saisie                   |   OK                          |
|   2, 0, 3, 4          |   Message erreur saisie                   |   OK                          |
|   2, 3, 0, 4          |   Message erreur saisie                   |   OK                          |
|   2, 3, 4, 0          |   Message erreur saisie                   |   OK                          |
|   a, , ,              |   Message erreur saisie                   |   OK                          |
|   -1, 2, 3, 4         |   Message erreur saisie                   |   OK                          |
|   2, 3, 4, 11         |   Message: Colis hors norme : poids       |   OK                          |
|   50, 50, 50, 1       |   5.-, 6.-, -, 11.00.-, 0.85.-,  11.85.-  |   OK                          |
|   10, 20, 30, 7       |   5.-, 2.-, -, 7.00.-, 0.55.-,  7.55.-    |   OK                          |   
|   51, 20, 30, 1       |   Message: Colis hors norme : dimensions  |   OK                          |   
|   10, 51, 51, 1       |   Message: Colis hors norme : dimensions  |   OK                          |   
|   10, 10, 51, 1       |   Message: Colis hors norme : dimensions  |   OK                          |   
|   50, 50, 50, 4       |   5.-, 6.-, - , 11.00.-, 0.85.-, 11.85.-  |   OK                          |   
|   1, 1, 1, 8          |   5.-, -, 3.00 , 8.00.-, 0.60.-, 8.60.-   |   OK                          |   
|   4000000000000, , ,  |   Message erreur saisie                   |   OK                          |   
=====================================================================================================

 Compilateur : Ubuntu g++ 5.4.0
 -----------------------------------------------------------------------------------
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;

int main(int argc, char** argv) {
    
    bool saisieIncorrecte = false;
    
    int largeur, longueur, hauteur, poids;
    unsigned int taxePoids = 0, taxeVolume = 0;
    
    float taxeTTC=0.0,taxeTot=0.0, volume=0.0;
    const float TVA = 0.08;
    const unsigned int TAXE_NORM = 5, LIM_POIDS1 = 8, LIM_POIDS2 = 5,SUPP_POIDS1 = 2,
          SUPP_POIDS2 = 1, LIM_VOL1 = 33, LIM_VOL2 = 27,SUPP_VOL1 = 6, SUPP_VOL2 = 3,
          POIDS_MAX = 10, DIM_MAX = 50, FACTURE_WIDTH = 30;
    
    cout << "Veuillez saisir la longueur [cm] : " << endl;
    cin >> longueur;
    cout << "Veuillez saisir la largeur [cm]  : " << endl;
    cin >> largeur;
    cout << "Veuillez saisir la hauteur [cm]  : " << endl;
    cin >> hauteur;
    cout << "Veuillez saisir le poids [kg]    : " << endl;
    cin >> poids;
    
    if( (cin.fail()) || (longueur<=0 || largeur <=0 || poids <=0 || hauteur <=0 )){
        cout << "Erreur : saisie incorrecte, redemarrez le programme." << endl;
    }
    else if(poids > POIDS_MAX){
        cout << "Colis hors norme : poids trop eleve"<<endl;
    }
    else if(longueur > DIM_MAX || largeur > DIM_MAX || hauteur > DIM_MAX){
        cout << "Colis hors norme : une ou plusieurs dimension(s) trop elevee(s)"<< endl;
    }
    else{
        if(poids > LIM_POIDS1){
            //première surtaxe sur le poids
            taxePoids = (LIM_POIDS1-LIM_POIDS2)*SUPP_POIDS2;
            
            //seconde surtaxe sur le poids
            taxePoids += (poids - LIM_POIDS1) * SUPP_POIDS1;
        }
        else if (poids > LIM_POIDS2){
            //première surtaxe sur le poids
            taxePoids = (poids-LIM_POIDS2)*SUPP_POIDS2;
        }
        
        // cm3 -> dm3
        volume = longueur * largeur * hauteur /1000.0;
        
        if(volume > LIM_VOL1){
            taxeVolume = SUPP_VOL1;
        }
        else if(volume > LIM_VOL2){
            taxeVolume = SUPP_VOL2;
        }
        taxeTot = taxeVolume + taxePoids + TAXE_NORM;
           
        /* AJout de la taxe pour obtenir le prix final */
        int quotient = taxeTot * TVA * 100 / 5;
        taxeTTC = taxeTot + quotient * 5.0 / 100;
        
        cout << setprecision(2) << fixed;
        
        cout << endl << endl 
             << "===================== FACTURE ======================" << endl;
        cout << left << setw(FACTURE_WIDTH) 
             << "Taxe normale : " << float(TAXE_NORM) << " Frs." << endl;
        
        if(taxePoids > 0){
           cout << left << setw(FACTURE_WIDTH)
                << "Surtaxe poids : " << float(taxePoids) 
                << " Frs. (" << poids << " kg)" << endl; 
        }

        if(taxeVolume > 0){
           cout << left << setw(FACTURE_WIDTH)
                << "Surtaxe d'encombrement : " << float(taxeVolume)
                << " Frs. (" << volume << " dm3)" << endl; 
        }

        cout << endl << left << setw(FACTURE_WIDTH)
             << "Taxe sans TVA : " << taxeTot << " Frs." << endl;

        cout << left << setw(FACTURE_WIDTH)
             << "TVA : " << TVA * 100 << "%" << endl;
        cout << left << setw(FACTURE_WIDTH)
             << "Valeur ajoutee : " << taxeTTC - taxeTot 
             << " Frs. ("<< taxeTot * TVA << " Frs.)"<<endl<<endl;
        cout << left << setw(FACTURE_WIDTH)
             << "Total : " << taxeTTC << " Frs." << endl;
        cout << "====================================================" << endl;
    }
    return 0;
}

