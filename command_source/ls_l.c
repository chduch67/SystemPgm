#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>

void print_file_info(const char *path, const struct stat *st) {
    printf("%c", S_ISDIR(st->st_mode) ? 'd' : '-');
    printf("%c", (st->st_mode & S_IRUSR) ? 'r' : '-');
    printf("%c", (st->st_mode & S_IWUSR) ? 'w' : '-');
    printf("%c", (st->st_mode & S_IXUSR) ? 'x' : '-');
    printf("%c", (st->st_mode & S_IRGRP) ? 'r' : '-');
    printf("%c", (st->st_mode & S_IWGRP) ? 'w' : '-');
    printf("%c", (st->st_mode & S_IXGRP) ? 'x' : '-');
    printf("%c", (st->st_mode & S_IROTH) ? 'r' : '-');
    printf("%c", (st->st_mode & S_IWOTH) ? 'w' : '-');
    printf("%c", (st->st_mode & S_IXOTH) ? 'x' : '-');
    printf(" %ld", st->st_nlink);
    printf(" %s", getpwuid(st->st_uid)->pw_name);
    printf(" %s", getgrgid(st->st_gid)->gr_name);
    printf(" %5ld", st->st_size);
    printf(" %.12s", 4 + ctime(&st->st_mtime));
    printf(" %s\n", path);
}

int main(int argc, char **argv) {
    DIR *dp;
    struct dirent *d;
    struct stat st;
    char path[BUFSIZ+1];
    char *dir;

    if (argc == 1) {
        dir = ".";
    } else {
        dir = argv[1];
    }

    if ((dp = opendir(dir)) == NULL) {
        perror(dir);
        exit(1);
    }

    while ((d = readdir(dp)) != NULL) {
        snprintf(path, BUFSIZ, "%s/%s", dir, d->d_name);
        if (stat(path, &st) == -1) {
            perror(path);
            continue;
        }
        if (d->d_name[0] != '.') {
            print_file_info(d->d_name, &st);
        }
    }

    closedir(dp);
    return 0;
}

