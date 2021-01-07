#pragma once
#include <iostream>
#include <cassert>
#define LGMOT 30
#define GRILLE 4
struct Coord {
	unsigned int abscisse;
	unsigned int ordonnée;
};
struct Contenu {
	char lettre;
	bool EstVisité;
};
struct Grille {
	Contenu tab_contenu[GRILLE][GRILLE];
};
/**
  * @brief Structure de données de type Mot
 */
typedef char Mot[LGMOT + 1];
typedef Mot Item;

/** @brief Conteneur d'items alloués en mémoire dynamique
 *  de capacité extensible suivant un pas d'extension
 */
struct ConteneurTDE {
	unsigned int capacite;        // capacité du conteneur (>0)
	unsigned int pasExtension; // pas d'extension du conteneur (>0)
	Mot* tab;                   // conteneur alloué en mémoire dynamique
	unsigned int nbMot;
};
struct Liste {
	/// Conteneur mémorisant les éléments de la liste.
	ConteneurTDE c;
	/// Nombre d'éléments stockés dans la liste.
	unsigned int nb;
};

/**
* @brief Recupère le mot saisi
* @param[in] id : le conteneur du Mot
*/
void saisir(Mot id);

/**
 * @brief Affiche un Mot
 * @param[in] d : le Mot à afficher
 */
void afficher(char* d);

/**
 * @brief Initialise un conteneur d'items
 * Allocation en mémoire dynamique du conteneur d'items
 * de capacité (capa) extensible par pas d'extension (p)
 * @see detruire, pour sa désallocation en fin d'utilisation
 * @param[out] c : le conteneur d'items
 * @param [in] capa : capacité du conteneur
 * @param [in] p : pas d'extension de capacité
 * @pre capa>0 et p>0
 */
void initialiser(ConteneurTDE& t, unsigned int c, unsigned int p);

/**
 * @brief Désalloue un conteneur d'items en mémoire dynamique
 * @see initialiser, le conteneur d'items a déjà été alloué
 * @param[out] c : le conteneur d'items
 */
void detruire(ConteneurTDE& t);

/**
 * @brief Lecture d'un item d'un conteneur d'items
 * @param[in] c : le conteneur d'items
 * @param[in] i : la position de l'item dans le conteneur
 * @return l'item à la position i
 * @pre i < c.capacite
 */
char lire(const ConteneurTDE& c, unsigned int i, unsigned int v);

/**
 * @brief Ecrire un item dans un conteneur d'items
 * @param[in,out] c : le conteneur d'items
 * @param[in] i : la position où ajouter/modifier l'item
 * @param[in] it : l'item à écrire
 */
void ecrire(ConteneurTDE& t, unsigned int i, const Item& it);
/**
 * @brief Récupère le Mot saisi et le stock
 * @param[in] LMot : le conteneur dans lequel le Mot est stocké
 */
void récupérer(ConteneurTDE& LMot);

/**
 * @brief Initialiser une liste vide, la liste est allouée en mémoire dynamique.
 * @see detruire, la liste est à désallouer en fin d’utilisation.
 * @param[out] l La liste à initialiser.
 * @param[in] capa Capacité de la liste.
 * @param[in] pas Pas d’extension de la liste.
 * @pre capa > 0 et pas > 0.
 */
void initialiser(Liste& l, unsigned int capa, unsigned int pas);

/**
 * @brief Désallouer une liste.
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
 * @brief Lire un élément de liste.
 * @param[in] l La liste.
 * @param[in] pos Position de l'élément à lire.
 * @return L'item lu en position pos.
 * @pre 0 <= pos < longueur(l).
 */
char lire(const Liste& l, unsigned int pos, unsigned int v);

/**
 * @brief Ecrire un item dans la liste.
 * @param[in,out] l La liste.
 * @param[in] pos Position de l'élément à écrire.
 * @param[in] it L'item.
 * @pre 0 <= pos < longueur(l).
*/
void ecrire(Liste& l, unsigned int pos, const Item& it);

/**
 * @brief Insérer un élément dans une liste.
 * @param[in,out] l La liste.
 * @param[in] pos La position à laquelle l'élément est inséré.
 * @param[in] it L'élément inséré.
 * @pre 0 <= pos <= longueur(l).
 */
void inserer(Liste& l, unsigned int pos, const Item& it);

/**
 * @brief Supprimer un élément dans une liste.
 * @param[in,out] l La liste.
 * @param[in] pos La position de l'élément à supprimer.
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
* @brief Affiche les mots de la seconde liste n'apparaissant pas dans la première
* @param[In] La première liste
* @param[In] La seconde liste
*/
void extraction(ConteneurTDE LMot1, ConteneurTDE LMot2);
/**
* @brief Affiche les mots de la seconde liste apparaissant dans la première
* @param[In] La première liste
* @param[In] La seconde liste
*/
/**
 * @brief Comparaison de deux ConteneurTDE
 * @param [in] LMot1 : le premier ConteneurTDE
 * @param [in] LMot2 : le deuxième ConteneurTDE
 */
void Comparaison(ConteneurTDE LMot1, ConteneurTDE LMot2);
/**
 * @brief Crée une liste de tous les mots apparaissant dans au moins deux de listes différentes;
 * @param [in-out] Mot1 : la liste contenant les Mot
 */
void identique(Liste& Mot1);
/**
 * @brief Initialise une grille
 * @param [in-out] tt : la grille a initialiser
 */
void initialiser(Grille& tt);


/**
 * @brief Cherche à placer dans la grille un Mot
 * @param [in] Chaine : Le Mot à placer
 */
bool Recherche(Mot& Chaine, Grille grille);
/**
 * @brief Déterminer si le mot commençant à la position pos peut être placé à partir d'un coordonnée.
 * @param [in] Chaine : Le Mot à tester
 * @param [in] pos : La position à tester
 * @param [in] coord : La coordonnée à tester
 */
bool SousRecherche(Mot& Chaine, int pos, Coord& coord, Grille grille);