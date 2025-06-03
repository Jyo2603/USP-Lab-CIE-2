// 7a. Write a C program to illustrate the effect of setjmp and longjmp
// functions on register and volatile variables.

#include <stdio.h>
#include <setjmp.h>

jmp_buf jb;
int gv = 1;

int main() {
    int av = 2;
    register int rv = 3;
    volatile int vv = 4;
    static int sv = 5;

    if (setjmp(jb)) {
        printf("\nAfter longjmp:\n");
    } else {
        gv = av = rv = vv = sv = 9;
        printf("Before longjmp:\n");
        longjmp(jb, 1);
    }

    printf("gv=%d av=%d rv=%d vv=%d sv=%d\n", gv, av, rv, vv, sv);
    return 0;
}
