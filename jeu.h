#include<stdio.h>
#include<stdlib.h>



#define nombreCol 7
#define nombreLig 7


enum JEU {VIDE = ' ', ROUGE = 'x', JAUNE = 'o'};
enum VERITE {TRUE = 1, FALSE = 0};


typedef struct{
    int dgauche;
    int ddroite;
    int hor;
    int ver;
} Casgagnant;
