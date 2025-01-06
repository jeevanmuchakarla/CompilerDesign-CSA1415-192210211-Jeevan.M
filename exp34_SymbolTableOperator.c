#include <stdio.h>
#include <string.h>

#define MAX_SYMBOLS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    char type[MAX_NAME_LENGTH];
    int size;
    int address;
} Symbol;

typedef struct {
    Symbol table[MAX_SYMBOLS];
    int count;
} SymbolTable;

void initialize(SymbolTable *st) {
    st->count = 0;
}

int insert(SymbolTable *st, char *name, char *type, int size, int address) {
    for (int i = 0; i < st->count; i++) {
        if (strcmp(st->table[i].name, name) == 0) {
            printf("Error: Symbol '%s' already exists in the table.\n", name);
            return 0;
        }
    }
    if (st->count >= MAX_SYMBOLS) {
        printf("Error: Symbol table is full.\n");
        return 0;
    }
    strcpy(st->table[st->count].name, name);
    strcpy(st->table[st->count].type, type);
    st->table[st->count].size = size;
    st->table[st->count].address = address;
    st->count++;
    return 1;
}

int search(SymbolTable *st, char *name) {
    for (int i = 0; i < st->count; i++) {
        if (strcmp(st->table[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

void display(SymbolTable *st) {
    if (st->count == 0) {
        printf("Symbol table is empty.\n");
        return;
    }
    printf("Symbol Table:\n");
    printf("%-15s %-15s %-10s %-10s\n", "Name", "Type", "Size", "Address");
    printf("-----------------------------------------------------------\n");
    for (int i = 0; i < st->count; i++) {
        printf("%-15s %-15s %-10d %-10d\n",
               st->table[i].name,
               st->table[i].type,
               st->table[i].size,
               st->table[i].address);
    }
}

int main() {
    SymbolTable st;
    initialize(&st);

    int choice;
    char name[MAX_NAME_LENGTH], type[MAX_NAME_LENGTH];
    int size, address;

    do {
        printf("\nSymbol Table Operations:\n");
        printf("1. Insert\n");
        printf("2. Search\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter Name: ");
            scanf("%s", name);
            printf("Enter Type: ");
            scanf("%s", type);
            printf("Enter Size: ");
            scanf("%d", &size);
            printf("Enter Address: ");
            scanf("%d", &address);
            if (insert(&st, name, type, size, address)) {
                printf("Symbol inserted successfully.\n");
            }
            break;
        case 2:
            printf("Enter Name to search: ");
            scanf("%s", name);
            int index = search(&st, name);
            if (index != -1) {
                printf("Symbol found: Name=%s, Type=%s, Size=%d, Address=%d\n",
                       st.table[index].name,
                       st.table[index].type,
                       st.table[index].size,
                       st.table[index].address);
            } else {
                printf("Symbol not found.\n");
            }
            break;
        case 3:
            display(&st);
            break;
        case 4:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}
