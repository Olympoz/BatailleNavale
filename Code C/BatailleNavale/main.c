#include <stdio.h>
#include <stdlib.h>
#define MAP_H 10
#define MAP_W 10
#define MAP_JOUEUR 2
#define DESTROYER 6
#define NAVIRE 3
#define BLACK_PEARL 4
#define PETIT_BATEAU 1
#define BATEAU_DE_PECHE 2
#define DEESTROYER 2

int main()
{

    Menu();
    AfficheTableau();
    PlacementDeestroyer();
}



void InitialisationTableau(){
}

//Fonction qui affiche le plateau de jeu
void AfficheTableau (int map[MAP_H][MAP_W][MAP_JOUEUR]){

    int Y;
    int X;

    for(Y = -1;Y < MAP_H; Y++){
            if (Y >-1 && Y <9 ){
                printf(" ");
            }
            if (Y == 11){
                printf("");
            }
             if (Y == -1){
                printf("Y/X");
            }else{
                printf(" %d ",Y+1);


            }
        for(X= 0; X< MAP_W; X++){
            if (Y>=0){

                if(Y == 0 || Y == MAP_H || X == 0 || X == MAP_W){
                    printf("0 ");
                }else{
                    if(map[Y][X]!=0){
                        printf("0 ",map[Y][X]);

                    }
                }
            }else{
                printf(" %d",X+1);
            }
        }
        printf("\n");
    }
    getchar();
}

//Fonction
void waitFor (unsigned int secs) {
    unsigned int retTime = time(0) + secs;
    while (time(0) < retTime);
}

//Fonction qui permet de créer l'aléatoire d'un élément
int doRand(int startVal, int endVal){
    waitFor(0.05);
    srand(time(NULL)*rand());
    if(startVal == 0 && endVal == 1){
        return rand() % 2;
    }else{
        return (rand() % ((endVal + startVal -1)) + startVal);
    }
}

//Fonction de placement du Destroyer en aléatoire pour utiliser avec l'IA
void PlacementDestroyer(int Destroyer[DESTROYER], int map[MAP_H][MAP_W][MAP_JOUEUR]){


    int X = 0;
    int Y = 0;
    int x = doRand(0,MAP_H );
    int y = doRand(0,MAP_W );
        if(map[x][y][MAP_JOUEUR] == 0){
        map[x][y][MAP_JOUEUR] = Destroyer[DESTROYER];
        Destroyer[X] = x;
        Destroyer[Y] = y;
        }else{
       PlacementDestroyer(Destroyer,map);
        }
}

void PlacementDeestroyer(int Deestroyer[DEESTROYER], int map[MAP_H][MAP_W][MAP_JOUEUR]){

    int X = 0;
    int Y = 0;

    printf("Rentrez des coordonnées X et Y\n");
    scanf("%d", map[X] );
    for(Y = -1;Y < MAP_H; Y++){
        for(X= 0; X< MAP_W; X++){

            if((map[X] == 0)){
            1 == map[X];

            }
        }
    }

}


//Fonction de placement du Navire en aléatoire pour utiliser avec l'IA
void PlacementNavire(int Navire[NAVIRE], int map[MAP_H][MAP_W][MAP_JOUEUR]){

    int X = 0;
    int Y = 0;
    int x = doRand(0,MAP_H-1);
    int y = doRand(0,MAP_W-1);
        if(map[x][y][MAP_JOUEUR] == 0){
        map[x][y][MAP_JOUEUR] = Navire[NAVIRE];
        Navire[X] = x;
        Navire[Y] = y;
        }else{
       PlacementNavire(Navire,map);
        }
}

//Fonction de placement du Black Pearl en aléatoire pour utiliser avec l'IA
void PlacementBlackPearl(int BlackPearl[BLACK_PEARL], int map[MAP_H][MAP_W][MAP_JOUEUR]){

    int X = 0;
    int Y = 0;
    int x = doRand(0,MAP_H-1);
    int y = doRand(0,MAP_W-1);
        if(map[x][y][MAP_JOUEUR] == 0){
        map[x][y][MAP_JOUEUR] = BlackPearl[BLACK_PEARL];
        BlackPearl[X] = x;
        BlackPearl[Y] = y;
        }else{
       PlacementBlackPearl(BlackPearl,map);
        }
}

//Fonction de placement du Petit Bateau en aléatoire pour utiliser avec l'IA
void PlacementPetitBateau(int PetitBateau[PETIT_BATEAU], int map[MAP_H][MAP_W][MAP_JOUEUR]){

    int X = 0;
    int Y = 0;
    int x = doRand(0,MAP_H-1);
    int y = doRand(0,MAP_W-1);
        if(map[x][y][MAP_JOUEUR] == 0){
        map[x][y][MAP_JOUEUR] = PetitBateau[PETIT_BATEAU];
        PetitBateau[X] = x;
        PetitBateau[Y] = y;
        }else{
       PlacementPetitBateau(PetitBateau,map);
        }
}

//si case = 0 donc case = 1
// 1 = petit bateau
// je dois faire 4 fonctions
// si la case est dispo alors mettre 1 sinon redemander des valeurs
// checker si c'est dans le tableau

//Fonction de placement du Bateau de Pêche en aléatoire pour utiliser avec l'IA
void PlacementBateauDePeche(int BateauDePeche[BATEAU_DE_PECHE], int map[MAP_H][MAP_W][MAP_JOUEUR]){

    int X = 0;
    int Y = 0;
    int x = doRand(0,MAP_H-1);
    int y = doRand(0,MAP_W-1);
        if(map[x][y][MAP_JOUEUR] == 0){
            printf("1", BateauDePeche);
        map[x][y][MAP_JOUEUR] = BateauDePeche[BATEAU_DE_PECHE];
        BateauDePeche[X] = x;
        BateauDePeche[Y] = y;
        }else{
       PlacementBateauDePeche(BateauDePeche,map);
        }
}

//Fonction principale où le jeu va se dérouler
//Entrées du programme : entrés users , donner coordonnées, dire si c'est valide, dire si touché ou coulé ou flop.
//Fin pour tout les bateaux d'un des deux joueurs coulés.
//Fin pour afficher le déroulement du jeu et appuyez pour sortir ou pour rejouer
void DeroulementJeu(){


}
//Fonction qui permet de sauvegarder la partie
void Save (){

    FILE* ftp = fopen("./test1.txt","a+");
    int i = 0;
    while(i < 1000){
        fprintf(ftp,"Hello world %d",i);
        i++;
    }
    fclose(ftp);
}

//Fonction qui permet de charger la partie au même endroit.
void Load (){

    FILE* fptr = fopen("./test1.txt","r");
    char c;
    while(1)
    {
        c = fgetc(fptr);
        if ( feof(fptr) )
        {
            break;
        }
        printf ("%c", c);
    }
    fclose(fptr);
}

//Fonction qui permet à l'IA de jouer
void IA (){
}
//Fonction qui pemet d'afficher le menu
void Menu(){
    printf("~~~~~~~~~~~~~~~BATAILLE NAVALE~~~~~~~~~~~~~~~\n");
    printf(" 1 : Joueur VS Joueur \n ");
    printf("2 : Joueur VS IA \n ");
    printf("3 : IA VS IA \n ");
    printf("4 : Charger \n ");
    printf("5 : Sauvegarder \n ");
    printf("6 : Quitter \n");

    getchar();
    system("cls");
}
