func fact(n) {
    if (n == 0) return 1;
    else return n * fact(n-1);
}

puti(fact(10)); // expect 3628800
