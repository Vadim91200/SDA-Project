#include "Test.h"
Grille grille;
void exo1() {
	compteur();
}

void exo2() {
	Mot buffer;
	Liste dMot;
	initialiser(dMot, 100, 2);
	unsigned int i = 0;
	do {
		saisir(buffer);
		if (strcmp(buffer, "*") == 1) {
			inserer(dMot, i, buffer);
			++i;
		}
	} while (strcmp(buffer, "*") == 1);
	canonique(dMot);
	detruire(dMot);
}

void exo3() {
	ConteneurTDE LMot1;
	ConteneurTDE LMot2;
	LMot1.nbMot = 0;
	LMot2.nbMot = 0;
	initialiser(LMot1, 10, 2);
	récupérer(LMot1);
	initialiser(LMot2, 10, 2);
	récupérer(LMot2);
	extraction(LMot1, LMot2);
	detruire(LMot1);
	detruire(LMot2);
}

void exo4() {
	ConteneurTDE LMot1;
	ConteneurTDE LMot2;
	LMot1.nbMot = 0;
	LMot2.nbMot = 0;
	initialiser(LMot1, 10, 2);
	initialiser(LMot2, 10, 2);
	récupérer(LMot1);
	récupérer(LMot2);
	Comparaison(LMot1, LMot2);
	detruire(LMot1);
	detruire(LMot2);
}

void exo5() {
	Liste Mot1;
	initialiser(Mot1, 100, 2);
	identique(Mot1);
	Liste dMot;
	initialiser(dMot, 30, 2);
	for (unsigned int k = 0; k < Mot1.nb; k++) {
		for (unsigned int j = 0; j < Mot1.nb; j++) {
			if (strcmp(Mot1.c.tab[k], Mot1.c.tab[j]) == 0 && k != j)
			{
				inserer(dMot, dMot.nb, Mot1.c.tab[k]);
			}
		}
	}
	canonique(dMot);
	detruire(dMot);
	detruire(Mot1);
}

void exo6() {
	Mot Chaine;
	Liste dMot;
	initialiser(dMot, 20, 2);
	initialiser(grille);
	do {
		saisir(Chaine);
		if (strcmp(Chaine, "*") == 1) {
			if (Recherche(Chaine, grille) == true) {
				inserer(dMot, dMot.nb, Chaine);
			}
		}
	} while (strcmp(Chaine, "*") == 1);
	canonique(dMot);
	detruire(dMot);
}

int main() {
	setlocale(LC_ALL, "");
	int num;
	std::cin >> num;
	switch (num) {
	case 1:
		exo1(); break; // correspond au main du premier programme
	case 2:
		exo2(); break; // correspond au main du second programme 
	case 3:
		exo3(); break;
	case 4:
		exo4(); break;
	case 5:
		exo5(); break;
	case 6:
		exo6(); break;
	}
}