#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int QuiCommence(int nb_joueur){

	int joueur;
	int i;
	int com[4] = {1,1,1,1};
	int max = 0;
	int retient;
	int occ = 1;
	int x = 2;
	int y = 2;
	
	wclear(ZoneMessage);
	//on initialise la zone qui contiendra le printf de la fin du programme
	srand(time(NULL)); 
	// initialisation de rand
	
	for( joueur = 0 ; joueur < nb_joueur; joueur++){
		if(com[joueur] > 0){
			//on lance le dé du joueur si son score est different de 0
			com[joueur] = rand()%6+1;
		}
		//compte le nombre d'occurence du max
		else if(max == com[joueur]){
			occ++;
		}
		//change le max
		else if(max < com[joueur]){
			max = com[joueur];
			retient = joueur;
			//revien a une seule occurence
			occ = 1;
		}
		//si il y a 2 fois le maximum et que les lancés sont fini recommence pour ces joueurs
		else if(( joueur+1 == nb_joueur) && (occ > 1)){
			for( i=joueur; i >= 0; i--){
				if(max > com[i]){
					com[i] = -1;
				}
			}
			//reinitialisation du max et du compteur
			max = 0;
			joueur =- 1;
		}
	}
	retient++;
	mvwprintw(ZoneMessage, y, x, "le joueur %i commence",retient);
	return retient;
}
int main(){
	QuiCommence(3);
}
