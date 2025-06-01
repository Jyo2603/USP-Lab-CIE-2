// 3b. Write a C program to implement ls –li command which lists the
// files in a specified directory. Your program should Print 5 attributes
// of files.

#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>

int main() {
    DIR *d = opendir(".");
    struct dirent *e;
    struct stat s;
    char p[256];

    printf("Inode      Links UID   Size       Name\n");
    while ((e = readdir(d))) {
        sprintf(p, "%s", e->d_name);
        if (!stat(p, &s))
            printf("%-10lu %-5lu %-5u %-10ld %s\n",
                   s.st_ino, s.st_nlink, s.st_uid, s.st_size, e->d_name);
    }
    closedir(d);
}
