// 7b. b) C program to simulate copy command by accepting the filenames
// from the command line. Report all errors.

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main(int c, char *v[]) {
    if (c < 3) return write(2, "Usage: cp src dest\n", 19), 1;

    int s = open(v[1], O_RDONLY);
    if (s < 0) return perror("src"), 1;

    int d = open(v[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (d < 0) return perror("dest"), close(s), 1;

    char b[1024]; ssize_t n;
    while ((n = read(s, b, 1024)) > 0) write(d, b, n);

    close(s); close(d);
    write(1, "Copied!\n", 8);
    return 0;
}
