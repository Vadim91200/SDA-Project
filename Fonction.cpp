#include "Test.h"
#pragma warning(disable : 4996)
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
void initialiser(Liste& l, unsigned int capa, unsigned int pas) {
	assert((capa > 0) && (pas > 0));
	initialiser(l.c, capa, pas);
	l.nb = 0;
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
	assert(pos < l.nb);
	ecrire(l.c, pos, it);
}

void inserer(Liste& l, unsigned int pos, const Item& it) {
	assert(pos <= l.nb);
	Mot temp;
	for (unsigned int i = l.nb; i > pos; i--) {
		for (unsigned int v = 0; v < 10; v++) {
			temp[v] = lire(l.c, i - 1, v);
		}
		ecrire(l.c, i, temp);
	}
	ecrire(l.c, pos, it);
	l.nb++;
}

void supprimer(Liste& l, unsigned int pos) {
	assert((l.nb != 0) && (pos < l.nb));
	l.nb--;
	Mot temp;
	for (unsigned int i = pos; i < l.nb; ++i) {
		for (unsigned int v = 0; v < 10; v++) {
			temp[v] = lire(l.c, i + 1, v);
		}
		ecrire(l.c, i, temp);
	}
}
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
	//Ss
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
/**
* @brief Affiche les mots de la seconde liste apparaissant dans la première
* @param[In] La première liste
* @param[In] La seconde liste
*/
void Comparaison(ConteneurTDE LMot1, ConteneurTDE LMot2) {
	Liste dMot;
	initialiser(dMot, 10, 2);
	for (unsigned int k = 0; k < LMot2.nbMot; k++) {
		for (unsigned int j = 0; j < LMot1.nbMot; j++) {
			if (strcmp(LMot2.tab[k], LMot1.tab[j]) == 0)
			{
				inserer(dMot, dMot.nb, LMot2.tab[k]);
			}
		}
	}
	canonique(dMot);
	detruire(dMot);
}
void identique(Liste& Mot1) {
	bool fin = false;
	bool oui = true;
	Mot buffer;
	Mot Ecrase = { 'W', 'R', 'O', 'N', 'G' };
	saisir(buffer);
	do
	{
		ConteneurTDE Conteneur;
		initialiser(Conteneur, 30, 2);
		Conteneur.nbMot = 0;
		unsigned int k = 0;
		do {
			if (strcmp(buffer, "*") == 1) {
				ecrire(Conteneur, k, buffer);
				++Conteneur.nbMot;
				++k;
			}saisir(buffer);
		} while (strcmp(buffer, "*") == 1);
		saisir(buffer);
		if (strcmp(buffer, "*") == 0) {
			fin = true;
		}
		for (unsigned int q = 0; q < Conteneur.nbMot; q++) {
			for (unsigned int w = 0; w < Conteneur.nbMot; w++) {
				if (strcmp(Conteneur.tab[q], Conteneur.tab[w]) == 0 && w != q) {
					ecrire(Conteneur, q, Ecrase);
				}
			}

		}
		unsigned int q = 0;
		for (unsigned int i = 0; i < Conteneur.nbMot; i++)
		{
			if (strcmp(Conteneur.tab[i], Ecrase) == 0)
			{

			}
			else
			{
				inserer(Mot1, q, Conteneur.tab[i]);
				q++;
			}

		}
		detruire(Conteneur);
	} while (fin != true);
}
void initialiser(Grille& tt) {
	for (unsigned int i = 0; i < GRILLE; i++) {
		for (unsigned int l = 0; l < GRILLE; l++) {
			std::cin >> tt.tab_contenu[i][l].lettre;
		}
	}
}
bool Recherche(Mot& Chaine, Grille grille) {
	for (unsigned int i = 0; i < GRILLE; i++) {
		for (unsigned int l = 0; l < GRILLE; l++) {
			grille.tab_contenu[i][l].EstVisité = false;
		}
	}
	for (unsigned int y = 0; y < GRILLE; y++) {
		for (unsigned int x = 0; x < GRILLE; x++) {
			Coord coord;
			coord.abscisse = x;
			coord.ordonnée = y;
			if (SousRecherche(Chaine, 0, coord, grille) == true) {
				return true;
			}
		}
	}
	return false;
}
bool SousRecherche(Mot& Chaine, int pos, Coord& coord, Grille grille) {
	if (pos >= strlen(Chaine)) {
		return true;
	}
	else if (coord.abscisse > GRILLE - 1 || coord.abscisse < 0 || coord.ordonnée > GRILLE - 1 || coord.ordonnée < 0) {
		return false;
	}
	else if (grille.tab_contenu[coord.abscisse][coord.ordonnée].lettre != Chaine[pos]) {
		return false;
	}
	else if (grille.tab_contenu[coord.abscisse][coord.ordonnée].EstVisité == true) {
		return false;
	}
	grille.tab_contenu[coord.abscisse][coord.ordonnée].EstVisité = true;
	if (coord.abscisse == 0 && coord.ordonnée == 0) {
		for (unsigned int y = coord.ordonnée; y <= coord.ordonnée + 1; y++) {
			for (unsigned int x = coord.abscisse; x <= coord.abscisse + 1; x++) {
				if (x < GRILLE && x >= 0 && y < GRILLE && y >= 0 && (x != coord.abscisse || y != coord.ordonnée)) {
					Coord coord2;
					coord2.abscisse = x;
					coord2.ordonnée = y;
					if (SousRecherche(Chaine, pos + 1, coord2, grille) == true) {
						return true;
					}
				}
			}
		}
	}
	else if (coord.abscisse == 0)
	{
		for (unsigned int y = coord.ordonnée - 1; y <= coord.ordonnée + 1; y++) {
			for (unsigned int x = coord.abscisse; x <= coord.abscisse + 1; x++) {
				if (x < GRILLE && x >= 0 && y < GRILLE && y >= 0 && (x != coord.abscisse || y != coord.ordonnée)) {
					Coord coord2;
					coord2.abscisse = x;
					coord2.ordonnée = y;
					if (SousRecherche(Chaine, pos + 1, coord2, grille) == true) {
						return true;
					}
				}
			}
		}
	}
	else if (coord.ordonnée == 0)
	{
		for (unsigned int y = coord.ordonnée; y <= coord.ordonnée + 1; y++) {
			for (unsigned int x = coord.abscisse - 1; x <= coord.abscisse + 1; x++) {
				if (x < GRILLE && x >= 0 && y < GRILLE && y >= 0 && (x != coord.abscisse || y != coord.ordonnée)) {
					Coord coord2;
					coord2.abscisse = x;
					coord2.ordonnée = y;
					if (SousRecherche(Chaine, pos + 1, coord2, grille) == true) {
						return true;
					}
				}
			}
		}
	}
	else
	{
		for (unsigned int y = coord.ordonnée - 1; y <= coord.ordonnée + 1; y++) {
			for (unsigned int x = coord.abscisse - 1; x <= coord.abscisse + 1; x++) {
				if (x < GRILLE && x >= 0 && y < GRILLE && y >= 0 && (x != coord.abscisse || y != coord.ordonnée)) {
					Coord coord2;
					coord2.abscisse = x;
					coord2.ordonnée = y;
					if (SousRecherche(Chaine, pos + 1, coord2, grille) == true) {
						return true;
					}
				}
			}
		}
	}

	grille.tab_contenu[coord.abscisse][coord.ordonnée].EstVisité = false;
	return false;
}