--------------------------------------
-- Programa: Lista de Exercicios 02 --
-- Aluno: Marcelo Mendonca Borges   --
-- Data: --/--/2017                 --
--------------------------------------

------------ Exercicio 01 ------------
listaDeInteiros :: Int -> Int -> [Int]
listaDeInteiros a b
                  |(a > b) = []
                  |(a == b) = [a]
                  |otherwise = [a..b]

------------ Exercicio 02 ------------
repetidos :: [Int] -> [Int]
repetidos [] = []
repetidos (x:xs) = [x,x] ++ repetidos xs

------------ Exercicio 03 ------------
divisor :: Int -> Int -> Bool
divisor num div = ((mod num div) == 0)

divisores num = [x | x <- [1..num], divisor num x]

------------ Exercicio 04 ------------



------------ Exercicio 05 ------------



------------ Exercicio 06 ------------
pares_e_impares_aux :: [Int] -> [Int] -> [Int] -> [[Int]]
pares_e_impares_aux [] a b = [a,b]
pares_e_impares_aux (x:xs) pares impares
                    |(even x) = pares_e_impares_aux xs (x:pares) impares
                    |otherwise = pares_e_impares_aux xs pares (x:impares)

pares_e_impares :: [Int] -> [[Int]]
pares_e_impares lista = pares_e_impares_aux lista [] []

------------ Exercicio 07 ------------
uniaoListas :: [Int] -> [Int] -> [Int]
uniaoListas [] lista = lista
uniaoListas (x:xs) (y:ys)
                   |((x < y)||(x == y)) = [x] ++ (uniaoListas xs (y:ys))
                   |(otherwise) = [y] ++ (uniaoListas (x:xs) ys)

------------ Exercicio 08 ------------
--Nao sei

------------ Exercicio 09 ------------
--Selection Sort----------------------
selectionSort :: (Ord a) => [a]->[a]
selectionSort [] = []
selectionSort xs = [x] ++ selectionSort (removeMenor x xs)
                            where x = minimum xs

removeMenor :: (Ord a) => a->[a]->[a]
removeMenor a [] = []
removeMenor a (x:xs)
              |(a == x) = xs
              |otherwise = x:(removeMenor a xs)

{-
minimo::(Ord a) => [a]->a
minimo [] = undefined
minimo [x] = x
minimo (x:xs)
       | x <= (minimo xs) = x
       | otherwise = minimo xs
-}
--Insertion Sort----------------------
insertionSort ::(Ord a) => [a] -> [a]
insertionSort [] = []
insertionSort (x:xs) = insereOrd x (insertionSort xs)

insercao2 :: Ord a => [a] -> [a]
insercao2 = foldr insereOrd []

insereOrd ::(Ord a) => a -> [a] -> [a]
insereOrd x [] = [x]
insereOrd x (y:ys)
            |(x <= y) = (x:y:ys)
            |otherwise = y: (insereOrd x ys)

--Quick Sort--------------------------
quickSort::(Ord a) => [a] -> [a]
quickSort [] = []
quickSort (s:xs) = quicksort [x|x <- xs,x < s] ++ [s] ++ quicksort [x|x <- xs,x >= s]

--Bubble Sort-------------------------
bubbleSort [] = []
bubbleSort lista = bolhaOrd lista (length lista)

bolhaOrd lista 0 = lista
bolhaOrd lista n = bolhaOrd (troca lista) (n-1)

troca [x] = [x]
troca (x:y:zs)
      | x > y = y : troca (x:zs)
      | otherwise = x : troca (y:zs)

------------ Exercicio 10 ------------
listaParaConjuntoAux :: [Int] -> [Int] -> [Int]
listaParaConjuntoAux [] lista = lista
listaParaConjuntoAux (x:xs) lista
                      |(elem x lista) = listaParaConjuntoAux xs lista
                      |otherwise = listaParaConjuntoAux xs (x:lista)

listaParaConjunto :: [Int] -> [Int]
listaParaConjunto lista = reverse (listaParaConjuntoAux lista [])

------------ Exercicio 11 ------------
--letra a)
uniaoConjuntosA :: [Int] -> [Int] -> [Int]
uniaoConjuntosA lista1 lista2 = listaParaConjunto (lista1 ++ lista2)

--letra b)
--Nao sei

--letra c)
uniaoConjuntosC :: [Int] -> [Int] -> [Int]
uniaoConjuntosC lista1 lista2 = [x | x <- lista1] ++ [x |x<-lista2, not(elem x lista1)]

------------ Exercicio 12 ------------
--letra a)
l1 :: [Int]
l1 = [x| x <- [100..300], ((mod x 3)==0)]

--letra b)
fatores n = [i | i<-[1..n], ((mod n i) == 0)]
primo n = if ((fatores n) == [1,n])
             then True
             else False
l2 :: [Int]
l2 = [x| x <- [1..100], primo x]

--letra c)
l3 :: [(Int,Int)]
l3 = [(x,y) | x <- l1, y <- l1]

--letra d)
--Nao sei
l4 :: [Int]
l4 = [(div x y) | x <- l1, y <- l2]

--letra e)
l5 :: [Float]
l5 = [(x^2) + 7*x + 1 | x <- [0.0,0.1,0.2,0.3,0.4,0.5,0.6,0.7,0.8,0.9,1.0]]

--letra f)
--Nao sei
