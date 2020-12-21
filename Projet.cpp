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
 * @brief Fichier contenant les algorithmes du Projet
 */
 /**
  * @brief Compte le nombre de points d'une liste
  */
void compteur() {
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
void canonique(Liste dMot) {
	Mot temps;
	for (unsigned int h = 0; h < 4; h++) {
		for (unsigned int q = 0; q < dMot.nb; q++) {
			for (unsigned int w = 0; w < dMot.nb; w++) {
				if (strcmp(dMot.c.tab[q], dMot.c.tab[w]) == 0 && w != q) {
					supprimer(dMot, q);
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
/**
* @brief Affiche les mots de la seconde liste n'apparaissant pas dans la premiere
* @param[In] La première liste
* @param[In] La seconde liste
*/
void extraction(ConteneurTDE LMot1, ConteneurTDE LMot2) {
	Liste dMot;
	initialiser(dMot, 10, 2);
	unsigned int c = 0;
	for (unsigned int k = 0; k < LMot2.nbMot; k++) {
		for (unsigned int j = 0; j < LMot1.nbMot; j++) {
			if (strcmp(LMot2.tab[k], LMot1.tab[j]) == 0)
			{
				break;
			}
			else
			{
				c++;
			}
			if (c == LMot1.nbMot)
			{
				inserer(dMot, dMot.nb, LMot2.tab[k]);
			}
		}
		c = 0;
	}
	canonique(dMot);
	detruire(dMot);
	
}
