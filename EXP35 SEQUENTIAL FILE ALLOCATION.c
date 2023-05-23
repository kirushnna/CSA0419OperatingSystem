#include <stdio.h>
#include <stdbool.h>

#define TOTAL_BLOCKS 16
#define INODE_BLOCKS 8
#define AVAILABLE_BLOCKS (TOTAL_BLOCKS - INODE_BLOCKS)
#define BLOCK_SIZE 1024

bool isBlockAvailable(bool allocation[], int startBlock, int size) {
	int i;
    for (i = startBlock; i < startBlock + size; i++) {
        if (allocation[i]) {
            return false;
        }
    }
    return true;
}

void allocateBlocks(bool allocation[], int startBlock, int size) {
	int i;
    for (i = startBlock; i < startBlock + size; i++) {
        allocation[i] = true;
    }
}

void deallocateBlocks(bool allocation[], int startBlock, int size) {
	int i;
    for (i = startBlock; i < startBlock + size; i++) {
        allocation[i] = false;
    }
}

void displayFileSystem(bool allocation[]) {
    printf("File System Allocation:\n");
    printf("-----------------------\n");
    printf("Block\tStatus\n");
    int i;
    for (i = 0; i < TOTAL_BLOCKS; i++) {
        printf("%d\t%s\n", i, allocation[i] ? "Allocated" : "Free");
    }
}

int main() {
    bool allocation[TOTAL_BLOCKS] = {false}; // Initialize all blocks as free
    int fileSize, startBlock, numBlocks;

    while (1) {
        displayFileSystem(allocation);

        printf("\nEnter file size in KB (Enter 0 to exit): ");
        scanf("%d", &fileSize);

        if (fileSize == 0) {
            break;
        }

        if (fileSize < 1 || fileSize > AVAILABLE_BLOCKS) {
            printf("Invalid file size! Minimum file size is 1 KB and maximum file size is %d KB.\n",
                   AVAILABLE_BLOCKS);
            continue;
        }

        printf("Enter the starting block for the file: ");
        scanf("%d", &startBlock);

        if (startBlock < 0 || startBlock >= AVAILABLE_BLOCKS) {
            printf("Invalid starting block! Available blocks for allocation are from 8 to %d.\n",
                   TOTAL_BLOCKS - 1);
            continue;
        }

        if (!isBlockAvailable(allocation, startBlock, fileSize)) {
            printf("Blocks are not available from the starting block. Trying to find the next available contiguous blocks...\n");

            bool found = false;
            int i;
            for (i = startBlock + 1; i <= AVAILABLE_BLOCKS - fileSize; i++) {
                if (isBlockAvailable(allocation, i, fileSize)) {
                    startBlock = i;
                    found = true;
                    break;
                }
            }

            if (!found) {
                printf("No contiguous blocks of size %d KB are available.\n", fileSize);
                continue;
            }
        }

        allocateBlocks(allocation, startBlock, fileSize);
        printf("File allocated successfully from block %d to block %d.\n", startBlock, startBlock + fileSize - 1);
    }

    printf("\nExiting the program.\n");

    return 0;
}

