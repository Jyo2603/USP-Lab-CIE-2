// 1a. Write a C program to display the file content in reverse order using lseek
// system call.

#include <fcntl.h>
#include <unistd.h>
int main() {
    int fd = open("test.txt", O_RDONLY);
    off_t pos = lseek(fd, 0, 2);
    char c;
    while (--pos >= 0) {
        lseek(fd, pos, 0);
        read(fd, &c, 1);
        write(1, &c, 1);
    }
    return 0;
}
