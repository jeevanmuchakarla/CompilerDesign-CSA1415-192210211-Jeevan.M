#include <stdio.h>
#include <string.h>

int current = 0; // Tracks the current position in the input string

// Function declarations for grammar rules
int S(const char *input);
int A(const char *input);

int S(const char *input) {
    // Rule: S -> aA
    if (input[current] == 'a') {
        current++;
        if (A(input)) {
            return 1; // Successfully parsed S -> aA
        }
    }
    return 0; // Parsing failed
}

int A(const char *input) {
    // Rule: A -> bA | c
    if (input[current] == 'b') {
        current++;
        if (A(input)) {
            return 1; // Successfully parsed A -> bA
        }
    } else if (input[current] == 'c') {
        current++;
        return 1; // Successfully parsed A -> c
    }
    return 0; // Parsing failed
}

int main() {
    char input[100];
    printf("Enter the input string: ");
    scanf("%s", input);

    current = 0; // Reset the position
    if (S(input) && input[current] == '\0') {
        printf("The string '%s' satisfies the grammar.\n", input);
    } else {
        printf("The string '%s' does not satisfy the grammar.\n", input);
    }

    return 0;
}
