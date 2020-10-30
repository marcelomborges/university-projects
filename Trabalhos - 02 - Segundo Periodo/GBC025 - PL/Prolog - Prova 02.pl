%%%-----Prova-Prolog-11/11/2016-----%%%

%%%-----Aluno: Marcelo Mendonca Borges
%%%-----Matricula: 11611BCC020

%%%-----Questao-01-----%%%
ack(0,Y,R):-
	R is Y+1.
ack(X,0,R):-
	X > 0,
	S is X-1,
	ack(S,1,R).
ack(X,Y,R):-
	X > 0,
	Y > 0,
	T is X-1,
	U is Y-1,
	ack(X,U,S),
	ack(T,S,R).

%%%-----Questao-02-----%%%
representa_lista([],[]).
representa_lista([X,X],[X]).
representa_lista([X,Y],[X|Z]):-
	X =< Y,
	A is X+1,
	representa_lista([A,Y],Z).

concatenar([],L,L).
concatenar([X|Y],Z,[X|C]):-
	concatenar(Y,Z,C).

interv2lista([],[]).
interv2lista([X|Y],L):-
	representa_lista(X,Z),
	interv2lista(Y,W),
	concatenar(Z,W,L).

escreve_lista([X]):-
        write('('),
	write(X),
	write(')'),
	nl.
escreve_lista([X|Y]):-
	write('('),
	write(X),
	write(') , '),
	escreve_lista(Y).
