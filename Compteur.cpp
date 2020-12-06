#include <iostream>
#include <cstring>
#include "Compteur.h"
#include "Mot.h"
/**
 * @file Compteur.cpp
 * Projet SDA_Boggle
 * @author GOICHOT, GULDAS
 * @version 1 - 06/12/2020
 * @brief Le Compteur de point
 * Structures de données et algorithmes - DUT1 Paris Descartes
 */
/**
* @brief Compte le nombre de point de la liste saisi
*/
void Compteur() {
	Mot buffer;
	unsigned int NbPoint = 0;
	unsigned int Taille;
	do {
		saisir(buffer);
		Taille = strlen(buffer);
		if (Taille <= 2) {
			NbPoint += 0;
		}
		else if (Taille == 3 || Taille == 4)
		{
			NbPoint += 1;
		}
		else if (Taille == 5)
		{
			NbPoint += 2;
		}
		else if (Taille == 6)
		{
			NbPoint += 3;
		}
		else if (Taille == 7)
		{
			NbPoint += 5;
		}
		else if (Taille >= 8)
		{
			NbPoint += 11;
		}
	} while (strcmp(buffer, "*") == 1);
	std::cout << NbPoint;
}
