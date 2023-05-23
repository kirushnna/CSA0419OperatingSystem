#include <stdio.h>
#include <stdlib.h>

// Function to calculate the absolute difference between two numbers
int abs_diff(int a, int b) {
    return abs(a - b);
}

// Function to perform SCAN disk scheduling
void scan(int tracks[], int n, int head, int direction) {
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
    if (direction == 1) {
        for (i = index; i < n; i++) {
            printf("%d ", tracks[i]);
            total_head_movement += abs_diff(current_track, tracks[i]);
            current_track = tracks[i];
        }

        // Reverse the direction and scan in the reverse direction
        direction = -1;
        printf("%d ", tracks[n - 1]);
        total_head_movement += abs_diff(current_track, tracks[n - 1]);
        current_track = tracks[n - 1];
        for (i = n - 2; i >= 0; i--) {
            printf("%d ", tracks[i]);
            total_head_movement += abs_diff(current_track, tracks[i]);
            current_track = tracks[i];
        }
    }
    // Scan in the reverse direction
    else if (direction == -1) {
        for (i = index - 1; i >= 0; i--) {
            printf("%d ", tracks[i]);
            total_head_movement += abs_diff(current_track, tracks[i]);
            current_track = tracks[i];
        }

        // Reverse the direction and scan in the forward direction
        direction = 1;
        printf("%d ", tracks[0]);
        total_head_movement += abs_diff(current_track, tracks[0]);
        current_track = tracks[0];
        for (i = 1; i < n; i++) {
            printf("%d ", tracks[i]);
            total_head_movement += abs_diff(current_track, tracks[i]);
            current_track = tracks[i];
        }
    }

    printf("\nTotal head movement: %d\n", total_head_movement);
    printf("Average head movement: %.2f\n", (float)total_head_movement / n);
}

int main() {
    int tracks[] = {55, 58, 60, 70, 18, 90, 150, 160, 184};
    int n = sizeof(tracks) / sizeof(tracks[0]);
    int head = 50;  // Starting head position
    int direction = 1;  // 1 for forward direction, -1 for reverse direction

    printf("Track positions: ");
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", tracks[i]);
    }
    printf("\n");

    scan(tracks, n, head, direction);

    return 0;
}

