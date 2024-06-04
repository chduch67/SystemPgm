#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "사용법: %s -v <모드> <파일>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *endptr;
    mode_t mode = strtol(argv[2], &endptr, 8);
    if (*endptr != '\0' || mode < 0 || mode > 0777) {
        fprintf(stderr, "잘못된 모드: %s\n", argv[2]);
        exit(EXIT_FAILURE);
    }

    if (chmod(argv[3], mode) == -1) {
        perror("chmod");
        exit(EXIT_FAILURE);
    }

    printf("'%s'의 권한을 %o로 변경했습니다.\n", argv[3], mode);
    return 0;
}

