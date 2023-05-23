func merge(arr[], start, mid, end) {
    n1 = mid - start + 1;
    n2 = end - mid;

    array left[50];
    array right[50];

    for (i = 0; i < n1; i = i + 1;) {
        left[i] = arr[start + i];
    }

    for (j = 0; j < n2; j = j + 1;) {
        right[j] = arr[mid + 1 + j];
    }

    i = 0;
    j = 0;
    k = start;

    while (i < n1 && j < n2) {
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            i = i + 1;
        } else {
            arr[k] = right[j];
            j = j + 1;
        }
        k = k + 1;
    }

    while (i < n1) {
        arr[k] = left[i];
        i = i + 1;
        k = k + 1;
    }

    while (j < n2) {
        arr[k] = right[j];
        j = j + 1;
        k = k + 1;
    }
}

func mergeSort(arr[], start, end) {
    if (start < end) {
        mid = start + (end - start) / 2;

        mergeSort(arr, start, mid);
        mergeSort(arr, mid + 1, end);

        merge(arr, start, mid, end);
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

mergeSort(nums, 0, size - 1);

for (i = 0; i < size; i = i + 1;) {
    puti(nums[i]);
}

// expect 1,2,3,4,5,6,7,8
