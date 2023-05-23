#include <stdio.h>
#include <stdbool.h>
bool isPageExists(int page, int frame[], int frameSize) 
{
	int i;
    for (i = 0; i < frameSize; i++) 
	{
        if (frame[i] == page) 
		{
            return true;
        }
    }
    return false;
}
int findOptimalPage(int pages[], int pageIndices[], int currentIndex, int numPages, int frame[], int frameSize) 
{
    int optimalIndex = -1;
    int farthestIndex = currentIndex;
    int i;
    for (i = 0; i < frameSize; i++) 
	{
        int j;
        for (j = currentIndex + 1; j < numPages; j++) 
		{
            if (frame[i] == pages[j]) 
			{
                if (j > farthestIndex) 
				{
                    farthestIndex = j;
                    optimalIndex = i;
                }
                break;
            }
        }
        if (j == numPages) 
		{
            return i;
        }
    }
    return (optimalIndex == -1) ? 0 : optimalIndex;
}
int optimalPageReplacement(int pages[],int NULL, int numPages, int frameSize)
 {
    int frame[frameSize];
    int pageFaults = 0;
    int i;
    for (i = 0; i < frameSize; i++) 
	{
        frame[i] = -1; 
    }

    for (i = 0; i < numPages; i++) 
	{
        if (!isPageExists(pages[i], frame, frameSize)) 
		{
            int replaceIndex = findOptimalPage(pages, NULL, i, numPages, frame, frameSize);
            frame[replaceIndex] = pages[i];
            pageFaults++;
        }
    }

    return pageFaults;
}

int main() {
    int pages[] = {4,1,2,4,3,2,1,5}; 
    int numPages = sizeof(pages) / sizeof(pages[0]);
    int frameSize = 3;
    int NULL;
    int pageFaults = optimalPageReplacement(pages,NULL, numPages, frameSize);

    printf("Number of Page Faults: %d\n", pageFaults);

    return 0;
}

