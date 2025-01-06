#include <stdio.h>
#include <string.h>

void generate_assembly(char *ir[], int n) {
    for (int i = 0; i < n; i++) {
        char op[10], arg1[10], arg2[10], result[10];
        sscanf(ir[i], "%s = %s %s %s", result, arg1, op, arg2);

        if (strcmp(op, "+") == 0) {
            printf("LOAD R1, %s\n", arg1);
            printf("ADD R1, %s\n", arg2);
            printf("STORE %s, R1\n", result);
        } else if (strcmp(op, "-") == 0) {
            printf("LOAD R1, %s\n", arg1);
            printf("SUB R1, %s\n", arg2);
            printf("STORE %s, R1\n", result);
        } else if (strcmp(op, "*") == 0) {
            printf("LOAD R1, %s\n", arg1);
            printf("MUL R1, %s\n", arg2);
            printf("STORE %s, R1\n", result);
        } else if (strcmp(op, "/") == 0) {
            printf("LOAD R1, %s\n", arg1);
            printf("DIV R1, %s\n", arg2);
            printf("STORE %s, R1\n", result);
        } else {
            printf("LOAD R1, %s\n", arg1);
            printf("STORE %s, R1\n", result);
        }
    }
}

int main() {
    char *ir[] = {
        "t1 = a + b",
        "t2 = t1 * c",
        "d = t2"
    };
    int n = sizeof(ir) / sizeof(ir[0]);

    printf("Assembly Code:\n");
    generate_assembly(ir, n);

    return 0;
}
