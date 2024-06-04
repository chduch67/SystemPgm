#include <stdio.h>

int main(int argc, char *argv[]) {
    // 인수가 없는 경우 빈 줄을 출력하고 종료.
    if (argc < 2) {
        printf("\n");
        return 0;
    }

    // 첫 번째 인수부터 마지막 인수까지 출력.
    for (int i = 1; i < argc; i++) {
        printf("%s", argv[i]);
        if (i < argc - 1) {
            printf(" ");
        }
    }
    printf("\n");

    return 0;
}
