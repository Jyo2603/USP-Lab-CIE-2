//4.b) Write a C program to
//i. To create a child process.
//ii. The child should execute an interpreter file by passing a few arguments
//iii. Create an interpreter file that has the path of echoall.c file and pass one argument
//iv. Create echoall.c file which prints the arguments received from both child process and
//interpreter file.

//📄 1. echoall.c — Prints all arguments
#include <stdio.h>

int main(int argc, char *argv[]) {
    for (int i = 0; i < argc; i++)
        printf("arg[%d] = %s\n", i, argv[i]);
    return 0;
}

//🛠️ Compile:
//gcc echoall.c -o echoall

//📄 2. interpreter.sh — Calls echoall with one argument

#!/bin/bash
./echoall interpreter_arg

//🛠️ Make executable:
//chmod +x interpreter.sh
//📄 3. main.c — Child executes interpreter and passes extra argument

#include <unistd.h>

int main() {
    if (!fork()) execl("./interpreter.sh", "interpreter.sh", "child_arg", NULL);
    return 0;
}

//🛠️ Compile:
//gcc main.c -o main
//▶️ Run the full setup:
//./main
//📌 Expected Output:
//arg[0] = ./echoall
//arg[1] = interpreter_arg
//arg[2] = child_arg
