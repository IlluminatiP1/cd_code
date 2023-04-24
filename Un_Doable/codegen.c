#include <stdio.h>
#include <string.h>

int main() {
    char code[100][100];
    int n, i, j, t = 0;

    // Read the 3-address code
    printf("Enter the 3-address code:\n");
    scanf("%d", &n);
    for(i = 0; i < n; i++) {
        scanf("%s", code[i]);
    }

    // Generate symbol table
    char symbols[100][10];
    int mem_locs[100], num_symbols = 0;
    for(i = 0; i < n; i++) {
        char *token = strtok(code[i], " ");
        while(token != NULL) {
            if(token[0] >= 'a' && token[0] <= 'z') {
                int k;
                for(k = 0; k < num_symbols; k++) {
                    if(strcmp(symbols[k], token) == 0) {
                        break;
                    }
                }
                if(k == num_symbols) {
                    strcpy(symbols[num_symbols], token);
                    mem_locs[num_symbols] = t;
                    num_symbols++;
                }
            }
            token = strtok(NULL, " ");
        }
        t++;
    }

    // Allocate memory for variables
    printf("Symbol Table:\n");
    for(i = 0; i < num_symbols; i++) {
        printf("%s\t%d\n", symbols[i], mem_locs[i]);
    }

    // Generate assembly code
    printf("Assembly code:\n");
    for(i = 0; i < n; i++) {
        char *token = strtok(code[i], " ");
        while(token != NULL) {
            if(token[0] >= 'a' && token[0] <= 'z') {
                int k;
                for(k = 0; k < num_symbols; k++) {
                    if(strcmp(symbols[k], token) == 0) {
                        printf("mov ax, [%d]\n", mem_locs[k]);
                        printf("push ax\n");
                        break;
                    }
                }
            }
            else if(token[0] == '+' || token[0] == '-' || token[0] == '*' || token[0] == '/') {
                printf("pop bx\n");
                printf("pop ax\n");
                switch(token[0]) {
                    case '+': printf("add ax, bx\n"); break;
                    case '-': printf("sub ax, bx\n"); break;
                    case '*': printf("mul bx\n"); break;
                    case '/': printf("div bx\n"); break;
                }
                printf("push ax\n");
            }
            else {
                printf("mov ax, %s\n", token);
                printf("push ax\n");
            }
            token = strtok(NULL, " ");
        }
        printf("\n");
    }

    return 0;
}
