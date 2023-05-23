array z[2,3];

func g(x) {
    puti(x);
    // f(x); // errors because function f not found
}

func f(x[]) {
    array y[2,2] = 1;
    y[0] = x + 1;
    x[1] = x;
    // z[x] = 100; // cannot declare array on first use
    z = 100;
    f(@z);  // pass global variable, expecting array
    f(y);   // pass local variable, expecting array
    f(x);   // pass passed-by-ref variable, expecting array
    // f(z);    // errors because z is not an array
    // f(y[0]); // errors because arrays must be ref by name only
    g(@z);  // pass global variable (array), expecting value
    g(z);   // pass local variable, expecting value
    g(y);   // pass local variable (array), expecting value
    g(x);   // pass passed-by-ref variable (array), expecting value
}

array x[3] = 2;
n = 5;
f(x);
g(z);
// g(x,n); // function g expects 1 arguments, but 2 given
// f(n); // errors because n is not an array
// f(m); // errors because array m is not found
