// 6a. Write a program to read n characters from a file and append them
// back to the same file using dup2 function.

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main() {
    int fd = open("file.txt", O_RDWR);
    char buf[50];
    int n = read(fd, buf, 50);
    lseek(fd, 0, SEEK_END);
    write(fd, buf, n); 

    dup2(fd, STDOUT_FILENO);     // Now printf or write to STDOUT goes to file.txt
    write(STDOUT_FILENO, buf, n);

    close(fd);
    return 0;
}
