#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    time_t current_time;
    struct tm *timeinfo;
    char time_string[80];

    time(&current_time);
    timeinfo = localtime(&current_time);

    strftime(time_string, sizeof(time_string), "%a, %d %b %Y %H:%M:%S %z", timeinfo);

    printf("%s\n", time_string);

    return 0;
}

