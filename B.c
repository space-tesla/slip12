Q.2) Write a C program which receives file names as command line arguments and displays those filenames in ascending order according to their sizes

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

int compare(const void *a, const void *b) {
    struct stat statA, statB;
    stat(*(char **)a, &statA);
    stat(*(char **)b, &statB);
    return statA.st_size - statB.st_size;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <file1> <file2> ...\n", argv[0]);
        return 1;
    }

    qsort(argv + 1, argc - 1, sizeof(char *), compare);

    for (int i = 1; i < argc; i++) {
        struct stat fileStat;
        stat(argv[i], &fileStat);
        printf("%s: %ld bytes\n", argv[i], fileStat.st_size);
    }

    return 0;
}


Output:

a.txt: 120 bytes
b.txt: 200 bytes
c.txt: 350 bytes
