#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void sigint_handler(int sig) {
    printf("Caught signal %d. Terminating.\n", sig);
    exit(EXIT_SUCCESS);
}

int main() {
    int counter = 0;
    pid_t pid, sid;

    /* Create child process */
    pid = fork();
    if (pid < 0) {
        fprintf(stderr, "Failed to fork. Terminating.\n");
        exit(EXIT_FAILURE);
    }

    if (pid > 0) {
        printf("Daemon process started. PID: %d\n", pid);
        exit(EXIT_SUCCESS);
    }

    /* Close standard file descriptors */
    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    close(STDERR_FILENO);

    /* Create new session */
    sid = setsid();
    if (sid < 0) {
        fprintf(stderr, "Failed to create new session. Terminating.\n");
        exit(EXIT_FAILURE);
    }

    /* Change working directory */
    if (chdir("/") < 0) {
        fprintf(stderr, "Failed to change working directory. Terminating.\n");
        exit(EXIT_FAILURE);
    }

    /* Ignore some signals */
    signal(SIGCHLD, SIG_IGN);
    signal(SIGTSTP, SIG_IGN);
    signal(SIGTTOU, SIG_IGN);
    signal(SIGTTIN, SIG_IGN);

    /* Install signal handler */
    signal(SIGINT, sigint_handler);

    /* Main loop */
    while (1) {
        printf("Hello, world! Counter: %d\n", counter++);
        usleep(500000);
    }

    return 0;
}