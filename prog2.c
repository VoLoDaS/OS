#include <stdio.h> 
#include <unistd.h> 
#include <sys/types.h>

int main() {
    pid_t pid;
    printf("Текущий ID: %d\n", getpid());
    printf("ID родительского процесса: %d\n", getppid()); //вывод текущего и родительского ID
    pid = fork();
    if (pid == -1) {
        printf("Ошибка\n");
        return 1; //код ошибки
    } 
    else if (pid == 0) {
        printf("Новый текущий ID: %d\n", getpid());
        printf("Новый ID родительского процесса: %d\n", getppid());
    } 
    else {
        printf("Оригинальный текущий ID: %d\n", getpid());
        printf("Оригинальный ID родительского процесса: %d\n", getppid());
    }
    return 0;
} 