#include <stdio.h>
#include <stdbool.h>
#define STATES 3
int nfa[STATES][2][STATES] = {
    {{0, 2}, {0, 0}},
    {{0, 2}, {0, 0}},
    {{0, 0}, {0, 0}}
};
bool epsilon[STATES][STATES] = {
    {false, true, false},
    {false, false, false},
    {false, false, false}
};
void epsilonClosure(int state, bool closure[]) {
    closure[state] = true;
    for (int i = 0; i < STATES; i++) {
        if (epsilon[state][i] && !closure[i]) {
            epsilonClosure(i, closure);
        }
    }
}
int main() {
    for (int i = 0; i < STATES; i++) {
        bool closure[STATES] = { false };
        epsilonClosure(i, closure);
        printf("e-closure(q%d): {", i);
        for (int j = 0; j < STATES; j++) {
            if (closure[j]) {
                printf(" q%d", j);
            }
        }
        printf(" }\n");
    }
    return 0;
}

