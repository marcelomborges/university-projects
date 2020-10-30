
%%%-----Exercicio-02-----%%%
n_esimo(1,X,[X|_]).
n_esimo(N, X, [_|Z]):-
	n_esimo(O,X,Z),
	N is O+1.

%%%-----Exercicio-03-----%%%
no_elementos([],0).
no_elementos([_|Y],N):-
	no_elementos(Y,R),
	N is R+1.

%%%-----Exercicio-04-e-05-----%%%
tire_elemento(_,[],[]).
tire_elemento(X,[X|Y],Y).
tire_elemento(X,[Y|Z],[Y|W]):-
	 X \= Y,
	 tire_elemento(X,Z,W).

%%%-----Exercicio-06-e-07-----%%%
retirar_ocor(_,[],[]).
retirar_ocor(X,[X|Y],Z):-
	retirar_ocor(X,Y,Z).
retirar_ocor(X,[Y|Z],[Y|W]):-
	X \= Y,
	retirar_ocor(X,Z,W).

%%%-----Exercicio-08-----%%%
retire_repet([],[]).
retire_repet([X|Y],[X|Z]):-
	retirar_ocor(X,Y,R),
	retire_repet(R,Z).

%%%-----Exercicio-09-----%%%
concatenar([],L,L).
concatenar([X|Y],Z,[X|C]):-
	concatenar(Y,Z,C).

%%%-----Exercicio-10-----%%%
maior([X],X).
maior([X|Y],Z):-
	maior(Y,Z),
	Z > X.
maior([X|Y],X):-
	maior(Y,Z),
	X > Z.

%%%-----Exercicio-11-----%%%
menor([X],X).
menor([X|Y],Z):-
	menor(Y,Z),
	Z < X.
menor([X|Y],X):-
	menor(Y,Z),
	X < Z.

%%%-----Exercicio-12-----%%%
pegar([],[_|_],[]).
pegar([X],Y,[E]):-
	n_esimo(X,E,Y).
pegar([X|Y],Z,[B|A]):-
	n_esimo(X,B,Z),
	pegar(Y,Z,A).

%%%-----Exercicio-13-----%%%
inserir_cabeca(X,Y,[X|Y]).

%%%-----Exercicio-14-----%%%
inserir_N(X,1,Y,[X|Y]).
inserir_N(X,N,[Y|Z],[Y|W]):-
	O is N-1,
	inserir_N(X,O,Z,W).

%%%-----Exercicio-15-----%%%
inverter([],[]).
inverter([X|Y],L):-
	inverter(Y,R),
	concatenar(R,[X],L).

%%%-----Exercicio-16-----%%%
substitui(_,_,[],[]).
substitui(X,Y,[X|Z],[Y|W]):-
	substitui(X,Y,Z,W).
substitui(X,Y,[Z|W],[Z|R]):-
	X \= Z,
	substitui(X,Y,W,R).

%%%-----Exercicio-17-----%%%
duplicar_todos([X],[X,X]).
duplicar_todos([X|Y],[X,X|S]):-
	duplicar_todos(Y,S).

%%%-----Exercicio-18-----%%%
duplicar_um(_,[],[]).
duplicar_um(X,[X|Z],[X,X|Z1]):-
	duplicar_um(X,Z,Z1).
duplicar_um(X,[W|Z],[W|Z1]):-
	X\=W,
	duplicar_um(X,Z,Z1).

%%%-----Exercicio-19-----%%%
nao_vazia([X],[X|_]).
nao_vazia([X|_],Z):-
	pertence(X,Z).
nao_vazia([X|Y],Z):-
	not(pertence(X,Z)),
	nao_vazia(Y,Z).

pertence(X,[X|_]).
pertence(X,[Y|Z]):-
	X\=Y,
	pertence(X,Z).

%%%-----Exercicio-20-----%%%
uniao([],[X|Y],[X|Y]).
uniao([X|Y],[Z|W],L):-
	concatenar([X|Y],[Z|W],R),
	retire_repet(R,L).

%%%-----Exercicio-21-----%%%
disjuntos(X,Y):-
	not(nao_vazia(X,Y)).

%%%-----Exercicio-22-----%%%
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

iguais(X,X):-!.
iguais(X,Y):-
	ordena_crescente(X,R1),
	ordena_crescente(Y,R2),
	retire_repet(R1,S1),
	retire_repet(R2,S2),
	iguais(S1,S2),!.


