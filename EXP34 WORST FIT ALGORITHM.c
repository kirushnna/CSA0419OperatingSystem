#include <stdio.h>

#define MAX_BLOCKS 100
#define MAX_PROCESSES 100

void worstFit(int blocks[], int m, int processes[], int n) {
    int allocation[MAX_PROCESSES];
    int i, j;

    for (i = 0; i < n; i++) {
        int worstFitIndex = -1;
        for (j = 0; j < m; j++) {
            if (blocks[j] >= processes[i]) {
                if (worstFitIndex == -1 || blocks[j] > blocks[worstFitIndex]) {
                    worstFitIndex = j;
                }
            }
        }

        if (worstFitIndex != -1) {
            allocation[i] = worstFitIndex;
            blocks[worstFitIndex] -= processes[i];
        }
    }

    printf("\nProcess No.\tProcess Size\tBlock no.\n");
    for (i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t", i + 1, processes[i]);
        if (allocation[i] != -1) {
            printf("%d\n", allocation[i] + 1);
        } else {
            printf("Not Allocated\n");
        }
    }
}

int main() {
    int blocks[MAX_BLOCKS], processes[MAX_PROCESSES];
    int m, n, i;

    printf("Enter the number of memory blocks: ");
    scanf("%d", &m);
    printf("Enter the size of each memory block:\n");
    for (i = 0; i < m; i++) {
        scanf("%d", &blocks[i]);
    }

    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter the size of each process:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &processes[i]);
    }

    worstFit(blocks, m, processes, n);

    return 0;
}

