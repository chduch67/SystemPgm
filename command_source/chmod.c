#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {
    // 인수의 개수가 3개가 아니면 사용법을 출력하고 종료.
    if (argc != 3) {
        fprintf(stderr, "사용법 : %s <모드> <파일>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // 모드 문자열을 정수로 변환.
    char *endptr;
    mode_t mode = strtol(argv[1], &endptr, 8);
    // 변환된 값이 잘못되었는지 확인.
    if (*endptr != '\0' || mode < 0 || mode > 0777) {  // "*endptr 1= '\0'"은 문자열의 끝에 도달하지 않았음을 확인하는 조건
        fprintf(stderr, "잘못된 모드: %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    // 파일의 권한을 변경.
    if (chmod(argv[2], mode) == -1) {
        perror("chmod");
        exit(EXIT_FAILURE);
    }

 
    return 0;
}
