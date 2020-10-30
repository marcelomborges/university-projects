%%%-----Aula-Pratica-06-----%%%
%%%-----Exercicio-2.1-----%%%

~(A&B) <===> ~A \/ ~B

:-op(70,xfx,<===>).
:-op(50,fx,~).
:-op(60,yfx,&).
:-op(60,yfx,\/).

%%%-----Exercicio-2.2-----%%%

se X entao Y.
se X e Y entao Z.

:-op(60,fy,se).
:-op(60,xfx,entao).
:-op(50,yfx,e).

%%%-----Exercicio-2.3-----%%%

:-op(50,xfx,existe_em).
X existe_em [X|_].
X existe_em [Y|Z] :-
	X \= Y,
	X existe_em Z.

%%%:-op(50,yfx,e).
:-op(60,fx,concatena).
:-op(70,xfx,gera).

concatena [] e X gera X.
concatena [X|Y] e Z gera [X|W] :-
	concatena Y e Z gera W.

%%%-----Exercicio-2.4-----%%%
t(0+1, 1+0).
t(X+0+1, X+1+0).
t(X+1+1, Z) :-
	t(X+1, X1),
	t(X1+1, Z).
