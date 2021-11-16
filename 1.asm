.set noat
.set noreorder
.align 2

lw $16, 0($0)       # $s0 = b = memory[0]
lw $17, 4($0)       # $s1 = c = memory[4]
lw $18, 8($0)       # $s2 = d = memory[8]
add $16, $16, $17   # b += c
sub $16, $16, $18   # (b+c) -= d
sw $16, 12($0)      # memory[12] = (b+c)-d
