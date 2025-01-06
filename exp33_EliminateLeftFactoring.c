#include <stdio.h>
#include <string.h>

#define MAX_PRODUCTIONS 10
#define MAX_LENGTH 50

void eliminateLeftFactoring(char production[MAX_PRODUCTIONS][MAX_LENGTH], int n) {
    char commonPrefix[MAX_LENGTH];
    int prefixLength = 0;
    int i, j;

    // Find the longest common prefix among the productions
    strcpy(commonPrefix, production[0]);
    for (i = 1; i < n; i++) {
        j = 0;
        while (commonPrefix[j] && production[i][j] && commonPrefix[j] == production[i][j]) {
            j++;
        }
        commonPrefix[j] = '\0'; // Truncate the common prefix to the current match
    }

    prefixLength = strlen(commonPrefix);

    if (prefixLength == 0) {
        printf("No left factoring needed.\n");
        return;
    }

    printf("Left factoring found. Common prefix: '%s'\n", commonPrefix);

    // Output the factored productions
    printf("Updated productions:\n");
    printf("A -> %sA'\n", commonPrefix); // A represents the non-terminal

    printf("A' -> ");
    for (i = 0; i < n; i++) {
        if (strlen(production[i]) == prefixLength) {
            printf("ε"); // ε represents the empty production
        } else {
            printf("%s", production[i] + prefixLength);
        }
        if (i < n - 1) {
            printf(" | ");
        }
    }
    printf("\n");
}

int main() {
    int n, i;
    char production[MAX_PRODUCTIONS][MAX_LENGTH];

    printf("Enter the number of productions: ");
    scanf("%d", &n);
    getchar(); // Clear the newline from the input buffer

    printf("Enter the productions (format: ...):\n");
    for (i = 0; i < n; i++) {
        printf("Production %d: ", i + 1);
        fgets(production[i], MAX_LENGTH, stdin);
        production[i][strcspn(production[i], "\n")] = '\0'; // Remove trailing newline
    }

    eliminateLeftFactoring(production, n);

    return 0;
}
