%telefone(P, T):-
%o n. de telefone da casa da pessoa P eh T.

telefone(maria, 123).
telefone(joaquim, 234).
telefone(marco, 345).
telefone(pedro, 456).
telefone(ana, 567).
telefone(juliana, 678).

%visita(X, Y):-
%a pessoa X esta visitando a pessoa Y.

visita(juliana, maria).
visita(ana, joaquim).
visita(marco, juliana).
visita(pedro, juliana).

%emCasa(X):-
%X esta em casa

emCasa(joaquim).
emCasa(maria).

acompanhada(X):-
	visita(_,X).

inconsistente:-
	emCasa(X),
	visita(X,_).

em_casa_de(X,Y):-
	visita(X,Y),
	emCasa(Y).
em_casa_de(X,Y):-
	visita(X,Z),
        em_casa_de(Z,Y).

contato(X,Y):-
	emCasa(X),
	telefone(X,Y).
contato(X,Y):-
	em_casa_de(X,Z),
	telefone(Z,Y).

festeiro(X):-
	emCasa(X),
	em_casa_de(Y,X),
	em_casa_de(Z,X),
	not(X=Y),
	not(Y=Z),
	not(Z=X),!.


