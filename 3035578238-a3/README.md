# COMP3235 Assignment 3
3035578238 Ho Leo

## Overview
The full C6 language and the bonus parts are implemented, including:
- Single and multi-dimension arrays
- Function and function calls, with array as parameters (pass-by-reference)
- `@` Global variable syntax
- Compile-time error checking
    - Array / function use-before-declare
    - Array / function repeated declarations
    - Return statements outside functions
    - etc.
- Runtime error reporting
    - Division by zero
    - Array index out of bounds
    - Array dimension mismatches
    - Negative array indices
- Support of multi-dimensional array arguments in function bodies

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

## Language Features
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

### Multi-dimensional array arguments
Multi-dimensional array arguments are fully supported in function bodies, i.e.

```
func g(z[]) {
    z[1,1,1] = 1;   <- this is supported
}
array t[5,5,5];
g(t);
```

To implement this, a new stack, the "safety stack", has to be constructed at the ceiling of the nas stack. The caller of a function with array parameters, contain instructions to push its arguments' dimensions and size to the "safety stack". This allows the function body to retrieve these information at runtime and to compute array offsets for multi-dimensional arrays. As the function returns, the caller then tears down the "safety stack" frame.

As array arguments are only known at runtime, array dimension mismatches or out-of-bound access may occur. All compiled programs contain instructions to detect if this occurs and generates a runtime error, exiting safely.

This is done without modification to nas.

## Limitations
- Max 100 functions declared
- Max 100 variables per scope
- Max 10 dimensions per array
- Labels 990-999 are reserved for runtime error reporting
