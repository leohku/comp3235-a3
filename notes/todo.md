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
[ ] Functions decl and calls with no array as param (60%)
    [ ] Function declaration site
        [X] Delayed emission (sprintf to two buffers)
        [ ] Code gen
            [ ] Label shenanigans
            [ ] Symtable entries with scoping
            [ ] Global variables denoted with "@"
            [ ] Expect global addresses for all array params (10%)
            [ ] Return behaviour (ret for all with optional return value)
    [ ] Function calling site
        [ ] Pass global address for all array params (10%)