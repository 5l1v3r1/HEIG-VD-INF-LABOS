/*
 -----------------------------------------------------------------------------------
 Laboratoire : 05
 Fichier     : DoValeFournier.cpp
 Auteur(s)   : Kevin Do Vale
               Robin Fournier
  
 Date        : 10.11.2016

 But         : Écrire un programme qui saisit au clavier une valeur de type float et
               qui affiche ce nombre en binaire selon la Norme IEEE-754 sur 32 bits.
               Les 3 champs seront affichés séparément:
                - 1 bit pour le signe
                - 23 bits pour la mantisse
                - 8 bits pour l'exposant

 Remarque(s) :  
========================================== Tests ========================================
|    Valeurs    |               Résultat(s)                 | Remarque                  |
|   1234567890  |   0, 00100110010110000000110, 10011101    |     OK                    |
|   0.000083    |   0, 01011100001000001001001, 01110001    |     OK                    |
|   12.6        |   0, 10010011001100110011010, 10000010    |     OK                    |
|   -1234567890 |   1, 00100110010110000000110, 10011101    |     OK                    |
|   -0.000083   |   1, 01011100001000001001001, 01110001    |     OK                    |
|   -12.6       |   1, 10010011001100110011010, 10000010    |     OK                    |
|   23456.76543 |   0, 01101110100000110001000, 10001101    |     OK                    |
|   -2.5        |   1, 01000000000000000000000, 10000000    |     OK                    |
|   test        |   message erreur saisie                   |     OK                    |
|123456789101112|                   -                       | problème : boucle infinie |
|    13141      |                                           |    dûe au cast en long    |
=========================================================================================

 Compilateur : MinGW-g++ 4.8.1 et Ubuntu g++ 5.4.0
 -----------------------------------------------------------------------------------
 */


#include <cstdlib>
#include <iostream>
#include <limits>

using namespace std;

int main(int argc, char** argv) {

   const unsigned int MAX_BITS_MANTISSE = 23;
   const unsigned int MAX_BITS_EXPOSANT = 8;
   const int MIN_EXPOSANT = -126;
      
   float floatValeur;
   
   string strMantisse;
   string strExposant;
   
   
   cout << "Entrez une valeur de type float : ";
   cin >> floatValeur;
   
   while(cin.fail()) { 
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      cout << "Valeur incorrecte ! \nEntrez une valeur de type float : ";
      cin >> floatValeur;
   }
   
   bool signe = floatValeur < 0;
   
   //Récupère la valeur absolue pour traiter celle ci
   if (signe) {
      floatValeur = - floatValeur;
   }
  
   ////// CALCUL DE L'EXPOSANT /////
   
   double exposant = 0;
   
   double minPuissanceDe2 = 1;
   
   for(int i =0; i > MIN_EXPOSANT; i--){
      minPuissanceDe2 /= 2; // remplace le pow(2, MIN_EXPOSANT)
   }
   
   //Calcul de l'exposant
   for (double val =  minPuissanceDe2; val <= floatValeur; val*=2) {
      exposant++;
   }
   
    int intExposant = exposant;
    
   //Transforme l'exposant en binaire
   while (intExposant >= 1){
      
      if (intExposant % 2 == 0){
         strExposant = '0' + strExposant;
      }
      else{
         strExposant = '1' + strExposant;
      }

      intExposant /= 2;
   }

   // Rajoute les bits manquant si nécessaire
   for (int i = strExposant.length() ; i < MAX_BITS_EXPOSANT; i++) {
      strExposant = '0' + strExposant;
   }
   
   //////CALCUL DE LA MANTISSE ////
   
   
   //Sépare la partie entière et décimale
   float partieInt = (long) floatValeur;
   float partieDecimal = floatValeur - partieInt;
  
   
   //Crée la mantisse de la partie entière
   while (partieInt >= 1){
      
      if ((partieInt / 2) - ((long long)(partieInt / 2)) == 0) {
         strMantisse = '0' + strMantisse;
      }
      else{
         strMantisse = '1' + strMantisse;
      }
      
      partieInt /= 2;
      partieInt = (long long)partieInt; //remplace le floor
   }

   //Rajoute la partie decimal
   while (partieDecimal != 1 && partieDecimal) {
      
      partieDecimal *= 2;
      if (partieDecimal == 1) {
         strMantisse += '1';
      } else if (partieDecimal > 1) {
         partieDecimal--;
         strMantisse += '1';
      } else {
         strMantisse += '0';
      }
      
   }
   
   // Code utiliser pour traiter les tout petits chiffres
   string tmp;
   if (exposant){
      
      tmp = "";
      int compteur = 0;
      while (strMantisse[compteur] != '1' && floatValeur){
         compteur++;
      }
   
      for (int bit = compteur + 1; bit < strMantisse.length(); bit++){
         tmp += strMantisse[bit];
      }
   }
   else {
      
      tmp = "";
      for (int i = 126; i < strMantisse.length(); i++) {
         tmp += strMantisse[i];
      }
   }
   
   strMantisse = tmp;
   
  
   ///// FORMATAGE, AFFICHAGE /////
   
   // Enlève les 0 en trop si nécessaire
   tmp = "";
   if (strMantisse.length() > MAX_BITS_MANTISSE) {
      for (int bit = 0; bit < MAX_BITS_MANTISSE; bit++){
         tmp += strMantisse[bit];
      }
      strMantisse = tmp;
   }
  
   // Rajoute les bits manquant si nécessaire
   for (int i = strMantisse.length() ; i < MAX_BITS_MANTISSE; i++) {
      strMantisse += '0';
   }
    
   //Affiche les résultats
   cout << "Signe    = " << signe << endl;
   cout << "Mantisse = " << strMantisse << endl;
   cout << "Exposant = " << strExposant << endl;

   
   return 0;
}