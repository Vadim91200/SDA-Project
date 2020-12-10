#include <iostream>
#include <cstring>
#include "Projet.h"
#include "Mot.h"
#include "Liste.h"
#pragma warning(disable : 4996)
/**
 * @file Projet.cpp
 * Projet SDA_Boggle
 * @author GOICHOT, GULDAS
 * @version 1 - 06/12/2020
 * @brief Fichier comportant toute les fonctions develloper pour le projet
 * Structures de données et algorithmes - DUT1 Paris Descartes
 */
 /**
 * @brief Affichage d'une date
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
/**
* @brief Affiche une liste sous forme canonique
* @param[In] La liste a afficher
*/
void Canonique(Liste dMot) {
	Mot temps;
	for (unsigned int h = 0; h < 5; h++) {
		for (unsigned int q = 0; q < dMot.nb; q++) {
			for (unsigned int w = 0; w < dMot.nb; w++) {
				if (strcmp(dMot.c.tab[q], dMot.c.tab[w]) == 0 && w != q) {
					supprimer(dMot, w);
				}
				else if (strcmp(dMot.c.tab[q], dMot.c.tab[w]) < 0)
				{
					strcpy(temps, dMot.c.tab[q]);
					if (q == dMot.nb) {
						inserer(dMot, q, dMot.c.tab[w]);
					}
					else {
						ecrire(dMot, q, dMot.c.tab[w]);

					}
					ecrire(dMot, w, temps);
				}
			}
		}
	}
	for (unsigned int i = 0; i < dMot.nb; i++) {
		std::cout << dMot.c.tab[i] << std::endl;
	}std::cout << "*" << std::endl;
}
