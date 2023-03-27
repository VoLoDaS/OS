#include <stdio.h> 
#include <unistd.h>

int main() {
    printf("Текущий ID: %d\n", getpid());
    printf("ID родительского процесса: %d\n", getppid()); 
    return 0; 
}