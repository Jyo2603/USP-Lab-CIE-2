// ✅ main.c 

#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>

int main() {
    pid_t pid = fork();
    if (pid == 0)
        execl("./p1", "p1", "example.txt", NULL);
    else {
        wait(NULL);
        printf("Child PID: %d\n", pid);
    }
}

// ✅ p1.c 

#include <unistd.h>
#include <stdio.h>

int main(int c, char *v[]) {
    access(v[1], F_OK) == 0 ?
        printf("Exists: %s\n", v[1]) :
        printf("Not found: %s\n", v[1]);
}
// 🧪 How to Compile and Run
// echo "hi" > example.txt
// gcc p1.c -o p1
// gcc main.c -o main
// ./main 
