#include <stdio.h>


int main(){
    //1
    // a = 0;
    // while(a != -1){
    //     printf("Entrez un nombre\n");
    //     scanf("%d", &a);
    //     if(a == -1){
    //         break;
    //     }
    //     res += a;
    //     nb++;
    // }
    // res /= nb;
    // printf("La moyenne est %.1f\n", res);

    //2
    // for(int i = 0; i < 5; i++){
    //     printf("Entrez un nombre\n");
    //     scanf("%d", &tab[i]);
    //     if(tab[i] > max){
    //         max = tab[i];
    //     }
    //     if(tab[i] < min){
    //         min = tab[i];
    //     }
    //     if(i == 0){ //condition particulière pour la première itération
    //         min = tab[i];
    //     }
    // }
    // printf("Le plus grand est %d et le plus petit est %d\n", max, min);

    //3
    // printf("Entrez :\n1 : Triangle haut, 2 : Triangle bas\n1 : Triangle droite, 2 : Triangle gauche\net enfin un nombre d'étoile\n");
    // scanf("%d %d %d", &choix1, &choix2, &nbE);

    // if(choix1 == 1){ //haut
    //     if(choix2 == 1){ // droite OK
    //         for(int i = 0; i < nbE+1; i++){
    //             for(int j = 0; j < i; j++){
    //                 printf("*");
    //             }
    //             printf("\n");
    //         }
    //     }
    //     else if(choix2 == 2){ // gauche NON
    //         for(int i = nbE+1; i > 0; i--){
    //             for(int j = 0; j < i; j++){
    //                 printf(" ");
    //             }
    //             for(int j = 0; j < nbE+1-i; j++){
    //                 printf("*");
    //             }
    //             printf("\n");
    //         }
    //     }
    //     else{
    //         printf("Erreur\n");
    //     }
    // }
    // else if(choix1 == 2){ //bas
    //     if(choix2 == 1){ //droite OK
    //         for(int i = nbE+1; i > 0; i--){
    //             for(int j = 0; j < i; j++){
    //                 printf("*");
    //             }
    //             printf("\n");
    //         }
    //     }
    //     else if(choix2 == 2){ // gauche NON
    //         for(int i = 0; i < nbE+1; i++){
    //             for(int j = 0; j < i; j++){
    //                 printf(" ");
    //             }
    //             for(int j = 0; j < nbE+1-i; j++){
    //                 printf("*");
    //             }
    //             printf("\n");
    //         }
    //     }
    //     else{
    //         printf("Erreur\n");
    //     }
    // }
    // else{
    //     printf("Erreur\n");
    // }

    //4
    //Tri bulle
    // for(int i = 0; i < 6; i++){
    //     printf("Entrez un nombre\n");
    //     scanf("%d", &tab[i]);
    // }

    // printf("Le tableau est :\n");
    // for(int i = 0; i < 6; i++){
    //     printf("%d ", tab[i]);
    // }

    // for(int i = 0; i < 6; i++){
    //     for(int j = 0; j < 6; j++){
    //         if(tab[i] < tab[j]){
    //             int tmp = tab[i];
    //             tab[i] = tab[j];
    //             tab[j] = tmp;
    //         }
    //     }
    // }

    // printf("Le tableau trié est :\n");
    // for(int i = 0; i < 6; i++){
    //     printf("%d ", tab[i]);
    // }

    //5
    // char tab[100] = "salut a tous cest la salle";
    // int tab2[27];
    // for(int i = 0; i < 27; i++){
    //     tab2[i] = 0;
    // }

    // //compte le nombre de chaque lettre minuscule & lettres non reconnus
    // for(int i = 0; i < 100; i++){
    //     if(tab[i] >= 'a' && tab[i] <= 'z'){
    //         tab2[tab[i]-'a']++; // 'a' = 97 donc 'a'-'a' = 0, 'b'-'a' = 1, etc...
    //     }
    //     else if(tab[i] == '\0'){ // fin liste caractère
    //         break;
    //     }
    //     else{
    //         tab2[26]++;
    //     }
    // }

    // //affiche le nombre de chaque lettre minuscule & lettres non reconnus
    // for(int i = 0; i < 27; i++){
    //     if(i < 26){
    //         printf("%c : %d\n", i+'a', tab2[i]); //lettre petit à petit
    //     }
    //     else{
    //         printf("Non reconnu : %d\n", tab2[i]);
    //     }
    // }

    //6



    return 0;
}