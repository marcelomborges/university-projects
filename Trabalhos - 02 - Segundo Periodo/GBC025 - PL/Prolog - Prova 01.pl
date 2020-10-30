parte_de(estrutura,fogao).
parte_de(cordao_eletrico,fogao).
parte_de(resistencia_de_aquecimento,estrutura).
parte_de(painel_do_fogao,estrutura).
parte_de(botao,painel_do_fogao).
parte_de(isolador,cordao_eletrico).

feito_de(resistencia_de_aquecimento,metal).
feito_de(botao,plastico).
feito_de(cordao_eletrico,fio_metalico).
feito_de(isolador,fibra_plastica).

faz_parte_do_fogao(X):-
	parte_de(X,fogao).
faz_parte_do_fogao(X):-
	parte_de(X,Y),
	faz_parte_do_fogao(Y).

%Que objetos (simples) sao de metal?
%?- feito_de(X metal).

%Que objetos (simples) nao sao de plastico?
%?- feito_de(X,_),not(feito_de(X,plastico)).
