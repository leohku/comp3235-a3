// Sorting an array using quick sort.
// This demonstrates functions, and array as parameters in recursive settings.

func partition(arr[], low, high) {
    pivot = arr[high];
    i = low - 1;

    for (j = low; j < high; j = j + 1;) {
        if (arr[j] <= pivot) {
            i = i + 1;

            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1;
}

func quickSort(arr[], low, high) {
    if (low < high) {
        pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

array nums[8];
nums[0] = 7;
nums[1] = 2;
nums[2] = 1;
nums[3] = 6;
nums[4] = 8;
nums[5] = 5;
nums[6] = 3;
nums[7] = 4;

size = 8;

quickSort(nums, 0, size - 1);

for (i = 0; i < size; i = i + 1;) {
    puti_(nums[i]);
    putc_(' ');
}

// expect 1,2,3,4,5,6,7,8
