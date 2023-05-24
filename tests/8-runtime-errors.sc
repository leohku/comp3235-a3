// This demonstrates runtime error reporting,
// in this case, an out-of-bounds access scenario

func h(a[]) {
    a[6,1,1] = 30;  // <- out-of-bounds access
}

func g(a[]) {
    a[1,1,1] = 20;
    h(a);
}

func f() {
    array z[5,5,5];
    z[1,1,1] = 10;
    g(z);
    return z[1,1,1];
}

puti(f());

// expect "Runtime Error: Array index out of bounds."
