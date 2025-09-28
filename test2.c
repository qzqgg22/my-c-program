#include <stdio.h>
#include <string.h>

int main() {
    char input[20];
    FILE *file;
    
    printf("Enter key (or 'Quit' to exit):\n");

    while (1) {
        printf("> ");
        if (fgets(input,sizeof(input),stdin)==NULL){
        break;
        }
        int lenth=strlen(input);
        if(lenth>0 && input[lenth-1]=='\n'){
            input[lenth-1]='\0';
        
        }
        if (strcmp(input, "Quit") == 0) {
            break;
        }
        
        
        if (strchr(input, ' ') != NULL) {
            printf("Error\n");
            continue;
        }
        
        file = fopen("data.txt", "r");
        if (file == NULL) {
            printf("Error opening file\n");
            continue;
        }
        
        char line[50];
        int found = 0;
        
        while (fgets(line, sizeof(line), file) != NULL) {
            char *colon = strchr(line, ':');
            if (colon == NULL) continue;
            
            *colon = '\0';
            if (strcmp(input, line) == 0) {
                char *value = colon + 1;
                int len = strlen(value);
                if (len > 0 && value[len-1] == '\n') {
                    value[len-1] = '\0';
                }
                printf("%s\n", value);  
                found = 1;
                break;
            }
        }
        
        fclose(file);
        
        if (!found) {
            printf("Error\n");
        }
    }
    
    return 0;
}
