#include <stdio.h>

#define DISK_BLOCK_SIZE 8192  // 8 KB in bytes
#define POINTER_SIZE 4        // Size of a disk block pointer in bytes
#define NUM_DIRECT_BLOCKS 12
#define NUM_INDIRECT_BLOCKS 256
#define NUM_DOUBLE_INDIRECT_BLOCKS 65536
#define NUM_TRIPLE_INDIRECT_BLOCKS 16777216

int main() {
    int max_file_size = 0;

    // Calculate the maximum file size that can be stored in the direct blocks
    max_file_size += NUM_DIRECT_BLOCKS * DISK_BLOCK_SIZE;

    // Calculate the maximum file size that can be stored in the single indirect blocks
    int num_blocks_single_indirect = (DISK_BLOCK_SIZE / POINTER_SIZE);
    max_file_size += num_blocks_single_indirect * DISK_BLOCK_SIZE;
    max_file_size += num_blocks_single_indirect * DISK_BLOCK_SIZE * NUM_INDIRECT_BLOCKS;

    // Calculate the maximum file size that can be stored in the double indirect blocks
    int num_blocks_double_indirect = num_blocks_single_indirect * NUM_INDIRECT_BLOCKS;
    max_file_size += num_blocks_double_indirect * DISK_BLOCK_SIZE;
    max_file_size += num_blocks_double_indirect * DISK_BLOCK_SIZE * NUM_INDIRECT_BLOCKS;
    max_file_size += num_blocks_double_indirect * DISK_BLOCK_SIZE * NUM_INDIRECT_BLOCKS * NUM_INDIRECT_BLOCKS;

    // Calculate the maximum file size that can be stored in the triple indirect blocks
    int num_blocks_triple_indirect = num_blocks_single_indirect * NUM_INDIRECT_BLOCKS * NUM_INDIRECT_BLOCKS;
    max_file_size += num_blocks_triple_indirect * DISK_BLOCK_SIZE;
    max_file_size += num_blocks_triple_indirect * DISK_BLOCK_SIZE * NUM_INDIRECT_BLOCKS;
    max_file_size += num_blocks_triple_indirect * DISK_BLOCK_SIZE * NUM_INDIRECT_BLOCKS * NUM_INDIRECT_BLOCKS;
    max_file_size += num_blocks_triple_indirect * DISK_BLOCK_SIZE * NUM_INDIRECT_BLOCKS * NUM_INDIRECT_BLOCKS * NUM_INDIRECT_BLOCKS;

    printf("Maximum file size that can be stored in this file system: %d bytes\n", max_file_size);

    return 0;
}

