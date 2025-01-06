#include <stdio.h>
#include <string.h>
#include <ctype.h>

int temp_count = 0;

void generate_three_address_code(char *expr) {
    char temp[10];
    char op;
    int i = 0, j = 0;

    while (expr[i] != '\0') {
        if (isdigit(expr[i]) || isalpha(expr[i])) {
            temp[j++] = expr[i];
        } else if (expr[i] == '+' || expr[i] == '-' || expr[i] == '*' || expr[i] == '/') {
            temp[j] = '\0';
            printf("t%d = %s\n", temp_count++, temp);
            j = 0;
            temp[j++] = 't';
            temp[j++] = temp_count - 1 + '0';
            temp[j++] = '\0';
            op = expr[i];
        }
        i++;
    }
    temp[j] = '\0';
    printf("t%d = %s %c %c\n", temp_count, temp, op, expr[i - 1]);
}

int main() {
    char expr[100];
    printf("Enter an arithmetic expression: ");
    scanf("%s", expr);
    generate_three_address_code(expr);
    return 0;
}
