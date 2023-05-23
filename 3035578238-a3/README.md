# COMP3235 Assignment 3
3035578238 Ho Leo

## Overview
The full C6 language and the bonus parts are implemented, including:
- Single and multi-dimension arrays
- Function and function calls, with array as parameters (pass-by-reference)
- `@` Global variable syntax
- Compile-time error checking

## Compilation
To compile `nas2`, run the following from the root project directory:
```
cd nas
make nas2
cd ..
```

To compile `c6c`, run the following from the root project directory:
```
cd src
make c6c
cd ..
```

To run a program, e.g. `./tests/1-mergesort.sc`, run the following from the root project directory:
```
./nas/nas2 <(./src/c6c ./tests/1-mergesort.sc)
```

## Tests
Multiple tests are written to ensure correctness. To start the test runner, run the following from the root project directory:
```
chmod +x ./tests/runtests.sh && ./tests/runtests.sh
```

## Syntax Design
For supporting array parameters in functions, I introduced a syntax during function declaration to denote an array parameter should be passed in, example:
```
func f(x, y[], z) {;}
```
Denotes `x` and `z` being passed by value, while `y` is an array passed by reference. When calling the function, the slot that `y` is in must only be passed an array argument, example:
```
array arr[1];
f(1, arr, 2);       // legal
f(1, arr[0], 2);    // illegal
```
Inside and outside a function, referencing the name of an array still resolves to its first element, not its address. For example:
```
array a[1] = 5;
a = a + 1;      // equivalent to a[0] = a[0] + 1;
func f(x, y[], z) {
    y = y + 1;  // equivalent to y[0] = y[0] + 1;
                // not &y = &y + 1;
}
```
This is deliberately designed to maintain consistency, so that the users of the language is not exposed to internal addresses of nas at any time (since the language contains no meaningful constructs for pointer operations anyways). More examples may be found in the `/tests` directory, e.g. the `mergeSort` function in `1-mergesort.sc`.

## Limitations
- Max 100 functions declared
- Max 100 variables per scope
- Max 10 dimensions per array
- Multi-dimension invokation of pass-by-ref arrays is not supported, i.e.
```
func f(x[]) {
    y = x[1,2];     // illegal
}
```
This is because pass-by-ref arrays are dynamic in size and dimension by nature, making it impossible to generate at compile time. However, referencing multi-dimensional global arrays are supported in function scopes, i.e.
```
array a[1,2] = 3;
func f() {
    y = @a[0,1];    // legal
}
```
