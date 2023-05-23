// Binary search on an array

func binarySearch(arr[], low, high, target) {
    if (low <= high) {
        mid = low + (high - low) / 2;

        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            return binarySearch(arr, mid + 1, high, target);
        } else {
            return binarySearch(arr, low, mid - 1, target);
        }
    }

    return -1;
}

array nums[10];
nums[0] = 2;
nums[1] = 5;
nums[2] = 8;
nums[3] = 12;
nums[4] = 18;
nums[5] = 23;
nums[6] = 30;
nums[7] = 32;
nums[8] = 40;
nums[9] = 55;

size = 10;
target = 23;

result = binarySearch(nums, 0, size - 1, target);

if (result != -1) {
    puti_(target);
    puts_(" found at index ");
    puti(result);
} else {
    puts("Element not found");
}

// expect "23 found at index 5"
