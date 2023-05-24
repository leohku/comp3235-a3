// This demonstrates support of multi-dimensional arrays in function bodies,
// even when the array has been passed-by-reference to other functions

func h(a[]) {
    a[1,1,1] = 30;
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

// expect 30
