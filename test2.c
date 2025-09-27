#include <stdio.h>
#include <string.h>

int main() {
    char input[50];
    char actual_key[50];
    
    printf("Enter key (or 'Quit' to exit):\n");

    while (1) {
        printf("> ");
        
        if (fgets(input, sizeof(input), stdin) == NULL) {
            break;
        }
        
        int len = strlen(input);
        if (len > 0 && input[len-1] == '\n') {
            input[len-1] = '\0';
        }
        
        if (strlen(input) == 0) {
            continue;
        }
        
        if (strcmp(input, "Quit") == 0) {
            break;
        }
        
        strcpy(actual_key, input);
        char *space_pos = strchr(actual_key, ' ');
        if (space_pos != NULL) {
            *space_pos = '\0';  
        }
        
        FILE *file = fopen("data.txt", "r");
        if (file == NULL) {
            printf("Error\n");
            continue;
        }
        
        char line[100];
        int found = 0;
        
        while (fgets(line, sizeof(line), file) != NULL) {
            char *colon = strchr(line, ':');
            if (colon == NULL) continue;
            
            *colon = '\0';
            
            char *key = line;
            while (*key == ' ') key++;
            char *key_end = key + strlen(key) - 1;
            while (key_end > key && isspace((unsigned char)*key_end)) {
                *key_end = '\0';
                key_end--;
            }
            
            if (strcmp(actual_key, key) == 0) {
                char *value = colon + 1;
                int value_len = strlen(value);
                if (value_len > 0 && value[value_len-1] == '\n') {
                    value[value_len-1] = '\0';
                }
                
                while (*value == ' ') value++;
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
