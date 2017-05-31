/**
* \file Laboratoir10KorradiGottburgMain.cpp
* \brief Programmes de facturation
* \details Programmes de facturation. Lis 4 fichiers ETgénère les factures.
* Tout d'abord le programme charge les quatres fichiers client commande 
* detail et produit, chacun stocké dans un vecteur de string different. 
* Ensuite, le vecteur contenant les commandes est parcouru et pour chaque 
* commande une série d'action va être effectuée
* 1: la ligne de la commande est splitee en trois string stockés un nouvel 
* 		array et les données numero de commande, 
* et date de commande sont stockés dans des variables indépendantes.
* 2: On ajoute dans un vecteur bill les données du client en fonction du 
*		numéro de client.
* 3: on récupère les données des produits.
*	pour cela:
*	- on ajoute le numéro d commande et la date de commande dans le vecteur bill
*	- on parcours le vecteur des détails. pour chaque détails correspondant 
*		à la commande,
*	- on parcours le vecteur contenant les produits. Pour chaque produit correspondant 
*		au détail, on ajout les données n°produit, libelle nombre prix et total 
* 	 au vecteur bill.
* 4: un fichier de facture est cree avec chaque element du vecteur bill et le texte 
*	s'y correspondant.
* \author Frederic Korradi
* \author Michael Gottburg
* \version 1.0
* \date 2016-12-20
* \copyright GNU Public License and HEIG-VD
*/

#include <cstdlib>
#include <iostream>
#include <iomanip>    
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;
using vstring = vector<string>; //create type alias vector<string> to vstring
using vstring_iter = vstring::iterator;

vstring readFile(const string &filename);
void writeFile(const string &filename, const vstring bill);
vstring splitLine(string order);
void getCustomerData(const string customer_number, const vstring &customers, vstring &bill);
void getProductData(const string order_number, const string order_date, const vstring details, const vstring &products, vstring &bill);

int main() {
    unsigned short flag = 0;
    const string FILE_CUSTOMER = "client.csv";
    const string FILE_ORDER = "commande.csv";
    const string FILE_DETAIL = "detail.csv";
    const string FILE_PROUDCT = "produit.csv";

    vstring orders = readFile(FILE_ORDER);
    vstring products = readFile(FILE_PROUDCT);
    vstring customers = readFile(FILE_CUSTOMER);
    vstring details = readFile(FILE_DETAIL);

    string order_number;
    string customer_number;
    string order_date;

    for (vstring_iter i = orders.begin(); i != orders.end(); i++) {
        vstring bill;
        vstring order = splitLine(*i);
        order_number = order.front();
        customer_number = order.at(1);
        order_date = order.at(2);
        
        getCustomerData(customer_number, customers, bill);
        getProductData(order_number, order_date, details, products, bill);
        writeFile(order_number + ".txt", bill);
    }

    return 0;
}

void getCustomerData(const string customer_number, const vstring &customers, vstring &bill) {
    for (unsigned int i = 0; i < customers.size(); i++) {
        vstring customer = splitLine(customers.at(i));
        if (customer_number == customer.front()) {
            bill.push_back("Numero : " + customer.front());
            bill.push_back("Nom : " + customer.at(1));
            bill.push_back("Ville : " + customer.at(2));
        }
    }
}

void getProductData(const string order_number, const string order_date, const vstring details, const vstring &products, vstring &bill) {
	bill.push_back("Commande : " + order_number);
	bill.push_back("Date : " + order_date);
	for (unsigned int i = 0; i < details.size(); i++) {
		vstring detail = splitLine(details[i]);
        if (order_number == detail[0]) {
            for (unsigned int j = 0; j < products.size(); j++) {
                vstring product = splitLine(products.at(j));
                if (detail.at(1) == product.front()) {
                    bill.push_back(product.front());
                    bill.push_back(product.at(1));
                    bill.push_back(detail.at(2));
                    bill.push_back(product.at(2));
                    bill.push_back(to_string(stoi(product.at(2)) * stoi(detail.at(2))));
                }
            }
        }
    }
}
vstring splitLine(string order) {
    vstring splitted_line(3);

    istringstream ist(order);
    ist >> splitted_line.front() >> splitted_line.at(1) >> splitted_line.at(2); 
	// Extraire dess strings de la ligne


    return splitted_line;
}

int errorHandler(unsigned short flag) {

    if (flag) {
        switch (flag) {
            case 1: cout << "Erreur : Un des fichiers n'existe pas." << endl;
                break;
            case 2: cout << "Erreur : un des fichiers est vides." << endl;
                break;
            case 3: cout << "Erreur : Un des fichiers est incomplet ou comporte "
						 << "des erreurs." << endl;
                break;
            case 4: cout << "Erreur: Impossible d'ouvrir le fichier en lecture." << endl;
                break;
        }
        return 1;
    }
}

vstring readFile(const string &filename) {
    ifstream file(filename);
    vstring file_content;
    if (file) {
        //L'ouverture s'est bien pass�e, on peut donc lire

        string line; // Pour stocker une ligne lue
        while (getline(file, line)) //Tant que le fichier n'est pas vide on lit une ligne
        {
            istringstream ist(line); // Pour permettre d'extraire les valeurs de la ligne
            string chaine; // Variables pour extraction
            int val;

            ist >> chaine >> val; // Extraire une chaine et un entier de la ligne lue

            //add
            file_content.push_back(line);
        }
        file.close();
    } else {
        errorHandler(4);
    }
    return file_content;
}

void writeFile(const string &filename, const vstring bill) {
	ofstream file(filename);
	unsigned int i = 0;
	for (; i < 5; i++) {
		file << bill.at(i) << endl;
	}
	//i++;
	unsigned int j = 0;
	file << setw(12) << left << "N° Produit" << setw(25) << "Libelle" << setw(8) 
		 << "Nombre" << setw(9) << "Prix" << "Total" << endl;
				//12			25			8			6
	while (i < bill.size()) {
		j = (i + 5) < bill.size() ? i+5 : bill.size();
		for (; i < j ; i = i+5) {
			file << setw(11) << bill.at(i) << setw(25) << bill.at(i+1) << setw(8) 
				 << bill.at(i+2) << setw(9) << bill.at(i+3) << bill.at(i+4);
		} 
		file << endl;
	}
    file.close();
}