#pragma once

#include "Mot.h"
#include "Item.h"

/** @brief Conteneur d'items alloués en mémoire dynamique
 *  de capacité extensible suivant un pas d'extension
 */
struct ConteneurTDE {
    unsigned int capacite;        // capacité du conteneur (>0)
    unsigned int pasExtension; // pas d'extension du conteneur (>0)
    Mot* tab;                   // conteneur alloué en mémoire dynamique
    unsigned int nbMot;
};

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
