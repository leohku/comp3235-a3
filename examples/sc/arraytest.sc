// Single dimensional arrays
array foo[10,10,10];
array x[3,2] = 462;
array z[100];
x = 30 + x[-1+1];
z[2] = 2;
puti(x);        // Expected 492
puti(z[2]);     // Expected 2

// Multi dimensional arrays
puti(x[2,1]);   // Expected 462
foo[4,6,2] = 1337;
puti(foo[x[2,1]]);  // Expected 1337
