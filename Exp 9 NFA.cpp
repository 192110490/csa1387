#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define STATES 3
bool nfaSimulate(char *input) {
    int currentState = 0;
    for (int i = 0; input[i] != '\0'; i++) {
        switch (currentState) {
            case 0:
                if (input[i] == '0') {
                    currentState = 1;
                }
                break;
            case 1:
                if (input[i] == '1') {
                    currentState = 2;
                } else if (input[i] == '0') {
                    currentState = 1;
                }
                break;
            default:
                break;
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

