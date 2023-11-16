#include "stdio.h"
#include "string.h"
#include "stdlib.h"


int main(){
    char message[50] = "msg";
    char user_input[8];
    char password[8] = "bonjour";
    int logged_in = 0;
    printf(" msg : %p\n", message);
    printf(" password : %p\n", password);
    printf(" user : %p\n", user_input);
    printf(" logged : %p\n", &logged_in);

    while (!logged_in){
        // Ask the user for the password
        printf(" %s\n", password);
        printf("please enter a password\n");
        // scanf("%s", user_input);
        int i = 8;
        int ch = 0;
        while(i--){
            ch = getchar();
            if(ch == '\n'){
                break;
            }
            user_input[i] = ch;
        }
        printf("%d\n", logged_in);

        
        
        if (!strcmp(user_input, password)){
            logged_in = 1;
        } 
        else {
            printf("Wrong password\nWould you like to send a request to the admin ? (y/n)");

            // ask the user if he wants to send a permission request to the admins
            char send_msg;
            scanf(" %c", &send_msg);
            if(send_msg == 'y'){
                while(strlen(message) > 50){
                    printf("write your message here : \n");
                    scanf("%s", message);
                }
                printf("we will send your request : (%s)\n", message);
            }

            // ask the user if they want to try again or leave
            printf("do you wish to try again ? (y/n)");
            char try_again;
            scanf(" %c", &try_again);
            if (!try_again){
                exit(0);
            }
        }
    }
    printf("You are logged in ! \n");
}