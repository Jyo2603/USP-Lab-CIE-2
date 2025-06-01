1b. Write a C program to create a child process and show how parent
and child processes will share the text file and justify that both
parent and child share the same file offset.

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int file = open("test.txt", O_RDONLY);
    char buf[20];

    if (fork() == 0) {
        read(file, buf, 5);
        buf[5] = '\0';
        printf("Child read: %s\n", buf);
    } else {
        wait(NULL);
        read(file, buf, 5);
        buf[5] = '\0';
        printf("Parent read: %s\n", buf);
    }
    return 0;
}
