    push    sp
    push    100
    add
    pop     sp
    push    1
    push    2
    push    3
    push    4
    push    5
    call    L000
    puti
    jmp     L001
L000: var 5,0
    push    fp[0]
    push    fp[1]
    add
    push    fp[2]
    add
    push    fp[3]
    add
    push    fp[4]
    add
    ret
L001: