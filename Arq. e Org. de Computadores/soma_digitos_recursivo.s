.data
   quebra_linha: .asciiz "\n"
   
.text

main:
   # Lê um inteiro
   li $v0, 5
   syscall
   
   beqz $v0, fim
   
   move $a1, $v0
   jal soma_digitos
   
   # Imprime o retorno da função
   move $a0, $v1
   li $v0, 1
   syscall
   la $a0, quebra_linha
   li $v0, 4
   syscall
   
   j main
   
fim:
   li $v0, 10
   syscall
   
soma_digitos:
   li $v1, 0
   li $t0, 10
   
soma_digitos_recursao:
   beqz $a1, caso_base
   
   # Realiza a divisão e seta o argumento para o quociente 
   div  $a1, $t0
   mflo $a1
   mfhi $t1
   # Salvando resto da divisão e endereço de retorno no stack
   addi $sp, $sp, -8
   sw $t1, 0($sp)
   sw $ra, 4($sp)
   
   jal soma_digitos_recursao
   
   # Recupera digitos do stack e começa a somar
   lw $t1, 0($sp)
   lw $ra, 4($sp)
   addi $sp, $sp, 8
   
   add $v1, $v1, $t1
   jr $ra
   
caso_base:
   jr $ra
