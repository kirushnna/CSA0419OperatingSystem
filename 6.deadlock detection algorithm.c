#include <stdio.h>

#define N 3		// number of processes
#define M 3		// number of resource types

int main()
{
    int max[N][M] = {{3, 6, 8}, {4, 3, 3}, {3, 4, 4}};		// maximum demand of each process
    int allocation[N][M] = {{3, 3, 3}, {2, 0, 3}, {1, 2, 4}};	// resources allocated to each process
    int available[M] = {1, 2, 0};				// number of available resources
	int i,j,k;
    int need[N][M];			// need[i][j] = max[i][j] - allocation[i][j]
    int finish[N] = {0};		// finish[i] = 1 if process i is finished
    int work[M];			// work[j] = number of available resources of type j
    int safeSeq[N];			// stores the safe sequence of processes

    // initialize need[][] and work[][]
    for ( i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }
    for ( j = 0; j < M; j++) {
        work[j] = available[j];
    }

    // find a safe sequence
    int count = 0;	// number of processes in the safe sequence
    while (count < N) {
        int found = 0;	// flag to indicate if a process can be added to the safe sequence
        for (i = 0; i < N; i++) {
            if (!finish[i]) {	// if process i is not finished
            
                for (j = 0; j < M; j++) {
                    if (need[i][j] > work[j]) {	// if process i needs more resources than available
                        break;	// process i cannot be added to the safe sequence
                    }
                }
                if (j == M) {	// if all resource needs of process i can be satisfied
                    for ( k = 0; k < M; k++) {
                        work[k] += allocation[i][k];	// release resources allocated to process i
                    }
                    finish[i] = 1;		// mark process i as finished
                    safeSeq[count] = i;	// add process i to the safe sequence
                    count++;
                    found = 1;	// process i can be added to the safe sequence
                }
            }
        }
        if (!found) {	// if no process can be added to the safe sequence
            printf("Deadlock detected.\n");
            return 0;
        }
    }

    // print the safe sequence
    printf("Safe sequence: ");
    for (i = 0; i < N; i++) {
        printf("%d ", safeSeq[i]);
    }
    printf("\n");

    return 0;
}
