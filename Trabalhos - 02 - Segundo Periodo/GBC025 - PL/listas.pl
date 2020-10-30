%%%---Predicados da Aula Teorica---%%%

cabeca([X|_],X).
cauda([_|Y],Y).

soma([X],X).
soma([X|Y],R):-
	soma(Y,S),
	R is S+X.

tamanho([],0).
tamanho([_|Y],R):-
	tamanho(Y,S),
	R is S+1.

%%%---Predicados da Pratica 05---%%%

concatena([],L,L).
concatena([X|R],L,[X|C]) :-
	concatena(R,L,C).

adiciona(X,L,[X|L]).

adiciona_fim(X,L,NL) :-
	concatena(L,[X],NL).

tira(_,[],[]).
tira(X,[X|R],R).
tira(X,[Y|R],[Y|R1]) :-
	X\=Y,
	tira(X,R,R1).

tira_todos([],[]).
tira_todos([_|Y],R):-
	tira_todos(Y,R).

pertence(X,[X|_]).
pertence(X,[Y|Z]):-
	X\=Y,
	pertence(X,Z).

ultimo([X],X).
ultimo([_|Y],Z):-
	ultimo(Y,Z).

sublista([],_).
sublista([X|Y],L):-
	pertence(X,L),
	sublista(Y,L).

insere_crescente(X,[],[X]).
insere_crescente(X,[Y|Z],[X|[Y|Z]]):-
	X=<Y.
insere_crescente(X,[Y|Z],[Y|W]):-
	Y<X,
	insere_crescente(X,Z,W).

ordena_crescente([],[]).
ordena_crescente([X|Y],L):-
	ordena_crescente(Y,R),
	insere_crescente(X,R,L).

insere_decrescente(X,[],[X]).
insere_decrescente(X,[Y|Z],[X|[Y|Z]]):-
	X>=Y.
insere_decrescente(X,[Y|Z],[Y|W]):-
	Y>X,
	insere_decrescente(X,Z,W).

ordena_decrescente([],[]).
ordena_decrescente([X|Y],L):-
	ordena_decrescente(Y,R),
	insere_decrescente(X,R,L).

inverte([],[]).
inverte([X|Y],L):-
	inverte(Y,R),
	adiciona_fim(X,R,L).

permutacao([],[]).
permutacao([X|Y],L):-
	permutacao(Y,P),
	insere(X,P,L).

insere(X,Y,[X|Y]).
insere(X,[Y|Z],[Y|R]):-
	insere(X,Z,R).

subconjunto([],_).
subconjunto([X|Y],L):-
	pertence(X,L),
	subconjunto(Y,L).
