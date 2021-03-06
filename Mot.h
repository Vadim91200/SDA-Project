#pragma once
/**
 * @file Mot.h
 * Projet SDA_Boggle
 * @author GOICHOT, GULDAS
 * @version 1 - 06/12/2020
 * @brief Composant de Mot
 * Structures de données et algorithmes - DUT1 Paris Descartes
 */
#define LGMOT 30
 /**
  * @brief Structure de données de type Mot
 */
typedef char Mot[LGMOT + 1];

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

