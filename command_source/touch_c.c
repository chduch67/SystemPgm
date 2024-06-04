#include <stdio.h>
#include <stdlib.h>
#include <utime.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "사용법 : %s 파일1 [파일2 ...]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    for (int i = 1; i < argc; i++) {
        FILE *file = fopen(argv[i], "r");
        if (file) {
            fclose(file);
            // 파일이 존재할 경우에만 시간을 변경
            struct utimbuf ut;
            ut.actime = ut.modtime = time(NULL);
            if (utime(argv[i], &ut) == -1) {
                perror("utime");
                exit(EXIT_FAILURE);
            }
        }
    }

    return 0;
}

