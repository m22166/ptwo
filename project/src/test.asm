    .global my_add
my_add:
    move.l  4(%sp), %d0     
    add.l   8(%sp), %d0     
    rts

    .global print_ascii
print_ascii:
    move.l  4(%sp), %a0      
print_loop:
    move.w  (%a0)+, %d0      
    beq     end_print      
    bra     print_loop

end_print:
    rts
