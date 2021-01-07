#pragma once
#include <iostream>
#include <cassert>
#define LGMOT 30
#define GRILLE 4
struct Coord {
	unsigned int abscisse;
	unsigned int ordonn�e;
};
struct Contenu {
	char lettre;
	bool EstVisit�;
};
struct Grille {
	Contenu tab_contenu[GRILLE][GRILLE];
};
/**
  * @brief Structure de donn�es de type Mot
 */
typedef char Mot[LGMOT + 1];
typedef Mot Item;

/** @brief Conteneur d'items allou�s en m�moire dynamique
 *  de capacit� extensible suivant un pas d'extension
 */
struct ConteneurTDE {
	unsigned int capacite;        // capacit� du conteneur (>0)
	unsigned int pasExtension; // pas d'extension du conteneur (>0)
	Mot* tab;                   // conteneur allou� en m�moire dynamique
	unsigned int nbMot;
};
struct Liste {
	/// Conteneur m�morisant les �l�ments de la liste.
	ConteneurTDE c;
	/// Nombre d'�l�ments stock�s dans la liste.
	unsigned int nb;
};

/**
* @brief Recup�re le mot saisi
* @param[in] id : le conteneur du Mot
*/
void saisir(Mot id);

/**
 * @brief Affiche un Mot
 * @param[in] d : le Mot � afficher
 */
void afficher(char* d);

/**
 * @brief Initialise un conteneur d'items
 * Allocation en m�moire dynamique du conteneur d'items
 * de capacit� (capa) extensible par pas d'extension (p)
 * @see detruire, pour sa d�sallocation en fin d'utilisation
 * @param[out] c : le conteneur d'items
 * @param [in] capa : capacit� du conteneur
 * @param [in] p : pas d'extension de capacit�
 * @pre capa>0 et p>0
 */
void initialiser(ConteneurTDE& t, unsigned int c, unsigned int p);

/**
 * @brief D�salloue un conteneur d'items en m�moire dynamique
 * @see initialiser, le conteneur d'items a d�j� �t� allou�
 * @param[out] c : le conteneur d'items
 */
void detruire(ConteneurTDE& t);

/**
 * @brief Lecture d'un item d'un conteneur d'items
 * @param[in] c : le conteneur d'items
 * @param[in] i : la position de l'item dans le conteneur
 * @return l'item � la position i
 * @pre i < c.capacite
 */
char lire(const ConteneurTDE& c, unsigned int i, unsigned int v);

/**
 * @brief Ecrire un item dans un conteneur d'items
 * @param[in,out] c : le conteneur d'items
 * @param[in] i : la position o� ajouter/modifier l'item
 * @param[in] it : l'item � �crire
 */
void ecrire(ConteneurTDE& t, unsigned int i, const Item& it);
/**
 * @brief R�cup�re le Mot saisi et le stock
 * @param[in] LMot : le conteneur dans lequel le Mot est stock�
 */
void r�cup�rer(ConteneurTDE& LMot);

/**
 * @brief Initialiser une liste vide, la liste est allou�e en m�moire dynamique.
 * @see detruire, la liste est � d�sallouer en fin d�utilisation.
 * @param[out] l La liste � initialiser.
 * @param[in] capa Capacit� de la liste.
 * @param[in] pas Pas d�extension de la liste.
 * @pre capa > 0 et pas > 0.
 */
void initialiser(Liste& l, unsigned int capa, unsigned int pas);

/**
 * @brief D�sallouer une liste.
 * @see initialiser
 * @param[out] l La liste.
 */
void detruire(Liste& l);

/**
 * @brief Longueur de liste.
 * @param[in] l La liste.
 * @return La longueur de la liste.
 */
unsigned int longueur(const Liste& l);

/**
 * @brief Lire un �l�ment de liste.
 * @param[in] l La liste.
 * @param[in] pos Position de l'�l�ment � lire.
 * @return L'item lu en position pos.
 * @pre 0 <= pos < longueur(l).
 */
char lire(const Liste& l, unsigned int pos, unsigned int v);

/**
 * @brief Ecrire un item dans la liste.
 * @param[in,out] l La liste.
 * @param[in] pos Position de l'�l�ment � �crire.
 * @param[in] it L'item.
 * @pre 0 <= pos < longueur(l).
*/
void ecrire(Liste& l, unsigned int pos, const Item& it);

/**
 * @brief Ins�rer un �l�ment dans une liste.
 * @param[in,out] l La liste.
 * @param[in] pos La position � laquelle l'�l�ment est ins�r�.
 * @param[in] it L'�l�ment ins�r�.
 * @pre 0 <= pos <= longueur(l).
 */
void inserer(Liste& l, unsigned int pos, const Item& it);

/**
 * @brief Supprimer un �l�ment dans une liste.
 * @param[in,out] l La liste.
 * @param[in] pos La position de l'�l�ment � supprimer.
 * @pre longueur(l) > 0 et 0 <= pos < longueur(l).
 */
void supprimer(Liste& l, unsigned int pos);
/**
  * @brief Compte le nombre de points d'une liste
  */
void compteur();
/**
* @brief Affiche une liste sous forme canonique
* @param[In] La liste a afficher
*/
void canonique(Liste dMot);
/**
* @brief Affiche les mots de la seconde liste n'apparaissant pas dans la premi�re
* @param[In] La premi�re liste
* @param[In] La seconde liste
*/
void extraction(ConteneurTDE LMot1, ConteneurTDE LMot2);
/**
* @brief Affiche les mots de la seconde liste apparaissant dans la premi�re
* @param[In] La premi�re liste
* @param[In] La seconde liste
*/
/**
 * @brief Comparaison de deux ConteneurTDE
 * @param [in] LMot1 : le premier ConteneurTDE
 * @param [in] LMot2 : le deuxi�me ConteneurTDE
 */
void Comparaison(ConteneurTDE LMot1, ConteneurTDE LMot2);
/**
 * @brief Cr�e une liste de tous les mots apparaissant dans au moins deux de listes diff�rentes;
 * @param [in-out] Mot1 : la liste contenant les Mot
 */
void identique(Liste& Mot1);
/**
 * @brief Initialise une grille
 * @param [in-out] tt : la grille a initialiser
 */
void initialiser(Grille& tt);


/**
 * @brief Cherche � placer dans la grille un Mot
 * @param [in] Chaine : Le Mot � placer
 */
bool Recherche(Mot& Chaine, Grille grille);
/**
 * @brief D�terminer si le mot commen�ant � la position pos peut �tre plac� � partir d'un coordonn�e.
 * @param [in] Chaine : Le Mot � tester
 * @param [in] pos : La position � tester
 * @param [in] coord : La coordonn�e � tester
 */
bool SousRecherche(Mot& Chaine, int pos, Coord& coord, Grille grille);