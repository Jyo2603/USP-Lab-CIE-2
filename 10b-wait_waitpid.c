// 10b. b) Demonstrate the working of wait and waitpid system calls with a
// program

#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

int main() {
    int s;
    if (fork() == 0) return 1;  // Child 1
    pid_t c2 = fork();
    if (c2 == 0) return 2;      // Child 2

    wait(&s);
    printf("Child 1 exited with: %d\n", WEXITSTATUS(s));
    waitpid(c2, &s, 0);
    printf("Child 2 exited with : %d\n", WEXITSTATUS(s));
}
