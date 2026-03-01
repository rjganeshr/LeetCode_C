// Two Sum Brute Force C implementation
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    
    int i, j;

    for(i = 0; i < numsSize - 1; i++)
    {
        for(j = i + 1; j < numsSize; j++)
        {
            if(nums[i] + nums[j] == target)
            {
                int *result = malloc(2 * sizeof(int)); 

                result[0] = i; 
                result[1] = j;

                *returnSize = 2;

                return result;
            }
        }
    }

    *returnSize = 0;
    return NULL;
}
