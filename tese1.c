#include <stdio.h>
#include <string.h> 

int main() {
    char input[50]; 

    printf("Please enter a command ('Dian' or 'Quit'): \n");

    while (1) { 
        scanf("%s", input); 

        if (strcmp(input, "Dian") == 0) {            
            printf("2002\n");
        } else if (strcmp(input, "Quit") == 0) {
            printf("Exiting the program. Goodbye!\n");
            break;
        } else
            printf("Error\n");
        }
    

    return 0;
}