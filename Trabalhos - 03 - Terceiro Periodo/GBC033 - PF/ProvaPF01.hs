------------------------------------
-- Programa: Primeira Prova de PF --
-- Aluno: Marcelo Mendonca Borges --
-- Data: 19/05/2017               --
------------------------------------


ackerman :: Integer -> Integer -> Integer
ackerman m n
           |(m == 0) = n+1
           |(m > 0) && (n == 0) = ackerman (m-1) n
           |(m > 0) && (n > 0) = ackerman (m-1) (ackerman m (n-1))

divisoresAux :: Integer -> Integer -> Integer
divisoresAux n b
               |(b == n) = 1 
               |((b < n) && ((mod n b)==0)) = 1 + (divisoresAux n (b+1))
               |otherwise = divisoresAux n (b+1)


numDivisores :: Integer -> Integer
numDivisores n = divisoresAux n 1

primo :: Integer -> Bool
primo n
      |(n == 1) = True
      |(numDivisores n == 2) = True
      |otherwise = False

divisoresAux' :: Integer -> Integer -> Integer -> Integer
divisoresAux' n b 1 = 1
divisoresAux' n b resultado
                |(b == n) = divisoresAux' n b 1
                |((b < n) && ((mod n b)==0)) = divisoresAux' n (b+1) resultado+1
                |otherwise = divisoresAux' n (b+1) resultado