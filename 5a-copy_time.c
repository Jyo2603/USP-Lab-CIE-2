// 5a. Write a program to copy access and modification time of a file to
// another file using utime function.

#include <stdio.h>
#include <utime.h>
#include <sys/stat.h>

int main() {
    struct stat s;
    struct utimbuf t;

    stat("source.txt", &s);
    t.actime = s.st_atime;
    t.modtime = s.st_mtime;
    utime("dest.txt", &t);

    printf("Time copied.\n");
    return 0;
}
