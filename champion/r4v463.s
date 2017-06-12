.name "r4v463"

sti r1,%:live,%1
live %0

live:
    live %0
    ld r2,10
    sti r1,r2,10
    add r2,10,r2
    xor r1,r1,r3
    zjmp %:live