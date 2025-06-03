// 5b.Write a C program using sigaction system call which calls a signal
// handler on SIGINT signal and then reset the default action of the
// SIGINT signal.

#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void handler(int s) {
    printf("\nCaught SIGINT\n");
    signal(SIGINT, SIG_DFL);
}

int main() {
    signal(SIGINT, handler);
    while (1) {
        printf("Press Ctrl+C to trigger. \n");
        pause();
    }
}
