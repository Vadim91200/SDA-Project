#ifndef _COMPTEUR_
#include "Liste.h"
/**
 * @file Compteur.h
 * Projet SDA_Boggle
 * @author GOICHOT, GULDAS
 * @version 1 - 06/12/2020
 * @brief Le compteur de point
 * Structures de données et algorithmes - DUT1 Paris Descartes
 */
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
* @brief Affiche les mots de la seconde liste n'apparaissant pas dans la premiere
* @param[In] La première liste
* @param[In] La seconde liste 
*/
void extraction(ConteneurTDE LMot1, ConteneurTDE LMot2);
#endif
