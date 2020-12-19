/**
 * @file Liste.cpp
 * @brief Composant de liste en mémoire dynamique et extensible
 */
 
#include <cassert> 
#include "Liste.h"

void initialiser(Liste& l, unsigned int capa, unsigned int pas) {
	assert ((capa>0) && (pas>0));
	initialiser(l.c, capa, pas);
	l.nb=0;
}
 
void detruire(Liste& l) {
	detruire(l.c);
}

unsigned int longueur(const Liste& l) {
	return l.nb;
}

char lire(const Liste& l, unsigned int pos, unsigned int v) {
	assert(pos < l.nb);
	return lire(l.c, pos, v);
}

void ecrire(Liste& l, unsigned int pos, const Item& it) {
	assert(pos<l.nb);
	ecrire(l.c, pos, it);
}	

void inserer(Liste& l, unsigned int pos, const Item& it) {
	assert(pos<=l.nb);
	Mot temp;
	for (unsigned int i=l.nb; i>pos; i--) {
		for (unsigned int v = 0; v < 10; v++) {
			temp[v] = lire(l.c, i - 1, v);
		}
		ecrire(l.c, i, temp);
	}
	ecrire(l.c, pos, it);
	l.nb++;
}

void supprimer(Liste& l, unsigned int pos) {
	assert((l.nb!=0) && (pos<l.nb));
	l.nb--;
	Mot temp;
	for (unsigned int i = pos; i < l.nb; ++i) {
		for (unsigned int v=0; v < 10; v++) {
			temp[v] = lire(l.c, i + 1, v);
		}
		ecrire(l.c, i, temp);
	}
}
