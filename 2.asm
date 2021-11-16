.set noat
.set noreorder
.align 2

lw $16, 0($0)            # constant 1 (loop increment) = memory[0]
lw $17, 4($0)            # b = memory[4]
lw $18, 8($0)            # c = memory[8]
lw $19, 12($0)           # d = memory[12]
add $17, $17, $18        # b += c
sub $20, $20, $20        # result = 0
sub $21, $21, $21        # count = 0
LOOP:
beq $21, $19, END        # if count == d goto END
add $20, $20, $17        # result += (b+c)
add $21, $21, $16        # count += 1
beq $1, $2, LOOP         # goto LOOP
END:
sw $20, 16($0)           # memory[16] = result
