.text
.globl main

main:
   li $v0, 5 
   syscall # lê um inteiro da entrada padrão
   li $t1, 1 # soma
   beq $v0, $zero, saida
   li $t0, 1 # contador
 	
while:
   mul $t1, $t1, $t0 # soma = soma * contador
   beq $t0, $v0, saida
   addi $t0, $t0, 1  # incrementa o contador
   j while
 	
saida:
   move $a0, $t1
   li $v0, 1
   syscall
   li $v0, 10
   syscall
 	
 	
