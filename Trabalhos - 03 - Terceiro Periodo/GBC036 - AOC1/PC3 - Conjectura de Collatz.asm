# Programa: PC3 - Conjectura de Collatz
# Aluno: Marcelo Mendonca Borges
# Matricula: 11611BCC020

.data
	leituraNumero: .asciiz "Digite um numero inteiro ao qual sera aplicada a Conjectura de Collatz: "
	
	valorAtual: .asciiz "\nValor Atual: "
.text
	main:
		add $t1, $zero, 2 # Colocando o valor 2 no registrador $t1 para utilizar posteriormente na divisao.
		
		li $v0, 4 # Escrever string.
		la $a0, leituraNumero
		syscall
		
		li $v0, 5 # Ler Inteiro. Resultado vai para $v0.
		syscall
		
		move $t0, $v0 # Move o valor lido na ultima syscall para $t0 que eh onde sera trabalhado.
		
		while:
			beq $t0, 1, fimDoPrograma # Se o valor em $t0 for igual a 1 nesse ponto o programa vai para fimDoPrograma
			
			li $v0, 4 # Escrever string.
			la $a0, valorAtual
			syscall
			
			li $v0, 1 # Escrever inteiro.
			add $a0, $t0, $zero
			syscall
			
			div $t0, $t1 # Divide $t0 por 2.
			mfhi $t2 # Pega o resto da divisao anterior que esta em HI e coloca em $t2.
			
			beq $t2, 1, acaoParaNumeroImpar # Caso o valor seja impar faz a acao correspondente.
			beq $t2, $zero, acaoParaNumeroPar # Caso o valor seja par faz a acao correspondente.
			
			j while
				
	fimDoPrograma:
		li $v0, 4 # Escrever string.
		la $a0, valorAtual
		syscall
		
		li $v0, 1 # Escrever inteiro.
		add $a0, $t0, $zero
		syscall
		
		li $v0, 10 # Exit. Operacao de finalizacao do programa.
		syscall
		
	acaoParaNumeroImpar:
		mul $t0, $t0, 3 # Multiplica o valor em $t0 por 3 e guarda em $t0.
		add $t0, $t0, 1 # Adiciona 1 ao valor em $t0 e guarda em $t0.
		j while # Retorna para a funcao while.
		
	acaoParaNumeroPar:
		div $t0, $t0, 2 # Divide o valor em $t0 por 2 e guarda em $t0.
		j while # Retorna para a funcao while.
