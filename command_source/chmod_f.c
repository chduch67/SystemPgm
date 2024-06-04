#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "사용법: %s -f <모드> <파일>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *endptr;
    mode_t mode = strtol(argv[2], &endptr, 8);
    if (*endptr != '\0' || mode < 0 || mode > 0777) {
        fprintf(stderr, "잘못된 모드: %s\n", argv[2]);
        exit(EXIT_FAILURE);
    }

    chmod(argv[3], mode);

    return 0;
}

