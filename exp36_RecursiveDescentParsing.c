#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Global variables
const char *input;
int current = 0;

// Function declarations for grammar rules
int E();
int EPrime();
int T();
int TPrime();
int F();

void error() {
    printf("Error: Invalid string.\n");
    exit(1);
}

void match(char expected) {
    if (input[current] == expected) {
        current++;
    } else {
        error();
    }
}

// E -> T E'
int E() {
    if (T()) {
        if (EPrime()) {
            return 1;
        }
    }
    return 0;
}

// E' -> + T E' | ε
int EPrime() {
    if (input[current] == '+') {
        match('+');
        if (T()) {
            if (EPrime()) {
                return 1;
            }
        }
        return 0;
    }
    // E' -> ε (empty production)
    return 1;
}

// T -> F T'
int T() {
    if (F()) {
        if (TPrime()) {
            return 1;
        }
    }
    return 0;
}

// T' -> * F T' | ε
int TPrime() {
    if (input[current] == '*') {
        match('*');
        if (F()) {
            if (TPrime()) {
                return 1;
            }
        }
        return 0;
    }
    // T' -> ε (empty production)
    return 1;
}

// F -> ( E ) | id
int F() {
    if (input[current] == '(') {
        match('(');
        if (E()) {
            if (input[current] == ')') {
                match(')');
                return 1;
            }
        }
        return 0;
    } else if (isalpha(input[current])) { // Match identifier (id)
        match(input[current]);
        return 1;
    }
    return 0;
}

int main() {
    char buffer[100];
    printf("Enter the input string: ");
    scanf("%s", buffer);

    input = buffer;
    current = 0;

    if (E() && input[current] == '\0') {
        printf("The string '%s' is valid.\n", buffer);
    } else {
        printf("The string '%s' is invalid.\n", buffer);
    }

    return 0;
}
