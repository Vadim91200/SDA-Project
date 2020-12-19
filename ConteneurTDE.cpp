#include <iostream>
#include <cassert>
#include "conteneurTDE.h"
#include "Item.h"
#include "Mot.h"
#pragma warning(disable : 4996) 
using namespace std;

void initialiser(ConteneurTDE& c, unsigned int capa, unsigned int p) {
	assert((capa > 0) && (p > 0));
	c.capacite = capa;
	c.pasExtension = p;
	c.tab = new Mot[capa];
}

void detruire(ConteneurTDE& c) {
	delete[] c.tab;
	c.tab = NULL;
}

char lire(const ConteneurTDE& c, unsigned int i, unsigned int v) {
	assert(i < c.capacite);
	return c.tab[i][v];
}

void ecrire(ConteneurTDE& c, unsigned int i, const Item& it) {
	if (i >= c.capacite) {
		/* Stratégie de réallocation proportionnelle au pas d'extension :
		 * initialisez la nouvelle taille du conteneur (newTaille)
		 * à i * c.pasExtension */
		unsigned int newTaille = (i + 1) * c.pasExtension;
		/* Allouez en mémoire dynamique un nouveau tableau (newT)
		 * à cette nouvelle taille*/
		Item* newT = new Item[newTaille];
		/* Recopiez les items déjà stockés dans le conteneur */
		for (unsigned int i = 0; i < c.capacite; ++i)
			strcpy(newT[i], c.tab[i]);
		/* Désallouez l'ancien tableau support du conteneur */
		delete[] c.tab;
		/* Actualiser la mise à jour du conteneur en mémoire dynamique
		 * Faites pointer le tableau support du conteneur
		 * sur le nouveau tableau en mémoire dynamique */
		c.tab = newT;
		/* Actualisez la taille du conteneur */
		c.capacite = newTaille;
	}
	/* Ecriture de l'item (it) à la position i dans le conteneur */
	strcpy(c.tab[i], it);
}
void récupérer(ConteneurTDE& LMot) {
	Mot buffer;
	unsigned int i = 0;
	do {
		saisir(buffer);
		if (strcmp(buffer, "*") == 1) {
			ecrire(LMot, i, buffer);
			++LMot.nbMot;
			++i;
		}
	} while (strcmp(buffer, "*") == 1);
}
