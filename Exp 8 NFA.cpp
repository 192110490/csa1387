#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define STATES 3
bool nfaSimulate(char *input) {
    int currentState = 0;
    for (int i = 0; input[i] != '\0'; i++) {
        if (currentState == 0 && input[i] == 'b') {
            currentState = 1;
        } else if (currentState == 1 && input[i] == 'a') {
            currentState = 2;
        }
    }
    return currentState == 2;
}
int main() {
    char input[100];
    
    printf("Enter a string: ");
    scanf("%s", input);
    
    if (nfaSimulate(input)) {
        printf("Accepted\n");
    } else {
        printf("Rejected\n");
    }   
    return 0;
}

