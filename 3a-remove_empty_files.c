// 3a. Write a C program to remove empty files from the given directory.

#include <dirent.h>
#include <sys/stat.h>
#include <stdio.h>
#include <unistd.h>

int main() {
    DIR *d = opendir(".");
    struct dirent *e;
    struct stat s;
    while ((e = readdir(d))) {
        if (!stat(e->d_name, &s) && S_ISREG(s.st_mode) && s.st_size == 0) {
            printf("Deleting: %s\n", e->d_name);
            remove(e->d_name);
        }
    }
    closedir(d);
}
