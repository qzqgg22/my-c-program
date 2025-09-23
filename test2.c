#include <stdio.h>
#include <string.h>

int main() {
    char input[20];
    
    printf("Enter key (or 'Quit' to exit):\n");

    while (1) {
        printf("> ");
        scanf("%s", input);
        
        if (strcmp(input, "Quit") == 0) {
            break;
        }
        
        FILE *file = fopen("data.txt", "r");
        if (file == NULL) {
            printf("Error\n");
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