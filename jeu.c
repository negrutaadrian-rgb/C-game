#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"jeu.h"


void Initialisation(char grille[nombreCol][nombreLig]){
    int colonne, ligne;
    for(colonne = 0; colonne < nombreCol; colonne++){
        for(ligne = 0; ligne < nombreLig; ligne++){
            grille[colonne][ligne] = VIDE;
        }
    }
}



void Affichage(char grille[nombreCol][nombreLig]){
    int i,j;
    for(i = 0; i < nombreCol; i++){
        printf("__", i + 1);
    }
    printf("\n");

    for(j = nombreLig - 1; j >= 0; j--){
        printf("|");
        for(i = 0; i < nombreCol; i++){
            printf("%c|", grille[i][j]);
        }
        printf(" \n");
    }    
    
    for(i = 0; i < nombreCol; i++){
        printf("__", i + 1);

    }
    printf("\n\n");
   
    for (i = 0; i < nombreCol; i++) {
		printf(" %d", i + 1);
	}
	printf("\n");
}


int joueur1(int player, char grille[nombreCol][nombreLig]){
    
    int colonne = 1;

    printf("Tu veux jouer dans quelle colonne ? ");
    scanf("%d", &colonne);
    
    return colonne;
}

int joueur2(int player, char grille[nombreCol][nombreLig]){
    
    int colonne = 1;
    printf("Tu veux jouer dans la colonne ? \n");
    scanf("%d", &colonne);
    return colonne;

}

int ordinateur(int player, char grille[nombreCol][nombreLig]){
    
    int col;
    static int res = FALSE;
    if(res == FALSE){
        srand(time(NULL));
        res = TRUE;
    }
    col = (rand() % nombreCol) + 1;
    return col;
}

int demande(int player, char grille[nombreCol][nombreLig]){
    int col;
    
    if(player == FALSE){
        printf("JOUEUR: JAUNE votre tour \n");
    }
    else{
        printf("JOUEUR: ROUGE votre tour \n");
    }
    
    switch(player){
        case TRUE:
            col = joueur1(player, grille);
            break;
        case FALSE:
            col = joueur2(player, grille);
            break;
    }
    if(player == FALSE){
        printf("JOUEUR: JAUNE - joue colonne %d\n", col);
    }
    else{
        printf("JOUEUR: ROUGE - joue colonne %d\n", col);
    }
    
    return col;
}


// on joue avec l'ordinateur
int demande2(int player, char grille[nombreCol][nombreLig]){
    int col;
    
    if(player == FALSE){
        printf("JOUEUR: JAUNE votre tour \n");
    }
    else{
        printf("JOUEUR: ROUGE votre tour \n");
    }
    switch(player){
        case TRUE:
            col = joueur1(player, grille);
            break;
        case FALSE:
            col = ordinateur(player, grille);
            break;
    }
    if(player == FALSE){
        printf("JOUEUR: JAUNE - joue colonne %d\n", col);
    }
    else{
        printf("JOUEUR: ROUGE - joue colonne %d\n", col);
    }
    
    return col;

}

int coupvalide(char grille[nombreCol][nombreLig], int colonne){
    
    int lignelibre = -1;
    int y;
    colonne = colonne - 1;
    
    
    
    if(colonne < 0 || colonne >= nombreCol){
        return FALSE;
    }

    for(y = nombreLig - 1; y >= 0; y--){
        if(grille[colonne][y] == VIDE){
            lignelibre = y;
        }
    }
    if(lignelibre == -1){
        return FALSE;
    
    }   
    return TRUE;
}

    






int victoire(char grille[nombreCol][nombreLig]){
    int ligne;
    int colonne;
    Casgagnant jeu[nombreCol][nombreLig];
    for(ligne = 0; ligne < nombreLig; ligne++){
        for(colonne = 0; colonne < nombreCol; colonne++){
            jeu[colonne][ligne].hor = 1;
            jeu[colonne][ligne].ver = 1;
            jeu[colonne][ligne].dgauche = 1;
            jeu[colonne][ligne].ddroite = 1;
        }
    }

    /* cas gagnant horizontale */
    for(ligne = 0; ligne < nombreLig; ligne++){
        for(colonne = 1; colonne < nombreCol; colonne++){
            if((grille[colonne][ligne] == grille[colonne-1][ligne]) && (grille[colonne][ligne] != VIDE)){
                jeu[colonne][ligne].hor = jeu[colonne-1][ligne].hor + 1;
                if(jeu[colonne][ligne].hor == 4){
                    return TRUE;
                }
            }
        }
    }
    /* cas gagnant verticale */
    for(ligne = 1; ligne < nombreLig; ligne++){
        for(colonne = 0; colonne < nombreCol; colonne++){
            if((grille[colonne][ligne] == grille[colonne][ligne-1])&& (grille[colonne][ligne] != VIDE)){
                jeu[colonne][ligne].ver = jeu[colonne][ligne-1].ver + 1;
                if(jeu[colonne][ligne].ver == 4){
                    return TRUE;
                }
            }
        }
    }
    /* cas gagnant diagonale à gauche */
    for ( ligne = 1; ligne < nombreLig ; ligne++){
        for(colonne = 0; colonne < nombreCol - 1; colonne++){
            if((grille[colonne][ligne] == grille[colonne+1][ligne-1])&&(grille[colonne][ligne] != VIDE)){
                jeu[colonne][ligne].dgauche = jeu[colonne+1][ligne-1].dgauche + 1;
                if(jeu[colonne][ligne].dgauche == 4){
                    return TRUE;
                }
            }
        }
    }
    /*cas gagnant diagonale à droite*/
    for ( ligne = 1; ligne < nombreLig ; ligne++){
        for(colonne = 0; colonne < nombreCol - 1; colonne++){
            if((grille[colonne][ligne] == grille[colonne-1][ligne-1])&&(grille[colonne][ligne] != VIDE)){
                jeu[colonne][ligne].ddroite = jeu[colonne-1][ligne-1].ddroite + 1;
                if(jeu[colonne][ligne].ddroite == 4){
                    return TRUE;
                }
            }
        }
    }
    return 0;
}
    
void joue(int player, char grille[nombreCol][nombreLig], int colonne){
    
    
    int lignelibre = -1;
    int x;
    colonne--;
    
    if(colonne < 0 || colonne >= nombreCol){
        return ;
    }
    
    for(x = nombreLig - 1; x >=0; x--){
        if(grille[colonne][x] == VIDE){
            lignelibre = x;
        }
    }
    if(lignelibre == -1){
        return ;
    }
    
    if(player == FALSE){
        grille[colonne][lignelibre] = JAUNE;
    }
    else{
        grille[colonne][lignelibre] = ROUGE;
    }
    
    if(player == FALSE){
        printf("JAUNE a joue grille[%d][%d] \n", colonne + 1, lignelibre + 1);
    }
    else{
        printf("ROUGE a joue grille[%d][%d] \n", colonne + 1, lignelibre + 1);
    }
}


    
// pour sauvegarde dans un fichier on doit faire l'ecriture dans le fichier, apres si le joeur veut recouperer la situation anterieure, on va lire de notre fihcier





    


            
        




