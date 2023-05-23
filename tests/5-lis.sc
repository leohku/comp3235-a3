// Dynamic programming algorithm to find the length of the longest increasing subsequence of 2 input arrays.
// This demonstrates the '@' decorator, and multi-dimensional arrays.

array dp[10, 10];

func LIS(arr1[], size1, arr2[], size2) {
    for (i = 0; i <= size1; i = i + 1;) {
        for (j = 0; j <= size2; j = j + 1;) {
            if (i == 0 || j == 0) {
                @dp[i, j] = 0;
            } else if (arr1[i - 1] == arr2[j - 1]) {
                @dp[i, j] = @dp[i - 1, j - 1] + 1;
            } else {
                @dp[i, j] = @dp[i - 1, j];
                if (@dp[i, j - 1] > @dp[i, j]) {
                    @dp[i, j] = @dp[i, j - 1];
                }
            }
        }
    }

    return @dp[size1, size2];
}

array array1[6];
array1[0] = 1;
array1[1] = 3;
array1[2] = 5;
array1[3] = 4;
array1[4] = 7;
array1[5] = 9;

array array2[5];
array2[0] = 1;
array2[1] = 2;
array2[2] = 4;
array2[3] = 6;
array2[4] = 8;

size1 = 6;
size2 = 5;

result = LIS(array1, size1, array2, size2);

puti(result);

// expect 2
