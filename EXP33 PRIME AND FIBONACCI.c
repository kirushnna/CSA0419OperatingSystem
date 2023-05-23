#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>


int isPrime(int num) {
    if (num <= 1)
        return 0;
    int i;
    for (i = 2; i * i <= num; i++) {
        if (num % i == 0)
            return 0;
    }

    return 1;
}

void generateFibonacci(int n) {
    int first = 0, second = 1;

    printf("Fibonacci Series: ");
    printf("%d ", first);

    if (n > 1)
        printf("%d ", second);
    int i;
    for (i = 3; i <= n; i++) {
        int next = first + second;
        printf("%d ", next);
        first = second;
        second = next;
    }

    printf("\n");
}

int main() {
    pid_t pid;
    int status;

    pid = fork();

    if (pid < 0) {
        printf("Fork failed.\n");
        return 1;
    } else if (pid == 0) {
        // Child process
        generateFibonacci(10); // Generate Fibonacci series
    } else {
        // Parent process
        wait(&status); // Wait for the child process to finish

        printf("Prime Numbers: ");
        int i;
        for (i = 2; i <= 30; i++) {
            if (isPrime(i))
                printf("%d ", i);
        }
        printf("\n");
    }

    return 0;
}

