// ✅ seek_read.c 

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>

int main() {
    int f = open("test.txt", O_RDONLY);
    char b[21];
    struct stat s;

    read(f, b, 20); b[20] = 0;
    printf("First 20: %s\n", b);

    lseek(f, 10, SEEK_SET);
    read(f, b, 20); b[20] = 0;
    printf("From 10 : %s\n", b);

    lseek(f, 10, SEEK_CUR);
    read(f, b, 20); b[20] = 0;
    printf("Next 10 : %s\n", b);

    fstat(f, &s);
    printf("Size    : %ld\n", s.st_size);

    close(f);
}

//🧪 How to Run:
//echo "ABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890abcdefghijklmnopqrstuvwxyz" > test.txt
//gcc seek_read.c -o seek_read
//./seek_read
