Q.1) Write a C program that prints the exit status of a terminated child process

#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();

    if (pid == 0) {
        exit(5); 
    } else {
        int status;
        wait(&status);
        if (WIFEXITED(status)) {
            printf("Child exited with status: %d\n", WEXITSTATUS(status));
        }
    }
    return 0;
}

Output:
Child exited with status: 5