#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    DIR *dp;                     // 디렉토리를 가리키는 포인터
    struct dirent *d;            // 디렉토리 엔트리를 가리키는 포인터
    char *dir;                   // 디렉토리 경로를 저장할 변수

    // 인수가 없으면 현재 디렉토리를 사용
    if (argc == 1) {
        dir = ".";
    } else {
        dir = argv[1];
    }

    // 디렉토리를 열고, 실패 시 오류 메시지 출력 후 종료
    if ((dp = opendir(dir)) == NULL) {
        perror(dir);
        exit(1);
    }

    // 디렉토리 엔트리를 읽고, 숨김 파일이 아니면 출력
    while ((d = readdir(dp)) != NULL) {
        if (d->d_name[0] != '.') {
            printf("%s\n", d->d_name);
        }
    }

    // 디렉토리 스트림을 닫음
    closedir(dp);
    return 0;
}
