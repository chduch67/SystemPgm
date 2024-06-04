#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

    // 파일 이름을 명령줄 인수에서 가져온다.
    char *file = argv[1];

    // 파일을 읽기 모드로 연다
    FILE *fp = fopen(file, "r");
    if (fp == NULL) {
        // 파일 열기에 실패한 경우 오류 메시지를 출력하고 프로그램을 종료.
        perror("fopen");
        exit(EXIT_FAILURE);
    }

    // 읽어들인 데이터를 저장할 버퍼를 선언.
    char buffer[BUFSIZ];
    
    // 파일의 끝에 도달할 때까지 한 줄씩 읽어서 출력.
    while (fgets(buffer, BUFSIZ, fp) != NULL) {
        printf("%s", buffer);
    }

   
    fclose(fp);

    return 0;
}
