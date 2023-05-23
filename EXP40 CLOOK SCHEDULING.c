#include <stdio.h>
#include <stdlib.h>
void sort(int tracks[], int numTracks) 
{
	int i;
    for (i = 0; i < numTracks - 1; i++) 
	{
    	int j;
        for (j = 0; j < numTracks - i - 1; j++) 
		{
            if (tracks[j] > tracks[j + 1]) 
			{
                int temp = tracks[j];
                tracks[j] = tracks[j + 1];
                tracks[j + 1] = temp;
            }
        }
    }
}
int findClosestTrack(int tracks[], int numTracks, int currentHead) 
{
    int minDiff = abs(currentHead - tracks[0]);
    int closestIndex = 0;
    int i;
    for (i = 1; i < numTracks; i++) 
	{
        int diff = abs(currentHead - tracks[i]);
        if (diff < minDiff) 
		{
            minDiff = diff;
            closestIndex = i;
        }
    }

    return closestIndex;
}
int CLOOK(int tracks[], int numTracks, int currentHead) 
{
    sort(tracks, numTracks);

    int totalHeadMovement = 0;
    int currentIndex = findClosestTrack(tracks, numTracks, currentHead);
    int i;
    for (i = currentIndex; i < numTracks; i++) 
	{
        totalHeadMovement += abs(currentHead - tracks[i]);
        currentHead = tracks[i];
    }
    totalHeadMovement += abs(currentHead - tracks[0]);
    currentHead = tracks[0];
    for (i = 1; i < currentIndex; i++) 
	{
        totalHeadMovement += abs(currentHead - tracks[i]);
        currentHead = tracks[i];
    }

    return totalHeadMovement;
}

int main() 
{
    int tracks[] = {55, 58, 60, 70, 18};
    int numTracks = sizeof(tracks) / sizeof(tracks[0]);
    int currentHead = 50; 

    int headMovement = CLOOK(tracks, numTracks, currentHead);
    float avgHeadMovement = (float)headMovement / numTracks;

    printf("Average Head Movement in clook scheduling : %.2f\n", avgHeadMovement);

    return 0;
}

