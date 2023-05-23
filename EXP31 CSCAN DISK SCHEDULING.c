#include <stdio.h>
#include <stdlib.h>

// Function to calculate the absolute difference between two numbers
int abs_diff(int a, int b) {
    return abs(a - b);
}

// Function to perform CSCAN disk scheduling
void cscan(int tracks[], int n, int head, int direction) {
    int total_head_movement = 0;
    int current_track = head;
    int i, j;

    // Sort the tracks in ascending order
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (tracks[j] > tracks[j + 1]) {
                int temp = tracks[j];
                tracks[j] = tracks[j + 1];
                tracks[j + 1] = temp;
            }
        }
    }

    // Find the index of the head position in the sorted tracks
    int index = 0;
    for (i = 0; i < n; i++) {
        if (tracks[i] >= head) {
            index = i;
            break;
        }
    }

    // Scan in the forward direction
    for (i = index; i < n; i++) {
        printf("%d ", tracks[i]);
        total_head_movement += abs_diff(current_track, tracks[i]);
        current_track = tracks[i];
}
    if (direction == -1) {
        printf("%d ", tracks[n - 1]);
        total_head_movement += abs_diff(current_track, tracks[n - 1]);
        current_track = tracks[n - 1];
        for (i = n - 2; i >= 0; i--) {
            printf("%d ", tracks[i]);
            total_head_movement += abs_diff(current_track, tracks[i]);
            current_track = tracks[i];
        }
    }

    printf("\nTotal head movement: %d\n", total_head_movement);
    printf("Average head movement: %.2f\n", (float)total_head_movement / n);
}

int main() {
    int tracks[] = {55, 58, 60, 70, 18};
    int n = sizeof(tracks) / sizeof(tracks[0]);
    int head = 50;  
    int direction = 1;  

    printf("Track positions: ");
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", tracks[i]);
    }
    printf("\n");

    cscan(tracks, n, head, direction);

    return 0;
}

