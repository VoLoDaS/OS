#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
int main() {
    pid_t pid;
    char *args[] = {"./executable", NULL};  // массив аргументов для нового процесса
    pid = fork();
    if (pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    else if (pid == 0) {
        printf("Child: PID=%ld, PPID=%ld\n", (long) getpid(), (long) getppid());
        if (execvp(args[0], args) == -1) { 
            perror("execvp");
            exit(EXIT_FAILURE);
        }
    }
    else {
        printf("Parent: PID=%ld, PPID=%ld\n", (long) getpid(), (long) getppid());
    }
    return 0;
}