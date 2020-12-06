/**
 * @file Mot.cpp
 * Projet SDA_Boggle
 * @author GOICHOT, GULDAS
 * @version 1 - 06/12/2020
 * @brief Composant de Mot
 * Structures de données et algorithmes - DUT1 Paris Descartes
 */

#include "Mot.h"
#include <iostream>
/**
* @brief Recupère le mot saisi
* @param[in] id : le conteneur du Mot
*/
void saisir(Mot id) {
	std::cin >> id;
}

/**
 * @brief Affiche un Mot
 * @param[in] d : le Mot à afficher
 */
void afficher(char* d) {
	for (unsigned int i = 0; i < strlen(d); i++)
	{
		std::cout << d[i];
	}
	std::cout << std::endl;
}
