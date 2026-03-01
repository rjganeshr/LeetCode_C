# Two Sum

## Problem
Given an array of integers `nums` and an integer `target`, return the indices of the two numbers such that they add up to the target.

You may assume that each input would have **exactly one solution**, and you may not use the same element twice.  

**Example Input/Output**

```c
Input: nums = [2, 7, 11, 15], target = 9
Output: [0, 1]

Input: nums = [4, 4, 5], target = 8
Output: [0, 1]

## Methods Explanation

### 1️⃣ Brute Force
- **Idea:** Check every possible pair of numbers in the array to see if they sum up to the target.  
- **Step-by-Step:**
  1. Loop through each element `nums[i]`.
  2. For each `i`, loop through all elements after it `nums[j]`.
  3. Check if `nums[i] + nums[j] == target`.
  4. If yes, return the indices `[i, j]`.
- **Pros:** Simple and easy to implement.  
- **Cons:** Inefficient for large arrays (O(n²)).

---

### 2️⃣ Hash Map
- **Idea:** Use a hash map (dictionary) to remember numbers we've seen so far, so we can check in O(1) if the complement exists.  
- **Step-by-Step:**
  1. Create an empty hash map.
  2. Loop through the array with index `i` and value `num`.
  3. Compute the complement: `complement = target - num`.
  4. Check if `complement` is in the hash map:
     - If yes → return `[hash_map[complement], i]`.
     - If no → add `num` to hash map with `i` as its value.
- **Pros:** Fast (O(n)) and scalable.  
- **Cons:** Uses extra memory (O(n)).
