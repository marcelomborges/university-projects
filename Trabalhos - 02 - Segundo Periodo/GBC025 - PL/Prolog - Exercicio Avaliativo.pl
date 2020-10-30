impar(X):-
	mod(X,2)=:=1.

obter_pares_impares([],[],[]).
obter_pares_impares([X|Y],[X|W],S):-
	not(impar(X)),
	obter_pares_impares(Y,W,S).

obter_pares_impares([X|Y],Z,[X|S]):-
	impar(X),
	obter_pares_impares(Y,Z,S).
