.data
   quebra_linha: .asciiz "\n"
   
.text

main:
   # Recebe n e k
   li $v0, 5
   syscall
   beqz $v0, fim
   move $a1, $v0
   li $v0, 5
   syscall
   move $a2, $v0
   
   jal contar_digitos
   
   # Printa o retorno de contar_digitos
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

contar_digitos:
   li $t0, 10
   li $v1, 0

contar_digitos_recursao:
   # Se o argumento for igual a zero, começa a contar os digitos
   beqz $a1, proximo_digito
   
   # Divide o argumento por 10. O resto é o digito atual
   div $a1, $t0
   mflo $a1
   mfhi $t1
   
   # Salva o digito atual e o endereço de memória no stack
   addi $sp, $sp, -8
   sw $t1, 0($sp)
   sw $ra, 4($sp)
   
   jal contar_digitos_recursao
   
   # Começa a contar os digitos que são iguais a k
   lw $t1, 0($sp)
   lw $ra, 4($sp)
   addi $sp, $sp, 8
   bne $t1, $a2, proximo_digito
   addi $v1, $v1, 1

proximo_digito:
   jr $ra
   
