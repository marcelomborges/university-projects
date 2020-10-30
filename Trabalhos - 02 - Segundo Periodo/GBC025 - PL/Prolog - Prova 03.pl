/*
Programa: Prova 03 - Prolog
Aluno: Marcelo Mendonca Borges
Matricula: 11611BCC020
*/

le_str(String):-
	get0(Char),
	le_str_aux(Char, String).

le_str_aux(-1,[]):- !.
le_str_aux(10, []):- !.
le_str_aux(13, []):- !.
le_str_aux(Char, [Char|Resto] ):-
	le_str(Resto).

le_atomo(Atomo):-
	le_str(String),
	name(Atomo,String).

main_alunos:-
	repeat,
	['kb.pl'],
	mostra_menu_alunos,
	write('Digite uma opcao: '),
	le_opcao(R),nl,
	(R = 5,!;executa_alunos(R),fail).

le_opcao(R):-
	repeat,
	le_atomo(R),
	(
	(R = 0,!);
	(R = 1,!);
	(R = 2,!);
	(R = 3,!);
	(R = 4,!);
	(R = 5,!);
	write('Digite uma opcao valida:'),fail).

mostra_menu_alunos:-
	nl,
	write('MENU: '),nl,
	write('0- Listar alunos'),nl,
	write('1- Obter o curso de um aluno'),nl,
	write('2- Cadastrar aluno'),nl,
	write('3- Atualizar dados de um aluno'),nl,
	write('4- Remover aluno'),nl,
	write('5- Fim'),nl,nl.

executa_alunos(0):-
	['kb.pl'],
	listing(aluno/3).


executa_alunos(1):-
	write('Digite o codigo referente ao aluno: '),
	le_atomo(Codigo),nl,
	curso(Codigo, Aluno, Curso),
	write('--> O curso do aluno '),
	write(Aluno),
	write(' eh '),
	write(Curso),
	write('.'),nl.

executa_alunos(1):-
	write('--> Nao existe aluno com esse codigo.'),nl.

executa_alunos(2):-
	write('Digite o codigo do aluno: '),
	le_atomo(Codigo),nl,
	write('Digite o nome do aluno: '),
	le_atomo(Aluno),nl,
	write('Digite o curso do aluno: '),
	le_atomo(Curso),nl,
	append('kb.pl'),
	write(aluno(Codigo, Aluno, Curso)),
	write('.'),nl,
	told,
	write('--> Aluno inserido no banco de dados.'),nl.

executa_alunos(3):-
	['kb.pl'],
	dynamic(aluno/3),
	write('Digite o codigo do aluno: '),
	le_atomo(Codigo),nl,
	aluno(Codigo,_,_),
	write('Digite o novo nome do aluno: '),
	le_atomo(Aluno),nl,
	write('Digite o novo curso do aluno: '),
	le_atomo(Curso),nl,
	retract(aluno(Codigo,_,_)),
	tell('kb.pl'),
	listing(aluno/3),
	write(aluno(Codigo, Aluno, Curso)),
	write('.'),nl,
	told,
	write('--> Os dados do aluno foram atualizados.'),nl,!.

executa_alunos(3):-
	write('--> Nao existe aluno com esse codigo.'),nl.

executa_alunos(4):-
	['kb.pl'],
	dynamic(aluno/3),
	write('Digite o codigo do aluno: '),
	le_atomo(Codigo),nl,
	aluno(Codigo,_,_),
	retract(aluno(Codigo,_,_)),
	tell('kb.pl'),
	listing(aluno/3),
	told,
	write('--> Aluno removido do banco de dados.'),nl,!.

executa_alunos(4):-
	write('--> Nao existe aluno com esse codigo.'),nl.

curso(Codigo, Aluno, Curso):-
	aluno(Codigo, Aluno, Curso).
