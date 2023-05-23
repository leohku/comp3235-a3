func fact(n) {
    if (n == 0) return 1;
    else return n * fact(n-1);
}

puti(fact(10)); // expect 3628800

func sumarr(arr[], length) {
    sum = 0;
    for (i = 0; i < length; i = i+1;) {
        sum = sum + arr[i];
    };
    return sum;
};

array x[10] = 10;
puti(sumarr(x, 10));
