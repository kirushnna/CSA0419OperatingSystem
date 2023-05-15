#include <stdio.h>

#define FILE_SIZE 100

// Function to calculate disk I/O operations for contiguous allocation
int calculateContiguousIO() {
    int block_size = 1;
    int num_blocks = FILE_SIZE;

    // Reading the entire file requires reading each block
    int total_io_operations = num_blocks;

    return total_io_operations;
}

// Function to calculate disk I/O operations for linked allocation
int calculateLinkedIO() {
    int block_size = 1;
    int num_blocks = FILE_SIZE;

    // Each block contains a pointer to the next block
    // Reading the entire file requires reading each block and following the pointers
    int total_io_operations = num_blocks + num_blocks;

    return total_io_operations;
}

// Function to calculate disk I/O operations for indexed (single-level) allocation
int calculateIndexedIO() {
    int block_size = 1;
    int num_blocks = FILE_SIZE;
    int index_block_size = num_blocks * block_size; // Assuming one index block can hold all block pointers

    // Reading the entire file requires reading the index block and each block
    int total_io_operations = 1 + num_blocks;

    return total_io_operations;
}

int main() {
    int contiguous_io = calculateContiguousIO();
    int linked_io = calculateLinkedIO();
    int indexed_io = calculateIndexedIO();

    printf("Contiguous Allocation: %d disk I/O operations\n", contiguous_io);
    printf("Linked Allocation: %d disk I/O operations\n", linked_io);
    printf("Indexed Allocation: %d disk I/O operations\n", indexed_io);

    return 0;
}

