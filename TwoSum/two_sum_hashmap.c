// Two Sum hashmap C implementation
#include <stdlib.h>

typedef struct {
    int key;
    int value;
} HashItem;

int hash(int key, int size) {
    int h = key % size;
    if(h < 0) h += size;  // fix negatives
    return h;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int tableSize = numsSize * 2;
    HashItem *hashTable = calloc(tableSize, sizeof(HashItem));

    for(int i = 0; i < tableSize; i++)
        hashTable[i].key = 0x80000000; // mark empty slot (INT_MIN)

    for(int i = 0; i < numsSize; i++) {
        int comp = target - nums[i];

        // lookup complement
        int h = hash(comp, tableSize);
        while(hashTable[h].key != 0x80000000) {
            if(hashTable[h].key == comp) {
                int *result = malloc(2 * sizeof(int));
                result[0] = hashTable[h].value;
                result[1] = i;
                *returnSize = 2;
                free(hashTable);
                return result;
            }
            h = (h + 1) % tableSize;
        }

        // insert current number
        h = hash(nums[i], tableSize);
        while(hashTable[h].key != 0x80000000) h = (h + 1) % tableSize;
        hashTable[h].key = nums[i];
        hashTable[h].value = i;
    }

    *returnSize = 0;
    free(hashTable);
    return NULL;
}
