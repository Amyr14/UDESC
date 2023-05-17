.text

main:
   # Lê um inteiro
   li $v0, 5
   syscall 
   
   # Seta argumento e chama a função
   move $a1, $v0
   jal somatorio
   
   # Mostra o resultado
   move $a0, $v1
   li $v0, 1
   syscall
   
   # Encerra o programa
   li $v0, 10
   syscall

somatorio:
   # Caso base ($a1 == 0)
   beqz $a1, caso_base
   
   # Salva o contexto
   addi $sp, $sp, -8
   sw $a1, 0($sp)
   sw $ra, 4($sp)
   
   # Realiza a recursão
   addi $a1, $a1 -1
   jal somatorio
   
   # Recupera valores da pilha
   lw $t0, 0($sp)
   lw $ra, 4($sp)
   addi $sp, $sp, 8
   
   # Soma valores
   add $v1, $v1, $t0
   jr $ra
   
caso_base:
   li $v1, 0
   jr $ra