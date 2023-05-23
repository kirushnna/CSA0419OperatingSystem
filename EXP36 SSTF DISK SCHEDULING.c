#include <stdio.h>
#include <stdlib.h>

int abs(int a) {
    return (a > 0) ? a : -a;
}

int findClosest(int tracks[], int n, int head) {
    int min = abs(tracks[0] - head);
    int index = 0;
    int i;
    
    for (i = 1; i < n; i++) {
        int diff = abs(tracks[i] - head);
        
        if (diff < min) {
            min = diff;
            index = i;
        }
    }
    
    return index;
}

void sstf(int tracks[], int n, int head) {
    int totalMovement = 0;
    int visited[n];
    int i;
    
    for (i = 0; i < n; i++)
        visited[i] = 0;
    
    printf("SSTF Disk Scheduling Order: ");

        for (i = 0; i < n; i++) {
        int closest = findClosest(tracks, n, head);
        visited[closest] = 1;
        printf("%d ", tracks[closest]);
        totalMovement += abs(tracks[closest] - head);
        head = tracks[closest];
    }
    
    printf("\nAverage Head Movement: %.2f\n", (float)totalMovement / n);
}

int main() {
    int tracks[] = {55, 58, 60, 70, 18};
    int n = sizeof(tracks) / sizeof(tracks[0]);
    int head = 50; // Starting head position
    
    printf("Initial Head Position: %d\n", head);
    
    sstf(tracks, n, head);
    
    return 0;
}

