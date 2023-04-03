#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid;

    pid = fork();

    if (pid == -1) {
        printf("Failed to fork\n");
        exit(1);
    } else if (pid == 0) {
        // Child process
        char *args[] = {"/bin/ls", "-l", NULL};
        execv(args[0], args);
    } else {
        // Parent process
        wait(NULL);
        printf("Child process finished\n");
    }

    return 0;
}