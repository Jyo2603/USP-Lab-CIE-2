// 2a. Write a C program to display various details of a file using stat
// structure (At least 5 fields).

#include <sys/stat.h>
#include <stdio.h>
#include <time.h>

int main() {
    struct stat s;
    stat("shared.txt", &s);
    printf("Size: %ld\n", s.st_size);
    printf("Mode: %o\n", s.st_mode & 0777);
    printf("Links: %lu\n", s.st_nlink);
    printf("UID: %d\n", s.st_uid);
    printf("Mod: %s", ctime(&s.st_mtime));
}
