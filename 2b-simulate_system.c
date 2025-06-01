//2b. Write a C program to simulate system function.

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int my_sys(const char *cmd) {
    int s;
    if (!cmd) return -1;
    if (!fork()) execl("/bin/sh", "sh", "-c", cmd, NULL);
    wait(&s);
    return WIFEXITED(s) ? WEXITSTATUS(s) : -1;
}

int main() {
    printf("Exit: %d\n", my_sys("ls -li"));
}
