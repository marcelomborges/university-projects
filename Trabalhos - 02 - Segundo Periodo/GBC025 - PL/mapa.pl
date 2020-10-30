estrada(a,b,25).
estrada(a,d,23).
estrada(b,c,19).
estrada(b,e,32).
estrada(c,d,14).
estrada(c,f,28).
estrada(d,f,30).
estrada(e,f,26).

dist(X,Y,Z):-
	estrada(X,Y,Z).
dist(X,Y,Z):-
	estrada(X,R,V),
	dist(R,Y,W),
	Z is V+W.