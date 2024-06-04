#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


void print_usage() {
    fprintf(stderr, "사용법 : ./rmdir 폴더\n");
    exit(EXIT_FAILURE);
}


int main(int argc, char *argv[]) {
    // 명령줄 인수의 개수가 2개가 아니면 사용법을 출력하고 종료.
    if (argc != 2) {
        print_usage();
    }

    // 첫 번째 명령줄 인수를 디렉토리로 설정.
    char *dir = argv[1];

    // 디렉토리를 삭제합니다. 실패하면 오류 메시지를 출력하고 종료.
    if (rmdir(dir) == -1) {
        perror("rmdir");
        exit(EXIT_FAILURE);
    }

    return 0;
}
