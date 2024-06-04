#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[]) { 
    int fd1, fd2, n;
    char buf[BUFSIZ];

    // 명령줄 인수가 3개인지 확인.
    if (argc != 3) { 
        fprintf(stderr, "사용법: %s file1 file2\n", argv[0]); 
        exit(1); 
    }

    // 첫 번째 파일을 읽기 모드로 엶.
    if ((fd1 = open(argv[1], O_RDONLY)) == -1) {
        perror(argv[1]);
        exit(2); 
    }

    // 두 번째 파일을 쓰기 모드로 엶. 파일이 없으면 생성하고, 기존 내용은 삭제한다.
    if ((fd2 = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644)) == -1) {
        perror(argv[2]);
        close(fd1);  // fd1 파일을 닫습니다.
        exit(3); 
    }

    // 첫 번째 파일에서 읽고, 두 번째 파일에 씁니다.
    while ((n = read(fd1, buf, BUFSIZ)) > 0) {
        if (write(fd2, buf, n) != n) {
            perror("write");
            close(fd1);  // fd1 파일을 닫습니다.
            close(fd2);  // fd2 파일을 닫습니다.
            exit(4);
        }
    }

    // 읽기 오류가 발생한 경우 처리합니다.
    if (n == -1) {
        perror("read");
    }

    // 파일을 닫습니다.
    close(fd1);
    close(fd2);
    
    return 0;
}
