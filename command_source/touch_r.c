#include <stdio.h>
#include <stdlib.h>
#include <utime.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "사용법 : %s 참조파일  파일\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    struct stat st;
    if (stat(argv[1], &st) == -1) {
        perror("stat");
        exit(EXIT_FAILURE);
    }

    struct utimbuf ut;
    ut.actime = st.st_atime;
    ut.modtime = st.st_mtime;

    if (utime(argv[2], &ut) == -1) {
        perror("utime");
        exit(EXIT_FAILURE);
    }

    return 0;
}

