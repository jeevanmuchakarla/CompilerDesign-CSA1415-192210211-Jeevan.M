#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_EXPR_LEN 100
#define MAX_TEMP_VARS 10

typedef struct {
    char expr[MAX_EXPR_LEN];
    char temp[MAX_TEMP_VARS][MAX_EXPR_LEN];
    int temp_count;
} Optimizer;

void eliminate_common_subexpressions(Optimizer *opt) {
    char *token;
    char *delim = " ";
    int i, j;

    token = strtok(opt->expr, delim);
    while (token != NULL) {
        int found = 0;
        for (i = 0; i < opt->temp_count; i++) {
            if (strcmp(token, opt->temp[i]) == 0) {
                found = 1;
                break;
            }
        }
        if (!found) {
            strcpy(opt->temp[opt->temp_count++], token);
        }
        token = strtok(NULL, delim);
    }

    printf("Optimized Expression:\n");
    for (i = 0; i < opt->temp_count; i++) {
        printf("t%d = %s\n", i, opt->temp[i]);
    }
}

int main() {
    Optimizer opt;
    opt.temp_count = 0;

    printf("Enter an arithmetic expression: ");
    fgets(opt.expr, MAX_EXPR_LEN, stdin);
    opt.expr[strcspn(opt.expr, "\n")] = '\0'; // Remove newline character

    eliminate_common_subexpressions(&opt);

    return 0;
}
