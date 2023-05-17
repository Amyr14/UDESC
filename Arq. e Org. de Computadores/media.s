.data
	erro_string: .asciiz "ERRO\n"
	pula_linha: .asciiz "\n"
.text
.globl main

main:
	li, $v0, 5
	syscall
	beq $v0, -1, erro
	li $t0, 0 # soma
	li $t1, 0 # contador
while:
	add $t0, $t0, $v0
	li, $v0, 5
	syscall
	addi $t1, $t1, 1 # incrementa o contador
	beq $v0, -1, saida
	j while

erro:
	la $a0, erro_string
	li $v0, 4
	syscall
	li $v0, 10
	syscall
	
saida: 
	move $a0, $t0
	li $v0, 1
	syscall
	la $a0, pula_linha
	li $v0, 4
	syscall
	div $a0, $t0, $t1
	li $v0, 1
	syscall
	li $v0, 10
	syscall


	
	

	
	
	