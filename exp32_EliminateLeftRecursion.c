#include <stdio.h>
#include <string.h>

#define MAX_PRODUCTIONS 10
#define MAX_LENGTH 50

void eliminateLeftRecursion(char production[MAX_PRODUCTIONS][MAX_LENGTH], char nt, int n) {
    char alpha[MAX_PRODUCTIONS][MAX_LENGTH], beta[MAX_PRODUCTIONS][MAX_LENGTH];
    int alphaCount = 0, betaCount = 0;

    for (int i = 0; i < n; i++) {
        if (production[i][0] == nt) {
            // Left recursion case
            strcpy(alpha[alphaCount], production[i] + 1); // Skip the non-terminal
            alphaCount++;
        } else {
            // Non-left-recursive case
            strcpy(beta[betaCount], production[i]);
            betaCount++;
        }
    }

    if (alphaCount == 0) {
        // No left recursion
        printf("No Left Recursion found.\n");
        return;
    }

    // Output the updated productions
    printf("Updated productions after eliminating left recursion:\n");
    for (int i = 0; i < betaCount; i++) {
        printf("%c -> %s%c'\n", nt, beta[i], nt);
    }
    for (int i = 0; i < alphaCount; i++) {
        printf("%c' -> %s%c'\n", nt, alpha[i], nt);
    }
    printf("%c' -> ε\n", nt); // ε denotes epsilon (empty production)
}

int main() {
    int n;
    char nt;
    char production[MAX_PRODUCTIONS][MAX_LENGTH];

    printf("Enter the number of Productions: ");
    scanf("%d", &n);
    getchar(); // Clear the newline left in the buffer

    printf("Enter the Non-Terminal element: ");
    scanf("%c", &nt);
    getchar(); // Clear the newline left in the buffer

    printf("Enter the production rules (format: ...):\n");
    for (int i = 0; i < n; i++) {
        printf("Production %d: ", i + 1);
        fgets(production[i], MAX_LENGTH, stdin);
        production[i][strcspn(production[i], "\n")] = 0; // Remove trailing newline
    }

    eliminateLeftRecursion(production, nt, n);

    return 0;
}
