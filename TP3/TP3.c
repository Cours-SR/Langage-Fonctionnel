#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "time.h"

//1
static float k;
float newton(float x, float k){
    static int n = 0;

    float suiv = x - ((x*x-k)/(2*x));
    n++;
    // printf("%f\n",suiv);

    if(x == suiv){
        return suiv;
    }
    if (x == 0){
        return x;
    }
    if(n==15){
        return suiv;
    }
    return newton(suiv, k);
}

float sqrt_(float x){
    k = x;
    return newton(x, k);
}

//2
float distance(float x, float y, float x1, float y1, float r){
    float px = x1-x;
    float py = y1-y;
    float distance = sqrt_(px)*2+sqrt_(py)*2;
    if(distance == r*2){
        //se touche
        printf("se touche\n");
    }
    else if(distance > r*2){
        //se touche pas
        printf("se touche pas\n");
    }
    else if(distance < r*2){
        //s'englobe
        printf("s'englobe\n");
    }
    return 0;
}

//3
int pwr(int base,int exp) {
    int res=1;
     
    while(exp>=1) {
        res*=base;
        exp--;
    }
    return(res);
}
int premiere_valeur(){
    return (int) time(NULL) % 16;
}

int random_(){
    //ou exclusif 5 bits les plus a gauche
    static int r = 14;

    //------------------------------------
    // EXEMPLE PROF pour + propre
    // (r >> (r>>1) ^ (r >> 2) && (r >> 3) (r >> 4)) & 1;
    // (r>>3) & 1
    // 0100111010 r
    // 0000100111 r>>3
    // 0000000001 & 1
    // 0000000001 resultat
    //------------------------------------


    //transofrmer en binaire
    int bin[16];
    int i = 0;
    for(int j = 0; j < 16; j++){
        bin[j] = 0;
    }
    while(r != 0){
        bin[i] = r % 2;
        r = r / 2;
        i++;
    }
    int res = 0;
    for(int j = 0; j < 4; j++){
        if(j==0){
            // printf("%d %d\n", bin[j], bin[j+1]);
            res = bin[j] ^ bin[j+1];
        }
        else{
            // printf("%d %d\n", res, bin[j+1]);
            res = res ^ bin[j+1];
        }
    
        // printf("%d\n", res);
    }
    printf("%d\n", res);
    //-----------------------
    int bin2[16];
    for(int j = 0; j < 16; j++){
        bin2[j] = bin[j];
    }
    //6 bits a droite décalé sur la droite
    for(int i = 6; i>-1; i--){
        bin2[i-1] = bin[i];
    }
    bin2[15] = res;

    //convertir en decimal
    r = 0;
    int j = 0;
    for(int i = 0; i < 16; i++){
        if(bin2[i] & 1){
            r = r + pwr(2, j);
            // printf("r = %d\n", r);
        }
        j++;
    }
    printf("%d\n", r);
}

int random2(){
    int r = premiere_valeur();
    int res = 0;
    
    for(int j = 0; j < 4; j++){
        if(j==0){
            // printf("%d %d\n", r >> j &1, r >> j+1&1);
            res = ((r >> j) & 1) ^ ((r >> j+1) & 1);
        }
        else{
            // printf("%d %d\n", res, r >> j+1&1);
            res = res ^ ((r >> j+1) & 1);
        }
    }
    printf("%d\n", res);

    //décale tout sur la droite
    r = r >> 1;
    //mettre a l'emplacement 16 le res
    r = r | (res << 15);

    printf("%d\n", r);
    return r;
}

// int main(){
    // newton(k);
    // distance(1,0,1,4,1);
    // random_();
    // random2();
// }

//4
int demande_mise(int argent){
    int mise;
    printf("combien voulez vous miser ?\n");
    scanf("%d", &mise);
    while(mise > argent){
        printf("vous n'avez pas assez d'argent\n");
        printf("combien voulez vous miser ?\n");
        scanf("%d", &mise);
    }
    return mise;
}

int demande_pari(){
    int pari;
    printf("sur quel chiffre voulez vous parier ?\n");
    scanf("%d", &pari);
    while(pari < 1 || pari > 6){
        printf("vous devez parier sur un chiffre entre 1 et 6\n");
        printf("sur quel chiffre voulez vous parier ?\n");
        scanf("%d", &pari);
    }
    return pari;
}

int main(){
    int argent = 50;
    int mise, pari;
    while(argent > 0 && argent < 30000){
        printf("vous avez %d euros\n", argent);

        mise = demande_mise(argent);
        printf("vous misez : %d\n", mise);

        pari = demande_pari();
        printf("vous avez parié : %d\n", pari);

        int resultat = 1 + random2() % 6;
        printf("resultat du lancer : %d\n", resultat);
        if (pari == resultat){
            printf("vous gagnez : %d\n", 2 * mise);
            argent += 2*mise;
        } else {
            printf("vous perdez la mise\n");
            argent -= mise;
        }
    }
    if (argent){
        printf ("bravo, vous avez ruiné le casino\n");
    } else {
        printf("vous êtes ruinés\n");
    }
}