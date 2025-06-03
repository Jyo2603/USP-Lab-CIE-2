// 8a. a) Write a C program that takes the file name as an argument and prints
// the type of the given file.

#include <stdio.h>
#include <sys/stat.h>

int main(int argc, char *argv[])      
{
    struct stat st;
    lstat(argv[1], &st);		

    if (S_ISREG(st.st_mode)) printf("Regular file\n");
    else if (S_ISDIR(st.st_mode)) printf("Directory\n");
    else if (S_ISLNK(st.st_mode)) printf("Symbolic link\n");
    else if (S_ISCHR(st.st_mode)) printf("Character device\n");
    else if (S_ISBLK(st.st_mode)) printf("Block device\n");
    else if (S_ISFIFO(st.st_mode)) printf("FIFO (named pipe)\n");
    else if (S_ISSOCK(st.st_mode)) printf("Socket\n");
    else printf("Unknown file type\n");

    return 0;
}

# 1. Regular File
echo "Hello" > regular.txt
./filetype regular.txt

# 2. Directory
mkdir mydir
./filetype mydir

# 3. Symbolic Link
ln -s regular.txt symlink
./filetype symlink

# 4. Character Device (use /dev/null as example)
./filetype /dev/null

# 5. Block Device (use existing like /dev/sda or /dev/disk0)
./filetype /dev/sda        # OR try: ./filetype /dev/disk0

# 6. FIFO (Named Pipe)
mkfifo myfifo
./filetype myfifo

# 7. Socket (UNIX domain)
python3 -c "import socket as s; sock=s.socket(s.AF_UNIX); sock.bind('mysock')"
./filetype mysock
