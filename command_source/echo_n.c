#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("\n");
        return 0;
    }

    for (int i = 1; i < argc; i++) {
        printf("%s", argv[i]);
        if (i != argc - 1)
            printf(" ");
    }

    return 0;
}

