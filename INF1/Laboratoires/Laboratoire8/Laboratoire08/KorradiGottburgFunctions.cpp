#include "KorradiGottburgFunctions.h"

/**
* \mainpage Definition des fonctions
* \file Functions.cpp
* \brief Definition des fonctions
* \details Definition des prototypes contenus dans le fichier Functions.h
* \author Frederic Korradi
* \author Michael Gottburg
* \version 1.0
* \date 2016-11-29
* \warning Tout fonctionne bien
* \remark Notre code est parfait
* \copyright GNU Public License and HEIG-VD
*/





bool inRange(int value, int min, int max) {
	return (value >= min && value <= max ? true : false);
}

int getInput(const string& MESSAGE, int max, int min) {
	int value = 0;
	cout << MESSAGE;

	while (!(cin >> value) || !(inRange(value, min, max))) {
		cin.clear();
		cin.ignore(numeric_limits<int>::max(), '\n');
		cout << MESSAGE;
	}
	cin.ignore(numeric_limits<int>::max(), '\n');
	return value;
}

void printCharNTimes(int nTimes, char charToPrint) {
	cout << setw(nTimes) << setfill(charToPrint) << "";
}

int initialize(int choice, int tab1[]) {
	return;
}

void copyTab1InTab2(int tab1[], int tab2[],const short& SIZE){
	for (int index = 0; index < SIZE; index++) {
		tab2[index] = tab1[index];
	}
	return;
}
void printTab(int tab[], const string& TEXTE) {
	cout << TEXTE << endl;
	const unsigned long long length = sizeof(tab); // demander à la prof si on doit passer la taille en paramètre ou faire un sizeof??? !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	for (int index = 0; index < length; index++) {
		cout << tab[index] << ' ';
	}
	cout << endl;
}
int deleteDuplicatesTab2(int tab2[], const short& SIZE) {
	for (int index = 0; index < SIZE; index++) {
		for (int index2 = 0; index2 < SIZE; index++) {
			if (tab2[index] != tab2[index2]){
				//TODO comment  faire quand on a un doublon?
			}
		}
	}
	return;
}
int sortTabs(int tab1[], int tab2[]) {
	return;
}
int insertInTab2IncrementedValuesAfterPairValues(int tab2[]) {
	return;
}
int initializeTab3WithTab1AndCompareThem(int tab1[]) {
	return;
}
void switchPos(int tab[], int x, int y) {
	int temp = tab[x];
	tab[x] = tab[y];
	tab[y] = temp;
}
int maxPos(int tab[], int size) {
	int pos = 0;
	int max_pos = 0;

	while (pos < size) {
		if (tab[pos] > tab[max_pos]) {
			max_pos = pos;
			pos++;
		}
	}
	return;
}
void triSelection(int tab[], int size) {
	int max_pos;
	const int INC = 1;
	for (; size > INC; size--) {
		max_pos= maxPos(tab, size);

		switchPos(tab, size - 1, max_pos);
	}
}
/*1: initialize
* 2: copie
* 3: print
* 4: delete
* 5: sort
* 6: insert
* 7: compare
*/
