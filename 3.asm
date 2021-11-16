.set noat
.set noreorder
.align 2

lw $16, 0($0)            # constant 1 (loop increment) = memory[0]
lw $17, 4($0)            # b = memory[4]
lw $18, 8($0)            # c = memory[8]
lw $19, 12($0)           # d = memory[12]
add $17, $17, $18        # b += c
mlt $17, $17, $19        # (b+c) *= d (not a real MIPS instruction!)
sw $17, 16($0)           # memory[16] = result
