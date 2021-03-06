#ifndef _yahtzee.h
#def _yahtzee.h

#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

int NbJoueur;
int De[5]={0};                                  /* Tableau de dés */
int Garde[5]={0};                               /* Tableau booléen, sert à savoir si on garde les dés ou si on les relance */
int Occurence[6]={0};                           /* Tableau content le nombre d'occurence de chaque valeur de dé */
char pseudo_j1[10] = "J1";                      /* Pseudo du joueur 1 */
char pseudo_j2[10] = "J2";                      /* Pseudo du joueur 2 */
char pseudo_j3[10] = "J3";                      /* Pseudo du joueur 3 */
char pseudo_j4[10] = "J4";                      /* Pseudo du joueur 4 */
char pseudos[40];                               /* Chaine de caractère contenant les pseudos des 4 joueurs avec le nombre d'espace nécesaire à un affichage correct */



int Categorie;                                   /* Permet de savoir quelle catégorie a été sélectionnée pour calculer le score */
WINDOW *ZoneTitre;                               /* Sous fenetre pour l'affichage de YAHTZEE ! */
WINDOW *ZoneMenu;                                /* Sous fenetre pour l'affichage des menus */
WINDOW *ZoneDe;                                  /* Sous fenetre pour l'affichage de la valeur de dés */
WINDOW *ZoneMessage;                             /* Sous fenetre pour l'affichage des messages à l'utilisateur pendant la partie */
WINDOW *ZoneAide;                                /* Sous fenetre pour l'affichage de l'aide au jeu */
WINDOW *ZoneScore;				                       /* Sous fenetre pour l'affichage de la fiche de score */
WINDOW * ZoneResultat;                           /* Sous fenetre pour l'affichage des résultats de la partie */


/* Menu */

void Debut();                                     /* Premier menu, permet de commencer une partie, afficher les règles ou quitter */
void Partie();                                    /* Commence une partie de Yahtzee */
void Regles();                                    /* Affiche les règles */  
void Page_Regles(WINDOW *localwin, int y, int x);

/* Initialisation de la partie */

void Menu();
void EntrerPseudo();                               /* Demande les pseudos des joueurs */
void MiseEnPlace();                                /* Crée les fenêtres utilisées pour jouer */
void FicheDeScore();								               /* Affiche la fiche de score dans la fenêtre */
void EntrerNbJoueur();

/* Fonctions de jeu */

void Nettoyer(WINDOW * localwin, int DebutY, int DebutX, int FinY, int FinX);
void Lancer();                                 /* Simule 5 lancers de dés et entre les résultats dans le tableau */
void CalculOccurence();                          /* Entre l'occurence de chaque valeur dans le tableau */
void CalculScore(int Joueur, int Categorie);
void EcrireScore(int Joueur);
void Garder(WINDOW *localwin, int Garde[5]);                                   /* Permet au joueur de conserver de dés avant de relancer */
int isBrelan();									                 /* Fonctions booléennes vérifiant les résultats */
int isCarre();								                	 /* --- */
int isFull();                                    /* --- */
int isPtSuite();                                 /* --- */
int isGdSuite();                                 /* --- */
int isYahtzee();                                 /* --- */
WINDOW *CreerFenetre(int height, int width, int starty, int startx);    /* Renvoit une fenetre ayant des bordures */
void ChainePseudo (char Pseudos[50]);
void FicheDeScore(WINDOW *localwin, int y, int x)
void ChoixCategorie(int *Categorie, WINDOW *localwin,int Joueur);             /* Permet de choisir la catégorie avec les flèches */
void CalculScore();                              /* Calcul le score pour la catégorie choisie */
void EcrireScore();                              /* Ecrie le score sur la ligne et dans la colonne correspondant au joueur */

int ChangerJoueur(int Joueur, int NbJoueur);
Aide(int isAide[4], int Joueur);
void DetruireFenetre(WINDOW * Fenetre);
void Resultat();
/* Fonctions d'affichage */

void de_un(WINDOW *localwin, int y, int x);                                      /* Dessine un De en caractères */
void de_deux(WINDOW *localwin, int y, int x);                                    /* Dessine un De en caractères */
void de_trois(WINDOW *localwin, int y, int x);                                   /* Dessine un De en caractères */
void de_quatre(WINDOW *localwin, int y, int x);                                  /* Dessine un De en caractères */
void de_cinq(WINDOW *localwin, int y, int x);                                    /* Dessine un De en caractères */
void de_six(WINDOW *localwin, int y, int x);                                     /* Dessine un De en caractères */
void de_vide(WINDOW *localwin, int y, int x);                                    /* Dessine un De en caractères */
void AffichageDe(int De[5], WINDOW *localwin);  

#endif
