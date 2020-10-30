# Programa: PC2 - Hello Word
# Aluno: Marcelo Mendonca Borges
# Matricula: 11611BCC020

.data
	helloWord: .asciiz ">>>> Hello world, aqui eh o Marcelo Mendonca Borges matricula 11611BCC020"
.text
	li $v0, 4
	la $a0 helloWord
	syscall
