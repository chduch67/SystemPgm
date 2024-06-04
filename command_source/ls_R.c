#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void list_dir(const char *dir) {
    DIR *dp;
    struct dirent *d;
    struct stat st;
    char path[BUFSIZ+1];

    if ((dp = opendir(dir)) == NULL) {
        perror(dir);
        return;
    }

    while ((d = readdir(dp)) != NULL) {
        if (d->d_name[0] != '.') {
            printf("%s\n", d->d_name);
        }
    }

    rewinddir(dp);

    while ((d = readdir(dp)) != NULL) {
        if (d->d_name[0] == '.') continue;

        snprintf(path, BUFSIZ, "%s/%s", dir, d->d_name);
        if (stat(path, &st) == -1) {
            perror(path);
            continue;
        }

        if (S_ISDIR(st.st_mode) && strcmp(d->d_name, ".") != 0 && strcmp(d->d_name, "..") != 0) {
            printf("\n%s:\n", path);
            list_dir(path);
        }
    }

    closedir(dp);
}

int main(int argc, char **argv) {
    char *dir;

    if (argc == 1) {
        dir = ".";
    } else {
        dir = argv[1];
    }

    list_dir(dir);
    return 0;
}

