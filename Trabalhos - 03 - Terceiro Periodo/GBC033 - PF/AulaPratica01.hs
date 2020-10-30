------------------------------------
-- Programa: Aula Pratica 01      --
-- Aluno: Marcelo Mendonca Borges --
-- Data: 07/04/2017               --
------------------------------------

----------- Exercicio 01 -----------
double x = x + x
quadruple x = double (double x)
factorial n = product [1..n]
average ns = sum ns `div` length ns

----------- Exercicio 02 -----------
n = a `div` length xs
 where
  a = 10
  xs = [1,2,3,4,5]

----------- Exercicio 03 -----------
last_1 ns = head(reverse ns)

----------- Exercicio 04 -----------
last_2 ns =  take 1 (reverse ns)

----------- Exercicio 05 -----------
init_1 ns = take ((length ns)-1) ns
init_2 ns = reverse(tail(reverse ns))