
.text
 
main:
   # Lê um inteiro qualquer da entrada padrão
   li $v0, 5 
   syscall 
   
   # Seta o registro de argumento para o valor recebido
   move $a1, $v0
   
   jal fibonacci
   
   # Imprime o valor retornado pela função fibonacci
   move $a0, $v1
   li $v0, 1
   syscall
   
   j fim
   
fibonacci:
   move $v1, $zero 
   
fibonacci_recursao:
   # Verifica por casos base
   blt $a1, 2, caso_base
  
   # Salva o galho da direita para uso posterior
   addi $t0, $a1, -2
   addi $sp, $sp, -8
   sw $t0, 0($sp)
   sw $ra, 4($sp)
 
   # Setando o argumento para avaliar o galho da esquerda
   addi $a1, $a1, -1
   
   jal fibonacci_recursao
   
   # Recupera valores do galho da direita, volta para fibonacci_recursao SEM linkar
   lw $a1, 0($sp)
   lw $ra, 4($sp)
   addi $sp, $sp, 8
   
   j fibonacci_recursao
  
caso_base:
   addi $v1, $v1, 1
   jr $ra	     
 
fim:
   li $v0, 10
   syscall
 
	 
