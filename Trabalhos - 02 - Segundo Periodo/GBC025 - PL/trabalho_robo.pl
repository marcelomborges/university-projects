/*
Programa: Trabalho de Prolog - Robo
Alunos: Adriano Araujo         (11611BCC015)
	João Paulo de Oliveira (11611BCC046)
	Lucas Rossi            (11611BCC044)
	Marcelo Mendonca       (11611BCC020)
	Matheus Pimenta        (11611BCC038)
*/

/*-----Exercicio-01-------------------------------------------*/
passo(X - Y, n , X - Ny):-
	Ny is Y+1.
passo(X - Y, s, X - Ny):-
	Ny is Y-1.
passo(X - Y, e, Nx - Y):-
	Nx is X+1.
passo(X - Y, o, Nx - Y):-
	Nx is X-1.
passo(X - Y, no, Nx - Ny):-
	Nx is X-1,
	Ny is Y+1.
passo(X - Y, ne, Nx - Ny):-
	Nx is X+1,
	Ny is Y+1.
passo(X - Y, se, Nx - Ny):-
	Nx is X+1,
	Ny is Y-1.
passo(X - Y, so, Nx - Ny):-
	Nx is X-1,
	Ny is Y-1.

/*-----Exercicio-02-------------------------------------------*/
/*Caso base da recursao*/
caminho(X-Y, X-Y, []).

/*Movimento para os pontos cardeais*/
caminho(Xi-Yi,Xf-Yf,[e|R]):-
	Xi < Xf,
	Yi = Yf,
	passo(Xi-Yi, e, Z-W),
	caminho(Z-W, Xf-Yf, R).

caminho(Xi-Yi,Xf-Yf,[o|R]):-
	Xi > Xf,
	Yi = Yf,
	passo(Xi-Yi, o, Z-W),
	caminho(Z-W, Xf-Yf, R).

caminho(Xi-Yi,Xf-Yf,[n|R]):-
	Yi < Yf,
	Xi = Xf,
	passo(Xi-Yi, n, Z-W),
	caminho(Z-W, Xf-Yf, R).

caminho(Xi-Yi,Xf-Yf,[s|R]):-
	Yi > Yf,
	Xi = Xf,
	passo(Xi-Yi, s, Z-W),
	caminho(Z-W, Xf-Yf, R).

/*Movimento para os pontos colaterais*/
caminho(Xi-Yi,Xf-Yf,[ne|R]):-
	Xi < Xf,
	Yi < Yf,
	passo(Xi-Yi, ne, Z-W),
	caminho(Z-W, Xf-Yf, R).

caminho(Xi-Yi,Xf-Yf,[no|R]):-
	Xi > Xf,
	Yi < Yf,
	passo(Xi-Yi, no, Z-W),
	caminho(Z-W, Xf-Yf, R).

caminho(Xi-Yi,Xf-Yf,[se|R]):-
	Yi > Yf,
	Xi < Xf,
	passo(Xi-Yi, se, Z-W),
	caminho(Z-W, Xf-Yf, R).

caminho(Xi-Yi,Xf-Yf,[so|R]):-
	Xi > Xf,
	Yi > Yf,
	passo(Xi-Yi, so, Z-W),
	caminho(Z-W, Xf-Yf, R).

/*-----Exercicio-03-------------------------------------------*/
:- dynamic(ocupada/1).
robo:-
	retractall(ocupada(_)),
	le_tamanho(Tamanho),
	Quantidade is (Tamanho*2)+2,
	gera_obstaculo(Tamanho,Quantidade),
	listing(ocupada/1),
	le_inicio(Inicio, Tamanho),
	asserta(ocupada(Inicio)),
	le_final(Final, Tamanho),
	write('Passagens:'),nl,
	caminho_alterado(Inicio,Final,Tamanho,L),nl,
	write('Sequencia Final:'),nl,
	imprime_lista(L),!.

le_tamanho(Tamanho):-
	repeat,
	write('Digite o tamanho da "matriz": '),
	le_atomo(Tamanho),nl,
	(Tamanho > 3,!;fail).

le_inicio(X-Y, Tamanho):-
	repeat,
	write('Digite a posicao inicial do robo:'),nl,
	write('Digite o X da posicao inicial: '),
	le_atomo(X),
	write('Digite o Y da posicao inicial: '),
	le_atomo(Y),nl,
	(not(ocupada(X-Y)),
	 X >= 0,
	 X < Tamanho,
	 Y >= 0,
	 Y < Tamanho,!;
	write('--> Erro, posicao invalida.'),nl,nl,fail).

le_final(X-Y, Tamanho):-
	repeat,
	write('Digite a posicao final do robo:'),nl,
	write('Digite o X da posicao final: '),
	le_atomo(X),
	write('Digite o Y da posicao final: '),
	le_atomo(Y),nl,
	(not(ocupada(X-Y)),
	 X >= 0,
	 X < Tamanho,
	 Y >= 0,
	 Y < Tamanho,!;
	write('--> Erro, posicao invalida'),nl,nl,fail).

gera_obstaculo(_,0):- !.
gera_obstaculo(Tamanho,Quantidade):-
		random(0,Tamanho,X),
		random(0,Tamanho,Y),
		asserta(ocupada(X-Y)),
		N is Quantidade - 1,
		gera_obstaculo(Tamanho, N).

imprime_lista([]):-!.
imprime_lista([X|Y]):-
	write('('),
	write(X),
	write(') '),
	imprime_lista(Y).
/*------------------------------------------------------------*/
/*Movimentacao*/
caminho_alterado(X-Y, X-Y, _, [X-Y]).

/*Movimento para os pontos colaterais*/
caminho_alterado(Xi-Yi, Xf-Yf, Ordem, [Xi-Yi|R]):-
	Xi < Xf,
	Yi < Yf,
	passo(Xi-Yi,ne,Z-W),
	not(ocupada(Z-W)),
	Z >= 0,
	Z < Ordem,
	W >= 0,
	W < Ordem,
	assertz(ocupada(Z-W)),
	write('('),write(Z-W),write(')'),nl,
	caminho_alterado(Z-W, Xf-Yf, Ordem, R).

caminho_alterado(Xi-Yi, Xf-Yf, Ordem, [Xi-Yi|R]):-
	Xi > Xf,
	Yi < Yf,
	passo(Xi-Yi,no,Z-W),
	not(ocupada(Z-W)),
	Z >= 0,
	Z < Ordem,
	W >= 0,
	W < Ordem,
	assertz(ocupada(Z-W)),
	write('('),write(Z-W),write(')'),nl,
	caminho_alterado(Z-W, Xf-Yf, Ordem, R).

caminho_alterado(Xi-Yi, Xf-Yf, Ordem, [Xi-Yi|R]):-
	Yi > Yf,
	Xi < Xf,
	passo(Xi-Yi,se,Z-W),
	not(ocupada(Z-W)),
	Z >= 0,
	Z < Ordem,
	W >= 0,
	W < Ordem,
	assertz(ocupada(Z-W)),
	write('('),write(Z-W),write(')'),nl,
	caminho_alterado(Z-W, Xf-Yf, Ordem, R).

caminho_alterado(Xi-Yi, Xf-Yf, Ordem, [Xi-Yi|R]):-
	Xi > Xf,
	Yi > Yf,
	passo(Xi-Yi,so,Z-W),
	not(ocupada(Z-W)),
	Z >= 0,
	Z < Ordem,
	W >= 0,
	W < Ordem,
	assertz(ocupada(Z-W)),
	write('('),write(Z-W),write(')'),nl,
	caminho_alterado(Z-W, Xf-Yf, Ordem, R).

/*Movimento para os pontos cardeais*/
caminho_alterado(Xi-Yi, Xf-Yf, Ordem, [Xi-Yi|R]):-
	Yi < Yf,
	Xi = Xf,
	passo(Xi-Yi,n,Z-W),
	not(ocupada(Z-W)),
	Z >= 0,
	Z < Ordem,
	W >= 0,
	W < Ordem,
	assertz(ocupada(Z-W)),
	write('('),write(Z-W),write(')'),nl,
	caminho_alterado(Z-W, Xf-Yf, Ordem, R).

caminho_alterado(Xi-Yi, Xf-Yf, Ordem, [Xi-Yi|R]):-
	Yi > Yf,
	Xi = Xf,
	passo(Xi-Yi,s,Z-W),
	not(ocupada(Z-W)),
	Z >= 0,
	Z < Ordem,
	W >= 0,
	W < Ordem,
	assertz(ocupada(Z-W)),
	write('('),write(Z-W),write(')'),nl,
	caminho_alterado(Z-W, Xf-Yf, Ordem, R).

caminho_alterado(Xi-Yi, Xf-Yf, Ordem, [Xi-Yi|R]):-
	Xi < Xf,
	Yi = Yf,
	passo(Xi-Yi,e,Z-W),
	not(ocupada(Z-W)),
	Z >= 0,
	Z < Ordem,
	W >= 0,
	W < Ordem,
	assertz(ocupada(Z-W)),
	write('('),write(Z-W),write(')'),nl,
	caminho_alterado(Z-W, Xf-Yf, Ordem, R).

caminho_alterado(Xi-Yi, Xf-Yf, Ordem, [Xi-Yi|R]):-
	Xi > Xf,
	Yi = Yf,
	passo(Xi-Yi,o,Z-W),
	not(ocupada(Z-W)),
	Z >= 0,
	Z < Ordem,
	W >= 0,
	W < Ordem,
	assertz(ocupada(Z-W)),
	write('('),write(Z-W),write(')'),nl,
	caminho_alterado(Z-W, Xf-Yf, Ordem, R).

/*------------------------------------------------------------*/

/*Movimento para os pontos colaterais*/
caminho_alterado(Xi-Yi, Xf-Yf, Ordem, [Xi-Yi|R]):-
	passo(Xi-Yi,ne,Z-W),
	not(ocupada(Z-W)),
	Z >= 0,
	Z < Ordem,
	W >= 0,
	W < Ordem,
	assertz(ocupada(Z-W)),
	write('('),write(Z-W),write(')'),nl,
	caminho_alterado(Z-W, Xf-Yf, Ordem, R).

caminho_alterado(Xi-Yi, Xf-Yf, Ordem, [Xi-Yi|R]):-
	passo(Xi-Yi,no,Z-W),
	not(ocupada(Z-W)),
	Z >= 0,
	Z < Ordem,
	W >= 0,
	W < Ordem,
	assertz(ocupada(Z-W)),
	write('('),write(Z-W),write(')'),nl,
	caminho_alterado(Z-W, Xf-Yf, Ordem, R).

caminho_alterado(Xi-Yi, Xf-Yf, Ordem, [Xi-Yi|R]):-
	passo(Xi-Yi,se,Z-W),
	not(ocupada(Z-W)),
	Z >= 0,
	Z < Ordem,
	W >= 0,
	W < Ordem,
	assertz(ocupada(Z-W)),
	write('('),write(Z-W),write(')'),nl,
	caminho_alterado(Z-W, Xf-Yf, Ordem, R).

caminho_alterado(Xi-Yi, Xf-Yf, Ordem, [Xi-Yi|R]):-
	passo(Xi-Yi,so,Z-W),
	not(ocupada(Z-W)),
	Z >= 0,
	Z < Ordem,
	W >= 0,
	W < Ordem,
	assertz(ocupada(Z-W)),
	write('('),write(Z-W),write(')'),nl,
	caminho_alterado(Z-W, Xf-Yf, Ordem, R).

/*Movimento para os pontos cardeais*/
caminho_alterado(Xi-Yi, Xf-Yf, Ordem, [Xi-Yi|R]):-
	passo(Xi-Yi,n,Z-W),
	not(ocupada(Z-W)),
	Z >= 0,
	Z < Ordem,
	W >= 0,
	W < Ordem,
	assertz(ocupada(Z-W)),
	write('('),write(Z-W),write(')'),nl,
	caminho_alterado(Z-W, Xf-Yf, Ordem, R).

caminho_alterado(Xi-Yi, Xf-Yf, Ordem, [Xi-Yi|R]):-
	passo(Xi-Yi,s,Z-W),
	not(ocupada(Z-W)),
	Z >= 0,
	Z < Ordem,
	W >= 0,
	W < Ordem,
	assertz(ocupada(Z-W)),
	write('('),write(Z-W),write(')'),nl,
	caminho_alterado(Z-W, Xf-Yf, Ordem, R).

caminho_alterado(Xi-Yi, Xf-Yf, Ordem, [Xi-Yi|R]):-
	passo(Xi-Yi,e,Z-W),
	not(ocupada(Z-W)),
	Z >= 0,
	Z < Ordem,
	W >= 0,
	W < Ordem,
	assertz(ocupada(Z-W)),
	write('('),write(Z-W),write(')'),nl,
	caminho_alterado(Z-W, Xf-Yf, Ordem, R).

caminho_alterado(Xi-Yi, Xf-Yf, Ordem, [Xi-Yi|R]):-
	passo(Xi-Yi,o,Z-W),
	not(ocupada(Z-W)),
	Z >= 0,
	Z < Ordem,
	W >= 0,
	W < Ordem,
	assertz(ocupada(Z-W)),
	write('('),write(Z-W),write(')'),nl,
	caminho_alterado(Z-W, Xf-Yf, Ordem, R).

/*Predicados de Leitura*/
le_atomo(Atomo) :-
	le_str(String),
	name(Atomo, String).

le_str(String) :-
	get0(Char),
	le_str_aux(Char, String).

le_str_aux(-1, []) :- !. /* EOF */
le_str_aux(10, []) :- !. /* EOL(UNIX) */
le_str_aux(13, []) :- !. /* EOL (DOS) */
le_str_aux(Char, [Char|Resto]) :-
	le_str(Resto).
