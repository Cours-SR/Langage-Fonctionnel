#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define CHANGE(i, pos, val) i += val << pos;


int a,b,c,d,e,f;

int pwr(int base,int exp) {
    int res=1;
     
    while(exp>=1) {
        res*=base;
        exp--;
    }
    return(res);
}

int main() {

    // PARTIE 1

    // 2.
    // printf("Salut BG\n");
    // scanf("%c", &c);
    // printf("Tu as entré %c\n", c);

    // //verification pair/impair
    // if(c % 2 == 0){
    //     printf("Le nombre est pair\n");
    // }
    // else{
    //     printf("Le nombre est impair\n");
    // }

    // 3.
    // printf("Age ?\n");
    // scanf("%d", &c);
    // if(c < 5){
    //     printf("Gratuit\n");
    // }
    // else if(c < 20 && c >= 5){
    //     printf("15€\n");
    // }
    // else if(c >= 20 && c < 60){
    //     printf("50€\n");
    // }
    // else{
    //     printf("10€\n");
    // }

    //4.
    // printf("Entrez deux nombre\n");
    // scanf("%d %d", &c, &d);

    // //Plus grand
    // if(c > d){
    //     printf("%d est plus grand que %d\n", c, d);
    // }
    // else if(c < d){
    //     printf("%d est plus grand que %d\n", d, c);
    // }
    // else{
    //     printf("%d est égal à %d\n", c, d);
    // }

    // //valeur absolue
    // if(c < 0){
    //     c = -c;
    // }
    // if(d < 0){
    //     d = -d;
    // }
    // printf("La valeur absolue de c est %d\n", c);
    // printf("La valeur absolue de d est %d\n", d);

    // //plus grand valeur absolue
    // if(c > d){
    //     printf("%d est plus grand que %d\n", c, d);
    // }
    // else if(c < d){
    //     printf("%d est plus grand que %d\n", d, c);
    // }
    // else{
    //     printf("%d est égal à %d\n", c, d);
    // }


    //5.
    // printf("Entrez un floattant représentant le rayon d'un cercle\n");
    // scanf("%f", &c);
    // float d;
    // d = 2 * 3.14 * c;
    // c = 3.14 * c * c;
    // printf("la surface du cercle est %.2f\n", c);
    // printf("le périmètre du cercle est %.2f\n", d);

    //6.
    // printf("Entrez première lettre trois prénoms en majuscule\n");
    // scanf("%c %c %c", &c, &d, &e);
    
    // // Tri des lettres
    // if(c > d && c > e && d > e){
    //     printf("%c %c %c", e, d, c);
    // }
    // else if(c > e && c > d && e > d){
    //     printf("%c %c %c", d, e, c);
    // }
    // else if(d > c && d > e && c > e){
    //     printf("%c %c %c", e, c, d);
    // }
    // else if(d > e && d > c && e > c){
    //     printf("%c %c %c", c, e, d);
    // }
    // else if(e > c && e > d && c > d){
    //     printf("%c %c %c", d, c, e);
    // }
    // else if(e > d && e > c && d > c){
    //     printf("%c %c %c", c, d, e);
    // }

    //7.
    // printf("Entrez première lettre prénom en majuscule, l'âge, le temps et la distance Personne 1 puis la Personne 2\n");
    // scanf("%c %d %f %d %c %d %f %d", &prenom, &age, &temps, &distance, &prenom2, &age2, &temps2, &distance2);

    // float p1 = (distance/temps)*(distance/temps)/age;
    // float p2 = (distance2/temps2)*(distance2/temps2)/age2;

    // if(p1 > p2){
    //     printf("La personne 1 %c a un meilleur score, distance = %d, score = %.2f\n", prenom, distance, p1);
    //     if(prenom < prenom2){
    //         printf("Bravo \n");
    //     }
    //     else{
    //         printf("Désolé\n");
    //     }
    // }
    // else if(p2 > p1){
    //     printf("La personne 2 %c a un meilleur score, distance = %d, score = %.2f\n", prenom2, distance2, p2);
    //     if(prenom2 < prenom){
    //         printf("Bravo \n");
    //     }
    //     else{
    //         printf("Désolé\n");
    //     }
    // }
    // else{
    //     printf("Les deux personnes ont le même score\n");
    // }


    // PARTIE 2

    //7.
    // int test[32];
    // printf("Entrez 5 entiers\n");
    // scanf("%d %d %d %d %d", &e, &d, &c, &b, &a);
    

    // //MODE 1
    // //remplit 0
    // for(int i = 0; i < 32; i++){
    //     test[i] = 0;
    // }
    // int i = 0;
    // //par zone remplit les nombres dans le grp
    // while(e != 0){
    //     if(i >= 0 && i < 6){
    //         test[i] = a % 2;
    //         a = a / 2;
    //     }
    //     if(i >= 6 && i < 12){
    //         test[i] = b % 2;
    //         b = b / 2;
    //     }
    //     if(i >= 12 && i < 18){
    //         test[i] = c % 2;
    //         c = c / 2;
    //     }
    //     if(i >= 18 && i < 24){
    //         test[i] = d % 2;
    //         d = d / 2;
    //     }
    //     if(i >= 24 && i < 30){
    //         test[i] = e % 2;
    //         e = e / 2;
    //     }
    //     i++;
    // }
    // //Affiche nb binaire grp
    // for(int i = 30; i >= 0; i--){
    //     printf("%d", test[i]);
    // }
    // int decimal = 0;
    // int puissance = 1;
    // for(int i = 0; i < 32; i++){
    //     decimal = decimal + test[i] * puissance;
    //     puissance = puissance * 2;
    // }
    // printf("\n%d\n", decimal);

    //MODE 2

    // printf("Entrez un entier decimal a séparé en 5 chiffres\n");
    // scanf("%d", &a);

    // //remplit 0
    // for(int i = 0; i < 31; i++){
    //     test[i] = 0;
    // }
    // int i = 0;
    // //converti en binaire
    // while(a != 0){
    //     test[i] = a % 2;
    //     a = a / 2;
    //     i++;
    // }
    // //Affiche nb binaire grp
    // for(int i = 31; i >= 0; i--){
    //     printf("%d", test[i]);
    // }

    // //converti en decimal par morceau avec &&
    // int j = 0;
    // for(int i = 0; i <= 5; i++){
    //     if(test[i] & 1){
    //         a = a + pwr(2, j);
    //     }
    //     j++;
    // }
    // j = 0;
    // for(int i = 6; i <= 11; i++){
    //     if(test[i] & 1){
    //         b = b + pwr(2, j);
    //     }
    //     j++;
    // }
    // j = 0;
    // for(int i = 12; i <= 17; i++){
    //     if(test[i] & 1){
    //         c = c + pwr(2, j);
    //     }
    //     j++;
    // }
    // j = 0;
    // for(int i = 18; i <= 23; i++){
    //     if(test[i] & 1){
    //         d = d + pwr(2, j);
    //     }
    //     j++;
    // }
    // j = 0;
    // for(int i = 24; i <= 29; i++){
    //     if(test[i] & 1){
    //         e = e + pwr(2, j);
    //     }
    //     j++;
    // }
    // printf("\n%d %d %d %d %d\n", e, d, c, b, a);


    //8.
    // printf("Entrez 6 nombres\n");
    // scanf("%d %d %d %d %d %d", &a,&b,&c,&d,&e,&f);

    // int res, pair, impair;
    // (a % 2 == 0) ? (pair += a) : (++impair);
    // (b % 2 == 0) ? (pair += b) : (++impair);
    // (c % 2 == 0) ? (pair += c) : (++impair);
    // (d % 2 == 0) ? (pair += d) : (++impair);
    // (e % 2 == 0) ? (pair += e) : (++impair);
    // (f % 2 == 0) ? (pair += f) : (++impair);

    // res = pair * impair;
    
    
    // printf("%d",res);

    //9.
    //a)
    int a = 1000;
    CHANGE(a, 0, 1);
    printf("%d\n", a);
    return 0;
}