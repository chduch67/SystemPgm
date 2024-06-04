#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    // 명령줄 인수의 개수가 3개가 아니면 사용법을 출력하고 종료.
    if (argc != 3) {
        fprintf(stderr, "사용법 : %s 파일1 파일2\n", argv[0]);
        return 1;
    }

    // 첫 번째 인수를 두 번째 인수로 이름 변경.
    if (rename(argv[1], argv[2]) != 0) {
        perror("rename");
        return 1;
    }

    return 0;
}
