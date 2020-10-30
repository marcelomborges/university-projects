pai(pedro,ana).
pai(pedro,maria).
pai(joaquim,pedro).
pai(manoel,joaquim).

ancestral(X,Y):-
	pai(X,Y).
ancestral(X,Y):-
	pai(X,R),
	ancestral(R,Y).
