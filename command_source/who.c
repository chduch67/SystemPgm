#include <stdio.h>
#include <utmp.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>


int main() {
    struct utmp ut; // utmp 구조체 변수
    int utmp_fd; // utmp 파일 디스크립터

    // utmp 파일을 읽기 전용으로 연다.
    if ((utmp_fd = open("/var/run/utmp", O_RDONLY)) == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    // utmp 파일을 읽어서 사용자 정보를 출력.
    while (read(utmp_fd, &ut, sizeof(struct utmp)) == sizeof(struct utmp)) {
        if (ut.ut_type == USER_PROCESS) { // 유저 프로세스 정보인 경우에만 출력.
            // 사용자 이름, 터미널 이름, 호스트 이름, 로그인 시간을 출력.
            printf("%-8s\t%-8s\t%-8s\t%s", ut.ut_user, ut.ut_line, ut.ut_host, ctime(&ut.ut_tv.tv_sec));
        }
    }

    
    close(utmp_fd);

    return 0; 
}
