------------------------------------
-- Programa: Aula Pratica 02      --
-- Aluno: Marcelo Mendonca Borges --
-- Data: 19/04/2017               --
------------------------------------

----------- Exercicio 01 -----------
media3 :: Double -> Double -> Double -> Double
media3 a b c = (a + b + c)/3

----------- Exercicio 02 -----------
maior2_1 :: Double -> Double -> Double
maior2_1 a b = if (a >= b) then a else b

----------- Exercicio 03 -----------
maior2_2 :: Double -> Double -> Double
maior2_2 a b
           |(a >= b) = a
           |otherwise = b

----------- Exercicio 04 -----------
maior3_1 :: Double -> Double -> Double -> Double
maior3_1 a b c = if ((a > b) && (a > c))
                   then a
                   else if (b > c)
                             then b
                             else c

----------- Exercicio 05 -----------
maior3_2 :: Double -> Double -> Double -> Double
maior3_2 a b c
             |a > b && a > c = a
             |b > c = b
             |otherwise = c       

----------- Exercicio 06 -----------
maior3_3 :: Double -> Double -> Double -> Double
maior3_3 a b c = maior2_2 a (maior2_2 b c) 

----------- Exercicio 07 -----------
numRaizes :: Double -> Double -> Double -> Int
numRaizes a b c
              |((b^2 - 4*a*c) > 0) = 2
              |((b^2 - 4*a*c) == 0) = 1
              |otherwise = 0

----------- Exercicio 08 -----------
misterio m n p = not (m==n&&n==p)
-- Verifica se pelo menos 2 entre os tres numeros da entrada sao diferentes
-- Se os tres numeros forem iguais a saida eh False
-- Os outros casos sempre resultam em True
