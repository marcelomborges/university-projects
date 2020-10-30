socio(joao,aau).
socio(suzana,aau).
socio(basilio,aau).
socio(elvira,aau).
casado(joao,suzana).
irma(elvira,basilio).

irmao(X,Y):-
	irma(Y,X).
