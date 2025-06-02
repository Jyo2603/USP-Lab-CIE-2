// 4a. Write a C program to demonstrate the creation of soft links and
// hard links.

#include <stdio.h>
#include <unistd.h>

int main() {

    link("test.txt", "hardlink.txt");
    printf("Hard link created successfully.\n");

    symlink("test.txt", "softlink.txt");
    printf("Soft link created successfully.\n");

    return 0;
}
