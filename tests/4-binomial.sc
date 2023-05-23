// Dynamic programming algorithm to find the binomial coefficient given (n,k)
// This demonstrates the '@' decorator, and multi-dimensional arrays.

array dp[20, 20];

func binomialCoefficient(n, k) {
    for (i = 0; i <= n; i = i + 1;) {
        for (j = 0; j <= i; j = j + 1;) {
            if (j == 0 || j == i) {
                @dp[i, j] = 1;
            } else {
                @dp[i, j] = @dp[i - 1, j - 1] + @dp[i - 1, j];
            }
        }
    }

    return @dp[n, k];
}

N = 10;
K = 5;

result = binomialCoefficient(N, K);

puti(result);

// expect 252
