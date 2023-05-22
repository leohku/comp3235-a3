Exploration
---
[X] Ask professor on ambiguity on passing arrays as arguments

Development
---
[X] Build symbol table structure
[X] Migrate old symbol table
[X] Move var symgen to codegen

[X] Single dimension array in global scope (40%)
    [X] Array initialisation
        [X] Lexing
        [X] Parsing
        [X] Symgen
        [X] Without initial value
        [X] With initial value
    [X] Array invokation
        [X] Lexing
        [X] Parsing
        [X] Symlookup
        [X] Assignment (pop)
        [X] Use (push)
[X] Multi-dimension array (10%)
    [X] Array initialisation
        [X] Parsing
        [X] Introducing ari()
        [X] Refactoring opr(ARRAY)
    [X] Array invokation
        [X] Parsing
        [X] Refactoring varlookup
    [X] geti, getc, gets n-d array support
    [ ] Multiple array declaration per line                     <- NOT DONE
[ ] Functions decl and calls with no array as param (60%)
    [ ] Function declaration site
        [X] Delayed emission (sprintf to two buffers)
        [X] Lexing and parsing
        [ ] Code gen
            [X] Label shenanigans
            [X] Function symtable entry - name and params
            [ ] Function body code gen
                [X] Scope activation and deactivation
                [X] varlookup & arr_symgen refactoring to support local scopes
                    [X] Create return structs for searchVarTable and searchPrmTable
                    [X] Local variable symtable entries
                    [X] arr_symgen refactoring
                    [X] varlookup emits full register
                    [X] varlookup consumer refactoring to take register
                [X] "var" generation and WIP buffer emission
                [X] Output buffer switching depending on scope
                [X] Return behaviour (including ret with optional return value)
                    [X] Lexing and parsing
                    [X] Codegen
            [ ] Global variables denoted with "@"
                [ ] Lexing and parsing
            [X] Expect global addresses for all array params (10%)
    [ ] Function calling site
        [ ] Lexing and parsing
        [ ] Pass global address for all array params (10%)
    [ ] Support for n-d arrays as arguments using stack mirroring
[ ] Test suite
    [ ] Normal programs
    [ ] AST error cases