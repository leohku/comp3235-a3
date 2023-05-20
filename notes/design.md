Symtable design
---
1 global variable table
1 global function table - that each links to a local variable table

Global variable table
---
```
{
    width: x,
    variables: [{
        symbol: "<sym>",
        ndim: x,
        dims: Dim[100],
        offset: x
    }, {...}]
}
```

width denotes the full width of the global variable table, used to allocate sp in the beginning

variables denotes the list of variables in said scope
    symbol is the string name of the variable
    offset is the base pointer offset relative to sb

Global function table
---
```
[{
    symbol: "<sym>",
    argtable: ArgVarTable
    localtable: LocalVarTable
}]
```
LocalVarTable.width is used for informing the second var argument (# of local variables)

Note: each function needs two labels, the function declaration, and the passthrough
Let the lower number be the declaration,
higher be the passthrough label

Local variable table - same as global var table, but offset is relative to fp instead
---
Note: when a variable cannot be found at local function table, then find it in global table

Functions:
---
Second behaviour:

func f(x[]):
  y = x + 1;    // means x[0] + 1
  puti(y[0])    // shows value of x[0] + 1, which can be meaningful
  x = x;        // means x[0] = x[0]
  f(x);         // only allows array variables to be passed, no integers allowed

func g(x):
  puti(x);      // shows value of x

array x[5];
f(x);           // call site knows f() accepts an array, so passes an address
g(x);           // call site knows g() accepts a value, so passes a value

The benefit of this behaviour is that pointer addresses are never exposed to end programmers using the language at all, which is of no use anyways in this language that has no concept of addresses.
