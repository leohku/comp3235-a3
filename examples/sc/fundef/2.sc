array z[2,3];

func f(x[]) {
    array y[2,2] = 1;
    y[0] = x + 1;
    x[1] = x;
    z[x] = 1;
}

func g(x) {
    puti(x);
}

array x[3] = 2;
