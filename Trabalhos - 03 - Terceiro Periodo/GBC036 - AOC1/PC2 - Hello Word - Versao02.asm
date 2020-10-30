# Programa: PC2 - Hello Word
# Aluno: Marcelo Mendonca Borges
# Matricula: 11611BCC020

.data
	leituraNome: .asciiz "Digite o seu nome (ate 7 caracteres): "
	nome : .space 100
	leituraMatricula: .asciiz "\nDigite a sua matricula (ate 11 caracteres): "
	matricula: .space 100
	mensagem1 : .asciiz "\n>>>> Hello world, aqui eh o "
	mensagem2 : .asciiz " matricula "
.text
	li $v0, 4
	la $a0 leituraNome
	syscall
	li $v0, 8
	la $a0 nome
	la $a1 8
	syscall
	li $v0, 4
	la $a0 leituraMatricula
	syscall
	li $v0, 8
	la $a0 matricula
	la $a1 12
	syscall
	li $v0, 4
	la $a0 mensagem1
	syscall
	li $v0, 4
	la $a0 nome
	syscall
	li $v0, 4
	la $a0 mensagem2
	syscall
	li $v0, 4
	la $a0 matricula
	syscall
	
	
