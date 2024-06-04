#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

// 사용법을 출력하는 함수
void print_usage() {
    fprintf(stderr, "사용법 : ./mkdir 폴더\n");
    exit(EXIT_FAILURE);
}

// 메인 함수
int main(int argc, char *argv[]) {
    // 인수의 개수가 2개가 아닌 경우 사용법을 출력하고 종료.
    if (argc != 2) {
        print_usage();
    }

    // 첫 번째 명령줄 인수를 디렉토리 이름으로 설정.
    char *dir = argv[1];

    // 디렉토리를 생성. 권한은 0777 (모든 사용자가 읽기, 쓰기, 실행 가능)으로 설정.
    if (mkdir(dir, 0777) == -1) {
        perror("mkdir");
        exit(EXIT_FAILURE);
    }

    return 0;
    }
