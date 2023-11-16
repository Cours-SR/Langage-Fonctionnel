#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* lowerCase(char* str){
    if(str[0] == '\0'){
        return str;
    }
    int i = 0;
    while(str[i] != '\0'){
        if(str[i] >= 'A' && str[i] <= 'Z'){
            str[i] +=32;
        }
        i++;
    }
    return str;
}

int swap(int* a, int* b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
    return 0;
}

char* concat(const char* str1, const char* str2){
    int i = 0;
    int j = 0;
    while(str1[i] != '\0'){ //on va à la fin de str1
        i++;
    }
    while(str2[j] != '\0'){ //on va à la fin de str2
        j++;
    }

    char* result = (char*)malloc(i + j + 1); //alloue taille exacte
    
    strcpy(result, str1); // Copie contenu str1 dans result
    strcpy(result + i, str2); // Copie contenu str2 suite str1

    // printf("%s\n", result);
    return result;
}

void demandeChaine() {
    char* resultat = NULL;
    char str1[100];
    char str2[100];

    printf("Entrez deux chaîne de caractères : ");
    scanf("%s %s", str1, str2);
    resultat = concat(str1, str2);

    while(1) {
        printf("%s\n", resultat);
        printf("Rajoutez ? (F stop) : ");
        scanf("%s", str1);
        if(strcmp(str1, "F") != 0) {
            resultat = concat(resultat, str1);
        }
        else {
            break;
        }
    }
    printf("%s\n", resultat);
    free(resultat);
}

char* concatmul(int n, char** str){
    int len = 0;
    for(int i = 0; i < n; i++){ //calcule taille chaine
        len += strlen(str[i]);
    }

    char* result = malloc(sizeof(char) * (len + 1)); //alloue taille exacte

    for(int i = 0; i < n; i++){
        char* temp = concat(result, str[i]);
        free(result); 
        result = temp;
    }

    printf("%s\n", result);
    return result;
}

int* createTabValSize(){
    int* tab = malloc(sizeof(int) * 1);
    tab[0] = 1;
    return tab;
}

int addSizeTab(int* tab){
    tab[0]++; //on ajoute 1 à la taille du tableau
    tab = realloc(tab, sizeof(int) * tab[0]); //on réalloue la mémoire    
}

int libereTab(int* tab){
    free(tab);
    return 0;
}

int afficheTabReverse(int* tab){
    for(int i = tab[0]; i > 0; i--){
        printf("%d ", tab[i]);
    }
}

int remplirTab(int* tab){
    int entree = 1;
    printf("Entrez des valeurs : (0 pour afficher et finir)\n");
    scanf("%d", &entree);
    while(entree != 0){
        addSizeTab(tab);
        printf("size : %d\n", tab[0]);
        tab[tab[0]] = entree;
        scanf("%d", &entree);
    }
    afficheTabReverse(tab);
}

struct User{
    int age;
    char* name;
    float height;
};

struct User ask_user(){
    struct User user;
    user.name = malloc(11);
    scanf("%d", &(user.age));
    scanf("%s", user.name);
    scanf("%f", &(user.height));
    return user;
}

struct User* fill_users(int* n){
    printf("how many \n");
    scanf("%d", n);
    struct User* users = malloc(sizeof(struct User) * *n);
    for (int i = 0; i < *n; i++){
    users[i] = ask_user();
    }
    return users;
}

void print_users(struct User* users, int nb_users){
    for (int i = 0; i < nb_users; i++){
        printf("name : %s, height : %f, age: %d\n", users[i].name, users[i].height, users[i].age);
    }
}

int main(){
    int n;
    struct User* users = fill_users(&n);
    print_users(users, n);
    free(users);

    //1
    // char* str = malloc(sizeof(char) * 100);
    // strcpy(str, "HELLO");
    // lowerCase(str);
    // printf("%s\n", str);  
    // free(str);

    //2
    // int a = 5;
    // int b = 10;
    // swap(&a, &b);
    // printf("%d %d\n", a, b);

    //3
    // char* str1 = malloc(sizeof(char) * 10);
    // char* str2 = malloc(sizeof(char) * 10);
    // strcpy(str1, "HELLO");
    // strcpy(str2, "WORLD");
    // concat(str1, str2);
    // free(str1);
    // free(str2);

    // demandeChaine();

    // char* test[] = {"Hello"," ", "World", " ", "!"};
    // char* result = concatmul(5, test);
    // free(result);

    //4
    // int* tab = createTabValSize();
    // remplirTab(tab);
    // libereTab(tab);

    return 0;
}