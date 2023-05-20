Questions:

1. Implementation of array argument passing - pass by val or ref? If pass by val, do we need to implement a heap / just make the stack frame for every function very large?

2. CALL case of nas2 - moving params to new frame (line 194):
st[SP+2-k] = st[SP-k]
Since k is an iterator on the operand count, doesn't this eventually overwrite the existing stack frame when k > 2?

3. Are we allowed to modify nas?

Notes:

- Need backpatching to patch labels
- For bonus (b), fns can have arrays as params, no factor for local vars - they are still declared the same way - only affects passed in arguments
- Function declarations need to have `jmp L001; L000: var x,y; ...; ret; L001: ...`.
- Function calls are translated to `push .; push.; call L...;`
- Variables either use sb[] (global) or fp[] (local) depending on location in symtable

Todo:

- [X] Symtable design (need to clarify the relationship between symtable and runtime stack)
- [ ] Need a way to backpatch (delayed emit) on function declarations <- lexer modification for stmt to have func + stmt_list, and perform operations to backpatch
- [ ] For the above, need to patch printf() to store into an internal buffer that can be safely modified
- [ ] Need a way to reference the correct symbol table while generating commands

Stuck:
- Still need clarification on passing array as arguments (AFAIK this may or may not require nas modification due to changing the calling convention if passing by value - after all the array sizes are dynamic)