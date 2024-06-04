#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    time_t current_time;          // 현재 시간을 저장할 변수
    struct tm *timeinfo;          // 시간 정보를 저장할 구조체 포인터
    char time_string[80];         // 포맷된 시간 문자열을 저장할 배열

    time(&current_time);          // 현재 시간을 가져와 current_time에 저장
    timeinfo = localtime(&current_time);  // current_time을 현지 시간대로 변환하여 timeinfo에 저장

    // timeinfo 구조체를 이용해 포맷된 시간 문자열을 생성
    strftime(time_string, sizeof(time_string), "%Y-%m-%d %H:%M:%S", timeinfo);

    printf("%s\n", time_string);  // 포맷된 시간 문자열을 출력

    return 0;
}
