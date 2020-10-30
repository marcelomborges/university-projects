% This buffer is for notes you don't want to save.
% If you want to create a file, visit that file with C-x C-f,
% then enter the text in that file's own buffer.

pai(pedro,ana).
pai(pedro,maria).
pai(pedro,joaquim).
mae(cristina,ana).
mae(cristina,maria).
mae(cristina,joaquim).

homem(pedro).
homem(joaquim).
mulher(cristina).
mulher(ana).
mulher(maria).

filho(X,Y):-
	pai(Y,X),
	homem(X).
filho(X,Y):-
	mae(Y,X),
	homem(X).

filha(X,Y):-
	pai(Y,X),
	mulher(X).
filha(X,Y):-
	mae(Y,X),
	mulher(X).

irmaos(X,Y):-
	pai(Z,X),
	pai(Z,Y).
irmaos(X,Y):-
	mae(Z,X),
	mae(Z,Y).

