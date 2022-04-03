#include<stdio.h>
#include<stdlib.h>
#include"jeu.c"



int main(int argc, char *argv[]){
    char grille[nombreCol][nombreLig];
    int col;
    int perdu = FALSE;
    int player = TRUE;
    int cmpt = 0;
    int mode = 0;
    
    
    printf("Mode de jeu ? \n 1. vs another player \n 2. vs ordinateur \n");
    scanf("%d", &mode);
    printf("Ton choix est de jouer avec %s: \n", mode == 1 ? "another player" : "ordinateur");
    Initialisation(grille);
    Affichage(grille); 
    
    
    switch(mode){
        case 1:
            while(!perdu){
        
            
                do{
                    col = demande(player, grille);

                }while(coupvalide(grille, col) == FALSE);
            
                joue(player,grille,col);
                
                printf("Joueur %s a joue: \n", player == FALSE ? "JAUNE" : "ROUGE");
                Affichage(grille);
                cmpt++;
                if(victoire(grille)== TRUE){
                    perdu = TRUE;
                    printf("Victoire de %s au %d-ieme coups!", player == FALSE ? "JAUNE" : "ROUGE", cmpt);

                }
                else if(cmpt == nombreCol * nombreLig){
                    perdu = TRUE;
                    printf("Match NUL (%d coups)\n", cmpt);
                }
            
                player = !player;
            
            
            }
        case 2:
            while(!perdu){
        
            
                do{
                    col = demande2(player, grille);

                }while(coupvalide(grille, col) == FALSE);
            
                joue(player,grille,col);
                printf("Joueur %s a joue: \n", player == FALSE ? "JAUNE" : "ROUGE");
                Affichage(grille);
                cmpt++;
                if(victoire(grille)== TRUE){
                    perdu = TRUE;
                    printf("Victoire de %s au %dieme coups!", player == FALSE ? "JAUNE" : "ROUGE", cmpt);

                }
                else if(cmpt == nombreCol * nombreLig){
                    perdu = TRUE;
                    printf("Match NUL (%d coups)\n", cmpt);
                }
            
                player = !player;
            
            }

    }
    
    return 0;

}
