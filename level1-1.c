#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT 50

typedef enum {
    USER_NORMAL,
    USER_ADMIN, 
    USER_NONE
} UserType;

typedef struct {
    char username;
    UserType type;
} User;

int main() {
    User current_user = {' ', USER_NONE};
    char input[MAX_INPUT];
    
    printf("=== library system ===\n");
    printf("you can enter: login, exit, quit\n\n");
    
    while (1) {
        if (current_user.type == USER_NONE) {
            printf("\n");}
         else if (current_user.type == USER_ADMIN) {
            printf("welcome admin\n");
        } else  {
            printf("welcome %c\n", current_user.username);
        }
        
        printf("please enter: ");
        scanf("%s", input);
        
        for (int i = 0; input[i]; i++) {
            input[i] = tolower(input[i]);
        }
        
        if (strcmp(input, "login") == 0) {
            if (current_user.type != USER_NONE) {
                printf("please exit the current account\n");
            } else {
                char username;
                printf("please enter the user name ");
                scanf(" %c", &username);
                
                if ((username >= 'A' && username <= 'Z') || 
                          (username >= 'a' && username <= 'z')) {
                    current_user.type = USER_NORMAL;
                    current_user.username = toupper(username);
                    printf("Are you admin?(answer 'yes' or 'no')\n");
                    scanf("%s",input);
                    if(strcmp(input,"yes")==0){
                         current_user.type = USER_ADMIN;
                         
                    }else {
                        continue;
                    }
                } else {
                    printf("the user's name must be A-Z\n");
                }
            }
        }
        else if (strcmp(input, "exit") == 0) {
            if (current_user.type == USER_NONE) {
                printf("you haven't login\n");
            } else {
                printf("exit successsful\n");
                current_user.type = USER_NONE;
                current_user.username = ' ';
            }
        }
        else if (strcmp(input, "quit") == 0) {
            printf("Goodbye!\n");
            break;
        }
        else {
            printf("error commands,you can erter: login, exit, quit\n");
        }
        printf("\n");
    }
    
    return 0;
}
