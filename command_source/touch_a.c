#include <stdio.h>
#include <stdlib.h>
#include <utime.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "사용법 : %s 파일1 [파일2 ...]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    for (int i = 1; i < argc; i++) {
        struct utimbuf ut;
        ut.actime = time(NULL);
        ut.modtime = -1; // 수정 시간을 변경하지 않음
        if (utime(argv[i], &ut) == -1) {
            perror("utime");
            exit(EXIT_FAILURE);
        }
    }

    return 0;
}

