------------------------------------
-- Programa: Aula Pratica 04      --
-- Aluno: Marcelo Mendonca Borges --
-- Data: 05/05/2017               --
------------------------------------

----------- Exercicio 01 -----------
fatorial :: Integer -> Integer
fatorial n
         |n==0 = 1
         |n>0 = fatorial (n-1)*n

fatorial' :: Integer -> String
fatorial' n
          |n<0 = "Erro Entrada com numero negativo"
          |n>=0 = show (fatorial n)

----------- Exercicio 02 -----------
pot2 :: Integer -> Integer
pot2 n
     |n==0 = 1
     |n>0 = 2*pot2 (n-1)

pot2' :: Integer -> Integer
pot2' n
      |n==0 = 1
      |otherwise = 2*pot2' (n-1)

----------- Exercicio 03 -----------
mul ::Int ->Int ->Int
mul m n
      |n==0 = 0
      |n>0 = m + mul m (n-1)
      |otherwise = -(mul m (-n))

----------- Exercicio 04 -----------
fib :: Int -> Int
fib n
    |n==0 = 0
    |n==1 = 1
    |n>1 = fib (n-2)+fib (n-1)

----------- Exercicio 05 -----------
potencia2 :: Integer->Integer
potencia2 n = potencia2' n 1

potencia2' :: Integer->Integer->Integer
potencia2' n y
             |n==0 = y
             |n>0 = potencia2' (n-1) (2*y)

----------- Exercicio 06 -----------
par :: Integer -> Bool
par n
    |n==0 = True
    |n==1 = False
    |n>1 = par(n-2)
    |n<0 = par(-n)

----------- Exercicio 07 -----------
fatorialDuplo :: Integer -> Integer
fatorialDuplo n
              |n==0 = 0
              |n==1 = 1
              |n==2 = 2
              |n>2 = n*fatorialDuplo(n-2)

----------- Exercicio 08 -----------
produtoIntervalo :: Integer -> Integer -> Integer
produtoIntervalo m n
                   |m==n = m
                   |m<n = m*produtoIntervalo (m+1) n
                   |otherwise = m*produtoIntervalo (m-1) n

----------- Exercicio 09 -----------
fatorial'' :: Integer -> Integer
fatorial'' n = produtoIntervalo 1 n

----------- Exercicio 10 -----------


----------- Exercicio 11 -----------
potencia :: Integer -> Integer -> Integer
potencia a b
           |b==0 = 1
           |b==1 = a
           |b>1 = a*(potencia a (b-1))

----------- Exercicio 12 -----------

----------- Exercicio 13 -----------

----------- Exercicio 14 -----------

----------- Exercicio 15 -----------

----------- Exercicio 16 -----------

----------- Exercicio 17 -----------
{-
fib2 :: Integer -> Integer
fib2 n = fib2' n 0 1

fib2' :: Integer -> Integer -> Integer -> Integer
fib2' n x y
          |n==0 = x
          |n==1 = y
          |n>1 = fib2' (n-1) y (x+y)

fib3 :: Integer->Integer
fib3 n 
     |n == 0 = 0
     |n == 1 = 1
     |n > 1 = fib3' 2 n 1 0

fib3' :: Integer->Integer->Integer->Integer->Integer
fib3' i n u p = if i == n
                  then (u+p)
                  else fib3' (i+1) n (u+p) u

fib4 :: Integer -> Integer
fib4 n = fib4' n i 0 1

fib4' :: Integer -> Integer -> Integer -> Integer
fib4' n i a b
          |n==0 = a
          |n==1 = b
          |n>1 = fib4' (n-1) y (x+y)
-}

